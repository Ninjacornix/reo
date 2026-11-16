#pragma once
#include "../gameplay_scenario/dialogue_assets.hpp"
#include <array>
#include <optional>
namespace reo::native::gameplay_world {
enum class DialogueBankBindingStatus {completed,unavailable,unsupported_profile};
struct DialogueBankPublished {
    DialogueBankBindingStatus status{DialogueBankBindingStatus::completed};
    bool physical_published{},character_mapped{};
};
// Typed physical tables and character indirection written by6B7350. This value
// belongs exclusively to the canonical Pool after its actual6B7610 clear.
// The logical view is derived; it never carries a second mutable bank owner.
class DialogueBankBindings final {
public:
    DialogueBankPublished publish_cues(std::size_t physical,std::optional<std::uint8_t> character,
        std::shared_ptr<const gameplay_scenario::DialogueCues>,std::string identity);
    DialogueBankPublished publish_texts(std::size_t physical,std::optional<std::uint8_t> character,
        std::shared_ptr<const gameplay_scenario::DialogueTexts>,std::string identity);
    std::array<gameplay_scenario::DialogueBank,9> logical()const;
    const gameplay_scenario::DialogueBank* physical(std::size_t)const noexcept;
    std::optional<std::uint8_t> physical_for_character(std::size_t)const noexcept;
private:
    std::array<gameplay_scenario::DialogueBank,5> physical_;
    std::array<std::uint8_t,8> character_to_physical_{};
    DialogueBankPublished map(std::size_t,std::optional<std::uint8_t>)noexcept;
};
}
