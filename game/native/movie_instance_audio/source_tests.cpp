#include "source.hpp"
#include "../adxt_shared_player/test_sources.hpp"
#include <algorithm>
#include <array>
#include <chrono>
#include <condition_variable>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <future>
#include <mutex>
#include <thread>

namespace n=reo::native::movie_instance_audio;
namespace a=n::audio;
namespace o=n::owner;
namespace i=n::instances;
namespace f=reo::native::adxt_shared_player::testing;
using P=a::ProviderStatus;
using namespace std::chrono_literals;
std::atomic<unsigned> checks{};
void check(bool value,const char* why){++checks;if(!value){std::fprintf(stderr,"FAILED movie instance audio: %s\n",why);std::exit(1);}}
template<class F>struct Borrow final:o::Operation {
    F work;explicit Borrow(F value):work(std::move(value)){}
    void run(i::Instances& players)noexcept override{work(players);}
};
template<class F>void until(F&& done){const auto end=std::chrono::steady_clock::now()+10s;while(!done()){check(std::chrono::steady_clock::now()<end,"bounded real worker progress");std::this_thread::yield();}}
struct Tick final:a::ServiceTick {
    unsigned calls{};std::uint32_t value{17};P result{P::completed};std::function<void()> during;
    P read(std::uint32_t& out)noexcept override{++calls;if(during)during();if(result==P::completed)out=value;return result;}
};
i::Source input(std::shared_ptr<const reo::native::resources::ByteView> bytes,unsigned channels=1){
    i::Source source;source.input=std::move(bytes);source.player.decoder.channels=channels;
    source.player.decoder.source_config.byte_length=static_cast<std::int32_t>(source.input->size());return source;
}
struct Fixture {
    std::shared_ptr<o::Owner> owner=std::make_shared<o::Owner>(i::control::Config{{2},{}});
    std::shared_ptr<Tick> tick=std::make_shared<Tick>();i::Key key,peer;
    Fixture(){run([&](auto& p){
        check(p.start_output()==i::Status::completed,"start existing private output");
        auto own=p.create({1,{0,0,0,0}}),other=p.create({2,{1,1,1,1}});
        check(own.status==i::Status::completed && other.status==i::Status::completed,"create two canonical instances");key=own.key;peer=other.key;
    });}
    template<class F>void run(F&& fn){Borrow op(std::forward<F>(fn));check(owner->run(op)==o::Admission::accepted,"canonical operation accepted");}
    void start(std::shared_ptr<const reo::native::resources::ByteView> bytes=f::file(1,48000,120000)){
        run([&](auto& p){check(p.start(key,input(std::move(bytes)))==i::Status::completed,"start source worker");check(p.start(peer,input(f::file(2,48000,120000),2))==i::Status::completed,"start independent stereo peer");});
    }
    void ready(){until([&]{bool ready{};run([&](auto& p){const auto work=p.service(17);check(work==i::Status::completed || work==i::Status::pending,"service actual sources");
        const auto x=p.inspect(key),y=p.inspect(peer);check(x.source && y.source && !x.source->fault && !y.source->fault,"actual source observations");
        ready=x.source->output.voice.playing && y.source->output.voice.playing && x.source->output.channel[0].samples>=1024 && y.source->output.channel[0].samples>=1024;});return ready;});}
    std::shared_ptr<a::ControlledSource> capture(){auto c=n::Source::capture(owner,key,tick);check(c.status==P::completed && c.source,"capture actual current source");return c.source;}
    void replace(){run([&](auto& p){const auto result=p.start(key,input(f::file(1,48000,120000)));check(result==i::Status::completed || result==i::Status::pending,"replacement requested");});
        until([&]{bool replaced{};run([&](auto& p){const auto result=p.service(17);check(result==i::Status::completed || result==i::Status::pending,"advance actual source retirement");const auto s=p.inspect(key);replaced=s.starts==2 && s.source && s.source->configured;});return replaced;});}
    void close(){check(owner->join()==o::Join::completed,"join actual source workers/private output");}
};
void capture_and_early_phase(){
    Fixture t;
    check(n::Source::capture({},t.key,t.tick).status==P::invalid_key && n::Source::capture(t.owner,t.key,{}).status==P::invalid_key,"null owner/tick refuses");
    check(n::Source::capture(t.owner,{},t.tick).status==P::invalid_key && n::Source::capture(t.owner,t.key,t.tick).status==P::closed,"foreign/idle source refuses");
    auto blocked=std::make_shared<f::Blocked>();blocked->bytes=f::file(1,48000,120000)->bytes;t.start(blocked);
    auto source=t.capture();std::uint8_t phase=99;std::uint32_t frequency=99;
    check(source->status(phase)==P::completed && phase==1 && source->sample_frequency(frequency)==P::completed && frequency==0,"before-header phase and zero frequency");
    t.run([&](auto&){check(n::Source::capture(t.owner,t.key,t.tick).status==P::busy,"nested capture refused");phase=99;check(source->status(phase)==P::busy && phase==99,"nested query refuses without output");});
    check(!t.tick->calls,"metadata and rejected capture never read service tick");
    {std::lock_guard lock(blocked->mutex);blocked->released=true;blocked->cv.notify_all();}
    t.ready();check(source->status(phase)==P::completed && phase==3 && source->sample_frequency(frequency)==P::completed && frequency==48000,"same source acquires actual header frequency");
    check(!t.tick->calls,"ready metadata is also tick-free");t.close();
}
void controls_and_peer(){
    Fixture t;t.start();t.ready();auto source=t.capture();i::control::ClockResult expected;
    t.run([&](auto& p){expected=p.estimate(t.key,t.tick->value);});a::Words words{77,88};
    check(expected.status==i::control::Status::completed && source->estimate(words)==P::completed && words.numerator==expected.value.result.ratio.numerator && words.denominator==expected.value.result.ratio.denominator,"movie estimate is existing native clock ratio");
    check(t.tick->calls==1 && source->pause(1)==P::completed && t.tick->calls==2,"pause uses actual tick once");
    std::uint64_t own_bytes{},peer_bytes{},visits{},diagnostics{};
    t.run([&](auto& p){auto own=p.inspect(t.key).source,peer=p.inspect(t.peer).source;check(own->clock.paused==1 && !own->output.voice.playing && peer->output.voice.playing,"pause affects only selected source");own_bytes=own->output.channel[0].consumed_bytes;peer_bytes=peer->output.channel[0].consumed_bytes;visits=p.snapshot().session.group_visits;diagnostics=p.snapshot().session.discard_diagnostics;});
    std::array<float,128> output{};check(t.owner->submix()->render_add(output.data(),64)==i::control::output::Status::completed && std::any_of(output.begin(),output.end(),[](float x){return x!=0;}),"private callback keeps rendering peer");
    t.run([&](auto& p){check(p.inspect(t.key).source->output.channel[0].consumed_bytes==own_bytes && p.inspect(t.peer).source->output.channel[0].consumed_bytes==peer_bytes+128,"paused source stays still while peer advances");});
    std::uint32_t result=99;check(source->discard(UINT32_MAX,result)==P::completed && result==0,"discard argument is unused original zero result");
    t.run([&](auto& p){check(p.snapshot().session.group_visits==visits+1 && p.snapshot().session.discard_diagnostics==diagnostics+1,"paused discard services same canonical group exactly once");});
    check(source->pause(2)==P::completed,"raw pause two accepted");t.run([&](auto& p){check(p.inspect(t.key).source->clock.paused==2,"raw pause word preserved");});
    t.replace();std::uint8_t phase=99;const auto ticks=t.tick->calls;check(source->status(phase)!=P::completed && phase==99 && t.tick->calls==ticks,"old source capability expires on replacement");
    auto replacement=t.capture();t.run([&](auto& p){check(p.inspect(t.key).source->clock.paused==2,"capability pause persists to stable instance replacement");});
    check(replacement->pause(0)==P::completed,"replacement resumes through fresh capability");
    t.run([&](auto& p){check(p.inspect(t.key).source->clock.paused==0,"resume changes selected canonical source");visits=p.snapshot().session.group_visits;diagnostics=p.snapshot().session.discard_diagnostics;});
    result=99;check(replacement->discard(123,result)==P::completed && result==0,"unpaused discard completes");
    t.run([&](auto& p){check(p.snapshot().session.group_visits==visits && p.snapshot().session.discard_diagnostics==diagnostics,"unpaused discard does not service group");});t.close();
}
void stale_and_reuse(){
    Fixture t;t.start();t.ready();auto source=t.capture();
    t.run([&](auto& p){const auto result=p.stop(t.key);check(result==i::Status::completed || result==i::Status::pending,"stop source");});
    const auto ticks=t.tick->calls;std::uint8_t phase=99;std::uint32_t scalar=99;a::Words words{77,88};
    check(source->status(phase)!=P::completed && phase==99 && source->estimate(words)!=P::completed && words.numerator==77 && words.denominator==88,"stopped queries retain output sentinels");
    check(source->sample_frequency(scalar)!=P::completed && scalar==99 && source->pause(0)!=P::completed && source->discard(123,scalar)!=P::completed && scalar==99 && t.tick->calls==ticks,"stopped controls refuse before tick or effects");
    until([&]{bool destroyed{};t.run([&](auto& p){const auto s=p.destroy(t.key);check(s==i::Status::completed || s==i::Status::pending,"destroy stopped public instance");const auto work=p.service(17);check(work==i::Status::completed || work==i::Status::pending,"retire destroyed instance");destroyed=p.inspect(t.key).status==i::Status::invalid_key;});return destroyed;});
    t.run([&](auto& p){auto fresh=p.create({1,{0,0,0,0}});check(fresh.status==i::Status::completed,"reuse joined public slot");t.key=fresh.key;check(p.start(t.key,input(f::file(1,48000,120000)))==i::Status::completed,"reused slot starts new source");});
    t.ready();auto fresh=t.capture();check(source->status(phase)==P::invalid_key && phase==99 && fresh->status(phase)==P::completed,"stable instance generation also invalidates old capability");
    t.close();phase=99;check(fresh->status(phase)==P::closed && phase==99 && t.tick->calls==ticks,"retained capability does not obstruct real joined shutdown");
}
void tick_boundary(){
    Fixture t;t.start();t.ready();auto source=t.capture();a::Words words{77,88};
    t.tick->result=P::fault;check(source->estimate(words)==P::fault && words.numerator==77 && words.denominator==88,"tick failure preserves output");
    t.tick->result=P::completed;t.tick->during=[&]{
        check(o::Owner::join_allowed_on_current_thread(),"tick sampled outside every canonical borrow");
        a::Words nested{11,22};check(source->estimate(nested)==P::busy && nested.numerator==11,"same provider reentry refuses before tick");
        t.replace();
    };
    check(source->estimate(words)!=P::completed && words.numerator==77 && words.denominator==88,"replacement during tick rechecked before estimate effects");t.tick->during={};
    source=t.capture();t.tick->during=[&]{t.owner->request_stop();};
    check(source->pause(1)==P::closed,"shutdown during tick rechecked before pause effects");t.tick->during={};
    const auto calls=t.tick->calls;check(source->estimate(words)==P::closed && t.tick->calls==calls,"closed owner refuses before tick");t.close();
}
void retained_during_call(){
    Fixture t;t.start();t.ready();auto source=t.capture();std::weak_ptr<a::ControlledSource> weak=source;auto* raw=source.get();
    t.tick->during=[&]{source.reset();check(!weak.expired(),"accepted provider call retains itself across tick");};
    a::Words words;check(raw->estimate(words)==P::completed && weak.expired(),"provider safely retires after accepted call returns");t.tick->during={};t.close();
}
void queued_shutdown(){
    Fixture t;t.start();t.ready();auto source=t.capture();std::mutex mutex;std::condition_variable cv;bool entered{},release{};
    Borrow hold([&](auto&){std::unique_lock lock(mutex);entered=true;cv.notify_all();check(cv.wait_for(lock,5s,[&]{return release;}),"release accepted owner operation");});
    auto held=std::async(std::launch::async,[&]{return t.owner->run(hold);});
    {std::unique_lock lock(mutex);check(cv.wait_for(lock,5s,[&]{return entered;}),"accepted operation entered");}
    std::uint8_t phase=99;auto pending=std::async(std::launch::async,[&]{return source->status(phase);});until([&]{return t.owner->report().waiting==1;});
    t.owner->request_stop();{std::lock_guard lock(mutex);release=true;cv.notify_all();}
    check(held.get()==o::Admission::accepted && pending.get()==P::closed && phase==99 && !t.tick->calls,"queued query is rechecked at shutdown without tick/output");t.close();
}
int main(){capture_and_early_phase();controls_and_peer();stale_and_reuse();tick_boundary();retained_during_call();queued_shutdown();std::printf("%u canonical movie/audio capability checks; real workers/private output, no device or game\n",checks.load());}
