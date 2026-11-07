#include "clock.hpp"
#include <stdexcept>
#include <utility>

namespace reo::native::movie_selected_clock {
Clock::Clock(Config config):config_(std::move(config)),guard_state_(config_.shared_guard?config_.shared_guard:std::make_shared<GuardState>(GuardState{config_.guard_depth,config_.guard_tag})){
    if(config_.state.selector>=kinds_.size())throw std::invalid_argument("Bounded movie callback selector");
}
Status Clock::set_callback(std::uint32_t slot,std::shared_ptr<Query> query) noexcept {
    if(slot>=callbacks_.size())return Status::invalid_input;
    callbacks_[slot]=std::move(query);kinds_[slot]=callbacks_[slot]?Kind::registered:Kind::empty;return Status::completed;
}
Status Clock::set_external(std::shared_ptr<Query> query) noexcept {external_=std::move(query);return Status::completed;}
Status Clock::update(const ControlUpdate& update) noexcept {
    if(busy_)return Status::busy;
    if(update.selector && *update.selector>=kinds_.size())return Status::invalid_input;
#define UPDATE_COUNTER(name) if(update.name)config_.state.counter.name=*update.name
    UPDATE_COUNTER(actual);UPDATE_COUNTER(requested);UPDATE_COUNTER(pause);UPDATE_COUNTER(buffering_pause);UPDATE_COUNTER(property_47);
    UPDATE_COUNTER(active_counter);UPDATE_COUNTER(increment);UPDATE_COUNTER(elapsed_counter);UPDATE_COUNTER(elapsed_origin);UPDATE_COUNTER(external_accumulator);
#undef UPDATE_COUNTER
    if(update.pending)config_.state.pending=*update.pending;
    if(update.selector)config_.state.selector=*update.selector;
    if(update.external_denominator)config_.state.external_denominator=*update.external_denominator;
    return Status::completed;
}
Snapshot Clock::snapshot() const noexcept{return{config_.state,kinds_,guard_state_->depth,guard_state_->tag,bool(external_)};}
void Clock::emit(Event event,Words words) noexcept{if(config_.probe)config_.probe->event(event,snapshot(),words);}
void Clock::enter() noexcept {
    emit(Event::phase_enter);
    if(config_.guard){emit(Event::hook_enter);config_.guard->enter(config_.enter_parameter);
        if(guard_state_->depth==0)guard_state_->tag=1;
        ++guard_state_->depth;}
}
void Clock::leave() noexcept {
    emit(Event::phase_leave);
    if(config_.guard){--guard_state_->depth;
        if(guard_state_->depth==0)guard_state_->tag=0;
        emit(Event::hook_leave);config_.guard->leave(config_.leave_parameter);}
}
void Clock::facts(const FactsUpdate& update) noexcept {
    auto& state=config_.state.counter;
    if(update.actual)state.actual=*update.actual;
    if(update.pause)state.pause=*update.pause;
    if(update.buffering_pause)state.buffering_pause=*update.buffering_pause;
    if(update.property_47)state.property_47=*update.property_47;
}
std::uint32_t Clock::callback(const std::shared_ptr<Query>& query,Words& words) noexcept {
    emit(Event::query,words);const auto reply=query->query(config_.state,words);
    if(reply.admitted && reply.numerator)words.numerator=reply.words.numerator;
    if(reply.admitted && reply.denominator)words.denominator=reply.words.denominator;
    facts(reply.facts);
    if(reply.remove_selected_slot)(void)set_callback(config_.state.selector,{});
    provider_failed_|=!reply.admitted;
    return reply.status;
}
std::uint32_t Clock::builtin(counter::Operation op,Words& words) noexcept{return counter::execute(config_.state.counter,op,words,config_.frequency).status;}
std::uint32_t Clock::external(Words& words,Words scratch) noexcept {
    if(!builtin(counter::Operation::admit,words))return 0;
    const auto provider=external_;
    if(!provider){words={0xFFFFFFFEu,1};return 0;}
    const auto status=callback(provider,scratch);auto& state=config_.state;
    if(provider_failed_)return status;
    Words unused;
    if(counter::execute(state.counter,counter::Operation::active_gate,unused,config_.frequency).status && state.previous_sample!=0xFFFFFFFBu)
        state.counter.external_accumulator+=scratch.numerator-state.previous_sample;
    state.previous_sample=scratch.numerator;state.external_denominator=scratch.denominator;
    words={state.counter.external_accumulator,state.external_denominator};return status;
}
std::uint32_t Clock::selected(Words& words,Words external_scratch) noexcept {
    enter();const auto slot=config_.state.selector;const auto kind=kinds_[slot];const auto query=callbacks_[slot];std::uint32_t status{};
    if(kind==Kind::registered)status=callback(query,words);
    else if(kind==Kind::counter)status=builtin(counter::Operation::counter,words);
    else if(kind==Kind::contextual)status=builtin(counter::Operation::contextual,words);
    else if(kind==Kind::external)status=external(words,external_scratch);
    else status=builtin(counter::Operation::unavailable,words);
    leave();return status;
}
void Clock::refresh(Scratch scratch) noexcept {
    auto words=scratch.refresh;(void)selected(words,scratch.external);auto& state=config_.state;
    if(provider_failed_)return;
    if(words.numerator!=state.cached.numerator || words.denominator!=state.cached.denominator){
        Words unused;(void)counter::execute(state.counter,counter::Operation::rebase,unused,config_.frequency);
        state.cached.numerator=words.numerator;state.cached.denominator=words.denominator;
    }
    state.pending=1;
}
Result Clock::execute(Operation op,Words prior,Scratch scratch) noexcept {
    if(busy_)return{Status::busy,prior,0,false};
    if(static_cast<unsigned>(op)>static_cast<unsigned>(Operation::tick))return{Status::invalid_input,prior,0,false};
    busy_=true;provider_failed_=false;struct Exit{bool& value;~Exit(){value=false;}}exit{busy_};
    Result result{Status::completed,prior,0,op!=Operation::refresh && op!=Operation::tick};
    if(op==Operation::selected)result.query_status=selected(result.words,scratch.external);
    else if(op==Operation::cached){
        if(config_.state.cached.numerator!=0xFFFFFFFBu)result.words=config_.state.cached;
        else result.query_status=selected(result.words,scratch.external);
    }else if(op==Operation::external)result.query_status=external(result.words,scratch.external);
    else if(op==Operation::refresh)refresh(scratch);
    else{
        Words unused;(void)counter::execute(config_.state.counter,counter::Operation::tick,unused,config_.frequency);
        if(config_.state.counter.property_47==1)refresh(scratch);
    }
    if(provider_failed_){result.status=Status::provider_failure;result.query_status_defined=false;}
    return result;
}
}
