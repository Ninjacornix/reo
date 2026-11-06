#include "integer_clock.hpp"

namespace reo::native::adxt_integer_clock {
namespace {
std::uint32_t depth(Observation o) noexcept {
    if (o.depth_mode == 2) {
        if (o.depth_code == 2) return 4;
        return o.depth_code == 1 ? 8 : 16;
    }
    if (o.depth_mode == 1 && o.depth_code == 2) return 4;
    return 16;
}
}
Result query(Query kind, Observation o) noexcept {
    if (kind != Query::rna_ratio && kind != Query::decoded_minus_queued)
        return {Status::invalid_query, {}};
    Ratio value{0, 1};
    if (o.state == 3 || o.state == 4) {
        if (kind == Query::rna_ratio) value.denominator = 48000;
        else {
            if (o.rna_free_bytes > 16384 || (o.output_present && o.output_bytes > 16384))
                return {Status::invalid_queue_snapshot, {}};
            value.denominator = o.frequency;
            const auto rna = (16384u - o.rna_free_bytes) / 2;
            const auto output = o.output_present ? o.output_bytes / 2 : 0;
            value.numerator = o.decoded - rna - output + o.offset;
        }
    } else if (o.state == 5) {
        value.denominator = o.frequency;
        value.numerator = o.total * (16u / depth(o));
        if (kind == Query::decoded_minus_queued) value.numerator += o.offset;
    }
    value.numerator += o.base;
    return {Status::completed, value};
}
void select_mode(Mode& state, std::uint32_t selection) noexcept {
    state.selection = selection;
    if (selection == 1) state.ratio = 5994;
    else if (selection == 2) state.ratio = 5000;
}
void count_resynchronization(Mode& state) noexcept { ++state.resynchronizations; }
} // namespace reo::native::adxt_integer_clock
