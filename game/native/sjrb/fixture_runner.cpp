// Transport only: synthetic original addresses terminate here, never in sjrb.
// Reads authored commands, calls the real core and prints observed JSON lines.
#include "sjrb.hpp"
#include <array>
#include <bit>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace reo::native::sjrb;
namespace {
constexpr std::int64_t buffer = 0x400010, slots_base = 0x500004;
void require(bool value, const char* message) { if (!value) throw std::runtime_error(message); }
void done(Status status) { require(status == Status::completed, "Core refused admitted transcript"); }
std::int32_t i32(std::int64_t value) { return std::bit_cast<std::int32_t>(static_cast<std::uint32_t>(value)); }
std::string hex(std::span<const std::uint8_t> bytes) {
    static constexpr char digits[] = "0123456789abcdef";
    std::string result; result.reserve(bytes.size() * 2);
    for (auto value : bytes) { result += digits[value >> 4]; result += digits[value & 15]; }
    return result;
}
struct Event { char kind{}; int before{}, after{}; Snapshot state{}; std::array<std::uint8_t, 256> descriptors{}; };
struct Transport {
    std::unique_ptr<Ring> ring;
    std::array<Chunk, 8> chunks{};
    std::array<bool, 8> initialized{};
    std::array<std::uint8_t, 256> descriptors{};
    std::array<Event, 8> events{};
    std::size_t event_count{};
    int depth{}, get_output{-1};
    std::int64_t peek_output{-1}, callback_address{-1};
    std::int32_t peek_granted{};
    std::vector<std::int32_t> callback_values;
    char error_kind{'X'};
    std::uint32_t context_token{};

