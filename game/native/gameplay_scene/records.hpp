#pragma once
#include "record_pool.hpp"
#include "entry_details.hpp"
#include "../gameplay_scenario/scene_control_types.hpp"
#include "../gameplay_collision/collision.hpp"
#include "../gameplay_actors/entity.hpp"
#include <array>

namespace reo::native::gameplay_scene {
// Collision-only state. Kind, priority, activity, identity and type-dependent
// +48 data live in the inherited typed control fields exactly once.
struct CollisionShape {
    gameplay_collision::Quad bounds;
    std::int32_t lower{}, upper{};
    std::uint8_t query_class{};
    bool busy{};
    gameplay_collision::ObjectAdmission object;
};
struct DoorDetails { std::optional<std::uint32_t> selector_without_matrix; };
// Exact type-3 policy fields consumed by5C3FE0. Raw RDT offsets are projected
// at RoomSceneInput; these are source parameters, not guest memory aliases.
struct FlagPolicyCallback {std::uint32_t gate{},expected{},inequality{};std::uint16_t event{0xffff};};
// Exact5C4230 inventory/flag callback inputs. `event_word` remains full-width
// because the source tests signed(P+68)!=-1 before narrowing the low half.
struct InventoryPolicyCallback {
    std::uint32_t gate{},expected{},inequality{},operation{},flag_bank{};
    std::uint32_t second_content{},event_word{0xffffffffu};
};
//5C4600's source fields are distinct from ControlTypeFive's periodic-effect
//state. Raw room data is projected without assigning guessed meanings to
//the task-condition and category-selected event values.
struct ConditionalEventCallback {
    std::uint16_t base_event{},condition{},alternate_event{},task_parameter{};
    std::uint8_t callback_parameter{},category_mask{};
    std::array<std::uint16_t,8> category_events{};
    std::int16_t counter_limit{},counter{};
    std::uint8_t deactivate{};
    std::uint32_t flag_id{},flag_mode{};
};
struct Record : gameplay_scenario::SceneControl {
    std::optional<CollisionShape> collision;
    gameplay_actors::EntityId owner;
    // Original proxy+3E: last query-class byte written by 5DC570/5DCA90.
    // It is independent of CollisionShape::query_class, which is authored
    // admission data used to decide whether the record matches a query.
    std::optional<std::uint8_t> last_query_class;
    RecordId source;
    std::optional<DoorDetails> door;
    std::optional<DoorEntryDetails> door_entry;
    std::optional<ObjectEntryDetails> object_entry;
    std::optional<LadderEntryDetails> ladder_entry;
    std::optional<std::uint8_t> owner_snapshot,extra; // original44/45; distinct from3F
    // Original3F: allocator zeroes it; room initialization writes ordinal+1.
    // Condition lookup reads this byte SIGNED, including the default zero.
    std::uint8_t condition_ordinal{};
    // Used only for tags whose +48 has no existing semantic typed projection.
    // Type0 destination and type2 descriptor always use their body field.
    std::optional<std::uint32_t> other_content;
    std::optional<FlagPolicyCallback> flag_policy;
    std::optional<InventoryPolicyCallback> inventory_policy;
    std::optional<ConditionalEventCallback> conditional_event;
    // Full-word native admission field. The matrix selector consumes a byte;
    // collision consumes equality with the complete word. A missing value is
    // distinct from an authored zero.
    std::optional<std::uint32_t> other_resource_class;
};
using Records=RecordPool<Record>;

inline std::uint8_t kind(const gameplay_scenario::SceneControlBody& body)noexcept {
    using namespace gameplay_scenario;
    return std::visit([](const auto& v)->std::uint8_t{
        using T=std::decay_t<decltype(v)>;
        if constexpr(std::is_same_v<T,ControlTypeZero>)return 0;
        else if constexpr(std::is_same_v<T,ControlTypeOne>)return 1;
        else if constexpr(std::is_same_v<T,ControlTypeTwo>)return 2;
        else if constexpr(std::is_same_v<T,ControlTypeThree>)return 3;
        else if constexpr(std::is_same_v<T,ControlTypeFour>)return 4;
        else if constexpr(std::is_same_v<T,ControlTypeFive>)return 5;
        else if constexpr(std::is_same_v<T,ControlTypeSix>)return 6;
        else if constexpr(std::is_same_v<T,ControlTypeSeven>)return 7;
        else if constexpr(std::is_same_v<T,ControlTypeNine>)return 9;
        else if constexpr(std::is_same_v<T,ControlTypeEleven>)return 11;
        else if constexpr(std::is_same_v<T,ControlTypeThirteen>)return 13;
        else return v.type;
    },body);
}
inline std::optional<std::uint32_t> content(const Record& record)noexcept {
    using namespace gameplay_scenario;
    if(const auto* zero=std::get_if<ControlTypeZero>(&record.body))return zero->destination?std::optional<std::uint32_t>(zero->destination->edge):std::nullopt;
    if(const auto* two=std::get_if<ControlTypeTwo>(&record.body))return two->model_reference?std::optional<std::uint32_t>(two->model_reference->descriptor):std::nullopt;
    return record.other_content;
}
inline gameplay_collision::Proxy collision_view(const Record& record)noexcept {
    gameplay_collision::Proxy p;
    p.kind=kind(record.body);p.priority=record.counter;p.active=record.enabled!=0;
    p.identifier=record.authored_id;const auto value=content(record);p.content_id=value.value_or(0);
    if(!value)p.active=false;
    if(const auto* two=std::get_if<gameplay_scenario::ControlTypeTwo>(&record.body))p.bypass_slot_guard=two->matrix_resource_class==2;
    else p.bypass_slot_guard=record.other_resource_class==2;
    if(record.collision){const auto& shape=*record.collision;p.bounds=shape.bounds;p.lower=shape.lower;p.upper=shape.upper;p.query_class=shape.query_class;p.busy=shape.busy;p.object=shape.object;}
    else p.active=false; // A standalone typed fixture has no admitted geometry.
    return p;
}
} // namespace reo::native::gameplay_scene
