#include "predictor_control.hpp"

#include <bit>
#include <fstream>
#include <iostream>
#include <map>
#include <optional>
#include <stdexcept>
#include <string>
#include <vector>

namespace c = reo::native::adx_control;
namespace {
unsigned unit_checks = 0;
void check(bool value, const char* message) {
    ++unit_checks;
    if (!value)
        throw std::runtime_error(message);
}
c::PredictorState sample(c::Phase phase = c::Phase::idle) {
    c::PredictorState value;
    value.phase = phase;
    value.completed_units = 0x89ABCDEF;
    value.mode = c::ChannelMode::stereo;
    value.encoded_input = {{0x123456789ABCDEF0ull}, 42};
    value.requested_units = 0xFFFFFFFF;
    value.left_output = {{0xFEDCBA9876543210ull}, 0xFFFFFFFC};
    value.right_output = {{93}, 17};
    value.history = {-32768, 32767, -1, 1};
    value.coefficients = {-4096, 123};
    value.key = {0xFFFF, 0x8001, 0x9234};
    return value;
}
void units() {
    const c::BufferPosition input{{91}, 7}, left{{92}, 11}, right{{93}, 13};
    for (const auto phase :
         {c::Phase::idle, c::Phase::requested, c::Phase::processing, c::Phase::ready}) {
        auto state = sample(phase), before = state;
        check(c::phase(state) == phase && c::completed(state) == before.completed_units,
              "Scalar queries preserve word values");
        const auto accepted = c::configure_mono(state, input, 0x80000000, left);
        check(accepted == (phase == c::Phase::idle), "Mono configuration is idle-only");
        if (phase == c::Phase::idle) {
            check(state.encoded_input == input && state.left_output == left &&
                      state.right_output == c::BufferPosition{} &&
                      state.mode == c::ChannelMode::mono && state.requested_units == 0x80000000,
                  "Mono selective configuration");
            check(state.history == before.history && state.coefficients == before.coefficients &&
                      state.key == before.key && state.completed_units == before.completed_units,
                  "Configure preserves history/key/coefficient/completion");
        } else
            check(state == before, "Busy configure changes no state");
        state = before;
        check(c::configure_stereo(state, input, 0xFFFFFFFF, left, right) ==
                  (phase == c::Phase::idle),
              "Stereo configuration is idle-only");
        if (phase != c::Phase::idle)
            check(state == before, "Busy stereo changes no state");
        else
            check(state.right_output == right && state.requested_units == 0xFFFFFFFF &&
                      state.mode == c::ChannelMode::stereo,
                  "Stereo retains raw count and independent output token");
        state = before;
        check(c::request_if_idle(state) == 1, "Request result is always one");
        if (phase == c::Phase::idle) {
            before.phase = c::Phase::requested;
            before.completed_units = 0;
        }
        check(state == before, "Request selective phase/completion mutation");
        state = sample(phase);
        before = state;
        c::acknowledge_ready(state);
        if (phase == c::Phase::ready)
            before.phase = c::Phase::idle;
        check(state == before, "Acknowledgement only changes ready phase");
        state = sample(phase);
        before = state;
        c::cancel(state);
        before.phase = c::Phase::idle;
        before.history = {};
        check(state == before, "Cancel resets phase/history and preserves remaining state");
    }
    auto state = sample();
    const c::WindowState window{
        input, {{0xFEDCBA9876543210ull}, 0xFFFFFFFC}, 0x7FFFFFFF, 0x80000001};
    check(c::request_stereo_window(state, window, 0x7FFFFFFF) == 1,
          "Window result preserves request scalar");
    check(state.requested_units == 0xFFFFFFFE && state.left_output.word_byte_offset == 0xFFFFFFFA &&
              state.right_output.word_byte_offset == 0xFFFFFFFC,
          "Window count and byte offsets wrap as words");
    check(state.left_output.span == window.output_base.span &&
              state.right_output.span == window.output_base.span,
          "Word arithmetic never truncates or changes opaque 64-bit span identity");
    state = sample(c::Phase::processing);
    const auto before = state;
    check(c::request_mono_window(state, window, 0) == 1 && state == before,
          "Busy mono wrapper ignores refusal then returns request one");
    check(c::request_stereo_window(state, window, 0xFFFFFFFF) == 1 && state == before,
          "Busy stereo wrapper preserves state despite returned one");
    state = sample();
    check(c::request_mono_window(state, window, 0xFFFFFFFF) == 1 &&
              state.requested_units == 0xFFFFFFFF,
          "Mono window retains signed-negative word without clamping");
    check(state.right_output == c::BufferPosition{}, "Mono window clears second output token");
    std::cout << "ADX_UNIT checks=" << unit_checks << '\n';
}

// Fixture transport/adaptation only. Synthetic original addresses and word
// layouts stay in this isolated test executable, never in the native core.
class Input {
    std::ifstream stream_;

