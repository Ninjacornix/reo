#include "queue.hpp"
#include "../adxt_shared_player/test_sources.hpp"
#include "../adxt_player/test_provider.hpp"
#include <array>
#include <chrono>
#include <iostream>
#include <source_location>
#include <thread>

namespace cue=reo::native::audio_cue_queue;
namespace inst=reo::native::adxt_instances;
namespace f=reo::native::adxt_shared_player::testing;
unsigned checks{};
void check(bool value,const std::source_location location=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Native cue queue check "+std::to_string(checks)+" at line "+std::to_string(location.line()));}
bool accepted(cue::Status value){return value==cue::Status::completed || value==cue::Status::pending;}
bool accepted(inst::Status value){return value==inst::Status::completed || value==inst::Status::pending;}
std::shared_ptr<f::File> clip(unsigned channels=2,unsigned samples=12000){
    auto file=f::file(channels,48000,samples);const auto end=96+(samples+31)/32*18*channels;
    file->bytes.resize((end+18+2047)/2048*2048);f::be16(file->bytes,end,0x8001);f::be16(file->bytes,end+2,14);return file;
}
struct Rig {
    std::shared_ptr<reo::audio_output::CallbackSlot> slot=std::make_shared<reo::audio_output::CallbackSlot>();
    std::shared_ptr<reo::native::adxt_player::testing::Provider> provider=std::make_shared<reo::native::adxt_player::testing::Provider>();
    std::shared_ptr<reo::native::audio_clip_loader::Loader> loader=std::make_shared<reo::native::audio_clip_loader::Loader>(reo::native::audio_clip_loader::Config{64,64});
    inst::Instances playback{{{2},{}},slot,provider};
    inst::Key key;
    cue::Queue queue{{2,65536},loader};
    Rig(){check(playback.start_output()==inst::Status::completed);auto created=playback.create({2,{0,0,0,0,0},{}});check(created.status==inst::Status::completed);key=created.key;
        check(playback.set_order(std::array{key})==inst::Status::completed && queue.bind(playback,key)==cue::Status::completed);}
    ~Rig(){(void)queue.close(playback);(void)playback.request_stop();(void)playback.join();(void)loader->join();}
    inst::Observation step(bool render=true){check(accepted(queue.service(playback,0)));check(accepted(playback.service(0)));auto state=playback.inspect(key);check(state.status==inst::Status::completed);
        if(render && state.source && state.source->output.channel[0].samples>=512){check(provider->step(512));}std::this_thread::yield();return state;}
};
template<class Predicate>inst::Observation drive(Rig& rig,Predicate until){
    const auto deadline=std::chrono::steady_clock::now()+std::chrono::seconds(10);
    for(;;){auto value=rig.step();if(until(value))return value;if(std::chrono::steady_clock::now()>=deadline)throw std::runtime_error("Native cue deadline");}
}
bool ended(const inst::Observation& value){return value.source && value.source->configured && value.source->playback.phase==reo::native::adxt_playback::Phase::ended;}
struct Release {std::shared_ptr<f::Blocked> file;~Release(){std::lock_guard lock(file->mutex);file->released=true;file->cv.notify_all();}};
std::array<std::uint64_t,2> playlist(bool delayed){
    Rig rig;auto next=std::make_shared<f::Blocked>();next->bytes=clip(2,20000)->bytes;next->released=!delayed;Release release{next};
    check(rig.playback.set_loop_enabled(rig.key,true)==inst::Status::completed);
    const auto first=rig.queue.enqueue(rig.playback,"native:first",clip()),second=rig.queue.enqueue(rig.playback,"native:second",next);
    check(first.status==cue::Status::completed && second.status==cue::Status::completed && first.receipt==1 && second.receipt==2 && rig.queue.snapshot().queued==2);
    check(accepted(rig.queue.start(rig.playback,0)) && rig.queue.start(rig.playback,0)==cue::Status::already_started);
    if(delayed){
        {std::unique_lock lock(next->mutex);check(next->cv.wait_for(lock,std::chrono::seconds(5),[&]{return next->entered;}));}
        const auto held=drive(rig,[](const auto& state){return state.source && state.source->first_payload_samples==12000;});
        check(!ended(held) && rig.queue.snapshot().preparing==1 && !rig.queue.snapshot().decoder_ended);
        for(unsigned i=0;i<100;++i)(void)rig.step(false);
        {std::lock_guard lock(next->mutex);next->released=true;next->cv.notify_all();}
    }
    const auto terminal=drive(rig,ended);check(terminal.source->first_payload_samples==32000 && !rig.playback.snapshot().session.output.statistics.underrun_frames);
    check(!terminal.source->decoder.source.loop.enabled && rig.playback.set_loop_enabled(rig.key,true)==inst::Status::completed);
    check(rig.queue.snapshot().registered_assets==2 && rig.queue.snapshot().submitted_sources==1 && rig.queue.snapshot().decoder_ended);
    check(rig.queue.enqueue(rig.playback,"too-late",clip()).status==cue::Status::closed);
    check(rig.queue.clear(rig.playback)==cue::Status::unsupported_profile && accepted(rig.queue.stop(rig.playback)));
    const auto digest=terminal.source->first_payload_digest;auto ordinary=clip();inst::Source source;source.input=ordinary;source.player.decoder.channels=2;
    source.player.decoder.source_config.byte_length=static_cast<std::int32_t>(ordinary->size());check(accepted(rig.playback.start(rig.key,std::move(source))));
    const auto resumed=drive(rig,[](const auto& state){return state.starts==2 && state.source && state.source->configured;});
    check(resumed.source->decoder.source.loop.enabled);return digest;
}
std::array<std::uint64_t,2> seventeen(bool delayed) {
    Rig rig;auto last=std::make_shared<f::Blocked>();last->bytes=clip(2,4097)->bytes;
    last->released=!delayed;Release release{last};
    for(unsigned i=0;i<17;++i)
        check(rig.queue.enqueue(rig.playback,"burst:"+std::to_string(i),i==16?last:clip(2,4097)).status==cue::Status::completed);
    const auto deadline=std::chrono::steady_clock::now()+std::chrono::seconds(5);
    while(rig.loader->snapshot().finished<(delayed?16u:17u) && std::chrono::steady_clock::now()<deadline)std::this_thread::yield();
    check(rig.loader->snapshot().finished==(delayed?16u:17u));
    check(accepted(rig.queue.start(rig.playback,0)));
    // A full lower queue must retain the seventeenth preparation, not fail,
    // discard it, or repeatedly register the same asset while waiting.
    check(rig.queue.snapshot().preparing==1 && rig.queue.snapshot().registered_assets==16);
    if(delayed) {
        // A partial ADPCM block can remain behind the next-header fence.
        // Earlier clips must progress while the final header is unavailable.
        const auto held=drive(rig,[](const auto& state){return state.source && state.source->first_payload_samples>=15u*4097u;});
        check(!ended(held) && rig.queue.snapshot().preparing==1);
        {std::lock_guard lock(last->mutex);last->released=true;last->cv.notify_all();}
    }
    const auto terminal=drive(rig,ended);
    check(terminal.source->first_payload_samples==17u*4097u && rig.queue.snapshot().registered_assets==17 &&
          rig.queue.snapshot().submitted_sources==1 && !rig.queue.snapshot().failed);
    return terminal.source->first_payload_digest;
}
int main()try{
    check(playlist(false)==playlist(true));
    check(seventeen(false)==seventeen(true));
    {
        Rig rig;check(rig.queue.repeat(rig.playback,true)==cue::Status::completed);
        check(rig.queue.enqueue(rig.playback,"repeat",clip()).status==cue::Status::completed && accepted(rig.queue.start(rig.playback,0)));
        (void)drive(rig,[](const auto& state){return state.source && state.source->first_payload_samples>=36000;});
        check(rig.queue.repeat(rig.playback,false)==cue::Status::completed);
        const auto terminal=drive(rig,ended);check(terminal.source->first_payload_samples>=36000 && !rig.queue.snapshot().repeat && !rig.playback.snapshot().session.output.statistics.underrun_frames);
    }
    {
        Rig rig;auto blocked=std::make_shared<f::Blocked>();blocked->bytes=clip()->bytes;Release release{blocked};
        check(rig.queue.enqueue(rig.playback,"canceled",blocked).status==cue::Status::completed);
        {std::unique_lock lock(blocked->mutex);check(blocked->cv.wait_for(lock,std::chrono::seconds(5),[&]{return blocked->entered;}));}
        check(accepted(rig.queue.start(rig.playback,0)) && accepted(rig.queue.stop(rig.playback)) && !rig.queue.snapshot().preparing && !rig.queue.snapshot().queued);
        check(rig.queue.enqueue(rig.playback,"replacement",clip(2,4097)).status==cue::Status::completed && accepted(rig.queue.start(rig.playback,0)));
        {std::lock_guard lock(blocked->mutex);blocked->released=true;blocked->cv.notify_all();}
        const auto terminal=drive(rig,ended);check(terminal.starts==1 && terminal.source->first_payload_samples==4097 && rig.queue.snapshot().accepted==2);
    }
    {
        struct StreamingGate final:f::File {
            mutable std::mutex mutex;mutable std::condition_variable cv;mutable unsigned calls{};
            mutable bool entered{},released{};
            reo::native::resources::ReadResult read(std::uint64_t at,std::span<std::byte> out)const override{
                {std::unique_lock lock(mutex);if(++calls>2){entered=true;cv.notify_all();cv.wait(lock,[&]{return released;});}}
                return File::read(at,out);
            }
        };
        Rig rig;auto blocked=std::make_shared<StreamingGate>();blocked->bytes=clip()->bytes;
        struct ReleaseStream {std::shared_ptr<StreamingGate> file;~ReleaseStream(){std::lock_guard lock(file->mutex);file->released=true;file->cv.notify_all();}}release{blocked};
        check(rig.queue.enqueue(rig.playback,"blocked-stream",blocked).status==cue::Status::completed && accepted(rig.queue.start(rig.playback,0)));
        bool entered{};const auto deadline=std::chrono::steady_clock::now()+std::chrono::seconds(5);
        while(!entered && std::chrono::steady_clock::now()<deadline){(void)rig.step();std::lock_guard lock(blocked->mutex);entered=blocked->entered;}
        check(entered && rig.playback.inspect(rig.key).starts==1);
        check(rig.queue.stop(rig.playback)==cue::Status::pending && rig.queue.snapshot().retirement_status==inst::Status::pending);
        check(rig.playback.inspect(rig.key).phase==inst::Phase::retiring);
        check(rig.queue.enqueue(rig.playback,"replacement-stream",clip(2,4097)).status==cue::Status::completed && accepted(rig.queue.start(rig.playback,0)));
        for(unsigned i=0;i<100;++i)(void)rig.step(false);
        check(rig.playback.inspect(rig.key).starts==1);
        {std::lock_guard lock(blocked->mutex);blocked->released=true;blocked->cv.notify_all();}
        const auto terminal=drive(rig,ended);check(terminal.starts==2 && terminal.source->first_payload_samples==4097 && rig.queue.snapshot().retirement_status==inst::Status::completed);
    }
    {
        Rig rig;auto blocked=std::make_shared<f::Blocked>();blocked->bytes=clip()->bytes;Release release{blocked};
        for(unsigned i=0;i<17;++i)check(rig.queue.enqueue(rig.playback,"pending",blocked).status==cue::Status::completed);
        check(rig.queue.enqueue(rig.playback,"overflow",clip()).status==cue::Status::capacity && rig.queue.snapshot().queued==17);
        check(rig.queue.clear(rig.playback)==cue::Status::completed && !rig.queue.snapshot().queued);
    }
    for(bool wrong_channels:{false,true}){
        Rig rig;auto invalid=clip(wrong_channels?1:2);if(!wrong_channels)invalid->bytes[0]=0;
        check(rig.queue.enqueue(rig.playback,"refused",invalid).status==cue::Status::completed);
        auto status=rig.queue.start(rig.playback,0);const auto deadline=std::chrono::steady_clock::now()+std::chrono::seconds(5);
        while(accepted(status) && std::chrono::steady_clock::now()<deadline){status=rig.queue.service(rig.playback,0);std::this_thread::yield();}
        check(status==(wrong_channels?cue::Status::unsupported_profile:cue::Status::source_failure));
        check(rig.queue.snapshot().failed && !rig.playback.inspect(rig.key).source && rig.queue.snapshot().failure==status);
        check(accepted(rig.queue.stop(rig.playback)) && rig.queue.enqueue(rig.playback,"recovered",clip(2,257)).status==cue::Status::completed && accepted(rig.queue.start(rig.playback,0)));
        check(drive(rig,ended).source->first_payload_samples==257);
    }
    {
        Rig rig;auto ordinary=clip();inst::Source source;source.input=ordinary;source.player.decoder.channels=2;
        source.player.decoder.source_config.byte_length=static_cast<std::int32_t>(ordinary->size());
        check(rig.playback.start(rig.key,std::move(source))==inst::Status::completed);
        const auto before=rig.playback.inspect(rig.key);auto bad=clip();bad->bytes[0]=0;
        check(rig.queue.enqueue(rig.playback,"failed-preload",bad).status==cue::Status::completed);
        auto status=cue::Status::pending;const auto deadline=std::chrono::steady_clock::now()+std::chrono::seconds(5);
        while(accepted(status) && std::chrono::steady_clock::now()<deadline){status=rig.queue.service(rig.playback,0);std::this_thread::yield();}
        const auto after=rig.playback.inspect(rig.key);
        check(status==cue::Status::source_failure && after.starts==before.starts && after.completed_stops==before.completed_stops && after.phase==inst::Phase::active);
        check(rig.queue.clear(rig.playback)==cue::Status::completed && rig.playback.inspect(rig.key).phase==inst::Phase::active);
    }
    {
        Rig rig,other;check(rig.queue.service(other.playback,0)==cue::Status::invalid_owner && rig.queue.stop(other.playback)==cue::Status::invalid_owner);
        check(rig.queue.bind(rig.playback,rig.key)==cue::Status::invalid_owner && rig.queue.enqueue(rig.playback,"",clip()).status==cue::Status::invalid_input);
        check(accepted(rig.queue.close(rig.playback)) && rig.queue.enqueue(rig.playback,"closed",clip()).status==cue::Status::closed && !other.playback.inspect(other.key).source);
    }
    std::cout<<checks<<" native cue controller checks\n";return 0;
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
