#include "session_startup.hpp"
#include "session_resources.hpp"
#include "session_input.hpp"
#include "../gameplay_scenario/actor_voice_selections.hpp"
#include "../gameplay_presentation/background.hpp"
#include "../gameplay_presentation/frontend_display.hpp"
#include "../gameplay_scenario/script_program.hpp"
#include "../gameplay_navigation/bank.hpp"
#include <cstdio>
#include <stdexcept>
#include <utility>
namespace reo::native::gameplay_application {
namespace {
NativeSession& admitted(NativeSession& session,const std::shared_ptr<const gameplay_world::HumanoidMotionBanks>& banks){
    if(!session.open()||session.update().busy()||session.world().busy()||!banks)
        throw std::invalid_argument("Canonical session startup capabilities unavailable");
    return session;
}
class RequiredStartupEffects final:public gameplay_world::PrimaryStartupEffects {
public:
    explicit RequiredStartupEffects(const gameplay_world::World& world):world_(world){}
    bool bound_to(const gameplay_world::World& world)const noexcept override{return &world==&world_;}
    gameplay_world::PrimaryStartupStatus voice_archive(std::uint8_t,std::uint8_t)override{return unavailable;}
    gameplay_world::PrimaryStartupStatus background(std::uint8_t)override{return unavailable;}
    gameplay_world::PrimaryStartupStatus initialize_stream_stage()override{return unavailable;}
    gameplay_world::PrimaryStartupStatus run(gameplay_world::PrimaryStartupWork)override{return unavailable;}
    gameplay_world::PrimaryStartupStatus actor_resources(gameplay_world::PrimaryStartupWork,const gameplay_world::actors::EntityId&)override{return unavailable;}
    std::optional<std::int8_t> roster_kind(std::uint8_t)const noexcept override{return{};}
    std::optional<float> reference_height(std::uint8_t)const noexcept override{return{};}
private:
    static constexpr auto unavailable=gameplay_world::PrimaryStartupStatus::unavailable;
    const gameplay_world::World& world_;
};
}
// Intercepts the source calls owned by the retained application graph.
// All other 5EB520 effects continue to require their real supplied owners.
class SessionStartupEffects final:public gameplay_world::PrimaryStartupEffects {
public:
    SessionStartupEffects(NativeSession& session,SessionResources& resources,
                          gameplay_world::PrimaryStartupEffects& remaining,SessionInput* input,
                          std::shared_ptr<gameplay_scenario::ActorVoiceSelections> voices,gameplay_presentation::BackgroundState* background,
                          SessionRoomMotions& room_motions,StartupTextureRegistry& textures,gameplay_presentation::FrontendDisplay* display,
                          SessionStartup& startup):
        session_(session),resources_(resources),remaining_(remaining),input_(input),voices_(std::move(voices)),background_(background),
        room_motions_(room_motions),textures_(textures),display_(display),startup_(startup){}
    bool bound_to(const gameplay_world::World& world)const noexcept override{
        return &world==&session_.world()&&resources_.bound_to(session_)&&remaining_.bound_to(world);
    }
    gameplay_world::PrimaryStartupStatus voice_archive(std::uint8_t slot,std::uint8_t character)override{
        using S=gameplay_scenario::StreamStatus;using P=gameplay_world::PrimaryStartupStatus;
        if(!voices_)return remaining_.voice_archive(slot,character);
        if(!session_.world().updating_)return P::unavailable;
        switch(voices_->activate(slot,character)){case S::completed:return P::completed;case S::busy:return P::busy;case S::closed:return P::closed;default:return P::unavailable;}
    }
    gameplay_world::PrimaryStartupStatus background(std::uint8_t selector)override{
        using P=gameplay_world::PrimaryStartupStatus;
        if(!background_)return remaining_.background(selector);
        return session_.world().updating_&&background_->select(selector)?P::completed:P::unavailable;
    }
    gameplay_world::PrimaryStartupStatus initialize_stream_stage()override{
        using Status=gameplay_world::PrimaryStartupStatus;
        // Standalone startup owners can supply their explicit capability.
        // The application binds its real1D1FC0 texture and native display.
        if(!display_)return remaining_.initialize_stream_stage();
        if(!session_.world().updating_||!textures_.bound_to(session_.world()))return Status::unavailable;
        const auto texture=textures_.texture(0);if(!texture||!display_->drain())return Status::unavailable;
        //1B0510 submits/waits before drawing on each of its three passes.
        for(unsigned pass=0;pass<3;++pass)if(!display_->loading_pass(*texture))return Status::unavailable;
        return Status::completed;
    }
    void motion_defaults_reloaded()noexcept override{room_motions_.reset_default_selection();remaining_.motion_defaults_reloaded();}
    gameplay_world::PrimaryStartupStatus run(gameplay_world::PrimaryStartupWork work)override{
        using Work=gameplay_world::PrimaryStartupWork;using Status=gameplay_world::PrimaryStartupStatus;
        auto& world=session_.world();
        if(work==Work::scenario_63f590)return world.updating_?Status::completed:Status::unavailable; // checked return-only body
        if(work==Work::resource_2600||work==Work::scenario_common_resources){
            if(!world.updating_)return Status::unavailable;
            const auto result=work==Work::resource_2600?textures_.release_cockpit_pair():textures_.load_scenario_common(session_);
            return result==StartupTextureStatus::completed?Status::completed:
                result==StartupTextureStatus::no_memory?Status::no_memory:Status::unavailable;
        }
        if(work==Work::scenario_resources||work==Work::scenario_particles||work==Work::timed_message_resources||work==Work::scenario_ui){
            auto& data=startup_.scenario_resources_;
            if(data.ready()){
                if(!world.updating_||!data.bound_to(world))return Status::unavailable;
                const auto result=work==Work::scenario_resources?data.load_return_points():
                    work==Work::scenario_particles?data.load_placements():
                    work==Work::timed_message_resources?data.load_doors():data.reset_positions();
                return result==ScenarioDataStatus::completed?Status::completed:
                    result==ScenarioDataStatus::no_memory?Status::no_memory:Status::unavailable;
            }
            return remaining_.run(work);
        }
        if(work==Work::room_motion_table){
            const auto result=room_motions_.load_scenario_auxiliary();
            return result==RoomMotionStatus::completed?Status::completed:
                result==RoomMotionStatus::no_memory?Status::no_memory:Status::unavailable;
        }
        if(work==Work::scenario_render_models&&startup_.graphics_)return startup_.load_scenario_effects();
        if(work==Work::scenario_render_data&&startup_.graphics_)return startup_.load_scenario_objects();
        if(work==Work::resource_pump&&display_){
            //18DCB0 quiesces graphics, compacts the guest token heap and
            // patches DMA references. Native draws sample retained immutable
            // owners synchronously and have no movable guest-token/DMA graph;
            // submit and drain the real staged surface before continuing.
            if(!world.updating_||!resources_.bound_to(session_)||!textures_.bound_to(world)||textures_.busy()||!display_->bound_to(world))return Status::unavailable;
            return display_->quiesce(world)?Status::completed:Status::unavailable;
        }
        if(work==Work::render_2500){
            const auto status=textures_.load_game_etc();
            return status==StartupTextureStatus::completed?Status::completed:
                status==StartupTextureStatus::no_memory?Status::no_memory:Status::unavailable;
        }
        if(work==Work::controller_routes && input_){
            if(!world.updating_ || !input_->bound_to(world))return Status::unavailable;
            return input_->initialize_roster_routes()?Status::completed:Status::unavailable;
        }
        if(work==Work::scene_resources)
            return resources_.initialize_roster().status==ResourceImportStatus::completed?Status::completed:Status::unavailable;
        if(work==Work::scenario_sound){
            if(!world.updating_||!world.primary_object_startup_)return Status::unavailable;
            return resources_.initialize_roster_room_objects()?Status::completed:Status::unavailable;
        }
        if(work==Work::scenario_scripts){
            if(!world.updating_||!world.primary_script_startup_||!world.scenario)return Status::unavailable;
            bank_=session_.archive().scenario_scripts(*world.scenario);if(!bank_)return Status::unavailable;
            if(session_.update().bind_roster_scenario_scripts(*bank_,session_.update().action_choices().state().table_row)!=
                gameplay_update::Status::completed)return Status::unavailable;
            return room_motions_.bind_table(*bank_)?Status::completed:Status::unavailable;
        }
        if(work==Work::start_scenario_script){
            if(!world.updating_||!world.primary_script_startup_||!bank_)return Status::unavailable;
            const auto profile=world.mode==0?gameplay_scenario::DispatchProfile::offline_actor:gameplay_scenario::DispatchProfile::ordinary;
            const auto script=gameplay_scenario::content::admit_script_program(*bank_,profile,gameplay_scenario::content::ScriptRoots::scenario_startup);
            if(script.status!=gameplay_scenario::content::ScriptAdmission::admitted||!script.program)return Status::unavailable;
            return session_.update().start_roster_scenario_script(script.program,session_.providers(),4096).status==
                gameplay_update::Status::completed?Status::completed:Status::unavailable;
        }
        if(work==Work::scenario_navigation){
            if(world.mode!=0||!world.scenario||!world.session().asset_loading_mode||!*world.session().asset_loading_mode)return Status::unavailable;
            char name[16];const int n=std::snprintf(name,sizeof name,"r%03u.sgl",unsigned(*world.scenario));
            if(n<0||std::size_t(n)>=sizeof name)return Status::unavailable;
            const auto bytes=session_.archive().read_resource(*world.scenario,name);
            if(!bytes){(void)world.navigation().clear_header_byte();return Status::unavailable;}
            gameplay_navigation::ImportFailure failure;
            const auto raw=std::span(reinterpret_cast<const std::uint8_t*>(bytes->data()),bytes->size());
            auto parsed=gameplay_navigation::Asset::read(raw,failure);if(!parsed)return Status::unavailable;
            return world.navigation().bind(std::make_shared<const gameplay_navigation::Asset>(std::move(*parsed)))?
                Status::completed:Status::unavailable;
        }
        if(work==Work::scenario_root_motion){
            // The historical enum name is misleading:1D4020 loads scenario
            // messages at32443C, after EVB startup and navigation, not motion.
            if(!world.updating_||!session_.scene_message_variant_)return Status::unavailable;
            return session_.scene_text_bank_.load_messages(*session_.scene_message_variant_).status==
                gameplay_scenario::SceneTextBankStatus::completed?Status::completed:Status::unavailable;
        }
        if(work==Work::scenario_tables)
            return session_.scene_text_bank().initialize_choices()==gameplay_scenario::SceneTextBankStatus::completed?
                Status::completed:Status::unavailable;
        return remaining_.run(work);
    }
    gameplay_world::PrimaryStartupStatus actor_resources(gameplay_world::PrimaryStartupWork work,
        const gameplay_world::actors::EntityId& actor)override{
        if(startup_.audio_||work==gameplay_world::PrimaryStartupWork::actor_equipment)return startup_.load_actor_resources(work,actor);
        return remaining_.actor_resources(work,actor);
    }
    std::optional<std::int8_t> roster_kind(std::uint8_t row)const noexcept override{
        if(const auto value=startup_.roster_kind(row))return value;
        return remaining_.roster_kind(row);
    }
    std::optional<float> reference_height(std::uint8_t character)const noexcept override{
        if(const auto value=startup_.reference_height(character))return value;
        return remaining_.reference_height(character);
    }
private:
    NativeSession& session_;SessionResources& resources_;gameplay_world::PrimaryStartupEffects& remaining_;
    SessionInput* input_{};
    std::shared_ptr<gameplay_scenario::ActorVoiceSelections> voices_;
    gameplay_presentation::BackgroundState* background_{};
    std::optional<gameplay_scenario::content::ScriptBank> bank_;
    SessionRoomMotions& room_motions_;
    StartupTextureRegistry& textures_;
    gameplay_presentation::FrontendDisplay* display_{};
    SessionStartup& startup_;
};
SessionStartup::SessionStartup(NativeSession& session,std::shared_ptr<const reo::assets::Source> source,
    std::shared_ptr<const gameplay_world::HumanoidMotionBanks> banks):
    session_(admitted(session,banks)),source_(source),actors_(source),motion_assets_(source),
    motion_owner_(session.world()),models_(session.world(),motion_owner_),room_motions_(session,motion_assets_,motion_owner_),textures_(session.world(),std::move(source)),scenario_resources_(session.world(),session.archive()){
    const auto result=motion_owner_.publish(std::move(banks));
    if(result.status!=gameplay_world::HumanoidPublicationStatus::completed)
        throw std::invalid_argument("Canonical session motion publication unavailable");
}
SessionStartup::~SessionStartup(){if(running_||close()==gameplay_world::PrimaryStartupStatus::busy)std::terminate();}
std::optional<std::int8_t> SessionStartup::roster_kind(std::uint8_t row)const noexcept{
    if(!open()||!roster_kinds_||row>=roster_kinds_->size())return{};
    return (*roster_kinds_)[row];
}
gameplay_world::PrimaryStartupStatus SessionStartup::adopt_cold_roster_kinds()noexcept{
    using Status=gameplay_world::PrimaryStartupStatus;
    if(!open())return Status::closed;
    if(running_||session_.world().busy()||session_.update().busy())return Status::busy;
    if(roster_kinds_||last_)return Status::unavailable;
    roster_kinds_=std::array<std::int8_t,4>{};return Status::completed;
}
std::optional<float> SessionStartup::reference_height(std::uint8_t character)const noexcept{
    if(!open()||!reference_heights_||character>=reference_heights_->size())return{};
    return (*reference_heights_)[character];
}
gameplay_world::PrimaryStartupStatus SessionStartup::adopt_cold_reference_heights()noexcept{
    using Status=gameplay_world::PrimaryStartupStatus;
    if(!open())return Status::closed;
    if(running_||session_.world().busy()||session_.update().busy())return Status::busy;
    if(reference_heights_||last_)return Status::unavailable;
    reference_heights_=std::array<float,8>{};return Status::completed;
}
gameplay_world::PrimaryRecordsInitialized SessionStartup::initialize_records()noexcept{
    if(!open())return{gameplay_world::PrimaryRecordsStatus::closed};
    if(busy()||session_.world().busy()||session_.update().busy())return{gameplay_world::PrimaryRecordsStatus::busy};
    running_=true;struct Reset{bool& value;~Reset(){value=false;}}reset{running_};
    return gameplay_world::initialize_primary_records(session_.world());
}
gameplay_world::PrimaryStartupReport SessionStartup::start(gameplay_world::PrimaryStartupEffects* effects,
    const gameplay_world::PrimaryEquipmentContext* equipment)noexcept{
    if(!open())return{gameplay_world::PrimaryStartupStatus::closed};
    if(busy()||session_.world().busy()||session_.update().busy())return{gameplay_world::PrimaryStartupStatus::busy};
    running_=true;struct Reset{bool& value;~Reset(){value=false;}}reset{running_};
    RequiredStartupEffects required(session_.world());
    std::optional<SessionStartupEffects> application_effects;
    if(session_.resources())application_effects.emplace(session_,*session_.resources(),effects?*effects:required,input_,voices_,background_,room_motions_,textures_,loading_display_,*this);
    const gameplay_world::PrimaryStartupContext context{
        session_.update(),actors_,motion_assets_,&session_.archive(),
        application_effects?&*application_effects:effects,equipment};
    last_=models_.start_roster(context);return *last_;
}
StartupTextureStatus SessionStartup::bind_frontend(std::shared_ptr<const gameplay_presentation::CommonFrontendTextures> common,
    gameplay_presentation::FrontendDisplay* display)noexcept{
    if(!open())return common||display?StartupTextureStatus::closed:StartupTextureStatus::completed;
    if(busy()||session_.world().busy()||session_.update().busy())return StartupTextureStatus::busy;
    if(display&&!display->bound_to(session_.world()))return StartupTextureStatus::unavailable;
    if(loading_display_&&display&&loading_display_!=display)return StartupTextureStatus::unavailable;
    const auto status=textures_.bind_common(std::move(common));if(status!=StartupTextureStatus::completed)return status;
    loading_display_=display;return StartupTextureStatus::completed;
}
RoomMotionResult SessionStartup::load_room_motions()noexcept{
    if(!open())return{RoomMotionStatus::closed};
    if(busy())return{RoomMotionStatus::busy};
    running_=true;struct Reset{bool& value;~Reset(){value=false;}}reset{running_};
    return room_motions_.load();
}
gameplay_world::PrimaryStartupStatus SessionStartup::close()noexcept{
    if(closed_)return gameplay_world::PrimaryStartupStatus::completed;
    if(busy()||session_.world().busy()||session_.update().busy())return gameplay_world::PrimaryStartupStatus::busy;
    running_=true;struct Reset{bool& value;~Reset(){value=false;}}reset{running_};
    if(models_.close()!=gameplay_world::PrimaryModelStatus::completed||
       motion_owner_.close()!=gameplay_world::HumanoidPublicationStatus::completed)
        return gameplay_world::PrimaryStartupStatus::busy;
    if(textures_.close()!=StartupTextureStatus::completed||scenario_resources_.close()!=ScenarioDataStatus::completed)return gameplay_world::PrimaryStartupStatus::busy;
    loading_display_=nullptr;graphics_=nullptr;audio_=nullptr;effect_bank_.reset();effect_geometry_.reset();effect_model_bytes_.reset();effect_data_bytes_.reset();object_models_.reset();weapon_programs_.reset();source_.reset();
    closed_=true;background_=nullptr;voices_.reset();roster_kinds_.reset();reference_heights_.reset();last_.reset();return gameplay_world::PrimaryStartupStatus::completed;
}
}
