#pragma once
#include "interpreter.hpp"

namespace reo::native::gameplay_scenario {
using FlagWords=std::array<std::uint32_t,16>;
struct SharedFlags {FlagWords scenario{},secondary{};};
enum class ActorFlagFamily { primary,auxiliary };
struct ActorFlagSelection {bool all_three{};std::uint8_t bank{};};
struct FlagStateSnapshot {
    SharedFlags shared;
    std::array<FlagWords,3> primary{},auxiliary{};
    std::array<std::uint8_t,16> bounded_bytes{};
    std::uint16_t bounded_halfword{};
    // Explicit native room/index admission profile, not an original bounds claim.
    std::array<std::array<std::uint16_t,6>,256> strided{};
};
struct ScenarioFlagChange {std::uint32_t id{};std::uint8_t value{},actor_owner{};NotifyOwner route{};};
struct StridedFlagChange {std::uint32_t record{},bit{};std::uint8_t slot{};bool set{};};
class FlagNotifications {
public:
    virtual ~FlagNotifications()=default;
    virtual void changed(const ScenarioFlagChange&)noexcept=0;
    virtual void changed(const StridedFlagChange&)noexcept=0;
};
// Externally serialized authoritative native banks. Notifications are synchronous
// after the write and may reenter ordinary flag operations; no lock is held.
class FlagState final:public Flags {
public:
    explicit FlagState(FlagNotifications* notifications=nullptr)noexcept:notifications_(notifications){}
    std::optional<bool> get(FlagBank,std::uint32_t)const noexcept override;
    bool write(FlagBank,std::uint32_t,bool)noexcept override;
    bool scenario(std::uint32_t,std::uint8_t,NotifyOwner,std::uint8_t)noexcept override;
    bool strided(std::uint32_t,std::uint32_t,std::uint8_t,bool,bool)noexcept override;
    bool actor_flag(ActorFlagFamily,ActorFlagSelection,std::uint32_t,bool)noexcept;
    const FlagStateSnapshot& snapshot()const noexcept{return state_;}
    void restore(const FlagStateSnapshot& value)noexcept{state_=value;}
    SharedFlags shared()const noexcept{return state_.shared;}
    void shared(const SharedFlags& value)noexcept{state_.shared=value;}
    bool notification_ready()const noexcept{return notifications_!=nullptr;}
private:
    FlagStateSnapshot state_;
    FlagNotifications* notifications_{};
    FlagWords* words(FlagBank)noexcept;
    const FlagWords* words(FlagBank)const noexcept;
};
} // namespace reo::native::gameplay_scenario
