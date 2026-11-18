#pragma once
// Verification-only legacy field projection. Never linked into the owner.
#include "context.hpp"
#include "../movie_clock_initialize/projection.hpp"
#include <array>
#include <vector>
namespace reo::native::movie_timing_context::testing {
inline std::vector<std::uint32_t> project(const View& view){
    const auto& facts=view.facts;
    std::vector<std::uint32_t> words{facts.actual,facts.requested,facts.pause,facts.depth,facts.pending,facts.buffering,facts.episodes,facts.rate,facts.property_e,facts.selector,facts.property_47,facts.tolerance,facts.admit_slack,facts.requested_slack};
    const auto clock=initialize::testing::project(view.clock);words.insert(words.end(),clock.begin(),clock.end());
    const auto& state=view.audio.filter;std::array<std::uint32_t,112> filter{};
    const auto word=[&](unsigned at,std::uint32_t value){filter[at/4]=value;};
    const auto lane=[&](unsigned at,std::uint64_t value){word(at,static_cast<std::uint32_t>(value));word(at+4,static_cast<std::uint32_t>(value>>32));};
    const auto pair=[&](unsigned at,audio::filter::Pair value){lane(at,value.numerator);lane(at+8,value.denominator);};
    word(0,state.enabled);word(4,state.pause);word(8,state.active);word(12,state.mode);word(16,state.window);word(20,state.sample_counter);
    for(unsigned n=0;n<state.history.size();++n)word(0x18+n*4,static_cast<std::uint32_t>(state.history[n]));
    pair(0x108,state.previous_input);pair(0x118,state.previous_helper);pair(0x128,state.previous_output);pair(0x138,state.quantum);pair(0x148,state.threshold);pair(0x158,state.first_offset);pair(0x168,state.later_offset);
    lane(0x178,state.helper_anchor);lane(0x180,state.master_anchor);lane(0x188,state.raw_maximum);
    word(0x190,state.reanchors);word(0x194,state.positive_steps);word(0x198,state.negative_steps);word(0x19C,state.resets);word(0x1A0,state.excess_resets);
    word(0x1A4,static_cast<std::uint32_t>(state.average_before));word(0x1A8,static_cast<std::uint32_t>(state.average_after));word(0x1AC,static_cast<std::uint32_t>(state.inactive_max));word(0x1B0,static_cast<std::uint32_t>(state.inactive_min));word(0x1B4,static_cast<std::uint32_t>(state.active_max));word(0x1B8,static_cast<std::uint32_t>(state.active_min));
    words.insert(words.end(),filter.begin(),filter.end());
    words.insert(words.end(),{view.audio.cache.numerator,view.audio.cache.denominator,view.guard.depth,view.guard.tag,view.audio.diagnostic,static_cast<std::uint32_t>(view.validated),static_cast<std::uint32_t>(view.audio.filter_observed)});
    return words;
}
}
