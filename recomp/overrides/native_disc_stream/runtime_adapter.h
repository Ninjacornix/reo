#pragma once
class PS2Runtime;
namespace reo_native_disc_stream {
// Optional File #1 build. Call after final ELF/function registration, before
// guest execution. Exact REO_NATIVE_DISC_STREAM=1 is additionally required.
// One runtime/RAM lifetime only; no reload/destruction/reuse adoption.
bool install(PS2Runtime& runtime) noexcept;
}
