#pragma once

#include "types.hpp"
#include <cstddef>
#include <cstdint>
#include <optional>
#include <span>
#include <stdexcept>
#include <string>
#include <vector>

namespace reo::native::resources::win32 {

inline constexpr std::size_t max_manifest_bytes = 8u * 1024u * 1024u;
inline constexpr std::size_t max_imported_files = 65536;
inline constexpr std::size_t max_relative_name_bytes = 1024;

struct ImportedFile {
    // Validated relative UTF-8 path; separators are canonical '/'.
    std::string name;
    std::uint64_t length = 0;
    Digest sha256{};
};

struct ImportManifest {
    std::uint32_t version = 0;
    std::string game;
    Digest elf_sha256{};
    std::vector<ImportedFile> files;
    // Optional provenance only. Never used to locate or authenticate an asset.
    std::optional<std::string> source;
};

class ImportManifestError : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

// Windows.Data.Json validates structure. Admission deliberately accepts only
// unsigned decimal integer tokens: fractions/exponents/signs are rejected even
// when binary64 rounding would produce an integer. File lengths are <=UINT32_MAX.
// Supports launcher import.json V1 (ISO) and V2 (game PAK), pinned File #1 only.
// Opens no file and changes no existing COM apartment. Throws before returning
// any partially admitted result. The caller must separately pin/hash real files.
[[nodiscard]] ImportManifest parse_import_manifest(std::span<const std::uint8_t> utf8);

} // namespace reo::native::resources::win32
