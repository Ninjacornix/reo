#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00100838
// Address: 0x100838 - 0x100b70
void sub_00100838_0x100838(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x100838u;

label_100838:
    // 0x100838: 0x27bdff40
    ctx->pc = 0x100838u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x10083c: 0xffb30050
    ctx->pc = 0x10083cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 19));
    // 0x100840: 0xffb20040
    ctx->pc = 0x100840u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x100844: 0x80982d
    ctx->pc = 0x100844u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x100848: 0xffb60080
    ctx->pc = 0x100848u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 22));
    // 0x10084c: 0xa0902d
    ctx->pc = 0x10084cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x100850: 0xffbf00b0
    ctx->pc = 0x100850u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 31));
    // 0x100854: 0x3c160020
    ctx->pc = 0x100854u;
    SET_GPR_U32(ctx, 22, ((uint32_t)32 << 16));
    // 0x100858: 0xffbe00a0
    ctx->pc = 0x100858u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 30));
    // 0x10085c: 0xffb70090
    ctx->pc = 0x10085cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 23));
    // 0x100860: 0xffb50070
    ctx->pc = 0x100860u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 21));
    // 0x100864: 0xffb40060
    ctx->pc = 0x100864u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 20));
    // 0x100868: 0xffb10030
    ctx->pc = 0x100868u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 17));
    // 0x10086c: 0xffb00020
    ctx->pc = 0x10086cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x100870: 0xc040164
    ctx->pc = 0x100870u;
    SET_GPR_U32(ctx, 31, 0x100878u);
    ctx->pc = 0x100874u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 6));
    ctx->pc = 0x100590u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00100590_0x100590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100878u; }
    }
    if (ctx->pc != 0x100878u) { return; }
    ctx->pc = 0x100878u;
    // 0x100878: 0x8ec47928
    ctx->pc = 0x100878u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 22), 31016)));
    // 0x10087c: 0xc04519c
    ctx->pc = 0x10087Cu;
    SET_GPR_U32(ctx, 31, 0x100884u);
    ctx->pc = 0x114670u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114670_0x114670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100884u; }
    }
    if (ctx->pc != 0x100884u) { return; }
    ctx->pc = 0x100884u;
    // 0x100884: 0x8ec37928
    ctx->pc = 0x100884u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 22), 31016)));
    // 0x100888: 0x146200a4
    ctx->pc = 0x100888u;
    {
        const bool branch_taken_0x100888 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 2));
        ctx->pc = 0x10088Cu;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x100888) {
            ctx->pc = 0x100B1Cu;
            goto label_100b1c;
        }
    }
    ctx->pc = 0x100890u;
    // 0x100890: 0x3c020026
    ctx->pc = 0x100890u;
    SET_GPR_U32(ctx, 2, ((uint32_t)38 << 16));
    // 0x100894: 0x3c060020
    ctx->pc = 0x100894u;
    SET_GPR_U32(ctx, 6, ((uint32_t)32 << 16));
    // 0x100898: 0x24030001
    ctx->pc = 0x100898u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
    // 0x10089c: 0x8c449f98
    ctx->pc = 0x10089cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 4294942616)));
    // 0x1008a0: 0x3c050026
    ctx->pc = 0x1008a0u;
    SET_GPR_U32(ctx, 5, ((uint32_t)38 << 16));
    // 0x1008a4: 0x0
    ctx->pc = 0x1008a4u;
    // NOP
    // 0x1008a8: 0xc045148
    ctx->pc = 0x1008A8u;
    SET_GPR_U32(ctx, 31, 0x1008B0u);
    ctx->pc = 0x1008ACu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294942624));
    ctx->pc = 0x114520u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114520_0x114520(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1008B0u; }
    }
    if (ctx->pc != 0x1008B0u) { return; }
    ctx->pc = 0x1008B0u;
    // 0x1008b0: 0xc04035e
    ctx->pc = 0x1008B0u;
    SET_GPR_U32(ctx, 31, 0x1008B8u);
    ctx->pc = 0x1008B4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x100D78u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00100D78_0x100d78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1008B8u; }
    }
    if (ctx->pc != 0x1008B8u) { return; }
    ctx->pc = 0x1008B8u;
    // 0x1008b8: 0x14400065
    ctx->pc = 0x1008B8u;
    {
        const bool branch_taken_0x1008b8 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1008BCu;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1008b8) {
            ctx->pc = 0x100A50u;
            goto label_100a50;
        }
    }
    ctx->pc = 0x1008C0u;
    // 0x1008c0: 0xc045c20
    ctx->pc = 0x1008C0u;
    SET_GPR_U32(ctx, 31, 0x1008C8u);
    ctx->pc = 0x1008C4u;
    SET_GPR_U32(ctx, 17, ((uint32_t)32 << 16));
    ctx->pc = 0x117080u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00117080_0x117080(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1008C8u; }
    }
    if (ctx->pc != 0x1008C8u) { return; }
    ctx->pc = 0x1008C8u;
    // 0x1008c8: 0x8e227944
    ctx->pc = 0x1008c8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 17), 31044)));
    // 0x1008cc: 0x441002d
    ctx->pc = 0x1008CCu;
    {
        const bool branch_taken_0x1008cc = (GPR_S32(ctx, 2) >= 0);
        ctx->pc = 0x1008D0u;
        SET_GPR_U32(ctx, 23, ((uint32_t)38 << 16));
        if (branch_taken_0x1008cc) {
            ctx->pc = 0x100984u;
            goto label_100984;
        }
    }
    ctx->pc = 0x1008D4u;
    // 0x1008d4: 0x3c140020
    ctx->pc = 0x1008d4u;
    SET_GPR_U32(ctx, 20, ((uint32_t)32 << 16));
    // 0x1008d8: 0x3c150026
    ctx->pc = 0x1008d8u;
    SET_GPR_U32(ctx, 21, ((uint32_t)38 << 16));
    // 0x1008dc: 0x1000000b
    ctx->pc = 0x1008DCu;
    {
        const bool branch_taken_0x1008dc = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1008E0u;
        SET_GPR_U32(ctx, 30, ((uint32_t)38 << 16));
        if (branch_taken_0x1008dc) {
            ctx->pc = 0x10090Cu;
            goto label_10090c;
        }
    }
    ctx->pc = 0x1008E4u;
    // 0x1008e4: 0x0
    ctx->pc = 0x1008e4u;
    // NOP