    std::size_t raw_index(std::int64_t address) const {
        require(address >= slots_base - 4 && address + 4 <= slots_base - 4 + 256, "Descriptor address escaped");
        return static_cast<std::size_t>(address - (slots_base - 4));
    }
    void store(std::int64_t address, std::uint32_t value) {
        const auto offset = raw_index(address);
        for (int i = 0; i < 4; ++i) descriptors[offset + i] = static_cast<std::uint8_t>(value >> (8 * i));
    }
    std::uint32_t load(std::int64_t address) const {
        const auto offset = raw_index(address); std::uint32_t value = 0;
        for (int i = 0; i < 4; ++i) value |= std::uint32_t(descriptors[offset + i]) << (8*i);
        return value;
    }
    int slot(std::int64_t address) const {
        require(address >= slots_base && (address - slots_base) % 16 == 0 && address < slots_base + 128, "Unsupported descriptor identity");
        return static_cast<int>((address - slots_base) / 16);
    }
    void materialize(int index) {
        const auto address = slots_base + 16 * index;
        const auto pointer = load(address); const auto bytes = i32(load(address + 4));
        if (!pointer) chunks[index] = Chunk::null(bytes);
        else {
            require(pointer >= buffer, "Unowned span pointer");
            done(ring->make_span(i32(std::int64_t(pointer) - buffer), bytes, chunks[index]));
        }
        initialized[index] = true;
    }
    void sync(bool force_get) {
        for (int i = 0; i < 8; ++i) {
            if (!initialized[i] && !(force_get && i == get_output)) continue;
            if (i == get_output && !force_get) continue;
            store(slots_base + 16*i, chunks[i].is_null() ? 0 : static_cast<std::uint32_t>(buffer + chunks[i].offset()));
            store(slots_base + 16*i + 4, std::bit_cast<std::uint32_t>(chunks[i].bytes()));
        }
    }
    void record(char kind) noexcept {
        // Max 3 events per qualified method; no observer allocation in hooks.
        if (event_count >= events.size()) std::terminate();
        sync(kind != 'E');
        if (kind == 'L' && peek_output >= 0) store(peek_output, std::bit_cast<std::uint32_t>(peek_granted));
        auto& event = events[event_count++]; event.kind = kind; event.before = depth;
        if (kind == 'E') ++depth;
        if (kind == 'L') --depth;
        event.after = depth; event.state = ring->snapshot(); event.descriptors = descriptors;
    }
    static void enter(void* value) noexcept { static_cast<Transport*>(value)->record('E'); }
    static void leave(void* value) noexcept { static_cast<Transport*>(value)->record('L'); }
    static void error(void* value, std::int32_t code) noexcept {
        auto& t = *static_cast<Transport*>(value);
        if (code != -3) std::terminate();
        t.record(t.error_kind);
        if (t.callback_address >= 0) {
            // The frozen corpus's single external callback edits only length.
            if (t.callback_values.size() != 1 || (t.callback_address - slots_base) % 16 != 4) std::terminate();
            const auto index = t.slot(t.callback_address - 4);
            t.chunks[index].set_bytes(t.callback_values[0]);
            t.store(t.callback_address, std::bit_cast<std::uint32_t>(t.callback_values[0]));
        }
    }
    void write_words(std::int64_t address, const std::vector<std::int32_t>& values) {
        for (std::size_t i = 0; i < values.size(); ++i) store(address + 4 * static_cast<std::int64_t>(i), std::bit_cast<std::uint32_t>(values[i]));
        require(values.size() == 2, "Only complete authored descriptor writes admitted");
        materialize(slot(address));
    }
};
void state_json(const Snapshot& state) {
    std::cout << "{\"capacity\":" << state.capacity << ",\"extension\":" << state.extension
              << ",\"data\":" << state.data << ",\"free\":" << state.free << ",\"write\":" << state.write
              << ",\"read\":" << state.read << ",\"totals\":[";
    for (std::size_t i = 0; i < 4; ++i) { if (i) std::cout << ','; std::cout << state.totals[i]; }
    std::cout << "]}";
}
void emit(Transport& t, int index, const std::string& op, bool has_return, std::uint32_t result) {
    t.sync(true);
    if (t.get_output >= 0) t.initialized[t.get_output] = true;
    if (t.peek_output >= 0) {
        t.store(t.peek_output, std::bit_cast<std::uint32_t>(t.peek_granted));
        t.initialized[t.slot(t.peek_output)] = false; // Numeric count overwrites only first word.
    }
    std::vector<std::uint8_t> backing(t.ring->backing_size()); done(t.ring->read_backing(backing));
    std::cout << "{\"index\":" << index << ",\"op\":\"" << op << "\",\"return\":";
    if (has_return) std::cout << result; else std::cout << "null";
    std::cout << ",\"state\":"; state_json(t.ring->snapshot());
    std::cout << ",\"descriptors\":\"" << hex(t.descriptors) << "\",\"backing\":\"" << hex(backing) << "\",\"events\":[";
    for (std::size_t i = 0; i < t.event_count; ++i) {
        if (i) std::cout << ',';
        const auto& event = t.events[i];
        std::cout << "{\"kind\":\"" << event.kind << "\",\"before\":" << event.before << ",\"after\":" << event.after;
        if (event.kind == 'X' || event.kind == 'D') {
            if (event.kind == 'X') std::cout << ",\"code\":-3,\"context\":" << t.context_token;
            std::cout << ",\"state\":"; state_json(event.state);
            std::cout << ",\"descriptors\":\"" << hex(event.descriptors) << '"';
        }
        std::cout << '}';
    }
    std::cout << "]}\n";
}
}

