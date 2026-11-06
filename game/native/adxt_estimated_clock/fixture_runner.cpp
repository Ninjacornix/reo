// Authored scalar observations and controls only; no expected result is read.
#include "estimated_clock.hpp"
#include <bit>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
namespace c = reo::native::adxt_estimated_clock;
struct Observer {
    struct Record { c::Event kind; c::Stream stream; c::integer::Mode mode; std::uint32_t drift; };
    std::vector<Record> events;
    static void observe(void* p, c::Event event, c::Stream stream, const c::Shared& shared) noexcept {
        static_cast<Observer*>(p)->events.push_back({event, stream, shared.mode, shared.drift_bits});
    }
};
int main(int argc, char** argv) {
    if (argc != 2) return 2;
    std::ifstream input(argv[1]);
    auto word = [&]() { std::uint64_t value{}; input >> value; return static_cast<std::uint32_t>(value); };
    c::Shared shared; shared.mode = {word(),word(),word()}; shared.rebase_selector = word(); shared.service_busy = word(); shared.drift_bits = word();
    c::Stream stream{word(),word(),static_cast<std::uint8_t>(word()),0};
    c::integer::Observation o; o.state = static_cast<std::uint8_t>(word()); o.decoded = word(); o.total = word(); o.frequency = word();
    o.base = word(); o.offset = word(); o.depth_mode = std::bit_cast<std::int16_t>(static_cast<std::uint16_t>(word()));
    o.depth_code = std::bit_cast<std::int16_t>(static_cast<std::uint16_t>(word())); o.output_present = word() != 0; o.output_bytes = word(); o.rna_free_bytes = word();
    Observer observer; observer.events.reserve(16); c::Clock clock(shared, stream, {&observer, Observer::observe});
    std::uint32_t output = 0x5a5a5a5a, denominator = output; std::string operation;
    while (input >> operation) {
        const auto tick = word(), argument = word(); observer.events.clear(); c::Result result;
        if (operation == "estimate") { result = clock.estimate(o,tick); if (result.status == c::Status::completed) { output = result.ratio.numerator; denominator = result.ratio.denominator; } }
        else if (operation == "centiseconds") result = clock.centiseconds(o,tick);
        else if (operation == "pause") result.status = clock.pause(o,std::bit_cast<std::int32_t>(argument),tick);
        else if (operation == "discard_rebase") result.status = clock.discard_rebase(o,tick);
        else return 3;
        const auto state = clock.snapshot();
        std::cout << "{\"status\":" << static_cast<unsigned>(result.status) << ",\"projection\":{\"output_u32\":" << output << ",\"denominator_u32\":" << denominator
            << ",\"estimate_base_u32\":" << state.estimate_base << ",\"tick_base_u32\":" << state.tick_base << ",\"paused_byte\":" << unsigned(state.paused)
            << ",\"rna_play_byte\":" << unsigned(state.rna_play) << ",\"mode_u32\":" << shared.mode.selection << ",\"counter_u32\":" << shared.mode.resynchronizations
            << ",\"drift_bits_u32\":" << shared.drift_bits << "},\"value\":" << result.value << ",\"events\":[";
        for (std::size_t i = 0; i < observer.events.size(); ++i) {
            if (i) std::cout << ',';
            const auto& e = observer.events[i];
            std::cout << "{\"kind\":" << static_cast<unsigned>(e.kind) << ",\"estimate_base_u32\":" << e.stream.estimate_base
                << ",\"tick_base_u32\":" << e.stream.tick_base << ",\"paused_byte\":" << unsigned(e.stream.paused)
                << ",\"rna_play_byte\":" << unsigned(e.stream.rna_play) << ",\"mode_u32\":" << e.mode.selection
                << ",\"counter_u32\":" << e.mode.resynchronizations << ",\"drift_bits_u32\":" << e.drift << '}';
        }
        std::cout << "]}\n";
    }
    return input.eof() ? 0 : 4;
}
