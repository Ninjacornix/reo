#pragma once
#include <cstdint>
#include <optional>
namespace reo::native::gameplay_world {
// Shared SPK state. Sequence/target/trigger roles follow the owned6B7930,
//6B8130/8440/88E0 consumers; response-state details retain their numeric value.
struct SpeechSelection {
    std::uint32_t sequence{};                    // DB4, one-based SPK selection
    std::int16_t target_identifier{-1};          // DC2
    std::int8_t target_context{-1};              // DC7, negative selects primary
    std::int8_t response_state{},pending{};       // DC1/DC0
};
struct SpeechState {
    std::optional<SpeechSelection> selection;
    std::optional<std::int32_t> gauge_notice;     // DB8, sender11 writes0/1
    std::optional<std::int8_t> variant;           // DA9; receipt can set this alone
};
}
