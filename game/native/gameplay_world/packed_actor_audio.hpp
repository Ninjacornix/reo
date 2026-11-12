#pragma once
#include "world.hpp"
#include "../gameplay_audio/owner.hpp"
namespace reo::native::gameplay_world {
class ActorSoundOffsets {
public:
    virtual ~ActorSoundOffsets()=default;
    virtual bool bound_to(const World&)const noexcept=0;
    // Actual class2/3 source33 producer. Unknown is not a zero program tag.
    virtual std::optional<std::uint8_t> find(const actors::EntityId&)=0;
};
// Complete1BA5E0/1BA4C0 with admitted1B91E0 class routing, using the actual
// canonical bank owner/RNG. Outcomes are retained even when a bank ignores it.
class PackedActorAudio final {
public:
    PackedActorAudio(World&,gameplay_audio::Owner&,const gameplay_audio::SpatialContext&,ActorSoundOffsets* =nullptr);
    bool bound_to(const World&)const noexcept;
    bool sound(const actors::EntityId&,std::uint32_t packed);
    const std::optional<gameplay_audio::Result>& last_result()const noexcept{return last_;}
private:
    World& world_;gameplay_audio::Owner& audio_;const gameplay_audio::SpatialContext& spatial_;
    ActorSoundOffsets* offsets_;std::optional<gameplay_audio::Result> last_;
    bool class_sound(const actors::EntityId&,Actor&,std::uint8_t,bool randomize);
};
}
