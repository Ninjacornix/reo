#include "primary_actor_initialization.hpp"
#include "humanoid_motion_owner.hpp"
#include "runtime/assets/virtual_afs.h"
#include <bit>
#include <cstring>
#include <iostream>
#include <source_location>
#include <stdexcept>
#ifdef REO_PRIMARY_INITIALIZATION_ORIGINAL
#include "primary_reference.hpp"
#endif
namespace g=reo::native::gameplay_world;
namespace a=reo::native::animation;
namespace {
std::uint64_t checks{},initializations{},restores{},setters{},refusals{},original_calls{},constraints{},bank_publications{};
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Native primary initialization check "+std::to_string(at.line()));}
g::Profile profile(){g::Profile result;result.layouts.push_back({});return result;}
void compare_original(g::World&,const g::Actor&,const g::Actor&,unsigned,bool);
void compare_setter(const g::Actor&,unsigned,unsigned);
void contracts(){
    g::World world(profile(),std::make_shared<g::Session>());
    check(g::restore_primary_slot(world,{})==g::PrimaryInitializationStatus::unavailable&&!g::select_primary_appearance(world,{},0,0));++refusals;
    bool failed=false;try{(void)g::primary_actor_default(255);}catch(const std::out_of_range&){failed=true;}check(failed);++refusals;
    check(world.close()==g::Status::completed&&g::restore_primary_slot(world,{})==g::PrimaryInitializationStatus::closed);
}
void owned(const char* archive){
    auto source=std::make_shared<reo::assets::Source>(archive);g::ActorAssets models(source);g::HumanoidMotionAssets motions(source);
    const auto base=motions.base();const std::array<std::uint8_t,8> characters{0,1,2,3,4,5,6,7};const auto banks=motions.overlay(1,characters,*base);
    check(banks->bank({g::HumanoidMotionFamily::primary,0})&&banks->bank({g::HumanoidMotionFamily::primary,0})->track_count()==0&&banks->bank({g::HumanoidMotionFamily::primary,0})!=banks->scripted().mode_one);
    for(unsigned character=0;character<8;++character)for(unsigned slot=0;slot<8;++slot)for(unsigned pause=0;pause<256;++pause)for(unsigned model_class:{0u,1u}){
        g::World world(profile(),std::make_shared<g::Session>());world.paused=std::bit_cast<std::int8_t>(std::uint8_t(pause));
        const auto asset=models.read_primary(std::uint8_t(character),0,std::uint8_t(model_class));
        auto initial=std::make_unique<g::Actor>();initial->slot=std::uint8_t(slot);initial->category=2;initial->character=255;initial->model_pose_class=std::uint8_t(model_class);initial->ai_control=std::uint8_t((pause+model_class)%3);
        initial->active=false;initial->visible=pause%2;initial->current=-123;initial->maximum=456;initial->status=std::array{0u,2u,8u,10u}[pause%4];initial->auxiliary_status=0x89abcdefu;initial->class_marker=77;initial->previous_motion_class=88;initial->room=0x1234;
        initial->position={1,2,3};initial->orientation={4,5,6,7};initial->local_impulse={8,9,10};initial->world_impulse={11,12,13};initial->root_motion_delta={14,15,16};initial->pending_notice=99;initial->appearance_variant=2;
        initial->model_asset=asset;initial->model=asset->make_instance();initial->animation=std::make_shared<a::Playback>(initial->model);initial->animation->motion=-19;initial->animation->channel_count=2;
        auto& channel=initial->animation->channel(a::ModelBank::primary,0);channel.timing={3.25f,8,2,1,0x92};channel.selector=7;channel.blend_remaining=17;channel.blend_position=.25f;
        const auto before=*initial;const auto created=world.spawn_primary(slot,std::move(initial));check(created.status==g::actors::EntityStatus::completed);const auto actor=world.resolve(created.id);
        check(g::initialize_primary_defaults(world,created.id,std::uint8_t(character),*banks)==g::PrimaryInitializationStatus::completed);
        check(actor->primary_state&&actor->primary_state->part_visibility.size()==asset->part_count()&&actor->animation->channel_count==5&&actor->animation->resources_known);
        check(actor->animation->channel(a::ModelBank::primary,0).timing.frame==3.25f&&actor->animation->channel(a::ModelBank::primary,0).timing.flags==0x92&&actor->animation->channel(a::ModelBank::primary,0).blend_remaining==17&&actor->animation->motion==-19);
        check(actor->model==before.model&&actor->ai_control==before.ai_control&&actor->visible==before.visible&&actor->appearance_variant==2&&actor->room==0x1234&&actor->position.x==1&&actor->orientation[1]==5&&actor->root_motion_delta.y==15&&actor->pending_notice==99);
        check(bool(actor->constraints)==(pause==0)&&actor->contact.regions.present());constraints+=bool(actor->constraints);
        check(actor->animation->resources[0]==banks->bank({g::HumanoidMotionFamily::primary,0})&&actor->animation->resources[1]==(character>=5?banks->alternate_style():banks->scripted().other_modes)&&actor->animation->resources[2]==banks->character(character));
        compare_original(world,*actor,before,character,false);++initializations;
    }
    const auto asset=models.read_primary(0,0,0);
    for(unsigned value=0;value<256;++value)for(unsigned pose=0;pose<16;++pose){
        g::World world(profile(),std::make_shared<g::Session>());world.session().exit_requested=std::uint8_t(value);auto initial=std::make_unique<g::Actor>();initial->slot=0;initial->category=0;initial->active=true;initial->character=0;
        initial->model_asset=asset;initial->model=asset->make_instance();initial->animation=std::make_shared<a::Playback>(initial->model);initial->position={11,22,33};initial->orientation={4,5,6,7};
        initial->saved_action_position={pose&1?100.f:0.f,pose&2?-50.f:0.f,pose&4?25.f:0.f};initial->saved_action_yaw=pose&8?-12345:0;initial->auxiliary_status=0x89abcdefu;initial->color_fade=g::ColorFade{0x12345678,3,4};
        const auto before=*initial;const auto created=world.spawn_primary(0,std::move(initial));const auto actor=world.resolve(created.id);
        check(g::restore_primary_slot(world,created.id)==g::PrimaryInitializationStatus::completed);compare_original(world,*actor,before,0,true);
        check(actor->animation==before.animation&&actor->character==before.character&&actor->orientation[0]==4&&actor->orientation[2]==6&&actor->saved_action_yaw==before.saved_action_yaw);++restores;
    }
    g::World world(profile(),std::make_shared<g::Session>());auto initial=std::make_unique<g::Actor>();initial->slot=0;initial->model_asset=asset;initial->model=asset->make_instance();initial->animation=std::make_shared<a::Playback>(initial->model);const auto created=world.spawn_primary(0,std::move(initial));const auto actor=world.resolve(created.id);
    for(unsigned character=0;character<256;++character)for(unsigned model_class=0;model_class<256;++model_class){
        actor->appearance_variant=99;actor->movement_enabled=0;check(g::select_primary_appearance(world,created.id,std::uint8_t(character),std::uint8_t(model_class))&&actor->character==character&&actor->model_pose_class==model_class&&actor->appearance_variant==0&&actor->movement_enabled==1);compare_setter(*actor,character,model_class);++setters;
    }
    actor->model_pose_class=0;g::HumanoidMotionOwner owner(world);check(owner.publish(banks).status==g::HumanoidPublicationStatus::completed);
    check(g::initialize_primary_defaults(world,created.id,0,*base)==g::PrimaryInitializationStatus::completed&&actor->animation->resources[2]==banks->character(0));
    const auto next=motions.overlay(2,characters,*banks);const auto publication=owner.publish(next);check(publication.status==g::HumanoidPublicationStatus::completed&&publication.actors==1&&publication.bindings==3&&actor->animation->resources[1]==next->scripted().other_modes&&actor->primary_state->default_motion_aliases[0].family==g::HumanoidMotionFamily::primary);++bank_publications;
    actor->model_variant=1;const auto health=actor->current;check(g::initialize_primary_defaults(world,created.id,0,*next)==g::PrimaryInitializationStatus::unavailable&&actor->current==health);++refusals;actor->model_variant=0;
    check(g::initialize_primary_defaults(world,created.id,255,*next)==g::PrimaryInitializationStatus::unavailable);++refusals;
    check(owner.close()==g::HumanoidPublicationStatus::completed&&g::initialize_primary_defaults(world,created.id,0,*next)==g::PrimaryInitializationStatus::unavailable);++refusals;
}
}
#ifdef REO_PRIMARY_INITIALIZATION_ORIGINAL
#include "primary_actor_initialization_reference.inc"
#else
namespace {void compare_original(g::World&,const g::Actor&,const g::Actor&,unsigned,bool){}void compare_setter(const g::Actor&,unsigned,unsigned){}}
#endif
int main(int argc,char** argv)try{
    contracts();if(argc==2)owned(argv[1]);else check(argc==1);
    std::cout<<"{\"checks\":"<<checks<<",\"initializations\":"<<initializations<<",\"restores\":"<<restores<<",\"setters\":"<<setters<<",\"constraints\":"<<constraints<<",\"bank_publications\":"<<bank_publications<<",\"refusals\":"<<refusals<<",\"original_calls\":"<<original_calls<<",\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
