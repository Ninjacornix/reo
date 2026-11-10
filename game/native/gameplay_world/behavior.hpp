#pragma once
#include "surfaces.hpp"

namespace reo::native::gameplay_world {
// Remaining real providers. These operations must be supplied by their native
// owners; the interface contains no successful default implementation.
enum class BehaviorStage {
    sample_surface,resolve_surface,prepare_inventory,progression,
    interaction,terminal_timer,prepare_control,analog_control,cooperation,
    consume_control_request,activity_notice,update_attachment,update_terminal_attachment
};
enum class ActionPass {primary,secondary};
class BehaviorServices : public actors::HitServices {
public:
    virtual void run(BehaviorStage,World&,Actor&)=0;
    // The state is read at each dispatch, after all earlier synchronous effects.
    // Unsupported required actions must fail visibly, never become a no-op.
    virtual void dispatch(ActionPass,std::uint8_t,World&,Actor&)=0;
    virtual bool suppress_action_notice(World&,Actor&,std::uint8_t previous_primary,
                                        std::uint8_t previous_secondary)=0;
};
// Actual activity-notice consumer, borrowed for a synchronous behavior pass.
// A false result stops this pass and retains mutations preceding publication.
class ActivityPublication {
public:
    virtual ~ActivityPublication()=default;
    virtual bool publish_activity(World&,Actor&)noexcept=0;
};
class GaugeApplication {
public:
    virtual ~GaugeApplication()=default;
    virtual bool apply_hit_gauge(World&,Actor&,std::uint16_t)=0;
};
class TerminalTiming {
public:
    virtual ~TerminalTiming()=default;
    virtual bool apply_terminal_timer(World&,Actor&)=0;
};
class ProgressionTiming {
public:
    virtual ~ProgressionTiming()=default;
    virtual bool apply_progression_timer(World&,Actor&)=0;
};
class ZeroHealthApplication {
public:
    virtual ~ZeroHealthApplication()=default;
    virtual bool apply_zero_health(World&,Actor&,actors::StatusServices&)=0;
};
// Operates directly on the canonical World actor/session. Timers, status and
// pending hits use their qualified native cores; other providers remain explicit.
// Throws leave a partial invocation, exactly as World service failures do.
void update_behavior(World&,Actor&,BehaviorServices&,std::span<const std::int16_t> hit_timer_amounts,
                     const gameplay_collision::response::Grid* native_floors=nullptr,
                     ActivityPublication* publication=nullptr,GaugeApplication* gauge=nullptr,
                     TerminalTiming* terminal=nullptr,ProgressionTiming* progression=nullptr,
                     ZeroHealthApplication* zero_health=nullptr);
// Actual primary-frame consumer of update_behavior. The remaining frame ports
// and behavior effects are borrowed synchronous owners and must outlive this
// adapter; a supplied native floor owner must also outlive it. Timer content is
// copied so callers cannot leave a dangling span. Without that owner both
// surface operations remain explicit required BehaviorServices effects.
// A supplied activity publication owner must likewise outlive this adapter;
// otherwise the activity stage remains an explicit required behavior effect.
class BehaviorFrameServices final : public Services {
public:
    BehaviorFrameServices(Services& frame,BehaviorServices& behavior,
                          std::span<const std::int16_t> hit_timer_amounts,
                          ActivityPublication* publication=nullptr,GaugeApplication* gauge=nullptr,
                          TerminalTiming* terminal=nullptr,ProgressionTiming* progression=nullptr,
                          ZeroHealthApplication* zero_health=nullptr);
    BehaviorFrameServices(Services& frame,BehaviorServices& behavior,
                          const gameplay_collision::response::Grid& floors,
                          std::span<const std::int16_t> hit_timer_amounts,
                          ActivityPublication* publication=nullptr,GaugeApplication* gauge=nullptr,
                          TerminalTiming* terminal=nullptr,ProgressionTiming* progression=nullptr,
                          ZeroHealthApplication* zero_health=nullptr);
    void begin_offline_frame(World&)override;
    void run(Stage,World&,Actor&)override;
    bool remote_motion(World&,Actor&)override;
    bool find_grid(World&,Actor&,std::int8_t&)override;
    void switch_grid(World&,std::int32_t,std::int32_t)override;
    float grid_response(World&,std::uint8_t)override;
private:
    Services& frame_;
    BehaviorServices& behavior_;
    std::vector<std::int16_t> hit_timer_amounts_;
    const gameplay_collision::response::Grid* floors_{};
    ActivityPublication* publication_{};
    GaugeApplication* gauge_{};
    TerminalTiming* terminal_{};
    ProgressionTiming* progression_{};
    ZeroHealthApplication* zero_health_{};
};
} // namespace reo::native::gameplay_world
