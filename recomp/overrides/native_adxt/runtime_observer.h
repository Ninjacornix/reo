#pragma once
class PS2Runtime;
namespace reo::native::adxt_binding {
// Optional bounded observation of original game ABI consumers. The explicit
// output path is CREATE_NEW; no game calls or PCM/source owners are replaced.
// Requires pre-run setup, exact File1 code and the actual guest RAM identity.
// Returns false if disabled/unavailable. Failure never prevents game launch.
[[nodiscard]] bool observe_before_run(PS2Runtime&)noexcept;
}
