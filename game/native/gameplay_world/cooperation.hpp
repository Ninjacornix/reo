#pragma once
#include "world.hpp"

namespace reo::native::gameplay_world {

enum class CooperationStatus { completed, unavailable };
class CooperationPublication {
public:
    virtual ~CooperationPublication()=default;
    virtual bool publish_peer(World&,Actor&)=0;
};

// Exact native counterpart of 64F720. `related` is the canonical target
// returned by the preceding source lookup; publication uses the existing
// selector-8 actor-message owner and preserves its refusal semantics.
CooperationStatus update_cooperation_request(World&, Actor&,
    Actor& related, CooperationPublication&) noexcept;

} // namespace reo::native::gameplay_world
