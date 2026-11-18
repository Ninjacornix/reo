#pragma once
#include "../audio_clip_loader/loader.hpp"
#include "../adxt_instances/instances.hpp"
#include <string_view>

namespace reo::native::audio_cue_queue {
enum class Status { completed, pending, capacity, invalid_input, invalid_owner,
    already_started, unsupported_profile, source_failure, no_memory, fault, closed };
struct Config { std::uint32_t channels{2}, encoded_capacity{65536}; };
struct Entry { Status status{Status::fault}; std::uint64_t receipt{}; };
struct Snapshot {
    std::uint32_t preparing{}, queued{}, registered_assets{};
    std::uint64_t accepted{}, submitted_sources{};
    audio_clip_loader::Status preparation_status{audio_clip_loader::Status::pending};
    adx_sequence::Status clip_status{adx_sequence::Status::invalid_input};
    adxt_instances::Status source_status{adxt_instances::Status::completed};
    adxt_instances::Status retirement_status{adxt_instances::Status::completed};
    Status failure{Status::completed};
    bool bound{}, play_requested{}, source_submitted{}, repeat{}, decoder_ended{}, failed{}, closed{};
};
// Native cue IDs and immutable resource views only. Every operation, including
// snapshot(), uses the same externally serialized instance-owner borrow as its
// player. No guest memory, original file service or source-provider reads occur.
// Bind once to an existing stable instance. Stop/close before destroying this
// controller; actual source join remains the canonical instance owner's job.
class Queue final {
public:
    Queue(Config,std::shared_ptr<audio_clip_loader::Loader>);
    ~Queue();
    Queue(const Queue&)=delete;
    Queue& operator=(const Queue&)=delete;
    [[nodiscard]] Status bind(adxt_instances::Instances&,const adxt_instances::Key&) noexcept;
    [[nodiscard]] Entry enqueue(adxt_instances::Instances&,std::string_view native_id,
        std::shared_ptr<const resources::ByteView>) noexcept;
    [[nodiscard]] Status start(adxt_instances::Instances&,std::uint32_t tick) noexcept;
    [[nodiscard]] Status service(adxt_instances::Instances&,std::uint32_t tick) noexcept;
    [[nodiscard]] Status repeat(adxt_instances::Instances&,bool) noexcept;
    [[nodiscard]] Status clear(adxt_instances::Instances&) noexcept;
    [[nodiscard]] Status stop(adxt_instances::Instances&) noexcept;
    [[nodiscard]] Status close(adxt_instances::Instances&) noexcept;
    [[nodiscard]] Snapshot snapshot() const noexcept;
private:
    struct State;
    std::unique_ptr<State> state_;
};
}
