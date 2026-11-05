#include "queue_bridge.h"
#include <algorithm>
#include <bit>
#include <optional>

namespace reo::sjuni::bridge {
namespace {
namespace core = reo::native::sjuni;
constexpr auto stale_wire_region = std::numeric_limits<std::uint64_t>::max();

bool valid_regions(std::span<const Region> regions) {
    for (std::size_t i = 0; i < regions.size(); ++i) {
        const auto& a = regions[i];
        if (a.id == 0 || a.id == stale_wire_region || a.size == 0 ||
            a.size > (std::uint64_t{1} << 32) - a.base) return false;
        for (std::size_t j = 0; j < i; ++j) {
            const auto& b = regions[j];
            if (a.id == b.id || (std::uint64_t(a.base) < std::uint64_t(b.base) + b.size &&
                               std::uint64_t(b.base) < std::uint64_t(a.base) + a.size)) return false;
        }
    }
    return true;
}

std::optional<core::Span> decode_span(std::uint32_t pointer, std::int32_t bytes,
                                      std::span<const Region> regions, bool stale = false) {
    if (stale) return core::Span{stale_wire_region, pointer, bytes};
    if (pointer == 0) return core::Span{0, 0, bytes};
    for (const auto& region : regions) {
        if (pointer < region.base) continue;
        const auto offset = std::uint64_t(pointer) - region.base;
        if (offset <= region.size && (bytes <= 0 || std::uint64_t(bytes) <= region.size - offset))
            return core::Span{region.id, std::int64_t(offset), bytes};
    }
    return std::nullopt;
}

std::optional<std::uint32_t> encode_pointer(const core::Span& span, std::span<const Region> regions) {
    if (span.region == 0) return span.offset == 0 ? std::optional<std::uint32_t>(0) : std::nullopt;
    if (span.region == stale_wire_region) {
        if (span.offset < 0 || span.offset > UINT32_MAX) return std::nullopt;
        return std::uint32_t(span.offset);
    }
    for (const auto& region : regions) {
        if (span.region != region.id || span.offset < 0) continue;
        const auto offset = std::uint64_t(span.offset);
        if (offset > region.size || (span.bytes > 0 && std::uint64_t(span.bytes) > region.size - offset) ||
            std::uint64_t(region.base) + offset > UINT32_MAX) return std::nullopt;
        return std::uint32_t(std::uint64_t(region.base) + offset);
    }
    return std::nullopt;
}

std::optional<core::Snapshot> decode_image(const Image& image, std::span<const Region> regions) {
    core::Snapshot state;
    state.mode = image.mode();
    const auto decode_node = [&](std::uint32_t pointer) {
        std::uint32_t index = core::no_node;
        if (pointer != 0) node_index(image, pointer, index);
        return index;
    };
    state.free_head = decode_node(image.words[5]);
    for (std::size_t i = 0; i < 4; ++i) state.heads[i] = decode_node(image.words[6 + i]);
    std::vector<bool> queued(image.nodes.size());
    for (const auto head : state.heads)
        for (auto n = head; n != core::no_node; n = decode_node(image.nodes[n].words[0]))
            queued[n] = true;
    state.nodes.resize(image.nodes.size());
    for (std::size_t i = 0; i < state.nodes.size(); ++i) {
        const auto& raw = image.nodes[i].words;
        const auto span = decode_span(raw[2], std::bit_cast<std::int32_t>(raw[3]), regions, !queued[i]);
        if (!span) return std::nullopt;
        state.nodes[i] = core::Node{decode_node(raw[0]), *span};
    }
    return state;
}

bool encode_image(Image& image, const core::Pool& pool, std::span<const Region> regions) {
    const auto pointer = [&](core::NodeId index) {
        return index == core::no_node ? 0u : image.node_base() + 16 * index;
    };
    // Validate every conversion before modifying even the temporary image.
    for (const auto& node : pool.nodes())
        if (!encode_pointer(node.span, regions)) return false;
    image.words[5] = pointer(pool.free_head());
    for (std::size_t i = 0; i != 4; ++i) image.words[6 + i] = pointer(pool.heads()[i]);
    for (std::size_t i = 0; i < pool.nodes().size(); ++i) {
        const auto& node = pool.nodes()[i];
        auto& words = image.nodes[i].words;
        words[0] = pointer(node.next);
        words[2] = *encode_pointer(node.span, regions);
        words[3] = std::bit_cast<std::uint32_t>(node.span.bytes);
    }
    return true;
}

struct CallbackRejected {};
struct Context;
bool operation_admitted(const Context& context);

struct Context {
    Memory memory;
    const Profile& profile;
    std::span<const Region> regions;
    const Call& call;
    Callbacks callbacks;
    Image image;
    core::Pool* pool{};
    core::Span input{};
    core::Span output{};
    std::int32_t available{};

