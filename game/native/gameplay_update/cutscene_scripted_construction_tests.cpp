#include "scripted_actor_construction.hpp"
#include "../gameplay_scenario/scenario_archive.hpp"
#include "../animation/playback.hpp"
#include "update.hpp"
#include "runtime/assets/virtual_afs.h"
#include <fstream>
#include <iostream>
#include <source_location>
#ifdef REO_CUTSCENE_SCRIPTED_ORIGINAL
#include "reference.hpp"
#include "admitted_model_rows.hpp"
#endif
namespace u=reo::native::gameplay_update;
namespace s=reo::native::gameplay_scenario;
namespace w=reo::native::gameplay_world;
namespace {
std::uint64_t checks{},original_cases{},original_spawns{},owned_scenes{},owned_spawns{},owned_unavailable{},owned_other_groups{},owned_large{},track_bindings{},busy_cases{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("Cutscene construction check "+std::to_string(at.line()));
}
template<class T>void put(std::vector<std::byte>& bytes,std::size_t at,T value){check(at<=bytes.size()&&sizeof value<=bytes.size()-at);std::memcpy(bytes.data()+at,&value,sizeof value);}
using Header=std::array<std::byte,36>;
std::shared_ptr<const s::CutsceneDescriptor> descriptor(std::span<const Header> headers){
    std::vector<std::byte> bytes(52);std::memcpy(bytes.data(),"0950",4);put(bytes,48,std::uint32_t(headers.size()));
    for(const auto& header:headers){const auto at=bytes.size();bytes.resize(at+32+36);put(bytes,at+28,1u);std::memcpy(bytes.data()+at+32,header.data(),36);}
    bytes.resize(bytes.size()+24);return s::CutsceneDescriptor::import(bytes);
}
struct Notices final:s::FlagNotifications {
    bool changed(const s::ScenarioFlagChange&)noexcept override{return true;}
    bool changed(const s::StridedFlagChange&)noexcept override{return true;}
};
void contracts(){
    std::array<Header,32> headers{};
    for(unsigned group=0;group<32;++group){const auto kind=std::int16_t(group%4),code=std::int16_t(5500),definition=std::int16_t(1);
        std::memcpy(headers[group].data()+4,&kind,2);std::memcpy(headers[group].data()+6,&code,2);std::memcpy(headers[group].data()+10,&definition,2);}
    const auto requests=u::cutscene_scripted_requests(*descriptor(headers));unsigned ordinal{};
    for(unsigned group=0;group<32;++group)if(group%4==2){check(requests[group]&&requests[group]->type==55&&requests[group]->variant==0&&requests[group]->definition_index==0&&requests[group]->model_group==ordinal++);}else check(!requests[group]);
    std::vector<std::byte> no_header(84);std::memcpy(no_header.data(),"0950",4);put(no_header,48,1u);
    // Eight count words plus remaining six count words are required.
    no_header.resize(108);bool refused=false;try{(void)u::cutscene_scripted_requests(*s::CutsceneDescriptor::import(no_header));}catch(const std::invalid_argument&){refused=true;}check(refused);
    for(unsigned variant:{2u,11u,53u}){bool bad=false;try{(void)w::File1LinkedModelProfiles{}.definition(0,std::uint16_t(variant));}catch(const std::out_of_range&){bad=true;}check(bad);}
#ifdef REO_CUTSCENE_SCRIPTED_ORIGINAL
    for(const auto& row:admitted_model_rows){const auto& value=w::File1LinkedModelProfiles{}.definition(row.type,row.variant);
        const auto& bytes=row.bytes;std::uint32_t scale;std::int16_t shadow;std::memcpy(&scale,bytes.data()+8,4);std::memcpy(&shadow,bytes.data()+14,2);
        check(value.model==bytes[0]&&value.texture==bytes[1]&&value.sound==bytes[2]&&value.construction_mode==bytes[4]&&std::bit_cast<std::uint32_t>(value.scale)==scale&&value.visibility_selector==std::bit_cast<std::int8_t>(bytes[12])&&value.shadow_enabled==std::bit_cast<std::int8_t>(bytes[13])&&value.shadow_asset==shadow);
    }
#endif
}
void owned(const char* archive,const char* manifest){
    auto source=std::make_shared<reo::assets::Source>(archive);s::content::ScenarioArchive scenes(source);w::ActorAssets assets(source);
    std::ifstream rows(manifest);check(bool(rows));unsigned scenario{},sequence{},variant{},suffix{},version{};std::uint64_t offset{};std::uint32_t length{};
    while(rows>>scenario>>sequence>>variant>>suffix>>offset>>length>>version){
        if(version!=950)continue;
        const auto input=s::read_cutscene_descriptor(scenes,std::uint16_t(scenario),std::uint8_t(sequence),std::uint8_t(variant),std::uint8_t(suffix));check(bool(input));
        w::Profile profile;profile.layouts.push_back({});w::World world(profile,std::make_shared<w::Session>());Notices notices;u::Owner owner(world,notices);u::ScriptedActorConstruction factory(world,owner.material_animations());
        std::shared_ptr<const u::PreparedCutsceneScriptedActors> prepared;
        try{prepared=factory.prepare_cutscene_scripted(*input,assets);}
        catch(const std::out_of_range& error){std::cerr<<"Unadmitted scene "<<scenario<<'/'<<sequence<<'/'<<variant<<'/'<<suffix<<": "<<error.what()<<'\n';++owned_unavailable;continue;}
        catch(const std::invalid_argument& error){std::cerr<<"Unadmitted scene "<<scenario<<'/'<<sequence<<'/'<<variant<<'/'<<suffix<<": "<<error.what()<<'\n';++owned_unavailable;continue;}
        check(prepared&&prepared->size()==input->actor_groups().size());std::vector<s::CutsceneActorBinding> bindings(prepared->size());
        std::size_t created{};const auto capacity=world.linked_models().remaining();
        for(unsigned group=0;group<prepared->size();++group){
            if(!prepared->request(group)){check(factory.create_cutscene_scripted(*prepared,group).status==u::ScriptedConstructionStatus::unavailable);++owned_other_groups;continue;}
            const auto& request=*prepared->request(group);check(request.model_group==created);
            const auto result=factory.create_cutscene_scripted(*prepared,group);check(result.status==u::ScriptedConstructionStatus::completed);const auto actor=world.resolve(result.id);
            const auto raw=input->section(input->actor_groups()[group][7]);std::uint32_t scale{},visibility{};std::memcpy(&scale,raw.data()+20,4);std::memcpy(&visibility,raw.data()+24,4);
            check(actor&&actor->scripted&&actor->scripted->scene_marker==1&&actor->scripted->scale_profile==std::uint8_t(scale));
            check(actor->slot==request.type&&actor->linked_model_variant==request.variant&&actor->model_pose_class==request.definition_index&&actor->scripted->model_group==created);
            const auto expected=std::uint8_t(scale)?w::File1LinkedModelProfiles{}.definition(actor->slot,actor->model_pose_class).scale:1.f;
            check(actor->model_scale.x==expected&&actor->model_scale.y==expected&&actor->model_scale.z==expected);
            for(unsigned part=0;part<actor->scripted->part_visibility.size();++part)check(actor->scripted->part_visibility[part]==((visibility>>part)&1));
            bindings[group]={2,result.id};++created;++owned_spawns;
        }
        check(created==prepared->scripted_count()&&world.linked_models().remaining()==capacity-created);
        check(factory.create_cutscene_scripted(*prepared,prepared->size()).status==u::ScriptedConstructionStatus::unavailable);
        // Only actual constructed kind2 groups are installed here. Primary/NPC
        // assignments remain with their unported owners, never synthetic IDs.
        auto all=input->actor_tracks(bindings);std::vector<s::CutsceneActorTrackGroup> selected;
        for(unsigned group=0;group<all.size();++group)if(prepared->request(group))selected.push_back(std::move(all[group]));
        check(owner.bind_cutscene_actor_tracks(selected)==s::CutsceneTrackStatus::completed);track_bindings+=selected.size();
        if(!busy_cases&&!selected.empty()){
            struct Speech final:s::CutsceneSpeech {
                w::World& world;u::Owner& owner;u::ScriptedActorConstruction& factory;const u::PreparedCutsceneScriptedActors& prepared;std::size_t group;bool called{};
                Speech(w::World& w,u::Owner& o,u::ScriptedActorConstruction& f,const u::PreparedCutsceneScriptedActors& p,std::size_t g):world(w),owner(o),factory(f),prepared(p),group(g){}
                bool queue_voice(const s::CutsceneSpeechRequest&)override{
                    const auto remaining=world.linked_models().remaining();check(world.busy());
                    check(factory.create_cutscene_scripted(prepared,group).status==u::ScriptedConstructionStatus::unavailable&&world.linked_models().remaining()==remaining);
                    check(owner.close()==u::Status::busy&&world.close()==w::Status::busy);called=true;return true;
                }
                bool animate_face(const s::CutsceneSpeechRequest&)override{return true;}
            } speech(world,owner,factory,*prepared,std::size_t(std::find_if(bindings.begin(),bindings.end(),[](const auto& binding){return bool(binding.actor);})-bindings.begin()));
            std::vector<std::byte> command(72);command[1]=std::byte{3};put(command,38,std::uint16_t(65535));
            s::CutsceneActorTrackGroup voice;voice.kind=2;voice.actor=selected.front().actor;voice.streams[0]=s::CutsceneActorStream::import(command);
            check(owner.bind_cutscene_actor_tracks(std::span(&voice,1))==s::CutsceneTrackStatus::completed);world.scenario=std::uint16_t(scenario);
            check(owner.run_cutscene_actor_tracks(0,0,&speech).status==s::CutsceneTrackStatus::completed&&speech.called);++busy_cases;
        }
        check(owner.clock().update_counter()==0&&owner.close()==u::Status::completed&&world.close()==w::Status::completed);
        owned_large+=input->actor_groups().size()>16;++owned_scenes;
    }
    check(rows.eof()&&owned_scenes==548&&owned_unavailable==0&&owned_spawns==729&&owned_large==17&&track_bindings==owned_spawns&&busy_cases==1);
}
}
#ifdef REO_CUTSCENE_SCRIPTED_ORIGINAL
#include "cutscene_scripted_reference_tests.inc"
#endif
int main(int argc,char** argv)try{
    contracts();
#ifdef REO_CUTSCENE_SCRIPTED_ORIGINAL
    original_requests();
#endif
    if(argc==3)owned(argv[1],argv[2]);else check(argc==1);
    std::cout<<"{\"checks\":"<<checks<<",\"original_cases\":"<<original_cases<<",\"original_spawns\":"<<original_spawns<<",\"owned_scenes\":"<<owned_scenes<<",\"owned_spawns\":"<<owned_spawns<<",\"unavailable_scenes\":"<<owned_unavailable<<",\"other_groups\":"<<owned_other_groups<<",\"large_scenes\":"<<owned_large<<",\"track_bindings\":"<<track_bindings<<",\"busy_cases\":"<<busy_cases<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
