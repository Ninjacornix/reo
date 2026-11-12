#include "session_startup.hpp"
#include "../gameplay_world/actor_voice_startup.hpp"
#include "../gameplay_world/actor_voice_requests.hpp"
#include "../gameplay_world/launch_roster.hpp"
#include "../gameplay_scenario/actor_voice_archive_assets.hpp"
#include "../gameplay_scenario/stream_instances.hpp"
#include "runtime/assets/virtual_afs.h"
#include <bit>
#include <chrono>
#include <cstring>
#include <iostream>
#include <source_location>
#include <stdexcept>
#include <thread>
namespace a=reo::native::gameplay_application;namespace w=reo::native::gameplay_world;namespace s=reo::native::gameplay_scenario;namespace n=reo::native;
namespace {
std::uint64_t checks{},caller_cases{},original_cases{},source_calls{},startup_bridges{},prefixes{},actual_sources{},actual_samples{};
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Actor voice caller "+std::string(at.file_name())+":"+std::to_string(at.line()));}
struct Notifications final:s::FlagNotifications {bool changed(const s::ScenarioFlagChange&)noexcept override{return true;}bool changed(const s::StridedFlagChange&)noexcept override{return true;}};
w::Profile profile(){w::Profile value;value.layouts.push_back({});return value;}
struct Event {unsigned kind{},channel{};std::int32_t first{},second{};std::uint32_t tick{};std::int32_t requested{};std::int8_t paused{};std::int32_t current{};std::uint32_t step{};friend bool operator==(const Event&,const Event&)=default;};
struct Output final:s::StreamBackend {
    s::StreamInstances& actual;s::StreamChannels& channels;std::vector<Event> events;int phase_value{};unsigned slot{};std::uint32_t tick=1234;
    Output(s::StreamInstances& backend,s::StreamChannels& state):actual(backend),channels(state){events.reserve(32);}
    void event(unsigned kind,unsigned channel,std::int32_t first=0,std::int32_t second=0){const auto& state=channels.snapshot();events.push_back({kind,channel,first,second,tick,state.requested_ids[channel],state.channels[channel].paused,state.channels[channel].current,std::bit_cast<std::uint32_t>(state.channels[channel].step)});}
    s::StreamValue phase(std::uint8_t channel)noexcept override{event(0,channel);return{s::StreamStatus::completed,phase_value};}
    s::StreamStatus start(std::uint8_t channel,s::StreamRequest request,std::uint32_t value)noexcept override{check(value==tick);const auto marker=actual.actor_archive_marker(std::uint8_t(slot));check(marker.status==s::StreamStatus::completed&&marker.value>0&&request.archive==unsigned(400+marker.value));event(1,channel,std::int32_t(slot+5),request.member);return s::StreamStatus::completed;}
    s::StreamStatus stop(std::uint8_t channel)noexcept override{event(2,channel);return s::StreamStatus::completed;}
    s::StreamStatus pause(std::uint8_t channel,bool paused,std::uint32_t value)noexcept override{check(value==tick);event(3,channel,paused?1:0);return s::StreamStatus::completed;}
    s::StreamStatus attenuation(std::uint8_t channel,std::int32_t value)noexcept override{event(4,channel,value);return s::StreamStatus::completed;}
    s::StreamStatus service(std::uint32_t)noexcept override{return s::StreamStatus::unbound;}
    s::StreamValue actor_archive_marker(std::uint8_t value)noexcept override{return actual.actor_archive_marker(value);}
    s::StreamSourceResult actor_voice_source(std::uint8_t value,std::int32_t member)noexcept override{return actual.actor_voice_source(value,member);}
};
struct Remaining final:w::PrimaryStartupEffects {
    w::World& world;bool stop_background=true;unsigned forbidden_voice{};
    explicit Remaining(w::World& value):world(value){}
    bool bound_to(const w::World& value)const noexcept override{return &value==&world;}
    w::PrimaryStartupStatus voice_archive(std::uint8_t,std::uint8_t)override{++forbidden_voice;return w::PrimaryStartupStatus::unavailable;}
    w::PrimaryStartupStatus background(std::uint8_t)override{return stop_background?w::PrimaryStartupStatus::unavailable:w::PrimaryStartupStatus::completed;}
    w::PrimaryStartupStatus initialize_stream_stage()override{return w::PrimaryStartupStatus::completed;}
    w::PrimaryStartupStatus run(w::PrimaryStartupWork)override{return w::PrimaryStartupStatus::completed;}
    w::PrimaryStartupStatus actor_resources(w::PrimaryStartupWork,const w::actors::EntityId&)override{return w::PrimaryStartupStatus::completed;}
    std::optional<std::int8_t> roster_kind(std::uint8_t)const noexcept override{return 0;}
    std::optional<float> reference_height(std::uint8_t)const noexcept override{return 0.f;}
};
template<class F>struct Operation final:n::adxt_control_owner::Operation {F callback;explicit Operation(F f):callback(std::move(f)){}void run(n::adxt_instances::Instances& players)noexcept override{callback(players);}};
}
#ifdef REO_ACTOR_VOICE_CALLER_ORIGINAL
#include "actor_voice_caller_reference.inc"
#else
void begin_original(const w::Actor&,const s::StreamChannelSnapshot&,Output&,int){}
void compare_original(const s::StreamChannelSnapshot&,const Output&,const w::ActorVoiceResult&){}
#endif
int main(int argc,char** argv)try{
    check(argc==3);auto models=std::make_shared<const reo::assets::Source>(argv[1]);auto audio=std::make_shared<reo::assets::Source>(argv[2]);Notifications notifications;
    a::NativeSession session(models,profile(),notifications);a::SessionStartup startup(session,models,w::HumanoidMotionAssets::initial_banks(false));check(startup.initialize_records().status==w::PrimaryRecordsStatus::completed);
    n::gameplay_session::LaunchRoster roster;roster.scenario=1;roster.count=5;for(unsigned i=0;i<5;++i)roster.actors[i].character=std::uint8_t(i);
    check(w::apply_launch_roster(session.world(),session.update().action_choices(),roster));session.world().session().asset_loading_mode=1;session.world().session().scene_stream_stage=0;
    s::ActorVoiceArchiveAssets assets(audio);auto catalog=std::make_shared<s::StreamAssetCatalog>();check(catalog->add_actor_voice_archives(assets));catalog->seal();
    std::array<std::uint32_t,1000> words{};words.front()=256;const auto table=n::adxt_attenuation::Table::from_words(words);check(table.status==n::adxt_attenuation::Status::completed);
    std::array<s::StreamInstanceConfig,3> config;for(unsigned i=0;i<3;++i){config[i].construction={i==2?1u:2u,{i,i,i,i},table.table};config[i].player.decoder.channels=config[i].construction.channels;}
    auto owner=std::make_shared<n::adxt_control_owner::Owner>(n::adxt_instances::control::Config{{3},{}});auto opened=s::StreamInstances::create(owner,config,catalog,{0,1,2});check(opened.status==s::StreamStatus::completed&&opened.value);auto backend=std::move(opened.value);
    Remaining remaining(session.world());w::ActorVoiceStartupEffects effects(session.world(),*backend,remaining);w::PrimaryStartupReport busy;
    Operation nested([&](auto&){busy=startup.start(&effects);});check(owner->run(nested)==n::adxt_control_owner::Admission::accepted&&busy.status==w::PrimaryStartupStatus::busy&&busy.stage==w::PrimaryStartupStage::voice_archives&&busy.voice_requests==0);++prefixes;
    const auto prefix=startup.start(&effects);check(prefix.status==w::PrimaryStartupStatus::unavailable&&prefix.stage==w::PrimaryStartupStage::background&&prefix.voice_requests==5&&prefix.slots_assigned==0&&remaining.forbidden_voice==0);++prefixes;
    for(unsigned i=0;i<8;++i){check(session.world().primary(i)->slot==0&&!session.world().primary(i)->model);if(i<5)check(backend->actor_archive_marker(std::uint8_t(i)).value==int(i+1));}
    remaining.stop_background=false;const auto completed=startup.start(&effects);check(completed.status==w::PrimaryStartupStatus::completed&&completed.models_applied==5&&remaining.forbidden_voice==0);++startup_bridges;
    n::gameplay_audio::SpatialContext spatial;for(unsigned i=0;i<4;++i)spatial.world_to_screen[i][i]=1.f;
    std::optional<std::uint32_t> tick=1234;s::StreamChannels channels(s::file1_stream_gain_curve());Output output(*backend,channels);w::ActorVoiceRequests requests(session.world(),channels,output,spatial,tick);
    check(requests.bound_to(session.world()));
    for(unsigned seed=0;seed<192;++seed){
        const unsigned slot=seed%5,character=(seed/5)%8;const auto actor=session.world().primary(slot);output.slot=slot;output.phase_value=int((seed/8)%6);output.events.clear();
        check(backend->activate_actor_archive(std::uint8_t(slot),std::uint8_t(character))==s::StreamStatus::completed);
        if(seed%17==0)check(backend->activate_actor_archive(std::uint8_t(slot),8)==s::StreamStatus::completed);
        const std::array<float,6> positions{0,50,100,400,4750,5000};actor->position={positions[seed%6],0,0};
        s::StreamChannelSnapshot state;for(unsigned i=0;i<3;++i){auto& channel=state.channels[i];channel.type=i==2?1:2;channel.maximum=(seed&4)?63:127;channel.current=(seed&8)?7:111;channel.level=float(channel.current);channel.target=17;channel.step=0.25f;channel.paused=(seed&2)?-1:0;state.requested_ids[i]=(seed&1)?7:42;}
        check(channels.restore(state)==s::StreamStatus::completed);const int member=seed%19==0?-1:7;
        begin_original(*actor,state,output,member);const auto result=requests.request(session.world().identity(slot),member);check(result.status==s::StreamStatus::completed);compare_original(channels.snapshot(),output,result);++caller_cases;
    }
    const auto actor=session.world().primary(0);check(backend->activate_actor_archive(0,0)==s::StreamStatus::completed);output.slot=0;output.phase_value=0;output.events.clear();tick.reset();const auto before=channels.snapshot().requested_ids;
    check(requests.request(session.world().identity(0),7).status==s::StreamStatus::unbound&&channels.snapshot().requested_ids==before&&output.events.size()==1);++prefixes;
    check(requests.request({},-1).original_return==-1&&requests.request({},-1).status==s::StreamStatus::completed);
    actor->category=2;check(requests.request(session.world().identity(0),7).status==s::StreamStatus::unsupported_profile);actor->category=0;
    for(unsigned i=0;i<3;++i)check(!backend->inspect(std::uint8_t(i)).source);
    // The concrete consumer uses the same canonical backend and verified owned
    // member. Its source worker/decoder run without opening an audio device.
    tick=1234;actor->position={0,0,0};s::StreamChannelSnapshot fresh;
    for(unsigned i=0;i<3;++i){fresh.channels[i].type=i==2?1:2;fresh.channels[i].maximum=127;fresh.channels[i].current=127;fresh.channels[i].level=127;fresh.requested_ids[i]=-1;}
    check(channels.restore(fresh)==s::StreamStatus::completed);
    w::ActorVoiceRequests concrete(session.world(),channels,*backend,spatial,tick);
    const auto submitted=concrete.request(session.world().identity(0),7);check(s::stream_accepted(submitted.status)&&submitted.original_return==0);++actual_sources;
    const auto deadline=std::chrono::steady_clock::now()+std::chrono::seconds(15);
    for(;;){const auto status=backend->service(*tick);if(!s::stream_accepted(status))throw std::runtime_error("Owned actor voice service refused");const auto observed=backend->inspect(2);if(observed.source&&observed.source->fault)throw std::runtime_error("Owned actor voice decoder fault");
        if(observed.source&&observed.source->configured&&observed.source->copied_samples){actual_samples=observed.source->copied_samples;break;}
        if(std::chrono::steady_clock::now()>=deadline)throw std::runtime_error("Owned actor voice source did not decode");
        std::this_thread::yield();}
    check(backend->actor_archive_marker(0).value==1&&channels.snapshot().requested_ids[2]==7&&channels.snapshot().channels[2].paused==0);
    check(s::stream_accepted(backend->stop(2)));
    check(startup.close()==w::PrimaryStartupStatus::completed&&session.close()==a::SessionStatus::completed&&backend->close()==s::StreamStatus::completed);check(requests.request({},-1).status==s::StreamStatus::closed);
    std::cout<<"{\"checks\":"<<checks<<",\"complete_native_caller_cases\":"<<caller_cases<<",\"complete_original_caller_cases\":"<<original_cases<<",\"source_calls\":"<<source_calls<<",\"canonical_startup_bridges\":"<<startup_bridges<<",\"refusal_prefixes\":"<<prefixes<<",\"decoder_sources_started\":"<<actual_sources<<",\"actual_copied_samples\":"<<actual_samples<<",\"audio_device_opened\":false,\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
