#pragma once
#include "flags.hpp"
#include "scene_controls.hpp"
#include "../gameplay_session/session.hpp"
#include "../gameplay_tasks/tasks.hpp"
#include "../gameplay_actors/entity.hpp"
#include "../transform_math/transform_math.hpp"
namespace reo::native::gameplay_scenario {
using EffectPosition=transform_math::Vector;
struct PeriodicVisual:gameplay_actors::Entity {
    EffectPosition position,initial_position;
    std::int16_t delay{},remaining{};
    float scale{};
};
struct PeriodicEmission {
    std::uint16_t descriptor{};
    EffectPosition position;
    std::uint32_t flags{0x1a193};
};
enum class EmissionStatus {completed,pool_full,unavailable};
struct EmissionResult {EmissionStatus status{EmissionStatus::unavailable};std::shared_ptr<PeriodicVisual> visual;};
class PeriodicEmitter {
public:
    virtual ~PeriodicEmitter()=default;
    // Required actual native visual/resource owner. A true admission requires
    // all three descriptors and the native periodic visual callback consumer.
    virtual bool admitted()const noexcept=0;
    virtual EmissionResult emit(const PeriodicEmission&)noexcept=0;
};
enum class PeriodicStatus {completed,flag_unavailable,emitter_unavailable,invalid_control,closed,no_memory,task_unavailable};
struct PeriodicState {
    std::uint8_t phase{};
    std::int16_t timer{},packed{};
    EffectPosition position;
};
struct PeriodicStep {PeriodicStatus status{PeriodicStatus::completed};bool retire{};};
// Complete source5D9680/5DDC70 timing and emission policy. Native caller owns
// the actual visual instance/resource lifecycle and publishes admission honestly.
PeriodicStep update_periodic(PeriodicState&,std::uint16_t stop_code,FlagState&,
    gameplay_session::Random&,PeriodicEmitter&)noexcept;

struct PeriodicCreated {
    PeriodicStatus status{PeriodicStatus::completed};
    gameplay_tasks::Status task_status{gameplay_tasks::Status::invalid};
    gameplay_tasks::Handle task{};
};
class PeriodicEffects final {
public:
    // All borrowed owners outlive this component and its synchronous callbacks.
    PeriodicEffects(gameplay_tasks::Scheduler&,SceneControls&,FlagState&,gameplay_session::Random&,PeriodicEmitter&);
    ~PeriodicEffects();
    PeriodicEffects(const PeriodicEffects&)=delete;
    PeriodicEffects& operator=(const PeriodicEffects&)=delete;
    PeriodicCreated create(const SceneControlId&)noexcept;
    bool admitted()const noexcept;
    bool bound_to(const SceneControls&,const FlagState&,const gameplay_session::Random&)const noexcept;
    bool bound_to(const SceneControls&)const noexcept;
    bool healthy()const noexcept;
    std::optional<PeriodicState> snapshot(const gameplay_tasks::Handle&)const noexcept;
    PeriodicStatus failure()const noexcept;
    void close()noexcept;
private:
    struct Shared;
    class Work;
    std::shared_ptr<Shared> shared_;
};
}
