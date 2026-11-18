#include "activity.hpp"
namespace reo::native::gameplay_session {
std::optional<std::int32_t> activity_mode(std::uint8_t main_mode,const ActivityState& state)noexcept{
    if(main_mode==0)return state.single?std::optional<std::int32_t>(*state.single):std::nullopt;
    if(main_mode==1)return state.online?std::optional<std::int32_t>(*state.online):std::nullopt;
    return 1;
}
}
