#include "model_parts.hpp"
#include <cstring>
#include <stdexcept>

namespace reo::native::gameplay_world {
namespace {
std::uint32_t word(std::span<const std::byte> bytes,std::size_t offset) {
    if (offset > bytes.size() || sizeof(std::uint32_t) > bytes.size()-offset)
        throw std::invalid_argument("Truncated native model part directory");
    std::uint32_t value;
    std::memcpy(&value,bytes.data()+offset,sizeof(value));
    return value;
}
}

std::uint32_t model_part_count(std::span<const std::byte> bytes) {
    const auto count = word(bytes,4);
    std::size_t offset = 12;
    for (std::uint32_t index = 0; index < count; ++index) {
        const auto type = word(bytes,offset);
        // The first lookup uses an unsigned count. The following ordinal
        // lookup uses a signed count and visits no records when it is negative.
        if (type == 2) return (count&0x80000000u) ? 0 : word(bytes,offset+4);
        const auto size = word(bytes,offset+8);
        if (size < 12 || size > bytes.size()-offset)
            throw std::invalid_argument("Native model part record extent unavailable");
        offset += size;
    }
    return 0;
}
}
