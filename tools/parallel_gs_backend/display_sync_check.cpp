#include "presentation_mode.h"
#include <iostream>
#include <limits>
#include <stdexcept>

using namespace reo::display_sync;
static unsigned checks;
static void require(bool condition, const char* why) {
    ++checks;
    if (!condition)
        throw std::runtime_error(why);
}
int main() try {
    require(parse(nullptr) == Mode::On && parse("") == Mode::On && parse("broken") == Mode::On,
            "Missing/invalid preferences must enable VSync");
    require(parse("off") == Mode::Off && parse("adaptive") == Mode::Adaptive,
            "Explicit preferences must be preserved");
    require(swapInterval(Mode::Off, true) == 0 && swapInterval(Mode::On, true) == 1 &&
                swapInterval(Mode::Adaptive, true) == -1 &&
                swapInterval(Mode::Adaptive, false) == 1,
            "OpenGL adaptive requires the tear extension");
    for (double refresh : {60., 120., 144.}) {
        Adaptive policy;
        double time = 10.;
        require(policy.synchronized(Mode::Adaptive, time, refresh), "First frame must synchronize");
        for (unsigned i = 0; i < 20; ++i) {
            time += 1. / refresh;
            require(policy.synchronized(Mode::Adaptive, time, refresh),
                    "At-refresh jitter must not tear");
        }
        time += 2. / refresh;
        require(!policy.synchronized(Mode::Adaptive, time, refresh),
                "Late frames should allow tearing");
        time += 1.02 / refresh;
        require(!policy.synchronized(Mode::Adaptive, time, refresh),
                "Hysteresis should prevent toggling");
        time += 1. / refresh;
        require(policy.synchronized(Mode::Adaptive, time, refresh),
                "Recovered cadence must synchronize");
        time += 2. / refresh;
        require(policy.synchronized(Mode::On, time, refresh),
                "On must synchronize even at low FPS");
        require(!policy.synchronized(Mode::Off, time + .001, refresh),
                "Off must never synchronize");
        require(policy.synchronized(Mode::Adaptive, time + .002, 0),
                "Unknown refresh must fall back to On");
    }
    Adaptive ntsc;
    double time = 0;
    for (unsigned i = 0; i < 120; ++i) {
        time += 1001. / 60000.;
        require(ntsc.synchronized(Mode::Adaptive, time, 60),
                "59.94 Hz game should synchronize at 60 Hz");
    }
    require(ntsc.synchronized(Mode::Adaptive, std::numeric_limits<double>::quiet_NaN(), 60),
            "Invalid timestamps must fall back to On");
    require(ntsc.synchronized(Mode::Adaptive, 100, 60), "Invalid samples must not poison recovery");
    using reo_gpu_present::selectPresentMode;
    const std::vector<VkPresentModeKHR> all{VK_PRESENT_MODE_FIFO_KHR, VK_PRESENT_MODE_IMMEDIATE_KHR,
                                            VK_PRESENT_MODE_FIFO_RELAXED_KHR,
                                            VK_PRESENT_MODE_MAILBOX_KHR};
    require(selectPresentMode(Mode::On, all) == VK_PRESENT_MODE_FIFO_KHR,
            "Vulkan On must use FIFO");
    require(selectPresentMode(Mode::Off, all) == VK_PRESENT_MODE_IMMEDIATE_KHR,
            "Vulkan Off prefers immediate");
    require(selectPresentMode(Mode::Adaptive, all) == VK_PRESENT_MODE_FIFO_RELAXED_KHR,
            "Vulkan adaptive must use relaxed FIFO");
    for (Mode mode : {Mode::On, Mode::Off, Mode::Adaptive})
        require(selectPresentMode(mode, {VK_PRESENT_MODE_FIFO_KHR}) == VK_PRESENT_MODE_FIFO_KHR,
                "Unsupported present modes must fall back to FIFO");
    require(selectPresentMode(Mode::Off, {VK_PRESENT_MODE_FIFO_KHR, VK_PRESENT_MODE_MAILBOX_KHR}) ==
                VK_PRESENT_MODE_MAILBOX_KHR,
            "Off can fall back to mailbox");
    std::cout << "PASS " << checks << " display sync checks\n";
    return 0;
} catch (const std::exception& error) {
    std::cerr << error.what() << '\n';
    return 1;
}
