#include <vector>
#import <Cocoa/Cocoa.h>
#import <GameController/GameController.h>
#include "macos_input.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <mutex>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <atomic>
#import <CoreHaptics/CoreHaptics.h>

namespace reo::macos_input {
bool display_available() {
    uint32_t count=0;if(CGGetOnlineDisplayList(0,nullptr,&count)!=kCGErrorSuccess||!count)return false;
    std::vector<CGDirectDisplayID> displays(count);if(CGGetOnlineDisplayList(count,displays.data(),&count)!=kCGErrorSuccess)return false;
    for(uint32_t i=0;i<count;++i)if(!CGDisplayIsAsleep(displays[i]))return true;
    return false;
}

namespace {
std::mutex mutex;
std::array<DualShock2State, 2> controllers{};
DualShock2State keyboard{};
std::array<bool, 256> keys{}; // Accessed only on the AppKit thread.
bool focused = false;
std::atomic<uint32_t> motors{0};
struct Configuration {
    std::array<int, 16> key{51,6,7,36,13,2,1,0,20,21,18,19,15,14,49,12};
    std::array<int, 16> mapping{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    std::array<int,4> camera{126,125,123,124};
    bool swapSticks = false, invertRightY = false;
    float deadzone = .15f;
    int device = -1; // -1 auto, -2 keyboard, otherwise controller index.
    bool rumble = true;
    Configuration() {
        auto parse = [](const char* name, auto& result, int maximum) {
            const char* value = std::getenv(name);
            if (!value) return;
            auto parsed = result;
            for (unsigned i = 0; i < parsed.size(); ++i) {
                char* end = nullptr;
                long number = std::strtol(value, &end, 10);
                if (end == value || number < 0 || number > maximum ||
                    (i + 1 < parsed.size() ? *end != ',' : *end != 0)) return;
                parsed[i] = int(number);
                value = end + (i + 1 < parsed.size());
            }
            result = parsed;
        };
        parse("REO_MACOS_KEYS", key, 256);
        parse("REO_MACOS_CAMERA_KEYS", camera, 256);
        if (const char* value = std::getenv("REO_MACOS_SWAP_STICKS")) swapSticks = *value == '1';
        if (const char* value = std::getenv("REO_MACOS_INVERT_RIGHT_Y")) invertRightY = *value == '1';
        parse("REO_MACOS_PAD_MAPPING", mapping, 16);
        if (const char* value = std::getenv("REO_MACOS_DEADZONE"))
            deadzone = std::clamp(std::atoi(value), 0, 30) / 100.0f;
        if (const char* value = std::getenv("REO_MACOS_INPUT_DEVICE")) {
            if (std::strcmp(value, "keyboard") == 0) device = -2;
            else if (std::strcmp(value, "auto") != 0) device = std::clamp(std::atoi(value), 0, 3);
        }
        if (const char* value = std::getenv("REO_MACOS_RUMBLE")) rumble = *value != '0';
    }
};
const Configuration& config() { static const Configuration value; return value; }
constexpr int pressureBits[12] = {5,7,4,6,12,13,14,15,10,11,8,9};
DualShock2State remap(const DualShock2State& source) {
    auto target = source;
    target.buttons = 0xffff;
    for (int i = 0; i < 16; ++i)
        if (config().mapping[i] < 16 && !(source.buttons & (1u << config().mapping[i]))) target.buttons &= ~(1u << i);
    for (int i = 0; i < 12; ++i) {
        const int sourceBit = config().mapping[pressureBits[i]];
        target.pressure[i] = (target.buttons & (1u << pressureBits[i])) ? 0 : 255;
        for (int j = 0; j < 12; ++j)
            if (pressureBits[j] == sourceBit) target.pressure[i] = source.pressure[j];
    }
    if (config().swapSticks) { std::swap(target.left_x,target.right_x); std::swap(target.left_y,target.right_y); }
    if (config().invertRightY) target.right_y = target.right_y == 128 ? 128 : uint8_t(255-target.right_y);
    return target;
}
void haptics(GCController* controller, uint32_t value) {
    static GCController* previous = nil;
    static CHHapticEngine* engine = nil;
    static double last = 0;
    static uint32_t sent = 0;
    if (!controller || !config().rumble) value = 0;
    if (controller != previous) {
        [engine stopWithCompletionHandler:nil];
        previous = controller;
        engine = [controller.haptics createEngineWithLocality:GCHapticsLocalityDefault];
        last = 0;
    }
    const double now = [NSDate timeIntervalSinceReferenceDate];
    if (!engine || (value == sent && now - last < .12)) return;
    last = now; sent = value;
    if (!value) return; // Patterns expire after .14s, including on focus loss.
    const float intensity = std::max(value & 65535u, value >> 16) / 65535.0f;
    if (![engine startAndReturnError:nil]) return;
    CHHapticEventParameter* level = [[CHHapticEventParameter alloc]
        initWithParameterID:CHHapticEventParameterIDHapticIntensity value:intensity];
    CHHapticEvent* event = [[CHHapticEvent alloc] initWithEventType:CHHapticEventTypeHapticContinuous
        parameters:@[level] relativeTime:0 duration:.14];
    CHHapticPattern* pattern = [[CHHapticPattern alloc] initWithEvents:@[event] parameters:@[] error:nil];
    id<CHHapticPatternPlayer> player = [engine createPlayerWithPattern:pattern error:nil];
    [player startAtTime:CHHapticTimeImmediate error:nil];
}

void button(DualShock2State& pad, PS2Button bit, bool pressed, int pressure = -1,
            float value = 1.0f) {
    if (pressed)
        pad.buttons &= ~bit;
    if (pressure >= 0)
        pad.pressure[pressure] = static_cast<uint8_t>(std::lround(std::clamp(value, 0.0f, 1.0f) * 255));
}

uint8_t axis(float value) {
    // Preserve exact neutral 128 and endpoints 0/255.
    if (std::abs(value) <= config().deadzone)
        return 128;
    return static_cast<uint8_t>(std::clamp(std::lround(128.0f + value * (value < 0 ? 128.0f : 127.0f)), 0l, 255l));
}
}

void capture() {
    if (![NSThread isMainThread])
        return;
    static id monitor = [NSEvent addLocalMonitorForEventsMatchingMask:NSEventMaskKeyDown | NSEventMaskKeyUp
        handler:^NSEvent*(NSEvent* event) {
            if (event.keyCode < keys.size())
                keys[event.keyCode] = event.type == NSEventTypeKeyDown &&
                    !(event.modifierFlags & NSEventModifierFlagCommand);
            return event;
        }];
    (void)monitor;
    const bool active = NSApp.active;
    if (!active)
        keys.fill(false);
    std::array<DualShock2State, 2> pads;
    for (auto& pad : pads)
        pad.reset();
    unsigned port = 0, index = 0;
    GCController* primary = nil;
    if (active && config().device != -2) {
        for (GCController* controller in GCController.controllers) {
            GCExtendedGamepad* gamepad = controller.extendedGamepad;
            if (!gamepad) continue;
            const unsigned current = index++;
            if (config().device >= 0 && current != unsigned(config().device)) continue;
            if (port >= pads.size()) break;
            if (port == 0) primary = controller;
            auto& pad = pads[port++];
            button(pad, PS2_UP, gamepad.dpad.up.pressed, 2, gamepad.dpad.up.value);
            button(pad, PS2_DOWN, gamepad.dpad.down.pressed, 3, gamepad.dpad.down.value);
            button(pad, PS2_LEFT, gamepad.dpad.left.pressed, 1, gamepad.dpad.left.value);
            button(pad, PS2_RIGHT, gamepad.dpad.right.pressed, 0, gamepad.dpad.right.value);
            button(pad, PS2_CROSS, gamepad.buttonA.pressed, 6, gamepad.buttonA.value);
            button(pad, PS2_CIRCLE, gamepad.buttonB.pressed, 5, gamepad.buttonB.value);
            button(pad, PS2_SQUARE, gamepad.buttonX.pressed, 7, gamepad.buttonX.value);
            button(pad, PS2_TRIANGLE, gamepad.buttonY.pressed, 4, gamepad.buttonY.value);
            button(pad, PS2_L1, gamepad.leftShoulder.pressed, 8, gamepad.leftShoulder.value);
            button(pad, PS2_R1, gamepad.rightShoulder.pressed, 9, gamepad.rightShoulder.value);
            button(pad, PS2_L2, gamepad.leftTrigger.value > 0.12f, 10, gamepad.leftTrigger.value);
            button(pad, PS2_R2, gamepad.rightTrigger.value > 0.12f, 11, gamepad.rightTrigger.value);
            button(pad, PS2_START, gamepad.buttonMenu.pressed);
            button(pad, PS2_SELECT, gamepad.buttonOptions.pressed);
            button(pad, PS2_L3, gamepad.leftThumbstickButton.pressed);
            button(pad, PS2_R3, gamepad.rightThumbstickButton.pressed);
            pad.left_x = axis(gamepad.leftThumbstick.xAxis.value);
            pad.left_y = axis(-gamepad.leftThumbstick.yAxis.value);
            pad.right_x = axis(gamepad.rightThumbstick.xAxis.value);
            pad.right_y = axis(-gamepad.rightThumbstick.yAxis.value);
        }
    }
    DualShock2State keyPad;
    keyPad.reset();
    auto keyDown = [&](int code) { return code >= 0 && unsigned(code) < keys.size() && keys[code]; };
    for (unsigned bit = 0; bit < 16; ++bit)
        if (keyDown(config().key[bit])) keyPad.buttons &= ~(1u << bit);
    keyPad.right_x = keyDown(config().camera[2]) ? 0 : keyDown(config().camera[3]) ? 255 : 128;
    keyPad.right_y = keyDown(config().camera[0]) ? 0 : keyDown(config().camera[1]) ? 255 : 128;
    static constexpr PS2Button pressureButtons[] = {PS2_RIGHT, PS2_LEFT, PS2_UP, PS2_DOWN,
        PS2_TRIANGLE, PS2_CIRCLE, PS2_CROSS, PS2_SQUARE, PS2_L1, PS2_R1, PS2_L2, PS2_R2};
    for (unsigned i = 0; i < 12; ++i)
        keyPad.pressure[i] = (keyPad.buttons & pressureButtons[i]) ? 0 : 255;
    haptics(primary, active ? motors.load(std::memory_order_relaxed) : 0);
    std::lock_guard lock(mutex);
    for (auto& pad : pads) pad = remap(pad);
    controllers = pads;
    keyboard = keyPad;
    focused = active;
}

void rumble(uint32_t value) { motors.store(value, std::memory_order_relaxed); }

DualShock2State read(int port, bool includeKeyboard) {
    std::lock_guard lock(mutex);
    DualShock2State result;
    result.reset();
    if (!focused)
        return result;
    result = controllers[port & 1];
    if ((port & 1) == 0 && includeKeyboard && config().device < 0) {
        result.buttons &= keyboard.buttons;
        for (unsigned i = 0; i < 12; ++i)
            result.pressure[i] = std::max(result.pressure[i], keyboard.pressure[i]);
        if (keyboard.right_x != 128)
            result.right_x = keyboard.right_x;
        if (keyboard.right_y != 128)
            result.right_y = keyboard.right_y;
    }
    return result;
}
}
