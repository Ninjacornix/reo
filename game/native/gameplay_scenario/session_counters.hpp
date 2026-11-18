#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
#include <optional>

namespace reo::native::gameplay_scenario {
// Explicit native profile: three authored owners, two counters each. Original
// unchecked larger indices can alias other state and are not admitted here.
class SessionCounters final {
public:
    using Snapshot=std::array<std::array<std::uint32_t,2>,3>;
    const Snapshot& snapshot()const noexcept{return values_;}
    void restore(const Snapshot& values)noexcept{values_=values;}
    bool store(std::size_t owner,std::uint32_t index,std::uint32_t value)noexcept{
        if(owner>=values_.size()||index>=2)return false;
        values_[owner][index]=value;return true;
    }
    std::optional<bool> consume(std::size_t owner,std::uint32_t index,bool wanted_nonzero)noexcept{
        if(owner>=values_.size()||index>=2)return{};
        auto& value=values_[owner][index];const bool nonzero=value!=0;
        if(nonzero)--value;
        return nonzero==wanted_nonzero;
    }
private:
    Snapshot values_{};
};
} // namespace reo::native::gameplay_scenario
