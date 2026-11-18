#include "game/native/animation/frame_events.hpp"
#include "reference.hpp"
#include <iostream>
#include <vector>
namespace a = reo::native::animation;
#include "functions.h"
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#include "original.cpp"
#pragma GCC diagnostic pop
std::uint64_t checks{}, cases{};
void check(bool value, const char* why) {
    ++checks;
    if (!value)
        throw std::runtime_error(why);
}
template <class T> void put(std::uint8_t* p, unsigned at, T v) {
    transform_write(p, at, v);
}
int main() try {
    const auto old = _mm_getcsr();
    struct Reset {
        unsigned value;
        ~Reset() {
            _mm_setcsr(value);
        }
    } reset{old};
    _mm_setcsr(0x1f80);
    std::vector<std::uint8_t> ram(0x2000000);
    R5900Context ctx;
    PS2Runtime runtime;
    constexpr unsigned actor = 0x100000;
    const std::array<float, 8> current{0, 1, 10, 99, 25.5f, 500, -3, -2.25f},
        ends{1, 1, 10, 100, 30, 503, 1, 2}, starts{0, 0, 1, 10, 5, 499, -5, 0},
        steps{0, .125f, 1, 2, -1, 100, -2, .25f};
    for (unsigned flags = 0; flags < 256; ++flags)
        for (unsigned loop = 0; loop < 256; ++loop)
            for (unsigned clock : {0u, 1u, 2u, 255u})
                for (unsigned bank : {0u, 1u})
                    for (unsigned shape = 0; shape < 8; ++shape) {
                        a::FrameRecord record{current[shape], ends[shape], starts[shape],
                                              std::bit_cast<std::int8_t>(std::uint8_t(loop)),
                                              std::uint8_t(flags)};
                        const float step = steps[shape], target = shape % 4 == 0   ? record.frame
                                                                  : shape % 4 == 1 ? record.end
                                                                  : shape % 4 == 2
                                                                      ? record.restart
                                                                      : record.frame + step * .5f;
                        const unsigned at = actor + 0x1e4 + 32 * bank;
                        put(ram.data(), at, record.frame);
                        put(ram.data(), at + 4, record.end);
                        put(ram.data(), at + 8, record.restart);
                        put(ram.data(), at + 12, record.loop);
                        put(ram.data(), at + 13, record.flags);
                        ram[0x3243cc] = std::uint8_t(clock);
                        std::array<std::uint8_t, 14> before{};
                        std::memcpy(before.data(), ram.data() + at, 14);
                        ctx.pc = 0x573480;
                        SET_GPR_U32(&ctx, 4, actor);
                        SET_GPR_U32(&ctx, 5, bank);
                        SET_GPR_U32(&ctx, 31, 0xabcdef);
                        ctx.f[12] = target;
                        ctx.f[13] = step;
                        o2_00573480_0x573480(ram.data(), &ctx, &runtime);
                        const bool native =
                            a::crosses_frame(record, target, step, std::uint8_t(clock));
                        check(ctx.pc == 0xabcdef && native == (GPR_U32(&ctx, 2) != 0),
                              "full original frame crossing result");
                        check(std::memcmp(before.data(), ram.data() + at, 14) == 0,
                              "crossing observes timing without advancing or mutating channel");
                        ++cases;
                    }
    a::FrameRecord unused{1, std::numeric_limits<float>::quiet_NaN(),
                          std::numeric_limits<float>::quiet_NaN(), 0, 0};
    check(a::crosses_frame(unused, 1, 1, 0), "nonlooping window doesnotreadunusedend/restart");
    unused.flags = 0x10;
    unused.frame = std::numeric_limits<float>::quiet_NaN();
    check(!a::crosses_frame(unused, unused.frame, unused.frame, 1),
          "frozen window returnsbeforeunusednumericreads");
    a::FrameRecord invalid{0, 10, 0, 0, 0};
    bool refused{};
    try {
        (void)a::crosses_frame(invalid, std::numeric_limits<float>::infinity(), 1, 0);
    } catch (const std::domain_error&) {
        refused = true;
    }
    check(refused, "used exceptionalnumericprofile explicitly refused");
    std::cout << "{\"checks\":" << checks << ",\"crossing_cases\":" << cases
              << ",\"raw_loop_patterns\":256,\"raw_flag_patterns\":256,\"game_run\":false}\n";
} catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    return 1;
}
