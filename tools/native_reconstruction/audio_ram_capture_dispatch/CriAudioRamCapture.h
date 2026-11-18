#pragma once
#include "CriAudioBackend.h"
#include <cstddef>
#include <cstdint>
#include <span>

#define PS2_RUNTIME_HAS_NATIVE_SOUND_RAM_CAPTURE 1
namespace ps2_cri_audio {
enum class NativeSoundRamSpaceV1:std::uint8_t { ee,iop };
enum class NativeSoundRamUseV1:std::uint8_t { command,query,status_transfer };
enum class NativeSoundRamControlV1:std::uint8_t { query_reply,status_arena,receive_descriptor,rpc_metadata };
struct NativeSoundRamReadV1 {NativeSoundRamSpaceV1 space;std::uint32_t address;std::span<std::uint8_t> destination;};
struct NativeSoundRamWriteV1 {NativeSoundRamSpaceV1 space;std::uint32_t address;std::span<const std::uint8_t> source;};
enum class NativeSoundRamControlKindV1:std::uint8_t { write,zero };
struct NativeSoundRamControlOpV1 {NativeSoundRamControlKindV1 kind;NativeSoundRamSpaceV1 space;std::uint32_t address;std::span<const std::uint8_t> source;std::size_t bytes;};
enum class NativeSoundRamStageV1:std::uint8_t { begin,read,control,transport,snapshot,log };
struct NativeSoundRamDiagnosticV1 {NativeSoundRamStageV1 stage;BankStatusV2 status;};
struct NativeSoundRamTokenV1 {std::uintptr_t opaque[4]{};};
struct NativeSoundRamPacketV1 {const std::uint8_t* data{};std::size_t bytes{};};
// Independent versioned COMPANION, never appended to published V2 layouts.
// Same registration owner, complete callbacks and explicit accepted SoundCall.
// There is no built-in RAM reader. Begin may return unsupported/unavailable;
// that does not qualify a production profile or permit identity-based memcpy.
// begin/end retain only bounded caller context and storage. They MUST NOT hold
// graphics/source/guest range locks across the entire RPC or a guest callback.
// Each read/control/forward/snapshot obtains the actual necessary protocol
// reservation, validates every extent BEFORE effects, copies bounded bytes,
// then releases it. A refused batch/transport must have no partial writes.
// EE canonical aliases and IOP addresses have distinct provenance. Unsupported
// scratch/MMIO/wrapping extents must be refused, never guessed from identity.
// Callbacks are synchronous, noexcept and must not retain SoundCall/reenter a
// public audio facade. Provider lifecycle is the same registration owner.
struct NativeSoundRamApiV1 {
    std::uint32_t abi_version{},structure_bytes{};
    std::uint64_t capabilities{};
    std::size_t max_packet_bytes{};
    BankStatusV2 (*begin)(void*,const SoundCall&,PS2Runtime*,std::uint8_t*,NativeSoundRamUseV1,NativeSoundRamTokenV1&) noexcept{};
    void (*end)(void*,const SoundCall&,NativeSoundRamTokenV1&) noexcept{};
    BankStatusV2 (*read_batch)(void*,const SoundCall&,NativeSoundRamTokenV1&,std::span<const NativeSoundRamReadV1>) noexcept{};
    BankStatusV2 (*control_batch)(void*,const SoundCall&,NativeSoundRamTokenV1&,NativeSoundRamControlV1,std::span<const NativeSoundRamControlOpV1>) noexcept{};
    // Exact bytewise FORWARD evolving-source semantics; both ranges reserved
    // through operation. Failures must refuse BEFORE any mutation.
    BankStatusV2 (*copy_forward)(void*,const SoundCall&,NativeSoundRamTokenV1&,NativeSoundRamSpaceV1,std::uint32_t,NativeSoundRamSpaceV1,std::uint32_t,std::size_t) noexcept{};
    // Return a loan from finite pre-budgeted owner storage, valid until end.
    // No SDK allocation, borrowed guest pointer, or raw-RAM logging is allowed.
    BankStatusV2 (*snapshot_packet)(void*,const SoundCall&,NativeSoundRamTokenV1&,std::uint32_t,std::size_t,NativeSoundRamPacketV1&) noexcept{};
    BankStatusV2 (*log_owned_packet)(void*,const SoundCall&,NativeSoundRamTokenV1&,NativeSoundRamPacketV1) noexcept{};
    void (*report)(void*,const SoundCall&,NativeSoundRamTokenV1&,NativeSoundRamDiagnosticV1) noexcept{};
};
inline constexpr std::uint32_t nativeSoundRamAbiVersionV1=1;
inline constexpr std::uint64_t nativeSoundRamCapabilitiesV1=(1ull<<8)-1;
BackendInstallStatusV1 installBackendWithNativeSoundRamBeforeRunV1(PS2Runtime&,BackendRegistrationV2,NativeSoundRamApiV1) noexcept;
// Sticky selection inspection only; never chooses legacy or admits a call.
bool nativeSoundRamSelectedV1() noexcept;
class NativeSoundRamCallV1 final {
public:
    // The accepted SoundCall MUST outlive this scope and remain accepted,
    // unmoved and unreleased until this scope's destruction. End and operations
    // reuse that admission even after stop; no gate is reacquired. End is called
    // after every invoked begin, including refused begin, for bounded cleanup.
    NativeSoundRamCallV1(const SoundCall&,PS2Runtime*,std::uint8_t*,NativeSoundRamUseV1) noexcept;
    NativeSoundRamCallV1(SoundCall&&,PS2Runtime*,std::uint8_t*,NativeSoundRamUseV1)=delete;
    NativeSoundRamCallV1(const SoundCall&&,PS2Runtime*,std::uint8_t*,NativeSoundRamUseV1)=delete;
    ~NativeSoundRamCallV1();
    NativeSoundRamCallV1(const NativeSoundRamCallV1&)=delete;
    NativeSoundRamCallV1& operator=(const NativeSoundRamCallV1&)=delete;
    bool selected()const noexcept{return selected_;}
    BankStatusV2 status()const noexcept{return status_;}
    explicit operator bool()const noexcept{return status_==BankStatusV2::ok;}
    BankStatusV2 read(std::span<const NativeSoundRamReadV1>) noexcept;
    BankStatusV2 write(std::span<const NativeSoundRamWriteV1>,NativeSoundRamControlV1) noexcept;
    BankStatusV2 control(std::span<const NativeSoundRamControlOpV1>,NativeSoundRamControlV1) noexcept;
    BankStatusV2 zero(NativeSoundRamSpaceV1,std::uint32_t,std::size_t,NativeSoundRamControlV1) noexcept;
    BankStatusV2 forward(NativeSoundRamSpaceV1,std::uint32_t,NativeSoundRamSpaceV1,std::uint32_t,std::size_t) noexcept;
    BankStatusV2 snapshot(std::uint32_t,std::size_t,NativeSoundRamPacketV1&) noexcept;
    BankStatusV2 log(NativeSoundRamPacketV1) noexcept;
    BankStatusV2 reject(NativeSoundRamStageV1 stage,BankStatusV2 status)noexcept{return finish(stage,status);}
private:
    const SoundCall* call_{};
    std::shared_ptr<backend_detail::Binding> binding_;
    NativeSoundRamTokenV1 token_;
    BankStatusV2 status_{BankStatusV2::unsupported};
    bool selected_{},begun_{};
    BankStatusV2 finish(NativeSoundRamStageV1,BankStatusV2) noexcept;
};
} // namespace ps2_cri_audio
