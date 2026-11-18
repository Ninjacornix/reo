#pragma once
#include "animation.hpp"
namespace reo::native::gameplay_world {
// Complete6673C0 and64F690, on canonical primary actor state.
std::uint8_t consume_action_reset(Actor&);
bool select_changed_health_action(Actor&);
// Semantic animation operations used at the original action call sites.
// The production implementation below retains the World and real playback;
// differential tests may observe this boundary without replacing the action.
class ActionAnimation {
public:
    virtual ~ActionAnimation()=default;
    virtual void select(Actor&,std::uint32_t,float,float)=0;
    virtual void activate(Actor&)=0;
    virtual std::int8_t tick(Actor&,float)=0;
    virtual void or_flags(Actor&);
    virtual float first_frame(Actor&,std::uint32_t,std::uint16_t);
    virtual float last_frame(Actor&,std::uint32_t,std::uint16_t);
    virtual float matched_frame(Actor&,std::uint32_t,std::uint16_t);
};
class NativeActionAnimation final:public ActionAnimation {
public:
    NativeActionAnimation(World&,WorldAnimation&);
    void select(Actor&,std::uint32_t,float,float)override;
    void activate(Actor&)override;
    std::int8_t tick(Actor&,float)override;
    void or_flags(Actor&)override;
    float first_frame(Actor&,std::uint32_t,std::uint16_t)override;
    float last_frame(Actor&,std::uint32_t,std::uint16_t)override;
    float matched_frame(Actor&,std::uint32_t,std::uint16_t)override;
private:
    World& world_;WorldAnimation& animation_;
    actors::EntityId admit(Actor&)const;
};
// Complete66B990. The caller owns dispatch66B960's status-bit clear.
void update_idle_action(Actor&,ActionAnimation&);
}
