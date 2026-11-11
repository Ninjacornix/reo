#pragma once
#include "primary_actor_initialization.hpp"
namespace reo::native::gameplay_world {
// Only the enclosing model owner may enter with an already-held World guard.
// Ordinary callers keep the public busy/refusal contract.
class PrimaryActorInitialization final {
    friend class PrimaryActorModels;
    friend PrimaryInitializationStatus initialize_primary_defaults(World&,actors::EntityId,std::uint8_t,const HumanoidMotionBanks&)noexcept;
    friend PrimaryInitializationStatus initialize_primary_slot(World&,actors::EntityId,std::uint8_t,const HumanoidMotionBanks&,const PrimaryEquipmentContext*)noexcept;
    friend PrimaryInitializationStatus restore_primary_slot(World&,actors::EntityId)noexcept;
    friend PrimaryInitializationStatus initialize_primary_actor(World&,const gameplay_update::State&,actors::EntityId,std::uint8_t,const HumanoidMotionBanks&,const PrimaryEquipmentContext*)noexcept;
    static PrimaryInitializationStatus defaults(World&,actors::EntityId,std::uint8_t,const HumanoidMotionBanks&,bool custom=false,const PrimaryEquipmentContext* = nullptr,bool nested=false)noexcept;
    static PrimaryInitializationStatus restore(World&,actors::EntityId,bool nested=false)noexcept;
    static PrimaryInitializationStatus select(World&,const gameplay_update::State&,actors::EntityId,std::uint8_t,const HumanoidMotionBanks&,const PrimaryEquipmentContext*,bool nested=false)noexcept;
};
}
