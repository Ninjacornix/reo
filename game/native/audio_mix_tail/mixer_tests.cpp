#include "mixer.hpp"
#include "../adxt_output_session/session.hpp"
#include "../audio_banks/v2/test_inputs.hpp"
#include "../../../recomp/overrides/native_banks/v3/test_capture.h"
#include <algorithm>
#include <array>
#include <bit>
#include <condition_variable>
#include <cstdio>
#include <cstring>
#include <limits>
#include <mutex>
#include <thread>

namespace m=reo::native::audio_mix_tail;
namespace b=reo::native::audio_banks::v2;
namespace o=reo::native::adxt_output_session;
namespace a=reo::audio_output;
unsigned checks{};
void check(bool value){++checks;if(!value)throw std::runtime_error("Shared bank output check "+std::to_string(checks));}
struct Gains final:b::GainProvider {
    std::uint64_t calls{};float value{1};
    std::array<unsigned,224> ports{};
    std::mutex mutex;std::condition_variable cv;bool block{},entered{},released{};
    float gain(unsigned port,unsigned,std::uint64_t) noexcept override {
        {std::unique_lock lock(mutex);if(block){entered=true;cv.notify_all();cv.wait(lock,[&]{return released;});}}
        ports[calls++%224]=port;return value;
    }
};
struct Master final:m::MasterGain {float value{0.5f};unsigned calls{};float gain() noexcept override{++calls;return value;}};
struct Allocation final:b::AllocationSource {
    b::HeapSource heap;bool rendering{};unsigned callback_alloc{},callback_free{};
    void* allocate(std::size_t n,std::size_t alignment) override {if(rendering)++callback_alloc;return heap.allocate(n,alignment);}
    void deallocate(void* p,std::size_t n,std::size_t alignment) noexcept override {if(rendering)++callback_free;heap.deallocate(p,n,alignment);}
};
struct Provider final:a::Provider {
    std::mutex mutex;a::CallbackSlot* slot{};std::array<float,1024> output{};
    unsigned attaches{},detaches{},stops{},fail_detach{};std::atomic<unsigned> unloads{};
    std::string_view source_sha256()const noexcept override{return a::provider_source_sha256;}
    bool attach(a::CallbackSlot& value) noexcept override{std::lock_guard lock(mutex);++attaches;slot=&value;return true;}
    bool detach() noexcept override {std::lock_guard lock(mutex);++detaches;if(fail_detach){--fail_detach;return false;}slot=nullptr;return true;}
    bool stop() noexcept override{++stops;return true;}bool unload() noexcept override{++unloads;return true;}
    bool render(unsigned frames){std::lock_guard lock(mutex);return slot && slot->dispatch(output.data(),frames);}
};
template<class T>void load(T& target){
    const auto bytes=bank();auto token=target.begin_submission();check(token.status==b::Status::ok);
    auto capture=target.capture(token.value,{bytes.hd.size(),bytes.bd.size(),bytes.tq.size()});check(capture.status==b::Status::ok);
    std::copy(bytes.hd.begin(),bytes.hd.end(),capture.value.hd().begin());std::copy(bytes.bd.begin(),bytes.bd.end(),capture.value.bd().begin());std::copy(bytes.tq.begin(),bytes.tq.end(),capture.value.tq().begin());
    auto prepared=target.prepare(token.value,std::move(capture.value));check(prepared.status==b::Status::ok);
    check(target.install(token.value,0,prepared.value)==b::Status::ok);
    const b::Command start=b::StartRequest{0,0,0};check(target.apply({&start,1}).status==b::Status::ok);
}
std::array<std::byte,1024> plane(std::int16_t value){std::array<std::byte,1024> result{};const auto bits=std::bit_cast<std::uint16_t>(value);
    for(unsigned n=0;n<result.size();n+=2){result[n]=std::byte(bits&255);result[n+1]=std::byte(bits>>8);}return result;}
