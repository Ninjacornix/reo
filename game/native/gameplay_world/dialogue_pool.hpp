#pragma once
#include "dialogue_records.hpp"
#include "dialogue_bank_bindings.hpp"
namespace reo::native::gameplay_update { class DialogueWorkers; }
namespace reo::native::gameplay_world {
class DialogueResponsesState;
struct DialogueResponseFrame;
struct DialogueResponsesUpdated;
struct DialogueBanksRefreshed;
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
    DialogueStatus reset_room_banks()noexcept; //complete6B7720 consumed native roles
    DialogueBanksRefreshed refresh_room_banks(const gameplay_scenario::content::ScenarioArchive&,const gameplay_scenario::content::ScriptBank&)noexcept; //1D41F0
    DialogueStatus clear_records()noexcept; //complete6B7810 owned state
    DialogueStatus banks(std::shared_ptr<const DialogueBanks>)noexcept;
    DialogueConstructed construct(const actors::EntityId&,const DialogueGates&)noexcept; //6B7930
    DialoguePoolUpdated update(const DialogueGates&)noexcept; //6B9590
    DialogueResponsesUpdated advance_responses(const DialogueResponseFrame&)noexcept; //complete6B7E40 admitted frame
    std::optional<DialogueRecord> record(std::size_t)const;
    std::shared_ptr<const DialogueBanks> bank_snapshot()const noexcept{return banks_;}
    std::optional<bool> flag(std::uint16_t)const noexcept;
    std::optional<std::int32_t> flag_duration(std::uint16_t)const noexcept;
    DialogueStatus advance_flag_durations()noexcept; //complete6B80A0, no pause gate in this helper
    std::optional<std::array<std::int16_t,2>> selected_counts()const noexcept{return initialized_&&counts_[0]&&counts_[1]?std::optional(std::array<std::int16_t,2>{*counts_[0],*counts_[1]}):std::nullopt;}
private:
    friend class DialogueResponsesState;
    friend class reo::native::gameplay_update::DialogueWorkers;
    DialogueResponsesUpdated advance_response_prefix(const DialogueResponseFrame&)noexcept; //Owner finalizes6B80A0
    DialogueResponsesUpdated advance_responses_impl(const DialogueResponseFrame&,bool include_durations)noexcept;
    DialogueConstructed construct_impl(const actors::EntityId&,const DialogueGates&,bool nested)noexcept;
    DialoguePoolUpdated update_impl(const DialogueGates&,bool nested)noexcept;
    std::optional<bool> gates(const DialogueGates&)const noexcept;
    DialogueStatus reset_room_banks_unchecked(std::size_t& actors_reset)noexcept;
    DialogueStatus publish_room_bank(std::size_t,bool texts,gameplay_scenario::content::Bytes,std::string identity);
    void clear_records_unchecked()noexcept;
    void select(std::size_t)noexcept; //6B9E90
    World& world_;ActorVoiceRequests* voice_;DialoguePresentation* presentation_;
    std::shared_ptr<const DialogueBanks> banks_;
    std::optional<DialogueBankBindings> physical_banks_; //actual6B7610 enables physical publication
    std::array<DialogueRecord,16> records_;
    std::array<std::array<std::optional<std::size_t>,16>,2> selected_;
    //6B7810 clears only channel0's short; channel1 is established by6B9590.
    std::array<std::optional<std::int16_t>,2> counts_;
    std::optional<actors::EntityId> previous_secondary_actor_;
    std::optional<actors::EntityId> primary_actor_;
    std::array<std::uint16_t,2> selected_sequences_{};
    // Flags and duration counters borrow the existing Session AuxiliaryScene.
    std::unique_ptr<DialogueResponsesState> responses_;
    bool initialized_{},running_{},responding_{};
};
} // namespace reo::native::gameplay_world
