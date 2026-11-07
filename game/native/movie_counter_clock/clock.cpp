#include "clock.hpp"

namespace reo::native::movie_counter_clock {
namespace {
bool active(const State& state) noexcept{return state.actual==4 && state.pause==0 && state.buffering_pause==0;}
bool elapsed(const State& state) noexcept{return state.elapsed_counter!=0xFFFFFFFFu && state.requested==4;}
bool admitted(const State& state) noexcept {
    return state.actual==4 || state.actual==0xFFFFFFFCu || state.actual==6 || state.actual==0xFFFFFFFAu;
}
}
Effects execute(State& state,Operation operation,Words& words,std::uint32_t shared_frequency) noexcept {
    Effects effects;
    if(static_cast<unsigned>(operation)>static_cast<unsigned>(Operation::admit)){effects.valid_operation=false;return effects;}
    if(operation==Operation::tick){
        if(active(state)){state.active_counter+=state.increment;effects.writes[effects.count++]=Field::active_counter;}
        if(elapsed(state)){state.elapsed_counter+=state.increment;effects.writes[effects.count++]=Field::elapsed_counter;}
        return effects;
    }
    if(operation==Operation::rebase){
        state.elapsed_origin=state.property_47==1?state.active_counter:state.external_accumulator;
        effects.writes[effects.count++]=Field::elapsed_origin;return effects;
    }
    effects.status_defined=true;
    if(operation==Operation::active_gate){effects.status=active(state);return effects;}
    if(operation==Operation::elapsed_gate){effects.status=elapsed(state);return effects;}
    const auto eligible=admitted(state);
    if(!eligible){words={0xFFFFFFFFu,1};}
    else if(operation==Operation::admit || operation==Operation::contextual){
        effects.status=operation==Operation::admit?1u:0u;return effects;
    }else if(operation==Operation::unavailable){words={0xFFFFFFFEu,1};}
    else {words={state.active_counter,shared_frequency};}
    effects.writes[effects.count++]=Field::numerator;effects.writes[effects.count++]=Field::denominator;
    return effects;
}
}
