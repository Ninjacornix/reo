#include "session.hpp"
#include "algorithms.hpp"
#include <algorithm>
#include <atomic>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

namespace b=reo::native::audio_banks::v2;
#include "test_inputs.hpp"
struct Event {std::mutex mutex;std::condition_variable cv;bool set{};void signal(){std::lock_guard lock(mutex);set=true;cv.notify_all();}void wait(){std::unique_lock lock(mutex);cv.wait(lock,[&]{return set;});}};
std::atomic<unsigned> assertions{};
void check(bool condition){auto n=++assertions;if(!condition)throw std::runtime_error("budget v2 assertion "+std::to_string(n));}
void ok(b::Status status){check(status==b::Status::ok);}
template<class T>T take(b::Result<T> result){ok(result.status);return std::move(result.value);}
struct Source final:b::AllocationSource {
    struct Record {void* p{};std::size_t bytes{},alignment{};};
    std::array<Record,1024> records{};
    b::HeapSource heap;
    std::mutex mutex;
    std::size_t calls{},frees{},live{},peak{};
    std::size_t fail_at=SIZE_MAX;
    bool render{};
    unsigned callback_alloc{},callback_free{};
    std::atomic<bool> pause_next{};
    std::atomic<bool> pause_free{};
    Event entered,resume;
    Event free_entered,free_resume;
    void* allocate(std::size_t bytes,std::size_t alignment)override {
        {std::lock_guard lock(mutex);if(render)++callback_alloc;if(calls++==fail_at)throw std::bad_alloc();}
        if(pause_next.exchange(false)){entered.signal();resume.wait();}
        void* p=heap.allocate(bytes,alignment);
        {std::lock_guard lock(mutex);auto it=std::find_if(records.begin(),records.end(),[](const auto& r){return !r.p;});if(it==records.end())std::terminate();*it={p,bytes,alignment};live+=bytes;peak=std::max(peak,live);}
        return p;
    }
    void deallocate(void* p,std::size_t bytes,std::size_t alignment)noexcept override {
        if(pause_free.exchange(false)){free_entered.signal();free_resume.wait();}
        {std::lock_guard lock(mutex);if(render)++callback_free;auto it=std::find_if(records.begin(),records.end(),[&](const auto& r){return r.p==p;});
            if(it==records.end()||it->bytes!=bytes||it->alignment!=alignment)std::terminate();
            *it={};live-=bytes;++frees;}
        heap.deallocate(p,bytes,alignment);
    }
};
b::Config config(const std::shared_ptr<Source>& source,std::size_t bytes=64u*1024u*1024u,std::size_t assets=128){b::Config c;c.allocation_source=source;c.max_asset_bytes=bytes;c.max_assets=assets;return c;}
b::Result<b::CapturedBank> capture(b::Session& s,const b::Submission& token,const InputBank& bytes){
    auto result=s.capture(token,{bytes.hd.size(),bytes.bd.size(),bytes.tq.size()});
    if(result.status==b::Status::ok){std::copy(bytes.hd.begin(),bytes.hd.end(),result.value.hd().begin());std::copy(bytes.bd.begin(),bytes.bd.end(),result.value.bd().begin());std::copy(bytes.tq.begin(),bytes.tq.end(),result.value.tq().begin());}return result;
}
b::Result<b::PreparedBank> prepare(b::Session& s,const b::Submission& token,const InputBank& bytes){auto c=capture(s,token,bytes);if(c.status!=b::Status::ok)return {c.status,{}};return s.prepare(token,std::move(c.value));}
void empty(const std::shared_ptr<const b::Budget>& budget,const std::shared_ptr<Source>& source){auto snap=budget->snapshot();check(snap.bytes==0&&snap.assets==0&&source->live==0);}
struct Gains final:b::GainProvider {float gain(unsigned,unsigned,std::uint64_t)noexcept override{return 1;}};
void mix(b::Session& s,const std::shared_ptr<Source>& source,unsigned frames){
    std::array<float,400> output{};Gains gains;source->render=true;const auto status=s.mix_add(output.data(),frames,gains);source->render=false;ok(status);check(source->callback_alloc==0&&source->callback_free==0);
}
void apply(b::Session& s,b::Command c){auto r=s.apply({&c,1});ok(r.status);check(r.applied==1);}
void tests(){
    const auto input=bank();
    std::size_t exactCapture{},preparePeak{},preparationCalls{};
    {
        auto source=std::make_shared<Source>();b::Session s(config(source));auto observer=s.budget_observer();auto token=take(s.begin_submission());
        {auto raw=take(capture(s,token,input));auto snap=observer->snapshot();exactCapture=snap.bytes;check(snap.bytes==source->live&&snap.assets==1);}
        empty(observer,source);
        const auto before=source->calls;
        {auto asset=take(prepare(s,token,input));auto snap=observer->snapshot();preparePeak=snap.peak_bytes;preparationCalls=source->calls-before;check(snap.bytes==source->live&&snap.assets==1);}
        empty(observer,source);check(preparePeak==source->peak);token={};check(s.join());
    }
    {
        auto source=std::make_shared<Source>();b::Session s(config(source,1));auto token=take(s.begin_submission());check(capture(s,token,input).status==b::Status::capacity);
        check(source->calls==0);empty(s.budget_observer(),source);token={};check(s.join());
    }
    for(auto limit:{exactCapture-1,exactCapture}){
        auto source=std::make_shared<Source>();b::Session s(config(source,limit));auto token=take(s.begin_submission());
        {auto raw=capture(s,token,input);check(raw.status==(limit==exactCapture?b::Status::ok:b::Status::capacity));}
        empty(s.budget_observer(),source);check(s.budget_observer()->snapshot().peak_bytes<=limit);token={};check(s.join());
    }
    for(auto limit:{preparePeak-1,preparePeak}){
        auto source=std::make_shared<Source>();b::Session s(config(source,limit));auto token=take(s.begin_submission());
        {auto asset=prepare(s,token,input);check(asset.status==(limit==preparePeak?b::Status::ok:b::Status::capacity));}
        empty(s.budget_observer(),source);check(s.budget_observer()->snapshot().peak_bytes<=limit);token={};check(s.join());
    }
    {
        auto source=std::make_shared<Source>();b::Session s(config(source,64u*1024u*1024u,1));auto token=take(s.begin_submission());
        auto first=take(capture(s,token,input));const auto calls=source->calls;check(capture(s,token,input).status==b::Status::capacity&&source->calls==calls);
        first={};empty(s.budget_observer(),source);auto asset=take(prepare(s,token,input));ok(s.install(token,3,asset));
        check(capture(s,token,input).status==b::Status::capacity);check(s.snapshot().ports[3].fingerprint==asset.fingerprint());
        ok(s.reset());check(s.budget_observer()->snapshot().assets==1);asset={};empty(s.budget_observer(),source);token={};check(s.join());
    }
    // Every allocation failure is injected through the owned upstream source,
    // without a TLS/global allocator override. No install occurs after refusal.
    for(std::size_t at=0;at<preparationCalls;++at){
        auto source=std::make_shared<Source>();source->fail_at=at;b::Session s(config(source));auto token=take(s.begin_submission());
        {auto result=prepare(s,token,input);check(result.status==b::Status::no_memory||result.status==b::Status::ok);if(at<source->calls)check(result.status==b::Status::no_memory);}
        empty(s.budget_observer(),source);check(!s.snapshot().ports[0].loaded);token={};check(s.join());
    }
    {
        auto source=std::make_shared<Source>();b::Session s(config(source));auto token=take(s.begin_submission());auto bad=input;bad.hd[0]=0;
        check(prepare(s,token,bad).status==b::Status::invalid_asset);empty(s.budget_observer(),source);
        auto raw=take(capture(s,token,input));b::Session other;auto otherToken=take(other.begin_submission());check(other.prepare(otherToken,std::move(raw)).status==b::Status::invalid_asset);
        empty(s.budget_observer(),source);otherToken={};check(other.join());token={};check(s.join());
    }
    // In-flight reserved bytes count before upstream allocation returns. A
    // concurrent reset invalidates the capture, which refunds both domains.
    {
        auto source=std::make_shared<Source>();b::Session s(config(source,64u*1024u*1024u,1));source->pause_next=true;b::Status result{};
        std::thread worker([&]{auto token=take(s.begin_submission());result=capture(s,token,input).status;});
        source->entered.wait();auto snap=s.budget_observer()->snapshot();check(snap.assets==1&&snap.bytes>0&&source->live==0);
        auto second=take(s.begin_submission());check(capture(s,second,input).status==b::Status::capacity);ok(s.reset());second={};source->resume.signal();worker.join();
        check(result==b::Status::stale_generation);empty(s.budget_observer(),source);check(s.join());
    }
    {
        auto source=std::make_shared<Source>();b::Session s(config(source));auto token=take(s.begin_submission());auto raw=take(capture(s,token,input));source->pause_next=true;b::Status result{};
        std::thread worker([&]{result=s.prepare(token,std::move(raw)).status;});source->entered.wait();ok(s.reset());source->resume.signal();worker.join();
        check(result==b::Status::stale_generation);empty(s.budget_observer(),source);token={};check(s.join());
    }
    {
        auto source=std::make_shared<Source>();b::Session s(config(source));auto token=take(s.begin_submission());auto first=take(prepare(s,token,input));ok(s.install(token,0,first));first={};
        apply(s,b::StartRequest{0,0,0});mix(s,source,1);auto replacement=take(prepare(s,token,input));ok(s.install(token,0,replacement));
        check(s.budget_observer()->snapshot().assets==2);mix(s,source,199);check(s.snapshot().retired_clips==1&&s.budget_observer()->snapshot().assets==2);
        const auto frees=source->frees;ok(s.drain_retired());check(s.budget_observer()->snapshot().assets==1&&source->frees>frees);
        apply(s,b::StartRequest{0,0,0});mix(s,source,1);apply(s,b::StopAll{});mix(s,source,199);
        token={};check(s.join());check(s.budget_observer()->snapshot().assets==1);replacement={};empty(s.budget_observer(),source);
    }
    // The resource and upstream survive Session/asset OBJECT destruction until
    // the final weak shared-control-block deallocation, too.
    {
        auto source=std::make_shared<Source>();auto budget=std::make_shared<b::Budget>(65536,1,source);auto lease=b::acquire_asset(budget);
        auto clip=std::allocate_shared<b::detail::DecodedSample>(b::AssetAllocator<b::detail::DecodedSample>(lease),lease);clip->pcm.resize(64);
        std::weak_ptr<const b::detail::DecodedSample> weak=clip;std::weak_ptr<const b::Budget> weakBudget=budget;std::weak_ptr<Source> weakSource=source;
        lease={};clip={};check(budget->snapshot().assets==1&&budget->snapshot().bytes==source->live);budget={};source={};check(!weakBudget.expired()&&!weakSource.expired());
        weak.reset();check(weakBudget.expired()&&weakSource.expired());
    }
    {
        auto source=std::make_shared<Source>();auto budget=std::make_shared<b::Budget>(65536,1,source);auto lease=b::acquire_asset(budget);
        source->pause_free=true;std::thread worker([&]{lease.reset();});source->free_entered.wait();
        check(budget->snapshot().assets==1&&budget->snapshot().bytes==source->live);
        bool refused=false;try{auto extra=b::acquire_asset(budget);(void)extra;}catch(const b::BudgetExceeded&){refused=true;}
        check(refused);source->free_resume.signal();worker.join();empty(budget,source);
    }
    {
        auto source=std::make_shared<Source>();b::PreparedBank retained;std::shared_ptr<const b::Budget> observer;
        {b::Session s(config(source));observer=s.budget_observer();auto token=take(s.begin_submission());retained=take(prepare(s,token,input));token={};check(s.join());}
        check(observer->snapshot().assets==1&&observer->snapshot().bytes==source->live);retained={};empty(observer,source);
    }
    // Concurrent successful and refused preparations share one real bound.
    {
        auto source=std::make_shared<Source>();b::Session s(config(source,preparePeak*2,3));std::atomic<unsigned> accepted{},refused{};std::atomic<bool> failed{};
        std::array<std::thread,8> workers;for(auto& worker:workers)worker=std::thread([&]{for(unsigned n=0;n<24;++n){auto token=s.begin_submission();if(token.status!=b::Status::ok){failed=true;return;}auto r=prepare(s,token.value,input);if(r.status==b::Status::ok)++accepted;else if(r.status==b::Status::capacity)++refused;else failed=true;}});
        for(auto& worker:workers)worker.join();
        check(!failed&&accepted+refused==192&&accepted>0);auto snap=s.budget_observer()->snapshot();check(snap.peak_assets<=3&&snap.peak_bytes<=preparePeak*2);
        empty(s.budget_observer(),source);check(s.join());
    }
}
int main()try{tests();std::cout<<"budget_v2 assertions="<<assertions.load()<<"\n";return 0;}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
