#include "audio_output_owner.h"
#include <atomic>
#include <condition_variable>
#include <cstdlib>
#include <iostream>
#include <thread>

using namespace reo::audio_output;
#define CHECK(x) do { if (!(x)) { std::cerr << "Failed line " << __LINE__ << ": " #x "\n"; std::abort(); } } while (0)

struct Event {
    std::mutex mutex;
    std::condition_variable changed;
    bool ready = false;
    void signal() { std::lock_guard lock(mutex); ready = true; changed.notify_all(); }
    void wait() { std::unique_lock lock(mutex); changed.wait(lock, [&] { return ready; }); }
};

// Models the pinned AUDIO.System.lock semantics, never calls actual raylib.
struct FakeProvider final : Provider {
    std::mutex device_lock;
    CallbackSlot* slot = nullptr;
    std::atomic<unsigned> attaches{0}, detaches{0}, stops{0}, unloads{0};
    std::atomic<bool> fail_attach{false}, fail_detach{false}, fail_stop{false}, fail_unload{false};
    bool wrong_source = false, stopped = false;
    Event detach_entered, before_dispatch, allow_dispatch;
    std::string_view source_sha256() const noexcept override {
        return wrong_source ? "unqualified" : provider_source_sha256;
    }
    bool attach(CallbackSlot& incoming) noexcept override {
        ++attaches;
        if (fail_attach.exchange(false)) return false;
        std::lock_guard lock(device_lock);
        CHECK(slot == nullptr);
        slot = &incoming;
        return true;
    }
    bool detach() noexcept override {
        ++detaches;
        detach_entered.signal();
        if (fail_detach.exchange(false)) return false;
        std::lock_guard lock(device_lock); // fences the complete callback
        slot = nullptr;
        return true;
    }
    bool stop() noexcept override {
        ++stops;
        CHECK(slot == nullptr);
        if (fail_stop.exchange(false)) return false;
        stopped = true;
        return true;
    }
    bool unload() noexcept override {
        ++unloads;
        CHECK(slot == nullptr && stopped);
        return !fail_unload.exchange(false);
    }
    bool fire(float* output, bool pause_before_admission = false) {
        std::lock_guard lock(device_lock);
        if (!slot) return false;
        if (pause_before_admission) {
            before_dispatch.signal();
            allow_dispatch.wait();
        }
        return slot->dispatch(output, 4);
    }
};

struct FakeRenderer final : Renderer {
    std::atomic<unsigned> calls{0};
    bool pause = false;
    Owner* self_join = nullptr;
    JoinResult callback_join = JoinResult::joined;
    Event entered, finish;
    void render(float* output, std::uint32_t frames) noexcept override {
        ++calls;
        if (self_join) callback_join = self_join->join();
        entered.signal();
        if (pause) finish.wait();
        for (unsigned i = 0; i < frames * 2; ++i) output[i] = 1.0f;
    }
};

void admitted_callback_retains_lifetime() {
    CallbackSlot slot;
    auto provider = std::make_shared<FakeProvider>();
    auto renderer = std::make_shared<FakeRenderer>();
    renderer->pause = true;
    auto owner = Owner::create(slot, provider, renderer);
    CHECK(owner->start() == StartResult::started);
    std::weak_ptr<Owner> weak = owner;
    float output[8]{};
    std::thread callback([&] { CHECK(provider->fire(output)); });
    renderer->entered.wait();
    owner->request_stop();
    owner->request_stop(); // neither call waits for the paused renderer
    owner.reset();
    CHECK(!weak.expired() && slot.occupied());
    auto retained = weak.lock();
    std::atomic<bool> joined = false;
    std::thread control([&] { CHECK(retained->join() == JoinResult::joined); joined = true; });
    provider->detach_entered.wait();
    CHECK(!joined && slot.occupied());
    renderer->finish.signal();
    callback.join();
    control.join();
    CHECK(output[0] == 1 && renderer->calls == 1);
    CHECK(provider->detaches == 1 && provider->stops == 1 && provider->unloads == 1);
    CHECK(!slot.occupied());
    std::thread repeat1([&] { CHECK(retained->join() == JoinResult::joined); });
    std::thread repeat2([&] { CHECK(retained->join() == JoinResult::joined); });
    repeat1.join(); repeat2.join();
    CHECK(provider->detaches == 1 && provider->stops == 1 && provider->unloads == 1);
    retained.reset();
    CHECK(weak.expired());
}

