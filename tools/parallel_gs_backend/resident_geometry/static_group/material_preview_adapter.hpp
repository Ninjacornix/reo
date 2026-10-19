#pragma once
#include "resident_material_preview.hpp"
#include "group_adapter27.hpp"
namespace reo_gpu_mixed_material {
// Concrete implementation of the frozen adapter's source-record hook. This
// class does not authorize export, submit a fake receipt or set live gates.
class SourceCertificate final : public reo_gpu_static_group::PreviewCertificate {
    ParallelGS::GSInterface& gs_;
    ParallelGS::ResidentMaterialGroupPreviewHandle preview_;

  public:
    SourceCertificate(ParallelGS::GSInterface& gs,
                      ParallelGS::ResidentMaterialGroupPreviewHandle preview)
        : gs_(gs), preview_(std::move(preview)) {
        if (!preview_)
            throw std::invalid_argument("Missing actual GS material preview");
    }
    const Vulkan::Device* owner() const override {
        return preview_->owner();
    }
    uint64_t epoch() const override {
        return preview_->epoch();
    }
    uint32_t transactionGeneration() const override {
        return preview_->generation();
    }
    void
    recordSourceCertificate(Vulkan::CommandBuffer& cmd,
                            const reo_gpu_batched_stream_consumer::Inputs& inputs,
                            const reo_gpu_batched_stream_consumer::Output& output) const override {
        if (inputs.owner != owner() || output.owner() != owner() || output.epoch() != epoch() ||
            output.generation() != transactionGeneration() || output.jobs() != preview_->jobs() ||
            !inputs.results)
            throw std::invalid_argument(
                "Actual GS preview is stale or foreign to the group source");
        using Binding = ParallelGS::ResidentMaterialGroupOutputBinding;
        auto binding = std::shared_ptr<Binding>(new Binding());
        binding->owner_ = const_cast<Vulkan::Device*>(output.owner());
        binding->epoch_ = output.epoch();
        binding->generation_ = output.generation();
        binding->jobs_ = output.jobs();
        for (unsigned bank = 0; bank < 5; ++bank) {
            auto* b = const_cast<Vulkan::Buffer*>(&output.bank(bank));
            b->add_reference();
            binding->banks_[bank] = Vulkan::BufferHandle(b);
        }
        for (uint32_t job = 0; job < output.jobs(); ++job)
            for (uint32_t chunk = 0; chunk < output.chunks(job); ++chunk)
                binding->views_.push_back({job, chunk, output.inputs(job, chunk, output.epoch())});
        if (!gs_.record_resident_material_group_source_certificate(
                preview_, cmd, std::move(binding), *inputs.results))
            throw std::invalid_argument(
                "Actual GS source-output binding is stale or foreign to the group source");
    }
};
} // namespace reo_gpu_mixed_material
