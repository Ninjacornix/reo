#pragma once
#include <cstring>
#include <cstdint>
#include <stdexcept>

namespace reo::graphics {
inline unsigned internalResolution(const char* value) {
    if(!value || !*value || std::strcmp(value,"1")==0) return 1;
    if(std::strcmp(value,"2")==0) return 2;
    if(std::strcmp(value,"4")==0) return 4;
    throw std::invalid_argument("Internal resolution must be Native (1), 2x (2), or 4x (4)");
}
// DISPLAY is briefly zero while the guest sets up its video mode. Upscaling
// that transitional state would turn a 2560-pixel scanout into 5120 pixels,
// beyond the runtime's 4096-pixel capture limit. Preserve Native until each
// enabled circuit has a display width and its scaled dimensions fit; the
// guest registers stay untouched.
inline bool highResolutionScanout(unsigned scale, uint64_t pmode,
                                  uint64_t display1, uint64_t display2) {
    if ((scale != 2 && scale != 4) || !(pmode & 3)) return false;
    auto ready = [scale](uint64_t display) {
        const unsigned dw = unsigned((display >> 32) & 0xFFF);
        const unsigned dh = unsigned((display >> 44) & 0x7FF);
        const unsigned magh = unsigned((display >> 23) & 0xF) + 1;
        const unsigned magv = unsigned((display >> 27) & 3) + 1;
        return dw && (dw + 1) / magh <= 4096 / scale &&
                     (dh + 1) / magv <= 4096 / scale;
    };
    return (!(pmode & 1) || ready(display1)) && (!(pmode & 2) || ready(display2));
}
}
