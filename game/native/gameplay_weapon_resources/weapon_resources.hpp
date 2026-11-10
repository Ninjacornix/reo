#pragma once
#include "../animation/weapon_program.hpp"
#include "../gameplay_world/world.hpp"
#include "../gameplay_scenario/scene_resources.hpp"
#include "../gameplay_scenario/resource_templates.hpp"
#include "../gameplay_bank_loading/loader.hpp"
namespace reo::native::gameplay_world {class ResourceDepletion;}
namespace reo::native::gameplay_weapon_resources {
// Prepared before gameplay from the actual File1 ROM archive. Its sixteen
// immutable banks are shared by native actors; changing equipment does no I/O.
class Catalogue final {
public:
    static std::shared_ptr<const Catalogue> prepare_file1_rom(std::shared_ptr<const afs_source_range::Archive>);
    std::shared_ptr<const animation::WeaponProgramBank> find(std::int8_t)const noexcept;
    const std::shared_ptr<const animation::WeaponProgramBank>& cleared()const noexcept{return cleared_;}
private:
    Catalogue()=default;
    std::array<std::shared_ptr<const animation::WeaponProgramBank>,128> banks_;
    std::shared_ptr<const animation::WeaponProgramBank> cleared_;
};
enum class Status {completed,unavailable,foreign_or_stale,closed};
struct Refreshed {
    Status status{Status::unavailable};
    bool programs_changed{};
    std::optional<gameplay_bank_loading::Submitted> audio;
};
// Concrete1D3B00/6B4AE0 composition: native immutable WMD binding plus actual
// bounded named-bank enqueue. No blocking read/decode occurs in refresh().
class Owner final {
public:
    Owner(gameplay_world::World&,gameplay_scenario::SceneResources&,
        const gameplay_scenario::ResourceTemplates&,std::shared_ptr<const Catalogue>,
        std::shared_ptr<gameplay_audio::Owner>,gameplay_bank_loading::Loader&);
    bool bound_to(const gameplay_world::World&,const gameplay_scenario::SceneResources&,
        const gameplay_scenario::ResourceTemplates&)const noexcept;
    Refreshed refresh(const gameplay_actors::EntityId&)noexcept;
private:
    friend class gameplay_world::ResourceDepletion;
    gameplay_world::World& world_;
    gameplay_scenario::SceneResources& resources_;
    const gameplay_scenario::ResourceTemplates& templates_;
    std::shared_ptr<const Catalogue> catalogue_;
    std::shared_ptr<gameplay_audio::Owner> audio_;
    gameplay_bank_loading::Loader& loader_;
};
}
