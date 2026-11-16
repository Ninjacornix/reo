#pragma once
#include "session_startup.hpp"
#include "session_resources.hpp"
#include "session_collision_frame.hpp"
#include "session_actor_services.hpp"
#include "session_input.hpp"
#include "session_audio.hpp"
#include "session_frontend.hpp"
#include "session_room_transport.hpp"
#include "../gameplay_presentation/session_presentation.hpp"
#include "../gameplay_presentation/windows_vblank.hpp"
#include "../gameplay_presentation/frontend_display.hpp"
#include "../gameplay_session/launch.hpp"
#include <string>
#include <vector>

namespace reo::native::gameplay_application {
// Actual host inputs; room, difficulty, asset key and motion publication must
// come from their producers. This type does not infer frontend choices.
struct OfflineLaunchInput {
    std::shared_ptr<const reo::assets::Source> source;
    gameplay_world::Profile profile;
    std::vector<std::byte> launch_record;
    gameplay_scenario::content::RoomId room;
    std::uint8_t difficulty{};
    std::string static_model_key;
    std::shared_ptr<const gameplay_world::HumanoidMotionBanks> motion_banks;
    std::shared_ptr<const gameplay_effects::EffectBank> effects;
    std::shared_ptr<const gameplay_collision::delivery::Catalog> contacts;
    // Actual File1 NETBIO01 source; absence keeps voice startup delegated to
    // the caller's explicit owner rather than inventing an archive selection.
    std::shared_ptr<reo::assets::Source> voice_source{};
};
enum class OfflineApplicationStatus {
    completed,invalid_input,unavailable,closed,busy,not_prepared,not_started,
    frame_already_bound,presentation_already_bound,pending_collision
};
enum class OfflinePrepareStage {records,roster,difficulty,room,assets,ready};
struct OfflinePrepareResult {
    OfflineApplicationStatus status{OfflineApplicationStatus::unavailable};
    OfflinePrepareStage stage{OfflinePrepareStage::records};
};
struct OfflineApplicationCreated;
// One fresh native application lifetime. Notification, message and frame
// providers are borrowed and must outlive the bound application/frame.
class OfflineApplication final {
public:
    static OfflineApplicationCreated create_fresh(OfflineLaunchInput,
        gameplay_scenario::FlagNotifications&,gameplay_update::GameplayMessageSink* = nullptr)noexcept;
    ~OfflineApplication();
    OfflineApplication(const OfflineApplication&)=delete;
    OfflineApplication& operator=(const OfflineApplication&)=delete;
    OfflinePrepareResult prepare()noexcept;
    // The host invokes the source-ordered frontend before direct game setup.
    // A partial result exposes the exact unavailable stage for a later retry.
    FrontendResult begin_frontend()noexcept;
    // Both the input owner and live process window outlive this application.
    OfflineApplicationStatus bind_input(reo::Input&,void* window)noexcept;
    // The real output monitor must belong to the same live input window.
    OfflineApplicationStatus bind_display_clock(void* window)noexcept;
    // The host supplies the same real mixer and output owner it will render.
    // This establishes sound ownership only; it does not run frontend startup.
    OfflineApplicationStatus bind_audio(std::shared_ptr<audio_mix_tail::Mixer>,
                                        std::shared_ptr<adxt_output_session::Session>)noexcept;
    gameplay_world::PrimaryStartupReport start(gameplay_world::PrimaryStartupEffects*,
        const gameplay_world::PrimaryEquipmentContext* = nullptr)noexcept;
    OfflineApplicationStatus bind_frame(gameplay_update::PhaseServices&,SessionCollisionInputs&,
        gameplay_world::SecondaryCollisionWalls&)noexcept;
    // Real display configuration/window are supplied by the host. The same
    // window must already be bound to the application's canonical input.
    OfflineApplicationStatus bind_presentation(void* window,gameplay_scenario::CameraProjectionContext,
        std::int8_t display_mode,std::uint32_t width,std::uint32_t height)noexcept;
    FrameStep advance(std::span<const std::int16_t> hit_timer_amounts,
                      std::size_t script_budget=4096,std::size_t task_budget=1024);
    OfflineApplicationStatus close()noexcept;
    NativeSession& session()noexcept{return *session_;}
    SessionStartup& startup()noexcept{return *startup_;}
    std::shared_ptr<SessionRooms> rooms()const noexcept{return rooms_;}
    std::shared_ptr<gameplay_scenario::ActorVoiceSelections> voice_selections()const noexcept{return voices_;}
    const gameplay_presentation::BackgroundState* background()const noexcept{return background_.get();}
    const gameplay_presentation::GraphicsState* graphics()const noexcept{return graphics_.get();}
    SessionAudio* audio()noexcept{return audio_.get();}
    SessionRoomTransport* room_transport()noexcept{return room_transport_.get();}
    gameplay_presentation::WindowsVBlank* display_clock()noexcept{return display_clock_.get();}
    gameplay_presentation::FrontendDisplay* frontend_display()noexcept{return frontend_display_.get();}
    const SessionFrontend* frontend()const noexcept{return frontend_.get();}
    SessionFrontend* frontend()noexcept{return frontend_.get();}
    // Retained collision queues remain available to their real owner after an
    // interrupted frame; close refuses to discard pending entries.
    SessionCollisionFrame* collision_frame()noexcept{return frame_.get();}
    OfflinePrepareStage prepare_stage()const noexcept{return stage_;}
    bool started()const noexcept{return started_;}
private:
    OfflineApplication(OfflineLaunchInput,std::shared_ptr<NativeSession>,std::unique_ptr<SessionStartup>);
    OfflineLaunchInput input_;
    std::shared_ptr<NativeSession> session_;
    std::unique_ptr<SessionStartup> startup_;
    std::unique_ptr<SessionRoomTransport> room_transport_;
    std::unique_ptr<SessionInput> input_source_;
    std::unique_ptr<gameplay_presentation::WindowsVBlank> display_clock_;
    std::unique_ptr<gameplay_presentation::FrontendDisplay> frontend_display_;
    std::shared_ptr<gameplay_scenario::ActorVoiceSelections> voices_;
    std::shared_ptr<const afs_source_range::Archive> sound_archive_;
    std::unique_ptr<SessionAudio> audio_;
    std::unique_ptr<gameplay_presentation::BackgroundState> background_;
    std::unique_ptr<gameplay_presentation::GraphicsState> graphics_;
    std::unique_ptr<SessionFrontend> frontend_;
    std::unique_ptr<gameplay_presentation::SessionPresentation> presentation_;
    std::shared_ptr<SessionRooms> rooms_;
    std::unique_ptr<SessionActorServices> actors_;
    std::unique_ptr<SessionCollisionFrame> frame_;
    OfflinePrepareStage stage_{OfflinePrepareStage::records};
    bool running_{},started_{},closed_{};
};
struct OfflineApplicationCreated {
    OfflineApplicationStatus status{OfflineApplicationStatus::unavailable};
    std::unique_ptr<OfflineApplication> application;
};
}
