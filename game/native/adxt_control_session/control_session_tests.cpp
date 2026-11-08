#include "control_session.hpp"
#include "../adxt_shared_player/test_sources.hpp"
#include "../adxt_player/test_provider.hpp"
#include "../audio_clip_loader/loader.hpp"
#include <array>
#include <cfenv>
#include <chrono>
#include <iostream>
#include <thread>

namespace c=reo::native::adxt_control_session;
namespace f=reo::native::adxt_shared_player::testing;
unsigned checks{};void check(bool b){++checks;if(!b)throw std::runtime_error("Control session check "+std::to_string(checks));}
struct Test {
    std::shared_ptr<reo::audio_output::CallbackSlot> slot=std::make_shared<reo::audio_output::CallbackSlot>();
    std::shared_ptr<reo::native::adxt_player::testing::Provider> provider=std::make_shared<reo::native::adxt_player::testing::Provider>();
    c::Session session;
    explicit Test(unsigned streams=2,c::player::clock::Shared initial_clock={}):session({{streams},initial_clock},slot,provider){check(session.start()==c::Status::completed);}
};
c::player::Config config(const std::shared_ptr<const reo::native::resources::ByteView>& file,unsigned channels){c::player::Config v;v.decoder.channels=channels;v.decoder.source_config.byte_length=static_cast<std::int32_t>(file->size());return v;}
c::Key open(Test& t,std::shared_ptr<const reo::native::resources::ByteView> file,unsigned channels,c::Indices indices){auto result=t.session.open(config(file,channels),file,indices);check(result.status==c::Status::completed);return result.key;}
c::Retirement retire(Test& t,const c::Key& key){for(unsigned i=0;i<100000;++i){auto r=t.session.retire(key);if(r.status==c::Status::completed){check(r.source_joined && r.evidence.output_retired && r.evidence.decoder.source.joined);return r;}check(r.status==c::Status::pending);std::this_thread::yield();}throw std::runtime_error("Retirement bound");}
std::shared_ptr<f::File> loop_file(unsigned channels,unsigned rate,unsigned start,unsigned span){
    auto file=std::make_shared<f::File>();const unsigned total=start+span,header=2048-start/32*18*channels,blocks=(total+31)/32*channels,end=header+blocks*18;
    auto& bytes=file->bytes;bytes.resize((end+4+2047)/2048*2048);
    f::be16(bytes,0,0x8000);f::be16(bytes,2,static_cast<std::uint16_t>(header-4));bytes[4]=3;bytes[5]=18;bytes[6]=4;bytes[7]=static_cast<std::uint8_t>(channels);
    f::be32(bytes,8,rate);f::be32(bytes,12,total);f::be16(bytes,16,500);bytes[18]=3;
    f::be16(bytes,20,0);f::be16(bytes,22,1);f::be16(bytes,26,1);f::be32(bytes,28,start);f::be32(bytes,32,2048);f::be32(bytes,36,total);f::be32(bytes,40,end);
    for(unsigned b=0;b<blocks;++b){const auto at=header+b*18;bytes[at+1]=3;std::fill_n(bytes.begin()+at+2,16,static_cast<std::uint8_t>(0x11+b%7));}
    f::be16(bytes,end,0x8001);return file;
}
std::shared_ptr<f::File> sequence_file(unsigned channels,unsigned rate,unsigned samples){
    auto file=f::file(channels,rate,samples);const auto end=96+(samples+31)/32*18*channels;
    file->bytes.resize((end+18+2047)/2048*2048);f::be16(file->bytes,end,0x8001);f::be16(file->bytes,end+2,14);return file;
}
c::player::Config sequence_config(std::shared_ptr<const reo::native::adx_sequence::Sequence> sequence){
    auto value=config(sequence,sequence->channels());value.decoder.seamless_enabled=true;value.sequence=std::move(sequence);return value;
}
std::shared_ptr<const reo::native::adxt_attenuation::Table> attenuation_table(){
    std::array<std::uint32_t,1000> words{};words[0]=256;
    std::fill(words.begin()+1,words.begin()+101,200);std::fill(words.begin()+101,words.begin()+201,100);
    auto table=reo::native::adxt_attenuation::Table::from_words(words);check(table.status==reo::native::adxt_attenuation::Status::completed);return table.table;
}
struct ClockImportProbe final:reo::native::adxt_lsc_input::Notification {
    c::Session& session;bool armed{};unsigned calls{};
    explicit ClockImportProbe(c::Session& value):session(value){}
    void empty(reo::native::adxt_lsc_input::Input&)noexcept override{
        if(!armed)return;
        ++calls;const auto before=session.snapshot().clock_state;
        check(session.configure_clock({{2,5000,123},1,0xdeadbeef})==c::Status::busy);
        const auto after=session.snapshot().clock_state;check(before.mode==after.mode && before.rebase_selector==after.rebase_selector && before.drift_bits==after.drift_bits && before.service_busy==after.service_busy && before.in_call==after.in_call);
    }
};
// Finite files can use native prefetch geometry without changing decoded
// samples, output priming, clocks or the existing sequence/live-input profiles.
std::array<std::uint64_t,2> finite_prefetch(unsigned capacity,unsigned channels,unsigned rate,unsigned samples){
    Test t;auto file=f::file(channels,rate,samples);auto pc=config(file,channels);
    if(capacity!=8192){pc.decoder.source_capacity=reo::native::adxt_shared_source::CapacityProfile::bounded_sectors;
        pc.decoder.source_config.capacity=pc.decoder.source_config.threshold=static_cast<std::int32_t>(capacity);}
    const auto opened=t.session.open(pc,file,{15,2,8,31});check(opened.status==c::Status::completed);bool ended{};
    for(unsigned i=0;i<1000000;++i){check(t.session.service(0)==c::Status::completed);const auto state=t.session.inspect(opened.key).evidence;check(!state.fault);
        if(state.configured && state.playback.phase==reo::native::adxt_playback::Phase::ended){ended=true;break;}
        if(state.output.channel[0].samples>=512)t.provider->step(512);
        if(state.decoder.source.in_flight)std::this_thread::yield();}
    check(ended);const auto state=t.session.inspect(opened.key).evidence;
    check(state.first_payload_samples==samples && !state.output.voice.skipped_samples && !t.session.snapshot().output.statistics.underrun_frames);
    const auto digest=state.first_payload_digest;retire(t,opened.key);check(t.session.join()==c::Status::completed);return digest;
}
// Block the actual asynchronous source read, while control service and output
// callbacks continue. The duration is measured in output frames, not sleeps.
std::uint64_t prefetch_read_stall(unsigned capacity){
    struct Gated final:f::File {
        mutable std::mutex mutex;mutable std::condition_variable cv;bool armed{};
        mutable bool entered{},released{};
        reo::native::resources::ReadResult read(std::uint64_t at,std::span<std::byte> out)const override{
            {std::unique_lock lock(mutex);if(armed){entered=true;cv.notify_all();cv.wait(lock,[&]{return released;});}}
            return File::read(at,out);
        }
        void release(){std::lock_guard lock(mutex);released=true;cv.notify_all();}
    };
    Test t;auto file=std::make_shared<Gated>();file->bytes=f::file(2,48000,200000)->bytes;
    struct Release {std::shared_ptr<Gated> file;~Release(){file->release();}}release{file};
    auto pc=config(file,2);
    if(capacity!=8192){pc.decoder.source_capacity=reo::native::adxt_shared_source::CapacityProfile::bounded_sectors;
        pc.decoder.source_config.capacity=pc.decoder.source_config.threshold=static_cast<std::int32_t>(capacity);}
    const auto opened=t.session.open(pc,file,{15,2,8,31});check(opened.status==c::Status::completed);bool primed{};
    for(unsigned i=0;i<1000000;++i){check(t.session.service(0)==c::Status::completed);const auto s=t.session.inspect(opened.key).evidence;check(!s.fault);
        if(s.output.voice.playing && s.output.channel[0].samples==8192 && !s.decoder.source.in_flight && s.decoder.source.ring.data>=static_cast<std::int32_t>(capacity)-2048){primed=true;break;}
        std::this_thread::yield();}
    if(!primed){const auto s=t.session.inspect(opened.key).evidence;std::cerr<<"Prefetch prime: capacity="<<capacity<<", playing="<<s.output.voice.playing<<", in_flight="<<s.decoder.source.in_flight<<", encoded="<<s.decoder.source.ring.data<<", output="<<s.output.channel[0].samples<<"\n";}
    check(primed);{std::lock_guard lock(file->mutex);file->armed=true;}
    bool blocked{};
    for(unsigned i=0;i<10000;++i){check(t.session.service(0)==c::Status::completed);
        {std::unique_lock lock(file->mutex);if(t.session.inspect(opened.key).evidence.decoder.source.in_flight){
            file->cv.wait_for(lock,std::chrono::milliseconds(100),[&]{return file->entered;});}blocked=file->entered;}if(blocked)break;
        check(t.provider->step(512));std::this_thread::yield();}
    check(blocked);const auto before=t.session.snapshot().output.statistics.underrun_frames;
    for(unsigned frame=0;frame<48000;frame+=512){
        for(unsigned service=0;service<16;++service)check(t.session.service(0)==c::Status::completed);
        check(t.provider->step(512));check(!t.session.inspect(opened.key).evidence.fault);
    }
    const auto shortage=t.session.snapshot().output.statistics.underrun_frames-before;
    check(t.session.retire(opened.key).status==c::Status::pending);
    file->release();retire(t,opened.key);check(t.session.join()==c::Status::completed);return shortage;
}
std::array<std::uint64_t,2> prepared_cue_boundary(bool delayed){
    namespace loading=reo::native::audio_clip_loader;namespace queued=reo::native::adxt_lsc_input;
    loading::Loader metadata({2,2});Test t;
    auto second=std::make_shared<f::Blocked>();second->bytes=sequence_file(2,48000,20000)->bytes;second->released=!delayed;
    struct Release {std::shared_ptr<f::Blocked> file;~Release(){std::lock_guard lock(file->mutex);file->released=true;file->cv.notify_all();}}release{second};
    const auto wait=[&](const loading::Key& key){
        const auto deadline=std::chrono::steady_clock::now()+std::chrono::seconds(5);
        for(;;){auto r=metadata.poll(key);if(r.status!=loading::Status::pending){check(r.status==loading::Status::ready);return r.clip;}
            if(std::chrono::steady_clock::now()>=deadline){throw std::runtime_error("Cue header preparation deadline");}std::this_thread::yield();}
    };
    const auto first=metadata.prepare(sequence_file(2,48000,12000));check(first.status==loading::Status::accepted);const auto first_clip=wait(first.key);
    const auto next=metadata.prepare(second);check(next.status==loading::Status::accepted);
    auto input=queued::Input::create({2,48000,4,2,65536});
    const auto a=input->register_asset("first",first_clip);check(a.status==queued::Status::completed && input->enqueue(a.key).status==queued::Status::completed);
    check(input->preparing_assets(1)==queued::Status::completed && input->preparing_assets(17)==queued::Status::capacity && input->snapshot().preparing_assets==1);
    const auto publish_next=[&]{const auto prepared=wait(next.key);const auto b=input->register_asset("second",prepared);
        check(b.status==queued::Status::completed && input->enqueue(b.key).status==queued::Status::completed && input->preparing_assets(0)==queued::Status::completed);};
    if(!delayed)publish_next();
    check(input->start()==queued::Status::completed);
    auto pc=config(input->origin(),2);pc.decoder.seamless_enabled=true;pc.lsc_input=input;
    pc.decoder.source_capacity=reo::native::adxt_shared_source::CapacityProfile::bounded_sectors;
    pc.decoder.source_config.capacity=pc.decoder.source_config.threshold=pc.decoder.source_config.maximum_request_bytes=65536;pc.decoder.source_config.maximum_sectors=32;
    const auto opened=t.session.open(pc,input->origin(),{15,2,8,31});check(opened.status==c::Status::completed);
    if(delayed){
        {std::unique_lock lock(second->mutex);check(second->cv.wait_for(lock,std::chrono::seconds(5),[&]{return second->entered;}));}
        bool boundary{};
        for(unsigned i=0;i<1000000;++i){check(t.session.service(0)==c::Status::completed);const auto s=t.session.inspect(opened.key).evidence;check(!s.fault);
            if(s.decoder.engine.decoded_total>=12000 && s.first_payload_samples==12000){boundary=true;break;}
            if(s.output.channel[0].samples>=512){check(t.provider->step(512));}std::this_thread::yield();}
        check(boundary);
        for(unsigned i=0;i<100;++i)check(t.session.service(0)==c::Status::completed);
        const auto held=t.session.inspect(opened.key).evidence;
        check(metadata.poll(next.key).status==loading::Status::pending && !input->snapshot().decoder_ended && !held.fault && held.playback.phase!=reo::native::adxt_playback::Phase::ended);
        {std::lock_guard lock(second->mutex);second->released=true;second->cv.notify_all();}publish_next();
    }
    bool ended{};
    for(unsigned i=0;i<1000000;++i){check(t.session.service(0)==c::Status::completed);const auto s=t.session.inspect(opened.key).evidence;check(!s.fault);
        if(s.configured && s.playback.phase==reo::native::adxt_playback::Phase::ended){ended=true;break;}
        if(s.output.channel[0].samples>=512){check(t.provider->step(512));}std::this_thread::yield();}
    const auto terminal=t.session.inspect(opened.key).evidence;
    check(ended && terminal.first_payload_samples==32000 && !t.session.snapshot().output.statistics.underrun_frames && input->snapshot().decoder_ended);
    check(input->preparing_assets(0)==queued::Status::closed);
    const auto digest=terminal.first_payload_digest;retire(t,opened.key);check(t.session.join()==c::Status::completed && metadata.join());return digest;
}
int main(){try{
    check(prepared_cue_boundary(false)==prepared_cue_boundary(true));
    const auto baseline_shortage=prefetch_read_stall(8192),prefetch_shortage=prefetch_read_stall(65536);
    std::cout<<"48128 frames blocked source: 8KiB underruns="<<baseline_shortage<<", 64KiB underruns="<<prefetch_shortage<<"\n";
    check(baseline_shortage>0 && prefetch_shortage==0);
    for(unsigned channels:{1u,2u})for(unsigned rate:{24000u,48000u})for(unsigned samples:{33u,200000u}){
        const auto baseline=finite_prefetch(8192,channels,rate,samples);
        for(unsigned capacity:{16384u,65536u,262144u})check(finite_prefetch(capacity,channels,rate,samples)==baseline);
    }
    {
        Test t;auto file=f::file(2,48000,20000);auto pc=config(file,2);
        pc.decoder.source_capacity=reo::native::adxt_shared_source::CapacityProfile::bounded_sectors;
        pc.decoder.source_config.capacity=pc.decoder.source_config.threshold=65536;
        for(unsigned variant=0;variant<4;++variant){auto bad=pc;
            if(variant==0)bad.decoder.source_config.byte_length-=2048;
            if(variant==1)bad.decoder.source_config.start_sector=1;
            if(variant==2)bad.decoder.source_config.maximum_sectors=32;
            if(variant==3)bad.decoder.source_config.threshold=8192;
            check(t.session.open(bad,file,{15,2,8,31}).status==c::Status::unsupported_profile);
            check(!t.session.snapshot().output.occupied);
        }
        check(t.session.join()==c::Status::completed);
    }
    {
        using I=reo::native::adxt_lsc_input::Input;using S=reo::native::adxt_lsc_input::Status;
        Test t;auto notification=std::make_shared<ClockImportProbe>(t.session);auto live=I::create({1,48000,4,2},notification);
        auto first=reo::native::adx_sequence::Clip::prepare(sequence_file(1,48000,12000));
        auto second=reo::native::adx_sequence::Clip::prepare(sequence_file(1,48000,4097));
        check(first.status==reo::native::adx_sequence::Status::completed && second.status==reo::native::adx_sequence::Status::completed);
        const auto a=live->register_asset("first.adx",first.clip),b=live->register_asset("second.adx",second.clip);
        check(a.status==S::completed && b.status==S::completed && live->enqueue(a.key).status==S::completed && live->enqueue(b.key).status==S::completed && live->start()==S::completed);
        auto pc=config(live->origin(),1);pc.decoder.seamless_enabled=true;pc.lsc_input=live;
        const auto opened=t.session.open(pc,live->origin(),{15,2,8,31});check(opened.status==c::Status::completed);bool ended=false;notification->armed=true;
        for(unsigned i=0;i<1000000;++i){check(t.session.service(0)==c::Status::completed);const auto state=t.session.inspect(opened.key).evidence;
            check(!state.fault && live->snapshot().error==S::completed);
            if(state.configured && state.playback.phase==reo::native::adxt_playback::Phase::ended){ended=true;break;}
            if(state.output.channel[0].samples>=512)t.provider->step(512);
            if(state.decoder.source.in_flight)std::this_thread::yield();}check(ended);
        const auto before=live->snapshot();check(before.published_bytes==before.planned_bytes && before.planned_samples==16097 && before.decoder_base==12000 && before.decoder_ended && before.completed_reads==before.accepted_reads && notification->calls>0);
        check(before.queue.records[0].status==2 && before.queue.records[0].progress==0xfffff && before.queue.records[1].status==2 && before.queue.records[1].progress==0xfffff);
        const auto clock=t.session.estimate(opened.key,0);check(clock.status==c::Status::completed && clock.value.result.ratio.numerator==16097 && clock.value.result.ratio.denominator==48000);
        check(live->enqueue(a.key).status==S::closed && t.session.set_loop_enabled(opened.key,true)==c::Status::unsupported_profile);
        check(!t.session.snapshot().output.statistics.underrun_frames);retire(t,opened.key);const auto done=live->snapshot();
        check(done.joined && !done.abandoned && !done.registered_assets && !done.journal_entries && !t.provider->unloaded);check(t.session.join()==c::Status::completed);
    }
    for(bool tabled:{false,true})for(unsigned channels:{1u,2u})for(unsigned rate:{24000u,44100u,48000u})for(unsigned first:{33u,8193u,20000u}){
        Test t;std::array<std::shared_ptr<const reo::native::resources::ByteView>,3> views{
            sequence_file(channels,rate,first),sequence_file(channels,rate,64),sequence_file(channels,rate,16385)};
        auto prepared=reo::native::adx_sequence::Sequence::prepare(views);check(prepared.status==reo::native::adx_sequence::Status::completed);
        auto pc=sequence_config(prepared.sequence);if(tabled){pc.attenuation_table=attenuation_table();pc.initial_attenuation=0xffffff9c;}
        const auto opened=t.session.open(pc,prepared.sequence,{15,2,8,31});check(opened.status==c::Status::completed);bool ended=false,faded=false;
        check(t.session.set_loop_enabled(opened.key,true)==c::Status::unsupported_profile);
        for(unsigned i=0;i<1000000;++i){check(t.session.service(0)==c::Status::completed);const auto state=t.session.inspect(opened.key).evidence;check(!state.fault);
            if(tabled){
                if(!faded && state.output.voice.playing && state.decoder.loop.seamless_samples>0){check(t.session.attenuation(opened.key,0xffffff38)==c::Status::completed);faded=true;}
                const auto current=t.session.inspect(opened.key).evidence;
                check(current.attenuation && current.attenuation->requested==(faded?-200:-100) && current.output.voice.volume==(faded?100u:200u));
                check(current.configured?current.output.voice.frequency==rate:!current.output.voice.playing);
            }
            if(state.clock_observation.state==3 && state.decoder.outer.phase==c::player::window::OuterPhase::decoding){
                const auto clock=t.session.estimate(opened.key,0);check(clock.status==c::Status::completed && clock.value.result.ratio.numerator==state.output.channel[0].consumed_bytes/2);}
            if(state.configured && state.playback.phase==reo::native::adxt_playback::Phase::ended){ended=true;break;}
            if(state.output.channel[0].samples>=512)t.provider->step(512);
            if(state.decoder.source.in_flight)std::this_thread::yield();}check(ended);
        const auto state=t.session.inspect(opened.key).evidence;check(state.decoder.loop.seamless_samples==static_cast<std::int32_t>(first+64) && state.first_payload_samples==first+64+16385);
        const auto clock=t.session.estimate(opened.key,0);check(clock.status==c::Status::completed && clock.value.result.ratio.numerator==first+64+16385 && clock.value.result.ratio.denominator==rate);
        check(!t.session.snapshot().output.statistics.underrun_frames && !state.output.voice.skipped_samples);retire(t,opened.key);check(t.session.join()==c::Status::completed);
    }
    {
        Test t;auto first=sequence_file(1,48000,12000);auto second=sequence_file(1,48000,4097);
        std::array<std::shared_ptr<const reo::native::resources::ByteView>,2> views{first,second};auto prepared=reo::native::adx_sequence::Sequence::prepare(views);check(prepared.status==reo::native::adx_sequence::Status::completed);
        auto pc=sequence_config(prepared.sequence);const auto reads=first->reads.load()+second->reads.load();
        check(t.session.open(pc,first,{0,0,0,0}).status==c::Status::unsupported_profile);
        pc.sequence.reset();check(t.session.open(pc,prepared.sequence,{0,0,0,0}).status==c::Status::unsupported_profile);
        pc=sequence_config(prepared.sequence);pc.decoder.source_config.maximum_sectors=2;
        check(t.session.open(pc,prepared.sequence,{0,0,0,0}).status==c::Status::unsupported_profile);
        check(first->reads.load()+second->reads.load()==reads && !t.session.snapshot().records && !t.session.snapshot().output.occupied);
        check(t.session.join()==c::Status::completed);
    }
    {
        Test t;auto first=sequence_file(1,48000,12000);auto blocked=std::make_shared<f::Blocked>();blocked->bytes=sequence_file(1,48000,4097)->bytes;blocked->released=true;
        struct Release{std::shared_ptr<f::Blocked> file;~Release(){std::lock_guard lock(file->mutex);file->released=true;file->cv.notify_all();}}release{blocked};
        std::array<std::shared_ptr<const reo::native::resources::ByteView>,2> views{first,blocked};auto prepared=reo::native::adx_sequence::Sequence::prepare(views);check(prepared.status==reo::native::adx_sequence::Status::completed);
        {std::lock_guard lock(blocked->mutex);blocked->released=false;blocked->entered=false;}
        auto pc=sequence_config(prepared.sequence);const auto opened=t.session.open(pc,prepared.sequence,{0,0,0,0});check(opened.status==c::Status::completed);bool waiting=false;
        for(unsigned i=0;i<100000;++i){check(t.session.service(0)==c::Status::completed);const auto state=t.session.inspect(opened.key).evidence;bool entered;{std::lock_guard lock(blocked->mutex);entered=blocked->entered;}
            if(entered && state.decoder.outer.decoded_samples==12000){waiting=true;break;}
            if(state.output.channel[0].samples>=512)t.provider->step(512);
            std::this_thread::yield();}check(waiting);
        for(unsigned i=0;i<20;++i)check(t.session.service(0)==c::Status::completed);
        const auto held=t.session.inspect(opened.key).evidence;check(held.decoder.loop.seamless_enabled && held.decoder.loop.seamless_samples==0 && held.decoder.source.in_flight && !held.fault);
        {std::lock_guard lock(blocked->mutex);blocked->released=true;blocked->cv.notify_all();}
        bool ended=false;for(unsigned i=0;i<100000;++i){check(t.session.service(0)==c::Status::completed);const auto state=t.session.inspect(opened.key).evidence;
            if(state.configured && state.playback.phase==reo::native::adxt_playback::Phase::ended){ended=true;break;}
            if(state.output.channel[0].samples>=512)t.provider->step(512);
            std::this_thread::yield();}check(ended && t.session.inspect(opened.key).evidence.decoder.loop.seamless_samples==12000);
        retire(t,opened.key);check(t.session.join()==c::Status::completed);
    }
    for(unsigned capacity:{8192u,65536u})for(bool tabled:{false,true})for(unsigned channels:{1u,2u})for(unsigned rate:{24000u,44100u,48000u})for(unsigned start:{0u,32u,800u})for(unsigned span:{16385u,32772u}){
        const auto loop_check_begin=checks;
        try{
        Test t;auto file=loop_file(channels,rate,start,span);auto pc=config(file,channels);pc.decoder.loop_enabled=true;
        if(capacity!=8192){pc.decoder.source_capacity=reo::native::adxt_shared_source::CapacityProfile::bounded_sectors;
            pc.decoder.source_config.capacity=pc.decoder.source_config.threshold=static_cast<std::int32_t>(capacity);}
        if(tabled){pc.attenuation_table=attenuation_table();pc.initial_attenuation=0xffffff9c;}
        auto opened=t.session.open(pc,file,{15,2,8,31});check(opened.status==c::Status::completed);const auto key=opened.key;bool repeated=false;std::int32_t decoded{};
        for(unsigned i=0;i<1000000;++i){const auto status=t.session.service(0);if(status!=c::Status::completed){const auto s=t.session.inspect(key).evidence;std::cerr<<"Loop service status="<<unsigned(status)<<", fault="<<s.fault<<", iteration="<<s.decoder.loop.iterations<<", decoded="<<s.decoder.outer.decoded_samples<<", encoded="<<s.decoder.source.ring.data<<"\n";}check(status==c::Status::completed);const auto state=t.session.inspect(key).evidence;
            check(!state.fault && state.decoder.outer.decoded_samples>=decoded && state.clock_observation.offset==0);decoded=state.decoder.outer.decoded_samples;
            if(state.decoder.loop.iterations>=2 && state.copied_samples>=start+2*span){repeated=true;break;}
            if(state.output.channel[0].samples>=512)t.provider->step(512);
            if(state.decoder.source.in_flight)std::this_thread::yield();}check(repeated);
        const auto looped=t.session.inspect(key).evidence;check(looped.playback.phase==reo::native::adxt_playback::Phase::playing && looped.decoder.loop.saved_valid && looped.decoder.source.loop.enabled && looped.decoder.header.loop.count==0);
        if(tabled){check(looped.attenuation && looped.attenuation->requested==-100 && looped.output.voice.volume==200 && looped.output.voice.frequency==rate);
            check(t.session.attenuation(key,0xffffff38)==c::Status::completed && t.session.inspect(key).evidence.output.voice.volume==100);}
        const auto clock=t.session.estimate(key,0);check(clock.status==c::Status::completed && clock.value.result.ratio.numerator==looped.output.channel[0].consumed_bytes/2 && clock.value.result.ratio.denominator==rate);
        check(t.session.set_loop_enabled(key,false)==c::Status::completed && !t.session.inspect(key).evidence.decoder.source.loop.enabled);
        bool ended=false;for(unsigned i=0;i<1000000;++i){check(t.session.service(0)==c::Status::completed);const auto state=t.session.inspect(key).evidence;
            if(state.configured && state.playback.phase==reo::native::adxt_playback::Phase::ended){ended=true;break;}
            if(state.output.channel[0].samples>=512)t.provider->step(512);
            if(state.decoder.source.in_flight)std::this_thread::yield();}check(ended);
        const auto terminal=t.session.estimate(key,0);check(terminal.status==c::Status::completed && terminal.value.result.ratio.numerator==start+span);
        check(!t.session.snapshot().output.statistics.underrun_frames);retire(t,key);check(t.session.join()==c::Status::completed);
        }catch(...){std::cerr<<"Loop capacity="<<capacity<<", channels="<<channels<<", rate="<<rate<<", start="<<start<<", span="<<span<<", initial_check="<<loop_check_begin<<"\n";throw;}
    }
    for(bool short_target:{false,true}){
        Test t;auto file=loop_file(1,48000,0,short_target?257:16385);if(!short_target)f::be32(file->bytes,28,1);
        auto pc=config(file,1);pc.decoder.loop_enabled=true;const auto opened=t.session.open(pc,file,{0,0,0,0});check(opened.status==c::Status::completed);bool fault=false;
        for(unsigned i=0;i<100000;++i){const auto status=t.session.service(0);if(status==c::Status::fault){fault=true;break;}check(status==c::Status::completed);std::this_thread::yield();}check(fault);
        const auto state=t.session.inspect(opened.key).evidence;check(state.fault && !state.configured && !state.output.voice.playing && !state.output.channel[0].samples);
        retire(t,opened.key);check(t.session.join()==c::Status::completed);
    }
    {
        Test t;auto file=f::file(1,48000,20000);auto pc=config(file,1);pc.decoder.loop_enabled=true;auto opened=t.session.open(pc,file,{0,0,0,0});check(opened.status==c::Status::completed);bool ended=false;
        for(unsigned i=0;i<100000;++i){check(t.session.service(0)==c::Status::completed);const auto state=t.session.inspect(opened.key).evidence;
            if(state.configured && state.playback.phase==reo::native::adxt_playback::Phase::ended){ended=true;break;}
            if(state.output.channel[0].samples>=512)t.provider->step(512);
            std::this_thread::yield();}check(ended && !t.session.inspect(opened.key).evidence.decoder.loop.iterations);
        retire(t,opened.key);check(t.session.join()==c::Status::completed);
    }
    {
        c::player::clock::Shared initial_clock;initial_clock.mode={1,6000,17};Test t(2,initial_clock);
        auto key=open(t,f::file(1,48000,120000),1,{0,0,0,0});auto peer=open(t,f::file(2,48000,120000),2,{1,1,1,1});
        const auto idle=t.session.snapshot();check(t.session.discard_rebase(key,10).status==c::Status::completed);
        check(t.session.snapshot().group_visits==idle.group_visits && t.session.snapshot().discard_diagnostics==idle.discard_diagnostics);
        check(t.session.pause(key,1,11).status==c::Status::completed);const auto before=t.session.inspect(key).evidence;
        check(t.session.discard_rebase(key,12).status==c::Status::completed);const auto after=t.session.inspect(key).evidence;
        check(after.clock.tick_base==12 && after.clock.paused==1 && after.clock.rna_play==0 && after.service_visits[0]==before.service_visits[0] && after.service_visits[1]==before.service_visits[1]+1);
        bool ready=false;for(unsigned i=0;i<100000;++i){check(t.session.service(0)==c::Status::completed);const auto target=t.session.inspect(key).evidence,other=t.session.inspect(peer).evidence;
            if(target.configured && target.playback.phase==reo::native::adxt_playback::Phase::playing && target.output.channel[0].samples>=2048 && other.output.voice.playing && other.output.channel[0].samples>=2048){ready=true;break;}std::this_thread::yield();}check(ready);
        const auto input=t.session.inspect(key).evidence;const auto start=t.session.snapshot();const auto callbacks=t.provider->callbacks;
        const auto rebased=t.session.discard_rebase(key,42);check(rebased.status==c::Status::completed && rebased.value.result==c::player::clock::Status::completed);
        const auto output=t.session.inspect(key).evidence;const auto end=t.session.snapshot();
        check(end.group_visits==start.group_visits+1 && end.discard_diagnostics==start.discard_diagnostics+1 && end.dtx_scans==end.group_visits*2 && !end.service_busy);
        check(output.service_visits[0]==input.service_visits[0] && output.service_visits[1]==input.service_visits[1]+1 && t.provider->callbacks==callbacks);
        check(output.clock.tick_base==42 && output.playback.tick_base==42 && output.clock.paused==1 && !output.output.voice.playing);
        check(t.session.pause(key,2,43).status==c::Status::completed);t.provider->step(512);
        check(t.session.discard_rebase(key,44).status==c::Status::completed);const auto resumed=t.session.inspect(key).evidence;
        check(resumed.clock.estimate_base==64 && resumed.clock.tick_base==44 && resumed.clock.paused==2 && resumed.clock.rna_play==1 && resumed.output.voice.playing);
        const auto count=t.session.snapshot().group_visits;const auto round=std::fegetround();(void)std::fesetround(FE_DOWNWARD);
        const auto refused=t.session.discard_rebase(key,45);(void)std::fesetround(round);
        check(refused.status==c::Status::unsupported_profile && refused.value.result==c::player::clock::Status::unsupported_fp && t.session.snapshot().group_visits==count && t.session.inspect(key).evidence.clock==resumed.clock);
        retire(t,key);retire(t,peer);check(t.session.join()==c::Status::completed);
    }
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
