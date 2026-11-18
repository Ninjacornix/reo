#pragma once
#include "../native_banks/v3/packet_adapter.h"
#include <filesystem>

namespace reo::native::sound_ram {
enum class IdentityStatus { observed_metadata, unavailable, wrong_original_executable };
struct IdentityResult {
    IdentityStatus status{IdentityStatus::unavailable};
    bank_packets::v3::MemoryIdentity identity;
};
// Pre-run file observations and a random report-session identifier only. Neither
// file hashes nor these tags grant RAM access or attest a loaded Runtime image.
// RuntimeMemory separately verifies loaded code and supplies actual binding IDs.
IdentityResult observe_build_identity(const std::filesystem::path& original_elf) noexcept;
} // namespace reo::native::sound_ram
