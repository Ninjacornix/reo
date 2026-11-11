#pragma once
#include "model_constraints.hpp"
namespace reo::native::gameplay_world {
enum class LinkedStatus { completed, full, no_memory, world_unavailable, busy, closed };
struct LinkedCreated {
    LinkedStatus status{LinkedStatus::world_unavailable};
    actors::EntityId id;
};
// Actual50-node6BA260/6BA300 allocation/list domain. The World owns Actor storage;
// this owner keeps physical-slot budget and source-order identities only.
class LinkedModelPool final {
  public:
    static constexpr std::size_t capacity = 50;
    ~LinkedModelPool();
    LinkedModelPool(const LinkedModelPool&) = delete;
    LinkedModelPool& operator=(const LinkedModelPool&) = delete;
    LinkedCreated allocate(bool insert_head);
    LinkedStatus reset() noexcept;
    LinkedStatus close() noexcept;
    bool busy() const noexcept {
        return resetting_ || updating_;
    }
    std::size_t remaining() const noexcept {
        return remaining_;
    }
    actors::EntityId head() const noexcept;
    actors::EntityId tail() const noexcept;
    std::optional<std::uint8_t> physical_slot(const actors::EntityId&) const noexcept;
    actors::EntityId identity_at(std::size_t slot)const noexcept{return slot<slots_.size()?slots_[slot].id:actors::EntityId{};}
    actors::EntityId previous(const actors::EntityId&) const;
    std::shared_ptr<Actor> resolve(const actors::EntityId&) const;

  private:
    friend class World;
    explicit LinkedModelPool(World& world) noexcept : world_(world) {}
    struct Slot {
        actors::EntityId id;
        std::optional<std::uint8_t> previous, next;
    };
    World& world_;
    std::array<Slot, capacity> slots_;
    std::optional<std::uint8_t> head_, tail_;
    std::size_t remaining_{capacity};
    bool closed_{}, resetting_{}, updating_{};
    LinkedStatus clear(bool close) noexcept;
    friend class LinkedModelPass;
};
class LinkedPoseRoot final {
  public:
    explicit LinkedPoseRoot(World& world) noexcept : world_(world) {}
    void select(actors::EntityId); // null is the source's known absent root.
    const actors::EntityId& selected() const noexcept {
        return selected_;
    }
    const actors::EntityId& observed() const noexcept {
        return observed_;
    }
    bool copy_joint17(Actor& dependent);

  private:
    World& world_;
    actors::EntityId selected_, observed_;
    friend class LinkedModelPass;
};
struct LinkedModelDefinition {
    std::uint8_t model{},texture{},sound{};
    float scale{};
    std::int8_t visibility_selector{};
    std::uint8_t construction_mode{};
    std::int8_t shadow_enabled{};
    std::int16_t shadow_asset{};
};
enum class ModelDefinitionBank { ordinary, alternate };
class File1LinkedModelProfiles final {
  public:
    bool skip_type1_correction(std::uint16_t variant) const;
    const LinkedModelDefinition& definition(std::uint8_t type,std::uint16_t variant,
        ModelDefinitionBank bank = ModelDefinitionBank::ordinary) const;
};
struct LinkedModelReport {
    std::size_t visited{}, updated{}, root_copies{}, floor_queries{};
};
class LinkedModelPass final {
  public:
    LinkedModelPass(World& world, LinkedModelPool& pool, LinkedPoseRoot& root,
                    const ModelCorrectionScales& scales,
                    const gameplay_collision::response::Grid* floors = nullptr)
        : world_(world), pool_(pool), root_(root), scales_(scales), floors_(floors) {}
    LinkedModelReport run();

  private:
    World& world_;
    LinkedModelPool& pool_;
    LinkedPoseRoot& root_;
    const ModelCorrectionScales& scales_;
    const gameplay_collision::response::Grid* floors_;
    File1LinkedModelProfiles profiles_;
};
} // namespace reo::native::gameplay_world
