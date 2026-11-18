#pragma once
#include "dialogue_records.hpp"
#include "inventory_visibility.hpp"
#include "../gameplay_scenario/text_cache.hpp"
namespace reo::native::gameplay_world {
// Borrowed inputs of actual6DEE20. The timed-message owner must supply these;
// a generic presentation binding does not fabricate its initialization.
// The application supplies its one shared native cache for all text frontends.
// Queue insertion/erase are the real source operations; later font/glyph
// rendering consumes cache snapshots through its distinct source owner.
class CachedDialoguePresentation final:public DialoguePresentation {
public:
    CachedDialoguePresentation(World&,gameplay_scenario::TextCache&,const DialogueVisibilityInputs&)noexcept;
    bool bound_to(const World&)const noexcept override;
    bool erase(std::span<const std::byte>)noexcept override;
    std::optional<bool> suppressed()noexcept override;
    bool draw(std::int16_t,std::uint16_t,std::span<const std::byte>,std::uint8_t)noexcept override;
private:
    World& world_;gameplay_scenario::TextCache& cache_;const DialogueVisibilityInputs& visibility_;
};
} // namespace reo::native::gameplay_world
