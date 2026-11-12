#include "game/native/gameplay_world/resource_pose_work.hpp"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <fstream>
#include <iostream>
#include <source_location>
#include <stdexcept>
#include <vector>
namespace g=reo::native::gameplay_world;namespace m=reo::native::transform_math;namespace s=reo::native::gameplay_scenario;namespace d=reo::native::gameplay_collision::delivery;
unsigned checks{},calls{},pool_cases{},factory_cases{},traversal_cases{},guards{};
constexpr unsigned base=0x3ec410,stride=0x1f0,parent=0x20000;
std::int8_t source_action{};unsigned source_flags{},expected_resource{},lookups{},template_reads{},packet_calls{},packet_descriptor{};
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Pose work "+std::to_string(at.line()));}
bool pose_mutation_port(std::uint8_t*,R5900Context*);
template<class T>T get(const std::uint8_t* memory,unsigned at){return transform_read<T>(memory,at);}
template<class T>void put(std::uint8_t* memory,unsigned at,T value){transform_write(memory,at,value);}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;
    if(pose_mutation_port(memory,context)){context->pc=GPR_U32(context,31);return;}
    switch(context->pc){
    case 0x107c68:{const auto at=GPR_U32(context,4),size=GPR_U32(context,6);check(at>=base&&at<=base+64*stride&&size<=base+64*stride-at&&GPR_U32(context,5)==0);std::memset(memory+at,0,size);SET_GPR_U32(context,2,at);break;}
    case 0x5b4d50:check(GPR_U32(context,4)==expected_resource);++lookups;SET_GPR_U32(context,2,std::uint8_t(source_action));break;
    case 0x5b4380:check(GPR_U32(context,4)==expected_resource);++template_reads;put(memory,0x50000,source_flags);SET_GPR_U32(context,2,0x50000);break;
    case 0x5da2c0:check(GPR_U32(context,4)>=base&&GPR_U32(context,4)<base+64*stride&&GPR_U32(context,6)==0);++packet_calls;packet_descriptor=GPR_U32(context,5);SET_GPR_U32(context,2,0);break;
#include "original_dispatch.hpp"
    default:throw std::runtime_error("Unadmitted pose helper "+std::to_string(context->pc));
    }
    context->pc=GPR_U32(context,31);
}
R5900Context invoke(std::uint8_t* memory,unsigned pc,std::array<unsigned,4> args={}){
    R5900Context context;PS2Runtime runtime;context.pc=pc;SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x1234);for(unsigned i=0;i<args.size();++i)SET_GPR_U32(&context,4+i,args[i]);original_transform_port(memory,&context,&runtime);check(context.pc==0x1234&&GPR_U32(&context,29)==0x1f00000);return context;
}
std::vector<unsigned> list(const std::uint8_t* memory,bool reverse=false){std::vector<unsigned> result;for(auto at=get<unsigned>(memory,reverse?0x3b55f0:0x3b55e8);at;at=get<unsigned>(memory,at+(reverse?0x1c:0x20))){check(result.size()<64);result.push_back(at);}return result;}
void topology(g::PoseWorkPool& pool,const std::array<g::actors::EntityId,64>& ids,const std::uint8_t* memory){
    check(pool.remaining()==get<std::uint16_t>(memory,0x3b55e0));const auto original=list(memory);
    check(original.size()==64-pool.remaining());check(pool.head()==(original.empty()?g::actors::EntityId{}:ids[(original.front()-base)/stride]));check(pool.tail()==(original.empty()?g::actors::EntityId{}:ids[(original.back()-base)/stride]));
    for(auto at:original){const auto physical=(at-base)/stride;check(pool.physical_slot(ids[physical])==physical);const auto actor=pool.resolve(ids[physical]);check(actor&&actor->pose_work&&actor->contact.authored_id==memory[at+6]);}
}
std::vector<std::byte> file(const char* path){std::ifstream in(path,std::ios::binary);const std::vector<char> raw{std::istreambuf_iterator<char>(in),{}};check(!raw.empty());std::vector<std::byte> out(raw.size());std::memcpy(out.data(),raw.data(),raw.size());return out;}
void pools(std::uint8_t* memory){
    auto session=std::make_shared<g::Session>();g::World world({{g::input::Remap{1,2,4}},1,{256,UINT64_MAX}},session);g::PoseWorkPool pool(world);std::array<g::actors::EntityId,64> ids;
    invoke(memory,0x581f50);topology(pool,ids,memory);
    for(unsigned sequence=0;sequence<32;++sequence){
        for(unsigned n=0;n<64;++n){const bool prepend=(n+sequence)%3!=0;const auto raw=invoke(memory,0x581fe0,{unsigned(prepend)});const auto at=GPR_U32(&raw,2);const auto made=pool.allocate(prepend);check(made.status==g::PoseWorkStatus::completed);const auto physical=(at-base)/stride;ids[physical]=made.id;
            const auto actor=pool.resolve(made.id);check(actor&&!actor->active&&!actor->visible&&actor->category==0&&actor->slot==0&&actor->primary==0&&actor->secondary==0&&actor->phase==0&&actor->subphase==0);check(actor->pose_work->basis==m::Matrix{}&&!actor->pose_work->update_bound&&!actor->gauge_value&&!actor->contact_style_discriminator);topology(pool,ids,memory);++pool_cases;
        }
        const auto exhausted=invoke(memory,0x581fe0,{1});check(!GPR_U32(&exhausted,2)&&pool.allocate().status==g::PoseWorkStatus::full);++guards;
        while(pool.remaining()!=64){const auto original=list(memory);const auto at=original[(pool.remaining()*17+sequence)%original.size()];const auto physical=(at-base)/stride;const auto id=ids[physical];const auto retained=pool.resolve(id);retained->visible=true;memory[at+1]=1;const bool clear_visible=(pool.remaining()+sequence)%2;
            invoke(memory,clear_visible?0x582de0:0x5820f0,{at});check(pool.retire(id,clear_visible)==g::PoseWorkStatus::completed&&!retained->active&&retained->visible==bool(memory[at+1]));check(!pool.resolve(id)&&pool.retire(id)==g::PoseWorkStatus::invalid_identity);ids[physical]={};topology(pool,ids,memory);++pool_cases;
        }
        check(pool.reset()==g::PoseWorkStatus::completed);invoke(memory,0x581f50);topology(pool,ids,memory);
    }
    // Actual tail-to-head service executes the full lifetime gate and real
    // visibility callback; no simulated successful downstream operation.
    for(unsigned pattern=0;pattern<64;++pattern){
        for(unsigned n=0;n<64;++n){const auto raw=invoke(memory,0x581fe0,{1});const auto at=GPR_U32(&raw,2);const auto made=pool.allocate();const auto physical=(at-base)/stride;ids[physical]=made.id;const auto actor=pool.resolve(made.id);
            actor->active=true;actor->pose_work->update_bound=true;actor->pose_work->kind=std::uint8_t(n%4==0?0:n%4+2);actor->pose_work->lifetime=std::int16_t(1+(n+pattern)%5);actor->primary=std::uint8_t((n+pattern)%3);
            memory[at]=1;memory[at+4]=actor->pose_work->kind;memory[at+8]=actor->primary;put(memory,at+0x12,actor->pose_work->lifetime);put(memory,at+0x14,0x582b80u);
        }
        for(unsigned tick=0;tick<5;++tick){invoke(memory,0x5821f0);const auto report=pool.update();check(report.status==g::PoseWorkStatus::completed);
            for(auto at:list(memory)){const auto physical=(at-base)/stride;const auto actor=pool.resolve(ids[physical]);check(actor&&actor->active==bool(memory[at])&&actor->visible==bool(memory[at+1])&&actor->primary==memory[at+8]&&actor->pose_work->lifetime==get<std::int16_t>(memory,at+0x12));}
            ++traversal_cases;
        }
        check(pool.remaining()==64);check(pool.reset()==g::PoseWorkStatus::completed);invoke(memory,0x581f50);
    }
    auto made=pool.allocate();if(!made.id)throw std::runtime_error("Unbound allocation status="+std::to_string(unsigned(made.status)));auto actor=pool.resolve(made.id);actor->pose_work->lifetime=7;const auto unbound=pool.update();if(unbound.status!=g::PoseWorkStatus::unavailable||actor->pose_work->lifetime!=7)throw std::runtime_error("Unbound update status="+std::to_string(unsigned(unbound.status))+" life="+std::to_string(actor->pose_work->lifetime)+" bound="+std::to_string(actor->pose_work->update_bound));check(pool.reset()==g::PoseWorkStatus::completed);++guards;
    check(pool.close()==g::PoseWorkStatus::completed&&pool.allocate().status==g::PoseWorkStatus::closed);g::PoseWorkPool replacement(world);check(replacement.remaining()==64);++guards;
}
void constructors(std::uint8_t* memory,const d::Catalog& catalog){
    auto session=std::make_shared<g::Session>();g::World world({{g::input::Remap{1,2,4}},1,{256,UINT64_MAX}},session);world.room=7;auto actor=std::make_unique<g::Actor>();const auto owner=world.spawn_primary(0,std::move(actor)).id;check(bool(owner));const auto parent_actor=world.resolve(owner);g::PoseWorkPool pool(world);g::ResourceModels models;const auto model=models.create();check(model.status==g::ResourceModelStatus::completed);
    s::SceneResources resources;s::ResourceTemplates templates;d::Packets packets;g::ResourcePoseWork factory(world,pool,resources,templates,packets,catalog);std::vector<std::byte> encoded(56);const auto write=[&]<class T>(unsigned at,T value){std::memcpy(encoded.data()+at,&value,sizeof value);};write(0,3u);write(4,1u);write(16,32u);
    const auto basis=m::Matrix{{{{.5f,.25f,-.1f,7}},{{.2f,2,.4f,8}},{{.3f,-.2f,.7f,9}},{{31,-12,7,1}}}};const m::Vector point{7,-9.5f,17};put(memory,0x21000,point);put(memory,0x22000,basis);put(memory,0x231c0,basis);model.model->pose=basis;model.model->position={37,41,43};put(memory,0x23200,model.model->position);
    for(unsigned action=0;action<64;++action)for(unsigned flags:{0u,0x1000000u})for(unsigned profile=0;profile<16;++profile){
        invoke(memory,0x581f50);check(pool.reset()==g::PoseWorkStatus::completed);const bool full=profile&1,same_room=profile&2,have_model=profile&4;expected_resource=profile&8?0xabcd0003u:profile%3==0?0u:3u;
        source_action=expected_resource?std::int8_t(action):0;source_flags=flags;lookups=template_reads=packet_calls=0;write(32,flags);encoded[47]=std::byte(action);check(templates.load(encoded));
        s::SceneDescriptor descriptor;descriptor.active=1;descriptor.template_index=0;descriptor.instance_index=3;if(have_model)descriptor.primary=model.model;check(bool(resources.load(3,descriptor)));
        parent_actor->room=std::uint16_t(same_room?7:8);parent_actor->orientation={1,-2,32767,INT16_MIN};parent_actor->auxiliary_status=action*3+1;put(memory,parent+0x1e2,parent_actor->room);put(memory,0x3243dc,std::uint16_t(7));put(memory,parent+0x90,parent_actor->orientation);memory[parent+0x115]=std::uint8_t(parent_actor->auxiliary_status);put(memory,0x3c564c+3*60,have_model?0x23000u:0u);
        if(full)for(unsigned n=0;n<64;++n){invoke(memory,0x581fe0,{1});check(pool.allocate().status==g::PoseWorkStatus::completed);}
        invoke(memory,0x5823e0,{parent,0x22000,0x21000,expected_resource});const auto result=factory.create(owner,basis,point,expected_resource);check(lookups==1&&parent_actor->auxiliary_status==memory[parent+0x115]);
        const auto at=get<unsigned>(memory,0x3b55e8);const bool created=!full&&get<std::uint16_t>(memory,0x3b55e0)==63;
        check(bool(result.work)==created);check(pool.remaining()==get<std::uint16_t>(memory,0x3b55e0));
        if(created){const auto work=pool.resolve(result.work);check(work&&work->pose_work);const auto& state=*work->pose_work;
            check(result.status==g::PoseWorkStatus::completed&&state.update_bound&&work->active==bool(memory[at])&&work->category==memory[at+2]&&work->slot==memory[at+3]&&state.kind==memory[at+4]&&state.variant==memory[at+5]&&state.selector==memory[at+0x30]&&state.ordinal==memory[at+0x31]&&state.lifetime==get<std::int16_t>(memory,at+0x12));
            check(std::memcmp(&work->position,memory+at+0x38,12)==0&&std::memcmp(&state.basis,memory+at+0x50,64)==0&&std::memcmp(work->orientation.data(),memory+at+0x90,8)==0);check(work->contact.related==owner&&packet_calls==1&&template_reads==1);
            const auto packet=packets.acquire(result.packet);check(packet&&packet.state().delivery.source==result.work&&packet.state().definition==catalog.find(0,std::int32_t(packet_descriptor)));check(packets.release(result.packet));
        }else check(packet_calls==0&&template_reads==0&&(result.status==g::PoseWorkStatus::completed||result.status==g::PoseWorkStatus::full));
        ++factory_cases;
    }
}
#include "tools/native_reconstruction/pose_work_mutation_tests.inc"
#ifdef REO_RESOURCE_POSE_UPDATES
#include "tools/native_reconstruction/pose_work_updates_tests.inc"
#endif
int main(int argc,char** argv)try{
    check(argc==2);std::vector<std::uint8_t> memory(0x2000000);owned_constants(memory.data());pools(memory.data());mutations(memory.data());const auto catalog=d::Catalog::import(file(argv[1]));constructors(memory.data(),catalog);
#ifdef REO_RESOURCE_POSE_UPDATES
    resource_updates(memory.data(),catalog);
#endif
    std::cout<<"{\"checks\":"<<checks<<",\"pool_cases\":"<<pool_cases<<",\"factory_cases\":"<<factory_cases<<",\"traversal_cases\":"<<traversal_cases<<",\"mutation_cases\":"<<mutation_cases<<",\"mutation_callbacks\":"<<mutation_callbacks<<",\"guards\":"<<guards
#ifdef REO_RESOURCE_POSE_UPDATES
    <<",\"update_cases\":"<<update_cases<<",\"update_retirements\":"<<update_retirements<<",\"update_packets\":"<<update_packets
#endif
    <<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
