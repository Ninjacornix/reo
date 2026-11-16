#pragma once
#include "world.hpp"
#include "interaction_transitions.hpp"

namespace reo::native::gameplay_world {

enum class ControlRequestFlowStatus { completed, unavailable };
struct ControlRequestFlowResult {
    ControlRequestFlowStatus status{ControlRequestFlowStatus::unavailable};
    bool original_result{};
};

// Only the original side-effecting consumers are supplied here. Their
// guest Boolean results are preserved separately from capability refusal.
class ControlRequestFlowServices {
public:
    virtual ~ControlRequestFlowServices()=default;
    virtual std::optional<bool> query_actor(World&,Actor&,std::uint8_t selector)=0; //663190; source return is ignored
    virtual std::optional<std::uint32_t> prepare_equipment(World&,Actor&)=0; //6507F0
    virtual bool consume_equipment(World&,Actor&,std::uint32_t)=0; //6506C0
    virtual bool activate_action(World&,Actor&)=0; //667370
    virtual bool notify(World&,Actor&,std::uint8_t selector)=0; //67E230
    virtual std::optional<std::int8_t> admit_control(World&,Actor&,std::uint8_t selector)=0; //6AF8B0
    virtual std::optional<std::int8_t> admit_actor(World&,Actor&)=0; //6AF9E0
    virtual bool publish_control(World&,Actor&,std::uint8_t selector,
                                 std::uint8_t control)=0; //67FF80
    virtual bool request_resource(World&,Actor&,std::uint8_t request)=0; //570080
};

// Native source-ordered64F2D0 state policy. Missing required consumers stop at
// their callsite, preserving every earlier actor mutation.
ControlRequestFlowResult process_control_request(World&,Actor&,
    ControlRequestFlowServices&,gameplay_update::RoomClaimSink* room_messages=nullptr);

} // namespace reo::native::gameplay_world
