#pragma once
#include "native_session.hpp"
#include "session_room_motions.hpp"
#include "startup_texture_registry.hpp"
#include "session_scenario_resources.hpp"
#include "../gameplay_world/primary_actor_records.hpp"
#include "../gameplay_world/primary_roster_startup.hpp"
namespace reo::native::gameplay_scenario {class ActorVoiceSelections;}
namespace reo::native::gameplay_presentation {class BackgroundState;class FrontendDisplay;class GraphicsState;}
namespace reo::native::gameplay_effects {class Geometry;class EffectBank;}
namespace reo::native::gameplay_weapon_resources {class Catalogue;}
namespace reo::native::gameplay_application {
class SessionInput;
class SessionAudio;
// Asset/model startup capabilities for one existing canonical application.
// NativeSession must outlive this owner. The supplied bank publication comes
// from its actual producer; cold1B2150 does not establish the default-load gate.
class SessionStartup final {
public:
    SessionStartup(NativeSession&,std::shared_ptr<const reo::assets::Source>,
                   std::shared_ptr<const gameplay_world::HumanoidMotionBanks>);
    ~SessionStartup();
    SessionStartup(const SessionStartup&)=delete;
    SessionStartup& operator=(const SessionStartup&)=delete;
    gameplay_world::PrimaryRecordsInitialized initialize_records()noexcept;
    gameplay_world::PrimaryStartupReport start(gameplay_world::PrimaryStartupEffects*,
        const gameplay_world::PrimaryEquipmentContext* =nullptr)noexcept;
    gameplay_world::PrimaryStartupStatus close()noexcept;
    RoomMotionResult load_room_motions()noexcept;
    const SessionRoomMotions& room_motions()const noexcept{return room_motions_;}
    const StartupTextureRegistry& startup_textures()const noexcept{return textures_;}
    SessionScenarioResources& scenario_resources()noexcept{return scenario_resources_;}
    const SessionScenarioResources& scenario_resources()const noexcept{return scenario_resources_;}
    bool busy()const noexcept{return running_||scenario_resources_.busy();}
    std::optional<std::int8_t> roster_kind(std::uint8_t row)const noexcept;
    std::optional<float> reference_height(std::uint8_t character)const noexcept;
    const std::shared_ptr<const gameplay_effects::Geometry>& scenario_effect_geometry()const noexcept{return effect_geometry_;}
    const std::shared_ptr<const gameplay_effects::EffectBank>& scenario_effect_bank()const noexcept{return effect_bank_;}
    const std::shared_ptr<const gameplay_world::ResourceStaticAssets>& scenario_object_models()const noexcept{return object_models_;}
    bool open()const noexcept{return !closed_&&session_.open();}
    bool bound_to(const NativeSession& value)const noexcept{return &value==&session_;}
    const gameplay_world::ActorAssets& actor_assets()const noexcept{return actors_;}
    const gameplay_world::HumanoidMotionAssets& motion_assets()const noexcept{return motion_assets_;}
    gameplay_world::HumanoidMotionOwner& motion_owner()noexcept{return motion_owner_;}
    gameplay_world::PrimaryActorModels& actor_models()noexcept{return models_;}
    const std::optional<gameplay_world::PrimaryStartupReport>& last_result()const noexcept{return last_;}
private:
    friend class OfflineApplication;
    friend class SessionStartupEffects;
    //5FE3C0 ->5EADD0 clears4BADD0..+D0, including the four4BADF0
    // selection kinds. Only the fresh application adopts this subproducer.
    gameplay_world::PrimaryStartupStatus adopt_cold_roster_kinds()noexcept;
    gameplay_world::PrimaryStartupStatus adopt_cold_reference_heights()noexcept;
    bool bind_graphics(gameplay_presentation::GraphicsState*)noexcept;
    bool bind_audio(SessionAudio*)noexcept;
    gameplay_world::PrimaryStartupStatus load_scenario_effects()noexcept;
    gameplay_world::PrimaryStartupStatus load_scenario_objects()noexcept;
    gameplay_world::PrimaryStartupStatus load_actor_resources(gameplay_world::PrimaryStartupWork,const gameplay_world::actors::EntityId&)noexcept;
    void bind_input(SessionInput* input) noexcept { input_=input; }
    void bind_voices(std::shared_ptr<gameplay_scenario::ActorVoiceSelections> voices)noexcept{voices_=std::move(voices);}
    void bind_background(gameplay_presentation::BackgroundState* background)noexcept{background_=background;}
    // The application lends its actual frontend producer and live display.
    // Both null releases the borrow; a different live owner cannot replace it.
    StartupTextureStatus bind_frontend(std::shared_ptr<const gameplay_presentation::CommonFrontendTextures>,
        gameplay_presentation::FrontendDisplay*)noexcept;
    NativeSession& session_;
    std::shared_ptr<const reo::assets::Source> source_;
    gameplay_world::ActorAssets actors_;
    gameplay_world::HumanoidMotionAssets motion_assets_;
    gameplay_world::HumanoidMotionOwner motion_owner_;
    gameplay_world::PrimaryActorModels models_;
    SessionRoomMotions room_motions_;
    StartupTextureRegistry textures_;
    SessionScenarioResources scenario_resources_;
    SessionInput* input_{};
    std::shared_ptr<gameplay_scenario::ActorVoiceSelections> voices_;
    gameplay_presentation::BackgroundState* background_{};
    gameplay_presentation::FrontendDisplay* loading_display_{};
    std::optional<std::array<std::int8_t,4>> roster_kinds_;
    //747400 is fresh-process ELF BSS, outside the file-backed o2 overlay.
    // Generic startup and warm repeats do not synthesize or reset this bank.
    std::optional<std::array<float,8>> reference_heights_;
    gameplay_presentation::GraphicsState* graphics_{};
    SessionAudio* audio_{};
    gameplay_scenario::content::Bytes effect_model_bytes_,effect_data_bytes_;
    std::shared_ptr<const gameplay_effects::Geometry> effect_geometry_;
    std::shared_ptr<const gameplay_effects::EffectBank> effect_bank_;
    std::shared_ptr<const gameplay_world::ResourceStaticAssets> object_models_;
    std::shared_ptr<const gameplay_weapon_resources::Catalogue> weapon_programs_;
    std::optional<gameplay_world::PrimaryStartupReport> last_;
    bool running_{},closed_{};
};
}
