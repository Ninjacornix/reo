#pragma once
#include "health.hpp"
#include <span>

namespace reo::native::gameplay_actors {
enum class ClassResult {unchanged,updated,invalid_maximum};
// Source-owned thresholds are supplied by the admitted game profile. Exceptional
// zero-denominator behavior is not replaced with invented IEEE/PS2 semantics.
ClassResult derive_health_class(HealthState&,std::span<const float,2> thresholds) noexcept;
} // namespace reo::native::gameplay_actors
