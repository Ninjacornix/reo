#include "update.hpp"
#include "../gameplay_scenario/script_program.hpp"
#include <stdexcept>

namespace reo::native::gameplay_update {
namespace {
using scenario::DispatchProfile;
using scenario::content::BankFormat;
using scenario::content::ScriptAdmission;
using scenario::content::ScriptProgram;

DispatchProfile dispatch_profile(const world::World& world) noexcept {
    return world.mode == 0 ? DispatchProfile::offline_actor : DispatchProfile::ordinary;
}

Status bind(scenario::Interpreter& vm, const ScriptProgram& script,
            std::size_t primary, std::size_t secondary) noexcept {
    if (script.status != ScriptAdmission::admitted || !script.entries[0]) return Status::script_failure;
    const std::array<scenario::ChannelReplacement,2> replacements{{
        {primary,script.program,script.entries[0]},
        {secondary,script.entries[1] ? script.program : nullptr,script.entries[1]}
    }};
    switch (vm.replace_channels(replacements)) {
    case scenario::Status::completed: return Status::completed;
    case scenario::Status::busy: return Status::busy;
    default: return Status::script_failure;
    }
}
}

Status Owner::bind_scenario_scripts(const scenario::content::ScriptBank& bank,std::uint8_t policy_row) {
    if (!open()) return Status::closed;
    if (running_) return Status::busy;
    using gameplay_collision::delivery::RoomCounterPolicy;
    if (bank.format() != BankFormat::scenario_evb || policy_row >= RoomCounterPolicy::rows)
        return Status::script_failure;
    std::optional<RoomCounterPolicy::ScenarioRows> rows;
    try { rows = scenario::content::import_room_counter_rows(bank); }
    catch (const std::invalid_argument&) { return Status::script_failure; }
    const auto script = scenario::content::admit_script_program(bank,dispatch_profile(world_));
    if (script.program && script.program->needs_scenario_counter_policy() && !rows)
        return Status::script_failure;
    const auto status = bind(scripts_,script,0,4);
    if (status != Status::completed) return status;
    // The row was checked and the channel swap ran synchronously on this owner.
    (void)world_.session().room_contacts.initialize_counters(policy_row,rows);
    (void)scripts_.restore_counters({});
    return Status::completed;
}

Status Owner::bind_room_scripts(const scenario::content::ScriptBank& bank,std::size_t room_channel) {
    if (!open()) return Status::closed;
    if (running_) return Status::busy;
    const auto profile = dispatch_profile(world_);
    if (bank.format() != BankFormat::room_section || room_channel == 0 || room_channel > 3 ||
        (profile == DispatchProfile::ordinary && room_channel != 1))
        return Status::script_failure;
    const auto script = scenario::content::admit_script_program(bank,profile);
    if (script.program && !script.program->admits_room_counters(&world_)) return Status::script_failure;
    return bind(scripts_,script,room_channel,5);
}
}
