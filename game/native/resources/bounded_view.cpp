#include "bounded_view.hpp"

#include <new>
#include <algorithm>
#include <atomic>
#include <condition_variable>
#include <cstring>
#include <map>
#include <mutex>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace reo::native::resources {
namespace {
class BoundedView final : public ByteView {
public:
    BoundedView(std::shared_ptr<const ByteView> parent, std::uint64_t base,
                std::uint64_t bytes) noexcept : parent_(std::move(parent)), base_(base), bytes_(bytes) {}

    std::uint64_t size() const noexcept override { return bytes_; }
    const std::shared_ptr<const ByteView>& parent() const noexcept { return parent_; }

    ReadResult read(std::uint64_t offset, std::span<std::byte> destination) const override {
        if (offset > bytes_ || destination.size() > bytes_ - offset)
            return {Status::invalid_range, 0};
        if (destination.empty()) return {Status::ok, 0};
        // Mount admission proves base_ + bytes_ <= parent size, without wrap.
        return parent_->read(base_ + offset, destination);
    }
private:
    std::shared_ptr<const ByteView> parent_;
    const std::uint64_t base_, bytes_;
};

// Explicit finite-asset admission, independent of source I/O and render queues.
// Reservation precedes loading; a lazy view counts against the live budget too.
constexpr std::uint64_t resident_view_limit=32ull*1024*1024;
constexpr std::uint64_t resident_live_limit=2ull*1024*1024*1024;
class ResidentView;
struct ResidentEntry {
    std::condition_variable constructed;
    std::weak_ptr<const ResidentView> view;
    bool constructing{true};
};
struct ResidentBudget {
    std::mutex mutex;
    std::uint64_t charged{};
    std::map<std::pair<std::string,std::uint64_t>,std::shared_ptr<ResidentEntry>> entries;
};
std::shared_ptr<ResidentBudget> resident_budget(){
    static const auto value=std::make_shared<ResidentBudget>();
    return value;
}
class ResidentView final:public ByteView {
public:
    ResidentView(std::shared_ptr<const ByteView> source,std::shared_ptr<ResidentBudget> budget,std::uint64_t bytes)
        :source_(std::move(source)),budget_(std::move(budget)),bytes_(bytes){}
    ~ResidentView()override{
        // Provider destruction and backing allocation release occur before the
        // registry lock. A provider destructor may itself request another view.
        std::vector<std::byte>().swap(bytes_data_);
        source_.reset();
        std::lock_guard lock(budget_->mutex);
        budget_->charged-=bytes_;
    }
    std::uint64_t size()const noexcept override{return bytes_;}
    bool ready()const noexcept{return ready_.load(std::memory_order_acquire);}
    ReadResult read(std::uint64_t offset,std::span<std::byte> destination)const override{
        if(offset>bytes_ || destination.size()>bytes_-offset)return{Status::invalid_range,0};
        if(destination.empty())return{Status::ok,0};
        if(!ready()){
            const auto loaded=materialize();
            if(loaded==Status::no_memory)throw std::bad_alloc();
            if(loaded!=Status::ok)return{loaded,0};
        }
        std::memcpy(destination.data(),bytes_data_.data()+static_cast<std::size_t>(offset),destination.size());
        return{Status::ok,destination.size()};
    }
private:
    Status materialize()const{
        std::shared_ptr<const ByteView> released;
        Status result{Status::ok};
        {
            std::lock_guard lock(load_);
            if(ready())return Status::ok;
            if(attempted_)return failed_;
            attempted_=true;
            try{
                std::vector<std::byte> staged(static_cast<std::size_t>(bytes_));
                const auto read=source_->read(0,staged);
                if(read.status==Status::ok && read.bytes==staged.size()){
                    bytes_data_=std::move(staged);
                    ready_.store(true,std::memory_order_release);
                }else failed_=read.status==Status::ok?Status::source_failure:read.status;
            }catch(const std::bad_alloc&){failed_=Status::no_memory;}
            catch(...){failed_=Status::source_failure;}
            result=ready()?Status::ok:failed_;
            released=std::move(source_);
        }
        released.reset(); // No provider destructor under load/registry locks.
        return result;
    }
    mutable std::shared_ptr<const ByteView> source_;
    const std::shared_ptr<ResidentBudget> budget_;
    const std::uint64_t bytes_;
    mutable std::mutex load_;
    mutable std::vector<std::byte> bytes_data_;
    mutable std::atomic<bool> ready_{};
    mutable bool attempted_{};
    mutable Status failed_{Status::source_failure};
};
const ResidentView* resident_parent(const ByteView* view)noexcept{
    // Inspect only our concrete wrappers. Never invoke custom size/read hooks.
    while(const auto* bounded=dynamic_cast<const BoundedView*>(view))view=bounded->parent().get();
    return dynamic_cast<const ResidentView*>(view);
}
void prune_resident_entries(const std::shared_ptr<ResidentBudget>& budget){
    for(;;){
        decltype(budget->entries)::node_type retired;
        {
            std::lock_guard lock(budget->mutex);
            auto found=budget->entries.end();
            for(auto it=budget->entries.begin();it!=budget->entries.end();++it)
                if(!it->second->constructing && it->second->view.expired()){found=it;break;}
            if(found==budget->entries.end())return;
            retired=budget->entries.extract(found);
        }
        // Weak control-block and entry destructors stay outside registry lock.
    }
}
} // namespace

