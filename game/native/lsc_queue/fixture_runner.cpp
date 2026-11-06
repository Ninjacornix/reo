#include "queue.hpp"
#include <iostream>
#include <sstream>
#include <vector>

namespace q = reo::native::lsc_queue;
std::string decode(const std::string& hex) {
    std::string bytes;
    if (hex == "-") return bytes;
    for (std::size_t i = 0; i < hex.size(); i += 2)
        bytes += static_cast<char>(std::stoul(hex.substr(i, 2), nullptr, 16));
    return bytes;
}
struct Ports final : q::LowerFile, q::EmptyNotification, q::Errors {
    q::Queue* queue{}; bool available{};
    std::int32_t lower_state{}; std::uint32_t lower_progress{};
    std::string callback;
    std::vector<std::shared_ptr<const q::Name>> names;
    std::vector<std::string> events;
    int index(const std::shared_ptr<const q::Name>& name) const {
        if (!name) return -1;
        for (std::size_t i = 0; i < names.size(); ++i) if (names[i] == name) return static_cast<int>(i);
        throw std::runtime_error("Unknown native sealed filename");
    }
    void event(std::string_view name, std::initializer_list<std::int64_t> args) {
        std::ostringstream out; out << "{\"event\":\"" << name << "\",\"args\":[";
        bool comma = false;
        for (const auto value : args) { if (comma) out << ','; comma = true; out << value; }
        out << "]}"; events.push_back(out.str());
    }
    bool present() const noexcept override { return available; }
    void stop_before_open() noexcept override { event("stop_lower", {available}); }
    void close_before_open() noexcept override { event("close_lower", {available}); }
    void open_range(const q::Entry& entry) noexcept override {
        event("open_range", {available, index(entry.name), entry.range.parent, entry.range.first_sector, entry.range.sectors});
    }
    void set_limit(std::uint32_t value) noexcept override { event("limit", {available, value}); }
    void thresholds(std::uint32_t minimum, std::uint32_t capacity) noexcept override { event("thresholds", {available, minimum, capacity}); }
    void position(std::uint32_t value) noexcept override { event("position", {available, value}); }
    void start() noexcept override { event("start_lower", {available}); }
    void stop_async() noexcept override { event("stop_async", {available}); }
    std::int32_t state() noexcept override {
        events.push_back("{\"event\":\"query_state\",\"args\":[" + std::to_string(available) + "],\"return\":" + std::to_string(static_cast<std::uint32_t>(lower_state)) + "}");
        return lower_state;
    }
    std::uint32_t progress_sectors() noexcept override {
        events.push_back("{\"event\":\"query_progress\",\"args\":[" + std::to_string(available) + "],\"return\":" + std::to_string(lower_progress) + "}");
        return lower_progress;
    }
    void report(q::Error error) noexcept override {
        // Original diagnostic identities belong to this comparison adapter.
        constexpr std::array<std::uint32_t, 5> formats{0x23d390, 0x23d3b8, 0x23d3d8, 0x23d400, 0x23d498};
        events.push_back("{\"event\":\"diagnostic\",\"format\":" + std::to_string(formats.at(static_cast<unsigned>(error))) + "}");
    }
    void notify() noexcept override {
        events.push_back("{\"event\":\"empty\"}");
        if (callback == "disable_repeat") queue->repeat(0);
        else if (callback == "pause") queue->pause(1);
        else if (callback == "remove_file") available = false;
        else if (callback == "stop") queue->stop();
        else if (callback == "start") queue->start();
        else if (callback == "enqueue") {
            const auto result = queue->enqueue({names.at(1), {29, 7, 9}});
            events.push_back("{\"event\":\"callback_enqueue\",\"result\":" + std::to_string(static_cast<std::uint32_t>(result)) + "}");
        }
    }
};
void snapshot(const q::Snapshot& state, const Ports& ports) {
    std::cout << "{\"flags\":[" << unsigned(state.state) << ',' << unsigned(state.transferring) << ','
              << unsigned(state.repeat) << ',' << unsigned(state.paused) << "],\"minimum\":" << state.minimum
              << ",\"capacity\":" << state.capacity << ",\"tail\":" << state.tail << ",\"head\":" << state.head
              << ",\"count\":" << state.count << ",\"file\":" << (state.file_present ? "true" : "false")
              << ",\"limit\":" << state.limit << ",\"extra\":" << state.extra << ",\"slots\":[";
    for (unsigned i = 0; i < q::slots; ++i) {
        if (i) std::cout << ',';
        const auto& r = state.records[i];
        std::cout << '[' << r.sequence << ',' << ports.index(r.entry.name) << ',' << r.checksum << ','
                  << r.entry.range.parent << ',' << r.entry.range.first_sector << ',' << r.entry.range.sectors
                  << ',' << r.status << ',' << r.progress << ']';
    }
    std::cout << "]}";
}
int main() { try {
    std::string name, callback; q::Config config; unsigned present, count, operations;
    while (std::cin >> name >> config.initial_slot >> config.previous_sequence >> config.capacity_bytes >> present >> callback >> count >> operations) {
        auto ports = std::make_shared<Ports>(); ports->available = present != 0; ports->callback = callback;
        for (unsigned i = 0; i < count; ++i) { std::string hex; std::cin >> hex; ports->names.push_back(q::Name::prepare(decode(hex))); }
        q::Queue queue(config, ports, ports, ports); ports->queue = &queue;
        for (unsigned i = 0; i < operations; ++i) {
            std::string operation; unsigned arguments; std::cin >> operation >> arguments;
            std::array<std::int64_t, 4> args{};
            for (unsigned a = 0; a < arguments; ++a) std::cin >> args.at(a);
            std::cin >> ports->lower_state >> ports->lower_progress;
            if (!std::cin) throw std::runtime_error("Incomplete native queue plan");
            ports->events.clear(); bool defined = false; std::int64_t result{};
            if (operation == "enqueue") { defined = true; result = static_cast<std::uint32_t>(queue.enqueue({ports->names.at(args[0]), {static_cast<std::uint32_t>(args[1]), static_cast<std::uint32_t>(args[2]), static_cast<std::uint32_t>(args[3])}})); }
            else if (operation == "clear") queue.clear();
            else if (operation == "start") queue.start();
            else if (operation == "stop") queue.stop();
            else if (operation == "pause") queue.pause(static_cast<std::int32_t>(args[0]));
            else if (operation == "repeat") queue.repeat(static_cast<std::int32_t>(args[0]));
            else if (operation == "minimum") queue.minimum(static_cast<std::int32_t>(args[0]));
            else if (operation == "service") { if (queue.service() != q::Service::completed) throw std::runtime_error("Unexpected native service reentry"); }
            else if (operation == "ordinal") { defined = true; result = static_cast<std::uint32_t>(queue.ordinal(static_cast<std::int32_t>(args[0]))); }
            else if (operation == "name") { defined = true; result = ports->index(queue.name(static_cast<std::uint32_t>(args[0]))); }
            else if (operation == "status") { defined = true; result = static_cast<std::uint32_t>(queue.status(static_cast<std::uint32_t>(args[0]))); }
            else if (operation == "progress") { defined = true; result = queue.progress(static_cast<std::uint32_t>(args[0])); }
            else throw std::runtime_error("Unknown native queue operation");
            std::cout << "{\"case\":\"" << name << "\",\"operation\":" << i << ",\"projection\":{\"result\":";
            if (defined) std::cout << result; else std::cout << "null";
            std::cout << ",\"events\":[";
            for (unsigned e = 0; e < ports->events.size(); ++e) { if (e) std::cout << ','; std::cout << ports->events[e]; }
            std::cout << "],\"after\":"; snapshot(queue.snapshot(), *ports); std::cout << "}}\n";
        }
    }
    if (!std::cin.eof()) throw std::runtime_error("Malformed native queue plan");
} catch (const std::exception& e) { std::cerr << e.what() << '\n'; return 1; } }
