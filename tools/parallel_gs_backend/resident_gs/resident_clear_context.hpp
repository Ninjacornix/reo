#pragma once
#include "device.hpp"
#include "command_buffer.hpp"
#include "tools/parallel_gs_backend/resident_geometry/enrollment/sha256.hpp"
#include <cstring>
#include <array>
#include <stdexcept>
#include <vector>
namespace reo_gpu_clear_context {
struct Parameters {
    uint32_t rgba,fbmsk,fbp,fbw,psm,fba,x0,y0,x1,y1,vramBytes,phase;
};
static_assert(sizeof(Parameters)==48);
// Only literal FRAME/FBA/SCISSOR fields and the original SDK color enter here.
// Actual GS integration supplies its own existing GPU VRAM buffer and queue.
class ClearContext final {
    Vulkan::Device& device_;std::array<Vulkan::Program*,3> program_{};Vulkan::BufferHandle control_;
public:
    ClearContext(Vulkan::Device& device,const std::array<std::vector<uint32_t>,3>& modules):device_(device){
        static constexpr const char* Pins[3]={"a5010f6208c4834357922684f352ee2794333080032cb9d224c4071fa0561fb3","bf6a31b2fb50664896a4d37d00ddd7408388dae5f198e2625a30fd20964d4a37","67b1c90c629540f8bc0bb0732ab7a578f4920acdc93518e5b861a81b7ba8fc47"};
        for(unsigned stage=0;stage<3u;++stage){
            const auto& module=modules[stage];
            if(module.size()<5u||module[0]!=0x07230203u)throw std::invalid_argument("GPU context clear module missing");
            std::vector<uint8_t> bytes(module.size()*4u);std::memcpy(bytes.data(),module.data(),bytes.size());
            if(reo_gpu_catalog::sha256(bytes)!=Pins[stage])throw std::invalid_argument("GPU context clear exact shader pin differs");
            Vulkan::ResourceLayout shape{};shape.sets[0].storage_buffer_mask=3u;shape.push_constant_size=sizeof(Parameters);for(unsigned b=0;b<2u;++b)shape.sets[0].meta[b].array_size=1u;
            program_[stage]=device.request_program(module.data(),module.size()*4u,&shape);if(!program_[stage]||!program_[stage]->get_pipeline_layout())throw std::runtime_error("GPU context clear program unavailable");
            const auto& layout=program_[stage]->get_pipeline_layout()->get_resource_layout();
            if(layout.descriptor_set_mask!=1u||layout.bindless_descriptor_set_mask||layout.sets[0].storage_buffer_mask!=3u||layout.push_constant_range.offset||layout.push_constant_range.size!=sizeof(Parameters)||layout.push_constant_range.stageFlags!=VK_SHADER_STAGE_COMPUTE_BIT)throw std::invalid_argument("GPU context clear physical ABI differs");
            for(unsigned b=0;b<2u;++b)if(layout.sets[0].meta[b].array_size!=1u||layout.stages_for_bindings[0][b]!=VK_SHADER_STAGE_COMPUTE_BIT)throw std::invalid_argument("GPU context clear binding differs");
        }
        Vulkan::BufferCreateInfo ci{};ci.domain=Vulkan::BufferDomain::Device;ci.size=64u;ci.usage=VK_BUFFER_USAGE_STORAGE_BUFFER_BIT|VK_BUFFER_USAGE_TRANSFER_SRC_BIT;control_=device.create_buffer(ci);if(!control_)throw std::runtime_error("GPU context clear control allocation failed");
    }
    ClearContext(const ClearContext&)=delete;
    static bool accepts(const Parameters& p){return p.fbw>0u&&p.fbw<=63u&&p.fbp<=511u&&(p.psm==0u||p.psm==1u||p.psm==2u||p.psm==10u)&&p.fba<=1u&&p.x0<=2047u&&p.x1<=2047u&&p.y0<=2047u&&p.y1<=2047u&&p.vramBytes==4194304u;}
    Vulkan::Device& device()const noexcept{return device_;}
    const Vulkan::Buffer& control()const noexcept{return *control_;}
    void record(Vulkan::CommandBuffer& cmd,const Vulkan::Buffer& actualVram,Parameters p)const{
        const auto& ci=actualVram.get_create_info();
        const bool gpuDomain=ci.domain==Vulkan::BufferDomain::Device||ci.domain==Vulkan::BufferDomain::UMACachedCoherentPreferDevice;
        if(&cmd.get_device()!=&device_||!accepts(p)||!gpuDomain||ci.size<p.vramBytes||(ci.usage&VK_BUFFER_USAGE_STORAGE_BUFFER_BIT)==0)throw std::invalid_argument("GPU context clear exact GS device/buffer/command domain differs");
        cmd.buffer_barrier(actualVram,VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT,VK_ACCESS_2_MEMORY_READ_BIT|VK_ACCESS_2_MEMORY_WRITE_BIT,VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT,VK_ACCESS_2_SHADER_STORAGE_READ_BIT|VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
        cmd.buffer_barrier(*control_,VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT,VK_ACCESS_2_MEMORY_READ_BIT|VK_ACCESS_2_MEMORY_WRITE_BIT,VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT,VK_ACCESS_2_SHADER_STORAGE_READ_BIT|VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
        cmd.set_specialization_constant_mask(0);cmd.set_program(program_[0]);cmd.set_storage_buffer(0,0,actualVram);cmd.set_storage_buffer(0,1,*control_);
        p.phase=0u;cmd.push_constants(&p,0,sizeof(p));cmd.dispatch(1u,1u,1u);
        const auto stageBarrier=[&](){cmd.buffer_barrier(*control_,VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT,VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT,VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT,VK_ACCESS_2_SHADER_STORAGE_READ_BIT|VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);};
        stageBarrier();cmd.set_program(program_[1]);p.phase=1u;cmd.push_constants(&p,0,sizeof(p));cmd.dispatch(256u,1u,1u);
        stageBarrier();cmd.set_program(program_[2]);p.phase=2u;cmd.push_constants(&p,0,sizeof(p));cmd.dispatch(256u,1u,1u);
        cmd.buffer_barrier(actualVram,VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT,VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT,VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT,VK_ACCESS_2_MEMORY_READ_BIT|VK_ACCESS_2_MEMORY_WRITE_BIT);
        cmd.set_specialization_constant_mask(0);
    }
    static constexpr bool ActualDeviceParityProved=false,ActualGsOrderingProved=false;
};
}
