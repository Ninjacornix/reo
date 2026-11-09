#pragma once
#include "../gameplay_actors/entity.hpp"
#include "../transform_math/transform_math.hpp"
#include <memory>
#include <optional>
namespace reo::native::gameplay_session {class Random;}
namespace reo::native::gameplay_effects {
enum class WorkUpdate {ordinary,oriented,scaled};
struct WorkRequest {
    std::optional<transform_math::Matrix> basis;
    std::optional<transform_math::Vector> position;
    std::int16_t variant{};
    std::uint16_t effect{};
    std::uint32_t child_mask{},flags{0x1a193};
    WorkUpdate update{WorkUpdate::ordinary};
};
// A retained invocation lease keeps storage alive; each mutation must also
// verify that its exact generation remains active in the canonical owner.
// This interface does not itself supply a visual constructor or allocate pools.
class WorkEdit {
public:
    virtual ~WorkEdit()=default;
    virtual gameplay_actors::EntityId identity()const noexcept=0;
    virtual bool uniform_scale(float)noexcept=0;
    virtual bool third_angle(std::int16_t)noexcept=0;
    virtual bool add_attributes(std::uint16_t)noexcept=0;
    virtual bool set_attributes(std::uint16_t)noexcept=0;
    // Complete652F90 child propagation plus source A8 and23E|100.
    virtual bool feedback(transform_math::Vector,float)noexcept=0;
};
enum class WorkStatus {completed,pool_full,resource_missing,unavailable};
struct WorkCreated {WorkStatus status{WorkStatus::unavailable};std::shared_ptr<WorkEdit> edit;};
class WorkBackend {
public:
    virtual ~WorkBackend()=default;
    virtual bool bound_to(const gameplay_session::Random&)const noexcept=0;
    virtual bool admitted()const noexcept=0;
    virtual WorkCreated create(const WorkRequest&)noexcept=0;
    // Find active type1D and refresh byte8=10, or allocate its actual lifecycle
    // from the very same168-record work owner. No separate companion capacity.
    virtual WorkStatus refresh_companion()noexcept=0;
};
}
