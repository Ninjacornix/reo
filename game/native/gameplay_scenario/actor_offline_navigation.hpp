#pragma once
#include "../gameplay_actors/entity.hpp"
#include <cstdint>
#include <memory>
namespace reo::native::gameplay_update {class Owner;}
namespace reo::native::gameplay_world {class World;class ActorResourceOperations;class ActorForcedTerminal;struct Actor;}
namespace reo::native::gameplay_collision::response {class Grid;}
namespace reo::native::gameplay_application {class SessionResources;}
namespace reo::native::gameplay_scenario {
class Interpreter;class SceneControls;class SceneModels;class SceneMatrixPrograms;
enum class OfflineNavigationStatus {completed,busy,closed,unavailable,publication_failure,resource_failure,script_failure};
// Source702740 and its819880/6F9600/812170 callers operate on this one
// canonical World, interpreter and borrowed scene/resource owners.
class ActorOfflineNavigation final {
public:
    explicit ActorOfflineNavigation(gameplay_update::Owner&)noexcept;
    bool bound_to(const gameplay_world::World&,const Interpreter&)const noexcept;
    bool busy()const noexcept;
    bool command_ready(std::uint32_t selector,std::uint32_t room,std::uint32_t node)const noexcept;
    OfflineNavigationStatus command(std::uint32_t selector,std::uint32_t room,std::uint32_t node)noexcept;
    OfflineNavigationStatus bind_scene(SceneControls*,SceneModels*,SceneMatrixPrograms*,
        std::shared_ptr<const gameplay_collision::response::Grid>,const SceneControls* expected_current=nullptr)noexcept;
    OfflineNavigationStatus bind_resource_operations(gameplay_world::ActorResourceOperations*,
        gameplay_world::ActorResourceOperations* expected_current=nullptr,gameplay_world::ActorForcedTerminal* terminal=nullptr)noexcept;
    OfflineNavigationStatus close()noexcept;
private:
    OfflineNavigationStatus bind_roster_resources(gameplay_world::ActorResourceOperations*,
        gameplay_world::ActorResourceOperations* expected_current=nullptr,gameplay_world::ActorForcedTerminal* terminal=nullptr)noexcept;
    OfflineNavigationStatus prepare_actor(gameplay_world::Actor&,std::uint32_t mode)noexcept;
    OfflineNavigationStatus reconstruct_actor(gameplay_world::Actor&)noexcept;
    OfflineNavigationStatus reset_actor_scripts(const gameplay_world::Actor&)noexcept;
    OfflineNavigationStatus enter_scene_actor(gameplay_world::Actor&)noexcept;
    OfflineNavigationStatus enter_route(gameplay_world::Actor&,std::uint32_t inherited_kind,std::int32_t& selected_room)noexcept;
    gameplay_update::Owner& update_;gameplay_world::World& world_;Interpreter& scripts_;
    SceneControls* controls_{};SceneModels* models_{};SceneMatrixPrograms* matrices_{};
    std::shared_ptr<const gameplay_collision::response::Grid> floors_;
    gameplay_world::ActorResourceOperations* operations_{};gameplay_world::ActorForcedTerminal* terminal_{};
    bool running_{},closed_{};
    friend class gameplay_application::SessionResources;
};
}
