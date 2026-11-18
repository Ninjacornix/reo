#include "original_fixture.hpp"
#include "original_declarations.inc"
#include <iostream>
#include <source_location>
#include <vector>

namespace {
std::size_t checks{}, calls{}, cases{};
void check(bool value, std::source_location at = std::source_location::current()) {
    ++checks;
    if (!value) throw std::runtime_error("Script closure check at " + std::to_string(at.line()));
}
struct Result { std::uint32_t pc{}, ordinal{}; };
}

void original_transform_port(std::uint8_t* bytes, R5900Context* context, PS2Runtime* runtime) {
    if (context->pc != 0x68c990) throw std::runtime_error("Unexpected original scanner dependency");
    o2_0068C990_0x68c990(bytes, context, runtime);
}

int main() try {
    std::vector<std::uint8_t> ram(0x2000000);
    original_constants(ram.data());
    constexpr std::uint32_t script = 0x1000000, returned = 0x1000;
    constexpr std::array<std::uint32_t, 10> ordinals{
        0, 1, 2, 63, 20000, 0x7fffffff, 0x80000000, 0xfffffffe, 0xffffffff, 0xf1377bd9};
    for (const auto channel : {0u, 1u, 4u, 5u})
        for (const bool failed : {false, true})
            for (const auto depth : {0u, 1u, 2u, 7u, 31u, 63u})
                for (const auto ending : {0xe4u, 0xe5u, 0xau, 0xdu}) {
                    // The scanners read only record headers. Include every
                    // original opener, nested else/endif pairs and both yield
                    // terminators, using the owned opener table below.
                    std::vector<std::uint32_t> words{failed ? 8u : 0xe4u};
                    for (unsigned i = 0; i < depth; ++i)
                        words.push_back(transform_read<std::uint32_t>(ram.data(), 0x717600 + 4 * (i % 32)));
                    for (unsigned i = 0; i < depth; ++i) {
                        words.push_back(0xe4);
                        words.push_back(0xe5);
                    }
                    words.push_back(ending);
                    words.push_back(0xe5); // else-scan skips a top-level E4.
                    words.push_back(0xa);
                    for (std::size_t i = 0; i < words.size(); ++i)
                        transform_write(ram.data(), script + std::uint32_t(i * 4), words[i]);
                    const auto run = [&](std::uint32_t ordinal) {
                        R5900Context context;
                        PS2Runtime runtime;
                        SET_GPR_U32(&context, 29, 0x1f00000);
                        SET_GPR_U32(&context, 31, returned);
                        transform_write(ram.data(), 0x4badc1, std::uint8_t(channel));
                        transform_write(ram.data(), 0x4bace0 + 4 * channel, script);
                        transform_write(ram.data(), 0x4bad58 + 4 * channel, ordinal);
                        if (failed) o2_0068C9E0_0x68c9e0(ram.data(), &context, &runtime);
                        else o2_0068CBE0_0x68cbe0(ram.data(), &context, &runtime);
                        ++calls;
                        check(context.pc == returned);
                        return Result{transform_read<std::uint32_t>(ram.data(), 0x4bace0 + 4 * channel),
                                      transform_read<std::uint32_t>(ram.data(), 0x4bad58 + 4 * channel)};
                    };
                    const auto base = run(0);
                    check(base.pc >= script && base.pc < script + words.size() * 4);
                    const bool reset = ending == 0xa || ending == 0xd;
                    for (const auto ordinal : ordinals) {
                        const auto actual = run(ordinal);
                        check(actual.pc == base.pc);
                        check(actual.ordinal == (reset ? 0u : base.ordinal + ordinal));
                        ++cases;
                    }
                }
    std::cout << "{\"cases\":" << cases << ",\"checks\":" << checks
              << ",\"original_calls\":" << calls << "}\n";
} catch (const std::exception& error) {
    std::cerr << error.what() << '\n';
    return 1;
}
