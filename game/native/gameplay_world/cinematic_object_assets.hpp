#pragma once
#include "../animation/model.hpp"
#include "../gameplay_scenario/scenario_archive.hpp"
#include "../gameplay_scenario/cutscene_cues.hpp"
#include <map>
#include <mutex>
#include <string>
#include <string_view>
namespace reo::native::gameplay_world {
class CinematicObjectAsset final {
public:
    static std::shared_ptr<const CinematicObjectAsset> import(std::string,
        gameplay_scenario::content::Bytes);
    std::string_view name()const noexcept{return name_;}
    std::span<const std::byte> bytes()const noexcept{return *bytes_;}
    std::uint16_t parts()const noexcept{return parts_;}
    std::uint16_t materials()const noexcept{return materials_;}
    const std::shared_ptr<const animation::Skeleton>& skeleton()const noexcept{return skeleton_;}
    std::span<const animation::Matrix> inverse_bind_pose()const noexcept{return inverse_bind_pose_;}
    std::shared_ptr<animation::Instance> make_instance()const;
    // Applicable only to verified cold construction. Material indices0..N-1
    // leave source slots30..35 zero for N<=30; no live work buffer is retained.
    std::optional<animation::Vector> cold_attachment_scale()const noexcept{
        return materials_<=30?std::optional<animation::Vector>{{0,0,0}}:std::nullopt;
    }
private:
    CinematicObjectAsset()=default;
    std::string name_;gameplay_scenario::content::Bytes bytes_;
    std::shared_ptr<const animation::Skeleton> skeleton_;
    std::vector<animation::Matrix> inverse_bind_pose_;
    std::uint16_t parts_{},materials_{};
};
// Read/prepare off the simulation invocation. Destination scenario and scene
// request are distinct identities; this owner does not mutate World or clocks.
class CinematicObjectAssets final {
public:
    explicit CinematicObjectAssets(std::shared_ptr<const gameplay_scenario::content::ScenarioArchive>);
    static std::string model_name(gameplay_scenario::CutsceneCue,std::uint32_t model);
    std::shared_ptr<const CinematicObjectAsset> read(std::uint16_t destination,
        gameplay_scenario::CutsceneCue,std::uint32_t model)const;
private:
    std::shared_ptr<const gameplay_scenario::content::ScenarioArchive> archive_;
    mutable std::mutex mutex_;
    mutable std::map<std::pair<std::uint16_t,std::string>,std::shared_ptr<const CinematicObjectAsset>> cache_;
};
}
