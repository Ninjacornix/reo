#include "sjrb.hpp"

#include <array>
#include <cstdint>
#include <iostream>
#include <limits>
#include <memory>
#include <stdexcept>
#include <vector>

using namespace reo::native::sjrb;
namespace {
int assertions = 0;
void require(bool value) { ++assertions; if (!value) throw std::runtime_error("SJRB assertion " + std::to_string(assertions)); }
void done(Status status) { require(status == Status::completed); }
struct Observer {
    Ring* ring{};
    Chunk* span{};
    std::array<char, 128> events{};
    std::size_t count{};
    int depth{}, errors{};
    bool edit_error{}, edit_enter{}, reenter{};
    Status nested{Status::completed};
    Snapshot at_error{};
    static void enter(void* opaque) noexcept {
        auto& s = *static_cast<Observer*>(opaque); s.events[s.count++] = 'E'; ++s.depth;
        if (s.edit_enter && s.span) s.span->set_bytes(2);
        if (s.reenter) s.nested = s.ring->reset();
    }
    static void leave(void* opaque) noexcept { auto& s = *static_cast<Observer*>(opaque); s.events[s.count++] = 'L'; --s.depth; }
    static void error(void* opaque, std::int32_t code) noexcept {
        auto& s = *static_cast<Observer*>(opaque); s.events[s.count++] = 'X';
        s.errors += code == -3; s.at_error = s.ring->snapshot();
        if (s.edit_error && s.span) s.span->set_bytes(2);
    }
    Hooks hooks() noexcept { return {this, enter, leave, error}; }
};

void geometry_and_storage() {
    require(!Ring::admits_geometry(0, 4)); require(!Ring::admits_geometry(-1, 0));
    require(!Ring::admits_geometry(16, -1)); require(!Ring::admits_geometry(16, 17));
    require(!Ring::admits_geometry(std::numeric_limits<std::int32_t>::max(), 1));
    require(Ring::admits_geometry(8192, 192)); require(Ring::admits_geometry(2048, 36));
    Observer observer;
    try { Ring invalid(0, 4, observer.hooks()); require(false); } catch (const std::invalid_argument&) {}
    require(observer.count == 0);
    Chunk retained;
    {
        auto ring = std::make_unique<Ring>(16, 4);
        done(ring->get(0, 4, retained));
        done(retained.write(std::array<std::uint8_t, 4>{1, 2, 3, 4}));
    }
    std::array<std::uint8_t, 4> bytes{};
    done(retained.read(bytes)); require((bytes == std::array<std::uint8_t, 4>{1, 2, 3, 4}));
    done(retained.write(std::array<std::uint8_t, 1>{9}, 3));
    require(retained.write(std::array<std::uint8_t, 2>{9, 9}, 3) == Status::invalid_span);
    done(retained.read(bytes)); require(bytes[3] == 9);
}

void suffix_transaction() {
    Observer observer;
    Ring ring(16, 4, observer.hooks(), 0xA5); observer.ring = &ring;
    Chunk free, published, suffix, read, returned, unread;
    done(ring.get(0, 8, free));
    done(free.write(std::array<std::uint8_t, 8>{1, 2, 3, 4, 5, 6, 7, 8}));
    done(Chunk::split(free, 5, published, suffix));
    done(ring.put(1, published)); done(ring.unget(0, suffix));
    done(ring.get(1, 5, read)); done(Chunk::split(read, 2, returned, unread));
    done(ring.put(0, returned)); done(ring.unget(1, unread));
    const auto state = ring.snapshot();
    require(state.free == 13 && state.data == 3 && state.write == 5 && state.read == 2);
    require((state.totals == std::array<std::uint32_t, 4>{5, 2, 2, 5}));
    require(observer.depth == 0 && observer.errors == 0 && observer.count == 12);
    std::array<std::uint8_t, 3> tail{}; done(unread.read(tail)); require((tail == std::array<std::uint8_t, 3>{3, 4, 5}));
    // Original numeric spans are not linear leases: a second Put is permitted.
    done(ring.put(0, returned)); require(ring.snapshot().free == 15);
}

void wrap_and_split() {
    Ring ring(16, 4, {}, 0xA5);
    Chunk start, read, wrapped, first, suffix;
    done(ring.get(0, 12, start));
    done(start.write(std::array<std::uint8_t, 12>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}));
    done(ring.put(1, start)); done(ring.get(1, 12, read)); done(ring.put(0, read));
    done(ring.get(0, 20, wrapped)); require(wrapped.offset() == 12 && wrapped.bytes() == 8);
    done(wrapped.write(std::array<std::uint8_t, 8>{70, 71, 72, 73, 74, 75, 76, 77}));
    done(ring.put(1, wrapped));
    std::array<std::uint8_t, 20> backing{}; done(ring.read_backing(backing));
    require(backing[0] == 74 && backing[3] == 77 && backing[16] == 74 && backing[19] == 77);
    done(ring.get(1, 8, read)); done(Chunk::split(read, 4, first, suffix));
    require(suffix.offset() == 16 && suffix.bytes() == 4);
    done(ring.put(0, first)); done(ring.unget(1, suffix));
    require(ring.snapshot().read == 0 && ring.snapshot().data == 4);
    done(ring.get(1, 4, read)); done(ring.put(0, read));
    require(ring.snapshot().read == 4 && ring.snapshot().write == 4 && ring.snapshot().free == 16);
    require(Chunk::split(read, 1, read, suffix) == Status::invalid_span);
    done(Chunk::split(read, 40, first, suffix)); require(first.bytes() == 4 && suffix.is_null());
    done(Chunk::split(read, 0, first, suffix)); require(first.bytes() == 0 && !first.is_null() && suffix.bytes() == 4);
}

