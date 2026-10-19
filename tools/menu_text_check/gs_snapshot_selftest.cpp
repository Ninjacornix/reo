// No game code/assets: exercise the real GS queue and post-flip scanout marker.
// A framebuffer clear submitted after the marker must not replace its pixels.
#include "runtime/ps2_gs_gpu.h"
#include "runtime/ps2_memory.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

void ps2GsSnapshotDisplay();

namespace {
bool isRgb(const std::vector<uint8_t>& pixels, uint8_t expected) {
    if (pixels.empty())
        return false;
    for (size_t offset = 0; offset < pixels.size(); offset += 4)
        if (pixels[offset] != expected || pixels[offset + 1] != expected ||
            pixels[offset + 2] != expected)
            return false;
    return true;
}

bool copy(GS& gs, std::vector<uint8_t>& pixels) {
    gs.latchHostPresentationFrame();
    uint32_t width = 0, height = 0, display = ~0u, source = ~0u;
    bool preferred = true;
    const bool copied =
        gs.copyLatchedHostPresentationFrame(pixels, width, height, &display, &source, &preferred);
    return copied && width == 64 && height == 64 && display == 0 && source == 0 && !preferred;
}
} // namespace

int main(int argc, char** argv) {
    const bool expectCurrentRace = argc == 2 && std::strcmp(argv[1], "--expect-current-race") == 0;
    _putenv("REO_GS_THREAD=1");
    _putenv("REO_BLACK_FRAME_FALLBACK=");
    _putenv("REO_FIELD_BOB=");

    // The GS worker has process lifetime in this runtime. Keep its referenced
    // resources alive through _Exit rather than destroying them under a worker.
    auto* vram = new std::vector<uint8_t>(PS2_GS_VRAM_SIZE, 255);
    auto* registers = new GSRegisters{};
    registers->pmode = 1;                                // CRT1 only.
    registers->smode2 = 2;                               // Progressive frame mode.
    registers->dispfb1 = 1ull << 9;                      // FBP0, FBW1, PSMCT32.
    registers->display1 = (63ull << 32) | (63ull << 44); // 64 x 64.
    auto* gs = new GS;
    gs->init(vram->data(), static_cast<uint32_t>(vram->size()), registers);
    gs->writeRegister(GS_REG_FRAME_1, 1ull << 16); // FBP0, FBW1.
    gs->writeRegister(GS_REG_SCISSOR_1, (63ull << 16) | (63ull << 48));
    gs->writeRegister(GS_REG_XYOFFSET_1, 0);
    gs->writeRegister(GS_REG_ZBUF_1, 1ull << 32); // Z writes masked.
    gs->writeRegister(GS_REG_TEST_1, 0);
    gs->writeRegister(GS_REG_PRIM, 6u | (1u << 8));         // Untextured, unblended sprite.
    gs->writeRegister(GS_REG_RGBAQ, 0x3f80000080000000ull); // Black, Q=1.
    gs->getLastDisplayBaseBytes(); // Drain setup before the scanout marker.

    ps2GsSnapshotDisplay();
    gs->getLastDisplayBaseBytes(); // The async marker must complete before inspection.
    std::vector<uint8_t> pixels;
    const bool initialWhite = copy(*gs, pixels) && isRgb(pixels, 255);

    // A fast IRQ clock can mark an unchanged image many times without GS work.
    // These markers must not prevent the following clear from making progress.
    for (unsigned i = 0; i < 1024; ++i)
        ps2GsSnapshotDisplay();

    // This simulates later frame work reusing the captured display buffer while
    // the host presentation is delayed. It belongs after the marker, never to it.
    gs->writeRegister(GS_REG_XYZ2, 0);
    gs->writeRegister(GS_REG_XYZ2, 1024ull | (1024ull << 16));
    gs->getLastDisplayBaseBytes(); // Prove the later queued clear has completed.
    const bool oldFrameCopied = copy(*gs, pixels);
    const bool oldFrameWhite = oldFrameCopied && isRgb(pixels, 255);
    const bool oldFrameBlack = oldFrameCopied && isRgb(pixels, 0);

    ps2GsSnapshotDisplay();        // The next marker should intentionally show black.
    gs->getLastDisplayBaseBytes(); // Wait for the new marker, not just its preceding clear.
    const bool nextBlack = copy(*gs, pixels) && isRgb(pixels, 0);

    // No draw intervenes, but DISPFB changes to untouched white VRAM. Reuse must
    // consider privileged display state rather than only the GS command serial.
    registers->dispfb1 = (1ull << 9) | 32u;
    ps2GsSnapshotDisplay();
    gs->getLastDisplayBaseBytes();
    uint32_t width = 0, height = 0, display = 0, source = 0;
    bool preferred = false;
    gs->latchHostPresentationFrame();
    const bool switchedWhite = gs->copyLatchedHostPresentationFrame(pixels, width, height, &display,
                                                                    &source, &preferred) &&
                               width == 64 && height == 64 && display == 32 && source == 32 &&
                               isRgb(pixels, 255);

    // Distinct RGB/alpha values exercise the identical-CRT scanout shortcut.
    // One CRT is the oracle; both constant-alpha and source-alpha compositing
    // must preserve its pixels when CRT2 reads exactly the same source.
    gs->writeRegister(GS_REG_RGBAQ, 0x3f8000000b357ecdull);
    gs->writeRegister(GS_REG_XYZ2, 0);
    gs->writeRegister(GS_REG_XYZ2, 1024ull | (1024ull << 16));
    registers->dispfb1 = 1ull << 9;
    registers->dispfb2 = registers->dispfb1;
    registers->display2 = registers->display1;
    registers->pmode = 1;
    ps2GsSnapshotDisplay();
    gs->getLastDisplayBaseBytes();
    const bool singleCopied = copy(*gs, pixels);
    const std::vector<uint8_t> singleCrt = pixels;
    registers->pmode = 0x7f27; // Two identical CRTs, constant alpha127.
    ps2GsSnapshotDisplay();
    gs->getLastDisplayBaseBytes();
    const bool constantAlphaSame = singleCopied && copy(*gs, pixels) && pixels == singleCrt;
    registers->pmode = 0x7f07; // Two identical CRTs, source alpha11.
    ps2GsSnapshotDisplay();
    gs->getLastDisplayBaseBytes();
    const bool sourceAlphaSame = singleCopied && copy(*gs, pixels) && pixels == singleCrt;
    registers->dispfb2 = (1ull << 9) | 32u;
    registers->pmode = 0x27; // Alpha0 selects the distinct white CRT2.
    ps2GsSnapshotDisplay();
    gs->getLastDisplayBaseBytes();
    const bool distinctCrtWhite = copy(*gs, pixels) && isRgb(pixels, 255);
    const bool passed = initialWhite && nextBlack && switchedWhite && constantAlphaSame &&
                        sourceAlphaSame && distinctCrtWhite &&
                        (expectCurrentRace ? oldFrameBlack : oldFrameWhite);
    std::printf("initial_white=%d captured_white_after_later_clear=%d "
                "captured_black_after_later_clear=%d next_black=%d switched_white=%d "
                "constant_alpha_same=%d source_alpha_same=%d distinct_crt_white=%d\n",
                initialWhite, oldFrameWhite, oldFrameBlack, nextBlack, switchedWhite,
                constantAlphaSame, sourceAlphaSame, distinctCrtWhite);
    std::printf("%s %s\n", passed ? "PASS" : "FAIL",
                expectCurrentRace ? "current snapshot lifetime defect reproduced"
                                  : "scanout pixels belong to their capture marker");
    std::fflush(stdout);
    std::_Exit(passed ? 0 : 1);
}
