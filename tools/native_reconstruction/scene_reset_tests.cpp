#include "game/native/gameplay_application/scene_reset.hpp"
#include "game/native/gameplay_application/native_session.hpp"
#include "runtime/assets/virtual_afs.h"
#include "reference.hpp"
#include "functions.h"
#include <iostream>
#include <vector>
namespace a=reo::native::gameplay_application;
namespace s=reo::native::gameplay_scenario;
namespace w=reo::native::gameplay_world;
namespace e=reo::native::gameplay_effects;
static std::size_t checks{},calls{},clears{},cases{};
static std::uint32_t random_value=0x10385f74;
static std::uint32_t next(){random_value=random_value*1664525u+1013904223u;return random_value;}
static void check(bool value){++checks;if(!value)throw std::runtime_error("Scene reset comparison "+std::to_string(checks));}
struct Notices:s::FlagNotifications{bool changed(const s::ScenarioFlagChange&)noexcept override{return true;}bool changed(const s::StridedFlagChange&)noexcept override{return true;}};
struct BusyServices:w::Services{
    a::SceneResetContext context;std::size_t visits{};
    explicit BusyServices(a::SceneResetContext value):context(value){}
    void begin_offline_frame(w::World&)override{++visits;check(a::reset_scene_models(context)==a::SceneResetStatus::busy);check(context.inventory.reset_request_gate()==w::InventoryUiStatus::busy);}
    void run(w::Stage,w::World&,w::Actor&)override{throw std::runtime_error("Unexpected active busy fixture actor");}
    bool remote_motion(w::World&,w::Actor&)override{throw std::runtime_error("Unexpected busy fixture motion");}
    bool find_grid(w::World&,w::Actor&,std::int8_t&)override{throw std::runtime_error("Unexpected busy fixture grid");}
    void switch_grid(w::World&,std::int32_t,std::int32_t)override{throw std::runtime_error("Unexpected busy fixture grid switch");}
    float grid_response(w::World&,std::uint8_t)override{throw std::runtime_error("Unexpected busy fixture response");}
};
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;const auto at=context->pc;
    if(at==0x107c68){check(GPR_U32(context,5)==0&&GPR_U32(context,6)==96);std::memset(memory+GPR_U32(context,4),0,96);++clears;context->pc=GPR_U32(context,31);return;}
    switch(at){
#include "original_dispatch.hpp"
    default:throw std::runtime_error("Unexpected reset child "+std::to_string(at));
    }
}
static void invoke(std::vector<std::uint8_t>& memory,std::uint32_t address){R5900Context context;PS2Runtime runtime;context.pc=address;transform_set32(&context,29,0x1ff0000);transform_set32(&context,31,0);original_transform_port(memory.data(),&context,&runtime);check(context.pc==0);}
static void channel(std::uint8_t* memory,std::uint32_t at,const s::SceneMatrixChannel& c){
    memory[at+1]=c.contact.gate;memory[at+2]=c.interaction;memory[at+3]=c.progress;memory[at+4]=c.playback;memory[at+6]=std::uint8_t(c.model_slot.encoded());memory[at+7]=c.program;memory[at+8]=c.cursor;memory[at+9]=c.curve;memory[at+10]=c.transform;memory[at+11]=c.contact.active;
    transform_write(memory,at+12,c.time);transform_write(memory,at+14,c.segment);transform_write(memory,at+16,c.sound_cursor);memory[at+20]=c.source_type;std::memcpy(memory+at+32,c.matrix.data(),64);
}
int main(int argc,char** argv)try{
    check(argc==2);auto source=std::make_shared<const reo::assets::Source>(argv[1]);Notices notices;w::Profile profile;profile.layouts.push_back({});auto host=std::make_shared<a::NativeSession>(source,profile,notices);check(host->install_room({41,73,0})==a::SessionStatus::completed);
    auto room=host->retain_room(host);check(bool(room)&&room->current());auto object=room->object_context();auto& models=object.models;auto& bindings=object.bindings;
    check(!host->inventory_ui().request_blocked());s::SceneModelGlobals unknown_globals;s::PriorityTextState unknown_text;check(!unknown_globals.state()&&!unknown_text.active());
    std::vector<std::uint8_t> memory(0x2000000);std::array<std::shared_ptr<s::ModelMatrix>,128> targets;
    for(unsigned seed=0;seed<256;++seed){
        ++cases;const auto initial=models.state();s::SceneMatrixPrograms::State initial_channels;
        for(unsigned index=0;index<16;++index){auto& c=initial_channels[index];c.contact={std::uint8_t(next()),std::uint8_t(next())};c.interaction=std::uint8_t(next());c.progress=std::uint8_t(next());c.playback=std::uint8_t(next());c.model_slot=next()%128;c.program=std::uint8_t(next());c.cursor=std::uint8_t(next());c.curve=std::uint8_t(next());c.transform=std::uint8_t(next());c.time=std::bit_cast<std::int16_t>(std::uint16_t(next()));c.segment=std::bit_cast<std::int16_t>(std::uint16_t(next()));c.sound_cursor=std::bit_cast<std::int16_t>(std::uint16_t(next()));c.source_type=std::uint8_t(next());for(auto& axis:c.matrix)for(auto& lane:axis)lane=std::bit_cast<float>(next());}
        s::FlagState flags;s::SceneMatrixPrograms programs(host->scene_controls(),models,bindings,flags,host->world().room,initial_channels);
        s::SceneModelResetValues old{{std::uint8_t(next()),std::uint8_t(next()),std::uint8_t(next())},std::uint8_t(next()),{}, {},next()};for(auto& value:old.deferred_actor_cleanup)value=std::uint8_t(next());old.translation={std::bit_cast<float>(next()),std::bit_cast<float>(next()),std::bit_cast<float>(next())};s::SceneModelGlobals globals(old);s::PriorityTextState text{std::uint8_t(next())};auto& camera=host->sequences();s::SequenceControlState camera_state;camera_state.selection=std::uint16_t(next());camera_state.phase=std::uint8_t(next());camera_state.selected_id=seed%32;camera_state.active[seed%32]=0xa5;camera_state.condition_id=77;camera_state.restart_byte=7;camera_state.mode=9;check(camera.restore(camera_state));e::Modulation modulation({std::uint16_t(next()),{1,2,3},4});
        check(host->inventory_ui().configure_requests(1)==w::InventoryUiStatus::completed);
        std::fill(memory.begin(),memory.end(),0x95);memory[0x49eef0]=old.controls[0];memory[0x49eef1]=old.controls[1];memory[0x49eef2]=old.controls[2];memory[0x49ef0c]=old.control;std::memcpy(memory.data()+0x4a5c25,old.deferred_actor_cleanup.data(),8);std::memcpy(memory.data()+0x49f770,&old.translation,12);transform_write(memory.data(),0x49f784,old.style_override);
        for(unsigned index=0;index<128;++index){s::ModelMatrix matrix;for(auto& axis:matrix)for(auto& lane:axis)lane=std::bit_cast<float>(next());check(models.pose(index,matrix)==s::ModelStatus::completed);models.mark_slot_byte(std::uint8_t(index),std::uint8_t(next()));targets[index]=std::make_shared<s::ModelMatrix>();check(bindings.bind_pose(std::uint8_t(index),targets[index]));std::memcpy(memory.data()+0x49fa10+64*index,matrix.data(),64);std::memcpy(memory.data()+0x4a3c20+64*index,host->room_models().saved()[index].data(),64);transform_write(memory.data(),0x4a1b70+4*index,0x800000u+64*index);transform_write(memory.data(),0x49f810+4*index,initial.styles[index]);}
        const auto preserved=models.state();const auto remap=models.remap();for(unsigned word=0;word<4;++word)transform_write(memory.data(),0x4a1b60+4*word,bindings.mask()[word]);for(unsigned index=0;index<16;++index)channel(memory.data(),0x4a3620+96*index,initial_channels[index]);const auto& mod=modulation.state();transform_write(memory.data(),0x4bac84,mod.color.x);transform_write(memory.data(),0x4bac88,mod.color.y);transform_write(memory.data(),0x4bac8c,mod.color.z);transform_write(memory.data(),0x4bac90,mod.intensity);transform_write(memory.data(),0x4b9d1a,mod.flags);memory[0x4bae0a]=*text.active();memory[0x4bae8d]=*host->inventory_ui().request_blocked();transform_write(memory.data(),0x3dddb6,camera.snapshot().selection);memory[0x3dddd5]=camera.snapshot().phase;
        invoke(memory,0x5d7d60);check(a::reset_scene_models({host->world(),host->room_models(),models,bindings,programs,modulation,host->inventory_ui(),globals,text,camera})==a::SceneResetStatus::completed);
        const auto& result=*globals.state();check(std::memcmp(result.controls.data(),memory.data()+0x49eef0,3)==0&&result.control==memory[0x49ef0c]);check(std::memcmp(result.deferred_actor_cleanup.data(),memory.data()+0x4a5c25,8)==0);check(std::memcmp(&result.translation,memory.data()+0x49f770,12)==0&&result.style_override==transform_read<unsigned>(memory.data(),0x49f784));check(bindings.mask()==std::array<std::uint32_t,4>{});
        for(unsigned index=0;index<128;++index){const auto pose=*models.pose(index);check(std::memcmp(pose.data(),memory.data()+0x49fa10+64*index,64)==0);check(models.state().styles[index]==transform_read<unsigned>(memory.data(),0x49f810+4*index));check(!bindings.target(std::uint8_t(index)));check(std::memcmp(targets[index]->data(),preserved.poses[index].data(),64)==0);}
        for(unsigned index=0;index<16;++index){std::array<std::uint8_t,96> state{};channel(state.data(),0,*programs.inspect(index));check(std::memcmp(state.data(),memory.data()+0x4a3620+96*index,96)==0);}
        check(modulation.state().flags==0&&modulation.state().color.x==0&&modulation.state().color.y==0&&modulation.state().color.z==0&&modulation.state().intensity==0);check(text.active()==memory[0x4bae0a]&&host->inventory_ui().request_blocked()==memory[0x4bae8d]);check(camera.snapshot().selection==transform_read<std::uint16_t>(memory.data(),0x3dddb6)&&camera.snapshot().phase==memory[0x3dddd5]);check(camera.snapshot().active==camera_state.active&&camera.snapshot().selected_id==camera_state.selected_id&&camera.snapshot().condition_id==77&&camera.snapshot().restart_byte==7&&camera.snapshot().mode==9&&!camera.phase_matches(0));check(models.state().visibility==preserved.visibility&&models.state().sound_resources==preserved.sound_resources&&models.remap()==remap);
        check(programs.reset()==s::SceneMatrixStatus::completed);programs.close();check(programs.reset()==s::SceneMatrixStatus::closed);
    }
    s::SceneModelGlobals globals;s::PriorityTextState text;auto& camera=host->sequences();check(camera.select(3,250)&&camera.phase_matches(0));e::Modulation modulation({});check(a::reset_scene_models({host->world(),host->room_models(),models,bindings,host->scene_matrices(),modulation,host->inventory_ui(),globals,text,camera})==a::SceneResetStatus::completed);
    check(camera.snapshot().selection==0&&!camera.phase_matches(0)&&camera.snapshot().active[3]==1);
    s::SceneModels foreign({},{});s::SceneModelBindings foreign_bindings(foreign,object.entities);check(a::reset_scene_models({host->world(),host->room_models(),models,foreign_bindings,host->scene_matrices(),modulation,host->inventory_ui(),globals,text,camera})==a::SceneResetStatus::unavailable_owner);check(foreign_bindings.close()==s::ModelBindingError::none&&foreign_bindings.reset()==s::ModelBindingError::closed);
    BusyServices busy({host->world(),host->room_models(),models,bindings,host->scene_matrices(),modulation,host->inventory_ui(),globals,text,camera});const auto old_mode=host->world().mode;host->world().mode=0;check(host->world().update_primary(busy).status==w::Status::completed&&busy.visits==1);host->world().mode=old_mode;
    check(host->close()==a::SessionStatus::completed);check(a::reset_scene_models(busy.context)==a::SceneResetStatus::closed);check(host->inventory_ui().reset_request_gate()==w::InventoryUiStatus::closed);
    check(clears==cases*16);std::cout<<"{\"checks\":"<<checks<<",\"cases\":"<<cases<<",\"model_slots\":128,\"channels\":16,\"original_calls\":"<<calls<<",\"memory_primitives\":"<<clears<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
