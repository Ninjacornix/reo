#include "target_metrics.hpp"
#include "world.hpp"
#include "linked_models.hpp"
#include "auxiliary_actors.hpp"
#include "../animation/model.hpp"
#include "../transform_math/heading.hpp"
#include <cmath>
#include <cstring>
#include <iostream>
#include <limits>
#include <source_location>
#include <stdexcept>
#ifdef REO_TARGET_METRICS_ORIGINAL
#include "reference.hpp"
#include "functions.h"
#endif
namespace g=reo::native::gameplay_world;
namespace c=reo::native::gameplay_collision;
namespace a=reo::native::animation;
namespace math=reo::native::transform_math;
namespace {
std::uint64_t checks{},profiles{},strict_profiles{},corrected_profiles{},unknown_profiles{},pairs{},wall_queries{},floor_queries{},sorts{},comparisons{},swaps{},refusals{},original_sorts{},original_comparisons{},floor_hits{},near_wall_hits{};
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Target metrics check at "+std::to_string(at.line()));}
template<class Buffer,class T>void put(Buffer& target,unsigned at,T value){check(at+sizeof(T)<=target.size());std::memcpy(target.data()+at,&value,sizeof(T));}
std::shared_ptr<const a::Skeleton> skeleton(){
    std::vector<std::byte> raw(28+12*84);put(raw,4,13u);put(raw,8,std::uint32_t(raw.size()));put(raw,16,1u);put(raw,20,16u);
    for(unsigned i=0;i<12;++i){const unsigned at=28+i*84,node=at+12;put(raw,at,1u);put(raw,at+4,1u);put(raw,at+8,84u);put(raw,node,i);
        put(raw,node+8,i==0?1u:0xffffffffu);put(raw,node+12,i>0&&i<11?i+1:0xffffffffu);
        for(unsigned lane=0;lane<3;++lane)put(raw,node+0x10+4*lane,1.f);
        put(raw,node+0x30,float(i+1));put(raw,node+0x34,float(20+2*i));put(raw,node+0x38,float(10+i));
    }
    return a::Skeleton::import_raw(raw);
}
c::response::Grid grid(std::uint32_t flags=0){
    std::vector<std::byte> raw(flags?108:48);put(raw,8,10000u);put(raw,12,10000u);put(raw,16,1u);put(raw,20,1u);put(raw,32,32u);put(raw,36,flags?44u:40u);put(raw,40,36u);put(raw,44,flags?0u:0xffffffffu);
    if(flags){put(raw,48,0xffffffffu);put(raw,52,flags);
        put(raw,56,c::Vec3{0,100,0});put(raw,68,c::Vec3{0,100,9000});put(raw,80,c::Vec3{9000,100,0});put(raw,92,c::Vec3{0,1,0});put(raw,104,-100.f);
    }
    return c::response::Grid::import(raw);
}
void model(g::Actor& actor,const std::shared_ptr<const a::Skeleton>& data){
    actor.model=std::make_shared<a::Instance>(data);auto basis=math::identity();basis[3]={actor.position.x,actor.position.y,actor.position.z,1};actor.model->rebuild(basis);
}
void populate(g::Actor& actor,unsigned family,unsigned slot,unsigned variant,const std::shared_ptr<const a::Skeleton>& data){
    actor.active=true;actor.slot=std::uint8_t(slot);actor.room=std::uint16_t((variant&1)&&slot%5==4?8:7);
    actor.position={float(500+100*slot+40*family),float(family==2?40+int(slot%7)*30:120+int(slot%3)*15),float(800+13*slot+55*family)};
    actor.orientation[1]=std::bit_cast<std::int16_t>(std::uint16_t(701*slot+32000*family));actor.motion_style=std::uint8_t(slot%12);
    if(family==2)actor.targeting=g::TargetingState{(variant&2)&&slot%7==6?0x100u:0u,(slot&1)!=0,std::uint8_t((slot*7+variant)%12)};
    model(actor,data);
}
#ifdef REO_TARGET_METRICS_ORIGINAL
constexpr unsigned stack_end=0x1f00000,frame_begin=stack_end-0x9340,output_base=0x3b27e0,output_end=0x3b5040;
std::vector<std::uint8_t> memory(0x2000000);std::array<bool,0x9340> written;
std::uint64_t unknown_reads{},original_walls{},original_floors{},reference_sorts{},reference_comparisons{};
bool tracking{};const g::TargetMetricRoom* active_room{};
c::Vec3 original_point(unsigned at){return transform_read<c::Vec3>(memory.data(),at);}
void project_actor(const g::Actor& actor,unsigned at,unsigned model_at){
    memory[at]=actor.active;memory[at+3]=actor.slot;put(memory,at+0x1e2,actor.room);put(memory,at+0x38,actor.position);put(memory,at+0x92,actor.orientation[1]);memory[at+0xb99]=actor.motion_style;
    if(actor.targeting&&actor.targeting->model_point)memory[at+0x551]=*actor.targeting->model_point;
    if(actor.targeting)put(memory,at+0xc94,actor.targeting->flags);
    put(memory,at+0x34,model_at);
    if(actor.model&&(!actor.targeting||actor.targeting->selected_model_point))for(unsigned i=0;i<actor.model->nodes().size();++i){
        const auto node=model_at+0x900+i*64;put(memory,model_at+0x820+4*i,node);put(memory,node+0x30,actor.model->world_translation(i));
    }
}
void project_world(g::World& world){
    std::fill(memory.begin(),memory.end(),0);std::fill(memory.begin()+output_base,memory.begin()+output_end,0xa5);memory[0x3243f2]=world.mode;
    for(unsigned i=0;i<8;++i)if(auto actor=world.primary(i))project_actor(*actor,0x4a5c30+0x10e0*i,0x1000000+0x2000*i);
    for(unsigned i=0;i<10;++i)if(auto actor=world.resolve(world.auxiliary_actors().identity_at(i)))project_actor(*actor,0x417090+0x1170*i,0x1040000+0x2000*i);
    for(unsigned i=0;i<50;++i)if(auto actor=world.resolve(world.linked_models().identity_at(i)))project_actor(*actor,0x42eb00+0xd90*i,0x1080000+0x2000*i);
}
std::vector<std::uint8_t> project_metrics(const g::TargetMetricState& state){
    std::vector<std::uint8_t> bytes(output_end-output_base,0xa5);
    const auto order=[&](unsigned at,const auto& rows){for(const auto& row:rows){std::memcpy(bytes.data()+at-output_base,row.data(),row.size());at+=unsigned(row.size());}};
    const auto metric=[&](unsigned at,const g::TargetPairMetric& pair){put(bytes,at-output_base,pair.distance);put(bytes,at+4-output_base,pair.bearing);};
    order(0x3b27e0,state.auxiliary_primary_order);order(0x3b2830,state.primary_auxiliary_order);order(0x3b2880,state.reverse_auxiliary_order);order(0x3b2a80,state.auxiliary_linked_order);order(0x3b2c80,state.reverse_primary_order);order(0x3b2e10,state.primary_linked_order);
    for(unsigned i=0;i<8;++i){
        for(unsigned j=0;j<8;++j)if(auto value=state.primary_pairs[i][j])metric(0x3b4e40+64*i+8*j,*value);
        for(unsigned j=0;j<10;++j)if(auto value=state.primary_auxiliary[i][j]){const auto at=0x3b2fa0+80*i+8*j;metric(at,*value);bytes[at+6-output_base]=0;}
        for(unsigned j=0;j<50;++j)if(auto value=state.primary_linked[i][j]){const auto at=0x3b41c0+400*i+8*j;metric(at,value->pair);bytes[at+6-output_base]=value->wall;bytes[at+7-output_base]=value->floor;}
    }
    for(unsigned i=0;i<10;++i)for(unsigned j=0;j<50;++j)if(auto value=state.auxiliary_linked[i][j]){const auto at=0x3b3220+400*i+8*j;metric(at,value->pair);bytes[at+6-output_base]=value->wall;bytes[at+7-output_base]=value->floor;}
    return bytes;
}
void run_original(const g::TargetMetricRoom& room,bool initialize){
    written.fill(false);unknown_reads=original_walls=original_floors=reference_sorts=reference_comparisons=0;
    for(unsigned at=frame_begin;at<stack_end;at+=4)put(memory,at,-1000000.f);
    if(initialize)for(unsigned at=0x1b0;at<0x9230;at+=4){put(memory,frame_begin+at,std::numeric_limits<float>::max());for(unsigned b=0;b<4;++b)written[at+b]=true;}
    R5900Context context;PS2Runtime runtime;tracking=true;active_room=&room;context.pc=0x6d6240;SET_GPR_U32(&context,29,stack_end);SET_GPR_U32(&context,31,0x100);original_transform_port(memory.data(),&context,&runtime);
    tracking=false;active_room=nullptr;check(context.pc==0x100&&GPR_U32(&context,29)==stack_end);
}
void compare_output(const std::vector<std::uint8_t>& expected){
    const auto first=std::mismatch(expected.begin(),expected.end(),memory.begin()+output_base);
    if(first.first!=expected.end())throw std::runtime_error("Target cache mismatch at "+std::to_string(output_base+std::distance(expected.begin(),first.first))+" expected "+std::to_string(*first.first)+" original "+std::to_string(*first.second));
    ++checks;
}
#endif
void compare(unsigned primary,unsigned auxiliary,unsigned linked,unsigned variant,std::uint8_t mode,const std::shared_ptr<const a::Skeleton>& data,const g::TargetMetricRoom& room){
    g::World world({{{1,2,4}},1,{128,UINT64_MAX}},std::make_shared<g::Session>());world.mode=mode;
    for(unsigned i=0;i<8;++i){auto actor=std::make_unique<g::Actor>();populate(*actor,0,i,variant,data);actor->active=(variant&4)?i>=8-primary:i<primary;check(bool(world.spawn_primary(i,std::move(actor)).id));}
    for(unsigned i=0;i<auxiliary;++i){const auto id=world.auxiliary_actors().allocate().id;auto actor=world.resolve(id);check(bool(actor));const auto slot=world.auxiliary_actors().physical_slot(id);check(bool(slot));populate(*actor,1,*slot,variant,data);}
    for(unsigned i=0;i<linked;++i){const auto id=world.linked_models().allocate(false).id;auto actor=world.resolve(id);check(bool(actor));const auto slot=world.linked_models().physical_slot(id);check(bool(slot));populate(*actor,2,*slot,variant,data);}
    auto& cache=world.target_metrics();check(!cache.state());const auto result=cache.rebuild(room);check(result.status==g::TargetMetricStatus::completed&&result.initialized_work&&cache.state());
#ifdef REO_TARGET_METRICS_ORIGINAL
    const auto expected=project_metrics(*cache.state());project_world(world);run_original(room,false);
    if(unknown_reads)++unknown_profiles;else{compare_output(expected);++strict_profiles;}
    project_world(world);run_original(room,true);check(unknown_reads==0&&original_walls==result.wall_queries&&original_floors==result.floor_queries);compare_output(expected);++corrected_profiles;
    if(result.sorts>reference_sorts||result.comparisons>reference_comparisons)
        throw std::runtime_error("Target sort work differs for profile "+std::to_string(primary)+"/"+std::to_string(auxiliary)+"/"+std::to_string(linked)+"/"+std::to_string(variant)+": native "+std::to_string(result.sorts)+"/"+std::to_string(result.comparisons)+", original "+std::to_string(reference_sorts)+"/"+std::to_string(reference_comparisons));
    ++checks;original_sorts+=reference_sorts;original_comparisons+=reference_comparisons;
#endif
    for(unsigned i=0;i<8;++i)check(cache.state()->primary_identity[i]==world.identity(i));
    for(unsigned i=0;i<primary;++i)check(cache.state()->primary_auxiliary_sources[i]==world.identity((variant&4)?i+8-primary:i));
    for(const auto& row:cache.state()->primary_linked)for(const auto& value:row)if(value){floor_hits+=value->floor!=0;near_wall_hits+=value->wall&&value->pair.distance<3000.f;}
    check(result.sorts<=136);++profiles;pairs+=result.pairs;wall_queries+=result.wall_queries;floor_queries+=result.floor_queries;sorts+=result.sorts;comparisons+=result.comparisons;swaps+=result.swaps;
}
void lifetime(const std::shared_ptr<const a::Skeleton>& data,const g::TargetMetricRoom& room){
    g::World world({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<g::Session>());auto& cache=world.target_metrics();
    check(cache.rebuild(room).status==g::TargetMetricStatus::unavailable&&!cache.state());++refusals;
    for(unsigned i=0;i<8;++i){auto actor=std::make_unique<g::Actor>();populate(*actor,0,i,0,data);actor->active=i==0;check(bool(world.spawn_primary(i,std::move(actor)).id));}
    auto id=world.linked_models().allocate(false).id;auto linked=world.resolve(id);check(bool(linked));const auto slot=world.linked_models().physical_slot(id).value();populate(*linked,2,slot,0,data);
    linked->targeting.reset();check(cache.rebuild(room).status==g::TargetMetricStatus::unavailable&&!cache.state());++refusals;
    linked->targeting=g::TargetingState{0,true};
    check(cache.rebuild(room).status==g::TargetMetricStatus::unavailable&&!cache.state());++refusals;
    linked->targeting->model_point=255;
    check(cache.rebuild(room).status==g::TargetMetricStatus::unavailable&&!cache.state());++refusals;
    linked->targeting->model_point=0;
    check(cache.rebuild(room).status==g::TargetMetricStatus::completed&&cache.state()->primary_linked[0][slot]);
    linked->motion_style=255;
    check(cache.rebuild(room).status==g::TargetMetricStatus::completed&&cache.state()->primary_linked[0][slot]);
    linked->targeting=g::TargetingState{};check(cache.rebuild(room).status==g::TargetMetricStatus::completed&&cache.state()->primary_linked[0][slot]);
    const auto prior=cache.state()->primary_linked[0][slot]->pair.distance;linked->targeting->flags=0x100;linked->position.x+=20;
    check(cache.rebuild(room).status==g::TargetMetricStatus::completed&&cache.state()->primary_linked[0][slot]->pair.distance==prior&&cache.state()->primary_linked_order[0][0]==255);
    check(world.linked_models().reset()==g::LinkedStatus::completed);const auto next=world.linked_models().allocate(false).id;check(next!=id&&world.linked_models().physical_slot(next)==slot);
    check(cache.rebuild(room).status==g::TargetMetricStatus::completed&&!cache.state()->primary_linked[0][slot]&&cache.state()->linked_identity[slot]==next);
    world.primary(0)->model.reset();check(cache.rebuild(room).status==g::TargetMetricStatus::unavailable&&!cache.state());++refusals;
    check(world.close()==g::Status::completed&&cache.rebuild(room).status==g::TargetMetricStatus::closed&&!cache.state());
}
}
#ifdef REO_TARGET_METRICS_ORIGINAL
void cache_scratch_read(std::uint32_t at,std::size_t size){if(tracking&&at>=frame_begin&&at+size<=stack_end)for(unsigned i=0;i<size;++i)if(!written[at-frame_begin+i]){++unknown_reads;break;}}
void cache_scratch_write(std::uint32_t at,std::size_t size){if(tracking&&at>=frame_begin&&at+size<=stack_end)for(unsigned i=0;i<size;++i)written[at-frame_begin+i]=true;}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    if(context->pc==0x6d6d60){const auto count=GPR_U32(context,5);check(count<=50);++reference_sorts;if(count)reference_comparisons+=count*(count-1)/2;}
    switch(context->pc){
#include "dispatch.inc"
    case 0x376e70:{const auto from=original_point(GPR_U32(context,4)),to=original_point(GPR_U32(context,5));SET_GPR_U32(context,2,math::direction_turn(to.x-from.x,to.z-from.z));break;}
    case 0x579980:{check(active_room&&GPR_U32(context,6)==0x4ffff&&GPR_U32(context,7)==0);auto filter=active_room->filter;filter.include=0x4ffff;filter.exclude=0;filter.dynamic_kind_gate=false;
        const auto hit=c::trace::any(active_room->walls,original_point(GPR_U32(context,4)),original_point(GPR_U32(context,5)),filter,active_room->dynamic);check(hit.status==c::trace::SamplingStatus::complete);SET_GPR_U32(context,2,bool(hit.hit));++original_walls;break;}
    case 0x57d630:{check(active_room&&GPR_U32(context,6)==255&&GPR_U32(context,7)==0x81);const auto hit=c::trace::floor_any_checked(active_room->floors,original_point(GPR_U32(context,4)),original_point(GPR_U32(context,5)),255,0x81);check(hit.status==c::trace::SamplingStatus::complete);SET_GPR_U32(context,2,hit.hit);++original_floors;break;}
    default:throw std::runtime_error("Undeclared target-metric original dependency "+std::to_string(context->pc));
    }
    context->pc=GPR_U32(context,31);
}
#endif
int main(){
    try{
        const auto data=skeleton();const auto empty=grid(),surface=grid(0x80),excluded=grid(0x81);
        for(unsigned primary:{0u,1u,3u,8u})for(unsigned auxiliary:{0u,2u,10u})for(unsigned linked:{0u,1u,7u,50u}){
            compare(primary,auxiliary,linked,0,0,data,{empty,empty,{},{}});
            compare(primary,auxiliary,linked,3,1,data,{surface,surface,{},{}});
            compare(primary,auxiliary,linked,1,0,data,{empty,excluded,{},{}});
            compare(primary,auxiliary,linked,5,2,data,{surface,excluded,{},{}});
        }
        lifetime(data,{empty,empty,{},{}});
        std::cout<<"{\"checks\":"<<checks<<",\"profiles\":"<<profiles<<",\"strict_profiles\":"<<strict_profiles<<",\"corrected_profiles\":"<<corrected_profiles<<",\"unknown_profiles\":"<<unknown_profiles<<",\"pairs\":"<<pairs<<",\"wall_queries\":"<<wall_queries<<",\"floor_queries\":"<<floor_queries<<",\"sorts\":"<<sorts<<",\"comparisons\":"<<comparisons<<",\"swaps\":"<<swaps<<",\"refusals\":"<<refusals<<",\"original_sorts\":"<<original_sorts<<",\"original_comparisons\":"<<original_comparisons<<",\"floor_hits\":"<<floor_hits<<",\"near_wall_hits\":"<<near_wall_hits<<"}\n";
    }catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
}
