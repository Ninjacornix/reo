#pragma once
#include "consumer_pipeline.hpp"
#include <functional>
#include <memory>
namespace reo_gpu_static_consumer {
struct Item {
    Inputs input;
    std::shared_ptr<Output> output;
    Parameters parameters;
};
using GuardedGroupExport = std::function<void(Vulkan::CommandBuffer&, const std::vector<Item>&)>;
// Concrete orchestration adapter. Producer has already recorded staging for
// every item. The supplied exact producer exporter MUST validate all consumer
// certificates before ANY authority copy and set Committed9 after that copy.
inline void recordGroup(Vulkan::CommandBuffer& cmd, Pipeline& consumer,
                        const std::vector<Item>& items, uint64_t epoch,
                        const GuardedGroupExport& exportAuthority) {
    if (items.empty() || items.size() > 128u || !exportAuthority)
        throw std::invalid_argument("Invalid static consumer group");
    const Vulkan::Buffer* global = items.front().input.results;
    for (const auto& item : items) {
        if (!item.output || item.input.results != global)
            throw std::invalid_argument("Split static sticky authority");
        consumer.prepare(cmd, item.input, *item.output, item.parameters, epoch);
    }
    for (const auto& item : items)
        consumer.seal(cmd, item.input, *item.output, epoch);
    exportAuthority(cmd, items);
    // A late export/source/certificate refusal blanks ALL already expanded
    // output before GS may consume it, including jobs prepared earlier.
    for (const auto& item : items)
        consumer.publicationGate(cmd, item.input, *item.output, epoch);
}
} // namespace reo_gpu_static_consumer
