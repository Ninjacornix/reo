#pragma once
#include "palette_source_join.hpp"
#include "palette_dma_origin.h"
#include "ps2_syscalls.h"
#include <filesystem>
#include <fstream>
#include <array>
#include <mutex>
#include <cstdlib>
#include <cstdio>
namespace reo_palette_observer {
using Fn = void (*)(uint8_t*, R5900Context*, PS2Runtime*);
constexpr unsigned MaxCalls = 128, MaxAllocations = 16, MaxParents = 16, MaxUnpacks = 128;
constexpr uint32_t ParentPCs[9]{0x19bbd0, 0x19bbfc, 0x19bcfc, 0x19bd2c, 0x19bd50,
                                0x19bd9c, 0x19bdb4, 0x19be54, 0x19be64};
struct Allocation {
    const void* memory = nullptr;
    R5900Context* context = nullptr;
    uint64_t generation = 0;
    uint32_t packet = 0, bytes = 0, descriptor = 0, parent = 0, sp = 0, returnPC = 0,
             outerReturnPC = 0;
    int32_t task = -1;
    bool complete = false;
};
struct PendingAllocator {
    PS2Runtime* runtime = nullptr;
    R5900Context* context = nullptr;
    uint32_t sp = 0, ret = 0, descriptor = 0, parent = 0;
    int32_t task = -1;
    bool active = false;
};
struct Capture {
    std::recursive_mutex mutex;
    bool enabled = false, originExhausted = false;
    unsigned calls = 0, parents = 0, unpacks = 0, allocationCount = 0;
    uint64_t nextGeneration = 1;
    Fn originalMath = nullptr, originalAllocator = nullptr, originalParent = nullptr,
       originalLegacy = nullptr;
    std::array<Allocation, MaxAllocations> allocations{};
    std::array<PendingAllocator, MaxParents> pending{};
    std::filesystem::path directory;
    std::ofstream log;
};
inline Capture capture;
inline int32_t task(PS2Runtime* runtime, const R5900Context* ctx) {
    if (!runtime || !ctx)
        return -1;
    R5900Context local;
    std::memcpy(&local, ctx, sizeof(local));
    ps2_syscalls::GetThreadId(nullptr, &local, runtime);
    return int32_t(reo_palette_join::gpr(local, 2));
}
inline void save(const std::string& name, const void* bytes, size_t size) {
    if (!capture.enabled)
        return;
    const auto path = capture.directory / name;
    if (std::filesystem::exists(path))
        return;
    std::ofstream file(path, std::ios::binary);
    file.write(static_cast<const char*>(bytes), size);
}
inline Allocation* allocated(const void* memory, uint32_t packet) {
    for (unsigned n = capture.allocationCount; n; --n) {
        auto& a = capture.allocations[n - 1];
        if (a.memory == memory && a.packet == packet)
            return &a;
    }
    return nullptr;
}
inline uint64_t allocationFor(const void* memory, uint32_t address, uint32_t bytes, bool scratch) {
    std::lock_guard<std::recursive_mutex> l(capture.mutex);
    if (!capture.enabled || capture.originExhausted || scratch)
        return 0;
    for (unsigned n = capture.allocationCount; n; --n) {
        const auto& a = capture.allocations[n - 1];
        if (a.memory == memory && address >= a.packet &&
            uint64_t(address) + bytes <= uint64_t(a.packet) + a.bytes)
            return a.generation;
    }
    return 0;
}
inline void unpack(const void* memory, uint32_t command, uint32_t tops, const uint8_t* raw,
                   uint32_t bytes, const reo_palette_origin::Spans& spans) {
    std::lock_guard<std::recursive_mutex> l(capture.mutex);
    if (!capture.enabled || capture.unpacks >= MaxUnpacks || command != 0x6cf80000u ||
        bytes != 3968)
        return;
    uint32_t cursor = 0, guest = 0;
    uint64_t generation = 0;
    bool contiguous = !spans.empty();
    for (const auto& s : spans) {
        if (s.offset != cursor || s.scratch || !s.allocation) {
            contiguous = false;
            break;
        }
        if (!cursor) {
            guest = s.address;
            generation = s.allocation;
        }
        if (s.address != guest + cursor || s.allocation != generation) {
            contiguous = false;
            break;
        }
        cursor += s.bytes;
    }
    contiguous = contiguous && cursor == bytes;
    const unsigned index = capture.unpacks++;
    capture.log << "{\"kind\":\"actual_unpacked_source\",\"index\":" << index
                << ",\"memory\":" << uintptr_t(memory) << ",\"source\":" << guest
                << ",\"bytes\":" << bytes << ",\"generation\":" << generation
                << ",\"contiguous\":" << (contiguous ? "true" : "false") << ",\"tops\":" << tops
                << ",\"guest_writes\":false}\n";
    if (contiguous)
        save("unpack-" + std::to_string(index) + ".raw.bin", raw, bytes);
    capture.log.flush();
}
inline void math(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) {
    const auto original = capture.originalMath;
    if (!original)
        std::terminate();
    reo_palette_join::ImmutableCall input{};
    unsigned index = MaxCalls;
    uint64_t generation = 0;
    int32_t tid = -1;
    try {
        std::lock_guard<std::recursive_mutex> l(capture.mutex);
        if (capture.enabled && capture.calls < MaxCalls && runtime && ctx &&
            reo_palette_join::captureBeforeMath(ram, runtime->memory().getScratchpad(), *ctx,
                                                input)) {
            index = capture.calls++;
            tid = task(runtime, ctx);
            const auto* a = allocated(&runtime->memory(), input.metadata.packet);
            generation = a ? a->generation : 0;
            const std::string stem = "call-" + std::to_string(index);
            save(stem + ".input.bin", &input, sizeof(input));
            capture.log << "{\"kind\":\"1994_entry\",\"index\":" << index
                        << ",\"generation\":" << generation << ",\"task\":" << tid
                        << ",\"runtime\":" << uintptr_t(runtime)
                        << ",\"context\":" << uintptr_t(ctx)
                        << ",\"stack\":" << reo_palette_join::gpr(*ctx, 29)
                        << ",\"parent\":" << input.metadata.parent
                        << ",\"descriptor\":" << input.metadata.descriptor
                        << ",\"packet\":" << input.metadata.packet
                        << ",\"bone\":" << input.metadata.bone
                        << ",\"mask\":" << input.metadata.mask
                        << ",\"RA\":" << input.metadata.returnPC
                        << ",\"input_is_actual_pre_math_SPR\":true,\"guest_writes\":false}\n";
            capture.log.flush();
        }
    } catch (...) {
        index = MaxCalls;
    }
    original(ram, ctx, runtime); // Unmodified original, exactly once per invocation.
    if (index == MaxCalls)
        return;
    try {
        std::lock_guard<std::recursive_mutex> l(capture.mutex);
        const bool returned = ctx && ctx->pc == input.metadata.returnPC;
        if (returned) {
            const std::string stem = "call-" + std::to_string(index);
            save(stem + ".context-after.bin", ctx, sizeof(*ctx));
            save(stem + ".position-after.bin", ram + input.metadata.positionDestination, 64);
            save(stem + ".normal-after.bin", ram + input.metadata.normalDestination, 48);
        }
        capture.log << "{\"kind\":\"1994_original_return\",\"index\":" << index
                    << ",\"actual_PC\":" << (ctx ? ctx->pc : 0)
                    << ",\"returned\":" << (returned ? "true" : "false")
                    << ",\"generation\":" << generation << ",\"guest_writes\":false}\n";
        capture.log.flush();
    } catch (...) {
    }
}
inline void allocator(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) {
    const auto original = capture.originalAllocator;
    if (!original)
        std::terminate();
    PendingAllocator pending{};
    unsigned slot = MaxParents;
    try {
        std::lock_guard<std::recursive_mutex> l(capture.mutex);
        if (capture.enabled && ctx && runtime) {
            const uint32_t pc = ctx->pc, ret = reo_palette_join::gpr(*ctx, 31),
                           sp = reo_palette_join::gpr(*ctx, 29);
            if (pc == 0x18ddd0 && reo_palette_join::gpr(*ctx, 4) == 0xfb0 &&
                reo_palette_join::gpr(*ctx, 5) == 16 && (ret == 0x19bbfc || ret == 0x19b1ec)) {
                for (unsigned i = 0; i < MaxParents; ++i)
                    if (!capture.pending[i].active) {
                        slot = i;
                        break;
                    }
                if (slot < MaxParents) {
                    pending = {runtime,
                               ctx,
                               sp,
                               ret,
                               reo_palette_join::gpr(*ctx, 18),
                               ret == 0x19bbfc ? 0x19bbd0u : 0x19b1c0u,
                               task(runtime, ctx),
                               true};
                    capture.pending[slot] = pending;
                }
            } else if (pc == 0x18de1c) {
                for (unsigned i = 0; i < MaxParents; ++i)
                    if (capture.pending[i].active && capture.pending[i].runtime == runtime &&
                        capture.pending[i].context == ctx && capture.pending[i].sp == sp + 0x20) {
                        slot = i;
                        pending = capture.pending[i];
                        break;
                    }
            }
        }
    } catch (...) {
        slot = MaxParents;
    }
    original(ram, ctx, runtime);
    if (slot == MaxParents)
        return;
    try {
        std::lock_guard<std::recursive_mutex> l(capture.mutex);
        if (ctx->pc != pending.ret)
            return;
        capture.pending[slot].active = false;
        const uint32_t packet = reo_palette_join::gpr(*ctx, 2);
        if ((packet & 15) || !reo_palette_join::mainRange(packet, 0xfb0))
            return;
        if (capture.allocationCount == MaxAllocations) {
            capture.originExhausted = true;
            return;
        }
        const uint32_t outer = reo_palette_join::mainRange(pending.sp, 0x70)
                                   ? reo_palette_join::rawWord(ram + pending.sp + 0x30)
                                   : 0;
        auto& a = capture.allocations[capture.allocationCount++];
        a = {&runtime->memory(),
             ctx,
             capture.nextGeneration++,
             packet,
             0xfb0,
             pending.descriptor,
             pending.parent,
             pending.sp,
             pending.ret,
             outer,
             pending.task,
             false};
        capture.log << "{\"kind\":\"actual_18DDD0_allocation_return\",\"generation\":"
                    << a.generation << ",\"packet\":" << packet
                    << ",\"bytes\":4016,\"descriptor\":" << a.descriptor
                    << ",\"parent\":" << a.parent << ",\"task\":" << a.task
                    << ",\"guest_writes\":false}\n";
        capture.log.flush();
    } catch (...) {
    }
}
inline void parent(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) {
    const auto original = capture.originalParent;
    if (!original)
        std::terminate();
    const uint32_t before = ctx ? ctx->pc : 0;
    original(ram, ctx, runtime);
    try {
        std::lock_guard<std::recursive_mutex> l(capture.mutex);
        if (!capture.enabled || !runtime || !ctx || capture.parents >= MaxParents)
            return;
        auto* a = allocated(&runtime->memory(), reo_palette_join::gpr(*ctx, 2));
        if (!a || a->parent != 0x19bbd0)
            return;
        const bool final = a->outerReturnPC && ctx->pc == a->outerReturnPC &&
                           reo_palette_join::gpr(*ctx, 29) == a->sp + 0x70;
        if (final) {
            a->complete = true;
            const unsigned index = capture.parents++;
            save("parent-" + std::to_string(index) + ".packet-after.bin", ram + a->packet,
                 a->bytes);
            save("parent-" + std::to_string(index) + ".context-after.bin", ctx, sizeof(*ctx));
        }
        capture.log << "{\"kind\":\"19BBD0_original_phase_return\",\"generation\":" << a->generation
                    << ",\"before_PC\":" << before << ",\"after_PC\":" << ctx->pc
                    << ",\"packet\":" << a->packet
                    << ",\"final_stack_return\":" << (final ? "true" : "false")
                    << ",\"guest_writes\":false}\n";
        capture.log.flush();
    } catch (...) {
    }
}
inline bool install(PS2Runtime& runtime) {
    const char* path = std::getenv("REO_GPU_PALETTE_ORIGIN_DIR");
    if (!path || !*path || capture.enabled)
        return false;
    const auto mathOriginal = runtime.lookupFunction(0x1994e0),
               allocatorOriginal = runtime.lookupFunction(0x18ddd0),
               parentOriginal = runtime.lookupFunction(0x19bbd0);
    if (!mathOriginal || !allocatorOriginal || !parentOriginal || mathOriginal == math ||
        allocatorOriginal == allocator || parentOriginal == parent)
        return false;
    for (auto pc : ParentPCs)
        if (runtime.lookupFunction(pc) != parentOriginal)
            return false;
    if (runtime.lookupFunction(0x18de1c) != allocatorOriginal)
        return false;
    const std::filesystem::path directory(path);
    if (std::filesystem::exists(directory) || !std::filesystem::create_directories(directory))
        return false;
    capture.directory = directory;
    capture.log.open(directory / "palette-origin.jsonl");
    if (!capture.log)
        return false;
    capture.originalMath = mathOriginal;
    capture.originalAllocator = allocatorOriginal;
    capture.originalParent = parentOriginal;
    capture.enabled = true;
    runtime.registerFunction(0x1994e0, math);
    runtime.registerFunction(0x18ddd0, allocator);
    runtime.registerFunction(0x18de1c, allocator);
    for (auto pc : ParentPCs)
        runtime.registerFunction(pc, parent);
    reo_palette_origin::install({allocationFor, unpack});
    return true;
}
} // namespace reo_palette_observer
