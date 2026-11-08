#include "queue.hpp"
#include <array>
#include <limits>
#include <stdexcept>
#include <string>

namespace reo::native::audio_cue_queue {
namespace loading=audio_clip_loader;
namespace input=adxt_lsc_input;
namespace instances=adxt_instances;
struct Queue::State {
    struct Pending { std::string id; loading::Key key; };
    Config config;
    std::shared_ptr<loading::Loader> loader;
    std::array<Pending,16> pending;
    std::uint32_t head{},count{};
    instances::Instances* identity{};
    instances::Key key;
    std::shared_ptr<input::Input> source;
    Snapshot report;
    State(Config c,std::shared_ptr<loading::Loader> worker):config(c),loader(std::move(worker)) {
        if(!loader || c.channels<1 || c.channels>2 || !adxt_shared_source::admits_capacity(
            static_cast<std::int32_t>(c.encoded_capacity),adxt_shared_source::CapacityProfile::bounded_sectors))
            throw std::invalid_argument("Bounded native cue queue required");
    }
    Status admitted(instances::Instances& owner) const noexcept {
        if(report.closed)return Status::closed;
        if(identity!=&owner || owner.inspect(key).status!=instances::Status::completed)return Status::invalid_owner;
        return Status::completed;
    }
    void cancel_preparations() noexcept {
        while(count){(void)loader->release(pending[head].key);pending[head]={};head=(head+1)%pending.size();--count;}
        head=0;
    }
    void reset() noexcept {
        cancel_preparations();source.reset();report.play_requested=report.source_submitted=report.failed=false;
        report.preparation_status=loading::Status::pending;report.clip_status=adx_sequence::Status::invalid_input;
        report.source_status=instances::Status::completed;
        report.retirement_status=instances::Status::completed;report.failure=Status::completed;
    }
    Status fail(instances::Instances& owner,Status status) noexcept {
        report.failed=true;report.failure=status;
        if(report.source_submitted)report.retirement_status=owner.stop(key);
        cancel_preparations();return status;
    }
};
Queue::Queue(Config config,std::shared_ptr<loading::Loader> loader):state_(std::make_unique<State>(config,std::move(loader))){}
Queue::~Queue(){state_->cancel_preparations();}
Status Queue::bind(instances::Instances& owner,const instances::Key& key) noexcept {
    auto& s=*state_;
    if(s.report.closed)return Status::closed;
    if(s.identity || owner.inspect(key).status!=instances::Status::completed)return Status::invalid_owner;
    s.identity=&owner;s.key=key;s.report.bound=true;return Status::completed;
}
Entry Queue::enqueue(instances::Instances& owner,std::string_view id,std::shared_ptr<const resources::ByteView> view) noexcept {
    auto& s=*state_;const auto admission=s.admitted(owner);if(admission!=Status::completed)return{admission,0};
    if(s.report.failed)return{Status::fault,0};
    if(id.empty() || id.size()>384 || id.find('\0')!=id.npos || !view)return{Status::invalid_input,0};
    if(s.source && (s.source->snapshot().closing || s.source->snapshot().decoder_ended))return{Status::closed,0};
    const auto queued=s.source?s.source->snapshot().queue.count:0;
    if(s.count+queued>=s.pending.size() || s.report.accepted==std::numeric_limits<std::uint64_t>::max())return{Status::capacity,0};
    try {
        std::string owned(id);const auto request=s.loader->prepare(std::move(view));
        if(request.status!=loading::Status::accepted){s.report.preparation_status=request.status;
            return{request.status==loading::Status::capacity || request.status==loading::Status::queue_full?Status::capacity:
                request.status==loading::Status::no_memory?Status::no_memory:Status::source_failure,0};}
        auto& entry=s.pending[(s.head+s.count)%s.pending.size()];entry.id=std::move(owned);entry.key=request.key;++s.count;++s.report.accepted;
        if(s.source && s.source->preparing_assets(s.count)!=input::Status::completed)return{s.fail(owner,Status::fault),0};
        return{Status::completed,s.report.accepted};
    }catch(const std::bad_alloc&){return{Status::no_memory,0};}catch(...){return{Status::fault,0};}
}
Status Queue::service(instances::Instances& owner,std::uint32_t tick) noexcept {
    auto& s=*state_;const auto admission=s.admitted(owner);if(admission!=Status::completed)return admission;
    if(s.report.failed)return Status::fault;
    const auto current=owner.inspect(s.key);
    if(current.phase==instances::Phase::fault){s.report.source_status=instances::Status::fault;return s.fail(owner,Status::source_failure);}
    if(s.report.retirement_status==instances::Status::pending && current.phase!=instances::Phase::retiring)
        s.report.retirement_status=instances::Status::completed;
    try {
        while(s.count){
            auto& entry=s.pending[s.head];const auto prepared=s.loader->poll(entry.key);
            s.report.preparation_status=prepared.status;s.report.clip_status=prepared.detail;
            if(prepared.status==loading::Status::pending)break;
            if(prepared.status!=loading::Status::ready || !prepared.clip)return s.fail(owner,Status::source_failure);
            const auto& header=prepared.clip->metadata().header;
            if(header.active_channels!=static_cast<std::int32_t>(s.config.channels))return s.fail(owner,Status::unsupported_profile);
            if(!s.source){
                s.source=input::Input::create({s.config.channels,header.base.frequency,8192,8,s.config.encoded_capacity});
                if(s.source->repeat(s.report.repeat?1:0)!=input::Status::completed)return s.fail(owner,Status::fault);
            }
            const auto asset=s.source->register_asset(entry.id,prepared.clip);
            if(asset.status!=input::Status::completed)return s.fail(owner,asset.status==input::Status::no_memory?Status::no_memory:Status::unsupported_profile);
            if(s.source->enqueue(asset.key).status!=input::Status::completed)return s.fail(owner,Status::fault);
            if(s.loader->release(entry.key)!=loading::Status::completed)return s.fail(owner,Status::fault);
            entry={};s.head=(s.head+1)%s.pending.size();--s.count;
            if(s.source->preparing_assets(s.count)!=input::Status::completed)return s.fail(owner,Status::fault);
        }
        if(s.source && s.source->snapshot().error!=input::Status::completed)return s.fail(owner,Status::source_failure);
        if(s.report.play_requested && s.source && !s.report.source_submitted){
            if(s.source->start()!=input::Status::completed)return s.fail(owner,Status::fault);
            instances::Source source;source.input=s.source->origin();source.player.lsc_input=s.source;
            source.player.initial_tick=tick;source.player.decoder.channels=s.config.channels;source.player.decoder.seamless_enabled=true;
            auto& geometry=source.player.decoder.source_config;
            geometry.byte_length=static_cast<std::int32_t>(input::byte_domain);
            geometry.capacity=geometry.threshold=geometry.maximum_request_bytes=static_cast<std::int32_t>(s.config.encoded_capacity);
            geometry.maximum_sectors=static_cast<std::int32_t>(s.config.encoded_capacity/2048);
            source.player.decoder.source_capacity=s.config.encoded_capacity==8192?adxt_shared_source::CapacityProfile::fixed_8k:adxt_shared_source::CapacityProfile::bounded_sectors;
            s.report.source_status=owner.start(s.key,std::move(source));
            if(s.report.source_status!=instances::Status::completed && s.report.source_status!=instances::Status::pending)return s.fail(owner,Status::fault);
            s.report.source_submitted=true;++s.report.submitted_sources;
        }
        return s.count || s.report.retirement_status==instances::Status::pending || (s.report.play_requested && !s.report.source_submitted)?Status::pending:Status::completed;
    }catch(const std::bad_alloc&){return s.fail(owner,Status::no_memory);}catch(...){return s.fail(owner,Status::fault);}
}
Status Queue::start(instances::Instances& owner,std::uint32_t tick) noexcept {
    auto& s=*state_;const auto admission=s.admitted(owner);if(admission!=Status::completed)return admission;
    if(s.report.failed)return Status::fault;
    if(s.report.play_requested)return Status::already_started;
    s.report.play_requested=true;return service(owner,tick);
}
Status Queue::repeat(instances::Instances& owner,bool enabled) noexcept {
    auto& s=*state_;const auto admission=s.admitted(owner);if(admission!=Status::completed)return admission;
    if(s.report.failed)return Status::fault;
    if(s.source && s.source->repeat(enabled?1:0)!=input::Status::completed)return Status::source_failure;
    s.report.repeat=enabled;return Status::completed;
}
Status Queue::clear(instances::Instances& owner) noexcept {
    auto& s=*state_;const auto admission=s.admitted(owner);if(admission!=Status::completed)return admission;
    if(s.report.source_submitted)return Status::unsupported_profile;
    s.reset();return Status::completed;
}
Status Queue::stop(instances::Instances& owner) noexcept {
    auto& s=*state_;const auto admission=s.admitted(owner);if(admission!=Status::completed)return admission;
    const auto stopped=owner.stop(s.key);
    if(stopped!=instances::Status::completed && stopped!=instances::Status::pending){s.report.source_status=stopped;return Status::fault;}
    s.reset();s.report.retirement_status=stopped;return stopped==instances::Status::pending?Status::pending:Status::completed;
}
Status Queue::close(instances::Instances& owner) noexcept {
    const auto stopped=stop(owner);
    if(stopped==Status::completed || stopped==Status::pending)state_->report.closed=true;
    return stopped;
}
Snapshot Queue::snapshot() const noexcept {
    const auto& s=*state_;auto report=s.report;report.preparing=s.count;report.queued=s.count;
    if(s.source){const auto source=s.source->snapshot();report.queued+=source.queue.count;report.registered_assets=source.registered_assets;report.decoder_ended=source.decoder_ended;}
    return report;
}
}
