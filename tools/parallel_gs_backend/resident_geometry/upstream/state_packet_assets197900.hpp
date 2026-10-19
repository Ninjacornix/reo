#pragma once
#include "viewport_assets.hpp"
namespace reo_gpu_upstream {
inline void attachStatePacket197900Assets(reo_gpu_palette_parent::Modules& modules,
                                          const std::filesystem::path& directory,
                                          bool explicitlyRequested = false) {
    if (!explicitlyRequested)
        return;
    for (const auto& stage : modules.statePacket197900)
        if (!stage.empty())
            throw std::invalid_argument("197900 stage asset already attached");
    if (!modules.statePacketAllocator.empty() || !modules.statePacketQueueHeaders.empty() ||
        !modules.statePacketQueueJournal.empty())
        throw std::invalid_argument("197900 helper asset already attached");
    std::array<std::vector<uint32_t>, 3> stages{
        viewportAsset(directory / "state197900_stage1.spv",
                      "4abb37170c0c62505b9fa9f24f7d8aecbb048b1b37dfa2578ef46880ff250249"),
        viewportAsset(directory / "state197900_stage2.spv",
                      "7f52eafc0fafa4f9b341af4d4a29d85b4a59a451ac979dec65e80377af2a7d8c"),
        viewportAsset(directory / "state197900_stage3.spv",
                      "aa2fac258de837e5214b63e4110999571dd48669aba5b8697ea2af54f6e5ee85")};
    auto allocator =
        viewportAsset(directory / "state197900_allocator.spv",
                      "32a03c43312a9487df6a0178c0392e04e854d73c33510976fd1a415361a26810");
    auto headers =
        viewportAsset(directory / "state197900_queue_headers.spv",
                      "3b4ef85f0b4147a9a049b5e3cd6d577886fd8e37720cacbe09dff011428b0ae5");
    auto journal =
        viewportAsset(directory / "state197900_queue_journal.spv",
                      "b4c3c39ac8d7834c256b06b8c541f35ccb2f0da80f4b9d9d77134a4528e376f3");
    modules.statePacket197900 = std::move(stages);
    modules.statePacketAllocator = std::move(allocator);
    modules.statePacketQueueHeaders = std::move(headers);
    modules.statePacketQueueJournal = std::move(journal);
    // Attachment grants no source proof, natural route or global readiness.
}
} // namespace reo_gpu_upstream
