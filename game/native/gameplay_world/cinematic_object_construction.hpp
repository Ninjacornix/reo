#pragma once
#include "cinematic_object_assets.hpp"
#include "cinematic_objects.hpp"
#include "../gameplay_scenario/cutscene_descriptor.hpp"
namespace reo::native::gameplay_world {
class PreparedCinematicObjects final {
public:
    std::size_t size()const noexcept{return entries_.size();}
    const std::shared_ptr<const CinematicObjectAsset>& asset(std::size_t group)const{return entries_.at(group).asset;}
    std::uint32_t initial_motion(std::size_t group)const{return entries_.at(group).motion;}
    std::uint32_t authored_model(std::size_t group)const{return entries_.at(group).model;}
    std::vector<gameplay_scenario::CutsceneObjectTrackGroup> tracks(
        std::span<const gameplay_scenario::CutsceneObjectBinding>)const;
private:
    friend class CinematicObjectConstruction;
    struct Entry {
        std::shared_ptr<const CinematicObjectAsset> asset;
        std::uint32_t motion{},model{};
        std::array<std::shared_ptr<const gameplay_scenario::CutsceneActorStream>,7> streams;
    };
    std::vector<Entry> entries_;
};
struct CinematicObjectsConstructed {
    CinematicObjectStatus status{CinematicObjectStatus::unavailable};
    std::vector<gameplay_scenario::CutsceneObjectBinding> bindings;
    std::size_t constructed{};
};
// The object portions of5F0610 and5ECF90. CPU preparation is independent of
// renderer submission. Admission requires a fresh initialized object generation;
// a partial result retains its real bindings and requires explicit scene reset.
class CinematicObjectConstruction final {
public:
    explicit CinematicObjectConstruction(World& world)noexcept:world_(world){}
    static std::shared_ptr<const PreparedCinematicObjects> prepare(
        const gameplay_scenario::CutsceneDescriptor&,gameplay_scenario::CutsceneCue,
        const CinematicObjectAssets&);
    CinematicObjectsConstructed create(const PreparedCinematicObjects&)noexcept;
private:World& world_;
};
}
