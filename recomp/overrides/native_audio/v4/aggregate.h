// Derived from frozen Aggregate3. Shared ports remain the exact parent ABI.
#pragma once
#include "../v3/aggregate.h"
#include "game/native/adxt_control_owner/owner.hpp"
namespace reo::native::audio_aggregate::v4 {
namespace parent=audio_aggregate::v3;
namespace pcm=pcm_bridge;namespace bank=audio_banks::v2;namespace packet=bank_packets::v3;namespace output=reo::audio_output;
using parent::Operation;using parent::operation_count;
using parent::production_channels;using parent::production_voices;using parent::production_pcm_bytes;
using parent::PacketBorrow;using parent::BankBorrow;using parent::PacketOperation;using parent::BankOperation;
using parent::QualifiedCaptureProvider;using parent::HostHooks;using parent::Inputs;using parent::Report;
using parent::TestRenderProbe;using parent::TestDomain;
class Aggregate;
using parent::BuildStatus;
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
    // Null, foreign, expired or wrong-thread proof refuses before reset effects.
    [[nodiscard]] bool reset_native(const adxt_control_owner::Quiescent*)noexcept;
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
} // namespace reo::native::audio_aggregate::v4
