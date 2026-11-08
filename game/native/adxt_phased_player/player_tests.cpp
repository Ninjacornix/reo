#include "test_group.hpp"
#include "../adxt_shared_player/test_sources.hpp"
#include "../adxt_player/test_provider.hpp"
#include <algorithm>
#include <array>
#include <chrono>
#include <iostream>
#include <thread>

namespace p=reo::native::adxt_phased_player;
namespace o=reo::native::adxt_output_session;
namespace s=reo::native::adxt_shared_player::testing;
namespace w=reo::native::adxt_phased_player::window;
namespace control=reo::native::adxt_service_group;
unsigned checks{};
void require(bool b){++checks;if(!b)throw std::runtime_error("Phased player check "+std::to_string(checks));}
struct Output {
    std::shared_ptr<reo::audio_output::CallbackSlot> slot=std::make_shared<reo::audio_output::CallbackSlot>();
    std::shared_ptr<reo::native::adxt_player::testing::Provider> provider=std::make_shared<reo::native::adxt_player::testing::Provider>();
    o::Session owner;
    explicit Output(unsigned n=2,std::uint64_t counter=UINT64_MAX):owner({n,counter},slot,provider){require(owner.start()==o::Status::completed);}
};
std::shared_ptr<p::Player> make(Output& output,p::testing::Driver& driver,unsigned channels,unsigned rate,unsigned total){
    auto source=s::file(channels,rate,total);auto producer=output.owner.open(channels);require(producer.status==o::Status::completed);
    p::Config config;config.decoder.channels=channels;config.decoder.source_config.byte_length=static_cast<std::int32_t>(source->size());
    return std::make_shared<p::Player>(config,std::move(producer.producer),source,reo::native::adxt_refill::make_async_backend(8192),std::make_shared<reo::native::adx_header::KeyContext>(),driver.shared);
}
void step(p::testing::Driver& driver,std::span<const std::shared_ptr<p::Player>> players,std::uint32_t tick=0){
    for(const auto& player:players){if(!player->active())continue;require(player->set_tick(tick)==p::Status::completed);require(player->service_source()==p::Status::completed);}
    require(driver.group.service()==control::Status::completed);
    require(!driver.guards->fault && !driver.guards->cri && !driver.guards->rna && !driver.guards->chunk && !driver.shared->service_busy);
    for(const auto& player:players)require(!player->snapshot().fault);
}
void retire(std::shared_ptr<p::Player> player){
    player->request_stop();require(!player->active());
    for(unsigned i=0;i<10000;++i){const auto result=player->retire_on_control_thread();
        if(result==p::Status::completed){require(player->snapshot().decoder.source.joined && player->snapshot().output_retired);return;}
        require(result==p::Status::pending);std::this_thread::yield();}
    throw std::runtime_error("Native source did not join");
}
int main(){try{
    {
        Output out;p::testing::Driver driver;auto player=make(out,driver,2,48000,8192);p::testing::Driver::Binding binding;
        driver.attach(binding,player,{15,0,7,31});require(player->service_transfer()==p::Status::waiting_header);
        const auto initial_source=player->snapshot().decoder.source;
        require(driver.group.service()==control::Status::completed);auto before=player->snapshot();
        require(before.service_visits[0]==0 && before.service_visits[1]==1 && before.service_visits[2]==1 && before.service_visits[3]==1 && before.service_visits[4]==2);
        require(!before.configured && !before.copied_samples && before.decoder.source.progress_sectors==0 && !before.decoder.source.in_flight && before.decoder.source.service_requested==initial_source.service_requested && before.decoder.source.state==initial_source.state);
        bool ready=false;
        for(unsigned i=0;i<100000;++i){step(driver,std::span(&player,1),31);const auto state=player->snapshot();
            if(state.configured){require(state.transfer_primed && state.playback.phase==reo::native::adxt_playback::Phase::buffering && !state.playback.started && !state.copied_samples);ready=true;break;}std::this_thread::yield();}
        require(ready);require(player->service_control(control::Phase::playing,31)==p::Status::unsupported_profile && !player->snapshot().fault);
        std::weak_ptr<p::Player> weak=player;player.reset();require(!weak.expired());player=weak.lock();
        retire(player);driver.detach(binding);player.reset();require(weak.expired());require(out.owner.join()==o::Status::completed);
    }
    // Real finite data plane under global phases, across all admitted rates,
    // channel counts, tiny/unaligned totals and multiple encoded source windows.
    unsigned matrix=0;
    for(unsigned ch:{1u,2u})for(unsigned rate:{24000u,44100u,48000u})for(unsigned total:{1u,31u,32u,36u,128u,4096u,8193u,20000u}){
        Output out;p::testing::Driver driver;auto player=make(out,driver,ch,rate,total);p::testing::Driver::Binding binding;driver.attach(binding,player,{11,3,14,29});
        bool ended=false;
        for(unsigned i=0;i<500000;++i){step(driver,std::span(&player,1));const auto state=player->snapshot();
            if(player->phase()==5){ended=true;break;}
            if(state.output.channel[0].samples>=512)out.provider->step(512);
            if(state.decoder.source.in_flight)std::this_thread::yield();}
        require(ended);const auto state=player->snapshot();require(state.first_payload_samples==total && state.output.channel[0].consumed_bytes/2>=total);
        const auto raw=player->estimate(0);require(raw.status==p::Status::completed && raw.result.ratio.numerator==total && raw.result.ratio.denominator==rate);
        require(out.owner.snapshot().statistics.underrun_frames==0 && !state.output.voice.skipped_samples);
        retire(player);driver.detach(binding);require(out.owner.join()==o::Status::completed);++matrix;
    }
    {
        Output out(2,128);p::testing::Driver driver;auto player=make(out,driver,2,48000,40017);p::testing::Driver::Binding binding;
        driver.attach(binding,player,{0,0,0,0});bool fault=false;
        for(unsigned i=0;i<100000;++i){require(player->service_source()==p::Status::completed);require(driver.group.service()==control::Status::completed);
            if(player->snapshot().fault){fault=true;break;}std::this_thread::yield();}
        const auto state=player->snapshot();require(fault && state.decoder.pcm.read_id!=0);
        require(state.output.channel[0].samples==0 && state.output.channel[1].samples==0);
        retire(player);driver.detach(binding);require(!out.provider->detaches);
        auto producer=out.owner.open(1);require(producer.status==o::Status::completed);bool refused=false;
        try{p::Config config;config.decoder.channels=2;auto file=s::file(2,48000,32);config.decoder.source_config.byte_length=static_cast<std::int32_t>(file->size());
            p::Player invalid(config,std::move(producer.producer),file,reo::native::adxt_refill::make_async_backend(8192),std::make_shared<reo::native::adx_header::KeyContext>(),driver.shared);
        }catch(const std::invalid_argument&){refused=true;}
        require(refused && !out.owner.snapshot().occupied);require(out.owner.join()==o::Status::completed);
    }
    {
        Output out;p::testing::Driver driver;auto file=std::make_shared<s::Blocked>();file->bytes=s::file(1,48000,80000)->bytes;
        auto producer=out.owner.open(1);require(producer.status==o::Status::completed);p::Config config;config.decoder.source_config.byte_length=static_cast<std::int32_t>(file->size());
        auto blocked=std::make_shared<p::Player>(config,std::move(producer.producer),file,reo::native::adxt_refill::make_async_backend(8192),std::make_shared<reo::native::adx_header::KeyContext>(),driver.shared);
        auto peer=make(out,driver,1,48000,120000);p::testing::Driver::Binding blocked_binding,peer_binding;
        driver.attach(blocked_binding,blocked,{0,0,0,0});driver.attach(peer_binding,peer,{1,1,1,1});std::array players{blocked,peer};bool ready=false;
        struct Release{std::shared_ptr<s::Blocked> file;~Release(){std::lock_guard lock(file->mutex);file->released=true;file->cv.notify_all();}}release{file};
        for(unsigned i=0;i<100000;++i){step(driver,players);bool entered;{std::lock_guard lock(file->mutex);entered=file->entered;}
            const auto state=peer->snapshot();if(entered && state.output.voice.playing && state.output.channel[0].samples>=2048){ready=true;break;}std::this_thread::yield();}
        require(ready);blocked->request_stop();driver.detach(blocked_binding);
        std::atomic<bool> joined{},failed{};std::thread closer([&]{const auto deadline=std::chrono::steady_clock::now()+std::chrono::seconds(5);
            while(std::chrono::steady_clock::now()<deadline){const auto result=blocked->retire_on_control_thread();
                if(result==p::Status::completed){joined=true;return;}if(result!=p::Status::pending){failed=true;return;}std::this_thread::yield();}failed=true;});
        const auto before=peer->snapshot().output.channel[0].consumed_bytes;out.provider->step(512);
        // No assertions can escape before releasing the deliberately blocked
        // worker and joining its closer. Preserve observations for afterward.
        const bool peer_progress=peer->snapshot().output.channel[0].consumed_bytes>before;
        const bool pending=!joined.load() && !out.provider->unloaded;
        {std::lock_guard lock(file->mutex);file->released=true;file->cv.notify_all();}closer.join();
        require(peer_progress && pending && joined && !failed && blocked->snapshot().decoder.source.joined);
        retire(peer);driver.detach(peer_binding);require(out.owner.join()==o::Status::completed);
    }
    {
        Output out(3);p::testing::Driver driver;std::array<std::shared_ptr<p::Player>,3> players{make(out,driver,1,48000,120000),make(out,driver,2,48000,120000),make(out,driver,1,48000,120000)};
        std::array<p::testing::Driver::Binding,3> bindings;
        driver.attach(bindings[0],players[0],{15,1,8,31});driver.attach(bindings[1],players[1],{0,15,3,0});driver.attach(bindings[2],players[2],{7,6,15,17});
        std::array<const o::Producer*,3> order{&players[2]->output_identity(),&players[0]->output_identity(),&players[1]->output_identity()};require(out.owner.set_order(order)==o::Status::completed);
        bool playing=false;
        for(unsigned i=0;i<100000;++i){step(driver,players);if(std::all_of(players.begin(),players.end(),[](auto& x){return x->snapshot().output.voice.playing && x->snapshot().output.channel[0].samples>=2048;})){playing=true;break;}std::this_thread::yield();}
        require(playing);require(players[0]->pause(1,33).status==p::Status::completed);
        const auto paused=players[0]->snapshot().output.channel[0].consumed_bytes,peer=players[1]->snapshot().output.channel[0].consumed_bytes;
        out.provider->step(512);require(players[0]->snapshot().output.channel[0].consumed_bytes==paused && players[1]->snapshot().output.channel[0].consumed_bytes>peer);
        require(players[0]->pause(2,44).status==p::Status::completed && players[0]->snapshot().clock.paused==2);
        out.provider->step(512);require(players[0]->snapshot().output.channel[0].consumed_bytes>paused);
        retire(players[0]);driver.detach(bindings[0]);const auto before=players[1]->snapshot().output.channel[0].consumed_bytes;out.provider->step(128);require(players[1]->snapshot().output.channel[0].consumed_bytes>before && !out.provider->unloaded);
        retire(players[1]);driver.detach(bindings[1]);retire(players[2]);driver.detach(bindings[2]);require(out.owner.join()==o::Status::completed && out.provider->unloads==1);
    }
    std::cout<<checks<<" phased native player checks; finite matrix="<<matrix<<"\n";return 0;
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}}
