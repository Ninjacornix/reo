#include "clock.hpp"
#include <cstdio>
namespace n=reo::native::movie_counter_clock;
int main(){
    n::State state{4,4,0,0,1,0xFFFFFFFFu,1,0x7FFFFFFFu,9,77};n::Words words{7,13};
    auto effects=n::execute(state,n::Operation::tick,words,48000);
    if(state.active_counter!=0 || state.elapsed_counter!=0x80000000u || effects.count!=2 || effects.status_defined)return 1;
    state.pause=2;effects=n::execute(state,n::Operation::tick,words,48000);
    if(state.active_counter!=0 || state.elapsed_counter!=0x80000001u || effects.count!=1 || effects.writes[0]!=n::Field::elapsed_counter)return 2;
    effects=n::execute(state,n::Operation::contextual,words,0);
    if(words.numerator!=7 || words.denominator!=13 || effects.count || effects.status || !effects.status_defined)return 3;
    effects=n::execute(state,n::Operation::counter,words,0);
    if(words.numerator!=0 || words.denominator!=0 || effects.count!=2)return 4;
    state.actual=0;effects=n::execute(state,n::Operation::contextual,words,48000);
    if(words.numerator!=0xFFFFFFFFu || words.denominator!=1 || effects.count!=2)return 5;
    state.property_47=2;effects=n::execute(state,n::Operation::rebase,words,48000);
    if(state.elapsed_origin!=77 || effects.count!=1 || effects.status_defined)return 6;
    effects=n::execute(state,static_cast<n::Operation>(99),words,48000);
    if(effects.valid_operation || effects.count || effects.status_defined || state.elapsed_origin!=77)return 7;
    std::puts("7 native movie counter/query boundary checks");return 0;
}
