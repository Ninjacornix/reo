#include "game/native/gameplay_application/session_resource_import.hpp"
#include "game/native/gameplay_application/native_session.hpp"
#include "game/native/gameplay_world/resource_factory.hpp"
#include "runtime/assets/virtual_afs.h"
#include "reference.hpp"
#include "functions.h"
#include <iostream>
#include <source_location>
#include <string_view>
#include <vector>
namespace a=reo::native::gameplay_application;namespace g=reo::native::gameplay_world;namespace s=reo::native::gameplay_scenario;
std::uint64_t checks{},cases{},calls{},reads{},selected{},placed{},starting{};
unsigned mode_prefix_ports{},mode_prefixes{},refusals{};
struct ModePrefixReached{};
const s::content::ScenarioArchive* archive{};std::uint16_t scenario{};
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Resource bootstrap check "+std::to_string(at.line()));}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;switch(context->pc){
    case 0x1a8970:check(GPR_U32(context,4)==0&&GPR_U32(context,5)==0x24fde0);++mode_prefix_ports;break;
    case 0x1cc260:case 0x12a1e8:++mode_prefix_ports;break;
    case 0x12b620:check(GPR_U32(context,4)==0x1ac640&&GPR_U32(context,5)==0);++mode_prefix_ports;break;
    case 0x1a8ce0:check(GPR_U32(context,4)==0xffffffffu);throw ModePrefixReached{};
    case 0x107c68:std::memset(memory+GPR_U32(context,4),int(GPR_U32(context,5)),GPR_U32(context,6));break;
    case 0x107ab0:std::memcpy(memory+GPR_U32(context,4),memory+GPR_U32(context,5),GPR_U32(context,6));break;
    case 0x10a830:{const auto format=GPR_U32(context,5);auto* output=reinterpret_cast<char*>(memory+GPR_U32(context,4));
        if(format==0x73e180)std::snprintf(output,64,"item%03u%02u.tbl",GPR_U32(context,6),GPR_U32(context,7));
        else if(format==0x73e1b0)std::snprintf(output,64,"item%03u.dat",GPR_U32(context,6));
        else throw std::runtime_error("Unadmitted resource format "+std::to_string(format));
        break;
    }
    case 0x1aa3e0:{const std::string key(reinterpret_cast<char*>(memory+GPR_U32(context,4)));const auto bytes=archive->read_resource(scenario,key);++reads;
        if(bytes){std::memcpy(memory+GPR_U32(context,5),bytes->data(),bytes->size());transform_write(memory,0x324420,GPR_U32(context,5));SET_GPR_U32(context,2,std::uint32_t((bytes->size()+2047)/2048*2048));}
        else SET_GPR_U32(context,2,0);
        break;
    }
