#pragma once
#include "scenario_archive.hpp"
#include "scene_reset_state.hpp"
namespace reo::native::gameplay_world {struct Session;}
namespace reo::native::gameplay_scenario {
enum class SceneTextVariant : std::uint8_t {standard,alternate};
enum class SceneTextBankStatus {completed,busy,unavailable,invalid_asset,no_memory};
struct SceneTextBankLoaded {
    SceneTextBankStatus status{SceneTextBankStatus::unavailable};
    bool read{};
    std::size_t bytes{};
};
// Actual1D4130(0) DM front bank324438 and distinct1D4020 message bank32443C.
// Actor dialogue windows later in the DM allocation retain their existing owner.
// Offsets are bounded asset offsets, never runtime guest addresses.
struct SceneTextLines {std::vector<std::span<const std::byte>> lines;};
struct SceneChoiceQuestion {
    bool enabled{};
    std::array<std::optional<std::span<const std::byte>>,2> lines;
};
class SceneTextBank final {
public:
    static constexpr std::size_t capacity=0x6000;
    SceneTextBank(gameplay_world::Session&,const content::ScenarioArchive&)noexcept;
    SceneTextBank(const SceneTextBank&)=delete;
    SceneTextBank& operator=(const SceneTextBank&)=delete;
    SceneTextBankLoaded load()noexcept; //1D4130(0), DM bank only
    SceneTextBankLoaded load_messages(SceneTextVariant)noexcept; //complete1D4020
    std::span<const std::byte> known()const noexcept{return std::span(bytes_).first(known_);}
    std::span<const std::byte> messages_known()const noexcept{return std::span(messages_).first(messages_known_);}
    //6BA070/6B9FA0: kind0 uses1D4020's bank; kind2 uses immutable MAIN1C1CE0.
    std::optional<SceneTextLines> message_lines(std::int16_t id,std::uint32_t kind=0)const noexcept;
    std::optional<std::array<std::uint16_t,8>> message_cues(std::int16_t id,std::uint32_t kind=0)const noexcept; //6BA190
    SceneTextBankStatus initialize_choices()noexcept; //complete5A4F90
    std::optional<std::span<const std::byte>> choice_text(std::uint32_t index)const noexcept;
    std::optional<SceneChoiceQuestion> choice_question(std::uint32_t id)const noexcept; //5A5090's first two rows
    PriorityTextState& priority()noexcept{return priority_;}
    const PriorityTextState& priority()const noexcept{return priority_;}
    bool bound_to(const gameplay_world::Session& session)const noexcept{return &session_==&session;}
private:
    gameplay_world::Session& session_;
    const content::ScenarioArchive& archive_;
    // Unread bytes have no admitted value. A short later read preserves all
    // previously established tail bytes; a miss establishes only word0=0.
    std::array<std::byte,capacity> bytes_{};
    std::size_t known_{};
    std::array<std::byte,0x10000> messages_{};
    std::size_t messages_known_{};
    PriorityTextState priority_;
    std::array<std::array<std::byte,64>,10> choices_{};
    bool choices_known_{};
    bool running_{};
};
} // namespace reo::native::gameplay_scenario
