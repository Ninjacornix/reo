#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
#include <optional>

namespace reo::native::gameplay_world { class World; }
namespace reo::native::gameplay_scenario {
class CutsceneRequests {
public:
    using Record = std::array<std::uint16_t,8>;
    static constexpr std::size_t capacity = 16;

    // The original has wrapping read/write indices and no separate full bit.
    void append(const Record&) noexcept;
    std::optional<Record> take() noexcept;
    void clear() noexcept;
    const auto& records() const noexcept { return records_; }
    std::uint8_t read_index() const noexcept { return read_; }
    std::uint8_t write_index() const noexcept { return write_; }

    bool limit_override{}; // original4BAE77

private:
    std::array<Record,capacity> records_{};
    std::uint8_t read_{},write_{};
};

class ForcedActorTerminal {
public:
    virtual ~ForcedActorTerminal() = default;
    virtual bool apply(gameplay_world::World&,std::uint32_t mode) noexcept = 0;
};

bool queue_cutscene(gameplay_world::World&,const std::array<std::uint16_t,5>&,
                    ForcedActorTerminal*) noexcept;
}
