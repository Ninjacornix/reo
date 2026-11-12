#include "game/native/gameplay_world/dialogue_targeting.hpp"
#include "game/native/gameplay_world/primary_actor_records.hpp"
#include "game/native/gameplay_world/auxiliary_actors.hpp"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <bit>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <vector>
namespace w=reo::native::gameplay_world;
namespace {
std::vector<std::uint8_t> memory(0x2000000);std::uint64_t checks{},cases{},calls{},retained_locks{},category_targets{};
constexpr unsigned base=0x4a5c30;
void check(bool value){++checks;if(!value)throw std::runtime_error("Dialogue target comparison "+std::to_string(cases)+" check "+std::to_string(checks));}
template<class T>void put(unsigned at,T value){std::memcpy(memory.data()+at,&value,sizeof value);}
template<class T>T get(unsigned at){T value;std::memcpy(&value,memory.data()+at,sizeof value);return value;}
w::Profile profile(){w::Profile value;value.layouts.push_back({});return value;}
void export_actor(const w::Actor& a,unsigned at){put(at,std::int8_t(a.active));put(at+1,std::int8_t(a.visible));put(at+2,a.category);put(at+3,a.slot);put(at+0x38,a.position);put(at+0x92,a.orientation[1]);put(at+0x1e2,a.room);put(at+0xb98,a.character);put(at+0xbb4,a.model_variant);put(at+0xdb4,a.speech.selection->sequence);put(at+0xdc0,a.speech.selection->pending);put(at+0xdc1,a.speech.selection->response_state);put(at+0xdc2,a.speech.selection->target_identifier);put(at+0xdc5,*a.speech.target_lock);put(at+0xdc7,a.speech.selection->target_context);}
}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){++calls;switch(context->pc){
#include "original_dispatch.hpp"
default:throw std::runtime_error("Undeclared dialogue target source helper "+std::to_string(context->pc));}}
int main()try{
    w::World world(profile(),std::make_shared<w::Session>());check(w::initialize_primary_records(world).status==w::PrimaryRecordsStatus::completed);auto& auxiliary=world.auxiliary_actors();
    std::array<w::actors::EntityId,3> ids;for(auto& id:ids){const auto created=auxiliary.allocate();check(created.status==w::AuxiliaryStatus::completed);id=created.id;}
    const auto address=[&](const w::actors::EntityId& id){for(unsigned i=0;i<8;++i)if(id==world.identity(i))return base+0x10e0*i;for(unsigned i=0;i<ids.size();++i)if(id==ids[i])return 0x100000+0x2000*i;return 0u;};
    owned_constants(memory.data());put(0x3b59f0,address(auxiliary.head()));
    constexpr std::array<float,15> edges{-301,-300,-100,-99,-1,-0.f,0.f,1,50,99,100,101,299,300,301};
    for(unsigned seed=0;seed<16384;++seed){
        for(unsigned i=0;i<11;++i){const auto actor=i<8?world.primary(i):world.resolve(ids[i-8]);actor->active=(seed+i)%5!=0;actor->visible=(seed+3*i)%7!=0;actor->slot=std::uint8_t((seed/11+i)%8);actor->category=i<8?0:1;actor->character=std::uint8_t((seed+i)%8);actor->model_variant=std::uint16_t((seed+i)%8);actor->room=std::uint16_t((seed+i)%3);actor->orientation[1]=std::bit_cast<std::int16_t>(std::uint16_t(seed*19+i*8192));actor->position={edges[(seed+i)%edges.size()],edges[(seed/15+i)%edges.size()],edges[(seed/225+i)%edges.size()]};actor->speech.selection=w::SpeechSelection{0xa5a5a5a5u,std::int16_t(int(seed%9)-1),std::int8_t(int((seed/9)%3)-1),-3,2};actor->speech.target_lock=std::bit_cast<std::int8_t>(std::uint8_t(seed/3));}
        const auto id=seed%3?world.identity(0):ids[0];const auto actor=world.resolve(id);const auto before=*actor->speech.selection;const auto previous_lock=*actor->speech.target_lock;
        for(unsigned i=0;i<8;++i)export_actor(*world.primary(i),base+0x10e0*i);
        for(const auto& aux_id:ids){const auto at=address(aux_id);export_actor(*world.resolve(aux_id),at);put(at+0x1c,address(auxiliary.next(aux_id)));}
        check(w::update_dialogue_target(world,id)==w::DialogueStatus::completed);
        R5900Context state;PS2Runtime runtime;state.pc=0x6b88e0;SET_GPR_U32(&state,4,address(id));SET_GPR_U32(&state,29,0x1f00000);SET_GPR_U32(&state,31,0xabcdef);original_transform_port(memory.data(),&state,&runtime);check(state.pc==0xabcdef&&GPR_U32(&state,29)==0x1f00000);
        const auto at=address(id);const auto& speech=*actor->speech.selection;check(speech.target_identifier==get<std::int16_t>(at+0xdc2)&&speech.target_context==get<std::int8_t>(at+0xdc7)&&actor->speech.target_lock==get<std::int8_t>(at+0xdc5));check(speech.sequence==before.sequence&&speech.pending==before.pending&&speech.response_state==before.response_state);
        retained_locks+=previous_lock&&*actor->speech.target_lock;category_targets+=actor->category!=0;++cases;
    }
    auto actor=world.primary(0);actor->speech.selection.reset();check(w::update_dialogue_target(world,world.identity(0))==w::DialogueStatus::unavailable);check(w::update_dialogue_target(world,{})==w::DialogueStatus::unavailable);check(world.close()==w::Status::completed&&w::update_dialogue_target(world,{})==w::DialogueStatus::closed);
    std::cout<<"{\"checks\":"<<checks<<",\"complete_original_cases\":"<<cases<<",\"source_calls\":"<<calls<<",\"retained_lock_profiles\":"<<retained_locks<<",\"nonprimary_profiles\":"<<category_targets<<",\"native_capability_checks\":3,\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
