#include "game/native/gameplay_scenario/resource_collisions.hpp"
#include "reference.hpp"
#include "owned_constants.hpp"
#include <iostream>
#include <limits>
#include <source_location>
#include <vector>
namespace s=reo::native::gameplay_scenario;
namespace scene=reo::native::gameplay_scene;
namespace m=reo::native::transform_math;
unsigned checks{},footprints{},constructions{},replacements{},refusals{},calls{};
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Resource collision check line "+std::to_string(at.line()));}
template<class T>T read(const std::uint8_t* memory,unsigned at){return transform_read<T>(memory,at);}
template<class T>void put(std::uint8_t* memory,unsigned at,T value){transform_write(memory,at,value);}
void original_transform_port(std::uint8_t* ram,R5900Context* ctx,PS2Runtime* runtime){
    ++calls;switch(ctx->pc){
#include "dispatch.inc"
    case 0x107c68:{const auto at=GPR_U32(ctx,4),size=GPR_U32(ctx,6);check(at<=0x2000000&&size<=0x2000000-at);std::memset(ram+at,std::uint8_t(GPR_U32(ctx,5)),size);SET_GPR_U32(ctx,2,at);break;}
    case 0x107ab0:{const auto dst=GPR_U32(ctx,4),src=GPR_U32(ctx,5),size=GPR_U32(ctx,6);check(size==32&&dst>=0x3e10f0&&dst<0x3e72f0&&src>=0x1e00000&&src<0x2000000-size);std::memmove(ram+dst,ram+src,size);SET_GPR_U32(ctx,2,dst);break;}
    default:throw std::runtime_error("Unadmitted collision source call "+std::to_string(ctx->pc));
    }ctx->pc=GPR_U32(ctx,31);
}
R5900Context call(std::uint8_t* ram,unsigned address,std::array<unsigned,3> args={}){
    R5900Context ctx;PS2Runtime runtime;ctx.pc=address;SET_GPR_U32(&ctx,29,0x1f00000);SET_GPR_U32(&ctx,31,0x100);for(unsigned i=0;i<3;++i)SET_GPR_U32(&ctx,4+i,args[i]);original_transform_port(ram,&ctx,&runtime);check(ctx.pc==0x100&&GPR_U32(&ctx,29)==0x1f00000);return ctx;
}
constexpr unsigned descriptor=0x100000,output=0x110000;
void sync(std::uint8_t* memory,const s::SceneDescriptor& value){
    memory[descriptor+2]=value.instance_index;put(memory,descriptor+8,value.position);put(memory,descriptor+0x16,value.yaw);memory[descriptor+0x2c]=std::bit_cast<std::uint8_t>(value.shape_profile);
}
void compare(const scene::Record& record,const std::uint8_t* memory,unsigned raw){
    const auto proxy=scene::collision_view(record);check(std::memcmp(proxy.bounds.data(),memory+raw,32)==0);check(proxy.lower==read<std::int32_t>(memory,raw+32)&&proxy.upper==read<std::int32_t>(memory,raw+36));
    check(proxy.identifier==read<unsigned>(memory,raw+0x40)&&proxy.content_id==read<unsigned>(memory,raw+0x48));check(proxy.kind==memory[raw+0x30]&&proxy.priority==memory[raw+0x32]&&proxy.query_class==memory[raw+0x31]&&proxy.active==bool(memory[raw+0x3c])&&proxy.busy==bool(memory[raw+0x3d]));check(!record.owner&&!record.source);
}
int main()try{
    std::vector<std::uint8_t> ram(0x2000000);auto* memory=ram.data();owned_constants(memory);put(memory,0x294e00,m::identity());
    for(unsigned profile=0;profile<20;++profile)for(unsigned yaw=0;yaw<65536;++yaw){
        const m::Vector position{float(int(yaw%319)-159)+.75f,float(int(yaw%655)-327)-.5f,float(int(yaw%997)-498)+.25f};s::SceneDescriptor value;value.position=position;value.yaw=std::uint16_t(yaw);value.shape_profile=std::int8_t(profile);sync(memory,value);
        call(memory,0x5927f0,{descriptor,profile|0xabcd0000u,output});const auto shape=s::resource_footprint(position,std::uint16_t(yaw),std::int8_t(profile));check(std::memcmp(shape.bounds.data(),memory+output,32)==0);++footprints;
    }
    s::SceneResources resources;auto records=std::make_shared<scene::Records>();s::ResourceCollisions owner(resources,records);call(memory,0x5c1120);std::vector<std::shared_ptr<s::SceneRecordAttachment>> retained;
    for(unsigned i=0;i<128;++i){s::SceneDescriptor value;value.instance_index=std::uint8_t(i+17);value.position={float(int(i)*3)-.25f,float(int(i)-64)+.75f,float(i*13)+.5f};value.yaw=std::uint16_t(i*793);value.shape_profile=std::int8_t(i%20);const auto id=resources.load(i,value);check(bool(id));sync(memory,value);put(memory,descriptor+32,0u);call(memory,0x591860,{descriptor});const auto created=owner.replace(*id);check(created.status==s::ResourceCollisionStatus::completed&&created.attachment);const auto raw=read<unsigned>(memory,descriptor+32);check(raw);compare(records->acquire(created.attachment->identity())->value,memory,raw);retained.push_back(created.attachment);++constructions;
        // Replacing an existing secondary must free its slot before allocation,
        // including when the shared scene owner has reached capacity128.
        auto held=records->acquire(created.attachment->identity());value=*resources.get(*id);value.position.y+=1.25f;value.yaw=std::uint16_t(value.yaw+1223);check(resources.replace(*id,value)==s::SceneStatus::completed);sync(memory,value);call(memory,0x591860,{descriptor});const auto replaced=owner.replace(*id);check(replaced.status==s::ResourceCollisionStatus::completed&&replaced.attachment&&!created.attachment->current()&&held);compare(records->acquire(replaced.attachment->identity())->value,memory,read<unsigned>(memory,descriptor+32));retained.back()=replaced.attachment;++replacements;
        check(records->size()==128u-read<std::uint16_t>(memory,0x3b5150));
    }
    s::SceneDescriptor empty;empty.instance_index=129;const auto extra=resources.load(200,empty);sync(memory,empty);put(memory,descriptor+32,0u);call(memory,0x591860,{descriptor});check(read<unsigned>(memory,descriptor+32)==0&&owner.replace(*extra).status==s::ResourceCollisionStatus::full&&!resources.get(*extra)->secondary);++refusals;
    auto node=records->first();unsigned raw=read<unsigned>(memory,0x3b5160);for(unsigned i=0;i<128;++i){check(node&&raw);compare(node->value,memory,raw);node=node->next;raw=read<unsigned>(memory,raw+0x28);}check(!node&&!raw);
    s::SceneResources foreign;check(owner.replace(*foreign.slot(0)).status==s::ResourceCollisionStatus::invalid_identity);++refusals;
    auto other=std::make_shared<scene::Records>();const auto other_id=*other->create({});empty.secondary=std::make_shared<s::SceneRecordAttachment>(other,other_id);check(resources.replace(*extra,empty)==s::SceneStatus::completed);check(owner.replace(*extra).status==s::ResourceCollisionStatus::unavailable&&other->acquire(other_id)&&records->size()==128);++refusals;
    for(int profile:{-128,-1,20,127}){bool refused{};try{(void)s::resource_footprint({},0,std::int8_t(profile));}catch(const std::out_of_range&){refused=true;}check(refused);++refusals;}
    for(float bad:{std::numeric_limits<float>::infinity(),std::numeric_limits<float>::quiet_NaN(),2147483648.f}){bool refused{};try{(void)s::resource_footprint({bad,0,0},0,0);}catch(const std::exception&){refused=true;}check(refused);++refusals;}
    records->clear();for(const auto& capability:retained)check(!capability->current());check(records->size()==0);check(owner.replace(*resources.slot(0)).status==s::ResourceCollisionStatus::unavailable&&records->size()==0);++refusals;
    bool rejected{};try{s::ResourceCollisions invalid(resources,{});}catch(const std::invalid_argument&){rejected=true;}check(rejected);++refusals;
    std::cout<<"{\"checks\":"<<checks<<",\"footprints\":"<<footprints<<",\"constructions\":"<<constructions<<",\"replacements\":"<<replacements<<",\"refusals\":"<<refusals<<",\"source_calls\":"<<calls<<",\"game_run\":false}\n";
}catch(const std::exception& ex){std::cerr<<ex.what()<<" footprint="<<footprints<<" construction="<<constructions<<" replacement="<<replacements<<'\n';return 1;}
