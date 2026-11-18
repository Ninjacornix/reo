#include "pcm_store.hpp"
#include <array>
#include <bit>
#include <cstdint>
#include <iostream>
#include <sstream>
#include <span>
#include <string>
#include <vector>

namespace a = reo::native::adx_pcm::v2;
namespace {
std::vector<std::int16_t> pcm(const std::string& hex) {
    std::vector<std::int16_t> values;
    if (hex == "-") return values;
    for (std::size_t i = 0; i < hex.size(); i += 4) {
        const auto low = std::stoul(hex.substr(i, 2), nullptr, 16);
        const auto high = std::stoul(hex.substr(i + 2, 2), nullptr, 16);
        values.push_back(std::bit_cast<std::int16_t>(static_cast<std::uint16_t>(low + (high << 8))));
    }
    return values;
}
std::string hex(std::span<const std::uint8_t> bytes) {
    constexpr char digits[] = "0123456789abcdef"; std::string result;
    result.reserve(bytes.size() * 2);
    for (const auto b : bytes) { result += digits[b >> 4]; result += digits[b & 15]; }
    return result;
}
struct Recorder {
    std::vector<std::string> callbacks; bool failed{};
    static void publication(void* p, std::uint32_t, const a::View& v) noexcept {
        auto& self = *static_cast<Recorder*>(p); std::array<std::uint8_t, a::capacity> data{};
        if (v.bytes() < 0 || v.bytes() > a::capacity || v.read_into(std::span(data).first(static_cast<std::size_t>(v.bytes()))) != a::Status::completed) self.failed = true;
        else self.callbacks.push_back(hex(std::span(data).first(static_cast<std::size_t>(v.bytes()))));
    }
};
std::string storage(const a::Store& owner, unsigned channels) {
    std::ostringstream out; const auto state = owner.snapshot(); out << "{\"rings\":[";
    for (unsigned c = 0; c < channels; ++c) {
        if (c) out << ',';
        const auto r = state.rings[c]; out << '[' << r.data << ',' << r.free << ',' << r.write << ',' << r.read;
        for (const auto n : r.totals) out << ',' << n;
        out << ']';
    }
    out << "],\"backings\":[";
    for (unsigned c = 0; c < channels; ++c) {
        if (c) out << ',';
        std::array<std::uint8_t, a::capacity + a::extension> bytes{};
        if (owner.read_backing(c, bytes) != a::Status::completed) throw std::runtime_error("backing");
        out << '"' << hex(bytes) << '"';
    }
    out << "]}"; return out.str();
}
}
int main() {
    std::string name, operation, left, right; unsigned channels; int queued, produced, published;
    while (std::cin >> name >> channels >> queued >> operation >> produced >> published >> left >> right) {
        Recorder recorder; a::Store owner({channels, 0, queued}, {&recorder, {}, Recorder::publication}, 0xa5);
        std::string staged = "null";
        if (operation == "publish") {
            const auto l = pcm(left), r = pcm(right); auto reservation = owner.reserve();
            if (reservation.status != a::Status::completed) return 2;
            if (owner.stage(reservation.lease, {l, r}, produced, published) != a::Status::completed) return 3;
            staged = storage(owner, channels);
            if (owner.publish(reservation.lease) != a::Status::completed) return 4;
        } else if (operation != "backpressure") return 5;
        if (recorder.failed) return 6;
        std::cout << "{\"name\":\"" << name << "\",\"stage\":" << staged << ",\"final\":" << storage(owner, channels) << ",\"callbacks\":[";
        for (std::size_t i = 0; i < recorder.callbacks.size(); ++i) { if (i) std::cout << ','; std::cout << '"' << recorder.callbacks[i] << '"'; }
        std::cout << "]}\n";
    }
}
