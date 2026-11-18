#pragma once
#include "world.hpp"
namespace reo::native::gameplay_world {
enum class PrimaryRecordsStatus {completed,busy,closed,not_empty,no_memory,entity_capacity};
struct PrimaryRecordsInitialized {
    PrimaryRecordsStatus status{PrimaryRecordsStatus::completed};std::size_t initialized{};
};
// Actual66A730 ordinary record clear, admitted only at bootstrap before any
// primary record exists. It establishes source zero values and capabilities;
// physical slot order does not imply the later authored actor.slot value.
PrimaryRecordsInitialized initialize_primary_records(World&)noexcept;
}
