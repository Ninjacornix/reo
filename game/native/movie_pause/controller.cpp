#include "controller.hpp"
#include <array>
#include <bit>
#include <stdexcept>
#include <utility>
namespace reo::native::movie_pause {
namespace {
constexpr std::array<std::uint32_t,9> rates{0,23976,24000,25000,29970,30000,50000,59940,60000};
std::uint32_t scale(std::uint32_t frequency,std::uint32_t numerator,std::uint32_t denominator)noexcept{
    const auto product=std::int64_t{std::bit_cast<std::int32_t>(frequency)}*std::bit_cast<std::int32_t>(numerator);
    return static_cast<std::uint32_t>(product/std::bit_cast<std::int32_t>(denominator));
}
bool requested(const State& state)noexcept{return state.requested==3 || state.requested==4;}
}
Controller::Controller(Config config):config_(std::move(config)){
    if(!config_.ports)throw std::invalid_argument("Owned movie control ports required");
}
void Controller::apply(const Updates& updates)noexcept {
#define APPLY(name) if(updates.name)config_.state.name=*updates.name
    APPLY(actual);APPLY(requested);APPLY(pause);APPLY(depth);APPLY(pending);APPLY(buffering);APPLY(episodes);APPLY(rate);
    APPLY(active_counter);APPLY(elapsed_counter);APPLY(external_accumulator);APPLY(external_denominator);
#undef APPLY
}
Status Controller::update(const Updates& updates)noexcept {
    if(busy_)return Status::busy;
    apply(updates);return Status::completed;
}
std::uint32_t Controller::invoke(Call call)noexcept {
    const auto provider=config_.ports;const auto reply=provider->call(call,{config_.state,guard()});
    apply(reply.updates);if(reply.provider!=ProviderStatus::completed)status_=Status::provider_failure;return reply.status;
}
void Controller::enter()noexcept {
    if(config_.hooks){config_.hooks->enter(config_.enter_parameter);if(!guard().depth)guard().tag=1;++guard().depth;}
}
void Controller::leave()noexcept {
    if(config_.hooks){--guard().depth;if(!guard().depth)guard().tag=0;config_.hooks->leave(config_.leave_parameter);}
}
void Controller::step(std::uint32_t mode)noexcept {
    if(mode!=2)return;
    auto& state=config_.state;
    const auto numerator=state.rate?1000u:0u;const auto denominator=state.rate?rates[state.rate]:29970u;
    const auto running=scale(config_.frequency,numerator,denominator);
    state.active_counter+=running;state.elapsed_counter+=running;
    state.external_accumulator+=scale(state.external_denominator,numerator,denominator);
}
std::uint32_t Controller::forward(std::uint32_t mode)noexcept {
    if(!requested(config_.state))return 0;
    step(mode);return invoke({Kind::command,7,8,mode,0});
}
std::uint32_t Controller::nested(std::uint32_t mode)noexcept {
    auto& state=config_.state;
    if(mode==1){++state.depth;if(state.depth==1)return forward(1);}
    else if(mode==0){--state.depth;if(state.depth==0)return forward(0);}
    else if(mode==2 && state.actual==4)return forward(2);
    return 0;
}
std::uint32_t Controller::pause(std::uint32_t value)noexcept {
    auto& state=config_.state;state.validation_seen=true;
    if(state.actual==0)return invoke({Kind::error,0,0xFF000142u,1,0});
    const auto mode=value?(state.pause?2u:1u):0u;
    if(!value && !state.pause)return 0;
    state.pause=value;const auto result=nested(mode);state.pending=1;return result;
}
std::uint32_t Controller::buffer()noexcept {
    enter();std::uint32_t result{};
    auto& state=config_.state;
    if(state.buffering==0){
        const auto decision=invoke({Kind::pause_predicate,0,0,0,0});
        if(status_==Status::completed && decision){state.buffering=1;++state.episodes;result=nested(1);}
    }else{
        const auto decision=invoke({Kind::resume_predicate,0,0,0,0});
        if(status_==Status::completed && decision){state.buffering=0;result=nested(0);}
    }
    leave();return result;
}
bool Controller::needs_step(Operation operation,std::uint32_t argument)const noexcept {
    const auto& state=config_.state;
    if(operation==Operation::step)return argument==2;
    if(operation==Operation::forward)return argument==2 && requested(state);
    if(operation==Operation::nested)return argument==2 && state.actual==4 && requested(state);
    return operation==Operation::pause && argument!=0 && state.pause!=0 && state.actual==4 && requested(state);
}
Result Controller::execute(Operation operation,std::uint32_t argument)noexcept {
    if(busy_)return{Status::busy,0,false};
    if(static_cast<unsigned>(operation)>static_cast<unsigned>(Operation::step))return{Status::invalid_input,0,false};
    if(needs_step(operation,argument) && config_.state.rate>=rates.size())return{Status::invalid_rate,0,false};
    busy_=true;struct Exit{bool& busy;~Exit(){busy=false;}}exit{busy_};status_=Status::completed;
    std::uint32_t result{};
    if(operation==Operation::pause)result=pause(argument);
    else if(operation==Operation::nested)result=nested(argument);
    else if(operation==Operation::forward)result=forward(argument);
    else if(operation==Operation::buffer)result=buffer();
    else step(argument);
    return{status_,result,status_==Status::completed && operation!=Operation::step};
}
}