    bool reread() {
        Image next;
        if (read_image(memory, profile, image.address, next) != Admission::accepted ||
            next.node_base() != image.node_base() || next.nodes.size() != image.nodes.size()) return false;
        const auto state = decode_image(next, regions);
        if (!state || pool->import_state(*state) != core::Result::completed) return false;
        image = std::move(next);
        if (call.queue < 4 && (call.operation == Operation::put || call.operation == Operation::unget)) {
            std::uint32_t p, n;
            if (!memory.read32(call.descriptor, p) || !memory.read32(call.descriptor + 4, n)) return false;
            const auto span = decode_span(p, std::bit_cast<std::int32_t>(n), regions,
                                          p != 0 && std::bit_cast<std::int32_t>(n) <= 0);
            if (!span) return false;
            input = *span;
        }
        return true;
    }

    bool flush(bool publish_output) {
        if (!encode_image(image, *pool, regions)) return false;
        std::optional<std::uint32_t> result_pointer;
        if (publish_output && call.operation == Operation::get) {
            result_pointer = encode_pointer(output, regions);
            if (!result_pointer) return false;
        }
        if (!mirror_queues(memory, image)) return false;
        if (result_pointer) {
            memory.write32(call.descriptor, *result_pointer);
            memory.write32(call.descriptor + 4, std::bit_cast<std::uint32_t>(output.bytes));
        }
        if (publish_output && call.operation == Operation::availability)
            memory.write32(call.descriptor, std::bit_cast<std::uint32_t>(available));
        return true;
    }

