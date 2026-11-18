#include "session.hpp"
#include <atomic>
#include <cmath>
#include <condition_variable>
#include <cstdlib>
#include <iostream>
#include <mutex>
#include <new>
#include <stdexcept>
#include <thread>

namespace b=reo::native::audio_banks;
struct Event {
    std::mutex mutex;std::condition_variable cv;bool value{};
    void signal(){std::lock_guard lock(mutex);value=true;cv.notify_all();}
    void wait(){std::unique_lock lock(mutex);cv.wait(lock,[&]{return value;});}
};
thread_local bool render_guard{},pause_next_new{};
std::atomic<unsigned> render_allocations{},render_deallocations{},total_deallocations{};
Event allocation_entered,allocation_release;
void* operator new(std::size_t size){
    if(render_guard)++render_allocations;
    if(pause_next_new){pause_next_new=false;allocation_entered.signal();allocation_release.wait();}
    if(void* result=std::malloc(size?size:1))return result;
    throw std::bad_alloc();
}
void* operator new[](std::size_t n){return ::operator new(n);}
void operator delete(void* p) noexcept{if(p){++total_deallocations;if(render_guard)++render_deallocations;}std::free(p);}
void operator delete[](void* p) noexcept{::operator delete(p);}
void operator delete(void* p,std::size_t) noexcept{::operator delete(p);}
void operator delete[](void* p,std::size_t) noexcept{::operator delete(p);}
std::atomic<unsigned> assertions{};
void check(bool condition){const auto n=++assertions;if(!condition)throw std::runtime_error("bank session assertion "+std::to_string(n));}
void ok(b::Status status){check(status==b::Status::ok);}
template<class T>T take(b::Result<T> result){ok(result.status);return std::move(result.value);}
void word16(std::vector<std::uint8_t>& d,std::size_t at,unsigned v){d.at(at)=v&255;d.at(at+1)=(v>>8)&255;}
void word32(std::vector<std::uint8_t>& d,std::size_t at,unsigned v){for(unsigned n=0;n<4;++n)d.at(at+n)=(v>>(n*8))&255;}
void tag(std::vector<std::uint8_t>& d,std::size_t at,const char* value){for(unsigned n=0;n<4;++n){d.at(at+n)=std::uint8_t("SCEI"[3-n]);d.at(at+4+n)=std::uint8_t(value[3-n]);}}
// Synthetic inputs only. No expected output is computed by a second mixer.
b::OwnedBankBytes bank(unsigned notes=1,unsigned regions=1,unsigned layers=1){
    b::OwnedBankBytes bytes;bytes.hd.resize(0x1800);bytes.bd.resize(32);bytes.tq.resize(0x20+notes*2+8);
    tag(bytes.hd,0,"Vers");tag(bytes.hd,0x10,"Head");
    const unsigned chunks[]{0x40,0xc0,0x140,0x1c0};const char* names[]{"Prog","Sset","Smpl","Vagi"};
    for(unsigned n=0;n<4;++n){word32(bytes.hd,0x24+n*4,chunks[n]);tag(bytes.hd,chunks[n],names[n]);word32(bytes.hd,chunks[n]+16,0x20);}
    const unsigned pr=0x60,ss=0xe0,sm=0x160,va=0x1e0;
    word32(bytes.hd,pr,0x300-pr);bytes.hd[pr+4]=std::uint8_t(regions);bytes.hd[pr+6]=127;bytes.hd[pr+7]=64;
    for(unsigned n=0;n<regions;++n){const auto at=0x300+n*20;bytes.hd[at+3]=64;bytes.hd[at+4]=127;bytes.hd[at+16]=127;bytes.hd[at+17]=64;}
    bytes.hd[ss+2]=127;bytes.hd[ss+3]=std::uint8_t(layers);
    // Large Sset sample lists use a separate record beyond all region data.
    if(layers>1){word32(bytes.hd,0xc0+16,0x1700-0xc0);bytes.hd[0x1702]=127;bytes.hd[0x1703]=std::uint8_t(layers);bytes.hd.resize(0x1904);}
    bytes.hd[sm+3]=64;bytes.hd[sm+4]=127;bytes.hd[sm+0xb]=62;bytes.hd[sm+0xd]=64;bytes.hd[sm+0x10]=127;word16(bytes.hd,sm+0x14,0x1fc0);
    word16(bytes.hd,va+4,48000);
    for(unsigned at:{0u,16u}){bytes.bd[at]=12;bytes.bd[at+1]=at?3:4;for(unsigned n=2;n<16;++n)bytes.bd[at+n]=0x77;}
    word16(bytes.tq,14,1);word32(bytes.tq,16,0x40000020);
    bytes.tq[0x20]=0xe0;bytes.tq[0x21]=127;bytes.tq[0x22]=0xe2;bytes.tq[0x23]=0;
    for(unsigned n=0;n<notes;++n){bytes.tq[0x24+n*2]=0xb2;bytes.tq[0x25+n*2]=127;}
    bytes.tq[0x24+notes*2]=0xff;return bytes;
}
struct Gains final:b::GainProvider {
    unsigned reads{};float value{1};b::Session* self{};bool self_join{},join_result{true};
    float gain(unsigned,unsigned,std::uint64_t) noexcept override{
        ++reads;if(self_join){self_join=false;join_result=self->join();}return value;
    }
};
void apply(b::Session& s,b::Command command){const auto result=s.apply({&command,1});ok(result.status);check(result.applied==1);}
void guarded_mix(b::Session& s,float* output,unsigned frames,Gains& gains){
    const auto allocations=render_allocations.load(),deallocations=render_deallocations.load();render_guard=true;
    const auto status=s.mix_add(output,frames,gains);render_guard=false;
    ok(status);check(render_allocations==allocations&&render_deallocations==deallocations);
}
void tests(){
    {
        b::Session s;auto submission=take(s.begin_submission());auto caller_bytes=bank();auto asset=take(s.prepare(submission,caller_bytes));
        const auto fingerprint=asset.fingerprint();caller_bytes.hd[0]=0;caller_bytes.bd[2]=0;caller_bytes.tq[0x20]=0xff;
        check(asset.fingerprint()==fingerprint);
        check(asset&&asset.sequence_count()==1);ok(s.install(submission,2,asset));
        check(s.prepare(submission,std::move(caller_bytes)).status==b::Status::invalid_asset&&s.snapshot().ports[2].fingerprint==fingerprint);
        check(s.install(submission,2,b::PreparedBank{},b::LoadPolicy::if_unloaded)==b::Status::skipped);
        apply(s,b::StartRequest{2,0,3});check(take(s.sequence_state(2,0,3))==1);
        Gains gains;std::array<float,400> output{};
        ok(s.mix_add(nullptr,200,gains));ok(s.mix_add(output.data(),0,gains));check(gains.reads==0&&s.snapshot().frame_clock==0);
        guarded_mix(s,output.data(),1,gains);check(gains.reads==224&&std::isfinite(output[0])&&output[0]>0);
        apply(s,b::SetMuted{true});const auto before=s.snapshot().frame_clock;output.fill(.25f);
        guarded_mix(s,output.data(),200,gains);check(s.snapshot().frame_clock==before+200&&output[0]==.25f);
        apply(s,b::CancelRequest{2,0,3});check(take(s.sequence_state(2,0,3))==0);
        guarded_mix(s,output.data(),200,gains);check(s.snapshot().voice_count==0);
        submission={};check(s.join());
    }
    {
        b::Session s;auto token=take(s.begin_submission());auto original=take(s.prepare(token,bank()));ok(s.install(token,2,original));
        apply(s,b::StartRequest{2,0,0});Gains gains;std::array<float,400> output{};guarded_mix(s,output.data(),1,gains);
        original={};auto replacement=take(s.prepare(token,bank()));ok(s.install(token,2,replacement));
        guarded_mix(s,output.data(),199,gains);check(s.snapshot().retired_clips==1&&s.snapshot().voice_count==0);
        const auto freed=total_deallocations.load();ok(s.drain_retired());check(s.snapshot().retired_clips==0&&total_deallocations>freed);
        // Current-cache releases never destroy PCM/control blocks in mix.
        apply(s,b::StartRequest{2,0,0});guarded_mix(s,output.data(),1,gains);apply(s,b::StopAll{});
        guarded_mix(s,output.data(),199,gains);check(s.snapshot().retired_clips==0);
        token={};check(s.join());
    }
    {
        b::Session s;auto token=take(s.begin_submission());auto asset=take(s.prepare(token,bank(48)));ok(s.install(token,0,asset));
        apply(s,b::StartRequest{});Gains gains;std::array<float,400> output{};guarded_mix(s,output.data(),1,gains);check(s.snapshot().voice_count==48);
        asset={};auto next=take(s.prepare(token,bank(48)));ok(s.install(token,0,next));guarded_mix(s,output.data(),199,gains);check(s.snapshot().retired_clips==48);
        // Replacement drains the full retirement budget atomically before it
        // creates another old-asset generation. No render-side heap reclamation.
        auto third=take(s.prepare(token,bank(48)));ok(s.install(token,0,third));check(s.snapshot().retired_clips==0);
        apply(s,b::StartRequest{});guarded_mix(s,output.data(),1,gains);next={};third={};
        auto fourth=take(s.prepare(token,bank()));ok(s.install(token,0,fourth));guarded_mix(s,output.data(),199,gains);check(s.snapshot().retired_clips==48);
        token={};check(s.join());
    }
    {
        b::Session s;auto token=take(s.begin_submission());auto asset=take(s.prepare(token,bank(1,255,255)));ok(s.install(token,0,asset));apply(s,b::StartRequest{});
        Gains gains;float output[2]{};guarded_mix(s,output,1,gains);check(s.snapshot().voice_count==48&&s.snapshot().diagnostics.unsupported==65025-48);
        token={};check(s.join());
    }
    {
        // 1022 notes plus two setup commands fill the1024-command loop; its
        // terminal Unsupported adds the1025th Event. All scratch is preowned.
        b::Session s;auto token=take(s.begin_submission());auto asset=take(s.prepare(token,bank(1022)));ok(s.install(token,0,asset));apply(s,b::StartRequest{});
        Gains gains;float output[2]{};guarded_mix(s,output,1,gains);check(s.snapshot().diagnostics.event_count==32);
        token={};check(s.join());
    }
    {
        b::Session s,foreign;auto token=take(s.begin_submission());auto asset=take(s.prepare(token,bank()));
        auto foreign_token=take(foreign.begin_submission());check(foreign.install(foreign_token,0,asset)==b::Status::invalid_asset);
        ok(s.reset());check(s.install(token,0,asset)==b::Status::stale_generation);
        check(s.apply(token,{}).status==b::Status::stale_generation);
        auto fresh=take(s.begin_submission());check(s.install(fresh,0,asset)==b::Status::stale_generation);
        token={};fresh={};foreign_token={};check(s.join()&&foreign.join());
    }
    {
        b::Session s;auto submission=take(s.begin_submission());auto bytes=bank();b::Status prepared{};
        std::thread producer([&]{pause_next_new=true;prepared=s.prepare(submission,std::move(bytes)).status;});
        allocation_entered.wait();ok(s.reset());allocation_release.signal();producer.join();check(prepared==b::Status::stale_generation);
        submission={};check(s.join());
    }
    {
        b::Config config;config.max_submissions=1;b::Session s(config);auto first=take(s.begin_submission());
        check(s.begin_submission().status==b::Status::capacity);std::atomic<bool> joined{};Event started;
        std::thread control([&]{s.request_stop();started.signal();check(s.join());joined=true;});started.wait();
        check(s.begin_submission().status==b::Status::closed&&!joined);first={};control.join();check(joined);
    }
    {
        b::Session s;std::array<b::Command,2> commands{b::SetMuted{true},b::SetPortVolume{99,10}};
        auto result=s.apply(commands);check(result.status==b::Status::invalid_input&&result.applied==1&&s.snapshot().muted);
        Gains gains;gains.value=std::numeric_limits<float>::quiet_NaN();float output[2]{.3f,.4f};
        check(s.mix_add(output,1,gains)==b::Status::unsupported_gain&&output[0]==.3f&&gains.reads==224);check(s.join());
    }
    {
        b::Session s;Gains gains;gains.self=&s;gains.self_join=true;float output[2]{};
        ok(s.mix_add(output,1,gains));check(!gains.join_result&&s.begin_submission().status==b::Status::closed);check(s.join());
    }
}
int main(){try{tests();std::cout<<assertions<<" bank session assertions; zero guarded render allocations/deallocations\n";return 0;}
catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}}
