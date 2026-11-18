#include "service.hpp"
#include <bit>

namespace reo::native::movie_service {
namespace {
std::int32_t signed_word(std::uint32_t value)noexcept{return std::bit_cast<std::int32_t>(value);}
void prepare(State& state,Ports& ports)noexcept {
    auto& p=state.properties;
    if(p[5]==1 && static_cast<std::uint32_t>(ports.call(Action::extent,1,state))==0 && static_cast<std::uint32_t>(ports.call(Action::requested_count,1,state))==0)p[5]=0;
    if(p[6]==1 && static_cast<std::uint32_t>(ports.call(Action::extent,2,state))==0 && static_cast<std::uint32_t>(ports.call(Action::requested_count,2,state))==0)p[6]=0;
    if(signed_word(state.shared[0])<0)state.shared[0]=p[5];
    if(signed_word(state.shared[1])<0)state.shared[1]=p[6];
    if(p[6]==0 && p[15]==2)p[15]=1;
    if(p[5]==0 && p[15]==1)p[15]=2;
    const auto mask=(p[6]==1?1u:0u)+(p[5]==1?2u:0u);
    if(mask!=3)p[25]=mask==1?1:mask==2?2:3;
}
bool ready(const State& state)noexcept {
    return (!state.properties[5] || (state.cached[0]|state.cached[1])) && (!state.properties[6] || (state.cached[2]|state.cached[3]));
}
bool start_allowed(const State& state)noexcept {
    const auto& p=state.properties;
    if(p[14] && p[5] && !state.buffered && signed_word(state.threshold)<signed_word(p[45]))return completion(state)!=0;
    return true;
}
std::uint32_t transition(State& state,Ports& ports)noexcept {
    const auto initial=state.actual;
    const auto request=state.requested;
    switch(initial){
    case 1:return (request>=2 && request<=4) || request==6?2:initial;
    case 2:
        if(!ready(state))return initial;
        prepare(state,ports);
        if(request==2 || request==3)return request;
        if(request==4 || request==6){
            if(!start_allowed(state))return 3;
            (void)ports.call(Action::start,0,state);return 4;
        }
        return initial;
    case 3:
        if(request==2 || request==3)return request;
        if((request==4 || request==6) && start_allowed(state)){
            (void)ports.call(Action::start,0,state);return 4;
        }
        return initial;
    case 4:
        if(ports.call(Action::end_transition,0,state))return state.actual;
        if(ports.call(Action::buffer_pause,0,state))return state.actual;
        return state.requested==6?6:state.actual;
    default:return initial;
    }
}
}
std::uint32_t completion(const State& state)noexcept {
    if(!state.properties[5] && !state.properties[6])return 1;
    switch(state.properties[25]){
    case 0:return state.cached[1]&state.cached[3];
    case 1:return state.cached[3];
    case 2:return state.cached[1];
    case 3:return state.cached[1]|state.cached[3];
    default:return 0;
    }
}
void service(State& state,Ports& ports)noexcept {
    const auto initial=state.actual;
    if(initial-1u>=4u || !state.pending)return;
    state.pending=0;
    const auto begin=ports.call(Action::counter,0,state);
    if(initial-2u<3u){
        (void)ports.call(Action::broadcast,0,state);
        (void)ports.call(Action::shared,0,state);
    }
    // Providers may change actual or reschedule pending. Reload actual after
    // the prepass; do not clear a callback's newly scheduled work afterward.
    state.actual=transition(state,ports);
    const auto end=ports.call(Action::counter,0,state);
    (void)ports.call(Action::statistics,end-begin,state);
}
} // namespace reo::native::movie_service
