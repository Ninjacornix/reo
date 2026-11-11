#include "npc_actor_construction.hpp"
#include "motion_profiles.hpp"
#include "../gameplay_scenario/cutscene_actor_tracks.hpp"
#include "runtime/assets/virtual_afs.h"
#include <fstream>
#include <iostream>
#include <source_location>
#ifdef REO_NPC_CONSTRUCTION_ORIGINAL
#include "reference.hpp"
#endif
namespace w=reo::native::gameplay_world;
namespace a=reo::native::animation;
namespace s=reo::native::gameplay_scenario;
#ifdef REO_NPC_CONSTRUCTION_ORIGINAL
void compare_original_npc(const w::Actor&,unsigned,unsigned);
#endif
namespace {
std::uint64_t checks{},constructors{},unavailable{},original_cases{},original_models{},original_attachments{},busy_cases{},full_cases{},retirements{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error(std::string("Native NPC construction check ")+at.file_name()+":"+std::to_string(at.line()));
}
w::Profile profile(){w::Profile value;value.layouts.push_back({});return value;}
void contracts(){
    for(unsigned id:{0u,209u,65535u}){bool refused=false;try{(void)w::npc_actor_definition(std::uint16_t(id));}catch(const std::out_of_range&){refused=true;}check(refused);}
    const auto& sample=w::npc_actor_definition(103);check(sample.id==103&&sample.health==2000&&sample.motion_style==0);
}
void owned(const char* archive,const char* manifest){
    auto source=std::make_shared<reo::assets::Source>(archive);w::ActorAssets assets(source);w::World world(profile(),std::make_shared<w::Session>());w::NpcActorConstruction factory(world);world.room=0xbeef;
    // Distinct known bank identities. The constructor only binds them; this
    // fixture does not claim motion asset selection or execute NPC animation.
    w::NpcMotionBindings bindings;bindings.primary=std::make_shared<a::MotionBank>();
    for(auto& bank:bindings.style)bank=std::make_shared<a::MotionBank>();
    for(auto& bank:bindings.actor_type)bank=std::make_shared<a::MotionBank>();
    std::ifstream rows(manifest);check(bool(rows));unsigned identity{},count{};std::shared_ptr<const w::PreparedNpcActor> retained;
    while(rows>>identity){
        ++count;
        for(unsigned definition:{0u,1u,2u,255u}){
            if(!world.auxiliary_actors().remaining()){const auto prior=world.auxiliary_actors().head();check(world.auxiliary_actors().reset()==w::AuxiliaryStatus::completed&&!world.resolve(prior));++retirements;}
            const auto before=world.auxiliary_actors().remaining();const auto attachments=world.auxiliary_actors().attachment_flags();
            std::shared_ptr<const w::PreparedNpcActor> prepared;
            try{prepared=factory.prepare(identity+0x10000u,definition+0x10000u,assets,bindings);}
            catch(const std::invalid_argument&){check(definition!=1&&(identity==72||identity==88||identity==89||identity==90||identity==119));check(world.auxiliary_actors().remaining()==before&&world.auxiliary_actors().attachment_flags()==attachments);++unavailable;continue;}
            const auto created=factory.create(*prepared);check(created.status==w::NpcConstructionStatus::completed);const auto actor=world.resolve(created.id);check(actor&&actor->npc&&actor->scripted);
            const auto& metadata=w::npc_actor_definition(std::uint16_t(identity));check(actor->active&&!actor->visible&&actor->category==1&&actor->model_variant==identity&&actor->model_pose_class==definition);
            check(actor->character==(metadata.motion_style?5:3)&&actor->ai_control==actor->character&&actor->current==metadata.health&&actor->maximum==metadata.health);
            check(actor->npc->height_parameter==metadata.height_parameter&&actor->npc->constructor_marker==1&&actor->motion_style==metadata.motion_style&&actor->motion_subtype==metadata.motion_subtype);
            check(actor->model_scale.x==metadata.scale&&actor->model_scale.y==metadata.scale&&actor->model_scale.z==metadata.scale&&actor->motion_multiplier==1&&actor->auxiliary_status==2);
            check(actor->model_asset==prepared->asset()&&actor->model&&actor->animation&&actor->animation->model()==actor->model&&actor->animation->resources_known&&actor->animation->channel_count==1);
            check(actor->animation->resources[0]==bindings.primary&&actor->animation->resources[1]==bindings.style[metadata.motion_style?1:0]&&actor->animation->resources[2]==bindings.actor_type[actor->character]);
            for(unsigned part=0;part<actor->scripted->part_visibility.size();++part)check(actor->scripted->part_visibility[part]==(definition!=1&&part==1?0:1));
            check(actor->collision.body_definition&&actor->collision.interpolation_target&&actor->contact.regions.present()&&actor->contact.regions.spheres().empty());
            const auto shape=w::File1MotionProfiles{}.shape(0,0).target;
            check(std::memcmp(&actor->collision.local_center,&shape.center,12)==0&&actor->collision.radius==shape.radius&&actor->collision.previous_radius==shape.radius&&actor->room==world.room);
#ifdef REO_NPC_CONSTRUCTION_ORIGINAL
            compare_original_npc(*actor,identity+0x10000u,definition+0x10000u);
#endif
            if(!retained)retained=prepared;
            ++constructors;
        }
    }
    check(rows.eof()&&count==130&&constructors==505&&unavailable==15&&retained);
    check(world.auxiliary_actors().reset()==w::AuxiliaryStatus::completed);
    // Actual four-slot claim owner, followed by an admitted FF/no-attachment.
    const auto head=factory.prepare(103,1,assets,bindings);
    for(unsigned index=0;index<5;++index){const auto created=factory.create(*head);check(created.status==w::NpcConstructionStatus::completed);const auto actor=world.resolve(created.id);check(actor->npc->attachment==(index<4?std::optional<std::uint8_t>(std::uint8_t(index)):std::nullopt));}
    while(world.auxiliary_actors().remaining())check(factory.create(*retained).status==w::NpcConstructionStatus::completed);
    check(factory.create(*retained).status==w::NpcConstructionStatus::full);++full_cases;
    check(world.auxiliary_actors().reset()==w::AuxiliaryStatus::completed);
    const auto actor=factory.create(*retained);check(actor.status==w::NpcConstructionStatus::completed);
    struct Speech final:s::CutsceneSpeech {
        w::World& world;w::NpcActorConstruction& factory;const w::PreparedNpcActor& prepared;bool called{};
        Speech(w::World& w,w::NpcActorConstruction& f,const w::PreparedNpcActor& p):world(w),factory(f),prepared(p){}
        bool queue_voice(const s::CutsceneSpeechRequest&)override{const auto count=world.auxiliary_actors().remaining();check(factory.create(prepared).status==w::NpcConstructionStatus::busy&&world.auxiliary_actors().remaining()==count&&world.close()==w::Status::busy);called=true;return true;}
        bool animate_face(const s::CutsceneSpeechRequest&)override{return true;}
    } speech(world,factory,*retained);
    std::vector<std::byte> event(72);event[1]=std::byte{3};const std::uint16_t end=65535;std::memcpy(event.data()+38,&end,2);
    s::CutsceneActorTracks tracks(world);s::CutsceneActorTrackGroup group;group.kind=1;group.actor=actor.id;group.streams[0]=s::CutsceneActorStream::import(event);
    check(tracks.install(std::span(&group,1))==s::CutsceneTrackStatus::completed);world.scenario=1;
    check(tracks.tick(0,0,&speech).status==s::CutsceneTrackStatus::completed&&speech.called);++busy_cases;
    auto missing=bindings;missing.primary.reset();bool refused=false;try{(void)factory.prepare(103,0,assets,missing);}catch(const std::invalid_argument&){refused=true;}check(refused);
    check(tracks.close()==s::CutsceneTrackStatus::completed&&world.close()==w::Status::completed&&factory.create(*retained).status==w::NpcConstructionStatus::closed);
}
}
#ifdef REO_NPC_CONSTRUCTION_ORIGINAL
#include "npc_actor_construction_reference_tests.inc"
#endif
int main(int argc,char** argv)try{
    contracts();if(argc==3)owned(argv[1],argv[2]);else check(argc==1);
    std::cout<<"{\"checks\":"<<checks<<",\"constructors\":"<<constructors<<",\"unavailable\":"<<unavailable<<",\"original_cases\":"<<original_cases<<",\"original_models\":"<<original_models<<",\"original_attachments\":"<<original_attachments<<",\"busy_cases\":"<<busy_cases<<",\"full_cases\":"<<full_cases<<",\"retirements\":"<<retirements<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
