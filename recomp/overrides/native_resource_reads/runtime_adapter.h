#pragma once

#include <cstddef>
#include <cstdint>
#include <filesystem>
#include <memory>

class PS2Runtime;
namespace reo::native::resources::win32 { class MountedResources; }

namespace reo_native_resource_reads {
using SharedMount=std::shared_ptr<const reo::native::resources::win32::MountedResources>;

#if defined(_WIN32) && defined(REO_GAME_FILE1) && \
    defined(REO_BUILD_NATIVE_RESOURCE_READS) && REO_BUILD_NATIVE_RESOURCE_READS
// Bootstrap only: after final ELF/function registration and before guest run.
// Failure leaves the existing RPC path available. Never writes imported files.
void configure(const char* serial, std::uint8_t* ram, std::size_t bytes,
               PS2Runtime& runtime, const std::filesystem::path& data_root) noexcept;

// Bootstrap-only handoff of the SAME validated immutable mount. Acquires a
// real pre-run setup lease and checks configured runtime/RAM identity. The
// result retains files/metadata independently of runtime, never RAM or a guest
// callback. Consumers take native ByteViews from it, with their own source
// stop/join. No second mount, environment read or fallback I/O is performed.
[[nodiscard]] SharedMount retain_mount_before_run(PS2Runtime&,const std::uint8_t*,std::size_t)noexcept;

// Called ONLY for N-command service 0x80000595, RPC 1, while the existing RPC
// mutex and guest execution are held. Never releases either or invokes guest
// services/callbacks. false permits legacy fallback before native I/O/mutation;
// true consumes the payload attempt, with ok selecting its existing reply policy.
// ok is unchanged on false. Runtime/RAM must outlive this synchronous call.
[[nodiscard]] bool tryRead(std::uint8_t* ram, PS2Runtime* runtime,
                           std::uint32_t send_buffer, std::uint32_t send_size,
                           std::uint32_t receive_buffer, std::uint32_t receive_size,
                           bool& ok) noexcept;
#else
inline void configure(const char*, std::uint8_t*, std::size_t, PS2Runtime&,
                      const std::filesystem::path&) noexcept {}
[[nodiscard]] inline SharedMount retain_mount_before_run(PS2Runtime&,const std::uint8_t*,std::size_t)noexcept{return {};}
[[nodiscard]] inline bool tryRead(std::uint8_t*, PS2Runtime*, std::uint32_t, std::uint32_t,
                                  std::uint32_t, std::uint32_t, bool&) noexcept { return false; }
#endif

} // namespace reo_native_resource_reads
