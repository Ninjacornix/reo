// Build with MSVC: cl /EHsc /std:c++17 movie_decoder_support_tests.cpp
#include "../../runtime/media/movie_decoder_support.h"
#include <cassert>
#include <cstdio>
#include <cstring>
#include <initializer_list>

int main() {
    using namespace reo_movie_probe;
    D3D11_VIDEO_DECODER_CONFIG config{};
    config.ConfigBitstreamRaw = 1;
    config.ConfigMinRenderTargetBuffCount = 8;
    assert(usableMpeg2Config(config));
    config.ConfigMinRenderTargetBuffCount = 9;
    assert(!usableMpeg2Config(config));
    config.ConfigMinRenderTargetBuffCount = 8;
    for (UINT raw : {0u, 2u}) {
        config.ConfigBitstreamRaw = raw;
        assert(!usableMpeg2Config(config));
    }
    config.ConfigBitstreamRaw = 1;
    // Drivers can use GUID_NULL or DXVA_NoEncrypt, independently in each field.
    const GUID noEncrypt = {
        0x1b81bed0, 0xa0c7, 0x11d3, {0xb9, 0x84, 0x00, 0xc0, 0x4f, 0x2e, 0x73, 0xc5}};
    const GUID encrypted = {0x12345678, 0, 0, {}};
    GUID* fields[] = {&config.guidConfigBitstreamEncryption,
                      &config.guidConfigMBcontrolEncryption,
                      &config.guidConfigResidDiffEncryption};
    for (GUID* field : fields) {
        *field = noEncrypt;
        assert(usableMpeg2Config(config));
        *field = encrypted;
        assert(!usableMpeg2Config(config));
        *field = GUID{};
    }
    assert(interopBlockReason(0x1002, false) == nullptr);
    assert(std::strstr(interopBlockReason(0x10de, false), "crash"));
    assert(std::strstr(interopBlockReason(0x8086, false), "untested"));
    assert(std::strstr(interopBlockReason(0xffff, false), "untested"));
    for (uint32_t vendor : {0x1002u, 0x10deu, 0x8086u, 0xffffu})
        assert(interopBlockReason(vendor, true) == nullptr);
    std::puts("Movie decoder configuration and vendor policy checks passed.");
}
