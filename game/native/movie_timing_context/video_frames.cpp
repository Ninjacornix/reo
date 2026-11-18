#include "video_frames.hpp"
#include <bit>
#include <limits>
#include <stdexcept>
namespace reo::native::movie_timing_context {
namespace {
struct Busy {bool& flag;explicit Busy(bool& value):flag(value){flag=true;}~Busy(){flag=false;}};
bool earlier(const Picture& candidate,const Picture& current)noexcept{return std::bit_cast<std::int32_t>(candidate.time.numerator)<std::bit_cast<std::int32_t>(current.time.numerator);}
}
PicturePool::PicturePool(std::span<const Picture> input){
    if(input.size()>pictures_.size())throw std::invalid_argument("At most 16 picture records");
    count_=static_cast<std::uint32_t>(input.size());for(unsigned i=0;i<count_;++i)pictures_[i]=input[i];
}
PicturePool::PicturePool(std::uint32_t count):count_(count){if(count>pictures_.size())throw std::invalid_argument("At most 16 picture records");}
int PicturePool::reserve()noexcept {
    for(unsigned i=0;i<count_;++i)if(pictures_[i].state==0 && pictures_[i].references==0){pictures_[i].state=1;return static_cast<int>(i);}
    return -1;
}
PictureSelection PicturePool::select(std::uint32_t end)const noexcept {
    PictureSelection value;
    for(unsigned i=0;i<count_;++i){const auto& picture=pictures_[i];if(picture.state!=2 && picture.state!=4)continue;
        ++value.count;
        if(value.first<0 || earlier(picture,pictures_[value.first])){value.second=value.first;value.first=static_cast<int>(i);}
        else if(value.second<0 || earlier(picture,pictures_[value.second]))value.second=static_cast<int>(i);
    }
    value.last=value.count==1 && end!=0;return value;
}
Result PicturePool::can_advance(Context& clock)const noexcept {
    Result result;result.status=Status::completed;result.return_defined=true;
    const auto selection=select(0);const auto facts=clock.snapshot().facts;
    if(facts.actual!=4 || selection.count<2)return result;
    if(!facts.selector){result.returned=1;return result;}
    Input input;input.query=pictures_[selection.second].time;return clock.execute(Operation::admit,input);
}
void PicturePool::release(std::uint32_t slot)noexcept{if(slot<count_)pictures_[slot].state=pictures_[slot].state==4?3:0;}
void PicturePool::demote(std::uint32_t slot)noexcept{if(slot<count_)pictures_[slot].state=pictures_[slot].state==4?2:0;}
struct FrameIdentity {};
class VideoFrames::Guard {
    Context& clock_;
public:
    explicit Guard(Context& clock):clock_(clock){if(clock_.hooks_){clock_.hooks_->enter(0x11223344);if(!clock_.guard_->depth)clock_.guard_->tag=1;++clock_.guard_->depth;}}
    ~Guard(){if(clock_.hooks_){--clock_.guard_->depth;if(!clock_.guard_->depth)clock_.guard_->tag=0;clock_.hooks_->leave(0x55667788);}}
};
VideoFrames::VideoFrames(std::shared_ptr<Context> clock,std::uint32_t count):clock_(std::move(clock)),identity_(std::make_shared<FrameIdentity>()),pool_(count){}
std::shared_ptr<VideoFrames> VideoFrames::create(std::shared_ptr<Context> clock,std::uint32_t count){
    if(!clock || count==0 || count>16 || clock->busy_ || clock->detached_ || !clock->video_.expired())throw std::invalid_argument("One live serialized video pool per timing context");
    auto result=std::shared_ptr<VideoFrames>(new VideoFrames(clock,count));clock->video_=result;return result;
}
VideoFrames::~VideoFrames(){for(auto& resource:resources_)if(resource.surface)resource.surface->drain();}
bool VideoFrames::open()const noexcept{return !closing_ && !closed_ && !clock_->detached_;}
FrameKey VideoFrames::key(std::uint32_t slot)const noexcept{FrameKey result;result.owner_=identity_;result.slot_=slot;result.serial_=resources_[slot].serial;return result;}
bool VideoFrames::valid(const FrameKey& value)const noexcept{return value.owner_.lock()==identity_ && value.slot_<pool_.count_ && value.serial_ && resources_[value.slot_].serial==value.serial_;}
FrameResult VideoFrames::reserve()noexcept {
    const auto retained=weak_from_this().lock();if(!retained)return{};if(busy_ || clock_->busy_)return{FrameStatus::busy};if(!open())return{FrameStatus::closed};Busy busy(busy_);Guard guard(*clock_);
    if(next_serial_==std::numeric_limits<std::uint64_t>::max())return{FrameStatus::invalid_input};
    for(unsigned i=0;i<pool_.count_;++i){auto& picture=pool_.pictures_[i];auto& resource=resources_[i];
        if(picture.state || picture.references || resource.surface)continue;
        picture.state=1;resource.serial=++next_serial_;return{FrameStatus::completed,key(i)};
    }
    return{FrameStatus::pending};
}
FrameStatus VideoFrames::publish(const FrameKey& value,Words time,std::shared_ptr<FrameSurface> surface,bool reference)noexcept {
    const auto retained=weak_from_this().lock();if(!retained)return FrameStatus::invalid_input;if(busy_ || clock_->busy_)return FrameStatus::busy;if(!open())return FrameStatus::closed;
    if(!valid(value))return FrameStatus::invalid_key;
    auto& resource=resources_[value.slot_];auto& picture=pool_.pictures_[value.slot_];
    if(!surface || resource.surface || picture.state!=1)return FrameStatus::invalid_input;
    for(const auto& existing:resources_)if(existing.surface==surface)return FrameStatus::invalid_input;
    Busy busy(busy_);resource.surface=std::move(surface);resource.reference=reference;resource.pending=true;picture.time=time;
    const auto ready=resource.surface->ready();if(ready==FrameStatus::completed){picture.state=reference?4:2;resource.pending=false;return FrameStatus::completed;}
    return ready==FrameStatus::pending?ready:FrameStatus::provider_failure;
}
FrameStatus VideoFrames::published_ready(const FrameKey& value)const noexcept {
    const auto retained=weak_from_this().lock();if(!retained)return FrameStatus::invalid_input;
    if(busy_ || clock_->busy_)return FrameStatus::busy;
    if(!open())return FrameStatus::closed;
    if(!valid(value))return FrameStatus::invalid_key;
    const auto& resource=resources_[value.slot_];if(!resource.surface)return FrameStatus::invalid_input;
    return resource.pending?FrameStatus::pending:FrameStatus::completed;
}
FrameResult VideoFrames::advance()noexcept {
    Guard guard(*clock_);const auto selection=pool_.select(end_);const auto value=pool_.can_advance(*clock_);
    if(value.status!=Status::completed)return{FrameStatus::clock_failure};
    return{FrameStatus::completed,{},value.returned!=0,selection.last};
}
FrameResult VideoFrames::can_advance()noexcept {
    const auto retained=weak_from_this().lock();if(!retained)return{};if(busy_ || clock_->busy_)return{FrameStatus::busy};if(!open())return{FrameStatus::closed};Busy busy(busy_);return advance();
}
FrameResult VideoFrames::get(bool admission)noexcept {
    const auto facts=clock_->snapshot().facts;if(facts.actual!=3 && facts.actual!=4)return{FrameStatus::empty};
    PictureSelection selection;{Guard guard(*clock_);selection=pool_.select(end_);}
    if(end_==1 && selection.count==0)return{FrameStatus::empty};
    {Guard guard(*clock_);selection=pool_.select(end_);}
    if(selection.first<0)return{FrameStatus::empty};
    if(current_>=0 && current_!=selection.first && resources_[current_].borrowed)return{FrameStatus::busy};
    const auto slot=static_cast<std::uint32_t>(selection.first);auto& resource=resources_[slot];
    if(!resource.surface || resource.pending)return{FrameStatus::provider_failure};
    current_=selection.first;resource.borrowed=true;
    // Original public get publishes this pair before the later output-admission
    // decision, even if the frame is then held. No cache/reset is invented.
    clock_->initial_.previous=pool_.pictures_[slot].time;
    if(admission){Input input;input.query=pool_.pictures_[slot].time;const auto value=clock_->execute(Operation::admit,input);
        if(value.status!=Status::completed)return{FrameStatus::clock_failure};
        if(!value.returned)return{FrameStatus::held,{},false,selection.last};}
    return{FrameStatus::completed,key(slot),true,selection.last};
}
FrameResult VideoFrames::acquire()noexcept {
    const auto retained=weak_from_this().lock();if(!retained)return{};if(busy_ || clock_->busy_)return{FrameStatus::busy};if(!open())return{FrameStatus::closed};Busy busy(busy_);return get(true);
}
FrameResult VideoFrames::peek()noexcept {
    const auto retained=weak_from_this().lock();if(!retained)return{};if(busy_ || clock_->busy_)return{FrameStatus::busy};if(!open())return{FrameStatus::closed};Busy busy(busy_);Guard guard(*clock_);
    const auto value=pool_.select(end_);if(value.first<0)return{FrameStatus::empty};
    return{FrameStatus::completed,key(static_cast<unsigned>(value.first)),true,value.last};
}
FrameStatus VideoFrames::unborrow(const FrameKey& value)noexcept {
    if(!valid(value))return FrameStatus::invalid_key;
    auto& resource=resources_[value.slot_];if(!resource.borrowed || current_!=static_cast<int>(value.slot_))return FrameStatus::invalid_input;
    Guard guard(*clock_);resource.borrowed=false;pool_.release(value.slot_);return FrameStatus::completed;
}
FrameStatus VideoFrames::release(const FrameKey& value)noexcept {
    const auto retained=weak_from_this().lock();if(!retained)return FrameStatus::invalid_input;if(busy_ || clock_->busy_)return FrameStatus::busy;Busy busy(busy_);return unborrow(value);
}
FrameResult VideoFrames::skip_if_due()noexcept {
    const auto retained=weak_from_this().lock();if(!retained)return{};if(busy_ || clock_->busy_)return{FrameStatus::busy};if(!open())return{FrameStatus::closed};Busy busy(busy_);
    const auto decision=advance();if(decision.status!=FrameStatus::completed || !decision.decision)return decision;
    const auto front=get(false);if(front.status!=FrameStatus::completed)return front;
    const auto released=unborrow(front.key);return{released,{},released==FrameStatus::completed,front.last};
}
FrameStatus VideoFrames::present(const FrameKey& value)noexcept {
    const auto retained=weak_from_this().lock();if(!retained)return FrameStatus::invalid_input;if(busy_ || clock_->busy_)return FrameStatus::busy;if(!open())return FrameStatus::closed;if(!valid(value))return FrameStatus::invalid_key;
    const auto& resource=resources_[value.slot_];if(!resource.borrowed || current_!=static_cast<int>(value.slot_) || !resource.surface)return FrameStatus::invalid_input;
    Busy busy(busy_);const auto result=resource.surface->submit();return result==FrameStatus::completed || result==FrameStatus::pending?result:FrameStatus::provider_failure;
}
FrameStatus VideoFrames::retain_reference(const FrameKey& value)noexcept {
    if(busy_ || clock_->busy_)return FrameStatus::busy;
    if(!open())return FrameStatus::closed;
    if(!valid(value))return FrameStatus::invalid_key;
    ++pool_.pictures_[value.slot_].references;++references_;return FrameStatus::completed;
}
FrameStatus VideoFrames::release_reference(const FrameKey& value)noexcept {
    if(busy_ || clock_->busy_)return FrameStatus::busy;
    if(!valid(value))return FrameStatus::invalid_key;
    auto& refs=pool_.pictures_[value.slot_].references;const auto next=refs-1;refs=std::bit_cast<std::int32_t>(next)<0?0:next;--references_;return FrameStatus::completed;
}
FrameStatus VideoFrames::demote(const FrameKey& value)noexcept{if(busy_ || clock_->busy_)return FrameStatus::busy;if(!valid(value))return FrameStatus::invalid_key;pool_.demote(value.slot_);return FrameStatus::completed;}
FrameStatus VideoFrames::abandon(const FrameKey& value)noexcept{if(busy_ || clock_->busy_)return FrameStatus::busy;if(!valid(value))return FrameStatus::invalid_key;if(pool_.pictures_[value.slot_].state!=1)return FrameStatus::invalid_input;resources_[value.slot_].pending=false;pool_.pictures_[value.slot_].state=0;return FrameStatus::completed;}
FrameStatus VideoFrames::end(std::uint32_t value)noexcept{if(busy_ || clock_->busy_)return FrameStatus::busy;if(!open())return FrameStatus::closed;end_=value;return FrameStatus::completed;}
FrameStatus VideoFrames::collect()noexcept {
    bool pending=false,fault=false;
    for(unsigned i=0;i<pool_.count_;++i){auto& resource=resources_[i];auto& picture=pool_.pictures_[i];if(!resource.surface)continue;
        if(!closing_ && resource.pending){const auto ready=resource.surface->ready();if(ready==FrameStatus::completed){picture.state=resource.reference?4:2;resource.pending=false;}else{pending|=ready==FrameStatus::pending;fault|=ready!=FrameStatus::pending;}}
        if(!closing_ && (picture.state || picture.references || resource.borrowed))continue;
        const auto status=resource.surface->retire();if(status==FrameStatus::completed){resource.surface.reset();resource.pending=false;resource.borrowed=false;resource.serial=0;}
        else{pending|=status==FrameStatus::pending;fault|=status!=FrameStatus::pending;}
    }
    if(fault)return FrameStatus::provider_failure;
    if(pending)return FrameStatus::pending;
    if(closing_)closed_=true;
    return FrameStatus::completed;
}
FrameStatus VideoFrames::poll()noexcept{const auto retained=weak_from_this().lock();if(!retained)return FrameStatus::invalid_input;if(busy_ || clock_->busy_)return FrameStatus::busy;Busy busy(busy_);return collect();}
FrameStatus VideoFrames::close()noexcept{const auto retained=weak_from_this().lock();if(!retained)return FrameStatus::invalid_input;if(busy_ || clock_->busy_)return FrameStatus::busy;Busy busy(busy_);closing_=true;return collect();}
FrameSnapshot VideoFrames::snapshot()const noexcept {
    FrameSnapshot value;value.pictures=pool_.pictures_;value.count=pool_.count_;value.references=references_;value.end=end_;value.current=current_;value.closing=closing_;value.closed=closed_;
    for(unsigned i=0;i<pool_.count_;++i){value.borrowed[i]=resources_[i].borrowed;value.resources+=bool(resources_[i].surface);}return value;
}
}
