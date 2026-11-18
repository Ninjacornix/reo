#include "adx_window.hpp"
#include <array>
#include <cstdlib>
#include <iostream>
#include <new>
#include <stdexcept>
#include <vector>

namespace allocation_probe { bool deny{}; std::size_t denied{}; }
__attribute__((noinline)) void* operator new(std::size_t size) {
    if(allocation_probe::deny) { ++allocation_probe::denied; throw std::bad_alloc(); }
    if(void* result=std::malloc(size?size:1)) return result;
    throw std::bad_alloc();
}
__attribute__((noinline)) void operator delete(void* p) noexcept { std::free(p); }
__attribute__((noinline)) void operator delete(void* p,std::size_t) noexcept { std::free(p); }

using namespace reo::native::adx_window;
namespace {
std::size_t assertions{};
void require(bool value) { ++assertions; if(!value) throw std::runtime_error("ADX window assertion "+std::to_string(assertions)); }
void done(Status status) { require(status==Status::completed); }
std::vector<std::uint8_t> blocks(unsigned count) {
    std::vector<std::uint8_t> result;
    for(unsigned i=0;i<count;++i) {
        const auto header=0x1234u+i; result.push_back(static_cast<std::uint8_t>(header>>8)); result.push_back(static_cast<std::uint8_t>(header));
        for(unsigned j=0;j<16;++j) result.push_back(static_cast<std::uint8_t>(j*37+i*19));
    }
    return result;
}
struct Observer {
    Window* owner{};
    bool forbid_late_allocations{}, reenter{}, source_descriptors_seen{};
    int depth{}, errors{};
    std::size_t guards{}, count{};
    std::array<Snapshot,4> before_publish{};
    std::array<std::int32_t,4> bytes{};
    PcmView retained;
    Status nested{Status::completed};
    static void guard(void* p,std::uint32_t ring,bool entering) noexcept {
        auto& s=*static_cast<Observer*>(p); ++s.guards;
        s.depth+=entering?1:-1;
        if(s.forbid_late_allocations) allocation_probe::deny=true;
        if(s.reenter) s.nested=s.owner->stop();
        if(!entering && ring==0 && s.owner->snapshot().outer.encoded.bytes==72) s.source_descriptors_seen=true;
    }
    static void error(void* p,std::uint32_t,std::int32_t) noexcept { ++static_cast<Observer*>(p)->errors; }
    static void pcm(void* p,std::uint32_t,const PcmView& view) noexcept {
        auto& s=*static_cast<Observer*>(p);
        if(s.count<s.bytes.size()) { s.before_publish[s.count]=s.owner->snapshot(); s.bytes[s.count]=view.bytes(); }
        ++s.count; s.retained=view;
    }
    Hooks hooks() noexcept { return {this,guard,error,pcm,nullptr}; }
};

void real_transaction_and_callbacks() {
    Observer o; Config config; config.channels=2;
    Window owner(config,o.hooks()); o.owner=&owner;
    done(owner.feed_encoded(blocks(8))); o.guards=0;
    const auto token=owner.request(); done(owner.service(token));
    const auto s=owner.snapshot();
    require(s.outer.position==128 && s.outer.encoded_bytes==144 && s.outer.sample_progress==128);
    require(s.inner.produced_samples==128 && s.inner.consumed_bytes==144 && s.inner.decoded_total==128);
    require(s.inner.phase==EnginePhase::idle && s.predictor.phase==reo::native::adx_control::Phase::idle);
    require(s.predictor.completed_units==8 && o.errors==0 && o.depth==0 && o.count==2);
    require(o.bytes[0]==256 && o.bytes[1]==256);
    require(o.before_publish[0].rings[0].free==2048 && o.before_publish[0].rings[0].data==0);
    require(o.before_publish[0].rings[1].data==0 && o.before_publish[1].rings[1].data==256);
    require(o.before_publish[0].inner.phase==EnginePhase::ready && o.before_publish[0].outer.position==0);
    require(o.before_publish[0].predictor.phase==reo::native::adx_control::Phase::idle);
    require(s.rings[1].free+s.rings[1].data==pcm_capacity);
}

void resources_are_staged_before_borrow() {
    Observer o; Window owner({},o.hooks()); o.owner=&owner;
    done(owner.feed_encoded(blocks(4))); o.guards=0;
    const auto before=owner.snapshot();
    allocation_probe::deny=true; const auto refusal=owner.service(owner.request()); allocation_probe::deny=false;
    require(refusal==Status::no_memory && allocation_probe::denied>0);
    require(owner.snapshot()==before && o.guards==0 && o.count==0);
    o.forbid_late_allocations=true;
    const auto denied=allocation_probe::denied;
    const auto result=owner.service(owner.request()); allocation_probe::deny=false;
    o.forbid_late_allocations=false;
    require(result==Status::completed && allocation_probe::denied==denied);
    require(owner.snapshot().outer.position==128 && o.source_descriptors_seen);
}

void independent_buffers_and_scratch_admission() {
    Config config; config.channels=2; config.downmix=true;
    Window mixed(config); done(mixed.feed_encoded(blocks(8))); done(mixed.service(mixed.request()));
    std::array<std::uint8_t,pcm_capacity+pcm_extension> a{},b{};
    done(mixed.read_pcm_backing(0,a)); done(mixed.read_pcm_backing(1,b)); require(a==b);
    std::int32_t consumed=0; done(mixed.consume_pcm(0,64,consumed)); require(consumed==64);
    const auto before=mixed.snapshot(); require(mixed.service(mixed.request())==Status::unsupported_geometry);
    require(mixed.snapshot()==before); done(mixed.consume_pcm(1,64,consumed));
    Config limited; limited.sample_limit=35; limited.initial_pcm_bytes[0]=16304;
    Observer o; Window owner(limited,o.hooks()); o.owner=&owner;
    done(owner.feed_encoded(blocks(4))); const auto initial=owner.snapshot(); o.guards=0;
    require(owner.service(owner.request())==Status::output_extent); require(owner.snapshot()==initial && o.guards==0);
    // Only40 samples were reserved; the real kernel needs64 scratch samples.
    // Releasing48 bytes makes the entire scratch range admitted before decode.
    done(owner.consume_pcm(0,48,consumed)); done(owner.service(owner.request()));
    require(owner.snapshot().outer.position==35 && owner.snapshot().inner.consumed_bytes==36);
}

void wrap_and_backpressure() {
    Config config; config.initial_pcm_cursor[0]=16352;
    Window owner(config); done(owner.feed_encoded(blocks(4))); done(owner.service(owner.request()));
    const auto s=owner.snapshot(); require(s.outer.position==32 && s.rings[1].write==32);
    require(s.outer.pcm[0].offset==16352 && s.outer.pcm[0].bytes==224);
    std::array<std::uint8_t,pcm_capacity+pcm_extension> bytes{}; done(owner.read_pcm_backing(0,bytes));
    require(std::equal(bytes.begin(),bytes.begin()+32,bytes.begin()+pcm_capacity));
    Config pressure; pressure.initial_pcm_bytes[0]=16352;
    Window stalled(pressure); done(stalled.feed_encoded(blocks(4)));
    require(stalled.service(stalled.request())==Status::backpressure);
    require(stalled.snapshot().outer.position==0 && stalled.snapshot().rings[0].data==72);
    std::int32_t accepted=0; done(stalled.consume_pcm(0,64,accepted)); done(stalled.service(stalled.request()));
    require(stalled.snapshot().outer.position==32 && stalled.snapshot().rings[1].data==16352);
}

void markers_budget_and_zero_progress() {
    for(bool padding:{false,true}) {
        Window owner({}); auto data=std::vector<std::uint8_t>{0x80,0x01,0,12}; data.resize(16);
        if(padding) data.resize(40); else { const auto block=blocks(1); data.insert(data.end(),block.begin(),block.end()); }
        done(owner.feed_encoded(data)); done(owner.service(owner.request()));
        auto s=owner.snapshot(); require(s.outer.phase==OuterPhase::ended && s.outer.position==0);
        require(s.rings[0].data==(padding?0:18)); require(s.outer.encoded.bytes==0);
        require(owner.service(owner.request())==Status::inactive);
    }
    Window zero({}); done(zero.feed_encoded(std::array<std::uint8_t,24>{})); done(zero.service(zero.request()));
    require(zero.snapshot().outer.position==32 && zero.snapshot().rings[0].data==6);
    Config limited; limited.total_samples=35;
    Window clipped(limited); done(clipped.feed_encoded(blocks(4))); done(clipped.service(clipped.request()));
    require(clipped.snapshot().inner.produced_samples==128 && clipped.snapshot().outer.position==35);
    require(clipped.snapshot().inner.consumed_bytes==72 && clipped.snapshot().rings[1].data==70);
    Window short_marker({}); done(short_marker.feed_encoded(std::array<std::uint8_t,4>{0x80,1,0,12}));
    const auto before=short_marker.snapshot(); require(short_marker.service(short_marker.request())==Status::malformed_marker);
    require(short_marker.snapshot()==before);
    Config budget; budget.sample_limit=0; Window empty(budget); done(empty.feed_encoded(blocks(4))); done(empty.service(empty.request()));
    require(empty.snapshot().outer.position==0 && empty.snapshot().rings[0].data==72 && empty.snapshot().rings[1].free==pcm_capacity);
    InnerState state; state.local_output_offset=7; state.decoded_total=12;
    const auto default_reserve=constructor_default_reservation(state,1000);
    require(default_reserve.offset==7 && default_reserve.available==8185 && default_reserve.remaining==988);
}

void request_stop_and_lifetime() {
    Observer o; PcmView retained;
    {
        Window first({},o.hooks()); o.owner=&first; Window other({});
        const auto token=first.request(); require(other.service(token)==Status::stale_request);
        done(first.feed_encoded(blocks(4))); o.reenter=true; done(first.service(token)); o.reenter=false;
        require(o.nested==Status::busy && !first.snapshot().admission_closed);
        retained=o.retained; done(first.stop());
        require(first.service(token)==Status::stale_request);
        require(first.feed_encoded(blocks(1))==Status::admission_closed);
        require(first.snapshot().rings[1].data==256);
        std::int32_t bytes=0; done(first.consume_pcm(0,64,bytes)); require(bytes==64);
    }
    std::array<std::uint8_t,4> bytes{};
    require(retained.read(bytes)==reo::native::sjrb::Status::completed);
    Config bad; bad.channels=3; require(!Window::admits(bad));
    bad={}; bad.channels=2; bad.initial_pcm_bytes[1]=2; require(!Window::admits(bad));
    bad={}; bad.total_samples=4097; require(!Window::admits(bad));
    bad={}; bad.max_request_samples=257; require(!Window::admits(bad));
}
}

int main() {
    try {
        real_transaction_and_callbacks(); resources_are_staged_before_borrow(); independent_buffers_and_scratch_admission();
        wrap_and_backpressure(); markers_budget_and_zero_progress(); request_stop_and_lifetime();
        std::cout<<"ADX native window assertions passed: "<<assertions<<'\n';
    } catch(const std::exception& error) { allocation_probe::deny=false; std::cerr<<error.what()<<'\n'; return 1; }
}
