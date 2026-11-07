#include "instances.hpp"
#include "../adxt_shared_player/test_sources.hpp"
#include "../adxt_player/test_provider.hpp"
#include <chrono>
#include <iostream>
#include <thread>
namespace n=reo::native::adxt_instances;
namespace f=reo::native::adxt_shared_player::testing;
using S=n::Status;
unsigned checks{};void check(bool v){++checks;if(!v)throw std::runtime_error("Instance check "+std::to_string(checks));}
template<class F>void until(F&& done){const auto deadline=std::chrono::steady_clock::now()+std::chrono::seconds(15);while(!done()){if(std::chrono::steady_clock::now()>deadline)throw std::runtime_error("Instance completion deadline");std::this_thread::yield();}}
struct Test {
    std::shared_ptr<reo::audio_output::CallbackSlot> slot=std::make_shared<reo::audio_output::CallbackSlot>();
    std::shared_ptr<reo::native::adxt_player::testing::Provider> provider=std::make_shared<reo::native::adxt_player::testing::Provider>();
    n::Instances instances;
    explicit Test(unsigned count=4):instances({{count},{}},slot,provider){check(instances.start_output()==S::completed);}
};
n::Key create(Test& t,unsigned slot,unsigned channels=1){auto result=t.instances.create({channels,{slot,slot,slot,slot}});check(result.status==S::completed);return result.key;}
n::Source source(std::shared_ptr<const reo::native::resources::ByteView> file,unsigned channels=1){n::Source s;s.input=std::move(file);s.player.decoder.channels=channels;s.player.decoder.source_config.byte_length=static_cast<std::int32_t>(s.input->size());s.player.initial_tick=41;return s;}
void service(Test& t){const auto status=t.instances.service(42);check(status==S::completed || status==S::pending);}
void join(Test& t){until([&]{const auto status=t.instances.join();check(status==S::completed || status==S::pending);return status==S::completed;});}
struct Release {
    std::shared_ptr<f::Blocked> file;
    void run(){std::lock_guard lock(file->mutex);file->released=true;file->cv.notify_all();}
    ~Release(){run();}
};
int main(){try{
    {
        Test t;const auto a=create(t,0),b=create(t,1,2);auto& i=t.instances;
        check(i.snapshot().instances==2 && !i.snapshot().session.records);
        check(i.create({1,{0,2,2,2}}).status==S::occupied);
        check(i.gain(a,0.25f)==S::completed && i.pause(a,1,40)==S::completed);
        check(i.start(a,source(f::file(1,48000,20000)))==S::completed);
        check(i.start(b,source(f::file(2,24000,20000),2))==S::completed);
        until([&]{service(t);const auto x=i.inspect(a),y=i.inspect(b);return x.source && y.source && x.source->configured && y.source->configured;});
        check(i.inspect(a).source->clock.paused==1 && i.inspect(a).source->output.voice.gain==0.25f);
        until([&]{service(t);const auto peer=i.inspect(b).source;return peer->output.voice.playing && peer->output.channel[0].samples>=512;});
        check(i.pause(a,0,42)==S::completed);const auto before=i.inspect(b).starts;const auto consumed=i.inspect(b).source->output.channel[0].consumed_bytes;
        const auto stopped=i.stop(a);check(stopped==S::completed || stopped==S::pending);
        until([&]{service(t);return i.inspect(a).phase==n::Phase::idle;});
        check(i.inspect(a).source->decoder.source.joined && i.inspect(a).completed_stops==1);
        check(i.inspect(b).starts==before && !t.provider->unloaded && i.estimate(a,42).status==n::control::Status::pending);
        check(t.provider->step(256) && i.inspect(b).source->output.channel[0].consumed_bytes>consumed);
        check(i.gain(a,1)==S::completed && i.start(a,source(f::file(1,48000,5000)))==S::completed);
        until([&]{service(t);return i.inspect(a).source->configured;});check(i.inspect(a).starts==2);
        const auto destroyed=i.destroy(a);check(destroyed==S::completed || destroyed==S::pending);
        until([&]{service(t);return i.inspect(a).status==S::invalid_key;});
        const auto fresh=create(t,0);check(i.stop(a)==S::invalid_key && i.inspect(fresh).phase==n::Phase::idle);
        check(i.inspect(b).status==S::completed);join(t);check(t.provider->unloaded);
    }
    {
        Test t;auto& i=t.instances;const auto a=create(t,0),b=create(t,1),c=create(t,2);
        auto fa=f::file(1,48000,20000),fb=f::file(1,48000,20000),fc=f::file(1,48000,20000);
        check(i.start(a,source(fa))==S::completed && i.start(b,source(fb))==S::completed && i.start(c,source(fc))==S::completed);
        check(i.service(0)==S::order_required && !fa->reads && !fb->reads && !fc->reads);
        const std::array duplicate{a,a,c};check(i.set_order(duplicate)==S::invalid_key);
        const std::array order{c,b,a};check(i.set_order(order)==S::completed);
        until([&]{service(t);return i.inspect(a).source->configured && i.inspect(b).source->configured && i.inspect(c).source->configured;});
        const auto extra=create(t,3); // Invalidates old admission, then stop three.
        for(const auto& key:order){const auto status=i.stop(key);check(status==S::completed || status==S::pending);}
        until([&]{service(t);return !i.snapshot().retiring;});check(i.inspect(extra).phase==n::Phase::idle);join(t);
    }
    {
        Test t(2);auto& i=t.instances;const auto a=create(t,0),b=create(t,1);
        auto blocked=std::make_shared<f::Blocked>();blocked->bytes=f::file(1,48000,20000)->bytes;Release release{blocked};
        check(i.start(a,source(blocked))==S::completed && i.start(b,source(f::file(1,48000,20000)))==S::completed);
        until([&]{service(t);std::lock_guard lock(blocked->mutex);return blocked->entered;});
        auto skipped=f::file(1,48000,6000),last=f::file(1,48000,7000);
        check(i.start(a,source(skipped))==S::pending && i.start(a,source(last))==S::pending);
        check(!skipped->reads && !last->reads && i.inspect(a).replacement_pending);
        until([&]{service(t);const auto peer=i.inspect(b).source;return peer->output.voice.playing && peer->output.channel[0].samples>=512;});check(!t.provider->unloaded);
        const auto consumed=i.inspect(b).source->output.channel[0].consumed_bytes;
        check(t.provider->step(256) && i.inspect(b).source->output.channel[0].consumed_bytes>consumed);
        release.run();until([&]{service(t);const auto x=i.inspect(a);return x.starts==2 && x.source->configured;});
        check(!skipped->reads && last->reads>0 && i.inspect(a).completed_stops==1);
        check(i.inspect(b).starts==1);join(t);check(t.provider->unloaded && i.inspect(a).status==S::invalid_key);
    }
    {
        std::shared_ptr<n::control::output::Submix> retained;
        {
            n::Instances i(n::control::Config{{2},{}});retained=i.submix();check(bool(retained));
            const auto a=i.create({1,{0,0,0,0}}),b=i.create({2,{1,1,1,1}});
            check(a.status==S::completed && b.status==S::completed && i.start_output()==S::completed);
            check(i.start(a.key,source(f::file(1,48000,20000)))==S::completed && i.start(b.key,source(f::file(2,24000,20000),2))==S::completed);
            const auto work=[&]{const auto s=i.service(42);check(s==S::completed || s==S::pending);};
            until([&]{work();const auto x=i.inspect(a.key).source,y=i.inspect(b.key).source;return x && y && x->output.voice.playing && y->output.voice.playing && x->output.channel[0].samples>=512 && y->output.channel[0].samples>=512;});
            const auto before=i.inspect(b.key).source->output.channel[0].consumed_bytes;
            std::array<float,512> output{};check(retained->render_add(output.data(),256)==n::control::output::Status::completed);
            check(i.inspect(a.key).source->output.channel[0].consumed_bytes>0 && i.inspect(b.key).source->output.channel[0].consumed_bytes>before);
            const auto stopped=i.stop(a.key);check(stopped==S::completed || stopped==S::pending);
            until([&]{work();return i.inspect(a.key).phase==n::Phase::idle;});
            check(i.inspect(b.key).source->output.voice.playing && retained->render_add(output.data(),256)==n::control::output::Status::completed);
            until([&]{const auto s=i.join();check(s==S::completed || s==S::pending);return s==S::completed;});
            const auto snapshot=i.snapshot().session;check(snapshot.joined && snapshot.output.external_output && snapshot.output.submix_fenced && !snapshot.output.provider_joined);
        }
        std::array<float,64> output;output.fill(0.25f);
        check(retained->render_add(output.data(),32)==n::control::output::Status::closed && output[0]==0.25f);
    }
    std::cout<<"Native stable ADXT instance checks "<<checks<<" passed\n";return 0;
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}}
