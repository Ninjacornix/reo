#include "MiniTest.h"

#include <cstdlib>
#include <cmath>
#include <thread>
#include <chrono>
#include "Syscalls/Helpers/CriAudio.h"
#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include "../../third_party/PS2Recomp/ps2xRuntime/src/lib/ipu/ps2_ipu_native.h"
#include "../../third_party/PS2Recomp/ps2xRuntime/src/lib/parent_natural_runtime.h"

namespace {
struct NativeCompressedTestInput {
    std::vector<uint8_t> copied;
    uint32_t budget = 16;
    uint64_t serial = 0;
    static bool resolve(void*, uint32_t source, uint32_t bytes, uint64_t& offset) {
        source &= 0x1fffffffu;
        if (source < 0x40000u || source + bytes > 0x40100u)
            return false;
        offset = source - 0x40000u;
        return true;
    }
    static bool accept(void* owner, uint64_t generation, uint64_t serial, uint64_t offset,
                       uint32_t source, const uint8_t* bytes, uint32_t count) {
        auto& input = *static_cast<NativeCompressedTestInput*>(owner);
        if (generation != 7u || serial != input.serial + 1u ||
            offset != (source & 0x1fffffffu) - 0x40000u)
            throw std::runtime_error("Test compressed DMA lineage changed");
        if (input.copied.size() + count > input.budget)
            return false;
        input.copied.insert(input.copied.end(), bytes, bytes + count);
        input.serial = serial;
        return true;
    }
};
} // namespace

void sub_0018F340_0x18f340(uint8_t*, R5900Context*, PS2Runtime*);

void sub_00126510_0x126510(uint8_t*, R5900Context*, PS2Runtime*);
// Isolate the owned coefficient routine's COP1 arithmetic from libm callees.
void sub_001223D0_0x1223d0(uint8_t*, R5900Context* ctx, PS2Runtime*) {
    ctx->f[0] = std::cos(ctx->f[12]);
    ctx->pc = GPR_U32(ctx, 31);
}
void sub_00122708_0x122708(uint8_t*, R5900Context* ctx, PS2Runtime*) {
    ctx->f[0] = std::sqrt(ctx->f[12]);
    ctx->pc = GPR_U32(ctx, 31);
}

void register_ps2_sif_dma_tests();
void register_ps2_sif_rpc_tests();
void register_ps2_spr_dma_tests();
void register_backedge_tests();

