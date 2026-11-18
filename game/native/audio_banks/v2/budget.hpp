#pragma once
#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <memory>
#include <mutex>
#include <new>
#include <stdexcept>
#include <type_traits>
#include <vector>

namespace reo::native::audio_banks::v2 {
// Producer/control allocation only. Custom sources must outlive every allocation
// via this strong owner and must implement the symmetric aligned free contract.
class AllocationSource {
public:
    virtual ~AllocationSource()=default;
    virtual void* allocate(std::size_t bytes,std::size_t alignment)=0;
    virtual void deallocate(void*,std::size_t bytes,std::size_t alignment) noexcept=0;
};
class HeapSource final:public AllocationSource {
public:
    void* allocate(std::size_t n,std::size_t alignment)override {
        if(alignment>__STDCPP_DEFAULT_NEW_ALIGNMENT__)return ::operator new(n,std::align_val_t(alignment));
        return ::operator new(n);
    }
    void deallocate(void* p,std::size_t,std::size_t alignment)noexcept override {
        if(alignment>__STDCPP_DEFAULT_NEW_ALIGNMENT__)::operator delete(p,std::align_val_t(alignment));else ::operator delete(p);
    }
};
struct BudgetSnapshot {
    std::size_t bytes{},peak_bytes{},assets{},peak_assets{},allocations{},refusals{};
    std::size_t byte_limit{},asset_limit{};
};
struct BudgetExceeded final:std::bad_alloc {};
class Budget;
struct AssetLease;
template<class T>class AssetAllocator;
class Budget final {
public:
    Budget(std::size_t bytes,std::size_t assets,std::shared_ptr<AllocationSource> source={})
        :source_(source?std::move(source):std::make_shared<HeapSource>()) {
        if(!bytes||!assets)throw std::invalid_argument("Positive bank asset budget required");
        counters_.byte_limit=bytes;counters_.asset_limit=assets;
    }
    BudgetSnapshot snapshot()const noexcept {std::lock_guard lock(mutex_);return counters_;}
private:
    template<class T>friend class AssetAllocator;
    friend struct AssetLease;
    friend std::shared_ptr<AssetLease> acquire_asset(const std::shared_ptr<Budget>&);
    void reserve_asset(){std::lock_guard lock(mutex_);if(counters_.assets==counters_.asset_limit){++counters_.refusals;throw BudgetExceeded();}++counters_.assets;counters_.peak_assets=std::max(counters_.peak_assets,counters_.assets);}
    void release_asset()noexcept {std::lock_guard lock(mutex_);--counters_.assets;}
    void* allocate(std::size_t bytes,std::size_t alignment) {
        {std::lock_guard lock(mutex_);if(bytes>counters_.byte_limit-counters_.bytes){++counters_.refusals;throw BudgetExceeded();}
            counters_.bytes+=bytes;counters_.peak_bytes=std::max(counters_.peak_bytes,counters_.bytes);}
        try {auto* p=source_->allocate(bytes,alignment);if(!p)throw std::bad_alloc();{std::lock_guard lock(mutex_);++counters_.allocations;}return p;}
        catch(...){std::lock_guard lock(mutex_);counters_.bytes-=bytes;throw std::bad_alloc();}
    }
    void deallocate(void* p,std::size_t bytes,std::size_t alignment)noexcept {
        // No budget lock is held while calling a user-owned allocation source.
        source_->deallocate(p,bytes,alignment);
        std::lock_guard lock(mutex_);counters_.bytes-=bytes;
    }
    mutable std::mutex mutex_;
    BudgetSnapshot counters_;
    std::shared_ptr<AllocationSource> source_;
};
struct AssetLease final {
    explicit AssetLease(std::shared_ptr<Budget> b)noexcept:budget(std::move(b)){}
    const std::shared_ptr<Budget> budget;
};
template<class T>class AssetAllocator {
public:
    using value_type=T;
    using propagate_on_container_move_assignment=std::true_type;
    using is_always_equal=std::false_type;
    AssetAllocator()=default;
    explicit AssetAllocator(std::shared_ptr<Budget> b):budget_(std::move(b)){}
    explicit AssetAllocator(std::shared_ptr<AssetLease> lease):budget_(lease?lease->budget:nullptr),lease_(std::move(lease)){}
    template<class U>AssetAllocator(const AssetAllocator<U>& other)noexcept:budget_(other.budget_),lease_(other.lease_),refund_asset_(other.refund_asset_){}
    T* allocate(std::size_t n) {
        if(!budget_||n>std::numeric_limits<std::size_t>::max()/sizeof(T))throw std::bad_alloc();
        return static_cast<T*>(budget_->allocate(n*sizeof(T),alignof(T)));
    }
    void deallocate(T* p,std::size_t n)noexcept {
        // allocate_shared can call deallocate after destroying its contained
        // object. The allocator itself retains BOTH resource and asset lease.
        auto keep=budget_;const bool refund=refund_asset_;
        keep->deallocate(p,n*sizeof(T),alignof(T));
        if(refund)keep->release_asset();
    }
    template<class U>bool operator==(const AssetAllocator<U>& other)const noexcept{return budget_==other.budget_&&lease_==other.lease_&&refund_asset_==other.refund_asset_;}
private:
    template<class U>friend class AssetAllocator;
    friend std::shared_ptr<AssetLease> acquire_asset(const std::shared_ptr<Budget>&);
    AssetAllocator(std::shared_ptr<Budget> budget,bool refund):budget_(std::move(budget)),refund_asset_(refund){}
    std::shared_ptr<Budget> budget_;
    std::shared_ptr<AssetLease> lease_;
    bool refund_asset_{};
};
inline std::shared_ptr<AssetLease> acquire_asset(const std::shared_ptr<Budget>& budget){
    budget->reserve_asset();
    // Only this control-block allocator refunds the count, after freeing the
    // final allocation. Its copies do not refund anything on destruction.
    try{return std::allocate_shared<AssetLease>(AssetAllocator<AssetLease>(budget,true),budget);}
    catch(...){budget->release_asset();throw;}
}
template<class T>using AssetVector=std::vector<T,AssetAllocator<T>>;
} // namespace reo::native::audio_banks::v2
