// Inputs-only Source2 client transport. No expected snapshot/ring state loaded.
#include "shared_source.hpp"
#include <array>
#include <fstream>
#include <iostream>
#include <optional>
#include <stdexcept>
#include <string>
#include <vector>

namespace s=reo::native::adxt_shared_source;
namespace old=reo::native::adxt_refill;
namespace resources=reo::native::resources;
namespace reo::native::adx_window::v2 {
// This isolated client transports the authored typed WindowLink configuration,
// not a header/decoder implementation and not an expected-derived checkpoint.
class StreamWindowOwner {
public:static s::Status configure(s::WindowLink& link,s::HeaderGeometry h,std::int32_t n,std::int32_t t,s::FileTargetAction a){
    return link.configure(h,n,t,a,s::DecoderLimitAction::none);}
};
}
namespace {
void require(bool value,const char* text){if(!value)throw std::runtime_error(text);}
std::vector<std::uint8_t> unhex(const std::string& text){
    std::vector<std::uint8_t> out;if(text!="-")for(std::size_t i=0;i<text.size();i+=2)out.push_back(std::uint8_t(std::stoul(text.substr(i,2),nullptr,16)));return out;
}
std::string hex(std::span<const std::uint8_t> bytes){
    constexpr char digits[]="0123456789abcdef";std::string out;out.reserve(bytes.size()*2);
    for(auto b:bytes){out+=digits[b>>4];out+=digits[b&15];}return out;
}
class View final:public resources::ByteView {
public:explicit View(std::vector<std::uint8_t> bytes):bytes_(std::move(bytes)){}
    std::uint64_t size()const noexcept override{return bytes_.size();}
    resources::ReadResult read(std::uint64_t at,std::span<std::byte> output)const override{
        if(at>bytes_.size()||output.size()>bytes_.size()-at)return {resources::Status::invalid_range,0};
        for(std::size_t i=0;i<output.size();++i)output[i]=std::byte(bytes_[std::size_t(at)+i]);return {resources::Status::ok,output.size()};}
private:std::vector<std::uint8_t> bytes_;
};
class Script final:public s::Backend {
    struct Job {std::shared_ptr<const resources::ByteView> view;std::uint64_t offset,id;std::uint32_t sectors;std::vector<std::byte> bytes;bool written{};};
    std::vector<Job> jobs_;std::optional<std::size_t> pending_;
public:
    int status{},acceptance{-999};bool declined_error{},inline_write{};
    old::Acceptance submit(std::shared_ptr<const resources::ByteView> view,std::uint64_t offset,std::uint32_t count,std::uint64_t id)noexcept override{
        const int accepted=acceptance==-999?int(count):acceptance;
        if(accepted>0){jobs_.push_back({std::move(view),offset,id,std::uint32_t(accepted),{},false});pending_=jobs_.size()-1;if(inline_write)write_job(*pending_);}
        return {accepted,declined_error};
    }
    void write_job(std::size_t index){require(index<jobs_.size(),"Unknown authored job");auto& job=jobs_[index];require(!job.written,"Duplicate job write");
        job.bytes.resize(std::size_t(job.sectors)*2048);require(job.view->read(job.offset,job.bytes).status==resources::Status::ok,"Synthetic view read failed");job.written=true;}
    old::Completion poll()noexcept override{
        if(!pending_)return {};auto& job=jobs_[*pending_];
        if(status!=1&&status!=3)return {old::BackendState::pending,job.id,{}};
        pending_.reset();if(status==3){job.view.reset();return {old::BackendState::error,job.id,{}};}
        if(!job.written)return {old::BackendState::error,job.id,{}};
        job.view.reset();return {old::BackendState::complete,job.id,std::move(job.bytes)};
    }
    bool shutdown_and_join()noexcept override{return !pending_;}
};
struct RingEvent {bool enter;reo::native::sjrb::Snapshot ring;};
struct Observer {
    s::SharedEncodedSource* owner{};bool suppress{};std::size_t count{},target_count{};
    std::array<RingEvent,512> events{};std::array<s::TargetObservation,16> targets{};
    void record(bool entering)noexcept{if(suppress)return;if(!owner||count==events.size())std::terminate();events[count++]={entering,owner->snapshot().ring};}
    static void enter(void* p)noexcept{static_cast<Observer*>(p)->record(true);}
    static void leave(void* p)noexcept{static_cast<Observer*>(p)->record(false);}
    static void error(void*,std::int32_t)noexcept{std::terminate();}
    static void target(void* p,const s::TargetObservation& value)noexcept{auto& o=*static_cast<Observer*>(p);if(o.target_count==o.targets.size())std::terminate();o.targets[o.target_count++]=value;}
};
void ring(const reo::native::sjrb::Snapshot& q){
    std::cout<<'['<<q.capacity<<','<<q.extension<<','<<q.data<<','<<q.free<<','<<q.write<<','<<q.read;
    for(auto n:q.totals)std::cout<<','<<n;std::cout<<']';
}
void snapshot(const s::Snapshot& x){
    std::cout<<"{\"ring\":";ring(x.ring);
    std::cout<<",\"source\":["<<x.state<<','<<x.accepted_sectors<<','<<x.progress_sectors<<','<<x.cumulative_bytes<<','<<x.retries<<','<<unsigned(x.paused)<<','
        <<x.in_flight<<','<<x.service_requested<<','<<x.stop_requested<<','<<x.close_requested<<','<<x.source_open<<','<<x.producer.offset<<','<<x.producer.bytes<<"],\"loop\":["
        <<x.loop.sample_limit<<','<<x.loop.target_sectors<<','<<x.loop.enabled<<','<<x.loop.header.loop_start_bytes<<','<<x.loop.header.loop_end_bytes<<','
        <<x.loop.header.loop_start_samples<<','<<x.loop.header.loop_end_samples<<"]}";
}
void view(const s::ReadBatch& batch,unsigned index){
    std::vector<std::uint8_t> data(std::size_t(batch.bytes(index)));require(batch.read_into(index,data)==s::Status::completed,"Owned batch read refused");
    std::cout<<"{\"offset\":"<<batch.offset(index)<<",\"bytes\":"<<batch.bytes(index)<<",\"hex\":\""<<hex(data)<<"\"}";
}
void emit(s::SharedEncodedSource& source,Observer& observer,std::optional<s::ReadBatch>& batch,int index,s::Status status){
    const auto state=source.snapshot();std::cout<<"{\"index\":"<<index<<",\"status\":"<<int(status)<<",\"state\":";snapshot(state);
    std::cout<<",\"ring_events\":[";for(std::size_t i=0;i<observer.count;++i){if(i)std::cout<<',';std::cout<<"{\"enter\":"<<(observer.events[i].enter?"true":"false")<<",\"ring\":";ring(observer.events[i].ring);std::cout<<'}';}
    std::cout<<"],\"targets\":[";for(std::size_t i=0;i<observer.target_count;++i){if(i)std::cout<<',';std::cout<<"{\"before\":";snapshot(observer.targets[i].before);std::cout<<",\"after\":";snapshot(observer.targets[i].after);std::cout<<'}';}
    std::cout<<"],\"views\":[";
    if(batch){for(unsigned i=0;i<batch->count();++i){if(i)std::cout<<',';view(*batch,i);}}
    else{observer.suppress=true;auto peek=source.borrow_batch({s::BatchShape::one,source.snapshot().ring.capacity,0});require(peek.status==s::Status::completed,"Observation borrow refused");
        view(peek.batch,0);require(source.finish_batch(peek.batch,{s::FinishKind::restore_reverse,0})==s::Status::completed,"Observation credit restore refused");observer.suppress=false;}
    std::cout<<"],\"ownership\":["<<state.producer_remaining.bytes<<','<<state.consumers[0].bytes<<','<<state.consumers[1].bytes<<"]}\n";
    observer.count=observer.target_count=0;
}
}
int main(int argc,char** argv){try{
    require(argc==2,"Input transcript required");std::ifstream input(argv[1]);require(bool(input),"Cannot open transcript");
    s::Config c;int position,occupied,callback,progress,file_action,enabled,limit;s::HeaderGeometry h;std::string bytes;
    input>>c.capacity>>c.start_sector>>c.byte_length>>c.threshold>>c.maximum_request_bytes>>c.maximum_sectors>>c.target_sectors>>c.finite_sector_limit>>c.retry_limit
        >>position>>occupied>>callback>>progress>>file_action>>enabled>>limit>>h.loop_start_bytes>>h.loop_end_bytes>>h.loop_start_samples>>h.loop_end_samples>>bytes;
    require(bool(input),"Malformed constructor input");auto retained=std::make_shared<View>(unhex(bytes));auto backend=std::make_unique<Script>();auto* script=backend.get();
    Observer observer;std::vector<std::uint8_t> seed(static_cast<std::size_t>(occupied));for(std::size_t i=0;i<seed.size();++i)seed[i]=std::uint8_t(0xd0+i);
    std::unique_ptr<s::SharedEncodedSource> source;
    try{source=std::make_unique<s::SharedEncodedSource>(c,retained,std::move(backend),s::InitialLoop{h,limit,s::FileTargetAction(file_action),s::DecoderLimitAction::none,enabled!=0},
        s::PreparedPrefix{position,progress,seed},s::Hooks{&observer,callback?Observer::target:nullptr,{&observer,Observer::enter,Observer::leave,Observer::error}});}
    catch(const std::invalid_argument&){std::cout<<"{\"constructor_refused\":true}\n";return 0;}
    observer.owner=source.get();auto link=source->take_window_link();require(link.status==s::Status::completed,"WindowLink mint refused");
    std::optional<s::ReadBatch> batch;emit(*source,observer,batch,-1,s::Status::completed);
    int index;std::string kind;
    while(input>>index>>kind){s::Status status=s::Status::completed;
        if(kind=="source"){int error,inline_write;input>>script->status>>script->acceptance>>error>>inline_write;script->declined_error=error!=0;script->inline_write=inline_write!=0;status=source->service().status;}
        else if(kind=="borrow"){int shape,first,second;input>>shape>>first>>second;require(!batch,"Nested batch in authored client");
            auto result=source->borrow_batch({shape==1?s::BatchShape::one:s::BatchShape::two,first,second});status=result.status;require(status==s::Status::completed,"Authored borrow refused");batch.emplace(std::move(result.batch));}
        else if(kind=="finish"){std::string plan,prefix;input>>plan>>prefix;require(bool(batch),"Missing authored batch");
            s::FinishKind p=plan=="single"?s::FinishKind::consume_single_prefix:plan=="reverse"?s::FinishKind::restore_reverse:plan=="first"?s::FinishKind::consume_first_prefix_restore_second:s::FinishKind::consume_second_prefix_consume_first;
            const auto n=prefix=="all"?batch->bytes(plan=="second"?1:0):std::stoi(prefix);status=source->finish_batch(*batch,{p,n});require(status==s::Status::completed,"Authored finish refused");batch.reset();}
        else if(kind=="write_job"){std::size_t id;input>>id;script->write_job(id);}
        else if(kind=="loop_enable"){int n;input>>n;status=source->set_loop_enabled(n!=0);}
        else if(kind=="configure"){int n,t,a;input>>h.loop_start_bytes>>h.loop_end_bytes>>h.loop_start_samples>>h.loop_end_samples>>n>>t>>a;
            status=reo::native::adx_window::v2::StreamWindowOwner::configure(link.link,h,n,t,s::FileTargetAction(a));}
        else if(kind=="pause"){int n;input>>n;status=source->set_paused(std::uint8_t(n));}
        else if(kind=="stop")status=source->request_stop();else if(kind=="close")status=source->request_close();
        else throw std::runtime_error("Unknown authored client command");
        require(bool(input),"Malformed action");emit(*source,observer,batch,index,status);
    }
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}}
