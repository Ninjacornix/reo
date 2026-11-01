#pragma once
#include "../../runtime/text/message_timing.h"
#include <array>
#include <cstring>

namespace reo::message_timing {
#if defined(REO_GAME_FILE2)
inline constexpr uint32_t timingAllocator = 0x1400d0, timingFront = 0x140210, timingFrontReturn = 0x1402a4;
inline constexpr uint32_t script = 0x6e7700, wrapper = 0x6e75c0, taskHandler = 0x6e43e0;
inline constexpr uint32_t scriptReturn = 0x6e7608, wrapperReturn = 0x6e4494;
inline constexpr std::array<uint32_t, 2> queueReturns{0x6e778c, 0x6e77e8};
inline constexpr uint32_t taskDurationLoad = 0x6e4474, taskDurationStore = 0x6e44a8;
#else
inline constexpr uint32_t timingAllocator = 0x1b46e0, timingFront = 0x1b4820, timingFrontReturn = 0x1b48b4;
inline constexpr uint32_t script = 0x6ba070, wrapper = 0x6b9f30, taskHandler = 0x6b6880;
inline constexpr uint32_t scriptReturn = 0x6b9f78, wrapperReturn = 0x6b6934;
inline constexpr std::array<uint32_t, 2> queueReturns{0x6ba0fc, 0x6ba158};
inline constexpr uint32_t taskDurationLoad = 0x6b6914, taskDurationStore = 0x6b6948;
#endif
inline uint32_t word(const uint8_t* ram, uint32_t address) {
    uint32_t value = 0;
    if (address <= PS2_RAM_SIZE - sizeof(value)) std::memcpy(&value, ram + address, sizeof(value));
    return value;
}
inline uint16_t half(const uint8_t* ram, uint32_t address) {
    uint16_t value = 0;
    if (address <= PS2_RAM_SIZE - sizeof(value)) std::memcpy(&value, ram + address, sizeof(value));
    return value;
}
inline bool call(const uint8_t* ram, uint32_t returnPc, uint32_t target) {
    return returnPc >= 8 && word(ram, returnPc - 8) == (0x0c000000u | (target >> 2));
}
struct Request {
    uint32_t task = 0;
    uint16_t original = 0, extended = 0;
};
inline Request request(const uint8_t* ram, uint32_t returnPc, uint32_t frontSp) {
    if (scale == 1000 || returnPc != timingFrontReturn || !call(ram, returnPc, timingAllocator) ||
        frontSp > PS2_RAM_SIZE - 0x134 || (frontSp & 15)) return {};
    // The resident allocator is shared by menus and speech. Require the entire
    // original timed-message task -> wrapper -> renderer -> enqueue frame chain.
    // Guest frames survive yields; host call-stack scopes do not.
    const uint32_t enqueueReturn = word(ram, frontSp + 0x60);
    if ((enqueueReturn != queueReturns[0] && enqueueReturn != queueReturns[1]) ||
        !call(ram, enqueueReturn, timingFront) ||
        word(ram, frontSp + 0xd0) != scriptReturn || !call(ram, scriptReturn, script) ||
        word(ram, frontSp + 0x100) != wrapperReturn || !call(ram, wrapperReturn, wrapper) ||
        word(ram, taskDurationLoad) != 0x8608000cu || word(ram, taskDurationStore) != 0xa603000cu)
        return {};
    const uint32_t task = word(ram, frontSp + 0xe0) & 0x1fffffffu;
    const uint32_t original = word(ram, frontSp + 0x120); // wrapper's saved TTL argument
    if (!task || (task & 3) || task > PS2_RAM_SIZE - 0x80 || ram[task + 8] != 0 ||
        half(ram, task + 0x10) != 0 || !original || original > 32767) return {};
    const auto extended = duration(original);
    const auto remaining = half(ram, task + 0x0c);
    // Later lines share the same original configuration, but the first successful
    // allocation may already have extended the task. Never multiply it again.
    if (remaining != original && remaining != extended) return {};
    return {task, static_cast<uint16_t>(original), extended};
}
inline void allocated(uint8_t* ram, const Request& pending, uint32_t slot) {
    if (!pending.task || slot > PS2_RAM_SIZE - 0x8c || half(ram, slot) != 1 ||
        half(ram, slot + 6) != pending.original || ram[pending.task + 8] != 0 ||
        half(ram, pending.task + 0x10) != 0) return;
    const auto remaining = half(ram, pending.task + 0x0c);
    if (remaining != pending.original && remaining != pending.extended) return;
    std::memcpy(ram + slot + 6, &pending.extended, 2);
    if (remaining == pending.original) std::memcpy(ram + pending.task + 0x0c, &pending.extended, 2);
}
}