label_1008e8:
    // 0x1008e8: 0x2403ffff
    ctx->pc = 0x1008e8u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1008ec: 0x0
    ctx->pc = 0x1008ecu;
    // NOP
label_1008f0:
    // 0x1008f0: 0x2442ffff
    ctx->pc = 0x1008f0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1008f4: 0x0
    ctx->pc = 0x1008f4u;
    // NOP
    // 0x1008f8: 0x0
    ctx->pc = 0x1008f8u;
    // NOP
    // 0x1008fc: 0x0
    ctx->pc = 0x1008fcu;
    // NOP
    // 0x100900: 0x0
    ctx->pc = 0x100900u;
    // NOP
    // 0x100904: 0x1443fffa
    ctx->pc = 0x100904u;
    {
        const bool branch_taken_0x100904 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 3));
        if (branch_taken_0x100904) {
            ctx->pc = 0x1008F0u;
            goto label_1008f0;
        }
    }
    ctx->pc = 0x10090Cu;
label_10090c:
    // 0x10090c: 0x26f0a180
    ctx->pc = 0x10090cu;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 23), 4294943104));
label_100910:
    // 0x100910: 0x3c058000
    ctx->pc = 0x100910u;
    SET_GPR_U32(ctx, 5, ((uint32_t)32768 << 16));
    // 0x100914: 0x200202d
    ctx->pc = 0x100914u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x100918: 0x34a50597
    ctx->pc = 0x100918u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 1431));
    // 0x10091c: 0xc045e06
    ctx->pc = 0x10091Cu;
    SET_GPR_U32(ctx, 31, 0x100924u);
    ctx->pc = 0x100920u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x117818u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00117818_0x117818(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100924u; }
    }
    if (ctx->pc != 0x100924u) { return; }
    ctx->pc = 0x100924u;
    // 0x100924: 0x4430013
    ctx->pc = 0x100924u;
    {
        const bool branch_taken_0x100924 = (GPR_S32(ctx, 2) >= 0);
        if (branch_taken_0x100924) {
            ctx->pc = 0x100928u;
            SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 36)));
            ctx->pc = 0x100974u;
            goto label_100974;
        }
    }
    ctx->pc = 0x10092Cu;
    // 0x10092c: 0x8e827910
    ctx->pc = 0x10092cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 20), 30992)));
    // 0x100930: 0x18400005
    ctx->pc = 0x100930u;
    {
        const bool branch_taken_0x100930 = (GPR_S32(ctx, 2) <= 0);
        ctx->pc = 0x100934u;
        SET_GPR_U32(ctx, 2, ((uint32_t)16 << 16));
        if (branch_taken_0x100930) {
            ctx->pc = 0x100948u;
            goto label_100948;
        }
    }
    ctx->pc = 0x100938u;
    // 0x100938: 0x3c040023
    ctx->pc = 0x100938u;
    SET_GPR_U32(ctx, 4, ((uint32_t)35 << 16));
    // 0x10093c: 0xc045a12
    ctx->pc = 0x10093Cu;
    SET_GPR_U32(ctx, 31, 0x100944u);
    ctx->pc = 0x100940u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 29864));
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100944u; }
    }
    if (ctx->pc != 0x100944u) { return; }
    ctx->pc = 0x100944u;
    // 0x100944: 0x3c020010
    ctx->pc = 0x100944u;
    SET_GPR_U32(ctx, 2, ((uint32_t)16 << 16));
