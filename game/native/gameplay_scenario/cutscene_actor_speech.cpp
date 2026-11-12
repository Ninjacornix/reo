#include "cutscene_actor_speech.hpp"
#include "cutscene_playback.hpp"
#include "facial_motions.hpp"
#include "../gameplay_bank_loading/aliases.hpp"
#include <bit>
#include <cstdio>
#include <stdexcept>
namespace reo::native::gameplay_scenario {
namespace {struct Reset {bool& value;~Reset(){value=false;}};}
CutsceneActorSpeech::CutsceneActorSpeech(gameplay_world::World& world,CutscenePlayback& playback):world_(world),playback_(&playback){
    if(world.closed()||world.cinematic_controller()!=&playback)throw std::invalid_argument("Native cinematic speech controller unavailable");
}
CutsceneActorSpeech::~CutsceneActorSpeech(){if(running_)std::terminate();}
bool CutsceneActorSpeech::bound_to(const gameplay_world::World& world,const CutscenePlayback& playback)const noexcept{return &world_==&world&&playback_==&playback;}
bool CutsceneActorSpeech::admit(const CutsceneSpeechRequest& request){
    last_={};
    if(running_){last_.status=CutsceneActorSpeechStatus::busy;return false;}
    if(world_.closed()){last_.status=CutsceneActorSpeechStatus::closed;return false;}
    if(!bound_||world_.cinematic_controller()!=playback_||!world_.scenario||*world_.scenario!=request.scenario)return false;
    const auto actor=world_.resolve(request.actor);if(!actor)return false;
    if(playback_->state().request.current.area!=request.scene)return false;
    const auto character=actor->category==0?std::bit_cast<std::int8_t>(std::uint8_t(actor->character+1u)):std::int8_t(0);
    return character==request.character;
}
bool CutsceneActorSpeech::queue_voice(const CutsceneSpeechRequest& request){
    if(!admit(request))return false;
    running_=true;Reset reset{running_};
    try{
        std::array<char,128> name{};
        const auto count=std::snprintf(name.data(),name.size(),"VO%03d%02d%02d_%01d.adx",int(request.scenario),int(request.scene),int(request.voice),int(request.character));
        if(count<0||std::size_t(count)>=name.size())return false;
        // This is the actual fixed1AB2F0 query. A selected nested VO archive
        // cannot replace its literal2337C0/count422 arguments.
        if(gameplay_bank_loading::sound_member(name.data()))return false;
        last_={CutsceneActorSpeechStatus::completed,true};return true;
    }catch(const std::bad_alloc&){last_.status=CutsceneActorSpeechStatus::no_memory;return false;}
}
bool CutsceneActorSpeech::animate_face(const CutsceneSpeechRequest& request){
    if(!admit(request))return false;
    running_=true;Reset reset{running_};
    auto* faces=playback_->facial_motions();if(!faces)return false;
    switch(faces->claim(request.actor,request.facial,request.scene,std::uint16_t(request.voice)).status){
    case FacialStatus::completed:last_.status=CutsceneActorSpeechStatus::completed;return true;
    case FacialStatus::busy:last_.status=CutsceneActorSpeechStatus::busy;break;
    case FacialStatus::closed:last_.status=CutsceneActorSpeechStatus::closed;break;
    case FacialStatus::no_memory:last_.status=CutsceneActorSpeechStatus::no_memory;break;
    default:break;
    }
    return false;
}
} // namespace reo::native::gameplay_scenario
