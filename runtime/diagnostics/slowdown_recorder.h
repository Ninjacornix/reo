#pragma once
// Wire schema 1. Windows x64, little endian, coherent shared memory. No game IO,
// waits, allocations, or locks after configure(). Each OS thread owns one ring.
#include <atomic>
#include <cstdint>
#include <cstring>
#include <cstdlib>
#ifdef _WIN32
#ifndef NOMINMAX
#define NOMINMAX
#endif
// Do not introduce the Windows breakpoint macro into later PS2 runtime enums.
#pragma push_macro("EXCEPTION_BREAKPOINT")
// Match the bootstrap's Win32/raylib name isolation, including when this header
// is the first Windows include in a graphics translation unit.
#pragma push_macro("Rectangle")
#pragma push_macro("CloseWindow")
#pragma push_macro("ShowCursor")
#pragma push_macro("LoadImage")
#pragma push_macro("DrawText")
#pragma push_macro("DrawTextEx")
#define Rectangle ReoWin32Rectangle
#define CloseWindow ReoWin32CloseWindow
#define ShowCursor ReoWin32ShowCursor
#include <windows.h>
#pragma pop_macro("DrawTextEx")
#pragma pop_macro("DrawText")
#pragma pop_macro("LoadImage")
#pragma pop_macro("ShowCursor")
#pragma pop_macro("CloseWindow")
#pragma pop_macro("Rectangle")
#pragma pop_macro("EXCEPTION_BREAKPOINT")
#endif

namespace reo::slowdown {
constexpr uint32_t version = 1, ring_count = 8, capacity = 1024;
struct Record {
    uint64_t time, sequence;
    uint32_t kind, flags;
    uint64_t a, b, c, d, e;
};
struct alignas(64) Ring {
    std::atomic<uint32_t> owner{0};
    uint32_t pad = 0;
    std::atomic<uint64_t> write{0}, read{0}, dropped{0};
    uint8_t reserved[32]{};
    Record records[capacity]{};
};
struct Header {
    uint32_t schema;
    std::atomic<uint32_t> ready;
    uint32_t pid;
    std::atomic<uint32_t> capabilities;
    uint64_t creation, frequency;
    char session[32], build[96], image[1024];
    uint8_t reserved[2912];
};
struct Shared {
    Header header;
    Ring rings[ring_count];
};
static_assert(sizeof(Record) == 64 && sizeof(Header) == 4096 && sizeof(Ring) == 65600);
static_assert(std::atomic<uint64_t>::is_always_lock_free);
inline Shared* shared = nullptr; // configured before workers start; immutable thereafter
inline uint64_t now() noexcept {
#ifdef _WIN32
    LARGE_INTEGER value;
    QueryPerformanceCounter(&value);
    return uint64_t(value.QuadPart);
#else
    return 0;
#endif
}
inline bool active() noexcept {
    return shared != nullptr;
}
inline void configure(const char* build) noexcept {
#ifdef _WIN32
    const char* name = std::getenv("REO_SLOWDOWN_MAP");
    const char* session = std::getenv("REO_SLOWDOWN_SESSION");
    if (!name || !session || std::strlen(session) != 32)
        return;
    HANDLE map = OpenFileMappingA(FILE_MAP_ALL_ACCESS, FALSE, name);
    if (!map)
        return;
    auto* data =
        static_cast<Shared*>(MapViewOfFile(map, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(Shared)));
    if (!data || data->header.schema != version ||
        data->header.ready.load(std::memory_order_acquire) ||
        std::memcmp(data->header.session, session, 32)) {
        if (data)
            UnmapViewOfFile(data);
        CloseHandle(map);
        return;
    }
    FILETIME creation{}, exit{}, kernel{}, user{};
    LARGE_INTEGER frequency{};
    wchar_t image[32768];
    DWORD length = 32768;
    if (!GetProcessTimes(GetCurrentProcess(), &creation, &exit, &kernel, &user) ||
        !QueryPerformanceFrequency(&frequency) ||
        !QueryFullProcessImageNameW(GetCurrentProcess(), 0, image, &length) ||
        !WideCharToMultiByte(CP_UTF8, 0, image, int(length), data->header.image, 1023, nullptr,
                             nullptr)) {
        UnmapViewOfFile(data);
        CloseHandle(map);
        return;
    }
    data->header.pid = GetCurrentProcessId();
    data->header.creation = (uint64_t(creation.dwHighDateTime) << 32) | creation.dwLowDateTime;
    data->header.frequency = uint64_t(frequency.QuadPart);
    std::strncpy(data->header.build, build, 95);
    data->header.capabilities.store(1, std::memory_order_relaxed); // transport
    shared = data;
    data->header.ready.store(1, std::memory_order_release);
    CloseHandle(map); // view remains valid until process exit, including late worker teardown
#endif
}
inline void capability(uint32_t bits) noexcept {
    if (shared)
        shared->header.capabilities.fetch_or(bits, std::memory_order_release);
}
inline void emit(uint32_t kind, uint64_t a = 0, uint64_t b = 0, uint64_t c = 0, uint64_t d = 0,
                 uint64_t e = 0, uint32_t flags = 0) noexcept {
#ifdef _WIN32
    if (!shared)
        return;
    // Registration is bounded. Rings are never reassigned, including on thread exit.
    thread_local Ring* ring = []() noexcept -> Ring* {
        for (auto& candidate : shared->rings) {
            uint32_t empty = 0;
            if (candidate.owner.compare_exchange_strong(empty, GetCurrentThreadId(),
                                                        std::memory_order_acq_rel))
                return &candidate;
        }
        // No ring available: account for loss without borrowing another thread's ring.
        return nullptr;
    }();
    if (!ring) {
        shared->header.capabilities.fetch_or(0x80000000u, std::memory_order_relaxed);
        return;
    }
    const uint64_t write = ring->write.load(std::memory_order_relaxed);
    if (write - ring->read.load(std::memory_order_acquire) >= capacity) {
        ring->dropped.fetch_add(1, std::memory_order_relaxed);
        return;
    }
    ring->records[write % capacity] = {now(), write, kind, flags, a, b, c, d, e};
    ring->write.store(write + 1, std::memory_order_release);
#endif
}
// 1=verified original clock, 2=frame phases, 3=warmup boundary, 4=invalid clock.
} // namespace reo::slowdown
