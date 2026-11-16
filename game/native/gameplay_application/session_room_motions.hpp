#pragma once
#include "../gameplay_world/humanoid_motion_owner.hpp"
#include "../gameplay_scenario/content.hpp"
namespace reo::native::gameplay_application {
class NativeSession;
enum class RoomMotionStatus {completed,unavailable,busy,closed,no_memory};
struct RoomMotionResult {
    RoomMotionStatus status{RoomMotionStatus::unavailable};
    bool released{},loaded{};
    std::optional<std::uint16_t> selector{};
};
//1B2D00 uses the same room/roster and immutable motion publication as ordinary
//animation. Unknown list tails remain unknown; loading another EVB preserves
//the entries after its00FF sentinel, exactly as68C410 does.
class SessionRoomMotions final {
public:
    SessionRoomMotions(NativeSession&,const gameplay_world::HumanoidMotionAssets&,
                       gameplay_world::HumanoidMotionOwner&);
    bool bind_table(const gameplay_scenario::content::ScriptBank&)noexcept;
    RoomMotionResult load()noexcept;
    std::optional<std::uint16_t> selector()const noexcept{return selected_;}
    std::optional<std::uint16_t> room_selector(std::uint16_t room)const noexcept{return room<rows_.size()?rows_[room]:std::nullopt;}
private:
    friend class SessionStartupEffects;
    RoomMotionStatus load_scenario_auxiliary()noexcept;
    void reset_default_selection()noexcept{selected_=0;load_failed_=false;}
    NativeSession& session_;
    const gameplay_world::HumanoidMotionAssets& assets_;
    gameplay_world::HumanoidMotionOwner& motions_;
    std::array<std::optional<std::uint16_t>,128> rows_{};
    std::optional<std::uint16_t> selected_;
    bool running_{},load_failed_{};
};
}
