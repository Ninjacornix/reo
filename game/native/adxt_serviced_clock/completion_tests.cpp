#include "completion.hpp"
#include <cfenv>
#include <immintrin.h>
#include <iostream>
#include <stdexcept>
namespace c=reo::native::adxt_serviced_clock;
unsigned checks{};void check(bool b){++checks;if(!b)throw std::runtime_error("Serviced clock check "+std::to_string(checks));}
struct Port final:c::Service {
    std::shared_ptr<c::clock::Shared> shared=std::make_shared<c::clock::Shared>();
    c::clock::integer::Observation before{.state=3,.decoded=48000,.frequency=48000,.rna_free_bytes=16384},after=before;
    c::clock::Stream fresh{17,33,1,0};c::ServiceStatus result{c::ServiceStatus::completed};unsigned calls{},diagnostics{};bool recursive{},change_rounding{};c::Completion* owner{};
    const c::clock::Shared* clock_identity()const noexcept override{return shared.get();}
    c::clock::integer::Observation observation()const noexcept override{return before;}
    void discard_diagnostic()noexcept override{++diagnostics;}
    c::ServiceStatus run_and_refresh(c::clock::Stream& state,c::clock::integer::Observation& observation)noexcept override{
        ++calls;if(owner)recursive=owner->discard(0)==c::Status::busy;if(change_rounding)(void)std::fesetround(FE_DOWNWARD);state=fresh;observation=after;return result;
    }
};
int main(){try{
    auto port=std::make_shared<Port>();port->shared->mode={1,6000,17};port->shared->drift_bits=0x12345678;
    c::Completion clock(port->shared,port->fresh,port);port->owner=&clock;port->after.decoded=96000;
    const auto csr=_mm_getcsr();check(clock.discard(100)==c::Status::completed);check(port->recursive && port->calls==1);
    check(clock.snapshot().estimate_base==12000 && clock.snapshot().tick_base==100 && clock.snapshot().paused==1 && clock.snapshot().rna_play==0);
    check(_mm_getcsr()==csr && !port->shared->in_call && port->shared->mode.selection==1 && port->shared->mode.resynchronizations==17 && port->shared->drift_bits==0x12345678 && !port->shared->service_busy);
    port->result=c::ServiceStatus::failed;const auto before=clock.snapshot();check(clock.discard(200)==c::Status::service_failure && clock.snapshot()==before);
    port->result=c::ServiceStatus::completed;port->after.frequency=0;check(clock.discard(200)==c::Status::zero_divisor && clock.snapshot()==before);
    port->after.frequency=48000;port->change_rounding=true;check(clock.discard(200)==c::Status::unsupported_fp && clock.snapshot()==before && std::fegetround()==FE_TONEAREST);port->change_rounding=false;
    port->before.rna_free_bytes=16385;const auto calls=port->calls;check(clock.discard(200)==c::Status::invalid_queue && port->calls==calls);
    port->before.rna_free_bytes=16384;port->shared->in_call=true;check(clock.discard(200)==c::Status::busy);port->shared->in_call=false;
    const auto round=std::fegetround();(void)std::fesetround(FE_DOWNWARD);check(clock.discard(200)==c::Status::unsupported_fp && port->calls==calls);(void)std::fesetround(round);
    auto stopped=port->fresh;stopped.paused=0;c::Completion unpaused(port->shared,stopped,port);check(unpaused.discard(900)==c::Status::completed && port->calls==calls && unpaused.snapshot()==stopped);
    bool rejected=false;try{c::Completion foreign(std::make_shared<c::clock::Shared>(),port->fresh,port);}catch(const std::invalid_argument&){rejected=true;}check(rejected);
    std::cout<<checks<<" serviced clock ownership checks\n";return 0;
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}}
