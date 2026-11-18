#include "room_models.hpp"
namespace reo::native::gameplay_application {
RoomModels::RoomModels()noexcept{
    //5EAEB0 clears the full49EEF0..+6D40 bank before5D7D60. This explicit
    // cold producer establishes zero saved poses/group bytes, never identities.
    for(auto& group:groups_)group.control=0;
    //5EAEB0:5EB078..088 clears the request cache toFF. No asset is loaded.
}
gameplay_scenario::SceneModelState RoomModels::cold_state()const noexcept{
    gameplay_scenario::SceneModelState result;result.poses=saved_;result.styles.fill(0xffffffffu);return result;
}
bool RoomModels::current(gameplay_scenario::content::RoomId id)const noexcept{
    return installed_room_&&installed_room_->scenario==std::uint8_t(id.scenario)&&installed_room_->room==std::uint8_t(id.room)&&installed_room_->variant==std::uint8_t(id.variant);
}
void RoomModels::publish_requested(gameplay_scenario::content::RoomId id)noexcept{
    requested_={std::uint8_t(id.scenario),std::uint8_t(id.room),std::uint8_t(id.variant)};
}
bool RoomModels::requested(gameplay_scenario::content::RoomId id)const noexcept{
    return requested_==std::array<std::uint8_t,3>{std::uint8_t(id.scenario),std::uint8_t(id.room),std::uint8_t(id.variant)};
}
gameplay_scenario::SceneModelState RoomModels::prepare(gameplay_scenario::content::RoomId id,
    const gameplay_scenario::RoomModelAsset& asset,const gameplay_scenario::SceneModelState& current_models)const noexcept{
    auto result=current_models;if(current(id))return result;
    for(const auto& pose:asset.poses())result.poses[pose.slot]=pose.matrix;
    // Actual1D0A70/1AA4C0 tail publishes each loaded physical part's byte1.
    for(unsigned i=0;i<asset.parts();++i)result.visibility[i]=1;
    return result;
}
bool RoomModels::commit(gameplay_scenario::content::RoomId id,
    std::shared_ptr<const gameplay_scenario::RoomModelAsset> asset)noexcept{
    if(!asset)return false;
    if(current(id))return true;
    for(const auto& pose:asset->poses())saved_[pose.slot]=pose.matrix;
    for(std::size_t i=0;i<asset->groups().size();++i){
        const auto& source=asset->groups()[i];auto& target=groups_[i];target.first_model=source.first_model;
        target.models=source.models;target.origin=source.origin;if(source.control)target.control=source.control;
    }
    installed_room_=gameplay_scenario::content::RoomId{std::uint8_t(id.scenario),std::uint8_t(id.room),std::uint8_t(id.variant)};
    asset_=std::move(asset);return true;
}
void RoomModels::restore_poses_and_styles(gameplay_scenario::SceneModels& models)const noexcept{
    for(unsigned i=0;i<128;++i)(void)models.pose(i,saved_[i]);
    models.reset_styles();
}
}
