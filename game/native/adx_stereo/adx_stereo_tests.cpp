#include "adx_stereo.hpp"
#include <algorithm>
#include <array>
#include <atomic>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <new>
#include <stdexcept>

namespace { std::atomic<int> allocations_until_failure{-1}; }
#if defined(__GNUC__)
#define TEST_NOINLINE __attribute__((noinline))
#else
#define TEST_NOINLINE __declspec(noinline)
#endif
TEST_NOINLINE void* operator new(std::size_t size) {
    auto count = allocations_until_failure.load();
    if (count >= 0 && allocations_until_failure.fetch_sub(1) == 0) throw std::bad_alloc();
    if (auto* result = std::malloc(size ? size : 1)) return result;
    throw std::bad_alloc();
}
TEST_NOINLINE void operator delete(void* p) noexcept { std::free(p); }
TEST_NOINLINE void operator delete(void* p, std::size_t) noexcept { std::free(p); }
TEST_NOINLINE void* operator new[](std::size_t n) { return ::operator new(n); }
TEST_NOINLINE void operator delete[](void* p) noexcept { ::operator delete(p); }
TEST_NOINLINE void operator delete[](void* p, std::size_t) noexcept { ::operator delete(p); }

namespace a = reo::native::adx_stereo;
namespace {
unsigned checks{};
void check(bool value, const char* message) {
    ++checks;
    if (!value) throw std::runtime_error(message);
}
std::array<std::uint8_t, 36> pair(std::uint16_t lh, std::uint8_t lp,
                                  std::uint16_t rh, std::uint8_t rp) {
    std::array<std::uint8_t, 36> result;
    std::fill_n(result.begin(), 18, lp);
    std::fill(result.begin() + 18, result.end(), rp);
    result[0] = static_cast<std::uint8_t>(lh >> 8); result[1] = static_cast<std::uint8_t>(lh);
    result[18] = static_cast<std::uint8_t>(rh >> 8); result[19] = static_cast<std::uint8_t>(rh);
    return result;
}
a::Result decode(std::span<const std::uint8_t> data, std::int32_t count,
                 a::State state = {}, a::Parameters params = {},
                 a::Mode mode = a::Mode::separate_channels, a::Limits limits = {}) {
    return a::decode_keyed_stereo(data, count, state, params, mode, limits);
}
void refusal(const a::Result& result, a::Status status, a::State initial) {
    check(result.status == status, "typed refusal");
    check(result.left_pcm.empty() && result.right_pcm.empty() && result.state == initial &&
          !result.histories_committed && result.pairs_decoded == 0 &&
          result.encoded_bytes_consumed == 0 && result.encoded_bytes_inspected == 0,
          "refusal rolls back both channels, history and key");
}
void channel_geometry() {
    auto bytes = pair(1, 0, 3, 0);
    for (unsigned i = 0; i < 16; ++i) {
        bytes[2 + i] = static_cast<std::uint8_t>(((i % 16) << 4) | (15 - i));
        bytes[20 + i] = bytes[2 + i];
    }
    const auto original = bytes;
    auto result = decode(bytes, 3);
    check(result.status == a::Status::ok && result.kernel_return == 3 && result.pairs_decoded == 1,
          "odd count returns requested count with whole pair only");
    for (unsigned i = 0; i < 32; ++i) {
        const int code = i % 2 ? 15 - static_cast<int>(i / 2) : static_cast<int>(i / 2);
        const int signed_code = code < 8 ? code : code - 16;
        check(result.left_pcm[i] == signed_code * 2 && result.right_pcm[i] == signed_code * 4,
              "separate channel geometry and signed high/low nibble scales");
    }
    check(result.state.left == a::History{0, -2} && result.state.right == a::History{0, -4},
          "two independent histories are newest then previous");
    check(result.histories_committed && result.encoded_bytes_consumed == 36 &&
          result.encoded_bytes_inspected == 36 && bytes == original, "normal extents and immutable input");
}
void predictor_and_key() {
    const auto data = pair(0, 0, 0, 0);
    auto result = decode(data, 2, {{100, 50}, {-200, -100}, 0}, {4096, 0, 0, 0});
    check(result.left_pcm.front() == 100 && result.left_pcm.back() == 100 &&
          result.right_pcm.front() == -200 && result.right_pcm.back() == -200,
          "newest history independently feeds each channel");
    result = decode(data, 2, {{0, -1}, {0, -3}, 0}, {0, 1, 0, 0});
    check(result.left_pcm.front() == -1 && result.right_pcm.front() == -1,
          "negative predictor rounds down, not toward zero");
    result = decode(data, 2, {{-32768, -32768}, {-32768, -32768}, 0}, {-32768, -32768, 0, 0});
    check(result.left_pcm.front() == -32768 && result.right_pcm.front() == -32768,
          "low-word product sum wraps before arithmetic shift");
    result = decode(pair(0, 0x11, 0, 0x11), 2, {{}, {}, 65535}, {0, 0, -1, -1});
    check(result.left_pcm.front() == 8192 && result.right_pcm.front() == 1 && result.state.key == 32767,
          "unsigned initial key and signed multiplier/addend advance per channel");
    result = decode(pair(0x1FFF, 0x78, 0x1FFF, 0x87), 2);
    check(result.left_pcm[0] == 32767 && result.left_pcm[1] == -32768 &&
          result.right_pcm[0] == -32768 && result.right_pcm[1] == 32767, "signed channel clipping");
}
void downmix() {
    auto result = decode(pair(0, 0x11, 0, 0x22), 2, {}, {}, a::Mode::downmix_7_over_10);
    check(std::all_of(result.left_pcm.begin(), result.left_pcm.end(), [](auto v){ return v == 2; }) &&
          result.left_pcm == result.right_pcm, "7-over-10 downmix duplicates to both outputs");
    check(result.state.left == a::History{1, 1} && result.state.right == a::History{2, 2},
          "downmix keeps unmixed predictor histories");
    result = decode(pair(0, 0xFF, 0, 0xEE), 2, {}, {}, a::Mode::downmix_7_over_10);
    check(result.left_pcm[0] == -2, "negative downmix truncates toward zero");
    result = decode(pair(0x1FFF, 0x77, 0x1FFF, 0x77), 2, {}, {}, a::Mode::downmix_7_over_10);
    check(result.left_pcm[0] == 32767, "positive downmix saturates after channel saturation");
    result = decode(pair(0x1FFF, 0x88, 0x1FFF, 0x88), 2, {}, {}, a::Mode::downmix_7_over_10);
    check(result.left_pcm[0] == -32768, "negative downmix saturates after channel saturation");
}
void markers() {
    const a::State initial{{10, 20}, {30, 40}, 7};
    const a::Parameters params{0, 0, 1, 1};
    for (auto mode : {a::Mode::separate_channels, a::Mode::downmix_7_over_10}) {
        const std::array<std::uint8_t, 2> left_marker{0x80, 0};
        auto result = decode(left_marker, 2, initial, params, mode, {0});
        check(result.status == a::Status::ok && result.stop == a::Stop::left_marker &&
              result.state == initial && !result.histories_committed && result.kernel_return == 0 &&
              result.left_pcm.empty() && result.encoded_bytes_inspected == 2, "left marker only needs two bytes");
        const auto right_marker = pair(0, 0x77, 0x8000, 0);
        result = decode(std::span(right_marker).first(20), 2, initial, params, mode, {0});
        check(result.status == a::Status::ok && result.stop == a::Stop::right_marker &&
              result.state.left == initial.left && result.state.right == initial.right &&
              result.state.key == 8 && !result.histories_committed && result.kernel_return == 0 &&
              result.left_pcm.empty() && result.encoded_bytes_consumed == 0 &&
              result.encoded_bytes_inspected == 20, "right marker retains left key advance before PCM");
        auto data = pair(0, 0x11, 0, 0x22);
        std::vector<std::uint8_t> prefixed(data.begin(), data.end());
        prefixed.insert(prefixed.end(), right_marker.begin(), right_marker.begin() + 20);
        result = decode(prefixed, 5, initial, params, mode);
        check(result.kernel_return == 2 && result.pairs_decoded == 1 && result.left_pcm.size() == 32 &&
              result.state.key == 10 && result.state.left == initial.left && result.state.right == initial.right &&
              !result.histories_committed && result.encoded_bytes_consumed == 36 &&
              result.encoded_bytes_inspected == 56, "prefix marker retains PCM/key but discards local histories");
    }
}
void admission() {
    const a::State initial{{1, 2}, {3, 4}, 5};
    auto data = pair(0, 0, 0, 0);
    for (std::size_t n = 0; n < data.size(); ++n)
        refusal(decode(std::span(data).first(n), 2, initial), a::Status::short_input, initial);
    refusal(decode(data, 2, initial, {}, a::Mode::separate_channels, {31}), a::Status::output_limit, initial);
    check(decode(data, 2, initial, {}, a::Mode::separate_channels, {32}).status == a::Status::ok,
          "exact per-channel capacity accepted without read-ahead");
    for (const auto count : {std::numeric_limits<std::int32_t>::min(), -3, -1, 0, 1}) {
        const auto result = decode({}, count, initial, {}, a::Mode::separate_channels, {0});
        check(result.status == a::Status::ok && result.kernel_return == count && result.state == initial &&
              result.histories_committed && result.left_pcm.empty(), "nonpositive pair counts commit unchanged histories");
    }
    refusal(decode(data, 2, initial, {}, static_cast<a::Mode>(999)), a::Status::unsupported_mode, initial);
}
void allocation() {
    const auto data = pair(0, 0, 0, 0);
    const a::State initial{{1, 2}, {3, 4}, 5};
    for (int allocation_index : {0, 1}) {
        allocations_until_failure.store(allocation_index);
        const auto result = decode(data, 2, initial);
        check(allocations_until_failure.load() == -1, "injected first/second output allocation reached");
        refusal(result, a::Status::no_memory, initial);
    }
    check(decode(data, 2, initial).status == a::Status::ok, "allocation refusal leaves no sticky state");
}
} // namespace
int main() {
    try {
        channel_geometry(); predictor_and_key(); downmix(); markers(); admission(); allocation();
        std::cout << "native keyed stereo: " << checks << " synthetic checks passed in 6 groups\n";
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "native keyed stereo check failed: " << e.what() << '\n';
        return 1;
    }
}