label_100948:
    // 0x100948: 0x2403ffff
    ctx->pc = 0x100948u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10094c: 0x0
    ctx->pc = 0x10094cu;
    // NOP
label_100950:
    // 0x100950: 0x2442ffff
    ctx->pc = 0x100950u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x100954: 0x0
    ctx->pc = 0x100954u;
    // NOP
    // 0x100958: 0x0
    ctx->pc = 0x100958u;
    // NOP
    // 0x10095c: 0x0
    ctx->pc = 0x10095cu;
    // NOP
    // 0x100960: 0x0
    ctx->pc = 0x100960u;
    // NOP
    // 0x100964: 0x1443fffa
    ctx->pc = 0x100964u;
    {
        const bool branch_taken_0x100964 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 3));
        if (branch_taken_0x100964) {
            ctx->pc = 0x100950u;
            goto label_100950;
        }
    }
    ctx->pc = 0x10096Cu;
    // 0x10096c: 0x1000ffe8
    ctx->pc = 0x10096Cu;
    {
        const bool branch_taken_0x10096c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x100970u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 23), 4294943104));
        if (branch_taken_0x10096c) {
            ctx->pc = 0x100910u;
            goto label_100910;
        }
    }
    ctx->pc = 0x100974u;
label_100974:
    // 0x100974: 0x1040ffdc
    ctx->pc = 0x100974u;
    {
        const bool branch_taken_0x100974 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x100978u;
        SET_GPR_U32(ctx, 2, ((uint32_t)16 << 16));
        if (branch_taken_0x100974) {
            ctx->pc = 0x1008E8u;
            goto label_1008e8;
        }
    }
    ctx->pc = 0x10097Cu;
    // 0x10097c: 0x10000004
    ctx->pc = 0x10097Cu;
    {
        const bool branch_taken_0x10097c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x100980u;
        WRITE32(ADD32(GPR_U32(ctx, 17), 31044), GPR_U32(ctx, 0));
        if (branch_taken_0x10097c) {
            ctx->pc = 0x100990u;
            goto label_100990;
        }
    }
    ctx->pc = 0x100984u;
