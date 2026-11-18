#include "instances.hpp"
#include "source_key.hpp"
#include <array>
#include <bit>
#include <cmath>
#include <limits>
#include <utility>

namespace reo::native::adxt_instances {
struct Identity {};
namespace {
Status mapped(control::Status value)noexcept {
    switch(value){case control::Status::completed:return Status::completed;case control::Status::pending:return Status::pending;
    case control::Status::closed:return Status::closed;case control::Status::busy:return Status::busy;
    case control::Status::order_required:return Status::order_required;case control::Status::capacity:return Status::capacity;
    case control::Status::unsupported_profile:return Status::unsupported_profile;case control::Status::invalid_indices:return Status::invalid_input;
    case control::Status::invalid_key:return Status::invalid_key;case control::Status::occupied:return Status::occupied;
    case control::Status::provider_refused:return Status::provider_refused;
    default:return Status::fault;}
}
struct Record {
    Construction construction;std::optional<control::Key> active;std::optional<Source> pending;
    std::optional<control::player::Snapshot> final;
    std::optional<std::uint32_t> time_base;std::optional<bool> loop_enabled;std::optional<std::int32_t> service_divisor;
    std::uint64_t generation{1},starts{},stops{};float gain{1};std::uint32_t volume{256},attenuation{};std::int32_t pause{};
    bool owned{},destroying{},retiring{},fault{},exhausted{},start_inhibit{},active_playlist{};
};
struct Busy {bool& value;explicit Busy(bool& v):value(v){value=true;}~Busy(){value=false;}};
bool same_indices(control::Indices a,control::Indices b)noexcept{return a.decoder==b.decoder || a.stream==b.stream || a.rna==b.rna || a.transfer==b.transfer;}
}
struct Instances::State {
    std::shared_ptr<const Identity> identity=std::make_shared<Identity>();
    control::Session session;std::array<Record,16> records;
    std::array<std::uint32_t,16> order{};std::uint32_t capacity{},ordered{};
    bool order_required{},closing{},busy{};
    State(control::Config config,std::shared_ptr<audio_output::CallbackSlot> slot,std::shared_ptr<audio_output::Provider> provider,bool external=false)
        :session(external?control::Session(config):control::Session(config,std::move(slot),std::move(provider))),capacity(config.output.streams){}
};
Instances::Instances(control::Config config,std::shared_ptr<audio_output::CallbackSlot> slot,std::shared_ptr<audio_output::Provider> provider)
    :state_(std::make_unique<State>(config,std::move(slot),std::move(provider))){}
Instances::Instances(control::Config config):state_(std::make_unique<State>(config,nullptr,nullptr,true)){}
std::shared_ptr<control::output::Submix> Instances::submix()const noexcept{return state_->session.submix();}
Instances::~Instances(){(void)request_stop();(void)join();}
bool Instances::valid(const Key& key,bool destroying)const noexcept {
    const auto& s=*state_;if(key.owner_.lock()!=s.identity || key.slot_>=s.capacity)return false;
    const auto& r=s.records[key.slot_];return r.owned && r.generation==key.generation_ && (destroying || !r.destroying);
}
Status Instances::start_output()noexcept {auto& s=*state_;if(s.busy)return Status::busy;if(s.closing)return Status::closed;Busy lock(s.busy);return mapped(s.session.start());}
Open Instances::create(Construction config)noexcept {
    auto& s=*state_;if(s.busy)return{Status::busy};if(s.closing)return{Status::closed};
    if(config.channels<1 || config.channels>2 || config.indices.decoder>=16 || config.indices.stream>=16 || config.indices.rna>=16 || config.indices.transfer>=32)return{Status::invalid_input};
    for(const auto& r:s.records)if(r.owned && same_indices(config.indices,r.construction.indices))return{Status::occupied};
    for(unsigned i=0;i<s.capacity;++i){auto& r=s.records[i];if(r.owned || r.exhausted)continue;
        r.construction=config;r.owned=true;r.fault=false;r.gain=1;r.volume=256;r.attenuation=0;r.pause=0;r.start_inhibit=false;r.starts=r.stops=0;r.final.reset();r.time_base.reset();r.loop_enabled.reset();r.service_divisor.reset();s.order_required=true;
        Key key;key.owner_=s.identity;key.slot_=i;key.generation_=r.generation;return{Status::completed,std::move(key)};}
    return{Status::capacity};
}
void Instances::release(std::uint32_t index)noexcept {
    auto& s=*state_;auto& r=s.records[index];r.owned=false;r.destroying=false;r.retiring=false;r.pending.reset();r.active.reset();r.final.reset();
    if(r.generation==std::numeric_limits<std::uint64_t>::max())r.exhausted=true;else ++r.generation;
    s.order_required=true;
}
Status Instances::retire(std::uint32_t index)noexcept {
    auto& s=*state_;auto& r=s.records[index];
    if(r.active){const auto result=s.session.retire(*r.active);
        if(result.status!=control::Status::completed && result.status!=control::Status::pending){r.fault=true;return mapped(result.status);}
        r.final=result.evidence;
        if(result.status==control::Status::pending)return Status::pending;
        r.active.reset();++r.stops;}
    r.retiring=false;if(r.destroying)release(index);return Status::completed;
}
Status Instances::open(std::uint32_t index)noexcept {
    auto& s=*state_;auto& r=s.records[index];if(!r.pending)return Status::completed;
    auto requested=std::move(*r.pending);r.pending.reset();
    requested.player.attenuation_table=r.construction.attenuation_table;requested.player.initial_attenuation=r.attenuation;
    if(r.time_base)requested.player.time_base=*r.time_base;
    if(r.service_divisor)requested.player.decoder.service_divisor=*r.service_divisor;
    // The stable inline-loop preference belongs to ordinary assets. Finite
    // playlists own repeat separately and contain no admitted inline loops.
    if(r.loop_enabled && !requested.player.sequence && !requested.player.lsc_input)requested.player.decoder.loop_enabled=*r.loop_enabled;
    const auto result=s.session.open(requested.player,std::move(requested.input),r.construction.indices);
    if(result.status!=control::Status::completed){r.fault=true;return mapped(result.status);}
    r.active=result.key;r.active_playlist=bool(requested.player.sequence || requested.player.lsc_input);r.final.reset();++r.starts;
    if(s.session.gain(*r.active,r.gain)!=control::Status::completed || (!r.construction.attenuation_table && s.session.volume(*r.active,r.volume)!=control::Status::completed) || s.session.set_start_inhibit(*r.active,r.start_inhibit)!=control::Status::completed || s.session.pause(*r.active,r.pause,requested.player.initial_tick).status!=control::Status::completed){r.fault=true;r.retiring=true;(void)retire(index);return Status::fault;}
    return Status::completed;
}
Status Instances::start(const Key& key,Source source)noexcept {
    auto& s=*state_;if(s.busy)return Status::busy;if(s.closing)return Status::closed;if(!valid(key))return Status::invalid_key;
    auto& r=s.records[key.slot_];
    if((source.player.sequence || source.player.lsc_input) && source.player.decoder.loop_enabled)return Status::unsupported_profile;
    if(source.player.initial_attenuation || (source.player.attenuation_table && source.player.attenuation_table!=r.construction.attenuation_table))return Status::invalid_input;
    if(!source.input || !source.input->size() || source.input->size()>std::uint64_t(INT32_MAX) || source.player.decoder.channels!=r.construction.channels || source.player.decoder.source_config.byte_length!=static_cast<std::int32_t>(source.input->size()))return Status::invalid_input;
    if(r.service_divisor.value_or(source.player.decoder.service_divisor)<=0)return Status::unsupported_profile;
    if(r.fault)return Status::fault;
    Busy lock(s.busy);r.pending=std::move(source);
    if(r.active){r.retiring=true;const auto status=retire(key.slot_);if(status!=Status::completed)return status;}
    return open(key.slot_);
}
Status Instances::stop(const Key& key)noexcept {
    auto& s=*state_;if(s.busy)return Status::busy;if(s.closing)return Status::closed;if(!valid(key))return Status::invalid_key;
    Busy lock(s.busy);auto& r=s.records[key.slot_];r.pending.reset();r.retiring=true;return retire(key.slot_);
}
Status Instances::destroy(const Key& key)noexcept {
    auto& s=*state_;if(s.busy)return Status::busy;if(s.closing)return Status::closed;if(!valid(key,true))return Status::invalid_key;
    Busy lock(s.busy);auto& r=s.records[key.slot_];r.pending.reset();r.destroying=true;r.retiring=true;return retire(key.slot_);
}
Status Instances::set_order(std::span<const Key> keys)noexcept {
    auto& s=*state_;if(s.busy)return Status::busy;if(s.closing)return Status::closed;
    unsigned count{};for(const auto& r:s.records)count+=r.owned && !r.destroying;
    if(keys.size()!=count)return Status::invalid_input;
    std::array<bool,16> seen{};
    for(const auto& key:keys){if(!valid(key) || seen[key.slot_])return Status::invalid_key;seen[key.slot_]=true;}
    for(unsigned i=0;i<keys.size();++i)s.order[i]=keys[i].slot_;
    s.ordered=count;s.order_required=false;return Status::completed;
}
Status Instances::publish_order()noexcept {
    auto& s=*state_;std::array<control::Key,16> keys;unsigned active{};
    if(!s.order_required){for(unsigned i=0;i<s.ordered;++i){const auto& r=s.records[s.order[i]];if(r.owned && !r.retiring && r.active)keys[active++]=*r.active;}}
    else{for(const auto& r:s.records)if(r.owned && !r.retiring && r.active)keys[active++]=*r.active;if(active>2)return Status::order_required;}
    return mapped(s.session.set_order(std::span(keys).first(active)));
}
Status Instances::service(std::uint32_t tick)noexcept {
    auto& s=*state_;if(s.busy)return Status::busy;if(s.closing)return Status::closed;
    unsigned prospective{};for(const auto& r:s.records)prospective+=r.owned && !r.destroying && (r.pending || (r.active && !r.retiring));
    if(prospective>2 && s.order_required)return Status::order_required;
    Busy lock(s.busy);bool pending=false,fault=false;
    for(unsigned i=0;i<s.capacity;++i){auto& r=s.records[i];if(!r.owned)continue;
        if(r.retiring){const auto status=retire(i);pending|=status==Status::pending;fault|=status!=Status::pending && status!=Status::completed;if(status!=Status::completed)continue;}
        if(r.owned && r.pending && !r.active){const auto status=open(i);fault|=status!=Status::completed;}}
    const auto ordered=publish_order();if(ordered!=Status::completed)return ordered;
    const auto work=mapped(s.session.service(tick));if(work!=Status::completed)return work;
    return fault?Status::fault:pending?Status::pending:Status::completed;
}
Observation Instances::inspect(const Key& key)const noexcept {
    if(!valid(key,true))return{};
    const auto& s=*state_;const auto& r=s.records[key.slot_];Observation out;
    out.status=Status::completed;out.phase=r.fault?Phase::fault:r.destroying?Phase::destroying:r.retiring?Phase::retiring:r.active?Phase::active:Phase::idle;
    out.replacement_pending=bool(r.pending);out.starts=r.starts;out.completed_stops=r.stops;
    if(r.construction.attenuation_table)out.requested_attenuation=std::bit_cast<std::int16_t>(static_cast<std::uint16_t>(r.attenuation));
    if(r.active){const auto value=s.session.inspect(*r.active);if(value.status!=control::Status::completed)out.status=Status::fault;else out.source=value.evidence;}else out.source=r.final;
    if(out.source && out.source->fault)out.phase=Phase::fault;
    return out;
}
Snapshot Instances::snapshot()const noexcept {
    const auto& s=*state_;Snapshot out;out.session=s.session.snapshot();out.closing=s.closing;out.order_required=s.order_required;
    for(const auto& r:s.records){out.instances+=r.owned;out.pending+=bool(r.pending);out.retiring+=r.retiring;}return out;
}
Status Instances::gain(const Key& key,float value)noexcept {
    auto& s=*state_;if(s.busy)return Status::busy;if(s.closing)return Status::closed;if(!valid(key))return Status::invalid_key;
    if(!std::isfinite(value) || value<0 || value>8)return Status::invalid_input;
    auto& r=s.records[key.slot_];if(r.fault)return Status::fault;Busy lock(s.busy);
    if(r.active && !r.retiring){const auto status=mapped(s.session.gain(*r.active,value));if(status!=Status::completed)return status;}
    r.gain=value;return Status::completed;
}
Status Instances::volume(const Key& key,std::uint32_t value)noexcept {
    auto& s=*state_;if(s.busy)return Status::busy;if(s.closing)return Status::closed;if(!valid(key))return Status::invalid_key;
    auto& r=s.records[key.slot_];if(r.fault)return Status::fault;if(r.construction.attenuation_table)return Status::unsupported_profile;Busy lock(s.busy);
    if(r.active && !r.retiring){const auto status=mapped(s.session.volume(*r.active,value));if(status!=Status::completed)return status;}
    r.volume=value;return Status::completed;
}
Status Instances::attenuation(const Key& key,std::uint32_t value)noexcept {
    auto& s=*state_;if(s.busy)return Status::busy;if(s.closing)return Status::closed;if(!valid(key))return Status::invalid_key;
    auto& r=s.records[key.slot_];if(r.fault)return Status::fault;if(!r.construction.attenuation_table)return Status::unsupported_profile;Busy lock(s.busy);
    if(r.active && !r.retiring){const auto status=mapped(s.session.attenuation(*r.active,value));if(status!=Status::completed)return status;}
    r.attenuation=value;return Status::completed;
}
Status Instances::pause(const Key& key,std::int32_t value,std::uint32_t tick)noexcept {
    auto& s=*state_;if(s.busy)return Status::busy;if(s.closing)return Status::closed;if(!valid(key))return Status::invalid_key;
    auto& r=s.records[key.slot_];if(r.fault)return Status::fault;Busy lock(s.busy);
    if(r.active && !r.retiring){const auto status=mapped(s.session.pause(*r.active,value,tick).status);if(status!=Status::completed)return status;}
    r.pause=value;return Status::completed;
}
control::ClockResult Instances::estimate(const Key& key,std::uint32_t tick)noexcept {
    auto& s=*state_;if(s.busy)return{control::Status::busy,{}};if(s.closing)return{control::Status::closed,{}};if(!valid(key))return{};
    const auto& r=s.records[key.slot_];if(r.fault)return{control::Status::fault,{}};if(!r.active || r.retiring)return{control::Status::pending,{}};
    Busy lock(s.busy);return s.session.estimate(*r.active,tick);
}
control::ClockResult Instances::centiseconds(const Key& key,std::uint32_t tick)noexcept {
    auto& s=*state_;if(s.busy)return{control::Status::busy,{}};if(s.closing)return{control::Status::closed,{}};if(!valid(key))return{};
    const auto& r=s.records[key.slot_];if(r.fault)return{control::Status::fault,{}};if(!r.active || r.retiring)return{control::Status::pending,{}};
    Busy lock(s.busy);return s.session.centiseconds(*r.active,tick);
}
control::RatioResult Instances::ratio(const Key& key,control::player::clock::integer::Query query)noexcept {
    auto& s=*state_;if(s.busy)return{control::Status::busy};if(s.closing)return{control::Status::closed};if(!valid(key))return{};
    const auto& r=s.records[key.slot_];if(r.fault)return{control::Status::fault};if(!r.active || r.retiring)return{control::Status::pending};
    Busy lock(s.busy);return s.session.ratio(*r.active,query);
}
control::ClockControl Instances::discard_rebase(const Key& key,std::uint32_t tick)noexcept {
    auto& s=*state_;if(s.busy)return{control::Status::busy,{}};if(s.closing)return{control::Status::closed,{}};if(!valid(key))return{};
    const auto& r=s.records[key.slot_];if(r.fault)return{control::Status::fault,{}};if(!r.active || r.retiring)return{control::Status::pending,{}};
    Busy lock(s.busy);return s.session.discard_rebase(*r.active,tick);
}
Status Instances::configure_clock(control::ClockConfiguration value)noexcept {
    auto& s=*state_;if(s.busy)return Status::busy;if(s.closing)return Status::closed;Busy lock(s.busy);return mapped(s.session.configure_clock(value));
}
Status Instances::set_time_base(const Key& key,std::uint32_t value)noexcept {
    auto& s=*state_;if(s.busy)return Status::busy;if(s.closing)return Status::closed;if(!valid(key))return Status::invalid_key;
    auto& r=s.records[key.slot_];if(r.fault)return Status::fault;Busy lock(s.busy);
    if(r.active && !r.retiring){const auto status=mapped(s.session.set_time_base(*r.active,value));if(status!=Status::completed)return status;}
    r.time_base=value;return Status::completed;
}
Status Instances::set_loop_enabled(const Key& key,bool value)noexcept {
    auto& s=*state_;if(s.busy)return Status::busy;if(s.closing)return Status::closed;if(!valid(key))return Status::invalid_key;
    auto& r=s.records[key.slot_];if(r.fault)return Status::fault;
    Busy lock(s.busy);
    if(r.active && !r.retiring && !r.active_playlist){const auto status=mapped(s.session.set_loop_enabled(*r.active,value));if(status!=Status::completed)return status;}
    r.loop_enabled=value;return Status::completed;
}
Status Instances::set_service_divisor(const Key& key,std::int32_t value)noexcept {
    auto& s=*state_;if(s.busy)return Status::busy;if(s.closing)return Status::closed;if(!valid(key))return Status::invalid_key;
    auto& r=s.records[key.slot_];if(r.fault)return Status::fault;if(value<=0)return Status::unsupported_profile;Busy lock(s.busy);
    if(r.active && !r.retiring){const auto status=mapped(s.session.set_service_divisor(*r.active,value));if(status!=Status::completed)return status;}
    r.service_divisor=value;return Status::completed;
}
Status Instances::set_start_inhibit(const Key& key,bool value)noexcept {
    auto& s=*state_;if(s.busy)return Status::busy;if(s.closing)return Status::closed;if(!valid(key))return Status::invalid_key;
    auto& r=s.records[key.slot_];if(r.fault)return Status::fault;Busy lock(s.busy);
    if(r.active && !r.retiring){const auto status=mapped(s.session.set_start_inhibit(*r.active,value));if(status!=Status::completed)return status;}
    r.start_inhibit=value;return Status::completed;
}
Status Instances::request_stop()noexcept {
    auto& s=*state_;if(s.busy)return Status::busy;if(s.closing)return Status::completed;Busy lock(s.busy);s.closing=true;
    for(auto& r:s.records){r.pending.reset();if(r.owned){r.retiring=true;r.destroying=true;}}
    return mapped(s.session.request_stop());
}
Status Instances::join()noexcept {
    auto& s=*state_;if(s.busy)return Status::busy;const auto stopped=request_stop();if(stopped!=Status::completed)return stopped;Busy lock(s.busy);
    const auto result=mapped(s.session.join());if(result==Status::completed)for(unsigned i=0;i<s.capacity;++i)if(s.records[i].owned)release(i);
    return result;
}
namespace {
control::Status source_control_status(Status value)noexcept {
    switch(value){
    case Status::completed:return control::Status::completed;
    case Status::busy:return control::Status::busy;
    case Status::closed:return control::Status::closed;
    case Status::invalid_key:return control::Status::invalid_key;
    default:return control::Status::fault;
    }
}
}
Status Instances::source_status(const SourceKey& key)const noexcept {
    const auto& s=*state_;
    if(s.busy)return Status::busy;
    if(s.closing)return Status::closed;
    if(!valid(key.instance_))return Status::invalid_key;
    const auto& record=s.records[key.instance_.slot_];
    if(record.fault)return Status::fault;
    if(!record.active || record.retiring || record.pending)return Status::closed;
    const auto observed=s.session.inspect(key.source_);
    if(observed.status!=control::Status::completed)return mapped(observed.status);
    if(observed.evidence.fault)return Status::fault;
    if(observed.evidence.stop_requested || observed.evidence.output_retired || observed.evidence.retired)return Status::closed;
    if(!observed.evidence.clock_observation_valid)return Status::fault;
    return Status::completed;
}
SourceCapture Instances::capture_source(const Key& instance)const noexcept {
    const auto& s=*state_;
    if(s.busy)return{Status::busy,{}};
    if(s.closing)return{Status::closed,{}};
    if(!valid(instance))return{};
    const auto& record=s.records[instance.slot_];
    if(record.fault)return{Status::fault,{}};
    if(!record.active || record.retiring || record.pending)return{Status::closed,{}};
    SourceKey key;key.instance_=instance;key.source_=*record.active;
    const auto status=source_status(key);
    if(status!=Status::completed)return{status,{}};
    return{Status::completed,std::move(key)};
}
control::Observation Instances::inspect_source(const SourceKey& key)const noexcept {
    const auto status=source_status(key);
    if(status!=Status::completed)return{source_control_status(status),{}};
    return state_->session.inspect(key.source_);
}
control::ClockResult Instances::estimate_source(const SourceKey& key,std::uint32_t tick)noexcept {
    const auto status=source_status(key);
    if(status!=Status::completed)return{source_control_status(status),{}};
    auto& s=*state_;Busy scope(s.busy);return s.session.estimate(key.source_,tick);
}
control::ClockControl Instances::pause_source(const SourceKey& key,std::int32_t argument,std::uint32_t tick)noexcept {
    const auto status=source_status(key);
    if(status!=Status::completed)return{source_control_status(status),{}};
    // Preserve the stable instance's persistent pause policy for a later start.
    auto& s=*state_;Busy scope(s.busy);const auto result=s.session.pause(key.source_,argument,tick);
    if(result.status==control::Status::completed)s.records[key.instance_.slot_].pause=argument;
    return result;
}
control::ClockControl Instances::discard_source(const SourceKey& key,std::uint32_t tick)noexcept {
    const auto status=source_status(key);
    if(status!=Status::completed)return{source_control_status(status),{}};
    auto& s=*state_;Busy scope(s.busy);return s.session.discard_rebase(key.source_,tick);
}
} // namespace reo::native::adxt_instances
