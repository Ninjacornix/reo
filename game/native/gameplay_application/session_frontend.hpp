#pragma once
#include <array>
#include <cstdint>
#include <optional>
#include <memory>
#include "../gameplay_scenario/display_fade.hpp"
#include "../gameplay_presentation/font_face.hpp"

namespace reo::assets {struct Source;}
namespace reo::native::gameplay_scenario {class TextCache;}
namespace reo::native::gameplay_presentation { class BackgroundState; class GraphicsState; class FrontendAssets; class CommonFrontendTextures; }
namespace reo::native::gameplay_world { class World; }
namespace reo::native::gameplay_application {
class SessionAudio;
enum class FrontendStatus {completed,unavailable,busy,closed};
enum class FrontendStage {task_pool,background,graphics_color,graphics_flags,graphics_format,graphics_options,graphics_fog,callbacks,common_sound,textures,font,complete};
struct FrontendResult {FrontendStatus status{FrontendStatus::unavailable};FrontendStage stage{FrontendStage::task_pool};};
// The 1B22C0 frontend pool has a different lifetime and capacity from the
// gameplay linked-task Scheduler. It is established only at a fresh entry.
struct FrontendColdPool {
    static constexpr std::uint16_t end=0xffff;
    std::array<std::uint16_t,160> next{};
    std::array<std::uint16_t,256> free_indices{};
    std::uint16_t head{},count{};
};
struct FrontendLetterbox {
    std::uint8_t phase{};
    std::int32_t remaining{},total{};
    gameplay_scenario::DisplayRectangle top{},bottom{};
};
class SessionFrontend final {
public:
    SessionFrontend(const SessionFrontend&)=delete;
    SessionFrontend& operator=(const SessionFrontend&)=delete;
    // Executes the source-ordered 1BCCB0 prefix. An unavailable stage retains
    // completed earlier effects, and retries do not reset the cold pool.
    [[nodiscard]] FrontendResult begin()noexcept;
    [[nodiscard]] FrontendStatus close()noexcept;
    ~SessionFrontend();
    // The two slots installed by1BCCB0 are serviced after an actual app frame;
    // this does not invent the other resident scheduler's modes or callbacks.
    [[nodiscard]] FrontendStatus advance_display_callbacks()noexcept;
    [[nodiscard]] const std::optional<FrontendColdPool>& pool()const noexcept{return pool_;}
    [[nodiscard]] FrontendStage stage()const noexcept{return stage_;}
    const std::shared_ptr<const gameplay_presentation::CommonFrontendTextures>& common_textures()const noexcept{return common_textures_;}
    const gameplay_presentation::FontFace* font()const noexcept{return font_.get();}
    gameplay_presentation::FrontendTextGate& text_gate()noexcept{return text_gate_;}
    gameplay_scenario::DisplayFadeState& display_fade()noexcept{return fade_;}
    FrontendLetterbox& letterbox()noexcept{return bars_;}
private:
    friend class OfflineApplication;
    SessionFrontend(gameplay_world::World&,gameplay_presentation::BackgroundState&,gameplay_presentation::GraphicsState&,
        gameplay_scenario::TextCache&,std::shared_ptr<const reo::assets::Source>)noexcept;
    void bind_audio(SessionAudio* audio)noexcept{audio_=audio;}
    gameplay_world::World& world_;
    gameplay_presentation::BackgroundState& background_;
    gameplay_presentation::GraphicsState& graphics_;
    gameplay_scenario::TextCache& text_cache_;
    std::shared_ptr<const reo::assets::Source> source_;
    SessionAudio* audio_{};
    std::unique_ptr<gameplay_presentation::FrontendAssets> assets_;
    std::shared_ptr<const gameplay_presentation::CommonFrontendTextures> common_textures_;
    std::unique_ptr<gameplay_presentation::FontFace> font_;
    gameplay_presentation::FrontendTextGate text_gate_;
    gameplay_scenario::DisplayFadeState fade_;
    FrontendLetterbox bars_;
    std::array<std::uint8_t,2> callback_state_{},callback_initialized_{};
    std::optional<FrontendColdPool> pool_;
    FrontendStage stage_{FrontendStage::task_pool};
    bool running_{},closed_{};
};
}
