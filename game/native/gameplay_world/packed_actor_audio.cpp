#include "packed_actor_audio.hpp"
#include <stdexcept>
namespace reo::native::gameplay_world {
PackedActorAudio::PackedActorAudio(World& world,gameplay_audio::Owner& audio,const gameplay_audio::SpatialContext& spatial,ActorSoundOffsets* offsets)
    :world_(world),audio_(audio),spatial_(spatial),offsets_(offsets){if(!bound_to(world))throw std::invalid_argument("Native packed sound owners unavailable");}
bool PackedActorAudio::bound_to(const World& world)const noexcept{return &world==&world_&&!world_.closed()&&audio_.bound_to(world_.session().random)&&(!offsets_||offsets_->bound_to(world));}
bool PackedActorAudio::class_sound(const actors::EntityId& id,Actor& actor,std::uint8_t event,bool randomize){
    if(!event||actor.category==1)return true;
    unsigned bank{},tag{};
    if(actor.category==0){bank=unsigned(actor.slot)+8;if(randomize)event=std::uint8_t(event+(world_.session().random.request(1)&1u));}
    else if(actor.category==2||actor.category==3){
        if(!offsets_)return false;
        const auto selected=offsets_->find(id);if(!selected)return false;
        if(world_.resolve(id).get()!=&actor)return false;
        bank=12;tag=*selected;
    }else return false; // Source reaches unassigned bank/owner registers here.
    last_=audio_.positional({bank,event,UINT32_MAX,UINT32_MAX,std::uint8_t(tag)},
        {actor.position.x,actor.position.y,actor.position.z},spatial_,1);
    return true;
}
bool PackedActorAudio::sound(const actors::EntityId& source,std::uint32_t packed){
    last_.reset();if(!bound_to(world_))return false;
    if(!source)return true;
    auto id=source;auto actor=world_.resolve(id);if(!actor)return false;
    if(actor->category==9){
        id=actor->contact.related;if(!id)return true;
        actor=world_.resolve(id);if(!actor)return false;
    }
    const auto byte=std::uint8_t(packed);
    if(actor->category!=0)return class_sound(id,*actor,std::uint8_t(byte&0x7f),bool(byte&0x80));
    if(byte&0x40){
        last_=audio_.positional({unsigned(actor->slot)+4u,unsigned(byte&0x3f)},
            {actor->position.x,actor->position.y,actor->position.z},spatial_,1);
        return true;
    }
    return class_sound(id,*actor,std::uint8_t(byte&0x3f),bool(byte&0x80));
}
}
