#pragma once
#include "world.hpp"
#include "../animation/scalar_playback.hpp"
#include "../gameplay_scene/record_pool.hpp"
#include <exception>
namespace reo::native::gameplay_world {
// Two adjacent authored36-byte pose records. Native values retain no relocated
// pointer; the final record may be followed by only its sentinel header.
struct CinematicObjectPose {
    std::uint16_t start{},end{};
    animation::Vector first{},control{},last{};
    std::array<std::int16_t,3> first_degrees{},last_degrees{};
    static CinematicObjectPose read(std::span<const std::byte>);
};
void evaluate_cinematic_object_pose(const CinematicObjectPose&,std::int32_t scene_frame,
                                  animation::Vector&,transform_math::Angles&);
struct CinematicObject {
    static constexpr std::uint8_t category=10;
    bool active{},visible{},reserved{};
    std::uint8_t phase{},animation_phase{};
    animation::Vector position{};
    transform_math::Angles angles{};
    animation::Matrix basis{};
    std::shared_ptr<animation::Instance> model;
    animation::FrameRecord timing;
    std::optional<CinematicObjectPose> pose;
    std::uint32_t motion{},flags{};
};
enum class CinematicObjectStatus {completed,unchanged,busy,closed,uninitialized,full,unavailable,no_memory};
struct CinematicObjectReserved {
    CinematicObjectStatus status{CinematicObjectStatus::uninitialized};
    std::optional<std::uint8_t> slot{};gameplay_scene::RecordId id{};
};
struct CinematicObjectsUpdated {
    CinematicObjectStatus status{CinematicObjectStatus::completed};
    std::size_t visited{},called{},published{};
    gameplay_scene::RecordId failed{};
};
// Distinct fixed sixteen-object571010/571080 domain owned by World. The generic
// generation token is reused; neither Actor storage nor the128 room pool is.
class CinematicObjectPool final {
public:
    static constexpr unsigned capacity=16;
    ~CinematicObjectPool(){if(running_)std::terminate();}
    CinematicObjectPool(const CinematicObjectPool&)=delete;
    CinematicObjectStatus initialize()noexcept;
    //5F1390 reserves the first inactive/unreserved physical record without activation.
    CinematicObjectReserved reserve_inactive()noexcept;
    gameplay_scene::RecordId identity_at(std::size_t slot)const noexcept{return initialized()&&slot<capacity?ids_[slot]:gameplay_scene::RecordId{};}
    std::shared_ptr<CinematicObject> resolve(const gameplay_scene::RecordId& id)const noexcept{
        if(!initialized())return{};
        const auto lease=pool_->acquire(id);return lease?std::shared_ptr<CinematicObject>(lease,&lease->value):nullptr;
    }
    bool initialized()const noexcept{return bool(pool_)&&!closed_&&!world_.closed();}
    CinematicObjectsUpdated run(const animation::MotionBank&,std::int32_t scene_frame);
    CinematicObjectStatus close()noexcept{
        if(running_||(!world_.closed()&&world_.busy()))return CinematicObjectStatus::busy;
        running_=world_.updating_=true;
        struct Reset{bool& a;bool& b;~Reset(){b=false;a=false;}}reset{running_,world_.updating_};
        closed_=true;auto previous=std::move(pool_);ids_.fill({});previous.reset();return CinematicObjectStatus::completed;
    }
private:
    friend class World;
    explicit CinematicObjectPool(World& world)noexcept:world_(world){}
    using Storage=gameplay_scene::RecordPool<CinematicObject>;
    World& world_;std::unique_ptr<Storage> pool_;
    std::array<gameplay_scene::RecordId,capacity> ids_{};
    bool running_{},closed_{};
};
}
