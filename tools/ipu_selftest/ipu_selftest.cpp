// Standalone IPU self-test: fake DMA/RAM host, hand-built MPEG-2 bitstreams (tools/ipu_selftest/run.bat).
#include "ipu/ps2_ipu.h"
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <vector>

static std::vector<uint8_t> ram(1 << 20);
static std::map<uint32_t, uint32_t> io;
static std::map<uint32_t, unsigned> completions;
static std::map<uint32_t, unsigned> memReads;
static std::vector<uint8_t> scratchpad(16 * 1024);
static int fails = 0;

static void check(bool ok, const char* what) {
    std::printf("%s %s\n", ok ? "PASS" : "FAIL", what);
    if (!ok)
        ++fails;
}

struct Bits {
    std::vector<uint8_t> b;
    int n = 0;
    void put(const char* s) {
        for (; *s; ++s) {
            if (*s == ' ')
                continue;
            if (n % 8 == 0)
                b.push_back(0);
            if (*s == '1')
                b.back() |= 0x80 >> (n % 8);
            ++n;
        }
    }
    void pad16() {
        while (b.size() % 16)
            b.push_back(0);
    }
};

// Put data at 0x10000 and run it through DMA channel 4 (normal mode).
static void feed(const Bits& bits) {
    std::memcpy(ram.data() + 0x10000, bits.b.data(), bits.b.size());
    io[0x1000B410] = 0x10000;
    io[0x1000B420] = static_cast<uint32_t>(bits.b.size() / 16);
    io[0x1000B400] = 0x100; // normal mode, STR
    ps2_ipu::dmaKick(0x1000B400);
}

static void startOut(uint32_t addr, uint32_t qwc) {
    io[0x1000B010] = addr;
    io[0x1000B020] = qwc;
    io[0x1000B000] = 0x100;
    ps2_ipu::dmaKick(0x1000B000);
}

