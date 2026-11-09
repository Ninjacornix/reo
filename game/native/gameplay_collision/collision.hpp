#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
#include <optional>
#include <span>
#include <vector>

namespace reo::native::gameplay_collision {
struct Vec3 { float x{}, y{}, z{}; };
struct Point { std::int32_t x{}, z{}; bool operator==(const Point&) const = default; };
using Quad = std::array<Point,4>;
// Import/query arithmetic retains the original integer polygon rules. Native
// callers supply ordinary values; no register context or guest addresses exist.
bool contains(std::span<const Point>, Point) noexcept;
bool overlaps(const Quad&, Point, float radius) noexcept;
bool admits_height(std::int32_t lower, std::int32_t upper, float y) noexcept;
std::optional<Point> integer_xz(Vec3) noexcept;
Vec3 forward_probe(Vec3, std::uint16_t heading, float offset) noexcept;

struct ProxyId {
    std::uint64_t room_generation{};
    std::uint32_t index{};
    bool operator==(const ProxyId&) const = default;
};
struct ActorQuery {
    Vec3 position, point;
    std::uint32_t actor_id{}, character_id{};
    std::uint8_t actor_class{}, query_class{};
    std::uint16_t selected_content{};
    float radius{50};
    bool local{}, primary_owner{}, secondary_owner{};
};
struct ObjectAdmission {
    std::uint8_t policy{};
    std::uint32_t selected_id{};
    std::int32_t mode{};
};
struct Proxy {
    Quad bounds;
    std::int32_t lower{}, upper{};
    std::uint8_t kind{}, query_class{}, priority{};
    bool active{true}, busy{};
    std::uint32_t identifier{}, content_id{};
    bool bypass_slot_guard{};
    ObjectAdmission object;
};
struct ProxyState {
    // Resolved scenario/matrix-span state, provided by native scenario owner.
    bool slot_idle{true}, grid_span_admitted{true};
};
struct Selection { ProxyId id; std::uint32_t actor_id{}; std::uint8_t query_class{}; };
class World {
public:
    // Preserve creation order; original query walks newest to oldest.
    World(std::uint64_t room_generation, std::vector<Proxy>);
    std::optional<Selection> select(const ActorQuery&, std::span<const ProxyState>) const noexcept;
    const Proxy* get(ProxyId) const noexcept;
    std::size_t size() const noexcept { return proxies_.size(); }
private:
    std::uint64_t generation_;
    std::vector<Proxy> proxies_;
};

// Finite owned RDT section-A import. It contains an offset directory followed
// by 0xB0-byte records, not a flat array. Only collision descriptions are
// imported here: object activation and scenario effects remain scenario-owned.
struct Door {
    std::uint32_t id{}, destination_room{}, destination_door{};
    std::uint16_t heading{};
    std::uint32_t selector{};
};
struct ImportedProxy { Proxy proxy; std::optional<Door> door; };
struct ImportContext { std::uint16_t scenario{}, room{}; };
std::vector<ImportedProxy> import_proxy_section(std::span<const std::byte>, ImportContext = {});

struct Sphere { Vec3 center; float radius{}; };
struct Contact { Vec3 correction; };
std::optional<Contact> sphere_contact(Sphere, Sphere) noexcept;
// Native displacement policy keeps the original ordered priority/movement
// split and horizontal-only application. Actor position ownership is external.
struct Body {
    Vec3 position, previous, accumulated;
    std::uint8_t priority{}, separation_count{};
};
bool separate(Body&, Body&, Vec3 correction, bool limit_repeated, bool fast_tick) noexcept;

struct Extrema { Vec3 positive, negative; };
void accumulate(Extrema&, Vec3) noexcept;
Vec3 combine(const Extrema&) noexcept;
}