int main() {
    register_ps2_sif_dma_tests();
    register_ps2_sif_rpc_tests();
    register_ps2_spr_dma_tests();
    register_backedge_tests();

    MiniTest::Case("NativeMovieCompressedInput", [](TestCase& suite) {
        suite.Run(
            "real DMA copy, backpressure and bit cursor preserve original header parsing",
            [](TestCase& t) {
                PS2Runtime runtime;
                t.IsTrue(runtime.memory().initialize(), "RAM initializes");
                auto& ctx = runtime.cpu();
                auto* ram = runtime.memory().getRDRAM();
                for (unsigned i = 0; i < 256; ++i)
                    ram[0x40000 + i] = uint8_t(i * 13u + 7u);
                const uint8_t sequence[]{0, 0, 1, 0xb3}, picture[]{0, 0, 1, 0};
                std::memcpy(ram + 0x40000, sequence, 4);
                std::memcpy(ram + 0x40028, picture, 4);
                const auto store = [&](uint32_t address, uint32_t value) {
                    runtime.Store32(ram, &ctx, address, value);
                };
                const auto load = [&](uint32_t address) {
                    return runtime.Load32(ram, &ctx, address);
                };
                store(0x10002010u, 1u << 30);
                store(0x10002000u, 0u);
                NativeCompressedTestInput input;
                ps2_ipu_native::Binding binding{&runtime, &input, 7u,
                                                &NativeCompressedTestInput::resolve,
                                                &NativeCompressedTestInput::accept};
                PS2Runtime::GuestExecutionScope guest(&runtime);
                reo_parent_natural::AccessScope actual(&runtime, &ctx);
                ps2_ipu_native::attach(runtime, binding);
                store(0x1000b410u, 0x40000u);
                store(0x1000b420u, 8u);
                store(0x1000b400u, 0x100u);
                t.Equals(load(0x1000b410u), 0x40010u,
                         "MADR advances only for the actual accepted compressed copy");
                t.Equals(load(0x1000b420u), 7u, "Backpressure retains untransferred QWC");
                t.IsTrue((load(0x1000b400u) & 0x100u) != 0u, "Partial compressed DMA stays active");
                store(0x10002000u, 0x40000000u);
                t.Equals(load(0x10002000u), 0x000001b3u,
                         "Original FDEC still reads the actual sequence header");
                store(0x10002000u, 0x4000000du);
                ps2_ipu_native::Cursor cursor;
                t.IsTrue(ps2_ipu_native::cursor(runtime, &input, 7u, cursor),
                         "Actual compressed lineage has a cursor");
                t.Equals(cursor.elementaryBit, 13ull,
                         "Header bit consumption retains its exact ES position");
                t.IsTrue(!ps2_ipu_native::advanceTo(runtime, &input, 7u, 129u),
                         "Uncopied input cannot be skipped by a synthetic completion");
                t.IsTrue(ps2_ipu_native::cursor(runtime, &input, 7u, cursor),
                         "Partial real progress retains lineage");
                t.Equals(cursor.elementaryBit, 128ull,
                         "Only the genuinely available bits were consumed");
                input.budget = 64u;
                t.IsTrue(ps2_ipu_native::advanceTo(runtime, &input, 7u, 319u),
                         "Ready native output consumes actual compressed bits");
                t.IsTrue(ps2_ipu_native::cursor(runtime, &input, 7u, cursor),
                         "Skipped compressed cursor remains source joined");
                t.Equals(cursor.elementaryBit, 319ull,
                         "One bit before the next prefix is representable");
                store(0x10002000u, 0x40000001u);
                t.Equals(load(0x10002000u), 0x00000100u,
                         "Original alignment FDEC sees the next complete picture prefix");
                bool stale = false;
                try {
                    ps2_ipu_native::advanceTo(runtime, &input, 8u, 320u);
                } catch (const std::invalid_argument&) {
                    stale = true;
                }
                t.IsTrue(stale, "A stale hardware generation cannot consume the current stream");
                // Original restore replays compressed qwords after BCLR. The owner
                // retains its serial while the actual FIFO receives a new view.
                store(0x1000b400u, 0u);
                store(0x10002000u, 0u);
                input.budget = 112u;
                store(0x1000b410u, 0x40000u);
                store(0x1000b420u, 2u);
                store(0x1000b400u, 0x100u);
                store(0x10002000u, 0x40000000u);
                t.Equals(load(0x10002000u), 0x000001b3u,
                         "A genuine restored DMA view retains exact replayed bytes");
                t.IsTrue((load(0x1000b400u) & 0x100u) == 0u && load(0x1000b420u) == 0u,
                         "Compressed DMA completes only after both real qword copies");
                bool cpuGraphics = false;
                try {
                    runtime.memory().write32(0x10002000u, 0x20000000u);
                } catch (const std::runtime_error&) {
                    cpuGraphics = true;
                }
                t.IsTrue(cpuGraphics, "An owned hardware movie cannot silently run CPU BDEC");
                store(0x10002010u, 1u << 30);
                ps2_ipu_native::detach(runtime, &input, 7u);
            });
    });

    MiniTest::Case("VU0TitlePrompt", [](TestCase& suite) {
        suite.Run("runtime constant enables generated sine opacity", [](TestCase& t) {
            PS2Runtime runtime;
            t.IsTrue(runtime.memory().initialize(), "RAM initializes");
            auto& ctx = runtime.cpu();
            alignas(16) float vf0[4];
            _mm_store_ps(vf0, ctx.vu0_vf[0]);
            t.IsTrue(vf0[0] == 0 && vf0[1] == 0 && vf0[2] == 0 && vf0[3] == 1,
                     "VF00 must be the hardware (0,0,0,1) constant");
            uint8_t* ram = runtime.memory().getRDRAM();
            // Four polynomial coefficients and +/-pi bounds from the owned ELF.
            const uint32_t coeff[] = {0x362e9c14u, 0xb94fb21fu, 0x3c08873eu, 0xbe2aaaa4u};
            std::memcpy(ram + 0x22fe30, coeff, sizeof(coeff));
            const uint32_t pi = 0x40490fdbu, minusPi = 0xc0490fdbu;
            std::memcpy(ram + 0x241c88, &pi, 4);
            std::memcpy(ram + 0x241c90, &minusPi, 4);
            for (int i = 1; i < 128; ++i) {
                const float angle = i * 3.14159265358979323846f / 128;
                ctx.f[12] = angle;
                SET_GPR_U32(&ctx, 31, 0);
                ctx.pc = 0x18f340;
                sub_0018F340_0x18f340(ram, &ctx, &runtime);
                t.IsTrue(std::fabs(ctx.f[0] - std::sin(angle)) < 0.001f,
                         "recompiled sine must produce the expected blinking opacity");
            }
        });
    });
    MiniTest::Case("CRIAdxPredictor", [](TestCase& suite) {
        suite.Run("generated coefficient routine uses the encoded square-root source",
                  [](TestCase& t) {
                      PS2Runtime runtime;
                      t.IsTrue(runtime.memory().initialize(), "RAM initializes");
                      auto& ctx = runtime.cpu();
                      uint8_t* ram = runtime.memory().getRDRAM();
                      for (int rate : {24000, 44100, 48000}) {
                          // Poison Fs: neither SQRT.S opcode is allowed to read f0 here.
                          ctx.f[0] = 42.0f;
                          ctx.pc = 0x126510;
                          SET_GPR_U32(&ctx, 4, 500);
                          SET_GPR_U32(&ctx, 5, rate);
                          SET_GPR_U32(&ctx, 6, 0x70000);
                          SET_GPR_U32(&ctx, 7, 0x70002);
                          SET_GPR_U32(&ctx, 29, 0x100000);
                          SET_GPR_U32(&ctx, 31, 0);
                          sub_00126510_0x126510(ram, &ctx, &runtime);
                          int16_t actual[2];
                          std::memcpy(actual, ram + 0x70000, 4);
                          const double a =
                              std::sqrt(2.0) - std::cos(2 * 3.14159265358979323846 * 500 / rate);
                          const double b = std::sqrt(2.0) - 1;
                          const double c = (a - std::sqrt((a + b) * (a - b))) / b;
                          t.IsTrue(std::abs(actual[0] - static_cast<int>(2 * c * 4096)) <= 1 &&
                                       std::abs(actual[1] - static_cast<int>(-c * c * 4096)) <= 1,
                                   "ADX coefficients must match the independent predictor formula");
                      }
                  });
    });
    MiniTest::Case("CRIPcmPlayback", [](TestCase& suite) {
        suite.Run("underrun recovery keeps stereo on the device timeline", [](TestCase& t) {
            ps2_cri_audio::reset();
            ps2_cri_audio::render(nullptr, 0);
            const int16_t left[] = {1, 2, 3, 4, 5, 6, 7, 8},
                          right[] = {10, 20, 30, 40, 50, 60, 70, 80};
            uint64_t end = 0;
            ps2_cri_audio::queue(0x1010, reinterpret_cast<const uint8_t*>(left), sizeof(left), end);
            ps2_cri_audio::configure(0x1000, 0x1010, 0x1020, 2, 48000, 256, true);
            ps2_cri_audio::render(nullptr, 4);
            t.Equals(ps2_cri_audio::consumed(0x1010), 0ull,
                     "missing right channel retains left until a stereo pair is available");
            ps2_cri_audio::queue(0x1020, reinterpret_cast<const uint8_t*>(right), sizeof(right),
                                 end);
            float output[2] = {};
            ps2_cri_audio::render(output, 1);
            t.IsTrue(
                output[0] == 5 / 32768.0f && output[1] == 50 / 32768.0f,
                "late stereo PCM must resume at the current frame, not replay the missed interval");
            t.Equals(ps2_cri_audio::consumed(0x1010), 10ull,
                     "skipped and played left bytes both count toward chunk return");
            t.Equals(ps2_cri_audio::consumed(0x1020), 10ull,
                     "stereo recovery skips both channels equally");
            ps2_cri_audio::render(nullptr, 10);
            ps2_cri_audio::configure(0x1000, 0x1010, 0x1020, 2, 48000, 256, false);
            ps2_cri_audio::queue(0x1010, reinterpret_cast<const uint8_t*>(left), sizeof(left), end);
            ps2_cri_audio::queue(0x1020, reinterpret_cast<const uint8_t*>(right), sizeof(right),
                                 end);
            ps2_cri_audio::render(nullptr, 100);
            ps2_cri_audio::configure(0x1000, 0x1010, 0x1020, 2, 48000, 256, true);
            ps2_cri_audio::render(output, 1);
            t.IsTrue(output[0] == 1 / 32768.0f && output[1] == 10 / 32768.0f,
                     "pause and resume must clear stale lateness without skipping queued PCM");
            ps2_cri_audio::reset();
        });
        suite.Run("underrun recovery preserves fractional source rate", [](TestCase& t) {
            ps2_cri_audio::reset();
            ps2_cri_audio::render(nullptr, 0);
            ps2_cri_audio::configure(0x1000, 0x1010, 0, 1, 8000, 256, true);
            ps2_cri_audio::render(nullptr, 7);
            const int16_t pcm[] = {1, 2, 3, 4};
            uint64_t end = 0;
            ps2_cri_audio::queue(0x1010, reinterpret_cast<const uint8_t*>(pcm), sizeof(pcm), end);
            float output[2] = {};
            ps2_cri_audio::render(output, 1);
            t.IsTrue(output[0] == 2 / 32768.0f && output[1] == 2 / 32768.0f,
                     "seven 48 kHz output frames skip only one 8 kHz source sample");
            t.Equals(ps2_cri_audio::consumed(0x1010), 2ull,
                     "fractional phase must not overconsume source PCM");
            ps2_cri_audio::reset();
        });
        suite.Run("planar stereo waits for both channels and respects pause", [](TestCase& t) {
            ps2_cri_audio::reset();
            const int16_t pcm[480] = {1234, -1234};
            uint64_t leftEnd = 0, rightEnd = 0;
            t.IsTrue(ps2_cri_audio::queue(0x1010, reinterpret_cast<const uint8_t*>(pcm),
                                          sizeof(pcm), leftEnd),
                     "PCM chunk should be accepted without truncating to a descriptor buffer");
            ps2_cri_audio::configure(0x1000, 0x1010, 0x1020, 2, 48000, 256, true);
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
            t.Equals(ps2_cri_audio::consumed(0x1010), 0ull,
                     "stereo must not advance one channel ahead of the other");
            ps2_cri_audio::configure(0x1000, 0x1010, 0x1020, 2, 48000, 256, false);
            t.IsTrue(ps2_cri_audio::queue(0x1020, reinterpret_cast<const uint8_t*>(pcm),
                                          sizeof(pcm), rightEnd),
                     "right channel accepts PCM");
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
            t.Equals(ps2_cri_audio::consumed(0x1010), 0ull,
                     "paused playback retains queued samples");
            ps2_cri_audio::configure(0x1000, 0x1010, 0x1020, 2, 48000, 256, true);
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
            t.Equals(ps2_cri_audio::consumed(0x1010), leftEnd, "PCM consumed at its sample rate");
            t.Equals(ps2_cri_audio::consumed(0x1020), rightEnd,
                     "stereo channels stay synchronized");
            ps2_cri_audio::reset();
        });
        suite.Run("natural-end drain plays out queued PCM, then stops", [](TestCase& t) {
            ps2_cri_audio::reset();
            const int16_t pcm[480] = {1234, -1234};
            uint64_t leftEnd = 0, rightEnd = 0;
            t.IsTrue(ps2_cri_audio::queue(0x2010, reinterpret_cast<const uint8_t*>(pcm),
                                          sizeof(pcm), leftEnd),
                     "left accepts PCM");
            t.IsTrue(ps2_cri_audio::queue(0x2020, reinterpret_cast<const uint8_t*>(pcm),
                                          sizeof(pcm), rightEnd),
                     "right accepts PCM");
            ps2_cri_audio::configure(0x2000, 0x2010, 0x2020, 2, 48000, 256, true);
            ps2_cri_audio::drain(0x2000); // game saw the line finish
            ps2_cri_audio::configure(0x2000, 0x2010, 0x2020, 2, 48000, 256, false);
            std::this_thread::sleep_for(std::chrono::milliseconds(30));
            t.Equals(ps2_cri_audio::consumed(0x2010), leftEnd,
                     "stopped-after-drain voice still plays its queued tail");
            t.Equals(ps2_cri_audio::consumed(0x2020), rightEnd,
                     "drain keeps stereo channels together");
            const int16_t more[480] = {77, -77};
            uint64_t moreEnd = 0;
            t.IsTrue(ps2_cri_audio::queue(0x2010, reinterpret_cast<const uint8_t*>(more),
                                          sizeof(more), moreEnd),
                     "left accepts later PCM");
            t.IsTrue(ps2_cri_audio::queue(0x2020, reinterpret_cast<const uint8_t*>(more),
                                          sizeof(more), moreEnd),
                     "right accepts later PCM");
            std::this_thread::sleep_for(std::chrono::milliseconds(30));
            t.Equals(ps2_cri_audio::consumed(0x2010), leftEnd,
                     "after draining the voice is really stopped");
            ps2_cri_audio::reset();
        });
    });
    const int result = MiniTest::Run();
    std::cout.flush();
    std::cerr.flush();
    // Process-wide HLE workers do not need teardown in this standalone runner.
    std::_Exit(result);
}
