#pragma once
#include <array>
#include <cstdint>
#include <optional>

namespace reo::native::gameplay_scenario {
// Canonical scene-record condition bank (original4BAA30..4BAA50). Its
// consumers cover multiple descriptor families. The original unbounded bit
// arithmetic can alias following owners; native admission stops at256 bits.
class SceneRecordEligibility final {
public:
    static constexpr std::uint32_t capacity=256;
    using Words=std::array<std::uint32_t,8>;
    std::optional<bool> get(std::uint32_t id)const noexcept {
        if(id>=capacity)return{};
        return bool(words_[id/32]&(1u<<(id&31)));
    }
    bool write(std::uint32_t id,bool enabled)noexcept {
        if(id>=capacity)return false;
        auto& word=words_[id/32];const auto mask=1u<<(id&31);
        word=enabled?word|mask:word&~mask;return true;
    }
    const Words& snapshot()const noexcept{return words_;}
    void restore(const Words& words)noexcept{words_=words;}
    friend bool operator==(const SceneRecordEligibility&,const SceneRecordEligibility&)=default;
private:
    Words words_{};
};
}
