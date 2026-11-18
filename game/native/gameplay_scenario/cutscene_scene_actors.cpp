#include "cutscene_scene_actors.hpp"
#include "../gameplay_update/update.hpp"
#include "../gameplay_world/scene_primary_actors.hpp"
#include <new>
#include <stdexcept>

namespace reo::native::gameplay_scenario {
namespace {
namespace g = gameplay_world;
using S = CutsceneSceneActorStatus;
S map(g::PrimaryModelStatus value) {
    switch (value) {
        case g::PrimaryModelStatus::completed:
            return S::completed;
        case g::PrimaryModelStatus::busy:
            return S::busy;
        case g::PrimaryModelStatus::closed:
            return S::closed;
        case g::PrimaryModelStatus::no_memory:
            return S::no_memory;
        default:
            return S::unavailable;
    }
}
S map(CutsceneTrackStatus value) {
    switch (value) {
        case CutsceneTrackStatus::completed:
            return S::completed;
        case CutsceneTrackStatus::busy:
            return S::busy;
        case CutsceneTrackStatus::closed:
            return S::closed;
        case CutsceneTrackStatus::no_memory:
            return S::no_memory;
        default:
            return S::unavailable;
    }
}
S map(g::CinematicObjectStatus value) {
    switch (value) {
        case g::CinematicObjectStatus::completed:
        case g::CinematicObjectStatus::unchanged:
            return S::completed;
        case g::CinematicObjectStatus::busy:
            return S::busy;
        case g::CinematicObjectStatus::closed:
            return S::closed;
        case g::CinematicObjectStatus::no_memory:
            return S::no_memory;
        default:
            return S::unavailable;
    }
}
struct Running {
    bool& value;
    explicit Running(bool& flag) : value(flag) {
        value = true;
    }
    ~Running() {
        value = false;
    }
};
} // namespace
CutsceneSceneActors::CutsceneSceneActors(
    gameplay_update::Owner& update, g::PrimaryActorModels& models, g::HumanoidMotionOwner& motions,
    const g::ActorAssets& assets, const g::HumanoidMotionAssets& motion_assets,
    const g::CinematicObjectAssets& object_assets, CutsceneSceneRoster initial)
    : update_(update), world_(update.world()), models_(models), motions_(motions), assets_(assets),
      motion_assets_(motion_assets), object_assets_(object_assets), npcs_(world_),
      scripted_(world_, update.material_animations()), objects_(world_), actor_tracks_(world_),
      object_tracks_(world_), roster_(initial) {
    if (!models.bound_to(world_) || !motions.bound_to(world_) || initial.primary.eligible_count > 8)
        throw std::invalid_argument("Native cinematic actor scene owner mismatch");
}
CutsceneSceneActors::~CutsceneSceneActors() {
    if (running_)
        std::terminate();
}
S CutsceneSceneActors::clear_tracks() noexcept {
    if (world_.closed())
        return S::closed;
    if (running_ || world_.busy())
        return S::busy;
    Running guard(running_);
    const auto actors = map(actor_tracks_.install({}));
    if (actors != S::completed)
        return actors;
    return map(object_tracks_.install({}));
}
S CutsceneSceneActors::initialize_records() noexcept {
    if (world_.closed())
        return S::closed;
    if (running_ || world_.busy())
        return S::busy;
    if (scope_ || latched_)
        return S::unavailable;
    Running guard(running_);
    try {
        const auto primary = world_.scene_primary_actors().initialize();
        if (primary != g::ScenePrimaryStatus::completed)
            return primary == g::ScenePrimaryStatus::no_memory ? S::no_memory : S::unavailable;
        const auto objects = map(world_.cinematic_objects().initialize());
        if (objects != S::completed)
            return objects;
        constructions_ = {};
        construction_groups_ = {};
        bindings_.clear();
        object_bindings_.clear();
        parameters_ = {};
        records_reset_ = false;
        return S::completed;
    } catch (const std::bad_alloc&) {
        return S::no_memory;
    } catch (...) {
        return S::unavailable;
    }
}
S CutsceneSceneActors::prepare_roster(CutscenePlaybackState& playback) noexcept {
    if (world_.closed())
        return S::closed;
    if (running_ || world_.busy())
        return S::busy;
    Running guard(running_);
    CutsceneRosterState projected{roster_.primary, roster_.source_slots, roster_.source_statuses,
                                  playback.selected_actor};
    const auto status =
        CutsceneRosterPreparation::apply(world_, projected, playback.request.selector);
    if (status != CutsceneRosterStatus::completed)
        return status == CutsceneRosterStatus::closed ? S::closed
               : status == CutsceneRosterStatus::busy ? S::busy
                                                      : S::unavailable;
    roster_ = {projected.roster, projected.source_slots, projected.source_statuses};
    playback.selected_actor = projected.preferred_one_based;
    return S::completed;
}
CutsceneSceneActorsResult
CutsceneSceneActors::construct(std::shared_ptr<const CutsceneDescriptor> descriptor,
                               const CutscenePlaybackState& playback, g::NpcSceneGraphics* graphics,
                               const g::PrimaryEquipmentContext* equipment) noexcept {
    if (world_.closed())
        return {S::closed, 0, 0, 0, 0, 0, {}};
    if (running_ || world_.busy())
        return {S::busy, 0, 0, 0, 0, 0, {}};
    if (latched_ || scope_ || !descriptor)
        return {};
    Running guard(running_);
    CutsceneSceneActorsResult report;
    try {
        if (!world_.scene_primary_actors().initialized())
            return report;
        // Acquire only immutable content before publishing actor bindings. A
        // caller cannot pair this descriptor with another scene's model plan.
        auto prepared_objects = g::CinematicObjectConstruction::prepare(
            *descriptor, playback.request.current, object_assets_);
        const auto headers = cutscene_primary_headers(*descriptor);
        std::array<bool, 8> occupied{};
        for (unsigned slot = 0; slot < 8; ++slot) {
            const auto actor = world_.resolve(world_.scene_primary_actors().identity_at(slot));
            if (!actor)
                return report;
            occupied[slot] = actor->active;
        }
        const auto selection = select_cutscene_primaries(
            headers.view(), roster_.primary, playback.selected_actor, occupied, reservations_);
        if (selection.status != CutscenePrimarySelectionStatus::completed)
            return report;
        std::vector<CutsceneActorBinding> next(headers.count);
        bindings_ = std::move(next);
        descriptor_ = std::move(descriptor);
        prepared_objects_ = std::move(prepared_objects);
        latched_ = true;
        //5F0DC0 constructs every selected primary before5F0C00 retires the
        // ordinary physical rows, and before any per-group initializer runs.
        for (const auto& choice : selection.selected()) {
            const auto made =
                models_.construct_scene_primary(choice, roster_.primary, motion_assets_);
            constructions_[choice.temporary_slot] = made;
            construction_groups_[choice.temporary_slot] = choice.group;
            if (made.id)
                bindings_[choice.group] = {0, made.id};
            if (made.status != g::PrimaryModelStatus::completed) {
                report.status = map(made.status);
                report.failed_group = choice.group;
                return report;
            }
            ++report.selected;
        }
        reservations_ = selection.reservations;
        const auto released = models_.release_scene_entry(motion_assets_);
        if (released.status != g::PrimaryModelStatus::completed) {
            report.status = map(released.status);
            return report;
        }
        scope_ = models_.open_scene_models();
        if (!scope_)
            return report;
        for (unsigned group = 0; group < headers.count; ++group) {
            const auto& header = headers.groups[group];
            if (!header.enabled)
                continue;
            report.failed_group = group;
            if (header.kind == 0 || header.kind == 3) {
                if (!bindings_[group].actor)
                    continue;
                const auto actor = world_.resolve(bindings_[group].actor);
                if (!actor)
                    return report;
                if (header.kind == 3 && actor->character == 255)
                    continue;
                const auto request =
                    models_.capture_scene(*scope_, bindings_[group].actor, *descriptor_, group);
                if (!request)
                    return report;
                const auto prepared =
                    g::PrimaryActorModels::prepare(*request, assets_, motion_assets_);
                const auto applied = models_.apply(*prepared, update_.state, equipment);
                if (applied.status != g::PrimaryModelStatus::completed) {
                    report.status = map(applied.status);
                    return report;
                }
                parameters_[group].assign(prepared->scene_parameters().begin(),
                                          prepared->scene_parameters().end());
                ++report.initialized;
            } else if (header.kind == 1) {
                const auto banks = motions_.snapshot();
                if (!banks)
                    return report;
                const auto prepared =
                    npcs_.prepare_cutscene_npcs(*descriptor_, assets_, banks->npc_bindings());
                const auto made = npcs_.create_cutscene_npc(*prepared, group, graphics);
                bindings_[group] = {1, made.id};
                if (made.status != g::NpcConstructionStatus::completed)
                    return report;
                parameters_[group].assign(prepared->parameters(group).begin(),
                                          prepared->parameters(group).end());
                ++report.npcs;
            } else if (header.kind == 2) {
                const auto prepared = scripted_.prepare_cutscene_scripted(*descriptor_, assets_);
                const auto made = scripted_.create_cutscene_scripted(*prepared, group);
                bindings_[group] = {2, made.id};
                if (made.status != gameplay_update::ScriptedConstructionStatus::completed)
                    return report;
                ++report.scripted;
            }
        }
        report.failed_group.reset();
        const auto reserved = objects_.reserve(*prepared_objects_);
        object_bindings_ = reserved.bindings;
        report.objects = object_bindings_.size();
        if (reserved.status != g::CinematicObjectStatus::completed) {
            report.status = map(reserved.status);
            return report;
        }
        const auto tracks = descriptor_->actor_tracks(bindings_);
        const auto installed = map(actor_tracks_.install(tracks));
        if (installed != S::completed) {
            report.status = installed;
            return report;
        }
        constructed_ = true;
        report.status = S::completed;
        return report;
    } catch (const std::bad_alloc&) {
        report.status = S::no_memory;
        return report;
    } catch (...) {
        return report;
    }
}
S CutsceneSceneActors::construct_object_models() noexcept {
    if (world_.closed())
        return S::closed;
    if (running_ || world_.busy())
        return S::busy;
    if (!constructed_ || records_reset_ || !prepared_objects_)
        return S::unavailable;
    Running guard(running_);
    try {
        const auto result = objects_.construct_reserved(*prepared_objects_, object_bindings_);
        if (result.status != g::CinematicObjectStatus::completed)
            return map(result.status);
        const auto tracks = prepared_objects_->tracks(object_bindings_);
        std::vector<gameplay_actors::EntityId> actors;
        actors.reserve(bindings_.size());
        for (const auto& binding : bindings_)
            actors.push_back(binding.actor);
        return map(object_tracks_.install(tracks, actors));
    } catch (const std::bad_alloc&) {
        return S::no_memory;
    } catch (...) {
        return S::unavailable;
    }
}
S CutsceneSceneActors::reset_records() noexcept {
    if (world_.closed())
        return S::closed;
    if (running_ || world_.busy())
        return S::busy;
    if (!scope_)
        return S::unavailable;
    Running guard(running_);
    const auto reset = map(models_.reset_scene_actors(*scope_));
    if (reset != S::completed)
        return reset;
    const auto objects = map(world_.cinematic_objects().initialize());
    if (objects != S::completed)
        return objects;
    records_reset_ = true;
    return S::completed;
}
S CutsceneSceneActors::finish_models(bool final_exit) noexcept {
    if (world_.closed())
        return S::closed;
    if (running_ || world_.busy())
        return S::busy;
    if (!scope_ || !records_reset_)
        return S::unavailable;
    Running guard(running_);
    if (final_exit)
        for (unsigned slot = 0; slot < constructions_.size(); ++slot) {
            const auto& made = constructions_[slot];
            if (!made.id || !made.release_on_exit || !construction_groups_[slot] ||
                *construction_groups_[slot] >= 16)
                continue;
            const auto released =
                map(models_.release_scene_model(*scope_, slot, motion_assets_).status);
            if (released != S::completed)
                return released;
        }
    const auto returned = map(final_exit ? models_.return_scene_models(*scope_)
                                         : models_.continue_scene_models(*scope_));
    if (returned != S::completed)
        return returned;
    scope_.reset();
    latched_ = constructed_ = records_reset_ = false;
    constructions_ = {};
    construction_groups_ = {};
    bindings_.clear();
    object_bindings_.clear();
    parameters_ = {};
    descriptor_.reset();
    prepared_objects_.reset();
    return S::completed;
}
} // namespace reo::native::gameplay_scenario
