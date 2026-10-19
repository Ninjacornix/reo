#include "gpu_palette_origin/palette_observer.hpp"
bool ReoInstallPaletteOriginObserver(PS2Runtime& runtime) {
    return reo_palette_observer::install(runtime);
}
