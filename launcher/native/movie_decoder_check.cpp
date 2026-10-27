// Decides whether this PC can use the GPU movie decoder. Prints one JSON line:
//   {"gpu":"<name>","gpuMovies":true|false,"reason":"<text>"}
// The launcher sets REO_GPU_MOVIE from it. The GPU route needs D3D11 MPEG-2 VLD on the
// adapter the renderer uses (AMD RDNA 4 parts, for example, have none); without it the
// original CPU decoder plays the movies.
// Sharing decoded frames with Vulkan has only been verified on AMD. NVIDIA drivers lose the
// device at the first scenario movie (GTX 1070 Ti, driver 582.31, issue #4) and Intel is
// untested, so both use the CPU decoder. REO_GPU_MOVIES_ANY_VENDOR=1 skips this rule.
// Built by launcher/build.ps1 (MSVC, Vulkan SDK headers); the launcher ships it as
// reo-movie-check.exe beside Outbreak.Launcher.exe.
#include <initguid.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <d3d11.h>
#include <dxgi.h>
#include <windows.h>
#define VK_NO_PROTOTYPES
#include <vulkan/vulkan.h>

namespace {
// DXVA_NoEncrypt; Mpeg2VldCore accepts it or GUID_NULL for every encryption field.
const GUID kNoEncrypt = {0x1b81bed0, 0xa0c7, 0x11d3, {0xb9, 0x84, 0x00, 0xc0, 0x4f, 0x2e, 0x73, 0xc5}};

std::string escape(const std::string& text) {
    std::string out;
    for (char c : text) {
        if (c == '"' || c == '\\')
            out += '\\';
        if (static_cast<unsigned char>(c) >= 0x20)
            out += c;
    }
    return out;
}

int report(const std::string& gpu, bool gpuMovies, const std::string& reason) {
    std::printf("{\"gpu\":\"%s\",\"gpuMovies\":%s,\"reason\":\"%s\"}\n", escape(gpu).c_str(),
                gpuMovies ? "true" : "false", escape(reason).c_str());
    return 0;
}

struct Selected {
    std::string name;
    LUID luid{};
    bool luidValid = false;
    uint32_t vendor = 0;
};

// Granite's default choice: the GRANITE_VULKAN_DEVICE_INDEX device if set, otherwise the
// highest score (discrete 3, integrated 2, virtual 1, Vulkan < 1.1 or other 0), earliest
// device on ties.
bool selectRendererGpu(Selected& selected, std::string& error) {
    HMODULE loader = LoadLibraryW(L"vulkan-1.dll");
    if (!loader) {
        error = "Vulkan loader not found";
        return false;
    }
    auto getInstanceProc =
        reinterpret_cast<PFN_vkGetInstanceProcAddr>(GetProcAddress(loader, "vkGetInstanceProcAddr"));
    auto createInstance = getInstanceProc
        ? reinterpret_cast<PFN_vkCreateInstance>(getInstanceProc(nullptr, "vkCreateInstance"))
        : nullptr;
    if (!createInstance) {
        error = "Vulkan loader incomplete";
        return false;
    }
    VkApplicationInfo app{VK_STRUCTURE_TYPE_APPLICATION_INFO};
    app.pApplicationName = "reo-movie-check";
    app.apiVersion = VK_API_VERSION_1_1;
    VkInstanceCreateInfo info{VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO};
    info.pApplicationInfo = &app;
    VkInstance instance = VK_NULL_HANDLE;
    if (createInstance(&info, nullptr, &instance) != VK_SUCCESS) {
        error = "Vulkan instance creation failed";
        return false;
    }
    auto destroy = reinterpret_cast<PFN_vkDestroyInstance>(getInstanceProc(instance, "vkDestroyInstance"));
    auto enumerate = reinterpret_cast<PFN_vkEnumeratePhysicalDevices>(
        getInstanceProc(instance, "vkEnumeratePhysicalDevices"));
    auto properties = reinterpret_cast<PFN_vkGetPhysicalDeviceProperties>(
        getInstanceProc(instance, "vkGetPhysicalDeviceProperties"));
    auto properties2 = reinterpret_cast<PFN_vkGetPhysicalDeviceProperties2>(
        getInstanceProc(instance, "vkGetPhysicalDeviceProperties2"));
    uint32_t count = 0;
    std::vector<VkPhysicalDevice> gpus;
    if (enumerate && enumerate(instance, &count, nullptr) == VK_SUCCESS && count) {
        gpus.resize(count);
        if (enumerate(instance, &count, gpus.data()) != VK_SUCCESS)
            gpus.clear();
        gpus.resize(count);
    }
    VkPhysicalDevice chosen = VK_NULL_HANDLE;
    if (const char* index = std::getenv("GRANITE_VULKAN_DEVICE_INDEX")) {
        const unsigned long at = std::strtoul(index, nullptr, 0);
        if (at < gpus.size())
            chosen = gpus[at];
    }
    if (!chosen && properties) {
        unsigned best = 0;
        for (size_t i = gpus.size(); i; --i) {
            VkPhysicalDeviceProperties p{};
            properties(gpus[i - 1], &p);
            unsigned score = 0;
            if (p.apiVersion >= VK_API_VERSION_1_1) {
                switch (p.deviceType) {
                case VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU: score = 3; break;
                case VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU: score = 2; break;
                case VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU: score = 1; break;
                default: break;
                }
            }
            if (score >= best) {
                best = score;
                chosen = gpus[i - 1];
            }
        }
    }
    bool ok = false;
    if (!chosen) {
        error = "No Vulkan GPU";
    } else if (!properties2) {
        error = "Vulkan 1.1 properties unavailable";
    } else {
        VkPhysicalDeviceIDProperties id{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES};
        VkPhysicalDeviceProperties2 p{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2};
        p.pNext = &id;
        properties2(chosen, &p);
        selected.name = p.properties.deviceName;
        selected.vendor = p.properties.vendorID;
        selected.luidValid = id.deviceLUIDValid == VK_TRUE;
        static_assert(sizeof(LUID) == VK_LUID_SIZE);
        std::memcpy(&selected.luid, id.deviceLUID, sizeof(LUID));
        ok = true;
        if (!selected.luidValid)
            error = "Renderer GPU has no adapter LUID";
    }
    if (destroy)
        destroy(instance, nullptr);
    return ok;
}

bool verifiedVendor(uint32_t vendor, std::string& reason) {
    if (vendor == 0x1002)
        return true;
    if (const char* any = std::getenv("REO_GPU_MOVIES_ANY_VENDOR"); any && std::strcmp(any, "1") == 0)
        return true;
    reason = vendor == 0x10de ? "Movie decoding on NVIDIA graphics cards can crash the game"
             : vendor == 0x8086 ? "Movie decoding on Intel graphics is untested"
                                : "Movie decoding on this graphics card is untested";
    return false;
}

bool plain(const GUID& g) {
    return IsEqualGUID(g, kNoEncrypt) || IsEqualGUID(g, GUID{});
}

// The acceptance rule of Mpeg2VldCore::initialize, on the device setup MovieOwnerService uses.
bool hardwareMpeg2(const LUID& luid, std::string& reason) {
    IDXGIFactory1* factory = nullptr;
    if (FAILED(CreateDXGIFactory1(__uuidof(IDXGIFactory1), reinterpret_cast<void**>(&factory)))) {
        reason = "DXGI unavailable";
        return false;
    }
    IDXGIAdapter1* adapter = nullptr;
    for (UINT i = 0; factory->EnumAdapters1(i, &adapter) != DXGI_ERROR_NOT_FOUND; ++i) {
        DXGI_ADAPTER_DESC1 desc{};
        adapter->GetDesc1(&desc);
        if (!(desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE) && desc.AdapterLuid.LowPart == luid.LowPart &&
            desc.AdapterLuid.HighPart == luid.HighPart)
            break;
        adapter->Release();
        adapter = nullptr;
    }
    factory->Release();
    if (!adapter) {
        reason = "Renderer GPU not found in DXGI";
        return false;
    }
    ID3D11Device* device = nullptr;
    HRESULT hr = D3D11CreateDevice(adapter, D3D_DRIVER_TYPE_UNKNOWN, nullptr,
                                   D3D11_CREATE_DEVICE_VIDEO_SUPPORT | D3D11_CREATE_DEVICE_BGRA_SUPPORT,
                                   nullptr, 0, D3D11_SDK_VERSION, &device, nullptr, nullptr);
    adapter->Release();
    if (FAILED(hr)) {
        reason = "No D3D11 video device";
        return false;
    }
    ID3D11VideoDevice* video = nullptr;
    hr = device->QueryInterface(__uuidof(ID3D11VideoDevice), reinterpret_cast<void**>(&video));
    if (FAILED(hr)) {
        device->Release();
        reason = "No D3D11 video device";
        return false;
    }
    const GUID profiles[] = {D3D11_DECODER_PROFILE_MPEG2_VLD, D3D11_DECODER_PROFILE_MPEG2and1_VLD};
    bool found = false;
    for (const auto& profile : profiles) {
        BOOL nv12 = FALSE;
        if (FAILED(video->CheckVideoDecoderFormat(&profile, DXGI_FORMAT_NV12, &nv12)) || !nv12)
            continue;
        D3D11_VIDEO_DECODER_DESC desc{profile, 640, 448, DXGI_FORMAT_NV12};
        UINT configs = 0;
        if (FAILED(video->GetVideoDecoderConfigCount(&desc, &configs)))
            continue;
        for (UINT i = 0; i < configs && !found; ++i) {
            D3D11_VIDEO_DECODER_CONFIG config{};
            if (FAILED(video->GetVideoDecoderConfig(&desc, i, &config)) || config.ConfigBitstreamRaw != 1 ||
                !plain(config.guidConfigBitstreamEncryption) ||
                !plain(config.guidConfigMBcontrolEncryption) ||
                !plain(config.guidConfigResidDiffEncryption) || config.ConfigMinRenderTargetBuffCount > 8)
                continue;
            ID3D11VideoDecoder* decoder = nullptr;
            if (SUCCEEDED(video->CreateVideoDecoder(&desc, &config, &decoder))) {
                decoder->Release();
                found = true;
            }
        }
        if (found)
            break;
    }
    video->Release();
    device->Release();
    reason = found ? "Hardware MPEG-2 decoder available" : "This GPU has no hardware MPEG-2 decoder";
    return found;
}
} // namespace

int main() {
    Selected gpu;
    std::string error;
    if (!selectRendererGpu(gpu, error) || !gpu.luidValid)
        return report(gpu.name, false, error);
    std::string reason;
    const bool gpuMovies = verifiedVendor(gpu.vendor, reason) && hardwareMpeg2(gpu.luid, reason);
    return report(gpu.name, gpuMovies, reason);
}
