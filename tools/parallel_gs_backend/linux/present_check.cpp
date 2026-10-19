#include "resident_xlib_presenter.h"
#include "context.hpp"
#include "thread_id.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <bit>
#include <chrono>
#include <thread>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

static std::vector<uint32_t> shader(const std::filesystem::path& path) {
    std::ifstream file(path, std::ios::binary | std::ios::ate);
    const auto bytes = file.tellg();
    if (bytes <= 0 || bytes > 4 * 1024 * 1024 || bytes % 4)
        throw std::runtime_error("Invalid fixture shader");
    std::vector<uint32_t> words(size_t(bytes) / 4);
    file.seekg(0);
    file.read(reinterpret_cast<char*>(words.data()), bytes);
    if (!file || words[0] != 0x07230203)
        throw std::runtime_error("Invalid fixture SPIR-V");
    return words;
}

int main(int argc, char** argv) try {
    if (argc != 2)
        throw std::runtime_error("Usage: linux_present_check PRESENT_SHADER_DIRECTORY");
    Display* display = XOpenDisplay(nullptr);
    if (!display)
        throw std::runtime_error("An isolated X server is required for the native present check");
    const Window window =
        XCreateSimpleWindow(display, DefaultRootWindow(display), 0, 0, 640, 480, 0, 0, 0);
    XMapWindow(display, window);
    XSync(display, False);
    Util::register_thread_index(0);
    if (!Vulkan::Context::init_loader(nullptr))
        throw std::runtime_error("Vulkan loader unavailable");
    Vulkan::Context context;
    context.set_num_thread_indices(1);
    const char* instanceExtensions[] = {"VK_KHR_surface", "VK_KHR_xlib_surface"};
    const char* deviceExtensions[] = {"VK_KHR_swapchain"};
    if (!context.init_instance_and_device(instanceExtensions, 2, deviceExtensions, 1))
        throw std::runtime_error("Native Vulkan WSI context failed");
    std::cout << "Vulkan device: " << context.get_gpu_props().deviceName
              << " type=" << context.get_gpu_props().deviceType << std::endl;
    {
        Vulkan::Device device;
        device.set_context(context);
        device.init_frame_contexts(4);
        const auto directory = std::filesystem::path(argv[1]);
        reo_gpu_present::ResidentXlibPresenter presenter(
            device, shader(directory / "present_opaque.vert.spv"),
            shader(directory / "present_native.frag.spv"));
        const std::vector<uint32_t> pixels(320 * 240, 0xff604020u);
        const Vulkan::ImageInitialData initial{pixels.data(), 0, 0};
        auto sourceInfo =
            Vulkan::ImageCreateInfo::immutable_2d_image(320, 240, VK_FORMAT_R8G8B8A8_UNORM);
        sourceInfo.initial_layout = VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL;
        auto source = device.create_image(sourceInfo, &initial);
        if (!source)
            throw std::runtime_error("Fixture image allocation failed");
        for (unsigned frame = 0; frame < 8; ++frame) {
            const unsigned width = frame < 4 ? 640 : 800;
            if (frame == 4) {
                XResizeWindow(display, window, width, 480);
                XSync(display, False);
            }
            presenter.attach(window, width, 480);
            auto complete = presenter.present(source, false, frame % 2 != 0);
            if (!complete)
                throw std::runtime_error("Presentation did not produce a real GPU fence");
            complete->wait();
            device.next_frame_context();
        }
        if (presenter.submittedFrames() != 8)
            throw std::runtime_error("Native present count mismatch");
        device.wait_idle();
        std::this_thread::sleep_for(
            std::chrono::milliseconds(100)); // Isolated display-test observation only.
        XSync(display, False);
        XImage* observed = XGetImage(display, window, 0, 0, 800, 480, AllPlanes, ZPixmap);
        if (!observed)
            throw std::runtime_error("Cannot observe the isolated presentation window");
        const auto center = XGetPixel(observed, 400, 240);
        const auto border = XGetPixel(observed, 4, 240);
        const auto channel = [](unsigned long pixel, unsigned long mask) {
            return unsigned((pixel & mask) >> std::countr_zero(mask));
        };
        const unsigned red = channel(center, observed->red_mask);
        const unsigned green = channel(center, observed->green_mask);
        const unsigned blue = channel(center, observed->blue_mask);
        const unsigned black =
            unsigned(border & (observed->red_mask | observed->green_mask | observed->blue_mask));
        XDestroyImage(observed);
        if (red != 32 || green != 64 || blue != 96 || black != 0)
            throw std::runtime_error("Native shader color/layout mismatch: " + std::to_string(red) +
                                     "," + std::to_string(green) + "," + std::to_string(blue) +
                                     " border=" + std::to_string(black));
    }
    XDestroyWindow(display, window);
    XCloseDisplay(display);
    std::cout << "PASS native_xlib_present frames=8 resized=1 color=1 letterbox=1 game=0\n";
    return 0;
} catch (const std::exception& error) {
    std::cerr << "FAIL native_xlib_present " << error.what() << '\n';
    return 1;
}
