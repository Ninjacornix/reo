#include "graphics_state.hpp"
#include <algorithm>
namespace reo::native::gameplay_presentation {
void GraphicsState::set_color(std::uint32_t value)noexcept{
    GraphicsColor result;result.packed=value;
    result.rgb={float((value>>16)&255u)/255.f,float((value>>8)&255u)/255.f,float(value&255u)/255.f};
    const auto alpha=(value>>24)&255u;
    result.alpha=float(alpha==255?128:alpha?std::max(1u,alpha>>1):0u);
    color_=result;
}
}
