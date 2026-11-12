#include "game/native/gameplay_update/scripted_actor_construction.hpp"
#include "runtime/assets/virtual_afs.h"
namespace {
namespace constructor_world=reo::native::gameplay_world;
namespace constructor_update=reo::native::gameplay_update;
std::size_t scripted_constructor_calls{},scripted_constructor_refusals{};
struct ConstructorOriginal {
    bool full{};std::uint16_t parts{};
    std::uint8_t group{},type{},variant{},definition{};
    std::vector<unsigned> calls;
};
ConstructorOriginal* constructor_original{};
PS2Runtime::Function constructor_port(std::uint32_t address){
    if(!constructor_original)return nullptr;
    switch(address){
    case 0x6ba300:return +[](std::uint8_t* ram,R5900Context* c,PS2Runtime*){
        auto& p=*constructor_original;p.calls.push_back(0x6ba300);check(GPR_U32(c,4)==1);
        if(!p.full)std::memset(ram+0x90000,0,0xd90);
        SET_GPR_U32(c,2,p.full?0:0x90000);done(c);
    };
    case 0x1d1f40:return +[](std::uint8_t* ram,R5900Context* c,PS2Runtime* runtime){
        auto& p=*constructor_original;p.calls.push_back(0x1d1f40);
        check(GPR_U32(c,4)==p.definition&&GPR_U32(c,5)==p.group&&GPR_U32(c,6)==p.type&&GPR_U32(c,7)==p.variant);
        sub_001D1F40_0x1d1f40(ram,c,runtime);
    };
    case 0x1d0920:return +[](std::uint8_t* ram,R5900Context* c,PS2Runtime*){
        auto& p=*constructor_original;p.calls.push_back(0x1d0920);
        check(GPR_U32(c,4)==p.definition&&GPR_U32(c,5)==p.group&&GPR_U32(c,6)==p.type&&GPR_U32(c,7)==p.variant&&GPR_U32(c,8)==0);
        fixture_write(ram,0x459120+0x1468*p.group+0x812,p.parts);done(c);
    };
    case 0x377560:return +[](std::uint8_t*,R5900Context* c,PS2Runtime*){
        auto& p=*constructor_original;p.calls.push_back(0x377560);
        check(GPR_U32(c,4)==0x90000&&GPR_U32(c,5)==2&&GPR_U32(c,6)==p.type);
        SET_GPR_U32(c,2,0);done(c);
    };
    default:return nullptr;
    }
}
struct ConstructorBytes final:reo::assets::PositionedSource {
    std::vector<std::uint8_t> bytes;mutable unsigned reads{};
    explicit ConstructorBytes(std::vector<std::uint8_t> input):bytes(std::move(input)){}
    std::uint64_t size()const noexcept override{return bytes.size();}
    std::size_t read(std::uint64_t offset,std::size_t length,void* output)const override{
        check(offset<=bytes.size()&&length<=bytes.size()-offset);++reads;
        std::memcpy(output,bytes.data()+offset,length);return length;
    }
};
std::vector<std::uint8_t> constructor_afs(const std::vector<std::pair<std::string,std::vector<std::uint8_t>>>& members){
    std::vector<std::uint8_t> bytes(2048);std::memcpy(bytes.data(),"AFS\0",4);
    fixture_write(bytes.data(),4,std::uint32_t(members.size()));
    const auto names=16+8*members.size();check(names+48*members.size()<bytes.size());
    fixture_write(bytes.data(),8+8*members.size(),std::uint32_t(names));
    fixture_write(bytes.data(),12+8*members.size(),std::uint32_t(48*members.size()));
    for(unsigned i=0;i<members.size();++i){
        const auto& [name,payload]=members[i];check(name.size()<32);
        std::memcpy(bytes.data()+names+48*i,name.data(),name.size());
        const auto offset=bytes.size();bytes.resize((offset+payload.size()+2047u)&~std::size_t(2047));
        fixture_write(bytes.data(),8+8*i,std::uint32_t(offset));fixture_write(bytes.data(),12+8*i,std::uint32_t(payload.size()));
        std::memcpy(bytes.data()+offset,payload.data(),payload.size());
    }
    return bytes;
}
void scripted_actor_constructor_tests(){
    namespace w=constructor_world;namespace u=constructor_update;
    std::vector<std::uint8_t> ram(0x900000);owned_linked_definition_constants(ram.data());
    w::File1LinkedModelProfiles profiles;
    // Each synthetic member has the same independently known seven-part AMO.
    // Actual owned skeleton/resource preparation is qualified separately.
    std::vector<std::uint8_t> bundle(72);
    fixture_write(bundle.data(),0x14,48u);fixture_write(bundle.data(),0x18,24u);
    fixture_write(bundle.data(),52,1u);fixture_write(bundle.data(),56,24u);
    fixture_write(bundle.data(),60,2u);fixture_write(bundle.data(),64,7u);fixture_write(bundle.data(),68,12u);
    for(unsigned type:{0u,1u,2u,3u,27u,60u})for(unsigned definition:{0u,1u,2u})for(unsigned variant=0;variant<4;++variant){
        const auto bank=definition==1?w::ModelDefinitionBank::alternate:w::ModelDefinitionBank::ordinary;
        const w::LinkedModelDefinition *scale{},*selected{},*shadow{};
        try{scale=&profiles.definition(std::uint8_t(type),std::uint16_t(definition));
            selected=&profiles.definition(std::uint8_t(type),std::uint16_t(variant),bank);
            shadow=&profiles.definition(std::uint8_t(type),std::uint16_t(variant));
        }catch(const std::out_of_range&){continue;}
        std::vector<std::pair<std::string,std::vector<std::uint8_t>>> members;
        if(selected->model!=255)members.push_back({std::string(w::ActorAssets::model_name(selected->model,bank)),bundle});
        else members.push_back({"unused.nbd",bundle});
        const auto storage=std::make_shared<ConstructorBytes>(constructor_afs({{"romdata_usa.afs",constructor_afs(members)}}));
        w::ActorAssets assets(std::make_shared<reo::assets::Source>("constructor fixture",storage));
        ActorFixture actors;tasks::Scheduler scheduler;u::MaterialAnimations materials(actors.world,scheduler);
        u::ScriptedActorConstruction factory(actors.world,materials);
        for(unsigned group:{0u,1u,255u,0x12340100u}){
            assertion_context="Scripted constructor class="+std::to_string(type)+" definition="+std::to_string(definition)+" variant="+std::to_string(variant);
            const u::ScriptedActorRequest request{group,0x12340000u|type,0x98760000u|variant,0xabcd0000u|definition};
            const auto prepared=factory.prepare(request,assets);const auto reads=storage->reads;
            const auto made=factory.create(*prepared);check(made.status==u::ScriptedConstructionStatus::completed&&made.id);
            check(storage->reads==reads);
            const auto actor=actors.world.resolve(made.id);check(actor&&actor->scripted);
            ConstructorOriginal original;original.group=std::uint8_t(group);original.type=std::uint8_t(type);
            original.variant=std::uint8_t(variant);original.definition=std::uint8_t(definition);original.parts=selected->model==255?0:7;
            constructor_original=&original;original_periodic_used=0;original_periodic_tasks.clear();
            check(invoke_npc_original(ram,o2_006BA5C0_0x6ba5c0,{request.model_group,request.type,request.variant,request.definition_index})==0x90000);
            constructor_original=nullptr;
            const auto at=0x90000u;
            check(actor->active==bool(ram[at])&&actor->visible==bool(ram[at+1])&&actor->category==ram[at+2]&&actor->slot==ram[at+3]);
            check(actor->scripted->model_group==ram[at+0x31]&&actor->model_pose_class==ram[at+0x54d]&&actor->linked_model_variant==fixture_read<std::uint16_t>(ram.data(),at+0xbba));
            check(actor->targeting&&actor->targeting->head_model_point&&*actor->targeting->head_model_point==ram[at+0x552]);
            check(std::bit_cast<std::uint32_t>(actor->motion_multiplier)==fixture_read<std::uint32_t>(ram.data(),at+0xf0));
            check(actor->model_scale.x==scale->scale&&actor->model_scale.x==fixture_read<float>(ram.data(),at+0xb4)&&actor->model_scale.y==fixture_read<float>(ram.data(),at+0xb8)&&actor->model_scale.z==fixture_read<float>(ram.data(),at+0xbc));
            check(fixture_read<std::uint32_t>(ram.data(),at+0x14)==0x6ba880&&fixture_read<std::uint32_t>(ram.data(),at+0x18)==0x371ef0);
            for(unsigned i=0;i<4;++i)check(actor->scripted->color[i]==ram[at+0xccc+i]);
            check(actor->scripted->alpha_mode==fixture_read<std::int8_t>(ram.data(),at+0xca0)&&actor->scripted->alpha==ram[at+0xca1]);
            check(actor->scripted->part_visibility.size()==original.parts);
            for(unsigned i=0;i<original.parts;++i)check(actor->scripted->part_visibility[i]==ram[at+0xf4+i]);
            const auto& render=actor->scripted->render;
            check(render.bank==bank&&render.model==selected->model&&render.texture==selected->texture&&render.construction_mode==selected->construction_mode&&render.shadow_enabled==shadow->shadow_enabled&&render.shadow_asset==shadow->shadow_asset);
            check(scheduler.size()==(type==27?1u:0u));
            check(original_periodic_used==scheduler.size());
            if(type==27)check(made.material_task.status==tasks::Status::completed);
            check((original.calls==std::vector<unsigned>{0x6ba300,0x1d1f40,0x1d0920,0x377560}));
            check(actors.world.linked_models().head()==made.id);
            check(actors.world.linked_models().reset()==w::LinkedStatus::completed);
            check(scheduler.run(tasks::Pass::update).status==tasks::Status::completed&&scheduler.size()==0);
            ++scripted_constructor_calls;
        }
    }
    const auto& descriptor=profiles.definition(27,0);
    const auto storage=std::make_shared<ConstructorBytes>(constructor_afs({{"romdata_usa.afs",constructor_afs({
        {std::string(w::ActorAssets::model_name(descriptor.model,w::ModelDefinitionBank::ordinary)),bundle}})}}));
    w::ActorAssets assets(std::make_shared<reo::assets::Source>("constructor capacity fixture",storage));
    for(unsigned actors_used:{0u,49u,50u})for(unsigned tasks_used:{0u,31u,32u}){
        assertion_context="Scripted constructor actors="+std::to_string(actors_used)+" tasks="+std::to_string(tasks_used);
        ActorFixture actors;tasks::Scheduler scheduler;u::MaterialAnimations materials(actors.world,scheduler);
        u::ScriptedActorConstruction factory(actors.world,materials);
        for(unsigned i=0;i<actors_used;++i)check(actors.world.linked_models().allocate(true).status==w::LinkedStatus::completed);
        for(unsigned i=0;i<tasks_used;++i)check(scheduler.create(std::make_shared<PeriodicIdle>()).status==tasks::Status::completed);
        const auto prepared=factory.prepare({3,27,0,0},assets);
        const auto made=factory.create(*prepared);
        ConstructorOriginal original;original.full=actors_used==50;original.group=3;original.type=27;original.parts=7;
        constructor_original=&original;original_periodic_used=tasks_used;original_periodic_tasks.clear();
        const auto returned=invoke_npc_original(ram,o2_006BA5C0_0x6ba5c0,{3,27,0,0});
        constructor_original=nullptr;
        check((returned==0)==original.full);
        check(made.status==(original.full?u::ScriptedConstructionStatus::full:u::ScriptedConstructionStatus::completed));
        check(bool(made.id)==!original.full&&scheduler.size()==original_periodic_used);
        check(actors.world.linked_models().remaining()==50-actors_used-(original.full?0u:1u));
        if(original.full){check(original.calls==std::vector<unsigned>{0x6ba300});++scripted_constructor_refusals;}
        else{
            check(made.material_task.status==(tasks_used==32?tasks::Status::full:tasks::Status::completed));
            ++scripted_constructor_calls;
        }
    }
    original_periodic_used=0;original_periodic_tasks.clear();
}
}
void o2_006BA300_0x6ba300(std::uint8_t* ram,R5900Context* c,PS2Runtime* runtime){
    const auto port=constructor_port(0x6ba300);if(!port)throw std::runtime_error("Unexpected constructor allocator port");port(ram,c,runtime);
}
