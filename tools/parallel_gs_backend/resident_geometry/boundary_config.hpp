#pragma once
#include "resident_parallel_owner.hpp"
#include "resident_array_owner.hpp"
namespace reo_resident_live {
inline OwnerConfig makeHybridArrayOwnerConfig(const ShaderBundle& scalarGpuModules,
                                              reo_gpu_array_bridge::Bundle ordered,
                                              reo_gpu_boundary::Bundle boundary) {
    ArrayShaderBundle modules{};
    modules.whole2ea = scalarGpuModules.whole2ea;
    modules.strip = scalarGpuModules.strip;
    modules.unpack = scalarGpuModules.unpack;
    modules.whole2eaBinding = scalarGpuModules.whole2eaBinding;
    modules.programs = scalarGpuModules.programs;
    modules.effectValidate = scalarGpuModules.effectValidate;
    modules.bytePatch = scalarGpuModules.bytePatch;
    modules.orderedStream = std::move(ordered);
    modules.boundary = std::move(boundary);
    auto config = makeArrayResidentOwnerConfig(std::move(modules));
    config.enabled = false;
    config.fullProtocolCoverage = false;
    return config;
}
} // namespace reo_resident_live
