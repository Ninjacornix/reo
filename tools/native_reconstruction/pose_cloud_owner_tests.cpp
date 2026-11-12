#include "game/native/gameplay_world/pose_cloud.hpp"
#include "game/native/gameplay_world/resource_pose_work.hpp"
#include "game/native/gameplay_effects/periodic_visuals.hpp"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <fstream>
#include <iostream>
#include <source_location>
#include <vector>
namespace g=reo::native::gameplay_world;namespace m=reo::native::transform_math;namespace e=reo::native::gameplay_effects;namespace l=reo::native::gameplay_lighting;namespace s=reo::native::gameplay_scenario;namespace d=reo::native::gameplay_collision::delivery;namespace t=reo::native::gameplay_tasks;
unsigned checks{},calls{},cases{},frames{},created{},visual_requests{},missing_visuals{},task_requests{},guards{},profile_refusals{};
constexpr unsigned base=0x3ec410,stride=0x1f0,parent_at=0x20000,position_at=0x22000;
void check(bool v,std::source_location p=std::source_location::current()){++checks;if(!v)throw std::runtime_error("Pose cloud owner "+std::to_string(p.line())+" case "+std::to_string(cases));}
template<class T>T get(const std::uint8_t* p,unsigned at){return transform_read<T>(p,at);}
template<class T>void put(std::uint8_t* p,unsigned at,T v){transform_write(p,at,v);}
struct Rig {
    std::shared_ptr<g::Session> session{std::make_shared<g::Session>()};g::World world;g::PoseWorkPool pool;
    s::Lighting lighting;l::Pool lights{lighting};t::Scheduler tasks;l::TimedLights timed;
    e::PeriodicVisuals visuals;g::PoseCloudUpdates updates;g::actors::EntityId parent;
    Rig(std::shared_ptr<const e::EffectBank> bank):world({{g::input::Remap{1,2,4}},1,{256,UINT64_MAX}},session),pool(world),timed(world,tasks,lights),visuals(std::move(bank),session->random),updates(world,pool,visuals,timed){parent=world.spawn_primary(0,std::make_unique<g::Actor>()).id;check(bool(parent));}
};
Rig* source{};
std::shared_ptr<const e::EffectBank> source_bank;
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;switch(context->pc){
    case 0x107c68:{const auto at=GPR_U32(context,4),size=GPR_U32(context,6);check(at>=base&&size<=base+64*stride-at&&GPR_U32(context,5)==0);std::memset(memory+at,0,size);SET_GPR_U32(context,2,at);break;}
    case 0x5da2c0:check(GPR_U32(context,4)>=base&&GPR_U32(context,4)<base+64*stride&&GPR_U32(context,5)==0x6a&&GPR_U32(context,6)==0);SET_GPR_U32(context,2,0);break;
    case 0x6525c0:{check(source&&!GPR_U32(context,4)&&GPR_U32(context,6)==0xc0&&GPR_U32(context,7)==0x55&&!GPR_U32(context,8)&&GPR_U32(context,9)==0x1a193);e::WorkRequest request;request.position=get<m::Vector>(memory,GPR_U32(context,5));request.effect=std::uint16_t(GPR_U32(context,7));request.child_mask=GPR_U32(context,6);request.variant=std::int16_t(GPR_U32(context,8));const auto made=source->visuals.create(request);if(made.status==e::WorkStatus::unavailable){(void)source_bank->bind(request.effect,request.variant);throw std::runtime_error("Native cloud visual unavailable outside bank binding");}check(made.status==e::WorkStatus::completed||made.status==e::WorkStatus::resource_missing||made.status==e::WorkStatus::pool_full);missing_visuals+=made.status==e::WorkStatus::resource_missing;++visual_requests;SET_GPR_U32(context,2,0);break;}
    case 0x6b2680:{check(source&&GPR_U32(context,4)==parent_at);const auto p=get<m::Vector>(memory,GPR_U32(context,5));const auto made=source->timed.create(source->parent,{p.x,p.y,p.z});check(made.status==l::TimedStatus::completed||made.status==l::TimedStatus::skipped||made.status==l::TimedStatus::task_full);++task_requests;break;}
#include "original_dispatch.hpp"
    default:throw std::runtime_error("Unadmitted pose cloud owner helper "+std::to_string(context->pc));
    }context->pc=GPR_U32(context,31);
}
void invoke(std::uint8_t* memory,unsigned pc,std::array<unsigned,7> args={}){R5900Context c;PS2Runtime runtime;c.pc=pc;SET_GPR_U32(&c,29,0x1f00000);SET_GPR_U32(&c,31,0x1234);for(unsigned i=0;i<7;++i)SET_GPR_U32(&c,4+i,args[i]);original_transform_port(memory,&c,&runtime);check(c.pc==0x1234&&GPR_U32(&c,29)==0x1f00000);}
std::vector<std::byte> file(const char* path){std::ifstream in(path,std::ios::binary);const std::vector<char> raw{std::istreambuf_iterator<char>(in),{}};check(!raw.empty());std::vector<std::byte> out(raw.size());std::memcpy(out.data(),raw.data(),raw.size());return out;}
std::vector<std::vector<std::byte>> corpus(const char* path){std::ifstream in(path,std::ios::binary);unsigned count{};in.read(reinterpret_cast<char*>(&count),4);check(count==12);std::vector<std::vector<std::byte>> out;for(unsigned i=0;i<count;++i){unsigned size{};in.read(reinterpret_cast<char*>(&size),4);check(size&&size<10000000);out.emplace_back(size);in.read(reinterpret_cast<char*>(out.back().data()),size);check(bool(in));}return out;}
int main(int argc,char** argv)try{
    check(argc==3);const auto catalog=d::Catalog::import(file(argv[1]));const auto assets=corpus(argv[2]);std::vector<std::uint8_t> ram(0x2000000);auto* memory=ram.data();owned_constants(memory);
    for(unsigned asset=0;asset<assets.size();asset+=2){const auto bank=e::EffectBank::import(assets[asset],assets[asset+1]);source_bank=bank;
        // Some actual banks map55 to raw group255 whose apparent part table is
        // unadmitted asset data. Preserve and test the real refusal; do not
        // manufacture a group or claim a successful original lifecycle there.
        bool admitted=true;if(bank->geometry().resolve(0x55)){try{(void)bank->bind(0x55,0);}catch(const std::invalid_argument&){admitted=false;}}
        if(!admitted){
            Rig native(bank);s::SceneResources resources;s::ResourceTemplates templates;d::Packets packets;g::ResourcePoseWork poses(native.world,native.pool,resources,templates,packets,catalog);const m::Vector point{1,2,3};const auto made=poses.attach(native.parent,0x6a,20,0,nullptr,&point,2);check(made.status==g::PoseWorkStatus::completed);const auto actor=native.pool.resolve(made.work);check(actor&&actor->primary==0&&actor->pose_work->lifetime==2);const auto pass=native.pool.update(&native.updates);check(pass.status==g::PoseWorkStatus::unavailable&&actor->primary==1&&!actor->visible&&actor->pose_work->lifetime==1&&actor->pose_work->timer==0&&native.visuals.size()==0&&native.tasks.size()==0&&packets.size()==1);check(native.pool.update(&native.updates).retired==1);++profile_refusals;continue;
        }
        for(unsigned n=0;n<24;++n){
            Rig native(bank),original(bank);source=&original;s::SceneResources resources;s::ResourceTemplates templates;d::Packets packets;g::ResourcePoseWork poses(native.world,native.pool,resources,templates,packets,catalog);const auto parent=native.world.resolve(native.parent),reference=original.world.resolve(original.parent);parent->primary=reference->primary=std::uint8_t(n%3==0?2:1);parent->secondary=reference->secondary=std::uint8_t(n%3==0?11:0);parent->surface_material=reference->surface_material=std::uint8_t(n);native.session->clock_mode=original.session->clock_mode=memory[0x3243cc]=std::uint8_t(n%2);
            native.session->random.restore({std::uint16_t(n*13),std::uint16_t(asset*31),std::uint8_t(n)});original.session->random.restore(native.session->random.state());invoke(memory,0x581f50);std::array<g::actors::EntityId,64> ids;const unsigned count=n%8==0?64:n%8==1?4:1;
            for(unsigned i=0;i<count;++i){const m::Vector point{float(int(i)-32)*.25f,float(n)*.5f,-7};put(memory,position_at,point);invoke(memory,0x5822a0,{parent_at,0,20,0x6a,0,position_at,2});const auto made=poses.attach(native.parent,0x6a,20,0,nullptr,&point,2);check(made.status==g::PoseWorkStatus::completed);const auto physical=native.pool.physical_slot(made.work);check(bool(physical));ids[*physical]=made.work;check(native.pool.remaining()==get<std::uint16_t>(memory,0x3b55e0));++created;}
            for(unsigned frame=0;frame<76;++frame){
                if(frame==3&&n%4==1){parent->primary=reference->primary=0;}
                invoke(memory,0x5821f0);const auto updated=native.pool.update(&native.updates);check(updated.status==g::PoseWorkStatus::completed&&native.pool.remaining()==get<std::uint16_t>(memory,0x3b55e0));
                for(unsigned slot=0;slot<64;++slot)if(ids[slot]){const auto actor=native.pool.resolve(ids[slot]);const auto at=base+stride*slot;check(bool(actor)==bool(memory[at]));if(actor){const auto& state=*actor->pose_work;check(actor->visible==bool(memory[at+1])&&actor->primary==memory[at+8]&&actor->auxiliary_status==memory[at+0x115]&&state.timer==get<std::int16_t>(memory,at+12)&&state.lifetime==get<std::int16_t>(memory,at+18));}}
                check(native.visuals.size()==original.visuals.size()&&native.visuals.piece_count()==original.visuals.piece_count()&&native.tasks.size()==original.tasks.size()&&native.lights.size()==original.lights.size());
                const auto visual=native.visuals.update({0,1,0}),expected=original.visuals.update({0,1,0});check(visual.status==e::VisualStatus::completed&&expected.status==e::VisualStatus::completed&&visual.visited==expected.visited&&visual.pieces==expected.pieces&&visual.retired==expected.retired);check(native.session->random.state()==original.session->random.state());
                check(native.tasks.run(t::Pass::update).status==t::Status::completed&&original.tasks.run(t::Pass::update).status==t::Status::completed);const auto a=native.lights.snapshot(),b=original.lights.snapshot();check(a.size()==b.size());for(unsigned i=0;i<a.size();++i)check(std::memcmp(&a[i].value.descriptor,&b[i].value.descriptor,sizeof(l::Definition))==0);++frames;
            }
            check(native.pool.remaining()==64&&get<std::uint16_t>(memory,0x3b55e0)==64&&native.tasks.size()==0&&original.tasks.size()==0);check(packets.size()==count);source=nullptr;++cases;
        }
    }
    check(visual_requests&&task_requests&&profile_refusals==1);std::cout<<"{\"checks\":"<<checks<<",\"cases\":"<<cases<<",\"constructors\":"<<created<<",\"frames\":"<<frames<<",\"visual_requests\":"<<visual_requests<<",\"missing_visuals\":"<<missing_visuals<<",\"light_requests\":"<<task_requests<<",\"profile_refusals\":"<<profile_refusals<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
