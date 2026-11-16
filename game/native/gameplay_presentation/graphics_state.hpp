#pragma once
#include <array>
#include <cstdint>
#include <optional>
namespace reo::native::gameplay_presentation {
struct GraphicsColor {std::uint32_t packed{};std::array<float,3> rgb{};float alpha{};};
struct GraphicsFog {float near_distance{},far_distance{};std::array<std::uint8_t,3> color{};};
struct FrontendDrawControls {
    std::uint32_t selector0c{},selector66{},selector62{},selector02{},selector00{},selector5e{},selector63{};
    bool supported_by_cpu()const noexcept{return selector0c==0&&selector66==0&&selector62==0&&selector02==0&&selector00==0&&selector5e==50&&selector63==0x10000;}
};
enum class GraphicsColorMode {raw,normalized};
// Native state for the admitted 196010 selector prefix. Color alpha follows
// the source's GS-domain 0..128 convention; RGB channels are normalized.
class GraphicsState final {
public:
    void set_color(std::uint32_t)noexcept;
    // Selector 1, argument 0x200, selects the source normalized-color path.
    void select_normalized_color()noexcept{mode_=GraphicsColorMode::normalized;model_color_=0x200;}
    //1963A8 clears the complete selector1 format nibble before publishing
    // its admitted value. Keep model imports on the same canonical state.
    void select_model_color(std::uint32_t value)noexcept{
        model_color_=value;
        mode_=value==0x200?GraphicsColorMode::normalized:GraphicsColorMode::raw;
    }
    const std::optional<std::uint32_t>& model_color()const noexcept{return model_color_;}
    // 196010 selector 0x15 replaces the two low format bits. The native
    // consumer retains just those bits, independently of unrelated options.
    void select_format(std::uint32_t value)noexcept{
        format_flags_=value==2?2u:0u;
        format_known_=true;
    }
    std::optional<std::uint32_t> format_flags()const noexcept{
        return format_known_?std::optional<std::uint32_t>{format_flags_}:std::nullopt;
    }
    // Selector 0x12 clears bits 0x18000 and sets bit 0x8000 only for
    // that exact input. It is captured alongside the format at mesh import.
    void select_option_12(std::uint32_t value)noexcept{
        option_12_=value==0x8000u;
    }
    std::optional<bool> option_12()const noexcept{return option_12_;}
    // The contiguous, infallible first four selector calls in 1AF0C0.
    void initialize_frontend_prefix()noexcept{
        set_color(0);select_normalized_color();select_format(2);select_option_12(0);
    }
    // 1AF0C0's contiguous fog publications, subsequently consumed by the CPU
    // renderer when no scene fog has yet been published.
    void initialize_frontend_fog()noexcept{frontend_fog_=GraphicsFog{500.f,10000.f,{255,255,255}};}
    const std::optional<GraphicsFog>& frontend_fog()const noexcept{return frontend_fog_;}
    void initialize_frontend_draw_controls()noexcept{frontend_controls_=FrontendDrawControls{0,0,0,0,0,50,0x10000};}
    const std::optional<FrontendDrawControls>& frontend_draw_controls()const noexcept{return frontend_controls_;}
    bool select_model_draw_controls(bool scenario_objects)noexcept{
        if(!frontend_controls_)return false;
        frontend_controls_->selector0c=0;frontend_controls_->selector66=scenario_objects?1:0;
        frontend_controls_->selector62=1;frontend_controls_->selector02=0;frontend_controls_->selector00=scenario_objects?0x20:0;
        return true;
    }
    const std::optional<GraphicsColor>& color()const noexcept{return color_;}
    std::optional<GraphicsColorMode> color_mode()const noexcept{return mode_;}
private:
    std::optional<GraphicsColor> color_;
    std::optional<GraphicsColorMode> mode_;
    std::optional<std::uint32_t> model_color_;
    std::optional<bool> option_12_;
    std::optional<GraphicsFog> frontend_fog_;
    std::optional<FrontendDrawControls> frontend_controls_;
    std::uint32_t format_flags_{};
    bool format_known_{};
};
}
