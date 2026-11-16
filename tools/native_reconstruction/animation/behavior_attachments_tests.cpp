#include "game/native/gameplay_world/behavior_attachments.hpp"
#include "game/native/gameplay_world/actor_initial_state.hpp"
#include "game/native/animation/model.hpp"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <fstream>
#include <iostream>
#include <source_location>
namespace w=reo::native::gameplay_world;namespace a=reo::native::animation;namespace t=reo::native::transform_math;
std::uint64_t checks{},calls{},frame_cases{},terminal_cases{},gates{},refusals{},snapshots{};unsigned current_case{};
void check(bool yes,std::source_location at=std::source_location::current()){++checks;if(!yes)throw std::runtime_error("Attachment case "+std::to_string(current_case)+" line "+std::to_string(at.line()));}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){++calls;switch(context->pc){
#include "original_dispatch.hpp"
default:throw std::runtime_error("Unexpected attachment source call");}}
constexpr unsigned actor=0x200000,work=0x210000,nodes=0x300000;
template<class T>void put(std::vector<std::uint8_t>& memory,unsigned at,T v){transform_write(memory.data(),at,v);}
template<class T>T get(const std::vector<std::uint8_t>& memory,unsigned at){return transform_read<T>(memory.data(),at);}
void call(std::vector<std::uint8_t>& memory,unsigned pc,unsigned selector=0,float step=1){R5900Context c;PS2Runtime r;c.pc=pc;c.f[12]=step;SET_GPR_U32(&c,4,actor);SET_GPR_U32(&c,5,selector);SET_GPR_U32(&c,31,0xabcdef);original_transform_port(memory.data(),&c,&r);check(c.pc==0xabcdef);}
void project(std::vector<std::uint8_t>& m,const w::World& world,const w::Actor& value){
    put(m,actor+0x34,work);put(m,actor+0x54d,value.model_pose_class);put(m,actor+0x232,value.model_offset_lock.value_or(0));put(m,actor+0x544,value.current);
    put(m,actor+0xb99,value.motion_style);put(m,actor+0xb98,value.character);put(m,actor+0xc50,value.model_offset_frame.value_or(0));put(m,actor+0xc52,value.model_offset_phase.value_or(0));put(m,0x4badf8,world.paused);put(m,0x3243cc,world.session().clock_mode);
    put(m,actor+0xf5,value.primary_state?value.primary_state->part_visibility.at(1):value.scripted?value.scripted->part_visibility.at(1):std::uint8_t(77));
    if(value.model)for(unsigned i=0;i<value.model->nodes().size();++i){put(m,work+0x820+4*i,nodes+400*i);put(m,nodes+400*i+0x40,value.model->nodes()[i].local);}
}
void compare(const std::vector<std::uint8_t>& m,const w::Actor& value){
    check(value.model_offset_frame.value_or(0)==get<std::int16_t>(m,actor+0xc50));check(value.model_offset_phase.value_or(0)==get<std::uint8_t>(m,actor+0xc52));
    const auto visible=value.primary_state?value.primary_state->part_visibility[1]:value.scripted?value.scripted->part_visibility[1]:std::uint8_t(77);check(visible==get<std::uint8_t>(m,actor+0xf5));
    if(value.model)for(unsigned i:{24u,26u})check(!std::memcmp(m.data()+nodes+400*i+0x40,&value.model->nodes()[i].local,64));
}
w::Profile profile(){w::Profile p;p.layouts.push_back({});return p;}
int main(int argc,char** argv)try{
    check(argc==2);std::vector<std::uint8_t> memory(0x900000);owned_constants(memory.data());std::ifstream input(argv[1],std::ios::binary);unsigned count{};input.read(reinterpret_cast<char*>(&count),4);check(count==2);
    std::array<std::shared_ptr<const a::Skeleton>,2> skeletons;
    for(auto& skeleton:skeletons){unsigned size{};input.read(reinterpret_cast<char*>(&size),4);std::vector<std::byte> data(size);input.read(reinterpret_cast<char*>(data.data()),size);check(bool(input));skeleton=a::Skeleton::import_raw(data);check(skeleton->nodes().size()>26);}
    w::World world(profile(),std::make_shared<w::Session>());
    for(unsigned asset=0;asset<2;++asset){
        w::Actor value;w::initialize_cleared_actor_defaults(value);value.model=std::make_shared<a::Instance>(skeletons[asset]);value.current=100;value.primary_state.emplace();value.primary_state->part_visibility.assign(3,1);
        for(unsigned style:{0u,1u})for(unsigned clock:{0u,1u})for(unsigned frame=0;frame<65536;++frame){
            current_case=frame;value.motion_style=std::uint8_t(style);world.session().clock_mode=std::uint8_t(clock);value.model_offset_frame=std::bit_cast<std::int16_t>(std::uint16_t(frame));value.model_offset_phase=std::uint8_t(frame%3);
            project(memory,world,value);call(memory,0x5d6a60);w::update_behavior_attachment(world,value);compare(memory,value);++frame_cases;
        }
        for(unsigned style:{0u,1u})for(unsigned phase=0;phase<3;++phase)for(unsigned frame:{0u,4u,5u,9u,10u,149u,150u,151u,65535u})for(float step:{-2.f,-.5f,0.f,.25f,1.f,1.75f,150.f,65535.f}){
            value.motion_style=std::uint8_t(style);value.model_offset_phase=std::uint8_t(phase);value.model_offset_frame=std::bit_cast<std::int16_t>(std::uint16_t(frame));
            project(memory,world,value);call(memory,0x5d6a60,0,step);w::update_behavior_attachment(world,value,step);compare(memory,value);++frame_cases;
        }
        for(unsigned character:{0u,1u,7u,255u})for(unsigned selector=0;selector<256;++selector){
            value.character=std::uint8_t(character);value.primary_state->part_visibility[1]=77;
            auto point=value.model->local_translation(24);point.y=13.25f;value.model->local_translation(24,point);
            point=value.model->local_translation(26);point.y=-9.5f;value.model->local_translation(26,point);
            project(memory,world,value);call(memory,0x5d6ed0,0x12340000u|selector);w::update_terminal_attachment(value,0x12340000u|selector);compare(memory,value);++terminal_cases;
        }
        // Actual independent scripted-family visibility owner receives the same F5 write.
        value.primary_state.reset();value.scripted.emplace();value.scripted->part_visibility.assign(3,77);project(memory,world,value);call(memory,0x5d6ed0,3);w::update_terminal_attachment(value);compare(memory,value);++terminal_cases;
        value.model->rebuild(t::identity());const auto retained=value.model->retain();const auto joints=retained->joints;
        value.model_offset_frame=0;value.model_offset_phase=0;value.model_offset_lock=0;w::update_behavior_attachment(world,value);
        check(!value.model->retain()&&retained->joints==joints);++snapshots;
        // F5 admission occurs after the first real node write, before its copy.
        value.scripted.reset();auto second=value.model->local_translation(26);second.y=-17;value.model->local_translation(26,second);bool refused=false;
        try{w::update_terminal_attachment(value,3);}catch(const std::runtime_error&){refused=true;}
        check(refused&&value.model->local_translation(24).y==(value.character?std::bit_cast<float>(0x40d33333u):7.f)&&value.model->local_translation(26).y==-17);++refusals;
    }
    for(unsigned branch=0;branch<4;++branch){w::Actor value;
        if(branch==0)value.model_pose_class=1;else if(branch==1)world.paused=1;else{value.model_offset_lock=std::uint16_t(branch==2?1:0);value.current=-1;}
        project(memory,world,value);call(memory,0x5d6a60);w::update_behavior_attachment(world,value);compare(memory,value);++gates;world.paused=0;
    }
    {w::Actor value;bool refused=false;try{w::update_behavior_attachment(world,value);}catch(const std::runtime_error&){refused=true;}check(refused);++refusals;
        value.model_offset_lock=0;value.current=1;refused=false;try{w::update_behavior_attachment(world,value);}catch(const std::runtime_error&){refused=true;}check(refused);++refusals;
        value.model_offset_frame=0;value.model_offset_phase=0;refused=false;try{w::update_behavior_attachment(world,value);}catch(const std::runtime_error&){refused=true;}check(refused);++refusals;
        value.model_pose_class=1;w::update_terminal_attachment(value,3);++gates;
    }
    std::cout<<"{\"checks\":"<<checks<<",\"source_calls\":"<<calls<<",\"frame_cases\":"<<frame_cases<<",\"terminal_cases\":"<<terminal_cases<<",\"gates\":"<<gates<<",\"refusals\":"<<refusals<<",\"snapshot_lifetimes\":"<<snapshots<<"}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
