#pragma once
class PS2Runtime;
namespace reo::native::native_gameplay {
enum class InstallStatus { installed,disabled,phase_closed,unsupported_image,registry_mismatch,publication_refused,allocation_failed };
struct InstallResult { InstallStatus status{InstallStatus::disabled}; };
// File #1 private candidate only. The bootstrap independently checks serial/entry
// and passes explicit selection. No host/background thread enters guest state.
InstallResult install_save_session_before_run(PS2Runtime&,bool selected_candidate) noexcept;
}
