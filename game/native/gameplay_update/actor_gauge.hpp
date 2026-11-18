#pragma once
#include <cstdint>
namespace reo::native::gameplay_update {
enum class GaugeStatus {completed,unavailable,event_unavailable};
struct GaugeResult {GaugeStatus status{GaugeStatus::completed};std::uint8_t value{};};
}
