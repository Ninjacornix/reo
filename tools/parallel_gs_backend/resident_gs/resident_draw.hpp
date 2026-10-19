#pragma once
#include "gs_renderer.hpp"

namespace ParallelGS {
// Private isolated first-batch seam. Material/state coordination is CPU-owned;
// all positions, varyings, primitive bounds and expansion are GPU-owned.
struct ResidentPrimitiveInputs {
    Vulkan::Device* owner=nullptr;
    Vulkan::BufferHandle positions,attributes,primitives;
    VkDeviceSize positionOffset=0,attributeOffset=0,primitiveOffset=0;
    uint32_t primitiveCount=0;
    bool exactFixedTopologyCertificate=false;
};
using ResidentReferenceSink=void(*)(const RenderPass&,const VertexPosition*,
                                  const VertexAttribute*,const PrimitiveAttribute*,void*);
}
