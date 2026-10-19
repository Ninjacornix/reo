#pragma once
#include "device.hpp"
#include "command_buffer.hpp"
#include "tools/parallel_gs_backend/resident_geometry/enrollment/sha256.hpp"
#include <array>
#include <vector>
#include <cstring>
#include <stdexcept>
namespace reo_gpu_readback {
struct Parameters { uint32_t base,stride,psm,x,y,width,height,bytes; };
static_assert(sizeof(Parameters)==32);
inline uint32_t bytesPerPixel(uint32_t psm) {
    switch(psm){case 0:case 48:return 4;case 1:case 49:return 3;case 2:case 10:case 50:case 58:return 2;case 19:case 27:return 1;default:throw std::invalid_argument("Unsupported original local-to-host format");}
}
class Readback final {
    Vulkan::Device& device_;Vulkan::Program* program_=nullptr;
public:
    Readback(Vulkan::Device& device,const std::vector<uint32_t>& module):device_(device){
        std::vector<uint8_t> bytes(module.size()*4u);std::memcpy(bytes.data(),module.data(),bytes.size());
        if(module.size()<5||module[0]!=0x07230203||reo_gpu_catalog::sha256(bytes)!="3685bcca951591cd43ff0117adf53c866771614b38c550f506c07828cc67537c")throw std::invalid_argument("GPU readback shader pin differs");
        Vulkan::ResourceLayout shape{};shape.sets[0].storage_buffer_mask=3u;shape.push_constant_size=sizeof(Parameters);for(unsigned b=0;b<2;++b)shape.sets[0].meta[b].array_size=1;
        program_=device.request_program(module.data(),module.size()*4u,&shape);if(!program_||!program_->get_pipeline_layout())throw std::runtime_error("GPU readback program missing");
        const auto& layout=program_->get_pipeline_layout()->get_resource_layout();if(layout.descriptor_set_mask!=1u||layout.bindless_descriptor_set_mask||layout.sets[0].storage_buffer_mask!=3u||layout.push_constant_range.offset||layout.push_constant_range.size!=sizeof(Parameters)||layout.push_constant_range.stageFlags!=VK_SHADER_STAGE_COMPUTE_BIT)throw std::invalid_argument("GPU readback shader physical ABI differs");
        for(unsigned b=0;b<2;++b)if(layout.sets[0].meta[b].array_size!=1||layout.stages_for_bindings[0][b]!=VK_SHADER_STAGE_COMPUTE_BIT)throw std::invalid_argument("GPU readback binding differs");
    }
    std::vector<uint8_t> read(const Vulkan::Buffer& actualVram,Parameters p)const {
        const auto& ci=actualVram.get_create_info();const auto bpp=bytesPerPixel(p.psm);
        if(p.base>16383u||p.stride>63u||p.x>2047u||p.y>2047u||p.width>4095u||p.height>4095u||uint64_t(p.width)*p.height*bpp!=p.bytes||ci.size<4194304u||(ci.usage&VK_BUFFER_USAGE_STORAGE_BUFFER_BIT)==0)throw std::invalid_argument("GPU readback literal controls differ");
        if(!p.bytes)return {};
        const uint64_t padded=(uint64_t(p.bytes)+3u)&~uint64_t(3u);
        Vulkan::BufferCreateInfo outputInfo{};outputInfo.domain=Vulkan::BufferDomain::Device;outputInfo.size=padded;outputInfo.usage=VK_BUFFER_USAGE_STORAGE_BUFFER_BIT|VK_BUFFER_USAGE_TRANSFER_SRC_BIT;auto output=device_.create_buffer(outputInfo);
        Vulkan::BufferCreateInfo hostInfo{};hostInfo.domain=Vulkan::BufferDomain::CachedHost;hostInfo.size=padded;hostInfo.usage=VK_BUFFER_USAGE_TRANSFER_DST_BIT;auto host=device_.create_buffer(hostInfo);
        if(!output||!host)throw std::runtime_error("GPU readback buffers unavailable");
        auto command=device_.request_command_buffer(Vulkan::CommandBuffer::Type::Generic);
        command->buffer_barrier(actualVram,VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT,VK_ACCESS_2_MEMORY_WRITE_BIT,VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT,VK_ACCESS_2_SHADER_STORAGE_READ_BIT);
        command->set_specialization_constant_mask(0);command->set_program(program_);command->set_storage_buffer(0,0,actualVram);command->set_storage_buffer(0,1,*output);command->push_constants(&p,0,sizeof(p));
        const uint32_t groups=(p.bytes+255u)/256u;command->dispatch(groups<65535u?groups:65535u,(groups+65534u)/65535u,1);
        command->buffer_barrier(*output,VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT,VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT,VK_PIPELINE_STAGE_2_COPY_BIT,VK_ACCESS_2_TRANSFER_READ_BIT);
        command->copy_buffer(*host,*output);command->buffer_barrier(*host,VK_PIPELINE_STAGE_2_COPY_BIT,VK_ACCESS_2_TRANSFER_WRITE_BIT,VK_PIPELINE_STAGE_2_HOST_BIT,VK_ACCESS_2_HOST_READ_BIT);
        Vulkan::Fence fence;device_.submit(command,&fence);if(!fence)throw std::runtime_error("GPU readback actual fence missing");fence->wait();
        const void* mapped=device_.map_host_buffer(*host,Vulkan::MEMORY_ACCESS_READ_BIT);if(!mapped)throw std::runtime_error("GPU readback host transfer missing");
        std::vector<uint8_t> result(p.bytes);std::memcpy(result.data(),mapped,p.bytes);device_.unmap_host_buffer(*host,Vulkan::MEMORY_ACCESS_READ_BIT);return result;
    }
};
}
