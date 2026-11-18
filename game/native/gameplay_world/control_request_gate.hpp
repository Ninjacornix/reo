#pragma once
#include "world.hpp"

namespace reo::native::gameplay_world {
enum class ControlRequestStatus { completed,unavailable,invalid_actor };
struct ControlRequestResult {
    ControlRequestStatus status{ControlRequestStatus::unavailable};
    bool original_result{};
};
class ControlRequestDispatcher {
public:
    virtual ~ControlRequestDispatcher()=default;
    // The source's nested64F2D0 consumer. A null result means its reached
    // dependency could not complete; false is a real guest false result.
    virtual std::optional<bool> dispatch(World&,Actor&)=0;
};
// Complete64F5F0's admission and held-input gates, delegating its nested
// 64F2D0 call to the supplied source-ordered dispatcher.
ControlRequestResult dispatch_control_request(World&,Actor&,ControlRequestDispatcher&);
}
