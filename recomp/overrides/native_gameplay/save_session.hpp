#pragma once
class PS2Runtime;
namespace reo::native::native_gameplay {
enum class InstallStatus { installed,disabled,phase_closed,unsupported_image,registry_mismatch,publication_refused,allocation_failed };
struct InstallResult { InstallStatus status{InstallStatus::disabled}; };
// File #1 private candidate only. The bootstrap independently checks serial/entry
// and passes explicit selection. No host/background thread enters guest state.
// shadow=true keeps every original entry authoritative. Entries without guest
// providers also run natively on a scratch copy of their declared guest regions,
// and return values/regions are compared; counts are printed at exit.
InstallResult install_save_session_before_run(PS2Runtime&,bool selected_candidate,bool shadow=false) noexcept;
}
