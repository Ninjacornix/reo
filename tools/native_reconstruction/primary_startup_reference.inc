#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
namespace {
constexpr unsigned source_actor=0x4a5c30;
std::vector<std::uint8_t> memory(0x2000000);
std::vector<Event> source_events;
unsigned source_model_calls{},source_imports{},source_ai_calls{};
struct SourceStopped {};
struct SourceInput {
    std::array<w::Actor,8> actors;unsigned population{},mode{},stage{},phase{},row{};
    std::int8_t kind{};bool snapshot{};std::size_t stop=~std::size_t{};
} source_input;
template<class T>void source_put(unsigned at,T value){std::memcpy(memory.data()+at,&value,sizeof value);}
void source_event(unsigned at,unsigned first=0,unsigned second=0){source_events.push_back({at,first,second});if(source_events.size()-1==source_input.stop)throw SourceStopped{};}
}
void begin_source(Fixture& fixture){
    source_input.population=*fixture.world.session().primary_population;source_input.mode=fixture.world.mode;source_input.stage=*fixture.world.session().scene_stream_stage;source_input.phase=std::uint8_t(fixture.world.session().message_phase);source_input.kind=fixture.effects.kind;source_input.row=fixture.update.action_choices().state().table_row;source_input.snapshot=bool(fixture.world.session().primary_initialization_snapshot);source_input.stop=fixture.effects.fail_at;
    for(unsigned i=0;i<8;++i)source_input.actors[i]=*fixture.world.primary(i);
}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++source_calls;const auto at=context->pc;const unsigned first=GPR_U32(context,4),second=GPR_U32(context,5);
    switch(at){
#include "original_dispatch.hpp"
    case 0x1ac630:SET_GPR_U32(context,2,0);break;
    case 0x1ba440:if(std::int32_t(first)<5)source_event(at,first,second);break;
    case 0x1af6a0:source_event(at,first);break;
    case 0x1b0510:case 0x18dcb0:source_event(at);break;
    case 0x1cde10:
        check(second==0x2000||second==0x2500||second==0x2a00);
        source_event(second==0x2000?0x1d24f0:second==0x2500?0x1d2550:0x1d24b0);break;
    case 0x5ec100:
        check(first<8&&second==source_actor+0x10e0*first);
        memory[second]=1;++source_model_calls;break;
    case 0x1d1a80:break; // Actual native immutable asset/default publication runs independently.
    case 0x1d3a70:case 0x1d3ca0:
        check(first>=source_actor&&(first-source_actor)%0x10e0==0);
        source_event(at,(first-source_actor)/0x10e0);break;
    case 0x1d45f0:case 0x6baa40:++source_imports;break; // Native archive/import owners run independently.
    case 0x8120c0:++source_ai_calls;break; // Native initialization runs against canonical controls/navigation.
    case 0x1d3f60:if(memory[0x3243f2]==0)source_event(at);break;
    case 0x1d1c50:case 0x1d1030:case 0x1d0b70:case 0x1b0ac0:
    case 0x591c50:case 0x6ad5c0:case 0x1d3e90:case 0x68c890:
    case 0x5a4f90:case 0x1d4020:case 0x1d4570:case 0x1d49e0:
    case 0x1cd080:case 0x1d2050:case 0x6dd9a0:case 0x6ecac0:case 0x63f590:
        if(at==0x1cd080)check(first==0x2600&&second==2);
        source_event(at);break;
    default:throw std::runtime_error("Undeclared startup source port "+std::to_string(at));
    }
    context->pc=GPR_U32(context,31);
}
void compare_source(Fixture& fixture,unsigned,const w::PrimaryStartupReport& result,const std::vector<Event>& events){
    if(result.status!=w::PrimaryStartupStatus::completed&&source_input.stop==~std::size_t{})return;
    std::fill(memory.begin(),memory.end(),0);owned_constants(memory.data());source_events.clear();source_model_calls=source_imports=source_ai_calls=0;
    const auto population=source_input.population;
    source_put(0x4baea0,std::uint32_t(population));memory[0x3243d7]=1;memory[0x3243fe]=std::uint8_t(source_input.stage);memory[0x3243fb]=std::uint8_t(source_input.phase);memory[0x3243f2]=std::uint8_t(source_input.mode);memory[0x3166a0]=std::uint8_t(source_input.snapshot);
    memory[0x4badf7]=std::uint8_t(source_input.row);memory[0x4badf0+memory[0x4badf7]]=std::uint8_t(source_input.kind);
    for(unsigned character=0;character<8;++character)source_put(0x747400+4*character,float(character)*1.25f-3.f);
    for(unsigned i=0;i<8;++i){const auto at=source_actor+0x10e0*i;const auto& actor=source_input.actors[i];memory[at]=std::uint8_t(actor.active);memory[at+3]=actor.slot;memory[at+0xb98]=actor.character;source_put(at+0x1e2,actor.room);source_put(at+0xbac,actor.gauge_value);source_put(at+0xbb6,actor.gauge_modifier_one);source_put(at+0xbb8,actor.gauge_modifier_two);source_put(at+0xbba,actor.linked_model_variant);source_put(at+0xd2c,actor.action_elapsed);source_put(at+0xd28,actor.control_elapsed);}
    R5900Context context{};PS2Runtime runtime;context.pc=0x5eb520;SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0xabcdef);bool stopped{};
    try{original_transform_port(memory.data(),&context,&runtime);}catch(const SourceStopped&){stopped=true;}
    check(stopped==(result.status!=w::PrimaryStartupStatus::completed));
    if(!stopped){check(context.pc==0xabcdef&&GPR_U32(&context,29)==0x1f00000&&source_model_calls==population&&source_imports==2);++source_cases;}else ++source_prefixes;
    check(memory[0x3243d2]==fixture.world.session().setup_gate&&memory[0x3243fe]==fixture.world.session().scene_stream_stage);
    if(source_events!=events){for(unsigned i=0;i<std::min(source_events.size(),events.size());++i)if(source_events[i]!=events[i]){std::cerr<<"event "<<i<<" original="<<std::hex<<source_events[i].at<<" native="<<events[i].at<<std::dec<<'\n';break;}std::cerr<<"events "<<source_events.size()<<"/"<<events.size()<<'\n';}check(source_events==events);
    check(source_ai_calls==(fixture.world.mode==0?result.gauges_initialized:0));
    for(unsigned i=0;i<8;++i){const auto actor=fixture.world.primary(i);const auto at=source_actor+0x10e0*i;check(actor->slot==memory[at+3]&&actor->room==transform_read<std::uint16_t>(memory.data(),at+0x1e2));check(actor->action_elapsed==transform_read<unsigned>(memory.data(),at+0xd2c)&&actor->control_elapsed==transform_read<unsigned>(memory.data(),at+0xd28)&&actor->gauge_value==transform_read<unsigned>(memory.data(),at+0xbac));check(actor->gauge_modifier_one==transform_read<std::uint16_t>(memory.data(),at+0xbb6)&&actor->gauge_modifier_two==transform_read<std::uint16_t>(memory.data(),at+0xbb8)&&actor->linked_model_variant==transform_read<std::uint16_t>(memory.data(),at+0xbba));if(i<result.gauges_initialized)check(actor->model_height_correction==transform_read<float>(memory.data(),at+0xbb0));}
}