label_100984:
    // 0x100984: 0x3c140020
    ctx->pc = 0x100984u;
    SET_GPR_U32(ctx, 20, ((uint32_t)32 << 16));
    // 0x100988: 0x3c150026
    ctx->pc = 0x100988u;
    SET_GPR_U32(ctx, 21, ((uint32_t)38 << 16));
    // 0x10098c: 0x3c1e0026
    ctx->pc = 0x10098cu;
    SET_GPR_U32(ctx, 30, ((uint32_t)38 << 16));
label_100990:
    // 0x100990: 0x92430000
    ctx->pc = 0x100990u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x100994: 0x26a4a000
    ctx->pc = 0x100994u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 21), 4294942720));
    // 0x100998: 0x282d
    ctx->pc = 0x100998u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10099c: 0x31600
    ctx->pc = 0x10099cu;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 3), 24));
    // 0x1009a0: 0x1040000c
    ctx->pc = 0x1009A0u;
    {
        const bool branch_taken_0x1009a0 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1009A4u;
        WRITE8(ADD32(GPR_U32(ctx, 4), 36), (uint8_t)GPR_U32(ctx, 3));
        if (branch_taken_0x1009a0) {
            ctx->pc = 0x1009D4u;
            goto label_1009d4;
        }
    }
    ctx->pc = 0x1009A8u;
    // 0x1009a8: 0x24860024
    ctx->pc = 0x1009a8u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 4), 36));
    // 0x1009ac: 0x24a50001
    ctx->pc = 0x1009acu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 1));
label_1009b0:
    // 0x1009b0: 0x28a20100
    ctx->pc = 0x1009b0u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 5), 256));
    // 0x1009b4: 0x10400007
    ctx->pc = 0x1009B4u;
    {
        const bool branch_taken_0x1009b4 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1009B8u;
        SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 5)));
        if (branch_taken_0x1009b4) {
            ctx->pc = 0x1009D4u;
            goto label_1009d4;
        }
    }
    ctx->pc = 0x1009BCu;
    // 0x1009bc: 0xa62021
    ctx->pc = 0x1009bcu;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
    // 0x1009c0: 0x90430000
    ctx->pc = 0x1009c0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1009c4: 0xa0830000
    ctx->pc = 0x1009c4u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1009c8: 0x31e00
    ctx->pc = 0x1009c8u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 3), 24));
    // 0x1009cc: 0x5460fff8
    ctx->pc = 0x1009CCu;
    {
        const bool branch_taken_0x1009cc = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        if (branch_taken_0x1009cc) {
            ctx->pc = 0x1009D0u;
            SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 1));
            ctx->pc = 0x1009B0u;
            goto label_1009b0;
        }
    }
    ctx->pc = 0x1009D4u;
label_1009d4:
    // 0x1009d4: 0x24020100
    ctx->pc = 0x1009d4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 256));
    // 0x1009d8: 0x14a20004
    ctx->pc = 0x1009D8u;
    {
        const bool branch_taken_0x1009d8 = (GPR_U32(ctx, 5) != GPR_U32(ctx, 2));
        ctx->pc = 0x1009DCu;
        SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 20), 30992)));
        if (branch_taken_0x1009d8) {
            ctx->pc = 0x1009ECu;
            goto label_1009ec;
        }
    }
    ctx->pc = 0x1009E0u;
    // 0x1009e0: 0x26a2a000
    ctx->pc = 0x1009e0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 21), 4294942720));
    // 0x1009e4: 0xa0400123
    ctx->pc = 0x1009e4u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 291), (uint8_t)GPR_U32(ctx, 0));
    // 0x1009e8: 0x8e827910
    ctx->pc = 0x1009e8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 20), 30992)));
