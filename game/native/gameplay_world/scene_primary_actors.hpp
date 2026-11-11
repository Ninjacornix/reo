#pragma once
#include "world.hpp"
namespace reo::native::gameplay_world {
enum class ScenePrimaryStatus {completed,full,uninitialized,invalid_identity,model_in_use,entity_capacity,no_memory,busy,closed};
struct ScenePrimaryFound {
    ScenePrimaryStatus status{ScenePrimaryStatus::uninitialized};
    std::optional<std::uint8_t> slot{};actors::EntityId id{};
};
// Distinct eight-actor5F1290/5F1330 domain, with actual Actor storage in World.
// It never replaces the ordinary World::primary roster. Scene cloning/model
// ownership and the separate sixteen category10 objects are other consumers.
class ScenePrimaryActorPool final {
public:
    static constexpr unsigned capacity=8;
    ~ScenePrimaryActorPool();
    ScenePrimaryActorPool(const ScenePrimaryActorPool&)=delete;
    ScenePrimaryActorPool& operator=(const ScenePrimaryActorPool&)=delete;
    ScenePrimaryStatus initialize()noexcept;
    // Finds but does NOT activate/reserve the record, matching5F1330.
    ScenePrimaryFound find_inactive()noexcept;
    actors::EntityId identity_at(std::size_t)const noexcept;
    std::optional<std::uint8_t> physical_slot(const actors::EntityId&)const noexcept;
    bool initialized()const noexcept{return initialized_&&!closed_&&!world_.closed();}
    bool busy()const noexcept{return mutating_;}
    ScenePrimaryStatus close()noexcept;
private:
    friend class World;
    explicit ScenePrimaryActorPool(World& world)noexcept:world_(world){}
    World& world_;std::array<actors::EntityId,capacity> slots_{};
    bool initialized_{},closed_{},mutating_{};
};
}
