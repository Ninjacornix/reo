#include "runtime/gs/performance.h"
#include <iostream>
#include <stdexcept>
using namespace reo::performance;
static unsigned checks = 0;
static void require(bool value) {
    ++checks;
    if (!value) throw std::runtime_error("Performance meter check failed");
}
int main() try {
    UpdateTracker tracker;
    require(tracker.observe(0));
    require(!tracker.observe(0)); // Other actors in the same guest frame.
    require(tracker.observe(1));
    require(!tracker.observe(1));
    require(tracker.observe(0xffffffffu));
    require(tracker.observe(0)); // Wrap/reset counts once, not billions of updates.
    require(!tracker.observe(0));
    Meter display;
    display.sample(0, 0, 0);
    auto reading = display.sample(1000000000ull, 60, 30);
    require(reading.fps == 600 && reading.frameMs == 167 && reading.ups == 300);
    reading = display.sample(2000000000ull, 120, 30);
    require(reading.fps == 600 && reading.frameMs == 167 && reading.ups == 0);
    reading = display.sample(3000000000ull, 150, 60);
    require(reading.fps == 300 && reading.frameMs == 333 && reading.ups == 300);
    reading = display.sample(6000000000ull, 151, 61);
    require(reading.fps == 3 && reading.frameMs == 30000 && reading.ups == 3);
    Meter warming;
    require(warming.sample(100, 0, 0).fps == 0);
    require(warming.sample(200000100, 12, 6).fps == 0);
    reading = warming.sample(1000000100, 60, 30);
    require(reading.fps == 600 && reading.ups == 300);
    std::cout << "PASS " << checks << " performance checks\n";
    return 0;
} catch (const std::exception& error) {
    std::cerr << error.what() << '\n'; return 1;
}
