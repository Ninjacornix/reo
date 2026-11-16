#pragma once
#include <d3d11.h>
#include <cstdint>

// Shared by the launcher check and the standalone video diagnostic. Keep the
// decoder requirements in sync with Mpeg2VldCore::initialize (eight surfaces).
namespace reo_movie_probe {
inline bool plainEncryption(const GUID& guid) {
    constexpr GUID noEncrypt = {
        0x1b81bed0, 0xa0c7, 0x11d3, {0xb9, 0x84, 0x00, 0xc0, 0x4f, 0x2e, 0x73, 0xc5}};
    return IsEqualGUID(guid, noEncrypt) || IsEqualGUID(guid, GUID{});
}

inline bool usableMpeg2Config(const D3D11_VIDEO_DECODER_CONFIG& config) {
    return config.ConfigBitstreamRaw == 1 && config.ConfigMinRenderTargetBuffCount <= 8 &&
           plainEncryption(config.guidConfigBitstreamEncryption) &&
           plainEncryption(config.guidConfigMBcontrolEncryption) &&
           plainEncryption(config.guidConfigResidDiffEncryption);
}

// Codec support and D3D11/Vulkan interoperability inform the default only.
// This caution never prevents an explicit choice in the launcher.
// See docs/GPU_MOVIE_SUPPORT.md for GPU families, sources, and the NVIDIA crash.
inline const char* interopBlockReason(uint32_t vendor, bool allowAnyVendor) {
    if (vendor == 0x1002 || allowAnyVendor)
        return nullptr;
    return vendor == 0x10de
        ? "Hardware MPEG-2 is available, but REO GPU movies on NVIDIA can crash the game"
        : vendor == 0x8086
        ? "Hardware MPEG-2 is available, but REO GPU movies on Intel are untested"
        : "Hardware MPEG-2 is available, but REO GPU movies on this vendor are untested";
}
} // namespace reo_movie_probe
