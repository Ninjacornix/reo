#pragma once
#include "actor_resource_operations.hpp"
#include "behavior.hpp"
namespace reo::native::gameplay_update {class Owner;}
namespace reo::native::gameplay_world {
class ActorRecovery;
// Remaining actual UI/recovery/remote-notice consumers. No successful defaults;
// implementations belong to this World and outlive synchronous progression.
class GaugeTransitionEffects {
public:
    virtual ~GaugeTransitionEffects()=default;
    virtual bool bound_to(const World&)const noexcept=0;
    virtual bool notify_ui()=0; //6DF160, global UI/timer request rather than a completion-statistics update
    virtual std::optional<bool> close_blocked()=0; //6DEE80
    virtual bool close()=0; //6E1430, after the canonical inventory-owner clear
    virtual bool recover(const actors::EntityId&,std::uint8_t)=0; //65FCB0
    virtual bool notify_off_room(const actors::EntityId&)=0; //81C690
};
inline constexpr std::array<std::uint32_t,8> actor_gauge_rates{30,60,24,60,60,30,30,15}; //71ADD0
inline constexpr std::array<float,8> actor_gauge_scales{.5f,.7f,.9f,1.f,1.2f,1.4f,1.6f,1.f}; //71AD10
class ActorGaugeProgression final:public ProgressionTiming {
public:
    ActorGaugeProgression(gameplay_update::Owner&,ActorResourceOperations&,GaugeTransitionEffects* = nullptr,ActorRecovery* = nullptr);
    std::uint8_t tick(const actors::EntityId&);
    bool apply_progression_timer(World&,Actor&)override;
private:
    gameplay_update::Owner& update_;ActorResourceOperations& operations_;World& world_;
    GaugeTransitionEffects* effects_{};
    ActorRecovery* recovery_{};
    GaugeTransitionEffects& effects();
    void close_ui();
};
}