label_1009ec:
    // 0x1009ec: 0x18400005
    ctx->pc = 0x1009ECu;
    {
        const bool branch_taken_0x1009ec = (GPR_S32(ctx, 2) <= 0);
        ctx->pc = 0x1009F0u;
        SET_GPR_U32(ctx, 4, ((uint32_t)35 << 16));
        if (branch_taken_0x1009ec) {
            ctx->pc = 0x100A04u;
            goto label_100a04;
        }
    }
    ctx->pc = 0x1009F4u;
    // 0x1009f4: 0x3c050026
    ctx->pc = 0x1009f4u;
    SET_GPR_U32(ctx, 5, ((uint32_t)38 << 16));
    // 0x1009f8: 0x248474c8
    ctx->pc = 0x1009f8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 29896));
    // 0x1009fc: 0xc045a12
    ctx->pc = 0x1009FCu;
    SET_GPR_U32(ctx, 31, 0x100A04u);
    ctx->pc = 0x100A00u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294942756));
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100A04u; }
    }
    if (ctx->pc != 0x100A04u) { return; }
    ctx->pc = 0x100A04u;
label_100a04:
    // 0x100a04: 0x8fa20010
    ctx->pc = 0x100a04u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x100a08: 0x26b0a000
    ctx->pc = 0x100a08u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 21), 4294942720));
    // 0x100a0c: 0x2405012c
    ctx->pc = 0x100a0cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 300));
    // 0x100a10: 0x200202d
    ctx->pc = 0x100a10u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x100a14: 0xae020128
    ctx->pc = 0x100a14u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 296), GPR_U32(ctx, 2));
    // 0x100a18: 0xc045bf4
    ctx->pc = 0x100A18u;
    SET_GPR_U32(ctx, 31, 0x100A20u);
    ctx->pc = 0x100A1Cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 292), GPR_U32(ctx, 16));
    ctx->pc = 0x116FD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116FD0_0x116fd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100A20u; }
    }
    if (ctx->pc != 0x100A20u) { return; }
    ctx->pc = 0x100A20u;
    // 0x100a20: 0x26e4a180
    ctx->pc = 0x100a20u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 23), 4294943104));
    // 0x100a24: 0xafa00000
    ctx->pc = 0x100a24u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x100a28: 0x282d
    ctx->pc = 0x100a28u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x100a2c: 0x302d
    ctx->pc = 0x100a2cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x100a30: 0x200382d
    ctx->pc = 0x100a30u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x100a34: 0x2408012c
    ctx->pc = 0x100a34u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 0), 300));
    // 0x100a38: 0x27c9a140
    ctx->pc = 0x100a38u;
    SET_GPR_S32(ctx, 9, ADD32(GPR_U32(ctx, 30), 4294943040));
    // 0x100a3c: 0x240a0004
    ctx->pc = 0x100a3cu;
    SET_GPR_S32(ctx, 10, ADD32(GPR_U32(ctx, 0), 4));
    // 0x100a40: 0xc045e7a
    ctx->pc = 0x100A40u;
    SET_GPR_U32(ctx, 31, 0x100A48u);
    ctx->pc = 0x100A44u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1179E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100A48u; }
    }
    if (ctx->pc != 0x100A48u) { return; }
    ctx->pc = 0x100A48u;
    // 0x100a48: 0x4410006
    ctx->pc = 0x100A48u;
    {
        const bool branch_taken_0x100a48 = (GPR_S32(ctx, 2) >= 0);
        ctx->pc = 0x100A4Cu;
        SET_GPR_U32(ctx, 2, ((uint32_t)8192 << 16));
        if (branch_taken_0x100a48) {
            ctx->pc = 0x100A64u;
            goto label_100a64;
        }
    }
    ctx->pc = 0x100A50u;
label_100a50:
    // 0x100a50: 0x8ec47928
    ctx->pc = 0x100a50u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 22), 31016)));
    // 0x100a54: 0xc045190
    ctx->pc = 0x100A54u;
    SET_GPR_U32(ctx, 31, 0x100A5Cu);
    ctx->pc = 0x114640u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100A5Cu; }
    }
    if (ctx->pc != 0x100A5Cu) { return; }
    ctx->pc = 0x100A5Cu;
    // 0x100a5c: 0x1000002f
    ctx->pc = 0x100A5Cu;
    {
        const bool branch_taken_0x100a5c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x100A60u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x100a5c) {
            ctx->pc = 0x100B1Cu;
            goto label_100b1c;
        }
    }
    ctx->pc = 0x100A64u;
