#include "../../network/native/ee_count_clock.h"

#include <atomic>
#include <chrono>
#include <cstdio>
#include <future>
#include <limits>
#include <thread>
#include <vector>

namespace {
int checks = 0, failures = 0;
void check(bool ok, const char* message) {
    ++checks;
    failures += !ok;
    std::printf("%s %s\n", ok ? "PASS" : "FAIL", message);
}

// Consumer fixture for the original SDK's Count -> microseconds conversion.
// The production clock implementation itself is included unchanged above.
class SdkTimer {
  public:
    explicit SdkTimer(uint32_t initial) : previous_(initial) {}
    uint64_t milliseconds(uint32_t count) {
        accumulated_ += uint32_t(count - previous_);
        previous_ = count;
        return accumulated_ / 300000;
    }

  private:
    uint32_t previous_;
    uint64_t accumulated_ = 0;
};
} // namespace

int main() {
    using reo_network::EeCountClock;
    using reo_network::ElapsedSecondsClock;
    using namespace std::chrono_literals;
    ElapsedSecondsClock seconds;
    const ElapsedSecondsClock::Clock::time_point epoch{};
    check(seconds.read(false, 0, epoch) == 0,
          "SDK seconds start at the existing accumulated value");
    check(seconds.read(false, 0, epoch + 250ms) < 0.26666668f,
          "ready queue remains gated before the original 266ms threshold");
    check(seconds.read(false, 0, epoch + 300ms) >= 0.26666668f,
          "advancing real seconds open the unchanged ready queue threshold");
    check(seconds.read(false, 999, epoch + 1500ms) == 1.5f,
          "repeated calls measure one shared epoch without accumulating caller values");
    check(seconds.read(true, 7, epoch + 2s) == 7,
          "SDK timer reset preserves an existing accumulated offset");
    check(seconds.read(false, 0, epoch + 2500ms) == 7.5f,
          "SDK timer advances from the reset epoch");
    check(seconds.read(true, 0, epoch + 3s) == 0,
          "new game initialization can reset the SDK timer to zero");
    struct Golden {
        uint64_t ns;
        uint32_t cycles;
    };
    // Independent arbitrary-precision reference values, including timestamps
    // that overflow a naive nanoseconds*frequency uint64 multiplication.
    constexpr Golden golden[] = {
        {0, 0},
        {3, 0},
        {4, 1},
        {1000, 294},
        {1000000, 294912},
        {1000000000, 294912000},
        {14600000000, 10747904},
        {10000000000000000000ull, 3489660928u},
        {std::numeric_limits<uint64_t>::max(), 850197365u},
    };
    for (const auto& sample : golden)
        check(EeCountClock::countAt(sample.ns) == sample.cycles,
              "Count agrees with independent exact boundary/reference value");

    constexpr uint64_t wrap = 14563555556ull;
    check(EeCountClock::countAt(wrap - 1) == 0xffffffffu && EeCountClock::countAt(wrap) == 0,
          "first 32-bit wrap occurs at the exact fractional-cycle boundary");
    SdkTimer wrapping(EeCountClock::countAt(wrap - 1000000));
    check(wrapping.milliseconds(EeCountClock::countAt(wrap + 40000000)) == 40,
          "SDK unsigned subtraction advances across Count wrap");

    SdkTimer deterministic(EeCountClock::countAt(0));
    check(!(17 < deterministic.milliseconds(EeCountClock::countAt(17000000))),
          "original 17ms send gate remains closed before enough EE cycles");
    check(17 < deterministic.milliseconds(EeCountClock::countAt(19000000)),
          "original 17ms send gate opens with advancing hardware time");
    check(deterministic.milliseconds(EeCountClock::countAt(1000000000)) == 983,
          "SDK divide300 keeps the authentic 294.912MHz conversion rate");

    EeCountClock clock;
    const auto first = clock.read();
    const auto wallStart = std::chrono::steady_clock::now();
    SdkTimer live(first);
    uint64_t sdkMs = 0;
    while (sdkMs <= 17 && std::chrono::steady_clock::now() - wallStart < std::chrono::seconds(2)) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        sdkMs = live.milliseconds(clock.read());
    }
    check(sdkMs > 17, "real steady-clock reads unblock the unchanged SDK send deadline");
    const auto wallMs = std::chrono::duration_cast<std::chrono::milliseconds>(
                            std::chrono::steady_clock::now() - wallStart)
                            .count();
    check(wallMs >= 17 && wallMs < 2000,
          "live send deadline obeys normal pacing and bounded completion");

    // Synchronized readers use the same clock, matching the runtime's shared
    // hardware source rather than inventing a new epoch for each guest thread.
    std::atomic<uint32_t> baseline{clock.read()};
    std::vector<std::future<bool>> readers;
    for (unsigned i = 0; i < 8; ++i)
        readers.push_back(std::async(std::launch::async, [&] {
            const auto before = clock.read();
            std::this_thread::sleep_for(std::chrono::milliseconds(3));
            const auto after = clock.read();
            return int32_t(before - baseline.load()) >= 0 && uint32_t(after - before) > 0;
        }));
    bool shared = true;
    for (auto& reader : readers)
        shared &= reader.get();
    check(shared, "all eight concurrent readers share advancing hardware time");
    std::printf("%d/%d checks passed\n", checks - failures, checks);
    return failures ? 1 : 0;
}
