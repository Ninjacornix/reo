#include "owner.hpp"
#include "../adxt_shared_player/test_sources.hpp"
#include <algorithm>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <cstdio>
#include <cstdlib>
#include <future>
#include <mutex>
#include <thread>

namespace n=reo::native::adxt_control_owner;
namespace i=n::instances;
namespace f=reo::native::adxt_shared_player::testing;
using namespace std::chrono_literals;
std::atomic<unsigned> checks{};
void check(bool ok,const char* why){++checks;if(!ok){std::fprintf(stderr,"FAILED control owner: %s\n",why);std::exit(1);}}
template<class F>struct Operation final:n::Operation {
    F fn;explicit Operation(F work):fn(std::move(work)){}
    void run(i::Instances& value)noexcept override{fn(value);}
};
template<class F>struct EmptyOperation final:n::EmptyOperation {
    F fn;explicit EmptyOperation(F work):fn(std::move(work)){}
    void run(const n::Quiescent& proof)noexcept override{fn(proof);}
};
template<class F>void until(F&& done){const auto end=std::chrono::steady_clock::now()+15s;while(!done()){check(std::chrono::steady_clock::now()<end,"bounded test completion");std::this_thread::yield();}}
struct Gate {
    std::mutex mutex;std::condition_variable cv;bool entered{},released{};
    void block(){std::unique_lock lock(mutex);entered=true;cv.notify_all();check(cv.wait_for(lock,10s,[&]{return released;}),"test operation release");}
    void wait(){std::unique_lock lock(mutex);check(cv.wait_for(lock,5s,[&]{return entered;}),"accepted operation entered");}
    void release(){std::lock_guard lock(mutex);released=true;cv.notify_all();}
};
i::Source source(std::shared_ptr<const reo::native::resources::ByteView> bytes,unsigned channels){
    i::Source result;result.input=std::move(bytes);result.player.decoder.channels=channels;
    result.player.decoder.source_config.byte_length=static_cast<std::int32_t>(result.input->size());return result;
}
void reentry(){
    n::Owner owner(i::control::Config{{1},{}}),other(i::control::Config{{1},{}});
    check(n::Owner::join_allowed_on_current_thread(),"outer owner can prepare a join outside controls");
    unsigned effects{};Operation nested([&](auto&){++effects;});
    Operation outer([&](auto&){
        check(!n::Owner::join_allowed_on_current_thread(),"outer owner can reject join before device effects");
        check(owner.run(nested)==n::Admission::busy && other.run(nested)==n::Admission::busy,"same and cross-owner nested controls refuse");
        check(owner.join()==n::Join::busy && other.join()==n::Join::busy,"all scoped joins refuse before locks");
        check(!owner.report().stopping && !other.report().stopping,"refused join never closes admission");
    });
    check(owner.run(outer)==n::Admission::accepted && effects==0,"borrow completed without nested effects");
    check(n::Owner::join_allowed_on_current_thread(),"join eligibility restores after control borrow");
    check(other.run(nested)==n::Admission::accepted && effects==1,"separate owner remains usable after refusal");
    check(owner.report().scoped_join_refused==1 && other.report().scoped_join_refused==1,"scoped join refusal diagnostics");
    check(owner.join()==n::Join::completed && owner.join()==n::Join::completed && other.join()==n::Join::completed,"idle joins are idempotent");
}
void serialization(){
    n::Owner owner(i::control::Config{{1},{}});Gate gate;std::atomic<unsigned> active{},second_effects{};
    Operation first([&](auto&){check(++active==1,"first control exclusively admitted");gate.block();--active;});
    Operation second([&](auto&){check(++active==1,"second control exclusively admitted");++second_effects;--active;});
    auto a=std::async(std::launch::async,[&]{return owner.run(first);});gate.wait();
    auto b=std::async(std::launch::async,[&]{return owner.run(second);});until([&]{return owner.report().waiting==1;});
    check(second_effects==0,"waiting control has no effects");gate.release();
    check(a.get()==n::Admission::accepted && b.get()==n::Admission::accepted && second_effects==1 && !active,"both controls serialize without shutdown");
    check(owner.join()==n::Join::completed && owner.report().waiting==0,"serialized owner joins");
}
void source_shutdown(){
    std::shared_ptr<i::control::output::Submix> retained;
    {
        n::Owner owner(i::control::Config{{2},{}});retained=owner.submix();
        auto blocked=std::make_shared<f::Blocked>();blocked->bytes=f::file(1,48000,20000)->bytes;
        auto peer=f::file(2,48000,20000);i::Key a,b;
        Operation start([&](auto& players){
            check(players.start_output()==i::Status::completed,"private admission starts");
            const auto x=players.create({1,{0,0,0,0}}),y=players.create({2,{1,1,1,1}});
            check(x.status==i::Status::completed && y.status==i::Status::completed,"canonical instances created");a=x.key;b=y.key;
            check(players.start(a,source(blocked,1))==i::Status::completed && players.start(b,source(peer,2))==i::Status::completed,"actual source workers start");
        });
        check(owner.run(start)==n::Admission::accepted,"source setup borrow");
        bool ready{};Operation service([&](auto& players){
            const auto work=players.service(7);check(work==i::Status::completed || work==i::Status::pending,"canonical service progress");
            const auto state=players.inspect(b);check(state.source && !state.source->fault,"peer actual source state");
            std::lock_guard lock(blocked->mutex);ready=blocked->entered && state.source->output.voice.playing && state.source->output.channel[0].samples>=1024;
        });
        until([&]{check(owner.run(service)==n::Admission::accepted,"service borrow admitted");return ready;});
        std::array<float,512> samples{};check(retained->render_add(samples.data(),256)==i::control::output::Status::completed && std::any_of(samples.begin(),samples.end(),[](float v){return v!=0;}),"actual peer callback renders while first source is blocked");
        Gate gate;Operation accepted([&](auto&){gate.block();});unsigned late_effects{};Operation late([&](auto&){++late_effects;});
        auto active=std::async(std::launch::async,[&]{return owner.run(accepted);});gate.wait();
        auto queued=std::async(std::launch::async,[&]{return owner.run(late);});until([&]{return owner.report().waiting==1;});
        owner.request_stop();check(owner.report().stopping && !owner.report().joined,"signal-only stop does not invent retirement");
        check(owner.run(late)==n::Admission::closed && late_effects==0,"new control refuses without waiting on active borrow");
        auto joining=std::async(std::launch::async,[&]{return owner.join();});
        check(joining.wait_for(20ms)==std::future_status::timeout,"join waits for accepted control");
        check(retained->render_add(samples.data(),0)==i::control::output::Status::completed,"source shutdown cannot pass the accepted-control fence");gate.release();
        check(active.get()==n::Admission::accepted && queued.get()==n::Admission::closed && !late_effects,"caller queued before stop is rechecked before effects");
        until([&]{return retained->render_add(samples.data(),0)==i::control::output::Status::closed;});
        check(joining.wait_for(20ms)==std::future_status::timeout && !owner.report().joined,"closing submix is not source join proof");
        {std::lock_guard lock(blocked->mutex);blocked->released=true;blocked->cv.notify_all();}
        check(joining.wait_for(5s)==std::future_status::ready && joining.get()==n::Join::completed,"actual blocked source acknowledges shutdown");
        const auto report=owner.report();check(report.joined && report.final && !report.final->instances && !report.final->session.records && report.final->session.joined,"canonical source state actually retired");
        check(report.final->session.output.submix_fenced && !report.final->session.output.provider_joined && report.final->session.output.statistics.output_frames==256,"private fence is separate from device ownership");
        check(owner.run(late)==n::Admission::closed && owner.join()==n::Join::completed && !late_effects,"closed owner remains closed and repeat join is safe");
    }
    std::array<float,64> samples;samples.fill(0.25f);
    check(retained->render_add(samples.data(),32)==i::control::output::Status::closed && std::all_of(samples.begin(),samples.end(),[](float v){return v==0.25f;}),"render lease safely outlives controller destruction");
}
void quiescent_reset(){
    n::Owner owner(i::control::Config{{1},{}}),other(i::control::Config{{1},{}});unsigned resets{};
    EmptyOperation reset([&](const n::Quiescent& proof){
        check(proof.authorizes(owner.submix()) && !proof.authorizes(other.submix()) && !proof.authorizes({}),"only same submix has a scoped reset proof");
        bool foreign{};std::thread probe([&]{foreign=proof.authorizes(owner.submix());});probe.join();check(!foreign,"reset proof is thread-bound");
        Operation nested([](auto&){});check(owner.run(nested)==n::Admission::busy && other.run(nested)==n::Admission::busy,"quiescent reset excludes nested source admission");
        check(owner.join()==n::Join::busy && !owner.report().stopping,"quiescent reset cannot join or close its owner");++resets;
    });
    check(owner.when_empty(reset)==n::Empty::completed && resets==1,"cold empty owner admits reset");
    i::Key key;Operation create([&](auto& p){check(p.start_output()==i::Status::completed,"start reset fixture submix");auto made=p.create({1,{0,0,0,0}});check(made.status==i::Status::completed,"create reset fixture instance");key=made.key;});
    check(owner.run(create)==n::Admission::accepted && owner.when_empty(reset)==n::Empty::occupied && resets==1,"idle constructed handle excludes reset");
    auto blocked=std::make_shared<f::Blocked>();blocked->bytes=f::file(1,48000,20000)->bytes;
    Operation start([&](auto& p){check(p.start(key,source(blocked,1))==i::Status::completed && p.service(7)==i::Status::completed,"start real reset fixture source");});
    check(owner.run(start)==n::Admission::accepted,"admit reset fixture source");
    {std::unique_lock lock(blocked->mutex);check(blocked->cv.wait_for(lock,5s,[&]{return blocked->entered;}),"actual read entered before retirement");}
    Operation destroy([&](auto& p){check(p.destroy(key)==i::Status::pending && !p.snapshot().session.output.occupied && p.snapshot().instances==1,"output fence is NOT actual source join");});
    check(owner.run(destroy)==n::Admission::accepted && owner.when_empty(reset)==n::Empty::occupied && resets==1,"blocked retiring source excludes reset despite empty output");
    {std::lock_guard lock(blocked->mutex);blocked->released=true;blocked->cv.notify_all();}
    bool retired{};Operation service([&](auto& p){const auto result=p.service(7);check(result==i::Status::completed || result==i::Status::pending,"advance joined destruction");retired=p.inspect(key).status==i::Status::invalid_key;});
    until([&]{check(owner.run(service)==n::Admission::accepted,"admit ordinary destruction service");return retired;});
    check(owner.when_empty(reset)==n::Empty::completed && resets==2,"actual joined destruction admits later reset");
    Gate gate;EmptyOperation paused([&](const n::Quiescent& proof){check(proof.authorizes(owner.submix()),"serialized reset starts with proof");gate.block();});
    auto resetting=std::async(std::launch::async,[&]{return owner.when_empty(paused);});gate.wait();
    unsigned created{};Operation late([&](auto& p){auto made=p.create({1,{0,0,0,0}});check(made.status==i::Status::completed,"later source creates after reset");++created;});
    auto creating=std::async(std::launch::async,[&]{return owner.run(late);});until([&]{return owner.report().waiting==1;});
    check(!created,"source creation cannot cross quiescent reset");gate.release();
    check(resetting.get()==n::Empty::completed && creating.get()==n::Admission::accepted && created==1,"reset and later source serialize");
    owner.request_stop();check(owner.when_empty(reset)==n::Empty::closed && resets==2,"closed reset refuses before callback");
    check(owner.join()==n::Join::completed && other.join()==n::Join::completed,"reset fixture joins");
}
int main(){reentry();serialization();source_shutdown();quiescent_reset();std::printf("%u native controller admission/source fence checks passed; no device\n",checks.load());}
