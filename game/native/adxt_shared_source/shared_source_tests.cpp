#include "shared_source.hpp"
#include <algorithm>
#include <atomic>
#include <condition_variable>
#include <cstdlib>
#include <iostream>
#include <mutex>
#include <new>
#include <thread>
#include <vector>

thread_local bool deny_allocations=false;
#if defined(__GNUC__)
#define TEST_NOINLINE __attribute__((noinline))
#else
#define TEST_NOINLINE __declspec(noinline)
#endif
TEST_NOINLINE void* operator new(std::size_t bytes){if(deny_allocations)throw std::bad_alloc();if(auto* p=std::malloc(bytes?bytes:1))return p;throw std::bad_alloc();}
TEST_NOINLINE void* operator new[](std::size_t n){return ::operator new(n);}
TEST_NOINLINE void operator delete(void* p)noexcept{std::free(p);}TEST_NOINLINE void operator delete[](void* p)noexcept{std::free(p);}
TEST_NOINLINE void operator delete(void* p,std::size_t)noexcept{std::free(p);}TEST_NOINLINE void operator delete[](void* p,std::size_t)noexcept{std::free(p);}

namespace s=reo::native::adxt_shared_source;
namespace old=reo::native::adxt_refill;
namespace r=reo::native::resources;
namespace reo::native::adx_window::v2 {
// Fixture for the concrete future Window2 link; no Ring or source pointer is
// available through this capability. Production has no generic user mutator.
class StreamWindowOwner {
public:
    static s::Status configure(s::WindowLink& link,s::HeaderGeometry h,std::int32_t n,std::int32_t t,s::FileTargetAction f,s::DecoderLimitAction d){return link.configure(h,n,t,f,d);}
    static s::LoopSnapshot snapshot(const s::WindowLink& link){return link.snapshot();}
};
}
using Window=reo::native::adx_window::v2::StreamWindowOwner;
unsigned assertions=0;
void check(bool value){++assertions;if(!value){std::cerr<<"assertion "<<assertions<<" failed\n";std::exit(1);}}
void ok(s::Status status){check(status==s::Status::completed);}
s::ReadBatch take(s::BatchResult result){ok(result.status);return std::move(result.batch);}
struct View final:r::ByteView {
    std::vector<std::byte> data;
    explicit View(std::size_t n):data(n){for(std::size_t i=0;i<n;++i)data[i]=std::byte((i*37+11)%251);}
    std::uint64_t size()const noexcept override{return data.size();}
    r::ReadResult read(std::uint64_t offset,std::span<std::byte> out)const override {
        if(offset>data.size()||out.size()>data.size()-offset)return {r::Status::invalid_range,0};
        std::copy_n(data.begin()+std::ptrdiff_t(offset),out.size(),out.begin());return {r::Status::ok,out.size()};
    }
};
struct Script final:s::Backend {
    int accepted=-1;bool declined_error{},pending{},ready{},failed{},wrong_id{};unsigned submitted{},joined{};
    std::uint64_t id{},offset{};std::uint32_t requested{};std::shared_ptr<const r::ByteView> view;
    std::vector<std::byte> result;
    old::Acceptance submit(std::shared_ptr<const r::ByteView> v,std::uint64_t at,std::uint32_t count,std::uint64_t token)noexcept override {
        ++submitted;view=std::move(v);offset=at;requested=count;id=token;
        const int n=accepted<0?int(count):accepted;pending=n>0;return {n,declined_error};
    }
    void complete(bool error=false){failed=error;result.clear();if(!error){result.resize(std::size_t(accepted<0?int(requested):accepted)*2048);auto got=view->read(offset,result);check(got.status==r::Status::ok);}ready=true;}
    old::Completion poll()noexcept override {
        if(!pending)return {};
        if(!ready)return {old::BackendState::pending,id,{}};
        pending=false;ready=false;view.reset();
        return {failed?old::BackendState::error:old::BackendState::complete,wrong_id?id+1:id,std::move(result)};
    }
    bool shutdown_and_join()noexcept override{if(pending)return false;++joined;view.reset();return true;}
};
struct Observations {
    unsigned enters{},leaves{},errors{},targets{};s::SharedEncodedSource* owner{};
    s::Status attempted=s::Status::completed;s::TargetObservation target;
    static void enter(void* p)noexcept{auto& x=*static_cast<Observations*>(p);++x.enters;if(x.owner)x.attempted=x.owner->set_loop_enabled(false);}
    static void leave(void* p)noexcept{++static_cast<Observations*>(p)->leaves;}
    static void error(void* p,std::int32_t)noexcept{++static_cast<Observations*>(p)->errors;}
    static void reached(void* p,const s::TargetObservation& t)noexcept{auto& x=*static_cast<Observations*>(p);++x.targets;x.target=t;if(x.owner)x.attempted=x.owner->request_stop();}
    s::Hooks hooks(){return {this,reached,{this,enter,leave,error}};}
};
struct Fixture {
    std::shared_ptr<View> view=std::make_shared<View>(16384);
    std::vector<std::uint8_t> seed=std::vector<std::uint8_t>(2048);
    Script* backend{};Observations observations;std::unique_ptr<s::SharedEncodedSource> source;
    Fixture(std::int32_t position=7900,s::InitialLoop loop={},s::Config config={}) {
        config.capacity=8192;if(config.maximum_request_bytes==4096)config.maximum_request_bytes=8192;
        if(config.maximum_sectors==2)config.maximum_sectors=4;
        if(config.byte_length==4096)config.byte_length=8192;
        config.threshold=8192;
        for(std::size_t i=0;i<seed.size();++i)seed[i]=std::uint8_t(view->data[i]);
        auto implementation=std::make_unique<Script>();backend=implementation.get();
        source=std::make_unique<s::SharedEncodedSource>(config,view,std::move(implementation),loop,s::PreparedPrefix{position,1,seed},observations.hooks());
        observations.owner=source.get();
    }
};
void conserved(const s::Snapshot& x) {
    check(std::int64_t(x.ring.data)+x.ring.free+x.producer_remaining.bytes+x.consumers[0].bytes+x.consumers[1].bytes==8192);
}
void batch_plans() {
    for(auto kind:{s::FinishKind::restore_reverse,s::FinishKind::consume_first_prefix_restore_second,s::FinishKind::consume_second_prefix_consume_first}){
        Fixture f;auto batch=take(f.source->borrow_batch({s::BatchShape::two,INT32_MAX,INT32_MAX}));
        check(batch.count()==2&&batch.bytes(0)==328&&batch.bytes(1)==1720);conserved(f.source->snapshot());
        std::vector<std::uint8_t> bytes(2048);ok(batch.read_into(0,{bytes.data(),328}));ok(batch.read_into(1,{bytes.data()+328,1720}));check(bytes==f.seed);
        const auto old=f.source->snapshot().ring;const auto calls=f.observations.enters;
        check(f.source->finish_batch(batch,{s::FinishKind::consume_second_prefix_consume_first,1721})==s::Status::invalid_count);
        check(f.source->snapshot().ring==old&&f.observations.enters==calls);check(batch.count()==2);
        const int prefix=kind==s::FinishKind::restore_reverse?0:100;
        ok(f.source->finish_batch(batch,{kind,prefix}));check(batch.count()==0);
        check(f.source->finish_batch(batch,{kind,prefix})==s::Status::invalid_lease);
        const int consumed=kind==s::FinishKind::restore_reverse?0:kind==s::FinishKind::consume_first_prefix_restore_second?100:428;
        auto after=f.source->snapshot();check(after.ring.data==2048-consumed&&after.ring.free==6144+consumed);conserved(after);
        auto next=take(f.source->borrow_batch({s::BatchShape::one,INT32_MAX,0}));std::vector<std::uint8_t> got(std::size_t(next.bytes(0)));
        ok(next.read_into(0,got));check(std::equal(got.begin(),got.end(),f.seed.begin()+consumed));
        ok(f.source->finish_batch(next,{s::FinishKind::consume_single_prefix,next.bytes(0)}));
        check(f.observations.errors==0&&f.observations.enters==f.observations.leaves&&f.observations.attempted==s::Status::reentrant_call);
    }
    Fixture f;auto zero=take(f.source->borrow_batch({s::BatchShape::two,0,0}));check(zero.count()==2&&zero.bytes(0)==0&&zero.bytes(1)==0);
    const auto before=f.source->snapshot().ring;const auto enters=f.observations.enters;
    ok(f.source->finish_batch(zero,{s::FinishKind::restore_reverse,0}));check(f.source->snapshot().ring==before&&f.observations.enters==enters&&f.observations.errors==0);
    auto mixed=take(f.source->borrow_batch({s::BatchShape::two,0,INT32_MAX}));check(mixed.bytes(0)==0&&mixed.bytes(1)==328);
    ok(f.source->finish_batch(mixed,{s::FinishKind::consume_second_prefix_consume_first,0}));conserved(f.source->snapshot());
}
void lease_lifetime() {
    Fixture a,b;auto original=take(a.source->borrow_batch({s::BatchShape::two,INT32_MAX,INT32_MAX}));
    check(b.source->finish_batch(original,{s::FinishKind::restore_reverse,0})==s::Status::invalid_lease);
    s::ReadBatch moved(std::move(original));check(original.count()==0&&moved.count()==2);
    check(a.source->finish_batch(original,{s::FinishKind::restore_reverse,0})==s::Status::invalid_lease);
    ok(a.source->finish_batch(moved,{s::FinishKind::restore_reverse,0}));
    {auto lost=take(a.source->borrow_batch({s::BatchShape::one,100,0}));check(lost.bytes(0)==100);}
    check(a.source->borrow_batch({s::BatchShape::one,1,0}).status==s::Status::busy);
    ok(a.source->begin_shutdown());check(!a.source->finalize_shutdown_and_join());
    auto held=take(b.source->borrow_batch({s::BatchShape::one,100,0}));b.source.reset();std::array<std::uint8_t,1> out{};
    check(held.read_into(0,out)==s::Status::invalid_lease); // Strong storage, dead control identity.
}
void producer_and_consumers() {
    for(bool error:{false,true}){
        Fixture f;f.backend->accepted=1;ok(f.source->service().status);check(f.backend->requested==3&&f.source->snapshot().producer.bytes==6144);
        auto batch=take(f.source->borrow_batch({s::BatchShape::two,INT32_MAX,INT32_MAX}));auto pending=f.source->snapshot();
        check(pending.in_flight&&pending.ring.data==0&&pending.ring.free==0&&pending.consumer_count==2);conserved(pending);
        f.backend->complete(error);std::array<std::uint8_t,2> held{};ok(batch.read_into(0,held));check(held[0]==f.seed[0]);
        auto result=f.source->service();check(result.status==(error?s::Status::provider_failure:s::Status::completed));
        auto after=f.source->snapshot();check(!after.in_flight&&after.producer.bytes==0);conserved(after);
        check(after.ring.data==(error?0:2048)&&after.ring.free==(error?6144:4096));
        ok(f.source->finish_batch(batch,{s::FinishKind::restore_reverse,0}));conserved(f.source->snapshot());
    }
}
void target_actions() {
    for(bool enabled:{false,true}){
        auto view=std::make_shared<View>(4096);std::vector<std::uint8_t> seed(2048);for(unsigned i=0;i<2048;++i)seed[i]=std::uint8_t(view->data[i]);
        s::Config cfg;cfg.capacity=8192;cfg.byte_length=4096;cfg.maximum_request_bytes=8192;cfg.maximum_sectors=4;cfg.target_sectors=2;cfg.threshold=8192;
        s::InitialLoop loop{{0,4096,0,32},32,s::FileTargetAction::file_loop,s::DecoderLimitAction::repeat,enabled};
        auto script=std::make_unique<Script>();auto* backend=script.get();backend->accepted=1;Observations observations;
        s::SharedEncodedSource source(cfg,view,std::move(script),loop,{0,1,seed},observations.hooks());observations.owner=&source;
        auto link=source.take_window_link();ok(link.status);check(link.link.valid());
        ok(source.service().status);backend->complete();auto result=source.service();auto state=source.snapshot();
        check(result.published&&result.target_invoked&&observations.targets==1);check(state.cumulative_bytes==2048);
        check(observations.target.before.progress_sectors==2&&observations.target.before.cumulative_bytes==2048&&observations.target.before.producer.bytes==0&&!observations.target.before.in_flight);
        check(state.progress_sectors==(enabled?0:2)&&state.state==(enabled?2:3));
        check(state.loop.sample_limit==(enabled?32:-1)&&state.loop.target_sectors==(enabled?2:INT32_MAX));
        check(Window::snapshot(link.link).sample_limit==state.loop.sample_limit);check(observations.attempted==s::Status::reentrant_call);
    }
    Fixture f(0,{{0,8192,0,32},32,s::FileTargetAction::file_loop,s::DecoderLimitAction::first_snapshot,true});
    auto link=f.source->take_window_link();ok(link.status);check(f.source->take_window_link().status==s::Status::busy);
    ok(Window::configure(link.link,{0,8192,0,32},32,2,s::FileTargetAction::file_loop,s::DecoderLimitAction::first_snapshot));
    f.backend->accepted=1;ok(f.source->service().status);ok(f.source->set_loop_enabled(false));f.backend->complete();check(f.source->service().limit_removed);check(f.source->snapshot().loop.sample_limit==-1);
    check(Window::configure(link.link,{-1,0,0,0},1,2,s::FileTargetAction::file_loop,s::DecoderLimitAction::repeat)==s::Status::invalid_configuration);
    auto view=std::make_shared<View>(8192);s::Config cfg;cfg.capacity=8192;cfg.byte_length=8192;cfg.maximum_request_bytes=8192;cfg.maximum_sectors=4;cfg.threshold=8192;
    auto implementation=std::make_unique<Script>();auto* readonly=implementation.get();Observations observation;
    s::SharedEncodedSource plain(cfg,view,std::move(implementation),{},{},observation.hooks());observation.owner=&plain;
    ok(plain.service().status);readonly->complete();auto boundary=plain.service();
    check(boundary.target_invoked&&!boundary.limit_removed&&!boundary.progress_rewound&&observation.targets==1);
    check(observation.target.before.state==2&&plain.snapshot().state==3&&plain.snapshot().cumulative_bytes==8192);
}
void stop_and_failure() {
    Fixture f;f.backend->accepted=1;ok(f.source->service().status);ok(f.source->request_stop());ok(f.source->request_close());
    check(f.source->snapshot().in_flight&&f.source->snapshot().source_open);check(f.source->service().status==s::Status::completed);
    f.backend->complete();check(f.source->service().published);check(f.source->snapshot().source_open);ok(f.source->service().status);
    check(f.source->snapshot().state==1&&!f.source->snapshot().source_open&&f.source->snapshot().ring.data==4096);
    auto token=take(f.source->borrow_batch({s::BatchShape::two,INT32_MAX,INT32_MAX}));ok(f.source->begin_shutdown());check(!f.source->finalize_shutdown_and_join());
    ok(f.source->finish_batch(token,{s::FinishKind::restore_reverse,0}));check(f.source->finalize_shutdown_and_join());check(f.backend->joined==1);
    check(f.source->finalize_shutdown_and_join()&&f.backend->joined==1);
    Fixture bad;bad.backend->accepted=5;check(bad.source->service().status==s::Status::provider_protocol);check(bad.source->snapshot().in_flight&&bad.source->snapshot().producer.bytes>0);
    ok(bad.source->begin_shutdown());check(!bad.source->finalize_shutdown_and_join());
    Fixture wrong;wrong.backend->accepted=1;ok(wrong.source->service().status);wrong.backend->complete();wrong.backend->wrong_id=true;
    check(wrong.source->service().status==s::Status::provider_protocol);check(wrong.source->snapshot().in_flight&&wrong.source->snapshot().producer_remaining.bytes==6144);
}
struct Gate {std::mutex mutex;std::condition_variable changed;bool entered{},release{},fail{},destroyed{};};
struct BlockingView final:r::ByteView {
    std::shared_ptr<Gate> gate;explicit BlockingView(std::shared_ptr<Gate> x):gate(std::move(x)){}
    ~BlockingView(){std::lock_guard lock(gate->mutex);gate->destroyed=true;gate->changed.notify_all();}
    std::uint64_t size()const noexcept override{return 8192;}
    r::ReadResult read(std::uint64_t offset,std::span<std::byte> out)const override {
        {std::unique_lock lock(gate->mutex);gate->entered=true;gate->changed.notify_all();gate->changed.wait(lock,[&]{return gate->release;});}
        std::fill(out.begin(),out.end(),std::byte(offset/2048+33));
        return {gate->fail?r::Status::source_failure:r::Status::ok,gate->fail?0:out.size()};
    }
};
void actual_provider() {
    for(bool failure:{false,true}){
        auto gate=std::make_shared<Gate>();gate->fail=failure;auto view=std::make_shared<BlockingView>(gate);std::weak_ptr<BlockingView> weak=view;
        s::Config cfg;cfg.capacity=8192;cfg.byte_length=8192;cfg.maximum_request_bytes=8192;cfg.maximum_sectors=4;cfg.threshold=8192;
        std::vector<std::uint8_t> seed(2048,17);
        s::SharedEncodedSource source(cfg,view,old::make_async_backend(8192),{},{7900,1,seed});view.reset();
        ok(source.service().status);{std::unique_lock lock(gate->mutex);gate->changed.wait(lock,[&]{return gate->entered;});}
        auto batch=take(source.borrow_batch({s::BatchShape::two,INT32_MAX,INT32_MAX}));check(batch.bytes(0)>0&&batch.bytes(1)>0);
        ok(source.request_stop());ok(source.request_close());check(source.snapshot().in_flight&&!weak.expired());
        check(source.service().status==s::Status::completed&&source.snapshot().in_flight); // No wait or publication suppression.
        {std::lock_guard lock(gate->mutex);gate->release=true;}gate->changed.notify_all();
        s::ServiceResult result;do{result=source.service();std::this_thread::yield();}while(source.snapshot().in_flight);
        check(result.status==(failure?s::Status::provider_failure:s::Status::completed));check(result.published!=failure);
        ok(source.service().status);check(!source.snapshot().source_open);conserved(source.snapshot());
        std::array<std::uint8_t,1> held{};ok(batch.read_into(0,held));check(held[0]==17);
        ok(source.begin_shutdown());check(!source.finalize_shutdown_and_join());
        ok(source.finish_batch(batch,{s::FinishKind::restore_reverse,0}));check(source.finalize_shutdown_and_join());
        check(weak.expired());{std::lock_guard lock(gate->mutex);check(gate->destroyed);}
    }
}
void limits_and_allocation() {
    s::Config cfg;cfg.maximum_id=1;Fixture f(0,{},cfg);
    auto once=take(f.source->borrow_batch({s::BatchShape::one,0,0}));ok(f.source->finish_batch(once,{s::FinishKind::restore_reverse,0}));
    check(f.source->borrow_batch({s::BatchShape::one,0,0}).status==s::Status::id_exhausted);
    Fixture n;n.backend->accepted=1;ok(n.source->service().status);n.backend->complete();
    deny_allocations=true;
    auto batch=take(n.source->borrow_batch({s::BatchShape::two,INT32_MAX,INT32_MAX}));auto publication=n.source->service();
    ok(publication.status);ok(n.source->finish_batch(batch,{s::FinishKind::consume_second_prefix_consume_first,100}));
    ok(n.source->set_paused(2));ok(n.source->set_loop_enabled(true));
    deny_allocations=false;conserved(n.source->snapshot());
    Fixture requests(0,{},cfg);requests.backend->accepted=1;ok(requests.source->service().status);requests.backend->complete();ok(requests.source->service().status);
    auto before=requests.source->snapshot().ring;auto enters=requests.observations.enters;
    check(requests.source->service().status==s::Status::id_exhausted);check(requests.source->snapshot().ring==before&&requests.observations.enters==enters);
    Fixture invalid_target;auto link=invalid_target.source->take_window_link();ok(link.status);
    ok(Window::configure(link.link,{},-1,0,s::FileTargetAction::none,s::DecoderLimitAction::none));
    before=invalid_target.source->snapshot().ring;enters=invalid_target.observations.enters;
    check(invalid_target.source->service().status==s::Status::invalid_configuration);
    check(invalid_target.source->snapshot().ring==before&&invalid_target.observations.enters==enters&&invalid_target.backend->submitted==0);
    Fixture updated(0,{{0,8192,0,32},32,s::FileTargetAction::file_loop,s::DecoderLimitAction::repeat,true});
    auto current=updated.source->take_window_link();ok(current.status);
    ok(Window::configure(current.link,{0,8192,0,32},32,2,s::FileTargetAction::file_loop,s::DecoderLimitAction::repeat));
    updated.backend->accepted=1;ok(updated.source->service().status);
    ok(Window::configure(current.link,{2048,8192,32,64},64,2,s::FileTargetAction::file_loop,s::DecoderLimitAction::seamless));
    updated.backend->complete();auto changed=updated.source->service();check(changed.target_invoked&&changed.progress_rewound);
    check(updated.source->snapshot().progress_sectors==1&&updated.source->snapshot().cumulative_bytes==2048&&updated.source->snapshot().loop.sample_limit==64);
    updated.source.reset();check(!current.link.valid());check(Window::configure(current.link,{},-1,0,s::FileTargetAction::none,s::DecoderLimitAction::none)==s::Status::closed);
}
void ring_completed_is_not_position_proof(){
    Observations observations;reo::native::sjrb::Ring ring(8192,36,observations.hooks().ring);
    reo::native::sjrb::Chunk chunk,bad;check(ring.get(0,100,chunk)==reo::native::sjrb::Status::completed);check(ring.put(1,chunk)==reo::native::sjrb::Status::completed);
    check(ring.get(1,50,chunk)==reo::native::sjrb::Status::completed);check(ring.make_span(7,1,bad)==reo::native::sjrb::Status::completed);
    auto before=ring.snapshot();check(ring.unget(1,bad)==reo::native::sjrb::Status::completed);
    auto after=ring.snapshot();check(observations.errors==1&&after.read==before.read&&after.data==before.data&&after.totals[2]==before.totals[2]-1);
}
void injected_posteffect_failure(){
    Fixture f;auto batch=take(f.source->borrow_batch({s::BatchShape::two,INT32_MAX,INT32_MAX}));
    check(f.source->finish_batch(batch,{s::FinishKind::consume_first_prefix_restore_second,100})==s::Status::ring_failure);
    const auto state=f.source->snapshot();check(state.ledger_fault&&state.state==4&&state.consumers[0].bytes==328&&state.consumers[1].bytes==0);
    check(state.ring.data==1720&&state.ring.free==6144);conserved(state);
    std::array<std::uint8_t,1> out{};check(batch.read_into(0,out)==s::Status::invalid_lease);
    check(f.source->borrow_batch({s::BatchShape::one,1,0}).status==s::Status::invariant_fault);
    check(f.source->finish_batch(batch,{s::FinishKind::restore_reverse,0})==s::Status::invariant_fault);
    ok(f.source->begin_shutdown());check(!f.source->finalize_shutdown_and_join());
}
void bounded_capacities(){
    for(std::int32_t capacity:{53248,272384,s::maximum_encoded_capacity}){
        check(!s::admits_capacity(capacity,s::CapacityProfile::fixed_8k));
        auto view=std::make_shared<View>(static_cast<std::size_t>(capacity)*2);
        s::Config config;config.capacity=config.threshold=config.maximum_request_bytes=capacity;config.maximum_sectors=capacity/2048;config.byte_length=capacity*2;
        std::array<std::uint8_t,64> seed{};for(unsigned n=0;n<seed.size();++n)seed[n]=static_cast<std::uint8_t>(view->data[n]);
        auto backend=std::make_unique<Script>();
        s::SharedEncodedSource source(config,view,std::move(backend),{},{capacity-20,0,seed},{},s::CapacityProfile::bounded_sectors);
        const auto before=source.snapshot();check(before.ring.capacity==capacity && before.ring.data==64 && before.ring.free==capacity-64);
        auto batch=take(source.borrow_batch({s::BatchShape::two,INT32_MAX,INT32_MAX}));check(batch.count()==2 && batch.bytes(0)==56 && batch.bytes(1)==8);
        std::array<std::uint8_t,64> copied{};ok(batch.read_into(0,std::span(copied).first(56)));ok(batch.read_into(1,std::span(copied).subspan(56)));check(copied==seed);
        check(source.finish_batch(batch,{s::FinishKind::consume_second_prefix_consume_first,9})==s::Status::invalid_count);
        ok(source.finish_batch(batch,{s::FinishKind::consume_second_prefix_consume_first,8}));const auto after=source.snapshot();check(!after.ring.data && after.ring.free==capacity);
        ok(source.begin_shutdown());check(source.finalize_shutdown_and_join());
    }
    for(auto capacity:{-1,0,2047,2049,s::maximum_encoded_capacity+2048})check(!s::admits_capacity(capacity,s::CapacityProfile::bounded_sectors));
    check(!s::admits_capacity(8192,static_cast<s::CapacityProfile>(99)));
}
int main(int argc,char** argv){if(argc==2&&std::string_view(argv[1])=="posteffect"){injected_posteffect_failure();std::cout<<"posteffect_assertions="<<assertions<<"\n";return 0;}
    batch_plans();lease_lifetime();producer_and_consumers();target_actions();stop_and_failure();actual_provider();limits_and_allocation();ring_completed_is_not_position_proof();bounded_capacities();
    std::cout<<"shared_source_assertions="<<assertions<<" real_async_backend=exercised\n";}
