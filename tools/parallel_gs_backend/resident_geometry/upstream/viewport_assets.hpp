#pragma once
#include "parent/parent_gpu_overlay.hpp"
#include <filesystem>
#include <fstream>
namespace reo_gpu_upstream {
inline std::vector<uint32_t> viewportAsset(const std::filesystem::path& path, const char* expected,
                                           bool requireSpirv = true) {
    std::ifstream file(path, std::ios::binary | std::ios::ate);
    if (!file)
        throw std::runtime_error("Viewport immutable shader asset missing");
    const auto length = file.tellg();
    if (length < 20 || length > 4 * 1024 * 1024 || (size_t(length) & 3u))
        throw std::runtime_error("Viewport shader asset size differs");
    std::vector<uint8_t> bytes(size_t(length), uint8_t{});
    file.seekg(0);
    if (!file.read(reinterpret_cast<char*>(bytes.data()), std::streamsize(bytes.size())))
        throw std::runtime_error("Viewport shader asset read incomplete");
    if (reo_gpu_catalog::sha256(bytes) != expected)
        throw std::runtime_error("Viewport immutable shader asset SHA differs");
    std::vector<uint32_t> words(bytes.size() / 4);
    std::memcpy(words.data(), bytes.data(), bytes.size());
    if (requireSpirv && words[0] != 0x07230203u)
        throw std::runtime_error("Viewport SPIRV asset magic differs");
    return words;
}
inline void attachViewportAssets(reo_gpu_palette_parent::Modules& modules,
                                 const std::filesystem::path& directory,
                                 bool explicitlyRequested = false) {
    if (!explicitlyRequested)
        return;
    if (!modules.viewport18F970.empty() || !modules.viewportQueueHeaders.empty() ||
        !modules.viewportQueueJournal.empty())
        throw std::invalid_argument("Viewport assets were attached twice");
    auto source =
        viewportAsset(directory / "viewport_effects.bundle",
                      "9512e1e750326ecc00f9fa61e7ade5104cfabd1390afda4ee580c524a63b552d", false);
    auto headers =
        viewportAsset(directory / "queue_header_metadata.spv",
                      "656bf97ab9d9f372bf082f7e579e00936133fc8bbe87111ba6b4b7725137009f");
    auto journal =
        viewportAsset(directory / "queue_journal_apply_effects.spv",
                      "dc538490b598748af2e4e14d5b0b73663689fece9ac9f94f24c8ffee8474d026");
    modules.viewport18F970 = std::move(source);
    modules.viewportQueueHeaders = std::move(headers);
    modules.viewportQueueJournal = std::move(journal);
    // Only immutable module attachment. No proof fields, readiness flag,
    // route registration or source ownership is changed here.
}
} // namespace reo_gpu_upstream
