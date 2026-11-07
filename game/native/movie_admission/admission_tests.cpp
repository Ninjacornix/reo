#include "admission.hpp"
#include <bit>
#include <cfenv>
#include <cstdio>
#include <immintrin.h>
#include <stdexcept>
#include <string>
namespace n=reo::native::movie_admission;
unsigned checks{};
void check(bool value){++checks;if(!value)throw std::runtime_error("Picture admission boundary check "+std::to_string(checks));}
struct Environment {
    std::fenv_t environment{};unsigned csr{_mm_getcsr()};
    Environment(){if(std::fegetenv(&environment))throw std::runtime_error("Cannot save test FP environment");}
    ~Environment(){(void)std::fesetenv(&environment);_mm_setcsr(csr);}
};
int main(){try{
    Environment restore;
    n::State state;state.count=2;state.cached=7;n::Input input;input.sample={1600,48000};input.query={1600,48000};input.frequency=48000;
    const auto unchanged=[&]{return state.count==2 && state.cached==7 && std::bit_cast<std::uint32_t>(state.previous)==0xBF800000u && state.auxiliary==0xFFFFFFFFu;};
    check(n::evaluate(state,static_cast<n::Operation>(999),input).status==n::Status::invalid_input && unchanged());
    input.frequency=0;check(n::evaluate(state,n::Operation::core,input).status==n::Status::zero_frequency && unchanged());input.frequency=48000;
    check(std::fesetround(FE_DOWNWARD)==0);
    check(n::evaluate(state,n::Operation::core,input).status==n::Status::unsupported_fp && unchanged());
    input.sample={0xFFFFFFFEu,1};input.frequency=0;
    check(n::evaluate(state,n::Operation::core,input).status==n::Status::completed && unchanged());
    input.sample={0,1};const auto integer=n::evaluate(state,n::Operation::core,input);
    check(integer.status==n::Status::completed && integer.decision==1 && state.auxiliary==0);
    check(std::fesetround(FE_TONEAREST)==0);input.sample={1600,48000};input.frequency=48000;
    const auto ordinary=_mm_getcsr();_mm_setcsr(ordinary|0x8000u);
    check(n::evaluate(state,n::Operation::core,input).status==n::Status::unsupported_fp && _mm_getcsr()==(ordinary|0x8000u));_mm_setcsr(ordinary);
    _mm_setcsr(ordinary|0x40u);
    check(n::evaluate(state,n::Operation::hysteresis,input).status==n::Status::unsupported_fp && _mm_getcsr()==(ordinary|0x40u));_mm_setcsr(ordinary);
    (void)std::feclearexcept(FE_ALL_EXCEPT);_mm_setcsr((_mm_getcsr()&~0x3Fu)|4u);
    const auto flags=_mm_getcsr();const auto round=std::fegetround();input.query_time=std::bit_cast<float>(0x7FA12345u);input.current_time=1000;
    check(n::evaluate(state,n::Operation::hysteresis,input).status==n::Status::completed);
    check(_mm_getcsr()==flags && std::fegetround()==round);
    std::printf("%u admission numeric/refusal/host-FP-preservation checks\n",checks);return 0;
}catch(const std::exception& error){std::fprintf(stderr,"%s\n",error.what());return 1;}}
