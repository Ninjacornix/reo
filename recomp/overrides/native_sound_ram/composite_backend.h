#pragma once
#include "../native_audio/v2/aggregate.h"
#include "../native_cd_owner/ram_configuration.h"

namespace reo::native::adxt_control_owner {class Owner;}
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
struct MediaInstallResult {
    InstallResult backend;
    std::shared_ptr<adxt_control_owner::Owner> sources;
    class PcmOrder;
    std::shared_ptr<const PcmOrder> pcm_order;
};
// Read-only capability to the SAME selected aggregate's raw voice container.
// Its bridge copies under its data lock. No independent/sorted map, mutable
// aggregate alias, SDK call or native-controller admission is exposed. Copy
// before entering source-owner controls; never call from an output callback.
class MediaInstallResult::PcmOrder {
public:
    virtual ~PcmOrder()=default;
    [[nodiscard]] virtual pcm_bridge::Result<std::size_t> copy(std::span<std::uint32_t>)const noexcept=0;
};
// Explicit alternative for the complete native ADXT game adapter. Uses the same
// real RAM authority, one outer device/bank/master callback, and a separately
// registered canonical source owner. Never selected by the legacy entry above.
// Successful callers bind ALL admitted guest PCM/source/control consumers before
// run. Original PCM production refuses; later reset requires canonical source
// quiescence after every instance was destroyed and its actual workers joined.
MediaInstallResult install_native_sources(PS2Runtime&,
    const reo_cd_async::ConfigurationReceipt&,bank_packets::v3::MemoryIdentity)noexcept;
// Combined guest adapters prepare their complete, inert binding BEFORE SDK
// selection. The supplied device-free Owner must be empty, open and exclusively
// controlled by that adapter; its host gain hooks are a caller obligation.
// Validation refusal leaves it untouched. After publication is attempted,
// failure may have stopped/joined it; the caller retains failure cleanup.
MediaInstallResult install_prepared_native_sources(PS2Runtime&,
    const reo_cd_async::ConfigurationReceipt&,bank_packets::v3::MemoryIdentity,
    const std::shared_ptr<adxt_control_owner::Owner>&)noexcept;
} // namespace reo::native::sound_ram
