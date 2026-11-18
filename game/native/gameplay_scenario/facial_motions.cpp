#include "facial_motions.hpp"
#include "cutscene_playback.hpp"
#include "../animation/model.hpp"
#include <cstring>
#include <stdexcept>
namespace reo::native::gameplay_scenario {
namespace {
struct Reset {bool& value;~Reset(){value=false;}};
template<class T>T field(std::span<const std::byte> data,std::size_t at){
    if(at>data.size()||sizeof(T)>data.size()-at)throw std::out_of_range("Native facial asset field unavailable");
    T value;std::memcpy(&value,data.data()+at,sizeof value);return value;
}
}
FacialMotions::FacialMotions(gameplay_world::World& world,CutscenePlaybackState& state,std::shared_ptr<const File1FacialAssets> assets)
    :world_(world),state_(state),assets_(std::move(assets)){
    if(world.closed()||world.busy()||!assets_)throw std::invalid_argument("Native facial owner unavailable");
    //1BAEC0 clears the allocated slice.67C250 separately initializes its
    // bookkeeping and6000 LIP cursor at the actual scene-entry position.
}
FacialMotions::~FacialMotions(){if(running_)std::terminate();}
bool FacialMotions::bound_to(const gameplay_world::World& world,const CutscenePlaybackState& state)const noexcept{return &world_==&world&&&state_==&state;}
FacialStatus FacialMotions::admission(bool allow_world_busy)const noexcept{
    if(running_||(!allow_world_busy&&world_.busy()))return FacialStatus::busy;
    if(world_.closed())return FacialStatus::closed;
    if(!controller_||controller_->facial_motions()!=this)return FacialStatus::unavailable;
    return FacialStatus::completed;
}
FacialStatus FacialMotions::reset()noexcept{
    const auto status=admission();if(status!=FacialStatus::completed)return status;
    matrices_={};lips_={};instances_={};matrix_count_=lip_count_=0;lip_end_=0x6000;initialized_=true;
    return FacialStatus::completed;
}
void FacialMotions::copy_asset(std::size_t at,const FacialAssetBytes& asset){
    if(!asset.storage)return;
    if(at>workspace_.size()||asset.storage->size()>workspace_.size()-at)throw std::out_of_range("Native facial workspace profile exceeded");
    std::copy(asset.storage->begin(),asset.storage->end(),workspace_.begin()+at);
}
FacialLoaded FacialMotions::load(gameplay_actors::EntityId actor_id,std::uint16_t cue,std::uint16_t voice,std::uint16_t facial)noexcept{
    FacialLoaded result;result.status=admission();if(result.status!=FacialStatus::completed)return result;
    if(!initialized_){result.status=FacialStatus::unavailable;return result;}
    auto actor=world_.resolve(actor_id);if(!actor){result.status=FacialStatus::unavailable;return result;}
    running_=true;Reset reset{running_};
    try{
        // The literal source flag accumulates ANY mismatch, rather than
        // conventional deduplication against one matching key.
        bool reload=matrix_count_==0;
        for(std::size_t index=0;index<matrix_count_;++index)if(matrices_[index].actor!=actor_id||matrices_[index].facial!=facial)reload=true;
        if(actor->category>1){result.status=FacialStatus::unavailable;return result;}
        if(actor->model_pose_class!=1)return result;
        const auto kind=actor->category?FacialMatrixKind::npc:FacialMatrixKind::player;
        const auto character=actor->category?actor->model_variant:actor->character;
        const auto speaker=actor->category?0u:std::uint32_t(actor->character)+1u;
        if(reload){
            if(matrix_count_>=matrices_.size()){result.status=FacialStatus::unavailable;return result;}
            const auto asset=assets_->matrix(kind,character);copy_asset(matrix_count_*3072,asset);result.matrix_loaded=bool(asset.storage);
            matrices_[matrix_count_++]={std::uint8_t(facial),actor_id};
        }
        // The source warns then continues when the32-entry record bank is
        // exhausted, aliasing its count word. This out-of-profile route refuses.
        if(lip_count_>=lips_.size()||!world_.session().scenario){result.status=FacialStatus::unavailable;return result;}
        const auto asset=assets_->lip(*world_.session().scenario,cue,voice,speaker);copy_asset(lip_end_,asset);result.lip_loaded=bool(asset.storage);
        lips_[lip_count_++]={lip_end_,cue,voice};if(asset.storage)lip_end_+=asset.storage->size();
        return result;
    }catch(const std::bad_alloc&){result.status=FacialStatus::no_memory;return result;}catch(...){result.status=FacialStatus::unavailable;return result;}
}
FacialClaimed FacialMotions::claim(gameplay_actors::EntityId actor_id,std::uint16_t facial,std::uint16_t cue,std::uint16_t voice)noexcept{
    FacialClaimed result;result.status=admission(true);if(result.status!=FacialStatus::completed)return result;
    if(!initialized_||!world_.resolve(actor_id)){result.status=FacialStatus::unavailable;return result;}
    try{for(std::size_t slot=0;slot<instances_.size();++slot){
        auto& instance=instances_[slot];if(instance.cursor.active)continue;
        for(std::size_t index=0;index<matrix_count_;++index)if(matrices_[index].actor==actor_id&&matrices_[index].facial==facial){instance.matrix=std::uint8_t(index);break;}
        for(std::size_t index=0;index<lip_count_;++index)if(lips_[index].cue==cue&&lips_[index].voice==voice){
            for(unsigned channel=0;channel<5;++channel)instance.origins[channel]=lips_[index].offset+field<std::uint32_t>(workspace_,lips_[index].offset+channel*4);
            instance.cursor.positions={};break;
        }
        instance.cursor.active=true;instance.cursor.frame=0;instance.actor=actor_id;result.slot=slot;return result;
    }return result;}catch(...){result.status=FacialStatus::unavailable;return result;}
}
std::shared_ptr<const animation::FacialCurves> FacialMotions::curves(const FacialInstance& instance)const{
    // Preserve the five pointers fixed at claim time. Values remain live in
    // the original retained asset workspace even if a later load overwrites
    // bytes; import does not silently retain an obsolete clip copy.
    std::vector<std::byte> data(20);
    for(unsigned channel=0;channel<5;++channel){
        const auto offset=std::uint32_t(data.size());std::memcpy(data.data()+channel*4,&offset,4);
        auto at=instance.origins[channel];
        for(;;){const auto frame=field<std::int32_t>(workspace_,at);(void)field<float>(workspace_,at+4);
            data.insert(data.end(),workspace_.begin()+at,workspace_.begin()+at+8);at+=8;if(frame<0)break;
        }
    }
    return animation::FacialCurves::import(data);
}
FacialUpdated FacialMotions::tick()noexcept{
    FacialUpdated result;result.status=admission();if(result.status!=FacialStatus::completed)return result;
    running_=true;Reset reset{running_};
    try{for(auto& instance:instances_){
        if(!instance.cursor.active)continue;
        ++result.visited;
        const auto step=animation::advance_facial_curves(instance.cursor,*curves(instance));
        if(step.stop_batch){instance.actor={};result.stopped=true;return result;}
        ++result.sampled;auto actor=world_.resolve(instance.actor);
        if(!actor||!actor->model){result.status=FacialStatus::unavailable;return result;}
        const auto tracks=actor->model->track_ids();std::size_t ordinal{};
        std::vector<animation::JointPosePatch> patches;
        for(std::size_t node=0;node<tracks.size();++node)if(tracks[node]==4){
            if(ordinal>=8){result.status=FacialStatus::unavailable;return result;}
            animation::FacialMatrices matrices;
            for(unsigned pose=0;pose<6;++pose)matrices[pose]=field<transform_math::Matrix>(workspace_,std::size_t(instance.matrix)*3072+pose*512+ordinal*64);
            patches.push_back({node,animation::blend_facial_pose(matrices,*step.weights)});++ordinal;
        }
        actor->model->patch_world_poses(patches);result.patched+=patches.size();
    }return result;}catch(const std::bad_alloc&){result.status=FacialStatus::no_memory;return result;}catch(...){result.status=FacialStatus::unavailable;return result;}
}
} // namespace reo::native::gameplay_scenario
