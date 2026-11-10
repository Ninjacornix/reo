#include "game/native/gameplay_world/resource_use.hpp"
#include "game/native/gameplay_world/inventory.hpp"
#include "reference.hpp"
#include "functions.h"
#include <fstream>
#include <iostream>
#include <source_location>
#include <vector>
namespace g=reo::native::gameplay_world;
namespace s=reo::native::gameplay_scenario;
unsigned checks{},calls{},uses{},configurations{},queries{},lookups{},refusals{},mode_reads{};
constexpr unsigned model_at=0x130000,vector_at=0x110000,parameters_at=0x110100,actor_at=0x10000;
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("Resource use check "+std::to_string(checks)+" line "+std::to_string(at.line()));
}
template<class T>T get(const std::uint8_t* m,unsigned at){return transform_read<T>(m,at);}
template<class T>void put(std::uint8_t* m,unsigned at,T value){transform_write(m,at,value);}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;const auto done=[&](){context->pc=GPR_U32(context,31);};
    switch(context->pc){
    case 0x1b0300:SET_GPR_U32(context,2,memory[0x3243f2]);++mode_reads;done();return;
    case 0x107ab0:{const auto dst=GPR_U32(context,4),src=GPR_U32(context,5),n=GPR_U32(context,6);check((dst==model_at+0x20c&&src==vector_at&&n==12)||(dst==model_at+0x224&&src==parameters_at&&n==8)||(src>=0x100000&&src<=0x110000&&n<=0x110000-src&&((dst==0x74bb50&&n<=129*24)||(dst==0x74b940&&n<=129*4)||(dst==0x74c770&&n<=128*4)||(dst==0x74c970&&n<=384*2))));std::memcpy(memory+dst,memory+src,n);SET_GPR_U32(context,2,dst);done();return;}
    case 0x107c68:{const auto dst=GPR_U32(context,4),n=GPR_U32(context,6);check(dst<=0x2000000&&n<=0x2000000-dst);std::memset(memory+dst,std::uint8_t(GPR_U32(context,5)),n);SET_GPR_U32(context,2,dst);done();return;}
#include "original_dispatch.hpp"
    default:throw std::runtime_error("Unadmitted original resource-use call "+std::to_string(context->pc));
    }
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#include "original.cpp"
#pragma GCC diagnostic pop
unsigned call(std::uint8_t* memory,unsigned pc,std::array<unsigned,3> args={}){
    R5900Context context;context.pc=pc;SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x100);
    for(unsigned i=0;i<3;++i){SET_GPR_U32(&context,4+i,args[i]);}PS2Runtime runtime;original_transform_port(memory,&context,&runtime);
    check(context.pc==0x100&&GPR_U32(&context,29)==0x1f00000);return GPR_U32(&context,2);
}
std::vector<std::vector<std::byte>> templates(const char* path){
    std::ifstream input(path,std::ios::binary);unsigned count{};input.read(reinterpret_cast<char*>(&count),4);check(count==5);std::vector<std::vector<std::byte>> result;
    for(unsigned i=0;i<count;++i){unsigned size{};input.read(reinterpret_cast<char*>(&size),4);check(size&&size<65536);result.emplace_back(size);input.read(reinterpret_cast<char*>(result.back().data()),size);check(bool(input));}return result;
}
int main(int argc,char** argv)try{
    check(argc==2);std::vector<std::uint8_t> ram(0x2000000);auto* memory=ram.data();auto session=std::make_shared<g::Session>();g::World world({{g::input::Remap{1,2,4}},1,{16,UINT64_MAX}},session);
    s::SceneResources resources;s::ResourceTemplates metadata;g::ResourceModels models;g::ResourceFrames frames(world,resources,models,nullptr,{},&metadata);g::ResourceUse owner(world,resources,metadata,frames);g::WorldInventory inventory(world,resources,metadata,frames);
    const auto made=models.create();check(made.status==g::ResourceModelStatus::completed);auto& model=*made.model;
    for(unsigned n=0;n<65536;++n){
        const auto resource=std::uint8_t(n);const unsigned raw=0x3c5630+60*resource;s::SceneDescriptor d;d.active=n%5?std::uint8_t(1+n%255):0;d.parameter=std::bit_cast<std::int16_t>(std::uint16_t(n*65521));d.flags=n*1664525u;if(n%3)d.primary=made.model;check(bool(resources.load(resource,d)));
        model.flags=n*1013904223u;model.use_delay=std::bit_cast<std::int16_t>(std::uint16_t(n));model.use_vector={-10,20,-30};model.use_parameters={-1,2,-3,4};model.program.elapsed=127;model.pulse_timer=511;
        session->mode=std::uint8_t(n>>8);session->gameplay_flags=std::uint8_t(n);memory[0x3243f2]=session->mode;memory[0x4bae96]=session->gameplay_flags;
        std::fill_n(memory+raw,60,0);memory[raw]=d.active;put(memory,raw+0x24,d.parameter);put(memory,raw+0x18,d.flags);put(memory,raw+0x1c,d.primary?model_at:0u);put(memory,model_at+0x23c,model.flags);put(memory,model_at+0xc,model.use_delay);put(memory,model_at+0x20c,model.use_vector);put(memory,model_at+0x224,model.use_parameters);
        g::ResourceUsePayload payload;const auto profile=(n/5)%4;if(profile&1)payload.vector=reo::native::animation::Vector{std::bit_cast<float>(n*1234567u),std::bit_cast<float>(0x7f800001u|(n&0x7fffffu)),std::bit_cast<float>(0x80000000u|n)};if(profile&2)payload.parameters=std::array<std::int16_t,4>{std::bit_cast<std::int16_t>(std::uint16_t(n)),INT16_MIN,INT16_MAX,std::bit_cast<std::int16_t>(std::uint16_t(n*7))};
        if(payload.vector){put(memory,vector_at,*payload.vector);}
        if(payload.parameters){put(memory,parameters_at,*payload.parameters);}
        const unsigned full=unsigned(resource)|(n*2654435761u&0xffffff00u);const auto actual=call(memory,0x5b3aa0,{full,payload.vector?vector_at:0u,payload.parameters?parameters_at:0u});check(owner.use(full,payload)==actual);
        const auto result=resources.get(*resources.slot(resource));check(result&&result->parameter==get<std::int16_t>(memory,raw+0x24)&&result->flags==get<unsigned>(memory,raw+0x18)&&result->active==d.active&&result->primary==d.primary);
        check(model.flags==get<unsigned>(memory,model_at+0x23c)&&model.use_delay==get<std::int16_t>(memory,model_at+0xc));check(std::memcmp(&model.use_vector,memory+model_at+0x20c,12)==0&&std::memcmp(model.use_parameters.data(),memory+model_at+0x224,8)==0);check(model.program.elapsed==127&&model.pulse_timer==511);++uses;
        if(n%16==0){const auto before=result->parameter;call(memory,0x5b3b80,{full,0,0});owner.configure(full);const auto after=resources.get(*resources.slot(resource));check(after&&after->parameter==before&&after->flags==get<unsigned>(memory,raw+0x18));check(std::memcmp(&model.use_vector,memory+model_at+0x20c,12)==0&&std::memcmp(model.use_parameters.data(),memory+model_at+0x224,8)==0&&model.use_delay==get<std::int16_t>(memory,model_at+0xc));++configurations;}
        call(memory,0x5b5850,{full,0xabcd0000u|(n>>8)});owner.visibility(full,0xabcd0000u|(n>>8));check(model.flags==get<unsigned>(memory,model_at+0x23c)&&resources.get(*resources.slot(resource))->parameter==get<std::int16_t>(memory,raw+0x24));
    }
    const auto owned_templates=templates(argv[1]);
    for(bool reset:{true,false})for(const auto& bytes:owned_templates){
        // Compare identical owner lifecycles: reset both tables, or retain both
        // tails across imports. Loading a shorter table does not clear its tail.
        if(reset){metadata=s::ResourceTemplates{};call(memory,0x5919f0);}
        check(metadata.load(bytes));std::memcpy(memory+0x100000,bytes.data(),bytes.size());call(memory,0x5921d0,{0x100000});
        for(unsigned index=0;index<129;++index)for(unsigned clock=0;clock<256;++clock)for(bool special:{false,true}){
            s::SceneDescriptor d;d.active=std::uint8_t((index+clock)%7!=0);d.template_index=std::uint8_t(index);d.attachment_id=std::uint16_t(special?0x3717:42);check(bool(resources.load(3,d)));session->clock_mode=std::uint8_t(clock);memory[0x3243cc]=session->clock_mode;constexpr unsigned raw=0x3c5630+3*60;memory[raw]=d.active;memory[raw+43]=d.template_index;put(memory,raw+6,d.attachment_id);
            const auto expected=std::bit_cast<std::int32_t>(call(memory,0x5b4e60,{0xabcd0003}));const auto actual=owner.initial_quantity(0xabcd0003);if(actual!=expected)throw std::runtime_error("Initial quantity mismatch query="+std::to_string(queries)+" index="+std::to_string(index)+" clock="+std::to_string(clock)+" special="+std::to_string(special)+" active="+std::to_string(d.active)+" native="+std::to_string(actual)+" original="+std::to_string(expected)+" count="+std::to_string(metadata.state().count));check(actual==expected);++queries;
        }
        s::SceneDescriptor missing;missing.active=1;missing.template_index=255;check(bool(resources.load(3,missing)));memory[0x3c5630+3*60]=1;memory[0x3c5630+3*60+43]=255;check(owner.initial_quantity(3)==0&&call(memory,0x5b4e60,{3})==0);
    }
    auto actor=std::make_unique<g::Actor>();const auto actor_id=world.spawn_primary(0,std::move(actor)).id;check(bool(actor_id));
    for(unsigned i=0;i<256;++i){s::SceneDescriptor d;d.active=std::uint8_t(i&1);d.attachment_id=std::uint16_t(i/3*257);check(bool(resources.load(i,d)));put(memory,0x3c5630+60*i+6,d.attachment_id);}
    unsigned seed=17;
    for(unsigned n=0;n<65536;++n){auto actor_value=world.resolve(actor_id);auto& items=actor_value->inventory;
        for(auto& id:items.carried){seed=seed*1664525u+1013904223u;id=std::uint8_t(seed>>24);}for(auto& id:items.storage){seed=seed*1664525u+1013904223u;id=std::uint8_t(seed>>24);}
        const auto target=std::uint8_t(n);const unsigned position=n%40;if(position<4)items.carried[position]=target;else if(position<36)items.storage[position-4]=target;
        std::memcpy(memory+actor_at+0xc84,items.carried.data(),4);std::memcpy(memory+actor_at+0xc88,items.storage.data(),32);
        const unsigned content=(n%5?unsigned(target/3*257):0x1234u)|(n*1664525u&0xffff0000u);check(inventory.find_by_content(actor_id,content)==call(memory,0x5f2210,{actor_at,content}));++lookups;
    }
    g::ResourceModels foreign_models;const auto foreign=foreign_models.create();check(foreign.status==g::ResourceModelStatus::completed);foreign.model->flags=123;s::SceneDescriptor invalid;invalid.active=1;invalid.parameter=4;invalid.flags=0x20040;invalid.primary=foreign.model;check(bool(resources.load(3,invalid)));session->mode=1;
    bool rejected{};try{owner.use(3);}catch(const std::runtime_error&){rejected=true;}const auto prefix=resources.get(*resources.slot(3));check(rejected&&prefix->parameter==3&&prefix->flags==0x40&&foreign.model->flags==123);++refusals;
    invalid.primary=made.model;invalid.parameter=4;check(bool(resources.load(3,invalid)));check(models.retire(made.id)==g::ResourceModelStatus::completed);check(model.use_delay==0&&model.use_parameters==std::array<std::int16_t,4>{}&&std::memcmp(&model.use_vector,memory+0x1d00000,12)==0);const auto replacement=models.create();check(replacement.status==g::ResourceModelStatus::completed);replacement.model->flags=55;rejected=false;try{owner.configure(3);}catch(const std::runtime_error&){rejected=true;}check(rejected&&replacement.model->flags==55);++refusals;
    invalid.primary.reset();invalid.template_index=200;invalid.attachment_id=1;check(bool(resources.load(3,invalid)));rejected=false;try{owner.initial_quantity(3);}catch(const std::runtime_error&){rejected=true;}check(rejected);++refusals;
    s::SceneResources other;rejected=false;try{g::ResourceUse wrong(world,other,metadata,frames);}catch(const std::invalid_argument&){rejected=true;}check(rejected);++refusals;
    check(world.close()==g::Status::completed);rejected=false;try{owner.use(3);}catch(const std::runtime_error&){rejected=true;}check(rejected);++refusals;
    std::cout<<"{\"checks\":"<<checks<<",\"uses\":"<<uses<<",\"configurations\":"<<configurations<<",\"quantity_queries\":"<<queries<<",\"content_lookups\":"<<lookups<<",\"refusals\":"<<refusals<<",\"mode_reads\":"<<mode_reads<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
