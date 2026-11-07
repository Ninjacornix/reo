#include "session.hpp"
#include <atomic>
#include <bit>
#include <cstdio>
#include <cstdlib>
#include <mutex>
#include <thread>
namespace n=reo::native::adxt_output_session;
namespace o=reo::audio_output;
namespace c=reo::native::pcm;
namespace p=reo::native::adxt_playback;
unsigned checks{};
void check(bool ok,const char* why){++checks;if(!ok){std::fprintf(stderr,"FAILED: %s\n",why);std::exit(1);}}
struct Provider final:o::Provider {
    std::shared_ptr<o::CallbackSlot> required;std::mutex mutex;o::CallbackSlot* slot{};
    std::array<float,1024> output{};unsigned attaches{},detaches{},stops{},unloads{},failures{};
    std::string_view source_sha256()const noexcept override{return o::provider_source_sha256;}
    bool attach(o::CallbackSlot& s)noexcept override{
        std::lock_guard lock(mutex);++attaches;if(&s!=required.get() || !s.occupied())return false;slot=&s;return true;}
    bool detach()noexcept override{std::lock_guard lock(mutex);++detaches;if(failures){--failures;return false;}slot=nullptr;return true;}
    bool stop()noexcept override{++stops;return true;}bool unload()noexcept override{++unloads;return true;}
    bool render(unsigned frames){std::lock_guard lock(mutex);return slot && slot->dispatch(output.data(),frames);}
};
struct Fixture {
    std::shared_ptr<o::CallbackSlot> slot=std::make_shared<o::CallbackSlot>();
    std::shared_ptr<Provider> host=std::make_shared<Provider>();n::Session session;
    Fixture(n::Config config={}):session(config,slot,host){host->required=slot;}
    std::unique_ptr<n::Producer> open(unsigned channels){auto result=session.open(channels);check(result.status==n::Status::completed,"exclusive producer opened");return std::move(result.producer);}
};
std::array<std::byte,1024> plane(std::int16_t sample){std::array<std::byte,1024> out{};
    const auto bits=std::bit_cast<std::uint16_t>(sample);for(unsigned i=0;i<out.size();i+=2){out[i]=std::byte(bits&255);out[i+1]=std::byte(bits>>8);}return out;}
