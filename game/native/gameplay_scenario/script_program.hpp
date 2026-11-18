#pragma once
#include "content.hpp"
#include "interpreter.hpp"

namespace reo::native::gameplay_scenario::content {
enum class ScriptAdmission {
    admitted, absent, unsupported_opcode, invalid_record, unbound_block,
    unknown_continuation, work_limit, invalid_payload
};

enum class ScriptRoots { configured, scenario_startup };

struct ScriptProgram {
    ScriptAdmission status{ScriptAdmission::absent};
    std::shared_ptr<const Program> program;
    std::array<std::optional<Position>, 2> entries;
    Position failure;
    std::uint32_t opcode{};
};

// Prove both configured roots with an initially unbound continuation. Preserve
// table indices in the Program and import only bytes traversed by the proof.
// Providers and caller channel ownership are checked separately at execution.
// 68C890 starts EVB table entry 1, independently of the configured 0/4 roots.
// That request proves only the startup closure and requires the entry to exist.
ScriptProgram admit_script_program(const ScriptBank&, DispatchProfile,
                                  ScriptRoots = ScriptRoots::configured);
}
