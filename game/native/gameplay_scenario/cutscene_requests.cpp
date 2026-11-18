#include "cutscene_requests.hpp"
#include "../gameplay_world/world.hpp"
#include <algorithm>

namespace reo::native::gameplay_scenario {
void CutsceneRequests::append(const Record& record) noexcept {
    records_[write_] = record;
    write_ = std::uint8_t((write_ + 1) % capacity);
}

std::optional<CutsceneRequests::Record> CutsceneRequests::take() noexcept {
    if (read_ == write_) return {};
    const auto record = records_[read_];
    read_ = std::uint8_t((read_ + 1) % capacity);
    return record;
}

void CutsceneRequests::clear() noexcept {
    records_ = {};
    read_ = write_ = 0;
}

bool queue_cutscene(gameplay_world::World& world,const std::array<std::uint16_t,5>& arguments,
                    ForcedActorTerminal* terminal) noexcept {
    if (world.closed()) return false;
    const auto actor = world.primary(world.selected_actor);
    if (!actor) return false;
    const bool use_default = (actor->status & 0x80) != 0;
    if (use_default && world.paused) return true;
    const bool already_terminal = (actor->status & 0x120) != 0;
    auto& queue = world.session().cutscene_requests;
    const bool override_limit = use_default || already_terminal || queue.limit_override;
    if (override_limit && !terminal) return false;
    queue.limit_override = override_limit;
    world.paused = 1;
    if (!already_terminal) {
        CutsceneRequests::Record record{};
        // 68F010 loads words from 7174D0 and takes their low halfwords.
        constexpr std::array<std::uint16_t,5> fallback{0,98,0,2,255};
        const auto& selected = use_default ? fallback : arguments;
        std::copy(selected.begin(),selected.end(),record.begin());
        queue.append(record);
    }
    if (override_limit && !terminal->apply(world,0)) return false;
    world.session().actor_placements.selected_request = false;
    return true;
}
}
