#include "admission.hpp"
#include <bit>
#include <cfenv>
#include <immintrin.h>
#include <limits>
namespace reo::native::movie_admission {
namespace {
std::int32_t signed_word(std::uint32_t word)noexcept{return std::bit_cast<std::int32_t>(word);}
float signed_float(std::uint32_t word)noexcept{return static_cast<float>(signed_word(word));}
float divide(float numerator,float denominator)noexcept{
    if(denominator==0.0f){
        const auto sign=(std::bit_cast<std::uint32_t>(numerator)^std::bit_cast<std::uint32_t>(denominator))&0x80000000u;
        return std::bit_cast<float>(0x7F7FFFFFu|sign);
    }
    return numerator/denominator;
}
struct Environment {
    std::fenv_t environment{};std::uint32_t csr{_mm_getcsr()};bool valid{std::fegetenv(&environment)==0};
    ~Environment(){if(valid){(void)std::fesetenv(&environment);_mm_setcsr(csr);}}
};
std::uint32_t fallback(State& state,const Input& input)noexcept {
    if(signed_word(state.auxiliary)<0){state.auxiliary=0;return 1;}
    const auto query_product=std::int64_t{signed_word(input.query.numerator)}*signed_word(input.frequency);
    const auto current_product=std::int64_t{signed_word(state.auxiliary)}*signed_word(input.query.denominator);
    return query_product<=current_product?1u:0u;
}
std::uint32_t hysteresis(State& state,float query,float current,std::uint32_t frequency)noexcept {
    const float tolerance=signed_float(state.tolerance);
    const float upper=current+tolerance;
    if(upper<query)return 0;
    const float lower=current-tolerance;
    if(query<=lower){
        if(state.previous!=query && state.tracked!=query){state.tracked=query;++state.count;}
        return 1;
    }
    const std::int32_t threshold=frequency==59940 && signed_word(state.rate)<3 && state.increment==1000?1:0;
    std::uint32_t result=state.cached;
    if(threshold<signed_word(state.count))result=current<query?0u:1u;
    state.count=0;state.previous=query;state.cached=result;return result;
}
}
bool supported_fp_environment()noexcept {
    static_assert(sizeof(float)==4 && std::numeric_limits<float>::is_iec559);
    return std::fegetround()==FE_TONEAREST && (_mm_getcsr()&~0x3Fu)==0x1F80u;
}
Result evaluate(State& destination,Operation operation,const Input& input)noexcept {
    if(static_cast<unsigned>(operation)>static_cast<unsigned>(Operation::hysteresis))return{Status::invalid_input,0};
    if(operation==Operation::fallback)return{Status::completed,fallback(destination,input)};
    if(operation==Operation::core && input.sample.denominator==1){
        if(input.sample.numerator==0xFFFFFFFEu)return{Status::completed,1};
        return{Status::completed,fallback(destination,input)};
    }
    if(operation==Operation::core && input.frequency==0)return{Status::zero_frequency,0};
    if(!supported_fp_environment())return{Status::unsupported_fp,0};
    Environment environment;if(!environment.valid)return{Status::unsupported_fp,0};
    auto state=destination;float query=input.query_time,current=input.current_time;
    if(operation==Operation::core){
        const auto product=input.sample.denominator*input.slack;
        const auto shift=std::int64_t{signed_word(product)}/signed_word(input.frequency);
        const auto shifted=input.sample.numerator+static_cast<std::uint32_t>(shift);
        const float query_scaled=signed_float(input.query.numerator)*10000.0f;
        query=divide(query_scaled,signed_float(input.query.denominator));
        const float current_scaled=signed_float(shifted)*10000.0f;
        current=divide(current_scaled,signed_float(input.sample.denominator));
        if(state.selector==1)return{Status::completed,query<=current?1u:0u};
    }
    const auto result=hysteresis(state,query,current,input.frequency);destination=state;return{Status::completed,result};
}
}
