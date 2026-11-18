#pragma once
#include "actor_views.hpp"
namespace reo::native::gameplay_collision::actors {
// Standalone post-pose metadata update (6F14F0), distinct from the registry's
// accumulated-push summary. A missing definition preserves the old summary.
// The caller retains the actor and native pose for this synchronous call.
bool refresh_summary(View);
} // namespace reo::native::gameplay_collision::actors
