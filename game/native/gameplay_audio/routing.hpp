#pragma once
#include "../audio_banks/v2/session.hpp"
#include "../gameplay_session/session.hpp"
#include <array>
#include <cstdint>

namespace reo::native::gameplay_audio {
namespace banks = audio_banks::v2;
struct Descriptor {
    std::uint8_t type{};
    std::uint16_t pitch{};
    std::uint8_t gain{}, pan{}, gain_variation{}, pitch_variation{}, group{}, replace_group{},
        next{};
    friend bool operator==(const Descriptor&, const Descriptor&) = default;
};
using Descriptors = std::array<Descriptor, 128>;
enum class Status {
    completed,
    skipped,
    pending,
    unavailable,
    invalid_input,
    invalid_asset,
    command_failed,
    cycle,
    stale,
    capacity,
    numeric_domain
};
struct Result {
    Status status{Status::unavailable};
    int source_return{};
    unsigned commands{};
};
// The standalone original-body oracle supplies a recording sink. Runtime uses
// Owner's concrete existing-bank Session sink, not an SDR/ADX queue.
class CommandSink {
  public:
    virtual ~CommandSink() = default;
    virtual bool apply(const banks::Command&) noexcept = 0;
};
struct Request {
    std::uint32_t bank{}, event{}, gain{UINT32_MAX}, pan{UINT32_MAX};
    std::uint8_t tag{};
    bool change{};
};
// Caller owns the canonical update/RNG order. A bounded repeated-link refusal
// is a deliberate safety extension; original Change can loop forever.
Result route(const Descriptors&, bool requested, std::uint8_t phase, Request,
             gameplay_session::Random&, CommandSink&) noexcept;
} // namespace reo::native::gameplay_audio
