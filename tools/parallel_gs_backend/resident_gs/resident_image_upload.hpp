#pragma once
#include "device.hpp"
#include "../resident_geometry/enrollment/sha256.hpp"
#include <cstring>
#include <stdexcept>
#include <vector>

namespace ParallelGS {
inline bool resident_image_upload_layout(const Vulkan::Program* program)
{
    if(!program||!program->get_pipeline_layout())return false;
    const auto& r=program->get_pipeline_layout()->get_resource_layout();
    return r.descriptor_set_mask==1u&&!r.bindless_descriptor_set_mask&&
        r.sets[0].storage_buffer_mask==1u&&r.sets[0].sampled_image_mask==2u&&
        !r.sets[0].fp_mask&&!r.sets[0].storage_image_mask&&
        r.sets[0].meta[0].array_size==1u&&r.sets[0].meta[1].array_size==1u&&
        r.stages_for_bindings[0][0]==VK_SHADER_STAGE_COMPUTE_BIT&&
        r.stages_for_bindings[0][1]==VK_SHADER_STAGE_COMPUTE_BIT&&
        r.push_constant_range.offset==0u&&r.push_constant_range.size==48u&&
        r.push_constant_range.stageFlags==VK_SHADER_STAGE_COMPUTE_BIT;
}
inline Vulkan::Program* create_resident_image_upload_program(Vulkan::Device& device,
    const std::vector<uint32_t>& module)
{
    std::vector<uint8_t> bytes(module.size()*4u);
    if(!module.empty())std::memcpy(bytes.data(),module.data(),bytes.size());
    if(reo_gpu_catalog::sha256(bytes)!="5f6cbab744047fbfefc122098b24acdcc6e9809cfcbc323436cec9d972c8cedd")
        throw std::invalid_argument("Resident IMAGE upload shader identity differs");
    Vulkan::ResourceLayout layout{};
    layout.sets[0].storage_buffer_mask=1u;layout.sets[0].sampled_image_mask=2u;
    layout.sets[0].meta[0].array_size=1u;layout.sets[0].meta[1].array_size=1u;
    layout.push_constant_size=48u;
    auto* program=device.request_program(module.data(),module.size()*4u,&layout);
    if(!resident_image_upload_layout(program))throw std::runtime_error("Resident IMAGE upload interface differs");
    return program;
}
}
