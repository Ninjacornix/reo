#include "dialogue_responses_state.hpp"
#include "dialogue_input_request.hpp"
#include "dialogue_partner_characters.hpp"
#include "dialogue_targeting.hpp"
#include "auxiliary_actors.hpp"
#include "../gameplay_update/update.hpp"
#include <bit>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
std::int16_t decrement(std::int16_t value)noexcept{return std::bit_cast<std::int16_t>(std::uint16_t(std::int32_t(value)-1));}
std::int32_t decrement(std::int32_t value)noexcept{return std::bit_cast<std::int32_t>(std::uint32_t(value)-1);}
std::int32_t increment(std::int32_t value)noexcept{return std::bit_cast<std::int32_t>(std::uint32_t(value)+1);}
}
DialogueResponsesState::Bank::Bank(std::shared_ptr<const gameplay_scenario::DialogueCues> cues):program(std::move(cues)),mutable_rows(program.physical_rows()){
    for(std::size_t i=0;i<gameplay_scenario::DialogueCues::selections;++i)if(const auto entry=program.response(i)){
        auto& row=mutable_rows[entry->physical_row];if(!row)row=DialogueResponseMutable{entry->definition.cue,entry->initial.condition_results,entry->initial.replied_to};
    }
}
DialogueResponsesState::DialogueResponsesState(DialoguePool& pool):pool_(pool),world_(pool.world_){}
void DialogueResponsesState::clear_owned()noexcept{banks_={};choices_={};uses_={};selected_use_=-1;report_={};}
void DialogueResponsesState::bind(const DialogueBanks& input){
    auto retained=retained_banks_;std::array<std::shared_ptr<Bank>,9> next;
    for(std::size_t i=0;i<next.size();++i){
        if(!input[i].cues)continue;
        for(const auto& known:retained)if(known->program.cues()->backing()==input[i].cues->backing()){next[i]=known;break;}
        if(!next[i]){next[i]=std::make_shared<Bank>(input[i].cues);retained.push_back(next[i]);}
    }
    retained_banks_=std::move(retained);banks_=std::move(next);
}
DialogueStatus DialogueResponsesState::select_bank(const Actor& actor,Bank*& result)const noexcept{
    const auto index=actor.category?8u:unsigned(actor.character);
    if(index>=banks_.size())return DialogueStatus::unsupported_profile;
    result=banks_[index].get();return DialogueStatus::completed;
}
std::optional<DialogueResponsesState::Row> DialogueResponsesState::row(Bank* bank,std::size_t selection)noexcept{
    if(!bank)return{};
    const auto entry=bank->program.response(selection);if(!entry)return{};
    auto& live=bank->mutable_rows[entry->physical_row];return live?std::optional(Row{entry->definition,&*live}):std::nullopt;
}
DialogueStatus DialogueResponsesState::suppression(std::optional<bool>& result)noexcept{
    if(!pool_.presentation_||!pool_.presentation_->bound_to(world_))return DialogueStatus::unavailable;
    result=pool_.presentation_->suppressed();return result?DialogueStatus::completed:DialogueStatus::unavailable;
}
DialogueStatus DialogueResponsesState::input(const actors::EntityId& id,const DialogueResponseFrame& frame,bool& requested,std::optional<std::size_t> physical_index){
    std::optional<bool> hidden;const auto status=suppression(hidden);if(status!=DialogueStatus::completed)return status;
    const auto actor=world_.resolve(id);if(!actor)return DialogueStatus::unavailable;
    const auto result=physical_index?prepare_loop_dialogue_input_request(actor->speech,frame.menu_frame,hidden,*physical_index):prepare_dialogue_input_request(actor->speech,frame.menu_frame,hidden);requested=result.requested;return result.status;
}
DialogueStatus DialogueResponsesState::evaluate(const actors::EntityId& id,Bank* bank,Row& entry,const DialogueResponseFrame& frame){
    const auto selected=world_.primary(world_.selected_actor);if(!selected)return DialogueStatus::unavailable;
    Bank* selected_bank{};auto status=select_bank(*selected,selected_bank);if(status!=DialogueStatus::completed)return status;
    const auto result=evaluate_dialogue_response_choice(world_,&pool_,id,entry.definition,*entry.mutable_row,
        bank?bank->program.cues().get():nullptr,pool_.selected_sequences_[1],selected_bank?selected_bank->program.cues().get():nullptr,choices_,frame.conditions);
    report_.evaluated+=result.evaluated;return result.status;
}
DialogueStatus DialogueResponsesState::monitor(const DialogueResponseFrame& frame){
    selected_use_=-1;const auto selected=world_.primary(world_.selected_actor);if(!selected)return DialogueStatus::unavailable;
    Bank* bank{};auto status=select_bank(*selected,bank);if(status!=DialogueStatus::completed)return status;
    for(std::size_t i=0;i<5000;++i)if(auto entry=row(bank,i);entry&&entry->mutable_row->cue>=0&&entry->definition.group==3){
        report_.selection=i;status=evaluate(world_.identity(world_.selected_actor),bank,*entry,frame);if(status!=DialogueStatus::completed)return status;
        if(choices_[3])choose_dialogue_response_use(uses_,selected_use_,choices_[3]);
    }
    return DialogueStatus::completed;
}
DialogueResponsePriority DialogueResponsesState::priority(const Actor& actor)const noexcept{
    if(actor.category||actor.slot!=world_.selected_actor||!pool_.selected_sequences_[1])return{};
    const auto selected=world_.primary(world_.selected_actor);if(!selected)return{DialogueStatus::unavailable,99};
    Bank* bank{};const auto status=select_bank(*selected,bank);if(status!=DialogueStatus::completed)return{status,99};
    return dialogue_response_priority(actor,world_.selected_actor,pool_.selected_sequences_[1],bank?bank->program.cues().get():nullptr);
}
DialogueStatus DialogueResponsesState::choose(const actors::EntityId& id,const DialogueResponseFrame&,bool& chosen){
    chosen=false;const auto actor=world_.resolve(id);if(!actor)return DialogueStatus::unavailable;
    for(unsigned group=0;group<5;++group){
        if(choices_[group]<=0||(actor->category&&group==3))continue;
        Bank* bank{};auto status=select_bank(*actor,bank);if(status!=DialogueStatus::completed)return status;
        const auto index=std::uint32_t(choices_[group]-1);if(bank&&index>=gameplay_scenario::DialogueCues::selections)return DialogueStatus::unsupported_profile;
        auto entry=row(bank,index);const auto metadata=bank?dialogue_response_cue_metadata(*bank->program.cues(),index):std::nullopt;
        if(metadata){const auto current=priority(*actor);if(current.status!=DialogueStatus::completed)return current.status;if(metadata->priority>=current.value)continue;}
        if(!entry)continue;
        if(!actor->speech.selection)return DialogueStatus::unavailable;
        auto& speech=*actor->speech.selection;
        if(speech.target_context<0){
            // Retail reads primary[DC2].BA0 before checking DC2's sign. A
            // negative identifier addresses unrelated preceding storage.
            if(speech.target_identifier<0||std::uint16_t(speech.target_identifier)>=World::primary_capacity)return DialogueStatus::unsupported_profile;
            const auto target=world_.primary(std::uint16_t(speech.target_identifier));if(!target)return DialogueStatus::unavailable;
            if(target->status&0x20u)continue;
        }
        if(entry->definition.group!=4){
            if(entry->definition.mode==0)entry->mutable_row->cue=-1;
            else if(entry->definition.mode==1&&group!=1){
                if(speech.target_context<0&&speech.target_identifier>=0)entry->mutable_row->replied_to|=1u<<(std::uint16_t(speech.target_identifier)&31u);
                // Both outcomes of the source's subsequent active-primary
                // mask comparison store -1; there is no observable read port.
                entry->mutable_row->cue=-1;
            }
        }
        if(group==3)increment_dialogue_response_use(uses_,choices_[3]);
        speech.sequence=std::uint32_t(choices_[group]);choices_[group]=0;speech.pending=1;actor->speech.response_delay=0;actor->speech.request=1;chosen=true;break;
    }
    return DialogueStatus::completed;
}
DialogueStatus DialogueResponsesState::direct(const actors::EntityId& id,const DialogueResponseFrame& frame,bool& done){
    const auto actor=world_.resolve(id);if(!actor)return DialogueStatus::unavailable;
    if(actor->category==0){
        Bank* bank{};auto status=select_bank(*actor,bank);if(status!=DialogueStatus::completed)return status;
        for(std::size_t i=0;i<5000;++i)if(auto entry=row(bank,i);entry&&entry->mutable_row->cue>=0&&entry->definition.group==6){
            report_.selection=i;const auto cue=std::uint16_t(entry->mutable_row->cue);if(cue>=gameplay_scenario::DialogueCues::selections)return DialogueStatus::unsupported_profile;
            if(const auto metadata=dialogue_response_cue_metadata(*bank->program.cues(),cue)){const auto current=priority(*actor);if(current.status!=DialogueStatus::completed)return current.status;if(metadata->priority>=current.value)continue;}
            status=evaluate(id,bank,*entry,frame);if(status!=DialogueStatus::completed)return status;
            if(choices_[6]){if(!actor->speech.selection)return DialogueStatus::unavailable;actor->speech.selection->sequence=std::uint32_t(choices_[6]);choices_[6]=0;actor->speech.selection->pending=1;actor->speech.response_delay=0;actor->speech.request=1;break;}
        }
    }
    if(!actor->speech.variant)return DialogueStatus::unavailable;
    done=*actor->speech.variant!=0;return DialogueStatus::completed;
}
DialogueStatus DialogueResponsesState::reply_to(const actors::EntityId& id,const actors::EntityId& other_id,const DialogueResponseFrame& frame,bool& done){
    done=false;if(!other_id)return DialogueStatus::completed;
    const auto actor=world_.resolve(id),other=world_.resolve(other_id);if(!actor||!other)return DialogueStatus::unavailable;
    if(!other->active||other->slot==actor->slot)return DialogueStatus::completed;
    if(!other->speech.selection)return DialogueStatus::unavailable;
    auto& spoken=*other->speech.selection;
    bool addressed=spoken.target_identifier<0&&spoken.target_context<0;
    if(!addressed){if(actor->category==0)addressed=spoken.target_context<0&&spoken.target_identifier==actor->character;else addressed=spoken.target_context>=0&&spoken.target_identifier==actor->model_variant;}
    if(!addressed||!spoken.sequence)return DialogueStatus::completed;
    if(actor->category&&other->category)return DialogueStatus::completed;
    Bank* other_bank{};auto status=select_bank(*other,other_bank);if(status!=DialogueStatus::completed)return status;
    if(!other_bank)return DialogueStatus::completed;
    if(spoken.sequence>gameplay_scenario::DialogueCues::selections)return DialogueStatus::unsupported_profile;
    const auto metadata=dialogue_response_cue_metadata(*other_bank->program.cues(),spoken.sequence-1);if(!metadata)return DialogueStatus::completed;
    Bank* bank{};status=select_bank(*actor,bank);if(status!=DialogueStatus::completed)return status;
    for(const auto reply:metadata->replies){
        if(!reply)continue;
        if(bank&&reply>=gameplay_scenario::DialogueCues::selections)return DialogueStatus::unsupported_profile;
        if(auto entry=row(bank,reply);entry&&entry->mutable_row->cue>=0&&entry->definition.group==4&&!choices_[4]){
            status=evaluate(id,bank,*entry,frame);if(status!=DialogueStatus::completed)return status;
        }
    }
    if(!choices_[4])return DialogueStatus::completed;
    for(unsigned i=0;i<choices_.size();++i)if(i!=4)choices_[i]=0;
    if(world_.mode==0)spoken.sequence=0;
    bool chosen{};status=choose(id,frame,chosen);if(status!=DialogueStatus::completed)return status;
    if(!actor->speech.selection)return DialogueStatus::unavailable;
    if(actor->speech.selection->pending)actor->speech.selection->pending=2;
    done=actor->speech.selection->pending!=0;return DialogueStatus::completed;
}
DialogueStatus DialogueResponsesState::reply(const actors::EntityId& id,const DialogueResponseFrame& frame,bool& done){
    const auto actor=world_.resolve(id);if(!actor)return DialogueStatus::unavailable;
    if(actor->category==0){const auto target=actor->slot==world_.selected_actor?pool_.primary_actor_.value_or(actors::EntityId{}):world_.identity(world_.selected_actor);return reply_to(id,target,frame,done);}
    auto status=reply_to(id,pool_.previous_secondary_actor_.value_or(actors::EntityId{}),frame,done);if(status!=DialogueStatus::completed||done)return status;
    return reply_to(id,pool_.primary_actor_.value_or(actors::EntityId{}),frame,done);
}
DialogueStatus DialogueResponsesState::prepare(const actors::EntityId& id,const DialogueResponseFrame& frame){
    const auto actor=world_.resolve(id);if(!actor)return DialogueStatus::unavailable;
    auto& state=actor->speech;
    if(actor->category==0){
        if(actor->slot==world_.selected_actor){
            if(world_.session().cutscene_requests.limit_override)return DialogueStatus::completed;
            if(!state.repeat_delay)return DialogueStatus::unavailable;
            state.repeat_delay=decrement(*state.repeat_delay);
            if(*state.repeat_delay>0){state.request=0;state.variant=0;return DialogueStatus::completed;}
            state.repeat_delay=0;
        }
        const auto partners=rebuild_dialogue_partner_characters(world_,id);if(partners.status!=DialogueStatus::completed)return partners.status;
    }
    if(!actor->active)return DialogueStatus::completed;
    if(!state.dialogue_delay)return DialogueStatus::unavailable;
    if(*state.dialogue_delay){state.dialogue_delay=decrement(*state.dialogue_delay);if(!*state.dialogue_delay){if(!state.selection)return DialogueStatus::unavailable;state.selection->pending=0;state.notice=0;state.target_lock=0;}}
    if(!state.response_delay)return DialogueStatus::unavailable;
    if(*state.response_delay){state.response_delay=decrement(*state.response_delay);if(!*state.response_delay){if(!state.selection)return DialogueStatus::unavailable;state.selection->response_state=0;}}
    if(!state.timing_active)return DialogueStatus::unavailable;
    if(*state.timing_active){if(!state.elapsed)return DialogueStatus::unavailable;state.elapsed=increment(*state.elapsed);}
    if(actor->category==0&&world_.mode!=0&&actor->slot!=world_.selected_actor)return DialogueStatus::completed;
    if(!state.request)return DialogueStatus::unavailable;
    if(!*state.request)return DialogueStatus::completed;
    std::optional<bool> hidden;auto status=suppression(hidden);if(status!=DialogueStatus::completed)return status;
    if(*hidden){state.request=0;state.variant=0;return DialogueStatus::completed;}
    report_.stage=DialogueResponseStage::target;status=update_dialogue_target(world_,id);if(status!=DialogueStatus::completed)return status;
    choices_={};if(!state.selection)return DialogueStatus::unavailable;
    state.selection->pending=0;state.timing_active=1;
    if(!state.elapsed)return DialogueStatus::unavailable;
    state.previous_elapsed=*state.elapsed;state.elapsed=0;
    report_.stage=DialogueResponseStage::priority;bool done{};status=direct(id,frame,done);if(status!=DialogueStatus::completed)return status;
    if(!done){
        if(actor->slot==world_.selected_actor)choices_[3]=selected_use_;
        report_.stage=DialogueResponseStage::response;status=reply(id,frame,done);if(status!=DialogueStatus::completed)return status;
        if(!done){
            Bank* bank{};status=select_bank(*actor,bank);if(status!=DialogueStatus::completed)return status;
            const auto limit=actor->category?6000u:5000u;
            for(std::size_t i=0;i<limit;++i)if(auto entry=row(bank,i);entry&&entry->mutable_row->cue>=0&&entry->definition.group<3){
                report_.selection=i;if(entry->definition.group<0)return DialogueStatus::unsupported_profile;
                if(!choices_[std::uint8_t(entry->definition.group)]){status=evaluate(id,bank,*entry,frame);if(status!=DialogueStatus::completed)return status;}
            }
            report_.stage=DialogueResponseStage::choice;status=choose(id,frame,done);if(status!=DialogueStatus::completed)return status;
        }
    }
    state.request=0;return DialogueStatus::completed;
}
DialogueStatus DialogueResponsesState::publish(const actors::EntityId& id,const DialogueResponseFrame& frame){
    const auto actor=world_.resolve(id);if(!actor||!actor->speech.selection)return DialogueStatus::unavailable;
    auto& state=actor->speech;auto& speech=*state.selection;
    if(!speech.pending)return DialogueStatus::completed;
    if(speech.pending==2)speech.response_state=1;
    //6B8640 is an actual empty function, with no state or service effect.
    report_.stage=DialogueResponseStage::construct;
    const auto constructed=pool_.construct_impl(id,frame.gates,true);if(constructed.record)++report_.constructed;
    if(constructed.status!=DialogueStatus::completed)return constructed.status;
    if(actor->category==0&&actor->slot==world_.selected_actor&&constructed.original_return){
        state.repeat_delay=world_.session().clock_mode?30:60;report_.stage=DialogueResponseStage::publication;
        if(!frame.publication||&frame.publication->world()!=&world_)return DialogueStatus::unavailable;
        if(frame.publication->record_actor_message(id,gameplay_update::ActorMessageSelector::speech)!=gameplay_update::PublicationStatus::completed)return DialogueStatus::unavailable;
        ++report_.published;
    }
    state.notice=1;if(!state.selection)return DialogueStatus::unavailable;state.selection->pending=0;return DialogueStatus::completed;
}
DialogueResponsesUpdated DialogueResponsesState::advance(const DialogueResponseFrame& frame,bool include_durations){
    report_={};
    const auto fail=[&](DialogueStatus status){report_.status=status;return report_;};
    const auto population=[&]()->std::optional<std::uint32_t>{const auto count=world_.session().primary_population;return count&&*count<=World::primary_capacity?count:std::nullopt;};
    report_.stage=DialogueResponseStage::input;
    if(world_.mode!=0){
        const auto selected=world_.identity(world_.selected_actor);report_.actor=selected;bool requested{};
        auto status=input(selected,frame,requested);if(status!=DialogueStatus::completed)return fail(status);
        if(!requested){if(!frame.menu_actions)return fail(DialogueStatus::unavailable);if(*frame.menu_actions&0x100u){const auto actor=world_.resolve(selected);if(!actor)return fail(DialogueStatus::unavailable);actor->speech.request=1;actor->speech.variant=0;}}
    }else{
        const auto count=population();if(!count)return fail(DialogueStatus::unavailable);
        constexpr std::array<std::int16_t,8> remote_variants{4,1,2,3,-1,-1,-1,-1};
        for(std::size_t i=0;i<*count;++i){
            const auto id=world_.identity(i);report_.actor=id;const auto actor=world_.resolve(id);if(!actor)return fail(DialogueStatus::unavailable);
            if(!actor->slot){
                bool requested{};const auto status=input(id,frame,requested,i);if(status!=DialogueStatus::completed)return fail(status);
                if(!requested){if(!frame.menu_actions)return fail(DialogueStatus::unavailable);if(*frame.menu_actions&0x100u){actor->speech.request=1;actor->speech.variant=0;}}
            }else{
                auto& speech=actor->speech;if(!speech.remote_request)return fail(DialogueStatus::unavailable);
                if(*speech.remote_request){
                    speech.request=1;if(*speech.remote_request>remote_variants.size())return fail(DialogueStatus::unsupported_profile);
                    const auto value=std::bit_cast<std::int8_t>(std::uint8_t(remote_variants[*speech.remote_request-1]));speech.variant=value;
                    if(value<0){speech.request=0;speech.variant=0;}
                    speech.remote_request=0;
                }
            }
        }
    }
    report_.stage=DialogueResponseStage::monitor;auto status=monitor(frame);if(status!=DialogueStatus::completed)return fail(status);
    if(world_.mode==0){
        const auto count=population();if(!count)return fail(DialogueStatus::unavailable);
        for(std::size_t i=0;i<*count;++i){const auto id=world_.identity(i);report_.actor=id;report_.stage=DialogueResponseStage::actor_prepare;status=prepare(id,frame);if(status!=DialogueStatus::completed)return fail(status);status=publish(id,frame);if(status!=DialogueStatus::completed)return fail(status);++report_.actors;}
    }else{
        report_.actor=world_.identity(world_.selected_actor);report_.stage=DialogueResponseStage::actor_prepare;status=prepare(report_.actor,frame);if(status!=DialogueStatus::completed)return fail(status);
        const auto count=population();if(!count)return fail(DialogueStatus::unavailable);
        for(std::size_t i=0;i<*count;++i){report_.actor=world_.identity(i);status=publish(report_.actor,frame);if(status!=DialogueStatus::completed)return fail(status);++report_.actors;}
    }
    auto& auxiliary=world_.auxiliary_actors();
    for(auto id=auxiliary.head();id;id=auxiliary.next(id)){report_.actor=id;report_.stage=DialogueResponseStage::actor_prepare;status=prepare(id,frame);if(status!=DialogueStatus::completed)return fail(status);status=publish(id,frame);if(status!=DialogueStatus::completed)return fail(status);++report_.actors;}
    report_.stage=DialogueResponseStage::records;report_.records=pool_.update_impl(frame.gates,true);if(report_.records.status!=DialogueStatus::completed)return fail(report_.records.status);
    report_.stage=DialogueResponseStage::durations;if(include_durations)world_.session().auxiliary_scene.advance_timers();return report_;
}
} // namespace reo::native::gameplay_world
