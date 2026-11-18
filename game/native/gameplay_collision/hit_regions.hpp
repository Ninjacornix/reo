#pragma once
#include "spatial.hpp"
#include "../gameplay_actors/hit.hpp"
namespace reo::native::gameplay_collision::hit_regions {
struct Definition {Vec3 offset;float radius{};std::uint32_t joint{};};
std::vector<Definition> import_definitions(std::span<const std::byte>);
enum class Transform {model_joints,actor_basis};
enum class Status {complete,missing_joint,invalid_count};
// Definitions and transformed spheres belong to this native actor component.
// A missing source differs from a present, empty terminated list.
class Regions {
public:
    void set(std::optional<std::vector<Definition>> definitions);
    bool present()const noexcept{return definitions_.has_value();}
    std::span<const Sphere> spheres()const noexcept{return spheres_;}
    Status refresh(Transform,const actors::Basis&,std::span<const actors::Basis> joints);
private:
    std::optional<std::vector<Definition>> definitions_;
    std::vector<Sphere> spheres_;
};
struct ContactState {std::uint8_t cooldown{},priority{},serial{};};
class Queue {
public:
    bool add(gameplay_actors::EntityId)noexcept;
    void clear()noexcept{for(std::size_t i=0;i<count_;++i)entries_[i]={};count_=0;}
    std::span<const gameplay_actors::EntityId> entries()const noexcept{return{entries_.data(),count_};}
private:
    std::array<gameplay_actors::EntityId,64> entries_{};
    std::size_t count_{};
};
// Caller owns actor eligibility, traversal order and global queue reset.
// Cooldown suppresses enrollment, never the independently scheduled pose refresh.
bool prepare_hit(gameplay_actors::HitActor&,ContactState&,gameplay_actors::EntityId,
                 bool definitions_present,Queue&)noexcept;
}
