#include "runtime_adapter.h"
#include "ps2_runtime_macros.h"
#include "ps2_stubs.h"
#include "../native_geometry/reo_vu_native_sha256.h"
#include "../../../game/native/sjuni_adapter/queue_bridge.h"

#include <array>
#include <atomic>
#include <bit>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <exception>

#if defined(REO_GAME_FILE2)
#error "The native SJUNI adapter is admitted only for File #1"
#endif

namespace reo_native_sjuni {
namespace {
namespace b = reo::sjuni::bridge;
using Function = PS2Runtime::RecompiledFunction;
constexpr std::array<std::uint32_t, 7> entries{0x140288, 0x140300, 0x140438, 0x140590,
                                               0x1406D8, 0x140768, 0x1407A8};
constexpr std::array<b::Operation, 7> operations{
    b::Operation::queued_bytes, b::Operation::get,          b::Operation::put,
    b::Operation::unget,        b::Operation::availability, b::Operation::queued_nodes,
    b::Operation::free_nodes};
constexpr b::Profile profile{0x228C98, 64, 0x228C60, 0x23DA78, 16};
constexpr std::uint32_t node_arena = 0x221780, node_arena_bytes = 0x2000;
constexpr std::uint32_t paired_records = 0x221480;
constexpr std::uint32_t text_begin = 0x140000, text_bytes = 0x840;
constexpr reo_native_image_identity::Digest text_digest{
    0x54, 0x43, 0x76, 0x80, 0x72, 0x78, 0x84, 0x7B, 0xC0, 0xF4, 0x29, 0x4C, 0x7A, 0x62, 0x23, 0x8A,
    0xCF, 0xF5, 0xA6, 0x45, 0xAC, 0xCC, 0x2E, 0xC2, 0xDE, 0xC9, 0xBF, 0x58, 0x07, 0x3D, 0x5C, 0xC2};

// One runtime owns these seven registrations. Its existing execution scope
// serializes calls; no independent mutex or persistent queue cache is added.
std::array<Function, entries.size()> originals{};
std::atomic<PS2Runtime*> owner{nullptr};
std::atomic<std::uint8_t*> installed_memory{nullptr};
std::atomic<bool> healthy{false};

void refuse(const char* reason) noexcept {
    healthy.store(false, std::memory_order_release);
    std::fprintf(stderr, "[native-sjuni] disabled: %s; original methods retained\n", reason);
}

bool canonical(const R5900Context* context, unsigned reg) noexcept {
    return GPR_U64(context, reg) == static_cast<std::uint64_t>(static_cast<std::int64_t>(
                                        std::bit_cast<std::int32_t>(GPR_U32(context, reg))));
}

bool mutating(b::Operation operation) noexcept {
    return operation == b::Operation::get || operation == b::Operation::put ||
           operation == b::Operation::unget;
}

// Reject aliasing against ALL local SJUNI object/node storage, not just this
// instance. The old implementation remains responsible for aliased calls.
bool descriptor_alias(std::uint32_t address, std::size_t bytes, std::uint32_t frame) noexcept {
    return b::overlaps(address, bytes, profile.object_base, 64u * 48u) ||
           b::overlaps(address, bytes, node_arena, node_arena_bytes) ||
           b::overlaps(address, bytes, frame, 80) || b::overlaps(address, bytes, 0x228C60, 0x38) ||
           b::overlaps(address, bytes, 0x23DA78, 16) ||
           b::overlaps(address, bytes, 0x2649E0, 0x20) ||
           b::overlaps(address, bytes, 0x221438, 0x48) ||
           b::overlaps(address, bytes, text_begin, text_bytes);
}

bool exhaustion_possible(const b::Image& image, const b::Call& call, std::uint32_t pointer,
                         std::int32_t length) noexcept {
    if ((call.operation != b::Operation::put && call.operation != b::Operation::unget) ||
        pointer == 0 || length <= 0 || image.words[5] != 0)
        return false;
    if (image.mode() != 1 || image.words[6 + call.queue] == 0)
        return true;
    auto link = image.words[6 + call.queue];
    std::uint32_t index = 0;
    if (!b::node_index(image, link, index))
        return true;
    if (call.operation == b::Operation::put) {
        while (image.nodes[index].words[0] != 0) {
            link = image.nodes[index].words[0];
            if (!b::node_index(image, link, index))
                return true;
        }
    }
    const auto& old = image.nodes[index].words;
    const auto old_length = std::bit_cast<std::int32_t>(old[3]);
    if (old_length <= 0)
        return true;
    const bool adjacent = call.operation == b::Operation::put
                              ? std::uint64_t(old[2]) + std::uint32_t(old_length) == pointer
                              : std::uint64_t(pointer) + std::uint32_t(length) == old[2];
    // The bridge independently rejects length/region/pointer overflow. This
    // preflight only proves that an exhaustion callback cannot be needed.
    return !adjacent;
}

// The portable bridge has a flat address-space view. Rebase only metadata into
// this compact private transaction; borrowed IOP payload tokens remain numeric
// and unchanged. No full-RAM copy, payload copy, guest hook or callback is used.
constexpr std::uint32_t stage_object = 0x40, stage_nodes = 0x80, stage_descriptor = 0x190;
constexpr b::Profile stage_profile{stage_object, 1, profile.vtable, profile.uuid, 16};
struct Transaction {
    std::array<std::byte, 0x200> bytes{};
    std::array<std::uint32_t, 2> descriptor_before{};
};

bool stage_image(b::Memory memory, const b::Image& image, const b::Call& call,
                 Transaction& transaction, std::size_t descriptor_bytes) {
    b::Memory stage(transaction.bytes);
    const auto translate = [&](std::uint32_t pointer) {
        if (pointer == 0)
            return 0u;
        std::uint32_t index = 0;
        if (!b::node_index(image, pointer, index))
            return 0u; // read_image validated chains.
        return stage_nodes + 16 * index;
    };
    for (unsigned i = 0; i < image.words.size(); ++i) {
        auto value = image.words[i];
        if (i == 3)
            value = stage_nodes;
        else if (i >= 5 && i < 10)
            value = translate(value);
        stage.write32(stage_object + 4 * i, value);
    }
    for (unsigned i = 0; i < image.nodes.size(); ++i)
        for (unsigned w = 0; w < 4; ++w)
            stage.write32(stage_nodes + 16 * i + 4 * w,
                          w == 0 ? translate(image.nodes[i].words[w]) : image.nodes[i].words[w]);
    for (unsigned w = 0; 4u * w < descriptor_bytes; ++w) {
        if (!memory.read32(call.descriptor + 4 * w, transaction.descriptor_before[w]))
            return false;
        stage.write32(stage_descriptor + 4 * w, transaction.descriptor_before[w]);
    }
    return true;
}

bool unstage_image(const b::Image& before, b::Image& after) noexcept {
    if (after.nodes.size() != before.nodes.size())
        return false;
    for (unsigned i = 0; i < before.words.size(); ++i) {
        if (i == 3 || (i >= 5 && i < 10))
            continue;
        if (after.words[i] != before.words[i])
            return false;
    }
    const auto translate = [&](std::uint32_t pointer, std::uint32_t& result) {
        if (pointer == 0) {
            result = 0;
            return true;
        }
        if (pointer < stage_nodes || (pointer - stage_nodes) % 16 != 0)
            return false;
        const auto index = (pointer - stage_nodes) / 16;
        if (index >= before.nodes.size())
            return false;
        result = before.node_base() + 16 * index;
        return true;
    };
    for (unsigned i = 5; i < 10; ++i)
        if (!translate(after.words[i], after.words[i]))
            return false;
    for (unsigned i = 0; i < after.nodes.size(); ++i) {
        if (after.nodes[i].words[1] != before.nodes[i].words[1] ||
            !translate(after.nodes[i].words[0], after.nodes[i].words[0]))
            return false;
    }
    after.address = before.address;
    after.words[3] = before.node_base();
    return true;
}

bool attempt(unsigned which, std::uint8_t* ram, R5900Context* context) {
    const auto operation = operations[which];
    if (!canonical(context, 4) || !canonical(context, 29) || context->in_delay_slot)
        return false;
    const auto object = GPR_U32(context, 4), stack = GPR_U32(context, 29);
    if (stack < 80 || stack > PS2_RAM_SIZE)
        return false;
    const auto frame = stack - 80;
    b::Memory memory(std::span<std::byte>(reinterpret_cast<std::byte*>(ram), PS2_RAM_SIZE));
    b::Image image;
    if (b::read_image(memory, profile, object, image) != b::Admission::accepted ||
        image.nodes.size() != 16 || image.mode() != 1 || image.node_base() < node_arena ||
        image.node_base() - node_arena >= node_arena_bytes ||
        (image.node_base() - node_arena) % 256 != 0 || b::overlaps(frame, 80, object, 48) ||
        b::overlaps(frame, 80, image.node_base(), image.nodes.size() * 16))
        return false;
    const auto slot = (image.node_base() - node_arena) / 256;
    std::uint32_t paired = 0;
    if (!memory.read32(paired_records + 24 * slot + 8, paired) || paired != object)
        return false;

    b::Call call{operation};
    if (operation != b::Operation::free_nodes) {
        if (!canonical(context, 5) || GPR_U32(context, 5) >= 4)
            return false;
        call.queue = GPR_U32(context, 5);
    }
    if (operation == b::Operation::get || operation == b::Operation::availability) {
        if (!canonical(context, 6) || !canonical(context, 7))
            return false;
        call.request = std::bit_cast<std::int32_t>(GPR_U32(context, 6));
        if (call.request < 0)
            return false;
        call.descriptor = GPR_U32(context, 7);
    } else if (operation == b::Operation::put || operation == b::Operation::unget) {
        if (!canonical(context, 6))
            return false;
        call.descriptor = GPR_U32(context, 6);
    }
    const std::size_t descriptor_bytes =
        operation == b::Operation::availability ? 4 : (mutating(operation) ? 8 : 0);
    if (descriptor_bytes &&
        (call.descriptor % 4 != 0 || !memory.contains(call.descriptor, descriptor_bytes) ||
         descriptor_alias(call.descriptor, descriptor_bytes, frame)))
        return false;

    std::uint32_t region_base = 0, region_size = 0;
    if (!memory.read32(0x221448, region_base) || !memory.read32(0x22143C, region_size) ||
        region_base == 0 || region_size == 0 ||
        std::uint64_t(region_base) + region_size > UINT32_MAX)
        return false;
    const std::array<b::Region, 1> regions{{{1, region_base, region_size}}};
    if (mutating(operation)) {
        std::uint32_t enter = 0, leave = 0;
        if (!memory.read32(0x2649E0, enter) || !memory.read32(0x2649E8, leave) || enter || leave)
            return false;
        if (operation != b::Operation::get) {
            std::uint32_t pointer = 0, length = 0;
            if (!memory.read32(call.descriptor, pointer) ||
                !memory.read32(call.descriptor + 4, length) ||
                exhaustion_possible(image, call, pointer, std::bit_cast<std::int32_t>(length)))
                return false;
        }
    }

    Transaction transaction;
    if (!stage_image(memory, image, call, transaction, descriptor_bytes))
        return false;
    b::Memory stage(transaction.bytes);
    auto staged_call = call;
    if (descriptor_bytes)
        staged_call.descriptor = stage_descriptor;
    // Deliberately no external callbacks. Only this private transaction can be
    // changed by a bridge failure; the original guest state remains untouched.
    const auto outcome = b::execute(stage, stage_profile, stage_object, regions, staged_call, {});
    if (outcome.disposition == b::Disposition::fallback_before_effects)
        return false;
    if (outcome.disposition != b::Disposition::completed) {
        refuse("private transaction contract violation (no guest effects committed)");
        return false;
    }
    b::Image result;
    if (b::read_image(stage, stage_profile, stage_object, result) != b::Admission::accepted ||
        !unstage_image(image, result)) {
        refuse("private transaction image validation failed (no guest effects committed)");
        return false;
    }
    std::array<std::uint32_t, 2> output{};
    if (operation == b::Operation::get || operation == b::Operation::availability)
        for (unsigned w = 0; 4u * w < descriptor_bytes; ++w)
            if (!stage.read32(stage_descriptor + 4 * w, output[w]))
                return false;

    // Final commit is allocation-free and has no callback/runtime dispatch.
    // mirror_queues validates ALL write ranges before its first guest write.
    if (mutating(operation) && !b::mirror_queues(memory, result)) {
        refuse("commit range rejected before guest writes");
        return false;
    }
    if (operation == b::Operation::get || operation == b::Operation::availability)
        for (unsigned w = 0; 4u * w < descriptor_bytes; ++w)
            memory.write32(call.descriptor + 4 * w, output[w]); // Prevalidated, cannot fail.
    if (!mutating(operation))
        SET_GPR_S32(context, 2, std::bit_cast<std::int32_t>(outcome.value));
    // Void methods do not invent an original v0 success/error result.
    context->pc = GPR_U32(context, 31);
    return true;
}

void dispatch(unsigned which, std::uint8_t* ram, R5900Context* context, PS2Runtime* runtime) {
    PS2Runtime::GuestExecutionScope execution(runtime);
    const auto original = originals[which];
    // Install captures every original before publishing ANY wrapper.
    if (context->pc != entries[which] || owner.load(std::memory_order_acquire) != runtime) {
        original(ram, context, runtime);
        return;
    }
    if (healthy.load(std::memory_order_acquire) && ram &&
        installed_memory.load(std::memory_order_acquire) == ram &&
        runtime->memory().getRDRAM() == ram) {
        try {
            if (attempt(which, ram, context))
                return;
        } catch (const std::exception&) {
            refuse("private transaction allocation/validation exception before guest commit");
        } catch (...) {
            refuse("private transaction exception before guest commit");
        }
    }
    // Nothing failed after a guest callback or partially committed guest write.
    // Every rejected operation calls its individually captured original ONCE.
    original(ram, context, runtime);
}

void sum(std::uint8_t* r, R5900Context* c, PS2Runtime* p) {
    dispatch(0, r, c, p);
}
void get(std::uint8_t* r, R5900Context* c, PS2Runtime* p) {
    dispatch(1, r, c, p);
}
void put(std::uint8_t* r, R5900Context* c, PS2Runtime* p) {
    dispatch(2, r, c, p);
}
void unget(std::uint8_t* r, R5900Context* c, PS2Runtime* p) {
    dispatch(3, r, c, p);
}
void available(std::uint8_t* r, R5900Context* c, PS2Runtime* p) {
    dispatch(4, r, c, p);
}
void nodes(std::uint8_t* r, R5900Context* c, PS2Runtime* p) {
    dispatch(5, r, c, p);
}
void free_nodes(std::uint8_t* r, R5900Context* c, PS2Runtime* p) {
    dispatch(6, r, c, p);
}
constexpr std::array<Function, entries.size()> wrappers{sum,       get,   put,       unget,
                                                        available, nodes, free_nodes};
} // namespace

bool install(PS2Runtime& runtime) noexcept {
    const char* enabled = std::getenv("REO_NATIVE_SJUNI");
    if (!enabled || std::strcmp(enabled, "1") != 0)
        return false;
    try {
        PS2Runtime::GuestExecutionScope execution(&runtime);
        auto* installed = owner.load(std::memory_order_acquire);
        if (installed == &runtime) {
            const auto* current_ram = runtime.memory().getRDRAM();
            bool same = current_ram &&
                        current_ram == installed_memory.load(std::memory_order_acquire) &&
                        reo_native_image_identity::sha256(current_ram + text_begin, text_bytes) ==
                            text_digest;
            for (unsigned i = 0; i < entries.size(); ++i)
                same = same && runtime.lookupFunction(entries[i]) == wrappers[i];
            if (!same)
                refuse("runtime memory/text/bindings changed; reinstallation refused");
            return same && healthy.load(std::memory_order_acquire);
        }
        if (installed) {
            std::fprintf(stderr, "[native-sjuni] another runtime already owns the pilot\n");
            return false;
        }
        const auto* ram = runtime.memory().getRDRAM();
        if (!ram ||
            reo_native_image_identity::sha256(ram + text_begin, text_bytes) != text_digest) {
            std::fprintf(stderr, "[native-sjuni] loaded resident text identity rejected; original "
                                 "methods retained\n");
            return false;
        }
        std::array<Function, entries.size()> captured{};
        for (unsigned i = 0; i < entries.size(); ++i) {
            captured[i] = runtime.lookupFunction(entries[i]);
            if (!captured[i] || captured[i] == wrappers[i]) {
                std::fprintf(
                    stderr,
                    "[native-sjuni] original binding missing at %08x; installation refused\n",
                    entries[i]);
                return false;
            }
        }
        PS2Runtime* expected_owner = nullptr;
        if (!owner.compare_exchange_strong(expected_owner, &runtime, std::memory_order_acq_rel)) {
            std::fprintf(stderr, "[native-sjuni] another installation owns the pilot\n");
            return false;
        }
        originals = captured;
        installed_memory.store(runtime.memory().getRDRAM(), std::memory_order_release);
        healthy.store(true, std::memory_order_release);
        for (unsigned i = 0; i < entries.size(); ++i) {
            runtime.registerFunction(entries[i], wrappers[i]);
            ps2_stubs::registerStubOverride(entries[i], wrappers[i]);
        }
        std::fprintf(stderr, "[native-sjuni] optional local pilot installed; live-hook mutations "
                             "use original methods\n");
        return true;
    } catch (...) {
        // Partial registration remains safe: captured originals exist for every
        // wrapper, and all already-installed wrappers now delegate unchanged.
        refuse("installation exception");
        return false;
    }
}
} // namespace reo_native_sjuni
