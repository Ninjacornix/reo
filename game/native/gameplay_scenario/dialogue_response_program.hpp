#pragma once
#include "dialogue_assets.hpp"
#include <vector>
namespace reo::native::gameplay_scenario {
struct DialogueCondition {
    std::uint8_t kind{},comparison{};
    std::uint16_t parameter{};
    std::int32_t value{};
    friend bool operator==(const DialogueCondition&,const DialogueCondition&)=default;
};
struct DialogueResponseDefinition {
    std::int16_t cue{};
    std::int8_t group{},mode{};
    std::array<DialogueCondition,4> conditions;
    std::array<std::int8_t,3> combiners;
    friend bool operator==(const DialogueResponseDefinition&,const DialogueResponseDefinition&)=default;
};
struct DialogueResponseInitialState {
    std::array<std::int8_t,4> condition_results;
    std::uint32_t replied_to{};
    friend bool operator==(const DialogueResponseInitialState&,const DialogueResponseInitialState&)=default;
};
struct DialogueResponseEntry {
    // Distinct table entries may name the same physical authored row. This key
    // preserves that alias for the response owner, rather than copying state.
    std::size_t physical_row{};
    DialogueResponseDefinition definition;
    DialogueResponseInitialState initial;
};
// Complete second-table data role reached by6B7520(mode0). This immutable
// program supplies definitions and authored initial state; live response state
// belongs to its one gameplay owner.
class DialogueResponseProgram final {
public:
    explicit DialogueResponseProgram(std::shared_ptr<const DialogueCues>);
    std::optional<DialogueResponseEntry> response(std::size_t selection)const noexcept;
    std::size_t physical_rows()const noexcept{return rows_.size();}
    std::shared_ptr<const DialogueCues> cues()const noexcept{return cues_;}
private:
    std::shared_ptr<const DialogueCues> cues_;
    std::array<std::optional<std::size_t>,DialogueCues::selections> selections_;
    std::vector<std::optional<DialogueResponseEntry>> rows_;
};
} // namespace reo::native::gameplay_scenario
