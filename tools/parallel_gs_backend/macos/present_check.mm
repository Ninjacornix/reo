#import <Cocoa/Cocoa.h>
#import <QuartzCore/QuartzCore.h>
#include "resident_metal_presenter.h"
#include "context.hpp"
#include "thread_id.hpp"
#include <fstream>
#include <iostream>

void* reoMetalLayerForWindow(void*, int, int);

static std::vector<uint32_t> shader(const std::filesystem::path& path) {
    std::ifstream file(path, std::ios::binary | std::ios::ate);
    const auto bytes = file.tellg();
    if (bytes < 20 || bytes > 4 * 1024 * 1024 || bytes % 4)
        throw std::runtime_error("Invalid presentation shader: " + path.string());
    std::vector<uint32_t> words(size_t(bytes) / 4);
    file.seekg(0);
    file.read(reinterpret_cast<char*>(words.data()), bytes);
    if (!file || words[0] != 0x07230203)
        throw std::runtime_error("Invalid presentation SPIR-V");
    return words;
}

int main(int argc, char** argv) {
    @autoreleasepool {
        try {
            if (argc != 2)
                throw std::runtime_error("Usage: macos_present_check PRESENT_SHADER_DIRECTORY");
            [NSApplication sharedApplication];
            [NSApp setActivationPolicy:NSApplicationActivationPolicyAccessory];
            NSWindow* window = [[NSWindow alloc]
                initWithContentRect:NSMakeRect(0, 0, 640, 480)
                          styleMask:NSWindowStyleMaskTitled | NSWindowStyleMaskResizable
                            backing:NSBackingStoreBuffered
                              defer:NO];
            window.title = @"REO Metal presentation check";
            [window orderFront:nil];
            [NSApp finishLaunching];
            void* layer = reoMetalLayerForWindow((__bridge void*)window, 640, 480);
            [CATransaction flush];
            Util::register_thread_index(0);
            if (!Vulkan::Context::init_loader(nullptr))
                throw std::runtime_error("Vulkan loader unavailable");
            Vulkan::Context context;
            context.set_num_thread_indices(1);
            const char* instances[] = {"VK_KHR_surface", "VK_EXT_metal_surface"};
            const char* devices[] = {"VK_KHR_swapchain"};
            if (!context.init_instance_and_device(instances, 2, devices, 1))
                throw std::runtime_error("Metal WSI context initialization failed");
            {
                Vulkan::Device device;
                device.set_context(context);
                device.init_frame_contexts(4);
                const auto directory = std::filesystem::path(argv[1]);
                reo_gpu_present::ResidentMetalPresenter presenter(
                    device, shader(directory / "present_opaque.vert.spv"),
                    shader(directory / "present_native.frag.spv"));
                std::vector<uint32_t> pixels(320 * 240, 0xff604020u);
                const Vulkan::ImageInitialData initial{pixels.data(), 0, 0};
                auto info = Vulkan::ImageCreateInfo::immutable_2d_image(
                    320, 240, VK_FORMAT_R8G8B8A8_UNORM);
                info.initial_layout = VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL;
                auto source = device.create_image(info, &initial);
                if (!source)
                    throw std::runtime_error("Test image allocation failed");
                for (unsigned frame = 0; frame < 8; ++frame) {
                    const unsigned width = frame < 4 ? 640 : 800;
                    if (frame == 4)
                        [window setContentSize:NSMakeSize(width, 480)];
                    layer = reoMetalLayerForWindow((__bridge void*)window, width, 480);
                    [CATransaction flush];
                    presenter.attach(reinterpret_cast<uintptr_t>(layer), width, 480);
                    auto completed = presenter.present(source, false, frame % 2 != 0);
                    if (!completed)
                        throw std::runtime_error("Presentation did not return a GPU fence");
                    completed->wait();
                    device.next_frame_context();
                    while (NSEvent* event = [NSApp nextEventMatchingMask:NSEventMaskAny
                        untilDate:[NSDate distantPast] inMode:NSDefaultRunLoopMode dequeue:YES])
                        [NSApp sendEvent:event];
                }
                if (presenter.submittedFrames() != 8)
                    throw std::runtime_error("Metal presentation count mismatch");
                device.wait_idle();
            }
            [window orderOut:nil];
            std::cout << "PASS metal_present frames=8 resized=1 game=0 pixel_comparison=0\n";
            return 0;
        } catch (const std::exception& error) {
            std::cerr << "FAIL metal_present " << error.what() << '\n';
            return 1;
        }
    }
}