void independent_lifetime(){
    Fixture f({2});auto a=f.open(2),b=f.open(1);auto left=plane(900),right=plane(-1100),mono=plane(500);
    check(a->copy(left,right)==n::Status::completed && b->copy(mono)==n::Status::completed,"two real PCM copies accepted");
    check(a->play(true)==p::Status::completed && b->play(true)==p::Status::completed,"two independent voices start");
    check(f.session.start()==n::Status::completed && f.host->render(32),"shared provider renders");
    check(f.host->output[0]==1400.0f/32768 && f.host->output[1]==-600.0f/32768,"actual stereo and mono mixed");
    const auto before=b->snapshot();const auto old=a->snapshot();
    check(a->retire()==n::Status::completed,"one stream retires synchronously");
    check(f.host->detaches==0 && f.slot->occupied() && !f.session.snapshot().closed,"stream retirement preserves provider");
    check(b->snapshot().channel[0].samples==before.channel[0].samples && b->snapshot().voice.playing,"other stream queue and play retained");
    check(f.host->render(32) && f.host->output[0]==500.0f/32768 && f.host->output[1]==500.0f/32768,"other stream continues actual render");
    auto replacement=f.open(2);
    check(replacement->snapshot().generation!=old.generation && replacement->snapshot().channel[0].queued_bytes==0 && replacement->snapshot().voice.phase==0,"reused slot has fresh epoch and DSP phase");
    check(a->copy(left,right)==n::Status::stale_producer && a->play(true)==p::Status::fault,"retired producer cannot mutate reused voice");
    check(a->snapshot().channel[0].consumed_bytes==old.channel[0].consumed_bytes,"old stream evidence retained across reuse");
    check(f.session.join()==n::Status::completed && f.host->detaches==1 && f.host->stops==1 && f.host->unloads==1,"whole session owns one actual provider fence");
    check(f.session.snapshot().provider_joined && !f.slot->occupied(),"stable slot released after join");
}
void order_and_reference(){
    Fixture f({3});std::array<std::unique_ptr<n::Producer>,3> streams;
    const std::array<std::int16_t,3> samples{32767,-32767,16384};const std::array<float,3> gain{1,1,0.0000001f};
    c::Config cfg;cfg.max_channels=3;cfg.max_voices=3;cfg.channel_samples=8192;c::Session reference(cfg);
    check(reference.select_frame_clock()==c::Status::ok,"reference frame clock");
    std::array<c::Channel,3> channels;std::array<c::Voice,3> voices;
    for(unsigned i=0;i<3;++i){streams[i]=f.open(1);auto bytes=plane(samples[i]);
        check(streams[i]->copy(bytes)==n::Status::completed && streams[i]->gain(gain[i])==n::Status::completed,"gain-bearing source copied");
        auto channel=reference.create_channel();auto voice=reference.create_voice();channels[i]=channel.value;voices[i]=voice.value;
        check(reference.enqueue(channels[i],bytes,0).status==c::Status::ok,"reference copy");
        check(reference.configure(voices[i],{channels[i],{},c::Channels::mono,48000,256,true},0)==c::Status::ok && reference.gain(voices[i],gain[i])==c::Status::ok,"reference voice/gain");}
    check(streams[0]->play(true)==p::Status::completed && streams[1]->play(true)==p::Status::completed,"first voices start");
    check(streams[2]->play(true)==p::Status::invalid_input && !streams[2]->snapshot().voice.playing,"third voice requires explicit summation order");
    std::array<const n::Producer*,3> order{streams[0].get(),streams[1].get(),streams[2].get()};
    check(f.session.set_order(order)==n::Status::completed && streams[2]->play(true)==p::Status::completed,"explicit full order admits third voice");
    check(reference.set_mix_order(voices)==c::Status::ok && f.session.start()==n::Status::completed,"both render graphs ready");
    std::array<float,64> expected{};check(reference.render(expected)==c::Status::ok && f.host->render(32),"actual and reference render");
    bool equal=true;for(unsigned i=0;i<expected.size();++i)equal=equal && std::bit_cast<std::uint32_t>(expected[i])==std::bit_cast<std::uint32_t>(f.host->output[i]);
    check(equal,"ordered multi-stream floats match unchanged core bit-for-bit");const auto normal=f.host->output[0];
    std::swap(order[1],order[2]);std::swap(voices[1],voices[2]);
    check(f.session.set_order(order)==n::Status::completed && reference.set_mix_order(voices)==c::Status::ok,"new explicit order applied");
    check(reference.render(expected)==c::Status::ok && f.host->render(32),"second actual and reference render");
    equal=true;for(unsigned i=0;i<expected.size();++i)equal=equal && std::bit_cast<std::uint32_t>(expected[i])==std::bit_cast<std::uint32_t>(f.host->output[i]);
    check(equal && f.host->output[0]!=normal,"cancellation discriminates summation order");
    std::array<const n::Producer*,3> duplicate{streams[0].get(),streams[0].get(),streams[2].get()};
    check(f.session.set_order(duplicate)==n::Status::invalid_input,"duplicate producer order refused");
    check(f.session.join()==n::Status::completed,"ordered session joined");
}
void refusals(){
    Fixture f({1,128});auto stream=f.open(2);auto bytes=plane(7);auto small=std::span<const std::byte>(bytes).first(64);
    check(stream->copy(small,small)==n::Status::completed && stream->copy(small,small)==n::Status::completed,"bounded copies accepted");
    const auto before=stream->snapshot();check(stream->copy(small,small)==n::Status::copy_refused,"lifetime counter preflight refuses whole stereo batch");
    check(stream->snapshot().channel[0].queued_bytes==before.channel[0].queued_bytes && stream->snapshot().channel[1].queued_bytes==before.channel[1].queued_bytes,"counter refusal leaves both queues untouched");
    check(f.session.open(1).status==n::Status::capacity,"bounded producer domain");
    check(stream->copy(small)==n::Status::invalid_input,"missing stereo plane refused");
    check(stream->stop_transfer()==p::Status::completed && stream->copy(small,small)==n::Status::closed,"per-stream copy fence gates subsequent acceptance");
    check(f.session.start()==n::Status::completed,"refusal fixture started");f.host->failures=1;
    check(f.session.join()==n::Status::pending,"failed provider detach remains pending");
    check(!f.session.snapshot().closed && stream->snapshot().channel[0].samples==before.channel[0].samples,"failed session fence retains actual queues");
    check(f.session.join()==n::Status::completed && stream->snapshot().retired,"provider retry clears after actual fence");
    check(stream->copy(small,small)==n::Status::stale_producer,"whole join closes retained producer");
    Fixture orphan({1});{auto lost=orphan.open(1);check(lost->copy(small)==n::Status::completed,"orphan test copy");}
    check(orphan.session.snapshot().streams[0].orphaned && orphan.session.open(1).status==n::Status::capacity,"lost producer never silently reuses live record");
    check(orphan.session.join()==n::Status::completed,"session join reclaims orphan");
}
void concurrent(){
    Fixture f({2});auto a=f.open(2),b=f.open(1);check(f.session.start()==n::Status::completed,"concurrent output started");
    auto bytes=plane(123);check(a->play(true)==p::Status::completed && b->play(true)==p::Status::completed,"concurrent streams active");
    std::atomic<bool> done{};std::thread callback([&]{while(!done.load()){f.host->render(32);std::this_thread::yield();}});
    for(unsigned n=0;n<1000;++n){const auto result=a->copy(bytes,bytes);check(result==n::Status::completed || result==n::Status::capacity,"concurrent batch admission");
        const auto s=a->snapshot();check(s.channel[0].samples==s.channel[1].samples && s.channel[0].consumed_bytes==s.channel[1].consumed_bytes,"concurrent stereo copy and consume are paired");}
    check(a->retire()==n::Status::completed && b->snapshot().active,"per-stream retirement fences render while retaining peer");
    check(f.session.join()==n::Status::completed,"concurrent session joined");done=true;callback.join();
}
void render_refusal(){
    Fixture f({1,64});auto stream=f.open(1);auto bytes=plane(42);
    check(stream->copy(std::span<const std::byte>(bytes).first(64))==n::Status::completed && stream->play(true)==p::Status::completed,"render refusal has actual queued input");
    check(f.session.start()==n::Status::completed && f.host->render(64),"refused render callback completed safely");
    const auto s=f.session.snapshot();check(s.render_fault && s.closing && s.last_render_status==c::Status::counter_limit,"render refusal has explicit diagnostic");
    check(stream->snapshot().channel[0].samples==32 && stream->snapshot().channel[0].consumed_bytes==0,"render preflight refusal retained input");
    check(f.session.start()==n::Status::closed && stream->copy(std::span<const std::byte>(bytes).first(64))==n::Status::closed,"render fault closes new admission");
    check(f.session.join()==n::Status::completed,"refused renderer still joins actual provider");
}
void external_submix(){
    std::shared_ptr<n::Submix> retained;Fixture reference({2});
    {
        n::Session session(n::Config{2});retained=session.submix();
        check(bool(retained) && !reference.session.submix(),"only external composition exposes a render-only lease");
        check(!retained->source_epoch_started(),"no native source epoch before first producer");
        std::array<float,256> values;values.fill(0.25f);
        check(retained->render_add(values.data(),128)==n::Status::pending && values[0]==0.25f,"unstarted submix preserves prior audio");
        auto a=session.open(2),b=session.open(1);auto ra=reference.open(2),rb=reference.open(1);
        check(retained->source_epoch_started(),"native producer publication latches the epoch");
        check(a.status==n::Status::completed && b.status==n::Status::completed,"external streams open without a provider");
        auto left=plane(900),right=plane(-1100),mono=plane(500);
        check(a.producer->copy(left,right)==n::Status::completed && b.producer->copy(mono)==n::Status::completed,"external actual planar copies");
        check(ra->copy(left,right)==n::Status::completed && rb->copy(mono)==n::Status::completed,"same reference planar copies");
        check(a.producer->play(true)==p::Status::completed && b.producer->play(true)==p::Status::completed && ra->play(true)==p::Status::completed && rb->play(true)==p::Status::completed,"same real voice controls");
        check(session.start()==n::Status::completed && reference.session.start()==n::Status::completed,"private admission and actual model provider start");
        check(reference.host->render(128) && retained->render_add(values.data(),128)==n::Status::completed,"external render adds to outer callback audio");
        for(unsigned i=0;i<values.size();++i)check(std::bit_cast<uint32_t>(values[i])==std::bit_cast<uint32_t>(0.25f+reference.host->output[i]),"same private PCM plus existing outer mix");
        check(a.producer->retire()==n::Status::completed,"external per-stream fence");values.fill(-0.125f);
        check(retained->render_add(values.data(),128)==n::Status::completed && values[0]==-0.125f+500.0f/32768,"peer remains audible after external stream retire");
        check(session.join()==n::Status::completed,"private submix fence completes without device join");
        check(retained->source_epoch_started(),"retirement never reopens startup reset admission");
        const auto snapshot=session.snapshot();
        check(snapshot.external_output && snapshot.submix_fenced && snapshot.closed && !snapshot.provider_joined,"private fence never claims outer device retirement");
        check(reference.host->unloads==0 && reference.slot->occupied(),"shared outer device lifetime is independent");
        values.fill(0.5f);check(retained->render_add(values.data(),128)==n::Status::closed && values[0]==0.5f,"joined submix preserves remaining outer audio");
    }
    std::array<float,64> values;values.fill(0.125f);
    check(retained->render_add(values.data(),32)==n::Status::closed && values[0]==0.125f,"retained callback lease outlives private control owner");
}
int main(){external_submix();independent_lifetime();order_and_reference();refusals();concurrent();render_refusal();std::printf("%u shared stream output checks passed; no audio device\n",checks);}
