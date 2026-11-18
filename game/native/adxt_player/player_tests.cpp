#include "player.hpp"
#include "test_provider.hpp"
#include <algorithm>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <cstdio>
#include <cstdlib>
#include <mutex>
#include <thread>
#include <vector>
namespace p=reo::native::adxt_player;
namespace r=reo::native::resources;
namespace o=reo::audio_output;
unsigned checks{};
void check(bool value,const char* text){++checks;if(!value){std::fprintf(stderr,"FAILED: %s\n",text);std::exit(1);}}
struct File: r::ByteView {
    std::vector<std::uint8_t> bytes;mutable std::atomic<unsigned> reads{};
    std::uint64_t size()const noexcept override{return bytes.size();}
    r::ReadResult read(std::uint64_t at,std::span<std::byte> out)const override {
        ++reads;if(at>bytes.size() || out.size()>bytes.size()-at)return{r::Status::invalid_range,0};
        for(std::size_t i=0;i<out.size();++i)out[i]=std::byte(bytes[static_cast<std::size_t>(at)+i]);
        return{r::Status::ok,out.size()};
    }
};
void be16(std::vector<std::uint8_t>& v,std::size_t at,std::uint16_t n){v[at]=static_cast<std::uint8_t>(n>>8);v[at+1]=static_cast<std::uint8_t>(n);}
void be32(std::vector<std::uint8_t>& v,std::size_t at,std::uint32_t n){for(unsigned i=0;i<4;++i)v[at+i]=static_cast<std::uint8_t>(n>>(24-i*8));}
std::shared_ptr<File> file(unsigned ch,unsigned rate,unsigned total){
    auto f=std::make_shared<File>();auto& d=f->bytes;const auto blocks=(total+31)/32*ch;
    d.resize(((96+blocks*18+2047)/2048)*2048);
    be16(d,0,0x8000);be16(d,2,92);d[4]=3;d[5]=18;d[6]=4;d[7]=static_cast<std::uint8_t>(ch);
    be32(d,8,rate);be32(d,12,total);be16(d,16,500);d[18]=3;
    for(unsigned b=0;b<blocks;++b){const auto at=96+b*18;d[at+1]=3;std::fill_n(d.begin()+at+2,16,static_cast<std::uint8_t>(0x11+b%7));}
    return f;
}
using Provider=reo::native::adxt_player::testing::Provider;
p::Config config(const std::shared_ptr<File>& f,unsigned channels){p::Config c;c.decoder.channels=channels;c.decoder.source_config.byte_length=static_cast<std::int32_t>(f->size());return c;}
void retire(p::Player& player){
    for(unsigned n=0;n<10000;++n){const auto result=player.retire_on_control_thread();
        if(result==p::Status::completed){check(player.snapshot().retired,"retired flag");return;}
        check(result==p::Status::pending,"only actual pending join can retry");std::this_thread::sleep_for(std::chrono::milliseconds(1));}
    check(false,"bounded retirement");
}
void finite(){
    for(unsigned ch:{1u,2u})for(unsigned rate:{24000u,44100u,48000u})for(unsigned total:{1u,31u,32u,33u,36u,64u,65u,40017u}){
        auto f=file(ch,rate,total);auto host=std::make_shared<Provider>();
        p::Player player(config(f,ch),f,reo::native::adxt_refill::make_async_backend(8192),std::make_shared<reo::native::adx_header::KeyContext>(),host);
        bool ended=false;
        for(unsigned n=0;n<100000;++n){const auto result=player.service(n/12);
            check(result==p::Status::completed || result==p::Status::waiting_header || result==p::Status::ended,"finite composition advances");
            const auto s=player.snapshot();
            check(!s.fault && (!s.configured || ch==1 || s.output[0].samples==s.output[1].samples),"atomic stereo queued observations");
            if(result==p::Status::ended){ended=true;break;}
            host->step();if(result==p::Status::waiting_header)std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
        check(ended,"actual finite player ended");const auto before=player.snapshot();
        check(before.first_payload_samples==total,"every declared payload sample copied including short tail");
        check(before.output[0].consumed_bytes/2>=total,"output consumer passed every payload sample before end");
        check(ch==1 || before.output[0].consumed_bytes==before.output[1].consumed_bytes,"stereo actual consumption remains paired");
        check(host->sync_zero && host->callbacks>1 && f->reads>0,"real async source and synchronous model callback executed");
        retire(player);const auto after=player.snapshot();
        check(after.provider_joined && after.decoder.source.joined && host->unloaded,"separate provider and actual source joins");
        check(after.output[0].consumed_bytes==before.output[0].consumed_bytes && after.output_statistics.output_frames==before.output_statistics.output_frames,"pre-clear output evidence retained");
        check(player.service(999)==p::Status::closed,"retired service refuses");
    }
}
void failed_fences(){
    auto f=file(2,48000,40017);auto host=std::make_shared<Provider>();host->fail_detach=1;host->fail_stop=1;host->fail_unload=1;
    p::Player player(config(f,2),f,reo::native::adxt_refill::make_async_backend(8192),std::make_shared<reo::native::adx_header::KeyContext>(),host);
    for(unsigned n=0;n<10000 && !player.snapshot().configured;++n){(void)player.service(n);std::this_thread::sleep_for(std::chrono::milliseconds(1));}
    check(player.snapshot().configured,"fence test attached");
    for(unsigned n=0;n<10;++n){(void)player.service(n);std::this_thread::sleep_for(std::chrono::milliseconds(1));}
    const auto retained=player.snapshot();check(retained.output[0].samples>0,"failed-fence test has accepted output");
    player.request_stop();
    for(unsigned i=0;i<3;++i){check(player.retire_on_control_thread()==p::Status::pending,"failed actual provider step retains for retry");
        const auto s=player.snapshot();check(!s.provider_joined && !s.retired && !s.decoder.source.joined,"provider failure cannot clear or join source graph");
        check(!s.decoder.stopped && s.output[0].queued_bytes==retained.output[0].queued_bytes &&
              s.output[0].samples==retained.output[0].samples && s.decoder.pcm.rings[0].data==retained.decoder.pcm.rings[0].data,
              "failed fence preserves both actual PCM queues and decoder admission");}
    retire(player);
    check(host->detaches==2 && host->stops==2 && host->unloads==2,"completed provider steps not repeated");
}
struct Blocked final:File {
    mutable std::mutex mutex;mutable std::condition_variable cv;mutable bool entered{},released{};
    r::ReadResult read(std::uint64_t at,std::span<std::byte> out)const override{
        {std::unique_lock lock(mutex);entered=true;cv.notify_all();cv.wait(lock,[&]{return released;});}
        return File::read(at,out);
    }
};
void blocked_source(){
    auto f=std::make_shared<Blocked>();f->bytes=file(1,48000,40017)->bytes;auto host=std::make_shared<Provider>();
    p::Player player(config(f,1),f,reo::native::adxt_refill::make_async_backend(8192),std::make_shared<reo::native::adx_header::KeyContext>(),host);
    check(player.service(0)==p::Status::waiting_header,"empty live source defers header");
    {std::unique_lock lock(f->mutex);check(f->cv.wait_for(lock,std::chrono::seconds(5),[&]{return f->entered;}),"real provider read entered");}
    player.request_stop();check(player.retire_on_control_thread()==p::Status::pending,"blocked actual source not reported joined");
    check(player.snapshot().provider_joined && !player.snapshot().decoder.source.joined,"provider and source fence identities stay separate");
    {std::lock_guard lock(f->mutex);f->released=true;}f->cv.notify_all();retire(player);
}
void concurrent(){
    auto f=file(2,44100,40017);auto host=std::make_shared<Provider>();
    p::Player player(config(f,2),f,reo::native::adxt_refill::make_async_backend(8192),std::make_shared<reo::native::adx_header::KeyContext>(),host);
    std::atomic<bool> done{};std::thread callback([&]{while(!done.load()){host->step(32);std::this_thread::yield();}});
    bool active=false;
    for(unsigned n=0;n<10000;++n){const auto result=player.service(n);const auto s=player.snapshot();
        check(!s.fault && (!s.configured || s.output[0].samples==s.output[1].samples),"concurrent stereo acceptance/render remains paired");
        if(s.output[0].consumed_bytes){active=true;break;}
        check(result==p::Status::waiting_header || result==p::Status::completed,"concurrent progress");std::this_thread::sleep_for(std::chrono::milliseconds(1));}
    check(active,"real concurrent callback consumed copied output");player.request_stop();retire(player);done=true;callback.join();
    check(host->unloaded && player.snapshot().decoder.source.joined,"concurrent callback and source retired");
}
int main(){finite();failed_fences();blocked_source();concurrent();std::printf("%u native player composition checks passed; no audio device\n",checks);}
