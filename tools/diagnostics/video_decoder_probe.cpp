// Lists the D3D11 hardware video decoders of every GPU, with MPEG-2 details.
// The native movie path needs D3D11_DECODER_PROFILE_MPEG2_VLD (or MPEG2and1_VLD)
// with NV12 output and ConfigBitstreamRaw == 1 on the adapter that runs the game.
// Build: clang++ -O2 -std=c++17 video_decoder_probe.cpp -ld3d11 -ldxgi -lole32 -o video-decoder-probe.exe
#include <initguid.h>
#include <cstdio>
#include <cstring>
#include <d3d11.h>
#include <dxgi.h>
#include <windows.h>

namespace {
// Profile GUIDs from d3d11.h; named here so the report is readable without a lookup.
struct Named {
    GUID guid;
    const char* name;
};
const Named kNames[] = {
    {D3D11_DECODER_PROFILE_MPEG2_MOCOMP, "MPEG2_MOCOMP"},
    {D3D11_DECODER_PROFILE_MPEG2_IDCT, "MPEG2_IDCT"},
    {D3D11_DECODER_PROFILE_MPEG2_VLD, "MPEG2_VLD"},
    {D3D11_DECODER_PROFILE_MPEG1_VLD, "MPEG1_VLD"},
    {D3D11_DECODER_PROFILE_MPEG2and1_VLD, "MPEG2and1_VLD"},
    {D3D11_DECODER_PROFILE_H264_VLD_NOFGT, "H264_VLD_NOFGT"},
    {D3D11_DECODER_PROFILE_VC1_VLD, "VC1_VLD"},
    {D3D11_DECODER_PROFILE_HEVC_VLD_MAIN, "HEVC_VLD_MAIN"},
    {D3D11_DECODER_PROFILE_HEVC_VLD_MAIN10, "HEVC_VLD_MAIN10"},
    {D3D11_DECODER_PROFILE_VP9_VLD_PROFILE0, "VP9_VLD_PROFILE0"},
};

const char* nameOf(const GUID& g) {
    for (const auto& n : kNames)
        if (IsEqualGUID(n.guid, g))
            return n.name;
    return nullptr;
}

bool isMpeg2(const GUID& g) {
    return IsEqualGUID(g, D3D11_DECODER_PROFILE_MPEG2_VLD) ||
           IsEqualGUID(g, D3D11_DECODER_PROFILE_MPEG2and1_VLD);
}

void printGuid(FILE* out, const GUID& g) {
    std::fprintf(out, "{%08lX-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}", g.Data1, g.Data2,
                 g.Data3, g.Data4[0], g.Data4[1], g.Data4[2], g.Data4[3], g.Data4[4], g.Data4[5],
                 g.Data4[6], g.Data4[7]);
}

void probeAdapter(FILE* out, IDXGIAdapter1* adapter) {
    DXGI_ADAPTER_DESC1 desc{};
    adapter->GetDesc1(&desc);
    char name[256]{};
    WideCharToMultiByte(CP_UTF8, 0, desc.Description, -1, name, sizeof name, nullptr, nullptr);
    std::fprintf(out, "\nAdapter: %s\n  vendor=0x%04X device=0x%04X LUID=%08lX:%08lX%s\n", name,
                 desc.VendorId, desc.DeviceId, desc.AdapterLuid.HighPart, desc.AdapterLuid.LowPart,
                 (desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE) ? " (software)" : "");
    ID3D11Device* device = nullptr;
    HRESULT hr = D3D11CreateDevice(adapter, D3D_DRIVER_TYPE_UNKNOWN, nullptr,
                                   D3D11_CREATE_DEVICE_VIDEO_SUPPORT, nullptr, 0,
                                   D3D11_SDK_VERSION, &device, nullptr, nullptr);
    if (FAILED(hr)) {
        std::fprintf(out, "  D3D11 video device: FAILED hr=0x%08lX\n", hr);
        return;
    }
    ID3D11VideoDevice* video = nullptr;
    hr = device->QueryInterface(__uuidof(ID3D11VideoDevice), reinterpret_cast<void**>(&video));
    if (FAILED(hr)) {
        std::fprintf(out, "  ID3D11VideoDevice: FAILED hr=0x%08lX\n", hr);
        device->Release();
        return;
    }
    const UINT count = video->GetVideoDecoderProfileCount();
    std::fprintf(out, "  decoder profiles: %u\n", count);
    bool mpeg2Usable = false;
    for (UINT i = 0; i < count; ++i) {
        GUID profile{};
        if (FAILED(video->GetVideoDecoderProfile(i, &profile)))
            continue;
        std::fprintf(out, "    ");
        printGuid(out, profile);
        const char* n = nameOf(profile);
        std::fprintf(out, " %s\n", n ? n : "");
        if (!isMpeg2(profile))
            continue;
        BOOL nv12 = FALSE;
        hr = video->CheckVideoDecoderFormat(&profile, DXGI_FORMAT_NV12, &nv12);
        std::fprintf(out, "      NV12 output: %s (hr=0x%08lX)\n", nv12 ? "yes" : "no", hr);
        D3D11_VIDEO_DECODER_DESC dd{profile, 640, 448, DXGI_FORMAT_NV12};
        UINT configs = 0;
        hr = video->GetVideoDecoderConfigCount(&dd, &configs);
        std::fprintf(out, "      configs at 640x448: %u (hr=0x%08lX)\n", configs, hr);
        for (UINT c = 0; c < configs; ++c) {
            D3D11_VIDEO_DECODER_CONFIG config{};
            if (FAILED(video->GetVideoDecoderConfig(&dd, c, &config)))
                continue;
            ID3D11VideoDecoder* decoder = nullptr;
            const HRESULT created = video->CreateVideoDecoder(&dd, &config, &decoder);
            if (decoder)
                decoder->Release();
            std::fprintf(out, "        config %u: BitstreamRaw=%u MinRenderTargets=%u create=0x%08lX encryption=",
                         c, config.ConfigBitstreamRaw, config.ConfigMinRenderTargetBuffCount, created);
            printGuid(out, config.guidConfigBitstreamEncryption);
            std::fprintf(out, "\n");
            if (nv12 && config.ConfigBitstreamRaw == 1 && SUCCEEDED(created))
                mpeg2Usable = true;
        }
    }
    std::fprintf(out, "  => usable for REO GPU movies: %s\n", mpeg2Usable ? "YES" : "NO");
    video->Release();
    device->Release();
}
} // namespace

int main() {
    char path[MAX_PATH]{};
    GetModuleFileNameA(nullptr, path, MAX_PATH);
    char* slash = std::strrchr(path, '\\');
    if (slash)
        std::strcpy(slash + 1, "video-decoder-report.txt");
    FILE* out = std::fopen(path, "w");
    FILE* sinks[] = {stdout, out};
    IDXGIFactory1* factory = nullptr;
    if (FAILED(CreateDXGIFactory1(__uuidof(IDXGIFactory1), reinterpret_cast<void**>(&factory)))) {
        std::printf("CreateDXGIFactory1 failed\n");
        return 1;
    }
    for (FILE* sink : sinks) {
        if (!sink)
            continue;
        std::fprintf(sink, "REO video decoder probe\n");
        IDXGIAdapter1* adapter = nullptr;
        for (UINT i = 0; factory->EnumAdapters1(i, &adapter) != DXGI_ERROR_NOT_FOUND; ++i) {
            probeAdapter(sink, adapter);
            adapter->Release();
        }
        std::fflush(sink);
    }
    factory->Release();
    if (out) {
        std::fclose(out);
        std::printf("\nSaved: %s\nPress Enter to close.", path);
    }
    std::getchar();
    return 0;
}
