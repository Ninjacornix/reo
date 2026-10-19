#pragma once
#include <cstdint>
#include <cstring>
#include <istream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <vector>

namespace reo::cheats {
struct Write {
    unsigned place;
    uint32_t address;
    unsigned size;
    uint64_t value;
};
inline bool dataAddress(uint32_t a, unsigned n) {
    return (n == 1 || n == 2 || n == 4 || n == 8) && a >= 0x370000u &&
           uint64_t(a) + n <= 0x1fd0000u && !(a < 0x900000u && uint64_t(a) + n > 0x570000u);
}
inline std::vector<Write> parse(std::istream& input) {
    std::string line;
    std::getline(input, line);
    if (line != "REO-CHEATS-1")
        throw std::runtime_error("Invalid native cheat manifest");
    std::vector<Write> result;
    while (std::getline(input, line)) {
        if (line.empty())
            continue;
        Write w{};
        std::istringstream row(line);
        std::string extra;
        if (!(row >> std::dec >> w.place >> std::hex >> w.address >> std::dec >> w.size >>
              std::hex >> w.value) ||
            (row >> extra) || w.place > 3 || !dataAddress(w.address, w.size) ||
            (w.size < 8 && w.value >= (uint64_t(1) << (w.size * 8))) || result.size() >= 4096)
            throw std::runtime_error("Unsupported native data cheat");
        result.push_back(w);
    }
    return result;
}
inline void apply(const std::vector<Write>& writes, uint8_t* ram, bool boot) {
    for (const auto& w : writes) {
        if (boot ? w.place == 1 : (w.place == 0 || w.place == 3))
            continue;
        for (unsigned i = 0; i < w.size; ++i)
            ram[w.address + i] = uint8_t(w.value >> (i * 8));
    }
}
} // namespace reo::cheats
