#pragma once
#include <cstddef>
#include <array>
#include <cstdint>
#include <memory>
#include <optional>
#include <unordered_map>
#include <variant>

namespace reo::native::gameplay_scenario {
struct SceneControlDomain;
class SceneControls;
class ActionChoices;
class PeriodicEffects;
}
namespace reo::native::gameplay_session { class Random; }
namespace reo::native::gameplay_scenario {
class SceneControlId final {
public:
    SceneControlId()=default;
    explicit operator bool()const noexcept{return bool(domain_);}
    friend bool operator==(const SceneControlId&,const SceneControlId&)=default;
private:
    std::shared_ptr<const SceneControlDomain> domain_;
    std::uint64_t serial_{};
    friend class SceneControls;
};
// Type numbers are observed content tags, not guessed subsystem names. Typed
// values project only fields owned by these commands; no original byte layout.
struct ControlRouteDestination {std::uint32_t room{},edge{};friend bool operator==(const ControlRouteDestination&,const ControlRouteDestination&)=default;};
struct ControlModelReference {std::uint32_t model{},descriptor{};friend bool operator==(const ControlModelReference&,const ControlModelReference&)=default;};
struct ControlMatrixProgramResource {std::uint8_t model_slot{};std::uint32_t descriptor{};std::uint8_t resource_class{};};
struct ControlTypeZero {std::uint32_t parameter{};std::uint16_t half_parameter{};std::uint8_t byte_parameter{},refresh_parameter{};std::optional<ControlRouteDestination> destination{};std::optional<ControlMatrixProgramResource> matrix_program{};};
struct ControlTypeOne {std::uint16_t parameter{};};
struct ControlTypeTwo {std::uint32_t selector{},parameter{};std::uint16_t half_parameter{};std::uint8_t byte_parameter{},refresh_parameter{};std::optional<ControlModelReference> model_reference{};std::optional<std::uint8_t> matrix_resource_class{};};
struct ControlTypeThree {std::uint32_t mode{};std::uint16_t parameter{};};
struct ControlTypeFour {std::uint32_t mode{},selector{};};
struct ControlTypeFive {std::uint16_t selector{},duration{},countdown{},secondary_parameter{};std::uint32_t completion{};std::uint8_t byte_parameter{};
    // Additional fields written by the complete reset. Their consumer roles
    // remain unresolved; they are typed state, not raw guest-layout storage.
    std::uint16_t reset_sentinel{};std::uint8_t reset_byte_a{},reset_byte_b{};
    std::array<float,3> position{};
    std::uint16_t effect_parameter{};};
struct ControlTypeNine {std::uint32_t parameter{};};
struct ControlTypeSix {std::uint32_t selector{};};
struct ControlTypeSeven {std::uint32_t selector{};};
struct ControlTypeEleven {};
struct ControlTypeThirteen {std::uint32_t selector{};std::uint16_t parameter{};};
struct ControlOther {std::uint8_t type{};};
using SceneControlBody=std::variant<ControlTypeZero,ControlTypeOne,ControlTypeTwo,ControlTypeThree,ControlTypeFour,ControlTypeFive,ControlTypeNine,ControlTypeThirteen,ControlOther,ControlTypeSix,ControlTypeSeven,ControlTypeEleven>;
struct SceneControl {std::uint32_t authored_id{};std::uint8_t enabled{};SceneControlBody body;std::uint8_t counter{};};
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
    explicit SceneControls(std::size_t maximum=1024);
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
    std::size_t size()const noexcept{return records_.size();}
    ControlResult apply(ControlCommand,const ControlArguments&,ControlEffects*,std::size_t maximum_visits=4096)noexcept;
    ControlResult apply_typed(bool enable,std::uint32_t type,std::uint32_t authored_id,std::uint32_t selector,std::size_t maximum_visits=4096)noexcept;
    ControlResult choose_five(std::uint32_t authored_id,const std::array<std::uint32_t,4>& choices,ActionChoices&,std::uint8_t character,bool permitted,gameplay_session::Random&,std::size_t maximum_visits=4096)noexcept;
    // First source type0/2 with fullword id matching the narrowed request.
    // Enabled flags do not filter; callers re-get(id) after synchronous effects.
    ControlRouteResult first_route(std::uint8_t authored_id,std::size_t maximum_visits=4096)const noexcept;
    ControlResult disable_three(std::size_t maximum_visits=4096)noexcept;
    ControlResult start_periodic(const PeriodicControlArguments&,PeriodicEffects&,std::size_t maximum_visits=4096)noexcept;
private:
    struct Node {SceneControlId id;SceneControl value;std::shared_ptr<Node> next;};
    std::shared_ptr<const SceneControlDomain> domain_;
    std::shared_ptr<Node> head_,tail_;
    std::unordered_map<std::uint64_t,std::weak_ptr<Node>> records_;
    std::uint64_t next_serial_{1};
    std::size_t maximum_;
    bool enabled_{true},clearing_{};
    std::shared_ptr<Node> acquire(const SceneControlId&)const noexcept;
};
} // namespace reo::native::gameplay_scenario
