#pragma once
#include "routing.hpp"
#include <span>

namespace reo::native::gameplay_audio {
enum class ImportMode { direct, staged };
struct Extent {
    std::size_t offset{}, size{};
};
struct Imported {
    Descriptors descriptors;
    std::array<Extent, 3> parts;
    std::size_t rows{};
    std::uint32_t source_return{};
};
struct ImportResult {
    Status status{Status::invalid_asset};
    Imported value{};
};
// Pure bounded metadata import. Parts are offsets in the caller-retained
// immutable SND buffer; no borrowed pointer escapes this operation.
ImportResult import_snd(std::span<const std::uint8_t>, unsigned slot,
                        ImportMode = ImportMode::direct) noexcept;
} // namespace reo::native::gameplay_audio
