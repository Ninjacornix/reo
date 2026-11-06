// Authored input transport only. No expected outputs or raw ring backing API.
#include "adxt_refill.hpp"
#include <array>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

namespace r=reo::native::adxt_refill;
namespace resources=reo::native::resources;
namespace {
void require(bool condition,const char* message) { if(!condition) throw std::runtime_error(message); }
std::vector<std::uint8_t> unhex(const std::string& text) {
    std::vector<std::uint8_t> out;
    if(text!="-") for(std::size_t i=0;i<text.size();i+=2) out.push_back(static_cast<std::uint8_t>(std::stoul(text.substr(i,2),nullptr,16)));
    return out;
}
std::string hex(std::span<const std::uint8_t> data) {
    static constexpr char digits[]="0123456789abcdef";std::string result;result.reserve(data.size()*2);
    for(auto byte:data) { result+=digits[byte>>4];result+=digits[byte&15]; } return result;
}
class View final : public resources::ByteView {
public:
    explicit View(std::vector<std::uint8_t> bytes):bytes_(std::move(bytes)) {}
    std::uint64_t size() const noexcept override { return bytes_.size(); }
    resources::ReadResult read(std::uint64_t offset,std::span<std::byte> output) const override {
        if(offset>bytes_.size() || output.size()>bytes_.size()-offset) return {resources::Status::invalid_range,0};
        for(std::size_t i=0;i<output.size();++i) output[i]=std::byte(bytes_[static_cast<std::size_t>(offset)+i]);
        return {resources::Status::ok,output.size()};
    }
private:
    std::vector<std::uint8_t> bytes_;
};
class Script final : public r::Backend {
public:
    int status{},acceptance{-999},error{},submissions{};
    r::Acceptance submit(std::shared_ptr<const resources::ByteView> view,std::uint64_t offset,
                        std::uint32_t sectors,std::uint64_t id) noexcept override {
        ++submissions;accepted_=acceptance==-999?static_cast<int>(sectors):acceptance;
        view_=std::move(view);offset_=offset;id_=id;pending_=accepted_>0;
        return {accepted_,error!=0};
    }
    r::Completion poll() noexcept override {
        if(!pending_) return {};
        if(status!=1 && status!=3) return {r::BackendState::pending,id_,{}};
        pending_=false;
        if(status==3) return {r::BackendState::error,id_,{}};
        std::vector<std::byte> result(static_cast<std::size_t>(accepted_)*2048);
        const auto read=view_->read(offset_,result);
        if(read.status!=resources::Status::ok) return {r::BackendState::error,id_,{}};
        view_.reset();
        return {r::BackendState::complete,id_,std::move(result)};
    }
    bool shutdown_and_join() noexcept override { return !pending_; }
private:
    std::shared_ptr<const resources::ByteView> view_;
    std::uint64_t offset_{},id_{};int accepted_{};bool pending_{};
};
void snapshot(const r::Snapshot& s) {
    const auto& q=s.ring;
    std::cout<<"{\"ring\":["<<q.capacity<<','<<q.extension<<','<<q.data<<','<<q.free<<','<<q.write<<','<<q.read;
    for(auto total:q.totals) std::cout<<','<<total;
    std::cout<<"],\"source\":["<<s.state<<','<<s.accepted_sectors<<','<<s.progress_sectors<<','<<s.cumulative_bytes<<','<<s.retries<<','
        <<static_cast<unsigned>(s.paused)<<','<<s.in_flight<<','<<s.service_requested<<','<<s.stop_requested<<','<<s.close_requested<<','
        <<s.source_open<<','<<s.producer_offset<<','<<s.producer_bytes<<"]}";
}
struct Observer {
    std::array<r::Snapshot,8> callbacks{};std::size_t count{};
    static void target(void* p,const r::Snapshot& s) noexcept {
        auto& self=*static_cast<Observer*>(p);if(self.count==self.callbacks.size()) std::terminate();self.callbacks[self.count++]=s;
    }
};
void emit(r::EncodedSource& owner,Observer& observer,int index,int sub,r::Status status,bool peek=true,
          const r::DataLease* current=nullptr) {
    std::cout<<"{\"index\":"<<index<<",\"sub\":"<<sub<<",\"status\":"<<static_cast<int>(status)<<",\"state\":";
    snapshot(owner.snapshot());std::cout<<",\"callbacks\":[";
    for(std::size_t i=0;i<observer.count;++i) { if(i) std::cout<<',';snapshot(observer.callbacks[i]); }std::cout<<']';
    if(peek || current) {
        auto output=[&](const r::DataLease& lease) {
            std::vector<std::uint8_t> bytes(static_cast<std::size_t>(lease.bytes()));
            require(lease.read_into(bytes)==r::Status::completed,"Public data-lease observation failed");
            std::cout<<",\"view\":{\"offset\":"<<lease.offset()<<",\"bytes\":"<<lease.bytes()<<",\"hex\":\""<<hex(bytes)<<"\"}";
        };
        if(current) output(*current);
        else {
            auto borrowed=owner.borrow_data(owner.snapshot().ring.capacity);
            require(borrowed.status==r::Status::completed,"Public view borrow failed");output(borrowed.lease);
            require(owner.finish_data(borrowed.lease,0)==r::Status::completed,"Public view credit return failed");
        }
    }
    std::cout<<"}\n";
}
} // namespace
int main(int argc,char** argv) {
    try {
        require(argc==2,"Expected input-only transcript");std::ifstream input(argv[1]);require(bool(input),"Cannot open input");
        r::Config config;int position,occupied,callback;std::string file;
        input>>config.capacity>>config.start_sector>>config.byte_length>>config.threshold>>config.maximum_request_bytes>>config.maximum_sectors
             >>config.target_sectors>>config.finite_sector_limit>>config.retry_limit>>position>>occupied>>callback>>file;
        auto view=std::make_shared<View>(unhex(file));auto backend=std::make_unique<Script>();auto* script=backend.get();Observer observer;
        std::vector<std::uint8_t> initial(static_cast<std::size_t>(occupied));
        for(std::size_t i=0;i<initial.size();++i) initial[i]=static_cast<std::uint8_t>(0xD0+i);
        std::unique_ptr<r::EncodedSource> owner;
        try { owner=std::make_unique<r::EncodedSource>(config,view,std::move(backend),
                r::Hooks{&observer,callback?Observer::target:nullptr,{}},r::InitialBuffer{position,initial}); }
        catch(const std::invalid_argument&) { std::cout<<"{\"constructor_refused\":true}\n";return 0; }
        emit(*owner,observer,-1,0,r::Status::completed);
        int index,status,acceptance,error,value;std::string action;
        while(input>>index>>action>>status>>acceptance>>error>>value) {
            observer.count=0;script->status=status;script->acceptance=acceptance;script->error=error;
            r::Status result=r::Status::completed;
            if(action=="lifecycle" || action=="refill") result=owner->service();
            else if(action=="pause") result=owner->set_paused(static_cast<std::uint8_t>(value));
            else if(action=="stop") result=owner->request_stop();
            else if(action=="close") result=owner->request_close();
            else if(action=="reset") {
                result=owner->reset_quiescent();emit(*owner,observer,index,0,result);
                if(result!=r::Status::completed) break;
                continue;
            } else if(action=="write_job") { /* Private-result timing, no unpublished ring mutation. */ }
            else if(action=="consume") {
                auto borrowed=owner->borrow_data(value);require(borrowed.status==r::Status::completed,"Consumer borrow refused");
                emit(*owner,observer,index,0,r::Status::completed,false,&borrowed.lease);
                result=owner->finish_data(borrowed.lease,borrowed.lease.bytes());emit(*owner,observer,index,1,result);continue;
            } else throw std::runtime_error("Unsupported authored action");
            emit(*owner,observer,index,0,result);
        }
    } catch(const std::exception& error) { std::cerr<<error.what()<<'\n';return 1; }
}