#include "original_dispatch.hpp"
    default:throw std::runtime_error("Unadmitted resource bootstrap port "+std::to_string(context->pc)+" return="+std::to_string(GPR_U32(context,31))+" assetmode="+std::to_string(memory[0x3243d7]));
    }context->pc=GPR_U32(context,31);
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#include "original.cpp"
#pragma GCC diagnostic pop
#include "owned_constants.hpp"
void call(std::vector<std::uint8_t>& memory,std::uint32_t at){R5900Context context;PS2Runtime runtime;context.pc=at;SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x123456);original_transform_port(memory.data(),&context,&runtime);check(context.pc==0x123456);}
void descriptor_bytes(std::uint8_t* out,const s::SceneDescriptor& value){
    std::memset(out,0,60);const auto put=[&](unsigned at,auto field){std::memcpy(out+at,&field,sizeof field);};
    out[0]=value.active;out[1]=value.room;out[2]=value.instance_index;out[3]=value.kind;put(4,value.authored_id);put(6,value.attachment_id);put(8,value.position);put(20,value.tilt);put(22,value.yaw);put(24,value.flags);
    check(!value.primary&&!value.secondary);put(36,value.parameter);put(40,value.ownership_tag);out[42]=value.claim_tag;out[43]=value.template_index;out[44]=std::uint8_t(value.shape_profile);out[45]=std::uint8_t(value.orientation_variant);put(46,value.saved_yaw);put(48,value.saved_position);
}
struct Notices final:s::FlagNotifications {
    bool changed(const s::ScenarioFlagChange&)noexcept override{return true;}
    bool changed(const s::StridedFlagChange&)noexcept override{return true;}
};
int main(int argc,char** argv)try{
    check(argc==2||argc==3);const bool offline_only=argc==3&&std::string_view(argv[2])=="--offline-only";check(argc==2||offline_only);auto source=std::make_shared<const reo::assets::Source>(std::filesystem::path(argv[1]));s::content::ScenarioArchive owned(source);archive=&owned;
    g::Profile profile;profile.layouts.push_back({});profile.entities.capacity=64;auto session=std::make_shared<g::Session>();g::World world(profile,session);world.mode=1;session->asset_loading_mode=1;
    s::SceneResources resources;s::ResourceTemplates templates;g::ResourceModels models;g::ResourceFrames frames(world,resources,models,nullptr,{},&templates);g::WorldInventory inventory(world,resources,templates,frames);a::ResourceBootstrap bootstrap(world,resources,templates,inventory);
    for(unsigned slot=0;slot<8;++slot){auto actor=std::make_unique<g::Actor>();actor->slot=std::uint8_t(slot);check(bool(world.spawn_primary(slot,std::move(actor)).id));}
    std::vector<std::uint8_t> memory(0x2000000);owned_resource_constants(memory.data());
    check(!g::Session{}.asset_loading_mode);Notices notices;a::NativeSession host(source,profile,notices);
    check(host.world().session().asset_loading_mode==1);
    for(unsigned seed=0;seed<256;++seed){memory[0x3243d7]=std::uint8_t(seed);const auto before=mode_prefix_ports;
        bool reached{};try{call(memory,0x1ac650);}catch(const ModePrefixReached&){reached=true;}
        check(reached&&mode_prefix_ports-before==4&&memory[0x3243d7]==*host.world().session().asset_loading_mode);++mode_prefixes;
    }
    check(host.close()==a::SessionStatus::completed);
    const auto run=[&](unsigned difficulty,unsigned observed,unsigned roll,unsigned variant,bool all_variants,unsigned mode=1,unsigned flags=0){
        world.scenario=scenario;world.room=memory[0x3243dc]=73;world.mode=memory[0x3243f2]=std::uint8_t(mode);session->gameplay_flags=memory[0x4bae96]=std::uint8_t(flags);session->asset_loading_mode=memory[0x3243d7]=1;session->difficulty=memory[0x4bae8a]=std::uint8_t(difficulty);
        session->clock_mode=memory[0x3243cc]=std::uint8_t(roll%2);const auto population=all_variants?1u:roll%9;session->primary_population=population;
        transform_write(memory.data(),0x3243da,scenario);transform_write(memory.data(),0x4baea0,population);transform_write(memory.data(),0x32440c,0x1000000u);transform_write(memory.data(),0x324420,0x1000000u);
        session->random.restore({std::uint16_t(roll*3),std::uint16_t(roll),std::uint8_t(observed)});transform_write(memory.data(),0x3244b0,std::uint16_t(roll*3));transform_write(memory.data(),0x3244b8,std::uint16_t(roll));memory[0x2b8de8]=std::uint8_t(observed);
        std::fill_n(memory.data()+0x3c5630,256*60,0x53);std::fill_n(memory.data()+0x4a5c30,8*0x10e0,0x67);std::fill_n(memory.data()+0x4bac52,32,0x41);
        for(auto& row:session->auxiliary_resources)row.fill(0x41);
        for(unsigned slot=0;slot<8;++slot){auto actor=world.primary(slot);actor->model_variant=std::uint16_t(all_variants?variant:(roll+slot)%153);actor->character=std::uint8_t(slot);actor->inventory={};
            const auto at=0x4a5c30+slot*0x10e0;transform_write(memory.data(),at+0xbb4,actor->model_variant);memory[at+0xb98]=actor->character;std::fill_n(memory.data()+at+0xc84,36,0);
        }
        std::vector<std::uint8_t> projected(memory.begin()+0x4a5c30,memory.begin()+0x4a5c30+8*0x10e0);
        call(memory,0x591c50);const auto result=bootstrap.run(owned);check(result.status==a::ResourceImportStatus::completed);check(result.item_found);
        for(unsigned slot=0;slot<256;++slot){std::array<std::uint8_t,60> expected;descriptor_bytes(expected.data(),*resources.get(*resources.slot(slot)));check(std::memcmp(expected.data(),memory.data()+0x3c5630+slot*60,60)==0);}
        check(resources.active_count()==transform_read<std::uint32_t>(memory.data(),0x743128));
        const auto& state=templates.state();check(state.count==transform_read<std::uint16_t>(memory.data(),0x74ccf0));
        check(std::memcmp(state.templates.data(),memory.data()+0x74bb50,129*24)==0);check(std::memcmp(state.y_offsets.data(),memory.data()+0x74b940,129*4)==0);check(std::memcmp(state.offsets.data(),memory.data()+0x74c770,128*4)==0);check(std::memcmp(state.compatibility.data(),memory.data()+0x74c970,384*2)==0);check(std::memcmp(state.selectors.data(),memory.data()+0x74b6e0,600)==0);
        for(unsigned i=0;i<129;++i)for(unsigned lane=0;lane<4;++lane)check(bootstrap.tuning()[i].values[lane]==transform_read<std::int16_t>(memory.data(),0x74b2d0+8*i+2*lane));
        check(std::memcmp(session->auxiliary_resources.data(),memory.data()+0x4bac52,32)==0);
        for(unsigned slot=0;slot<8;++slot){const auto actor=world.primary(slot);std::memcpy(projected.data()+slot*0x10e0+0xc84,actor->inventory.carried.data(),4);std::memcpy(projected.data()+slot*0x10e0+0xc88,actor->inventory.storage.data(),32);}
        check(std::memcmp(projected.data(),memory.data()+0x4a5c30,projected.size())==0);
        const auto random=session->random.state();check(random.primary==transform_read<std::uint16_t>(memory.data(),0x3244b0)&&random.secondary==transform_read<std::uint16_t>(memory.data(),0x3244b8)&&random.observed==memory[0x2b8de8]);
        selected+=result.selected;placed+=result.placed;starting+=result.starting;++cases;
    };
    for(auto value:{1u,2u,28u,35u,41u}){scenario=std::uint16_t(value);
        if(!offline_only){for(unsigned difficulty=0;difficulty<4;++difficulty)for(unsigned observed=0;observed<4;++observed)for(unsigned roll=0;roll<100;++roll)run(difficulty,observed,roll,0,false);
            for(unsigned variant=0;variant<=152;++variant)run(0,0,37,variant,true);}
        // Actual mode-zero fixed rows, both 4BAE96 branches, and all clock/
        // roster populations. Original RNG state must remain identical.
        for(unsigned difficulty=0;difficulty<4;++difficulty)for(unsigned flags=0;flags<2;++flags)
            for(unsigned roll=0;roll<9;++roll)run(difficulty,roll%4,roll,0,false,0,flags);
    }
    const auto previous=resources.active_count();const auto unchanged=[&]{check(resources.active_count()==previous);++refusals;};
    world.mode=0;session->difficulty.reset();check(bootstrap.run(owned).status==a::ResourceImportStatus::unavailable_profile);unchanged();world.mode=1;session->difficulty=0;
    session->difficulty.reset();check(bootstrap.run(owned).status==a::ResourceImportStatus::unavailable_profile);unchanged();session->difficulty=0;
    session->asset_loading_mode=0;check(bootstrap.run(owned).status==a::ResourceImportStatus::unavailable_profile);unchanged();session->asset_loading_mode=1;
    session->primary_population=9;check(bootstrap.run(owned).status==a::ResourceImportStatus::unavailable_profile);unchanged();
    std::cout<<"{\"status\":\"passed\",\"checks\":"<<checks<<",\"cases\":"<<cases<<",\"original_calls\":"<<calls<<",\"original_reads\":"<<reads<<",\"selected\":"<<selected<<",\"placed\":"<<placed<<",\"starting\":"<<starting<<",\"asset_mode_prefixes\":"<<mode_prefixes<<",\"refusals\":"<<refusals<<",\"game_launched\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
