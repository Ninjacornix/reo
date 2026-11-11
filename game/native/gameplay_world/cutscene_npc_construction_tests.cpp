#include "npc_actor_construction.hpp"
#include "../gameplay_scenario/scenario_archive.hpp"
#include "../gameplay_scenario/cutscene_actor_tracks.hpp"
#include "../animation/constraints.hpp"
#include "runtime/assets/virtual_afs.h"
#include <fstream>
#include <iostream>
#include <source_location>
#ifdef REO_CUTSCENE_NPC_ORIGINAL
#include "reference.hpp"
#endif
namespace w=reo::native::gameplay_world;
namespace s=reo::native::gameplay_scenario;
namespace a=reo::native::animation;
#ifdef REO_CUTSCENE_NPC_ORIGINAL
void compare_scene_npcs(const s::CutsceneDescriptor&,std::span<const w::actors::EntityId>,w::World&,std::int8_t);
#endif
namespace {
std::uint64_t checks{},scenes{},created_npcs{},full_scenes{},original_cases{},original_npcs{},shadow_calls{},partial_cases{},parameter_entries{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error(std::string("Scene NPC check ")+at.file_name()+":"+std::to_string(at.line()));
}
w::Profile profile(){w::Profile result;result.layouts.push_back({});return result;}
struct Graphics final:w::NpcSceneGraphics {
    w::NpcActorConstruction& factory;const w::PreparedCutsceneNpcActors& prepared;std::size_t group{};bool fail{},throwing{};unsigned calls{};
    Graphics(w::NpcActorConstruction& f,const w::PreparedCutsceneNpcActors& p):factory(f),prepared(p){}
    bool prepare_shadow(w::World& world,w::actors::EntityId id,std::uint16_t model)override{
        const auto actor=world.resolve(id);check(actor&&actor->model_variant==model&&world.busy());
        for(auto visibility:actor->scripted->part_visibility)check(visibility==1);
        const auto count=world.auxiliary_actors().remaining();check(factory.create_cutscene_npc(prepared,group,this).status==w::NpcConstructionStatus::busy&&world.auxiliary_actors().remaining()==count);
        check(world.auxiliary_actors().reset()==w::AuxiliaryStatus::busy&&world.close()==w::Status::busy);++calls;
        if(throwing)throw 17;
        return !fail;
    }
};
void owned(const char* archive,const char* manifest){
    auto source=std::make_shared<reo::assets::Source>(archive);w::ActorAssets assets(source);s::content::ScenarioArchive input(source);
    w::NpcMotionBindings banks;banks.primary=std::make_shared<a::MotionBank>();for(auto& bank:banks.style)bank=std::make_shared<a::MotionBank>();
    for(auto& bank:banks.actor_type)bank=std::make_shared<a::MotionBank>();
    std::ifstream rows(manifest);check(bool(rows));unsigned scenario{},sequence{},variant{},suffix{},version{};std::uint64_t offset{};std::uint32_t length{};
    while(rows>>scenario>>sequence>>variant>>suffix>>offset>>length>>version){
        if(version!=950)continue;
        const auto descriptor=s::read_cutscene_descriptor(input,std::uint16_t(scenario),std::uint8_t(sequence),std::uint8_t(variant),std::uint8_t(suffix));check(bool(descriptor));
        for(const auto pause:{std::int8_t(0),std::int8_t(1)}){
            w::World world(profile(),std::make_shared<w::Session>());world.paused=pause;world.room=0xabcd;w::NpcActorConstruction factory(world);
            std::shared_ptr<const w::PreparedCutsceneNpcActors> prepared;
            try{prepared=factory.prepare_cutscene_npcs(*descriptor,assets,banks);}catch(const std::exception& error){throw std::runtime_error("Scene "+std::to_string(scenario)+"/"+std::to_string(sequence)+"/"+std::to_string(variant)+"/"+std::to_string(suffix)+": "+error.what());}
            check(prepared&&prepared->size()==descriptor->actor_groups().size());
            Graphics graphics(factory,*prepared);std::vector<w::actors::EntityId> ids(prepared->size());bool full=false;
            for(unsigned group=0;group<prepared->size();++group){
                if(!prepared->request(group)){check(factory.create_cutscene_npc(*prepared,group,&graphics).status==w::NpcConstructionStatus::unavailable);continue;}
                if(!partial_cases){
                    check(pause==0);const auto count=world.auxiliary_actors().remaining();check(factory.create_cutscene_npc(*prepared,group).status==w::NpcConstructionStatus::unavailable&&world.auxiliary_actors().remaining()==count);
                    for(unsigned failure=0;failure<2;++failure){graphics.fail=failure==0;graphics.throwing=failure==1;graphics.group=group;
                        const auto result=factory.create_cutscene_npc(*prepared,group,&graphics);check(result.status==w::NpcConstructionStatus::unavailable&&result.id&&world.resolve(result.id)&&!world.busy());
                        check(world.auxiliary_actors().reset()==w::AuxiliaryStatus::completed);
                    }
                    graphics.fail=graphics.throwing=false;graphics.calls=0;++partial_cases;
                }
                graphics.group=group;const auto result=factory.create_cutscene_npc(*prepared,group,&graphics);
                if(result.status==w::NpcConstructionStatus::full){check(scenario==1&&sequence==6&&variant==0&&suffix==0&&prepared->npc_count()==11);full=true;continue;}
                check(result.status==w::NpcConstructionStatus::completed);ids[group]=result.id;const auto actor=world.resolve(result.id);check(actor&&actor->npc&&actor->scripted);
                const auto bytes=descriptor->section(descriptor->actor_groups()[group][7]);std::uint32_t scale{},mask{};std::memcpy(&scale,bytes.data()+20,4);std::memcpy(&mask,bytes.data()+24,4);
                check(actor->scripted->scale_profile==std::uint8_t(scale));const auto expected=std::uint8_t(scale)?w::npc_actor_definition(actor->model_variant).scale:1.f;
                check(actor->model_scale.x==expected&&actor->model_scale.y==expected&&actor->model_scale.z==expected);
                if(!std::uint8_t(scale)&&!pause)check(bool(actor->constraints));
                for(unsigned part=0;part<actor->scripted->part_visibility.size();++part)check(actor->scripted->part_visibility[part]==(part<32?((mask>>part)&1u):1u));
                parameter_entries+=prepared->parameters(group).size();++created_npcs;
            }
            if(full)++full_scenes;
#ifdef REO_CUTSCENE_NPC_ORIGINAL
            if(!full)compare_scene_npcs(*descriptor,ids,world,pause);
#endif
            std::vector<s::CutsceneActorBinding> bindings(ids.size());for(unsigned group=0;group<ids.size();++group)if(ids[group])bindings[group]={1,ids[group]};
            const auto all=descriptor->actor_tracks(bindings);std::vector<s::CutsceneActorTrackGroup> selected;for(unsigned group=0;group<ids.size();++group)if(ids[group])selected.push_back(all[group]);
            s::CutsceneActorTracks tracks(world);check(tracks.install(selected)==s::CutsceneTrackStatus::completed);shadow_calls+=graphics.calls;
            check(tracks.close()==s::CutsceneTrackStatus::completed&&world.close()==w::Status::completed);++scenes;
        }
    }
    check(rows.eof()&&scenes==1096&&created_npcs==490&&full_scenes==2&&partial_cases==1);
}
}
#ifdef REO_CUTSCENE_NPC_ORIGINAL
#include "cutscene_npc_reference_tests.inc"
#endif
int main(int argc,char** argv)try{
    if(argc==3)owned(argv[1],argv[2]);else check(argc==1);
    std::cout<<"{\"checks\":"<<checks<<",\"scenes\":"<<scenes<<",\"created_npcs\":"<<created_npcs<<",\"full_scenes\":"<<full_scenes<<",\"original_cases\":"<<original_cases<<",\"original_npcs\":"<<original_npcs<<",\"shadow_calls\":"<<shadow_calls<<",\"partial_cases\":"<<partial_cases<<",\"parameter_entries\":"<<parameter_entries<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