// CPP-only integration entry points; admitted native callers forward-declare
// these without expanding the existing runtime's global header fingerprint.
std::shared_ptr<const ByteView> retain_resident_view(std::shared_ptr<const ByteView> source,std::string identity){
    if(!source)throw std::invalid_argument("Resident asset requires an immutable view");
    if(resident_parent(source.get()))return source; // Preserve an existing slice.
    if(identity.empty() || identity.size()>1024 ||
       std::any_of(identity.begin(),identity.end(),[](unsigned char value){return value<32 || value>126;}))
        throw std::invalid_argument("Validated native asset identity required");
    const auto bytes=source->size();
    if(!bytes || bytes>resident_view_limit)throw std::length_error("Resident asset exceeds 32 MiB per-view admission");
    const auto budget=resident_budget();
    const auto key=std::make_pair(std::move(identity),bytes);
    auto candidate=std::make_shared<ResidentEntry>();
    std::shared_ptr<ResidentEntry> entry;
    for(;;){
        entry.reset(); // Release an earlier cache entry outside registry lock.
        prune_resident_entries(budget);
        std::unique_lock lock(budget->mutex);
        const auto found=budget->entries.find(key);
        if(found!=budget->entries.end()){
            entry=found->second;
            if(entry->constructing){
                entry->constructed.wait(lock,[&]{return !entry->constructing;});
                continue;
            }
            if(auto existing=entry->view.lock())return existing;
            continue; // Expired entry is removed outside lock on the next pass.
        }
        if(bytes>resident_live_limit-budget->charged)throw std::length_error("Resident assets exceed 2 GiB live reservation budget");
        budget->entries.emplace(key,candidate);
        budget->charged+=bytes;
        entry=candidate;
        break;
    }
    std::shared_ptr<const ResidentView> result;
    // Keep the caller's provider reference alive through any constructor
    // failure until reservation rollback/notification have completed.
    try{result=std::make_shared<const ResidentView>(source,budget,bytes);}
    catch(...){
        {
            std::lock_guard lock(budget->mutex);
            budget->charged-=bytes;entry->constructing=false;
        }
        entry->constructed.notify_all();throw;
    }
    {
        std::lock_guard lock(budget->mutex);
        entry->view=result;entry->constructing=false;
    }
    entry->constructed.notify_all();
    return result;
}
bool is_resident_view(const std::shared_ptr<const ByteView>& view)noexcept{
    const auto* resident=resident_parent(view.get());
    return resident && resident->ready();
}

ViewResult bounded_view(std::shared_ptr<const ByteView> parent, std::uint64_t base,
                        std::uint64_t bytes) noexcept {
    if (!parent) return {Status::invalid_view, {}};
    const auto size = parent->size();
    if (base > size || bytes > size - base) return {Status::invalid_range, {}};
    try {
        return {Status::ok, std::make_shared<const BoundedView>(std::move(parent), base, bytes)};
    } catch (const std::bad_alloc&) {
        return {Status::no_memory, {}};
    }
}

} // namespace reo::native::resources
