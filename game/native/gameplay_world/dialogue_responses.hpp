#pragma once
#include "dialogue_conditions.hpp"
namespace reo::native::gameplay_update {class Owner;}
namespace reo::native::gameplay_world {
enum class DialogueResponseStage {entry,input,monitor,actor_prepare,target,priority,response,choice,construct,publication,records,durations};
struct DialogueResponseFrame {
    const gameplay_actors::input::Frame* menu_frame{};
    std::optional<std::uint32_t> menu_actions; //actual input::menu return4BAE90
    DialogueGates gates;
    DialogueConditionBindings conditions;
    gameplay_update::Owner* publication{}; //must be the same World's canonical Update owner
};
struct DialogueResponsesUpdated {
    DialogueStatus status{DialogueStatus::completed};
    DialogueResponseStage stage{DialogueResponseStage::entry};
    actors::EntityId actor;
    std::optional<std::size_t> selection;
    std::size_t actors{},evaluated{},constructed{},published{};
    DialoguePoolUpdated records;
};
}
