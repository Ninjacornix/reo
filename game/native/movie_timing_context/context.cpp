#include "context.hpp"
#include <bit>
#include <stdexcept>
#include <utility>
namespace reo::native::movie_timing_context {
namespace {
struct Flag {bool& value;bool before;explicit Flag(bool& flag):value(flag),before(flag){value=true;}~Flag(){value=before;}};
bool selector_profile(std::uint32_t selector)noexcept{return selector==0 || selector==1 || selector==2 || selector==5;}
pause::Updates pause_updates(const Updates& updates)noexcept {
    pause::Updates result;
#define COPY(name) result.name=updates.name
    COPY(actual);COPY(requested);COPY(pause);COPY(depth);COPY(pending);COPY(buffering);COPY(episodes);COPY(rate);
#undef COPY
    return result;
}
}
class Context::Bridge final:public pause::Ports {
    Context& owner_;
public:
    explicit Bridge(Context& owner):owner_(owner){}
    pause::Reply call(pause::Call call,pause::View view)noexcept override{return owner_.command(call,view);}
};
std::shared_ptr<Context> Context::create(Config config){
    auto ports=config.ports;auto owner=std::shared_ptr<Context>(new Context(std::move(config)));owner->finish(std::move(ports));return owner;
}
Context::Context(Config config):facts_(config.facts),frequency_(config.frequency),initial_(initialize::initialize()),guard_(config.guard?std::move(config.guard):std::make_shared<selected::GuardState>()),hooks_(std::move(config.hooks)),buffering_(std::move(config.buffering)){
    if(!config.audio || !config.helper || !config.ports || !selector_profile(facts_.selector) || facts_.rate>=9)throw std::invalid_argument("Prepared owned movie timing profile required");
    audio_=std::make_shared<audio::Clock>(audio::State{},std::move(config.audio),std::move(config.helper));
    selected::Config selected;selected.frequency=frequency_;selected.guard=hooks_;selected.shared_guard=guard_;
    selected.state.counter={facts_.actual,facts_.requested,facts_.pause,facts_.buffering,facts_.property_47,initial_.active_counter,initial_.increment,initial_.elapsed_counter,initial_.elapsed_origin,initial_.external_accumulator};
    selected.state.cached=initial_.cached;selected.state.selector=facts_.selector;selected.state.pending=facts_.pending;selected.state.previous_sample=initial_.previous_external;selected.state.external_denominator=initial_.external_denominator;
    selected_=std::make_unique<selected::Clock>(std::move(selected));
    if(selected_->set_callback(2,audio_)!=selected::Status::completed)throw std::logic_error("Movie audio callback binding failed");
    admission_.count=initial_.hysteresis_count;admission_.tracked=std::bit_cast<float>(initial_.tracked_query_bits);admission_.cached=initial_.cached_decision;admission_.previous=std::bit_cast<float>(initial_.previous_query_bits);
}
void Context::finish(std::shared_ptr<Ports> ports){
    ports_=std::move(ports);pause::Config config;config.ports=std::make_shared<Bridge>(*this);config.hooks=hooks_;config.shared_guard=guard_;config.frequency=frequency_;
    config.state.actual=facts_.actual;config.state.requested=facts_.requested;config.state.pause=facts_.pause;config.state.depth=facts_.depth;config.state.pending=facts_.pending;config.state.buffering=facts_.buffering;config.state.episodes=facts_.episodes;config.state.rate=facts_.rate;
    config.state.active_counter=initial_.active_counter;config.state.elapsed_counter=initial_.elapsed_counter;config.state.external_accumulator=initial_.external_accumulator;config.state.external_denominator=initial_.external_denominator;
    pause_=std::make_unique<pause::Controller>(std::move(config));
}
Status Context::validate(const Updates& updates)const noexcept {
    if(updates.selector && !selector_profile(*updates.selector))return Status::invalid_input;
    if(updates.rate && *updates.rate>=9)return Status::invalid_input;
    return Status::completed;
}
void Context::properties(const Updates& updates)noexcept {
#define APPLY(name) if(updates.name)facts_.name=*updates.name
    APPLY(actual);APPLY(requested);APPLY(pause);APPLY(depth);APPLY(pending);APPLY(buffering);APPLY(episodes);APPLY(rate);
    APPLY(property_e);APPLY(selector);APPLY(property_47);APPLY(tolerance);APPLY(admit_slack);APPLY(requested_slack);
#undef APPLY
}
Status Context::observe(const Updates& updates)noexcept {
    if(busy_)return Status::busy;
    if(detached_)return Status::detached;
    const auto admitted=validate(updates);if(admitted!=Status::completed)return admitted;
    selected::ControlUpdate control;control.actual=updates.actual;control.requested=updates.requested;control.pause=updates.pause;control.buffering_pause=updates.buffering;control.pending=updates.pending;control.selector=updates.selector;control.property_47=updates.property_47;
    if(selected_->update(control)!=selected::Status::completed)return Status::busy;
    if(pause_->update(pause_updates(updates))!=pause::Status::completed)return Status::busy;
    properties(updates);return Status::completed;
}
bool Context::from_pause(const pause::State& state)noexcept {
    selected::ControlUpdate update;update.actual=state.actual;update.requested=state.requested;update.pause=state.pause;update.buffering_pause=state.buffering;update.pending=state.pending;update.active_counter=state.active_counter;update.elapsed_counter=state.elapsed_counter;update.external_accumulator=state.external_accumulator;update.external_denominator=state.external_denominator;
    if(selected_->update(update)!=selected::Status::completed)return false;
    facts_.actual=state.actual;facts_.requested=state.requested;facts_.pause=state.pause;facts_.depth=state.depth;facts_.pending=state.pending;facts_.buffering=state.buffering;facts_.episodes=state.episodes;facts_.rate=state.rate;validated_|=state.validation_seen;return true;
}
bool Context::to_pause()noexcept {
    const auto state=selected_->snapshot().state;const auto& counter=state.counter;pause::Updates update;
    update.actual=counter.actual;update.requested=counter.requested;update.pause=counter.pause;update.buffering=counter.buffering_pause;update.pending=state.pending;update.rate=facts_.rate;
    update.active_counter=counter.active_counter;update.elapsed_counter=counter.elapsed_counter;update.external_accumulator=counter.external_accumulator;update.external_denominator=state.external_denominator;
    return pause_->update(update)==pause::Status::completed;
}
pause::Reply Context::command(pause::Call call,pause::View view)noexcept {
    if(!from_pause(view.state))return{pause::ProviderStatus::failed,0,{}};
    if(buffering_ && (call.kind==pause::Kind::pause_predicate || call.kind==pause::Kind::resume_predicate))return buffer_predicate(call.kind==pause::Kind::resume_predicate);
    const auto provider=ports_;Reply reply;
    if(call.kind==pause::Kind::command){Flag component(in_component_);reply=provider->call(call,snapshot());}
    else reply=provider->call(call,snapshot());
    if(validate(reply.updates)!=Status::completed)return{pause::ProviderStatus::failed,reply.status,{}};
    properties(reply.updates);
    selected::ControlUpdate control;control.selector=reply.updates.selector;control.property_47=reply.updates.property_47;
    if(selected_->update(control)!=selected::Status::completed)return{pause::ProviderStatus::failed,reply.status,{}};
    return{reply.provider,reply.status,pause_updates(reply.updates)};
}
View Context::snapshot()const noexcept {
    View view;view.facts=facts_;view.clock=initial_;view.audio=audio_->snapshot().state;view.audio_health=audio_->snapshot().health;view.guard=*guard_;view.validated=validated_;view.detached=detached_;
    if(buffering_)view.clock.latest=buffering_->latest;
    const auto clock=selected_->snapshot();const auto& state=clock.state;const auto& counter=state.counter;
    view.facts.actual=counter.actual;view.facts.requested=counter.requested;view.facts.pause=counter.pause;view.facts.buffering=counter.buffering_pause;view.facts.pending=state.pending;view.facts.selector=state.selector;view.facts.property_47=counter.property_47;
    view.clock.callbacks=clock.slots;view.clock.cached=state.cached;view.clock.active_counter=counter.active_counter;view.clock.increment=counter.increment;view.clock.elapsed_counter=counter.elapsed_counter;view.clock.elapsed_origin=counter.elapsed_origin;view.clock.external_accumulator=counter.external_accumulator;view.clock.external_denominator=state.external_denominator;view.clock.previous_external=state.previous_sample;
    view.clock.hysteresis_count=admission_.count;view.clock.tracked_query_bits=std::bit_cast<std::uint32_t>(admission_.tracked);view.clock.cached_decision=admission_.cached;view.clock.previous_query_bits=std::bit_cast<std::uint32_t>(admission_.previous);
    if(pause_){const auto pause=pause_->snapshot().view.state;view.facts.depth=pause.depth;view.facts.episodes=pause.episodes;view.validated|=pause.validation_seen;
        if(in_pause_){view.facts.actual=pause.actual;view.facts.requested=pause.requested;view.facts.pause=pause.pause;view.facts.buffering=pause.buffering;view.facts.pending=pause.pending;view.facts.rate=pause.rate;view.clock.active_counter=pause.active_counter;view.clock.elapsed_counter=pause.elapsed_counter;view.clock.external_accumulator=pause.external_accumulator;view.clock.external_denominator=pause.external_denominator;}}
    return view;
}
Result Context::query(Operation operation,Input input)noexcept {
    const auto value=selected_->execute(operation==Operation::selected?selected::Operation::selected:selected::Operation::cached,input.prior,{});
    Result result;result.words=value.words;result.words_written=value.status==selected::Status::completed;result.return_defined=value.query_status_defined;result.returned=value.query_status;
    result.status=value.status==selected::Status::completed?Status::completed:value.status==selected::Status::provider_failure?Status::provider_failure:Status::busy;
    return result;
}
Result Context::due(Words query,bool requested)noexcept {
    const auto queried=selected_->execute(selected::Operation::cached,{},{});
    if(queried.status!=selected::Status::completed)return{queried.status==selected::Status::provider_failure?Status::provider_failure:Status::busy};
    const auto clock=selected_->snapshot().state;const auto& counter=clock.counter;auto state=admission_;
    state.selector=clock.selector;state.tolerance=facts_.tolerance;state.rate=facts_.rate;state.increment=counter.increment;state.auxiliary=counter.elapsed_counter;
    admission::Input input;input.query=query;input.sample=queried.words;input.slack=requested?facts_.requested_slack:facts_.admit_slack;input.frequency=frequency_;
    const auto value=admission::evaluate(state,admission::Operation::core,input);
    if(value.status!=admission::Status::completed)return{Status::numeric_failure};
    selected::ControlUpdate update;update.elapsed_counter=state.auxiliary;
    if(selected_->update(update)!=selected::Status::completed)return{Status::busy};
    admission_=state;Result result;result.status=Status::completed;result.decision=value.decision;result.decision_written=requested;result.return_defined=true;result.returned=requested?0:value.decision;return result;
}
Result Context::error(std::uint32_t code,std::uint32_t detail)noexcept {
    const auto provider=ports_;const auto reply=provider->call({pause::Kind::error,0,code,detail,0},snapshot());
    const auto status=validate(reply.updates);if(status!=Status::completed)return{Status::provider_failure};
    properties(reply.updates);selected::ControlUpdate update;update.actual=reply.updates.actual;update.requested=reply.updates.requested;update.pause=reply.updates.pause;update.buffering_pause=reply.updates.buffering;update.pending=reply.updates.pending;update.selector=reply.updates.selector;update.property_47=reply.updates.property_47;
    if(selected_->update(update)!=selected::Status::completed || pause_->update(pause_updates(reply.updates))!=pause::Status::completed)return{Status::busy};
    Result result;result.status=reply.provider==pause::ProviderStatus::completed?Status::completed:Status::provider_failure;result.returned=reply.status;result.return_defined=reply.provider==pause::ProviderStatus::completed;return result;
}
Result Context::execute(Operation operation,Input input)noexcept {
    const auto retained=weak_from_this().lock();
    if(!retained)return{Status::invalid_input};
    if(detached_)return{Status::detached};
    if(static_cast<unsigned>(operation)>static_cast<unsigned>(Operation::picture_request))return{Status::invalid_input};
    if(busy_){
        if(in_component_ && !nested_query_ && (operation==Operation::selected || operation==Operation::cached)){Flag nested(nested_query_);return query(operation,input);}
        return{Status::busy};
    }
    Flag busy(busy_);
    if(operation==Operation::selected || operation==Operation::cached)return query(operation,input);
    if(operation==Operation::refresh || operation==Operation::tick){
        const auto value=selected_->execute(operation==Operation::refresh?selected::Operation::refresh:selected::Operation::tick,{},{});
        return{value.status==selected::Status::completed?Status::completed:value.status==selected::Status::provider_failure?Status::provider_failure:Status::busy};
    }
    if(operation==Operation::pause || operation==Operation::buffer){
        if(!to_pause())return{Status::busy};
        Flag pausing(in_pause_);const auto value=pause_->execute(operation==Operation::pause?pause::Operation::pause:pause::Operation::buffer,input.value);
        if(!from_pause(pause_->snapshot().view.state))return{Status::busy};
        Result result;result.status=value.status==pause::Status::completed?Status::completed:value.status==pause::Status::provider_failure?Status::provider_failure:Status::invalid_input;result.returned=value.returned;result.return_defined=value.return_defined;return result;
    }
    if(operation==Operation::admit){
        if(facts_.property_e){Result result;result.status=Status::completed;result.decision=result.returned=1;result.return_defined=true;return result;}
        return due(input.query,false);
    }
    if(operation==Operation::requested_admit){
        validated_=true;
        if(selected_->snapshot().state.counter.actual==0){auto result=error(0xFF000126u,3);result.decision_written=true;return result;}
        if(!facts_.property_e || selected_->snapshot().state.counter.requested!=4){Result result;result.status=Status::completed;result.decision_written=true;result.decision=facts_.property_e?0:1;result.return_defined=true;return result;}
        return due(input.query,true);
    }
    validated_=true;
    if(selected_->snapshot().state.counter.actual==0)return error(0xFF000125u,2);
    ++initial_.picture_sequence;initial_.requested_picture=input.query;selected::ControlUpdate update;update.pending=1;
    if(selected_->update(update)!=selected::Status::completed)return{Status::busy};
    Result result;result.status=Status::completed;result.return_defined=true;return result;
}
Status Context::detach_queries()noexcept {
    if(busy_)return Status::busy;
    if(detached_)return Status::detached;
    if(selected_->set_callback(2,{})!=selected::Status::completed)return Status::busy;
    detached_=true;return Status::completed;
}
}
