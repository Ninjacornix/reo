#pragma once
#include <cstdint>
namespace reo::native::gameplay_world {class World;class ActorResourceOperations;}
namespace reo::native::gameplay_events {class Statistics;}
namespace reo::native::gameplay_update {class Owner;class StatePublication;}
namespace reo::native::gameplay_application {class SessionResources;}
namespace reo::native::gameplay_scenario {
enum class ActorScriptTerminalStatus {completed,closed,busy,unavailable_owner,publication_failure,resource_failure};
// Complete68EF50/669E00 over the canonical actor/resource/publication owners.
// This is distinct from61's health operation and6687A0's terminal timer.
class ActorScriptTerminal final {
public:
    bool bound_to(const gameplay_world::World&)const noexcept;
    bool ready()const noexcept;
    bool command_ready()const noexcept;
    ActorScriptTerminalStatus command()noexcept;
    bool retire_offline_actor_ready(std::uint32_t selector)const noexcept;
    ActorScriptTerminalStatus retire_offline_actor(std::uint32_t selector)noexcept; //702CE0
    ActorScriptTerminalStatus bind_resource_operations(gameplay_world::ActorResourceOperations*,
        gameplay_world::ActorResourceOperations* expected_current=nullptr)noexcept;
    ActorScriptTerminalStatus close()noexcept;
private:
    ActorScriptTerminal(gameplay_world::World&,gameplay_events::Statistics&,
        gameplay_update::StatePublication&,std::uint8_t& pause_latched)noexcept;
    ActorScriptTerminalStatus bind_roster_resources(gameplay_world::ActorResourceOperations*,
        gameplay_world::ActorResourceOperations* expected_current=nullptr)noexcept;
    gameplay_world::World& world_;
    gameplay_events::Statistics& statistics_;
    gameplay_update::StatePublication& publication_;
    std::uint8_t& pause_latched_; // sole Update.State4BADF9, distinct from World4BAE89
    gameplay_world::ActorResourceOperations* operations_{};
    bool running_{},closed_{};
    friend class gameplay_update::Owner;
    friend class gameplay_application::SessionResources;
};
}
