#include "game/native/gameplay_world/resource_frames.hpp"
#include "game/native/gameplay_world/resource_programs.hpp"
#include "reference.hpp"
#include "owned_constants.hpp"
#include <fstream>
#include <iostream>
#include <source_location>
#include <vector>
namespace g=reo::native::gameplay_world;
namespace a=reo::native::animation;
namespace s=reo::native::gameplay_scenario;
constexpr unsigned pool=0x3f4010,stride=0x250,descriptor_at=0x3c5630+3*60,bank_at=0x749180;
std::uint64_t checks{},common_cases{},weapon_cases{},sequence_frames{},source_calls{},refusals{},passes{};
std::string active_case;
void check(bool value,const std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error(active_case+" line "+std::to_string(at.line()));
}
template<class T>T read(const std::uint8_t* p,unsigned at){return transform_read<T>(p,at);}
template<class T>void put(std::uint8_t* p,unsigned at,T value){transform_write(p,at,value);}
void original_transform_port(std::uint8_t* ram,R5900Context* ctx,PS2Runtime* runtime){
    ++source_calls;
    switch(ctx->pc){
#include "dispatch.inc"
        case 0x107c68:std::memset(ram+GPR_U32(ctx,4),GPR_U32(ctx,5)&255,GPR_U32(ctx,6));break;
        default:throw std::runtime_error("Unadmitted resource frame dependency "+std::to_string(ctx->pc));
    }
    ctx->pc=GPR_U32(ctx,31);
}
R5900Context call(std::uint8_t* ram,unsigned entry,unsigned argument=0,unsigned arg1=0){
    R5900Context ctx;PS2Runtime runtime;ctx.pc=entry;SET_GPR_U32(&ctx,4,argument);SET_GPR_U32(&ctx,5,arg1);
    SET_GPR_U32(&ctx,29,0x1f00000);SET_GPR_U32(&ctx,31,0xabcdef);original_transform_port(ram,&ctx,&runtime);
    check(ctx.pc==0xabcdef&&GPR_U32(&ctx,29)==0x1f00000);return ctx;
}
struct Fixture {
    std::vector<std::uint8_t> ram=std::vector<std::uint8_t>(0x2000000);
    g::World world{{{g::input::Remap{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<g::Session>()};
    s::SceneResources resources;
    g::ResourceModels models;
    g::ResourceFrames frames{world,resources,models};
    g::ResourceModelCreated created;
    unsigned raw{};
    std::shared_ptr<g::ResourcePartPoses> bases=std::make_shared<g::ResourcePartPoses>();
    Fixture(){
        owned_constants(ram.data());put(ram.data(),0x294e00,reo::native::transform_math::identity());call(ram.data(),0x590be0);
        for(unsigned slot=0;slot<4;++slot)check(world.spawn_primary(slot,std::make_unique<g::Actor>()).status==g::actors::EntityStatus::completed);
        created=models.create();check(created.status==g::ResourceModelStatus::completed);
        raw=GPR_U32(&call_allocate(),2); // keep source and native allocation identities distinct
    }
    R5900Context allocated;
    const R5900Context& call_allocate(){allocated=call(ram.data(),0x590c70);check(pool+stride*created.model->physical_slot==GPR_U32(&allocated,2));return allocated;}
    void reset(unsigned owner=1,std::uint32_t flags=0x20000,bool active=true){
        check(created.model->current());auto& model=*created.model;
        model.active=active;model.visible=true;model.flags=flags;model.resource_slot=3;model.draw_layer=77;model.asset_index=2;model.program={};model.program.phase=2;model.program.elapsed=123;model.program.completed.fill(0x55);
        bases->asset_index=2;bases->count=6;model.base_parts=bases;
        put(ram.data(),raw,std::uint8_t(active));put(ram.data(),raw+1,std::uint8_t(1));put(ram.data(),raw+0x23c,flags);put(ram.data(),raw+0x240,std::uint8_t(3));put(ram.data(),raw+0x241,std::uint8_t(77));put(ram.data(),raw+0x242,std::int16_t(2));
        ram[raw+9]=2;put(ram.data(),raw+0x10,std::int16_t(123));std::fill_n(ram.data()+raw+0x38,7,0x55);put(ram.data(),raw+0x24,0u);put(ram.data(),raw+0x28,0u);
        for(unsigned part=0;part<6;++part){
            model.part_enabled[part]=std::uint8_t(part%2);ram[raw+0x30+part]=model.part_enabled[part];
            for(unsigned column=0;column<4;++column)for(unsigned lane=0;lane<4;++lane){
                model.parts[part][column][lane]=float(1+part*16+column*4+lane)*.125f;
                bases->poses[part][column][lane]=float(15+part*16+column*4+lane)*-.25f;
            }
            put(ram.data(),raw+0x40+64*part,model.parts[part]);put(ram.data(),0x3c9a50+384*2+64*part,bases->poses[part]);
        }
        put(ram.data(),0x3dbb14+2*2,std::int16_t(6));
        s::SceneDescriptor descriptor;descriptor.active=1;descriptor.ownership_tag=std::uint16_t(owner);descriptor.flags=0x24000;descriptor.primary=created.model;descriptor.parameter=1;
        check(bool(resources.load(3,descriptor)));ram[descriptor_at]=1;put(ram.data(),descriptor_at+24,descriptor.flags);put(ram.data(),descriptor_at+28,raw);put(ram.data(),descriptor_at+32,0u);put(ram.data(),descriptor_at+36,descriptor.parameter);put(ram.data(),descriptor_at+40,descriptor.ownership_tag);
        world.room=5;world.selected_actor=0;world.session().resource_hide_selected=world.session().resource_hide_others=0;
        for(unsigned slot=0;slot<4;++slot){auto actor=world.primary(slot);actor->active=actor->visible=true;actor->room=5;actor->status=0;actor->surface_material=std::uint8_t(11+slot);actor->selected_resource=3;actor->category=0;actor->slot=std::uint8_t(slot);actor->motion_style=0;sync(slot);}
        sync_session();
    }
    void sync(unsigned slot){const auto actor=world.primary(slot);const auto at=0x4a5c30+0x10e0*slot;
        ram[at]=actor->active;ram[at+1]=actor->visible;ram[at+2]=actor->category;ram[at+3]=actor->slot;put(ram.data(),at+0x1e2,actor->room);put(ram.data(),at+0xba0,actor->status);ram[at+0x175]=actor->surface_material;ram[at+0xc7c]=actor->selected_resource;ram[at+0xb99]=actor->motion_style;
    }
    void sync_session(){put(ram.data(),0x3243dc,world.room);ram[0x4baded]=world.selected_actor;ram[0x4b9d10]=world.session().resource_hide_selected;ram[0x4b9d11]=world.session().resource_hide_others;}
    void compare(){const auto& model=*created.model;const auto descriptor=resources.get(*resources.slot(3));check(bool(descriptor));
        check(model.current()==(models.available()==63));check(model.active==bool(ram[raw]));check(model.visible==bool(ram[raw+1]));check(model.flags==read<std::uint32_t>(ram.data(),raw+0x23c));check(model.draw_layer==ram[raw+0x241]);
        check(descriptor->flags==read<std::uint32_t>(ram.data(),descriptor_at+24));check(bool(descriptor->primary)==bool(read<unsigned>(ram.data(),descriptor_at+28)));
        check(model.program.phase==ram[raw+9]&&model.program.elapsed==read<std::int16_t>(ram.data(),raw+0x10));
        check(std::memcmp(model.program.completed.data(),ram.data()+raw+0x38,7)==0);
        check(std::memcmp(model.part_enabled.data(),ram.data()+raw+0x30,6)==0);
        for(unsigned part=0;part<6;++part)for(unsigned column=0;column<4;++column)for(unsigned lane=0;lane<4;++lane){
            const auto observed=read<std::uint32_t>(ram.data(),raw+0x40+64*part+16*column+4*lane);
            if(std::bit_cast<std::uint32_t>(model.parts[part][column][lane])!=observed)throw std::runtime_error(active_case+" matrix part="+std::to_string(part)+" col="+std::to_string(column)+" lane="+std::to_string(lane)+" expected="+std::to_string(observed)+" got="+std::to_string(std::bit_cast<std::uint32_t>(model.parts[part][column][lane])));
            ++checks;
        }
    }
    void step(bool weapon){call(ram.data(),weapon?0x6b45c0:0x5932f0,raw);if(weapon)frames.weapon(created.id,*created.model);else frames.common(created.id,*created.model);compare();}
};
int main(int argc,char** argv)try{
    check(argc==2);const auto old=_mm_getcsr();struct Reset{unsigned old;~Reset(){_mm_setcsr(old);}}restore{old};_mm_setcsr(0x1f80);
    for(unsigned owner:{0u,1u,2u,3u,4u,32769u,65535u})for(unsigned mode=0;mode<14;++mode)for(bool active:{false,true}){
        active_case="common owner="+std::to_string(owner)+" mode="+std::to_string(mode)+" active="+std::to_string(active);Fixture f;f.reset(owner,0x20000|(mode&1?0x80000000u:0u),active);
        const auto slot=owner>=1&&owner<=4?owner-1:0;auto actor=f.world.primary(slot);
        if(mode==2)actor->active=false;
        if(mode==3)actor->visible=false;
        if(mode==4)actor->room=8;
        if(mode>=5&&mode<=10)actor->status=1u<<(mode==5?5:mode==6?6:mode==7?7:mode==8?8:mode==9?9:10);
        f.world.selected_actor=std::uint8_t(mode%4);f.world.session().resource_hide_selected=mode==11;f.world.session().resource_hide_others=mode==12;f.sync(slot);f.sync_session();f.step(false);++common_cases;
    }
    for(std::uint32_t flags:{0u,0x80000000u,0x400u,0xc00u,0x100000u,0x40100000u})for(bool active:{false,true}){
        active_case="nonattached gates";Fixture f;f.reset(1,flags,active);
        if(active&&flags==0x40100000u){bool refused{};try{f.frames.common(f.created.id,*f.created.model);}catch(const std::runtime_error&){refused=true;}check(refused);++refusals;}
        else{f.step(false);++common_cases;}
    }
    std::ifstream file(argv[1],std::ios::binary);unsigned count{};file.read(reinterpret_cast<char*>(&count),4);check(count==16);
    for(unsigned bank_index=0;bank_index<count;++bank_index){
        unsigned size{};file.read(reinterpret_cast<char*>(&size),4);check(size&&size<=2048);std::array<std::byte,2048> bytes{};file.read(reinterpret_cast<char*>(bytes.data()),size);check(bool(file));const auto bank=a::WeaponProgramBank::import(std::span(bytes).first(size));Fixture f;
        for(unsigned select=0;select<10;++select){if(bank->selection(select).kind!=a::WeaponSelectionKind::program)continue;
            for(unsigned owner=1;owner<=4;++owner)for(unsigned pattern=0;pattern<8;++pattern){
                active_case="weapon bank="+std::to_string(bank_index)+" selection="+std::to_string(select)+" owner="+std::to_string(owner)+" pattern="+std::to_string(pattern);f.reset(owner,0x20000,pattern!=5);const auto actor=f.world.primary(owner-1);actor->weapon_programs=bank;actor->motion_style=std::uint8_t(select%2);f.sync(owner-1);
                for(unsigned slot=0;slot<4;++slot)std::memcpy(f.ram.data()+bank_at+2048*slot,bytes.data(),2048);
                const auto descriptor_id=*f.resources.slot(3);auto descriptor=*f.resources.get(descriptor_id);descriptor.parameter=select<2?1:0;check(f.resources.replace(descriptor_id,descriptor)==s::SceneStatus::completed);put(f.ram.data(),descriptor_at+36,descriptor.parameter);
                const unsigned mode=select<2||select>=8?0:select/2;g::WorldResourcePrograms programs(f.world,f.resources);programs.select(*actor,mode);call(f.ram.data(),0x6b4420,0x4a5c30+0x10e0*(owner-1),mode);
                auto& state=f.created.model->program;state.elapsed=pattern==1?-3:pattern==2?32766:pattern==3?-32768:0;put(f.ram.data(),f.raw+0x10,state.elapsed);
                state.completed.fill(pattern==4?63:pattern==6?0x15:pattern==7?0xff:0);std::memcpy(f.ram.data()+f.raw+0x38,state.completed.data(),7);
                if(pattern==5){actor->status=0x200;f.sync(owner-1);}f.compare();
                for(unsigned frame=0;frame<96;++frame){f.step(true);++sequence_frames;}
                ++weapon_cases;
            }
        }
    }
    for(unsigned phase:{0u,2u,255u})for(unsigned owner:{0u,1u,4u,32769u,65535u}){
        active_case="weapon phase/invalid owner";Fixture f;f.reset(owner);f.created.model->program.phase=std::uint8_t(phase);f.ram[f.raw+9]=std::uint8_t(phase);f.step(true);++weapon_cases;
    }
    for(unsigned count=0;count<=6;++count)for(unsigned phase:{0u,2u}){
        active_case="static part copy count="+std::to_string(count);Fixture f;f.reset(1,0x20000,false);f.bases->count=std::uint16_t(count);put(f.ram.data(),0x3dbb14+2*2,std::int16_t(count));f.world.primary(0)->status=0x200;f.sync(0);f.created.model->program.phase=std::uint8_t(phase);f.ram[f.raw+9]=std::uint8_t(phase);f.step(true);++weapon_cases;
    }
    {
        active_case="actual ResourceModels update callback and self retirement";Fixture f;f.reset();f.created.model->work=std::make_shared<g::WeaponModelWork>(f.frames);f.world.primary(0)->active=false;f.sync(0);put(f.ram.data(),f.raw+0x14,0x6b45c0u);
        call(f.ram.data(),0x590ea0);const auto result=f.models.update(false);check(result.status==g::ResourceModelStatus::completed&&result.called==1);check(!f.created.model->current()&&!f.models.retain(f.created.id));f.compare();++passes;
    }
    {
        active_case="native safety refusals";Fixture f;f.reset();g::ResourceModels foreign;const auto other=foreign.create();bool refused{};try{f.frames.common(other.id,*other.model);}catch(const std::runtime_error&){refused=true;}check(refused);++refusals;
        for(unsigned owner:{5u,128u,32768u}){f.reset(owner);refused=false;try{f.frames.common(f.created.id,*f.created.model);}catch(const std::runtime_error&){refused=true;}check(refused);++refusals;}
        for(unsigned flags:{0x800u,0x80000u}){f.reset(1,flags);refused=false;try{f.frames.common(f.created.id,*f.created.model);}catch(const std::runtime_error&){refused=true;}check(refused);++refusals;}
        for(unsigned failure=0;failure<4;++failure){f.reset(1,0x20000,false);f.world.primary(0)->status=0x200;
            if(failure==0)f.created.model->base_parts.reset();
            if(failure==1)f.bases->asset_index=7;
            if(failure==2)f.bases->count=7;
            if(failure==3)f.created.model->asset_index=-1;
            refused=false;try{f.frames.weapon(f.created.id,*f.created.model);}catch(const std::runtime_error&){refused=true;}check(refused);++refusals;
        }
        f.reset();f.created.model->program.phase=1;refused=false;try{f.frames.weapon(f.created.id,*f.created.model);}catch(const std::runtime_error&){refused=true;}check(refused);++refusals;
        f.reset();std::array<std::byte,40> empty{};auto first=a::WeaponProgramBank::import(empty),second=a::WeaponProgramBank::import(empty);f.created.model->program.phase=1;f.created.model->program.source=first;f.created.model->program.selected=std::make_shared<a::WeaponProgram>();f.world.primary(0)->weapon_programs=second;
        refused=false;try{f.frames.weapon(f.created.id,*f.created.model);}catch(const std::runtime_error&){refused=true;}check(refused);++refusals;
        f.reset();auto descriptor=*f.resources.get(*f.resources.slot(3));descriptor.secondary=other.model;check(f.resources.replace(*f.resources.slot(3),descriptor)==s::SceneStatus::completed);f.world.primary(0)->active=false;refused=false;try{f.frames.common(f.created.id,*f.created.model);}catch(const std::runtime_error&){refused=true;}check(refused&&f.created.model->current());++refusals;
        f.reset();check(f.models.retire(f.created.id)==g::ResourceModelStatus::completed);refused=false;try{f.frames.weapon(f.created.id,*f.created.model);}catch(const std::runtime_error&){refused=true;}check(refused);++refusals;
    }
    std::cout<<"{\"checks\":"<<checks<<",\"common_cases\":"<<common_cases<<",\"weapon_cases\":"<<weapon_cases<<",\"sequence_frames\":"<<sequence_frames<<",\"source_calls\":"<<source_calls<<",\"passes\":"<<passes<<",\"refusals\":"<<refusals<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
