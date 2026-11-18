#pragma once
#include "cutscene_actor_commands.hpp"
namespace reo::native::gameplay_scenario {
class CutscenePlayback;
enum class CutsceneActorSpeechStatus {completed,busy,closed,unavailable,no_memory};
struct CutsceneActorSpeechResult {CutsceneActorSpeechStatus status{CutsceneActorSpeechStatus::unavailable};bool voice_missing{};};
// Actual5EEC50 speech frontend for the pinned File1 sound catalogue. The fixed
//1AB2F0 lookup precedes any selected SDK archive/player state. Owned generated
// VO names genuinely miss that catalogue; an unexpected positive lookup refuses
// its unprovided media path. Facial claims use the sole playback-owned worker.
// The World and target controller outlive an unbound candidate. After binding,
// the controller owns this adapter; borrowed access expires at unbind/destruction.
class CutsceneActorSpeech final:public CutsceneSpeech {
public:
    CutsceneActorSpeech(gameplay_world::World&,CutscenePlayback&);
    ~CutsceneActorSpeech();
    CutsceneActorSpeech(const CutsceneActorSpeech&)=delete;
    CutsceneActorSpeech& operator=(const CutsceneActorSpeech&)=delete;
    bool bound_to(const gameplay_world::World&,const CutscenePlayback&)const noexcept;
    bool busy()const noexcept{return running_;}
    bool queue_voice(const CutsceneSpeechRequest&)override;
    bool animate_face(const CutsceneSpeechRequest&)override;
    const CutsceneActorSpeechResult& last_result()const noexcept{return last_;}
private:
    friend class CutscenePlayback;
    gameplay_world::World& world_;CutscenePlayback* playback_;
    CutsceneActorSpeechResult last_;bool running_{},bound_{};
    bool admit(const CutsceneSpeechRequest&);
};
} // namespace reo::native::gameplay_scenario
