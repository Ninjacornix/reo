#pragma once
#include "record_pool.hpp"
#include "../gameplay_scenario/scene_control_types.hpp"
#include "../gameplay_collision/collision.hpp"
#include "../gameplay_actors/entity.hpp"

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
struct Record : gameplay_scenario::SceneControl {
    std::optional<CollisionShape> collision;
    gameplay_actors::EntityId owner;
    RecordId source;
    std::optional<DoorDetails> door;
    std::optional<std::uint8_t> owner_snapshot, extra;
    // Used only for tags whose +48 has no existing semantic typed projection.
    // Type0 destination and type2 descriptor always use their body field.
    std::uint32_t other_content{};
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
inline std::uint32_t content(const Record& record)noexcept {
    using namespace gameplay_scenario;
    if(const auto* zero=std::get_if<ControlTypeZero>(&record.body);zero&&zero->destination)return zero->destination->edge;
    if(const auto* two=std::get_if<ControlTypeTwo>(&record.body);two&&two->model_reference)return two->model_reference->descriptor;
    return record.other_content;
}
inline gameplay_collision::Proxy collision_view(const Record& record)noexcept {
    gameplay_collision::Proxy p;
    p.kind=kind(record.body);p.priority=record.counter;p.active=record.enabled!=0;
    p.identifier=record.authored_id;p.content_id=content(record);
    if(const auto* two=std::get_if<gameplay_scenario::ControlTypeTwo>(&record.body))p.bypass_slot_guard=two->matrix_resource_class==2;
    else p.bypass_slot_guard=record.other_resource_class==2;
    if(record.collision){const auto& shape=*record.collision;p.bounds=shape.bounds;p.lower=shape.lower;p.upper=shape.upper;p.query_class=shape.query_class;p.busy=shape.busy;p.object=shape.object;}
    else p.active=false; // A standalone typed fixture has no admitted geometry.
    return p;
}
} // namespace reo::native::gameplay_scene