label_100a64:
    // 0x100a64: 0x2021025
    ctx->pc = 0x100a64u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x100a68: 0x68430007
    ctx->pc = 0x100a68u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 7); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & ~mask) | ((aligned_data << shift) & mask)); }
    // 0x100a6c: 0x6c430000
    ctx->pc = 0x100a6cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 0); uint32_t shift = (addr & 7) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & ~mask) | ((aligned_data >> shift) & mask)); }
    // 0x100a70: 0x6844000f
    ctx->pc = 0x100a70u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 15); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & ~mask) | ((aligned_data << shift) & mask)); }
    // 0x100a74: 0x6c440008
    ctx->pc = 0x100a74u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 8); uint32_t shift = (addr & 7) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & ~mask) | ((aligned_data >> shift) & mask)); }
    // 0x100a78: 0x68450017
    ctx->pc = 0x100a78u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 23); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & ~mask) | ((aligned_data << shift) & mask)); }
    // 0x100a7c: 0x6c450010
    ctx->pc = 0x100a7cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 16); uint32_t shift = (addr & 7) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & ~mask) | ((aligned_data >> shift) & mask)); }
    // 0x100a80: 0x6846001f
    ctx->pc = 0x100a80u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 31); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & ~mask) | ((aligned_data << shift) & mask)); }
    // 0x100a84: 0x6c460018
    ctx->pc = 0x100a84u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 24); uint32_t shift = (addr & 7) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & ~mask) | ((aligned_data >> shift) & mask)); }
    // 0x100a88: 0xb2630007
    ctx->pc = 0x100a88u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 7); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 3) >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x100a8c: 0xb6630000
    ctx->pc = 0x100a8cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 0); uint32_t shift = ((addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 3) << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x100a90: 0xb264000f
    ctx->pc = 0x100a90u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 15); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 4) >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x100a94: 0xb6640008
    ctx->pc = 0x100a94u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 8); uint32_t shift = ((addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 4) << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x100a98: 0xb2650017
    ctx->pc = 0x100a98u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 23); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 5) >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x100a9c: 0xb6650010
    ctx->pc = 0x100a9cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 16); uint32_t shift = ((addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 5) << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x100aa0: 0xb266001f
    ctx->pc = 0x100aa0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 31); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 6) >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x100aa4: 0xb6660018
    ctx->pc = 0x100aa4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 24); uint32_t shift = ((addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 6) << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x100aa8: 0x88430023
    ctx->pc = 0x100aa8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 35); uint32_t shift = (3 - (addr & 3)) << 3; uint32_t mask = 0xFFFFFFFF << shift; uint32_t aligned_word = READ32(addr & ~3); SET_GPR_U32(ctx, 3, (GPR_U32(ctx, 3) & ~mask) | ((aligned_word << shift) & mask)); }
    // 0x100aac: 0x98430020
    ctx->pc = 0x100aacu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 32); uint32_t shift = (addr & 3) << 3; uint32_t mask = 0xFFFFFFFF >> shift; uint32_t aligned_word = READ32(addr & ~3); SET_GPR_U32(ctx, 3, (GPR_U32(ctx, 3) & ~mask) | ((aligned_word >> shift) & mask)); }
    // 0x100ab0: 0xaa630023
    ctx->pc = 0x100ab0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 35); uint32_t shift = (3 - (addr & 3)) << 3; uint32_t mask = 0xFFFFFFFF >> shift; uint32_t aligned_addr = addr & ~3; uint32_t old_data = READ32(aligned_addr); uint32_t new_data = (old_data & ~mask) | ((GPR_U32(ctx, 3) >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x100ab4: 0xba630020
    ctx->pc = 0x100ab4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 32); uint32_t shift = (addr & 3) << 3; uint32_t mask = 0xFFFFFFFF << shift; uint32_t aligned_addr = addr & ~3; uint32_t old_data = READ32(aligned_addr); uint32_t new_data = (old_data & ~mask) | ((GPR_U32(ctx, 3) << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x100ab8: 0x8e837910
    ctx->pc = 0x100ab8u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 20), 30992)));
    // 0x100abc: 0x18600010
    ctx->pc = 0x100ABCu;
    {
        const bool branch_taken_0x100abc = (GPR_S32(ctx, 3) <= 0);
        ctx->pc = 0x100AC0u;
        SET_GPR_U32(ctx, 4, ((uint32_t)35 << 16));
        if (branch_taken_0x100abc) {
            ctx->pc = 0x100B00u;
            goto label_100b00;
        }
    }
    ctx->pc = 0x100AC4u;
    // 0x100ac4: 0x26650008
    ctx->pc = 0x100ac4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 19), 8));
    // 0x100ac8: 0xc045a12
    ctx->pc = 0x100AC8u;
    SET_GPR_U32(ctx, 31, 0x100AD0u);
    ctx->pc = 0x100ACCu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 29920));
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100AD0u; }
    }
    if (ctx->pc != 0x100AD0u) { return; }
    ctx->pc = 0x100AD0u;
    // 0x100ad0: 0x8e827910
    ctx->pc = 0x100ad0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 20), 30992)));
    // 0x100ad4: 0x1840000a
    ctx->pc = 0x100AD4u;
    {
        const bool branch_taken_0x100ad4 = (GPR_S32(ctx, 2) <= 0);
        ctx->pc = 0x100AD8u;
        SET_GPR_U32(ctx, 4, ((uint32_t)35 << 16));
        if (branch_taken_0x100ad4) {
            ctx->pc = 0x100B00u;
            goto label_100b00;
        }
    }
    ctx->pc = 0x100ADCu;
    // 0x100adc: 0x8e650004
    ctx->pc = 0x100adcu;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 19), 4)));
    // 0x100ae0: 0xc045a12
    ctx->pc = 0x100AE0u;
    SET_GPR_U32(ctx, 31, 0x100AE8u);
    ctx->pc = 0x100AE4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 29936));
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100AE8u; }
    }
    if (ctx->pc != 0x100AE8u) { return; }
    ctx->pc = 0x100AE8u;
    // 0x100ae8: 0x8e827910
    ctx->pc = 0x100ae8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 20), 30992)));
    // 0x100aec: 0x18400004
    ctx->pc = 0x100AECu;
    {
        const bool branch_taken_0x100aec = (GPR_S32(ctx, 2) <= 0);
        ctx->pc = 0x100AF0u;
        SET_GPR_U32(ctx, 4, ((uint32_t)35 << 16));
        if (branch_taken_0x100aec) {
            ctx->pc = 0x100B00u;
            goto label_100b00;
        }
    }
    ctx->pc = 0x100AF4u;
    // 0x100af4: 0x8e650000
    ctx->pc = 0x100af4u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x100af8: 0xc045a12
    ctx->pc = 0x100AF8u;
    SET_GPR_U32(ctx, 31, 0x100B00u);
    ctx->pc = 0x100AFCu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 29952));
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100B00u; }
    }
    if (ctx->pc != 0x100B00u) { return; }
    ctx->pc = 0x100B00u;
