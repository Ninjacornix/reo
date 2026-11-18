#pragma once
#include <cstddef>
#include <array>
#include <cstdint>
#include <memory>
#include <optional>
#include "scene_control_types.hpp"
#include "../gameplay_scene/records.hpp"
#include <variant>

namespace reo::native::gameplay_scenario {
class SceneControls;
class ActionChoices;
class PeriodicEffects;
}
namespace reo::native::gameplay_session { class Random; }
namespace reo::native::gameplay_scenario {
using SceneControlId=gameplay_scene::RecordId;

enum class ControlCommand { zero_two_parameter,type_one_parameter,enable_even,disable_even,zero_word_byte,
    restart_five,reset_five,restart_five_byte,enable_odd,disable_odd,enable_one,disable_one,
    enable_zero_two,disable_zero_two,zero_two_half,enable_nine,enable_thirteen,refresh_zero_two };
struct ControlArguments {std::uint32_t authored_id{},parameter{},selector{};std::uint16_t extra{};};
struct PeriodicControlArguments {std::uint32_t authored_id{};std::uint16_t selector{},stop{},parameter{};};
enum class ControlStatus { completed,invalid_identity,provider_unavailable,invalid_profile,closed,full,budget_exhausted };
struct ControlResult {ControlStatus status{ControlStatus::completed};std::size_t visited{},matched{};};
struct ControlRouteResult {ControlStatus status{ControlStatus::completed};std::optional<SceneControlId> id;std::size_t visited{};};
class ControlEffects {
public:
    virtual ~ControlEffects()=default;
    virtual void reset(SceneControls&,const SceneControlId&)noexcept=0;
    virtual void refresh(SceneControls&,const SceneControlId&,std::uint8_t authored_id)noexcept=0;
};
// Simulation-owner thread only. Invocation leases preserve the current node's
// next link across a callback that retires it. Traversal reads next AFTER effect.
class SceneControls final {
public:
    explicit SceneControls(std::size_t maximum=128);
    explicit SceneControls(std::shared_ptr<gameplay_scene::Records>);
    std::shared_ptr<gameplay_scene::Records> records()const noexcept{return pool_;}
    ~SceneControls();
    SceneControls(const SceneControls&)=delete;
    SceneControls& operator=(const SceneControls&)=delete;
    std::optional<SceneControlId> append(SceneControl);
    std::optional<SceneControl> get(const SceneControlId&)const noexcept;
    ControlStatus replace(const SceneControlId&,SceneControl)noexcept;
    ControlStatus erase(const SceneControlId&)noexcept;
    ControlStatus reset_five(const SceneControlId&)noexcept;
    void clear()noexcept;
    void enabled(bool value)noexcept{enabled_=value;}
    bool enabled()const noexcept{return enabled_;}
    std::size_t size()const noexcept{return pool_->size();}
    ControlResult apply(ControlCommand,const ControlArguments&,ControlEffects*,std::size_t maximum_visits=4096)noexcept;
    ControlResult apply_typed(bool enable,std::uint32_t type,std::uint32_t authored_id,std::uint32_t selector,std::size_t maximum_visits=4096)noexcept;
    ControlResult choose_five(std::uint32_t authored_id,const std::array<std::uint32_t,4>& choices,ActionChoices&,std::uint8_t character,bool permitted,gameplay_session::Random&,std::size_t maximum_visits=4096)noexcept;
    // First source type0/2 with fullword id matching the narrowed request.
    // Enabled flags do not filter; callers re-get(id) after synchronous effects.
    ControlRouteResult first_route(std::uint8_t authored_id,std::size_t maximum_visits=4096)const noexcept;
    ControlResult disable_three(std::size_t maximum_visits=4096)noexcept;
    ControlResult start_periodic(const PeriodicControlArguments&,PeriodicEffects&,std::size_t maximum_visits=4096)noexcept;
private:
    using Node=gameplay_scene::Records::Node;
    std::shared_ptr<gameplay_scene::Records> pool_;
    bool enabled_{true},clearing_{};
    std::shared_ptr<Node> acquire(const SceneControlId&)const noexcept;
};
} // namespace reo::native::gameplay_scenario
