// GPU integration check: real subsamples must survive scanout, rather than
// merely multiplying the size of a nearest-neighbour image.
#include "parallel_backend.h"
#include "gs_registers.hpp"
#include "thread_id.hpp"
#include "runtime/gs/internal_resolution.h"
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <utility>
using namespace gs_backend_bridge;
using namespace reo_parallel_backend;
using namespace ParallelGS;

static void require(bool value, const char* message) {
    if (!value) throw std::runtime_error(message);
}
static Privileged display() {
    Reg64<SMODE1Bits> clock{};
    clock.desc.LC = SMODE1Bits::LC_ANALOG;
    clock.desc.CMOD = SMODE1Bits::CMOD_NTSC;
    clock.desc.SPML = 4;
    Privileged p{};
    // Match Outbreak's field-mode framebuffer and the host progressive policy.
    p[0] = 1; p[1] = clock.bits; p[2] = 1;
    p[7] = 8ull << 9;
    p[8] = 636ull | (50ull << 12) | (4ull << 23) |
           (2559ull << 32) | (447ull << 44);
    p[15] = 0x551B4000; p[16] = 0x7F00;
    return p;
}
static Frame render(const char* scale) {
    _putenv_s("REO_INTERNAL_RESOLUTION", scale);
    Config config;
    config.validatedDrawing = true;
    config.forceProgressive = true;
    config.antiBlur = true;
    config.publishPrivilegedReset = [](const Privileged&) {};
    config.publishStatusAck = [](uint64_t) {};
    auto backend = makeFactory(config)();
    std::vector<uint8_t> memory(4u * 1024u * 1024u);
    Init init; init.vram = memory.data(); init.vramSize = memory.size();
    init.registers = display();
    std::string error;
    require(backend->init(init, error), error.c_str());
    if (scale[0] == '2') {
        auto startup = display(); startup[8] = 0;
        auto frame = backend->capture({startup, 122});
        require(frame.width <= 4096 && frame.height <= 4096,
                "Uninitialized display produced an oversized scanout");
    }
    const std::pair<uint8_t, uint64_t> setup[] = {
        {0x1A, 1}, {0x4C, 8ull << 16}, {0x4D, 8ull << 16},
        {0x4E, 224ull | (1ull << 32)}, {0x4F, 224ull | (1ull << 32)},
        {0x40, (511ull << 16) | (447ull << 48)},
        {0x41, (511ull << 16) | (447ull << 48)},
        {0x47, 0x30000}, {0x48, 0x30000}, {0x18, 0}, {0x19, 0}, {0x46, 1}};
    for (auto [address, value] : setup) backend->directRegister(address, value);
    backend->directRegister(0, 3);
    backend->directRegister(1, 0x804080FFull | (0x3F800000ull << 32));
    // Vary depth as a real 3D triangle does. A constant-depth triangle can
    // correctly be identified as UI and intentionally snapped to native pixels.
    backend->directRegister(5, 1ull << 32);
    backend->directRegister(5, (2ull << 32) | (64ull * 16));
    backend->directRegister(5, (3ull << 32) | ((64ull * 16) << 16));
    backend->flush();
    auto frame = backend->capture({display(), 123});
    backend->close();
    require(frame.rgba.size() == size_t(frame.width) * frame.height * 4,
            "Missing GPU pixel readback");
    return frame;
}
int main() try {
    Util::register_thread_index(4);
    require(reo::graphics::internalResolution(nullptr) == 1, "Native default");
    require(!reo::graphics::highResolutionScanout(2, 1, 0, 0), "Startup display guard");
    require(!reo::graphics::highResolutionScanout(2, 3, display()[8], 0),
            "Both enabled circuits must be initialized");
    require(reo::graphics::highResolutionScanout(2, 2, 0, display()[8]),
            "Second display circuit supports 2x");
    bool rejected = false;
    try { reo::graphics::internalResolution("4"); }
    catch (const std::invalid_argument&) { rejected = true; }
    require(rejected, "Unsupported resolution accepted");
    const auto native = render("1");
    const auto higher = render("2");
    require(native.width == 512 && native.height == 448, "Wrong native scanout");
    require(higher.width == native.width * 2 && higher.height == native.height * 2,
            "Internal resolution did not double both dimensions");
    size_t differentBlocks = 0, litPixels = 0;
    for (uint32_t y = 0; y < higher.height; y += 2)
        for (uint32_t x = 0; x < higher.width; x += 2) {
            auto pixel = [&](unsigned dx, unsigned dy) {
                auto i = (size_t(y + dy) * higher.width + x + dx) * 4;
                return uint32_t(higher.rgba[i]) | (uint32_t(higher.rgba[i+1]) << 8) |
                       (uint32_t(higher.rgba[i+2]) << 16);
            };
            auto first = pixel(0, 0);
            litPixels += first != 0;
            differentBlocks += first != pixel(1, 0) || first != pixel(0, 1) ||
                               first != pixel(1, 1);
        }
    std::cout << "lit-pixels=" << litPixels << " subpixel-blocks=" << differentBlocks << '\n';
    require(litPixels > 100, "Triangle not drawn");
    require(differentBlocks > 20, "2x image contains only duplicated native pixels");
    std::cout << "PASS native=" << native.width << 'x' << native.height
              << " 2x=" << higher.width << 'x' << higher.height
              << " distinct-subpixel-blocks=" << differentBlocks << '\n';
    return 0;
} catch (const std::exception& error) {
    std::cerr << error.what() << '\n';
    return 1;
}
