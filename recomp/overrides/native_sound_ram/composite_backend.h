#pragma once
#include "../native_audio/v2/aggregate.h"
#include "../native_cd_owner/ram_configuration.h"

namespace reo::native::sound_ram {
enum class InstallStatus {
    installed, disabled, phase_closed, unsupported_layout, memory_unavailable,
    output_unavailable, aggregate_unavailable, publication_refused, allocation_failed
};
struct InstallResult {
    InstallStatus status{InstallStatus::disabled};
    ps2_cri_audio::BackendInstallStatusV1 dispatch_status{
        ps2_cri_audio::BackendInstallStatusV1::invalid_owner};
};
// Private candidate entry, after actual CD configuration and game overrides.
// The identity is recorded metadata; the factory independently obtains its RAM
// authority. Requires exact REO_NATIVE_AUDIO=1 and a coherent flag2 build.
// No bootstrap calls this entry until the complete factory has been qualified.
InstallResult install(PS2Runtime&,const reo_cd_async::ConfigurationReceipt&,
                      bank_packets::v3::MemoryIdentity) noexcept;
} // namespace reo::native::sound_ram
