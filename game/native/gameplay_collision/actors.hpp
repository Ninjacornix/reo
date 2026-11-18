#pragma once
#include "response.hpp"
#include "../gameplay_actors/entity.hpp"
#include <variant>
namespace reo::native::gameplay_collision::actors {
using EntityId=gameplay_actors::EntityId;
struct Basis {
    Vec3 x{1,0,0}, y{0,1,0}, z{0,0,1}, translation;
    Vec3 direction(Vec3)const noexcept;
    Vec3 point(Vec3)const noexcept;
};
struct Center {
    std::optional<std::uint16_t> first_joint, second_joint;
    Vec3 first_offset, second_offset;
};
enum class ShapeKind { sphere, capsule };
struct ShapeDefinition { ShapeKind kind{}; float radius{}; Center first, second; };
ShapeDefinition import_shape(std::span<const std::byte>);
using Shape=std::variant<Sphere,response::Capsule>;
struct Summary { float x{}, z{}; std::uint16_t half_length{}, heading{}; };
struct Actor {
    EntityId id;
    Vec3 position, previous, candidate_direction;
    std::span<const Basis> joints;
    std::optional<ShapeDefinition> definition;
    std::uint8_t actor_class{}, priority{}, separation_count{};
    bool contact{}, boundary_clamped{};
    EntityId peer;
    std::uint16_t room{};
    Summary summary;
};
Shape build(const Actor&,const ShapeDefinition&,Vec3 accumulated={});
Summary summarize(const Shape&) noexcept;
struct Registration { EntityId actor; std::uint16_t source_mask{}, collision_class{}; };
struct SolveReport { std::uint32_t visited{}, candidates{}, contacts{}; };
// Single-owner per-update registration. Actor state remains owned by the native
// actor store; no borrowed actor/joint reference survives solve().
class Registry {
public:
    bool add(Registration);
    void clear()noexcept{for(std::size_t i=0;i<count_;++i)registrations_[i]={};count_=0;}
    std::size_t size()const noexcept{return count_;}
    SolveReport solve(std::span<Actor>,bool limit_repeated=false,bool fast_tick=false);
private:
    std::array<Registration,32> registrations_{};
    std::size_t count_{};
};
class AuxiliaryBoundary {
public:
    bool set(std::uint8_t kind,EntityId id)noexcept;
    void clear()noexcept{owner_={};}
    void apply(std::span<Actor>,bool offline,std::uint16_t room,EntityId selected)const noexcept;
private:
    EntityId owner_;
};
}