  public:
    explicit Input(const char* path) : stream_(path, std::ios::binary) {
        if (!stream_)
            throw std::runtime_error("Cannot open ADX fixture input");
    }
    std::uint32_t word() {
        std::array<unsigned char, 4> bytes{};
        stream_.read(reinterpret_cast<char*>(bytes.data()), bytes.size());
        if (!stream_)
            throw std::runtime_error("Truncated ADX fixture input");
        return std::uint32_t(bytes[0]) | (std::uint32_t(bytes[1]) << 8) |
               (std::uint32_t(bytes[2]) << 16) | (std::uint32_t(bytes[3]) << 24);
    }
    std::string text(std::size_t limit) {
        const auto size = word();
        if (size > limit)
            throw std::runtime_error("ADX fixture text bound");
        std::string value(size, '\0');
        stream_.read(value.data(), value.size());
        if (!stream_)
            throw std::runtime_error("Truncated ADX fixture text");
        return value;
    }
    void header() {
        std::array<char, 8> bytes{};
        stream_.read(bytes.data(), bytes.size());
        if (!stream_ || bytes != std::array<char, 8>{'A', 'D', 'X', 'C', 'T', 'L', '1', 0} ||
            word() != 1)
            throw std::runtime_error("Unsupported ADX control fixture format");
    }
    void end() {
        if (stream_.peek() != std::char_traits<char>::eof())
            throw std::runtime_error("Trailing ADX fixture input");
    }
};
struct Snapshot {
    std::array<std::uint32_t, 15> context;
    std::array<std::uint32_t, 32> decoder;
    std::array<std::uint32_t, 192> payload;
    friend bool operator==(const Snapshot&, const Snapshot&) = default;
};
Snapshot snapshot(Input& input) {
    Snapshot result;
    for (auto& word : result.context)
        word = input.word();
    for (auto& word : result.decoder)
        word = input.word();
    for (auto& word : result.payload)
        word = input.word();
    return result;
}
class Tokens {
    static constexpr std::uint32_t payload_base = 0x500000;
    static constexpr std::uint64_t payload_id = 0xFEDCBA9876543210ull;
    std::map<std::uint32_t, std::uint64_t> ids;
    std::map<std::uint64_t, std::uint32_t> bases;

