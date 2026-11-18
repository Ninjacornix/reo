#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
#include <span>
#include <utility>
#include <vector>

namespace reo::native::gameplay_scenario {
// Authored-owner snapshots used by 7020E0/702380, separate from the live linked
// scene-control owner. Only fields consumed by these commands are projected.
struct SavedControl {
    std::uint8_t enabled{},type{},authored_id{},selector{};
};
class SavedControlRecords final {
public:
    static constexpr std::size_t owner_count=3;
    // Explicit bounded native profile, not a claim about the stock allocator.
    explicit SavedControlRecords(std::size_t maximum_per_owner=1024):maximum_(maximum_per_owner){}
    bool restore(std::size_t owner,std::span<const SavedControl> records){
        if(owner>=owner_count||records.size()>maximum_)return false;
        std::vector<SavedControl> copy(records.begin(),records.end());
        records_[owner]=std::move(copy);return true;
    }
    std::span<const SavedControl> get(std::size_t owner)const noexcept{
        return owner<owner_count?std::span<const SavedControl>(records_[owner]):std::span<const SavedControl>{};
    }
    bool apply(std::size_t owner,bool enable,std::uint32_t type,std::uint32_t authored_id,std::uint32_t selector)noexcept{
        if(owner>=owner_count)return false;
        for(auto& record:records_[owner]){
            if(record.type!=type||record.authored_id!=authored_id)continue;
            if(type==2&&record.selector!=selector)continue;
            if(type==3&&(record.selector&1u)!=selector)continue;
            record.enabled=enable?1:0;
        }
        return true;
    }
private:
    std::array<std::vector<SavedControl>,owner_count> records_;
    std::size_t maximum_;
};
} // namespace reo::native::gameplay_scenario
