#pragma once
#include <cstring>
#include <cstdint>
#include <stdexcept>

namespace reo::graphics {
inline unsigned internalResolution(const char* value) {
    if(!value || !*value || std::strcmp(value,"1")==0) return 1;
    if(std::strcmp(value,"2")==0) return 2;
    throw std::invalid_argument("Internal resolution must be Native (1) or 2x (2)");
}
// DISPLAY is briefly zero while the guest sets up its video mode. Upscaling
// that transitional state would turn a 2560-pixel scanout into 5120 pixels,
// beyond the runtime's 4096-pixel capture limit. Preserve Native until each
// enabled circuit has a display width; the guest registers stay untouched.
inline bool highResolutionScanout(unsigned scale, uint64_t pmode,
                                  uint64_t display1, uint64_t display2) {
    if (scale != 2 || !(pmode & 3)) return false;
    return (!(pmode & 1) || ((display1 >> 32) & 0xFFF)) &&
           (!(pmode & 2) || ((display2 >> 32) & 0xFFF));
}
}
