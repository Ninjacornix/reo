#pragma once
#include "world.hpp"
namespace reo::native::gameplay_world {
enum class AuxiliaryStatus {completed,full,no_memory,world_unavailable,invalid_identity,busy,closed};
struct AuxiliaryCreated {AuxiliaryStatus status{AuxiliaryStatus::world_unavailable};actors::EntityId id;};
struct AuxiliaryAttachment {AuxiliaryStatus status{AuxiliaryStatus::world_unavailable};std::optional<std::uint8_t> slot;};
// The distinct ten-actor682C60/682D10/682E30 domain. Actor storage belongs to
// World; this owner retains capacity, list order and free-slot reuse metadata.
class AuxiliaryActorPool final {
public:
    static constexpr unsigned capacity=10;
    ~AuxiliaryActorPool();
    AuxiliaryActorPool(const AuxiliaryActorPool&)=delete;
    AuxiliaryActorPool& operator=(const AuxiliaryActorPool&)=delete;
    AuxiliaryCreated allocate(std::uint32_t insert_at_tail=0);
    AuxiliaryStatus release(const actors::EntityId&)noexcept;
    AuxiliaryStatus reset()noexcept;
    AuxiliaryStatus close()noexcept;
    bool busy()const noexcept{return mutating_||updating_;}
    unsigned remaining()const noexcept{return remaining_;}
    actors::EntityId head()const noexcept;
    actors::EntityId tail()const noexcept;
    actors::EntityId next(const actors::EntityId&)const noexcept;
    actors::EntityId previous(const actors::EntityId&)const noexcept;
    std::optional<std::uint8_t> physical_slot(const actors::EntityId&)const noexcept;
    actors::EntityId identity_at(std::size_t slot)const noexcept{return slot<slots_.size()?slots_[slot].id:actors::EntityId{};}
    actors::EntityId find(std::uint32_t identifier,bool active_only=false)const noexcept;
    AuxiliaryAttachment claim_attachment()noexcept;
    std::array<bool,4> attachment_flags()const noexcept{return attachments_;}
private:
    friend class World;
    friend class NpcActorConstruction;
    friend class NpcActorUpdates;
    friend class CinematicActorFrames;
    explicit AuxiliaryActorPool(World&)noexcept;
    struct Slot {actors::EntityId id;std::optional<std::uint8_t> previous,next;std::uint8_t byte_on_reuse{};};
    World& world_;
    std::array<Slot,capacity> slots_;
    std::array<std::uint8_t,capacity> free_{};
    std::array<bool,4> attachments_{};
    unsigned remaining_{capacity};
    std::optional<std::uint8_t> head_,tail_;
    bool closed_{},mutating_{},updating_{};
    AuxiliaryStatus clear(bool seal)noexcept;
};
}
