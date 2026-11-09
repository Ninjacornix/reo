#include "adxt_refill.hpp"
#include "../resources/bounded_view.hpp"

#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <cstdio>
#include <cstdlib>
#include <mutex>
#include <optional>
#include <stdexcept>
#include <thread>
#include <string>

namespace reo::native::resources {
std::shared_ptr<const ByteView> retain_resident_view(std::shared_ptr<const ByteView>,std::string);
bool is_resident_view(const std::shared_ptr<const ByteView>&) noexcept;
}

namespace r = reo::native::adxt_refill;
namespace resources = reo::native::resources;
namespace {
int assertions{};
void check(bool condition, const char* message) {
    ++assertions;
    if (!condition) { std::fprintf(stderr,"FAILED: %s\n",message); std::abort(); }
}
class PatternView : public resources::ByteView {
public:
    std::uint64_t size() const noexcept override { return 16384; }
    resources::ReadResult read(std::uint64_t offset, std::span<std::byte> out) const override {
        if (offset > size() || out.size() > size()-offset) return {resources::Status::invalid_range,0};
        for (std::size_t i=0;i<out.size();++i) out[i]=std::byte((offset+i)*37+(offset+i)/2048*19);
        return {resources::Status::ok,out.size()};
    }
};
class ScriptBackend final : public r::Backend {
public:
    std::int32_t acceptance{2}; bool error{}; int submissions{}, polls{}, joins{};
    std::uint64_t id{}; std::uint32_t sectors{}; bool retired{}, complete{}, bad_id{}, short_result{}, pending{};
    std::shared_ptr<const resources::ByteView> view; std::uint64_t offset{};
    r::Acceptance submit(std::shared_ptr<const resources::ByteView> input, std::uint64_t begin,
            std::uint32_t requested, std::uint64_t request) noexcept override {
        ++submissions; view=std::move(input); offset=begin; sectors=requested; id=request;
        pending=acceptance>0;
        return {acceptance,error};
    }
    r::Completion poll() noexcept override {
        ++polls;
        if (!pending) return {};
        if (!complete && !error) return {r::BackendState::pending,id,{}};
        retired=true; pending=false;
        if (error) return {r::BackendState::error,id,{}};
        std::vector<std::byte> bytes(static_cast<std::size_t>(acceptance)*2048);
        const auto result=view->read(offset,bytes);
        if (result.status!=resources::Status::ok) return {r::BackendState::error,id,{}};
        if (short_result) bytes.pop_back();
        return {r::BackendState::complete,bad_id ? id+1 : id,std::move(bytes)};
    }
    bool shutdown_and_join() noexcept override { ++joins; return !pending; }
};
struct Fixture {
    std::shared_ptr<PatternView> view=std::make_shared<PatternView>();
    ScriptBackend* script{};
    std::unique_ptr<r::EncodedSource> source;
    explicit Fixture(r::Config config={},r::Hooks hooks={},r::InitialBuffer initial={}) {
        auto backend=std::make_unique<ScriptBackend>(); script=backend.get();
        source=std::make_unique<r::EncodedSource>(config,view,std::move(backend),hooks,initial);
    }
};
void conservation(const r::Snapshot& s) {
    check(s.ring.data+s.ring.free+s.producer_bytes+s.consumer_bytes==s.ring.capacity,"all actual credits conserved");
}
void basic_and_leases() {
    Fixture f;
    check(f.source->service()==r::Status::completed,"submit real free grant");
    auto s=f.source->snapshot(); conservation(s);
    check(s.in_flight && s.ring.free==0 && s.ring.data==0 && s.producer_bytes==4096,"whole producer grant held");
    auto empty=f.source->borrow_data(4096);
    check(empty.status==r::Status::completed && empty.lease.bytes()==0,"unpublished producer data unreadable");
    check(f.source->finish_data(empty.lease,0)==r::Status::completed,"empty consumer token returned");
    check(f.source->service()==r::Status::completed,"pending service unchanged");
    check(f.script->submissions==1,"no duplicate pending submission");
    f.script->complete=true;
    check(f.source->service()==r::Status::completed,"ready publication");
    s=f.source->snapshot(); conservation(s);
    check(!s.in_flight && s.progress_sectors==2 && s.ring.data==4096,"accepted completed bytes published");
    auto data=f.source->borrow_data(3000); check(data.status==r::Status::completed,"data lease admitted");
    std::array<std::uint8_t,2048> bytes{};
    check(data.lease.read_into(bytes)==r::Status::completed && bytes[1]==37,"actual provider bytes consumed");
    conservation(f.source->snapshot());
    const auto before=f.source->snapshot().ring;
    check(f.source->finish_data(data.lease,3001)==r::Status::invalid_count,"overreturn refuses");
    check(f.source->snapshot().ring==before,"overreturn no effects");
    auto moved=std::move(data.lease);
    check(data.lease.read_into(bytes)==r::Status::invalid_lease,"moved token invalid");
    check(f.source->finish_data(moved,2048)==r::Status::completed,"prefix free and suffix unget");
    check(f.source->finish_data(moved,0)==r::Status::invalid_lease,"duplicate return refuses");
    s=f.source->snapshot(); conservation(s); check(s.ring.data==2048 && s.ring.free==2048,"partial consumer credit exact");
    Fixture other;
    auto remaining=f.source->borrow_data(2048);
    check(other.source->finish_data(remaining.lease,1)==r::Status::invalid_lease,"foreign owner refuses");
    check(f.source->finish_data(remaining.lease,0)==r::Status::completed,"zero consumed returns data");
}
void partial_wrap_consumer() {
    r::Config config; std::array<std::uint8_t,2048> occupied{};
    Fixture f(config,{},r::InitialBuffer{0,occupied}); f.script->acceptance=1;
    check(f.source->service()==r::Status::completed,"request with existing data");
    auto data=f.source->borrow_data(1024); check(data.status==r::Status::completed,"consumer while I/O pending");
    conservation(f.source->snapshot());
    check(f.source->finish_data(data.lease,1024)==r::Status::completed,"consumer return while pending");
    f.script->complete=true; check(f.source->service()==r::Status::completed,"partial producer completes");
    auto s=f.source->snapshot(); conservation(s); check(s.ring.data==3072 && s.ring.free==1024,"independent grants exact");
    Fixture wrap(config,{},r::InitialBuffer{2060,{}}); wrap.script->acceptance=1;
    check(wrap.source->service()==r::Status::completed,"wrap submission");
    check(wrap.source->snapshot().producer_bytes==2072,"actual extended free span");
    wrap.script->complete=true; check(wrap.source->service()==r::Status::completed,"actual mirror publication");
    auto chunk=wrap.source->borrow_data(2048); std::array<std::uint8_t,2048> output{};
    check(chunk.lease.read_into(output)==r::Status::completed,"wrapped data read");
    std::array<std::byte,2048> expected{}; (void)wrap.view->read(0,expected);
    for (std::size_t i=0;i<output.size();++i) check(output[i]==std::to_integer<std::uint8_t>(expected[i]),"wrapped payload exact");
    check(wrap.source->finish_data(chunk.lease,2048)==r::Status::completed,"wrapped consumer returns");
}
void rejected_and_protocol() {
    for (const auto acceptance : {0,-1}) {
        Fixture f; f.script->acceptance=acceptance; f.script->error=true;
        check(f.source->service()==r::Status::provider_failure,"declined error sign truthful");
        auto s=f.source->snapshot(); conservation(s);
        check(!s.in_flight && s.ring.free==4096 && s.retries==1,"declined whole grant returned");
        (void)f.source->service(); (void)f.source->service();
        check(f.source->snapshot().state==4 && f.source->snapshot().retries==2,"source retry cap exact");
    }
    Fixture zero; zero.script->acceptance=0;
    check(zero.source->service()==r::Status::completed && zero.source->snapshot().retries==0,"idle rejection does not retry");
    Fixture error; (void)error.source->service(); error.script->error=true;
    check(error.source->service()==r::Status::provider_failure,"later provider error");
    conservation(error.source->snapshot()); check(error.source->snapshot().ring.free==4096,"error whole grant unget");
    Fixture short_result; (void)short_result.source->service(); short_result.script->complete=true; short_result.script->short_result=true;
    check(short_result.source->service()==r::Status::provider_protocol,"short successful payload refused");
    check(short_result.source->snapshot().ring.data==0 && short_result.source->snapshot().ring.free==4096,"short bytes never published");
    Fixture wrong; (void)wrong.source->service(); wrong.script->complete=true; wrong.script->bad_id=true;
    check(wrong.source->service()==r::Status::provider_protocol,"wrong completion identity refused");
    check(wrong.source->snapshot().in_flight && wrong.source->snapshot().producer_bytes==4096,"unknown retirement retains storage credit");
    Fixture excessive; excessive.script->acceptance=3;
    check(excessive.source->service()==r::Status::provider_protocol,"overaccept refused");
    check(excessive.source->snapshot().in_flight,"overaccept cannot invent retirement");
}
struct HookProbe { r::EncodedSource* source{}; int calls{}; r::Status reentry{}; r::Snapshot observed{}; };
void target(void* raw,const r::Snapshot& s) noexcept {
    auto& probe=*static_cast<HookProbe*>(raw); ++probe.calls; probe.observed=s;
    probe.reentry=probe.source->request_close();
}
void control_and_incarnations() {
    HookProbe probe; r::Config config; config.target_sectors=1;
    Fixture f(config,{&probe,target,{}}); probe.source=f.source.get(); f.script->acceptance=1;
    check(f.source->set_paused(1)==r::Status::completed && f.source->service()==r::Status::completed,"pause controls only admission");
    check(f.script->submissions==0,"no paused request");
    (void)f.source->set_paused(2); (void)f.source->service();
    check(f.script->submissions==1,"pause values other than1 admitted");
    (void)f.source->set_paused(1); (void)f.source->request_stop();
    const auto before=f.source->snapshot().ring;
    check(f.source->reset_quiescent()==r::Status::busy,"pending reset refused");
    check(f.source->snapshot().ring==before,"pending reset no effects");
    f.script->complete=true; check(f.source->service()==r::Status::completed,"stop drains accepted publication");
    check(probe.calls==1 && probe.observed.progress_sectors==1 && probe.observed.producer_bytes==0,"source target observation order");
    check(probe.reentry==r::Status::reentrant_call,"callback mutation refused");
    check(f.source->snapshot().state==2,"stop not yet fully serviced");
    (void)f.source->service(); check(f.source->snapshot().state==1,"later stop handshake");
    auto data=f.source->borrow_data(2048); check(data.status==r::Status::completed,"stopped accepted data drains");
    check(f.source->reset_quiescent()==r::Status::busy,"consumer holds reset");
    (void)f.source->request_close(); (void)f.source->service();
    check(!f.source->snapshot().source_open,"close while consumer retains bytes");
    check(f.source->replace_source(f.view)==r::Status::busy,"source reuse held by consumer");
    check(f.source->finish_data(data.lease,2048)==r::Status::completed,"closed source returns actual credit");
    check(f.source->replace_source(f.view)==r::Status::completed,"drained new incarnation");
    check(f.source->snapshot().epoch==2 && f.source->snapshot().ring.data==0,"epoch increments only quiescent");
    config.maximum_id=1; Fixture limits(config); limits.script->acceptance=1;
    (void)limits.source->service(); limits.script->complete=true; (void)limits.source->service();
    auto token=limits.source->borrow_data(2048); (void)limits.source->finish_data(token.lease,2048);
    check(limits.source->borrow_data(1).status==r::Status::id_exhausted,"lease IDs never wrap");
    (void)limits.source->request_stop();
    check(limits.source->reset_quiescent()==r::Status::id_exhausted,"epoch IDs never wrap");
    Fixture abandoned; abandoned.script->acceptance=1; (void)abandoned.source->service();
    abandoned.script->complete=true; (void)abandoned.source->service();
    { auto lost=abandoned.source->borrow_data(2048); check(lost.status==r::Status::completed,"lost lease setup"); }
    check(abandoned.source->borrow_data(1).status==r::Status::busy,"lease destructor never returns credit");
}
class BlockedView final : public PatternView {
public:
    mutable std::mutex mutex; mutable std::condition_variable cv; mutable bool entered{}, release{}, done{};
    resources::ReadResult read(std::uint64_t offset,std::span<std::byte> out) const override {
        { std::unique_lock lock(mutex); entered=true; cv.notify_all(); cv.wait(lock,[&]{return release;}); }
        auto result=PatternView::read(offset,out);
        { std::lock_guard lock(mutex); done=true; cv.notify_all(); }
        return result;
    }
    void wait_entered() { std::unique_lock lock(mutex); check(cv.wait_for(lock,std::chrono::seconds(3),[&]{return entered;}),"real provider entered"); }
    void unblock() { std::lock_guard lock(mutex); release=true; cv.notify_all(); }
};
void actual_async_lifetime() {
    auto view=std::make_shared<BlockedView>(); std::weak_ptr<BlockedView> weak=view;
    r::EncodedSource source({},view,r::make_async_backend(4096));
    check(source.service()==r::Status::completed,"actual AsyncReadOwner submitted"); view->wait_entered();
    auto concurrent_data=source.borrow_data(2048);
    check(concurrent_data.status==r::Status::completed && concurrent_data.lease.bytes()==0,"data owner remains independent of blocked provider");
    check(source.finish_data(concurrent_data.lease,0)==r::Status::completed,"data hook has no provider wait");
    check(source.request_close()==r::Status::completed,"close signals without joining provider");
    check(source.begin_shutdown()==r::Status::completed,"shutdown is signal distinct from join");
    check(!source.finalize_shutdown_and_join(),"pending work not joined by lie");
    check(source.reset_quiescent()==r::Status::closed,"shutdown cannot reset provider state");
    check(source.service()==r::Status::completed && source.snapshot().in_flight,"blocked provider leaves held grant");
    conservation(source.snapshot());
    auto retained=view; view.reset(); check(!weak.expired(),"provider retained across pending close");
    retained->unblock();
    const auto deadline=std::chrono::steady_clock::now()+std::chrono::seconds(3);
    while (source.snapshot().in_flight && std::chrono::steady_clock::now()<deadline) {
        (void)source.service(); std::this_thread::yield();
    }
    check(!source.snapshot().in_flight && source.snapshot().ring.data==4096,"real blocked read publishes after normal close signal");
    (void)source.service(); check(!source.snapshot().source_open,"source close after completed lease");
    check(source.finalize_shutdown_and_join(),"real worker joined outside owner/ring hooks");
    check(source.snapshot().joined,"truthful joined state"); retained.reset();
    check(weak.expired(),"provider released after completion close and join");
}
class FailingView final : public PatternView {
public:
    explicit FailingView(bool allocation) : allocation_(allocation) {}
    resources::ReadResult read(std::uint64_t,std::span<std::byte> output) const override {
        if (!output.empty()) output[0]=std::byte{0x7B};
        if (allocation_) throw std::bad_alloc();
        return {resources::Status::source_failure,1};
    }
private:
    bool allocation_;
};
void actual_provider_failures() {
    for (const bool allocation : {false,true}) {
        auto view=std::make_shared<FailingView>(allocation);
        r::EncodedSource source({},view,r::make_async_backend(4096));
        check(source.service()==r::Status::completed,"real failure provider accepted request");
        const auto deadline=std::chrono::steady_clock::now()+std::chrono::seconds(3);
        r::Status status{};
        while (source.snapshot().in_flight && std::chrono::steady_clock::now()<deadline) {
            status=source.service(); std::this_thread::yield();
        }
        check(status==r::Status::provider_failure,"real source/allocation exception translated");
        const auto state=source.snapshot(); conservation(state);
        check(!state.in_flight && state.ring.data==0 && state.ring.free==4096,"failed staging never published and grant returned");
        (void)source.begin_shutdown(); check(source.finalize_shutdown_and_join(),"failed provider can really join");
    }
    auto view=std::make_shared<PatternView>();
    r::EncodedSource limited({},view,r::make_async_backend(2048));
    check(limited.service()==r::Status::provider_failure,"actual async read budget refusal");
    check(!limited.snapshot().in_flight && limited.snapshot().ring.free==4096,"submit refusal returns real grant");
}
void admission_and_owner_destruction() {
    auto view=std::make_shared<PatternView>();
    for (auto config : {r::Config{}}) {
        config.byte_length=2049;
        bool refused=false; try { r::EncodedSource bad(config,view,std::make_unique<ScriptBackend>()); }
        catch (const std::invalid_argument&) { refused=true; }
        check(refused,"partial sector geometry refused before callbacks/provider");
    }
    std::optional<r::DataLease> retained;
    { Fixture f; f.script->acceptance=1; (void)f.source->service(); f.script->complete=true; (void)f.source->service();
      auto lease=f.source->borrow_data(2048); retained.emplace(std::move(lease.lease)); }
    std::array<std::uint8_t,2> output{};
    check(retained->read_into(output)==r::Status::invalid_lease,"destroyed owner closes token while storage stays retained");
}
class GuardedResidentBody final:public PatternView {
public:
    mutable std::mutex mutex;
    mutable std::condition_variable wake;
    mutable bool entered{},released{};
    mutable std::atomic<unsigned> reads{};
    mutable std::atomic<std::size_t> full_read_bytes{};
    mutable std::atomic<bool> forbid{},forbidden_body_entered{};
    resources::ReadResult read(std::uint64_t offset,std::span<std::byte> out)const override{
        ++reads;
        if(forbid.load(std::memory_order_acquire)){
            forbidden_body_entered.store(true,std::memory_order_release);
            std::this_thread::sleep_for(std::chrono::milliseconds(2500));
            return {resources::Status::source_failure,0};
        }
        {
            std::unique_lock lock(mutex);entered=true;wake.notify_all();
            wake.wait(lock,[&]{return released;});
        }
        full_read_bytes.store(out.size(),std::memory_order_release);
        return PatternView::read(offset,out);
    }
    void release()const {std::lock_guard lock(mutex);released=true;wake.notify_all();}
};
void resident_adaptive_backend(){
    auto body=std::make_shared<GuardedResidentBody>();
    const auto resident=resources::retain_resident_view(body,"refill-test-resident-body-v1");
    check(bool(resident)&&!resources::is_resident_view(resident)&&body->reads==0,"resident construction/probe never reads unprepared source");
    const auto slice=resources::bounded_view(resident,2048,8192);
    check(slice.status==resources::Status::ok&&!resources::is_resident_view(slice.view),"bounded capability remains false before whole body ready");
    auto backend=r::make_async_backend(4096);
    check(backend->submit(slice.view,0,2,41).sectors==2,"lazy first request accepted through async backend");
    {
        std::unique_lock lock(body->mutex);
        check(body->wake.wait_for(lock,std::chrono::seconds(3),[&]{return body->entered;}),"first full source read runs on real worker");
    }
    check(!resources::is_resident_view(resident)&&backend->poll().state==r::BackendState::pending,"unready full-copy read remains pending");
    check(backend->submit(slice.view,0,1,42).sectors==0&&!backend->shutdown_and_join(),"one accepted request holds slot and retirement fence");
    body->release();
    r::Completion first;
    const auto deadline=std::chrono::steady_clock::now()+std::chrono::seconds(5);
    do {first=backend->poll();if(first.state==r::BackendState::pending)std::this_thread::yield();}
    while(first.state==r::BackendState::pending&&std::chrono::steady_clock::now()<deadline);
    check(first.state==r::BackendState::complete&&first.request_id==41&&first.bytes.size()==4096,"first async completion keeps exact request identity and byte count");
    check(resources::is_resident_view(resident)&&resources::is_resident_view(slice.view)&&body->reads==1&&body->full_read_bytes==body->size(),"readiness means entire original body copied, including through bounded parent");
    check(backend->poll().state==r::BackendState::idle,"first result transfers once");
    body->forbid.store(true,std::memory_order_release);
    // An untrusted view that looks like memory still uses the real async path.
    // Its armed body sleeps 2.5 seconds if invoked; prepared resident reads must
    // not invoke that body or wait for any queued read completion.
    auto untrusted=r::make_async_backend(4096);
    const auto began=std::chrono::steady_clock::now();
    check(untrusted->submit(body,0,2,99).sectors==2,"ordinary custom view remains async after a separate cache is ready");
    const auto body_deadline=began+std::chrono::seconds(3);
    while(!body->forbidden_body_entered.load(std::memory_order_acquire)&&std::chrono::steady_clock::now()<body_deadline)std::this_thread::yield();
    check(body->forbidden_body_entered.load(std::memory_order_acquire)&&untrusted->poll().state==r::BackendState::pending,"2.5-second ordinary body is pending rather than executed inline");
    check(untrusted->submit(slice.view,0,1,1000).sectors==0&&!untrusted->shutdown_and_join(),"ready memory cannot overtake an already accepted async request");
    const auto reads=body->reads.load();
    for(std::uint64_t id=100;id<132;++id){
        check(backend->submit(slice.view,4096,2,id).sectors==2,"resident bounded memory request accepted");
        check(backend->submit(slice.view,0,1,id+1000).sectors==0,"resident ready result preserves single pending slot");
        check(!backend->shutdown_and_join(),"resident accepted result must still drain before join");
        const auto result=backend->poll();
        check(result.state==r::BackendState::complete&&result.request_id==id&&result.bytes.size()==4096,"resident result immediately available without worker poll wait");
        for(std::size_t i=0;i<result.bytes.size();++i)check(result.bytes[i]==std::byte((6144+i)*37+(6144+i)/2048*19),"resident slice payload exact");
        check(backend->poll().state==r::BackendState::idle,"resident completion delivered exactly once");
    }
    check(body->reads==reads,"prepared data never calls original body again");
    check(backend->submit(slice.view,0,0,700).sectors==0,"zero-sector resident submission unchanged");
    check(backend->submit(slice.view,0,3,701).error,"resident maximum read budget still enforced");
    check(backend->submit(slice.view,8191,1,702).error,"resident subrange overflow refused");
    check(backend->submit(slice.view,std::numeric_limits<std::uint64_t>::max(),1,703).error,"resident offset overflow refused");
    check(backend->submit(slice.view,0,std::numeric_limits<std::uint32_t>::max(),704).error,"resident sector multiplication bounded before allocation");
    check(backend->shutdown_and_join()&&backend->submit(slice.view,0,1,705).sectors==0,"resident backend closes and joins normally");
    r::Completion failed;
    do {failed=untrusted->poll();if(failed.state==r::BackendState::pending)std::this_thread::yield();}
    while(failed.state==r::BackendState::pending&&std::chrono::steady_clock::now()-began<std::chrono::seconds(5));
    check(failed.state==r::BackendState::error&&failed.request_id==99&&failed.bytes.empty(),"untrusted delayed failure preserves result identity and no partial bytes");
    check(std::chrono::steady_clock::now()-began>=std::chrono::milliseconds(2400),"ordinary body actually imposed its 2.5-second blocked read");
    check(untrusted->submit(slice.view,0,1,1001).sectors==1,"same backend admits prepared memory after retiring its async request");
    const auto transitioned=untrusted->poll();
    check(transitioned.state==r::BackendState::complete&&transitioned.request_id==1001&&transitioned.bytes.size()==2048,"async-to-resident transition has immediate one-shot completion");
    check(untrusted->shutdown_and_join(),"ordinary delayed provider really joined");
    // A normal source close still drains its already accepted completion; the
    // adaptive memory path must not invent cancellation or drop accepted PCM.
    r::EncodedSource source({},resident,r::make_async_backend(4096));
    check(source.service()==r::Status::completed&&source.snapshot().in_flight,"resident source retains accepted request until poll");
    check(source.request_close()==r::Status::completed,"normal resident close signals source-view retirement");
    check(source.begin_shutdown()==r::Status::completed&&!source.finalize_shutdown_and_join(),"source shutdown cannot skip accepted resident result");
    check(source.service()==r::Status::completed&&!source.snapshot().in_flight&&source.snapshot().ring.data==4096,"accepted resident bytes drain through normal ring publication");
    check(source.service()==r::Status::completed&&!source.snapshot().source_open&&source.finalize_shutdown_and_join(),"source close and native join remain quiescent");
    check(body->reads==reads,"resident source drain/close makes no backing body read");
}
} // namespace
int main() {
    for(std::size_t bytes:std::array<std::size_t,3>{0,2049,r::maximum_source_read_bytes+2048}){
        bool refused=false;try{(void)r::make_async_backend(bytes,r::ReadProfile::bounded_source);}catch(const std::invalid_argument&){refused=true;}
        check(refused,"extended worker rejects invalid budget before a request");
    }
    for(auto profile:{r::ReadProfile::fixed_8k,static_cast<r::ReadProfile>(99)}){
        bool refused=false;try{(void)r::make_async_backend(8193,profile);}catch(const std::invalid_argument&){refused=true;}
        check(refused,"legacy/unknown worker profile cannot admit large request budget");
    }
    basic_and_leases(); partial_wrap_consumer(); rejected_and_protocol(); control_and_incarnations();
    actual_async_lifetime(); actual_provider_failures(); admission_and_owner_destruction();
    resident_adaptive_backend();
    std::printf("Native encoded-source checks passed: %d assertions\n",assertions);
}
