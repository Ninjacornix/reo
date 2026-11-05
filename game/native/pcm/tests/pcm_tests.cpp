#include "pcm.hpp"
#include <array>
#include <atomic>
#include <bit>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <new>
#include <stdexcept>
#include <thread>
#include <vector>
using namespace reo::native::pcm;
thread_local bool refuse_allocation = false;
[[gnu::noinline]] void* operator new(std::size_t n) {
    if (refuse_allocation)
        throw std::bad_alloc();
    if (void* p = std::malloc(n ? n : 1))
        return p;
    throw std::bad_alloc();
}
[[gnu::noinline]] void operator delete(void* p) noexcept {
    std::free(p);
}
[[gnu::noinline]] void operator delete(void* p, std::size_t) noexcept {
    std::free(p);
}
[[gnu::noinline]] void* operator new[](std::size_t n) {
    return ::operator new(n);
}
[[gnu::noinline]] void operator delete[](void* p) noexcept {
    ::operator delete(p);
}
[[gnu::noinline]] void operator delete[](void* p, std::size_t) noexcept {
    ::operator delete(p);
}
#define CHECK(x)                                                                                   \
    do {                                                                                           \
        if (!(x))                                                                                  \
            throw std::runtime_error(#x);                                                          \
    } while (false)
unsigned checks{};
void check(bool b) {
    CHECK(b);
    ++checks;
}
std::span<const std::byte> bytes(const std::vector<std::int16_t>& v) {
    return {reinterpret_cast<const std::byte*>(v.data()), v.size() * 2};
}
Config small() {
    Config c;
    c.max_channels = 3;
    c.max_voices = 3;
    c.channel_samples = 16;
    return c;
}
template <class T> T take(Result<T> r) {
    CHECK(r.status == Status::ok);
    return r.value;
}
void handles() {
    Session a(small()), b(small());
    auto c = take(a.create_channel());
    auto v = take(a.create_voice());
    check(b.inspect(c).status == Status::invalid_handle);
    check(b.inspect(v).status == Status::invalid_handle);
    check(a.close_channel(c) == Status::ok);
    check(a.inspect(c).status == Status::invalid_handle);
    auto c2 = take(a.create_channel());
    check(a.inspect(c2).status == Status::ok);
    check(a.configure(v, {c2, {}, Channels::mono, 48000, 256, true}, 0) == Status::ok);
    check(a.close_channel(c2) == Status::channel_in_use);
    check(a.release(v) == Status::ok);
    check(a.release(v) == Status::invalid_handle);
    check(a.close_channel(c2) == Status::ok);
    auto old = take(a.create_channel());
    check(a.reset(123) == Status::ok);
    check(a.inspect(old).status == Status::invalid_handle);
    a.shutdown(456);
    check(a.create_channel().status == Status::closed);
    check(a.reset(0) == Status::closed);
    check(a.select_frame_clock() == Status::closed);
    alignas(Session) std::array<std::byte, sizeof(Session)> storage{};
    auto* first = std::construct_at(reinterpret_cast<Session*>(storage.data()), small(), 0);
    auto stale = take(first->create_channel());
    std::destroy_at(first);
    auto* reused = std::construct_at(reinterpret_cast<Session*>(storage.data()), small(), 0);
    check(reused->inspect(stale).status == Status::invalid_handle);
    std::destroy_at(reused);
    auto conf = small();
    conf.max_channels = conf.max_voices = 1;
    conf.max_generation = 2;
    Session retired(conf);
    auto x = take(retired.create_channel());
    check(retired.close_channel(x) == Status::ok);
    auto y = take(retired.create_channel());
    check(retired.close_channel(y) == Status::ok);
    check(retired.create_channel().status == Status::capacity);
    auto u = take(retired.create_voice());
    check(retired.release(u) == Status::ok);
    auto w = take(retired.create_voice());
    check(retired.release(w) == Status::ok);
    check(retired.create_voice().status == Status::capacity);
}
void aliases_and_admission() {
    Session s(small());
    auto left = take(s.create_channel()), right = take(s.create_channel());
    auto a = take(s.create_voice()), b = take(s.create_voice());
    check(s.configure(a, {left, {}, Channels::mono, 48000, 256, true}, 0) == Status::ok);
    const auto before = s.clock();
    const auto frames = s.statistics().output_frames;
    check(s.configure(b, {left, right, Channels::stereo, 24000, 256, true}, 100000000) ==
          Status::unsupported_alias);
    check(s.configure(a, {left, left, Channels::stereo, 48000, 256, true}, 100000000) ==
          Status::unsupported_alias);
    check(s.clock().last_tick_ns == before.last_tick_ns && s.statistics().output_frames == frames);
    check(s.configure(a, {left, right, Channels::mono, 48000, 256, true}, 100000000) ==
          Status::invalid_input);
    check(s.configure(a, {left, {}, static_cast<Channels>(3), 48000, 256, true}, 100000000) ==
          Status::invalid_input);
    check(s.gain(a, std::numeric_limits<float>::quiet_NaN()) == Status::invalid_input);
    check(s.gain(a, -1) == Status::invalid_input);
    check(s.release(a) == Status::ok);
    check(s.configure(b, {left, {}, Channels::disabled, 0, 999, true}, 0) == Status::ok);
    auto other = take(s.create_voice());
    check(s.configure(other, {left, {}, Channels::mono, 0, 256, true}, 100000000) ==
          Status::unsupported_alias);
    check(s.clock().last_tick_ns == 0);
    check(s.close_channel(left) == Status::channel_in_use);
    check(s.configure(b, {{}, {}, Channels::disabled, 0, 0, false}, 0) == Status::ok);
    check(s.close_channel(left) == Status::ok);
    std::array<float, 3> odd{1, 2, 3};
    check(s.render(odd) == Status::invalid_input);
    check(odd[0] == 1 && odd[2] == 3);
    check(s.advance_frames(16385) == Status::invalid_input);
    check(s.clock().last_tick_ns == 0);
}
void queue_ring_and_clock() {
    auto conf = small();
    conf.channel_samples = 4;
    Session s(conf);
    auto ch = take(s.create_channel());
    auto v = take(s.create_voice());
    check(s.select_frame_clock() == Status::ok);
    check(s.configure(v, {ch, {}, Channels::mono, 48000, 256, true}, 0) == Status::ok);
    std::vector<std::int16_t> first{1, 2, 3, 4}, second{5, 6}, overflow{7};
    check(take(s.enqueue(ch, bytes(first), 0)) == 8);
    std::array<float, 4> output{};
    check(s.render(output) == Status::ok);
    check(take(s.consumed(ch, 0)) == 4);
    check(take(s.enqueue(ch, bytes(second), 0)) == 12);
    check(s.enqueue(ch, bytes(overflow), 0).status == Status::capacity);
    std::array<std::int16_t, 4> copy{};
    check(s.copy_samples(ch, copy) == Status::ok);
    check((copy == std::array<std::int16_t, 4>{3, 4, 5, 6}));
    check(s.discard(ch) == Status::ok);
    check(take(s.consumed(ch, 0)) == 12);
    check(take(s.inspect(ch)).samples == 0);
    auto info = take(s.inspect(v));
    check(info.phase == 0 && info.playing);
    check(s.release(v) == Status::ok);
    const auto frames = s.statistics().output_frames;
    check(s.reset(0) == Status::ok);
    check(s.statistics().output_frames == frames);
    Session headless(conf);
    auto c = take(headless.create_channel());
    auto voice = take(headless.create_voice());
    check(headless.configure(voice, {c, {}, Channels::mono, 48000, 256, true}, 0) == Status::ok);
    check(headless.enqueue(c, bytes(first), 0).status == Status::ok);
    check(headless.enqueue(c, bytes(overflow), 20834).status ==
          Status::ok); // Clock consumes first, freeing capacity.
    check(take(headless.inspect(c)).queued_bytes == 10 &&
          take(headless.inspect(c)).consumed_bytes == 2);
    check(headless.advance_headless(-1) == Status::ok);
    check(headless.clock().last_tick_ns == 20833);
    check(headless.advance_headless(std::numeric_limits<std::int64_t>::max()) ==
          Status::clock_limit);
    check(headless.clock().last_tick_ns == 20833);
    conf.max_counter = 8;
    Session bounded(conf);
    auto limited = take(bounded.create_channel());
    check(bounded.select_frame_clock() == Status::ok);
    check(bounded.enqueue(limited, bytes(first), 0).status == Status::ok);
    check(bounded.enqueue(limited, bytes(overflow), 0).status == Status::counter_limit);
    check(take(bounded.inspect(limited)).queued_bytes == 8);
}
void unsupported_mix() {
    Session s(small());
    std::array<Channel, 3> channels;
    std::array<Voice, 3> voices;
    std::vector<std::int16_t> samples{1, 2};
    for (unsigned i = 0; i < 3; ++i) {
        channels[i] = take(s.create_channel());
        voices[i] = take(s.create_voice());
        check(s.enqueue(channels[i], bytes(samples), 0).status == Status::ok);
        check(s.configure(voices[i], {channels[i], {}, Channels::mono, 48000, 256, true}, 0) ==
              Status::ok);
    }
    std::array<float, 2> output{123, 456};
    check(s.render(output) == Status::unsupported_mix);
    check(output[0] == 123 && output[1] == 456);
    check(s.advance_headless(20834) == Status::unsupported_mix);
    check(s.consumed(channels[0], 20834).status == Status::unsupported_mix);
    check(!s.clock().frame_clock && s.clock().last_tick_ns == 0 &&
          s.statistics().output_frames == 0);
    for (unsigned i = 0; i < 3; ++i) {
        auto c = take(s.inspect(channels[i]));
        auto v = take(s.inspect(voices[i]));
        check(c.samples == 2 && c.queued_bytes == 4 && c.consumed_bytes == 0);
        check(v.phase == 0 && v.late_samples == 0 && v.skipped_samples == 0);
    }
    check(s.release(voices[2]) == Status::ok);
    check(s.render(output) == Status::ok);
    check(output[0] == 2.0f / 32768.0f);
}
void pause_stop_and_generation() {
    Session s;
    auto c = take(s.create_channel());
    auto v = take(s.create_voice());
    check(s.select_frame_clock() == Status::ok);
    std::vector<std::int16_t> pcm(8192, 100);
    for (unsigned i = 0; i < 8; ++i)
        check(s.enqueue(c, bytes(pcm), 0).status == Status::ok);
    pcm.resize(6465);
    check(s.enqueue(c, bytes(pcm), 0).status == Status::ok); //72001samples
    check(s.configure(v, {c, {}, Channels::mono, 48000, 256, true}, 0) == Status::ok);
    auto stopped = s.stop(v, true, 48000);
    check(stopped.status == Status::ok && stopped.action == StopAction::cut);
    check(s.inspect(v).status == Status::invalid_handle);
    auto ci = take(s.inspect(c));
    check(ci.samples == 0 && ci.consumed_bytes == ci.queued_bytes);
    auto voice = take(s.create_voice());
    check(s.configure(voice, {c, {}, Channels::mono, 24000, 256, true}, 0) == Status::ok);
    std::vector<std::int16_t> tiny{1000, 2000, 3000};
    check(s.enqueue(c, bytes(tiny), 0).status == Status::ok);
    std::array<float, 2> out{};
    check(s.render(out) == Status::ok);
    check(take(s.inspect(voice)).phase == 0.5);
    check(s.configure(voice, {c, {}, Channels::mono, 24000, 256, false}, 0) == Status::ok);
    check(s.render(out) == Status::ok);
    check(out[0] == 0);
    check(take(s.inspect(voice)).phase == 0.5);
    check(s.configure(voice, {c, {}, Channels::mono, 24000, 256, true}, 0) == Status::ok);
    check(s.drain(voice) == Status::ok);
    check(s.configure(voice, {c, {}, Channels::mono, 24000, 256, false}, 0) == Status::ok);
    check(take(s.inspect(voice)).playing);
    std::array<float, 16> tail{};
    check(s.render(tail) == Status::ok);
    check(!take(s.inspect(voice)).playing);
}
void no_operational_allocations() {
    Session s(small());
    std::array<std::byte, 4> data{std::byte{0}, std::byte{1}, std::byte{0}, std::byte{2}};
    std::array<float, 2> out{};
    bool ok = false;
    refuse_allocation = true;
    try {
        auto c = s.create_channel();
        auto v = s.create_voice();
        auto select = s.select_frame_clock();
        auto configured = s.configure(v.value, {c.value, {}, Channels::mono, 48000, 256, true}, 0);
        auto push = s.enqueue(c.value, data, 0);
        auto render = s.render(out);
        auto consumed = s.consumed(c.value, 0);
        auto released = s.release(v.value);
        auto closed = s.close_channel(c.value);
        ok = c.status == Status::ok && v.status == Status::ok && select == Status::ok &&
             configured == Status::ok && push.status == Status::ok && render == Status::ok &&
             consumed.status == Status::ok && released == Status::ok && closed == Status::ok;
    } catch (...) {
        refuse_allocation = false;
        throw;
    }
    refuse_allocation = false;
    check(ok);
}
void concurrency() {
    auto conf = small();
    conf.channel_samples = 128;
    Session s(conf);
    auto c = take(s.create_channel());
    auto v = take(s.create_voice());
    check(s.select_frame_clock() == Status::ok);
    check(s.configure(v, {c, {}, Channels::mono, 48000, 256, true}, 0) == Status::ok);
    std::atomic<bool> done = false, failed = false;
    std::thread producer([&] {
        std::array<std::byte, 2> sample{std::byte{1}, std::byte{0}};
        for (unsigned i = 0; i < 5000;) {
            auto r = s.enqueue(c, sample, 0);
            if (r.status == Status::ok)
                ++i;
            else if (r.status == Status::capacity)
                std::this_thread::yield();
            else {
                failed = true;
                break;
            }
        }
        done = true;
    });
    std::thread consumer([&] {
        std::array<float, 32> block{};
        while (!done) {
            if (s.render(block) != Status::ok)
                failed = true;
        }
        for (unsigned i = 0; i < 16; ++i)
            if (s.render(block) != Status::ok)
                failed = true;
    });
    producer.join();
    consumer.join();
    check(!failed);
    auto info = take(s.inspect(c));
    check(info.queued_bytes == 10000 && info.consumed_bytes == 10000 && info.samples == 0);
    s.shutdown(0);
}
void explicit_order() {
    auto conf = small();
    conf.max_voices = 4;
    Session s(conf), other(conf);
    std::array<Channel, 3> channels;
    std::array<Voice, 3> voices;
    const std::vector<std::int16_t> data(8, 100);
    check(s.select_frame_clock() == Status::ok);
    for (std::size_t i = 0; i < voices.size(); ++i) {
        channels[i] = take(s.create_channel());
        voices[i] = take(s.create_voice());
        check(s.enqueue(channels[i], bytes(data), 0).status == Status::ok);
        check(s.configure(voices[i], {channels[i], {}, Channels::mono, 48000, 256, true}, 0) == Status::ok);
    }
    std::array<float, 2> out{123, 123};
    check(s.render(out) == Status::unsupported_mix && out[0] == 123);
    std::array<Voice, 3> order{voices[2], voices[0], voices[1]};
    refuse_allocation = true;
    const auto declared = s.set_mix_order(order);
    refuse_allocation = false;
    check(declared == Status::ok);
    auto invalid = order;
    invalid[1] = invalid[0];
    check(s.set_mix_order(invalid) == Status::invalid_input);
    invalid[1] = take(other.create_voice());
    check(s.set_mix_order(invalid) == Status::invalid_handle);
    check(s.set_mix_order(std::span<const Voice>(order).first(2)) == Status::invalid_input);
    check(s.render(out) == Status::ok); // Invalid declarations retain prior valid order.
    check(take(s.inspect(channels[0])).consumed_bytes == 2);
    const auto extra = take(s.create_voice());
    check(s.render(out) == Status::unsupported_mix);
    const std::array<Voice, 4> expanded{extra, voices[0], voices[2], voices[1]};
    check(s.set_mix_order(expanded) == Status::ok);
    check(s.advance_frames(1) == Status::ok);
    check(s.release(extra) == Status::ok);
    check(s.render(out) == Status::unsupported_mix);
    check(s.set_mix_order(order) == Status::ok);
    check(s.advance_frames(1) == Status::ok);
    const auto replacement = take(s.create_voice());
    check(s.set_mix_order(expanded) == Status::invalid_handle);
    const std::array<Voice, 4> fresh{replacement, voices[0], voices[2], voices[1]};
    check(s.set_mix_order(fresh) == Status::ok);
    check(s.reset(0) == Status::ok);
    check(s.set_mix_order(fresh) == Status::invalid_input);
    check(s.set_mix_order({}) == Status::ok);
    s.shutdown(0);
    check(s.set_mix_order({}) == Status::closed);
}
void optional_source_domains() {
    auto conf = small();
    conf.allow_shared_channels = conf.allow_missing_channels = true;
    Session s(conf), foreign(conf);
    const auto left = take(s.create_channel());
    const auto second = take(s.create_channel());
    const auto a = take(s.create_voice()), b = take(s.create_voice()), absent = take(s.create_voice());
    check(s.select_frame_clock() == Status::ok);
    const std::vector<std::int16_t> samples(8, 100);
    check(s.enqueue(left,bytes(samples),0).status == Status::ok);
    check(s.enqueue(second,bytes(samples),0).status == Status::ok);
    check(s.configure(a,{left,{},Channels::mono,48000,256,true},0) == Status::ok);
    check(s.configure(b,{left,{},Channels::mono,48000,256,true},0) == Status::ok);
    std::array<float,2> output{123,123};
    check(s.render(output) == Status::unsupported_alias && output[0] == 123);
    check(s.statistics().output_frames == 0 && take(s.inspect(left)).consumed_bytes == 0);
    check(s.configure(absent,{{},{},Channels::mono,48000,256,true},0) == Status::ok);
    const std::array<Voice,3> order{absent,b,a};
    check(s.set_mix_order(order) == Status::ok);
    check(s.render(output) == Status::ok);
    check(take(s.inspect(left)).consumed_bytes == 4);
    auto no_source = take(s.inspect(absent));
    check(no_source.phase == 0 && no_source.late_samples == 0 && no_source.playing);
    check(s.configure(absent,{second,{},Channels::stereo,48000,256,true},0) == Status::ok);
    check(s.advance_frames(1) == Status::ok);
    auto missing_right = take(s.inspect(absent));
    check(missing_right.late_samples == 1 && take(s.inspect(second)).consumed_bytes == 0);
    check(s.configure(absent,{{},{},Channels::stereo,48000,256,true},0) == Status::ok);
    check(s.advance_frames(1) == Status::ok);
    check(take(s.inspect(absent)).late_samples == missing_right.late_samples);
    check(s.configure(absent,{second,second,Channels::stereo,48000,256,true},0) == Status::unsupported_alias);
    const auto other = take(foreign.create_channel());
    check(s.configure(absent,{other,{},Channels::mono,48000,256,true},0) == Status::invalid_handle);
    check(s.close_channel(left) == Status::channel_in_use);
    check(s.release(a) == Status::ok && s.close_channel(left) == Status::channel_in_use);
    check(s.release(b) == Status::ok && s.close_channel(left) == Status::ok);
}
int main() {
    try {
        handles();
        aliases_and_admission();
        queue_ring_and_clock();
        unsupported_mix();
        pause_stop_and_generation();
        no_operational_allocations();
        explicit_order();
        optional_source_domains();
        concurrency();
        std::cout << checks << " PCM owner checks passed\n";
        return 0;
    } catch (const std::exception& e) {
        refuse_allocation = false;
        std::cerr << e.what() << '\n';
        return 1;
    }
}
