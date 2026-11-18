#include "primary_actor_records.hpp"
#include <cstring>
#include <iostream>
#include <source_location>
#include <stdexcept>
namespace w=reo::native::gameplay_world;
std::uint64_t checks{},source_cases{},lifetimes{},capacity_cases{},busy_cases{};
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Primary record bootstrap "+std::to_string(at.line()));}
w::Profile profile(unsigned capacity=1024){w::Profile value;value.layouts.push_back({});value.entities.capacity=capacity;return value;}
#ifdef REO_PRIMARY_RECORDS_ORIGINAL
#include "reference.hpp"
#include "functions.h"
constexpr unsigned source_base=0x4a5c30,source_bytes=0x8700;
std::vector<std::uint8_t> memory(0x2000000);
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){switch(context->pc){
#include "original_dispatch.hpp"
default:throw std::runtime_error("Undeclared primary bootstrap source helper");}}
void original_clear(unsigned seed){for(unsigned i=0;i<source_bytes+32;++i)memory[source_base-16+i]=std::uint8_t(seed+i*37+1);const auto before=memory;R5900Context context;PS2Runtime runtime;context.pc=0x66a730;SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0xabcdef);original_transform_port(memory.data(),&context,&runtime);check(context.pc==0xabcdef&&GPR_U32(&context,29)==0x1f00000&&GPR_U32(&context,2)==source_base);for(unsigned i=0;i<source_bytes;++i)check(memory[source_base+i]==0);check(std::memcmp(memory.data()+source_base-16,before.data()+source_base-16,16)==0&&std::memcmp(memory.data()+source_base+source_bytes,before.data()+source_base+source_bytes,16)==0);++source_cases;}
#endif
void check_cleared(const w::Actor& actor,unsigned physical){
    check(actor.contact_style_discriminator==0);
    check(actor.sound_state==w::ActorSoundState{}&&actor.projectile_variant==0);
    check(actor.speech.selection&&actor.speech.selection->sequence==0&&actor.speech.selection->target_identifier==0&&actor.speech.selection->target_context==0&&actor.speech.selection->pending==0&&actor.speech.selection->response_state==0&&actor.speech.variant==0&&actor.speech.gauge_notice==0);
    check(actor.speech.request==0&&actor.speech.notice==0&&actor.speech.repeat_delay==0&&actor.speech.response_delay==0&&actor.speech.target_lock==0&&actor.speech.timing_active==0&&actor.speech.previous_elapsed==0&&actor.speech.elapsed==0&&actor.speech.remote_request==0);
    check(actor.speech.dialogue_delay==0&&actor.speech.display_style==0&&actor.speech.partner_characters==std::array<std::int8_t,4>{});
    check(!actor.active&&!actor.visible&&actor.category==0&&actor.slot==0&&actor.primary==0&&actor.secondary==0&&actor.phase==0&&actor.subphase==0);
    check(actor.current==0&&actor.maximum==0&&actor.status==0&&actor.auxiliary_status==0&&actor.room==0&&actor.character==0&&actor.model_variant==0);
    check(actor.position.x==0&&actor.position.y==0&&actor.position.z==0&&actor.orientation==std::array<std::int16_t,4>{});
    check(actor.model_scale.x==0&&actor.model_scale.y==0&&actor.model_scale.z==0&&actor.motion_rate==0&&actor.motion_multiplier==0);
    check(actor.surface_kind==0&&actor.surface_material==0&&actor.surface_normal.x==0&&actor.surface_normal.y==0&&actor.surface_normal.z==0);
    check(actor.surface_transition_flags==0&&actor.secondary_pose_category_override==0&&actor.secondary_pose_history.has_value()&&actor.head_reaction.has_value());
    for(const auto& vector:actor.secondary_pose_history->displacement)check(vector.x==0&&vector.y==0&&vector.z==0);
    const auto& head=*actor.head_reaction;check(head.mode==0&&head.ticks==0&&head.retarget_ticks==0&&!head.target&&head.current==std::array<std::int16_t,2>{}&&head.applied==std::array<std::int16_t,2>{}&&head.step==std::array<std::int16_t,2>{});
    for(const auto& column:head.local)for(const float value:column)check(value==0);
    check(!actor.model&&!actor.model_asset&&!actor.animation&&!actor.constraints&&!actor.alignment_target);
    check(actor.ai_execution&&*actor.ai_execution==reo::native::gameplay_ai::ExecutionState{});
    check(actor.navigation_route.has_value());const auto& route=*actor.navigation_route;
    check(route.current_node==0&&route.destination_node==0&&route.last_current_node==0&&route.output.link==0&&route.output.route.first==0&&route.output.route.second==0);
    check(route.final_position.x==0&&route.final_position.y==0&&route.final_position.z==0&&route.output.route.first_position.x==0&&route.output.route.first_position.y==0&&route.output.route.first_position.z==0&&route.output.route.second_position.x==0&&route.output.route.second_position.y==0&&route.output.route.second_position.z==0);
    check(route.previous_action==0&&route.action==0&&route.destination_room==0&&route.completed==0&&route.selection_mode==0&&route.refresh==0&&route.travel_ticks==0);
    check(actor.inventory.carried==std::array<std::uint8_t,4>{}&&actor.inventory.storage==std::array<std::uint8_t,32>{});
#ifdef REO_PRIMARY_RECORDS_ORIGINAL
    const auto at=source_base+physical*0x10e0;check(actor.sound_state->allocation_slot==memory[at+0x554]&&actor.sound_state->program_variant==memory[at+0x33]&&*actor.projectile_variant==memory[at+0xcf2]);check(actor.slot==memory[at+3]&&*actor.surface_transition_flags==memory[at+0xce2]&&*actor.secondary_pose_category_override==transform_read<unsigned>(memory.data(),at+0xfac));check(actor.position.x==transform_read<float>(memory.data(),at+0x38)&&actor.model_scale.y==transform_read<float>(memory.data(),at+0xb8)&&head.ticks==transform_read<std::int16_t>(memory.data(),at+0xbd2));
    check(actor.ai_execution->goal==transform_read<std::uint16_t>(memory.data(),at+0xff4)&&actor.ai_execution->action==transform_read<std::uint16_t>(memory.data(),at+0xff8)&&!actor.ai_execution->weight_profile&&transform_read<unsigned>(memory.data(),at+0x10ac)==0);
    check(route.output.link==transform_read<std::int16_t>(memory.data(),at+0x10aa)&&route.current_node==std::int8_t(memory[at+0x100c])&&route.final_position.z==transform_read<float>(memory.data(),at+0x1018)&&route.selection_mode==memory[at+0x105b]);
    for(unsigned i=0;i<4;++i)check((*actor.speech.partner_characters)[i]==std::int8_t(memory[at+0xdac+i]));
    check(actor.speech.selection->sequence==transform_read<std::uint32_t>(memory.data(),at+0xdb4)&&*actor.speech.gauge_notice==transform_read<std::int32_t>(memory.data(),at+0xdb8)&&*actor.speech.variant==std::int8_t(memory[at+0xda9]));
    check(actor.speech.selection->pending==std::int8_t(memory[at+0xdc0])&&actor.speech.selection->response_state==std::int8_t(memory[at+0xdc1])&&actor.speech.selection->target_identifier==transform_read<std::int16_t>(memory.data(),at+0xdc2)&&actor.speech.selection->target_context==std::int8_t(memory[at+0xdc7]));
    check(*actor.speech.request==std::int8_t(memory[at+0xda8])&&*actor.speech.notice==transform_read<std::int16_t>(memory.data(),at+0xdaa));
    check(*actor.speech.repeat_delay==transform_read<std::int32_t>(memory.data(),at+0xdb0)&&*actor.speech.response_delay==transform_read<std::int16_t>(memory.data(),at+0xdbe));
    check(*actor.speech.target_lock==std::int8_t(memory[at+0xdc5])&&*actor.speech.remote_request==memory[at+0x1098]);
    check(*actor.speech.timing_active==transform_read<std::int32_t>(memory.data(),at+0xdc8)&&*actor.speech.previous_elapsed==transform_read<std::int32_t>(memory.data(),at+0xdcc)&&*actor.speech.elapsed==transform_read<std::int32_t>(memory.data(),at+0xdd0));
    check(*actor.speech.dialogue_delay==transform_read<std::int16_t>(memory.data(),at+0xdbc)&&*actor.speech.display_style==std::int8_t(memory[at+0x1075]));
#else
    (void)physical;
#endif
}
struct Busy final:w::Services {
    void begin_offline_frame(w::World& world)override{check(w::initialize_primary_records(world).status==w::PrimaryRecordsStatus::busy);++busy_cases;}
    void run(w::Stage,w::World&,w::Actor&)override{std::terminate();}
    bool remote_motion(w::World&,w::Actor&)override{std::terminate();}
    bool find_grid(w::World&,w::Actor&,std::int8_t&)override{std::terminate();}
    void switch_grid(w::World&,std::int32_t,std::int32_t)override{std::terminate();}
    float grid_response(w::World&,std::uint8_t)override{std::terminate();}
};
int main()try{
    const w::Actor generic;check(!generic.sound_state&&!generic.projectile_variant);check(!generic.speech.dialogue_delay&&!generic.speech.display_style&&!generic.speech.partner_characters);
    check(!generic.speech.selection&&!generic.speech.variant&&!generic.speech.gauge_notice);
    check(!generic.speech.request&&!generic.speech.notice&&!generic.speech.repeat_delay&&!generic.speech.response_delay&&!generic.speech.target_lock&&!generic.speech.timing_active&&!generic.speech.previous_elapsed&&!generic.speech.elapsed&&!generic.speech.remote_request);
    for(unsigned seed=0;seed<64;++seed){
#ifdef REO_PRIMARY_RECORDS_ORIGINAL
        original_clear(seed);
#endif
        w::World world(profile(),std::make_shared<w::Session>());world.mode=std::uint8_t(seed%4);world.selected_actor=7;world.room=42;world.session().primary_population=3;auto separate=std::make_unique<w::Actor>();separate->character=93;const auto outside=world.spawn_linked(std::move(separate)).id;const auto retained_outside=world.resolve(outside);check(bool(retained_outside));
        const auto result=w::initialize_primary_records(world);check(result.status==w::PrimaryRecordsStatus::completed&&result.initialized==8&&!world.busy());check(world.mode==seed%4&&world.selected_actor==7&&world.room==42&&world.session().primary_population==3&&world.resolve(outside)==retained_outside&&retained_outside->character==93);
        std::array<std::shared_ptr<w::Actor>,8> retained;std::array<w::actors::EntityId,8> identities;for(unsigned index=0;index<8;++index){retained[index]=world.primary(index);identities[index]=world.identity(index);check(bool(retained[index])&&world.resolve(identities[index])==retained[index]);check_cleared(*retained[index],index);for(unsigned earlier=0;earlier<index;++earlier)check(identities[earlier]!=identities[index]&&retained[earlier]!=retained[index]);}
        retained[7]->character=41;retained[7]->surface_transition_flags=17;retained[7]->secondary_pose_history->displacement[0]={1,2,3};check(w::initialize_primary_records(world).status==w::PrimaryRecordsStatus::not_empty&&world.identity(7)==identities[7]&&world.primary(7)->character==41&&world.primary(7)->surface_transition_flags==17&&world.primary(7)->secondary_pose_history->displacement[0].x==1);
        check(world.close()==w::Status::completed&&w::initialize_primary_records(world).status==w::PrimaryRecordsStatus::closed);for(unsigned index=0;index<8;++index){check(!world.resolve(identities[index])&&retained[index]->slot==0);++lifetimes;}check(retained[7]->character==41&&retained_outside->character==93);
    }
    for(unsigned capacity=1;capacity<=8;++capacity){w::World world(profile(capacity),std::make_shared<w::Session>());const auto outside=capacity?world.spawn_linked(std::make_unique<w::Actor>()).id:w::actors::EntityId{};const auto retained=world.resolve(outside);check(w::initialize_primary_records(world).status==w::PrimaryRecordsStatus::entity_capacity&&!world.busy());for(unsigned i=0;i<8;++i)check(!world.primary(i)&&!world.identity(i));check(world.resolve(outside)==retained);if(capacity>1)check(world.spawn_linked(std::make_unique<w::Actor>()).status==w::actors::EntityStatus::completed);++capacity_cases;}
    w::World partial(profile(),std::make_shared<w::Session>());auto actor=std::make_unique<w::Actor>();actor->slot=6;actor->character=51;const auto existing=partial.spawn_primary(4,std::move(actor)).id;check(w::initialize_primary_records(partial).status==w::PrimaryRecordsStatus::not_empty&&partial.resolve(existing)->slot==6&&partial.resolve(existing)->character==51&&!partial.primary(0));
    w::World busy(profile(),std::make_shared<w::Session>());Busy services;check(busy.update_primary(services).status==w::Status::completed&&busy_cases==1&&!busy.busy());check(w::initialize_primary_records(busy).status==w::PrimaryRecordsStatus::completed);
    std::cout<<"{\"checks\":"<<checks<<",\"complete_source_clears\":"<<source_cases<<",\"canonical_bootstraps\":64,\"capacity_refusals\":"<<capacity_cases<<",\"busy_proofs\":"<<busy_cases<<",\"lifetimes\":"<<lifetimes<<",\"game_run\":false}\n";
}catch(const std::exception& x){std::cerr<<x.what()<<'\n';return 1;}
