#include "session_bridge.hpp"
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <cstdlib>
#include <iostream>
#include <mutex>
#include <new>
#include <stdexcept>
#include <thread>

static std::atomic<std::size_t> allocations{};
void* operator new(std::size_t n){++allocations;if(auto* p=std::malloc(n?n:1))return p;throw std::bad_alloc();}
void* operator new[](std::size_t n){return ::operator new(n);}
void operator delete(void* p) noexcept{std::free(p);}
void operator delete[](void* p) noexcept{std::free(p);}
void operator delete(void* p,std::size_t) noexcept{std::free(p);}
void operator delete[](void* p,std::size_t) noexcept{std::free(p);}
namespace b=reo::native::pcm_bridge;
std::atomic<unsigned> assertions{};
void check(bool value){const auto n=++assertions;if(!value)throw std::runtime_error("bridge assertion "+std::to_string(n));}
void ok(b::Status value){check(value==b::Status::ok);}
struct Host final:b::Host {
    std::int64_t now{};
    unsigned polls{},ensures{},gain_reads{},mixes{},masters{},routes{},banks{};
    std::atomic<unsigned> fences{};
    bool ready{},fence{true},reenter_ensure{},pause_mix{},mix_entered{},allow_mix{},reenter_shutdown{};
    float stream{1},master{1},bank_add{};
    b::Session* session{};
    b::Status self_shutdown{b::Status::ok},after_close{b::Status::ok};
    std::mutex mutex;
    std::condition_variable changed;
    std::int64_t now_ns() noexcept override{return now;}
    void poll_settings() noexcept override{++polls;}
    void ensure_output() noexcept override{
        ++ensures;
        if(reenter_ensure){reenter_ensure=false;self_shutdown=session->render(nullptr,0);}
    }
    bool output_ready() noexcept override{return ready;}
    float stream_gain(std::uint32_t) noexcept override{++gain_reads;return stream;}
    void mix_banks(float* p,std::uint32_t frames) noexcept override{
        ++mixes;
        if(p)for(std::size_t n=0;n<std::size_t(frames)*2;++n)p[n]+=bank_add;
        if(reenter_shutdown)self_shutdown=session->shutdown();
        if(pause_mix){
            std::unique_lock lock(mutex);mix_entered=true;changed.notify_all();
            while(!allow_mix)changed.wait(lock);
        }
    }
    float master_gain() noexcept override{++masters;return master;}
    void reset_stream_routes() noexcept override{++routes;}
    bool stop_join_output() noexcept override{
        ++fences;
        if(session){self_shutdown=session->shutdown();after_close=session->ensureHostOutput();}
        return fence;
    }
    void reset_banks() noexcept override{++banks;}
};
void tests(){
    {
        auto host=std::make_shared<Host>();b::Session s(host);host->session=&s;
        auto admission=s.pre_run_state();check(admission.before_first_operation&&admission.healthy&&admission.admission_open&&!admission.complete_runtime_installation_proved);
        std::array<std::uint8_t,2> bytes{0,64};std::uint64_t end=123;
        check(s.queue(0,bytes.data(),2,end)==b::Status::invalid_input);
        check(end==123&&!host->ensures&&!host->polls&&!s.pre_run_state().before_first_operation);
        ok(s.ensureHostOutput());check(host->polls==1&&host->ensures==1);
        host->reenter_ensure=true;ok(s.queue(1,bytes.data(),2,end));
        check(host->self_shutdown==b::Status::ok&&s.clock().frame_clock&&end==2);
        ok(s.configure(0,1,0,1,48000,256,true));
        host->stream=.5f;host->bank_add=.25f;host->master=2;
        std::array<float,2> pcm{};ok(s.render(pcm.data(),1));
        check(pcm[0]==1&&pcm[1]==1&&host->masters==2);
        auto frames=s.statistics().output_frames;
        ok(s.reset());check(s.statistics().output_frames==frames&&host->routes==1&&!host->banks&&!host->fences);
        host->ready=true;host->now=1000000000;
        ok(s.configure(0,1,0,1,48000,256,true));
        check(s.statistics().output_frames==frames&&s.clock().last_tick_ns==0);
        host->ready=false;const auto gains=host->gain_reads;
        ok(s.configure(2,2,0,1,48000,256,true));
        check(s.statistics().output_frames==frames+12000&&s.clock().last_tick_ns==250000000&&host->gain_reads==gains+1);
        auto queried=s.consumed(999);ok(queried.status);check(queried.value==0&&s.statistics().output_frames==frames+24000);
        host->fence=false;check(s.shutdown()==b::Status::output_fence_required);
        check(host->self_shutdown==b::Status::reentrant_shutdown&&host->after_close==b::Status::closed&&host->routes==1&&!host->banks);
        std::array<std::uint32_t,64> order{};check(s.copy_order(order).value==2);
        host->fence=true;ok(s.shutdown());check(host->routes==2&&host->banks==1&&s.copy_order(order).value==0);
        ok(s.shutdown());check(host->fences==2&&host->banks==1);
        check(s.reset()==b::Status::closed);
    }
    {
        auto host=std::make_shared<Host>();b::Domain d;d.max_channels=2;d.max_voices=2;b::Session s(host,d);
        ok(s.configure(0,1,0,1,0,UINT32_MAX,true));
        check(!s.inspect_channel(1).source_visible&&s.inspect_voice(0).info.frequency==48000);
        ok(s.configure(1,1,2,2,48000,256,true));
        check(s.configure(2,1,0,1,48000,256,true)==b::Status::domain_capacity);
        check(s.configure(1,3,0,1,48000,256,true)==b::Status::domain_capacity);
        check(s.configure(1,1,1,2,48000,256,true)==b::Status::unsupported_alias);
        ok(s.release(1));
        // Channels remain retained even when their referencing voice is gone.
        check(s.configure(2,3,0,1,48000,256,true)==b::Status::domain_capacity);
        ok(s.reset());ok(s.configure(2,3,0,1,48000,256,true));
        ok(s.shutdown());
    }
    {
        auto host=std::make_shared<Host>();b::Domain d;d.max_channels=d.max_voices=32;b::Session s(host,d);
        ok(s.render(nullptr,0));
        const auto before=allocations.load();
        for(unsigned pass=0;pass<100;++pass){
            for(unsigned n=0;n<32;++n)ok(s.configure(n,n+1,0,1,48000,256,true));
            for(unsigned n=0;n<32;++n)ok(s.release(n));
            ok(s.reset());
        }
        check(allocations.load()==before);
        ok(s.shutdown());
    }
    {
        auto host=std::make_shared<Host>();b::Session s(host);host->session=&s;host->reenter_shutdown=true;
        ok(s.render(nullptr,0));check(host->self_shutdown==b::Status::reentrant_shutdown);
        host->reenter_shutdown=false;host->pause_mix=true;
        std::thread render([&]{ok(s.render(nullptr,0));});
        {std::unique_lock lock(host->mutex);while(!host->mix_entered)host->changed.wait(lock);}
        std::atomic<bool> joined{};
        std::thread shutdown([&]{ok(s.shutdown());joined=true;});
        while(s.pre_run_state().admission_open)std::this_thread::yield();
        check(!joined.load()&&!host->fences);
        check(s.render(nullptr,0)==b::Status::closed);
        {std::lock_guard lock(host->mutex);host->allow_mix=true;host->changed.notify_all();}
        render.join();shutdown.join();check(joined&&host->fences==1&&host->banks==1);
    }
    {
        auto host=std::make_shared<Host>();b::Session s(host);ok(s.configure(1,1,0,1,48000,256,true));
        host->stream=9;check(s.render(nullptr,0)==b::Status::unsupported_gain);
        check(!s.pre_run_state().healthy&&!s.pre_run_state().admission_open&&s.statistics().output_frames==0);
        ok(s.shutdown());
    }
}
int main(){try{tests();std::cout<<assertions<<" session bridge assertions passed\n";return 0;}
catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}}
