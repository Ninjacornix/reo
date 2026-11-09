#pragma once
#include "postmove_view.hpp"
#include "../transform_math/transform_math.hpp"
namespace reo::native::gameplay_collision::ground {
struct RotationRef {
    const std::int16_t &x, &y, &z;
    transform_math::Angles angles() const noexcept;
};
struct View {
    postmove::VectorRef position, normal;
    float& height;
    std::uint8_t &surface, &material;
    std::uint16_t& attributes;
    const std::uint32_t& auxiliary_status;
    RotationRef rotation;
};
// This is the secondary policy. The primary actor's surface restoration and
// special-surface handling are deliberately separate consumers.
void refresh(View, const response::Grid&) noexcept;
std::int8_t classify(Vec3 probe, std::uint16_t yaw, const response::Grid&) noexcept;
enum class ProbeStatus { completed, uninitialized_source_probe };
// A source state outside {-1,0,1} has no initialized probe. The preceding floor
// refresh remains visible; no guessed coordinates or classification is stored.
ProbeStatus probe(View, std::int8_t& state, const response::Grid&);
struct ProbeStates {
    std::int8_t kind_one{}, kind_twenty_nine{}, kind_twenty_d{};
};
struct Entry {
    actors::EntityId id;
    View view;
    postmove::VectorRef displacement;
    const std::uint16_t& controls;
    const std::uint8_t& subtype;
    ProbeStates& states;
};
class Walls {
  public:
    virtual ~Walls() = default;
    // Required native wall owner; mutates this same actor synchronously.
    virtual void correct(const actors::EntityId&, View) = 0;
};
struct Report {
    std::uint32_t visited{}, wall_queries{}, displaced{}, classified{}, unknown_probes{};
};
// The scene owner supplies the native reverse-list order and retains actor
// leases throughout. No activity filter, entry references or list pointers are
// retained. All identities must be present and unique before the first write.
Report update(std::span<Entry> ordered, const response::Grid&, Walls&);
} // namespace reo::native::gameplay_collision::ground
