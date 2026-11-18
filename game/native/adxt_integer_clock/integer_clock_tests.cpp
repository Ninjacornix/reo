#include "integer_clock.hpp"
#include <cstdio>
#include <cstdlib>
namespace c = reo::native::adxt_integer_clock;
namespace {
unsigned checks;
void check(bool value) { ++checks; if (!value) std::abort(); }
}
int main() {
    c::Observation o{3,40017,60001,48000,123,71,0,0,true,191,16191};
    auto r=c::query(c::Query::decoded_minus_queued,o);
    check(r.status==c::Status::completed && r.ratio==c::Ratio{40020,48000});
    check(c::query(c::Query::rna_ratio,o).ratio==c::Ratio{123,48000});
    // A queued byte is half a sample only after each original individual count
    // truncates. Combining two odd counts before division changes this case.
    o.output_bytes=1;o.rna_free_bytes=16383;
    check(c::query(c::Query::decoded_minus_queued,o).ratio.numerator==40211);
    o.rna_free_bytes=16385;
    check(c::query(c::Query::decoded_minus_queued,o).status==c::Status::invalid_queue_snapshot);
    check(c::query(c::Query::rna_ratio,o).status==c::Status::completed);
    o.rna_free_bytes=0;o.output_bytes=16385;
    check(c::query(c::Query::decoded_minus_queued,o).status==c::Status::invalid_queue_snapshot);
    o.output_present=false;
    check(c::query(c::Query::decoded_minus_queued,o).status==c::Status::completed);
    o.state=5;o.frequency=0;o.total=0xffffffff;o.offset=1;o.base=1;o.depth_mode=2;o.depth_code=2;
    check(c::query(c::Query::decoded_minus_queued,o).ratio==c::Ratio{0xfffffffe,0});
    check(c::query(c::Query::rna_ratio,o).ratio==c::Ratio{0xfffffffd,0});
    o.state=255;
    check(c::query(c::Query::decoded_minus_queued,o).ratio==c::Ratio{1,1});
    check(c::query(static_cast<c::Query>(999),o).status==c::Status::invalid_query);
    c::Mode mode{7,123,0xffffffff};
    c::select_mode(mode,0);check(mode==c::Mode{0,123,0xffffffff});
    c::select_mode(mode,1);check(mode==c::Mode{1,5994,0xffffffff});
    c::select_mode(mode,2);check(mode==c::Mode{2,5000,0xffffffff});
    c::select_mode(mode,0xffffffff);check(mode==c::Mode{0xffffffff,5000,0xffffffff});
    c::count_resynchronization(mode);check(mode.resynchronizations==0);
    std::printf("ADXT integer clock: %u assertions passed\n",checks);
}
