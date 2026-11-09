#pragma once
#include "contact_component.hpp"
#include "postmove_view.hpp"
#include <map>
namespace reo::native::gameplay_collision::delivery {
struct View {
    actors::EntityId id;
    gameplay_actors::HitActor& actor;
    Component& contact;
    const std::uint8_t& character;
    postmove::VectorRef position;
    std::uint8_t& cooldown;
};
class Actors {
  public:
    virtual ~Actors() = default;
    // Invocation-scoped native actor/pose leases must outlive every returned
    // view. Lookup rejects retired IDs; no actor storage address is persisted.
    virtual std::optional<View> find(const actors::EntityId&) = 0;
};
Identity identity(View) noexcept;
bool prepare(View, hit_regions::Queue&) noexcept;
enum class Status {
    completed,
    missing_actor,
    unadmitted_content,
    unknown_advanced_direction,
    uninitialized_output_point,
    invalid_roster
};
// An immutable decoded response descriptor. Source bank/key selection and
// geometry ownership are separate from the response template's numeric ID.
struct Template {
    std::int16_t base{}, route_amount{};
    std::uint8_t damage_kind{}, priority{}, auxiliary_a{}, auxiliary_b{};
    std::uint8_t max_contacts{}, cooldown{}, flags{}, actor_sound{};
    std::uint8_t kind{}, response_code{}, value_id{}, query_flags{}, response_flags{};
    std::uint8_t progression{}, scene_sound{}, probability{};
};
Template import_template(std::span<const std::byte>);
struct Packet {
    actors::EntityId source, cached_related;
    Template response;
    std::uint8_t bank{}, key{}, event{};
};
Status record_provenance(View receiver, const Packet&, Actors&);
Status restore_provenance(const Packet&, Actors&);
void roll_response(View, const Template&, gameplay_session::Random&) noexcept;
void convert_response(View) noexcept;
std::uint8_t pair_kind(const gameplay_actors::HitActor* source,
                       const gameplay_actors::HitActor& target) noexcept;
struct Value {
    std::int16_t amount{};
    std::uint8_t kind{};
};
struct DistanceValues {
    std::array<Value, 3> bins;
};
struct CategoryValues {
    // An admitted null category table differs from an unknown content address.
    bool admitted{};
    std::optional<std::array<DistanceValues, 128>> entries;
};
struct RandomValues {
    std::array<std::array<std::uint16_t, 8>, 4> damage, progression;
};
struct Tables {
    std::array<float, 100> probabilities{};
    std::array<std::int16_t, 128> weights{};
    std::array<CategoryValues, 256> categories;
    std::optional<std::array<DistanceValues, 128>> flat;
    // Signed template-half selectors remain signed keys. Missing rows refuse
    // rather than interpreting adjacent immutable content as a new table.
    std::map<std::int16_t, RandomValues> random;
};
class Feedback {
  public:
    virtual ~Feedback() = default;
    virtual bool authority(View) = 0;
    virtual void vibration(View, std::uint8_t pattern) = 0;
};
float multiplier(View, const Packet&, const Tables&, gameplay_session::Random&, Feedback&);
struct Calculated {
    Status status{Status::completed};
    Value value;
};
// first is source argument a0 (the contacted actor in scanner call sites),
// second is argument a1 (the resolved attack owner). Keep that source ordering.
Calculated category_value(View first, View second, const Template&, float, const Tables&);
Calculated flat_value(View first, View second, const Template&, float, const Tables&);
} // namespace reo::native::gameplay_collision::delivery
