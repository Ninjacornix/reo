/* stb_image_write implementation for the standalone replay tool.
 * runtime/gs/gs_renderer.cpp declares stbi_write_png extern "C"; inside reo_recomp
 * raylib provides it, but reo-gs-replay does not link raylib. */
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "runtime/gs/stb_image_write.h"
