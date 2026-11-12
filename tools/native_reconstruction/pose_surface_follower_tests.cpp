#include "game/native/gameplay_world/pose_surface_follower.hpp"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <iostream>
#include <source_location>
namespace g=reo::native::gameplay_world;namespace m=reo::native::transform_math;namespace c=reo::native::gameplay_collision;
unsigned checks{},cases{},calls{},retirements{},visuals{},floors{},positioned{};constexpr unsigned work_at=0x20000,visual_at=0x22000;
void check(bool value,std::source_location p=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Surface follower "+std::to_string(p.line())+" case "+std::to_string(cases));}
template<class T>T get(const std::uint8_t* p,unsigned at){return transform_read<T>(p,at);}template<class T>void put(std::uint8_t* p,unsigned at,T value){transform_write(p,at,value);}
struct Effects final:g::SurfaceFollowerEffects {
    g::Actor* actor{};g::actors::EntityId visual_id;bool full{};unsigned reject{};float height{};m::Vector visual_position;std::vector<unsigned> events;std::vector<m::Vector> points;
    std::optional<g::actors::EntityId> visual(const g::actors::EntityId&)override{events.push_back(1);return reject==1?std::nullopt:std::optional(full?g::actors::EntityId{}:visual_id);}
    std::optional<c::response::Floor> floor(m::Vector p)override{events.push_back(2);points.push_back(p);c::response::Floor result;result.height=height;return reject==2?std::nullopt:std::optional(result);}
    bool position(const g::actors::EntityId& id,m::Vector point)override{check(id==visual_id);events.push_back(3);if(reject==3)return false;visual_position=point;return true;}
    bool retire(const g::actors::EntityId&)override{events.push_back(4);if(reject==4)return false;actor->active=actor->visible=false;return true;}
}effects;
std::vector<unsigned> original_events;std::vector<m::Vector> original_points;
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;if(context->pc==0x370500&&GPR_U32(context,4)==visual_at+0x38)original_events.push_back(3);switch(context->pc){
    case 0x58da20:check(GPR_U32(context,4)==work_at&&GPR_U32(context,5)==0&&!memory[work_at+1]&&memory[work_at+8]==1);original_events.push_back(1);SET_GPR_U32(context,2,effects.full?0:visual_at);break;
    case 0x616f20:check(GPR_U32(context,4)==work_at+0x38&&GPR_U32(context,6)==255);original_events.push_back(2);original_points.push_back(get<m::Vector>(memory,GPR_U32(context,4)));memory[GPR_U32(context,5)]=0;context->f[0]=effects.height;break;
    case 0x582de0:check(GPR_U32(context,4)==work_at);original_events.push_back(4);memory[work_at]=memory[work_at+1]=0;break;
#include "original_dispatch.hpp"
    default:throw std::runtime_error("Unadmitted follower helper "+std::to_string(context->pc));
    }context->pc=GPR_U32(context,31);
}
void vector_equal(const void* a,const void* b){check(std::memcmp(a,b,12)==0);}
int main()try{
    std::vector<std::uint8_t> ram(0x2000000);auto* memory=ram.data();owned_constants(memory);g::Actor actor;actor.pose_work.emplace();effects.actor=&actor;g::actors::EntityStore identities({1});effects.visual_id=identities.create(std::make_unique<g::actors::Entity>()).id;check(bool(effects.visual_id));
    for(unsigned phase:{0u,1u,2u,255u})for(unsigned n=0;n<65536;++n){
        actor.active=true;actor.visible=n&1;actor.primary=std::uint8_t(phase);actor.position={float(int(n%1009)-504)*.125f,float(int(n%1013)-506)*.5f,float(int(n%1019)-509)*.25f};actor.sampled_surface_height=-999;auto& state=*actor.pose_work;state.timer=std::bit_cast<std::int16_t>(std::uint16_t(n));state.follower_visual=effects.visual_id;
        effects.full=n&2;effects.height=float(int(n%997)-498)*.25f;effects.visual_position={-10,-20,-30};effects.events.clear();effects.points.clear();original_events.clear();original_points.clear();
        memory[work_at]=actor.active;memory[work_at+1]=actor.visible;memory[work_at+8]=actor.primary;put(memory,work_at+12,state.timer);put(memory,work_at+0x24,visual_at);put(memory,work_at+0x38,actor.position);put(memory,work_at+0x170,actor.sampled_surface_height);put(memory,visual_at+0x38,effects.visual_position);
        R5900Context context;PS2Runtime runtime;context.pc=0x584760;SET_GPR_U32(&context,4,work_at);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x1234);original_transform_port(memory,&context,&runtime);check(context.pc==0x1234&&GPR_U32(&context,29)==0x1f00000);
        check(g::advance_pose_surface_follower(actor,{},effects));
        check(actor.active==bool(memory[work_at])&&actor.visible==bool(memory[work_at+1])&&actor.primary==memory[work_at+8]);
        check(state.timer==get<std::int16_t>(memory,work_at+12)&&actor.sampled_surface_height==get<float>(memory,work_at+0x170)&&state.follower_visual==effects.visual_id);
        vector_equal(&actor.position,memory+work_at+0x38);vector_equal(&effects.visual_position,memory+visual_at+0x38);
        check(effects.events==original_events&&effects.points.size()==original_points.size());for(unsigned i=0;i<effects.points.size();++i)vector_equal(&effects.points[i],&original_points[i]);for(const auto event:effects.events){visuals+=event==1;floors+=event==2;positioned+=event==3;retirements+=event==4;}++cases;
    }
    for(unsigned reject=1;reject<=4;++reject){actor.active=actor.visible=true;actor.primary=reject==1||reject==4?0:1;effects.full=reject==4;effects.reject=reject;check(!g::advance_pose_surface_follower(actor,{},effects));}
    check(identities.retire(effects.visual_id)==g::actors::EntityStatus::completed&&!identities.acquire(effects.visual_id));
    std::cout<<"{\"checks\":"<<checks<<",\"cases\":"<<cases<<",\"retirements\":"<<retirements<<",\"visuals\":"<<visuals<<",\"floors\":"<<floors<<",\"positioned\":"<<positioned<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
