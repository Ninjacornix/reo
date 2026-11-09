#pragma once
#include "actors.hpp"
namespace reo::native::gameplay_collision::spatial {
// Authored/contact identity is independent of EntityId domain/generation.
// Source class2 uses a character token; other classes use a contact ID, neither
// of which is inferred from an entity's reusable storage slot.
struct AuthoredIdentity {std::uint8_t category{},contact_id{};};
enum class PointSpace {world,origin_vector};
struct Point {Vec3 value;PointSpace space{PointSpace::world};};
std::optional<Point> sphere_segment(Vec3 start,Vec3 end,Sphere)noexcept;
std::optional<Point> sphere_margin(Vec3 start,Vec3 end,Sphere,float margin)noexcept;
std::optional<Point> overlap(Sphere,Vec3 point,float margin)noexcept;
bool sphere_edge(Vec3 start,Vec3 end,Sphere)noexcept;
struct Target {
    gameplay_actors::EntityId entity;
    AuthoredIdentity identity;
    std::uint32_t movement_flags{},response_flags{};
    std::vector<Sphere> regions;
};
struct Source {gameplay_actors::EntityId entity,related;AuthoredIdentity identity;};
struct Policy {
    std::uint8_t recipient_mask{};
    bool special_mode{},per_actor{},occlusion{};
    std::span<const std::uint8_t> class_masks;
};
struct Contact {
    gameplay_actors::EntityId target;
    AuthoredIdentity authored;
    std::uint8_t region{};
    Point point;
    Vec3 region_center;
};
enum class Status {complete,unknown_class_domain,invalid_region_count,invalid_target_count,missing_occlusion};
struct Scan {
    std::vector<Contact> deliveries;
    std::uint32_t region_hits{};
    gameplay_actors::EntityId last_scanned,advanced_direction_owner;
    // Some source global-nearest variants later read a region pointer advanced
    // past its owned array. That direction reference remains explicitly unknown.
    bool advanced_direction_unknown{};
    Status status{Status::complete};
};
class Occlusion {
public:
    virtual ~Occlusion()=default;
    virtual bool blocked(Vec3 start,Vec3 end)const=0;
};
enum class Mode {segment,margin};
bool admits(const Target&,const Policy&,Status&)noexcept;
Scan scan(std::span<const Target>,const Source&,Policy,Vec3 start,Vec3 end,float margin,
          Mode,const Occlusion* obstacles=nullptr);
}
