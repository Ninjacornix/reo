#pragma once
#include "../adxt_refill/adxt_refill.hpp"
#include <array>
#include <cstdint>
#include <memory>
#include <span>

namespace reo::native::adx_window::v2 {class StreamWindowOwner;}
namespace reo::native::adx_window::service_r4 {class StreamWindowOwner;}
namespace reo::native::adxt_shared_source {

enum class Status {completed,busy,closed,invalid_configuration,invalid_source,
    invalid_lease,invalid_count,id_exhausted,provider_failure,provider_protocol,
    ring_failure,reentrant_call,invariant_fault};
using Backend=adxt_refill::Backend;
using Config=adxt_refill::Config;
inline constexpr std::int32_t encoded_capacity=8192,encoded_extension=36;
inline constexpr std::int32_t maximum_encoded_capacity=static_cast<std::int32_t>(adxt_refill::maximum_source_read_bytes);
enum class CapacityProfile {fixed_8k,bounded_sectors};
[[nodiscard]] constexpr bool admits_capacity(std::int32_t value,CapacityProfile profile)noexcept{
    return profile==CapacityProfile::fixed_8k?value==encoded_capacity:
        profile==CapacityProfile::bounded_sectors && value>=2048 && value<=maximum_encoded_capacity && value%2048==0;
}
enum class FileTargetAction {none,file_loop};
enum class DecoderLimitAction {none,first_snapshot,repeat,seamless};
struct HeaderGeometry {
    std::int32_t loop_start_bytes{},loop_end_bytes{},loop_start_samples{},loop_end_samples{};
    friend bool operator==(const HeaderGeometry&,const HeaderGeometry&)=default;
};
struct LoopSnapshot {
    HeaderGeometry header;
    std::int32_t sample_limit{-1},target_sectors{};
    FileTargetAction file_action{FileTargetAction::none};
    DecoderLimitAction decoder_action{DecoderLimitAction::none};
    bool enabled{},alive{true};std::uint64_t epoch{1};
    friend bool operator==(const LoopSnapshot&,const LoopSnapshot&)=default;
};
struct InitialLoop {
    HeaderGeometry header;std::int32_t sample_limit{-1};
    FileTargetAction file_action{FileTargetAction::none};
    DecoderLimitAction decoder_action{DecoderLimitAction::none};bool enabled{};
};
struct LoopDomain;
// No public mutator or raw state reference. A single concrete Window2 receives
// this link. It does not keep the backend/control owner alive or grant reentry.
class WindowLink final {
public:
    WindowLink()=default;WindowLink(WindowLink&&)noexcept=default;
    WindowLink(const WindowLink&)=delete;WindowLink& operator=(const WindowLink&)=delete;
    WindowLink& operator=(WindowLink&&)=delete;
    [[nodiscard]] bool valid()const noexcept;
private:
    friend class SharedEncodedSource;
    friend class reo::native::adx_window::v2::StreamWindowOwner;
    friend class reo::native::adx_window::service_r4::StreamWindowOwner;
    std::shared_ptr<LoopDomain> domain_;std::uint64_t epoch_{};
    [[nodiscard]] Status configure(HeaderGeometry,std::int32_t sample_limit,
        std::int32_t target_sectors,FileTargetAction,DecoderLimitAction)noexcept;
    [[nodiscard]] Status set_sample_limit(std::int32_t,DecoderLimitAction)noexcept;
    [[nodiscard]] LoopSnapshot snapshot()const noexcept;
};
struct LinkResult {Status status{Status::invalid_lease};WindowLink link;};
struct PreparedPrefix {
    std::int32_t position{},progress_sectors{};
    std::span<const std::uint8_t> bytes; // Constructor-owned copy, not retained.
};
enum class BatchShape {one,two};
struct BatchRequest {BatchShape shape{BatchShape::one};std::int32_t first_max{},second_max{};};
enum class FinishKind {consume_single_prefix,restore_reverse,
    consume_first_prefix_restore_second,consume_second_prefix_consume_first};
struct FinishPlan {FinishKind kind;std::int32_t prefix_bytes{};};
struct LeaseDomain;
class ReadBatch final {
public:
    ReadBatch()=default;~ReadBatch()=default; // No credit return/I/O/join.
    ReadBatch(ReadBatch&&)noexcept;
    ReadBatch(const ReadBatch&)=delete;ReadBatch& operator=(const ReadBatch&)=delete;
    ReadBatch& operator=(ReadBatch&&)=delete;
    [[nodiscard]] std::uint32_t count()const noexcept;
    [[nodiscard]] std::int32_t offset(std::uint32_t)const noexcept;
    [[nodiscard]] std::int32_t bytes(std::uint32_t)const noexcept;
    [[nodiscard]] Status read_into(std::uint32_t,std::span<std::uint8_t>,std::size_t relative=0)const noexcept;
private:
    friend class SharedEncodedSource;
    std::shared_ptr<LeaseDomain> domain_;std::array<sjrb::Chunk,2> chunks_;
    std::uint64_t epoch_{},id_{};std::uint32_t count_{};
};
struct BatchResult {Status status{Status::invalid_lease};ReadBatch batch;};
struct Grant {std::int32_t offset{},bytes{};friend bool operator==(const Grant&,const Grant&)=default;};
enum class Transfer {none,acquire_producer,acquire_consumer,publish_data,restore_free,consume_data,restore_data};
struct Snapshot {
    sjrb::Snapshot ring;
    LoopSnapshot loop;
    std::int32_t state{},accepted_sectors{},progress_sectors{},cumulative_bytes{},retries{};
    Grant producer,producer_remaining;std::array<Grant,2> consumers{};std::uint32_t consumer_count{};
    std::uint8_t paused{};
    bool in_flight{},service_requested{},stop_requested{},close_requested{},source_open{},
        shutting_down{},joined{},ledger_fault{};
    std::uint64_t epoch{},request_id{},batch_id{};
    Transfer transfer{Transfer::none};std::int32_t transfer_bytes{};
    Status last_error{Status::completed};
};
struct TargetObservation {Snapshot before,after;};
struct Hooks {
    void* context{};
    // Synchronous read-only/nonreentrant observations, not action callbacks.
    void(*target)(void*,const TargetObservation&)noexcept{};
    sjrb::Hooks ring{};
};
struct ServiceResult {Status status{Status::completed};bool published{},target_invoked{},progress_rewound{},limit_removed{};};

// One externally serialized control owner. Workers touch PRIVATE backend result
// storage only. No Ring escape, independent-grant finish, cancellation on normal
// stop, reset/replacement, or generic mutating callback exists in this version.
class SharedEncodedSource final {
public:
    SharedEncodedSource(Config,std::shared_ptr<const resources::ByteView>,
        std::unique_ptr<Backend>,InitialLoop={},PreparedPrefix={},Hooks={},CapacityProfile=CapacityProfile::fixed_8k);
    ~SharedEncodedSource(); // Control-thread emergency backend fence, not stop.
    SharedEncodedSource(const SharedEncodedSource&)=delete;
    SharedEncodedSource& operator=(const SharedEncodedSource&)=delete;
    [[nodiscard]] Snapshot snapshot()const noexcept;
    [[nodiscard]] ServiceResult service()noexcept;
    [[nodiscard]] BatchResult borrow_batch(BatchRequest)noexcept;
    [[nodiscard]] Status finish_batch(ReadBatch&,FinishPlan)noexcept;
    [[nodiscard]] LinkResult take_window_link()noexcept;
    [[nodiscard]] Status set_loop_enabled(bool)noexcept;
    [[nodiscard]] Status set_paused(std::uint8_t)noexcept;
    [[nodiscard]] Status request_stop()noexcept;
    [[nodiscard]] Status request_close()noexcept;
    [[nodiscard]] Status begin_shutdown()noexcept;
    [[nodiscard]] bool finalize_shutdown_and_join()noexcept;
private:
    class Scope;
    Config config_;Hooks hooks_;sjrb::Ring ring_;
    std::shared_ptr<const resources::ByteView> view_;std::unique_ptr<Backend> backend_;
    std::shared_ptr<LeaseDomain> leases_;std::shared_ptr<LoopDomain> loop_;
    sjrb::Chunk producer_;std::array<sjrb::Chunk,2> consumers_;
    Snapshot state_;std::uint64_t last_request_{},last_batch_{};
    bool busy_{},linked_{};
    [[nodiscard]] Status fail(Status,bool terminal=false,bool ledger=false)noexcept;
    [[nodiscard]] Status return_producer(bool)noexcept;
    [[nodiscard]] ServiceResult publish(adxt_refill::Completion&)noexcept;
    [[nodiscard]] bool conservation()const noexcept;
};
} // namespace reo::native::adxt_shared_source