  public:
    Tokens() {
        bases.emplace(payload_id, payload_base);
    }
    c::BufferPosition decode(std::uint32_t value) {
        if (!value)
            return {};
        if (value >= payload_base && value < payload_base + 0x300)
            return {{payload_id}, value - payload_base};
        const auto found = ids.find(value);
        if (found != ids.end())
            return {{found->second}, 0};
        const auto id = std::uint64_t(ids.size()) + 1;
        ids.emplace(value, id);
        bases.emplace(id, value);
        return {{id}, 0};
    }
    std::uint32_t export_word(c::BufferPosition value) const {
        if (!value.span.value) {
            if (value.word_byte_offset)
                throw std::runtime_error("Unmapped fixture null token offset");
            return 0;
        }
        return bases.at(value.span.value) + value.word_byte_offset;
    }
};
std::int16_t signed_half(std::uint32_t word, unsigned shift) {
    return std::bit_cast<std::int16_t>(static_cast<std::uint16_t>(word >> shift));
}
c::PredictorState import_state(const Snapshot& image, Tokens& tokens) {
    const auto& w = image.context;
    c::PredictorState result;
    result.phase = static_cast<c::Phase>(w[3]);
    result.completed_units = w[4];
    result.mode = static_cast<c::ChannelMode>(w[5]);
    result.encoded_input = tokens.decode(w[6]);
    result.requested_units = w[7];
    result.left_output = tokens.decode(w[8]);
    result.right_output = tokens.decode(w[9]);
    result.history = {signed_half(w[10], 0), signed_half(w[10], 16), signed_half(w[11], 0),
                      signed_half(w[11], 16)};
    result.coefficients = {signed_half(w[12], 0), signed_half(w[12], 16)};
    result.key = {static_cast<std::uint16_t>(w[13]), static_cast<std::uint16_t>(w[13] >> 16),
                  static_cast<std::uint16_t>(w[14])};
    return result;
}
std::uint32_t pack(std::int16_t low, std::int16_t high) {
    return std::uint32_t(static_cast<std::uint16_t>(low)) |
           (std::uint32_t(static_cast<std::uint16_t>(high)) << 16);
}
void export_state(Snapshot& image, const c::PredictorState& state, const Tokens& tokens) {
    auto& w = image.context;
    w[3] = static_cast<std::uint32_t>(state.phase);
    w[4] = state.completed_units;
    w[5] = static_cast<std::uint32_t>(state.mode);
    w[6] = tokens.export_word(state.encoded_input);
    w[7] = state.requested_units;
    w[8] = tokens.export_word(state.left_output);
    w[9] = tokens.export_word(state.right_output);
    w[10] = pack(state.history[0], state.history[1]);
    w[11] = pack(state.history[2], state.history[3]);
    w[12] = pack(state.coefficients[0], state.coefficients[1]);
    w[13] = std::uint32_t(state.key.value) | (std::uint32_t(state.key.multiplier) << 16);
    w[14] = (w[14] & 0xFFFF0000u) | state.key.addend;
}
std::optional<std::uint32_t> operate(std::uint32_t operation,
                                     const std::vector<std::uint32_t>& args,
                                     c::PredictorState& state, const Snapshot& image,
                                     Tokens& tokens) {
    const auto needed = operation == 1 ? 4u : operation == 2 ? 5u : operation >= 7 ? 2u : 1u;
    if (operation > 8 || args.size() != needed ||
        args[0] != (operation >= 7 ? 0x410000u : 0x400000u))
        throw std::runtime_error("Unexpected fixture operation/arguments");
    switch (operation) {
        case 0:
            return static_cast<std::uint32_t>(c::phase(state));
        case 1:
            return c::configure_mono(state, tokens.decode(args[1]), args[2], tokens.decode(args[3]))
                       ? 1u
                       : 0u;
        case 2:
            return c::configure_stereo(state, tokens.decode(args[1]), args[2],
                                       tokens.decode(args[3]), tokens.decode(args[4]))
                       ? 1u
                       : 0u;
        case 3:
            return c::request_if_idle(state);
        case 4:
            c::cancel(state);
            return {};
        case 5:
            c::acknowledge_ready(state);
            return {};
        case 6:
            return c::completed(state);
        default: {
            if (image.decoder[2] != 0x400000)
                throw std::runtime_error("Unexpected fixture predictor binding");
            const c::WindowState window{tokens.decode(image.decoder[18]),
                                        tokens.decode(image.decoder[23]), image.decoder[26],
                                        image.decoder[25]};
            return operation == 7 ? c::request_mono_window(state, window, args[1])
                                  : c::request_stereo_window(state, window, args[1]);
        }
    }
}
void compare(const char* filename) {
    Input input(filename);
    input.header();
    const auto cases = input.word();
    if (cases != 16)
        throw std::runtime_error("Expected the complete original16-case fixture");
    unsigned calls = 0, defined = 0, ignored_void = 0;
    for (std::uint32_t i = 0; i < cases; ++i) {
        const auto name = input.text(256);
        auto actual = snapshot(input);
        const auto decoder_before = actual.decoder;
        const auto payload_before = actual.payload;
        Tokens tokens;
        auto state = import_state(actual, tokens);
        const auto count = input.word();
        if (count > 256)
            throw std::runtime_error("Fixture call count bound");
        for (std::uint32_t j = 0; j < count; ++j) {
            const auto operation = input.word(), argc = input.word();
            if (argc > 5)
                throw std::runtime_error("Fixture argument bound");
            std::vector<std::uint32_t> args(argc);
            for (auto& arg : args)
                arg = input.word();
            const auto is_defined = input.word(), expected_return = input.word();
            const auto expected = snapshot(input);
            const auto returned = operate(operation, args, state, actual, tokens);
            if (is_defined > 1 || bool(is_defined) != returned.has_value() ||
                (returned && *returned != expected_return))
                throw std::runtime_error(name + ": native defined return differs");
            export_state(actual, state, tokens);
            if (actual != expected)
                throw std::runtime_error(name + ": native full relevant memory image differs");
            if (actual.decoder != decoder_before || actual.payload != payload_before)
                throw std::runtime_error(name + ": decoder/payload changed");
            ++calls;
            if (returned)
                ++defined;
            else
                ++ignored_void;
        }
    }
    input.end();
    if (calls != 96 || defined != 72 || ignored_void != 24)
        throw std::runtime_error("Incomplete original-word comparison");
    std::cout << "ADX_COMPARE cases=" << cases << " calls=" << calls << " state_images=" << calls
              << " snapshot_words=" << calls * (15 + 32 + 192) << " defined_returns=" << defined
              << " ignored_void_returns=" << ignored_void << '\n';
}
} // namespace
int main(int argc, char** argv) {
    try {
        if (argc == 1 || (argc == 2 && std::string(argv[1]) == "--unit"))
            units();
        else if (argc == 3 && std::string(argv[1]) == "--fixtures")
            compare(argv[2]);
        else
            throw std::runtime_error("Use --unit or --fixtures <bounded binary fixture>");
        return 0;
    } catch (const std::exception& error) {
        std::cerr << "FAIL: " << error.what() << '\n';
        return 1;
    }
}
