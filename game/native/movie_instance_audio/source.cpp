#include "source.hpp"
#include <bit>
#include <utility>

namespace reo::native::movie_instance_audio {
namespace {
using P=audio::ProviderStatus;
template<class F>struct Borrow final:owner::Operation {
    F work;explicit Borrow(F value):work(std::move(value)){}
    void run(instances::Instances& value)noexcept override{work(value);}
};
P admission(owner::Admission value,P result)noexcept {
    return value==owner::Admission::accepted?result:value==owner::Admission::closed?P::closed:P::busy;
}
P mapped(instances::control::Status value)noexcept {
    using S=instances::control::Status;
    switch(value){
    case S::completed:return P::completed;
    case S::busy:case S::pending:return P::busy;
    case S::closed:return P::closed;
    case S::invalid_key:return P::invalid_key;
    default:return P::fault;
    }
}
P mapped(instances::Status value)noexcept {
    using S=instances::Status;
    switch(value){
    case S::completed:return P::completed;
    case S::busy:case S::pending:return P::busy;
    case S::closed:return P::closed;
    case S::invalid_key:return P::invalid_key;
    default:return P::fault;
    }
}
}
Source::Source(std::shared_ptr<owner::Owner> value,instances::SourceKey key,std::shared_ptr<audio::ServiceTick> tick)
    :owner_(std::move(value)),key_(std::move(key)),tick_(std::move(tick)){}
Capture Source::capture(std::shared_ptr<owner::Owner> value,const instances::Key& key,
                        std::shared_ptr<audio::ServiceTick> tick)noexcept {
    if(!value || !tick)return{};
    instances::SourceCapture captured;
    Borrow borrow([&](auto& players){captured=players.capture_source(key);});
    const auto accepted=value->run(borrow);
    const auto result=admission(accepted,mapped(captured.status));
    if(result!=P::completed)return{result,{}};
    try{
        auto source=std::shared_ptr<Source>(new Source(std::move(value),std::move(captured.key),std::move(tick)));
        return{P::completed,std::move(source)};
    }
    catch(...){return{P::fault,{}};}
}
audio::ProviderStatus Source::execute(Operation operation,std::uint32_t argument,audio::Words* words,
                                     std::uint32_t* scalar,std::uint8_t* phase)noexcept {
    const auto keep=weak_from_this().lock();if(!keep)return P::closed;
    if(busy_.test_and_set(std::memory_order_acquire))return P::busy;
    struct Exit {std::atomic_flag& flag;~Exit(){flag.clear(std::memory_order_release);}} exit{busy_};
    instances::control::Observation observed;
    Borrow inspect([&](auto& players){observed=players.inspect_source(key_);});
    const auto inspected=owner_->run(inspect);
    auto result=admission(inspected,mapped(observed.status));
    if(result!=P::completed)return result;
    const auto state=observed.evidence.clock_observation.state;
    if(operation==Operation::status){*phase=state;return P::completed;}
    if(operation==Operation::frequency){*scalar=std::bit_cast<std::int8_t>(state)<2?0:observed.evidence.clock_observation.frequency;return P::completed;}
    // The tick owner retains its own native state. No guest RAM alias, guest
    // callback, blocking I/O or owner join is permitted in this provider.
    // Sampling occurs outside canonical admission; source identity is checked
    // again by each source-specific operation before any control/query effect.
    std::uint32_t tick{};result=tick_->read(tick);if(result!=P::completed)return result;
    instances::control::ClockResult estimate;
    instances::control::ClockControl control;
    Borrow apply([&](auto& players){
        if(operation==Operation::estimate)estimate=players.estimate_source(key_,tick);
        else if(operation==Operation::pause)control=players.pause_source(key_,std::bit_cast<std::int32_t>(argument),tick);
        else control=players.discard_source(key_,tick);
    });
    const auto accepted=owner_->run(apply);
    result=admission(accepted,mapped(operation==Operation::estimate?estimate.status:control.status));
    if(result!=P::completed)return result;
    if(operation==Operation::estimate){
        if(estimate.value.result.status!=adxt_estimated_clock::Status::completed)return P::fault;
        *words={estimate.value.result.ratio.numerator,estimate.value.result.ratio.denominator};
    }else{
        if(control.value.result!=adxt_estimated_clock::Status::completed)return P::fault;
        if(operation==Operation::discard)*scalar=0; // Original result; argument is not a seek.
    }
    return P::completed;
}
audio::ProviderStatus Source::status(std::uint8_t& value)noexcept{return execute(Operation::status,0,nullptr,nullptr,&value);}
audio::ProviderStatus Source::estimate(audio::Words& value)noexcept{return execute(Operation::estimate,0,&value,nullptr,nullptr);}
audio::ProviderStatus Source::sample_frequency(std::uint32_t& value)noexcept{return execute(Operation::frequency,0,nullptr,&value,nullptr);}
audio::ProviderStatus Source::pause(std::uint32_t value)noexcept{return execute(Operation::pause,value,nullptr,nullptr,nullptr);}
audio::ProviderStatus Source::discard(std::uint32_t argument,std::uint32_t& value)noexcept{return execute(Operation::discard,argument,nullptr,&value,nullptr);}
}