label_100b00:
    // 0x100b00: 0x3c032000
    ctx->pc = 0x100b00u;
    SET_GPR_U32(ctx, 3, ((uint32_t)8192 << 16));
    // 0x100b04: 0x27c2a140
    ctx->pc = 0x100b04u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 30), 4294943040));
    // 0x100b08: 0x431025
    ctx->pc = 0x100b08u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x100b0c: 0x8ec47928
    ctx->pc = 0x100b0cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 22), 31016)));
    // 0x100b10: 0xc045190
    ctx->pc = 0x100B10u;
    SET_GPR_U32(ctx, 31, 0x100B18u);
    ctx->pc = 0x100B14u;
    SET_GPR_U32(ctx, 16, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    ctx->pc = 0x114640u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100B18u; }
    }
    if (ctx->pc != 0x100B18u) { return; }
    ctx->pc = 0x100B18u;
    // 0x100b18: 0x200102d
    ctx->pc = 0x100b18u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_100b1c:
    // 0x100b1c: 0xdfbf00b0
    ctx->pc = 0x100b1cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x100b20: 0xdfbe00a0
    ctx->pc = 0x100b20u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x100b24: 0xdfb70090
    ctx->pc = 0x100b24u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x100b28: 0xdfb60080
    ctx->pc = 0x100b28u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x100b2c: 0xdfb50070
    ctx->pc = 0x100b2cu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x100b30: 0xdfb40060
    ctx->pc = 0x100b30u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x100b34: 0xdfb30050
    ctx->pc = 0x100b34u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x100b38: 0xdfb20040
    ctx->pc = 0x100b38u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x100b3c: 0xdfb10030
    ctx->pc = 0x100b3cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x100b40: 0xdfb00020
    ctx->pc = 0x100b40u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x100b44: 0x3e00008
    ctx->pc = 0x100B44u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x100B48u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 192));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x100838u: goto label_100838;
            case 0x1008E8u: goto label_1008e8;
            case 0x1008F0u: goto label_1008f0;
            case 0x10090Cu: goto label_10090c;
            case 0x100910u: goto label_100910;
            case 0x100948u: goto label_100948;
            case 0x100950u: goto label_100950;
            case 0x100974u: goto label_100974;
            case 0x100984u: goto label_100984;
            case 0x100990u: goto label_100990;
            case 0x1009B0u: goto label_1009b0;
            case 0x1009D4u: goto label_1009d4;
            case 0x1009ECu: goto label_1009ec;
            case 0x100A04u: goto label_100a04;
            case 0x100A50u: goto label_100a50;
            case 0x100A64u: goto label_100a64;
            case 0x100B00u: goto label_100b00;
            case 0x100B1Cu: goto label_100b1c;
            case 0x100B60u: goto label_100b60;
            default: break;
        }
        return;
    }
    ctx->pc = 0x100B4Cu;
    // 0x100b4c: 0x0
    ctx->pc = 0x100b4cu;
    // NOP
    // 0x100b50: 0x27bdfff0
    ctx->pc = 0x100b50u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x100b54: 0xffbf0000
    ctx->pc = 0x100b54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x100b58: 0xc04020e
    ctx->pc = 0x100B58u;
    SET_GPR_U32(ctx, 31, 0x100B60u);
    ctx->pc = 0x100B5Cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x100838u;
    goto label_100838;
    ctx->pc = 0x100B60u;
label_100b60:
    // 0x100b60: 0xdfbf0000
    ctx->pc = 0x100b60u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x100b64: 0x3e00008
    ctx->pc = 0x100B64u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x100B68u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x100838u: goto label_100838;
            case 0x1008E8u: goto label_1008e8;
            case 0x1008F0u: goto label_1008f0;
            case 0x10090Cu: goto label_10090c;
            case 0x100910u: goto label_100910;
            case 0x100948u: goto label_100948;
            case 0x100950u: goto label_100950;
            case 0x100974u: goto label_100974;
            case 0x100984u: goto label_100984;
            case 0x100990u: goto label_100990;
            case 0x1009B0u: goto label_1009b0;
            case 0x1009D4u: goto label_1009d4;
            case 0x1009ECu: goto label_1009ec;
            case 0x100A04u: goto label_100a04;
            case 0x100A50u: goto label_100a50;
            case 0x100A64u: goto label_100a64;
            case 0x100B00u: goto label_100b00;
            case 0x100B1Cu: goto label_100b1c;
            case 0x100B60u: goto label_100b60;
            default: break;
        }
        return;
    }
    ctx->pc = 0x100B6Cu;
    // 0x100b6c: 0x0
    ctx->pc = 0x100b6cu;
    // NOP
}
