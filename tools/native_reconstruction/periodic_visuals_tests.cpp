#include "game/native/gameplay_effects/periodic_visuals.hpp"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <atomic>
#include <fstream>
#include <iostream>
#include <source_location>
#include <thread>
#ifdef REO_WEAPON_RESOURCES
#include "owned_weapons.hpp"
#include <cstdio>
#include <string>
unsigned weapon_file_reads{};
std::string weapon_string(const std::uint8_t* memory,unsigned at){if(at>0x2000000-128)throw std::runtime_error("Invalid weapon string");for(unsigned n=0;n<128;++n)if(!memory[at+n])return {reinterpret_cast<const char*>(memory+at),n};throw std::runtime_error("Unbounded weapon string");}
#endif
#ifdef REO_RESOURCE_PLACEMENT
#include "game/native/gameplay_world/resource_factory.hpp"
const reo::native::gameplay_collision::response::Grid* placement_floors{};
unsigned placement_floor_queries{};
#endif
namespace e=reo::native::gameplay_effects;
namespace s=reo::native::gameplay_scenario;
namespace m=reo::native::transform_math;
unsigned checks{},calls{},banks{},updates{},created{},expired{},piece_cases{},camera_cases{},heap_allocations{},heap_releases{};
unsigned signed_timer_cases{},task_cases{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("Periodic visual check "+std::to_string(checks)+" at "+at.file_name()+":"+std::to_string(at.line()));
}
template<class T>T get(const std::uint8_t* memory,std::uint32_t at){return transform_read<T>(memory,at);}
template<class T>void put(std::uint8_t* memory,std::uint32_t at,T value){transform_write(memory,at,value);}
constexpr std::uint32_t model=0x3b85b0,heap=0x800000,parts=0x900000,child_pool=0xb00000;
bool allocated{};
bool task_retired{};
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;const auto done=[&](){context->pc=GPR_U32(context,31);};
    switch(context->pc){
    case 0x573740:check(GPR_U32(context,4)==0x10000);task_retired=true;done();return;
    case 0x107c68:{const auto at=GPR_U32(context,4),n=GPR_U32(context,6);check(at<=0x2000000&&n<=0x2000000-at);std::memset(memory+at,std::uint8_t(GPR_U32(context,5)),n);SET_GPR_U32(context,2,at);done();return;}
#ifdef REO_RESOURCE_FACTORY
    case 0x107ab0:{const auto dst=GPR_U32(context,4),src=GPR_U32(context,5),size=GPR_U32(context,6);
#ifdef REO_WEAPON_RESOURCES
        if(size==16&&dst>=0x2b3864&&dst<=0x2b38d4){check(src>=0x1e00000&&src<0x2000000-size);std::memmove(memory+dst,memory+src,size);SET_GPR_U32(context,2,dst);done();return;}
#endif
#ifdef REO_RESOURCE_PLACEMENT
        if(size==32&&dst>=0x3e10f0&&dst<0x3e72f0){check(src>=0x1e00000&&src<0x2000000-size);std::memmove(memory+dst,memory+src,size);SET_GPR_U32(context,2,dst);done();return;}
#endif
        check(src>=0x100000&&src<=0x110000&&size<=0x110000-src);check((dst==0x74bb50&&size<=129*24)||(dst==0x74b940&&size<=129*4)||(dst==0x74c770&&size<=128*4)||(dst==0x74c970&&size<=384*2));std::memmove(memory+dst,memory+src,size);SET_GPR_U32(context,2,dst);done();return;}
#endif
#ifdef REO_RESOURCE_PLACEMENT
    case 0x616f60:{check(placement_floors);const auto at=GPR_U32(context,4),out=GPR_U32(context,5);check(at<=0x2000000-12&&out<0x2000000);const auto floor=placement_floors->floor(get<reo::native::gameplay_collision::Vec3>(memory,at),std::uint8_t(GPR_U32(context,6)));memory[out]=floor.material;context->f[0]=floor.height;++placement_floor_queries;done();return;}
#endif
#ifdef REO_RESOURCE_INVENTORY
    case 0x18dbb0:{const auto dst=GPR_U32(context,4),src=GPR_U32(context,5),size=GPR_U32(context,6);check(size==29&&dst>=0x4a5c30&&dst<0x4aa000&&src>=0x1e00000&&src<0x2000000-size);std::memmove(memory+dst,memory+src,size);SET_GPR_U32(context,2,dst);done();return;}
#endif
#ifdef REO_WEAPON_RESOURCES
    case 0x10a830:{const auto dst=GPR_U32(context,4);const auto format=weapon_string(memory,GPR_U32(context,5));check(dst>=0x1e00000&&dst<0x2000000-128&&(format=="weapon%02d"||format=="data/rom/motion/weapon/wp%02d.wmd"));const auto n=std::snprintf(reinterpret_cast<char*>(memory+dst),128,format.c_str(),std::bit_cast<std::int32_t>(GPR_U32(context,6)));check(n>=0&&n<128);SET_GPR_U32(context,2,n);done();return;}
    case 0x1cc8f0:{const auto name=weapon_string(memory,GPR_U32(context,4));const auto dst=GPR_U32(context,5);check(dst>=0x749180&&dst<0x74b180&&(dst-0x749180)%2048==0&&GPR_U32(context,6)==1&&GPR_U32(context,7)==0);bool found{};for(const auto& weapon:owned_weapons){std::array<char,128> expected{};std::snprintf(expected.data(),expected.size(),"data/rom/motion/weapon/wp%02d.wmd",weapon.selector);if(name==expected.data()){check(weapon.bytes.size()<=2048);std::memcpy(memory+dst,weapon.bytes.data(),weapon.bytes.size());found=true;break;}}check(found);++weapon_file_reads;SET_GPR_U32(context,2,0);done();return;}
#endif
    case 0x18dc50:check(!allocated&&GPR_U32(context,5)==4&&GPR_U32(context,4)<0x100000);allocated=true;++heap_allocations;SET_GPR_U32(context,2,1);done();return;
    case 0x18dca0:check(allocated&&GPR_U32(context,4)==1);SET_GPR_U32(context,2,heap);done();return;
    case 0x18dc90:check(allocated&&GPR_U32(context,4)==1);allocated=false;++heap_releases;done();return;
    case 0x1b10c0:case 0x1b1110:check(GPR_U32(context,4)==1);done();return;
#include "original_dispatch.hpp"
    default:throw std::runtime_error("Unadmitted periodic visual source call "+std::to_string(context->pc));
    }
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#include "original_visuals.cpp"
#pragma GCC diagnostic pop
R5900Context call(std::uint8_t* memory,std::uint32_t function,std::array<std::uint32_t,7> args={},float f12=0){
    R5900Context context;context.pc=function;SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x100);
    for(unsigned i=0;i<args.size();++i){SET_GPR_U32(&context,4+i,args[i]);}context.f[12]=f12;PS2Runtime runtime;
    original_transform_port(memory,&context,&runtime);
    if(context.pc!=0x100||GPR_U32(&context,29)!=0x1f00000)throw std::runtime_error("Original visual return function="+std::to_string(function)+" pc="+std::to_string(context.pc)+" sp="+std::to_string(GPR_U32(&context,29)));
    check(context.pc==0x100&&GPR_U32(&context,29)==0x1f00000);return context;
}
std::vector<std::vector<std::byte>> load(const char* path){
    std::ifstream source(path,std::ios::binary);std::uint32_t n{};source.read(reinterpret_cast<char*>(&n),4);check(n==12);std::vector<std::vector<std::byte>> data;
    for(unsigned i=0;i<n;++i){std::uint32_t size{};source.read(reinterpret_cast<char*>(&size),4);check(size&&size<0x200000);data.emplace_back(size);source.read(reinterpret_cast<char*>(data.back().data()),size);check(bool(source));}return data;
}
void prepare(std::uint8_t* memory,std::span<const std::byte> nbd,std::span<const std::byte> efdata){
    owned_constants(memory);
    std::memcpy(memory+0x100000,nbd.data(),nbd.size());std::memcpy(memory+0xa00000,efdata.data(),efdata.size());
    std::memcpy(memory+0x3926d0,efdata.data(),1024);
    const auto raw_model=0x100000+get<std::uint32_t>(memory,0x100014),raw_forest=0x100000+get<std::uint32_t>(memory,0x100024);
    const auto count=call(memory,0x1a31b0,{raw_model});put(memory,model+0x808,parts);
    for(unsigned i=0;i<GPR_U32(&count,2);++i){const auto c=call(memory,0x1a34b0,{raw_model,i});put(memory,parts+152*i+4,GPR_U32(&c,2));call(memory,0x1a3500,{raw_model,i,parts+152*i+8});}
    put(memory,0x32440c,std::uint32_t(0x400000));call(memory,0x1d3350,{model,raw_forest,0});
    put(memory,0x392670+0x18,model);put(memory,0x392670+0x1c,std::uint32_t(0xa00400));put(memory,0x324444,child_pool);call(memory,0x651850);
}
struct Live {std::uint32_t original;std::shared_ptr<s::PeriodicVisual> visual;};
struct CapturingEmitter final:s::PeriodicEmitter {
    e::PeriodicVisuals& owner;std::vector<Live>& live;std::uint8_t* memory;
    CapturingEmitter(e::PeriodicVisuals& o,std::vector<Live>& l,std::uint8_t* m):owner(o),live(l),memory(m){}
    bool admitted()const noexcept override{return owner.admitted();}
    bool bound_to(const reo::native::gameplay_session::Random& random)const noexcept override{return owner.bound_to(random);}
    s::EmissionResult emit(const s::PeriodicEmission& request)noexcept override{
        auto result=owner.emit(request);if(result.status==s::EmissionStatus::completed){live.insert(live.begin(),{get<std::uint32_t>(memory,0x3b5848),result.visual});++created;}return result;
    }
};
void compare(e::PeriodicVisuals& owner,std::span<const Live> live,const std::uint8_t* memory){
    const auto frame=owner.retain();check(frame&&frame->visuals.size()==live.size()&&owner.size()==live.size());
    std::size_t count{};
    for(std::size_t j=0;j<live.size();++j){const auto at=live[j].original;const auto& output=frame->visuals[j];
        check(output.visible==(memory[at+1]!=0));check(output.pieces.size()==memory[at+0x31]);count+=output.pieces.size();
        check(live[j].visual->delay==get<std::int16_t>(memory,at+0xc)&&live[j].visual->remaining==get<std::int16_t>(memory,at+0xe));
        for(std::size_t i=0;i<output.pieces.size();++i){const auto& part=output.pieces[i];const auto child=get<std::uint32_t>(memory,at+0x134+4*std::uint32_t(i));
            if(!output.visible)continue;
            check(part.visible==(memory[at+0xf4+i]!=0));if(!part.visible)continue;
            check(part.root==get<std::uint16_t>(memory,child+2)&&part.material==memory[child+1]);check(part.flags==get<std::uint32_t>(memory,child+4));
            check(std::memcmp(&part.parameters.translation,memory+child+0x24,12)==0);check(std::memcmp(part.parameters.rotation.data(),memory+child+0x30,6)==0);check(std::memcmp(&part.parameters.scale,memory+child+0x38,12)==0);
            const auto* mesh=output.bank->geometry().material(part.root,part.material);check(mesh&&part.mesh<std::size_t(output.bank->geometry().meshes().size()));
            for(std::size_t slot=0;slot<mesh->indices.size();++slot){check(std::bit_cast<std::uint32_t>(part.material_values[slot])==get<std::uint32_t>(memory,child+0x50+4*std::uint32_t(slot)));}
            check(std::memcmp(&part.parameters208,memory+child+0xc,12)==0);++piece_cases;
        }
    }
    check(owner.piece_count()==count);check(std::size_t(256-get<std::uint16_t>(memory,0x3b5820))==count);check(std::size_t(168-get<std::uint16_t>(memory,0x3b5828))==live.size());
}
#ifdef REO_RESOURCE_PULSES
#include "tools/native_reconstruction/resource_pulses_tests.inc"
#endif
#ifdef REO_RESOURCE_STATIC
#include "tools/native_reconstruction/resource_static_tests.inc"
#endif
#ifdef REO_RESOURCE_FACTORY
#include "tools/native_reconstruction/resource_factory_tests.inc"
#endif
#ifdef REO_RESOURCE_PLACEMENT
#include "tools/native_reconstruction/resource_placement_tests.inc"
#endif
#ifdef REO_RESOURCE_DELAYED
#include "tools/native_reconstruction/resource_delayed_tests.inc"
#endif
#ifdef REO_RESOURCE_ACTIONS
#include "tools/native_reconstruction/resource_actions_tests.inc"
#endif
#ifdef REO_RESOURCE_INVENTORY
#include "tools/native_reconstruction/resource_inventory_tests.inc"
#endif
#ifdef REO_WEAPON_RESOURCES
#include "tools/native_reconstruction/weapon_resources_tests.inc"
#endif
int main(int argc,char** argv)try{
    check(argc==
#ifdef REO_RESOURCE_STATIC
#ifdef REO_WEAPON_RESOURCES
    5
#elif defined(REO_RESOURCE_FACTORY)
        4
#else
        3
#endif
#else
        2
#endif
    );const auto corpus=load(argv[1]);std::vector<std::uint8_t> ram(0x2000000);auto* memory=ram.data();
    for(unsigned asset=0;asset<corpus.size();asset+=2){
        auto bank=e::EffectBank::import(corpus[asset],corpus[asset+1]);++banks;
        for(unsigned profile=0;profile<3;++profile){
            std::fill(ram.begin(),ram.end(),0);prepare(memory,corpus[asset],corpus[asset+1]);e::PeriodicVisuals owner(bank);std::vector<Live> live;
            const auto emit=[&](unsigned serial){
                const s::PeriodicEmission request{std::uint16_t(36+serial%3),{float(int(serial%41)-20)*3.5f,float(int(serial%19)-9),float(serial%73)*2.25f},0x1a193};
                put(memory,0x70000,request.position);auto result=call(memory,0x6525d0,{0,0x70000,0,request.descriptor,0,request.flags,0x6535c0});const auto at=GPR_U32(&result,2);auto native=owner.emit(request);
                check(at?(native.status==s::EmissionStatus::completed&&native.visual):(native.status==s::EmissionStatus::pool_full&&!native.visual));
                if(!at)return;
                const auto delay=profile==1?std::int16_t(serial%9):std::int16_t(0);const float distance=profile==2?float(int(serial%37)-18):30.f;
                native.visual->position=request.position;native.visual->delay=delay;native.visual->scale=distance;put(memory,at+0x38,request.position);put(memory,at+0xc,delay);put(memory,at+0xf0,distance);
                live.insert(live.begin(),{at,std::move(native.visual)});++created;
            };
            if(profile==2){for(unsigned i=0;i<170;++i)emit(i);check(owner.size()==168&&owner.piece_count()==256);}
            for(unsigned tick=0;tick<400;++tick){
                if(profile!=2&&tick%3==0)emit(tick);
                const m::Vector camera{float(int(tick%101)-50),float(int(tick%29)-14),float(tick%139)};put(memory,0x324138,camera);
                for(const auto& value:live){call(memory,0x6535c0,{value.original});}
                const auto before=live.size();live.erase(std::remove_if(live.begin(),live.end(),[&](const auto& value){return memory[value.original]==0;}),live.end());expired+=unsigned(before-live.size());
                const auto report=owner.update(camera);check(report.status==e::VisualStatus::completed);compare(owner,live,memory);++updates;
                if(tick%17==0&&!live.empty()){
                    const auto retained=owner.retain();const auto first=retained->visuals.front();const auto id=first.id;const auto oldbank=first.bank;
                    call(memory,0x652d60,{live.front().original});call(memory,0x651d00,{live.front().original});check(owner.retire(id));check(!owner.retire(id));live.erase(live.begin());check(first.bank==oldbank&&retained->visuals.front().id==id);
                }
            }
            const auto retained=owner.retain();owner.close();owner.close();check(owner.size()==0&&owner.piece_count()==0&&!owner.admitted()&&!owner.retain());check(bool(retained));check(owner.update({}).status==e::VisualStatus::closed);
        }
    }
    for(unsigned i=0;i<65536;++i){
        const m::Vector p{float(int(i%67)-33)*.125f,float(int(i%59)-29),float(i%43)*.25f};const auto camera=i%7==0?p:m::Vector{float(i%29),float(int(i%47)-23)*.5f,float(i%79)};const float distance=float(int(i%101)-50)*.25f;
        put(memory,0x71000,p);put(memory,0x324138,camera);call(memory,0x652ce0,{0x72000,0x70fdc},distance);const auto result=e::toward_camera(p,camera,distance);check(std::memcmp(&result,memory+0x71000,12)==0);++camera_cases;
    }
    {
        auto bank=e::EffectBank::import(corpus[0],corpus[1]);std::fill(ram.begin(),ram.end(),0);prepare(memory,corpus[0],corpus[1]);e::PeriodicVisuals owner(bank);
        for(unsigned seed=0;seed<65536;++seed){
            put(memory,0x70000,m::Vector{1,2,3});const auto result=call(memory,0x6525d0,{0,0x70000,0,36,0,0x1a193,0x6535c0});const auto at=GPR_U32(&result,2);auto native=owner.emit({36,{1,2,3}});check(at&&native.visual);
            const auto delay=std::bit_cast<std::int16_t>(std::uint16_t(seed)),remaining=std::bit_cast<std::int16_t>(std::uint16_t(seed*257));native.visual->delay=delay;native.visual->remaining=remaining;native.visual->scale=0;put(memory,at+0xc,delay);put(memory,at+0xe,remaining);put(memory,at+0xf0,0.f);
            put(memory,0x324138,m::Vector{10,20,30});call(memory,0x6535c0,{at});check(owner.update({10,20,30}).status==e::VisualStatus::completed);
            check(native.visual->delay==get<std::int16_t>(memory,at+0xc)&&native.visual->remaining==get<std::int16_t>(memory,at+0xe));
            const auto frame=owner.retain();if(memory[at]){check(frame->visuals.size()==1&&frame->visuals[0].visible==(memory[at+1]!=0));call(memory,0x652d60,{at});call(memory,0x651d00,{at});check(owner.retire(frame->visuals[0].id));}else check(frame->visuals.empty());
            ++signed_timer_cases;
        }
    }
    // The real periodic task now emits through this exact visual/resource
    // owner; no successful visual fixture substitutes for6525D0 in this chain.
    for(unsigned asset=0;asset<corpus.size();asset+=2){
        auto bank=e::EffectBank::import(corpus[asset],corpus[asset+1]);
        for(unsigned profile=0;profile<8;++profile){
            std::fill(ram.begin(),ram.end(),0);prepare(memory,corpus[asset],corpus[asset+1]);e::PeriodicVisuals owner(bank);std::vector<Live> live;live.reserve(168);CapturingEmitter emitter(owner,live,memory);
            s::FlagState flags;reo::native::gameplay_session::Random random;random.restore({std::uint16_t(profile*991),std::uint16_t(0x918a^profile),std::uint8_t(profile)});
            put(memory,0x3244b0,random.state().primary);put(memory,0x3244b8,random.state().secondary);put(memory,0x2b8de8,random.state().observed);
            s::PeriodicState state;state.position={float(profile),-5,17};put(memory,0x10000+0x70,state.position);put(memory,0x10000+0x28,std::uint32_t(0x20000));put(memory,0x20000+0x52,std::uint16_t(0x8000));
            for(unsigned tick=0;tick<200;++tick){
                if(tick==180){flags.write(s::FlagBank::bounded_halfword,0,true);put(memory,0x4bac50,std::uint16_t(1));}
                task_retired=false;call(memory,0x5d9680,{0x10000});const auto step=s::update_periodic(state,0x8000,flags,random,emitter);check(step.status==s::PeriodicStatus::completed&&step.retire==task_retired);
                check(state.phase==memory[0x10000+8]&&state.timer==get<std::int16_t>(memory,0x10000+0xc)&&state.packed==get<std::int16_t>(memory,0x10000+0xe));
                const auto rng=random.state();check(rng.primary==get<std::uint16_t>(memory,0x3244b0)&&rng.secondary==get<std::uint16_t>(memory,0x3244b8)&&rng.observed==memory[0x2b8de8]);
                put(memory,0x324138,m::Vector{10,20,30});for(const auto& value:live){call(memory,0x6535c0,{value.original});}
                live.erase(std::remove_if(live.begin(),live.end(),[&](const auto& value){return memory[value.original]==0;}),live.end());
                check(owner.update({10,20,30}).status==e::VisualStatus::completed);compare(owner,live,memory);++task_cases;if(step.retire)break;
            }
        }
    }
#ifdef REO_RESOURCE_PULSES
    compare_resource_pulses(corpus,ram);
#endif
#ifdef REO_RESOURCE_STATIC
    compare_resource_static(argv[2],ram);
#endif
#ifdef REO_RESOURCE_FACTORY
    compare_resource_factory(argv[2],argv[3],ram);
#endif
#ifdef REO_RESOURCE_PLACEMENT
    compare_resource_placement(argv[2],argv[3],ram);
#endif
#ifdef REO_RESOURCE_DELAYED
    compare_resource_delayed(argv[2],argv[3],ram);
#endif
#ifdef REO_RESOURCE_ACTIONS
    compare_resource_actions(argv[2],argv[3],ram);
#endif
#ifdef REO_RESOURCE_INVENTORY
    compare_resource_inventory(argv[2],argv[3],ram);
#endif
#ifdef REO_WEAPON_RESOURCES
    compare_weapon_resources(argv[4],ram);
#endif
    auto bank=e::EffectBank::import(corpus[0],corpus[1]);e::PeriodicVisuals owner(bank);check(owner.emit({35,{}}).status==s::EmissionStatus::unavailable);check(owner.emit({36,{},1}).status==s::EmissionStatus::unavailable);
    check(owner.emit({36,{std::numeric_limits<float>::quiet_NaN(),0,0}}).status==s::EmissionStatus::unavailable);check(owner.update({std::numeric_limits<float>::quiet_NaN(),0,0}).status==e::VisualStatus::invalid_camera&&owner.size()==0);
    std::atomic<bool> done{},bad{};std::atomic<unsigned> reads{};
    std::thread reader([&]{std::uint64_t revision{};while(!done.load()){const auto frame=owner.retain();if(!frame){std::this_thread::yield();continue;}if(frame->revision<revision)bad=true;revision=frame->revision;for(const auto& visual:frame->visuals)if(!visual.bank||visual.bank->geometry().roots().empty())bad=true;++reads;}});
    for(unsigned i=0;i<2000;++i){if(i%5==0)check(owner.emit({36,{}}).status==s::EmissionStatus::completed);check(owner.update({10,20,30}).status==e::VisualStatus::completed);if(i%10==0)std::this_thread::yield();}
    done=true;reader.join();check(!bad&&reads>0);owner.close();bank.reset();check(!owner.retain());
    std::cout<<"{\"checks\":"<<checks<<",\"banks\":"<<banks<<",\"updates\":"<<updates<<",\"created\":"<<created<<",\"expired\":"<<expired<<",\"piece_cases\":"<<piece_cases<<",\"camera_cases\":"<<camera_cases<<",\"signed_timer_cases\":"<<signed_timer_cases<<",\"task_cases\":"<<task_cases
#ifdef REO_RESOURCE_PULSES
    <<",\"resource_pulse_frames\":"<<resource_pulse_frames<<",\"resource_pulse_emissions\":"<<resource_pulse_emissions<<",\"resource_pulse_refusals\":"<<resource_pulse_refusals
#endif
#ifdef REO_RESOURCE_STATIC
    <<",\"static_banks\":"<<static_banks<<",\"static_roots\":"<<static_roots<<",\"static_matrices\":"<<static_matrices<<",\"static_lookups\":"<<static_lookups<<",\"static_large_roots\":"<<static_large_roots<<",\"static_refusals\":"<<static_refusals
#endif
#ifdef REO_RESOURCE_FACTORY
    <<",\"factory_cases\":"<<factory_cases<<",\"factory_visible\":"<<factory_visible<<",\"factory_missing_geometry\":"<<factory_missing_geometry<<",\"factory_passes\":"<<factory_passes<<",\"factory_refusals\":"<<factory_refusals
#endif
#ifdef REO_RESOURCE_PLACEMENT
    <<",\"placement_cases\":"<<placement_cases<<",\"placement_owned\":"<<placement_owned<<",\"placement_refusals\":"<<placement_refusals<<",\"placement_full\":"<<placement_full<<",\"placement_floor_queries\":"<<placement_floor_queries
#endif
#ifdef REO_RESOURCE_DELAYED
    <<",\"delayed_constructors\":"<<delayed_constructors<<",\"delayed_frames\":"<<delayed_frames<<",\"delayed_rebuilds\":"<<delayed_rebuilds<<",\"delayed_refusals\":"<<delayed_refusals<<",\"delayed_full_cases\":"<<delayed_full_cases
#endif
#ifdef REO_RESOURCE_ACTIONS
    <<",\"resource_actions\":"<<resource_actions<<",\"resource_action_retirements\":"<<resource_action_retirements<<",\"resource_action_failures\":"<<resource_action_failures
#endif
#ifdef REO_RESOURCE_INVENTORY
    <<",\"inventory_lookups\":"<<inventory_lookups<<",\"inventory_removals\":"<<inventory_removals<<",\"inventory_compactions\":"<<inventory_compactions<<",\"inventory_insertions\":"<<inventory_insertions<<",\"inventory_detachments\":"<<inventory_detachments<<",\"inventory_refusals\":"<<inventory_refusals
#endif
#ifdef REO_WEAPON_RESOURCES
    <<",\"weapon_refreshes\":"<<weapon_refreshes<<",\"weapon_loaded_banks\":"<<weapon_loaded_banks<<",\"weapon_missing_banks\":"<<weapon_missing_banks<<",\"weapon_pcm_frames\":"<<weapon_pcm_frames<<",\"weapon_signal_samples\":"<<weapon_signal_samples<<",\"weapon_refusals\":"<<weapon_refusals<<",\"weapon_file_reads\":"<<weapon_file_reads
#endif
    <<",\"original_helper_calls\":"<<calls<<",\"heap_allocations\":"<<heap_allocations<<",\"heap_releases\":"<<heap_releases<<",\"concurrent_reader_pass\":true,\"game_run\":false}\n";
    return 0;
}catch(const std::exception& error){std::cerr<<error.what()
#ifdef REO_RESOURCE_PULSES
    <<" pulse frames="<<resource_pulse_frames<<" emissions="<<resource_pulse_emissions
#endif
#ifdef REO_RESOURCE_STATIC
    <<" static bank="<<static_banks<<" root="<<static_roots
#endif
#ifdef REO_RESOURCE_FACTORY
    <<" factory cases="<<factory_cases
#endif
#ifdef REO_RESOURCE_DELAYED
    <<" delayed constructors="<<delayed_constructors<<" frames="<<delayed_frames<<" rebuilds="<<delayed_rebuilds
#endif
#ifdef REO_RESOURCE_INVENTORY
    <<" inventory compact="<<inventory_compactions<<" remove="<<inventory_removals<<" detach="<<inventory_detachments
#endif
    <<'\n';return 1;}
