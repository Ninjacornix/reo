#pragma once
#include "device.hpp"
#include "vram_copy_offset29_data.hpp"
#include <array>
#include <stdexcept>
#include <cstring>
namespace reo_gpu_vram_copy29 {
inline Vulkan::ResourceLayout originalLayout(){Vulkan::ResourceLayout result{};if(!result.unserialize(Layout,sizeof(Layout)))throw std::runtime_error("Corrected VRAM copy exact baked layout is incompatible");return result;}
inline Vulkan::Program* request(Vulkan::Device& device,const Vulkan::Program* original=nullptr){
    auto layout=originalLayout();
    if(original){
        const auto* shader=original->get_shader(Vulkan::ShaderStage::Compute);std::array<uint8_t,sizeof(Layout)> serialized{};
        if(!shader||!shader->get_layout().serialize(serialized.data(),serialized.size())||std::memcmp(serialized.data(),Layout,sizeof(Layout)))throw std::invalid_argument("Corrected VRAM copy does not match this original baked program ABI");
    }
    auto* result=device.request_program(Module,sizeof(Module),&layout);if(!result||!result->get_pipeline_layout())throw std::runtime_error("Corrected VRAM copy program creation failed");return result;
}
inline constexpr bool ActualDeviceParityProved=false;
}
