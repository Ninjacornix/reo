#include "control_session.hpp"
#include "../adxt_transfer_groups/transfer_groups.hpp"
#include "../adxt_serviced_clock/completion.hpp"
#include <array>
#include <limits>
#include <stdexcept>
#include <utility>

namespace reo::native::adxt_control_session {
namespace group=adxt_service_group;
namespace transfer=adxt_transfer_groups;
struct Identity {};
namespace {
Status mapped(player::Status s)noexcept{
    switch(s){case player::Status::completed:case player::Status::ended:case player::Status::waiting_header:return Status::completed;
    case player::Status::pending:return Status::pending;case player::Status::busy:return Status::busy;case player::Status::closed:return Status::closed;
    case player::Status::unsupported_profile:return Status::unsupported_profile;default:return Status::fault;}
}
struct Guards final:group::Guards,transfer::ChunkGuard {
    int cri{},rna{},chunk{};std::uint64_t scans{};bool fault{};
    void enter(group::Domain d)noexcept override{if(d==group::Domain::cri)++cri;else ++rna;}
    void leave(group::Domain d)noexcept override{if(d==group::Domain::cri)--cri;else --rna;if(cri<0 || rna<0)fault=true;}
    void enter()noexcept override{++chunk;++scans;}
    void leave()noexcept override{--chunk;if(chunk<0)fault=true;}
};
struct Record {
    std::shared_ptr<player::Player> player;player::Ports ports;Indices indices;
    std::uint64_t generation{1};bool retiring{},exhausted{};
};
struct Scope {bool& busy;explicit Scope(bool& b):busy(b){busy=true;}~Scope(){busy=false;}};
}
struct Session::State {
    Config config;std::shared_ptr<const Identity> identity=std::make_shared<Identity>();
    std::shared_ptr<player::clock::Shared> clock;
    std::shared_ptr<adx_header::KeyContext> keys=std::make_shared<adx_header::KeyContext>();
    std::shared_ptr<Guards> guards=std::make_shared<Guards>();
    std::shared_ptr<transfer::DtxGroup> dtx=std::make_shared<transfer::DtxGroup>(guards);
    std::shared_ptr<transfer::DtrGroup> dtr=std::make_shared<transfer::DtrGroup>(dtx);
    group::Group group;output::Session output;
    std::array<Record,16> records;
    std::array<std::uint32_t,16> order{};std::size_t order_count{};
    std::array<bool,16> decoders{},streams{},rnas{};std::array<bool,32> transfers{};
    std::uint64_t visits{},discard_diagnostics{};bool busy{},closing{},joined{},order_required{};
    State(Config c,std::shared_ptr<audio_output::CallbackSlot> slot,std::shared_ptr<audio_output::Provider> provider,bool external=false)
        :config(c),clock(std::make_shared<player::clock::Shared>(c.clock)),group(clock,guards,dtr,dtx),
         output(external?output::Session(c.output):output::Session(c.output,std::move(slot),std::move(provider))){
        if(c.clock.in_call || c.clock.service_busy)throw std::invalid_argument("Quiescent native clock required");
    }
    void remove_ports(Record& r)noexcept{
        (void)group.set_decoder(r.indices.decoder,{});(void)group.set_stream(r.indices.stream,{});
        (void)group.set_rna(r.indices.rna,{});(void)dtr->set(r.indices.transfer,{});r.ports={};
    }
    void free_indices(Indices i)noexcept{decoders[i.decoder]=streams[i.stream]=rnas[i.rna]=transfers[i.transfer]=false;}
    bool restore_order()noexcept{
        if(order_required)return true;
        std::array<const output::Producer*,16> identities{};
        for(std::size_t i=0;i<order_count;++i){const auto& r=records[order[i]];
            if(!r.player || r.retiring){order_required=true;return false;}identities[i]=&r.player->output_identity();}
        if(output.set_order(std::span(identities).first(order_count))!=output::Status::completed){order_required=true;return false;}
        return true;
    }
    struct ClockService final:adxt_serviced_clock::Service {
        State& owner;std::shared_ptr<player::Player> target;std::uint32_t tick{};
        ClockService(State& state,std::shared_ptr<player::Player> player,std::uint32_t supplied_tick)
            :owner(state),target(std::move(player)),tick(supplied_tick){}
        const player::clock::Shared* clock_identity()const noexcept override{return owner.clock.get();}
        player::clock::integer::Observation observation()const noexcept override{return target->snapshot().clock_observation;}
        void discard_diagnostic()noexcept override{++owner.discard_diagnostics;}
        adxt_serviced_clock::ServiceStatus run_and_refresh(player::clock::Stream& stream,player::clock::integer::Observation& observation)noexcept override{
            // Original discard services the group, not file/source polling.
            for(auto& r:owner.records)if(r.player && !r.retiring)
                if(r.player->set_tick(tick)!=player::Status::completed)return adxt_serviced_clock::ServiceStatus::failed;
            const auto result=owner.group.service();if(result==group::Status::completed)++owner.visits;
            const auto fresh=target->snapshot();stream=fresh.clock;observation=fresh.clock_observation;
            if(!fresh.clock_observation_valid || owner.guards->fault || owner.guards->cri || owner.guards->rna || owner.guards->chunk)return adxt_serviced_clock::ServiceStatus::failed;
            return result==group::Status::completed?adxt_serviced_clock::ServiceStatus::completed:adxt_serviced_clock::ServiceStatus::busy;
        }
    };
};
Session::Session(Config config,std::shared_ptr<audio_output::CallbackSlot> slot,std::shared_ptr<audio_output::Provider> provider)
    :state_(std::make_unique<State>(config,std::move(slot),std::move(provider))){}
Session::Session(Config config):state_(std::make_unique<State>(config,nullptr,nullptr,true)){}
std::shared_ptr<output::Submix> Session::submix()const noexcept{return state_->output.submix();}
Session::~Session(){(void)request_stop();(void)join();}
bool Session::valid(const Key& key,bool retiring)const noexcept{
    const auto& s=*state_;if(key.identity_.lock()!=s.identity || key.slot_>=s.records.size())return false;
    const auto& r=s.records[key.slot_];return r.player && r.generation==key.generation_ && (retiring || !r.retiring);
}
Status Session::start()noexcept{
    auto& s=*state_;if(s.busy)return Status::busy;if(s.closing)return Status::closed;Scope scope(s.busy);
    return s.output.start()==output::Status::completed?Status::completed:Status::provider_refused;
}
Open Session::open(player::Config config,std::shared_ptr<const resources::ByteView> view,Indices indices)noexcept{
    auto& s=*state_;if(s.busy)return{Status::busy,{}};if(s.closing)return{Status::closed,{}};
    if(indices.decoder>=16 || indices.stream>=16 || indices.rna>=16 || indices.transfer>=32)return{Status::invalid_indices,{}};
    if(s.decoders[indices.decoder] || s.streams[indices.stream] || s.rnas[indices.rna] || s.transfers[indices.transfer])return{Status::occupied,{}};
    std::uint32_t slot=0;while(slot<s.config.output.streams && (s.records[slot].player || s.records[slot].exhausted))++slot;
    if(slot==s.config.output.streams)return{Status::capacity,{}};
    Scope scope(s.busy);auto opened=s.output.open(config.decoder.channels,indices.host_gain_key);
    if(opened.status!=output::Status::completed)return{opened.status==output::Status::capacity?Status::capacity:Status::fault,{}};
    std::shared_ptr<player::Player> player;player::Ports ports;
    try{
        auto backend=config.lsc_input?config.lsc_input->take_backend():adxt_refill::make_async_backend(8192);
        player=std::make_shared<player::Player>(config,std::move(opened.producer),std::move(view),std::move(backend),s.keys,s.clock);
        ports=player->make_ports();
    }catch(const std::bad_alloc&){
        player.reset();if(opened.producer)(void)opened.producer->retire();return{s.restore_order()?Status::allocation_failure:Status::fault,{}};
    }catch(...){
        player.reset();if(opened.producer)(void)opened.producer->retire();return{s.restore_order()?Status::unsupported_profile:Status::fault,{}};
    }
    // No allocation or externally failing operation remains after publication.
    (void)s.group.set_decoder(indices.decoder,ports.decoder);(void)s.group.set_stream(indices.stream,ports.stream);
    (void)s.group.set_rna(indices.rna,ports.rna);(void)s.dtr->set(indices.transfer,ports.transfer);
    auto& r=s.records[slot];r.player=std::move(player);r.ports=std::move(ports);r.indices=indices;r.retiring=false;
    s.decoders[indices.decoder]=s.streams[indices.stream]=s.rnas[indices.rna]=s.transfers[indices.transfer]=true;s.order_required=true;
    Key key;key.identity_=s.identity;key.slot_=slot;key.generation_=r.generation;return{Status::completed,std::move(key)};
}
Status Session::set_order(std::span<const Key> keys)noexcept{
    auto& s=*state_;if(s.busy)return Status::busy;if(s.closing)return Status::closed;
    unsigned active{};for(const auto& r:s.records)active+=bool(r.player && !r.retiring);
    // Retiring producers may still be live until their first retirement fence.
    if(keys.size()!=active || s.output.snapshot().occupied!=active)return Status::invalid_key;
    std::array<bool,16> used{};std::array<const output::Producer*,16> order{};
    for(std::size_t i=0;i<keys.size();++i){if(!valid(keys[i]) || used[keys[i].slot_])return Status::invalid_key;
        used[keys[i].slot_]=true;order[i]=&s.records[keys[i].slot_].player->output_identity();}
    Scope scope(s.busy);if(s.output.set_order(std::span(order).first(keys.size()))!=output::Status::completed)return Status::fault;
    for(std::size_t i=0;i<keys.size();++i)s.order[i]=keys[i].slot_;
    s.order_count=keys.size();s.order_required=false;return Status::completed;
}
Status Session::service(std::uint32_t tick)noexcept{
    auto& s=*state_;if(s.busy)return Status::busy;if(s.closing)return Status::closed;
    unsigned active{};for(const auto& r:s.records)active+=bool(r.player && !r.retiring);
    if(active>2 && s.order_required)return Status::order_required;
    Scope scope(s.busy);bool fault=false;
    for(auto& r:s.records)if(r.player && !r.retiring){
        fault|=r.player->set_tick(tick)!=player::Status::completed;
        fault|=r.player->service_source()!=player::Status::completed;
    }
    if(s.group.service()!=group::Status::completed)return Status::fault;
    ++s.visits;
    for(const auto& r:s.records)if(r.player && !r.retiring)fault|=r.player->snapshot().fault;
    if(s.guards->fault || s.guards->cri || s.guards->rna || s.guards->chunk || s.clock->service_busy)return Status::fault;
    return fault?Status::fault:Status::completed;
}
Observation Session::inspect(const Key& key)const noexcept{
    if(!valid(key,true))return{};
    return{Status::completed,state_->records[key.slot_].player->snapshot()};
}
Snapshot Session::snapshot()const noexcept{
    const auto& s=*state_;Snapshot result;result.output=s.output.snapshot();result.clock_state=*s.clock;result.service_busy=s.clock->service_busy;
    for(const auto& r:s.records){result.records+=bool(r.player);result.retiring+=r.retiring;}
    result.group_visits=s.visits;result.dtx_scans=s.guards->scans;result.closing=s.closing;result.joined=s.joined;
    result.discard_diagnostics=s.discard_diagnostics;
    result.order_required=s.order_required;result.guard_fault=s.guards->fault;return result;
}
Status Session::gain(const Key& key,float gain)noexcept{
    auto& s=*state_;if(s.busy)return Status::busy;if(s.closing)return Status::closed;if(!valid(key))return Status::invalid_key;Scope scope(s.busy);
    return mapped(s.records[key.slot_].player->gain(gain));
}
Status Session::volume(const Key& key,std::uint32_t value)noexcept{
    auto& s=*state_;if(s.busy)return Status::busy;if(s.closing)return Status::closed;if(!valid(key))return Status::invalid_key;Scope scope(s.busy);
    return mapped(s.records[key.slot_].player->volume(value));
}
Status Session::attenuation(const Key& key,std::uint32_t value)noexcept{
    auto& s=*state_;if(s.busy)return Status::busy;if(s.closing)return Status::closed;if(!valid(key))return Status::invalid_key;Scope scope(s.busy);
    return mapped(s.records[key.slot_].player->attenuation(value));
}
ClockResult Session::estimate(const Key& key,std::uint32_t tick)noexcept{
    auto& s=*state_;if(s.busy)return{Status::busy,{}};if(s.closing)return{Status::closed,{}};if(!valid(key))return{};Scope scope(s.busy);
    const auto value=s.records[key.slot_].player->estimate(tick);return{mapped(value.status),value};
}
ClockResult Session::centiseconds(const Key& key,std::uint32_t tick)noexcept{
    auto& s=*state_;if(s.busy)return{Status::busy,{}};if(s.closing)return{Status::closed,{}};if(!valid(key))return{};Scope scope(s.busy);
    const auto value=s.records[key.slot_].player->centiseconds(tick);return{mapped(value.status),value};
}
RatioResult Session::ratio(const Key& key,player::clock::integer::Query query)noexcept{
    auto& s=*state_;if(s.busy)return{Status::busy};if(s.closing)return{Status::closed};if(!valid(key))return{};Scope scope(s.busy);
    const auto source=s.records[key.slot_].player->snapshot();if(!source.clock_observation_valid)return{Status::fault};
    const auto value=player::clock::integer::query(query,source.clock_observation);
    return{value.status==player::clock::integer::Status::completed?Status::completed:Status::unsupported_profile,value};
}
Status Session::configure_clock(ClockConfiguration value)noexcept{
    auto& s=*state_;if(s.busy || s.clock->in_call || s.clock->service_busy)return Status::busy;if(s.closing)return Status::closed;Scope scope(s.busy);
    s.clock->mode=value.mode;s.clock->rebase_selector=value.rebase_selector;s.clock->drift_bits=value.drift_bits;
    return Status::completed;
}
ClockControl Session::pause(const Key& key,std::int32_t argument,std::uint32_t tick)noexcept{
    auto& s=*state_;if(s.busy)return{Status::busy,{}};if(s.closing)return{Status::closed,{}};if(!valid(key))return{};Scope scope(s.busy);
    const auto value=s.records[key.slot_].player->pause(argument,tick);return{mapped(value.status),value};
}
ClockControl Session::discard_rebase(const Key& key,std::uint32_t tick)noexcept{
    auto& s=*state_;if(s.busy)return{Status::busy,{}};if(s.closing)return{Status::closed,{}};if(!valid(key))return{};
    auto target=s.records[key.slot_].player;
    const bool paused=target->snapshot().clock.paused!=0;
    if(paused){unsigned active{};for(const auto& r:s.records)active+=bool(r.player && !r.retiring);
        if(active>2 && s.order_required)return{Status::order_required,{}};}
    Scope scope(s.busy);
    if(!paused){const auto value=target->discard_rebase(tick);return{mapped(value.status),value};}
    try{
        auto service=std::make_shared<State::ClockService>(s,target,tick);
        const auto value=target->discard_via(std::move(service),tick);return{mapped(value.status),value};
    }catch(...){return{Status::allocation_failure,{player::Status::unsupported_profile,player::clock::Status::unsupported_service}};}
}
Status Session::set_time_base(const Key& key,std::uint32_t base)noexcept{
    auto& s=*state_;if(s.busy)return Status::busy;if(s.closing)return Status::closed;if(!valid(key))return Status::invalid_key;Scope scope(s.busy);
    return mapped(s.records[key.slot_].player->set_time_base(base));
}
Status Session::set_loop_enabled(const Key& key,bool enabled)noexcept{
    auto& s=*state_;if(s.busy)return Status::busy;if(s.closing)return Status::closed;if(!valid(key))return Status::invalid_key;Scope scope(s.busy);
    return mapped(s.records[key.slot_].player->set_loop_enabled(enabled));
}
Status Session::set_start_inhibit(const Key& key,bool value)noexcept{
    auto& s=*state_;if(s.busy)return Status::busy;if(s.closing)return Status::closed;if(!valid(key))return Status::invalid_key;Scope scope(s.busy);
    return mapped(s.records[key.slot_].player->set_start_inhibit(value));
}
Retirement Session::retire_slot(std::uint32_t slot)noexcept{
    auto& s=*state_;auto& r=s.records[slot];
    if(!r.retiring){r.retiring=true;r.player->request_stop();s.remove_ports(r);s.order_required=true;}
    const auto status=r.player->retire_on_control_thread();auto snapshot=r.player->snapshot();
    if(status!=player::Status::completed)return{mapped(status),std::move(snapshot),false};
    if(!snapshot.decoder.source.joined || !snapshot.output_retired)return{Status::fault,std::move(snapshot),false};
    s.free_indices(r.indices);r.player.reset();r.retiring=false;
    if(r.generation==std::numeric_limits<std::uint64_t>::max())r.exhausted=true;else ++r.generation;
    return{Status::completed,std::move(snapshot),true};
}
Retirement Session::retire(const Key& key)noexcept{
    auto& s=*state_;if(s.busy)return{Status::busy,{},false};if(!valid(key,true))return{};Scope scope(s.busy);return retire_slot(key.slot_);
}
Status Session::request_stop()noexcept{
    auto& s=*state_;if(s.busy)return Status::busy;if(s.closing)return Status::completed;s.closing=true;
    for(auto& r:s.records)if(r.player && !r.retiring){r.retiring=true;r.player->request_stop();s.remove_ports(r);}
    s.output.request_stop();
    return Status::completed;
}
Status Session::join()noexcept{
    auto& s=*state_;if(s.busy)return Status::busy;if(s.joined)return Status::completed;(void)request_stop();Scope scope(s.busy);
    bool pending=false,fault=false;for(std::uint32_t i=0;i<s.records.size();++i)if(s.records[i].player){
        const auto result=retire_slot(i);pending|=result.status==Status::pending;fault|=result.status!=Status::pending && result.status!=Status::completed;}
    if(fault)return Status::fault;
    if(pending)return Status::pending;
    const auto result=s.output.join();if(result!=output::Status::completed)return Status::pending;
    s.joined=true;return Status::completed;
}
} // namespace reo::native::adxt_control_session
