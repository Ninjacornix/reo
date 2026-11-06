#include "player.hpp"
#include <algorithm>
#include <bit>
#include <limits>
#include <optional>
#include <stdexcept>

namespace reo::native::adxt_clocked_player {
namespace {
Config checked(Config c,const output::Producer& producer) {
    if(c.decoder.downmix || c.decoder.seamless_enabled || c.decoder.pitch_offset ||
       c.decoder.channels<1 || c.decoder.channels>2)throw std::invalid_argument("Shared native player profile");
    const auto s=producer.snapshot();
    if(!s.active || s.fault || s.channels!=c.decoder.channels || !s.transfer_open || s.voice.playing ||
       s.channel[0].samples || s.channel[0].queued_bytes || s.channel[1].samples || s.channel[1].queued_bytes)
        throw std::invalid_argument("Prepared producer does not match decoder");
    return c;
}
}
class Player::State {
public:
    Config config;std::unique_ptr<output::Producer> output;
    std::shared_ptr<clock::Shared> shared_clock;clock::Stream clock_state;std::uint32_t time_base{};
    window::StreamWindowOwner decoder;window::Request request;
    std::optional<adxt_playback::Playback> playback;
    std::optional<window::pcm::ReadLease> held;
    std::array<std::array<std::uint8_t,16384>,2> copy{};
    std::array<std::uint64_t,2> digest{1469598103934665603ull,1469598103934665603ull};
    std::uint64_t copied{},first{};
    bool configured{},stopping{},output_retired{},retired{},fault{},busy{};
    State(Config c,const output::Producer& producer,std::shared_ptr<const resources::ByteView> view,
          std::unique_ptr<adxt_shared_source::Backend> backend,std::shared_ptr<adx_header::KeyContext> keys,std::shared_ptr<clock::Shared> shared)
        :config(checked(c,producer)),shared_clock(std::move(shared)),clock_state{0,c.initial_tick,0,0},time_base(c.time_base),
         decoder(config.decoder,std::move(view),std::move(backend),std::move(keys)),request(decoder.request()){if(!shared_clock)throw std::invalid_argument("Shared original clock context required");}
    Status fail()noexcept {
        fault=true;(void)output->stop_transfer();(void)output->play(false);clock_state.rna_play=0;return Status::fault;
    }
    clock::integer::Observation observation(const window::Snapshot& w,const output::StreamSnapshot& out)const noexcept {
        clock::integer::Observation o;
        o.state=playback?static_cast<std::uint8_t>(playback->state().phase):1;
        o.decoded=static_cast<std::uint32_t>(w.outer.decoded_samples);
        o.total=w.header.base.total_samples;o.frequency=w.header.base.frequency;o.base=time_base;
        o.output_present=true;o.output_bytes=static_cast<std::uint32_t>(w.pcm.rings[0].data);
        o.rna_free_bytes=16384-static_cast<std::uint32_t>(out.channel[0].samples)*2;
        return o; // tag0 depth16; no admitted seamless/A4 offset in this cut.
    }
    clock::integer::Observation observation()const noexcept {return observation(decoder.snapshot(),output->snapshot());}
    void synchronize_clock()noexcept {
        if(!playback)return;
        auto s=playback->state();s.estimate_base=clock_state.estimate_base;s.tick_base=clock_state.tick_base;
        s.paused=clock_state.paused!=0;playback.emplace(s);
    }
    Status pump()noexcept {
        for(;;){
            std::uint32_t free{};
            if(output->free_samples(free)!=adxt_playback::Status::completed)return fail();
            const auto before=decoder.snapshot();
            const auto samples=std::min(free,static_cast<std::uint32_t>(before.pcm.rings[0].data)/2)/32*32;
            if(!samples)return Status::completed;
            if(held || samples>8192 || samples>std::numeric_limits<std::uint64_t>::max()-copied)return fail();
            auto read=decoder.borrow_pcm(static_cast<std::int32_t>(samples*2));
            if(read.status!=window::pcm::Status::completed)return fail();
            held.emplace(std::move(read.lease));const auto bytes=held->grant(0).bytes;
            if(bytes<=0 || bytes%64 || bytes>16384)return fail();
            std::array<std::span<const std::byte>,2> spans;
            for(std::uint32_t c=0;c<config.decoder.channels;++c){
                if(held->grant(c).bytes!=bytes || held->read_into(c,std::span(copy[c]).first(static_cast<std::size_t>(bytes)))!=window::pcm::Status::completed)return fail();
                spans[c]=std::as_bytes(std::span(copy[c]).first(static_cast<std::size_t>(bytes)));
            }
            if(output->copy(spans[0],spans[1])!=output::Status::completed)return fail();
            if(decoder.finish_pcm(*held)!=window::Status::completed)return fail();
            held.reset();copied+=static_cast<unsigned>(bytes)/2;
            const auto prefix=std::min<std::uint64_t>(static_cast<unsigned>(bytes)/2,before.header.base.total_samples-first);
            for(std::uint32_t c=0;c<config.decoder.channels;++c)
                for(std::size_t i=0;i<prefix*2;++i){digest[c]^=copy[c][i];digest[c]*=1099511628211ull;}
            first+=prefix;
        }
    }
};
Player::Player(Config c,std::unique_ptr<output::Producer> output,std::shared_ptr<const resources::ByteView> view,
               std::unique_ptr<adxt_shared_source::Backend> backend,std::shared_ptr<adx_header::KeyContext> keys,std::shared_ptr<clock::Shared> shared)
{
    try {
        if(!output)throw std::invalid_argument("Exclusive stream producer required");
        // Keep producer ownership outside State until decoder construction
        // succeeds, including allocation failure before the State exists.
        state_=std::make_unique<State>(c,*output,std::move(view),std::move(backend),std::move(keys),std::move(shared));
        state_->output=std::move(output);
    } catch(...) { if(output)(void)output->retire();throw; }
}
Player::~Player(){request_stop();(void)retire_on_control_thread();}
Status Player::service(std::uint32_t tick)noexcept {
    auto& s=*state_;
    if(s.busy)return Status::busy;
    if(s.fault)return Status::fault;
    if(s.stopping || s.retired)return Status::closed;
    if(s.playback && s.playback->state().phase==adxt_playback::Phase::ended)return Status::ended;
    s.busy=true;struct Exit{bool& b;~Exit(){b=false;}}exit{s.busy};
    if(s.decoder.service_source().status!=adxt_shared_source::Status::completed)return s.fail();
    const auto decoded=s.decoder.service(s.request);
    if(decoded!=window::Status::completed && decoded!=window::Status::inactive && decoded!=window::Status::backpressure)return s.fail();
    if(!s.configured){
        if(s.decoder.snapshot().outer.phase==window::OuterPhase::header)return Status::waiting_header;
        if(s.decoder.configure_ready()!=window::Status::completed)return s.fail();
        const auto ready=s.decoder.snapshot();
        if(ready.ready.pitch || ready.ready.pans[0]!=(s.config.decoder.channels==1?0:-15) ||
           (s.config.decoder.channels==2 && ready.ready.pans[1]!=15)){
            s.fail();return Status::unsupported_profile;
        }
        if(s.output->configure(static_cast<std::uint32_t>(ready.ready.frequency))!=output::Status::completed)return s.fail();
        adxt_playback::State control;control.request_samples=ready.outer.max_request;control.estimate_base=s.clock_state.estimate_base;control.tick_base=s.clock_state.tick_base;control.paused=s.clock_state.paused!=0;s.playback.emplace(control);s.configured=true;
    }
    if(s.pump()!=Status::completed)return Status::fault;
    const auto ready=s.decoder.snapshot();
    const auto previous=s.playback->state();
    const auto controlled=s.playback->service({ready.outer.phase==window::OuterPhase::ended,s.config.decoder.channels,
                                               ready.header.active_samples_per_block,tick},s.decoder,*s.output);
    if(controlled==adxt_playback::Status::pending)return Status::pending;
    if(controlled!=adxt_playback::Status::completed)return s.fail();
    const auto current=s.playback->state();
    if(previous.phase==adxt_playback::Phase::buffering && current.phase==adxt_playback::Phase::playing && !current.paused){
        s.clock_state.estimate_base=current.estimate_base;s.clock_state.tick_base=current.tick_base;s.clock_state.rna_play=1;
    }
    if(current.phase==adxt_playback::Phase::ended)s.clock_state.rna_play=0;
    return current.phase==adxt_playback::Phase::ended?Status::ended:Status::completed;
}
Snapshot Player::snapshot()const noexcept {
    const auto& s=*state_;Snapshot result;result.decoder=s.decoder.snapshot();result.output=s.output->snapshot();
    if(s.playback)result.playback=s.playback->state();
    result.first_payload_digest=s.digest;result.copied_samples=s.copied;result.first_payload_samples=s.first;
    result.configured=s.configured;result.stop_requested=s.stopping;result.output_retired=s.output_retired;
    result.retired=s.retired;result.fault=s.fault || result.output.fault;result.clock=s.clock_state;result.clock_observation=s.observation(result.decoder,result.output);
    result.clock_observation_valid=!s.retired && !s.fault && result.output.active && !result.output.fault;return result;
}
Status Player::gain(float value)noexcept {
    auto& s=*state_;if(s.busy)return Status::busy;if(s.fault)return Status::fault;if(s.stopping)return Status::closed;
    return s.output->gain(value)==output::Status::completed?Status::completed:Status::unsupported_profile;
}
const output::Producer& Player::output_identity()const noexcept{return *state_->output;}
ClockResult Player::estimate(std::uint32_t tick)noexcept {
    auto& s=*state_;if(s.busy)return{Status::busy,{clock::Status::busy,{},0}};
    if(s.fault || s.stopping)return{s.fault?Status::fault:Status::closed,{clock::Status::invalid_queue,{},0}};
    if(!s.output->snapshot().active)return{Status::closed,{clock::Status::invalid_queue,{},0}};
    s.busy=true;struct Exit{bool& b;~Exit(){b=false;}}exit{s.busy};
    clock::Clock owner(*s.shared_clock,s.clock_state);const auto result=owner.estimate(s.observation(),tick);
    if(result.status!=clock::Status::completed)return{result.status==clock::Status::busy?Status::busy:Status::unsupported_profile,result};
    s.clock_state=owner.snapshot();s.synchronize_clock();return{Status::completed,result};
}
ClockResult Player::centiseconds(std::uint32_t tick)noexcept {
    auto& s=*state_;if(s.busy)return{Status::busy,{clock::Status::busy,{},0}};
    if(s.fault || s.stopping)return{s.fault?Status::fault:Status::closed,{clock::Status::invalid_queue,{},0}};
    if(!s.output->snapshot().active)return{Status::closed,{clock::Status::invalid_queue,{},0}};
    s.busy=true;struct Exit{bool& b;~Exit(){b=false;}}exit{s.busy};
    clock::Clock owner(*s.shared_clock,s.clock_state);const auto result=owner.centiseconds(s.observation(),tick);
    if(result.status!=clock::Status::completed)return{result.status==clock::Status::busy?Status::busy:Status::unsupported_profile,result};
    s.clock_state=owner.snapshot();s.synchronize_clock();return{Status::completed,result};
}
ClockControl Player::pause(std::int32_t argument,std::uint32_t tick)noexcept {
    auto& s=*state_;if(s.busy)return{Status::busy,clock::Status::busy};
    if(s.fault || s.stopping)return{s.fault?Status::fault:Status::closed,clock::Status::invalid_queue};
    if(!s.output->snapshot().active)return{Status::closed,clock::Status::invalid_queue};
    s.busy=true;struct Exit{bool& b;~Exit(){b=false;}}exit{s.busy};
    const auto before=s.clock_state;const auto initial=s.observation();
    // Validate without changing the canonical shared/stream state or output.
    // The prepared core is pure apart from those explicit state objects and
    // preserves FP state. Fresh queue observations are taken AFTER RNA play.
    auto scratch=*s.shared_clock;clock::Clock preflight(scratch,before);
    const auto admitted=preflight.pause(initial,argument,tick);
    if(admitted!=clock::Status::completed)return{admitted==clock::Status::busy?Status::busy:Status::unsupported_profile,admitted};
    const bool changed=argument!=static_cast<std::int32_t>(std::bit_cast<std::int8_t>(before.paused));
    const bool active=initial.state==3 || initial.state==4;
    if(changed){
        s.clock_state.paused=static_cast<std::uint8_t>(argument);s.synchronize_clock();
        if(active){
            s.clock_state.rna_play=argument==1?0:1;
            if(s.output->play(s.clock_state.rna_play!=0)!=adxt_playback::Status::completed)
                return{s.fail(),clock::Status::completed};
        }
    }
    clock::Clock owner(*s.shared_clock,before);
    const auto result=owner.pause(active && changed?s.observation():initial,argument,tick);
    if(result!=clock::Status::completed)return{s.fail(),result};
    s.clock_state=owner.snapshot();s.synchronize_clock();return{Status::completed,result};
}
ClockControl Player::discard_rebase(std::uint32_t tick)noexcept {
    auto& s=*state_;if(s.busy)return{Status::busy,clock::Status::busy};
    if(s.fault || s.stopping)return{s.fault?Status::fault:Status::closed,clock::Status::invalid_queue};
    if(!s.output->snapshot().active)return{Status::closed,clock::Status::invalid_queue};
    s.busy=true;struct Exit{bool& b;~Exit(){b=false;}}exit{s.busy};
    clock::Clock owner(*s.shared_clock,s.clock_state);const auto result=owner.discard_rebase(s.observation(),tick);
    if(result!=clock::Status::completed)return{result==clock::Status::busy?Status::busy:Status::unsupported_profile,result};
    s.clock_state=owner.snapshot();s.synchronize_clock();return{Status::completed,result};
}
Status Player::set_time_base(std::uint32_t base)noexcept {
    auto& s=*state_;if(s.busy)return Status::busy;if(s.fault)return Status::fault;if(s.stopping)return Status::closed;
    s.time_base=base;return Status::completed;
}
void Player::request_stop()noexcept{state_->stopping=true;}
Status Player::retire_on_control_thread()noexcept {
    auto& s=*state_;if(s.busy)return Status::busy;if(s.retired)return Status::completed;
    s.busy=true;struct Exit{bool& b;~Exit(){b=false;}}exit{s.busy};s.stopping=true;
    if(!s.output_retired){
        const auto retired=s.output->retire();
        if(retired!=output::Status::completed && !(retired==output::Status::closed && s.output->snapshot().retired))return s.fail();
        s.output_retired=true;s.clock_state.rna_play=0;
    }
    if(s.held){if(s.decoder.finish_pcm(*s.held)!=window::Status::completed)return s.fail();s.held.reset();}
    const auto stopped=s.decoder.stop_decode();
    if(stopped!=window::Status::completed && stopped!=window::Status::retirement_pending && stopped!=window::Status::owned_fault)return s.fail();
    while(s.decoder.snapshot().pcm.rings[0].data){
        auto read=s.decoder.borrow_pcm(16384);if(read.status!=window::pcm::Status::completed || !read.lease.grant(0).bytes)return s.fail();
        if(s.decoder.finish_pcm(read.lease)!=window::Status::completed)return s.fail();
    }
    const auto retired=s.decoder.retire_on_control_thread();
    if(retired==window::Status::retirement_pending)return Status::pending;
    if(retired!=window::Status::completed)return s.fail();
    s.retired=true;return Status::completed;
}
} // namespace reo::native::adxt_clocked_player
