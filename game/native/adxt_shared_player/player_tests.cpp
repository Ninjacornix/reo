#include "player.hpp"
#include "test_sources.hpp"
#include "../adxt_player/test_provider.hpp"
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <stdexcept>
#include <thread>
namespace p=reo::native::adxt_shared_player;
namespace t=p::testing;
namespace o=reo::native::adxt_output_session;
unsigned checks{};
void check(bool value,const char* text){++checks;if(!value){std::fprintf(stderr,"FAILED: %s\n",text);std::exit(1);}}
struct Output {
    std::shared_ptr<reo::audio_output::CallbackSlot> slot=std::make_shared<reo::audio_output::CallbackSlot>();
    std::shared_ptr<reo::native::adxt_player::testing::Provider> host=std::make_shared<reo::native::adxt_player::testing::Provider>();
    o::Session session;
    explicit Output(o::Config c={2}):session(c,slot,host){}
};
p::Config config(const std::shared_ptr<t::File>& file,unsigned channels){p::Config c;c.decoder.channels=channels;c.decoder.source_config.byte_length=static_cast<std::int32_t>(file->size());return c;}
std::unique_ptr<p::Player> player(Output& output,std::shared_ptr<t::File> file,unsigned channels){
    auto producer=output.session.open(channels);check(producer.status==o::Status::completed,"stream producer opened");
    return std::make_unique<p::Player>(config(file,channels),std::move(producer.producer),file,
        reo::native::adxt_refill::make_async_backend(8192),std::make_shared<reo::native::adx_header::KeyContext>());
}
void retire(p::Player& player){
    for(unsigned n=0;n<10000;++n){const auto status=player.retire_on_control_thread();
        if(status==p::Status::completed){const auto s=player.snapshot();check(s.retired && s.output_retired && s.decoder.source.joined,"actual stream/source retired");return;}
        check(status==p::Status::pending,"actual source fence remains pending");std::this_thread::yield();}
    check(false,"bounded source retirement");
}
void finite(){
    Output output;check(output.session.start()==o::Status::completed,"one session provider starts before players");
    for(unsigned channels:{1u,2u})for(unsigned rate:{24000u,44100u,48000u})for(unsigned total:{1u,31u,32u,33u,36u,64u,65u,40017u}){
        auto stream=player(output,t::file(channels,rate,total),channels);bool ended=false;
        for(unsigned n=0;n<100000;++n){const auto result=stream->service(0);const auto s=stream->snapshot();
            check(result==p::Status::completed || result==p::Status::waiting_header || result==p::Status::ended,"finite shared player advances");
            check(!s.fault && (channels==1 || s.output.channel[0].samples==s.output.channel[1].samples),"shared stereo counts paired");
            if(result==p::Status::ended){ended=true;break;}
            if(s.output.channel[0].samples>=64)output.host->step(64);
            if(result==p::Status::waiting_header)std::this_thread::yield();
        }
        check(ended && stream->snapshot().first_payload_samples==total,"shared output contains every finite payload sample");
        check(stream->snapshot().output.channel[0].consumed_bytes/2>=total,"actual output consumption passed payload");
        retire(*stream);check(output.host->detaches==0 && output.host->unloads==0 && output.slot->occupied(),"per-resource completion never joins shared provider");
        check(output.session.snapshot().occupied==0,"slot available for next resource");
    }
    check(output.session.join()==o::Status::completed && output.host->detaches==1 && output.host->stops==1 && output.host->unloads==1,"all48 resources share one provider lifetime");
}
void peer_lifetime(){
    Output output;auto a=player(output,t::file(2,48000,40017),2),b=player(output,t::file(1,24000,80001),1);
    const std::array<const o::Producer*,2> order{&b->output_identity(),&a->output_identity()};
    check(output.session.set_order(order)==o::Status::completed && output.session.start()==o::Status::completed,"read-only player identities coordinate actual order");
    for(unsigned n=0;n<10000;++n){(void)a->service(0);(void)b->service(0);output.host->step(64);
        if(b->snapshot().output.channel[0].consumed_bytes && a->snapshot().output.channel[0].consumed_bytes)break;
        std::this_thread::yield();}
    const auto before=b->snapshot();check(before.output.channel[0].consumed_bytes>0,"peer is consuming actual PCM");
    a->request_stop();retire(*a);
    for(unsigned n=0;n<1000 && b->snapshot().output.channel[0].consumed_bytes==before.output.channel[0].consumed_bytes;++n){
        check(b->service(0)!=p::Status::fault,"peer survives other source join");output.host->step(64);std::this_thread::yield();}
    check(b->snapshot().output.channel[0].consumed_bytes>before.output.channel[0].consumed_bytes && b->snapshot().output.active,"peer continues through shared renderer");
    check(!output.host->detaches && output.slot->occupied(),"peer source join does not touch provider");
    retire(*b);check(output.session.join()==o::Status::completed,"peer session closes last");
}
void blocked_peer(){
    Output output;auto blocked=std::make_shared<t::Blocked>();blocked->bytes=t::file(1,48000,40017)->bytes;
    auto a=player(output,blocked,1),b=player(output,t::file(1,48000,40017),1);
    check(output.session.start()==o::Status::completed,"blocked peer session starts");
    check(a->service(0)==p::Status::waiting_header,"blocked source waits for actual worker");
    {std::unique_lock lock(blocked->mutex);check(blocked->cv.wait_for(lock,std::chrono::seconds(5),[&]{return blocked->entered;}),"actual source read blocked");}
    a->request_stop();check(a->retire_on_control_thread()==p::Status::pending && a->snapshot().output_retired && !a->snapshot().decoder.source.joined,"output stream fenced while actual source remains pending");
    for(unsigned n=0;n<10000 && !b->snapshot().output.channel[0].consumed_bytes;++n){
        check(b->service(0)!=p::Status::fault,"peer services while other worker blocked");output.host->step(64);std::this_thread::yield();}
    check(b->snapshot().output.channel[0].consumed_bytes>0 && !output.host->detaches,"shared audio progresses independently of blocked source");
    {std::lock_guard lock(blocked->mutex);blocked->released=true;}blocked->cv.notify_all();retire(*a);retire(*b);
    check(output.session.join()==o::Status::completed,"blocked peer graph finally joins");
}
void failure(){
    Output output({2,128});auto stream=player(output,t::file(2,48000,40017),2);bool fault=false;
    for(unsigned n=0;n<10000;++n){if(stream->service(0)==p::Status::fault){fault=true;break;}std::this_thread::yield();}
    const auto s=stream->snapshot();check(fault && s.decoder.pcm.read_id!=0,"actual refused output copy retains decoder read lease");
    check(s.output.channel[0].samples==0 && s.output.channel[1].samples==0,"refused whole stereo batch published neither channel");
    retire(*stream);check(!output.host->detaches,"faulted source retires without global output reset");
    auto prepared=output.session.open(1);check(prepared.status==o::Status::completed,"constructor failure has prepared producer");
    bool rejected=false;try{auto file=t::file(2,48000,32);p::Player invalid(config(file,2),std::move(prepared.producer),file,
        reo::native::adxt_refill::make_async_backend(8192),std::make_shared<reo::native::adx_header::KeyContext>());}catch(const std::invalid_argument&){rejected=true;}
    check(rejected && output.session.snapshot().occupied==0,"constructor failure retires consumed producer without orphaning");
    check(output.session.join()==o::Status::completed,"failed graph session closes");
}
int main(){finite();peer_lifetime();blocked_peer();failure();std::printf("%u shared player composition checks passed; no audio device\n",checks);}
