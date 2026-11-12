#include "game/native/gameplay_world/pose_splitting_arc.hpp"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <iostream>
#include <source_location>
namespace g=reo::native::gameplay_world;namespace m=reo::native::transform_math;namespace c=reo::native::gameplay_collision;
unsigned checks{},cases{},calls{},retirements{},floors{},packets{},trails{},sounds{},presets{};constexpr unsigned work_at=0x20000,parent_at=0x22000,emitter_at=0x24000;
void check(bool value,std::source_location p=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Splitting pose arc "+std::to_string(p.line())+" case "+std::to_string(cases));}
template<class T>T get(const std::uint8_t* p,unsigned at){return transform_read<T>(p,at);}template<class T>void put(std::uint8_t* p,unsigned at,T value){transform_write(p,at,value);}
struct Spawn {m::Matrix basis;m::Vector point;std::array<std::int16_t,4> angles;std::uint8_t descriptor{},variant{};};
struct Effects final:g::SplittingArcEffects {
    g::Actor* actor{};g::actors::EntityId work_id,parent_id,emitter_id;unsigned reject{};m::Vector primary_point;float height{};std::vector<unsigned> events;std::vector<m::Vector> points;std::vector<Spawn> children;
    std::optional<m::Vector> primary_zero_position()override{return reject==1?std::nullopt:std::optional(primary_point);}
    std::optional<c::response::Floor> floor(m::Vector p)override{events.push_back(10);points.push_back(p);c::response::Floor result;result.height=height;return reject==5?std::nullopt:std::optional(result);}
    bool packet(const g::actors::EntityId& id,std::uint8_t descriptor,std::uint8_t bank)override{check(id==work_id&&descriptor==0x1b&&bank==1);events.push_back(1);return reject!=2;}
    bool trail(const g::actors::EntityId& parent,const g::actors::EntityId& work,std::uint8_t mode)override{check(parent==parent_id&&work==work_id&&mode<2);events.push_back(2+mode);return reject!=3u+mode;}
    bool sound(const g::actors::EntityId& id,std::uint8_t event)override{check(id==parent_id&&event==7);events.push_back(4);return reject!=6;}
    bool preset(const g::actors::EntityId& id,const m::Matrix& basis,m::Vector point,const std::array<std::int16_t,4>& angles,std::uint8_t descriptor,std::uint8_t variant)override{check(id==emitter_id&&descriptor==7&&variant<4);events.push_back(20+variant);children.push_back({basis,point,angles,descriptor,variant});return reject!=7u+variant;}
    bool retire(const g::actors::EntityId& id)override{check(id==work_id);events.push_back(30);if(reject==11)return false;actor->active=actor->visible=false;return true;}
}effects;
std::vector<unsigned> original_events;std::vector<m::Vector> original_points;std::vector<Spawn> original_children;
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;switch(context->pc){
    case 0x5da2c0:check(GPR_U32(context,4)==work_at&&GPR_U32(context,5)==0x1b&&GPR_U32(context,6)==1);original_events.push_back(1);break;
    case 0x578620:check(GPR_U32(context,4)==parent_at&&GPR_U32(context,5)==work_at&&GPR_U32(context,6)<2&&!GPR_U32(context,7)&&!GPR_U32(context,8));original_events.push_back(GPR_U32(context,6)+2);break;
    case 0x616f20:check(GPR_U32(context,4)==work_at+0x38&&GPR_U32(context,6)==255);original_events.push_back(10);original_points.push_back(get<m::Vector>(memory,GPR_U32(context,4)));context->f[0]=effects.height;memory[GPR_U32(context,5)]=0;break;
    case 0x1b9310:check(GPR_U32(context,4)==parent_at&&GPR_U32(context,5)==7&&!GPR_U32(context,6));original_events.push_back(4);break;
    case 0x582720:{check(GPR_U32(context,4)==emitter_at&&GPR_U32(context,5)==work_at+0x50&&GPR_U32(context,6)==work_at+0x38&&GPR_U32(context,7)==work_at+0x90&&GPR_U32(context,8)==7&&GPR_U32(context,9)<4);const auto variant=std::uint8_t(GPR_U32(context,9));original_events.push_back(20+variant);original_children.push_back({get<m::Matrix>(memory,GPR_U32(context,5)),get<m::Vector>(memory,GPR_U32(context,6)),get<std::array<std::int16_t,4>>(memory,GPR_U32(context,7)),7,variant});break;}
    case 0x582de0:check(GPR_U32(context,4)==work_at);original_events.push_back(30);memory[work_at]=memory[work_at+1]=0;break;
#include "original_dispatch.hpp"
    default:throw std::runtime_error("Unadmitted splitting arc helper "+std::to_string(context->pc));
    }context->pc=GPR_U32(context,31);
}
void vector_equal(const void* a,const void* b){check(std::memcmp(a,b,12)==0);}
int main()try{
    std::vector<std::uint8_t> ram(0x2000000);auto* memory=ram.data();owned_constants(memory);g::Actor actor;actor.pose_work.emplace();effects.actor=&actor;g::actors::EntityStore ids({3});effects.work_id=ids.create(std::make_unique<g::actors::Entity>()).id;effects.parent_id=ids.create(std::make_unique<g::actors::Entity>()).id;effects.emitter_id=ids.create(std::make_unique<g::actors::Entity>()).id;actor.contact.related=effects.parent_id;actor.pose_work->emitter_owner=effects.emitter_id;check(bool(effects.work_id)&&bool(effects.parent_id)&&bool(effects.emitter_id));
    for(unsigned phase:{0u,1u,2u,255u})for(unsigned n=0;n<65536;++n){
        actor.active=true;actor.visible=n&1;actor.primary=std::uint8_t(phase);actor.auxiliary_status=n*257;actor.orientation={std::int16_t(n*19),std::int16_t(n*257),std::int16_t(n*251),-17};actor.position={float(int(n%13)-6)*.125f,float(int(n%17)-8)*.5f,float(int(n%19)-9)*.25f};actor.sampled_surface_height=-999;auto& state=*actor.pose_work;state.velocity={.25f,float(int(n%7)-3)*.125f,float(int(n%11)-5)*.0625f};state.acceleration={-.125f,float(int(n%11)-5)*.0625f,float(int(n%13)-6)*.03125f};
        for(unsigned col=0;col<4;++col)for(unsigned row=0;row<4;++row)state.basis[col][row]=float(int((n*(col+1)+row*7)%29)-14)*.25f;
        effects.primary_point={float(int(n%23)-11)*.125f,float(int(n%31)-15)*.25f,float(int(n%37)-18)*.5f};if(n%17==0)effects.primary_point.x=actor.position.x;if(n%31==0)effects.primary_point={actor.position.x,actor.position.y,actor.position.z};effects.height=float(int(n%29)-14)*.25f;effects.events.clear();effects.points.clear();effects.children.clear();original_events.clear();original_points.clear();original_children.clear();
        memory[work_at]=actor.active;memory[work_at+1]=actor.visible;memory[work_at+8]=actor.primary;memory[work_at+0x115]=std::uint8_t(actor.auxiliary_status);put(memory,work_at+0x24,emitter_at);put(memory,work_at+0x28,parent_at);put(memory,work_at+0x38,actor.position);put(memory,work_at+0x50,state.basis);put(memory,work_at+0x90,actor.orientation);put(memory,work_at+0xc0,state.velocity);put(memory,work_at+0xcc,state.acceleration);put(memory,work_at+0x170,actor.sampled_surface_height);put(memory,0x4a5c68,effects.primary_point);
        R5900Context context;PS2Runtime runtime;context.pc=0x5831e0;SET_GPR_U32(&context,4,work_at);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x1234);original_transform_port(memory,&context,&runtime);check(context.pc==0x1234&&GPR_U32(&context,29)==0x1f00000);
        check(g::advance_splitting_pose_arc(actor,effects.work_id,effects));check(actor.active==bool(memory[work_at])&&actor.visible==bool(memory[work_at+1])&&actor.primary==memory[work_at+8]&&std::uint8_t(actor.auxiliary_status)==memory[work_at+0x115]&&actor.sampled_surface_height==get<float>(memory,work_at+0x170));
        vector_equal(&actor.position,memory+work_at+0x38);vector_equal(&state.velocity,memory+work_at+0xc0);vector_equal(&state.acceleration,memory+work_at+0xcc);check(std::memcmp(actor.orientation.data(),memory+work_at+0x90,8)==0&&std::memcmp(&state.basis,memory+work_at+0x50,64)==0);
        check(effects.events==original_events&&effects.points.size()==original_points.size()&&effects.children.size()==original_children.size());for(unsigned i=0;i<effects.points.size();++i)vector_equal(&effects.points[i],&original_points[i]);for(unsigned i=0;i<effects.children.size();++i){const auto& a=effects.children[i];const auto& b=original_children[i];check(a.angles==b.angles&&a.descriptor==b.descriptor&&a.variant==b.variant&&std::memcmp(&a.basis,&b.basis,64)==0);vector_equal(&a.point,&b.point);}
        for(const auto event:effects.events){packets+=event==1;trails+=event==2||event==3;sounds+=event==4;floors+=event==10;presets+=event>=20&&event<24;retirements+=event==30;}++cases;
    }
    for(unsigned reject=1;reject<=11;++reject){actor.active=actor.visible=true;actor.primary=reject<=4?0:1;actor.position={};actor.pose_work->velocity={};actor.pose_work->acceleration={};effects.height=1000;effects.reject=reject;check(!g::advance_splitting_pose_arc(actor,effects.work_id,effects));}
    std::cout<<"{\"checks\":"<<checks<<",\"cases\":"<<cases<<",\"retirements\":"<<retirements<<",\"floor_queries\":"<<floors<<",\"packets\":"<<packets<<",\"trails\":"<<trails<<",\"sounds\":"<<sounds<<",\"presets\":"<<presets<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
