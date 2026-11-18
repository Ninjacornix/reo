#pragma once
#include <array>
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
    std::optional<std::int8_t> request;          // DA8,6B7D40 input/6B8130 response request
    std::optional<std::int16_t> notice;          // DAA,6B8440 sets and DBC expiration clears
    std::optional<std::int32_t> repeat_delay;    // DB0, selected primary request cooldown
    std::optional<std::int16_t> response_delay;  // DBE, response-state lifetime
    std::optional<std::int8_t> target_lock;      // DC5,6B88E0 retains a nearby target
    std::optional<std::int32_t> timing_active;   // DC8, enables DD0 accumulation
    std::optional<std::int32_t> previous_elapsed,elapsed; // DCC/DD0
    std::optional<std::uint8_t> remote_request;  //1098, consumed by6B7E40 ordinary nonzero slots
    std::optional<std::array<std::int8_t,4>> partner_characters; // DAC..DAF,6B8130 list of other primary characters
    std::optional<std::int8_t> variant;           // DA9; receipt can set this alone
    std::optional<std::int16_t> dialogue_delay;   // DBC,6B7930 cue delay
    std::optional<std::int8_t> display_style;      //1075,6B97D0 dialogue presentation
};
}
