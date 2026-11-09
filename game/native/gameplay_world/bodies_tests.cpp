#include "bodies.hpp"
#include <iostream>
#include <stdexcept>
namespace g=reo::native::gameplay_world;
namespace a=reo::native::gameplay_collision::actors;
unsigned checks{};
void check(bool value){++checks;if(!value)throw std::runtime_error("World body check "+std::to_string(checks));}
g::Profile profile(){return{{{0x100,0x10,0x20}},1,{16,2}};}
std::unique_ptr<g::Actor> actor(float x){
    auto value=std::make_unique<g::Actor>();value->active=true;value->position={x,0,0};
    value->previous_position=value->position;value->candidate_direction={x==0?1.f:-1.f,0,0};
    value->current=value->maximum=100;value->collision.body_definition=a::ShapeDefinition{a::ShapeKind::sphere,2,{},{}};
    return value;
}
struct Poses:g::BodyPoses {
    g::World* world{};g::WorldBodies* bodies{};unsigned calls{};bool missing{},throwing{},reenter{},replace_previous{};
    std::shared_ptr<g::JointPose> pose=std::make_shared<g::JointPose>();
    std::shared_ptr<const g::JointPose> retain(const g::actors::EntityId&,const g::Actor&)override{
        ++calls;
        if(throwing)throw std::runtime_error("Declared pose owner failure");
        if(reenter){check(bodies->solve(*this,{},false,false).status==g::BodyStatus::busy);check(!bodies->clear());
            check(!bodies->add({world->identity(0),3,1}));bodies->enqueue(*world,*world->primary(0),1,3);}
        if(replace_previous && calls==2){check(world->retire_primary(0)==g::actors::EntityStatus::completed);
            check(world->spawn_primary(0,actor(99)).status==g::actors::EntityStatus::completed);}
        return missing?nullptr:pose;
    }
};
struct Frame:g::Services {
    unsigned forwarded{},finish_forwarded{};
    void begin_offline_frame(g::World&)override{}
    void run(g::Stage stage,g::World&,g::Actor&)override{++forwarded;if(stage==g::Stage::finish_motion)++finish_forwarded;}
    bool remote_motion(g::World&,g::Actor&)override{return false;}
    bool find_grid(g::World&,g::Actor&,std::int8_t&)override{return false;}
    void switch_grid(g::World&,std::int32_t,std::int32_t)override{}
    float grid_response(g::World&,std::uint8_t)override{return 0;}
};
int main()try{
    {
        g::World world(profile(),std::make_shared<g::Session>());g::WorldBodies bodies(world);Poses poses;
        auto first=world.spawn_primary(0,actor(0)),second=world.spawn_primary(1,actor(1));
        check(first.status==g::actors::EntityStatus::completed && second.status==g::actors::EntityStatus::completed);
        auto left=world.primary(0),right=world.primary(1);right->slot=7;
        Frame base;g::MotionFrameServices motion(base,bodies);auto frame=world.update_primary(motion);
        check(frame.status==g::Status::completed && frame.updated==2 && base.finish_forwarded==0);
        check(bodies.pending()==2 && bodies.counts().accepted==2);
        auto result=bodies.solve(poses,first.id,false,false);
        check(result.status==g::BodyStatus::completed && result.solve.visited==2 && result.solve.contacts>0);
        check(bodies.pending()==0 && poses.calls==0);
        check(left->room_marker==1 && right->room_marker==1 && left->collision.body_peer==second.id && right->collision.body_peer==first.id);
        check(left->position.x!=0 || right->position.x!=1);
        // A paused frame must retain the exact ==1 rule in the real motion caller.
        world.paused=1;g::finish_motion(world,*left,bodies);check(bodies.pending()==0);
        world.paused=-1;g::finish_motion(world,*left,bodies);check(bodies.pending()==1);check(bodies.clear());
        // A nonselected online actor registers mask0, class1: it remains a target.
        world.mode=1;world.selected_actor=0;left->position={0,0,0};left->previous_position=left->position;
        right->position={1,0,0};right->previous_position=right->position;
        g::finish_motion(world,*left,bodies);g::finish_motion(world,*right,bodies);
        result=bodies.solve(poses,first.id,false,false);check(result.status==g::BodyStatus::completed && result.solve.contacts==1);
        // An unregistered actor's absent model pose must not block this pass.
        right->collision.body_definition->first.first_joint=999;poses.missing=true;
        g::finish_motion(world,*left,bodies);result=bodies.solve(poses,first.id,false,false);
        check(result.status==g::BodyStatus::completed && poses.calls==0);
    }
    {
        g::World world(profile(),std::make_shared<g::Session>());g::WorldBodies bodies(world);Poses poses;
        auto id=world.spawn_primary(0,actor(0)).id;auto live=world.primary(0);
        live->collision.body_definition->first.first_joint=0;g::finish_motion(world,*live,bodies);
        poses.missing=true;auto result=bodies.solve(poses,id,false,false);
        check(result.status==g::BodyStatus::pose_unavailable && result.blocked_actor==id && bodies.pending()==1);
        check(live->position.x==0 && live->room_marker==0);
        poses.missing=false;poses.pose->joints.resize(1);poses.reenter=true;poses.world=&world;poses.bodies=&bodies;
        result=bodies.solve(poses,id,false,false);check(result.status==g::BodyStatus::completed && bodies.pending()==0 && bodies.counts().busy==1);
        poses.reenter=false;poses.throwing=true;g::finish_motion(world,*live,bodies);bool failed{};
        try{bodies.solve(poses,id,false,false);}catch(const std::runtime_error&){failed=true;}
        check(failed && bodies.pending()==1 && bodies.clear());
        poses.throwing=false;poses.pose->joints.clear();g::finish_motion(world,*live,bodies);
        check(bodies.solve(poses,id,false,false).status==g::BodyStatus::invalid_geometry && bodies.pending()==1);check(bodies.clear());
        for(unsigned i=0;i<33;++i)bodies.enqueue(world,*live,1,3);
        check(bodies.pending()==32 && bodies.counts().full==1);check(bodies.clear());
        bodies.enqueue(world,*live,1,3);check(world.retire_primary(0)==g::actors::EntityStatus::completed);
        auto replacement=world.spawn_primary(0,actor(99));check(replacement.id!=id);
        check(bodies.solve(poses,replacement.id,false,false).status==g::BodyStatus::invalid_geometry);
        check(world.primary(0)->position.x==99 && live->position.x==0);check(bodies.clear());
        bodies.enqueue(world,*live,1,3);check(bodies.pending()==0 && bodies.counts().retired_or_foreign==1);
        g::World foreign(profile(),std::make_shared<g::Session>());bodies.enqueue(foreign,*world.primary(0),1,3);
        check(bodies.counts().retired_or_foreign==2);
    }
    {
        g::World world(profile(),std::make_shared<g::Session>());g::WorldBodies bodies(world);Poses poses;
        poses.world=&world;poses.replace_previous=true;poses.pose->joints.resize(1);
        for(unsigned i=0;i<2;++i){world.spawn_primary(i,actor(float(i)));auto live=world.primary(i);
            live->collision.body_definition->first.first_joint=0;g::finish_motion(world,*live,bodies);}
        auto old=world.identity(0);auto result=bodies.solve(poses,old,false,false);
        check(result.status==g::BodyStatus::roster_changed && result.blocked_actor==old && bodies.pending()==2);
        check(world.primary(0)->position.x==99 && world.primary(1)->position.x==1);
    }
    {
        g::World world(profile(),std::make_shared<g::Session>());g::WorldBodies bodies(world);Poses poses;
        auto bound=world.spawn_primary(0,actor(0)).id;auto selected=world.spawn_primary(1,actor(1)).id;
        world.primary(0)->position={0,0,500};world.primary(1)->position={1,-900,450};
        world.primary(1)->transient_marker=0x81;check(bodies.boundary().set(0,bound));world.mode=1;
        auto result=bodies.solve(poses,selected,false,false);check(result.status==g::BodyStatus::completed);
        check(world.primary(1)->position.z==300 && world.primary(1)->transient_marker==1);
        check(world.retire_primary(0)==g::actors::EntityStatus::completed);world.spawn_primary(0,actor(0));
        world.primary(1)->position.z=450;bodies.solve(poses,selected,false,false);check(world.primary(1)->position.z==450);
    }
    std::cout<<"{\"checks\":"<<checks<<",\"status\":\"passed\",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
