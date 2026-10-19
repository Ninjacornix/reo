#include "gs_interface.hpp"
#include "context.hpp"
#include "device.hpp"
#include "command_buffer.hpp"
#include "fence.hpp"
#include <algorithm>
#include <chrono>
#include <cstring>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace fs = std::filesystem;
using namespace ParallelGS;
using namespace Vulkan;
constexpr size_t vramSize = 4u * 1024u * 1024u;
constexpr unsigned controlAssertions = 9;
static bool nativeScanout = false; // Explicit offline comparison only; native runtime is unchanged.
static bool antiBlur = false;      // Independent offline PCRTC policy control.
static unsigned scanoutWarmup = 0; // Synthetic final-state fields; never original dump evidence.
static bool exportRecordedVsyncs() {
    return nativeScanout || antiBlur;
}
using ReplayClock = std::chrono::steady_clock;
static double microseconds(ReplayClock::time_point begin, ReplayClock::time_point end) {
    return std::chrono::duration<double, std::micro>(end - begin).count();
}
static std::vector<uint8_t> read(const fs::path& p) {
    std::ifstream f(p, std::ios::binary | std::ios::ate);
    if (!f)
        throw std::runtime_error("Cannot read " + p.string());
    const auto size = f.tellg();
    if (size < 0 || size > 256 * 1024 * 1024)
        throw std::runtime_error("Input size limit");
    std::vector<uint8_t> b(static_cast<size_t>(size));
    f.seekg(0);
    if (!b.empty() && !f.read(reinterpret_cast<char*>(b.data()), size))
        throw std::runtime_error("Truncated input");
    return b;
}
static void save(const fs::path& p, const void* bytes, size_t size) {
    std::ofstream f(p, std::ios::binary | std::ios::trunc);
    f.write(static_cast<const char*>(bytes), static_cast<std::streamsize>(size));
    if (!f)
        throw std::runtime_error("Cannot write " + p.string());
}
static uint64_t hash(const uint8_t* p, size_t n) {
    uint64_t h = 14695981039346656037ull;
    for (size_t i = 0; i < n; ++i)
        h = (h ^ p[i]) * 1099511628211ull;
    return h;
}
static void zero(GSInterface& gs) {
    std::memset(gs.map_vram_write(0, vramSize), 0, vramSize);
    gs.end_vram_write(0, vramSize);
}
static void setup(GSInterface& gs) {
    gs.write_register(RegisterAddr::PRMODECONT, uint64_t(1));
    gs.write_register(RegisterAddr::FRAME_1, uint64_t(8) << 16);
    gs.write_register(RegisterAddr::FRAME_2, uint64_t(8) << 16);
    gs.write_register(RegisterAddr::ZBUF_1, uint64_t(224) | (uint64_t(1) << 32));
    gs.write_register(RegisterAddr::ZBUF_2, uint64_t(224) | (uint64_t(1) << 32));
    gs.write_register(RegisterAddr::SCISSOR_1, (uint64_t(511) << 16) | (uint64_t(447) << 48));
    gs.write_register(RegisterAddr::SCISSOR_2, (uint64_t(511) << 16) | (uint64_t(447) << 48));
    gs.write_register(RegisterAddr::TEST_1,
                      uint64_t(0x30000)); // Defined enabled-Z ALWAYS, masked writes.
    gs.write_register(RegisterAddr::TEST_2, uint64_t(0x30000));
    gs.write_register(RegisterAddr::XYOFFSET_1, uint64_t(0));
    gs.write_register(RegisterAddr::XYOFFSET_2, uint64_t(0));
    gs.write_register(RegisterAddr::COLCLAMP, uint64_t(1));
    auto& priv = gs.get_priv_register_state();
    std::memset(&priv, 0, sizeof(priv));
    priv.smode1.LC = SMODE1Bits::LC_ANALOG;
    priv.smode1.CMOD = SMODE1Bits::CMOD_PROGRESSIVE;
    priv.qwords_lo[0x00 / 8] = 1;                // Circuit 1 enabled.
    priv.qwords_lo[0x70 / 8] = uint64_t(8) << 9; // FBP=0, FBW=8, CT32.
    priv.qwords_lo[0x80 / 8] =
        uint64_t(318) | (uint64_t(50) << 12) | (uint64_t(511) << 32) | (uint64_t(447) << 44);
}
static ScanoutResult scanout(GSInterface& gs, unsigned phase = 0) {
    VSyncInfo info = {};
    info.phase = phase;
    info.dst_layout = VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL;
    info.dst_stage = VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT;
    info.dst_access = VK_ACCESS_2_SHADER_SAMPLED_READ_BIT;
    info.force_progressive = !nativeScanout;
    info.anti_blur = antiBlur;
    info.adapt_to_internal_horizontal_resolution = true;
    gs.flush();
    return gs.vsync(info);
}
struct DownloadResult {
    std::vector<uint8_t> pixels;
    double readbackUs = 0;
    unsigned width = 0, height = 0;
    VkFormat format = VK_FORMAT_UNDEFINED;
};
static DownloadResult download(Device& device, const ScanoutResult& out, const fs::path& directory,
                               bool writeOutputs = true) {
    const auto readbackBegin = ReplayClock::now();
    DownloadResult downloaded;
    if (!out.image)
        throw std::runtime_error("No GPU scanout image");
    const auto& ci = out.image->get_create_info();
    if (ci.format != VK_FORMAT_R8G8B8A8_UNORM && ci.format != VK_FORMAT_B8G8R8A8_UNORM &&
        ci.format != VK_FORMAT_R8G8B8A8_SRGB && ci.format != VK_FORMAT_B8G8R8A8_SRGB)
        throw std::runtime_error("Unexpected scanout format; no implicit reinterpretation");
    const size_t bytes = size_t(ci.width) * ci.height * 4;
    BufferCreateInfo bi = {};
    bi.domain = BufferDomain::CachedHost;
    bi.size = bytes;
    bi.usage = VK_BUFFER_USAGE_TRANSFER_DST_BIT;
    auto buffer = device.create_buffer(bi);
    // Diagnostic ownership boundary: all upstream queues complete before this readback.
    device.wait_idle();
    auto cmd = device.request_command_buffer();
    cmd->image_barrier(*out.image, VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL,
                       VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                       VK_ACCESS_2_MEMORY_WRITE_BIT | VK_ACCESS_2_MEMORY_READ_BIT,
                       VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_READ_BIT);
    VkBufferImageCopy copy = {};
    copy.imageSubresource.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    copy.imageSubresource.layerCount = 1;
    copy.imageExtent = {ci.width, ci.height, 1};
    cmd->copy_image_to_buffer(*buffer, *out.image, 1, &copy);
    cmd->buffer_barrier(*buffer, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_WRITE_BIT,
                        VK_PIPELINE_STAGE_HOST_BIT, VK_ACCESS_2_HOST_READ_BIT);
    cmd->image_barrier(*out.image, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                       VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL, VK_PIPELINE_STAGE_TRANSFER_BIT,
                       VK_ACCESS_2_TRANSFER_READ_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT,
                       VK_ACCESS_2_SHADER_SAMPLED_READ_BIT);
    Fence fence;
    device.submit(cmd, &fence);
    fence->wait();
    const auto* pixels =
        static_cast<const uint8_t*>(device.map_host_buffer(*buffer, MEMORY_ACCESS_READ_BIT));
    downloaded.pixels.assign(pixels, pixels + bytes);
    device.unmap_host_buffer(*buffer, MEMORY_ACCESS_READ_BIT);
    downloaded.readbackUs = microseconds(readbackBegin, ReplayClock::now());
    downloaded.width = ci.width;
    downloaded.height = ci.height;
    downloaded.format = ci.format;
    if (!writeOutputs)
        return downloaded;
    save(directory / "scanout.bin", downloaded.pixels.data(), bytes);
    std::ofstream metadata(directory / "scanout.json");
    metadata << "{\"width\":" << ci.width << ",\"height\":" << ci.height
             << ",\"vk_format\":" << ci.format << ",\"internal_width\":" << out.internal_width
             << ",\"internal_height\":" << out.internal_height
             << ",\"mode_width\":" << out.mode_width << ",\"mode_height\":" << out.mode_height
             << ",\"interlaced\":" << (out.interlaced ? "true" : "false")
             << ",\"phase\":" << out.interlace_phase
             << ",\"force_progressive\":" << (nativeScanout ? "false" : "true")
             << ",\"anti_blur\":" << (antiBlur ? "true" : "false") << ",\"fnv64\":\"" << std::hex
             << hash(downloaded.pixels.data(), bytes) << "\"}\n";
    if (!metadata)
        throw std::runtime_error("Cannot write scanout metadata");
    return downloaded;
}
static void saveFieldBmp(const fs::path& path, const DownloadResult& image) {
    if (!image.width || !image.height || image.width > 4096 || image.height > 4096 ||
        image.pixels.size() != size_t(image.width) * image.height * 4)
        throw std::runtime_error("Invalid field BMP extent");
    std::vector<uint8_t> bytes(54 + image.pixels.size());
    auto put16 = [&](size_t offset, uint16_t v) {
        bytes[offset] = uint8_t(v);
        bytes[offset + 1] = uint8_t(v >> 8);
    };
    auto put32 = [&](size_t offset, uint32_t v) {
        for (unsigned i = 0; i < 4; ++i)
            bytes[offset + i] = uint8_t(v >> (8 * i));
    };
    bytes[0] = 'B';
    bytes[1] = 'M';
    put32(2, uint32_t(bytes.size()));
    put32(10, 54);
    put32(14, 40);
    put32(18, image.width);
    put32(22, uint32_t(-int32_t(image.height)));
    put16(26, 1);
    put16(28, 32);
    put32(34, uint32_t(image.pixels.size()));
    const bool bgra =
        image.format == VK_FORMAT_B8G8R8A8_UNORM || image.format == VK_FORMAT_B8G8R8A8_SRGB;
    for (size_t i = 0; i < image.pixels.size(); i += 4) {
        bytes[54 + i] = image.pixels[i + (bgra ? 0 : 2)];
        bytes[54 + i + 1] = image.pixels[i + 1];
        bytes[54 + i + 2] = image.pixels[i + (bgra ? 2 : 0)];
        bytes[54 + i + 3] = 255;
    }
    save(path, bytes.data(), bytes.size());
}
static void logState(const GSInterface& gs, const char* stage) {
    const auto& r = gs.get_register_state();
    const auto& c = r.ctx[r.prim.desc.CTXT];
    std::cerr << "STATE " << stage << " PRIM=" << std::hex << r.prim.bits
              << " RGBAQ=" << r.rgbaq.bits << " FRAME=" << c.frame.bits << " ZBUF=" << c.zbuf.bits
              << " TEST=" << c.test.bits << " SCISSOR=" << c.scissor.bits
              << " XYOFFSET=" << c.xyoffset.bits << " PRMODECONT=" << r.prmodecont.bits << std::dec
              << " prim=" << r.prim.desc.PRIM << " ctxt=" << r.prim.desc.CTXT
              << " rgba=" << unsigned(r.rgbaq.desc.R) << ',' << unsigned(r.rgbaq.desc.G) << ','
              << unsigned(r.rgbaq.desc.B) << ',' << unsigned(r.rgbaq.desc.A)
              << " q=" << r.rgbaq.desc.Q << " fbw=" << c.frame.desc.FBW
              << " fbmask=" << c.frame.desc.FBMSK << " zte=" << c.test.desc.ZTE
              << " ztst=" << c.test.desc.ZTST << " zmask=" << c.zbuf.desc.ZMSK << '\n';
}
static bool extraRasterControl(GSInterface& gs, Device& device, const fs::path& output,
                               const char* name, unsigned primitive, bool reverse, bool packed) {
    gs.reset_context_state();
    setup(gs);
    zero(gs);
    gs.write_register(RegisterAddr::PRIM, uint64_t(primitive));
    gs.write_register(RegisterAddr::RGBAQ, uint64_t(0x80604020) | (uint64_t(0x3f800000) << 32));
    logState(gs, name);
    if (packed) {
        // Exact upstream sandbox layout: PACKED RGBAQ,XYZ2 repeated three times.
        // PRE replaces PRIM with triangle+AA1, as used by sandbox/gs_test.cpp.
        alignas(16) uint64_t packet[14] = {};
        packet[0] = uint64_t(3) | (uint64_t(1) << 15) | (uint64_t(1) << 46) |
                    (uint64_t(3 | (1 << 7)) << 47) | (uint64_t(2) << 60);
        packet[1] = 0x51;
        for (unsigned i = 0; i < 3; ++i) {
            packet[2 + 4 * i] = uint64_t(0x20) | (uint64_t(0x40) << 32);
            packet[3 + 4 * i] = uint64_t(0x60) | (uint64_t(0x80) << 32);
        }
        packet[8] = uint64_t(64 * 16);        // Vertex1 X in first 32-bit word.
        packet[12] = uint64_t(64 * 16) << 32; // Vertex2 Y in second word.
        gs.gif_transfer(0, packet, sizeof(packet));
    } else {
        const uint64_t x = uint64_t(64 * 16), y = x << 16;
        gs.write_register(RegisterAddr::XYZ2, uint64_t(0));
        if (primitive == 6)
            gs.write_register(RegisterAddr::XYZ2, x | y);
        else {
            gs.write_register(RegisterAddr::XYZ2, reverse ? y : x);
            gs.write_register(RegisterAddr::XYZ2, reverse ? x : y);
        }
    }
    logState(gs, name);
    gs.flush();
    const auto* bytes = static_cast<const uint8_t*>(gs.map_vram_read(0, vramSize));
    uint32_t interior = 0;
    std::memcpy(&interior, bytes + 12, 4);
    save(output / (std::string(name) + "-vram.bin"), bytes, vramSize);
    const auto stats = gs.consume_flush_stats();
    std::cerr << "RASTER_CONTROL " << name << " actual=0x" << std::hex << interior
              << " expected=0x80604020" << std::dec << " primitives=" << stats.num_primitives
              << " passes=" << stats.num_render_passes << '\n';
    const auto image = scanout(gs);
    const auto directory = output / name;
    fs::create_directories(directory);
    download(device, image, directory);
    return interior == 0x80604020;
}
static unsigned controls(GSInterface& gs, Device& device, const fs::path& output) {
    unsigned failures = 0;
    setup(gs);
    zero(gs);
    gs.write_register(RegisterAddr::PRIM, uint64_t(3));
    gs.write_register(RegisterAddr::RGBAQ, uint64_t(0x80604020) | (uint64_t(0x3f800000) << 32));
    logState(gs, "original-triangle-before-vertices");
    gs.write_register(RegisterAddr::XYZ2, uint64_t(0));
    gs.write_register(RegisterAddr::XYZ2, uint64_t(64 * 16));
    gs.write_register(RegisterAddr::XYZ2, uint64_t(64 * 16) << 16);
    gs.flush();
    const auto* b = static_cast<const uint8_t*>(gs.map_vram_read(0, vramSize));
    uint32_t pixel = 0;
    std::memcpy(&pixel, b + 12, 4); // Independent CT32 x=1,y=1 word=3.
    save(output / "triangle-control-vram.bin", b, vramSize);
    std::cerr << "TRIANGLE_INTERIOR actual=0x" << std::hex << pixel << " expected=0x80604020"
              << std::dec << '\n';
    const auto controlImage = scanout(gs);
    const auto controlDirectory = output / "triangle-scanout";
    fs::create_directories(controlDirectory);
    download(device, controlImage, controlDirectory);
    device.wait_idle();
    b = static_cast<const uint8_t*>(gs.map_vram_read(0, vramSize));
    uint32_t afterScanout = 0;
    std::memcpy(&afterScanout, b + 12, 4);
    save(output / "triangle-after-scanout-vram.bin", b, vramSize);
    std::cerr << "TRIANGLE_AFTER_SCANOUT actual=0x" << std::hex << afterScanout << std::dec << '\n';
    if (pixel != 0x80604020) {
        ++failures;
        const auto stats = gs.consume_flush_stats();
        std::cerr << "TRIANGLE_FAILURE primitives=" << stats.num_primitives
                  << " passes=" << stats.num_render_passes << '\n';
    }
    // Independent exterior address: x=63,y=31 -> last word of first CT32 page.
    std::memcpy(&pixel, b + 8192 - 4, 4);
    if (pixel != 0) {
        ++failures;
        std::cerr << "FAIL triangle exterior actual=" << pixel << '\n';
    }
    gs.write_register(RegisterAddr::BITBLTBUF, (uint64_t(1) << 48)); // Destination width=64, CT32.
    gs.write_register(RegisterAddr::TRXPOS, uint64_t(128) << 32);
    gs.write_register(RegisterAddr::TRXREG, uint64_t(2) | (uint64_t(2) << 32));
    gs.write_register(RegisterAddr::TRXDIR, uint64_t(0));
    gs.write_register(RegisterAddr::HWREG, uint64_t(0x12345678) | (uint64_t(0x90abcdef) << 32));
    gs.write_register(RegisterAddr::HWREG, uint64_t(0xfedcba09) | (uint64_t(0x87654321) << 32));
    gs.flush();
    b = static_cast<const uint8_t*>(gs.map_vram_read(0, vramSize));
    const uint32_t expected[] = {0x12345678, 0x90abcdef, 0xfedcba09, 0x87654321};
    save(output / "transfer-control-vram.bin", b, vramSize);
    for (unsigned i = 0; i < 4; ++i) {
        std::memcpy(&pixel, b + 16384 + i * 4, 4);
        std::cerr << "TRANSFER_PIXEL " << i << " actual=0x" << std::hex << pixel << " expected=0x"
                  << expected[i] << std::dec << '\n';
        if (pixel != expected[i])
            ++failures;
    }
    if (!extraRasterControl(gs, device, output, "reverse-triangle", 3, true, false))
        ++failures;
    if (!extraRasterControl(gs, device, output, "direct-sprite", 6, false, false))
        ++failures;
    if (!extraRasterControl(gs, device, output, "packed-triangle", 3, false, true))
        ++failures;
    std::cerr << "CONTROL_ASSERTIONS passed=" << controlAssertions - failures
              << " failed=" << failures << '\n';
    return failures;
}
#include "dump_reader.hpp"
struct DumpReplaySummary {
    DumpStats dump;
    uint64_t vramHash = 0, primitives = 0, passes = 0;
    unsigned parityFailures = 0;
};
static DumpReplaySummary repeatDump(GSInterface& gs, Device& device, const fs::path& input,
                                    const fs::path& output, unsigned repeat, std::ostream& result) {
    const auto ioBegin = ReplayClock::now();
    const auto bytes = read(input);
    const double fileReadUs = microseconds(ioBegin, ReplayClock::now());
    DumpReplaySummary summary;
    std::vector<uint8_t> firstVram, firstPixels;
    unsigned firstWidth = 0, firstHeight = 0;
    VkFormat firstFormat = VK_FORMAT_UNDEFINED;
    result << ",\"gs_repeat\":" << repeat << ",\"dump_file_read_us\":" << fileReadUs
           << ",\"dump_file_bytes\":" << bytes.size() << ",\"dump_file_fnv64\":\"" << std::hex
           << hash(bytes.data(), bytes.size()) << std::dec << '"'
           << ",\"repeat_timing_scope\":\"same_device_after_controls_restored_frozen_state_each_"
              "iteration\""
           << ",\"repeat_timings\":[";
    for (unsigned iteration = 0; iteration < repeat; ++iteration) {
        // Reparse cached file bytes so parse/allocation cost is measured separately every time.
        const auto parseBegin = ReplayClock::now();
        const auto parsed = parseDump(bytes);
        const auto parseEnd = ReplayClock::now();
        device.wait_idle(); // Drain previous readbacks before beginning the measured replay.
        (void)gs.consume_flush_stats();
        const auto restoreBegin = ReplayClock::now();
        restoreDump(gs, parsed);
        const auto restoreEnd = ReplayClock::now();
        if (exportRecordedVsyncs() && (!parsed.stats.frames || parsed.stats.frames > 64))
            throw std::runtime_error("Scanout comparison requires 1..64 recorded VSyncs");
        auto lastRecordedImage = enqueueDump(
            gs, parsed,
            [&](unsigned frameIndex, size_t recordIndex, unsigned phase,
                const ScanoutResult& image) {
                if (!exportRecordedVsyncs() || iteration + 1 != repeat)
                    return;
                const auto directory = output / ("vsync-" + std::to_string(frameIndex + 1));
                fs::create_directories(directory);
                const auto pixels = download(device, image, directory);
                saveFieldBmp(directory / "scanout.bmp", pixels);
                const auto& priv = gs.get_priv_register_state();
                std::ofstream state(directory / "display.json");
                state << "{\"original_vsync_index\":" << frameIndex + 1
                      << ",\"record_index\":" << recordIndex << ",\"dump_field_phase\":" << phase
                      << ",\"iteration\":" << iteration
                      << ",\"force_progressive\":" << (nativeScanout ? "false" : "true")
                      << ",\"anti_blur\":" << (antiBlur ? "true" : "false")
                      << ",\"skip_deinterlace\":false"
                      << ",\"pmode\":" << priv.qwords_lo[0] << ",\"smode1\":" << priv.qwords_lo[2]
                      << ",\"smode2\":" << priv.qwords_lo[4]
                      << ",\"dispfb1\":" << priv.qwords_lo[14]
                      << ",\"display1\":" << priv.qwords_lo[16]
                      << ",\"dispfb2\":" << priv.qwords_lo[18]
                      << ",\"display2\":" << priv.qwords_lo[20]
                      << ",\"bgcolor\":" << priv.qwords_lo[28] << "}\n";
                if (!state)
                    throw std::runtime_error("Cannot write recorded VSync state");
            });
        // Native comparison uses the last REAL field, without inventing a fifth
        // duplicate VSync which would mutate the adaptive field-history cache.
        const auto image =
            exportRecordedVsyncs() ? lastRecordedImage : scanout(gs, parsed.stats.lastPhase);
        const auto enqueueEnd = ReplayClock::now();
        device.wait_idle();
        const auto completionEnd = ReplayClock::now();
        const auto stats = gs.consume_flush_stats();
        const auto vramBegin = ReplayClock::now();
        const auto* vram = static_cast<const uint8_t*>(gs.map_vram_read(0, vramSize));
        std::vector<uint8_t> copiedVram(vram, vram + vramSize);
        const auto vramEnd = ReplayClock::now();
        // Hashing, byte comparisons and disk exports are outside readback timing.
        const auto downloaded = download(device, image, output, iteration + 1 == repeat);
        bool identical = true;
        if (iteration == 0) {
            firstVram = copiedVram;
            firstPixels = downloaded.pixels;
            firstWidth = downloaded.width;
            firstHeight = downloaded.height;
            firstFormat = downloaded.format;
        } else {
            identical = copiedVram == firstVram && downloaded.pixels == firstPixels &&
                        downloaded.width == firstWidth && downloaded.height == firstHeight &&
                        downloaded.format == firstFormat;
            if (!identical) {
                if (!summary.parityFailures) {
                    save(output / "repeat-first-vram.bin", firstVram.data(), firstVram.size());
                    save(output / "repeat-first-scanout.bin", firstPixels.data(),
                         firstPixels.size());
                }
                ++summary.parityFailures;
                save(output / ("repeat-mismatch-vram-" + std::to_string(iteration) + ".bin"),
                     copiedVram.data(), copiedVram.size());
                save(output / ("repeat-mismatch-scanout-" + std::to_string(iteration) + ".bin"),
                     downloaded.pixels.data(), downloaded.pixels.size());
            }
        }
        summary.dump = parsed.stats;
        summary.vramHash = hash(copiedVram.data(), copiedVram.size());
        summary.primitives = stats.num_primitives;
        summary.passes = stats.num_render_passes;
        const double parseUs = microseconds(parseBegin, parseEnd);
        const double restoreUs = microseconds(restoreBegin, restoreEnd);
        const double enqueueUs = microseconds(restoreEnd, enqueueEnd);
        const double completionUs = microseconds(enqueueEnd, completionEnd);
        const double vramReadbackUs = microseconds(vramBegin, vramEnd);
        if (iteration)
            result << ',';
        result << "{\"iteration\":" << iteration << ",\"parse_us\":" << parseUs
               << ",\"restore_us\":" << restoreUs << ",\"enqueue_us\":" << enqueueUs
               << ",\"completion_tail_us\":" << completionUs
               << ",\"restore_enqueue_completion_us\":" << microseconds(restoreBegin, completionEnd)
               << ",\"vram_readback_us\":" << vramReadbackUs
               << ",\"scanout_readback_us\":" << downloaded.readbackUs
               << ",\"packets\":" << parsed.stats.packets
               << ",\"packet_bytes\":" << parsed.stats.packetBytes
               << ",\"vsyncs\":" << parsed.stats.frames
               << ",\"fifo_reads\":" << parsed.stats.fifoReads
               << ",\"gpu_primitives\":" << summary.primitives
               << ",\"gpu_passes\":" << summary.passes << ",\"scanout_width\":" << downloaded.width
               << ",\"scanout_height\":" << downloaded.height
               << ",\"scanout_format\":" << downloaded.format << ",\"vram_fnv64\":\"" << std::hex
               << summary.vramHash << "\",\"scanout_fnv64\":\""
               << hash(downloaded.pixels.data(), downloaded.pixels.size()) << std::dec
               << "\",\"exact_outputs_equal_iteration0\":" << (identical ? "true" : "false") << '}';
        std::cerr << "GS_REPEAT iteration=" << iteration << " parse_us=" << parseUs
                  << " restore_us=" << restoreUs << " enqueue_us=" << enqueueUs
                  << " completion_tail_us=" << completionUs
                  << " vram_readback_us=" << vramReadbackUs
                  << " scanout_readback_us=" << downloaded.readbackUs
                  << " exact_outputs=" << identical << '\n';
        if (iteration + 1 == repeat) {
            save(output / "final-vram.bin", copiedVram.data(), copiedVram.size());
            // Explicit synthetic observer, outside original replay timing/parity.
            // Hold the final GS/VRAM state and alternate only field phase. The
            // main scanout above remains the last REAL recorded field.
            if (scanoutWarmup && gs.get_priv_register_state().extwrite.WRITE)
                throw std::runtime_error("Synthetic final-state warmup requires EXTWRITE disabled");
            for (unsigned index = 1; index <= scanoutWarmup; ++index) {
                const unsigned phase = parsed.stats.lastPhase ^ (index & 1u);
                const auto directory = output / "synthetic-warmup" / std::to_string(index);
                fs::create_directories(directory);
                const auto pixels = download(device, scanout(gs, phase), directory);
                saveFieldBmp(directory / "scanout.bmp", pixels);
                const auto& priv = gs.get_priv_register_state();
                std::ofstream state(directory / "display.json");
                state << "{\"synthetic\":true,\"original_dump_vsync\":false,\"warmup_index\":"
                      << index << ",\"phase\":" << phase
                      << ",\"source_original_vsync_count\":" << parsed.stats.frames
                      << ",\"state_policy\":\"hold_final_registers_and_vram_no_new_gif\""
                      << ",\"force_progressive\":" << (nativeScanout ? "false" : "true")
                      << ",\"anti_blur\":" << (antiBlur ? "true" : "false")
                      << ",\"skip_deinterlace\":false,\"extwrite\":" << priv.qwords_lo[26]
                      << ",\"pmode\":" << priv.qwords_lo[0] << ",\"smode2\":" << priv.qwords_lo[4]
                      << ",\"dispfb1\":" << priv.qwords_lo[14]
                      << ",\"display1\":" << priv.qwords_lo[16]
                      << ",\"dispfb2\":" << priv.qwords_lo[18]
                      << ",\"display2\":" << priv.qwords_lo[20] << "}\n";
                if (!state)
                    throw std::runtime_error("Cannot write synthetic scanout state");
            }
        }
    }
    result << "],\"repeat_parity_failures\":" << summary.parityFailures;
    return summary;
}
int main(int argc, char** argv) try {
    if (argc < 2) {
        std::cerr << "Usage: parallel_gs_check EMPTY_OUTPUT [--corpus MANIFEST | --gs DUMP "
                     "[--gs-repeat N] [--native-scanout] [--anti-blur] [--scanout-warmup N]]\n";
        return 2;
    }
    const bool dumpMode = argc >= 3 && std::string(argv[2]) == "--gs";
    unsigned repeat = 1;
    if (dumpMode) {
        if (argc < 4)
            throw std::runtime_error("Missing --gs input");
        bool repeatSeen = false, warmupSeen = false;
        for (int i = 4; i < argc; ++i) {
            if (std::string(argv[i]) == "--native-scanout") {
                if (nativeScanout)
                    throw std::runtime_error("Duplicate --native-scanout");
                nativeScanout = true;
                continue;
            }
            if (std::string(argv[i]) == "--anti-blur") {
                if (antiBlur)
                    throw std::runtime_error("Duplicate --anti-blur");
                antiBlur = true;
                continue;
            }
            if (std::string(argv[i]) == "--scanout-warmup") {
                if (warmupSeen || i + 1 == argc)
                    throw std::runtime_error("Missing or duplicate --scanout-warmup");
                warmupSeen = true;
                const std::string count = argv[++i];
                if (count.size() != 1 || count[0] < '0' || count[0] > '8' || ((count[0] - '0') & 1))
                    throw std::runtime_error("--scanout-warmup requires an even integer in [0,8]");
                scanoutWarmup = unsigned(count[0] - '0');
                continue;
            }
            if (std::string(argv[i]) != "--gs-repeat" || repeatSeen || i + 1 == argc)
                throw std::runtime_error("Expected --gs-repeat N, --native-scanout or --anti-blur");
            repeatSeen = true;
            const std::string count = argv[++i];
            if (count.empty() || count.size() > 2 ||
                count.find_first_not_of("0123456789") != std::string::npos)
                throw std::runtime_error("--gs-repeat must be an integer in [1,32]");
            repeat = static_cast<unsigned>(std::stoul(count));
            if (!repeat || repeat > 32)
                throw std::runtime_error("--gs-repeat must be in [1,32]");
        }
        if (warmupSeen && !exportRecordedVsyncs())
            throw std::runtime_error("--scanout-warmup requires --native-scanout or --anti-blur");
    } else if (argc != 2 && !(argc == 4 && std::string(argv[2]) == "--corpus")) {
        throw std::runtime_error("Invalid arguments; --gs-repeat requires --gs");
    }
    const fs::path output = argv[1];
    if (fs::exists(output) && !fs::is_empty(output))
        throw std::runtime_error("Output must be empty");
    fs::create_directories(output);
    if (!Context::init_loader(nullptr))
        throw std::runtime_error("Vulkan loader initialization failed");
    Context context;
    context.set_num_thread_indices(1);
    const char* descriptorSetting = std::getenv("REO_PARALLEL_GS_DESCRIPTOR_BUFFER");
    const bool requestDescriptorBuffer = !(descriptorSetting && descriptorSetting[0] == '0');
    const unsigned contextFlags =
        CONTEXT_CREATION_ENABLE_PUSH_DESCRIPTOR_BIT | CONTEXT_CREATION_ENABLE_DESCRIPTOR_HEAP_BIT |
        (requestDescriptorBuffer ? CONTEXT_CREATION_ENABLE_DESCRIPTOR_BUFFER_BIT : 0);
    if (!context.init_instance_and_device(nullptr, 0, nullptr, 0, contextFlags))
        throw std::runtime_error("Vulkan device initialization failed");
    Device device;
    device.set_context(context);
    device.init_frame_contexts(4);
    const bool descriptorBufferEnabled = device.get_device_features().supports_descriptor_buffer;
    std::cerr << "DESCRIPTOR_BUFFER requested=" << requestDescriptorBuffer
              << " enabled=" << descriptorBufferEnabled << '\n';
    GSInterface gs;
    GSOptions options = {};
    std::ofstream result(output / "result.json");
    const bool initialized = gs.init(&device, options);
    result << "{\"source_pin\":\"cc6184af7e0c03da603045ca371ffa5dae9b0655\",\"adapter\":"
           << std::quoted(device.get_gpu_properties().deviceName)
           << ",\"gs_initialized\":" << (initialized ? "true" : "false")
           << ",\"descriptor_buffer_requested\":" << (requestDescriptorBuffer ? "true" : "false")
           << ",\"descriptor_buffer_enabled\":" << (descriptorBufferEnabled ? "true" : "false");
    result << ",\"native_scanout\":" << (nativeScanout ? "true" : "false")
           << ",\"force_progressive\":" << (nativeScanout ? "false" : "true")
           << ",\"anti_blur\":" << (antiBlur ? "true" : "false")
           << ",\"synthetic_scanout_warmup_count\":" << scanoutWarmup
           << ",\"synthetic_warmup_in_original_replay_timing\":false"
           << ",\"recorded_vsync_exports\":" << (exportRecordedVsyncs() ? "true" : "false")
           << ",\"field_export_observer_in_enqueue_timing\":"
           << (exportRecordedVsyncs() ? "true" : "false");
    if (!initialized) {
        result << "}\n";
        return 3;
    }
    const unsigned controlFailures = controls(gs, device, output);
    unsigned failures = controlFailures;
    const auto* controlVram = static_cast<const uint8_t*>(gs.map_vram_read(0, vramSize));
    save(output / "control-vram.bin", controlVram, vramSize);
    gs.reset_context_state();
    setup(gs);
    zero(gs);
    (void)gs.consume_flush_stats(); // Corpus counters exclude the independent controls.
    uint64_t packets = 0, packetBytes = 0;
    DumpStats dumpStats;
    DumpReplaySummary repeated;
    bool restoredDump = false;
    if (argc > 2) {
        if (dumpMode) {
            repeated = repeatDump(gs, device, argv[3], output, repeat, result);
            dumpStats = repeated.dump;
            packets = dumpStats.packets;
            packetBytes = dumpStats.packetBytes;
            failures += repeated.parityFailures;
            restoredDump = true;
        } else {
            if (argc != 4 || std::string(argv[2]) != "--corpus")
                throw std::runtime_error("Invalid arguments");
            std::ifstream manifest(argv[3]);
            std::string kind, filename;
            if (!(manifest >> kind) || kind != "REO_ACTUAL_PACKETS_RECONSTRUCTED_STATE_V1")
                throw std::runtime_error("Invalid corpus classification");
            unsigned path = 0;
            while (manifest >> path >> std::quoted(filename)) {
                if (path > 3)
                    throw std::runtime_error("Invalid GIF path");
                const auto bytes = read(filename);
                if (bytes.empty() || bytes.size() % 16)
                    throw std::runtime_error("Invalid GIF byte length");
                // vector<uint64_t> provides the source alignment expected by upstream's decoder.
                std::vector<uint64_t> aligned(bytes.size() / 8);
                std::memcpy(aligned.data(), bytes.data(), bytes.size());
                gs.gif_transfer(path, aligned.data(), bytes.size());
                ++packets;
                packetBytes += bytes.size();
            }
            if (!manifest.eof() || !packets)
                throw std::runtime_error("Malformed or empty corpus");
        }
    }
    uint64_t finalVramHash = repeated.vramHash, primitiveCount = repeated.primitives,
             renderPasses = repeated.passes;
    if (!dumpMode) {
        const auto image = scanout(gs, dumpStats.lastPhase);
        download(device, image, output);
        const auto stats = gs.consume_flush_stats();
        const auto* vram = static_cast<const uint8_t*>(gs.map_vram_read(0, vramSize));
        save(output / "final-vram.bin", vram, vramSize);
        finalVramHash = hash(vram, vramSize);
        primitiveCount = stats.num_primitives;
        renderPasses = stats.num_render_passes;
    }
    result << ",\"independent_control_assertions\":" << controlAssertions
           << ",\"control_failures\":" << controlFailures << ",\"actual_packets\":" << packets
           << ",\"actual_packet_bytes\":" << packetBytes
           << ",\"faithful_room_replay\":false,\"initial_state\":\""
           << (restoredDump ? "pcsx2_frozen_v8_v9" : "reconstructed")
           << "\",\"dump_vsyncs\":" << dumpStats.frames
           << ",\"dump_fifo_reads\":" << dumpStats.fifoReads << ",\"vram_fnv64\":\"" << std::hex
           << finalVramHash << std::dec << "\",\"gpu_primitive_count\":" << primitiveCount
           << ",\"gpu_render_passes\":" << renderPasses << "}\n";
    if (!result)
        throw std::runtime_error("Cannot write result");
    device.wait_idle();
    return failures ? 1 : 0;
} catch (const std::exception& e) {
    std::cerr << "ERROR " << e.what() << '\n';
    return 2;
}
