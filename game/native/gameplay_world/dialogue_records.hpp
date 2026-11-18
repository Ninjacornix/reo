#pragma once
#include "actor_voice_requests.hpp"
#include "../gameplay_scenario/dialogue_assets.hpp"
namespace reo::native::gameplay_world {
enum class DialogueStatus {completed,unavailable,unsupported_profile,busy,closed,capacity,no_memory};
enum class DialogueStage {entry,initialize,line,voice,corruption,fade,erase,buffer,visibility,draw,completed};
struct DialogueReport {DialogueStatus status{DialogueStatus::completed};DialogueStage stage{DialogueStage::entry};};
// Typed values of the actual0x98 text record. Text resources retain their
// immutable bank; an actor uses its canonical domain/generation identity.
struct DialogueRecord {
    bool active{};
    std::int16_t phase{},delay{},initial_delay{},age{};
    std::int8_t fade_ticks{},character_ticks{},channel{};
    std::uint8_t alpha{};
    std::int16_t revealed{},line_bytes{};
    std::array<std::byte,64> buffer{};
    std::int16_t voice{},center{};
    actors::EntityId actor;
    std::uint16_t sequence{};
    std::int16_t glyphs{};
    std::int8_t corruption_count{},reveal_index{},literal{},page{},newlines{},display_style{};
    std::array<std::byte,4> prefix{};
    std::array<std::uint8_t,32> corrupted{};
    std::shared_ptr<const gameplay_scenario::DialogueTexts> text_owner;
    std::size_t text_index{};
};
// Actual native presentation capability. Missing cache or draw ownership is
// refused only when that source operation is reached; no default succeeds.
class DialoguePresentation {
public:
    virtual ~DialoguePresentation()=default;
    virtual bool bound_to(const World&)const noexcept=0;
    virtual bool erase(std::span<const std::byte>)noexcept=0; //1B49B0 text-key cache
    virtual std::optional<bool> suppressed()noexcept=0; //6DEE20
    virtual bool draw(std::int16_t center,std::uint16_t y,std::span<const std::byte>,std::uint8_t alpha)noexcept=0; //1B48E0
};
struct DialogueContext {
    World& world;
    ActorVoiceRequests* voice{};
    DialoguePresentation* presentation{};
    // Source74E778 retains the prior secondary selection's actor pointer.
    // Its reached signed+58 test reads the low halfword of basis.x.z.
    std::optional<actors::EntityId> previous_secondary_actor;
    std::array<std::int16_t,2> selected_counts{};
    std::array<bool,2> second_selected_active{};
};
// Complete6B97D0 scalar update. Pool traversal supplies channel0/1 and actual
// selected-list state. Unknown/stale capabilities preserve the completed prefix.
DialogueReport advance_dialogue_record(DialogueRecord&,std::uint8_t channel,const DialogueContext&)noexcept;
} // namespace reo::native::gameplay_world
