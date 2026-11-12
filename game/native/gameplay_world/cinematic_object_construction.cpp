#include "cinematic_object_construction.hpp"
#include <algorithm>
#include <cstring>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
template<class T>T read(std::span<const std::byte> bytes,unsigned at){T result;std::memcpy(&result,bytes.data()+at,sizeof result);return result;}
bool cold(const CinematicObject& value){
    return !value.active&&!value.visible&&!value.reserved&&!value.phase&&!value.animation_phase&&
        !value.model&&!value.model_asset&&!value.pose&&!value.motion&&!value.flags&&!value.authored_model&&
        value.position.x==0&&value.position.y==0&&value.position.z==0&&value.angles==transform_math::Angles{}&&
        value.basis==animation::Matrix{}&&value.part_visibility==std::array<std::uint8_t,8>{}&&
        value.timing.frame==0&&value.timing.end==0&&value.timing.restart==0&&!value.timing.loop&&!value.timing.flags;
}
}
std::shared_ptr<const PreparedCinematicObjects> CinematicObjectConstruction::prepare(
    const gameplay_scenario::CutsceneDescriptor& descriptor,gameplay_scenario::CutsceneCue request,const CinematicObjectAssets& assets){
    const auto& groups=descriptor.object_groups();
    if(groups.size()>CinematicObjectPool::capacity)throw std::out_of_range("Native cinematic object construction group capacity unavailable");
    auto result=std::shared_ptr<PreparedCinematicObjects>(new PreparedCinematicObjects);result->entries_.reserve(groups.size());
    for(const auto& group:groups){
        const auto header=descriptor.section(group[2]);
        if(header.size()<36||read<std::uint16_t>(header,2)==65535)throw std::invalid_argument("Native cinematic object sparse/absent header profile unavailable");
        PreparedCinematicObjects::Entry entry;entry.motion=read<std::uint32_t>(header,4);entry.model=read<std::uint32_t>(header,8);
        entry.asset=assets.read(descriptor.identity()[0],request,entry.model);
        if(!entry.asset)throw std::invalid_argument("Native cinematic object required named asset unavailable: "+CinematicObjectAssets::model_name(request,entry.model));
        if(!entry.asset->cold_attachment_scale())throw std::invalid_argument("Native cinematic object cold material profile unavailable");
        for(unsigned stream=0;stream<7;++stream)entry.streams[stream]=gameplay_scenario::CutsceneActorStream::import(descriptor.section(group[stream]));
        result->entries_.push_back(std::move(entry));
    }
    return result;
}
std::vector<gameplay_scenario::CutsceneObjectTrackGroup> PreparedCinematicObjects::tracks(
    std::span<const gameplay_scenario::CutsceneObjectBinding> bindings)const{
    if(bindings.size()!=entries_.size())throw std::invalid_argument("Native cinematic object prepared bindings unavailable");
    std::vector<gameplay_scenario::CutsceneObjectTrackGroup> result;result.reserve(entries_.size());
    for(unsigned group=0;group<entries_.size();++group){
        gameplay_scenario::CutsceneObjectTrackGroup next;static_cast<gameplay_scenario::CutsceneObjectBinding&>(next)=bindings[group];
        next.streams=entries_[group].streams;result.push_back(std::move(next));
    }
    return result;
}
CinematicObjectsConstructed CinematicObjectConstruction::create(const PreparedCinematicObjects& prepared)noexcept{
    if(world_.closed())return{CinematicObjectStatus::closed,{},0};
    if(world_.busy())return{CinematicObjectStatus::busy,{},0};
    CinematicObjectsConstructed result;
    try{
        auto& pool=world_.cinematic_objects();
        if(!pool.initialized()){result.status=CinematicObjectStatus::uninitialized;return result;}
        for(unsigned slot=0;slot<CinematicObjectPool::capacity;++slot){const auto value=pool.resolve(pool.identity_at(slot));if(!value||!cold(*value))return result;}
        result.bindings.reserve(prepared.size());
        pool.running_=world_.updating_=true;
        struct Reset{bool& a;bool& b;~Reset(){b=false;a=false;}}reset{pool.running_,world_.updating_};
        // Source reserves every requested record before constructing any model.
        for(const auto& entry:prepared.entries_){
            const auto reserved=pool.reserve_locked();if(reserved.status!=CinematicObjectStatus::completed){result.status=reserved.status;return result;}
            const auto value=pool.resolve(reserved.id);value->motion=entry.motion;value->authored_model=entry.model;
            result.bindings.push_back({reserved.id,entry.asset->cold_attachment_scale()});
        }
        for(unsigned group=0;group<prepared.size();++group){
            const auto value=pool.resolve(result.bindings[group].object);const auto& entry=prepared.entries_[group];
            value->model=entry.asset->make_instance();value->model_asset=entry.asset;
            std::fill(value->part_visibility.begin(),value->part_visibility.end(),1);++result.constructed;
        }
        result.status=CinematicObjectStatus::completed;return result;
    }catch(const std::bad_alloc&){result.status=CinematicObjectStatus::no_memory;return result;}
    catch(...){return result;}
}
}
