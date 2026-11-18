// Compiles the exact marked production worker block, supplied by its runner.
#include "game/native/adxt_control_owner/owner.hpp"
#include "game/native/audio_cue_queue/queue.hpp"
#include "game/native/adxt_shared_player/test_sources.hpp"
#include <algorithm>
#include <array>
#include <atomic>
#include <chrono>
#include <cmath>
#include <condition_variable>
#include <cstdint>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <memory>
#include <mutex>
#include <span>
#include <thread>
#include <vector>
namespace sources=reo::native::adxt_control_owner;
namespace adxt_instances=reo::native::adxt_instances;
namespace f=reo::native::adxt_shared_player::testing;
#include "worker_block.inc"
using namespace std::chrono_literals;
namespace cue=reo::native::audio_cue_queue;
struct QueueFeeds {std::shared_ptr<cue::Queue> queue;bool enabled{};};
std::shared_ptr<QueueFeeds> expected_feeds;
std::atomic<unsigned> checks{},failures{};
void check(bool value,const char* why){++checks;if(!value){std::fprintf(stderr,"FAILED: %s\n",why);std::exit(1);}}
std::atomic<const sources::Owner*> expected_owner{};
std::atomic<std::uint64_t> supplied_tick{};
bool read_tick(const sources::Owner* owner,std::uint32_t& tick,std::shared_ptr<void>& context)noexcept{
    const auto value=supplied_tick.load(std::memory_order_acquire);
    if(expected_owner.load()!=owner || !(value&(std::uint64_t{1}<<32)))return false;
    context=expected_feeds;tick=static_cast<std::uint32_t>(value);return true;
}
adxt_instances::Status native_work(const std::shared_ptr<void>& context,adxt_instances::Instances& p,std::uint32_t tick)noexcept{
    if(p.snapshot().order_required)return adxt_instances::Status::order_required;
    const auto feeds=std::static_pointer_cast<QueueFeeds>(context);
    if(!feeds || !feeds->enabled)return adxt_instances::Status::completed;
    const auto status=feeds->queue->service(p,tick);
    return status==cue::Status::completed?adxt_instances::Status::completed:status==cue::Status::pending?adxt_instances::Status::pending:status==cue::Status::closed?adxt_instances::Status::closed:adxt_instances::Status::fault;
}
template<class F>struct Op final:sources::Operation {
    F work;explicit Op(F f):work(std::move(f)){}
    void run(adxt_instances::Instances& p)noexcept override{work(p);}
};
template<class F>void control(sources::Owner& owner,F f){Op op(std::move(f));check(owner.run(op)==sources::Admission::accepted,"canonical controller admission");}
std::vector<std::uint8_t> read(const char* name){std::ifstream in(name,std::ios::binary|std::ios::ate);check(bool(in),"owned reference input opens");const auto size=in.tellg();check(size>0&&size<64*1024*1024,"bounded reference input");std::vector<std::uint8_t> bytes(static_cast<std::size_t>(size));in.seekg(0);in.read(reinterpret_cast<char*>(bytes.data()),size);check(bool(in),"owned input complete");return bytes;}
struct Outcome {std::uint64_t underruns{},skipped{},samples{};std::int64_t maximum_pcm_error{};};
Outcome exercise(bool independent,bool inhibited,const std::vector<std::uint8_t>& asset,const std::vector<std::uint8_t>& expected,bool foreground=false,std::vector<std::uint8_t>* reference=nullptr){
    auto owner=std::make_shared<sources::Owner>(adxt_instances::control::Config{});
    expected_owner=owner.get();supplied_tick=0;
    std::unique_ptr<NativeSourceService> worker;
    if(independent)worker=std::make_unique<NativeSourceService>(owner,read_tick,native_work,[](void*)noexcept{++failures;},nullptr);
    auto file=std::make_shared<f::File>();file->bytes=asset;file->bytes.resize((asset.size()+2047)/2048*2048);
    adxt_instances::Key key;
    control(*owner,[&](auto& p){
        check(p.start_output()==adxt_instances::Status::completed,"actual native submix starts");
        auto opened=p.create({2,{0,0,0,0}});check(opened.status==adxt_instances::Status::completed,"stereo native instance");key=opened.key;
        check(p.set_order(std::array{key})==adxt_instances::Status::completed,"ordinary guest order publication");
        if(inhibited)check(p.set_start_inhibit(key,true)==adxt_instances::Status::completed,"inhibit before source start");
        adxt_instances::Source source;source.input=file;source.player.decoder.channels=2;source.player.initial_tick=7;
        source.player.decoder.service_divisor=30;source.player.decoder.source_capacity=reo::native::adxt_shared_source::CapacityProfile::bounded_sectors;
        source.player.decoder.source_config.byte_length=static_cast<std::int32_t>(file->size());
        source.player.decoder.source_config.capacity=source.player.decoder.source_config.threshold=65536;
        check(p.start(key,std::move(source))==adxt_instances::Status::completed,"real owned ADX source starts");
    });
    if(independent){std::this_thread::sleep_for(20ms);control(*owner,[&](auto& p){check(p.snapshot().session.group_visits==0,"no native service before published guest tick");});}
    bool primed{};const auto deadline=std::chrono::steady_clock::now()+5s;
    while(!primed){
        control(*owner,[&](auto& p){check(p.service(7)==adxt_instances::Status::completed,"initial guest service");auto s=p.inspect(key);check(s.source&&!s.source->fault,"source remains valid");primed=s.source->output.channel[0].samples==8192 && (inhibited || s.source->output.voice.playing);});
        check(std::chrono::steady_clock::now()<deadline,"real source priming deadline");std::this_thread::yield();
    }
    supplied_tick.store((std::uint64_t{1}<<32)|7,std::memory_order_release);
    const auto render=owner->submix();std::array<float,960> pcm{};
    if(inhibited){
        for(unsigned j=0;j<10;++j){pcm.fill(0);check(render->render_add(pcm.data(),480)==adxt_instances::control::output::Status::completed,"inhibited output callback");check(std::all_of(pcm.begin(),pcm.end(),[](float x){return x==0;}),"inhibited source stays silent");std::this_thread::sleep_for(20ms);}
        control(*owner,[&](auto& p){auto s=p.inspect(key);check(s.source && !s.source->output.voice.playing && !s.source->output.voice.skipped_samples,"inhibit prevents output consumption");check(p.set_start_inhibit(key,false)==adxt_instances::Status::completed,"release inhibit");});
        const auto end=std::chrono::steady_clock::now()+2s;bool playing{};
        while(!playing){control(*owner,[&](auto& p){playing=p.inspect(key).source->output.voice.playing;});check(std::chrono::steady_clock::now()<end,"native worker admits released start");std::this_thread::sleep_for(1ms);}
    }
    // Only callbacks continue for two seconds. There are no guest service calls.
    Outcome result;const auto start=std::chrono::steady_clock::now();
    for(unsigned block=0;block<200;++block){
        if(foreground)control(*owner,[&](auto& p){for(unsigned n=0;n<8;++n)check(p.service(7)==adxt_instances::Status::completed,"reference foreground service");});
        pcm.fill(0);check(render->render_add(pcm.data(),480)==adxt_instances::control::output::Status::completed,"paced native callback");
        if(independent || foreground)for(unsigned at=0;at<pcm.size();++at){
            const auto sample=std::int32_t(std::lround(pcm[at]*32768));const auto index=(std::size_t(block)*pcm.size()+at)*2;
            std::int16_t wanted{};std::memcpy(&wanted,expected.data()+index,2);result.maximum_pcm_error=std::max(result.maximum_pcm_error,std::int64_t(std::abs(sample-int(wanted))));
            if(reference){const auto value=static_cast<std::int16_t>(sample);const auto* bytes=reinterpret_cast<const std::uint8_t*>(&value);reference->insert(reference->end(),bytes,bytes+2);}
        }
        std::this_thread::sleep_until(start+(block+1)*10ms);
    }
    control(*owner,[&](auto& p){auto s=p.inspect(key);check(s.source && !s.source->fault,"source survived withheld guest service");result.underruns=p.snapshot().session.output.statistics.underrun_frames;result.skipped=s.source->output.voice.skipped_samples;result.samples=s.source->copied_samples;
        if(independent){check(result.underruns==0 && result.skipped==0,"independent refill avoids starvation and skipped PCM");check(s.source->clock.tick_base==7,"worker never advances cached game tick base");check(s.source->decoder.service_divisor==30,"original service divisor preserved");}
    });
    if(independent){
        std::fprintf(stderr,"candidate PCM maximum error=%lld, underruns=%llu, skipped=%llu\n",(long long)result.maximum_pcm_error,(unsigned long long)result.underruns,(unsigned long long)result.skipped);
        check(result.maximum_pcm_error==0,"first two seconds exactly match the ordinary serviced native reference");
        std::size_t paused_queue{};
        control(*owner,[&](auto& p){check(p.pause(key,1,7)==adxt_instances::Status::completed,"pause admitted on controller");paused_queue=p.inspect(key).source->output.channel[0].samples;});
        for(unsigned block=0;block<10;++block){pcm.fill(0);check(render->render_add(pcm.data(),480)==adxt_instances::control::output::Status::completed,"paused callback");check(std::all_of(pcm.begin(),pcm.end(),[](float x){return x==0;}),"paused worker never restarts audio");std::this_thread::sleep_for(20ms);}
        control(*owner,[&](auto& p){auto s=p.inspect(key);check(s.source && s.source->clock.paused && !s.source->output.voice.playing && s.source->output.channel[0].samples>=paused_queue,"pause state and unconsumed queue preserved through repeated native service");check(p.pause(key,0,7)==adxt_instances::Status::completed,"resume admitted");check(owner->join()==sources::Join::busy,"scoped join refuses without closing owner");});
        pcm.fill(0);check(render->render_add(pcm.data(),480)==adxt_instances::control::output::Status::completed,"resumed native callback");
        check(std::any_of(pcm.begin(),pcm.end(),[](float x){return x!=0;}),"resume emits actual source PCM");
    }else if(foreground)check(!result.underruns && !result.skipped,"ordinary serviced reference has no PCM shortage");
    else check(result.underruns==96000-8192,"baseline exposes full unrefilled output loss");
    if(worker){worker->request_stop();}
    owner->request_stop();
    if(worker){worker->join();}
    check(owner->join()==sources::Join::completed,"worker and actual source join before teardown");check(owner->report().joined,"joined publication");
    pcm.fill(.25f);check(render->render_add(pcm.data(),480)==adxt_instances::control::output::Status::closed,"retained output closes safely");
    check(std::all_of(pcm.begin(),pcm.end(),[](float x){return x==.25f;}),"closed submix does not mutate outer mix");
    worker.reset();expected_owner=nullptr;return result;
}
void ordered_peers(const std::vector<std::uint8_t>& asset){
    auto owner=std::make_shared<sources::Owner>(adxt_instances::control::Config{});expected_owner=owner.get();supplied_tick=0;
    NativeSourceService worker(owner,read_tick,native_work,[](void*)noexcept{++failures;},nullptr);
    auto file=std::make_shared<f::File>();file->bytes=asset;file->bytes.resize((asset.size()+2047)/2048*2048);std::array<adxt_instances::Key,3> keys;
    control(*owner,[&](auto& p){check(p.start_output()==adxt_instances::Status::completed,"three-source native output");
        for(unsigned slot=0;slot<3;++slot){auto key=p.create({2,{slot,slot,slot,slot}});check(key.status==adxt_instances::Status::completed,"three native instances");keys[slot]=key.key;
            adxt_instances::Source source;source.input=file;source.player.decoder.channels=2;source.player.initial_tick=7;source.player.decoder.source_config.byte_length=static_cast<std::int32_t>(file->size());
            check(p.start(keys[slot],std::move(source))==adxt_instances::Status::completed,"three actual source workers");
        }
        check(p.pause(keys[2],1,7)==adxt_instances::Status::completed,"third peer paused before publication");
    });
    supplied_tick.store((std::uint64_t{1}<<32)|7,std::memory_order_release);std::this_thread::sleep_for(30ms);
    check(worker.order_deferrals()>0 && worker.visits()==0,"no guessed order while guest publication pending");
    control(*owner,[&](auto& p){check(p.set_order(keys)==adxt_instances::Status::completed,"guest explicitly publishes three-source order");});
    const auto end=std::chrono::steady_clock::now()+5s;bool primed{};
    while(!primed){control(*owner,[&](auto& p){primed=true;for(const auto& k:keys){const auto s=p.inspect(k);check(s.source&&!s.source->fault,"ordered peer remains valid");primed&=s.source->output.channel[0].samples==8192;}});check(std::chrono::steady_clock::now()<end,"three-source priming bound");std::this_thread::sleep_for(1ms);}
    auto render=owner->submix();std::array<float,960> pcm{};for(unsigned n=0;n<10;++n){pcm.fill(0);check(render->render_add(pcm.data(),480)==adxt_instances::control::output::Status::completed,"ordered active peers render");std::this_thread::sleep_for(10ms);}
    control(*owner,[&](auto& p){const auto peer=p.inspect(keys[2]);check(peer.source&&peer.source->clock.paused&&!peer.source->output.voice.playing&&peer.source->output.channel[0].samples==8192&&!peer.source->output.voice.skipped_samples,"third paused peer remains unconsumed");check(!p.snapshot().session.output.statistics.underrun_frames,"ordered peer render has no shortage");});
    worker.request_stop();owner->request_stop();worker.join();check(owner->join()==sources::Join::completed,"three-source worker and sources join");check(worker.visits()>0,"worker actually services ordered peers");expected_owner=nullptr;
}
void queued_shutdown(){
    auto owner=std::make_shared<sources::Owner>(adxt_instances::control::Config{}),foreign=std::make_shared<sources::Owner>(adxt_instances::control::Config{});
    supplied_tick.store((std::uint64_t{1}<<32)|7);expected_owner=foreign.get();
    NativeSourceService worker(owner,read_tick,native_work,[](void*)noexcept{++failures;},nullptr);
    std::this_thread::sleep_for(15ms);check(worker.visits()==0,"foreign owner clock does not enable service");
    std::mutex mutex;std::condition_variable cv;bool entered{},released{};
    std::thread accepted([&]{control(*owner,[&](auto&){std::unique_lock lock(mutex);entered=true;cv.notify_all();check(cv.wait_for(lock,5s,[&]{return released;}),"accepted controller release bound");});});
    {std::unique_lock lock(mutex);check(cv.wait_for(lock,5s,[&]{return entered;}),"controller admitted before worker");}
    expected_owner=owner.get();const auto end=std::chrono::steady_clock::now()+5s;
    while(!owner->report().waiting){check(std::chrono::steady_clock::now()<end,"worker waiting on canonical admission");std::this_thread::sleep_for(1ms);}
    worker.request_stop();owner->request_stop();std::atomic<bool> joined{};
    std::thread joining([&]{worker.join();joined=true;});std::this_thread::sleep_for(10ms);
    check(!joined,"thread join waits for the admitted controller to release");
    {std::lock_guard lock(mutex);released=true;cv.notify_all();}
    accepted.join();joining.join();check(joined&&worker.visits()==0,"queued worker refuses after closed admission without service effects");
    check(owner->join()==sources::Join::completed && foreign->join()==sources::Join::completed,"staged thread/controller/source teardown completes");expected_owner=nullptr;
}
std::uint64_t queued_delayed_header(bool feeder){
    auto owner=std::make_shared<sources::Owner>(adxt_instances::control::Config{});expected_owner=owner.get();supplied_tick=0;
    auto loader=std::make_shared<reo::native::audio_clip_loader::Loader>(reo::native::audio_clip_loader::Config{64,64});
    auto feeds=std::make_shared<QueueFeeds>();feeds->queue=std::make_shared<cue::Queue>(cue::Config{2,65536},loader);feeds->enabled=feeder;expected_feeds=feeds;
    auto last=std::make_shared<f::Blocked>();
    auto clip=[](){auto file=f::file(2,48000,4097);const auto end=96+(4097+31)/32*18*2;file->bytes.resize((end+18+2047)/2048*2048);f::be16(file->bytes,end,0x8001);f::be16(file->bytes,end+2,14);return file;};
    last->bytes=clip()->bytes;adxt_instances::Key key;
    control(*owner,[&](auto& p){check(p.start_output()==adxt_instances::Status::completed,"queued worker submix");auto made=p.create({2,{0,0,0,0}});check(made.status==adxt_instances::Status::completed,"queued stable instance");key=made.key;check(p.set_order(std::array{key})==adxt_instances::Status::completed,"queued guest order publication");check(feeds->queue->bind(p,key)==cue::Status::completed,"native queued feeder binds");for(unsigned n=0;n<17;++n)check(feeds->queue->enqueue(p,"delay:"+std::to_string(n),n==16?last:clip()).status==cue::Status::completed,"seventeen queued preparations accepted");});
    {std::unique_lock lock(last->mutex);check(last->cv.wait_for(lock,5s,[&]{return last->entered;}),"seventeenth actual header read is blocked");}
    control(*owner,[&](auto& p){const auto status=feeds->queue->start(p,7);check(status==cue::Status::completed || status==cue::Status::pending,"queued source play requested");check(feeds->queue->snapshot().registered_assets==16 && feeds->queue->snapshot().preparing==1,"seventeenth header remains fenced");});
    bool primed{};const auto end=std::chrono::steady_clock::now()+5s;
    while(!primed){control(*owner,[&](auto& p){check(p.service(7)==adxt_instances::Status::completed,"queued source initial service");const auto s=p.inspect(key);primed=s.source && s.source->output.voice.playing && s.source->output.channel[0].samples==8192;});check(std::chrono::steady_clock::now()<end,"queued priming bound");std::this_thread::yield();}
    NativeSourceService worker(owner,read_tick,native_work,[](void*)noexcept{++failures;},nullptr);supplied_tick.store((std::uint64_t{1}<<32)|7);
    auto render=owner->submix();std::array<float,960> pcm{};const auto start=std::chrono::steady_clock::now();
    for(unsigned block=0;block<200;++block){
        if(block==30){std::lock_guard lock(last->mutex);last->released=true;last->cv.notify_all();}
        pcm.fill(0);check(render->render_add(pcm.data(),480)==adxt_instances::control::output::Status::completed,"queued withheld-guest callback");std::this_thread::sleep_until(start+(block+1)*10ms);
    }
    std::uint64_t underruns{};control(*owner,[&](auto& p){const auto s=p.inspect(key);underruns=p.snapshot().session.output.statistics.underrun_frames;const auto q=feeds->queue->snapshot();check(s.source && !s.source->fault,"queued native source stays valid");
        if(feeder)check(!underruns && !s.source->output.voice.skipped_samples && q.registered_assets==17 && s.source->first_payload_samples==17u*4097u && s.source->playback.phase==reo::native::adxt_playback::Phase::ended,"native feeder commits delayed seventeenth header and complete exact payload without loss");
        else check(underruns>0 && q.registered_assets==16 && q.preparing==1,"decoder-only worker exposes uncommitted-header starvation");
    });
    worker.request_stop();worker.join();control(*owner,[&](auto& p){const auto status=feeds->queue->close(p);check(status==cue::Status::completed || status==cue::Status::pending,"queued feeder unregister/close before owner teardown");});owner->request_stop();check(owner->join()==sources::Join::completed,"queued native sources join");loader->request_stop();check(loader->join(),"actual metadata worker joins");expected_feeds.reset();expected_owner=nullptr;return underruns;
}
int main(int argc,char** argv){check(argc==3,"owned ADX and independent PCM paths required");const auto asset=read(argv[1]),expected=read(argv[2]);check(expected.size()>=96000*4,"reference covers two seconds");std::vector<std::uint8_t> native_reference;auto serviced=exercise(false,false,asset,expected,true,&native_reference);auto baseline=exercise(false,false,asset,expected),candidate=exercise(true,false,asset,native_reference),inhibit=exercise(true,true,asset,native_reference);ordered_peers(asset);queued_shutdown();auto queue_baseline=queued_delayed_header(false),queue_candidate=queued_delayed_header(true);check(!failures,"no background service failure");std::printf("{\"checks\":%u,\"baseline_underruns\":%llu,\"candidate_underruns\":%llu,\"candidate_skipped\":%llu,\"candidate_pcm_max_error\":%lld,\"inhibited_underruns\":%llu,\"reference_vs_ffmpeg_max_error\":%lld,\"queue_without_feeder_underruns\":%llu,\"queue_with_feeder_underruns\":%llu}\n",checks.load(),(unsigned long long)baseline.underruns,(unsigned long long)candidate.underruns,(unsigned long long)candidate.skipped,(long long)candidate.maximum_pcm_error,(unsigned long long)inhibit.underruns,(long long)serviced.maximum_pcm_error,(unsigned long long)queue_baseline,(unsigned long long)queue_candidate);}
