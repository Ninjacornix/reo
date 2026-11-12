#include "cinematic_objects.hpp"
#include "../animation/motion_bank.hpp"
#include <bit>
#include <cmath>
#include <cstring>
#include <new>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
template<class T>T pose_read(std::span<const std::byte> bytes,unsigned at){T value;std::memcpy(&value,bytes.data()+at,sizeof value);return value;}
float finite(float value){if(!std::isfinite(value))throw std::domain_error("Native cinematic object finite pose required");return value;}
std::uint16_t turn(float degrees){
    const float product=finite(65536.f*degrees),scaled=finite(product/360.f),value=finite(.5f+scaled);
    const float reduced=value>=2147483648.f?finite(value-2147483648.f):value;
    if(reduced< -2147483648.f||reduced>=2147483648.f)throw std::out_of_range("Native cinematic object turn conversion outside admitted range");
    return std::uint16_t(std::uint32_t(std::int32_t(std::trunc(reduced))));
}
float lerp(float first,float last,float t){const float delta=finite(last-first),product=finite(delta*t);return finite(first+product);}
float bezier(float first,float control,float last,float t){const auto left=lerp(first,control,t),right=lerp(control,last,t);return lerp(left,right,t);}
}
CinematicObjectPose CinematicObjectPose::read(std::span<const std::byte> bytes){
    if(bytes.size()<40)throw std::invalid_argument("Native cinematic object pose requires next record header");
    CinematicObjectPose result;result.start=pose_read<std::uint16_t>(bytes,2);result.end=pose_read<std::uint16_t>(bytes,38);
    result.first=pose_read<animation::Vector>(bytes,4);result.first_degrees=pose_read<std::array<std::int16_t,3>>(bytes,16);
    if(result.end!=65535){
        if(bytes.size()<58)throw std::invalid_argument("Native cinematic object pose requires next key values");
        result.control=pose_read<animation::Vector>(bytes,24);result.last=pose_read<animation::Vector>(bytes,40);
        result.last_degrees=pose_read<std::array<std::int16_t,3>>(bytes,52);
    }
    return result;
}
void evaluate_cinematic_object_pose(const CinematicObjectPose& pose,std::int32_t frame,animation::Vector& position,transform_math::Angles& angles){
    if(pose.end==65535){position=pose.first;for(unsigned i=0;i<3;++i)angles[i]=turn(float(pose.first_degrees[i]));return;}
    const auto elapsed=std::bit_cast<std::int32_t>(std::uint32_t(frame)-pose.start);
    const float t=pose.end==pose.start?1.f:finite(float(elapsed)/float(std::int32_t(pose.end)-pose.start));
    position={bezier(pose.first.x,pose.control.x,pose.last.x,t),bezier(pose.first.y,pose.control.y,pose.last.y,t),bezier(pose.first.z,pose.control.z,pose.last.z,t)};
    for(unsigned i=0;i<3;++i){
        float degrees=float(pose.first_degrees[i]);
        if(pose.first_degrees[i]!=pose.last_degrees[i])degrees=lerp(degrees,float(pose.last_degrees[i]),t);
        angles[i]=turn(degrees);
    }
}
CinematicObjectPool& World::cinematic_objects(){
    if(closed_)throw std::runtime_error("Native cinematic object owner is closed");
    if(!cinematic_objects_){if(busy())throw std::runtime_error("Native cinematic object owner creation during update");cinematic_objects_.reset(new CinematicObjectPool(*this));}
    return *cinematic_objects_;
}
CinematicObjectStatus CinematicObjectPool::initialize()noexcept{
    if(closed_||world_.closed())return CinematicObjectStatus::closed;
    if(running_||world_.busy())return CinematicObjectStatus::busy;
    if(world_.paused==0)return CinematicObjectStatus::unchanged;
    running_=world_.updating_=true;
    struct Reset{bool& a;bool& b;~Reset(){b=false;a=false;}}reset{running_,world_.updating_};
    try{
        auto prepared=std::make_unique<Storage>(capacity);std::array<gameplay_scene::RecordId,capacity> ids;
        for(auto& id:ids){const auto made=prepared->create(CinematicObject{},gameplay_scene::Placement::oldest);if(!made)return CinematicObjectStatus::unavailable;id=*made;}
        pool_.swap(prepared);ids_.swap(ids);return CinematicObjectStatus::completed;
    }catch(const std::bad_alloc&){return CinematicObjectStatus::no_memory;}
}
CinematicObjectReserved CinematicObjectPool::reserve_inactive()noexcept{
    if(closed_||world_.closed())return{CinematicObjectStatus::closed};
    if(running_||world_.busy())return{CinematicObjectStatus::busy};
    if(!pool_)return{};
    running_=world_.updating_=true;
    struct Reset{bool& a;bool& b;~Reset(){b=false;a=false;}}reset{running_,world_.updating_};
    for(unsigned slot=0;slot<capacity;++slot){
        const auto value=resolve(ids_[slot]);if(!value)return{CinematicObjectStatus::unavailable};
        if(value->active||value->reserved)continue;
        value->reserved=true;return{CinematicObjectStatus::completed,std::uint8_t(slot),ids_[slot]};
    }
    return{CinematicObjectStatus::full};
}
CinematicObjectsUpdated CinematicObjectPool::run(const animation::MotionBank& motions,std::int32_t scene_frame){
    if(closed_||world_.closed())return{CinematicObjectStatus::closed};
    if(running_||world_.busy())return{CinematicObjectStatus::busy};
    if(world_.paused==0||!pool_)return{CinematicObjectStatus::unchanged};
    running_=world_.updating_=true;
    struct Reset{bool& a;bool& b;~Reset(){b=false;a=false;}}reset{running_,world_.updating_};
    CinematicObjectsUpdated result;
    for(const auto& id:ids_){
        const auto value=resolve(id);++result.visited;
        if(!value)throw std::runtime_error("Native cinematic object identity unavailable");
        if(!value->active)continue;
        ++result.called;
        if(value->phase==0){value->phase=1;value->basis=transform_math::identity();}
        if(value->phase!=1)continue;
        const auto unavailable=[&]{result.status=CinematicObjectStatus::unavailable;result.failed=id;return result;};
        if(!value->model)return unavailable();
        if(value->flags&1){
            const auto index=200ull*(value->motion/100)+value->motion%100;
            if(index>=animation::MotionBank::capacity)return unavailable();
            const auto block=motions.slots()[std::size_t(index)];if(!block)return unavailable();
            animation::bind_scalar_frame(*value->model,value->timing,block->clip(),0);value->animation_phase=0;
        }
        value->flags^=2;
        if(value->pose)evaluate_cinematic_object_pose(*value->pose,scene_frame,value->position,value->angles);
        value->basis=transform_math::identity();transform_math::compose_euler_axes(value->basis,value->angles);
        value->basis[3][0]+=finite(value->position.x);value->basis[3][1]+=finite(value->position.y);value->basis[3][2]+=finite(value->position.z);
        if(value->flags&4)value->flags^=4;
        if(value->animation_phase==0){if(value->flags&1){value->flags^=1;value->animation_phase=1;}}
        else if(value->animation_phase==1&&animation::advance_scalar_frame(*value->model,value->timing,.5f,world_.session().clock_mode)==1)value->animation_phase=0;
        value->model->rebuild(value->basis);++result.published;
    }
    return result;
}
}
