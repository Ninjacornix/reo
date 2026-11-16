#include "session_room_transport.hpp"
#include <stdexcept>
namespace reo::native::gameplay_application {
SessionRoomTransport::SessionRoomTransport(NativeSession& session):session_(session){
    if(!session.open()||session.busy()||session.world().mode!=0)
        throw std::invalid_argument("Offline room transport requires the idle canonical offline session");
}
SessionRoomTransport::~SessionRoomTransport(){if(close()==RoomTransportStatus::busy)std::terminate();}
bool SessionRoomTransport::ready(gameplay_update::MessageRoute route)const noexcept{
    return !closed_&&initialized_&&route==gameplay_update::MessageRoute::mode_zero&&
        session_.open()&&session_.world().mode==0&&session_.reception().room_membership_ready(route);
}
RoomTransportStatus SessionRoomTransport::initialize()noexcept{
    if(closed_||!session_.open())return RoomTransportStatus::closed;
    if(running_||session_.busy())return RoomTransportStatus::busy;
    if(initialized_||session_.world().mode!=0)return RoomTransportStatus::unavailable;
    //810080 owns these resets. Generic NativeSession construction does not.
    if(!session_.room_membership().initialize(0))return RoomTransportStatus::unavailable;
    session_.world().session().activity.single=0;
    requests_.clear();snapshots_.clear();scene_messages_.clear();frame_counter_=sent_bytes_=0;
    activation_tick_.reset();active_=false;initialized_=true;
    return RoomTransportStatus::completed;
}
RoomTransportStatus SessionRoomTransport::activate(std::uint32_t tick)noexcept{
    if(closed_||!session_.open())return RoomTransportStatus::closed;
    if(running_||session_.busy())return RoomTransportStatus::busy;
    if(!ready(gameplay_update::MessageRoute::mode_zero))return RoomTransportStatus::unavailable;
    if(active_)return RoomTransportStatus::completed;
    auto& world=session_.world();
    //810550 sets83E2D5, reads1AC630, sets3243FB, and selects83E2D7(0).
    // It does not clear room tables/queues; a retry preserves queued requests.
    world.session().activity.single=1;activation_tick_=tick;
    world.session().message_phase=2;world.selected_actor=0;active_=true;
    return RoomTransportStatus::completed;
}
bool SessionRoomTransport::begin_room_claim(const gameplay_update::RoomClaimBeginMessage& value)noexcept{
    if(!ready(value.route)||!requests_.push(Request{value}))return false;
    sent_bytes_+=16+value.length;return true;
}
bool SessionRoomTransport::send(const gameplay_update::RoomClaimReleaseMessage& value)noexcept{
    if(!ready(value.route)||!requests_.push(Request{value}))return false;
    sent_bytes_+=16+value.length;return true;
}
bool SessionRoomTransport::send(const gameplay_update::RoomMembershipMessage& value)noexcept{
    if(!ready(value.route)||value.update.count>value.update.rows.size()||!snapshots_.push(value))return false;
    sent_bytes_+=22+5*value.update.count;return true;
}
bool SessionRoomTransport::send(const gameplay_update::ScenarioOwnerMessage& value)noexcept{
    return send_scene(value,value.route,value.length);
}
bool SessionRoomTransport::send(const gameplay_update::SceneRecordParameterMessage& value)noexcept{
    return send_scene(value,value.route,value.length);
}
bool SessionRoomTransport::scene_record_parameters_ready()const noexcept{
    return ready(gameplay_update::MessageRoute::mode_zero);
}
bool SessionRoomTransport::send_scene(SceneValue value,gameplay_update::MessageRoute route,unsigned length)noexcept{
    if(!ready(route))return false;
    //811190 drops all channel5 traffic while inactive or before the first
    //810200 frame. Activation's display tick83E318 is NOT frame counter83E2D8.
    if(!active_||!frame_counter_)return true;
    //8112CC checks the preceding byte total, excluding this new payload.
    // Actor aggregate channels are not admitted by this transport yet.
    if(sent_bytes_>=512)return true;
    if(!scene_messages_.push({std::move(value),session_.world().selected_actor}))return false;
    sent_bytes_+=16+length;return true;
}
std::optional<std::uint32_t> SessionRoomTransport::room_owner(gameplay_update::MessageRoute route,std::uint16_t room)noexcept{
    return ready(route)?session_.reception().room_owner(route,room):std::nullopt;
}
RoomTransportStep SessionRoomTransport::pump()noexcept{
    using R=gameplay_update::ReceptionStatus;
    if(closed_||!session_.open())return{RoomTransportStatus::closed};
    if(running_||session_.busy())return{RoomTransportStatus::busy};
    if(!active_||!ready(gameplay_update::MessageRoute::mode_zero))return{RoomTransportStatus::unavailable};
    const auto setup=session_.world().session().setup_gate;
    if(!setup)return{RoomTransportStatus::unavailable};
    if(*setup)return{}; //810210..214: loading suspends all room stages.
    running_=true;struct Reset{bool& value;~Reset(){value=false;}}reset{running_};
    RoomTransportStep result;
    ++frame_counter_;sent_bytes_=0; //81049C..8104AC before queue processing
    if(!session_.reception().begin_room_membership_update())return{RoomTransportStatus::unavailable};
    //8104D8 priority receive first, then8104E0 requests. The publication made
    // below is queued for the NEXT pump, never an immediate authority echo.
    while(snapshots_.count){
        const auto value=snapshots_.pop();++result.snapshots;
        if(session_.reception().receive(value).status!=R::completed){result.status=RoomTransportStatus::unavailable;return result;}
    }
    //8107D0 drains normal channels in numeric order, so channel5 precedes7.
    while(scene_messages_.count){
        const auto message=scene_messages_.pop();++result.scene_messages;
        auto& world=session_.world();
        if(message.sender==world.selected_actor)continue;
        //4BAE76 is also the gameplay phase's transition gate. Use its existing
        //canonical owner so pause/transition writes immediately affect receipt.
        if(session_.update().state.transition_gate)continue;
        const auto phase=world.session().message_phase;if(phase!=1&&phase!=2)continue;
        if(const auto* parameter=std::get_if<gameplay_update::SceneRecordParameterMessage>(&message.value)){
            if(session_.reception().receive(*parameter).status!=R::completed){result.status=RoomTransportStatus::unavailable;return result;}
            continue;
        }
        auto& flags=session_.update().flags();const auto& value=std::get<gameplay_update::ScenarioOwnerMessage>(message.value);
        //67DD88..67DDC4: nonzero sets sender+1 before the scenario bit; clear
        // leaves the ownership tag untouched. Reception sends no notification.
        if(value.value&&!flags.scenario_owner(value.flag,std::uint8_t(message.sender+1))){result.status=RoomTransportStatus::unavailable;return result;}
        if(!flags.write(gameplay_scenario::FlagBank::scenario,value.flag,value.value!=0)){result.status=RoomTransportStatus::unavailable;return result;}
    }
    while(requests_.count){
        const auto value=requests_.pop();++result.requests;
        const auto received=std::visit([&](const auto& request){return session_.reception().receive(request);},value);
        if(received.status!=R::completed){result.status=RoomTransportStatus::unavailable;return result;}
    }
    const auto changes=session_.reception().collect_room_membership();
    if(changes.status!=gameplay_session::RoomMembershipStatus::completed){result.status=RoomTransportStatus::unavailable;return result;}
    if(changes.update){
        if(!send(gameplay_update::RoomMembershipMessage{gameplay_update::MessageRoute::mode_zero,*changes.update}))result.status=RoomTransportStatus::full;
        else ++result.published;
    }
    return result;
}
RoomTransportStatus SessionRoomTransport::close()noexcept{
    if(closed_)return RoomTransportStatus::completed;
    if(running_||session_.busy())return RoomTransportStatus::busy;
    requests_.clear();snapshots_.clear();scene_messages_.clear();active_=false;closed_=true;return RoomTransportStatus::completed;
}
}