int main() {
    ps2_ipu::Host h;
    h.readIo = [](uint32_t a) { return io[a]; };
    h.writeIo = [](uint32_t a, uint32_t v) { io[a] = v; };
    h.mem = [](uint32_t a, uint32_t s) -> uint8_t* {
        ++memReads[a];
        if (a & 0x80000000u) {
            const uint32_t off = a & 0x3FFFu;
            return (off + s <= scratchpad.size()) ? scratchpad.data() + off : nullptr;
        }
        return (static_cast<uint64_t>(a) + s <= ram.size()) ? ram.data() + a : nullptr;
    };
    h.dmaComplete = [](uint32_t ch) {
        ++completions[ch];
        std::printf("  dma%u complete\n", ch);
    };
    ps2_ipu::setHost(h);

    // ---- Test 1: BDEC intra, DC only. Y0..3 diff +10 (size 4 '110' + '1010'), EOB '10';
    // Cb diff -3 (size 2 '10' + '00'), Cr diff +5 (size 3 '110' + '101'), EOB '10'.
    ps2_ipu::write32(0x10002010, 0x40000000); // reset, MPEG-2, IDP 0, zigzag, linear q
    Bits b1;
    // Y0: +10 -> 138; Y1..Y3: diff 0 (size 0 '100') -> 138
    b1.put("110 1010 10");
    for (int i = 0; i < 3; ++i)
        b1.put("100 10");
    b1.put("10 00 10");   // Cb: size 2 ('10'), bits '00' -> -3 => 125
    b1.put("110 101 10"); // Cr: size 3 ('110'), bits '101' -> +5 => 133
    b1.pad16();
    startOut(0x40000, 48);
    feed(b1);
    // BDEC: mbi=1, dcr=1, dt=0, qsc=1, fb=0
    ps2_ipu::write32(0x10002000, (2u << 28) | (1u << 27) | (1u << 26) | (1u << 16));
    const int16_t* o = reinterpret_cast<const int16_t*>(ram.data() + 0x40000);
    bool yok = true;
    for (int i = 0; i < 256; ++i)
        yok &= (o[i] >= 137 && o[i] <= 139);
    bool cbok = true, crok = true;
    for (int i = 0; i < 64; ++i) {
        cbok &= (o[256 + i] >= 124 && o[256 + i] <= 126);
        crok &= (o[320 + i] >= 132 && o[320 + i] <= 134);
    }
    std::printf("  Y[0]=%d Y[255]=%d Cb=%d Cr=%d busy=%08X ctrl=%08X\n", o[0], o[255], o[256],
                o[320], ps2_ipu::read32(0x10002004), ps2_ipu::read32(0x10002010));
    check(((ps2_ipu::read32(0x10002010) >> 8) & 0x3Fu) == 0x3Fu,
          "BDEC intra exposes CBP 0x3F in IPU_CTRL[13:8]");
    check(yok, "BDEC luma DC 138");
    check(cbok, "BDEC Cb DC 125");
    check(crok, "BDEC Cr DC 133");
    check((io[0x1000B000] & 0x100) == 0, "DMA3 completed (48 qw)");
    check(ps2_ipu::read32(0x10002004) == 0, "IPU idle after BDEC");

    // ---- Test 2: FDEC / VDEC on a fresh stream.
    ps2_ipu::write32(0x10002010, 0x40000000);
    Bits b2;
    b2.put("011 1 00000000 00000000 00000000 0000000");
    b2.pad16();
    feed(b2);
    ps2_ipu::write32(0x10002000, 4u << 28); // FDEC fb=0
    const uint32_t fdec = ps2_ipu::read32(0x10002000);
    std::printf("  FDEC=%08X\n", fdec);
    check(fdec == 0x70000000u, "FDEC peeks 32 bits");
    ps2_ipu::write32(0x10002000, 3u << 28); // VDEC tbl 0 (MBAI), fb 0
    const uint32_t vdec = ps2_ipu::read32(0x10002000);
    std::printf("  VDEC=%08X BP=%08X\n", vdec, ps2_ipu::read32(0x10002020));
    check(vdec == 0x00030002u, "VDEC MBAI '011' = 2, length 3");
    check((ps2_ipu::read32(0x10002020) & 0x7F) == 3, "BP advanced by 3");

    // ---- Test 3: CSC of a grey macroblock.
    ps2_ipu::write32(0x10002010, 0x40000000);
    Bits b3;
    for (int i = 0; i < 384; ++i)
        b3.put("10000000");
    b3.pad16();
    std::memset(ram.data() + 0x50000, 0xEE, 1024);
    startOut(0x50000, 64);
    feed(b3);
    ps2_ipu::write32(0x10002000, (7u << 28) | 1u); // CSC mbc=1, RGB32
    const uint8_t* px = ram.data() + 0x50000;
    std::printf("  CSC px0 = %u %u %u %u\n", px[0], px[1], px[2], px[3]);
    check(px[0] >= 128 && px[0] <= 131 && px[1] >= 128 && px[1] <= 131 && px[2] >= 128 &&
              px[2] <= 131,
          "CSC grey");

    // ---- Test 4: BDEC non-intra, cbp = block 0 only ('1010' = 32), coefficient run 1 level 1
    // ('011' + sign 0) => scan pos 1 = natural (0,1): horizontal frequency 1. qsc 8 (qs 16),
    // W 16: F = (3*16*16)/32 = 24 -> ~4.2*cos((2x+1)pi/16): +4 at x=0, -4 at x=7, rows equal.
    ps2_ipu::write32(0x10002010, 0x40000000);
    Bits b4;
    b4.put("1010 0110 10");
    b4.pad16();
    startOut(0x60000, 48);
    feed(b4);
    ps2_ipu::write32(0x10002000, (2u << 28) | (8u << 16)); // BDEC mbi=0, qsc=8
    const int16_t* q = reinterpret_cast<const int16_t*>(ram.data() + 0x60000);
    std::printf("  row0: %d %d %d %d %d %d %d %d | row7 x0=%d | Y1 x8=%d\n", q[0], q[1], q[2], q[3],
                q[4], q[5], q[6], q[7], q[7 * 16], q[8]);
    check(q[0] == 4 && q[7] == -4 && q[7 * 16] == q[0] && q[8] == 0,
          "BDEC non-intra AC (horizontal)");
    check(((ps2_ipu::read32(0x10002010) >> 8) & 0x3Fu) == 32u,
          "BDEC non-intra exposes coded-block pattern 32");

    // ---- Test 5: TO_IPU REF+IRQ ends a chain after its own payload with TIE set.
    // TAG comes from bits 31:16 of the tag's lower word, not the upper ADDR word.
    ps2_ipu::write32(0x10002010, 0x40000000);
    io.clear();
    completions.clear();
    memReads.clear();
    constexpr uint32_t tagAt = 0x20000, payloadAt = 0x30000, nextPayloadAt = 0x31000;
    const uint64_t irqRef = (uint64_t(payloadAt) << 32) | 0xB0000002u; // REF, IRQ, 2 QW
    const uint64_t nextEnd = (uint64_t(nextPayloadAt) << 32) | 0x70000001u;
    std::memcpy(ram.data() + tagAt, &irqRef, sizeof(irqRef));
    std::memcpy(ram.data() + tagAt + 16, &nextEnd, sizeof(nextEnd));
    std::memset(ram.data() + payloadAt, 0xA5, 32);
    std::memset(ram.data() + nextPayloadAt, 0x5A, 16);
    io[0x1000B410] = 0;
    io[0x1000B420] = 0;
    io[0x1000B430] = tagAt;
    io[0x1000B400] = 0x185; // DIR=1, chain, TIE, STR
    ps2_ipu::dmaKick(0x1000B400);
    check((io[0x1000B400] & 0xFFFF0000u) == 0xB0000000u, "DMA4 CHCR.TAG reflects tag lower word");
    check((io[0x1000B400] & 0x100u) == 0, "DMA4 IRQ/TIE clears STR after tag payload");
    check(io[0x1000B420] == 0 && io[0x1000B410] == payloadAt + 32,
          "DMA4 transfers exactly tag QWC");
    check(io[0x1000B430] == tagAt + 16, "DMA4 IRQ/TIE leaves TADR at the following tag");
    check(completions[4] == 1, "DMA4 IRQ/TIE raises one completion");
    check(memReads[payloadAt] == 1 && memReads[payloadAt + 16] == 1,
          "DMA4 reads both tagged payload QW");
    check(memReads[tagAt + 16] == 0 && memReads[nextPayloadAt] == 0,
          "DMA4 IRQ/TIE does not consume next tag");
    ps2_ipu::read32(0x10002010);
    ps2_ipu::dmaKick(0x1000B400); // idle poll/kick must not re-raise completion
    check(completions[4] == 1, "DMA4 completion is not repeated while idle");
    ps2_ipu::write32(0x10002000, 4u << 28);
    check(ps2_ipu::read32(0x10002000) == 0xA5A5A5A5u, "DMA4 tagged payload reaches IPU FIFO");

    // ---- Test 6: synthetic BDEC -> scratchpad -> CBP-gated packing -> RAM -> CSC.
    // This generic hardware fixture checks CBP publication for a CPU-copy consumer.
    // It does not establish the cause of a particular game's video failure.
    ps2_ipu::write32(0x10002010, 0x40000000);
    io.clear();
    std::memset(scratchpad.data(), 0, scratchpad.size());
    startOut(0x80001800u, 48);
    feed(b1);
    ps2_ipu::write32(0x10002000, (2u << 28) | (1u << 27) | (1u << 26) | (1u << 16));
    const uint32_t pictureCbp = (ps2_ipu::read32(0x10002010) >> 8) & 0x3Fu;
    Bits packed;
    packed.b.resize(384, 0);
    if (pictureCbp != 0) {
        for (size_t i = 0; i < packed.b.size(); ++i) {
            int16_t sample;
            std::memcpy(&sample, scratchpad.data() + 0x1800 + i * 2, sizeof(sample));
            packed.b[i] = static_cast<uint8_t>(sample < 0 ? 0 : sample > 255 ? 255 : sample);
        }
    }
    check(packed.b[0] >= 137 && packed.b[0] <= 139 && packed.b[256] >= 124 &&
              packed.b[256] <= 126 && packed.b[320] >= 132 && packed.b[320] <= 134,
          "CBP-gated CPU packing copies decoded SPR macroblock");
    ps2_ipu::write32(0x10002010, 0x40000000);
    startOut(0x70000, 64);
    feed(packed);
    ps2_ipu::write32(0x10002000, (7u << 28) | 1u);
    const uint8_t* picture = ram.data() + 0x70000;
    check(picture[0] > 100 && picture[1] > 100 && picture[2] > 100,
          "BDEC/CPU-copy/CSC pipeline produces a non-green frame");
    check((io[0x1000B000] & 0x100u) == 0, "Pipeline DMA3 completes RGB32 output");
    std::printf("%s (%d failures)\n", fails ? "FAILED" : "ALL PASS", fails);
    return fails ? 1 : 0;
}
