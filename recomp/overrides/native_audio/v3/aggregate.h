// Derived from frozen Aggregate2; native stream-only composition profile.
// Mechanically derived from frozen Aggregate1 by derive.py; grouped packet3 contract.
#pragma once
#include "Kernel/Syscalls/Helpers/CriAudioBackend.h"
#include "game/native/pcm_bridge/session_bridge.hpp"
#include "game/native/adxt_output_session/session.hpp"
#include "game/native/audio_output/audio_output_owner.h"
#include "recomp/overrides/native_banks/v3/packet_adapter.h"
#include <array>
#include <cstdint>
#include <memory>

namespace reo::native::audio_aggregate::v3 {
namespace pcm=pcm_bridge;
namespace bank=audio_banks::v2;
namespace packet=bank_packets::v3;
namespace output=reo::audio_output;
inline constexpr std::uint32_t production_channels=2040,production_voices=2041;
inline constexpr std::uint64_t production_pcm_bytes=391680000;
enum class Operation:std::uint8_t {ensure_output,queue,configure,consumed,render,discard,drain,release,
    queued_samples,reset,shutdown,submit_bank,submit_packet,mix_banks,reset_banks,pending_loads,port_state,sequence_state,report_paths,count};
inline constexpr std::size_t operation_count=std::size_t(Operation::count);
struct PacketBorrow {const std::uint8_t* ram{};std::size_t ram_bytes{};const std::uint8_t* packet{};std::size_t packet_bytes{};};
struct BankBorrow {unsigned port{};const std::uint8_t* hd{};std::size_t hd_bytes{};const std::uint8_t* bd{};std::size_t bd_bytes{};const std::uint8_t* tq{};std::size_t tq_bytes{};};
class PacketOperation {public:virtual ~PacketOperation()=default;virtual packet::PacketResult run(const packet::CaptureSource&) noexcept=0;};
class BankOperation {public:virtual ~BankOperation()=default;virtual packet::Status run(const packet::CaptureSource&) noexcept=0;};
// INJECTED qualification obligation, not an implementation of a real factory.
// Metadata identity() has no guest/device work or allocation. with_* must retain
// actual runtime/RAM incarnation plus coherent read/borrow ownership, invoke the
// operation synchronously at most once, and return its result unchanged when
// invoked. No operation/source may escape; pre-operation refusal is explicit.
class QualifiedCaptureProvider {
public:
    virtual ~QualifiedCaptureProvider()=default;
    virtual packet::MemoryIdentity identity()const noexcept=0;
    virtual packet::PacketResult with_packet(const PacketBorrow&,PacketOperation&) noexcept=0;
    virtual packet::Status with_bank(const BankBorrow&,BankOperation&) noexcept=0;
};
struct Report {
    bool testing_profile{},captured_after_fence{},owner_joined{},host_output_started{},stream_fenced{},bank_path_counters_enabled{};
    pcm::Domain pcm_domain{};
    packet::MemoryIdentity capture_identity{}; // supplied binding metadata, not factory attestation
    std::uint64_t declared_pcm_bytes{};
    std::array<std::uint64_t,operation_count> attempts{},completed{},refused{};
    std::uint64_t hard_failures{},queue_rejections{},device_renderer_calls{},device_frame_requests{},
        device_renders_completed{},stop_signals{},join_attempts{},self_join_refusals{},fence_failures{},
        packets_accepted{},packet_commands{},packet_consumed_bytes{};
    std::uint64_t first_hard_failure{}; // operation8/status8/raw32; 128..239 bank/packet, 250..255 owner contract/profile
    pcm::core::Statistics pcm_statistics{};
    pcm::core::Clock pcm_clock{};
    std::uint64_t native_submix_calls{},native_submix_frames{},native_submix_failures{};
    bool native_streams_bound{};
    bank::Snapshot banks{};
    bank::BudgetSnapshot asset_budget{},control_budget{};
};
class HostHooks {
public:
    virtual ~HostHooks()=default;
    // All clock/poll/gain/route hooks are pure/noexcept, no guest/provider work
    // or session/aggregate reentry. Bank gain runs under bank transaction/data.
    virtual std::int64_t now_ns() noexcept=0;
    virtual void poll_settings() noexcept=0;
    virtual float stream_gain(std::uint32_t) noexcept=0;
    virtual float bank_gain(unsigned,unsigned,std::uint64_t) noexcept=0;
    virtual float master_gain() noexcept=0;
    virtual void reset_stream_routes() noexcept=0;
    // Native diagnostic point snapshot, not old printf/reset-counter parity.
    // Control only, after bank data lock release. Flag marks path counters absent.
    virtual void report_bank_paths(const bank::Snapshot&,bool path_counters_enabled) noexcept=0;
    // Control only, outside owner lifecycle/state locks, never a callback.
    // Snapshot statistics/budgets were captured after fence BEFORE core clear.
    virtual void report_joined(const Report&) noexcept=0;
};
struct Inputs {
    std::shared_ptr<HostHooks> host;
    std::shared_ptr<QualifiedCaptureProvider> capture;
    std::shared_ptr<output::Provider> provider;
    // Strong stable slot lease; provider/factory must qualify actual trampoline
    // lifetime. A fabricated shared_ptr or matching hash is not that proof.
    std::shared_ptr<output::CallbackSlot> slot;
    // When present, original PCM producers/reset are unsupported. The game
    // binding must migrate every stream and retain its controls/source owners.
    std::shared_ptr<adxt_output_session::Submix> native_streams;
    bank::Config banks;
    packet::Config packets;
};
class TestRenderProbe {public:virtual ~TestRenderProbe()=default;virtual void after_pcm_before_banks()noexcept=0;};
struct TestDomain {std::uint32_t channels{8},voices{8},max_render_frames{16384};std::size_t metadata_bytes{65536};std::shared_ptr<TestRenderProbe> render_probe;};
class Aggregate;
enum class BuildStatus {ready_composition,invalid_inputs,provider_rejected,allocation_failed};
struct BuildResult {BuildStatus status;std::shared_ptr<Aggregate> owner;};
// Inert composition only. No environment, runtime/capture factory, provider open,
// registry/worker installation or bootstrap activation is implemented here.
BuildResult create(Inputs) noexcept;
BuildResult create_for_tests(Inputs,TestDomain) noexcept;
pcm::Domain production_domain() noexcept;
class DeviceRenderer;
class Aggregate final:public std::enable_shared_from_this<Aggregate> {
public:
    ~Aggregate();
    ps2_cri_audio::BackendRegistrationV2 registration() noexcept;
    Report report()const noexcept;
    // Read-only isolated-oracle observations; caller must arrange quiescence.
    pcm::ChannelObservation inspect_channel(std::uint32_t)const noexcept;
    pcm::VoiceObservation inspect_voice(std::uint32_t)const noexcept;
    pcm::Status copy_samples(std::uint32_t,std::span<std::int16_t>)const noexcept;
    pcm::Result<std::size_t> copy_order(std::span<std::uint32_t>)const noexcept;
    bank::Snapshot inspect_banks()const noexcept;
private:
    friend BuildResult create(Inputs) noexcept;
    friend BuildResult create_for_tests(Inputs,TestDomain) noexcept;
    friend class DeviceRenderer;
    struct State;
    Aggregate(Inputs,pcm::Domain,bool,std::shared_ptr<TestRenderProbe> = {});
    bool initialize_output();
    void signal_stop() noexcept;
    bool finish_after_outer_drain() noexcept;
    void render_admitted(ps2_cri_audio::SoundCall&,float*,unsigned) noexcept;
    void compatibility_render(float*,unsigned) noexcept;
    void ensure_output() noexcept;
    bool queue(std::uint32_t,const std::uint8_t*,std::uint32_t,std::uint64_t&) noexcept;
    void configure(std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t,bool) noexcept;
    std::uint64_t consumed(std::uint32_t) noexcept;
    void discard(std::uint32_t) noexcept;
    void drain(std::uint32_t) noexcept;
    void release(std::uint32_t) noexcept;
    std::size_t queued_samples(std::uint32_t) noexcept;
    void reset_pcm() noexcept;
    ps2_cri_audio::BankStatusV2 submit_bank(const BankBorrow&) noexcept;
    ps2_cri_audio::BankStatusV2 submit_packet(const PacketBorrow&) noexcept;
    ps2_cri_audio::BankStatusV2 mix_banks(float*,unsigned) noexcept;
    ps2_cri_audio::BankStatusV2 reset_banks() noexcept;
    ps2_cri_audio::BankQueryV2 query(Operation,unsigned=0,unsigned=0,unsigned=0,std::uint32_t* = nullptr) noexcept;
    ps2_cri_audio::BankStatusV2 report_paths() noexcept;
    std::unique_ptr<State> state_;
};
} // namespace reo::native::audio_aggregate::v3
