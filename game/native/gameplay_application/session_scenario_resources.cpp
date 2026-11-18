#include "session_scenario_resources.hpp"
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <new>
namespace reo::native::gameplay_application {
namespace {
constexpr std::size_t epp_capacity=0x10000,door_capacity=0x4000,rtp_capacity=0xc000,admission_size=0x80;
template<class T>T read(const std::byte* bytes,std::size_t at){T result;std::memcpy(&result,bytes+at,sizeof result);return result;}
bool scenario_profile(const gameplay_world::World& world)noexcept{
    if(!world.scenario||!world.session().asset_loading_mode||!*world.session().asset_loading_mode)return false;
    switch(*world.scenario){case 1:case 2:case 28:case 35:case 41:return true;default:return false;}
}
}
SessionScenarioResources::SessionScenarioResources(gameplay_world::World& world,const gameplay_scenario::content::ScenarioArchive& archive)noexcept:
    world_(world),archive_(archive){}
SessionScenarioResources::~SessionScenarioResources(){if(close()==ScenarioDataStatus::busy)std::terminate();}
bool SessionScenarioResources::bound_to(const gameplay_world::World& world)const noexcept{return &world==&world_&&!closed_&&!world_.closed();}
ScenarioDataStatus SessionScenarioResources::initialize()noexcept{
    if(closed_||world_.closed())return ScenarioDataStatus::closed;
    if(running_||world_.busy())return ScenarioDataStatus::busy;
    if(initialized_)return ScenarioDataStatus::unavailable;
    try{if(!epp_)epp_=std::make_unique_for_overwrite<std::byte[]>(epp_capacity);
        if(!door_)door_=std::make_unique_for_overwrite<std::byte[]>(door_capacity);
        if(!rtp_)rtp_=std::make_unique_for_overwrite<std::byte[]>(rtp_capacity);
        initialized_=true;return ScenarioDataStatus::completed;
    }catch(const std::bad_alloc&){return ScenarioDataStatus::no_memory;}
}
ScenarioDataStatus SessionScenarioResources::load_placements()noexcept{
    if(closed_||world_.closed())return ScenarioDataStatus::closed;
    if(running_)return ScenarioDataStatus::busy;
    if(!initialized_||!scenario_profile(world_))return ScenarioDataStatus::unavailable;
    running_=true;struct Guard{bool& flag;~Guard(){flag=false;}}guard{running_};
    try{char name[24];const int length=std::snprintf(name,sizeof name,"r%02u.epp",unsigned(*world_.scenario));
        if(length<0||std::size_t(length)>=sizeof name)return ScenarioDataStatus::unavailable;
        const auto data=archive_.read_resource_sectors(*world_.scenario,name);
        if(world_.closed())return ScenarioDataStatus::closed;
        if(!data){epp_[0]=std::byte{0xff};epp_known_=std::max<std::size_t>(epp_known_,1);return ScenarioDataStatus::completed;}
        if(data->size()>epp_capacity)return ScenarioDataStatus::invalid_asset;
        std::memcpy(epp_.get(),data->data(),data->size());epp_known_=std::max(epp_known_,data->size());return ScenarioDataStatus::completed;
    }catch(const std::bad_alloc&){return ScenarioDataStatus::no_memory;}
    catch(...){return ScenarioDataStatus::unavailable;}
}
EnemyPlacementResult SessionScenarioResources::placement(std::uint16_t room,std::uint16_t variant,std::uint16_t index)const noexcept{
    if(closed_||world_.closed())return{ScenarioDataStatus::closed,{}};
    if(running_)return{ScenarioDataStatus::busy,{}};
    if(!initialized_||!epp_known_)return{};
    std::size_t cursor{};
    while(cursor<epp_known_){
        const auto key=std::to_integer<std::uint8_t>(epp_[cursor]);if(key==255)return{ScenarioDataStatus::completed,{}};
        if(epp_known_-cursor<8)return{ScenarioDataStatus::invalid_asset,{}};
        if(key==room&&std::to_integer<std::uint8_t>(epp_[cursor+1])==variant){
            const auto base=std::size_t(read<std::uint16_t>(epp_.get(),cursor+4));const auto at=base+std::size_t(index)*20;
            if(at>epp_known_||epp_known_-at<20)return{ScenarioDataStatus::invalid_asset,{}};
            EnemyPlacement result;result.field0=read<std::uint16_t>(epp_.get(),at);result.yaw=read<std::uint16_t>(epp_.get(),at+2);
            for(unsigned lane=0;lane<3;++lane)result.position[lane]=read<std::int32_t>(epp_.get(),at+4+4*lane);
            result.field16=read<std::uint32_t>(epp_.get(),at+16);return{ScenarioDataStatus::completed,result};
        }cursor+=8;
    }
    return{ScenarioDataStatus::invalid_asset,{}};
}
ScenarioDataStatus SessionScenarioResources::load_doors()noexcept{
    if(closed_||world_.closed())return ScenarioDataStatus::closed;
    if(running_)return ScenarioDataStatus::busy;
    if(!initialized_||!scenario_profile(world_))return ScenarioDataStatus::unavailable;
    running_=true;struct Guard{bool& flag;~Guard(){flag=false;}}guard{running_};
    std::memset(door_.get(),0,door_capacity);doors_ready_=false;door_group_end_=door_admission_=door_metadata_=0;
    try{char name[24];const int length=std::snprintf(name,sizeof name,"door%03u.dat",unsigned(*world_.scenario));
        if(length<0||std::size_t(length)>=sizeof name)return ScenarioDataStatus::unavailable;
        const auto data=archive_.read_resource_sectors(*world_.scenario,name);const std::size_t bytes=data?data->size():0;
        if(world_.closed())return ScenarioDataStatus::closed;
        if(bytes>door_capacity-admission_size)return ScenarioDataStatus::invalid_asset;
        if(data)std::memcpy(door_.get(),data->data(),bytes);
        const auto group_length=std::size_t(read<std::uint32_t>(door_.get(),0));door_metadata_=read<std::uint32_t>(door_.get(),4);
        if(group_length>door_capacity-16)return ScenarioDataStatus::invalid_asset;
        door_group_end_=16+group_length;door_admission_=bytes;std::memset(door_.get()+door_admission_,0,admission_size);doors_ready_=true;
        return ScenarioDataStatus::completed;
    }catch(const std::bad_alloc&){return ScenarioDataStatus::no_memory;}
    catch(...){return ScenarioDataStatus::unavailable;}
}
ScenarioDataStatus SessionScenarioResources::reset_positions()noexcept{
    if(closed_||world_.closed())return ScenarioDataStatus::closed;
    if(running_)return ScenarioDataStatus::busy;
    if(!initialized_)return ScenarioDataStatus::unavailable;
    positions_={};positions_ready_=true;return ScenarioDataStatus::completed;
}
ScenarioDataStatus SessionScenarioResources::load_return_points()noexcept{
    if(closed_||world_.closed())return ScenarioDataStatus::closed;
    if(running_)return ScenarioDataStatus::busy;
    if(!initialized_||!scenario_profile(world_))return ScenarioDataStatus::unavailable;
    running_=true;struct Guard{bool& flag;~Guard(){flag=false;}}guard{running_};
    try{
        char name[24];const int length=std::snprintf(name,sizeof name,"r%02u.rtp",unsigned(*world_.scenario));
        if(length<0||std::size_t(length)>=sizeof name)return ScenarioDataStatus::unavailable;
        const auto data=archive_.read_resource_sectors(*world_.scenario,name);
        if(world_.closed())return ScenarioDataStatus::closed;
        if(!data)return ScenarioDataStatus::completed;
        if(data->size()>rtp_capacity)return ScenarioDataStatus::invalid_asset;
        std::memcpy(rtp_.get(),data->data(),data->size());rtp_known_=std::max(rtp_known_,data->size());
        // A malformed replacement must not expose stale parsed old content.
        // Existing callers holding an immutable old publication keep its lease.
        return_points_.reset();
        return_points_=gameplay_scenario::RoomReturnPoints::import(std::span<const std::byte>(rtp_.get(),rtp_known_));
        return ScenarioDataStatus::completed;
    }catch(const std::bad_alloc&){return ScenarioDataStatus::no_memory;}
    catch(const std::invalid_argument&){return ScenarioDataStatus::invalid_asset;}
    catch(...){return ScenarioDataStatus::unavailable;}
}
std::optional<DoorRecordView> SessionScenarioResources::doors()const noexcept{
    if(!ready()||running_||!doors_ready_)return{};
    return DoorRecordView{std::span<const std::byte>(door_.get()+16,door_group_end_-16),door_metadata_,
        std::span<const std::byte>(door_.get()+door_admission_,admission_size)};
}
std::span<const DoorPositionRecord> SessionScenarioResources::positions()const noexcept{
    if(!ready()||running_||!positions_ready_)return{};return positions_;
}
ScenarioDataStatus SessionScenarioResources::close()noexcept{
    if(closed_)return ScenarioDataStatus::completed;
    if(running_||world_.busy())return ScenarioDataStatus::busy;
    epp_.reset();door_.reset();rtp_.reset();return_points_.reset();rtp_known_=epp_known_=door_group_end_=door_admission_=0;initialized_=positions_ready_=doors_ready_=false;closed_=true;return ScenarioDataStatus::completed;
}
}
