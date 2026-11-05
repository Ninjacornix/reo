#include "queue_bridge.h"

#include <functional>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace reo::sjuni::bridge;

namespace {
void require(bool condition, const char* expression, int line) {
    if (!condition) throw std::runtime_error(std::string("line ") + std::to_string(line) + ": " + expression);
}
#define REQUIRE(...) require((__VA_ARGS__), #__VA_ARGS__, __LINE__)

struct Fixture {
    static constexpr std::uint32_t object = 0x1000;
    static constexpr std::uint32_t node_base = 0x2000;
    static constexpr std::uint32_t descriptor = 0x3000;
    std::vector<std::byte> bytes = std::vector<std::byte>(0x10000, std::byte{0xA5});
    Profile profile{object, 4, 0x228C60, 0x23DA78, 8};
    std::vector<Region> regions{{1, 0x8000, 0x1000}};
    std::uint32_t count;

    explicit Fixture(std::uint32_t count_ = 3) : count(count_) {
        const std::array<std::uint32_t, 12> words{
            profile.vtable, 0xA1B20101, profile.uuid, node_base, count, node_base,
            0, 0, 0, 0, 0xDEADC0DE, 0xCAFEBABE};
        for (std::size_t i = 0; i < words.size(); ++i) write(object + std::uint32_t(i * 4), words[i]);
        for (std::uint32_t i = 0; i < count; ++i) {
            write(node_base + 16 * i, i + 1 < count ? node_base + 16 * (i + 1) : 0);
            write(node_base + 16 * i + 4, 0xC0DE0000 + i);
            write(node_base + 16 * i + 8, 0xF1000000 + i); // Unregistered stale tokens are preserved.
            write(node_base + 16 * i + 12, 0x80000000 + i);
        }
        span(descriptor, 0x8100, 8);
    }
    Memory memory() { return Memory(bytes); }
    void write(std::uint32_t address, std::uint32_t value) { REQUIRE(memory().write32(address, value)); }
    std::uint32_t read(std::uint32_t address) {
        std::uint32_t value{};
        REQUIRE(memory().read32(address, value));
        return value;
    }
    void span(std::uint32_t address, std::uint32_t pointer, std::uint32_t length) {
        write(address, pointer); write(address + 4, length);
    }
    void one_queued(std::uint32_t queue, std::uint32_t pointer = 0x8100, std::uint32_t length = 8) {
        write(object + 20, count > 1 ? node_base + 16 : 0);
        write(object + 24 + 4 * queue, node_base);
        write(node_base, 0);
        span(node_base + 8, pointer, length);
    }
};

struct Trace {
    std::vector<Event> events;
    std::function<void(Event, Memory)> action;
    Callbacks callbacks() {
        return {this, [](void* context, Event event, std::int32_t code, Memory memory) {
            auto& self = *static_cast<Trace*>(context);
            self.events.push_back(event);
            if (event == Event::error) REQUIRE(code == -3);
            auto action = self.action;
            if (action) action(event, memory);
        }};
    }
};

bool same_image(const Image& a, const Image& b) {
    return a.address == b.address && a.words == b.words && a.nodes == b.nodes;
}

void image_admission_is_transactional() {
    using Mutator = std::function<void(Fixture&)>;
    const std::vector<std::pair<Mutator, Admission>> cases{
        {[](auto& f) { f.write(f.object, 0); }, Admission::wrong_identity},
        {[](auto& f) { f.write(f.object + 8, 0); }, Admission::wrong_identity},
        {[](auto& f) { f.write(f.object + 4, 0x100); }, Admission::wrong_identity},
        {[](auto& f) { f.write(f.object + 16, 0); }, Admission::invalid_node_storage},
        {[](auto& f) { f.write(f.object + 16, UINT32_MAX); }, Admission::invalid_node_storage},
        {[](auto& f) { f.write(f.object + 16, 9); }, Admission::invalid_node_storage},
        {[](auto& f) { f.write(f.object + 12, 0); }, Admission::invalid_node_storage},
        {[](auto& f) { f.write(f.object + 12, f.node_base + 1); }, Admission::invalid_node_storage},
        {[](auto& f) { f.write(f.object + 12, f.object + 16); }, Admission::overlapping_storage},
        {[](auto& f) { f.write(f.object + 12, 0xFFF0); }, Admission::unavailable_memory},
        {[](auto& f) { f.write(f.object + 12, 0xFFFFFFF0); }, Admission::unavailable_memory},
        {[](auto& f) { f.write(f.node_base + 32, f.node_base); }, Admission::invalid_chain},
        {[](auto& f) { f.write(f.object + 24, f.node_base); }, Admission::invalid_chain},
        {[](auto& f) { f.write(f.node_base + 16, 0); }, Admission::invalid_chain},
        {[](auto& f) { f.write(f.node_base, f.node_base + 48); }, Admission::invalid_chain},
        {[](auto& f) { f.write(f.node_base, f.node_base + 4); }, Admission::invalid_chain},
    };
    Image sentinel;
    sentinel.address = 0xDEAD;
    sentinel.words.fill(0x12345678);
    sentinel.nodes.push_back(RawNode{{7, 8, 9, 10}});
    for (const auto& [mutate, expected] : cases) {
        Fixture fixture;
        mutate(fixture);
        const auto before_memory = fixture.bytes;
        auto output = sentinel;
        REQUIRE(read_image(fixture.memory(), fixture.profile, fixture.object, output) == expected);
        REQUIRE(same_image(output, sentinel) && fixture.bytes == before_memory);
    }
    Fixture fixture;
    for (auto wrong : {fixture.object + 4, fixture.object + 1, fixture.object + 48 * 4,
                       fixture.object - 48}) {
        auto output = sentinel;
        REQUIRE(read_image(fixture.memory(), fixture.profile, wrong, output) == Admission::wrong_identity);
        REQUIRE(same_image(output, sentinel));
    }
    auto unavailable = fixture.profile;
    unavailable.object_base = 0xFFF0;
    unavailable.object_slots = 1;
    auto output = sentinel;
    REQUIRE(read_image(fixture.memory(), unavailable, 0xFFF0, output) == Admission::unavailable_memory);
    REQUIRE(same_image(output, sentinel));
    REQUIRE(read_image(fixture.memory(), fixture.profile, fixture.object, output) == Admission::accepted);
    REQUIRE(output.nodes.size() == 3 && output.address == fixture.object);
}

void mirroring_preserves_external_words_and_stale_spans() {
    Fixture f;
    const auto initial = f.bytes;
    Trace trace;
    const auto put = execute(f.memory(), f.profile, f.object, f.regions,
                             {Operation::put, 0, 0, f.descriptor}, trace.callbacks());
    REQUIRE(put.disposition == Disposition::completed);
    REQUIRE(f.read(f.object + 24) == f.node_base && f.read(f.object + 20) == f.node_base + 16);
    const auto get = execute(f.memory(), f.profile, f.object, f.regions,
                             {Operation::get, 0, 8, f.descriptor + 16}, trace.callbacks());
    REQUIRE(get.disposition == Disposition::completed);
    REQUIRE(f.read(f.descriptor + 16) == 0x8100 && f.read(f.descriptor + 20) == 8);
    REQUIRE(f.read(f.node_base + 8) == 0x8100 && f.read(f.node_base + 12) == 8);
    REQUIRE(f.read(f.object + 20) == f.node_base && f.read(f.node_base) == f.node_base + 16);
    for (std::uint32_t i = 0; i < f.count; ++i) REQUIRE(f.read(f.node_base + i * 16 + 4) == 0xC0DE0000 + i);
    REQUIRE(f.read(f.node_base + 24) == 0xF1000001 && f.read(f.node_base + 28) == 0x80000001);
    for (std::uint32_t offset : {0, 4, 8, 12, 16, 40, 44}) {
        for (std::uint32_t byte = 0; byte < 4; ++byte)
            REQUIRE(f.bytes[f.object + offset + byte] == initial[f.object + offset + byte]);
    }
}

void invalid_selector_does_not_require_input_memory() {
    for (auto operation : {Operation::put, Operation::unget}) {
        Fixture f;
        Trace trace;
        const auto before = f.bytes;
        const auto result = execute(f.memory(), f.profile, f.object, f.regions,
                                     {operation, UINT32_MAX, 0, 0xFFFFFFFD}, trace.callbacks());
        REQUIRE(result.disposition == Disposition::completed);
        REQUIRE(trace.events == std::vector<Event>{Event::error});
        REQUIRE(f.bytes == before);
    }
}

void unaligned_and_alias_descriptors_decline_without_effects() {
    for (auto operation : {Operation::get, Operation::put, Operation::unget, Operation::availability}) {
        for (std::uint32_t descriptor : {Fixture::descriptor + 1, Fixture::object + 20,
                                         Fixture::node_base + 4, std::uint32_t(0xFFFC)}) {
            Fixture f;
            Trace trace;
            // Make the unaligned input otherwise fully admissible: without the
            // alignment gate, put/unget would publish it instead of coincidentally
            // declining an unregistered pointer assembled from shifted bytes.
            if (descriptor == Fixture::descriptor + 1 &&
                (operation == Operation::put || operation == Operation::unget))
                f.span(descriptor, 0x8100, 8);
            const auto before = f.bytes;
            const auto result = execute(f.memory(), f.profile, f.object, f.regions,
                                         {operation, 0, 4, descriptor}, trace.callbacks());
            // A four-byte availability output at FFFC is valid, unlike a span.
            if (operation == Operation::availability && descriptor == 0xFFFC) {
                REQUIRE(result.disposition == Disposition::completed);
            } else {
                REQUIRE(result.disposition == Disposition::fallback_before_effects);
                REQUIRE(f.bytes == before && trace.events.empty());
            }
        }
    }
}

void unsupported_regions_decline_without_effects() {
    const std::vector<std::vector<Region>> cases{
        {}, {{0, 0x8000, 0x100}}, {{UINT64_MAX, 0x8000, 0x100}}, {{1, 0x8000, 0}},
        {{1, 0xFFFFFFF0, 32}}, {{1, 0x8000, 0x100}, {1, 0x8200, 0x100}},
        {{1, 0x8000, 0x200}, {2, 0x8100, 0x200}}, {{1, 0x9000, 0x100}}
    };
    for (const auto& regions : cases) {
        Fixture f;
        Trace trace;
        const auto before = f.bytes;
        const auto outcome = execute(f.memory(), f.profile, f.object, regions,
                                      {Operation::put, 0, 0, f.descriptor}, trace.callbacks());
        REQUIRE(outcome.disposition == Disposition::fallback_before_effects);
        REQUIRE(f.bytes == before && trace.events.empty());
    }
    Fixture f;
    f.one_queued(0);
    Trace trace;
    const auto before = f.bytes;
    const auto result = execute(f.memory(), f.profile, f.object, {},
                                 {Operation::queued_bytes, 0, 0, 0}, trace.callbacks());
    REQUIRE(result.disposition == Disposition::fallback_before_effects);
    REQUIRE(f.bytes == before && trace.events.empty());
}

void cross_region_adjacency_is_not_silently_changed() {
    for (auto operation : {Operation::put, Operation::unget}) {
        Fixture f;
        f.regions = {{1, 0x8000, 0x100}, {2, 0x8100, 0x100}};
        if (operation == Operation::put) {
            f.one_queued(0, 0x80F0, 16);
            f.span(f.descriptor, 0x8100, 8);
        } else {
            f.one_queued(0, 0x8100, 8);
            f.span(f.descriptor, 0x80F0, 16);
        }
        Trace trace;
        const auto before = f.bytes;
        const auto outcome = execute(f.memory(), f.profile, f.object, f.regions,
                                      {operation, 0, 0, f.descriptor}, trace.callbacks());
        REQUIRE(outcome.disposition == Disposition::fallback_before_effects);
        REQUIRE(f.bytes == before && trace.events.empty());
    }
    Fixture f;
    f.regions = {{1, 0x8000, 0x100}, {2, 0x8100, 0x100}};
    f.one_queued(0, 0x80D0, 16);
    f.span(f.descriptor, 0x8100, 8); // Initially not adjacent across regions.
    Trace trace;
    trace.action = [&](Event event, Memory) {
        if (event == Event::enter) f.span(f.node_base + 8, 0x80F0, 16);
    };
    const auto outcome = execute(f.memory(), f.profile, f.object, f.regions,
                                  {Operation::put, 0, 0, f.descriptor}, trace.callbacks());
    REQUIRE(outcome.disposition == Disposition::callback_contract_violation);
    REQUIRE(trace.events == std::vector<Event>{Event::enter});
    REQUIRE(f.read(f.node_base + 8) == 0x80F0 && f.read(f.node_base + 12) == 16);
    REQUIRE(f.read(f.object + 20) == f.node_base + 16); // No new node consumed/merge.
}

void exhaustion_reentry_does_not_retry() {
    Fixture f(1);
    f.one_queued(0);
    f.span(f.descriptor, 0x8300, 4);
    Trace trace;
    bool nested = false;
    trace.action = [&](Event event, Memory memory) {
        if (event == Event::error && !nested) {
            nested = true;
            const auto result = execute(memory, f.profile, f.object, f.regions,
                                          {Operation::get, 0, 8, f.descriptor + 16}, trace.callbacks());
            REQUIRE(result.disposition == Disposition::completed);
        }
    };
    const auto outcome = execute(f.memory(), f.profile, f.object, f.regions,
                                  {Operation::put, 1, 0, f.descriptor}, trace.callbacks());
    REQUIRE(outcome.disposition == Disposition::completed && nested);
    REQUIRE(trace.events == std::vector<Event>{Event::enter, Event::error, Event::enter, Event::leave, Event::leave});
    REQUIRE(f.read(f.object + 24) == 0 && f.read(f.object + 28) == 0);
    REQUIRE(f.read(f.object + 20) == f.node_base);
    REQUIRE(f.read(f.descriptor + 16) == 0x8100 && f.read(f.descriptor + 20) == 8);
    REQUIRE(f.read(f.node_base + 8) == 0x8100 && f.read(f.node_base + 12) == 8);
}

void input_is_reread_after_enter() {
    for (auto operation : {Operation::put, Operation::unget}) {
        Fixture f;
        Trace trace;
        trace.action = [&](Event event, Memory) {
            if (event == Event::enter) f.span(f.descriptor, 0x8200, 12);
        };
        const auto result = execute(f.memory(), f.profile, f.object, f.regions,
                                     {operation, 0, 0, f.descriptor}, trace.callbacks());
        REQUIRE(result.disposition == Disposition::completed);
        REQUIRE(f.read(f.node_base + 8) == 0x8200 && f.read(f.node_base + 12) == 12);
        REQUIRE(trace.events == std::vector<Event>{Event::enter, Event::leave});
    }
}

void invalidated_callback_state_never_falls_back() {
    for (int mutation = 0; mutation < 3; ++mutation) {
        Fixture f;
        Trace trace;
        trace.action = [&](Event event, Memory) {
            if (event != Event::enter) return;
            if (mutation == 0) f.write(f.object, 0); // Identity changed.
            if (mutation == 1) f.write(f.node_base + 32, f.node_base); // Cycle introduced.
            if (mutation == 2) f.span(f.descriptor, 0xDEAD0000, 8); // Unregistered new input.
        };
        const auto outcome = execute(f.memory(), f.profile, f.object, f.regions,
                                      {Operation::put, 0, 0, f.descriptor}, trace.callbacks());
        REQUIRE(outcome.disposition == Disposition::callback_contract_violation);
        REQUIRE(trace.events == std::vector<Event>{Event::enter});
        REQUIRE(f.read(f.object + 24) == 0); // Outer operation did not publish a node.
        if (mutation == 0) REQUIRE(f.read(f.object) == 0);
        if (mutation == 1) REQUIRE(f.read(f.node_base + 32) == f.node_base);
        if (mutation == 2) REQUIRE(f.read(f.descriptor) == 0xDEAD0000);
    }
}

void callback_output_writes_survive() {
    Fixture f;
    f.one_queued(0);
    Trace trace;
    trace.action = [&](Event event, Memory) {
        if (event == Event::leave) {
            REQUIRE(f.read(f.descriptor) == 0x8100 && f.read(f.descriptor + 4) == 8);
            f.span(f.descriptor, 0xFEEDBEEF, UINT32_MAX);
        }
    };
    const auto get = execute(f.memory(), f.profile, f.object, f.regions,
                              {Operation::get, 0, 8, f.descriptor}, trace.callbacks());
    REQUIRE(get.disposition == Disposition::completed);
    REQUIRE(f.read(f.descriptor) == 0xFEEDBEEF && f.read(f.descriptor + 4) == UINT32_MAX);
    trace.events.clear();
    f.write(f.descriptor, 123);
    trace.action = [&](Event event, Memory) {
        REQUIRE(event == Event::error);
        REQUIRE(f.read(f.descriptor) == 0);
        f.write(f.descriptor, 77);
    };
    const auto available = execute(f.memory(), f.profile, f.object, f.regions,
                                    {Operation::availability, 4, 10, f.descriptor}, trace.callbacks());
    REQUIRE(available.disposition == Disposition::completed && available.value == 0);
    REQUIRE(f.read(f.descriptor) == 77 && trace.events == std::vector<Event>{Event::error});
    trace.events.clear();
    f.span(f.descriptor, 0x1234, 567);
    trace.action = [&](Event event, Memory) {
        REQUIRE(event == Event::error);
        REQUIRE(f.read(f.descriptor) == 0x1234 && f.read(f.descriptor + 4) == 567);
        f.span(f.descriptor, 0x5678, 999);
    };
    const auto invalid_get = execute(f.memory(), f.profile, f.object, f.regions,
                                      {Operation::get, 4, 10, f.descriptor}, trace.callbacks());
    REQUIRE(invalid_get.disposition == Disposition::completed);
    REQUIRE(f.read(f.descriptor) == 0 && f.read(f.descriptor + 4) == 0);
}
} // namespace

int main() {
    try {
        image_admission_is_transactional();
        mirroring_preserves_external_words_and_stale_spans();
        invalid_selector_does_not_require_input_memory();
        unaligned_and_alias_descriptors_decline_without_effects();
        unsupported_regions_decline_without_effects();
        cross_region_adjacency_is_not_silently_changed();
        exhaustion_reentry_does_not_retry();
        input_is_reread_after_enter();
        invalidated_callback_state_never_falls_back();
        callback_output_writes_survive();
        std::cout << "SJUNI bridge: 10 adversarial groups passed; synthetic memory only\n";
        return 0;
    } catch (const std::exception& error) {
        std::cerr << "SJUNI bridge test failure: " << error.what() << '\n';
        return 1;
    }
}
