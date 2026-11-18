#include "filter.hpp"
#include <cstdio>
#include <stdexcept>
#include <string>
namespace n=reo::native::movie_audio_filter;
unsigned checks{};
void check(bool value){++checks;if(!value)throw std::runtime_error("Audio filter admission check "+std::to_string(checks));}
int main(){try{
    for(unsigned bad_window:{0u,61u}){
        auto state=n::initialize();state.window=bad_window;state.active=1;state.helper_anchor=0;state.master_anchor=1000;
        auto before=state;n::Pair input{1800,48000};const auto result=n::process(state,input,{0,90000});
        check(result.status==n::Status::invalid_history && !result.observed && state==before && input==n::Pair{1800,48000});
    }
    {
        auto state=n::initialize();state.sample_counter=0xFFFFFFFFu;const auto before=state;n::Pair input{1800,48000};
        check(n::process(state,input,{0,90000}).status==n::Status::invalid_history && state==before && input==n::Pair{1800,48000});
    }
    for(bool quantum:{false,true}){
        auto state=n::initialize();state.active=1;state.window=1;state.helper_anchor=0;state.master_anchor=1000;
        if(quantum)state.quantum={0,1};
        const auto before=state;n::Pair input{2000,48000};
        const auto result=n::process(state,input,{1,quantum?90000u:0u});
        check(result.status==n::Status::division_by_zero && !result.observed && state==before && input==n::Pair{2000,48000});
    }
    {
        auto state=n::initialize();state.enabled=0;state.window=0;state.threshold.denominator=0;const auto before=state;n::Pair input{99,0};
        const auto result=n::process(state,input,{7,0});check(result.status==n::Status::completed && result.output==input && !result.observed && state==before);
        check(n::window(state,61)==n::Status::invalid_history && state==before);
        check(n::window(state,0xFFFFFFFFu)==n::Status::completed && state==before);
    }
    {
        auto state=n::initialize();const auto before=state;
        check(n::process(state,state.previous_output,{0,90000}).status==n::Status::invalid_alias && state==before);
        state.mode=0;const auto seeded=state;check(n::baseline(state,{100,0})==n::Status::division_by_zero && state==seeded);
    }
    std::printf("%u audio-filter admission/transaction checks\n",checks);return 0;
}catch(const std::exception& error){std::fprintf(stderr,"%s\n",error.what());return 1;}}
