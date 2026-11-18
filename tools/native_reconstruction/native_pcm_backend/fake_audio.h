#pragma once
#include "raylib.h"
#include <atomic>
#include <condition_variable>
#include <mutex>

namespace fake_audio {
struct Event {
    std::mutex mutex;
    std::condition_variable changed;
    bool signalled = false;
    void signal() { std::lock_guard lock(mutex); signalled = true; changed.notify_all(); }
    void wait() { std::unique_lock lock(mutex); changed.wait(lock, [&] { return signalled; }); }
};
extern std::atomic<bool> ready, callback_on_play;
extern std::atomic<unsigned> loads, plays, stops, unloads;
void pump(float*, unsigned frames);
}
