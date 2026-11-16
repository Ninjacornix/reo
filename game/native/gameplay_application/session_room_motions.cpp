#include "session_room_motions.hpp"
#include "native_session.hpp"
#include <cstring>
#include <stdexcept>
namespace reo::native::gameplay_application {
SessionRoomMotions::SessionRoomMotions(NativeSession& session,const gameplay_world::HumanoidMotionAssets& assets,
    gameplay_world::HumanoidMotionOwner& motions):session_(session),assets_(assets),motions_(motions){
    if(!session_.open()||!motions_.bound_to(session_.world()))throw std::invalid_argument("Native room motion owners unavailable");
}
RoomMotionStatus SessionRoomMotions::load_scenario_auxiliary()noexcept{
    if(!session_.open())return RoomMotionStatus::closed;
    auto& world=session_.world();
    // Private exact-site5EB350 capability: its outer model owner holds World.
    if(running_||!world.updating_)return RoomMotionStatus::busy;
    if(!world.scenario||!motions_.snapshot())return RoomMotionStatus::unavailable;
    running_=true;struct Reset{bool& value;~Reset(){value=false;}}reset{running_};
    try{
        const auto loaded=assets_.scenario_auxiliary(std::uint8_t(*world.scenario),*motions_.snapshot());
        const auto result=motions_.publish_nested(loaded,true);
        return result.status==gameplay_world::HumanoidPublicationStatus::completed?RoomMotionStatus::completed:
            result.status==gameplay_world::HumanoidPublicationStatus::no_memory?RoomMotionStatus::no_memory:RoomMotionStatus::unavailable;
    }catch(const std::bad_alloc&){return RoomMotionStatus::no_memory;}
    catch(...){return RoomMotionStatus::unavailable;}
}
bool SessionRoomMotions::bind_table(const gameplay_scenario::content::ScriptBank& bank)noexcept{
    using namespace gameplay_scenario::content;
    if(!session_.open()||running_||bank.format()!=BankFormat::scenario_evb)return false;
    try{
        const auto object=bank.object(8);if(!object)return false;
        const auto bytes=bank.view(*object);auto next=rows_;
        for(std::size_t offset=0;offset+2<=bytes.size();offset+=2){
            std::uint16_t value;std::memcpy(&value,bytes.data()+offset,2);
            if(value==255){rows_=next;return true;}
            if(offset/2>=next.size())return false;
            next[offset/2]=value;
        }
    }catch(...){}
    return false;
}
RoomMotionResult SessionRoomMotions::load()noexcept{
    if(!session_.open())return{RoomMotionStatus::closed};
    if(running_||session_.busy())return{RoomMotionStatus::busy};
    auto& world=session_.world();const auto desired=room_selector(world.room);
    if(!selected_||!desired||!motions_.snapshot())return{};
    if(*selected_==*desired)return{load_failed_?RoomMotionStatus::unavailable:RoomMotionStatus::completed,false,false,selected_};
    running_=world.updating_=true;
    struct Guard{bool& local;bool& world;~Guard(){world=false;local=false;}}guard{running_,world.updating_};
    RoomMotionResult result;result.selector=selected_;
    try{
        if(*selected_){
            const auto released=assets_.release_overlay(*motions_.snapshot());
            if(motions_.publish_nested(released,true).status!=gameplay_world::HumanoidPublicationStatus::completed)return result;
            result.released=true;
        }
        // Source publishes the desired selector before file reads. A failed
        //native load remains failed on equal-selector calls until reset/change.
        selected_=desired;result.selector=selected_;load_failed_=true;
        const auto common=assets_.overlay(*desired,{},*motions_.snapshot());
        if(motions_.publish_nested(common,true).status!=gameplay_world::HumanoidPublicationStatus::completed)return result;
        for(std::size_t slot=0;slot<gameplay_world::World::primary_capacity;++slot){
            const auto actor=world.primary(slot);if(!actor)return result;
            if(!actor->active)continue;
            const auto loaded=assets_.overlay_character(actor->character,*motions_.snapshot());
            if(motions_.publish_nested(loaded,true).status!=gameplay_world::HumanoidPublicationStatus::completed)return result;
        }
        load_failed_=false;result.loaded=true;result.status=RoomMotionStatus::completed;return result;
    }catch(const std::bad_alloc&){result.status=RoomMotionStatus::no_memory;return result;}
    catch(...){return result;}
}
}
