#include "input.hpp"
#include "../adxt_control_session/control_session.hpp"
#include "../adxt_shared_player/test_sources.hpp"
#include "../adxt_player/test_provider.hpp"
#include <cstdio>
#include <thread>
#include <source_location>

namespace i=reo::native::adxt_lsc_input;
namespace c=reo::native::adxt_control_session;
namespace q=reo::native::adx_sequence;
namespace f=reo::native::adxt_shared_player::testing;
unsigned checks{};
bool attenuation_mode{};
void check(bool value,std::source_location location=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Live input line "+std::to_string(location.line())+" check "+std::to_string(checks));}
std::shared_ptr<f::File> file(unsigned samples,unsigned channels=1,unsigned rate=48000){
    auto out=f::file(channels,rate,samples);const auto end=96+(samples+31)/32*18*channels;
    out->bytes.resize((end+18+2047)/2048*2048);f::be16(out->bytes,end,0x8001);f::be16(out->bytes,end+2,14);return out;
}
std::shared_ptr<const q::Clip> clip(std::shared_ptr<const reo::native::resources::ByteView> view){
    auto value=q::Clip::prepare(std::move(view));check(value.status==q::Status::completed);return value.clip;
}
struct Test{
    std::shared_ptr<reo::audio_output::CallbackSlot> slot=std::make_shared<reo::audio_output::CallbackSlot>();
    std::shared_ptr<reo::native::adxt_player::testing::Provider> provider=std::make_shared<reo::native::adxt_player::testing::Provider>();
    std::shared_ptr<const reo::native::adxt_attenuation::Table> attenuation;
    c::Session session;
    Test():session({},slot,provider){check(session.start()==c::Status::completed);
        if(attenuation_mode){std::array<std::uint32_t,1000> words{};words[0]=256;
            std::fill(words.begin()+1,words.begin()+101,200);std::fill(words.begin()+101,words.begin()+201,100);
            attenuation=reo::native::adxt_attenuation::Table::from_words(words).table;check(bool(attenuation));}}
};
c::player::Config config(const std::shared_ptr<i::Input>& input){c::player::Config out;out.decoder.channels=input->channels();out.decoder.seamless_enabled=true;out.lsc_input=input;out.decoder.source_config.byte_length=i::byte_domain;
    const auto bytes=static_cast<std::int32_t>(input->capacity());out.decoder.source_config.capacity=out.decoder.source_config.threshold=out.decoder.source_config.maximum_request_bytes=bytes;out.decoder.source_config.maximum_sectors=bytes/2048;
    out.decoder.source_capacity=bytes==8192?reo::native::adxt_shared_source::CapacityProfile::fixed_8k:reo::native::adxt_shared_source::CapacityProfile::bounded_sectors;return out;}
c::Key open(Test& t,const std::shared_ptr<i::Input>& input,c::Indices indices={0,0,0,0}){
    auto requested=config(input);requested.attenuation_table=t.attenuation;if(t.attenuation)requested.initial_attenuation=0xffffff9c;
    auto result=t.session.open(requested,input->origin(),indices);check(result.status==c::Status::completed);
    if(t.attenuation)check(t.session.inspect(result.key).evidence.output.voice.volume==200);
    return result.key;
}
void retire(Test& t,const c::Key& key){
    for(unsigned n=0;n<100000;++n){const auto value=t.session.retire(key);if(value.status==c::Status::completed){check(value.source_joined && value.evidence.output_retired);return;}check(value.status==c::Status::pending);std::this_thread::yield();}
    throw std::runtime_error("Live source retirement exceeded bound");
}
void ended(Test& t,const c::Key& key){
    bool faded=false;
    for(unsigned n=0;n<1000000;++n){check(t.session.service(0)==c::Status::completed);const auto value=t.session.inspect(key).evidence;check(!value.fault);
        if(t.attenuation){
            if(!faded && value.output.voice.playing && value.decoder.loop.seamless_samples>0){check(t.session.attenuation(key,0xffffff38)==c::Status::completed);faded=true;}
            const auto current=t.session.inspect(key).evidence;
            check(current.attenuation && current.attenuation->requested==(faded?-200:-100) && current.output.voice.volume==(faded?100u:200u));
            check(current.configured?current.output.voice.frequency==48000:!current.output.voice.playing);
        }
        if(value.configured && value.playback.phase==reo::native::adxt_playback::Phase::ended)return;
        if(value.output.channel[0].samples>=512)t.provider->step(512);
        if(value.decoder.source.in_flight)std::this_thread::yield();}
    throw std::runtime_error("Live source did not end");
}
struct EnqueueNotification final:i::Notification{
    i::AssetKey next;unsigned calls{};
    void empty(i::Input& input)noexcept override{if(calls++==0)check(input.enqueue(next).status==i::Status::completed);}
};
struct Failure final:f::File{
    std::atomic<bool> fail{};
    reo::native::resources::ReadResult read(std::uint64_t at,std::span<std::byte> out)const override{
        if(fail){if(!out.empty())out[0]=std::byte{0xee};return{reo::native::resources::Status::source_failure,0};}
        return File::read(at,out);
    }
};
std::array<std::uint64_t,2> capacity_waveform(unsigned channels,unsigned capacity,unsigned minimum){
    Test t;auto live=i::Input::create({channels,48000,2,2,capacity});
    auto first=file(500003,channels),second=file(120001,channels);
    const auto a=live->register_asset("large-first",clip(first)),b=live->register_asset("large-second",clip(second));
    check(a.status==i::Status::completed && b.status==i::Status::completed && live->capacity()==capacity);
    check(live->minimum(static_cast<std::int32_t>(minimum))==i::Status::completed && live->snapshot().queue.minimum==minimum);
    check(live->enqueue(a.key).status==i::Status::completed && live->enqueue(b.key).status==i::Status::completed && live->start()==i::Status::completed);
    if(capacity!=8192){
        auto wrong=config(live);wrong.decoder.source_config.capacity=8192;
        check(t.session.open(wrong,live->origin(),{0,0,0,0}).status==c::Status::unsupported_profile);
        check(!live->snapshot().bound && !live->snapshot().abandoned && !t.session.snapshot().records && !t.session.snapshot().output.occupied);
        wrong=config(live);wrong.decoder.source_capacity=reo::native::adxt_shared_source::CapacityProfile::fixed_8k;
        check(t.session.open(wrong,live->origin(),{0,0,0,0}).status==c::Status::unsupported_profile && !live->snapshot().bound);
    }
    const auto key=open(t,live);ended(t,key);const auto source=live->snapshot();const auto player=t.session.inspect(key).evidence;
    check(source.error==i::Status::completed && source.published_bytes==first->size()+second->size() && source.planned_samples==620004);
    check(player.first_payload_samples==620004 && player.decoder.source.ring.capacity==static_cast<std::int32_t>(capacity));
    check(!player.output.voice.skipped_samples && !t.session.snapshot().output.statistics.underrun_frames);
    const auto digest=player.first_payload_digest;retire(t,key);check(live->snapshot().joined && !live->snapshot().abandoned && t.session.join()==c::Status::completed);
    return digest;
}
int main(){try{
    for(bool mode:{false,true}){attenuation_mode=mode;
    for(unsigned channels:{1u,2u}){
        const auto baseline=capacity_waveform(channels,8192,6553);
        check(capacity_waveform(channels,channels==1?53248:272384,channels==1?45056:51200)==baseline);
        check(capacity_waveform(channels,1048576,838860)==baseline);
    }
    for(unsigned capacity:{0u,2047u,2049u,1048576u+2048u,0xffffffffu}){
        bool refused=false;try{(void)i::Input::create({1,48000,1,2,capacity});}catch(const std::invalid_argument&){refused=true;}check(refused);
    }
    for(std::int32_t minimum:{0,1,6144,8192}){
        Test t;auto live=i::Input::create({1,48000,1,2});auto payload=file(20000);
        const auto prepared=live->register_asset("threshold",clip(payload));
        check(live->minimum(minimum)==i::Status::completed && live->snapshot().queue.minimum==static_cast<std::uint32_t>(minimum));
        check(live->minimum(-1)==i::Status::completed && live->minimum(8193)==i::Status::completed);
        check(live->snapshot().queue.minimum==static_cast<std::uint32_t>(minimum) && live->snapshot().diagnostics==2);
        check(live->enqueue(prepared.key).status==i::Status::completed && live->start()==i::Status::completed);
        const auto key=open(t,live);
        if(minimum==0){
            // Strict occupied < minimum admits no work at zero. There must be
            // no fabricated completion, decoded sample or output signal.
            for(unsigned n=0;n<64;++n)check(t.session.service(0)==c::Status::completed);
            const auto observed=live->snapshot();
            check(observed.planned_bytes==payload->size() && !observed.accepted_reads && !observed.completed_reads && !observed.published_bytes && observed.unavailable_reads);
            check(!t.session.inspect(key).evidence.first_payload_samples && !t.session.snapshot().output.statistics.signal_frames);
            // Changing the queue minimum does not revise an already opened
            // lower file's threshold or authorize accepted progress.
            check(live->minimum(8192)==i::Status::completed);
            for(unsigned n=0;n<64;++n)check(t.session.service(0)==c::Status::completed);
            check(!live->snapshot().accepted_reads && !live->snapshot().published_bytes);
        }else if(minimum==1){
            // The byte count may leave a partial encoded block. Strict
            // occupied < 1 cannot admit its missing suffix. Preserve the
            // stalled state instead of fabricating EOF or bypassing the gate.
            bool stalled=false;
            for(unsigned n=0;n<100000;++n){
                check(t.session.service(0)==c::Status::completed);const auto player=t.session.inspect(key).evidence;
                if(player.output.channel[0].samples>=512)t.provider->step(512);
                const auto observed=live->snapshot();
                if(observed.completed_reads && !player.decoder.source.in_flight && player.decoder.source.ring.data>0 && player.decoder.source.ring.data<18){stalled=true;break;}
                std::this_thread::yield();
            }
            check(stalled);const auto before=live->snapshot();
            for(unsigned n=0;n<64;++n){check(t.session.service(0)==c::Status::completed);if(t.session.inspect(key).evidence.output.channel[0].samples>=512)t.provider->step(512);}
            const auto after=live->snapshot();
            check(after.published_bytes==before.published_bytes && after.accepted_reads==before.accepted_reads && after.published_bytes<after.planned_bytes && after.error==i::Status::completed);
        }else{
            ended(t,key);const auto observed=live->snapshot();const auto player=t.session.inspect(key).evidence;
            check(observed.published_bytes==payload->size() && observed.completed_reads && observed.error==i::Status::completed);
            check(player.first_payload_samples==20000 && !player.output.voice.skipped_samples && !t.session.snapshot().output.statistics.underrun_frames);
        }
        retire(t,key);check(live->minimum(6144)==i::Status::closed && t.session.join()==c::Status::completed);
    }
    {
        Test t;auto input=i::Input::create({1,48000,1,2});auto foreign=i::Input::create({1,48000,1,2});
        check(t.session.open(config(input),foreign->origin(),{0,0,0,0}).status==c::Status::unsupported_profile);
        check(t.session.snapshot().records==0 && t.session.snapshot().output.occupied==0);
        check(t.session.join()==c::Status::completed);
    }
    {
        // The second asset is registered/enqueued after playback has begun.
        // Pause exactly one prevents its admission; argument two resumes it.
        Test t;auto live=i::Input::create({1,48000,2,2});const auto a=live->register_asset("first",clip(file(20000)));
        auto blocked=std::make_shared<f::Blocked>();blocked->bytes=file(12001)->bytes;blocked->released=true;
        const auto b=live->register_asset("late",clip(blocked));
        struct Release{std::shared_ptr<f::Blocked> source;~Release(){std::lock_guard lock(source->mutex);source->released=true;source->cv.notify_all();}}release{blocked};
        check(live->enqueue(a.key).status==i::Status::completed && live->start()==i::Status::completed);const auto key=open(t,live);
        bool playing=false;for(unsigned n=0;n<100000;++n){check(t.session.service(0)==c::Status::completed);const auto value=t.session.inspect(key).evidence;
            if(value.output.voice.playing && value.decoder.outer.sample_progress<20000){playing=true;break;}std::this_thread::yield();}check(playing);
        check(live->pause(1)==i::Status::completed && live->enqueue(b.key).status==i::Status::completed);
        for(unsigned n=0;n<32;++n)check(t.session.service(0)==c::Status::completed);
        check(live->snapshot().planned_samples==20000 && live->snapshot().queue.paused==1);
        {std::lock_guard lock(blocked->mutex);blocked->released=false;blocked->entered=false;}
        check(live->pause(2)==i::Status::completed);
        bool waiting=false;for(unsigned n=0;n<1000000;++n){check(t.session.service(0)==c::Status::completed);const auto value=t.session.inspect(key).evidence;
            bool entered;{std::lock_guard lock(blocked->mutex);entered=blocked->entered;}
            if(entered && value.decoder.outer.sample_progress>=20000){waiting=true;break;}
            if(value.output.channel[0].samples>=512)t.provider->step(512);
            std::this_thread::yield();}check(waiting);
        const auto pending=live->snapshot();check(pending.planned_samples==32001 && pending.published_bytes==file(20000)->size() && pending.file_progress==0);
        for(unsigned n=0;n<32;++n){check(t.session.service(0)==c::Status::completed);const auto value=t.session.inspect(key).evidence;
            check(!value.fault && value.decoder.loop.seamless_samples==0 && value.decoder.outer.phase==reo::native::adxt_phased_player::window::OuterPhase::decoding);}
        {std::lock_guard lock(blocked->mutex);blocked->released=true;blocked->cv.notify_all();}
        ended(t,key);check(live->snapshot().decoder_base==20000 && live->snapshot().planned_samples==32001);
        const auto clock=t.session.estimate(key,0);check(clock.status==c::Status::completed && clock.value.result.ratio.numerator==32001);
        retire(t,key);check(live->snapshot().joined && !live->snapshot().abandoned && t.session.join()==c::Status::completed);
    }
    {
        Test t;auto live=i::Input::create({1,48000,2,2}),foreign=i::Input::create({1,48000,1,2});
        const auto prepared=clip(file(8193));const auto a=live->register_asset("a",prepared),b=live->register_asset("b",prepared);
        check(a.status==i::Status::completed && b.status==i::Status::completed && live->register_asset("full",prepared).status==i::Status::capacity);
        check(live->enqueue({}).status==i::Status::invalid_key && foreign->enqueue(a.key).status==i::Status::invalid_key);
        for(unsigned n=0;n<16;++n)check(live->enqueue(a.key).status==i::Status::completed);
        check(live->enqueue(b.key).status==i::Status::capacity && live->snapshot().queue.count==16);
        std::array<std::byte,32> buffer{};buffer.fill(std::byte{0xa5});check(live->origin()->read(0,buffer).status==reo::native::resources::Status::invalid_view && buffer[0]==std::byte{0xa5});
        check(live->start()==i::Status::completed && live->start()==i::Status::unsupported_profile);
        const auto key=open(t,live);check(t.session.open(config(live),live->origin(),{1,1,1,1}).status==c::Status::unsupported_profile);
        check(t.session.snapshot().records==1 && t.session.snapshot().output.occupied==1 && live->snapshot().bound && live->stop()==i::Status::unsupported_profile);
        ended(t,key);const auto before=live->snapshot();check(before.planned_samples==16*8193 && before.decoder_base==15*8193 && before.published_bytes==before.planned_bytes);
        const auto clock=t.session.estimate(key,0);check(clock.status==c::Status::completed && clock.value.result.ratio.numerator==16*8193);
        retire(t,key);check(live->snapshot().joined && !live->snapshot().abandoned && !live->snapshot().registered_assets);
        check(live->enqueue(a.key).status==i::Status::closed && t.session.join()==c::Status::completed);
    }
    {
        Test t;auto callback=std::make_shared<EnqueueNotification>();auto live=i::Input::create({1,48000,2,2},callback);
        auto a=live->register_asset("first",clip(file(12000))),b=live->register_asset("callback",clip(file(4097)));callback->next=b.key;
        check(live->enqueue(a.key).status==i::Status::completed && live->start()==i::Status::completed);const auto key=open(t,live);ended(t,key);
        const auto value=live->snapshot();check(callback->calls>=1 && value.planned_samples==16097 && value.decoder_base==12000 && value.published_bytes==value.planned_bytes);
        retire(t,key);check(t.session.join()==c::Status::completed);
    }
    for(int repeat:{1,2,257}){
        Test t;auto live=i::Input::create({1,48000,1,2});const auto a=live->register_asset("repeat",clip(file(10001)));
        check(live->enqueue(a.key).status==i::Status::completed && live->repeat(repeat)==i::Status::completed && live->start()==i::Status::completed);const auto key=open(t,live);
        if(repeat!=2){bool repeated=false;for(unsigned n=0;n<1000000;++n){check(t.session.service(0)==c::Status::completed);const auto value=t.session.inspect(key).evidence;
                if(value.decoder.loop.seamless_samples>=20002){repeated=true;break;}
                if(value.output.channel[0].samples>=512)t.provider->step(512);
                std::this_thread::yield();}check(repeated);check(live->repeat(0)==i::Status::completed);}
        ended(t,key);const auto value=live->snapshot();check(value.planned_samples%10001==0 && (repeat==2?value.planned_samples==10001:value.planned_samples>=30003));
        const auto state=t.session.inspect(key).evidence;check(state.first_payload_samples==value.planned_samples && !state.output.voice.skipped_samples && !t.session.snapshot().output.statistics.underrun_frames);
        retire(t,key);check(t.session.join()==c::Status::completed);
    }
    {
        Test t;auto live=i::Input::create({1,48000,1,2});auto blocked=std::make_shared<f::Blocked>();blocked->bytes=file(20000)->bytes;blocked->released=true;
        std::weak_ptr<f::Blocked> weak=blocked;auto prepared=clip(blocked);auto a=live->register_asset("blocked",prepared);prepared.reset();
        struct Release{std::weak_ptr<f::Blocked> file;~Release(){if(auto f=file.lock()){std::lock_guard lock(f->mutex);f->released=true;f->cv.notify_all();}}}release{weak};
        {std::lock_guard lock(blocked->mutex);blocked->released=false;blocked->entered=false;}blocked.reset();
        check(live->enqueue(a.key).status==i::Status::completed && live->start()==i::Status::completed);const auto key=open(t,live);
        auto peer_file=file(120000);c::player::Config pc;pc.decoder.source_config.byte_length=static_cast<std::int32_t>(peer_file->size());const auto peer=t.session.open(pc,peer_file,{1,1,1,1});check(peer.status==c::Status::completed);
        bool ready=false;for(unsigned n=0;n<100000;++n){check(t.session.service(0)==c::Status::completed);auto held=weak.lock();bool entered;{std::lock_guard lock(held->mutex);entered=held->entered;}
            const auto value=t.session.inspect(peer.key).evidence;if(entered && value.output.voice.playing && value.output.channel[0].samples>=2048){ready=true;break;}std::this_thread::yield();}check(ready);
        const auto pending=live->snapshot();check(pending.accepted_reads==1 && !pending.completed_reads && !pending.published_bytes && !pending.file_progress && pending.queue.records[0].status==1);
        const auto retired=t.session.retire(key);check(retired.status==c::Status::pending && !live->snapshot().joined && !weak.expired() && live->snapshot().registered_assets==1);
        const auto consumed=t.session.inspect(peer.key).evidence.output.channel[0].consumed_bytes;t.provider->step(512);check(t.session.inspect(peer.key).evidence.output.channel[0].consumed_bytes>consumed && !t.provider->unloaded);
        {auto held=weak.lock();std::lock_guard lock(held->mutex);held->released=true;held->cv.notify_all();}
        retire(t,key);check(live->snapshot().joined && !live->snapshot().abandoned && weak.expired());retire(t,peer.key);check(t.session.join()==c::Status::completed);
    }
    {
        Test t;auto live=i::Input::create({1,48000,1,2});auto broken=std::make_shared<Failure>();broken->bytes=file(20000)->bytes;auto prepared=clip(broken);const auto a=live->register_asset("failure",prepared);
        check(live->enqueue(a.key).status==i::Status::completed && live->start()==i::Status::completed);broken->fail=true;const auto key=open(t,live);bool failed=false;
        for(unsigned n=0;n<100000;++n){const auto result=t.session.service(0);if(result==c::Status::fault){failed=true;break;}check(result==c::Status::completed);std::this_thread::yield();}check(failed);
        check(live->snapshot().error==i::Status::source_failure && !live->snapshot().published_bytes && t.session.inspect(key).evidence.output.channel[0].queued_bytes==0);
        retire(t,key);check(live->snapshot().joined && !live->snapshot().abandoned && t.session.join()==c::Status::completed);
    }
    }
    std::printf("%u live LSC ownership/control assertions, raw and attenuation profiles\n",checks);return 0;
}catch(const std::exception& e){std::fprintf(stderr,"%s\n",e.what());return 1;}}
