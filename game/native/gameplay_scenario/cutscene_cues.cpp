#include "cutscene_cues.hpp"
#include "flags.hpp"
#include "../gameplay_world/world.hpp"

namespace reo::native::gameplay_scenario {
namespace {
std::optional<std::uint8_t> resolve_variant(const gameplay_world::World& world,const FlagState& flags,
                                            std::uint16_t selector,std::uint16_t actor_selection) noexcept {
    if (selector == 2) {
        const auto actor = world.primary(world.selected_actor);
        if (!actor) return {};
        return actor->character;
    }
    if (selector != 1 && selector != 3 && selector != 5) return 0;
    const auto owner = flags.scenario_owner(actor_selection);
    if (!owner) return {};
    if (*owner == 0 && selector != 3) return 0;
    const auto actor = world.primary(*owner == 0 ? world.selected_actor : std::size_t(*owner - 1));
    if (!actor) return {};
    return selector == 3 ? actor->character : std::uint8_t(actor->motion_style != 0);
}

CutsceneCue cue(const CutsceneRequests::Record& record,std::uint8_t variant) noexcept {
    return {std::uint8_t(record[1]),std::uint8_t(record[2]),variant};
}
}

std::optional<CutsceneBatch> collect_cutscene_cues(gameplay_world::World& world,const FlagState& flags) noexcept {
    if (world.closed()) return {};
    auto& requests = world.session().cutscene_requests;
    auto next = requests;
    const auto first = next.take();
    if (!first) return {};

    CutsceneBatch batch;
    batch.mode = std::uint8_t((*first)[0]);
    if (batch.mode == 3) batch.mode = 1;
    batch.selector = std::uint8_t((*first)[3]);
    batch.actor_selection = (*first)[4];
    const auto variant = resolve_variant(world,flags,batch.selector,batch.actor_selection);
    if (!variant) return {};
    batch.current = cue(*first,*variant);
    if (batch.mode != 0) {
        batch.audio_cues[batch.audio_count++] = batch.current;
        while (next.read_index() != next.write_index()) {
            const auto& pending = next.records()[next.read_index()];
            if (pending[0] == 0) break;
            // Additional requests share the first request's actor selection.
            const auto next_variant = resolve_variant(world,flags,pending[3],batch.actor_selection);
            if (!next_variant) return {};
            batch.audio_cues[batch.audio_count++] = cue(pending,*next_variant);
            (void)next.take();
        }
    }
    requests = next;
    return batch;
}
}
