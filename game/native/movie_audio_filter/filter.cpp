#include "filter.hpp"
#include <algorithm>
#include <bit>

namespace reo::native::movie_audio_filter {
namespace {
std::int64_t signed_lane(std::uint64_t value) noexcept{return std::bit_cast<std::int64_t>(value);}
std::int32_t signed_word(std::uint32_t value) noexcept{return std::bit_cast<std::int32_t>(value);}
std::uint64_t lane(std::int32_t value) noexcept{return static_cast<std::uint64_t>(static_cast<std::int64_t>(value));}
bool less(std::uint64_t a,std::uint64_t b) noexcept{return signed_lane(a)<signed_lane(b);}
std::uint64_t magnitude(std::uint64_t value) noexcept{return less(value,0)?0-value:value;}
bool valid_window(const State& state) noexcept{return state.window>=1 && state.window<=state.history.size();}
bool valid_push(const State& state) noexcept{return valid_window(state) && signed_word(state.sample_counter)>=0;}
struct Arithmetic {
    Status status{Status::completed};
    std::uint64_t divide(std::uint64_t numerator,std::uint64_t denominator) noexcept {
        if(!denominator){status=Status::division_by_zero;return 0;}
        const bool negative=less(numerator,0)!=less(denominator,0);
        const auto quotient=magnitude(numerator)/magnitude(denominator);
        return negative?0-quotient:quotient;
    }
    std::uint64_t scale(std::uint64_t factor,Pair ratio) noexcept{return divide(factor*ratio.numerator,ratio.denominator);}
    std::uint64_t prediction(const State& state,Pair input,Pair helper) noexcept {
        if(state.helper_anchor==UINT64_MAX)return 0;
        return state.master_anchor+divide(input.denominator*(helper.numerator-state.helper_anchor),helper.denominator);
    }
};
}
State initialize() noexcept{return{};}
void clear_history(State& state) noexcept {state.history.fill(0);state.sample_counter=0;++state.resets;}
void enabled(State& state,std::uint32_t value) noexcept{state.enabled=value;}
void pause(State& state,std::uint32_t value) noexcept{state.pause=value;}
void mode(State& state,std::uint32_t value) noexcept{state.mode=value;}
Status window(State& state,std::uint32_t value) noexcept {
    if(signed_word(value)<=0)return Status::completed;
    if(value>state.history.size())return Status::invalid_history;
    state.window=value;return Status::completed;
}
void ratio(State& state,Ratio kind,Pair value) noexcept {
    switch(kind){case Ratio::quantum:state.quantum=value;break;case Ratio::threshold:state.threshold=value;break;
        case Ratio::first_offset:state.first_offset=value;break;case Ratio::later_offset:state.later_offset=value;break;}
}
Average average(const State& state) noexcept {
    if(!valid_window(state))return{Status::invalid_history,0};
    std::uint32_t sum{};
    for(std::uint32_t n=0;n<state.window;++n)sum+=static_cast<std::uint32_t>(state.history[n]);
    return{Status::completed,static_cast<std::int32_t>(signed_word(sum)/static_cast<std::int32_t>(state.window))};
}
Average push(State& state,std::int32_t value) noexcept {
    if(!valid_push(state))return{Status::invalid_history,0};
    state.history[state.sample_counter%state.window]=value;++state.sample_counter;
    const auto result=average(state);state.average_before=result.value;state.average_after=result.value;return result;
}
Average shift(State& state,std::int32_t correction) noexcept {
    if(!valid_window(state))return{Status::invalid_history,0};
    for(std::uint32_t n=0;n<state.window;++n)state.history[n]=signed_word(static_cast<std::uint32_t>(state.history[n])-static_cast<std::uint32_t>(correction));
    const auto result=average(state);state.average_after=result.value;return result;
}
Status baseline(State& state,Pair position) noexcept {
    if(state.mode)return Status::completed;
    Arithmetic arithmetic;const auto change=arithmetic.divide(state.previous_output.denominator*position.numerator,position.denominator);
    if(arithmetic.status!=Status::completed)return arithmetic.status;
    state.previous_output.numerator+=change;return Status::completed;
}
Result process(State& destination,Pair& input,Pair helper) noexcept {
    for(const Pair* pair:{&destination.previous_input,&destination.previous_helper,&destination.previous_output,&destination.quantum,&destination.threshold,&destination.first_offset,&destination.later_offset})
        if(&input==pair)return{Status::invalid_alias,{},false};
    if(helper.denominator==1 || destination.enabled==0)return{Status::completed,input,false};
    if(!valid_push(destination))return{Status::invalid_history,{},false};
    auto state=destination;auto source=input;Arithmetic arithmetic;
    if(less(source.numerator,state.raw_maximum))source.numerator=state.raw_maximum;
    if(state.pause==1)state.active=0;
    else if(state.active==0){
        if(less(state.raw_maximum,source.numerator)){
            state.active=1;
            const auto offset=arithmetic.scale(source.denominator,state.helper_anchor==UINT64_MAX?state.first_offset:state.later_offset);
            state.helper_anchor=helper.numerator;state.master_anchor=source.numerator+offset;clear_history(state);
        }else if(state.mode==0)state.active=1;
    }
    if(less(state.raw_maximum,source.numerator))state.raw_maximum=source.numerator;
    const auto predicted=arithmetic.prediction(state,source,helper);
    if(state.active==0){
        if(less(state.raw_maximum,predicted)){
            state.master_anchor=state.mode?state.raw_maximum:state.previous_output.numerator;
            state.helper_anchor=helper.numerator;++state.reanchors;
        }
    }else if(state.mode==1){
        const auto threshold=arithmetic.scale(source.denominator,state.threshold);
        const auto error=source.numerator-predicted;
        if(less(threshold,magnitude(error))){
            state.helper_anchor=helper.numerator;state.master_anchor=source.numerator;clear_history(state);++state.excess_resets;
        }else{
            const auto pushed=push(state,signed_word(static_cast<std::uint32_t>(error)));
            const auto mean=lane(pushed.value);const auto quantum=arithmetic.scale(source.denominator,state.quantum);
            if(less(quantum,magnitude(mean))){
                auto factor=arithmetic.divide(mean*2,quantum);
                if(less(quantum,mean)){--factor;state.positive_steps+=static_cast<std::uint32_t>(factor);}
                else{++factor;state.negative_steps-=static_cast<std::uint32_t>(factor);}
                const auto correction=arithmetic.divide(factor*quantum,2);
                state.helper_anchor=helper.numerator;state.master_anchor=predicted+correction;
                (void)shift(state,signed_word(static_cast<std::uint32_t>(correction)));
            }
        }
    }
    Pair output{arithmetic.prediction(state,source,helper),source.denominator};
    if(less(output.numerator,state.previous_output.numerator))output=state.previous_output;
    state.previous_input=source;state.previous_helper=helper;state.previous_output=output;
    const auto error=signed_word(static_cast<std::uint32_t>(source.numerator-output.numerator));
    if(state.active){state.active_max=std::max(state.active_max,error);state.active_min=std::min(state.active_min,error);}
    else{state.inactive_max=std::max(state.inactive_max,error);state.inactive_min=std::min(state.inactive_min,error);}
    if(arithmetic.status!=Status::completed)return{arithmetic.status,{},false};
    destination=state;input=source;return{Status::completed,output,true};
}
}
