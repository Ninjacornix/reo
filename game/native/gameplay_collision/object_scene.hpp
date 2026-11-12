#pragma once
#include "object_lifetime.hpp"
namespace reo::native::gameplay_collision::room_objects {
enum class SceneStatus {complete,closed,already_started,unavailable_owner,stale_lifetime,construction_refused,dynamic_refused};
struct SceneResult {
    SceneStatus status{SceneStatus::complete};
    std::size_t visited{},selected{},constructed{};
    InstanceResult last{};
};
// Actual6AD4E0 outer caller. This composes the existing6ADAB0 instance and
//6AEE20 dynamic consumers against their one canonical object/scene/model graph.
// Borrowed state and initial model poses must be established by real producers.
class Scene final {
public:
    Scene(Owner&,gameplay_actors::EntityStore&,ownership::Proxies&,ModelBindings&,
          const response::Grid&,const response::Grid&);
    SceneResult initialize(std::uint16_t room,response::Filter);
    InstanceStatus close()noexcept;
    InteractionOwner::Lifetime& lifetime()noexcept{return lifetime_;}
    const room_geometry::Dynamic& dynamic()const noexcept{return lifetime_.dynamic();}
    std::uint8_t count()const noexcept{return count_;}
    bool open()const noexcept{return !closed_;}
private:
    Owner& objects_;
    InteractionOwner interactions_;
    InteractionOwner::Lifetime lifetime_;
    std::uint8_t count_{};
    bool started_{},closed_{};
};
}
