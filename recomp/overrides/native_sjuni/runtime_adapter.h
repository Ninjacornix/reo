#pragma once

class PS2Runtime;

namespace reo_native_sjuni {
// File #1 optional build only. Requires REO_NATIVE_SJUNI=1 and the exact loaded
// resident text. Call after ELF/function registration, before guest execution.
// Failure leaves the native path disabled; original guest methods remain usable.
bool install(PS2Runtime& runtime) noexcept;
} // namespace reo_native_sjuni
