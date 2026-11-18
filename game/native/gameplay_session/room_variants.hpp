#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
#include <optional>
namespace reo::native::gameplay_session {
// Canonical source4B9D20 room selections. Unknown is distinct from authored0;
// initialization/import must supply a real value before a consumer needs it.
class RoomVariants {
public:
    static constexpr std::size_t capacity=128;
    std::optional<std::uint8_t> get(std::uint32_t room)const noexcept{
        return room<values_.size()?values_[room]:std::nullopt;
    }
    bool store(std::uint32_t room,std::uint32_t value)noexcept{
        if(room>=values_.size())return false;
        values_[room]=std::uint8_t(value);return true;
    }
    void restore(const std::array<std::uint8_t,capacity>& values)noexcept{
        for(std::size_t i=0;i<values_.size();++i)values_[i]=values[i];
    }
private:
    std::array<std::optional<std::uint8_t>,capacity> values_{};
};
}
