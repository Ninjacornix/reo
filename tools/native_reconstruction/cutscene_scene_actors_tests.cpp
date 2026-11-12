#include "game/native/gameplay_scenario/cutscene_scene_actors.hpp"
#include "game/native/gameplay_scenario/scenario_archive.hpp"
#include "game/native/gameplay_update/update.hpp"
#include "game/native/gameplay_world/auxiliary_actors.hpp"
#include "game/native/gameplay_world/linked_models.hpp"
#include "runtime/assets/virtual_afs.h"
#include <fstream>
#include <iostream>
#include <source_location>

namespace s = reo::native::gameplay_scenario;
namespace w = reo::native::gameplay_world;
namespace u = reo::native::gameplay_update;
namespace tasks = reo::native::gameplay_tasks;
namespace {
std::uint64_t checks{}, scenes{}, primary{}, npcs{}, scripted{}, objects{}, queue_transitions{},
    parameters{}, refusals{}, retained_models{};
std::vector<std::string> missing_models;
void check(bool value, std::source_location location = std::source_location::current()) {
    ++checks;
    if (!value)
        throw std::runtime_error(std::string("Cinematic scene actor check ") +
                                 location.file_name() + ":" + std::to_string(location.line()));
}
struct Notices final : s::FlagNotifications {
    bool changed(const s::ScenarioFlagChange&) noexcept override {
        return true;
    }
    bool changed(const s::StridedFlagChange&) noexcept override {
        return true;
    }
};
w::Profile profile() {
    w::Profile result;
    result.layouts.push_back({});
    return result;
}
void run(const char* archive, const char* manifest) {
    auto source = std::make_shared<reo::assets::Source>(archive);
    w::ActorAssets assets(source);
    w::HumanoidMotionAssets content(source);
    const auto base = content.base();
    const std::array<std::uint8_t, 8> characters{0, 1, 2, 3, 4, 5, 6, 7};
    const auto banks = content.overlay(1, characters, *base);
    auto input = std::make_shared<s::content::ScenarioArchive>(source);
    w::CinematicObjectAssets object_assets(input);
    std::ifstream rows(manifest);
    check(bool(rows));
    unsigned scenario, area, scene, suffix;
    while (rows >> scenario >> area >> scene >> suffix) {
        const auto descriptor =
            s::read_cutscene_descriptor(*input, std::uint16_t(scenario), std::uint8_t(area),
                                        std::uint8_t(scene), std::uint8_t(suffix));
        check(bool(descriptor));
        w::World world(profile(), std::make_shared<w::Session>());
        world.paused = 1;
        world.scenario = descriptor->identity()[0];
        world.room = descriptor->identity()[1];
        world.session().asset_loading_mode = 1;
        world.session().primary_population = 8;
        Notices notices;
        u::Owner update(world, notices);
        w::HumanoidMotionOwner motions(world);
        check(motions.publish(banks).status == w::HumanoidPublicationStatus::completed);
        w::PrimaryActorModels models(world, motions);
        for (unsigned slot = 0; slot < 8; ++slot) {
            auto initial = std::make_unique<w::Actor>();
            initial->slot = std::uint8_t(slot);
            initial->character = std::uint8_t(slot);
            initial->active = true;
            initial->room = world.room;
            const auto id = world.spawn_primary(slot, std::move(initial)).id;
            check(bool(id));
            const auto prepared =
                w::PrimaryActorModels::prepare(models.capture(id).value(), assets, content);
            check(models.apply(*prepared, update.state).status == w::PrimaryModelStatus::completed);
        }
        s::CutsceneSceneRoster roster;
        roster.primary.characters = characters;
        roster.primary.eligible_count = 8;
        s::CutsceneSceneActors owner(update, models, motions, assets, content, object_assets,
                                     roster);
        s::CutscenePlaybackState playback;
        playback.request.current = {std::uint8_t(area), std::uint8_t(scene), std::uint8_t(suffix)};
        check(owner.construct({}, playback).status == s::CutsceneSceneActorStatus::unavailable &&
              !owner.partial());
        ++refusals;
        check(owner.initialize_records() == s::CutsceneSceneActorStatus::completed);
        std::shared_ptr<const w::PreparedCinematicObjects> prepared;
        try {
            prepared = w::CinematicObjectConstruction::prepare(*descriptor, playback.request.current,
                                                              object_assets);
        } catch (const std::invalid_argument& error) {
            const std::string message=error.what();
            if (!message.starts_with("Native cinematic object required named asset unavailable: "))
                throw;
            missing_models.push_back(message);
            const auto first=world.identity(0);const auto model=world.primary(0)->model;
            check(owner.construct(descriptor,playback).status==s::CutsceneSceneActorStatus::unavailable);
            check(!owner.partial()&&world.identity(0)==first&&world.primary(0)->model==model&&models.capture(first));
            check(world.close()==w::Status::completed);continue;
        }
        check(prepared && prepared->size() == descriptor->object_groups().size());
        for (unsigned pass = 0; pass < 2; ++pass) {
            const auto scene_motion = content.scene(descriptor->identity()[0],
                                                    descriptor->identity()[1], *motions.snapshot());
            check(motions.publish(scene_motion.banks).status ==
                  w::HumanoidPublicationStatus::completed);
            check(owner.prepare_roster(playback) == s::CutsceneSceneActorStatus::completed);
            const auto result = owner.construct(descriptor, playback);
            if (result.status != s::CutsceneSceneActorStatus::completed)
                throw std::runtime_error("Scene actor construction failed " +
                                         std::to_string(scenario) + "/" + std::to_string(area) +
                                         "/" + std::to_string(scene) + "/" +
                                         std::to_string(suffix) + " group " +
                                         std::to_string(result.failed_group.value_or(999)) +
                                         " selected " + std::to_string(result.selected));
            check(!owner.partial() && owner.actors().size() == descriptor->actor_groups().size());
            primary += result.initialized;
            npcs += result.npcs;
            scripted += result.scripted;
            objects += result.objects;
            struct Lease {
                std::shared_ptr<const reo::native::animation::Instance> model;
                std::size_t nodes;
                std::optional<reo::native::animation::Vector> root;
            };
            std::vector<Lease> retained;
            const auto remember = [&](auto model) {
                const auto count = model->nodes().size();
                retained.push_back(
                    {model, count,
                     count ? std::optional(model->local_translation(0)) : std::nullopt});
            };
            for (std::size_t group = 0; group < owner.actors().size(); ++group) {
                const auto& binding = owner.actors()[group];
                if (!binding.actor)
                    continue;
                const auto actor = world.resolve(binding.actor);
                check(actor && actor->scripted);
                if (binding.kind == 2) {
                    //6BA5C0 leaves these linked actors inactive until their
                    // authored first command. FF models/no skeleton are real
                    // admitted absences, not fabricated animation capability.
                    check(!actor->active);
                    check(bool(actor->model) == bool(actor->model_asset && actor->model_asset->skeleton()));
                    check(actor->model ? actor->animation && actor->animation->model() == actor->model
                                       : !actor->animation);
                } else {
                    check(actor->active && actor->model && actor->animation &&
                          actor->animation->model() == actor->model);
                }
                check(actor->room == (binding.kind == 2 ? 0 : world.room));
                if (actor->model)
                    remember(actor->model);
                parameters += owner.parameters(group).size();
            }
            for (unsigned slot = 0; slot < prepared->size(); ++slot) {
                const auto object =
                    world.cinematic_objects().resolve(world.cinematic_objects().identity_at(slot));
                check(object && object->reserved && !object->model);
            }
            check(owner.construct_object_models() == s::CutsceneSceneActorStatus::completed);
            for (unsigned slot = 0; slot < prepared->size(); ++slot) {
                const auto object =
                    world.cinematic_objects().resolve(world.cinematic_objects().identity_at(slot));
                check(object && object->reserved && object->model_asset &&
                      object->motion == prepared->initial_motion(slot));
                check(bool(object->model)==bool(object->model_asset->skeleton()));
                if(object->model)remember(object->model);
            }
            check(owner.construct(descriptor, playback).status ==
                  s::CutsceneSceneActorStatus::unavailable);
            ++refusals;
            check(owner.finish_models(false) == s::CutsceneSceneActorStatus::unavailable);
            ++refusals;
            check(owner.clear_tracks() == s::CutsceneSceneActorStatus::completed);
            const auto cleaned = content.release_scene_tables(*motions.snapshot());
            check(motions.publish(cleaned).status == w::HumanoidPublicationStatus::completed);
            check(owner.reset_records() == s::CutsceneSceneActorStatus::completed);
            check(world.auxiliary_actors().reset() == w::AuxiliaryStatus::completed &&
                  world.linked_models().reset() == w::LinkedStatus::completed);
            check(update.linked().run(tasks::Pass::update).status == tasks::Status::completed);
            check(owner.finish_models(pass == 1) == s::CutsceneSceneActorStatus::completed);
            if (pass == 0) {
                ++queue_transitions;
                const auto defaults = content.ensure_base(motions.snapshot());
                check(motions.publish(defaults).status == w::HumanoidPublicationStatus::completed);
                const auto restored = content.overlay(1, characters, *defaults);
                check(motions.publish(restored).status == w::HumanoidPublicationStatus::completed);
            }
            for (const auto& lease : retained) {
                check(lease.model && lease.model->nodes().size() == lease.nodes);
                if (lease.root) {
                    const auto root = lease.model->local_translation(0);
                    check(root.x == lease.root->x && root.y == lease.root->y &&
                          root.z == lease.root->z);
                }
                ++retained_models;
            }
        }
        ++scenes;
        check(world.close() == w::Status::completed);
    }
    check(rows.eof() && scenes > 0 && primary > 0 && npcs > 0 && scripted > 0 && objects > 0 &&
          queue_transitions == scenes);
}
} // namespace
int main(int argc, char** argv) {
    check(argc == 3);
    run(argv[1], argv[2]);
    std::cout << "{\"missing_models\":[";for(std::size_t i=0;i<missing_models.size();++i){if(i)std::cout<<',';std::cout<<'\"'<<missing_models[i]<<'\"';}
    std::cout << "],\"checks\":" << checks << ",\"scenes\":" << scenes << ",\"primary\":" << primary
              << ",\"npcs\":" << npcs << ",\"scripted\":" << scripted << ",\"objects\":" << objects
              << ",\"queue_transitions\":" << queue_transitions << ",\"parameters\":" << parameters
              << ",\"refusals\":" << refusals << ",\"retained_models\":" << retained_models
              << ",\"game_run\":false}\n";
}
