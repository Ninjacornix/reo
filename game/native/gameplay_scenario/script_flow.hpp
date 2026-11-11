#pragma once
#include "interpreter.hpp"

namespace reo::native::gameplay_scenario::detail {
enum class ScriptFlow {
    next, remember, resume, resume_yield, next_block, next_block_yield,
    skip, delay, if_test, if_test_without_open, else_scan, end_if
};

struct ScriptFlowBinding {
    ScriptFlow flow{ScriptFlow::next};
    std::size_t minimum_payload{};
    bool opens_condition{};
    bool context_dependent{};
};

ScriptFlowBinding script_flow_binding(std::uint32_t opcode, DispatchProfile) noexcept;
}
