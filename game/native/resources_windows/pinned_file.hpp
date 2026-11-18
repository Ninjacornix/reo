#pragma once

#include "types.hpp"
#include "runtime/assets/virtual_afs.h"

#include <filesystem>
#include <cstddef>
#include <memory>

namespace reo::native::resources::win32 {

struct FileIdentity {
    std::uint64_t volume_serial{}, length{};
    std::array<std::uint8_t, 16> file_id{};
    Digest sha256{};
    std::filesystem::path final_path;
};

enum class PinnedStatus { ok, invalid_path, io_error, unsupported_file, length_mismatch,
                          hash_mismatch, hash_error, no_memory };
struct PinnedOpenResult;

// Hash and positioned reads use the same retained Windows file handle. It shares
// read access only. No later path reopen, metadata-only identity or source copy.
class PinnedFile final : public reo::assets::PositionedSource {
public:
    [[nodiscard]] static PinnedOpenResult open_verified(const std::filesystem::path& path,
                                                       std::uint64_t expected_length,
                                                       const Digest& expected_sha256) noexcept;
    ~PinnedFile() override;
    [[nodiscard]] std::uint64_t size() const noexcept override;
    [[nodiscard]] std::size_t read(std::uint64_t offset, std::size_t bytes, void* output) const override;
    [[nodiscard]] const FileIdentity& identity() const noexcept;
private:
    struct Impl;
    explicit PinnedFile(std::unique_ptr<Impl>) noexcept;
    std::unique_ptr<Impl> impl_;
};

struct PinnedOpenResult {
    PinnedStatus status{PinnedStatus::io_error};
    std::shared_ptr<const PinnedFile> file;
    // Win32 code for I/O, raw NTSTATUS for hash_error; zero for policy mismatch.
    std::uint32_t system_error{};
    Digest observed_sha256{};
};
} // namespace reo::native::resources::win32
