#pragma once
// Verification-only physical projection; not linked into the native core.
#include "initialize.hpp"
#include <vector>
namespace reo::native::movie_clock_initialize::testing {
inline std::vector<std::uint32_t> project(const State& state){
    std::vector<std::uint32_t> words;words.reserve(168);
    for(auto callback:state.callbacks)words.push_back(static_cast<std::uint32_t>(callback));
    for(const auto& record:state.records){words.push_back(record.count);words.insert(words.end(),record.history.begin(),record.history.end());words.push_back(record.value.numerator);words.push_back(record.value.denominator);}
    words.insert(words.end(),state.prefix.opaque.begin(),state.prefix.opaque.end());
    words.insert(words.end(),{state.prefix.side_baseline,state.prefix.bias,state.prefix.opaque_flag});
    words.insert(words.end(),state.first_window.begin(),state.first_window.end());
    words.insert(words.end(),state.window_parameters.begin(),state.window_parameters.end());
    words.insert(words.end(),state.second_window.begin(),state.second_window.end());
    for(auto pair:{state.previous,state.latest,state.cached})words.insert(words.end(),{pair.numerator,pair.denominator});
    words.insert(words.end(),state.admission_payload.begin(),state.admission_payload.end());
    words.insert(words.end(),{state.active_counter,state.increment,state.picture_sequence,state.requested_picture.numerator,state.requested_picture.denominator,state.hysteresis_count,state.tracked_query_bits,state.cached_decision,state.previous_query_bits,state.elapsed_counter,state.elapsed_origin,static_cast<std::uint32_t>(bool(state.external)),state.previous_external,state.external_accumulator,state.external_denominator});
    return words;
}
}
