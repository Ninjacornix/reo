#pragma once
#include "health.hpp"
#include "../gameplay_session/session.hpp"

namespace reo::native::gameplay_actors {
struct StatusActor : HealthState {
    std::uint32_t auxiliary_status{};
    std::uint16_t damage_interval_one{}, damage_interval_two{}, status_duration{}, recovery_timer{};
    std::uint8_t primary{}, secondary{}, phase{}, subphase{}, motion_class{}, response_class{};
};
struct StatusSession : HealthSession {
    bool paused{};
    std::uint8_t clock_mode{}, feedback_phase{}, feedback_suppressed{};
    std::int16_t session_state{};
};
class StatusServices : public HealthServices {
public:
    virtual void feedback(StatusActor&,StatusSession&,std::uint8_t kind)=0;
    virtual void publish(StatusActor&,StatusSession&,std::uint8_t kind)=0;
    virtual void cleanup(StatusActor&,StatusSession&)=0;
    virtual void recover(StatusActor&,StatusSession&)=0;
    virtual void snapshot(StatusActor&,StatusSession&)=0;
};
bool periodic_damage_admitted(const StatusActor&) noexcept;
void clear_status(StatusActor&,StatusSession&,StatusServices&,std::uint8_t selector);
void tick_status(StatusActor&,StatusSession&,StatusServices&,gameplay_session::Random&);
void select_zero_health_action(StatusActor&,StatusSession&,StatusServices&);
bool override_hit_response(StatusActor&,StatusSession&,StatusServices&);
} // namespace reo::native::gameplay_actors
