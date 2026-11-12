#pragma once
#include "../gameplay_scenario/room_model_assets.hpp"
#include "../gameplay_scenario/scene_models.hpp"
#include "../gameplay_scenario/scenario_archive.hpp"

namespace reo::native::gameplay_application {
// The saved pose bank has application lifetime. Current poses remain solely
// in the active room's existing SceneModels; asset definitions are immutable.
class RoomModels final {
public:
    RoomModels()noexcept;
    gameplay_scenario::SceneModelState cold_state()const noexcept;
    bool current(gameplay_scenario::content::RoomId)const noexcept;
    const std::shared_ptr<const gameplay_scenario::RoomModelAsset>& asset()const noexcept{return asset_;}
    gameplay_scenario::SceneModelState prepare(gameplay_scenario::content::RoomId,
        const gameplay_scenario::RoomModelAsset&,const gameplay_scenario::SceneModelState&)const noexcept;
    bool commit(gameplay_scenario::content::RoomId,std::shared_ptr<const gameplay_scenario::RoomModelAsset>)noexcept;
    //5D7D60 pose/style subproducer only. Matrix channels, bindings, camera and
    // other reset side effects remain their existing concrete owners' work.
    void restore_poses_and_styles(gameplay_scenario::SceneModels&)const noexcept;
    const std::array<animation::Matrix,128>& saved()const noexcept{return saved_;}
    const std::array<gameplay_scenario::RoomModelGroup,24>& groups()const noexcept{return groups_;}
private:
    std::array<animation::Matrix,128> saved_{};
    std::array<gameplay_scenario::RoomModelGroup,24> groups_{};
    std::optional<gameplay_scenario::content::RoomId> room_;
    std::shared_ptr<const gameplay_scenario::RoomModelAsset> asset_;
};
}
