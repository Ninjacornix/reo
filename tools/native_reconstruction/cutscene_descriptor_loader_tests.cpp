#include "game/native/gameplay_scenario/cutscene_descriptor_loader.hpp"
#include "game/native/gameplay_scenario/cutscene_playback.hpp"
#include "runtime/assets/virtual_afs.h"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <fstream>
#include <iostream>
#include <source_location>
namespace s=reo::native::gameplay_scenario;namespace w=reo::native::gameplay_world;
std::uint64_t checks{},calls{},loads{},reparses{},missing{},sections{},tail_checks{};
unsigned serial{};std::uint16_t current_scenario{};s::CutsceneCue current_cue;std::vector<std::byte> payload;bool absent{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("Descriptor loader case "+std::to_string(serial)+" line "+std::to_string(at.line()));
}
std::string basename(){char name[128];std::snprintf(name,sizeof name,"dm%02u%02u%c.bin",unsigned(current_cue.area),unsigned(current_cue.scene),int(current_cue.variant)+97);return name;}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;const auto done=[&](unsigned value=0){SET_GPR_U32(context,2,value);context->pc=GPR_U32(context,31);};
    const auto name=[&](unsigned reg){return std::string(reinterpret_cast<const char*>(memory+GPR_U32(context,reg)));};
    switch(context->pc){
#include "original_dispatch.hpp"
    case 0x107c68:check(GPR_U32(context,5)==0&&GPR_U32(context,6)==128);std::fill_n(memory+GPR_U32(context,4),128,0);done();return;
    case 0x10a830:{const auto format=name(5);int size{};const auto destination=reinterpret_cast<char*>(memory+GPR_U32(context,4));
        if(format=="data/edit/eve/r%03d/dm%02d%02d%c.bin")size=std::snprintf(destination,128,format.c_str(),GPR_U32(context,6),GPR_U32(context,7),GPR_U32(context,8),GPR_U32(context,9));
        else{check(format=="dm%02d%02d%c.bin");size=std::snprintf(destination,128,format.c_str(),GPR_U32(context,6),GPR_U32(context,7),GPR_U32(context,8));}
        check(size>0&&size<128&&std::string(destination).ends_with(basename()));done(unsigned(size));return;}
    case 0x18dab0:check(name(4).ends_with(basename()));done(absent?0:unsigned(payload.size()));return;
    case 0x1cc8f0:check(name(4).ends_with(basename())&&GPR_U32(context,6)==1&&GPR_U32(context,7)==(absent?0:payload.size()));
        if(!absent){std::memcpy(memory+GPR_U32(context,5),payload.data(),payload.size());}done(absent?0:1);return;
    case 0x1aa1e0:check(GPR_U32(context,4)==current_scenario);transform_write(memory,0x2b16a0,0x123450u);done();return;
    case 0x1a9f20:check(GPR_U32(context,4)==0x123450&&name(5)==basename()&&GPR_U32(context,7)==0);
        if(!absent){std::memcpy(memory+GPR_U32(context,6),payload.data(),payload.size());}done(absent?0:unsigned(payload.size()));return;
    default:throw std::runtime_error("Unadmitted descriptor loader source call "+std::to_string(context->pc));
    }
}
unsigned invoke(std::uint8_t* memory){R5900Context context;PS2Runtime runtime;context.pc=0x5ed900;SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0xabcdef);original_transform_port(memory,&context,&runtime);check(context.pc==0xabcdef&&GPR_U32(&context,29)==0x1f00000);return GPR_U32(&context,2);}
int main(int argc,char** argv)try{
    check(argc==3);auto source=std::make_shared<reo::assets::Source>(argv[1]);s::content::ScenarioArchive archive(source);
    w::Session session;auto workspace=std::make_shared<s::CutsceneDescriptorWorkspace>();s::CutsceneDescriptorLoader loader(session,archive,workspace);s::CutscenePlaybackState state;
    std::vector<std::uint8_t> memory(0x2000000);owned_constants(memory.data());constexpr unsigned base=0x1000000;
    transform_write(memory.data(),0x324428,base-0x40000u);transform_write(memory.data(),0x38ec98,base);
    std::ifstream manifest(argv[2]);check(bool(manifest));unsigned scenario,area,scene,suffix;std::uint64_t offset;std::size_t length;
    std::shared_ptr<const s::CutsceneDescriptor> retained;
    const auto compare=[&](unsigned original,const s::CutsceneDescriptorLoaded& result){
        check(result.status==s::CutsceneDescriptorLoadStatus::completed&&result.value==original);
        if(!result.parsed)return;
        const auto d=loader.descriptor();check(d&&state.loaded_identity==d->identity()&&state.end_frame==d->duration());
        check(state.loaded_identity==transform_read<std::array<std::uint8_t,3>>(memory.data(),0x38ecc8)&&state.end_frame==transform_read<unsigned>(memory.data(),0x38ecb0));
        check(state.light_groups==transform_read<std::int16_t>(memory.data(),0x38ecbc));
        const auto section=[&](s::CutsceneSection value,unsigned pointer){check(transform_read<unsigned>(memory.data(),pointer)==base+value.offset);const auto bytes=d->section(value);check(std::memcmp(bytes.data(),memory.data()+base+value.offset,bytes.size())==0);++sections;};
        const auto groups=[&](const auto& values,unsigned pointer){for(unsigned group=0;group<values.size();++group)for(unsigned stream=0;stream<values[group].size();++stream)section(values[group][stream],pointer+4*unsigned(values[group].size())*group+4*stream);};
        section(d->camera_selection(),0x3901a8);groups(d->camera_streams(),0x3900a0);section(d->events(),0x3901d0);section(d->general(),0x3901c8);groups(d->actor_groups(),0x38fb60);groups(d->object_groups(),0x38f7b0);section(d->secondary(),0x3901c0);
        if(d->extension_groups()){groups(*d->extension_groups(),0x38ff90);section(*d->tail_first(),0x3901b8);section(*d->tail_second(),0x3901b0);section(*d->tail_last(),0x743528);}
        for(std::size_t at=0;at+40<=workspace->capacity;at+=40){const auto bytes=workspace->record40(at);check(bytes&&std::memcmp(bytes->data(),memory.data()+base+at,40)==0);++tail_checks;}
    };
    while(manifest>>scenario>>area>>scene>>suffix>>offset>>length){
        current_scenario=std::uint16_t(scenario);current_cue={std::uint8_t(area),std::uint8_t(scene),std::uint8_t(suffix)};payload.resize(length);source->read(offset,length,payload.data());session.scenario=current_scenario;state.request.current=current_cue;
        for(unsigned mode:{0u,1u,255u}){
            ++serial;session.session_state=0;session.asset_loading_mode=std::uint8_t(mode);session.scenario=current_scenario;
            transform_write(memory.data(),0x324200,session.session_state);transform_write(memory.data(),0x3243d7,std::uint8_t(mode));transform_write(memory.data(),0x3243da,current_scenario);transform_write(memory.data(),0x38ecd0,current_cue);absent=false;
            const auto generation=workspace->generation();const auto original=invoke(memory.data());const auto result=loader.load(state);check(result.read&&result.parsed&&workspace->generation()==generation+1);compare(original,result);++loads;
            const auto snapshot=loader.descriptor();if(!retained)retained=snapshot;
            if(snapshot->secondary().count){const auto at=snapshot->secondary().offset;check(workspace->consume_frame(at,40));transform_write(memory.data(),base+at+2,std::uint16_t(65535));}
            session.session_state=1;session.asset_loading_mode.reset();session.scenario.reset();transform_write(memory.data(),0x324200,session.session_state);
            const auto reused=invoke(memory.data());const auto parsed=loader.load(state);check(!parsed.read&&parsed.parsed&&workspace->generation()==generation+1);compare(reused,parsed);++reparses;
            if(snapshot->secondary().count)check(std::memcmp(snapshot->section(snapshot->secondary()).data(),payload.data()+snapshot->secondary().offset,40)==0);
        }
    }
    check(manifest.eof()&&loads==1644&&reparses==1644&&retained);
    // Missing reads preserve the previous descriptor and every workspace byte.
    for(unsigned mode:{0u,1u,255u}){session.session_state=0;session.asset_loading_mode=std::uint8_t(mode);session.scenario=0;current_scenario=0;absent=true;transform_write(memory.data(),0x324200,session.session_state);transform_write(memory.data(),0x3243d7,std::uint8_t(mode));transform_write(memory.data(),0x3243da,current_scenario);
        const auto snapshot=loader.descriptor();const auto generation=workspace->generation();const auto original=invoke(memory.data());const auto result=loader.load(state);compare(original,result);check(!result.read&&!result.parsed&&result.value==1&&loader.descriptor()==snapshot&&workspace->generation()==generation);++missing;}
    session.asset_loading_mode.reset();check(loader.load(state).status==s::CutsceneDescriptorLoadStatus::unavailable);
    session.session_state=1;auto empty=std::make_shared<s::CutsceneDescriptorWorkspace>();s::CutsceneDescriptorLoader unbound(session,archive,empty);check(unbound.load(state).status==s::CutsceneDescriptorLoadStatus::unavailable);
    bool refused=false;try{s::CutsceneDescriptorLoader invalid(session,archive,{});}catch(const std::invalid_argument&){refused=true;}check(refused);
    std::cout<<"{\"checks\":"<<checks<<",\"loads\":"<<loads<<",\"reparses\":"<<reparses<<",\"missing_reads\":"<<missing<<",\"sections\":"<<sections<<",\"retained_tail_checks\":"<<tail_checks<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
