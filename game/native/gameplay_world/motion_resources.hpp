#pragma once
#include "world.hpp"
#include "../animation/playback.hpp"
namespace reo::native::gameplay_world {
enum class MotionRelation : std::size_t { auxiliary, first_linked, second_linked };
enum class MotionActorPool { primary, secondary, auxiliary };
struct MotionActorLocator {
    MotionActorPool pool{};
    std::uint8_t slot{};
};
struct MotionRelationBindings {
    std::optional<actors::EntityId> auxiliary;
    std::optional<MotionActorLocator> first_linked, second_linked;
};
// Native behavior-owned relation admission. Absence is explicit only after a
// complete binding; an unbound relation set is unavailable, never guessed null.
class MotionRelations final {
  public:
    explicit MotionRelations(World& world) : world_(world) {}
    bool bind(actors::EntityId, MotionRelationBindings);
    std::shared_ptr<Actor> resolve(const actors::EntityId&, MotionRelation) const;

  private:
    struct Entry {
        actors::EntityId owner;
        MotionRelationBindings targets;
    };
    World& world_;
    std::vector<Entry> entries_;
};
class WorldMotionResources final {
  public:
    explicit WorldMotionResources(World& world, const MotionRelations* relations = nullptr)
        : world_(world), relations_(relations) {}
    std::shared_ptr<const animation::MotionBank> resolve(const actors::EntityId&,
                                                         std::uint32_t selector);

  private:
    World& world_;
    const MotionRelations* relations_{};
    std::shared_ptr<Actor> related(const actors::EntityId&, std::uint8_t selector) const;
};
} // namespace reo::native::gameplay_world
