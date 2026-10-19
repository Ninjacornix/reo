#pragma once
#include "consumer_pipeline.hpp"
#include "retirement_scope.hpp"
#include "gs_interface.hpp"
#include "resident_material.hpp"
#include <memory>
namespace reo_gpu_static_consumer {
// Private owner integration candidate. The exact full-image registry must
// invoke this branch before the bounded0/1 EffectValidate/mesh-pool route.
class TailOwner {
    Vulkan::Device& device_;
    ParallelGS::GSInterface& gs_;

  public:
    TailOwner(Vulkan::Device& d, ParallelGS::GSInterface& gs) : device_(d), gs_(gs) {}
    bool admit(const uint8_t* actualImage, const uint8_t* registeredImage, size_t imageBytes,
               const Item& item, uint64_t epoch) const {
        if (!actualImage || !registeredImage || imageBytes != 16384u ||
            std::memcmp(actualImage, registeredImage, imageBytes) || !item.output ||
            item.output->owner() != &device_ || item.input.owner != &device_ ||
            item.output->epoch() != epoch ||
            (item.parameters.geometry[2] != 0u && item.parameters.geometry[2] != 4u))
            return false;
        const auto prim = (item.parameters.mainTag[1] >> 15u) & 2047u;
        // The private material API prepares a projected raw PRIM view while actual
        // registers and queue remain unchanged until successful retirement.
        return prim <= 2047u && (prim & 7u) == 4u;
    }
    Parameters parameters(const ParallelGS::ResidentMaterial& material, Parameters p) const {
        if (material.registers.size() != sizeof(ParallelGS::RegisterState))
            throw std::invalid_argument("Missing projected command material snapshot");
        ParallelGS::RegisterState r;
        std::memcpy(&r, material.registers.data(), sizeof(r));
        const auto& c = r.ctx[r.prim.desc.CTXT];
        p.offsetScissorLo = {int32_t(c.xyoffset.desc.OFX), int32_t(c.xyoffset.desc.OFY),
                             int32_t(c.scissor.desc.SCAX0), int32_t(c.scissor.desc.SCAY0)};
        p.scissorHi = {int32_t(c.scissor.desc.SCAX1), int32_t(c.scissor.desc.SCAY1), 0, 0};
        std::memcpy(p.material.data(), &material.primitive.state, 24);
        return p;
    }
    bool retire(const Item& item, const reo_resident_live::Retired& receipt,
                uint64_t expectedGeneration, uint64_t expectedOrdinal) {
        if (!item.output || item.output->owner() != &device_ || item.input.owner != &device_ ||
            receipt.epoch != item.output->epoch() || receipt.bankGeneration != expectedGeneration ||
            receipt.ordinal != expectedOrdinal || receipt.status || !receipt.ended ||
            receipt.exhausted || !receipt.eventCount ||
            receipt.eventCount > 2u * item.parameters.limits[0] + 1u ||
            (item.parameters.geometry[2] != 0u && item.parameters.geometry[2] != 4u))
            return false;
        auto* certificate = const_cast<Vulkan::Buffer*>(&item.output->bank(3));
        // Granite's raw-pointer IntrusivePtr constructor adopts a reference. Add
        // exactly one reference so the GS lease remains alive after owner retirement.
        certificate->add_reference();
        Vulkan::BufferHandle hold(certificate);
        return gs_.adopt_resident_gpu_tail(&device_, std::move(hold), FinalQueueBase * 4u,
                                           receipt.epoch, receipt.bankGeneration,
                                           (item.parameters.mainTag[1] >> 15u) & 2047u, true);
    }
};
} // namespace reo_gpu_static_consumer
