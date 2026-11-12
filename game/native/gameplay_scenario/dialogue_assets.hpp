#pragma once
#include "scenario_archive.hpp"
#include <string>

namespace reo::native::gameplay_scenario {
// The admitted owned SP bank has two distinct 6,000-entry offset tables.
//6B7930 uses the first table through6B7520(mode1); second-table records are
// a different source role and are not reinterpreted as these cue records.
struct DialogueCue {
    std::uint16_t text{};
    std::int16_t delay{},voice{};
    friend bool operator==(const DialogueCue&,const DialogueCue&)=default;
};
class DialogueCues final {
public:
    static constexpr std::size_t selections=6000;
    explicit DialogueCues(content::Bytes);
    std::optional<DialogueCue> cue(std::size_t selection)const noexcept;
    content::Bytes backing()const noexcept{return bytes_;}
private:
    content::Bytes bytes_;
    std::uint32_t first_{},second_{};
};
struct DialogueText {
    // Authored text after the source's eight-byte presentation prefix,
    // excluding its terminator. The retained owner outlives this span.
    std::span<const std::byte> body;
    std::array<std::uint16_t,8> effects;
};
class DialogueTexts final {
public:
    explicit DialogueTexts(content::Bytes);
    std::size_t size()const noexcept{return count_;}
    std::optional<DialogueText> text(std::size_t index)const noexcept;
    content::Bytes backing()const noexcept{return bytes_;}
private:
    content::Bytes bytes_;
    std::uint32_t effects_{};
    std::size_t count_{};
};
struct DialogueBank {
    std::shared_ptr<const DialogueCues> cues;
    std::shared_ptr<const DialogueTexts> texts;
    std::string cue_identity,text_identity;
};
// Actual1D41F0 resource names for one explicit section and character. The
// caller supplies the source6B73F0 section result; it is not inferred from room.
// Missing halves stay missing, matching the independent source load gates.
DialogueBank prepare_dialogue_bank(const content::ScenarioArchive&,std::uint16_t scenario,
    std::uint8_t section,std::uint8_t character);
} // namespace reo::native::gameplay_scenario
