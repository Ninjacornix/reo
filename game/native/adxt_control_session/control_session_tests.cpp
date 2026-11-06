#include "control_session.hpp"
#include "../adxt_shared_player/test_sources.hpp"
#include "../adxt_player/test_provider.hpp"
#include <array>
#include <iostream>
#include <thread>

namespace c=reo::native::adxt_control_session;
namespace f=reo::native::adxt_shared_player::testing;
unsigned checks{};void check(bool b){++checks;if(!b)throw std::runtime_error("Control session check "+std::to_string(checks));}
struct Test {
    std::shared_ptr<reo::audio_output::CallbackSlot> slot=std::make_shared<reo::audio_output::CallbackSlot>();
    std::shared_ptr<reo::native::adxt_player::testing::Provider> provider=std::make_shared<reo::native::adxt_player::testing::Provider>();
    c::Session session;
    explicit Test(unsigned streams=2):session({{streams},{}},slot,provider){check(session.start()==c::Status::completed);}
};
c::player::Config config(const std::shared_ptr<const reo::native::resources::ByteView>& file,unsigned channels){c::player::Config v;v.decoder.channels=channels;v.decoder.source_config.byte_length=static_cast<std::int32_t>(file->size());return v;}
c::Key open(Test& t,std::shared_ptr<const reo::native::resources::ByteView> file,unsigned channels,c::Indices indices){auto result=t.session.open(config(file,channels),file,indices);check(result.status==c::Status::completed);return result.key;}
c::Retirement retire(Test& t,const c::Key& key){for(unsigned i=0;i<100000;++i){auto r=t.session.retire(key);if(r.status==c::Status::completed){check(r.source_joined && r.evidence.output_retired && r.evidence.decoder.source.joined);return r;}check(r.status==c::Status::pending);std::this_thread::yield();}throw std::runtime_error("Retirement bound");}
int main(){try{
    {
        Test t,foreign;auto file=f::file(1,48000,8192);auto key=open(t,file,1,{15,2,9,31});
        check(t.session.inspect({}).status==c::Status::invalid_key && foreign.session.inspect(key).status==c::Status::invalid_key);
        check(t.session.open(config(file,1),file,{0,2,0,0}).status==c::Status::occupied);
        check(t.session.open(config(file,1),file,{16,0,0,0}).status==c::Status::invalid_indices);
        auto bad=config(file,1);bad.decoder.downmix=true;check(t.session.open(bad,file,{1,3,4,5}).status==c::Status::unsupported_profile);
        check(t.session.snapshot().records==1 && t.session.snapshot().output.occupied==1 && file->reads==0);
        retire(t,key);check(t.session.inspect(key).status==c::Status::invalid_key && t.session.estimate(key,0).status==c::Status::invalid_key);
        auto replacement=open(t,file,1,{15,2,9,31});check(t.session.pause(key,1,0).status==c::Status::invalid_key);retire(t,replacement);
        check(t.session.join()==c::Status::completed && t.session.join()==c::Status::completed && t.provider->unloads==1);
        check(t.session.open(config(file,1),file,{0,0,0,0}).status==c::Status::closed && t.session.service(0)==c::Status::closed);
        check(foreign.session.join()==c::Status::completed);
    }
    unsigned matrix{};
    for(unsigned channels:{1u,2u})for(unsigned rate:{24000u,44100u,48000u})for(unsigned total:{1u,31u,32u,36u,128u,4096u,8193u,20000u}){
        Test t;auto file=f::file(channels,rate,total);auto key=open(t,file,channels,{15,0,11,31});bool ended=false;
        for(unsigned i=0;i<500000;++i){check(t.session.service(0)==c::Status::completed);const auto state=t.session.inspect(key);check(state.status==c::Status::completed && !state.evidence.fault);
            if(state.evidence.playback.phase==reo::native::adxt_playback::Phase::ended && state.evidence.configured){ended=true;break;}
            if(state.evidence.output.channel[0].samples>=512)t.provider->step(512);
            if(state.evidence.decoder.source.in_flight)std::this_thread::yield();}
        check(ended);const auto raw=t.session.estimate(key,0);check(raw.status==c::Status::completed && raw.value.result.ratio.numerator==total && raw.value.result.ratio.denominator==rate);
        const auto state=t.session.inspect(key).evidence;check(state.first_payload_samples==total && state.output.channel[0].consumed_bytes/2>=total && !state.output.voice.skipped_samples);
        auto report=t.session.snapshot();check(!report.output.statistics.underrun_frames && report.dtx_scans==report.group_visits*2 && !report.service_busy && !report.guard_fault);
        retire(t,key);check(t.session.join()==c::Status::completed);++matrix;
    }
    {
        Test t(4);std::array<std::shared_ptr<f::File>,3> files{f::file(1,48000,120000),f::file(2,48000,120000),f::file(1,48000,120000)};
        std::array<c::Key,3> keys{open(t,files[0],1,{15,1,8,31}),open(t,files[1],2,{0,15,3,0}),open(t,files[2],1,{7,6,15,17})};
        check(t.session.service(0)==c::Status::order_required && !files[0]->reads && !files[1]->reads && !files[2]->reads);
        std::array<c::Key,3> duplicate{keys[0],keys[0],keys[2]};check(t.session.set_order(duplicate)==c::Status::invalid_key);
        std::array<c::Key,3> order{keys[2],keys[0],keys[1]};check(t.session.set_order(order)==c::Status::completed);
        auto bad=config(files[0],1);bad.decoder.downmix=true;check(t.session.open(bad,files[0],{2,2,2,2}).status==c::Status::unsupported_profile);
        check(!t.session.snapshot().order_required && t.session.snapshot().output.occupied==3 && !t.session.snapshot().output.order_required);
        bool playing=false;for(unsigned i=0;i<100000;++i){check(t.session.service(0)==c::Status::completed);bool all=true;for(const auto& key:keys){const auto s=t.session.inspect(key).evidence;all&=s.output.voice.playing && s.output.channel[0].samples>=2048;}if(all){playing=true;break;}std::this_thread::yield();}check(playing);
        check(t.session.pause(keys[0],1,33).status==c::Status::completed);const auto own=t.session.inspect(keys[0]).evidence.output.channel[0].consumed_bytes,peer=t.session.inspect(keys[1]).evidence.output.channel[0].consumed_bytes;
        t.provider->step(512);check(t.session.inspect(keys[0]).evidence.output.channel[0].consumed_bytes==own && t.session.inspect(keys[1]).evidence.output.channel[0].consumed_bytes>peer);
        check(t.session.pause(keys[0],2,44).status==c::Status::completed);t.provider->step(512);check(t.session.inspect(keys[0]).evidence.output.channel[0].consumed_bytes>own);
        retire(t,keys[0]);check(t.session.snapshot().records==2 && !t.provider->unloaded);retire(t,keys[1]);retire(t,keys[2]);
        t.provider->fail_detach=1;check(t.session.join()==c::Status::pending && !t.session.snapshot().joined);check(t.session.join()==c::Status::completed && t.provider->unloads==1);
    }
    {
        Test t;auto blocked=std::make_shared<f::Blocked>();blocked->bytes=f::file(1,48000,80000)->bytes;
        auto key=open(t,blocked,1,{0,0,0,0});auto peer=open(t,f::file(1,48000,120000),1,{1,1,1,1});
        struct Release{std::shared_ptr<f::Blocked> file;~Release(){std::lock_guard lock(file->mutex);file->released=true;file->cv.notify_all();}}release{blocked};
        bool ready=false;for(unsigned i=0;i<100000;++i){check(t.session.service(0)==c::Status::completed);bool entered;{std::lock_guard lock(blocked->mutex);entered=blocked->entered;}
            const auto s=t.session.inspect(peer).evidence;if(entered && s.output.voice.playing && s.output.channel[0].samples>=2048){ready=true;break;}std::this_thread::yield();}check(ready);
        const auto pending=t.session.retire(key);check(pending.status==c::Status::pending && !pending.source_joined && t.session.snapshot().retiring==1);
        check(t.session.open(config(blocked,1),blocked,{0,0,0,0}).status==c::Status::occupied);
        const auto before=t.session.inspect(peer).evidence.output.channel[0].consumed_bytes;t.provider->step(512);check(t.session.inspect(peer).evidence.output.channel[0].consumed_bytes>before && !t.provider->unloaded);
        check(t.session.service(0)==c::Status::completed);
        {std::lock_guard lock(blocked->mutex);blocked->released=true;blocked->cv.notify_all();}retire(t,key);retire(t,peer);check(t.session.join()==c::Status::completed);
    }
    std::cout<<checks<<" native media control checks; finite matrix="<<matrix<<"\n";return 0;
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}}