    void event(Event event, std::int32_t code = 0) {
        // Get has not yet written output at entry/invalid-selector error; the
        // availability operation writes zero before invoking its error callback.
        const bool publish = event == Event::leave || call.operation == Operation::availability;
        if (!flush(publish)) throw CallbackRejected{};
        if (callbacks.invoke && (event != Event::error || image.words[10] != 0))
            callbacks.invoke(callbacks.context, event, code, memory);
        if (!reread()) throw CallbackRejected{};
        if (event == Event::enter && !operation_admitted(*this)) throw CallbackRejected{};
        if (event == Event::leave && call.operation == Operation::get) {
            std::uint32_t pointer, bytes;
            if (!memory.read32(call.descriptor, pointer) || !memory.read32(call.descriptor + 4, bytes))
                throw CallbackRejected{};
            // Leave may mutate caller output after original Get's final write.
            output = *decode_span(pointer, std::bit_cast<std::int32_t>(bytes), regions, true);
        }
        // Availability does not clear its output again after error reentry.
        if (call.operation == Operation::availability) {
            std::uint32_t value;
            if (!memory.read32(call.descriptor, value)) throw CallbackRejected{};
            available = std::bit_cast<std::int32_t>(value);
        }
    }
};

bool operation_admitted(const Context& context) {
    const auto& call = context.call;
    const auto& pool = *context.pool;
    const auto regions = context.regions;
    core::Result checked = core::Result::completed;
    if (call.operation == Operation::get) checked = pool.check_get(call.queue, call.request);
    if (call.operation == Operation::put) checked = pool.check_put(call.queue, context.input);
    if (call.operation == Operation::unget) checked = pool.check_unget(call.queue, context.input);
    if (checked != core::Result::completed) return false;
    if (call.queue >= 4 || context.image.mode() != 1) return true;
    const auto head = pool.heads()[call.queue];
    if (call.operation == Operation::get && head != core::no_node &&
        call.request < pool.nodes()[head].span.bytes) {
        auto remainder = pool.nodes()[head].span;
        remainder.offset += call.request; // check_get established representability.
        remainder.bytes = std::int32_t(std::int64_t(remainder.bytes) - call.request);
        if (!encode_pointer(remainder, regions)) return false;
    }
    if (call.operation == Operation::put || call.operation == Operation::unget) {
        auto selected = head;
        if (call.operation == Operation::put && selected != core::no_node)
            while (pool.nodes()[selected].next != core::no_node) selected = pool.nodes()[selected].next;
        if (selected != core::no_node && context.input.region != 0 && context.input.bytes > 0) {
            const auto& old = pool.nodes()[selected].span;
            const auto old_pointer = encode_pointer(old, regions);
            const auto new_pointer = encode_pointer(context.input, regions);
            if (!old_pointer || !new_pointer) return false;
            const bool adjacent = call.operation == Operation::put
                ? std::uint64_t(*old_pointer) + std::uint32_t(old.bytes) == *new_pointer
                : std::uint64_t(*new_pointer) + std::uint32_t(context.input.bytes) == *old_pointer;
            if (adjacent && old.region != context.input.region) return false;
        }
    }
    return true;
}

bool descriptor_admitted(Memory memory, const Image& image, const Call& call) {
    std::size_t size = 0;
    if (call.operation == Operation::get || call.operation == Operation::put || call.operation == Operation::unget)
        size = 8;
    else if (call.operation == Operation::availability) size = 4;
    if (size == 0) return true;
    // Original selector rejection is before input descriptor dereference.
    if (call.queue >= 4 && (call.operation == Operation::put || call.operation == Operation::unget)) return true;
    return call.descriptor % 4 == 0 && memory.contains(call.descriptor, size) &&
        !overlaps(call.descriptor, size, image.address, 48) &&
        !overlaps(call.descriptor, size, image.node_base(), image.nodes.size() * 16);
}
} // namespace

Outcome execute(Memory memory, const Profile& profile, std::uint32_t object,
                std::span<const Region> regions, const Call& call, Callbacks callbacks) {
    if (!valid_regions(regions)) return {};
    Image image;
    if (read_image(memory, profile, object, image) != Admission::accepted ||
        !descriptor_admitted(memory, image, call)) return {};
    const auto state = decode_image(image, regions);
    if (!state) return {};
    core::Pool pool(std::uint32_t(image.nodes.size()), image.mode());
    if (pool.import_state(*state) != core::Result::completed) return {};
    Context context{memory, profile, regions, call, callbacks, std::move(image), &pool};
    if ((call.operation == Operation::put || call.operation == Operation::unget) && call.queue < 4) {
        if (!context.reread()) return {};
    }
    if (!operation_admitted(context)) return {};
    if (callbacks.invoke) {
        pool.set_hooks({&context,
            [](void* p) { static_cast<Context*>(p)->event(Event::enter); },
            [](void* p) { static_cast<Context*>(p)->event(Event::leave); },
            [](void* p, std::int32_t code) { static_cast<Context*>(p)->event(Event::error, code); }});
    }
    try {
        core::Result result = core::Result::completed;
        std::uint32_t value = 0;
        switch (call.operation) {
        case Operation::get: result = pool.get(call.queue, call.request, context.output); break;
        case Operation::put: result = pool.put(call.queue, context.input); break;
        case Operation::unget: result = pool.unget(call.queue, context.input); break;
        case Operation::queued_bytes: value = std::bit_cast<std::uint32_t>(pool.queued_bytes(call.queue)); break;
        case Operation::availability: value = pool.head_availability(call.queue, call.request, context.available); break;
        case Operation::queued_nodes: result = pool.queued_nodes(call.queue, value); break;
        case Operation::free_nodes: value = pool.free_nodes(); break;
        }
        if (result == core::Result::unsupported_selector) return {};
        if (result != core::Result::completed || !context.flush(true))
            return {Disposition::callback_contract_violation, 0};
        return {Disposition::completed, value};
    } catch (const CallbackRejected&) {
        return {Disposition::callback_contract_violation, 0};
    }
}

} // namespace reo::sjuni::bridge
