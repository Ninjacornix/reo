#include "adx_block.hpp"

#include <algorithm>
#include <array>
#include <atomic>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <new>
#include <stdexcept>
#include <string>

namespace { std::atomic<bool> fail_allocation{false}; }
#if defined(__GNUC__)
#define TEST_NOINLINE __attribute__((noinline))
#else
#define TEST_NOINLINE __declspec(noinline)
#endif
TEST_NOINLINE void* operator new(std::size_t size) {
    if (fail_allocation.exchange(false)) throw std::bad_alloc();
    if (auto* pointer = std::malloc(size ? size : 1)) return pointer;
    throw std::bad_alloc();
}
TEST_NOINLINE void operator delete(void* pointer) noexcept { std::free(pointer); }
TEST_NOINLINE void operator delete(void* pointer, std::size_t) noexcept { std::free(pointer); }
TEST_NOINLINE void* operator new[](std::size_t size) { return ::operator new(size); }
TEST_NOINLINE void operator delete[](void* pointer) noexcept { ::operator delete(pointer); }
TEST_NOINLINE void operator delete[](void* pointer, std::size_t) noexcept { ::operator delete(pointer); }

namespace a = reo::native::adx_block;
namespace {
unsigned checks{};
void check(bool condition, const char* message) {
    ++checks;
    if (!condition) throw std::runtime_error(message);
}
std::array<std::uint8_t, 18> block(std::uint16_t scale_header, std::uint8_t payload) {
    std::array<std::uint8_t, 18> result;
    result.fill(payload);
    result[0] = static_cast<std::uint8_t>(scale_header >> 8);
    result[1] = static_cast<std::uint8_t>(scale_header);
    return result;
}
std::vector<std::uint8_t> two(const std::array<std::uint8_t, 18>& first,
                             const std::array<std::uint8_t, 18>& second) {
    std::vector<std::uint8_t> result(first.begin(), first.end());
    result.insert(result.end(), second.begin(), second.end());
    return result;
}
void unchanged_failure(const a::Result& result, a::Status expected, a::State initial) {
    check(result.status == expected, "expected admission/allocation refusal");
    check(result.pcm.empty() && result.state == initial && !result.history_committed &&
          result.blocks_decoded == 0 && result.encoded_bytes_consumed == 0,
          "refusal is transactional for output, history and key");
}

void nibbles_and_scale() {
    auto data = block(1, 0);
    for (unsigned i = 0; i < 16; ++i)
        data[2 + i] = static_cast<std::uint8_t>(((2 * i % 16) << 4) | ((2 * i + 1) % 16));
    const auto original = data;
    const auto result = a::decode_keyed_mono(data, 1, {{123, -456}, 0}, {});
    check(result.status == a::Status::ok && result.kernel_return == 1 && result.blocks_decoded == 1,
          "one complete native block");
    const std::array<std::int16_t, 16> expected{0, 2, 4, 6, 8, 10, 12, 14, -16, -14, -12, -10, -8, -6, -4, -2};
    for (std::size_t i = 0; i < 32; ++i) check(result.pcm[i] == expected[i % 16], "signed nibble precedes scale");
    check(result.state.history == a::History{-2, -4} && result.history_committed, "final newest/previous order");
    check(result.encoded_bytes_consumed == 18 && result.encoded_bytes_inspected == 18, "normal encoded extent");
    check(data == original, "borrowed encoded input remains unchanged");
    const auto masked = a::decode_keyed_mono(block(0x2000, 0x11), 1, {}, {});
    check(std::all_of(masked.pcm.begin(), masked.pcm.end(), [](auto sample) { return sample == 1; }),
          "scale discards nonmarker bits outside 13-bit mask");
}

void predictor_arithmetic() {
    const auto walking = a::decode_keyed_mono(block(0, 0x11), 1, {{123, 7}, 0}, {4096, 0, 0, 0});
    for (std::size_t i = 0; i < walking.pcm.size(); ++i)
        check(walking.pcm[i] == static_cast<std::int16_t>(124 + i), "newest predictor progression");
    check(walking.state.history == a::History{155, 154}, "predictor history commits last two PCM values");
    const auto alternating = a::decode_keyed_mono(block(0, 0), 1, {{100, 5}, 0}, {0, 4096, 0, 0});
    for (std::size_t i = 0; i < alternating.pcm.size(); ++i)
        check(alternating.pcm[i] == (i % 2 ? 100 : 5), "older predictor progression");
    const auto negative = a::decode_keyed_mono(block(0, 0), 1, {{1, 0}, 0}, {-1, 0, 0, 0});
    check(negative.pcm[0] == -1 && negative.pcm[1] == 0, "arithmetic right shift rounds negative prediction downward");
    const auto wrapped = a::decode_keyed_mono(block(0, 0), 1, {{-32768, -32768}, 0}, {-32768, -32768, 0, 0});
    check(std::all_of(wrapped.pcm.begin(), wrapped.pcm.end(), [](auto sample) { return sample == -32768; }),
          "two positive products wrap at word width before predictor shift");
    const auto positive = a::decode_keyed_mono(block(0, 0), 1, {{32767, 32767}, 0}, {32767, 32767, 0, 0});
    check(std::all_of(positive.pcm.begin(), positive.pcm.end(), [](auto sample) { return sample == 32767; }),
          "positive predictor saturation");
    const auto clip = a::decode_keyed_mono(block(0x1FFF, 0x78), 1, {}, {});
    for (std::size_t i = 0; i < clip.pcm.size(); ++i)
        check(clip.pcm[i] == (i % 2 ? -32768 : 32767), "positive/negative sample clipping");
}

void key_state() {
    const auto data = two(block(0, 0x11), block(0, 0x11));
    const auto cycle = a::decode_keyed_mono(data, 2, {{}, 0x7FFF}, {0, 0, -1, -1});
    check(cycle.state.key == 0x7FFF, "signed key multiplication/addition and mask");
    check(cycle.pcm[0] == 8192 && cycle.pcm[32] == 1, "scale uses old key before per-block advancement");
    const auto high_bit = a::decode_keyed_mono(block(0, 0x11), 1, {{}, 0xFFFF}, {0, 0, -32768, -32768});
    check(high_bit.status == a::Status::ok && high_bit.state.key == 0 && high_bit.pcm[0] == 8192,
          "initial unsigned halfword key is not mistaken for an end marker");
    const auto keyed = a::decode_keyed_mono(two(block(0x1234, 0x11), block(0x3697, 0x11)),
                                           2, {{}, 0x1234}, {0, 0, 3, -5});
    check(keyed.state.key == 0x23C0 && std::all_of(keyed.pcm.begin(), keyed.pcm.end(),
          [](auto sample) { return sample == 1; }), "two signed-key updates and matching headers");
}

void marker_and_transaction() {
    const a::State initial{{10, 5}, 0};
    const a::Parameters parameters{4096, 0, 3, 7};
    auto data = std::vector<std::uint8_t>{0x80, 0};
    const auto first = a::decode_keyed_mono(data, std::numeric_limits<std::int32_t>::max(), initial, parameters, {0});
    check(first.status == a::Status::ok && first.stop == a::Stop::marker && first.kernel_return == 0 &&
          first.pcm.empty() && first.state == initial && !first.history_committed,
          "raw first header marker precedes key and needs no payload/output capacity");
    const auto ordinary = block(0, 0x11);
    data.assign(ordinary.begin(), ordinary.end());
    data.insert(data.end(), {0x80, 0});
    const auto prefix = a::decode_keyed_mono(data, 3, initial, parameters, {32});
    check(prefix.status == a::Status::ok && prefix.kernel_return == 1 && prefix.stop == a::Stop::marker,
          "marker returns completed prefix block count");
    check(prefix.pcm.size() == 32 && prefix.pcm.front() == 11 && prefix.pcm.back() == 42,
          "marker retains prior PCM effects");
    check(prefix.state.key == 7 && prefix.state.history == initial.history && !prefix.history_committed,
          "marker retains prior key but never commits local predictor history");
    check(prefix.encoded_bytes_consumed == 18 && prefix.encoded_bytes_inspected == 20,
          "marker is inspected but not consumed");
    data.pop_back();
    unchanged_failure(a::decode_keyed_mono(data, 3, initial, parameters), a::Status::short_input, initial);
    data.back() = 0;
    data.push_back(0);
    unchanged_failure(a::decode_keyed_mono(data, 3, initial, parameters), a::Status::short_input, initial);
    unchanged_failure(a::decode_keyed_mono(two(ordinary, ordinary), 2, initial, parameters, {32}),
                       a::Status::output_limit, initial);
    const auto one = a::decode_keyed_mono(two(ordinary, ordinary), 1, initial, parameters);
    check(one.kernel_return == 1 && one.pcm.size() == 32 && one.encoded_bytes_inspected == 18,
          "last requested block never speculatively reads another header");
}

void nonpositive_and_bounds() {
    const a::State initial{{-32768, 32767}, 0xFFFF};
    for (const auto count : {std::numeric_limits<std::int32_t>::min(), -7, -1, 0}) {
        const auto result = a::decode_keyed_mono({}, count, initial, {-32768, 32767, -32768, 32767}, {0});
        check(result.status == a::Status::ok && result.kernel_return == count && result.state == initial &&
              result.history_committed && result.pcm.empty() && result.blocks_decoded == 0,
              "nonpositive requested count returns unchanged signed count and normal history publication");
    }
    const auto input = block(0, 0);
    for (std::size_t size = 0; size < input.size(); ++size)
        unchanged_failure(a::decode_keyed_mono(std::span(input).first(size), 1, initial, {}),
                           a::Status::short_input, initial);
    unchanged_failure(a::decode_keyed_mono(input, 1, initial, {}, {31}), a::Status::output_limit, initial);
    const auto exactly = a::decode_keyed_mono(input, 1, initial, {}, {32});
    check(exactly.status == a::Status::ok && exactly.pcm.size() == 32, "exact output limit admitted");
    const auto arbitrary_limit = a::decode_keyed_mono(input, 1, initial, {}, {std::numeric_limits<std::size_t>::max()});
    check(arbitrary_limit.status == a::Status::ok && arbitrary_limit.pcm.size() == 32, "large limit does not force allocation");
}

void allocation_failure() {
    const auto data = block(0, 0x11);
    const a::State initial{{12, -34}, 0x1234};
    fail_allocation = true;
    const auto result = a::decode_keyed_mono(data, 1, initial, {1, 2, 3, 4});
    check(!fail_allocation, "allocation injection reached PCM allocation");
    unchanged_failure(result, a::Status::no_memory, initial);
    check(a::decode_keyed_mono(data, 1, initial, {}).status == a::Status::ok,
          "allocation refusal leaves no sticky decoder state");
}
} // namespace

int main() {
    try {
        nibbles_and_scale();
        predictor_arithmetic();
        key_state();
        marker_and_transaction();
        nonpositive_and_bounds();
        allocation_failure();
        std::cout << "native keyed mono block: " << checks << " synthetic contract checks passed in 6 groups\n";
        return 0;
    } catch (const std::exception& error) {
        std::cerr << "native keyed mono block check failed: " << error.what() << '\n';
        return 1;
    }
}
