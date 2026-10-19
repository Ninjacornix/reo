#pragma once
#include "group_adapter27.hpp"
#include "typed_static_builder.hpp"
#include "material_preview_adapter.hpp"
#include "resident_preview_source_words.hpp"
namespace reo_gpu_static_group {
struct Configuration {
    bool activationRequested = false;
    std::shared_ptr<const reo_resident_live::Program> program;
    GroupModules modules;
    Scope scope = Scope::ScopedLive;
    LiveProofs proofs{};
    reo_gpu_static_stream_export::Proofs exporterProofs{};
    uint32_t capacity = 128;
};
struct Run {
    GroupOutput output;
    ParallelGS::ResidentMaterialGroupPreviewHandle preview;
    uint32_t lastGeometry = ~0u;
};
inline void prewarmPreviewSource(Vulkan::Device& device) {
    Vulkan::ResourceLayout l{};
    l.sets[0].storage_buffer_mask = 15;
    l.push_constant_size = 16;
    for (unsigned b = 0; b < 4; ++b)
        l.sets[0].meta[b].array_size = 1;
    auto* p = device.request_program(ParallelGS::ResidentPreviewSourceWords,
                                     sizeof(ParallelGS::ResidentPreviewSourceWords), &l);
    if (!p || !p->get_pipeline_layout())
        throw std::runtime_error("Static preview source pipeline unavailable");
    auto cmd = device.request_command_buffer(Vulkan::CommandBuffer::Type::Generic);
    if (!cmd)
        throw std::runtime_error("Static preview source prewarm command unavailable");
    cmd->set_program(p);
    Vulkan::DeferredPipelineCompile state{};
    cmd->extract_pipeline_state(state);
    auto pipeline = p->get_pipeline(state.hash);
    if (pipeline.pipeline == VK_NULL_HANDLE)
        pipeline = Vulkan::CommandBuffer::build_compute_pipeline(
            &device, state, Vulkan::CommandBuffer::CompileMode::Sync);
    if (pipeline.pipeline == VK_NULL_HANDLE)
        throw std::runtime_error("Static preview source driver prewarm failed");
    device.submit(cmd);
}
} // namespace reo_gpu_static_group
