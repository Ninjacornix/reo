#pragma once
#include "../gameplay_session/launch.hpp"

namespace reo::native::gameplay_scenario { class ActionChoices; }
namespace reo::native::gameplay_world {
class World;

// Apply the roster to pre-existing canonical primary actors, after validating
// every destination. Physical actor creation belongs to the session owner.
bool apply_launch_roster(World&,gameplay_scenario::ActionChoices&,
                        const gameplay_session::LaunchRoster&) noexcept;
}
