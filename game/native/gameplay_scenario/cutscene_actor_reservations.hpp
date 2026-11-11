#pragma once
#include <array>
#include <bit>
#include <cstdint>
#include <span>
namespace reo::native::gameplay_scenario {
enum class CutsceneReservationStatus {completed,full,invalid_count};
// Separate cinematic requested/assigned character sets (5F0C60/5F0CF0/5F0D90).
// These are neither NPC missing-character IDs nor the actual actor bindings.
// The enclosing scene/simulation owner serializes access.
class CutsceneActorReservations final {
public:
    static constexpr unsigned capacity=32;
    CutsceneActorReservations()noexcept{requested_.fill(0x88);reserved_.fill(0x88);}
    // Invalid counts leave existing state intact. The original signed byte
    // count is admitted only in0..32; oversized/negative memory copies are not.
    CutsceneReservationStatus initialize(std::span<const std::uint8_t> characters)noexcept{
        if(characters.size()>capacity)return CutsceneReservationStatus::invalid_count;
        // Input may alias a current view. Capture before clearing either set.
        std::array<std::uint8_t,capacity> next;next.fill(0x88);
        for(unsigned i=0;i<characters.size();++i)next[i]=characters[i];
        requested_=next;requested_count_=std::uint8_t(characters.size());reserved_.fill(0x88);reserved_count_=0;
        return CutsceneReservationStatus::completed;
    }
    bool contains(std::int32_t character)const noexcept{
        if(character==255)return true;
        for(const auto byte:requested())if(std::bit_cast<std::int8_t>(byte)==character)return true;
        for(const auto byte:reserved())if(std::bit_cast<std::int8_t>(byte)==character)return true;
        return false;
    }
    // Repeated characters are retained, matching the source append operation.
    CutsceneReservationStatus reserve(std::uint8_t character)noexcept{
        if(reserved_count_==capacity)return CutsceneReservationStatus::full;
        reserved_[reserved_count_++]=character;return CutsceneReservationStatus::completed;
    }
    std::span<const std::uint8_t> requested()const noexcept{return{requested_.data(),requested_count_};}
    std::span<const std::uint8_t> reserved()const noexcept{return{reserved_.data(),reserved_count_};}
private:
    std::array<std::uint8_t,capacity> requested_{},reserved_{};
    std::uint8_t requested_count_{},reserved_count_{};
};
}
