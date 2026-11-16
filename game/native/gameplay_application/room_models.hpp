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
    //7434B0 is a request cache, published before loads by5EBE30. It does
    // not establish installed asset provenance after an interrupted load.
    const std::array<std::uint8_t,3>& requested()const noexcept{return requested_;}
    void publish_requested(gameplay_scenario::content::RoomId)noexcept;
    void invalidate_requested()noexcept{requested_.fill(255);} //5EBDB0
    bool requested(gameplay_scenario::content::RoomId)const noexcept;
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
    std::array<std::uint8_t,3> requested_{255,255,255};
    std::optional<gameplay_scenario::content::RoomId> installed_room_;
    std::shared_ptr<const gameplay_scenario::RoomModelAsset> asset_;
};
}