void errors_callbacks_and_guards() {
    Observer observer;
    Ring ring(16, 4, observer.hooks()); observer.ring = &ring;
    Chunk acquired, mismatch;
    done(ring.get(0, 6, acquired)); done(ring.make_span(1, 6, mismatch));
    observer.span = &mismatch; observer.edit_error = true;
    done(ring.unget(0, mismatch));
    require(observer.at_error.totals[0] == 6 && observer.depth == 0 && observer.errors == 1);
    require(ring.snapshot().totals[0] == 4 && ring.snapshot().write == 6 && ring.snapshot().free == 10);
    require(observer.events[2] == 'E' && observer.events[3] == 'X' && observer.events[4] == 'L');
    observer.edit_error = false;
    std::int32_t count = -1; const auto before_count = observer.count;
    done(ring.count(7, count)); require(count == 0 && observer.count == before_count + 1 && observer.depth == 0);
    std::int32_t granted = -1; bool fits = false;
    done(ring.peek(7, 0, granted, fits)); require(granted == 0 && fits);
    done(ring.get(7, -9, acquired)); require(acquired.is_null() && acquired.bytes() == 0);
    done(ring.make_span(1, 2, acquired)); observer.span = &acquired;
    done(ring.put(7, acquired)); require(acquired.is_null());
    observer.reenter = true;
    done(ring.get(0, 0, acquired)); require(observer.nested == Status::reentrant_call);
}

void safety_refusals_and_reset() {
    Observer observer;
    Ring ring(16, 4, observer.hooks()); observer.ring = &ring;
    Ring other(16, 4);
    Chunk foreign, live;
    done(other.get(0, 4, foreign)); done(ring.get(0, 4, live));
    auto before = ring.snapshot(); auto calls = observer.count;
    require(ring.put(1, foreign) == Status::foreign_storage);
    require(ring.unget(0, foreign) == Status::foreign_storage);
    require(ring.get(0, -1, live) == Status::unsafe_request);
    require(ring.snapshot() == before && observer.count == calls);
    live.set_bytes(30);
    require(ring.put(1, live) == Status::invalid_span);
    require(ring.snapshot() == before && observer.count == calls);
    live.set_bytes(4); done(ring.reset());
    before = ring.snapshot(); calls = observer.count;
    require(ring.put(1, live) == Status::stale_incarnation);
    require(live.write(std::array<std::uint8_t, 1>{1}) == Status::stale_incarnation);
    require(ring.snapshot() == before && observer.count == calls);
    done(ring.make_span(1, 4, live)); observer.span = &live; observer.edit_enter = true;
    require(ring.put(1, live) == Status::callback_contract_violation);
    require(ring.snapshot() == before && observer.depth == 0 && observer.count == calls + 2);
    observer.edit_enter = false;
    Chunk null = Chunk::null(3); calls = observer.count;
    done(ring.put(1, null)); done(ring.unget(0, null));
    live.set_bytes(-3); done(ring.put(1, live)); done(ring.unget(0, live));
    require(observer.count == calls);
    const auto preserved = live;
    require(ring.make_span(19, 2, live) == Status::invalid_span);
    require(live.offset() == preserved.offset() && live.bytes() == preserved.bytes());
}

void signed_words_and_permissive_counts() {
    Ring ring(65536, 0);
    Chunk span; done(ring.make_span(0, 65536, span));
    for (int i = 0; i < 32767; ++i) done(ring.put(0, span));
    require(ring.snapshot().free == std::numeric_limits<std::int32_t>::min());
    const auto before = ring.snapshot();
    require(ring.get(0, 1, span) == Status::unsafe_state); require(ring.snapshot() == before);
    std::int32_t grant = 0; bool fits = true;
    done(ring.peek(0, 1, grant, fits)); require(grant == std::numeric_limits<std::int32_t>::min() && !fits);
    done(ring.reset());
    done(ring.set_total(0, 0, 0xFFFFFFFE)); done(ring.get(0, 4, span));
    require(ring.snapshot().totals[0] == 2);
    std::uint32_t total = 99;
    require(ring.total(7, 1, total) == Status::invalid_selector && total == 99);
    require(ring.set_total(0, 9, 0) == Status::invalid_selector);
    done(ring.total(0, 0, total)); require(total == 2);
    done(ring.reset());
    std::int32_t grant_negative = 0; bool negative_fits = false;
    done(ring.peek(0, -3, grant_negative, negative_fits)); require(grant_negative == -3 && negative_fits);
}
}

int main() {
    try {
        geometry_and_storage(); suffix_transaction(); wrap_and_split(); errors_callbacks_and_guards();
        safety_refusals_and_reset(); signed_words_and_permissive_counts();
        std::cout << "SJRB native assertions passed: " << assertions << '\n';
    } catch (const std::exception& error) { std::cerr << error.what() << '\n'; return 1; }
}
