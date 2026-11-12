#pragma once
#include "pose_parent_flight.hpp"
#include "pose_timed_projectile.hpp"
#include "packed_actor_audio.hpp"
#include "actor_offset_sound_policy.hpp"
namespace reo::native::gameplay_world {
class CanonicalActorSoundOffsets final:public ActorSoundOffsets {
public:
    explicit CanonicalActorSoundOffsets(World& world):world_(world){}
    bool bound_to(const World&)const noexcept override;
    std::optional<std::uint8_t> find(const actors::EntityId&)override;
private:World& world_;
};
class CanonicalProjectileParentVariant final:public ProjectileParentVariant {
public:
    explicit CanonicalProjectileParentVariant(World& world):world_(world){}
    bool bound_to(const World&)const noexcept override;
    std::optional<std::uint8_t> read(const actors::EntityId&)override;
private:World& world_;
};
class CanonicalActorOffsetSound final:public ActorOffsetSound {
public:
    CanonicalActorOffsetSound(World&,gameplay_audio::Owner&,const gameplay_audio::SpatialContext&);
    bool bound_to(const World&)const noexcept override;
    bool sound(const actors::EntityId&,std::uint8_t event)override;
    const std::optional<gameplay_audio::Result>& last_result()const noexcept{return last_;}
private:
    World& world_;gameplay_audio::Owner& audio_;const gameplay_audio::SpatialContext& spatial_;
    std::optional<gameplay_audio::Result> last_;
};
}
