#pragma once
#include "actor_resource_operations.hpp"
#include "behavior.hpp"
namespace reo::native::gameplay_world {
// Complete6687A0 through the actual5F6800 inventory consumer and native pose
// snapshot. Borrowed world/resource owners outlive this object and its adapter.
class ActorTerminalTimer final:public TerminalTiming {
public:
    ActorTerminalTimer(World&,ActorResourceOperations&);
    void tick(const actors::EntityId&);
    bool apply_terminal_timer(World&,Actor&)override;
private:
    World& world_;ActorResourceOperations& operations_;
};
}