struct Fixture {
    std::shared_ptr<Gains> gains=std::make_shared<Gains>();std::shared_ptr<Master> master=std::make_shared<Master>();
    std::shared_ptr<Allocation> allocation=std::make_shared<Allocation>();
    std::shared_ptr<m::Mixer> mix;std::shared_ptr<a::CallbackSlot> slot=std::make_shared<a::CallbackSlot>();
    std::shared_ptr<Provider> provider=std::make_shared<Provider>();o::Session output;
    explicit Fixture(std::optional<m::PacketProfile> profile={}):mix(std::make_shared<m::Mixer>(config(),gains,master,profile)),output(o::Config{2,UINT64_MAX,mix},slot,provider){}
    b::Config config(){b::Config c;c.max_render_frames=512;c.allocation_source=allocation;return c;}
    void render(unsigned frames){allocation->rendering=true;const auto ran=provider->render(frames);allocation->rendering=false;check(ran);}
};
int main(){try{
    {
        Fixture f;b::Config config;config.max_render_frames=512;b::Session reference(config);Gains expected;
        load(*f.mix);load(reference);const auto observer=f.mix->budget_observer();check(observer->snapshot().bytes>0);
        auto first=f.output.open(1),second=f.output.open(1);check(first.status==o::Status::completed && second.status==o::Status::completed);
        const auto samples=plane(30000);check(first.producer->copy(samples)==o::Status::completed && second.producer->copy(samples)==o::Status::completed);
        check(first.producer->play(true)==reo::native::adxt_playback::Status::completed && second.producer->play(true)==reo::native::adxt_playback::Status::completed);
        check(f.output.start()==o::Status::completed);f.render(64);
        std::array<float,1024> wanted{};std::fill_n(wanted.begin(),128,1.0f);check(reference.mix_add(wanted.data(),64,expected)==b::Status::ok);
        for(unsigned n=0;n<128;++n)wanted[n]=std::clamp(wanted[n]*0.5f,-1.0f,1.0f);
        check(std::memcmp(wanted.data(),f.provider->output.data(),128*sizeof(float))==0);
        check(f.gains->calls==224 && f.master->calls==1 && f.gains->ports==expected.ports);
        for(unsigned n=0;n<224;++n)check(f.gains->ports[n]==n/16);
        const auto before=f.mix->snapshot().banks.frame_clock;
        check(first.producer->retire()==o::Status::completed && second.producer->retire()==o::Status::completed);
        check(f.provider->detaches==0 && f.output.snapshot().occupied==0 && f.slot->occupied());
        f.render(512);wanted.fill(0);check(reference.mix_add(wanted.data(),512,expected)==b::Status::ok);
        for(auto& value:wanted)value=std::clamp(value*0.5f,-1.0f,1.0f);
        check(std::memcmp(wanted.data(),f.provider->output.data(),sizeof(wanted))==0 && std::any_of(wanted.begin(),wanted.end(),[](float v){return v!=0;}));
        check(f.mix->snapshot().banks.frame_clock>before && !f.allocation->callback_alloc && !f.allocation->callback_free);
        auto other_provider=std::make_shared<Provider>();auto other_slot=std::make_shared<a::CallbackSlot>();bool refused=false;
        try{o::Session other({2,UINT64_MAX,f.mix},other_slot,other_provider);}catch(const std::invalid_argument&){refused=true;}
        check(refused && !other_provider->attaches && !other_slot->occupied() && !f.mix->snapshot().stopping);
        f.provider->fail_detach=1;check(f.output.join()==o::Status::pending);
        check(!f.mix->snapshot().joined && observer->snapshot().bytes>0 && !f.provider->unloads);
        check(f.output.join()==o::Status::completed && f.mix->snapshot().joined && observer->snapshot().bytes==0 && !f.slot->occupied());
        check(f.provider->stops==1 && f.provider->unloads==1 && f.mix->begin_submission().status==b::Status::closed);
        check(reference.join());
    }
    for(bool bank_failure:{false,true}){
        Fixture f;load(*f.mix);check(f.output.start()==o::Status::completed);
        if(bank_failure)f.gains->value=std::numeric_limits<float>::quiet_NaN();else f.master->value=9;
        f.render(64);const auto value=f.mix->snapshot();
        check(value.last_status==(bank_failure?m::Status::bank_failure:m::Status::invalid_master_gain));
        check(f.output.snapshot().render_fault && f.output.snapshot().bank_mix_fault && f.output.snapshot().closing);
        check(std::all_of(f.provider->output.begin(),f.provider->output.begin()+128,[](float v){return v==0;}));
        check(f.master->calls==(bank_failure?0u:1u) && value.bank_failures==unsigned(bank_failure) && value.master_failures==unsigned(!bank_failure));
        check(f.output.join()==o::Status::completed && f.mix->snapshot().joined);
    }
    {
        namespace p=m::packets;
        Fixture f(m::PacketProfile{packet_test::identity(),{}});check(f.mix->begin_submission().status==b::Status::invalid_submission);
        const auto bytes=bank();packet_test::Capture source;source.bank={bytes.hd,bytes.bd,bytes.tq};
        auto call=f.mix->begin_call();check(call.status==p::Status::ok && f.mix->submit_bank(call.value,0,source)==p::Status::ok);
        check(source.group_reads==1 && source.bank_reads==3);
        const std::array<std::uint8_t,6> start{0,0,0,0,0,255};source.packet=start;
        const auto submitted=f.mix->submit_packet(call.value,source);check(submitted.status==p::Status::ok && submitted.parser_accepted && submitted.commands_applied==1);
        call.value={};check(f.output.start()==o::Status::completed);f.render(512);
        check(std::any_of(f.provider->output.begin(),f.provider->output.end(),[](float value){return value!=0;}));
        auto wrong=f.mix->begin_call();source.changed=true;check(f.mix->submit_packet(wrong.value,source).status==p::Status::foreign_runtime);wrong.value={};
        auto held=f.mix->begin_call();check(held.status==p::Status::ok);
        std::atomic<bool> done{};o::Status result=o::Status::fault;
        std::thread closer([&]{result=f.output.join();done=true;});
        while(!f.provider->unloads)std::this_thread::yield();
        const auto early=done.load();const auto retained=f.mix->snapshot();const auto refused=f.mix->begin_call().status;
        held.value={};closer.join();
        check(!early && retained.stopping && !retained.joined && refused==p::Status::closed);
        check(result==o::Status::completed && f.mix->snapshot().joined && f.mix->budget_observer()->snapshot().bytes==0);
    }
    {
        Fixture f;load(*f.mix);check(f.output.start()==o::Status::completed);
        {std::lock_guard lock(f.gains->mutex);f.gains->block=true;}
        bool rendered=false;std::thread callback([&]{rendered=f.provider->render(64);});
        {std::unique_lock lock(f.gains->mutex);f.gains->cv.wait(lock,[&]{return f.gains->entered;});}
        std::atomic<bool> joining{},finished{};o::Status status=o::Status::fault;
        std::thread closer([&]{joining=true;status=f.output.join();finished=true;});
        while(!joining)std::this_thread::yield();
        const auto prematurely_finished=finished.load();
        {std::lock_guard lock(f.gains->mutex);f.gains->released=true;f.gains->cv.notify_all();}
        callback.join();closer.join();
        check(!prematurely_finished && rendered && status==o::Status::completed && f.mix->snapshot().joined);
        check(f.provider->unloads==1 && f.mix->budget_observer()->snapshot().bytes==0);
    }
    std::printf("%u shared stream/bank output checks\n",checks);return 0;
}catch(const std::exception& e){std::fprintf(stderr,"%s\n",e.what());return 1;}}
