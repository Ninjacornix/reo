#include "dialogue_pool.hpp"
#include <bit>
#include <cmath>
#include <exception>
#include <new>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
std::int16_t short_value(std::int32_t value)noexcept{return std::bit_cast<std::int16_t>(std::uint16_t(value));}
std::int8_t byte_value(std::int32_t value)noexcept{return std::bit_cast<std::int8_t>(std::uint8_t(value));}
}
DialoguePool::DialoguePool(World& world,ActorVoiceRequests* voice,DialoguePresentation* presentation):world_(world),voice_(voice),presentation_(presentation){
    if(world_.closed()||world_.busy()||world_.dialogue_pool_owner_)throw std::invalid_argument("Native dialogue owner unavailable, busy or occupied");
    world_.dialogue_pool_owner_=this;
}
DialoguePool::~DialoguePool(){if(running_)std::terminate();if(world_.dialogue_pool_owner_==this)world_.dialogue_pool_owner_=nullptr;}
bool DialoguePool::bound_to(const World& world)const noexcept{return &world==&world_&&!world_.closed();}
std::optional<bool> DialoguePool::gates(const DialogueGates& value)const noexcept{
    if(world_.paused)return false;
    if(!value.blocked)return{};
    if(*value.blocked)return false;
    if(!value.flags)return{};
    return !(*value.flags&4);
}
void DialoguePool::clear_records_unchecked()noexcept{records_={};counts_[0]=0;selected_={};}
DialogueStatus DialoguePool::initialize_owned_state()noexcept{
    if(world_.closed())return DialogueStatus::closed;
    if(running_||world_.busy())return DialogueStatus::busy;
    initialized_=false;banks_.reset();flags_={};previous_secondary_actor_.reset();primary_actor_.reset();selected_sequences_={};clear_records_unchecked();
    const auto population=world_.session().primary_population;if(!population||*population>World::primary_capacity)return DialogueStatus::unavailable;
    for(std::size_t i=0;i<*population;++i){const auto actor=world_.primary(i);if(!actor)return DialogueStatus::unavailable;actor->speech.selection=SpeechSelection{0,0,0,0,0};actor->speech.gauge_notice=0;actor->speech.dialogue_delay=0;}
    initialized_=true;return DialogueStatus::completed;
}
DialogueStatus DialoguePool::clear_records()noexcept{
    if(world_.closed())return DialogueStatus::closed;
    if(running_||world_.busy())return DialogueStatus::busy;
    if(!initialized_)return DialogueStatus::unavailable;
    clear_records_unchecked();return DialogueStatus::completed;
}
DialogueStatus DialoguePool::banks(std::shared_ptr<const DialogueBanks> value)noexcept{
    if(world_.closed())return DialogueStatus::closed;
    if(running_||world_.busy())return DialogueStatus::busy;
    if(!value)return DialogueStatus::unavailable;
    banks_=std::move(value);return DialogueStatus::completed;
}
std::optional<DialogueRecord> DialoguePool::record(std::size_t index)const{return initialized_&&index<records_.size()?std::optional(records_[index]):std::nullopt;}
std::optional<bool> DialoguePool::flag(std::uint16_t value)const noexcept{if(!initialized_||value>=512)return{};return bool(flags_[value/32]&(1u<<(value%32)));}
DialogueConstructed DialoguePool::construct(const actors::EntityId& id,const DialogueGates& inputs)noexcept{
    DialogueConstructed report;const auto fail=[&](DialogueStatus status){report.status=status;return report;};
    if(world_.closed())return fail(DialogueStatus::closed);
    if(running_||world_.busy())return fail(DialogueStatus::busy);
    const auto admitted=gates(inputs);if(!admitted)return fail(DialogueStatus::unavailable);if(!*admitted)return report;
    if(!initialized_)return fail(DialogueStatus::unavailable);
    const auto actor=world_.resolve(id);if(!actor)return fail(DialogueStatus::unavailable);if(!actor->active)return report;
    const auto selected=world_.primary(world_.selected_actor);if(!selected)return fail(DialogueStatus::unavailable);
    const float x=selected->position.x-actor->position.x,y=selected->position.y-actor->position.y,z=selected->position.z-actor->position.z;
    const float xx=x*x,yy=y*y,zz=z*z,sum=xx+yy,total=sum+zz,distance=std::sqrt(total);
    if(!std::isfinite(distance))return fail(DialogueStatus::unsupported_profile);
    if(distance>800.f||(actor->room!=selected->room&&std::fabs(actor->position.y-selected->position.y)>200.f))return report;
    if(!actor->speech.selection)return fail(DialogueStatus::unavailable);
    if(!banks_)return report;
    const auto character=actor->category?8u:unsigned(actor->character);if(character>=banks_->size())return fail(DialogueStatus::unsupported_profile);
    const auto& bank=(*banks_)[character];if(!bank.cues)return report;
    const auto sequence=actor->speech.selection->sequence;if(!sequence||sequence>gameplay_scenario::DialogueCues::selections)return fail(DialogueStatus::unsupported_profile);
    const auto cue=bank.cues->cue(sequence-1);if(!cue)return report;
    running_=world_.updating_=true;struct Reset{DialoguePool& owner;~Reset(){owner.world_.updating_=false;owner.running_=false;}}reset{*this};
    for(std::size_t i=0;i<records_.size();++i)if(!records_[i].active){report.record=i;auto& value=records_[i];value.active=true;value.phase=0;value.age=0;value.channel=0;value.sequence=0;break;}
    if(!report.record)return fail(DialogueStatus::capacity);
    auto& value=records_[*report.record];actor->speech.dialogue_delay=cue->delay;value.delay=cue->delay;value.initial_delay=cue->delay;
    if(!actor->speech.variant)return fail(DialogueStatus::unavailable);
    const auto variant=std::bit_cast<std::uint8_t>(*actor->speech.variant);
    if(variant){value.age=9999;value.display_style=byte_value((variant&0x7f)+(variant&0x80?9:1));}else value.display_style=1;
    if(!bank.texts)return fail(DialogueStatus::unavailable);
    const auto text=bank.texts->text(cue->text);if(!text)return fail(DialogueStatus::unsupported_profile);
    value.text_owner=bank.texts;value.text_index=cue->text;value.sequence=std::uint16_t(sequence);value.channel=0;
    if(actor->category==0&&actor->slot==world_.selected_actor)value.channel=1;
    value.voice=-1;value.actor=id;value.voice=cue->voice;value.literal=0;report.original_return=1;
    if(text->body.size()>=2&&text->body[0]==std::byte{0x81}&&text->body[1]==std::byte{0x69}){value.literal=1;report.original_return=0;}
    value.prefix={std::byte{'<'},std::byte{'c'},std::byte(actor->class_marker?0x3c:0x3b),std::byte{'>'}};
    if(actor->category==0&&actor->slot==world_.selected_actor)value.prefix[2]=std::byte(actor->class_marker?0x3a:0x39);
    for(const auto effect:text->effects){if(effect==0xffff)break;const auto flag=effect&0x7fffu;if(flag>=512)return fail(DialogueStatus::unsupported_profile);
        const auto mask=1u<<(flag%32);if(effect&0x8000)flags_[flag/32]|=mask;else flags_[flag/32]&=~mask;++report.effects;}
    return report;
}
void DialoguePool::select(std::size_t index)noexcept{
    const auto channel=unsigned(records_[index].channel);if(*counts_[channel]>=16)return;
    auto at=std::size_t((*counts_[channel])++);selected_[channel][at]=index;
    while(at){const auto previous=*selected_[channel][at-1];if(records_[previous].age>=records_[index].age)break;selected_[channel][at-1]=index;selected_[channel][at]=previous;--at;}
}
DialoguePoolUpdated DialoguePool::update(const DialogueGates& inputs)noexcept{
    DialoguePoolUpdated report;
    if(world_.closed()){report.status=DialogueStatus::closed;return report;}
    if(running_||world_.busy()){report.status=DialogueStatus::busy;return report;}
    const auto admitted=gates(inputs);if(!admitted){report.status=DialogueStatus::unavailable;return report;}if(!*admitted)return report;
    if(!initialized_){report.status=DialogueStatus::unavailable;return report;}
    running_=world_.updating_=true;struct Reset{DialoguePool& owner;~Reset(){owner.world_.updating_=false;owner.running_=false;}}reset{*this};counts_={std::int16_t(0),std::int16_t(0)};selected_={};
    for(std::size_t i=0;i<records_.size();++i)if(records_[i].active){auto& value=records_[i];++report.visited;value.age=short_value(value.age+1);if(value.channel<0||value.channel>=2){report.status=DialogueStatus::unsupported_profile;report.failed=i;return report;}select(i);++report.selected;}
    for(auto& channel:selected_)for(std::size_t i=1;i<channel.size();++i)if(channel[i]){records_[*channel[i]].active=false;channel[i].reset();++report.discarded;}
    primary_actor_.reset();selected_sequences_[0]=0;
    for(unsigned channel=0;channel<2;++channel){if(channel==1){previous_secondary_actor_.reset();selected_sequences_[1]=0;}
        if(!selected_[channel][0])continue;
        const auto index=*selected_[channel][0];auto& value=records_[index];
        DialogueContext context{world_,voice_,presentation_,previous_secondary_actor_,{*counts_[0],*counts_[1]},{bool(selected_[0][1]&&records_[*selected_[0][1]].active),bool(selected_[1][1]&&records_[*selected_[1][1]].active)}};
        const auto step=advance_dialogue_record(value,std::uint8_t(channel),context);if(step.status!=DialogueStatus::completed){report.status=step.status;report.stage=step.stage;report.failed=index;return report;}
        selected_sequences_[channel]=value.sequence;if(channel==0)primary_actor_=value.actor;else previous_secondary_actor_=value.actor;++report.updated;
    }
    report.stage=DialogueStage::completed;return report;
}
} // namespace reo::native::gameplay_world
