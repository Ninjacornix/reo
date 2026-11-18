#pragma once
#include <filesystem>
class PS2Runtime;
namespace reo::native::host_movie_binding {
// Pre-run only. Explicit private native-MP4 candidate; no default/diagnostic
// activation. Runtime owns/join-fences the registered native worker.
[[nodiscard]] bool install_before_run(PS2Runtime&,const std::filesystem::path&)noexcept;
}
