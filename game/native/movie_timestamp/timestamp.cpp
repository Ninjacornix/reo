#include "timestamp.hpp"
#include <bit>
namespace reo::native::movie_timestamp {
namespace {
std::int32_t s(std::uint32_t value)noexcept{return std::bit_cast<std::int32_t>(value);}
std::uint32_t positive(std::uint32_t value)noexcept{return s(value)<0?0:value;}
std::uint32_t convert(std::uint32_t count,std::uint32_t rate)noexcept{return static_cast<std::uint32_t>((std::int64_t{s(count)}*22500000)/rate);}
}
Result reconcile(State& state,const Input& input)noexcept {
    constexpr std::array<std::uint32_t,9> rates{1,23976,24000,25000,29970,30000,50000,59940,60000};
    if(input.rate>=rates.size())return{};
    const auto rate=rates[input.rate];
    if(s(state.baseline)<0)state.baseline=positive(input.stamp.value-convert(input.reference,rate));
    auto result=positive(input.stamp.value-state.baseline);
    if(state.cached.value!=input.stamp.value){
        state.cached=input.stamp;state.origin=input.reference;state.base=0;state.maximum=input.kind==3?1:0;
    }else{
        if(input.changed){state.base+=state.maximum+1;state.origin=0;state.maximum=0;}
        const auto delta=input.reference-state.origin;
        if(s(delta)>=s(state.maximum))state.maximum=delta;
        result=positive(result+convert(state.base+delta,rate));
    }
    return{result,true};
}
}
