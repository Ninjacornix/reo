#include "timecode.hpp"
#include <cstdio>
#include <stdexcept>
namespace n=reo::native::movie_timestamp;
unsigned checks{};
void check(bool v){++checks;if(!v)throw std::runtime_error("Native timestamp invariant");}
int main(){try{
    n::FlowState state;n::FlowInput input;input.picture.rate=4;input.picture.kind=1;input.picture.gop=1;input.changed=1;input.accounting=n::Stamp{22500,100,4096};
    auto result=n::publish(state,input);check(result.admitted && result.value==0 && result.scale==29970 && state.temporal.baseline==22500);
    input.accounting.reset();input.changed=0;input.picture.kind=2;input.picture.reference=3;check(n::publish(state,input).value==3000);
    input.picture.kind=3;input.picture.reference=1;check(n::publish(state,input).value==1000 && state.latest.value==3000);
    input.picture.reference=2;check(n::publish(state,input).value==2000 && state.latest.reference==3);
    input.picture.kind=1;input.picture.reference=0;input.picture.gop=2;input.changed=1;check(n::publish(state,input).value==4000 && state.latest.value==4000);
    const auto before=state.current;input.picture.rate=0;check(!n::publish(state,input).admitted && state.current.value==before.value);input.picture.rate=9;check(!n::publish(state,input).admitted);input.picture.rate=4;input.picture.drop=2;check(!n::publish(state,input).admitted);
    n::FlowState drop;n::FlowInput authored;authored.picture.rate=7;authored.picture.drop=1;authored.picture.hours=1;authored.picture.gop=1;authored.changed=1;
    check(n::publish(drop,authored).value==0 && drop.first.value==215892000 && drop.first.scale==59940);
    n::State temporal;const auto previous=temporal;check(!n::reconcile(temporal,{9,0,0,0,{}}).admitted && temporal.baseline==previous.baseline);
    std::printf("%u timestamp invariants passed\n",checks);return 0;
}catch(const std::exception& e){std::fprintf(stderr,"%s\n",e.what());return 1;}}
