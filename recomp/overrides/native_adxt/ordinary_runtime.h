#pragma once
class PS2Runtime;
namespace reo_cd_async {class ConfigurationReceipt;}
namespace reo::native::bank_packets::v3 {struct MemoryIdentity;}
namespace reo::native::sound_ram {struct InstallResult;}
namespace reo::native::adxt_binding {
// Complete private ordinary-file profile only. This declaration does not make
// the adapter selected by a bootstrap or qualify its runtime admission.
sound_ram::InstallResult install_ordinary_before_run(PS2Runtime&,
    const reo_cd_async::ConfigurationReceipt&,bank_packets::v3::MemoryIdentity)noexcept;
}
