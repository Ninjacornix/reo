#include "pcm_store.hpp"
#include <array>
#include <bit>
#include <cstdint>
#include <iostream>
#include <span>
#include <string>
#include <vector>

namespace a = reo::native::adx_pcm;
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
        auto& self = *static_cast<Recorder*>(p);
        std::array<std::uint8_t, a::capacity> data{};
        if (v.bytes() < 0 || v.bytes() > a::capacity || v.read_into(std::span(data).first(static_cast<std::size_t>(v.bytes()))) != a::Status::completed) self.failed = true;
        else self.callbacks.push_back(hex(std::span(data).first(static_cast<std::size_t>(v.bytes()))));
    }
};
}
int main() {
    std::string name, operation, left, right; unsigned channels; int queued, produced, published;
    while (std::cin >> name >> channels >> queued >> operation >> produced >> published >> left >> right) {
        Recorder recorder; a::Store owner({channels, 0, queued}, {&recorder, {}, Recorder::publication}, 0xa5);
        a::Status status = a::Status::completed;
        if (operation == "publish") {
            const auto l = pcm(left), r = pcm(right); auto reservation = owner.reserve(); status = reservation.status;
            if (status == a::Status::completed) status = owner.write_and_publish(reservation.lease, {l, r}, produced, published);
        } else if (operation != "backpressure") return 2;
        if (status != a::Status::completed || recorder.failed) return 3;
        const auto s = owner.snapshot();
        std::cout << "{\"name\":\"" << name << "\",\"rings\":[";
        for (unsigned c = 0; c < channels; ++c) {
            if (c) std::cout << ',';
            const auto r = s.rings[c];
            std::cout << '[' << r.data << ',' << r.free << ',' << r.write << ',' << r.read;
            for (const auto n : r.totals) std::cout << ',' << n;
            std::cout << ']';
        }
        std::cout << "],\"callbacks\":[";
        for (std::size_t i = 0; i < recorder.callbacks.size(); ++i) { if (i) std::cout << ','; std::cout << '"' << recorder.callbacks[i] << '"'; }
        std::cout << "],\"backings\":[";
        for (unsigned c = 0; c < channels; ++c) {
            if (c) std::cout << ',';
            std::array<std::uint8_t, a::capacity + a::extension> data{};
            if (owner.read_backing(c, data) != a::Status::completed) return 4;
            std::cout << '"' << hex(data) << '"';
        }
        std::cout << "]}\n";
    }
}
