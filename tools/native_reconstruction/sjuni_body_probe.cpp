// Isolated native-body probe for original guard/continuation comparisons.
// The binary protocol contains synthetic queue metadata, never code or payload.
#include "game/native/sjuni_adapter/queue_bridge.h"
#include <bit>
#include <fstream>
#include <stdexcept>
#include <vector>

namespace b = reo::sjuni::bridge;

static std::uint32_t read_word(std::istream& input) {
    std::uint32_t value = 0;
    for (unsigned i = 0; i != 4; ++i) {
        const int byte = input.get();
        if (byte == std::char_traits<char>::eof()) throw std::runtime_error("truncated probe input");
        value |= std::uint32_t(static_cast<unsigned char>(byte)) << (8 * i);
    }
    return value;
}
static void write_word(std::ostream& output, std::uint32_t value) {
    for (unsigned i = 0; i != 4; ++i) output.put(char((value >> (8 * i)) & 255u));
    if (!output) throw std::runtime_error("probe output failed");
}

int main(int argc, char** argv) {
    if (argc != 3) return 2;
    std::ifstream input(argv[1], std::ios::binary);
    std::ofstream output(argv[2], std::ios::binary | std::ios::trunc);
    if (!input || !output) return 2;
    const auto operation = read_word(input), queue = read_word(input), request = read_word(input);
    const auto object = read_word(input), count = read_word(input), descriptor = read_word(input);
    if (operation > 2 || count == 0 || count > 4096) return 2;
    std::vector<std::byte> bytes(8u * 1024u * 1024u);
    b::Memory memory(bytes);
    for (unsigned i = 0; i != 12; ++i)
        if (!memory.write32(object + 4 * i, read_word(input))) return 2;
    std::uint32_t node_base;
    if (!memory.read32(object + 12, node_base)) return 2;
    for (unsigned i = 0; i != count * 4; ++i)
        if (!memory.write32(node_base + 4 * i, read_word(input))) return 2;
    for (unsigned i = 0; i != 2; ++i)
        if (!memory.write32(descriptor + 4 * i, read_word(input))) return 2;
    if (input.peek() != std::char_traits<char>::eof()) return 2;
    const b::Profile profile{0x228c98u, 64u, 0x228c60u, 0x23da78u, 4096u};
    const b::Region region{1, 1, 0xffffffffull};
    const auto op = operation == 0 ? b::Operation::get : operation == 1 ? b::Operation::put : b::Operation::unget;
    const auto before = bytes;
    // The Python controller has already executed the original entry hook.
    // No native enter/leave callbacks are permitted in this body-only phase.
    const auto result = b::execute(memory, profile, object, std::span(&region, 1),
        {op, queue, std::bit_cast<std::int32_t>(request), descriptor}, {});
    if (result.disposition != b::Disposition::completed && bytes != before) return 3;
    write_word(output, std::uint32_t(result.disposition));
    for (unsigned i = 0; i != 12; ++i) {
        std::uint32_t value;
        if (!memory.read32(object + 4 * i, value)) return 2;
        write_word(output, value);
    }
    for (unsigned i = 0; i != count * 4; ++i) {
        std::uint32_t value;
        if (!memory.read32(node_base + 4 * i, value)) return 2;
        write_word(output, value);
    }
    for (unsigned i = 0; i != 2; ++i) {
        std::uint32_t value;
        if (!memory.read32(descriptor + 4 * i, value)) return 2;
        write_word(output, value);
    }
}
