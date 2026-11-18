#pragma once
#include "dialogue_records.hpp"
namespace reo::native::gameplay_world {
enum class DialogueBankLoadStage {entry,section,cache,reset,cues,texts,completed};
struct DialogueBanksRefreshed {
    DialogueStatus status{DialogueStatus::completed};
    DialogueBankLoadStage stage{DialogueBankLoadStage::entry};
    std::optional<std::int32_t> section;
    std::optional<std::size_t> physical;
    std::size_t requested{},loaded{},missing{},actors_reset{};
    bool cache_hit{},reset{},cache_published{};
};
}
