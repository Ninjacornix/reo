#include "motion_resources.hpp"
#include <algorithm>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
animation::Playback& playback(Actor& actor) {
    if (!actor.animation || actor.animation->model() != actor.model)
        throw std::runtime_error("Canonical native motion/model owner unavailable or stale");
    return *actor.animation;
}
} // namespace
bool MotionRelations::bind(actors::EntityId owner, MotionRelationBindings targets) {
    if (!world_.resolve(owner))
        return false;
    if (targets.auxiliary && !world_.resolve(*targets.auxiliary))
        return false;
    for (const auto& locator : {targets.first_linked, targets.second_linked})
        if (locator && locator->pool == MotionActorPool::primary &&
            locator->slot >= World::primary_capacity)
            return false;
    std::erase_if(entries_, [&](const auto& entry) { return !world_.resolve(entry.owner); });
    auto at = std::find_if(entries_.begin(), entries_.end(),
                           [&](const auto& e) { return e.owner == owner; });
    if (at != entries_.end())
        at->targets = std::move(targets);
    else {
        if (entries_.size() >= 1024)
            return false;
        entries_.push_back({std::move(owner), std::move(targets)});
    }
    return true;
}
std::shared_ptr<Actor> MotionRelations::resolve(const actors::EntityId& owner,
                                                MotionRelation kind) const {
    if (!world_.resolve(owner))
        throw std::runtime_error("Native motion relation owner foreign or retired");
    const auto at = std::find_if(entries_.begin(), entries_.end(),
                                 [&](const auto& e) { return e.owner == owner; });
    if (at == entries_.end())
        throw std::runtime_error("Native motion relation set has not been admitted");
    if (kind == MotionRelation::auxiliary)
        return at->targets.auxiliary ? world_.resolve(*at->targets.auxiliary) : nullptr;
    const auto& locator =
        kind == MotionRelation::first_linked ? at->targets.first_linked : at->targets.second_linked;
    if (!locator)
        return {};
    if (locator->pool != MotionActorPool::primary)
        throw std::runtime_error("Required native motion actor locator pool unavailable");
    // Source633350 is a fresh category/slot lookup. Preserve intentional late
    // selection of the current live occupant, unlike direct B24 generation refs.
    return world_.primary(locator->slot);
}
std::shared_ptr<Actor> WorldMotionResources::related(const actors::EntityId& owner,
                                                     std::uint8_t selector) const {
    if (!relations_)
        throw std::runtime_error("Required native motion relation owner unavailable");
    return relations_->resolve(owner, selector < 9    ? MotionRelation::auxiliary
                                      : selector < 12 ? MotionRelation::first_linked
                                                      : MotionRelation::second_linked);
}
std::shared_ptr<const animation::MotionBank>
WorldMotionResources::resolve(const actors::EntityId& owner, std::uint32_t supplied) {
    const auto actor = world_.resolve(owner);
    if (!actor)
        throw std::runtime_error("Native motion resource actor foreign or retired");
    auto& state = playback(*actor);
    const std::uint8_t selector = std::uint8_t(supplied);
    // Complete5D4470 cache effects happen before5D4810's resource decision.
    if (selector >= 15) {
        state.source_kind = state.source_slot = 0;
        throw std::out_of_range("Original motion family would return an unassigned saved register");
    }
    if (selector < 2) {
        state.source_kind = 0;
        state.source_slot = std::uint8_t(actor->motion_style != 0);
    } else if (selector == 2) {
        state.source_kind = 0;
        state.source_slot = actor->category == 0   ? std::uint8_t(actor->character + 2)
                            : actor->category == 1 ? 10
                                                   : 0;
    } else if (selector < 6)
        state.source_kind = state.source_slot = 0;
    else {
        const auto target = related(owner, selector);
        state.source_kind = target ? 255 : 0;
        state.source_slot = target ? target->slot : 0;
    }
    std::shared_ptr<Actor> source = actor;
    unsigned bank;
    if (selector < 3)
        bank = actor->category == 1 ? 1 : selector;
    else if (selector < 6)
        bank = selector - 3;
    else {
        source = related(owner, selector);
        if (!source)
            return {};
        bank = (selector - 6) % 3;
    }
    auto& selected = playback(*source);
    if (!selected.resources_known)
        throw std::runtime_error("Native motion bank loading/absence has not been admitted");
    if(source->motion_bank_aliases[bank]){
        const auto resource=resolve_humanoid_motion_bank(world_,*source->motion_bank_aliases[bank],selected.resources[bank]);
        if(!resource&&(world_.humanoid_motion_source()||world_.humanoid_motion_source_closed()))
            throw std::runtime_error("Native humanoid motion content owner unavailable or closed");
        return resource;
    }
    return selected.resources[bank];
}
} // namespace reo::native::gameplay_world