void stop_wins_admission_while_detach_waits() {
    CallbackSlot slot;
    auto provider = std::make_shared<FakeProvider>();
    auto renderer = std::make_shared<FakeRenderer>();
    auto owner = Owner::create(slot, provider, renderer);
    CHECK(owner->start() == StartResult::started);
    float output[8];
    for (auto& sample : output) sample = 9.0f;
    std::thread callback([&] { CHECK(!provider->fire(output, true)); });
    provider->before_dispatch.wait();
    owner->request_stop();
    std::atomic<bool> joined = false;
    std::thread control([&] { CHECK(owner->join() == JoinResult::joined); joined = true; });
    provider->detach_entered.wait();
    CHECK(!joined && slot.occupied());
    provider->allow_dispatch.signal();
    callback.join(); control.join();
    CHECK(renderer->calls == 0);
    for (auto sample : output) CHECK(sample == 0.0f);
    CHECK(owner->start() == StartResult::stop_requested);
}

void failure_retry_preserves_completed_steps() {
    CallbackSlot slot;
    auto provider = std::make_shared<FakeProvider>();
    auto renderer = std::make_shared<FakeRenderer>();
    auto owner = Owner::create(slot, provider, renderer);
    provider->fail_attach = true;
    CHECK(owner->start() == StartResult::attach_failed && !slot.occupied());
    CHECK(owner->start() == StartResult::started && slot.occupied());
    CHECK(owner->start() == StartResult::already_started && provider->attaches == 2);
    provider->fail_detach = true;
    provider->fail_stop = true;
    provider->fail_unload = true;
    CHECK(owner->join() == JoinResult::detach_failed && slot.occupied());
    float output[8];
    CHECK(!provider->fire(output) && renderer->calls == 0);
    CHECK(owner->join() == JoinResult::stop_failed && slot.occupied());
    CHECK(owner->join() == JoinResult::unload_failed && slot.occupied());
    CHECK(owner->join() == JoinResult::joined && !slot.occupied());
    CHECK(owner->join() == JoinResult::joined);
    CHECK(provider->detaches == 2 && provider->stops == 2 && provider->unloads == 2);
}

void callback_self_join_is_refused() {
    CallbackSlot slot;
    auto provider = std::make_shared<FakeProvider>();
    auto renderer = std::make_shared<FakeRenderer>();
    auto owner = Owner::create(slot, provider, renderer);
    renderer->self_join = owner.get();
    CHECK(owner->start() == StartResult::started);
    float output[8]{};
    CHECK(provider->fire(output));
    CHECK(renderer->callback_join == JoinResult::callback_thread);
    CHECK(owner->stop_requested() && provider->detaches == 0 && slot.occupied());
    CHECK(owner->join() == JoinResult::joined);
}

void qualification_slot_and_bounds() {
    CallbackSlot slot;
    auto provider = std::make_shared<FakeProvider>();
    auto renderer = std::make_shared<FakeRenderer>();
    provider->wrong_source = true;
    CHECK(!Owner::create(slot, provider, renderer));
    provider->wrong_source = false;
    CHECK(!Owner::create(slot, {}, renderer));
    auto owner = Owner::create(slot, provider, renderer);
    auto other_provider = std::make_shared<FakeProvider>();
    auto other = Owner::create(slot, other_provider, renderer);
    CHECK(owner->start() == StartResult::started);
    CHECK(other->start() == StartResult::slot_busy && other_provider->attaches == 0);
    CHECK(other->join() == JoinResult::joined && slot.occupied());
    float sentinel = 7.0f;
    CHECK(!slot.dispatch(&sentinel, maximum_callback_frames + 1) && sentinel == 7);
    CHECK(!slot.dispatch(nullptr, 1));
    CHECK(renderer->calls == 0);
    CHECK(owner->join() == JoinResult::joined);
    CHECK(!slot.dispatch(&sentinel, 0) && sentinel == 7);
}

int main() {
    admitted_callback_retains_lifetime();
    stop_wins_admission_while_detach_waits();
    failure_retry_preserves_completed_steps();
    callback_self_join_is_refused();
    qualification_slot_and_bounds();
    std::cout << "audio_output_owner: 5 deterministic contract cases passed\n";
}
