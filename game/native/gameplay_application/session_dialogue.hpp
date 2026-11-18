#pragma once
#include "native_session.hpp"
#include "../gameplay_world/dialogue_pool.hpp"
#include "../gameplay_world/dialogue_room_banks.hpp"
#include "../gameplay_world/inventory_dialogue_presentation.hpp"
#include "../gameplay_update/dialogue_workers.hpp"
namespace reo::native::gameplay_application {
// Dialogue lifetime for one existing application. The application, voice owner,
// remaining frame services and menu inputs must outlive this borrowed owner.
// Construction neither invents input/UI gates nor executes the unported whole
//5EB6D0 finish path. Its real1D41F0 child is an explicit entry below.
class SessionDialogue final {
public:
    SessionDialogue(NativeSession&,gameplay_world::ActorVoiceRequests&,
        gameplay_update::PhaseServices&,const gameplay_world::input::Frame*,
        const std::optional<std::uint32_t>& menu_actions);
    ~SessionDialogue();
    SessionDialogue(const SessionDialogue&)=delete;
    SessionDialogue& operator=(const SessionDialogue&)=delete;
    bool bound_to(const NativeSession&)const noexcept;
    bool open()const noexcept;
    gameplay_world::DialogueStatus cold_clear()noexcept; //6B7610
    gameplay_world::DialogueStatus clear_text_cache()noexcept; //1B4A60
    gameplay_world::DialogueBanksRefreshed finish_banks(const gameplay_scenario::content::ScriptBank&)noexcept; //1D41F0 at5EB720
    FrameStep advance(gameplay_world::Services*,std::size_t script_budget=4096,std::size_t task_budget=1024);
    gameplay_world::DialogueStatus close()noexcept;
    const gameplay_world::DialoguePool& pool()const noexcept{return pool_;}
    const gameplay_scenario::TextCache& text_cache()const noexcept{return cache_;}
    const std::optional<gameplay_world::DialogueResponsesUpdated>& last_response()const noexcept{return last_;}
private:
    NativeSession& session_;
    gameplay_update::PhaseServices& remaining_;
    const gameplay_world::input::Frame* menu_;
    const std::optional<std::uint32_t>& actions_;
    gameplay_scenario::TextCache& cache_;
    gameplay_world::InventoryDialoguePresentation presentation_;
    gameplay_world::DialoguePool pool_;
    std::optional<gameplay_world::DialogueResponsesUpdated> last_;
    bool running_{},closed_{};
    bool busy()const noexcept;
};
}