int main(int argc, char** argv) {
    try {
        require(argc == 2, "Expected one authored command file");
        std::ifstream input(argv[1]); require(bool(input), "Cannot read command transcript");
        Transport t; t.descriptors.fill(0x5A);
        std::string command;
        while (input >> command) {
            if (command == "NEW") {
                std::int32_t capacity, extension; input >> capacity >> extension;
                t.ring = std::make_unique<Ring>(capacity, extension, Hooks{&t, Transport::enter, Transport::leave, Transport::error}, 0xA5);
            } else if (command == "WORDS" || command == "CALLBACK") {
                std::int64_t address, count; input >> address >> count;
                require(count > 0 && count < 8, "Unbounded authored word count");
                std::vector<std::int32_t> values;
                for (std::int64_t i = 0, value; i < count; ++i) { input >> value; values.push_back(i32(value)); }
                if (command == "WORDS") t.write_words(address, values);
                else { t.callback_address = address; t.callback_values = std::move(values); }
            } else if (command == "BYTES") {
                std::int64_t address; std::string bytes; input >> address >> bytes;
                require(bytes.size() % 2 == 0, "Odd authored byte string");
                std::vector<std::uint8_t> values;
                for (std::size_t i = 0; i < bytes.size(); i += 2) values.push_back(static_cast<std::uint8_t>(std::stoul(bytes.substr(i, 2), nullptr, 16)));
                Chunk span; done(t.ring->make_span(i32(address - buffer), static_cast<std::int32_t>(values.size()), span)); done(span.write(values));
            } else if (command == "CALL") {
                int index, count; std::string op; input >> index >> op >> count;
                require(count >= 0 && count <= 4, "Argument bound exceeded");
                std::array<std::int64_t, 4> a{}; for (int i = 0; i < count; ++i) input >> a[i];
                t.events = {}; t.event_count = 0; t.get_output = -1; t.peek_output = -1;
                bool returned = false; std::uint32_t result = 0;
                if (op == "set_error") {
                    t.error_kind = a[1] == 0x13F7D8 ? 'D' : 'X';
                    t.context_token = static_cast<std::uint32_t>(a[2]);
                    done(t.ring->set_hooks({&t, Transport::enter, Transport::leave, a[1] ? Transport::error : nullptr}));
                } else if (op == "get") {
                    t.get_output = t.slot(a[3]);
                    done(t.ring->get(static_cast<std::uint32_t>(a[1]), i32(a[2]), t.chunks[t.get_output]));
                } else if (op == "put" || op == "unget") {
                    auto& span = t.chunks[t.slot(a[2])]; require(t.initialized[t.slot(a[2])], "Uninitialized span input");
                    done(op == "put" ? t.ring->put(static_cast<std::uint32_t>(a[1]), span) : t.ring->unget(static_cast<std::uint32_t>(a[1]), span));
                } else if (op == "split") {
                    const int in = t.slot(a[0]), left = t.slot(a[2]), right = t.slot(a[3]);
                    require(t.initialized[in], "Uninitialized split input");
                    done(Chunk::split(t.chunks[in], i32(a[1]), t.chunks[left], t.chunks[right]));
                    t.initialized[left] = t.initialized[right] = true;
                } else if (op == "reset") done(t.ring->reset());
                else if (op == "count") {
                    std::int32_t value; done(t.ring->count(static_cast<std::uint32_t>(a[1]), value)); result = std::bit_cast<std::uint32_t>(value); returned = true;
                } else if (op == "peek") {
                    t.peek_output = a[3]; bool fits = false;
                    done(t.ring->peek(static_cast<std::uint32_t>(a[1]), i32(a[2]), t.peek_granted, fits)); result = fits; returned = true;
                } else if (op == "set_total") done(t.ring->set_total(static_cast<std::uint32_t>(a[1]), static_cast<std::uint32_t>(a[2]), static_cast<std::uint32_t>(a[3])));
                else if (op == "total") { done(t.ring->total(static_cast<std::uint32_t>(a[1]), static_cast<std::uint32_t>(a[2]), result)); returned = true; }
                else if (op == "capacity" || op == "extension") { result = op == "capacity" ? t.ring->snapshot().capacity : t.ring->snapshot().extension; returned = true; }
                else if (op != "uuid" && op != "buffer") throw std::runtime_error("Unsupported command operation");
                emit(t, index, op, returned, result);
            } else throw std::runtime_error("Unknown authored command");
            require(bool(input), "Truncated authored command");
        }
    } catch (const std::exception& error) { std::cerr << error.what() << '\n'; return 1; }
}
