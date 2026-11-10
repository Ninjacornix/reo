#pragma once
#include "../gameplay_world/world.hpp"
namespace reo::native::gameplay_update {
enum class MessageRoute {mode_zero,mode_one};
enum class PublicationStatus {completed,unavailable,message_unavailable};
struct RoomClaimReleaseMessage {
    MessageRoute route{};std::uint8_t sender{},room{};
    static constexpr unsigned channel=7,type=4,length=8,control=4,operation=1;
};
class RoomClaimSink {
public:
    virtual ~RoomClaimSink()=default;
    virtual bool send(const RoomClaimReleaseMessage&)noexcept{return false;}
};
//1B0010 with811B30/811300's actual a2==0 request branch. Actor message
// phase/pause/status gates do not apply to this control-channel publication.
inline PublicationStatus publish_actor_room_release(gameplay_world::World& world,std::uint32_t slot,RoomClaimSink* sink)noexcept{
    if(world.closed())return PublicationStatus::unavailable;
    if(world.mode==0){if(slot!=0)return PublicationStatus::completed;}
    else if(world.mode==1){if(slot>=4)return PublicationStatus::completed;}
    else return PublicationStatus::completed;
    const auto actor=world.primary(slot);if(!actor)return PublicationStatus::unavailable;
    if(actor->room>=128||slot!=world.selected_actor)return PublicationStatus::completed;
    return sink&&sink->send(RoomClaimReleaseMessage{world.mode==0?MessageRoute::mode_zero:MessageRoute::mode_one,world.selected_actor,std::uint8_t(actor->room)})?PublicationStatus::completed:PublicationStatus::message_unavailable;
}
}
