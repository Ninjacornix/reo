#pragma once
#include "address_domain.h"
#include "../native_audio/v2/aggregate.h"
#include "../native_cd_owner/ram_configuration.h"
#include "Kernel/Syscalls/Helpers/CriAudioRamCapture.h"
#include <array>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <span>

class PS2Runtime;
namespace reo::native::sound_ram {
namespace packet=bank_packets::v3;
namespace aggregate=audio_aggregate::v2;
class CompositeBackend;
class RuntimeMemory;
enum class MemoryPrepareStatus {ready,phase_closed,invalid_profile,cd_unavailable,gs_unavailable,writer_unavailable,capacity,no_memory};
struct MemoryPrepareResult {MemoryPrepareStatus status{MemoryPrepareStatus::invalid_profile};std::shared_ptr<RuntimeMemory> owner;};
class PcmOperation {
public:virtual ~PcmOperation()=default;virtual bool run(std::span<const std::uint8_t>)noexcept=0;
};
enum class MemoryOperation:std::uint8_t {begin,end,read,control,forward,snapshot,log,packet,bank,pcm,retire,count};
inline constexpr std::size_t memory_operation_count=std::size_t(MemoryOperation::count);
struct MemoryStatistics {
    std::array<std::uint64_t,memory_operation_count> attempts{},refused{};
    std::uint64_t active_slots{},active_operations{},diagnostic_reports{},first_failure{};
    bool retired{};
};

// A real source-qualified provider, not a general host memory-copy utility.
// The same strong SDK composite Binding must retain this owner and the actual
// Runtime/bridge/backing incarnation through accepted calls and outer drain.
// Native tokens borrow an accepted, unmoved/unreleased SoundCall until end.
// No reservation spans a NativeScope, decoder, guest callback or PCM provider.
class RuntimeMemory final:public aggregate::QualifiedCaptureProvider {
public:
    static constexpr std::size_t scope_capacity=16,packet_capacity=65536,pcm_capacity=0x4000;
    static constexpr std::size_t maximum_ranges=16,maximum_part_ranges=3;
    ~RuntimeMemory() override;
    RuntimeMemory(const RuntimeMemory&)=delete;RuntimeMemory& operator=(const RuntimeMemory&)=delete;
    packet::MemoryIdentity identity()const noexcept override;
    packet::PacketResult with_packet(const aggregate::PacketBorrow&,aggregate::PacketOperation&)noexcept override;
    packet::Status with_bank(const aggregate::BankBorrow&,aggregate::BankOperation&)noexcept override;
    bool with_pcm(const std::uint8_t*,std::size_t,PcmOperation&)noexcept;

    ps2_cri_audio::BankStatusV2 begin(const ps2_cri_audio::SoundCall&,PS2Runtime*,std::uint8_t*,ps2_cri_audio::NativeSoundRamUseV1,ps2_cri_audio::NativeSoundRamTokenV1&)noexcept;
    void end(const ps2_cri_audio::SoundCall&,ps2_cri_audio::NativeSoundRamTokenV1&)noexcept;
    ps2_cri_audio::BankStatusV2 read_batch(const ps2_cri_audio::SoundCall&,ps2_cri_audio::NativeSoundRamTokenV1&,std::span<const ps2_cri_audio::NativeSoundRamReadV1>)noexcept;
    ps2_cri_audio::BankStatusV2 control_batch(const ps2_cri_audio::SoundCall&,ps2_cri_audio::NativeSoundRamTokenV1&,ps2_cri_audio::NativeSoundRamControlV1,std::span<const ps2_cri_audio::NativeSoundRamControlOpV1>)noexcept;
    ps2_cri_audio::BankStatusV2 copy_forward(const ps2_cri_audio::SoundCall&,ps2_cri_audio::NativeSoundRamTokenV1&,ps2_cri_audio::NativeSoundRamSpaceV1,std::uint32_t,ps2_cri_audio::NativeSoundRamSpaceV1,std::uint32_t,std::size_t)noexcept;
    ps2_cri_audio::BankStatusV2 snapshot_packet(const ps2_cri_audio::SoundCall&,ps2_cri_audio::NativeSoundRamTokenV1&,std::uint32_t,std::size_t,ps2_cri_audio::NativeSoundRamPacketV1&)noexcept;
    ps2_cri_audio::BankStatusV2 log_owned_packet(const ps2_cri_audio::SoundCall&,ps2_cri_audio::NativeSoundRamTokenV1&,ps2_cri_audio::NativeSoundRamPacketV1)noexcept;
    void report(const ps2_cri_audio::SoundCall&,ps2_cri_audio::NativeSoundRamTokenV1&,ps2_cri_audio::NativeSoundRamDiagnosticV1)noexcept;
    MemoryStatistics statistics()const noexcept;
    // Root calls only after actual SDK outer drain + child/provider fence, or
    // known unpublished preparation abort. Refuses active slots/operations and
    // guest/IO context; does not close previously accepted work on requestStop.
    bool retire_after_outer_drain()noexcept;
private:
    friend class CompositeBackend;
    static MemoryPrepareResult prepare(PS2Runtime&,const reo_cd_async::ConfigurationReceipt&,packet::MemoryIdentity)noexcept;
    struct State;
    explicit RuntimeMemory(std::unique_ptr<State>)noexcept;
    std::unique_ptr<State> state_;
};
} // namespace reo::native::sound_ram
