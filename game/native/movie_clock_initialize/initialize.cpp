#include "initialize.hpp"
namespace reo::native::movie_clock_initialize {
State initialize()noexcept {
    State state;
    using Kind=movie_selected_clock::Kind;
    state.callbacks={Kind::unavailable,Kind::counter,Kind::empty,Kind::contextual,Kind::empty,Kind::external,Kind::empty};
    constexpr std::array<std::uint32_t,6> defaults{0x7FFFFFFFu,0xFFFFFFFFu,0xFFFFFFFFu,0,0xFFFFFFFFu,0x7FFFFFFFu};
    for(unsigned index=0;index<state.records.size();++index)state.records[index].value={defaults[index],1};
    state.prefix.opaque={0,0,0xFFFFFFFFu,0xFFFFFFFFu};
    state.window_parameters={1,0,0,0};
    state.previous=state.latest=state.cached={0xFFFFFFFBu,1};
    state.admission_payload={0xFFFFFFFBu,0x7FFFFFFFu,0,0x7FFFFFFFu,0};
    state.increment=1000;state.requested_picture={0,1};state.hysteresis_count=100;
    state.tracked_query_bits=state.previous_query_bits=0xBF800000u;
    state.elapsed_counter=0xFFFFFFFFu;state.previous_external=0xFFFFFFFBu;state.external_denominator=1;
    return state;
}
}
