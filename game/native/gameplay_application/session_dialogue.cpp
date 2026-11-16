#include "session_dialogue.hpp"
#include "session_resources.hpp"
#include <exception>
#include <stdexcept>
namespace reo::native::gameplay_application {
namespace {
NativeSession& admitted(NativeSession& session,gameplay_world::ActorVoiceRequests& voice){
    if(!session.open()||session.world().busy()||session.update().busy()||!voice.bound_to(session.world()))
        throw std::invalid_argument("Canonical session dialogue capabilities are closed, busy or foreign");
    return session;
}
}
SessionDialogue::SessionDialogue(NativeSession& session,gameplay_world::ActorVoiceRequests& voice,
    gameplay_update::PhaseServices& remaining,const gameplay_world::input::Frame* menu,const std::optional<std::uint32_t>& actions):
    session_(admitted(session,voice)),remaining_(remaining),menu_(menu),actions_(actions),cache_(session.text_cache()),
    presentation_(session.world(),cache_,session.inventory_ui()),pool_(session.world(),&voice,&presentation_){}
SessionDialogue::~SessionDialogue(){if(busy())std::terminate();}
bool SessionDialogue::bound_to(const NativeSession& session)const noexcept{return &session==&session_&&open();}
bool SessionDialogue::open()const noexcept{return !closed_&&session_.open();}
bool SessionDialogue::busy()const noexcept{return running_||session_.world().busy()||session_.update().busy();}
gameplay_world::DialogueStatus SessionDialogue::cold_clear()noexcept{
    if(!open())return gameplay_world::DialogueStatus::closed;
    if(busy())return gameplay_world::DialogueStatus::busy;
    return pool_.initialize_owned_state();
}
gameplay_world::DialogueStatus SessionDialogue::clear_text_cache()noexcept{
    if(!open())return gameplay_world::DialogueStatus::closed;
    if(busy())return gameplay_world::DialogueStatus::busy;
    cache_.reset();return gameplay_world::DialogueStatus::completed;
}
gameplay_world::DialogueBanksRefreshed SessionDialogue::finish_banks(const gameplay_scenario::content::ScriptBank& bank)noexcept{
    gameplay_world::DialogueBanksRefreshed report;
    if(!open()){report.status=gameplay_world::DialogueStatus::closed;return report;}
    if(busy()){report.status=gameplay_world::DialogueStatus::busy;return report;}
    running_=true;struct Reset{bool& value;~Reset(){value=false;}}reset{running_};
    return pool_.refresh_room_banks(session_.archive(),bank);
}
FrameStep SessionDialogue::advance(gameplay_world::Services* actors,std::size_t script_budget,std::size_t task_budget){
    if(!open())return{SessionStatus::closed,{}};
    if(busy())return{SessionStatus::busy,{}};
    running_=true;struct Reset{bool& value;~Reset(){value=false;}}reset{running_};
    auto resources=session_.resources();if(resources&&!resources->initialized())resources=nullptr;
    gameplay_update::DialogueWorkers workers(session_.update(),remaining_,pool_,session_.inventory_ui(),menu_,actions_,
        resources?&resources->descriptors():nullptr,resources?&resources->templates():nullptr);
    try{auto result=session_.advance(&workers,actors,script_budget,task_budget);last_=workers.last_result();return result;}
    catch(...){last_=workers.last_result();throw;}
}
gameplay_world::DialogueStatus SessionDialogue::close()noexcept{
    if(busy())return gameplay_world::DialogueStatus::busy;
    closed_=true;last_.reset();return gameplay_world::DialogueStatus::completed;
}
}
