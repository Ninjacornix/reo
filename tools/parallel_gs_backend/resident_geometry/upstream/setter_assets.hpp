#pragma once
#include "parent/parent_gpu_overlay.hpp"
#include <filesystem>
#include <fstream>
namespace reo_gpu_upstream {
inline std::vector<uint32_t> setterAsset(const std::filesystem::path& path, const char* expected) {
    std::ifstream file(path, std::ios::binary | std::ios::ate);
    if (!file)
        throw std::runtime_error("Setter immutable shader asset missing");
    const auto length = file.tellg();
    if (length < 20 || length > 4 * 1024 * 1024 || (size_t(length) & 3u))
        throw std::runtime_error("Setter shader asset size differs");
    std::vector<uint8_t> bytes(size_t(length), uint8_t{});
    file.seekg(0);
    if (!file.read(reinterpret_cast<char*>(bytes.data()), std::streamsize(bytes.size())))
        throw std::runtime_error("Setter shader asset read incomplete");
    if (reo_gpu_catalog::sha256(bytes) != expected)
        throw std::runtime_error("Setter immutable shader asset SHA differs");
    std::vector<uint32_t> words(bytes.size() / 4u);
    std::memcpy(words.data(), bytes.data(), bytes.size());
    if (words[0] != 0x07230203u)
        throw std::runtime_error("Setter SPIRV asset magic differs");
    return words;
}
// Explicit module attachment only. The unchanged source/ownership admission
// gates and actual Service instance still decide whether any call may run.
inline void attachSetterAssets(reo_gpu_palette_parent::Modules& modules,
                               const std::filesystem::path& directory) {
    if (!modules.setter196010.empty() || !modules.setter196010Additional.empty())
        throw std::invalid_argument("Setter assets were attached twice");
    auto primary = setterAsset(directory / "setter196010_static5abc.spv",
                               "dedb7f6e1edf5e836cc38957964325ca824a2fb2c9871eed48588603bf698786");
    std::vector<std::vector<uint32_t>> additional{
        setterAsset(directory / "setter196010_static_copy.spv",
                    "91ae5d95413e36484c8548dbe6f4d3f6d08ded59e0ff0f0538844a47107e8571"),
        setterAsset(directory / "setter196010_static10.spv",
                    "1a9b42db9fe56afebeaf91be0415a55351d36ee979e226bc95be6621d4c732b0"),
        setterAsset(directory / "setter196010_static11.spv",
                    "f12a42933bc3865816f950a6fd283545d7dc6b8fe38d6d3c47d422f26fc6c9fe"),
        setterAsset(directory / "setter196010_static16.spv",
                    "ede0582c30e8e143fa816822146378d71b975f9fb5f4c93bd8526cf4fd4d0fb6"),
        setterAsset(directory / "setter196010_static17.spv",
                    "38e1ddb70d27594ea89b0c6c03b754f864906bab46f8eb0fc1091de3e94c2656"),
        setterAsset(directory / "setter196010_static19.spv",
                    "f9fda6222c6de88653897a6263bd6ba8297dca1fdaa44f0298dd7eaa5dedcc74"),
        setterAsset(directory / "setter196010_static67.spv",
                    "52cfc36453a5b26e13c6eca71acd845328811dcded5b5be67185b7a3aa2c1532")};
    // All eight pins validate before either destination member changes.
    modules.setter196010 = std::move(primary);
    modules.setter196010Additional = std::move(additional);
}
} // namespace reo_gpu_upstream
