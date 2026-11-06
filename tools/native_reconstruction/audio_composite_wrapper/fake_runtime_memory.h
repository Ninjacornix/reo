#pragma once
#include "recomp/overrides/native_audio/v2/aggregate.h"
#include "recomp/overrides/native_cd_owner/ram_configuration.h"
#include "Kernel/Syscalls/Helpers/CriAudioRamCapture.h"
#include <algorithm>
#include <array>
#include <memory>
#include <span>
namespace reo::native::sound_ram {
namespace packet=bank_packets::v3;
namespace aggregate=audio_aggregate::v2;
class RuntimeMemory;
enum class MemoryPrepareStatus {ready,phase_closed,invalid_profile,cd_unavailable,gs_unavailable,writer_unavailable,capacity,no_memory};
struct MemoryPrepareResult {MemoryPrepareStatus status{MemoryPrepareStatus::invalid_profile};std::shared_ptr<RuntimeMemory> owner;};
class PcmOperation {public:virtual ~PcmOperation()=default;virtual bool run(std::span<const std::uint8_t>)noexcept=0;};
enum class MemoryOperation:std::uint8_t {begin,end,read,control,forward,snapshot,log,packet,bank,pcm,retire,count};
inline constexpr std::size_t memory_operation_count=std::size_t(MemoryOperation::count);
struct MemoryStatistics {std::array<std::uint64_t,memory_operation_count> attempts{},refused{};std::uint64_t active_slots{},active_operations{},diagnostic_reports{},first_failure{};bool retired{};};
// Structural fixture ONLY. No Runtime, RAM/read capability, writer reservation,
// CD/GS seal, actual device or public-facade admission is implemented here.
class RuntimeMemory final:public aggregate::QualifiedCaptureProvider {
public:
    MemoryStatistics stats;
    unsigned retires{},pcm_calls{},begins{},ends{},reads{},controls{},forwards{},snapshots{},logs{},reports{};
    bool permit_pcm=true,pin_active{},operation_active{},permit_retire=true;
    const std::uint8_t* borrowed_pcm{};std::size_t borrowed_bytes{};
    std::array<std::uint8_t,0x4000> owned{};
    const ps2_cri_audio::SoundCall* call{};PS2Runtime* runtime{};
    std::uint8_t* ram{};ps2_cri_audio::NativeSoundRamUseV1 use{};
    ps2_cri_audio::NativeSoundRamTokenV1* token{};
    std::span<const ps2_cri_audio::NativeSoundRamReadV1> read_ops;
    ps2_cri_audio::NativeSoundRamControlV1 control_kind{};
    std::span<const ps2_cri_audio::NativeSoundRamControlOpV1> control_ops;
    ps2_cri_audio::NativeSoundRamSpaceV1 source_space{},destination_space{};
    std::uint32_t source{},destination{};std::size_t bytes{};
    ps2_cri_audio::NativeSoundRamPacketV1 packet_value;
    ps2_cri_audio::NativeSoundRamDiagnosticV1 diagnostic{};
    ps2_cri_audio::BankStatusV2 status=ps2_cri_audio::BankStatusV2::ok;
    packet::MemoryIdentity identity()const noexcept override{return {};}
    packet::PacketResult with_packet(const aggregate::PacketBorrow&,aggregate::PacketOperation&)noexcept override{return {packet::Status::unsupported};}
    packet::Status with_bank(const aggregate::BankBorrow&,aggregate::BankOperation&)noexcept override{return packet::Status::unsupported;}
    bool with_pcm(const std::uint8_t* p,std::size_t n,PcmOperation& operation)noexcept {
        ++pcm_calls;borrowed_pcm=p;borrowed_bytes=n;
        if(!permit_pcm||!p||!n||(n&1)||n>owned.size())return false;
        pin_active=true;std::copy_n(p,n,owned.data());pin_active=false;
        operation_active=true;++stats.active_operations;const auto result=operation.run({owned.data(),n});--stats.active_operations;operation_active=false;return result;
    }
    ps2_cri_audio::BankStatusV2 begin(const ps2_cri_audio::SoundCall& c,PS2Runtime*r,std::uint8_t*b,ps2_cri_audio::NativeSoundRamUseV1 u,ps2_cri_audio::NativeSoundRamTokenV1&t)noexcept {++begins;call=&c;runtime=r;ram=b;use=u;token=&t;t.opaque[0]=0x12345678;++stats.active_slots;return status;}
    void end(const ps2_cri_audio::SoundCall&c,ps2_cri_audio::NativeSoundRamTokenV1&t)noexcept {++ends;call=&c;token=&t;t.opaque[0]=0;if(stats.active_slots)--stats.active_slots;}
    ps2_cri_audio::BankStatusV2 read_batch(const ps2_cri_audio::SoundCall&c,ps2_cri_audio::NativeSoundRamTokenV1&t,std::span<const ps2_cri_audio::NativeSoundRamReadV1>ops)noexcept {++reads;call=&c;token=&t;read_ops=ops;return status;}
    ps2_cri_audio::BankStatusV2 control_batch(const ps2_cri_audio::SoundCall&c,ps2_cri_audio::NativeSoundRamTokenV1&t,ps2_cri_audio::NativeSoundRamControlV1 k,std::span<const ps2_cri_audio::NativeSoundRamControlOpV1>ops)noexcept {++controls;call=&c;token=&t;control_kind=k;control_ops=ops;return status;}
    ps2_cri_audio::BankStatusV2 copy_forward(const ps2_cri_audio::SoundCall&c,ps2_cri_audio::NativeSoundRamTokenV1&t,ps2_cri_audio::NativeSoundRamSpaceV1 ss,std::uint32_t s,ps2_cri_audio::NativeSoundRamSpaceV1 ds,std::uint32_t d,std::size_t n)noexcept {++forwards;call=&c;token=&t;source_space=ss;source=s;destination_space=ds;destination=d;bytes=n;return status;}
    ps2_cri_audio::BankStatusV2 snapshot_packet(const ps2_cri_audio::SoundCall&c,ps2_cri_audio::NativeSoundRamTokenV1&t,std::uint32_t at,std::size_t n,ps2_cri_audio::NativeSoundRamPacketV1&p)noexcept {++snapshots;call=&c;token=&t;source=at;bytes=n;p={owned.data(),n};return status;}
    ps2_cri_audio::BankStatusV2 log_owned_packet(const ps2_cri_audio::SoundCall&c,ps2_cri_audio::NativeSoundRamTokenV1&t,ps2_cri_audio::NativeSoundRamPacketV1 p)noexcept {++logs;call=&c;token=&t;packet_value=p;return status;}
    void report(const ps2_cri_audio::SoundCall&c,ps2_cri_audio::NativeSoundRamTokenV1&t,ps2_cri_audio::NativeSoundRamDiagnosticV1 d)noexcept {++reports;call=&c;token=&t;diagnostic=d;}
    MemoryStatistics statistics()const noexcept{return stats;}
    bool retire_after_outer_drain()noexcept {++retires;if(!permit_retire||stats.active_slots||stats.active_operations)return false;stats.retired=true;return true;}
    static MemoryPrepareResult prepare(PS2Runtime&,const reo_cd_async::ConfigurationReceipt&,packet::MemoryIdentity)noexcept;
};
}
