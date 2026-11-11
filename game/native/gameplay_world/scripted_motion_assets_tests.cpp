#include "scripted_motion_assets.hpp"
#include "actor_assets.hpp"
#include "../gameplay_update/scripted_actor_construction.hpp"
#include "../gameplay_update/update.hpp"
#include "../gameplay_update/linked_model_workers.hpp"
#include "../gameplay_scenario/cutscene_actor_commands.hpp"
#include "runtime/assets/virtual_afs.h"
#include <fstream>
#include <iostream>
#include <source_location>
#include <sstream>
#ifdef REO_SCRIPTED_MOTION_ORIGINAL
#include "reference.hpp"
#endif

namespace w=reo::native::gameplay_world;
namespace a=reo::native::animation;
namespace u=reo::native::gameplay_update;
namespace {
std::uint64_t checks{},owned_members{},owned_blocks{},consumer_updates{},original_loader_cases{},ordinary_model_workers{},authored_command_consumers{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("Scripted motion asset check line "+std::to_string(at.line()));
}
template<class T>void put(std::vector<std::uint8_t>& bytes,std::size_t at,T value){
    if(at>bytes.size()||sizeof value>bytes.size()-at)throw std::runtime_error("Fixture write bound");
    std::memcpy(bytes.data()+at,&value,sizeof value);
}
using File=std::pair<std::string,std::vector<std::uint8_t>>;
std::vector<std::uint8_t> afs(std::vector<File> files){
    const auto aligned=[](std::size_t n){return(n+2047)&~std::size_t(2047);};
    const auto names=16+8*files.size();std::vector<std::uint8_t> bytes(aligned(names+48*files.size()));
    std::memcpy(bytes.data(),"AFS\0",4);put(bytes,4,std::uint32_t(files.size()));
    put(bytes,8+8*files.size(),std::uint32_t(names));put(bytes,12+8*files.size(),std::uint32_t(48*files.size()));
    for(std::size_t i=0;i<files.size();++i){
        const auto& [name,payload]=files[i];check(name.size()<32);
        std::memcpy(bytes.data()+names+48*i,name.data(),name.size());
        const auto start=bytes.size();bytes.resize(aligned(start+payload.size()));
        put(bytes,8+8*i,std::uint32_t(start));put(bytes,12+8*i,std::uint32_t(payload.size()));
        if(!payload.empty())std::memcpy(bytes.data()+start,payload.data(),payload.size());
    }
    return bytes;
}
struct Memory final:reo::assets::PositionedSource {
    const std::vector<std::uint8_t> bytes;
    mutable std::optional<std::uint64_t> failure;
    mutable std::vector<std::uint64_t> reads;
    explicit Memory(std::vector<std::uint8_t> value):bytes(std::move(value)){}
    std::uint64_t size()const noexcept override{return bytes.size();}
    std::size_t read(std::uint64_t offset,std::size_t n,void* out)const override{
        reads.push_back(offset);if(failure==offset)throw std::runtime_error("Injected source read failure");
        if(offset>bytes.size()||n>bytes.size()-offset)throw std::runtime_error("Fixture read bound");
        std::memcpy(out,bytes.data()+offset,n);return n;
    }
};
std::vector<std::uint8_t> raw_bank(bool present=true){
    // Structurally valid raw bank with an empty twenty-byte clip; no playback
    // semantics are inferred from this controlled loader-only input.
    std::vector<std::uint8_t> bytes(48);put(bytes,0,0u);put(bytes,4,1u);
    put(bytes,8,1u);put(bytes,12,16u);put(bytes,16,present?28u:0xffffffffu);
    put(bytes,28+8,20u);return bytes;
}
template<class Action>void refused(Action action){bool caught{};try{action();}catch(const std::exception&){caught=true;}check(caught);}
void contracts(){
    std::vector<File> files(1342,{"duplicate.bin",{}});
    files[759]={"d02.bin",raw_bank()};files[789]={"hd02.bin",raw_bank()};
    const auto memory=std::make_shared<Memory>(afs({{"romdata_usa.afs",afs(files)}}));
    const auto source=std::make_shared<reo::assets::Source>("motion fixture",memory);
    w::ScriptedMotionAssets assets(source);
    const auto first=assets.read(1,2);
    check(first.status[0]==w::ScriptedMotionLoadStatus::loaded&&first.status[1]==w::ScriptedMotionLoadStatus::not_found&&first.status[2]==w::ScriptedMotionLoadStatus::loaded);
    check(first.members[0]==759&&first.members[2]==789&&!first.members[1]);
    check(first.banks.mode_one&&first.banks.other_modes&&!first.banks.track_two);
    check(first.banks.mode_one!=first.banks.other_modes);
    const auto old_block=first.banks.mode_one->find(0,0);check(bool(old_block));
    memory->reads.clear();const auto absent=assets.read(65535,65535,first.banks);
    check(absent.banks.mode_one==first.banks.mode_one&&absent.banks.other_modes==first.banks.other_modes&&memory->reads.empty());
    // Body I/O failure preserves the old body and still reads the head.
    const auto directory=reo::assets::table(*source,0,source->size);const auto common=reo::assets::table(*source,directory.entries[0].offset,directory.entries[0].size);
    memory->failure=std::uint64_t(directory.entries[0].offset)+common.entries[759].offset;
    const auto failed=assets.read(1,2,first.banks);
    check(failed.status[0]==w::ScriptedMotionLoadStatus::source_failure&&failed.status[2]==w::ScriptedMotionLoadStatus::loaded);
    check(failed.banks.mode_one==first.banks.mode_one&&failed.banks.other_modes!=first.banks.other_modes);
    memory->failure.reset();
    // A successful file with an absent row retains that prior block, while a
    // malformed file preserves the whole old bank and does not stop the head.
    files[759].second=raw_bank(false);
    const auto sparse_source=std::make_shared<reo::assets::Source>("sparse replacement",std::make_shared<Memory>(afs({{"romdata_usa.afs",afs(files)}})));
    const auto retained=w::ScriptedMotionAssets(sparse_source).read(1,2,first.banks);
    check(retained.status[0]==w::ScriptedMotionLoadStatus::loaded&&retained.banks.mode_one!=first.banks.mode_one&&retained.banks.mode_one->find(0,0)==old_block);
    check(first.banks.mode_one->find(0,0)==old_block);
    files[759].second.resize(3);
    const auto broken_source=std::make_shared<reo::assets::Source>("malformed replacement",std::make_shared<Memory>(afs({{"romdata_usa.afs",afs(files)}})));
    const auto broken=w::ScriptedMotionAssets(broken_source).read(1,2,first.banks);
    check(broken.status[0]==w::ScriptedMotionLoadStatus::invalid_asset&&broken.status[2]==w::ScriptedMotionLoadStatus::loaded&&broken.banks.mode_one==first.banks.mode_one);
    refused([]{w::ScriptedMotionAssets invalid({});});
    refused([&]{w::ScriptedMotionAssets invalid(std::make_shared<reo::assets::Source>("wrong ROM profile",std::make_shared<Memory>(afs({{"romdata_usa.afs",afs({{"d02.bin",raw_bank()}})}}))));});
    refused([&]{w::ScriptedMotionAssets invalid(std::make_shared<reo::assets::Source>("missing ROM",std::make_shared<Memory>(afs({{"other.afs",afs(files)}}))));});
    refused([&]{w::ScriptedMotionAssets invalid(std::make_shared<reo::assets::Source>("ambiguous ROM",std::make_shared<Memory>(afs({{"romdata_usa.afs",afs(files)},{"ROMDATA_USA.AFS",afs(files)}}))));});
}
struct Notifications final:reo::native::gameplay_scenario::FlagNotifications {
    bool changed(const reo::native::gameplay_scenario::ScenarioFlagChange&)noexcept override{std::terminate();}
    bool changed(const reo::native::gameplay_scenario::StridedFlagChange&)noexcept override{std::terminate();}
};
struct Remaining final:u::PhaseServices {
    std::vector<u::Worker> stages;
    unsigned buttons{},transitions{},effects{};
    void run(u::Worker stage,u::Owner&)override{check(stage!=u::Worker::scenario_model_poses);stages.push_back(stage);}
    bool button(u::Button,u::Owner&)override{++buttons;return false;}
    bool transition_request(u::Owner&)override{++transitions;return false;}
    void effect(u::PhaseEffect,u::Owner&,std::uint32_t)override{++effects;}
};
struct EmptyActors final:w::Services {
    void begin_offline_frame(w::World&)override{}
    void run(w::Stage,w::World&,w::Actor&)override{std::terminate();}
    bool remote_motion(w::World&,w::Actor&)override{std::terminate();}
    bool find_grid(w::World&,w::Actor&,std::int8_t&)override{std::terminate();}
    void switch_grid(w::World&,std::int32_t,std::int32_t)override{std::terminate();}
    float grid_response(w::World&,std::uint8_t)override{std::terminate();}
};
void worker_contracts(){
    w::Profile profile;profile.layouts.push_back({});w::World world(profile,std::make_shared<w::Session>()),foreign(profile,std::make_shared<w::Session>());
    Notifications notices;u::Owner owner(world,notices),other(foreign,notices);Remaining remaining;
    const auto floors=std::make_shared<const reo::native::gameplay_collision::response::Grid>();
    refused([&]{u::LinkedModelWorkers invalid(world,remaining,{});});
    u::LinkedModelWorkers workers(world,remaining,floors);
    refused([&]{u::LinkedModelWorkers duplicate(world,remaining,floors);});
    check(workers.progress()==u::LinkedModelProgress::never_run&&!workers.last_models());
    refused([&]{workers.run(u::Worker::scenario_model_poses,other);});
    workers.run(u::Worker::scenario_model_poses,owner);
    check(workers.progress()==u::LinkedModelProgress::completed&&workers.last_models()->visited==0&&remaining.stages.empty());
    workers.run(u::Worker::reset_entity_queues,owner);
    check(workers.progress()==u::LinkedModelProgress::never_run&&!workers.last_models()&&remaining.stages.size()==1);
    check(!workers.button(u::Button::primary,owner)&&!workers.transition_request(owner));
    workers.effect(u::PhaseEffect::finish_request,owner,123);check(remaining.buttons==1&&remaining.transitions==1&&remaining.effects==1);
    const auto stale=world.linked_models().allocate(true).id;
    world.resolve(stale)->visible=true;
    refused([&]{workers.run(u::Worker::scenario_model_poses,owner);});
    check(workers.progress()==u::LinkedModelProgress::failed&&!workers.last_models());
    check(world.linked_models().reset()==w::LinkedStatus::completed);
    refused([&]{workers.select_root(stale);});
    check(workers.close()==u::Status::completed);refused([&]{workers.run(u::Worker::scenario_model_poses,owner);});
    refused([&]{workers.select_root({});});
    u::LinkedModelWorkers replacement(world,remaining,floors);
    replacement.run(u::Worker::scenario_model_poses,owner);
    check(replacement.progress()==u::LinkedModelProgress::completed);
}
void owned(const char* archive,const char* manifest){
    const auto source=std::make_shared<reo::assets::Source>(archive);w::ScriptedMotionAssets assets(source);
    std::ifstream rows(manifest),raw(archive,std::ios::binary);check(bool(rows)&&bool(raw));
    unsigned scenario{},clip{},kind{},member{};std::uint64_t offset{},length{};
    while(rows>>scenario>>clip>>kind>>member>>offset>>length){
        const auto loaded=assets.read(std::uint16_t(scenario),std::uint16_t(clip));
        check(loaded.status[kind]==w::ScriptedMotionLoadStatus::loaded&&loaded.members[kind]==member);
        const auto bank=kind==0?loaded.banks.mode_one:kind==1?loaded.banks.track_two:loaded.banks.other_modes;
        check(bool(bank));std::vector<std::uint8_t> expected(length);
        raw.seekg(std::streamoff(offset));raw.read(reinterpret_cast<char*>(expected.data()),std::streamsize(length));check(bool(raw));
        for(const auto& block:bank->slots())if(block){
            check(block->source_offset()<=length&&block->bytes().size()<=length-block->source_offset());
            check(std::memcmp(block->bytes().data(),expected.data()+block->source_offset(),block->bytes().size())==0);
            check(block->source_identity().find("ROM member "+std::to_string(member)+":")!=std::string::npos);
            ++owned_blocks;
        }
        ++owned_members;
    }
    check(rows.eof()&&owned_members==89);
    const auto loaded=assets.read(1,0);check(loaded.status[0]==w::ScriptedMotionLoadStatus::loaded);
    std::shared_ptr<const a::MotionBlock> selected;unsigned key{};
    for(;key<100;++key){selected=loaded.banks.mode_one->find(key,0);if(selected)break;}
    check(bool(selected));const auto node_count=selected->clip()->tracks().size();
    w::Profile profile;profile.layouts.push_back({});w::World world(profile,std::make_shared<w::Session>());
    Notifications notices;u::Owner owner(world,notices);u::ScriptedActorConstruction constructor(world,owner.material_animations());
    w::ActorAssets models(source);std::shared_ptr<const u::PreparedScriptedActor> prepared;
    for(unsigned type=0;type<62&&!prepared;++type)for(unsigned variant=0;variant<32&&!prepared;++variant){
        try{const auto candidate=constructor.prepare({0,type,variant,0},models);
            if(candidate->asset()&&candidate->asset()->skeleton()&&candidate->asset()->skeleton()->nodes().size()==node_count)prepared=candidate;
        }catch(const std::out_of_range&){}catch(const std::invalid_argument&){}
    }
    check(bool(prepared));const auto created=constructor.create(*prepared);check(created.status==u::ScriptedConstructionStatus::completed);
    const auto actor=world.resolve(created.id);world.paused=1;
    std::array<std::byte,36> event{};
    const auto write_event=[&](unsigned at,auto value){std::memcpy(event.data()+at,&value,sizeof value);};
    event[1]=std::byte{0};write_event(4,10.f);write_event(8,20.f);write_event(12,30.f);
    check(reo::native::gameplay_scenario::apply_cutscene_actor_command(world,created.id,event)==reo::native::gameplay_scenario::CutsceneCommandStatus::completed);++authored_command_consumers;
    event.fill(std::byte{});event[1]=std::byte{1};write_event(4,1u);write_event(8,key);
    check(reo::native::gameplay_scenario::apply_cutscene_actor_command(world,created.id,event)==reo::native::gameplay_scenario::CutsceneCommandStatus::completed);++authored_command_consumers;
    event.fill(std::byte{});event[1]=std::byte{6};write_event(4,2.f);write_event(24,2u);
    check(reo::native::gameplay_scenario::apply_cutscene_actor_command(world,created.id,event)==reo::native::gameplay_scenario::CutsceneCommandStatus::completed);++authored_command_consumers;
    const auto floors=std::make_shared<const reo::native::gameplay_collision::response::Grid>();
    check(owner.bind_linked_actors(loaded.banks,floors)==u::Status::completed);
    Remaining remaining;u::LinkedModelWorkers poses(world,remaining,floors);
    for(unsigned tick=0;tick<16;++tick){const auto result=owner.run_linked_actor_updates();
        check(result.status==w::LinkedUpdateStatus::completed&&result.called==1&&actor->phase==1&&actor->visible);
        poses.run(u::Worker::scenario_model_poses,owner);
        check(poses.progress()==u::LinkedModelProgress::completed&&poses.last_models()->updated==1);
        check(actor->animation->resources[0]==loaded.banks.mode_one&&actor->model->retain()&&actor->model->retain()->joints.size()==node_count);
        ++consumer_updates;
    }
    check(actor->scripted->movement_remaining==0&&actor->scripted->forward_step==0&&!(actor->scripted->request_flags&2));
    const auto idle=std::make_shared<const reo::native::gameplay_scenario::Program>(std::vector<std::vector<std::byte>>{{std::byte{1},{},{},{},std::byte{0xa},{},{},{}}});
    check(owner.scripts().install(0,idle)==reo::native::gameplay_scenario::Status::completed&&owner.scripts().install(1,idle)==reo::native::gameplay_scenario::Status::completed);
    EmptyActors no_primary;world.mode=1;world.scenario=0;
    check(owner.initialize_completion_statistics()==reo::native::gameplay_events::StatisticsStatus::completed);
    // The actual ordinary worker pause gate resets evidence but skips this pass.
    check(owner.run_workers(poses,no_primary).status==u::Status::completed);
    check(poses.progress()==u::LinkedModelProgress::never_run&&!poses.last_models());
    world.paused=0;const auto ordinary=owner.run_workers(poses,no_primary);
    check(ordinary.status==u::Status::completed&&poses.progress()==u::LinkedModelProgress::completed&&poses.last_models()->updated==1);
    ++ordinary_model_workers;
    check(owner.close()==u::Status::completed&&world.close()==w::Status::completed);
}
}
#ifdef REO_SCRIPTED_MOTION_ORIGINAL
#include "scripted_motion_loader_reference_tests.inc"
#endif
int main(int argc,char** argv)try{
    contracts();worker_contracts();if(argc==3)owned(argv[1],argv[2]);else check(argc==1);
#ifdef REO_SCRIPTED_MOTION_ORIGINAL
    original_loader_routes();
#endif
    std::cout<<"{\"checks\":"<<checks<<",\"owned_members\":"<<owned_members<<",\"owned_blocks\":"<<owned_blocks<<",\"consumer_updates\":"<<consumer_updates<<",\"original_loader_cases\":"<<original_loader_cases<<",\"ordinary_model_workers\":"<<ordinary_model_workers<<",\"authored_command_consumers\":"<<authored_command_consumers<<"}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
