#pragma once
#include "resident_draw.hpp"
#include <array>
#include <vector>

namespace ParallelGS {
// Immutable command/material metadata. Contains no host vertex data or bounds
// derived from vertices. Texture images are kept alive through native submission.
struct ResidentMaterial {
    std::vector<uint8_t> registers;
    uint64_t textureFlushCounter=0;
    RenderPass pass{};
    PrimitiveAttribute primitive{};
    std::vector<StateVector> states;
    std::vector<TextureInfo> textures;
    std::vector<Vulkan::ImageHandle> images;
};
}
