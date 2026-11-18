#pragma once
#include <cstdint>

namespace reo::native::gameplay_scenario {
// Canonical scene render-program channel admission mask. The channel program
// evaluator and modern renderer consumer are separate, explicit dependencies.
class SceneChannels final {
public:
    std::uint32_t mask()const noexcept{return mask_;}
    void restore(std::uint32_t value)noexcept{mask_=value;}
    void bit(std::uint32_t index,bool enabled)noexcept{
        const auto bit=std::uint32_t(1)<<(index&31u);mask_=enabled?mask_|bit:mask_&~bit;
    }
    void all(bool enabled)noexcept{mask_=enabled?UINT32_MAX:0;}
    bool enabled(std::uint32_t channel)const noexcept{return (mask_&(std::uint32_t(1)<<(channel&31u)))!=0;}
private:
    std::uint32_t mask_{};
};
} // namespace reo::native::gameplay_scenario
