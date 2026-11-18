#include "actor_metadata.hpp"
namespace reo::native::gameplay_collision::actors {
bool refresh_summary(View actor) {
    if (!actor.definition)
        return false;
    const auto shape = build(actor, *actor.definition);
    auto summary = summarize(shape);
    if (std::holds_alternative<Sphere>(shape))
        summary.heading = 0;
    actor.summary = summary;
    return true;
}
} // namespace reo::native::gameplay_collision::actors
