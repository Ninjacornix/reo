#pragma once
#include "boundary_pipeline.hpp"
#include "resident_mesh_pool.hpp"
namespace reo_gpu_boundary {
inline void copyOutputs(Vulkan::CommandBuffer& cmd, Pipeline& source,
                        const Authority& authoritative, const reo_gpu_mesh_pool::MeshPool& pool,
                        const reo_gpu_mesh_pool::MeshPool::Slice& slice) {
    pool.validate(slice);
    if (pool.owner() != authoritative.owner)
        throw std::invalid_argument("Boundary output pool differs from authority owner");
    source.copy(cmd, pool.bank(reo_gpu_mesh_pool::MeshPool::Events),
                slice.offsets[reo_gpu_mesh_pool::MeshPool::Events], source.events(), 0, 16400);
    source.copy(cmd, pool.bank(reo_gpu_mesh_pool::MeshPool::NativeVertices),
                slice.offsets[reo_gpu_mesh_pool::MeshPool::NativeVertices], source.native(), 0,
                32768);
    source.copy(cmd, pool.bank(reo_gpu_mesh_pool::MeshPool::History),
                slice.offsets[reo_gpu_mesh_pool::MeshPool::History], source.history(), 0, 96);
    source.copy(cmd, pool.bank(reo_gpu_mesh_pool::MeshPool::CompletionTape),
                slice.offsets[reo_gpu_mesh_pool::MeshPool::CompletionTape],
                *authoritative.completion, 0, 48);
    // Commit's sticky status already gates EffectValidate, strip expansion and
    // subsequent whole-program epochs. Every copied output slice stays alive
    // through the existing actual GS retirement; no host output is consumed.
}
} // namespace reo_gpu_boundary
