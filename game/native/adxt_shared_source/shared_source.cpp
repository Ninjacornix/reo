// Source2 ownership extension. Source1's qualified refill arithmetic/backend
// policy is reused; two-consumer and typed-target ownership are new policy.
#include "shared_source.hpp"
#include <algorithm>
#include <bit>
#include <limits>
#include <stdexcept>
#include <utility>

namespace reo::native::adxt_shared_source {
namespace {
constexpr std::int32_t sector=2048;
bool geometry(HeaderGeometry h)noexcept {
    return h.loop_start_bytes>=0&&h.loop_end_bytes>=h.loop_start_bytes&&
        h.loop_start_samples>=0&&h.loop_end_samples>=h.loop_start_samples;
}
bool selectors(FileTargetAction f,DecoderLimitAction d)noexcept {
    return (f==FileTargetAction::none||f==FileTargetAction::file_loop)&&
        unsigned(d)<=unsigned(DecoderLimitAction::seamless);
}
bool target(std::int32_t t,std::int32_t sectors)noexcept{return t==-1||t==INT32_MAX||(t>=0&&t<=sectors);}
std::int32_t checked_capacity(const Config& c,CapacityProfile profile) {
    if(!admits_capacity(c.capacity,profile)||c.start_sector<0||c.start_sector>INT32_MAX/sector||
        c.byte_length<0||c.byte_length%sector||c.threshold<0||c.threshold>c.capacity||
        c.maximum_request_bytes<0||c.maximum_request_bytes>c.capacity||c.maximum_sectors<0||c.maximum_sectors>512||
        !target(c.target_sectors,c.byte_length/sector)||c.finite_sector_limit<0||c.finite_sector_limit>0xfffff||
        c.retry_limit< -1||c.retry_limit>127||!c.maximum_id||
        std::int64_t(c.start_sector)*sector+c.byte_length>INT32_MAX)
        throw std::invalid_argument("Unsupported shared encoded-source geometry");
    return c.capacity;
}
Grant grant(const sjrb::Chunk& c)noexcept{return {c.is_null()?0:c.offset(),c.bytes()};}
bool positive(std::int64_t n)noexcept{return n>=0&&n<=INT32_MAX;}
// Preflight exact unget/put effects. A zero/nonpositive span is the actual
// Ring's immediate NOOP: no synthetic position error or counter change.
bool unget(sjrb::Snapshot& s,std::uint32_t pool,const sjrb::Chunk& c)noexcept {
    if(c.is_null()||c.bytes()<=0)return true;
    auto& p=pool?s.read:s.write;auto& n=pool?s.data:s.free;
    const auto before=(std::int64_t(p)+s.capacity-c.bytes())%s.capacity;
    if(before<0||before!=c.offset()%s.capacity||std::int64_t(n)+c.bytes()>s.capacity)return false;
    p=std::int32_t(before);n+=c.bytes();s.totals[pool*2]-=std::uint32_t(c.bytes());return true;
}
bool put(sjrb::Snapshot& s,std::uint32_t pool,const sjrb::Chunk& c)noexcept {
    if(c.is_null()||c.bytes()<=0)return true;
    auto& n=pool?s.data:s.free;if(std::int64_t(n)+c.bytes()>s.capacity)return false;
    n+=c.bytes();s.totals[pool*2+1]+=std::uint32_t(c.bytes());return true;
}
}
struct LeaseDomain {bool alive{true},busy{},readable{true};std::uint64_t epoch{1},active{};};
struct LoopDomain {LoopSnapshot state;std::int32_t file_sectors{};bool busy{};};
bool WindowLink::valid()const noexcept{return domain_&&domain_->state.alive&&domain_->state.epoch==epoch_;}
LoopSnapshot WindowLink::snapshot()const noexcept{return valid()?domain_->state:LoopSnapshot{{},-1,0,FileTargetAction::none,DecoderLimitAction::none,false,false,0};}
Status WindowLink::configure(HeaderGeometry h,std::int32_t limit,std::int32_t t,FileTargetAction f,DecoderLimitAction d)noexcept {
    if(!valid())return Status::closed;if(domain_->busy)return Status::reentrant_call;
    if(!geometry(h)||limit< -1||!target(t,domain_->file_sectors)||!selectors(f,d))return Status::invalid_configuration;
    auto& s=domain_->state;s.header=h;s.sample_limit=limit;s.target_sectors=t==-1?domain_->file_sectors:t;s.file_action=f;s.decoder_action=d;return Status::completed;
}
Status WindowLink::set_sample_limit(std::int32_t n,DecoderLimitAction d)noexcept {
    if(!valid())return Status::closed;if(domain_->busy)return Status::reentrant_call;
    if(n< -1||unsigned(d)>unsigned(DecoderLimitAction::seamless))return Status::invalid_configuration;
    domain_->state.sample_limit=n;domain_->state.decoder_action=d;return Status::completed;
}
ReadBatch::ReadBatch(ReadBatch&& other)noexcept:domain_(std::move(other.domain_)),chunks_(std::move(other.chunks_)),
    epoch_(other.epoch_),id_(std::exchange(other.id_,0)),count_(std::exchange(other.count_,0)){}
std::uint32_t ReadBatch::count()const noexcept{return id_?count_:0;}
std::int32_t ReadBatch::offset(std::uint32_t i)const noexcept{return id_&&i<count_?chunks_[i].offset():0;}
std::int32_t ReadBatch::bytes(std::uint32_t i)const noexcept{return id_&&i<count_?chunks_[i].bytes():0;}
Status ReadBatch::read_into(std::uint32_t i,std::span<std::uint8_t> out,std::size_t relative)const noexcept {
    if(!domain_||!domain_->alive||!domain_->readable||domain_->epoch!=epoch_||!id_||domain_->active!=id_||i>=count_)return Status::invalid_lease;
    if(domain_->busy)return Status::reentrant_call;
    return chunks_[i].read(out,relative)==sjrb::Status::completed?Status::completed:Status::invalid_count;
}
class SharedEncodedSource::Scope final {
public:
    explicit Scope(SharedEncodedSource& s):s_(s),entered_(!s.busy_){if(entered_){s.busy_=true;s.leases_->busy=true;s.loop_->busy=true;}}
    ~Scope(){if(entered_){s_.state_.transfer=Transfer::none;s_.state_.transfer_bytes=0;s_.busy_=false;s_.leases_->busy=false;s_.loop_->busy=false;}}
    explicit operator bool()const noexcept{return entered_;}
private:SharedEncodedSource& s_;bool entered_;
};
SharedEncodedSource::SharedEncodedSource(Config c,std::shared_ptr<const resources::ByteView> view,
    std::unique_ptr<Backend> backend,InitialLoop loop,PreparedPrefix prefix,Hooks hooks,CapacityProfile profile)
    :config_(c),hooks_(hooks),ring_(checked_capacity(c,profile),encoded_extension,{},0xa5),view_(std::move(view)),backend_(std::move(backend)),
     leases_(std::make_shared<LeaseDomain>()),loop_(std::make_shared<LoopDomain>()) {
    const auto begin=std::uint64_t(c.start_sector)*sector;
    if(!backend_||!view_||begin>view_->size()||std::uint64_t(c.byte_length)>view_->size()-begin||
       prefix.position<0||prefix.position>=c.capacity||prefix.progress_sectors<0||
       prefix.bytes.size()>std::size_t(c.capacity)||!geometry(loop.header)||loop.sample_limit< -1||!selectors(loop.file_action,loop.decoder_action))
        throw std::invalid_argument("Invalid prepared shared source");
    loop_->file_sectors=c.byte_length/sector;
    loop_->state={loop.header,loop.sample_limit,c.target_sectors==-1?loop_->file_sectors:c.target_sectors,
        loop.file_action,loop.decoder_action,loop.enabled,true,1};
    if(prefix.position){sjrb::Chunk p;
        if(ring_.get(0,prefix.position,p)!=sjrb::Status::completed||p.bytes()!=prefix.position||
           ring_.put(1,p)!=sjrb::Status::completed||ring_.get(1,prefix.position,p)!=sjrb::Status::completed||
           ring_.put(0,p)!=sjrb::Status::completed)throw std::invalid_argument("Prepared cursor refused");}
    std::size_t written=0;
    while(written<prefix.bytes.size()){sjrb::Chunk p;
        if(ring_.get(0,std::int32_t(prefix.bytes.size()-written),p)!=sjrb::Status::completed||p.bytes()<=0||
           p.write(prefix.bytes.subspan(written,std::size_t(p.bytes())))!=sjrb::Status::completed||ring_.put(1,p)!=sjrb::Status::completed)
            throw std::invalid_argument("Prepared prefix refused");written+=std::size_t(p.bytes());}
    if(ring_.set_hooks(hooks.ring)!=sjrb::Status::completed)throw std::invalid_argument("Ring hooks refused");
    state_.state=c.byte_length?2:3;state_.progress_sectors=std::min(prefix.progress_sectors,loop_->file_sectors);
    state_.service_requested=true;state_.source_open=true;state_.epoch=1;
}
SharedEncodedSource::~SharedEncodedSource(){leases_->alive=false;loop_->state.alive=false;backend_.reset();}
Snapshot SharedEncodedSource::snapshot()const noexcept {
    auto out=state_;out.ring=ring_.snapshot();out.loop=loop_->state;out.producer=grant(producer_);
    for(unsigned i=0;i<2;++i)out.consumers[i]=grant(consumers_[i]);return out;
}
bool SharedEncodedSource::conservation()const noexcept {
    const auto s=ring_.snapshot();std::int64_t sum=std::int64_t(s.data)+s.free+state_.producer_remaining.bytes;
    if(s.data<0||s.free<0||s.data>config_.capacity||s.free>config_.capacity||state_.producer_remaining.bytes<0||
       s.read<0||s.read>=config_.capacity||s.write<0||s.write>=config_.capacity)return false;
    for(const auto& c:consumers_){if(c.bytes()<0)return false;sum+=c.bytes();}
    return sum==config_.capacity;
}
Status SharedEncodedSource::fail(Status status,bool terminal,bool ledger)noexcept {
    state_.last_error=status;if(terminal)state_.state=4;
    if(ledger){state_.ledger_fault=true;leases_->readable=false;}return status;
}
LinkResult SharedEncodedSource::take_window_link()noexcept {
    Scope scope(*this);if(!scope)return {Status::reentrant_call,{}};
    if(state_.shutting_down||state_.joined)return {Status::closed,{}};
    if(linked_)return {Status::busy,{}};
    WindowLink link;link.domain_=loop_;link.epoch_=loop_->state.epoch;linked_=true;return {Status::completed,std::move(link)};
}
BatchResult SharedEncodedSource::borrow_batch(BatchRequest request)noexcept {
    Scope scope(*this);if(!scope)return {Status::reentrant_call,{}};
    if(state_.shutting_down||state_.joined)return {Status::closed,{}};
    if(state_.ledger_fault)return {Status::invariant_fault,{}};
    if(leases_->active)return {Status::busy,{}};
    if((request.shape!=BatchShape::one&&request.shape!=BatchShape::two)||request.first_max<0||request.second_max<0||
       (request.shape==BatchShape::one&&request.second_max!=0))return {Status::invalid_count,{}};
    if(last_batch_==config_.maximum_id)return {Status::id_exhausted,{}};
    if(!conservation())return {fail(Status::invariant_fault,true,true),{}};
    const auto count=request.shape==BatchShape::one?1u:2u;
    // Valid owned Ring state + bounded geometry make each nonnegative Get total.
    const auto initial=ring_.snapshot();if(initial.read<0||initial.read>=config_.capacity)return {fail(Status::invariant_fault,true,true),{}};
    ReadBatch batch;batch.domain_=leases_;batch.epoch_=state_.epoch;batch.id_=++last_batch_;
    leases_->active=batch.id_;state_.batch_id=batch.id_;state_.consumer_count=0;
    for(unsigned i=0;i<count;++i){state_.transfer=Transfer::acquire_consumer;
        if(ring_.get(1,i?request.second_max:request.first_max,consumers_[i])!=sjrb::Status::completed){
            (void)fail(Status::ring_failure,true,true);batch.count_=state_.consumer_count;return {Status::ring_failure,std::move(batch)};}
        ++state_.consumer_count;batch.chunks_[i]=consumers_[i];batch.count_=state_.consumer_count;
    }
    if(!conservation())return {fail(Status::invariant_fault,true,true),std::move(batch)};
    return {Status::completed,std::move(batch)};
}
Status SharedEncodedSource::finish_batch(ReadBatch& batch,FinishPlan plan)noexcept {
    Scope scope(*this);if(!scope)return Status::reentrant_call;
    if(state_.ledger_fault)return Status::invariant_fault;
    if(batch.domain_.get()!=leases_.get()||!batch.id_||batch.id_!=leases_->active||batch.epoch_!=state_.epoch||
       batch.count_!=state_.consumer_count||!leases_->alive)return Status::invalid_lease;
    if(!conservation())return fail(Status::invariant_fault,true,true);
    for(unsigned i=0;i<batch.count_;++i)if(batch.chunks_[i].offset()!=consumers_[i].offset()||batch.chunks_[i].bytes()!=consumers_[i].bytes()||
        batch.chunks_[i].incarnation()!=consumers_[i].incarnation())return Status::invalid_lease;
    struct Step{bool restore;unsigned index;sjrb::Chunk chunk;std::array<sjrb::Chunk,2> remaining;sjrb::Snapshot after;};
    std::array<Step,4> steps{};unsigned count=0;auto remaining=consumers_;auto shadow=ring_.snapshot();
    auto append=[&](bool restore,unsigned index,const sjrb::Chunk& chunk,const sjrb::Chunk& residue){
        if(count>=steps.size())return false;
        if(!(restore?unget(shadow,1,chunk):put(shadow,0,chunk)))return false;
        remaining[index]=residue;steps[count++]={restore,index,chunk,remaining,shadow};return true;
    };
    sjrb::Chunk prefix,suffix,none;
    auto split=[&](unsigned i){return plan.prefix_bytes>=0&&plan.prefix_bytes<=consumers_[i].bytes()&&
        sjrb::Chunk::split(consumers_[i],plan.prefix_bytes,prefix,suffix)==sjrb::Status::completed;};
    bool valid=false;
    switch(plan.kind){
    case FinishKind::consume_single_prefix:
        valid=batch.count_==1&&split(0)&&append(false,0,prefix,suffix)&&append(true,0,suffix,none);break;
    case FinishKind::restore_reverse:
        valid=plan.prefix_bytes==0;
        if(valid&&batch.count_==2)valid=append(true,1,consumers_[1],none);
        if(valid)valid=append(true,0,consumers_[0],none);break;
    case FinishKind::consume_first_prefix_restore_second:
        valid=batch.count_==2&&split(0)&&append(true,1,consumers_[1],none)&&append(false,0,prefix,suffix)&&append(true,0,suffix,none);break;
    case FinishKind::consume_second_prefix_consume_first:
        valid=batch.count_==2&&split(1)&&append(false,0,consumers_[0],none)&&append(false,1,prefix,suffix)&&append(true,1,suffix,none);break;
    }
    if(!valid)return Status::invalid_count; // No actual credit effects yet.
    for(unsigned i=0;i<count;++i){auto& step=steps[i];state_.transfer=step.restore?Transfer::restore_data:Transfer::consume_data;state_.transfer_bytes=step.chunk.bytes();
        auto status=step.restore?ring_.unget(1,step.chunk):ring_.put(0,step.chunk);
        const auto actual=ring_.snapshot();
        // The real Ring.completed alone is insufficient for Unget correctness.
        if(actual==step.after)consumers_=step.remaining;
        else return fail(Status::invariant_fault,true,true);
        if(status!=sjrb::Status::completed)return fail(Status::ring_failure,true,true);
    }
    leases_->active=0;state_.batch_id=0;state_.consumer_count=0;
    batch.id_=0;batch.count_=0;batch.domain_.reset();for(auto& chunk:batch.chunks_)chunk.clear();
    if(!conservation())return fail(Status::invariant_fault,true,true);return Status::completed;
}
Status SharedEncodedSource::return_producer(bool error)noexcept {
    auto expected=ring_.snapshot();if(!unget(expected,0,producer_))return fail(Status::invariant_fault,true,true);
    state_.transfer=Transfer::restore_free;state_.transfer_bytes=producer_.bytes();
    const auto result=ring_.unget(0,producer_);
    if(ring_.snapshot()!=expected)return fail(Status::invariant_fault,true,true);
    state_.producer_remaining={};producer_.clear();state_.in_flight=false;
    if(result!=sjrb::Status::completed)return fail(Status::ring_failure,true,true);
    if(error&&config_.retry_limit>=0){if(state_.retries>=config_.retry_limit)state_.state=4;else ++state_.retries;}
    return conservation()?Status::completed:fail(Status::invariant_fault,true,true);
}
ServiceResult SharedEncodedSource::publish(adxt_refill::Completion& completion)noexcept {
    const auto bytes=std::int64_t(state_.accepted_sectors)*sector;
    if(completion.request_id!=state_.request_id||bytes<0||bytes>producer_.bytes()||completion.bytes.size()!=std::size_t(bytes))return {fail(Status::provider_protocol,true)};
    if(!positive(std::int64_t(state_.cumulative_bytes)+bytes)||!positive(std::int64_t(state_.progress_sectors)+state_.accepted_sectors)||
       state_.progress_sectors+state_.accepted_sectors>loop_->file_sectors||!conservation())return {fail(Status::invariant_fault,true)};
    sjrb::Chunk prefix,suffix;auto shadow=ring_.snapshot();
    if(sjrb::Chunk::split(producer_,std::int32_t(bytes),prefix,suffix)!=sjrb::Status::completed||!put(shadow,1,prefix))return {fail(Status::invariant_fault,true,true)};
    const auto after_put=shadow;if(!unget(shadow,0,suffix))return {fail(Status::invariant_fault,true,true)};
    if(producer_.write({reinterpret_cast<const std::uint8_t*>(completion.bytes.data()),std::size_t(bytes)})!=sjrb::Status::completed)return {fail(Status::ring_failure,true,true)};
    state_.in_flight=false;state_.transfer=Transfer::publish_data;state_.transfer_bytes=prefix.bytes();
    const auto put_status=ring_.put(1,prefix);
    if(ring_.snapshot()!=after_put)return {fail(Status::invariant_fault,true,true)};
    state_.producer_remaining=grant(suffix);if(put_status!=sjrb::Status::completed)return {fail(Status::ring_failure,true,true)};
    state_.transfer=Transfer::restore_free;state_.transfer_bytes=suffix.bytes();const auto unget_status=ring_.unget(0,suffix);
    if(ring_.snapshot()!=shadow)return {fail(Status::invariant_fault,true,true)};
    state_.producer_remaining={};if(unget_status!=sjrb::Status::completed)return {fail(Status::ring_failure,true,true)};
    state_.cumulative_bytes+=std::int32_t(bytes);state_.progress_sectors+=state_.accepted_sectors;producer_.clear();
    ServiceResult result;result.published=true;
    if(state_.progress_sectors==loop_->state.target_sectors&&(loop_->state.file_action==FileTargetAction::file_loop||hooks_.target)){
        TargetObservation observation;state_.transfer=Transfer::none;state_.transfer_bytes=0;observation.before=snapshot();result.target_invoked=true;
        if(loop_->state.file_action==FileTargetAction::file_loop){
            if(loop_->state.enabled){const auto old=state_.progress_sectors;
                state_.progress_sectors=std::min(loop_->state.header.loop_start_bytes/sector,loop_->file_sectors);result.progress_rewound=state_.progress_sectors!=old;
            }else{loop_->state.sample_limit=-1;loop_->state.target_sectors=INT32_MAX;result.limit_removed=true;}
        }
        observation.after=snapshot();if(hooks_.target)hooks_.target(hooks_.context,observation);
    }
    if(state_.progress_sectors>=loop_->file_sectors||state_.cumulative_bytes/sector>=config_.finite_sector_limit)state_.state=3;
    state_.retries=0;if(!conservation())result.status=fail(Status::invariant_fault,true,true);return result;
}
ServiceResult SharedEncodedSource::service()noexcept {
    Scope scope(*this);if(!scope)return {Status::reentrant_call};
    if(state_.joined)return {Status::closed};
    if(state_.ledger_fault)return {Status::invariant_fault};
    if(!state_.in_flight){
        if(state_.stop_requested){if(!state_.service_requested)state_.state=1;state_.stop_requested=false;}
        if(state_.close_requested){view_.reset();state_.source_open=false;state_.close_requested=false;}
        state_.service_requested=false;
    }
    if(state_.state!=2||!state_.source_open)return {};
    auto completion=backend_->poll();
    if(state_.in_flight){
        if(completion.state==adxt_refill::BackendState::pending||completion.state==adxt_refill::BackendState::idle)return {};
        if(completion.request_id!=state_.request_id)return {fail(Status::provider_protocol,true)};
        if(completion.state==adxt_refill::BackendState::complete)return publish(completion);
        state_.in_flight=false;const auto restored=return_producer(true);
        return {restored==Status::completed?fail(Status::provider_failure):restored};
    }
    if(completion.state==adxt_refill::BackendState::pending||completion.state==adxt_refill::BackendState::complete)return {fail(Status::provider_protocol,true)};
    if(state_.paused==1||state_.stop_requested||state_.shutting_down)return {};
    if(!conservation())return {fail(Status::invariant_fault,true,true)};
    const auto ring=ring_.snapshot();if(config_.capacity-ring.free>=config_.threshold)return {};
    if(last_request_==config_.maximum_id)return {fail(Status::id_exhausted)};
    const auto candidate=std::min({config_.capacity-ring.write+encoded_extension,ring.free,config_.maximum_request_bytes});
    const auto count=std::min({candidate/sector,loop_->state.target_sectors-state_.progress_sectors,
        loop_->file_sectors-state_.progress_sectors,config_.maximum_sectors});
    const auto possible=std::int64_t(count)*sector;
    if(count<0||!positive(std::int64_t(state_.cumulative_bytes)+possible)||
       !positive((std::int64_t(config_.start_sector)+state_.progress_sectors)*sector+possible))return {fail(Status::invalid_configuration)};
    state_.in_flight=true;state_.transfer=Transfer::acquire_producer;
    const auto got=ring_.get(0,config_.maximum_request_bytes,producer_);state_.producer_remaining=grant(producer_);
    if(got!=sjrb::Status::completed||producer_.bytes()!=candidate)return {fail(Status::ring_failure,true,true)};
    state_.request_id=++last_request_;
    const auto offset=(std::uint64_t(config_.start_sector)+std::uint32_t(state_.progress_sectors))*sector;
    const auto acceptance=backend_->submit(view_,offset,std::uint32_t(count),state_.request_id);state_.accepted_sectors=acceptance.sectors;
    if(acceptance.sectors>count)return {fail(Status::provider_protocol,true)};
    if(acceptance.sectors>0)return {};
    const auto restored=return_producer(acceptance.error);if(restored!=Status::completed)return {restored};
    return {acceptance.error?fail(Status::provider_failure):Status::completed};
}
Status SharedEncodedSource::set_loop_enabled(bool enabled)noexcept {
    Scope scope(*this);if(!scope)return Status::reentrant_call;
    if(state_.shutting_down||state_.joined)return Status::closed;loop_->state.enabled=enabled;return Status::completed;
}
Status SharedEncodedSource::set_paused(std::uint8_t paused)noexcept {
    Scope scope(*this);if(!scope)return Status::reentrant_call;
    if(state_.shutting_down||state_.joined)return Status::closed;state_.paused=paused;return Status::completed;
}
Status SharedEncodedSource::request_stop()noexcept {
    Scope scope(*this);if(!scope)return Status::reentrant_call;
    if(state_.joined)return Status::closed;
    if(state_.state==2&&state_.in_flight){state_.stop_requested=true;state_.service_requested=false;}else state_.state=1;
    return Status::completed;
}
Status SharedEncodedSource::request_close()noexcept {
    const auto status=request_stop();if(status!=Status::completed)return status;state_.close_requested=state_.source_open;return Status::completed;
}
Status SharedEncodedSource::begin_shutdown()noexcept {
    const auto status=request_stop();if(status!=Status::completed)return status;state_.shutting_down=true;return Status::completed;
}
bool SharedEncodedSource::finalize_shutdown_and_join()noexcept {
    if(state_.joined)return true;
    Scope scope(*this);if(!scope||!state_.shutting_down||state_.in_flight||producer_.bytes()||leases_->active||state_.ledger_fault)return false;
    if(!backend_->shutdown_and_join())return false;
    state_.joined=true;state_.source_open=false;view_.reset();leases_->alive=false;loop_->state.alive=false;return true;
}
} // namespace reo::native::adxt_shared_source
