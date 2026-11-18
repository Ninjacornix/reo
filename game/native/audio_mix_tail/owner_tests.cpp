#include "mixer.hpp"
#include "../adxt_control_session/control_session.hpp"
#include "../adxt_shared_player/test_sources.hpp"
#include "../adxt_player/test_provider.hpp"
#include "../audio_banks/v2/test_inputs.hpp"
#include <cstdio>
#include <thread>
namespace m=reo::native::audio_mix_tail;
namespace c=reo::native::adxt_control_session;
namespace f=reo::native::adxt_shared_player::testing;
namespace i=reo::native::adxt_lsc_input;
namespace b=m::banks;
unsigned assertions{};
void check(bool value){++assertions;if(!value)throw std::runtime_error("Unified media owner check "+std::to_string(assertions));}
struct Gains final:b::GainProvider {float gain(unsigned,unsigned,std::uint64_t) noexcept override{return 1;}};
struct Master final:m::MasterGain {float gain() noexcept override{return 1;}};
void retire(c::Session& session,const c::Key& key){
    for(unsigned n=0;n<100000;++n){const auto value=session.retire(key);if(value.status==c::Status::completed){check(value.source_joined && value.evidence.output_retired);return;}
        check(value.status==c::Status::pending);std::this_thread::yield();}
    throw std::runtime_error("Unified source retirement exceeded bound");
}
int main(){try{
    b::Config bc;bc.max_render_frames=512;bc.path_counters=true;
    auto mix=std::make_shared<m::Mixer>(bc,std::make_shared<Gains>(),std::make_shared<Master>());
    {
        const auto bytes=bank();auto token=mix->begin_submission();check(token.status==b::Status::ok);
        auto raw=mix->capture(token.value,{bytes.hd.size(),bytes.bd.size(),bytes.tq.size()});check(raw.status==b::Status::ok);
        std::copy(bytes.hd.begin(),bytes.hd.end(),raw.value.hd().begin());std::copy(bytes.bd.begin(),bytes.bd.end(),raw.value.bd().begin());std::copy(bytes.tq.begin(),bytes.tq.end(),raw.value.tq().begin());
        auto prepared=mix->prepare(token.value,std::move(raw.value));check(prepared.status==b::Status::ok && mix->install(token.value,0,prepared.value)==b::Status::ok);
        const b::Command start=b::StartRequest{0,0,0};check(mix->apply({&start,1}).status==b::Status::ok);
    }
    auto slot=std::make_shared<reo::audio_output::CallbackSlot>();auto provider=std::make_shared<reo::native::adxt_player::testing::Provider>();
    c::Config config;config.output.bank_mix=mix;c::Session session(config,slot,provider);check(session.start()==c::Status::completed);
    auto blocked=std::make_shared<f::Blocked>();blocked->bytes=f::file(1,48000,20000)->bytes;
    const auto end=96+(20000+31)/32*18;blocked->bytes.resize((end+18+2047)/2048*2048);f::be16(blocked->bytes,end,0x8001);f::be16(blocked->bytes,end+2,14);blocked->released=true;
    auto prepared=reo::native::adx_sequence::Clip::prepare(blocked);check(prepared.status==reo::native::adx_sequence::Status::completed);
    auto input=i::Input::create({1,48000,1,2});const auto asset=input->register_asset("blocked-live",prepared.clip);check(asset.status==i::Status::completed);
    struct Release{std::shared_ptr<f::Blocked> source;~Release(){std::lock_guard lock(source->mutex);source->released=true;source->cv.notify_all();}}release{blocked};
    {std::lock_guard lock(blocked->mutex);blocked->released=false;blocked->entered=false;}
    check(input->enqueue(asset.key).status==i::Status::completed && input->start()==i::Status::completed);
    c::player::Config lc;lc.lsc_input=input;lc.decoder.seamless_enabled=true;lc.decoder.source_config.byte_length=i::byte_domain;
    const auto live=session.open(lc,input->origin(),{0,0,0,0});check(live.status==c::Status::completed);
    auto finite=f::file(1,48000,120000);c::player::Config pc;pc.decoder.source_config.byte_length=static_cast<std::int32_t>(finite->size());
    const auto peer=session.open(pc,finite,{1,1,1,1});check(peer.status==c::Status::completed);
    bool ready=false;for(unsigned n=0;n<100000;++n){check(session.service(0)==c::Status::completed);bool entered;
        {std::lock_guard lock(blocked->mutex);entered=blocked->entered;}const auto value=session.inspect(peer.key).evidence;
        if(entered && value.output.voice.playing && value.output.channel[0].samples>=2048){ready=true;break;}std::this_thread::yield();}check(ready);
    const auto before=mix->snapshot();const auto consumed=session.inspect(peer.key).evidence.output.channel[0].consumed_bytes;
    check(provider->step(512));check(mix->snapshot().banks.frame_clock>before.banks.frame_clock && session.inspect(peer.key).evidence.output.channel[0].consumed_bytes>consumed);
    check(session.retire(live.key).status==c::Status::pending && !input->snapshot().joined && !mix->snapshot().joined);
    check(provider->step(512) && mix->snapshot().banks.ports[0].loaded && !provider->unloaded);
    {std::lock_guard lock(blocked->mutex);blocked->released=true;blocked->cv.notify_all();}
    retire(session,live.key);check(input->snapshot().joined && !input->snapshot().abandoned && !mix->snapshot().stopping);
    retire(session,peer.key);const auto clock=mix->snapshot().banks.frame_clock;
    check(provider->step(512) && mix->snapshot().banks.frame_clock>clock && !session.snapshot().output.occupied);
    check(session.join()==c::Status::completed && mix->snapshot().joined && provider->unloads==1 && !slot->occupied());
    check(mix->budget_observer()->snapshot().bytes==0);
    std::printf("%u unified live-source/decoder/bank/output assertions\n",assertions);return 0;
}catch(const std::exception& e){std::fprintf(stderr,"%s\n",e.what());return 1;}}
