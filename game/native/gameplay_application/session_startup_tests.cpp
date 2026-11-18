#include "session_startup.hpp"
#include "offline_application.hpp"
#include "session_resources.hpp"
#include "../animation/playback.hpp"
#include "session_rooms.hpp"
#include "session_behavior_services.hpp"
#include "session_primary_actions.hpp"
#include "session_scene_query_effects.hpp"
#include "../gameplay_world/launch_roster.hpp"
#include "../gameplay_scenario/scenario_events.hpp"
#include "../gameplay_scenario/actor_voice_selections.hpp"
#include "../gameplay_presentation/frontend_assets.hpp"
#include "../adxt_output_session/session.hpp"
#include "../audio_mix_tail/mixer.hpp"
#include "../audio_output/audio_output_owner.h"
#include "runtime/assets/virtual_afs.h"
#include "runtime/input/input.h"
#ifdef _WIN32
#include <windows.h>
#endif
#include <algorithm>
#include <cstring>
#include <fstream>
#include <filesystem>
#include "../gameplay_scenario/script_program.hpp"
#include <iostream>
#include <source_location>
#include <stdexcept>
namespace app=reo::native::gameplay_application;
namespace w=reo::native::gameplay_world;
namespace s=reo::native::gameplay_scenario;
namespace u=reo::native::gameplay_update;
namespace scene=reo::native::gameplay_scene;
namespace {
unsigned checks{},startups{},models{},guards{},refusals{},lifetimes{},script_steps{},frontend_positive{},frontend_loading_passes{},frontend_resource_barriers{};
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Session startup check "+std::to_string(at.line()));}
struct TestBankGain final:reo::native::audio_banks::v2::GainProvider {float gain(unsigned,unsigned,std::uint64_t)noexcept override{return 1.f;}};
struct TestMasterGain final:reo::native::audio_mix_tail::MasterGain {float gain()noexcept override{return 1.f;}};
// Explicitly unstarted output boundary; no audio device is claimed.
struct UnstartedAudioProvider final:reo::audio_output::Provider {
    std::string_view source_sha256()const noexcept override{return reo::audio_output::provider_source_sha256;}
    bool attach(reo::audio_output::CallbackSlot&)noexcept override{return false;}
    bool detach()noexcept override{return false;}
    bool stop()noexcept override{return false;}
    bool unload()noexcept override{return false;}
};
struct Notifications final:s::FlagNotifications {
    app::NativeSession* host{};app::SessionStartup* startup{};bool armed{},guarded{true};unsigned callbacks{};
    bool changed(const s::ScenarioFlagChange& change)noexcept override{
        if(armed&&change.id==123){++callbacks;guarded=guarded&&host&&startup&&host->world().busy()&&
            host->update().busy()&&host->close()==app::SessionStatus::busy&&
            host->resources()->close()==app::SessionResourceStatus::busy&&
            startup->close()==w::PrimaryStartupStatus::busy&&
            host->update().step_script(0).status==u::Status::busy;}
        return true;
    }
    bool changed(const s::StridedFlagChange&)noexcept override{return true;}
};
w::Profile profile(){w::Profile value;value.layouts.push_back({});return value;}
struct Memory final:reo::assets::PositionedSource {
    std::vector<std::uint8_t> bytes;
    std::uint64_t size()const noexcept override{return bytes.size();}
    std::size_t read(std::uint64_t at,std::size_t count,void* out)const override{
        if(at>bytes.size()||count>bytes.size()-at)throw std::runtime_error("Startup fixture source range");
        std::memcpy(out,bytes.data()+at,count);return count;
    }
};
std::shared_ptr<const reo::assets::Source> fixture_source(){
    auto source=std::make_shared<Memory>();auto& bytes=source->bytes;bytes.resize(6*4096+3*1024*1024);
    std::memcpy(bytes.data(),"AFS\0",4);reo::assets::put32(bytes.data()+4,6);
    const std::array names{"r001.afs","r002.afs","r028.afs","r035.afs","r041.afs","romdata_usa.afs"};
    for(unsigned i=0;i<6;++i){const unsigned base=(i+1)*4096,size=i==5?3*1024*1024:4096;reo::assets::put32(bytes.data()+8+8*i,base);reo::assets::put32(bytes.data()+12+8*i,size);std::memcpy(bytes.data()+512+48*i,names[i],std::strlen(names[i]));std::memcpy(bytes.data()+base,"AFS\0",4);const unsigned count=i==5?1342:1;reo::assets::put32(bytes.data()+base+4,count);for(unsigned member=0;member<count;++member){reo::assets::put32(bytes.data()+base+8+8*member,i==5?16384+2048*member:2048);reo::assets::put32(bytes.data()+base+12+8*member,1);}}
    reo::assets::put32(bytes.data()+56,512);reo::assets::put32(bytes.data()+60,6*48);
    return std::make_shared<const reo::assets::Source>("explicit startup fixture",source);
}
// Controlled EVB overlay only: all model, item, room and SGL bytes remain the
// actual owned archive. Entry 1 publishes scenario flag 123 then yields.
struct ScriptOverlay final:reo::assets::PositionedSource {
    std::shared_ptr<const reo::assets::Source> source;std::uint64_t offset{};std::vector<std::uint8_t> bytes;
    std::uint64_t size()const noexcept override{return source->size;}
    std::size_t read(std::uint64_t at,std::size_t size,void* out)const override{
        source->read(at,size,out);const auto first=std::max(at,offset),last=std::min(at+size,offset+bytes.size());
        if(first<last)std::memcpy(static_cast<std::uint8_t*>(out)+(first-at),bytes.data()+(first-offset),std::size_t(last-first));
        return size;
    }
};
// Controlled one-resource fault for testing the source-ordered type/placement
// boundary and recovery. All other bytes still come from the owned archive.
struct PlacementFault final:reo::assets::PositionedSource {
    std::shared_ptr<const reo::assets::Source> source;std::vector<std::byte> placement;bool corrupt{true};mutable unsigned reads{};
    std::uint64_t size()const noexcept override{return source->size;}
    std::size_t read(std::uint64_t at,std::size_t size,void* out)const override{
        source->read(at,size,out);
        if(size==placement.size()&&size>=4&&!std::memcmp(out,placement.data(),size)){
            ++reads;
            if(corrupt)static_cast<std::byte*>(out)[0]=std::byte{0};
        }
        return size;
    }
};
std::shared_ptr<const reo::assets::Source> controlled_startup_source(const char* path,bool variant_command=false){
    auto source=std::make_shared<const reo::assets::Source>(path);
    const auto lower=[](std::string name){for(auto& c:name)if(c>='A'&&c<='Z')c+=('a'-'A');return name;};
    const auto root=reo::assets::table(*source,0,source->size);
    const auto parent=std::find_if(root.entries.begin(),root.entries.end(),[&](const auto& value){return lower(value.name)=="r041.afs";});
    check(parent!=root.entries.end());const auto inner=reo::assets::table(*source,parent->offset,parent->size);
    const auto member=std::find_if(inner.entries.begin(),inner.entries.end(),[&](const auto& value){return lower(value.name)=="r041.evb";});
    check(member!=inner.entries.end()&&member->size>=(variant_command?184u:168u));
    auto overlay=std::make_shared<ScriptOverlay>();overlay->source=source;overlay->offset=std::uint64_t(parent->offset)+member->offset;overlay->bytes.resize(member->size);
    const auto word=[&](unsigned at,std::uint32_t value){reo::assets::put32(overlay->bytes.data()+at,value);};
    // Retain the authored room-to-motion table. Only executable roots are
    // controlled;1B2D00 must select the real room73 common motion member68.
    std::vector<std::uint8_t> authored(member->size);source->read(overlay->offset,authored.size(),authored.data());
    std::uint32_t motion_table{};std::memcpy(&motion_table,authored.data()+32,4);
    check(motion_table>=192&&motion_table<authored.size());
    std::size_t table_end=motion_table;std::uint16_t value{};
    do{check(table_end+2<=authored.size());std::memcpy(&value,authored.data()+table_end,2);table_end+=2;}while(value!=255);
    word(32,motion_table);std::copy(authored.begin()+motion_table,authored.begin()+table_end,overlay->bytes.begin()+motion_table);
    word(0,128);word(4,136); // Entry 4 is null, as in the owned r041 EVB.
    word(128,1);word(132,0xa); // configured root 0
    word(136,1);
    if(variant_command){word(140,0x0200005a);word(144,127);word(148,3);word(152,0);}
    const unsigned flag=variant_command?156:140;
    word(flag,0x0200000b);word(flag+4,0);word(flag+8,123);word(flag+12,1);word(flag+16,0xa);
    return std::make_shared<const reo::assets::Source>("controlled-startup-evb",overlay);
}
void fixtures(){
    const auto source=fixture_source();Notifications notices;app::NativeSession session(source,profile(),notices);
    const auto records=session.scene_records();bool refused{};
    try{app::SessionStartup invalid(session,source,{});}catch(const std::invalid_argument&){refused=true;}
    check(refused&&!session.world().humanoid_motion_source()&&!session.world().humanoid_motion_source_closed());++refusals;
    app::SessionStartup startup(session,source,w::HumanoidMotionAssets::initial_banks(false));
    check(startup.bound_to(session)&&startup.open()&&session.world().humanoid_motion_source()==&startup.motion_owner());
    for(unsigned row=0;row<5;++row)check(!startup.roster_kind(std::uint8_t(row)));
    for(unsigned character=0;character<9;++character)check(!startup.reference_height(std::uint8_t(character)));
    check(startup.initialize_records().status==w::PrimaryRecordsStatus::completed);
    check(startup.initialize_records().status==w::PrimaryRecordsStatus::not_empty);++refusals;
    for(unsigned i=0;i<8;++i)check(session.world().primary(i)&&session.world().primary(i)->slot==0);
    refused=false;try{app::SessionStartup duplicate(session,source,w::HumanoidMotionAssets::initial_banks(false));}catch(const std::invalid_argument&){refused=true;}
    check(refused&&session.world().humanoid_motion_source()==&startup.motion_owner());++refusals;
    session.world().session().primary_population=0;
    const auto unavailable=startup.start(nullptr);check(unavailable.status==w::PrimaryStartupStatus::unavailable&&unavailable.stage==w::PrimaryStartupStage::background&&session.world().session().setup_gate==2&&startup.last_result());++refusals;
    check(session.scene_records()==records&&session.world().session().timing==&session.update());
    check(startup.close()==w::PrimaryStartupStatus::completed&&!startup.last_result()&&!startup.open());
    check(!startup.roster_kind(0)&&!startup.reference_height(0));
    check(startup.start(nullptr).status==w::PrimaryStartupStatus::closed&&startup.initialize_records().status==w::PrimaryRecordsStatus::closed);++refusals;
    check(session.close()==app::SessionStatus::completed&&startup.close()==w::PrimaryStartupStatus::completed);
    app::NativeSession second(source,profile(),notices);app::SessionStartup later(second,source,w::HumanoidMotionAssets::initial_banks(false));
    check(later.initialize_records().status==w::PrimaryRecordsStatus::completed);const auto retained=second.world().primary(0);const auto id=second.world().identity(0);
    check(second.close()==app::SessionStatus::completed&&later.close()==w::PrimaryStartupStatus::completed&&!second.world().resolve(id)&&retained->slot==0);++lifetimes;
}
struct Effects final:w::PrimaryStartupEffects {
    app::NativeSession& session;app::SessionStartup& startup;std::shared_ptr<reo::native::gameplay_scene::Records> records;
    app::OfflineApplication* application{};
    std::vector<w::PrimaryStartupWork> work;unsigned voices{},backgrounds{},stream_initializations{};bool failed_once{};
    w::PrimaryStartupWork fail_work{w::PrimaryStartupWork::scenario_sound};
    Effects(app::NativeSession& value,app::SessionStartup& capabilities):session(value),startup(capabilities),records(session.scene_records()){}
    bool bound_to(const w::World& value)const noexcept override{return &value==&session.world();}
    w::PrimaryStartupStatus guard(){
        check(session.world().busy()&&session.close()==app::SessionStatus::busy&&startup.close()==w::PrimaryStartupStatus::busy);
        check(session.install_room({41,73,0})==app::SessionStatus::busy&&session.step_room_script().status==app::SessionStatus::busy&&session.advance(nullptr,nullptr).status==app::SessionStatus::busy);
        check(startup.start(this).status==w::PrimaryStartupStatus::busy&&startup.initialize_records().status==w::PrimaryRecordsStatus::busy&&session.update().close()==u::Status::busy);
        if(session.resources())check(session.initialize_resources().status==app::ResourceImportStatus::busy);
        if(application){check(application->close()==app::OfflineApplicationStatus::busy&&application->prepare().status==app::OfflineApplicationStatus::busy);
            if(const auto voices=application->voice_selections())check(voices->marker(0).status!=s::StreamStatus::closed);}
        check(session.scene_records()==records&&records==session.scene_controls().records()&&records==session.scene_proxies().records());++guards;
        return w::PrimaryStartupStatus::completed;
    }
    w::PrimaryStartupStatus voice_archive(std::uint8_t slot,std::uint8_t character)override{check(slot<5&&character<8);++voices;return guard();}
    w::PrimaryStartupStatus background(std::uint8_t value)override{check(value==0);++backgrounds;return guard();}
    w::PrimaryStartupStatus initialize_stream_stage()override{++stream_initializations;return guard();}
    w::PrimaryStartupStatus run(w::PrimaryStartupWork value)override{work.push_back(value);const auto result=guard();if(value==fail_work&&!failed_once){failed_once=true;return w::PrimaryStartupStatus::unavailable;}return result;}
    w::PrimaryStartupStatus actor_resources(w::PrimaryStartupWork value,const w::actors::EntityId& id)override{check((value==w::PrimaryStartupWork::actor_equipment||value==w::PrimaryStartupWork::actor_secondary_resources)&&session.world().resolve(id));return guard();}
    std::optional<std::int8_t> roster_kind(std::uint8_t row)const noexcept override{return row<4?std::optional<std::int8_t>(0):std::nullopt;}
    std::optional<float> reference_height(std::uint8_t character)const noexcept override{return character<8?std::optional(float(character)+2.f):std::nullopt;}
};
void owned(const char* path){
    const auto source=std::make_shared<const reo::assets::Source>(path);Notifications notices;
    for(unsigned mode:{0u,1u})for(unsigned population:{1u,4u,8u}){
        app::NativeSession session(source,profile(),notices,std::uint8_t(mode));
        check(session.install_room({41,73,0})==app::SessionStatus::completed);const auto records=session.scene_records();
        check(session.scene_controls().size()==7&&session.scene_proxies().size()==7&&session.room_scene());
        app::SessionStartup startup(session,source,w::HumanoidMotionAssets::initial_banks(false));
        check(startup.initialize_records().status==w::PrimaryRecordsStatus::completed);
        auto& state=session.world().session();state.primary_population=population;state.asset_loading_mode=1;state.scene_stream_stage=0;
        for(unsigned i=0;i<8;++i){const auto actor=session.world().primary(i);check(actor->slot==0);actor->character=std::uint8_t(i);actor->ai_control=std::uint8_t(i&1);}
        Effects effects(session,startup);const auto interrupted=startup.start(&effects);
        check(interrupted.status==w::PrimaryStartupStatus::unavailable&&interrupted.stage==w::PrimaryStartupStage::scenario_sound&&state.setup_gate==2&&!session.world().busy());++refusals;
        std::array<std::shared_ptr<w::Actor>,8> retained;std::array<std::shared_ptr<reo::native::animation::Instance>,8> models_before;
        std::array<w::actors::EntityId,8> identities;
        for(unsigned i=0;i<8;++i){retained[i]=session.world().primary(i);models_before[i]=retained[i]->model;identities[i]=session.world().identity(i);}
        const auto completed=startup.start(&effects);check(completed.status==w::PrimaryStartupStatus::completed&&completed.models_applied==population&&completed.gauges_initialized==population&&state.setup_gate==0&&state.scene_stream_stage==0);++startups;
        check(effects.stream_initializations==1&&effects.backgrounds==3&&effects.voices==2*std::min(population,5u)&&startup.motion_owner().snapshot()->base_loaded());
        check(session.scene_records()==records&&records==session.scene_controls().records()&&records==session.scene_proxies().records()&&session.world().session().timing==&session.update());
        for(unsigned i=0;i<8;++i){check(retained[i]==session.world().primary(i)&&retained[i]->model==models_before[i]&&retained[i]->slot==(i<population?i:0));if(i<population){check(retained[i]->active&&retained[i]->model&&retained[i]->animation&&retained[i]->animation->model()==retained[i]->model);++models;}}
        check(session.update().clock().update_counter()==0);const auto script=session.step_room_script();check(script.status==app::SessionStatus::completed&&script.update.script_operations>0&&!script.update.clock_committed);++script_steps;
        check(startup.close()==w::PrimaryStartupStatus::completed&&session.close()==app::SessionStatus::completed);
        for(unsigned i=0;i<population;++i){check(retained[i]->model==models_before[i]&&!session.world().resolve(identities[i]));++lifetimes;}
    }
}
#include "session_scene_query_effects_type4_tests.inc"
#include "session_scene_query_effects_type6_tests.inc"
#include "session_scenario_motion_tests.inc"
#include "session_return_points_tests.inc"
void owned_resources(const char* archive_path,const char* catalog_path,const char* effects_path,bool synthetic){
    const auto source=synthetic?controlled_startup_source(archive_path):std::make_shared<const reo::assets::Source>(archive_path);Notifications notices;
    auto host=std::make_shared<app::NativeSession>(source,profile(),notices,0);
    check(host->install_room({41,73,0})==app::SessionStatus::completed);
    app::SessionStartup startup(*host,source,w::HumanoidMotionAssets::initial_banks(false));
    check(startup.initialize_records().status==w::PrimaryRecordsStatus::completed);
    reo::native::gameplay_session::LaunchRoster roster;roster.scenario=41;roster.count=4;
    for(unsigned i=0;i<4;++i)roster.actors[i].model_variant=std::uint16_t(i+1);
    check(w::apply_launch_roster(host->world(),host->update().action_choices(),roster));
    check(host->import_launch_difficulty(1)==app::SessionStatus::completed);
    check(host->select_scene_message_catalog(s::SceneTextVariant::alternate)==app::SessionStatus::completed);
    auto& state=host->world().session();state.scene_stream_stage=0;state.collision_disabled_mask=0;
    if(synthetic)state.room_variants.restore(std::array<std::uint8_t,128>{});
    std::ifstream in(effects_path,std::ios::binary);unsigned count{};in.read(reinterpret_cast<char*>(&count),4);check(count==12);
    std::array<std::vector<std::byte>,2> inputs;
    for(auto& input:inputs){unsigned size{};in.read(reinterpret_cast<char*>(&size),4);check(size&&size<10000000);input.resize(size);in.read(reinterpret_cast<char*>(input.data()),size);check(bool(in));}
    auto bank=reo::native::gameplay_effects::EffectBank::import(inputs[0],inputs[1]);
    std::ifstream catalog_in(catalog_path,std::ios::binary);std::vector<char> raw{std::istreambuf_iterator<char>(catalog_in),{}};check(!raw.empty());
    std::vector<std::byte> data(raw.size());std::memcpy(data.data(),raw.data(),raw.size());
    auto catalog=std::make_shared<const reo::native::gameplay_collision::delivery::Catalog>(reo::native::gameplay_collision::delivery::Catalog::import(data));
    auto rooms=std::make_shared<app::SessionRooms>(host);
    const auto assets=app::SessionResourceAssets::load(host->archive(),41,"DEF41.NBD",bank,catalog);
    check(assets&&host->bind_resource_assets(assets,rooms)==app::SessionStatus::completed);
    auto& graph=*host->resources();check(!graph.initialized());
    // Before 591C50, excluded/nonlocal 68EF50 paths remain admitted while a
    // local active actor must not see fabricated empty resource descriptors.
    auto primary=host->world().primary(0);const auto old_room=primary->room;const auto old_slot=primary->slot;
    const auto old_status=primary->status;const auto old_active=primary->active;
    primary->active=false;check(host->update().actor_script_terminal().command_ready());
    primary->active=true;primary->status=0;primary->slot=1;check(host->update().actor_script_terminal().command_ready());
    primary->slot=0;primary->room=255;check(!host->update().actor_script_terminal().command_ready());
    primary->room=old_room;primary->slot=old_slot;primary->status=old_status;primary->active=old_active;
    Effects effects(*host,startup);effects.fail_work=w::PrimaryStartupWork::scenario_resources;
    const auto first=startup.start(&effects);
    check(first.status==w::PrimaryStartupStatus::unavailable&&
        first.stage==(synthetic?w::PrimaryStartupStage::remaining_resources:w::PrimaryStartupStage::scripts)&&graph.initialized());
    check(graph.descriptors().active_count()>0&&state.setup_gate==2&&!host->world().busy());
    const auto numeric_texture=startup.startup_textures().texture(0x2500);
    check(numeric_texture&&numeric_texture->width&&numeric_texture->height&&
          numeric_texture->rgba.size()==std::size_t(numeric_texture->width)*numeric_texture->height*4);
    check(!startup.startup_textures().texture(0)); // No implicit frontend producer.

    const auto started_room=primary->room;const auto started_status=primary->status;
    primary->room=255;primary->status=0;check(host->update().actor_script_terminal().command_ready());
    primary->room=started_room;primary->status=started_status;
    check(std::find(effects.work.begin(),effects.work.end(),w::PrimaryStartupWork::scene_resources)==effects.work.end());
    const auto count_before=graph.descriptors().active_count();
    host->world().scenario=35;check(host->update().scenario_events().scenario_command(11,8,{})==s::ScenarioEventStatus::completed);
    const auto task=host->update().events().slot(0,8);check(bool(task));host->world().scenario=41;
    const auto blocked=startup.start(&effects);
    check(blocked.status==w::PrimaryStartupStatus::unavailable&&blocked.stage==w::PrimaryStartupStage::scene_resources&&graph.initialized());
    check(graph.descriptors().active_count()==count_before&&host->update().events().slot(0,8).has_value()&&!host->world().busy());
    check(host->update().events().erase(task->handle)==reo::native::gameplay_tasks::Status::completed);
    const auto warm_program=std::make_shared<const s::Program>(std::vector<std::vector<std::byte>>{{std::byte{0xa},{},{},{}}});
    check(host->update().scripts().install(0,warm_program)==s::Status::completed);
    auto warm=host->update().scripts().channels()[0];warm.saved=warm.current;warm.countdown=17;warm.condition=11;
    check(host->update().scripts().restore_channel(0,warm)==s::Status::completed);
    const auto warm_refusal=startup.start(&effects);
    const auto retained=host->update().scripts().channels()[0];
    check(warm_refusal.status==w::PrimaryStartupStatus::unavailable&&warm_refusal.stage==w::PrimaryStartupStage::scripts&&
          retained.program==warm.program&&retained.current==warm.current&&retained.saved==warm.saved&&
          retained.countdown==17&&retained.condition==11&&!host->world().busy());
    warm.saved={};check(host->update().scripts().restore_channel(0,warm)==s::Status::completed);
    if(synthetic){
        // Controlled process-cold ELF BSS values; not an implicit production reset.
        state.room_variants.restore(std::array<std::uint8_t,128>{});
        auto inert=host->update().scripts().channels()[4];inert.condition=23;
        check(host->update().scripts().restore_channel(4,inert)==s::Status::completed);
        notices.host=host.get();notices.startup=&startup;notices.armed=true;
    }
    const auto completed=startup.start(&effects);notices.armed=false;
    check(graph.initialized()&&!host->world().busy());
    if(synthetic){
        check(completed.status==w::PrimaryStartupStatus::completed&&state.setup_gate==0);
        check(host->update().flags().get(s::FlagBank::scenario,123)==true&&notices.callbacks==1&&notices.guarded);
        check(host->world().navigation().bound()&&host->world().navigation().asset()&&
              !host->world().navigation().asset()->descriptors().empty());
        const auto& inert=host->update().scripts().channels()[4];
        check(!inert.program&&inert.block_index==4&&inert.condition==23);
        check(std::find(effects.work.begin(),effects.work.end(),w::PrimaryStartupWork::start_scenario_script)==effects.work.end());
        check(std::find(effects.work.begin(),effects.work.end(),w::PrimaryStartupWork::scenario_navigation)==effects.work.end());
    }else check(completed.status==w::PrimaryStartupStatus::unavailable&&state.setup_gate==2&&completed.stage==w::PrimaryStartupStage::scripts);
    check(std::find(effects.work.begin(),effects.work.end(),w::PrimaryStartupWork::scenario_scripts)==effects.work.end());
    if(synthetic){
        // Invoke the canonical room73 selector and source-ordered motion
        // publication using the retained authored EVB table and live roster.
        check(startup.room_motions().selector()==0&&startup.room_motions().room_selector(73)==68);
        const auto loaded=startup.load_room_motions();
        check(loaded.status==app::RoomMotionStatus::completed&&loaded.loaded&&!loaded.released&&loaded.selector==68);
        const auto movements=startup.motion_owner().snapshot();
        const auto cached=startup.load_room_motions();
        check(cached.status==app::RoomMotionStatus::completed&&!cached.loaded&&!cached.released&&startup.motion_owner().snapshot()==movements);
        const auto actor=host->world().primary(0);
        check(actor&&actor->model&&actor->animation&&actor->locomotion);
        actor->primary=1;actor->secondary=0;actor->phase=0;actor->subphase=0;
        actor->status=0;actor->current=actor->maximum;actor->class_marker=0;actor->previous_motion_class=0;
        actor->auxiliary_status=0;actor->locomotion->velocity={3,4,5};actor->locomotion->marker=7;
        app::SessionSceneQueryEffects query_effects(*host,*rooms);
        app::SessionActorQueries queries(*host,*rooms,query_effects);
        // Source type3/5C3FE0 projection: the admitted flag-only operation
        // writes the canonical scene-record eligibility bank exactly once.
        scene::Record policy_record;
        policy_record.authored_id=101;
        policy_record.body=s::ControlTypeThree{0,UINT16_MAX};
        policy_record.flag_policy=scene::FlagPolicyCallback{0,0,0,UINT16_MAX};
        const auto policy_result=query_effects.dispatch(host->world(),*actor,{},policy_record);
        check(policy_result&&*policy_result&&host->update().flags().get(
            s::FlagBank::scenario,101)==true);
        policy_record.authored_id=102;
        policy_record.body=s::ControlTypeThree{1,UINT16_MAX};
        policy_record.flag_policy=scene::FlagPolicyCallback{4,0,0,UINT16_MAX};
        const auto actor_flag_result=query_effects.dispatch(host->world(),*actor,{},policy_record);
        check(actor_flag_result&&*actor_flag_result&&host->update().flags().actor_flag(
            s::ActorFlagFamily::primary,0,102)==true);
        session_scene_query_effects_type4_tests(*host,query_effects,actor);
    session_scene_query_effects_type6_tests(*host,query_effects,actor);
        app::SessionPrimaryActions actions(*host,*rooms,queries);
        app::SessionBehaviorServices behavior(*host,actions);
        behavior.dispatch(w::ActionPass::secondary,1,host->world(),*actor);
        check(actor->phase==1&&actor->motion_rate==1&&actor->locomotion->marker==0&&
              actor->locomotion->velocity.x==0&&actor->locomotion->velocity.y==0&&actor->locomotion->velocity.z==0);
        for(unsigned frame=0;frame<4;++frame)
            behavior.dispatch(w::ActionPass::secondary,1,host->world(),*actor);
        check(actor->phase==10||actor->phase==11);
        check(actor->animation->model()==actor->model&&graph.animation().bound_to(host->world()));
        // Real turn selection resolves the owned motion descriptor/bank and
        // initial frame before it changes the live actor playback.
        actor->secondary=1;actor->phase=0;actor->auxiliary_status=0;
        const auto before_turn=actor->orientation[1];
        behavior.dispatch(w::ActionPass::secondary,1,host->world(),*actor);
        check(actor->phase==2&&actor->orientation[1]!=before_turn&&actor->locomotion->marker==1);
        check(actor->root_motion_delta.x==0&&actor->root_motion_delta.y==0&&actor->root_motion_delta.z==0);
        // All nine ordinary directional states use the same retained room,
        // actual floor geometry and authored character animation blocks.
        for(std::uint8_t secondary=3;secondary<=11;++secondary){
            actor->primary=1;actor->secondary=secondary;actor->phase=0;
            actor->auxiliary_status=0;actor->class_marker=0;
            behavior.dispatch(w::ActionPass::secondary,1,host->world(),*actor);
            behavior.dispatch(w::ActionPass::secondary,1,host->world(),*actor);
            check(actor->primary==1&&actor->secondary==secondary&&actor->phase==2);
            const auto& channel=actor->animation->channel(reo::native::animation::ModelBank::primary,0);
            check(channel.timing.end>0&&actor->animation->model()==actor->model);
        }
        // Source primary selection now reaches actual forward-contact and
        // scene-query owners before changing the canonical movement action.
        actor->primary=1;actor->secondary=0;actor->phase=0;actor->subphase=0;
        actor->auxiliary_status=0;actor->status=0;actor->class_marker=0;
        actor->input={};actor->input.held=1;actor->surface_kind=0;
        actor->transient_action=0;actor->transient_equipment=0;
        behavior.dispatch(w::ActionPass::primary,1,host->world(),*actor);
        check(actor->primary==1&&actor->secondary==3&&actor->phase==0);
        behavior.dispatch(w::ActionPass::secondary,1,host->world(),*actor);
        check(actor->secondary==3&&actor->phase==1);
        behavior.dispatch(w::ActionPass::secondary,1,host->world(),*actor);
        check(actor->secondary==3&&actor->phase==2);
        actor->input={};behavior.dispatch(w::ActionPass::primary,1,host->world(),*actor);
        check(actor->phase==0xff);
        // One real behavior invocation after controlled action selection:
        // retain the actual room/floor graph and use canonical application
        // services for inventory, queries, actions, activity and gauge work.
        const auto frame_room=rooms->retain(host->world().room);check(frame_room&&frame_room->current(frame_room->identity()));
        actor->room=host->world().room;actor->primary=1;actor->secondary=0;actor->phase=0;actor->subphase=0;
        actor->status=0;actor->auxiliary_status=0;actor->current=actor->maximum;actor->pending_hit=0;
        actor->class_marker=actor->previous_motion_class=0;actor->input={};state.inventory_owner=0;
        check(actor->analog_control.has_value()&&host->inventory_ui().dialogue_suppressed()==false);
        // This controlled SessionStartup host does not run OfflineApplication's
        // scene-entry finalizer. Invoke its qualified5D7D60 request-gate
        // subproducer explicitly;6DEC80 initialization leaves4BAE8D unknown.
        check(!host->inventory_ui().request_blocked().has_value());
        check(host->inventory_ui().reset_request_gate()==w::InventoryUiStatus::completed&&host->inventory_ui().request_blocked()==0);
        actor->action_elapsed=17;actor->control_elapsed=23;
        const auto action_before=actor->action_elapsed,control_before=actor->control_elapsed;
        const auto clock_before=host->update().clock().update_counter();
        w::update_behavior(host->world(),*actor,behavior,{},&frame_room->geometry().floors,&host->update(),&host->update());
        check(actor->action_elapsed==action_before+1&&actor->control_elapsed==control_before+1&&
              host->update().clock().update_counter()==clock_before&&actor->active&&actor->model&&actor->animation);
        // A room with another authored selector retires only overlay
        // families, then publishes common and active-character banks in order.
        std::uint16_t next_room{};
        for(;next_room<128;++next_room){const auto selection=startup.room_motions().room_selector(next_room);if(selection&&*selection&&*selection!=68)break;}
        check(next_room<128);host->world().room=next_room;
        const auto changed=startup.load_room_motions();
        check(changed.status==app::RoomMotionStatus::completed&&changed.released&&changed.loaded&&
              changed.selector==startup.room_motions().room_selector(next_room));
        check(startup.motion_owner().snapshot()->base_loaded()&&movements->character(0));
        const auto changed_banks=startup.motion_owner().snapshot();host->world().room=127;
        check(!startup.room_motions().room_selector(127));
        check(startup.load_room_motions().status==app::RoomMotionStatus::unavailable&&startup.motion_owner().snapshot()==changed_banks);
        host->world().room=73;
        const auto restored=startup.load_room_motions();
        check(restored.status==app::RoomMotionStatus::completed&&restored.released&&restored.loaded&&restored.selector==68);
    }
    check(startup.startup_textures().texture(0x2500)==numeric_texture);
    check(startup.close()==w::PrimaryStartupStatus::completed&&!startup.startup_textures().texture(0x2500)&&
          numeric_texture->rgba.size()==std::size_t(numeric_texture->width)*numeric_texture->height*4&&host->close()==app::SessionStatus::completed);
}
// Missing frame providers explicitly refuse rather than reporting fictitious work.
struct RefusingPhases final:u::PhaseServices {
    void run(u::Worker,u::Owner&)override{throw std::runtime_error("unavailable frame worker");}
    bool button(u::Button,u::Owner&)override{throw std::runtime_error("unavailable input");}
    bool transition_request(u::Owner&)override{throw std::runtime_error("unavailable transition");}
    void effect(u::PhaseEffect,u::Owner&,std::uint32_t)override{throw std::runtime_error("unavailable effect");}
};
struct RefusingCollisionInputs final:app::SessionCollisionInputs {
    u::BodyFrame bodies(u::Owner&)override{throw std::runtime_error("unavailable bodies");}
    u::HeightFrame secondary_heights(u::Owner&)override{throw std::runtime_error("unavailable heights");}
};
struct RefusingWalls final:w::SecondaryCollisionWalls {
    void correct(const w::actors::EntityId&,reo::native::gameplay_collision::ground::View,const w::CollisionRoom&)override{
        throw std::runtime_error("unavailable walls");
    }
};
void fresh_application(const char* archive_path,const char* catalog_path,const char* effects_path,const char* voice_path=nullptr){
    const auto base=controlled_startup_source(archive_path,true);Notifications notices;
    s::content::ScenarioArchive scenario_archive(base);const auto original_placements=scenario_archive.read_resource(41,"r041.sto");
    check(bool(original_placements));auto fault=std::make_shared<PlacementFault>();fault->source=base;fault->placement=*original_placements;
    const auto source=std::make_shared<const reo::assets::Source>("controlled-placement-fault",fault);
    std::ifstream in(effects_path,std::ios::binary);unsigned count{};in.read(reinterpret_cast<char*>(&count),4);check(count==12);
    std::array<std::vector<std::byte>,2> inputs;
    for(auto& input:inputs){unsigned size{};in.read(reinterpret_cast<char*>(&size),4);check(size&&size<10000000);input.resize(size);in.read(reinterpret_cast<char*>(input.data()),size);check(bool(in));}
    auto bank=reo::native::gameplay_effects::EffectBank::import(inputs[0],inputs[1]);
    std::ifstream catalog_in(catalog_path,std::ios::binary);std::vector<char> raw{std::istreambuf_iterator<char>(catalog_in),{}};check(!raw.empty());
    std::vector<std::byte> data(raw.size());std::memcpy(data.data(),raw.data(),raw.size());
    auto catalog=std::make_shared<const reo::native::gameplay_collision::delivery::Catalog>(reo::native::gameplay_collision::delivery::Catalog::import(data));
    app::OfflineLaunchInput input{source,profile(),std::vector<std::byte>(32),{41,73,0},1,"DEF41.NBD",
        w::HumanoidMotionAssets::initial_banks(false),bank,catalog};
    if(voice_path)input.voice_source=std::make_shared<reo::assets::Source>(voice_path);
    input.launch_record[3]=std::byte{41};input.launch_record[4]=std::byte{1};input.launch_record[5]=std::byte{1};
    input.launch_record[16]=std::byte{1};input.launch_record[24]=std::byte{1};input.launch_record[28]=std::byte{2};
    auto invalid=input;invalid.room.scenario=35;
    check(app::OfflineApplication::create_fresh(std::move(invalid),notices).status==app::OfflineApplicationStatus::invalid_input);
    app::NativeSession generic(source,profile(),notices,0);
    check(!generic.world().session().room_variants.get(73)&&!generic.world().navigation().refresh_source_ready());
    check(!generic.text_cache().initialized()&&!generic.scene_text_bank().priority().active()&&
          generic.application_lifecycle().phase()==reo::native::gameplay_session::ApplicationLifecycle::Phase::unbound);
    check(generic.close()==app::SessionStatus::completed);
    // A host that enters the native frontend cannot skip its reached frontier.
    auto frontend_launch=input;
    auto frontend_fault=std::make_shared<PlacementFault>();frontend_fault->source=base;frontend_fault->placement=*original_placements;
    frontend_launch.source=std::make_shared<const reo::assets::Source>("controlled-frontend-placement-fault",frontend_fault);
    auto probing=app::OfflineApplication::create_fresh(std::move(frontend_launch),notices);
    check(probing.status==app::OfflineApplicationStatus::completed&&bool(probing.application));
    auto& frontend_app=*probing.application;
    for(unsigned row=0;row<4;++row)check(frontend_app.startup().roster_kind(std::uint8_t(row))==0);
    check(!frontend_app.startup().roster_kind(4)&&!frontend_app.startup().roster_kind(255));
    for(unsigned character=0;character<8;++character)check(frontend_app.startup().reference_height(std::uint8_t(character))==0.f);
    check(!frontend_app.startup().reference_height(8)&&!frontend_app.startup().reference_height(255));
    const auto no_clock=frontend_app.begin_frontend();check(no_clock.status==app::FrontendStatus::unavailable&&no_clock.stage==app::FrontendStage::task_pool);
    check(frontend_app.bind_display_clock(nullptr)==app::OfflineApplicationStatus::unavailable);
#ifdef _WIN32
    HWND frontend_window=CreateWindowExA(0,"STATIC","native frontend clock test",WS_OVERLAPPEDWINDOW,
        0,0,640,448,nullptr,nullptr,GetModuleHandleA(nullptr),nullptr);
    check(frontend_window!=nullptr);ShowWindow(frontend_window,SW_SHOWNOACTIVATE);check(IsWindowVisible(frontend_window)!=0);
    reo::Input frontend_input;check(frontend_input.init());
    check(frontend_app.bind_input(frontend_input,frontend_window)==app::OfflineApplicationStatus::completed);
    check(frontend_app.bind_display_clock(nullptr)==app::OfflineApplicationStatus::unavailable);
    check(frontend_app.bind_display_clock(frontend_window)==app::OfflineApplicationStatus::completed);
    check(frontend_app.bind_display_clock(frontend_window)==app::OfflineApplicationStatus::unavailable);
    check(frontend_app.display_clock());const auto observed=frontend_app.display_clock()->counter();
    const auto next=frontend_app.display_clock()->wait_next();
    check(observed.status==reo::native::gameplay_presentation::VBlankStatus::completed&&
          next.status==reo::native::gameplay_presentation::VBlankStatus::completed&&next.count!=observed.count);
    const auto front=frontend_app.begin_frontend();check(front.status==app::FrontendStatus::unavailable&&front.stage==app::FrontendStage::common_sound);
    check(frontend_app.background()->rgb()==std::array<std::uint8_t,3>{0,0,0}&&frontend_app.background()->parameter14()==0xff000000u);
    check(frontend_app.graphics()&&frontend_app.graphics()->color()&&frontend_app.graphics()->color()->packed==0&&frontend_app.graphics()->color()->alpha==0);
    check(frontend_app.graphics()->color_mode()==reo::native::gameplay_presentation::GraphicsColorMode::normalized);
    check(frontend_app.graphics()->format_flags()&&(*frontend_app.graphics()->format_flags()&3u)==2u);
    check(frontend_app.graphics()->option_12()&&!*frontend_app.graphics()->option_12());
    check(frontend_app.graphics()->frontend_fog()&&frontend_app.graphics()->frontend_fog()->near_distance==500.f&&
          frontend_app.graphics()->frontend_fog()->far_distance==10000.f&&frontend_app.graphics()->frontend_fog()->color==std::array<std::uint8_t,3>{255,255,255});
    check(frontend_app.graphics()->frontend_draw_controls()&&frontend_app.graphics()->frontend_draw_controls()->supported_by_cpu());
    auto* frontend=frontend_app.frontend();check(frontend&&frontend->pool()&&frontend->pool()->count==256&&frontend->pool()->head==0);
    for(unsigned i=0;i<160;++i)check(frontend->pool()->next[i]==(i==159?app::FrontendColdPool::end:i+1));
    for(unsigned i=0;i<256;++i)check(frontend->pool()->free_indices[i]==i);
    const auto* retained_pool=&*frontend->pool();const auto retry_front=frontend_app.begin_frontend();
    check(retry_front.status==app::FrontendStatus::unavailable&&retry_front.stage==front.stage&&&*frontend->pool()==retained_pool);
    check(frontend_app.prepare().status==app::OfflineApplicationStatus::unavailable);
    std::shared_ptr<reo::native::adxt_output_session::Session> frontend_output;
    if(voice_path){
        auto frontend_mixer=std::make_shared<reo::native::audio_mix_tail::Mixer>(reo::native::audio_banks::v2::Config{},std::make_shared<TestBankGain>(),std::make_shared<TestMasterGain>());
        reo::native::adxt_output_session::Config config;config.bank_mix=frontend_mixer;
        frontend_output=std::make_shared<reo::native::adxt_output_session::Session>(config,std::make_shared<reo::audio_output::CallbackSlot>(),std::make_shared<UnstartedAudioProvider>());
        check(frontend_app.bind_audio(frontend_mixer,frontend_output)==app::OfflineApplicationStatus::completed);
        const auto ready=frontend_app.begin_frontend();check(ready.status==app::FrontendStatus::completed&&ready.stage==app::FrontendStage::complete);
        check(frontend->font()&&frontend->common_textures()&&frontend->common_textures()->loading_texture());
        check(frontend_app.startup().startup_textures().texture(0)==frontend->common_textures()->loading_texture());
        check(frontend_mixer->snapshot().banks.ports[0].loaded&&frontend_app.session().text_cache().initialized());
        check(frontend->advance_display_callbacks()==app::FrontendStatus::completed&&frontend->display_fade().rectangle.width==0);
        check(frontend->advance_display_callbacks()==app::FrontendStatus::completed&&frontend->display_fade().rectangle.width==640&&
              frontend->letterbox().top.width==640&&frontend->letterbox().bottom.y==384);
        check(frontend_app.frontend_display()&&frontend_app.frontend_display()->bound_to(frontend_window,*frontend_app.display_clock()));
        check(frontend_app.frontend_display()->bound_to(frontend_app.session().world())&&
              !frontend_app.frontend_display()->bound_to(generic.world())&&!frontend_app.frontend_display()->quiesce(generic.world()));
        check(frontend_app.frontend_display()->drain());
        for(unsigned i=0;i<3;++i)check(frontend_app.frontend_display()->loading_pass(*frontend->common_textures()->loading_texture()));
        check(frontend_app.frontend_display()->loading_passes()==3&&frontend_app.frontend_display()->pending_surface());
        check(frontend_app.prepare().status==app::OfflineApplicationStatus::completed);
        const auto reached=frontend_app.start(nullptr);
        check(reached.status==w::PrimaryStartupStatus::completed&&reached.stage==w::PrimaryStartupStage::completed&&reached.models_applied==2&&reached.gauges_initialized==2&&reached.resource_calls==30&&
              frontend_app.frontend_display()->loading_passes()==6&&frontend_app.frontend_display()->resource_barriers()==7&&
              !frontend_app.frontend_display()->pending_surface()&&frontend_app.session().world().session().scene_stream_stage==0&&
              frontend_app.startup().startup_textures().texture(0x2500));
        // Controlled executable roots and placement fault are explicit. Every
        // reached provider is native, including source1B0510/RN/model/audio,
        // pre-first-frame channel5 suppression and the retained late buffers.
        // This is a completed controlled startup, not an untouched-script or
        // rendered gameplay-frame claim.
        check(frontend_app.session().world().session().room_variants.get(127)==3&&
              frontend_app.session().update().flags().get(s::FlagBank::scenario,123)==true&&
              !frontend_app.session().scene_text_bank().messages_known().empty()&&frontend_app.started());
        const auto& scenario_data=frontend_app.startup().scenario_resources();
        check(scenario_data.ready()&&scenario_data.return_points()&&scenario_data.placement(2,0,0).status==app::ScenarioDataStatus::completed);
        const auto doors=scenario_data.doors();check(doors&&!doors->groups.empty()&&doors->metadata==55&&doors->admissions.size()==128);
        check(scenario_data.positions().size()==64&&std::all_of(scenario_data.positions().begin(),scenario_data.positions().end(),[](const auto& value){return !value.type&&!value.id&&!value.group&&!value.x&&!value.z;}));
        for(unsigned id=0x2600;id<=0x2604;++id)check(bool(frontend_app.startup().startup_textures().texture(id)));
        const auto installed_sound=frontend_mixer->snapshot();
        check(installed_sound.banks.ports[4].loaded&&installed_sound.banks.ports[5].loaded);
        const auto objects=frontend_app.startup().scenario_object_models();
        check(objects&&frontend_app.session().resources()->factory().static_assets()==objects&&
              frontend_app.session().resources()->static_models()==objects&&!objects->roots().empty()&&objects->nbd());
        const auto scenario_effects=frontend_app.startup().scenario_effect_bank();
        check(scenario_effects&&frontend_app.startup().scenario_effect_geometry()&&
              frontend_app.session().resources()->visuals().bank()==scenario_effects);
        check(!scenario_effects->geometry().roots().empty()&&!scenario_effects->tracks().groups().empty());
        // The source1D1030 publication is consumed by the actual retained
        // work owner; keeping asset bytes alone would not establish this path.
        reo::native::gameplay_effects::WorkRequest actual_effect;
        actual_effect.effect=36;actual_effect.position=reo::native::transform_math::Vector{1,2,3};actual_effect.child_mask=UINT32_MAX;
        const auto created_effect=frontend_app.session().resources()->visuals().create(actual_effect);
        check(created_effect.status==reo::native::gameplay_effects::WorkStatus::completed&&bool(created_effect.edit));
        auto& actual_visuals=frontend_app.session().resources()->visuals();
        check(actual_visuals.replace_bank({})&&!actual_visuals.admitted());
        check(actual_visuals.create(actual_effect).status==reo::native::gameplay_effects::WorkStatus::unavailable&&
              actual_visuals.refresh_companion()==reo::native::gameplay_effects::WorkStatus::unavailable);
        check(created_effect.edit->uniform_scale(2)); // retained work keeps its own immutable bank
        check(actual_visuals.replace_bank(scenario_effects)&&actual_visuals.admitted());
        ++frontend_positive;frontend_loading_passes+=unsigned(frontend_app.frontend_display()->loading_passes());
        frontend_resource_barriers+=unsigned(frontend_app.frontend_display()->resource_barriers());
    }
#endif
    check(frontend_app.close()==app::OfflineApplicationStatus::completed);
#ifdef _WIN32
    if(frontend_output)check(frontend_output->join()==reo::native::adxt_output_session::Status::completed);
    frontend_input.shutdown();check(DestroyWindow(frontend_window)!=0);
#endif
    auto created=app::OfflineApplication::create_fresh(std::move(input),notices);
    check(created.status==app::OfflineApplicationStatus::completed&&bool(created.application));
    auto& application=*created.application;auto& host=application.session();auto& state=host.world().session();
    std::shared_ptr<reo::native::audio_mix_tail::Mixer> audio_mixer;
    std::shared_ptr<reo::native::adxt_output_session::Session> audio_output;
    if(voice_path){
        audio_mixer=std::make_shared<reo::native::audio_mix_tail::Mixer>(reo::native::audio_banks::v2::Config{},std::make_shared<TestBankGain>(),std::make_shared<TestMasterGain>());
        reo::native::adxt_output_session::Config audio_config;audio_config.bank_mix=audio_mixer;
        audio_output=std::make_shared<reo::native::adxt_output_session::Session>(audio_config,std::make_shared<reo::audio_output::CallbackSlot>(),std::make_shared<UnstartedAudioProvider>());
        check(application.bind_audio(audio_mixer,audio_output)==app::OfflineApplicationStatus::completed);
        check(application.bind_audio(audio_mixer,audio_output)==app::OfflineApplicationStatus::unavailable);
        check(application.audio()&&application.audio()->bound_to(host.world()));
        check(application.audio()->load_common().status==app::SessionAudioLoadStatus::completed);
        check(audio_mixer->snapshot().banks.ports[0].loaded);
    }else check(application.bind_audio({}, {})==app::OfflineApplicationStatus::unavailable);
    const auto voices=application.voice_selections();
    if(voice_path)check(voices&&voices->marker(0).status==s::StreamStatus::unbound);
    else check(!voices);
    check(application.background()&&!application.background()->rgb()&&!application.background()->parameter14());
#ifdef _WIN32
    // Real process-owned window and actual host input owner. Focus may belong
    // to the test runner, so this assertion does not invent keyboard activity.
    HWND input_window=CreateWindowExA(0,"STATIC","native input and display test",WS_OVERLAPPEDWINDOW,
        0,0,640,448,nullptr,nullptr,GetModuleHandleA(nullptr),nullptr);
    check(input_window!=nullptr);
    reo::Input host_input;
    check(application.bind_input(host_input,input_window)==app::OfflineApplicationStatus::unavailable);
    check(host_input.init());
    check(application.bind_input(host_input,nullptr)==app::OfflineApplicationStatus::unavailable);
    check(application.bind_input(host_input,input_window)==app::OfflineApplicationStatus::completed);
    check(application.bind_input(host_input,input_window)==app::OfflineApplicationStatus::unavailable);
#endif
    check(host.text_cache().initialized()&&host.scene_text_bank().messages_known().empty()&&
          host.application_lifecycle().phase()==reo::native::gameplay_session::ApplicationLifecycle::Phase::preparing);
    check(state.scene_stream_stage==0);
    for(unsigned i=0;i<128;++i)check(state.room_variants.get(i)==0);
    check(host.world().navigation().refresh_source_ready()&&!host.world().navigation().bound()&&
          !host.world().navigation().initialize_cold_empty());
    check(application.start(nullptr).status==w::PrimaryStartupStatus::unavailable&&!application.started());
    RefusingPhases phases;RefusingCollisionInputs collision;RefusingWalls walls;
    check(application.bind_frame(phases,collision,walls)==app::OfflineApplicationStatus::not_started);
    const auto prepared=application.prepare();check(prepared.status==app::OfflineApplicationStatus::completed&&prepared.stage==app::OfflinePrepareStage::ready);
    check(host.resources()&&!host.resources()->initialized()&&host.world().primary(0)&&host.world().scenario==41);
    check(host.scene_text_bank().priority().active()==0&&host.scene_text_bank().messages_known().empty()&&!host.scene_text_bank().choice_text(0));
    check(application.rooms()&&!application.rooms()->objects()&&!application.rooms()->object_startup_bytes());
    check(!application.rooms()->retain(73)); // No object import before 6AD5C0.
    // Controlled test prerequisites for the still-external stream and collision producers.
    state.collision_disabled_mask=0;
    // Queue through the actual task owner before1D4020 supplies the catalog.
    // This is before the first model/script startup. No linked pass runs
    // during startup; the actual1D4020 loader can supply the queued task later.
    std::vector<std::byte> text_script(16);const std::array<std::uint32_t,4> text_commands{1,0x01000132,181,0xa};
    std::memcpy(text_script.data(),text_commands.data(),text_script.size());
    auto text_program=std::make_shared<const s::Program>(std::vector<std::vector<std::byte>>{text_script},s::DispatchProfile::offline_actor);
    check(!text_program->unsupported()&&host.timed_scene_text().request(181)==s::TimedTextStatus::completed);
    check(host.timed_scene_text().snapshot().tasks==1&&host.timed_scene_text().snapshot().active==1&&
          host.scene_text_bank().messages_known().empty());
    const auto queued_cache=host.text_cache().snapshot();check(bool(queued_cache));
    check(std::none_of(queued_cache->begin(),queued_cache->end(),[](const auto& text){return text.active;}));
    Effects effects(host,application.startup());effects.application=&application;effects.fail_work=w::PrimaryStartupWork::scenario_resources;
    const auto partial=application.start(&effects);
    check(application.background()->rgb()==std::array<std::uint8_t,3>{0,0,0}&&application.background()->parameter14()==0xff000000u&&effects.backgrounds==0);
    if(voices){check(effects.voices==0);check(voices->marker(0).status==s::StreamStatus::completed&&voices->marker(0).value==int(host.world().primary(0)->character)+1);}
#ifdef _WIN32
    check(std::find(effects.work.begin(),effects.work.end(),w::PrimaryStartupWork::controller_routes)==effects.work.end());
#endif
    const auto partial_objects=application.rooms()->objects();const auto partial_bytes=application.rooms()->object_startup_bytes();
    check(partial.status==w::PrimaryStartupStatus::unavailable&&partial.stage==w::PrimaryStartupStage::remaining_resources&&
          partial_objects&&partial_objects->initialized()&&partial_objects->objects().empty()&&partial_objects->type(0)&&partial_bytes&&
          partial_bytes->byte_b2ba==0&&partial_bytes->byte_b2b9==4&&partial_bytes->byte_b2bc==0&&fault->reads==1);
    const auto native_types=scenario_archive.read_resource(41,"obj041.dat");check(bool(native_types));
    const auto word=[&](std::size_t at){std::uint32_t v{};for(unsigned i=0;i<4;++i)v|=std::uint32_t(std::to_integer<std::uint8_t>((*native_types)[at+i]))<<(8*i);return v;};
    const auto types_at=word(8),models_at=word(12);check(word(4)>0&&types_at&&models_at);
    const auto first_flags=std::uint16_t(word(types_at+4)>>16);
    const auto first_model=std::uint16_t(std::to_integer<std::uint8_t>((*native_types)[models_at])|
        (std::uint16_t(std::to_integer<std::uint8_t>((*native_types)[models_at+1]))<<8));
    check(partial_objects->type(0)->model_slot==first_model&&partial_objects->type(0)->flags==first_flags);
    const auto original_objects=partial_objects;fault->corrupt=false;
    const auto old_room=application.rooms()->retain(73);check(old_room&&old_room->current(old_room->identity()));
    check(!host.scene_text_bank().messages_known().empty()); //1D4020 precedes the explicit1D4570 refusal.
    auto continuation=host.update().scripts().channels()[0];check(bool(continuation.saved.block!=UINT32_MAX));
    continuation.saved={};check(host.update().scripts().restore_channel(0,continuation)==s::Status::completed);
    check(state.room_variants.store(127,7));
    check(application.prepare().status==app::OfflineApplicationStatus::completed&&state.room_variants.get(127)==7&&state.scene_stream_stage==1);
    notices.host=&host;notices.startup=&application.startup();notices.armed=true;
    const auto second=application.start(&effects);notices.armed=false;
    check(second.status==w::PrimaryStartupStatus::completed&&application.started()&&state.room_variants.get(127)==3);
    check(application.background()->parameter14()==0xff000000u&&effects.backgrounds==0);
    if(voices)check(effects.voices==0&&voices->marker(0).value==int(host.world().primary(0)->character)+1);
#ifdef _WIN32
    const s::CameraProjectionContext projection{320,224,640,448,
        reo::native::transform_math::identity(),reo::native::transform_math::identity()};
    check(application.bind_presentation(input_window,projection,0,640,448)==app::OfflineApplicationStatus::completed);
    check(application.bind_presentation(input_window,projection,0,640,448)==app::OfflineApplicationStatus::presentation_already_bound);
#endif
    check(!host.scene_text_bank().messages_known().empty()&&
          host.application_lifecycle().phase()==reo::native::gameplay_session::ApplicationLifecycle::Phase::gameplay);
    // Source startup places this roster in room1. This owned-content fixture
    // installed room73 for its bounded resource profile; explicitly place the
    // controlled player there to exercise the in-room VM branch. This does not
    // claim a native room1-to-room73 transition or stock scenario progression.
    // Actual5A4F90 now owns the common prompt catalog, without a test callback.
    check(std::find(effects.work.begin(),effects.work.end(),w::PrimaryStartupWork::scenario_tables)==effects.work.end());
    const auto yes=host.scene_text_bank().choice_text(0),no=host.scene_text_bank().choice_text(1);check(yes&&no);
    check(yes->size()==8&&std::memcmp(yes->data(),"<c7>YES",8)==0);
    check(host.timed_scene_text().show_choice_prompt(181,0x12340002)==s::TimedTextStatus::completed);
    const auto choices=host.text_cache().snapshot();check(bool(choices));
    const auto has_choice=[&](std::int16_t x,std::span<const std::byte> text){return std::any_of(choices->begin(),choices->end(),[&](const auto& row){return row.active&&row.x==x&&row.y==408&&row.duration==2&&row.priority==0&&std::equal(text.begin(),text.end(),row.text.begin());});};
    check(has_choice(392,*yes)&&has_choice(464,*no));
    // Controlled caller closes this prompt before the independent task test.
    for(const auto& row:*choices)if(row.active)check(host.text_cache().erase(row.text)==s::TextCacheStatus::completed);
    check(host.world().primary(0)->active&&host.world().primary(0)->room==1);
    host.world().primary(0)->room=73;
    check(host.update().scripts().install(1,text_program)==s::Status::completed);
    const auto text_step=host.step_room_script();check(text_step.status==app::SessionStatus::completed);++script_steps;
    if(host.timed_scene_text().snapshot().tasks!=2){
        std::cerr<<"Timed text tasks="<<host.timed_scene_text().snapshot().tasks<<" script operations="<<text_step.update.script_operations<<" room="<<host.world().room<<'\n';
        for(unsigned i=0;i<3;++i)if(const auto actor=host.world().primary(i))
            std::cerr<<"party "<<i<<" active="<<unsigned(actor->active)<<" class="<<unsigned(actor->slot)<<" room="<<actor->room<<'\n';
    }
    check(host.timed_scene_text().snapshot().tasks==2);
    // Exercise the real linked callback in isolation from the still-missing
    // frame providers. This is task/application integration, not a game frame.
    namespace tasks=reo::native::gameplay_tasks;
    check(host.update().linked().run(tasks::Pass::update).status==tasks::Status::completed);
    check(host.timed_scene_text().snapshot().callback_status==s::TimedTextStatus::completed);
    const auto message=host.scene_text_bank().message_lines(181);check(message&&message->lines.size()==1);
    const auto drawn_cache=host.text_cache().snapshot();check(bool(drawn_cache));
    const auto drawn=std::find_if(drawn_cache->begin(),drawn_cache->end(),[](const auto& text){return text.active;});
    check(drawn!=drawn_cache->end()&&drawn->x==64&&drawn->y==380&&drawn->duration==60&&drawn->priority==1&&
          std::equal(message->lines[0].begin(),message->lines[0].end(),drawn->text.begin()));
    for(unsigned i=1;i<60;++i)check(host.update().linked().run(tasks::Pass::update).status==tasks::Status::completed);
    check(host.timed_scene_text().snapshot().active==0&&host.timed_scene_text().snapshot().tasks==1);
    check(host.update().linked().run(tasks::Pass::update).status==tasks::Status::completed);
    check(host.timed_scene_text().snapshot().tasks==0&&host.timed_scene_text().snapshot().callback_status==s::TimedTextStatus::completed);
    const auto retired_cache=host.text_cache().snapshot();check(bool(retired_cache));
    check(std::none_of(retired_cache->begin(),retired_cache->end(),[](const auto& text){return text.active;}));
    check(application.rooms()->objects()!=original_objects&&!old_room->current(old_room->identity())&&&old_room->geometry().objects==original_objects.get());
    check(notices.callbacks==1&&notices.guarded&&host.world().primary(0)->active&&host.world().navigation().bound());
    auto* before_grid=application.rooms()->script_commands();
    check(before_grid&&before_grid->ready(false)&&!before_grid->ready(true)&&!before_grid->ready(false,true));
    auto objects=application.rooms()->objects();const auto ids=objects->objects();
    const auto found=std::find_if(ids.begin(),ids.end(),[&](const auto& id){return objects->get(id)->external_id<32;});
    check(found!=ids.end());const auto object=*found;const auto external=objects->get(object)->external_id;
    check(objects->change_external_flags(external,0,16)&&!(objects->get(object)->control_flags&16));
    std::vector<std::byte> room_script(16);const std::array<std::uint32_t,4> commands{1,0x010000c5,external,0xa};
    std::memcpy(room_script.data(),commands.data(),room_script.size());
    auto program=std::make_shared<const s::Program>(std::vector<std::vector<std::byte>>{room_script},s::DispatchProfile::offline_actor);
    check(!program->unsupported()&&program->needs_room_objects()&&host.update().scripts().install(1,program)==s::Status::completed);
    check(host.step_room_script().status==app::SessionStatus::completed&&(objects->get(object)->control_flags&16));
    std::vector<std::byte> movement(24);const std::array<std::uint32_t,6> move_commands{1,0x020000c4,external,0,0,0xa};
    std::memcpy(movement.data(),move_commands.data(),movement.size());
    auto move_program=std::make_shared<const s::Program>(std::vector<std::vector<std::byte>>{movement},s::DispatchProfile::offline_actor);
    check(!move_program->unsupported()&&move_program->needs_room_object_lifetime()&&host.update().scripts().install(1,move_program)==s::Status::completed);
    check(host.step_room_script().status==app::SessionStatus::script_failure&&(objects->get(object)->control_flags&16));
    check(application.bind_frame(phases,collision,walls)==app::OfflineApplicationStatus::completed&&application.collision_frame());
    auto* live=application.rooms()->script_commands();check(live&&live->ready(false)&&!live->ready(true)&&!live->ready(false,true));
    check(application.bind_frame(phases,collision,walls)==app::OfflineApplicationStatus::frame_already_bound);
#ifdef _WIN32
    host_input.shutdown();
    check(application.advance({}).status==app::SessionStatus::missing_providers);
    check(host_input.init());
#endif
    bool refused=false;try{application.advance({});}catch(const std::runtime_error&){refused=true;}
    check(refused&&application.started()&&host.world().primary(0)->active);
    check(application.close()==app::OfflineApplicationStatus::completed&&application.close()==app::OfflineApplicationStatus::completed);
    check(!application.audio());
    if(audio_output)check(audio_output->join()==reo::native::adxt_output_session::Status::completed);
    check(!application.background());
    if(voices)check(voices->marker(0).status==s::StreamStatus::closed);
#ifdef _WIN32
    host_input.shutdown();check(DestroyWindow(input_window)!=0);
#endif
}
#include "fresh_startup_diagnostic.inc"
#include "session_startup_navigation_tests.inc"
}
int main(int argc,char** argv)try{if(argc==5&&std::strcmp(argv[4],"--fresh-startup-diagnostic")==0){fresh_startup_diagnostic(argv[1],argv[2],argv[3]);return 0;}check(argc==1||argc==2||argc==4||argc==5);fixtures();navigation_startup_ordering();if(argc>=2)owned(argv[1]);if(argc>=4){scenario_auxiliary_motions(argv[1]);owned_return_points(argv[1]);owned_resources(argv[1],argv[2],argv[3],false);owned_resources(argv[1],argv[2],argv[3],true);fresh_application(argv[1],argv[2],argv[3],argc==5?argv[4]:nullptr);}std::cout<<"{\"checks\":"<<checks<<",\"canonical_startups\":"<<startups<<",\"models\":"<<models<<",\"busy_guards\":"<<guards<<",\"refusals\":"<<refusals<<",\"lifetimes\":"<<lifetimes<<",\"owned_room_script_steps\":"<<script_steps<<",\"frontend_positive\":"<<frontend_positive<<",\"frontend_loading_passes\":"<<frontend_loading_passes<<",\"frontend_resource_barriers\":"<<frontend_resource_barriers<<",\"game_run\":false}\n";}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
