#pragma once
#include <cstdint>
#include <memory>
#include <cstddef>
#include <limits>
#include <vector>

namespace reo::native::gameplay_actors {
struct EntityDomain;
class EntityStore;

// An owned native identity, never an encoded guest address. A shared immutable
// domain token prevents an ID from a retired world matching a new world.
class EntityId final {
public:
    EntityId() = default;
    explicit operator bool() const noexcept { return bool(domain_); }
    friend bool operator==(const EntityId&, const EntityId&) = default;
private:
    std::shared_ptr<const EntityDomain> domain_;
    std::uint64_t generation_{};
    std::uint32_t slot_{};
    friend class EntityStore;
};

// Concrete actor families supply typed gameplay components. The owner never
// allocates a guest-layout byte record or stores an original function pointer.
struct Entity {
    virtual ~Entity()=default;
};
enum class EntityStatus { completed,invalid,foreign_or_stale,full,no_memory,closed };
struct EntityCreated { EntityStatus status{EntityStatus::invalid};EntityId id; };
struct EntityConfig {
    std::uint32_t capacity{1024};
    std::uint64_t max_generation{std::numeric_limits<std::uint64_t>::max()};
};
// Simulation-owner thread only. Strong invocation leases keep an actor alive
// while a callback retires it; future lookup rejects the retired identity.
class EntityStore final {
public:
    explicit EntityStore(EntityConfig={});
    ~EntityStore();
    EntityStore(const EntityStore&)=delete;
    EntityStore& operator=(const EntityStore&)=delete;
    EntityCreated create(std::unique_ptr<Entity>) noexcept;
    std::shared_ptr<Entity> acquire(const EntityId&)const noexcept;
    EntityStatus retire(const EntityId&) noexcept;
    std::vector<EntityId> identities()const;
    std::size_t size()const noexcept{return size_;}
    void shutdown() noexcept;
private:
    struct Slot {std::shared_ptr<Entity> entity;std::uint64_t generation{};};
    std::shared_ptr<const EntityDomain> domain_;
    std::vector<Slot> slots_;
    std::uint64_t maximum_generation_;
    std::size_t size_{};
    bool closed_{};
    bool matches(const EntityId&)const noexcept;
};
} // namespace reo::native::gameplay_actors
