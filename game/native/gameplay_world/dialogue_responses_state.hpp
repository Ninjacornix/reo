#pragma once
#include "dialogue_responses.hpp"
#include "dialogue_response_choice.hpp"
#include "dialogue_response_uses.hpp"
namespace reo::native::gameplay_world {
// Exclusively owned by DialoguePool; no independently constructible response
// world, actor pool, random generator, flags, publication or presentation.
class DialogueResponsesState final {
    friend class DialoguePool;
    struct Bank {
        explicit Bank(std::shared_ptr<const gameplay_scenario::DialogueCues>);
        gameplay_scenario::DialogueResponseProgram program;
        std::vector<std::optional<DialogueResponseMutable>> mutable_rows;
    };
    struct Row {
        gameplay_scenario::DialogueResponseDefinition definition;
        DialogueResponseMutable* mutable_row{};
    };
    explicit DialogueResponsesState(DialoguePool&);
    void clear_owned()noexcept;
    void bind(const DialogueBanks&);
    DialogueResponsesUpdated advance(const DialogueResponseFrame&,bool include_durations);
    DialogueStatus select_bank(const Actor&,Bank*&)const noexcept;
    static std::optional<Row> row(Bank*,std::size_t)noexcept;
    DialogueStatus suppression(std::optional<bool>&)noexcept;
    DialogueStatus input(const actors::EntityId&,const DialogueResponseFrame&,bool&,std::optional<std::size_t> physical_index = {});
    DialogueStatus evaluate(const actors::EntityId&,Bank*,Row&,const DialogueResponseFrame&);
    DialogueResponsePriority priority(const Actor&)const noexcept;
    DialogueStatus monitor(const DialogueResponseFrame&);
    DialogueStatus choose(const actors::EntityId&,const DialogueResponseFrame&,bool&);
    DialogueStatus direct(const actors::EntityId&,const DialogueResponseFrame&,bool&);
    DialogueStatus reply_to(const actors::EntityId&,const actors::EntityId&,const DialogueResponseFrame&,bool&);
    DialogueStatus reply(const actors::EntityId&,const DialogueResponseFrame&,bool&);
    DialogueStatus prepare(const actors::EntityId&,const DialogueResponseFrame&);
    DialogueStatus publish(const actors::EntityId&,const DialogueResponseFrame&);
    DialoguePool& pool_;
    World& world_;
    std::array<std::shared_ptr<Bank>,9> banks_;
    std::vector<std::shared_ptr<Bank>> retained_banks_;
    std::array<std::int32_t,8> choices_{};
    DialogueResponseUses uses_;
    std::int32_t selected_use_{-1};
    DialogueResponsesUpdated report_;
};
}
