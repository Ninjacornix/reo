#pragma once
#include "dialogue_records.hpp"
namespace reo::native::gameplay_world {
struct DialogueGates {
    std::optional<std::uint8_t> blocked; //4BAE8D, distinct from World.paused
    std::optional<std::uint8_t> flags;   //4BAE89; bit2 suppresses dialogue
};
using DialogueBanks=std::array<gameplay_scenario::DialogueBank,9>;
struct DialogueConstructed {
    DialogueStatus status{DialogueStatus::completed};
    std::optional<std::size_t> record;
    std::int32_t original_return{};
    std::size_t effects{};
};
struct DialoguePoolUpdated {
    DialogueStatus status{DialogueStatus::completed};
    std::size_t visited{},selected{},discarded{},updated{};
    std::optional<std::size_t> failed;
    DialogueStage stage{DialogueStage::entry};
};
class DialoguePool final {
public:
    DialoguePool(World&,ActorVoiceRequests* = nullptr,DialoguePresentation* = nullptr);
    ~DialoguePool();
    DialoguePool(const DialoguePool&)=delete;
    DialoguePool& operator=(const DialoguePool&)=delete;
    bool bound_to(const World&)const noexcept;
    // Projection of actual6B7610 cold clear onto this owner's records, flags,
    // selection caches and represented canonical speech fields. The source's
    // other timer/monitor owners are not installed by this projection.
    DialogueStatus initialize_owned_state()noexcept;
    DialogueStatus clear_records()noexcept; //complete6B7810 owned state
    DialogueStatus banks(std::shared_ptr<const DialogueBanks>)noexcept;
    DialogueConstructed construct(const actors::EntityId&,const DialogueGates&)noexcept; //6B7930
    DialoguePoolUpdated update(const DialogueGates&)noexcept; //6B9590
    std::optional<DialogueRecord> record(std::size_t)const;
    std::optional<bool> flag(std::uint16_t)const noexcept;
    std::optional<std::array<std::int16_t,2>> selected_counts()const noexcept{return initialized_&&counts_[0]&&counts_[1]?std::optional(std::array<std::int16_t,2>{*counts_[0],*counts_[1]}):std::nullopt;}
private:
    std::optional<bool> gates(const DialogueGates&)const noexcept;
    void clear_records_unchecked()noexcept;
    void select(std::size_t)noexcept; //6B9E90
    World& world_;ActorVoiceRequests* voice_;DialoguePresentation* presentation_;
    std::shared_ptr<const DialogueBanks> banks_;
    std::array<DialogueRecord,16> records_;
    std::array<std::array<std::optional<std::size_t>,16>,2> selected_;
    //6B7810 clears only channel0's short; channel1 is established by6B9590.
    std::array<std::optional<std::int16_t>,2> counts_;
    std::optional<actors::EntityId> previous_secondary_actor_;
    std::optional<actors::EntityId> primary_actor_;
    std::array<std::uint16_t,2> selected_sequences_{};
    // Complete owned SPM profiles use only authored IDs0..511. Higher source
    // bit indices require their actual larger owner before they can be used.
    std::array<std::uint32_t,16> flags_{};
    bool initialized_{},running_{};
};
} // namespace reo::native::gameplay_world
