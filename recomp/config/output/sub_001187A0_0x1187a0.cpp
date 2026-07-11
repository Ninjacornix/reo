#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001187A0
// Address: 0x1187a0 - 0x1189a8
void sub_001187A0_0x1187a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1187a0u;

    // 0x1187a0: 0x27bdff80
    ctx->pc = 0x1187a0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x1187a4: 0x202d
    ctx->pc = 0x1187a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1187a8: 0xffb00020
    ctx->pc = 0x1187a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x1187ac: 0x3c100026
    ctx->pc = 0x1187acu;
    SET_GPR_U32(ctx, 16, ((uint32_t)38 << 16));
    // 0x1187b0: 0xffb10030
    ctx->pc = 0x1187b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 17));
    // 0x1187b4: 0xffbf0070
    ctx->pc = 0x1187b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
    // 0x1187b8: 0x2611e1c0
    ctx->pc = 0x1187b8u;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 16), 4294959552));
    // 0x1187bc: 0xffb40060
    ctx->pc = 0x1187bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 20));
    // 0x1187c0: 0xffb30050
    ctx->pc = 0x1187c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 19));
    // 0x1187c4: 0xc045c20
    ctx->pc = 0x1187C4u;
    SET_GPR_U32(ctx, 31, 0x1187CCu);
    ctx->pc = 0x1187C8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    ctx->pc = 0x117080u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00117080_0x117080(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1187CCu; }
    }
    if (ctx->pc != 0x1187CCu) { return; }
    ctx->pc = 0x1187CCu;
    // 0x1187cc: 0xae00e1c0
    ctx->pc = 0x1187ccu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4294959552), GPR_U32(ctx, 0));
    // 0x1187d0: 0xc047598
    ctx->pc = 0x1187D0u;
    SET_GPR_U32(ctx, 31, 0x1187D8u);
    ctx->pc = 0x1187D4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
    ctx->pc = 0x11D660u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1187D8u; }
    }
    if (ctx->pc != 0x1187D8u) { return; }
    ctx->pc = 0x1187D8u;
    // 0x1187d8: 0x3c050012
    ctx->pc = 0x1187d8u;
    SET_GPR_U32(ctx, 5, ((uint32_t)18 << 16));
    // 0x1187dc: 0x3c060026
    ctx->pc = 0x1187dcu;
    SET_GPR_U32(ctx, 6, ((uint32_t)38 << 16));
    // 0x1187e0: 0x3c048000
    ctx->pc = 0x1187e0u;
    SET_GPR_U32(ctx, 4, ((uint32_t)32768 << 16));
    // 0x1187e4: 0x40802d
    ctx->pc = 0x1187e4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1187e8: 0x24a58268
    ctx->pc = 0x1187e8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294935144));
    // 0x1187ec: 0x24c6e180
    ctx->pc = 0x1187ecu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 4294959488));
    // 0x1187f0: 0xc045b02
    ctx->pc = 0x1187F0u;
    SET_GPR_U32(ctx, 31, 0x1187F8u);
    ctx->pc = 0x1187F4u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 17));
    ctx->pc = 0x116C08u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116C08_0x116c08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1187F8u; }
    }
    if (ctx->pc != 0x1187F8u) { return; }
    ctx->pc = 0x1187F8u;
    // 0x1187f8: 0x3c050012
    ctx->pc = 0x1187f8u;
    SET_GPR_U32(ctx, 5, ((uint32_t)18 << 16));
    // 0x1187fc: 0x3c048000
    ctx->pc = 0x1187fcu;
    SET_GPR_U32(ctx, 4, ((uint32_t)32768 << 16));
    // 0x118800: 0x24a58758
    ctx->pc = 0x118800u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294936408));
    // 0x118804: 0x220302d
    ctx->pc = 0x118804u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x118808: 0xc045b02
    ctx->pc = 0x118808u;
    SET_GPR_U32(ctx, 31, 0x118810u);
    ctx->pc = 0x11880Cu;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 19));
    ctx->pc = 0x116C08u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116C08_0x116c08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118810u; }
    }
    if (ctx->pc != 0x118810u) { return; }
    ctx->pc = 0x118810u;
    // 0x118810: 0x1200000e
    ctx->pc = 0x118810u;
    {
        const bool branch_taken_0x118810 = (GPR_U32(ctx, 16) == GPR_U32(ctx, 0));
        ctx->pc = 0x118814u;
        SET_GPR_U32(ctx, 19, ((uint32_t)38 << 16));
        if (branch_taken_0x118810) {
            ctx->pc = 0x11884Cu;
            goto label_11884c;
        }
    }
    ctx->pc = 0x118818u;
    // 0x118818: 0xc0475ae
    ctx->pc = 0x118818u;
    SET_GPR_U32(ctx, 31, 0x118820u);
    ctx->pc = 0x11881Cu;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 19), 4294959424));
    ctx->pc = 0x11D6B8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118820u; }
    }
    if (ctx->pc != 0x118820u) { return; }
    ctx->pc = 0x118820u;
    // 0x118820: 0x1000000b
    ctx->pc = 0x118820u;
    {
        const bool branch_taken_0x118820 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x118820) {
            ctx->pc = 0x118850u;
            goto label_118850;
        }
    }
    ctx->pc = 0x118828u;
label_118828:
    // 0x118828: 0x2403ffff
    ctx->pc = 0x118828u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x11882c: 0x0
    ctx->pc = 0x11882cu;
    // NOP
label_118830:
    // 0x118830: 0x2442ffff
    ctx->pc = 0x118830u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x118834: 0x0
    ctx->pc = 0x118834u;
    // NOP
    // 0x118838: 0x0
    ctx->pc = 0x118838u;
    // NOP
    // 0x11883c: 0x0
    ctx->pc = 0x11883cu;
    // NOP
    // 0x118840: 0x0
    ctx->pc = 0x118840u;
    // NOP
    // 0x118844: 0x1443fffa
    ctx->pc = 0x118844u;
    {
        const bool branch_taken_0x118844 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 3));
        if (branch_taken_0x118844) {
            ctx->pc = 0x118830u;
            goto label_118830;
        }
    }
    ctx->pc = 0x11884Cu;
label_11884c:
    // 0x11884c: 0x2670e140
    ctx->pc = 0x11884cu;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 19), 4294959424));
label_118850:
    // 0x118850: 0x3c058000
    ctx->pc = 0x118850u;
    SET_GPR_U32(ctx, 5, ((uint32_t)32768 << 16));
    // 0x118854: 0x200202d
    ctx->pc = 0x118854u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x118858: 0x34a50001
    ctx->pc = 0x118858u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 1));
    // 0x11885c: 0xc045e06
    ctx->pc = 0x11885Cu;
    SET_GPR_U32(ctx, 31, 0x118864u);
    ctx->pc = 0x118860u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x117818u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00117818_0x117818(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118864u; }
    }
    if (ctx->pc != 0x118864u) { return; }
    ctx->pc = 0x118864u;
    // 0x118864: 0x4400047
    ctx->pc = 0x118864u;
    {
        const bool branch_taken_0x118864 = (GPR_S32(ctx, 2) < 0);
        ctx->pc = 0x118868u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x118864) {
            ctx->pc = 0x118984u;
            goto label_118984;
        }
    }
    ctx->pc = 0x11886Cu;
    // 0x11886c: 0x8e020024
    ctx->pc = 0x11886cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x118870: 0x1040ffed
    ctx->pc = 0x118870u;
    {
        const bool branch_taken_0x118870 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x118874u;
        SET_GPR_U32(ctx, 2, ((uint32_t)16 << 16));
        if (branch_taken_0x118870) {
            ctx->pc = 0x118828u;
            goto label_118828;
        }
    }
    ctx->pc = 0x118878u;
    // 0x118878: 0xc046044
    ctx->pc = 0x118878u;
    SET_GPR_U32(ctx, 31, 0x118880u);
    ctx->pc = 0x11887Cu;
    SET_GPR_U32(ctx, 20, ((uint32_t)33 << 16));
    ctx->pc = 0x118110u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00118110_0x118110(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118880u; }
    }
    if (ctx->pc != 0x118880u) { return; }
    ctx->pc = 0x118880u;
    // 0x118880: 0xc045198
    ctx->pc = 0x118880u;
    SET_GPR_U32(ctx, 31, 0x118888u);
    ctx->pc = 0x118884u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 20), 4294942184)));
    ctx->pc = 0x114660u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118888u; }
    }
    if (ctx->pc != 0x118888u) { return; }
    ctx->pc = 0x118888u;
    // 0x118888: 0x3c030026
    ctx->pc = 0x118888u;
    SET_GPR_U32(ctx, 3, ((uint32_t)38 << 16));
    // 0x11888c: 0x2463df40
    ctx->pc = 0x11888cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294958912));
    // 0x118890: 0x24640200
    ctx->pc = 0x118890u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 3), 512));
    // 0x118894: 0x64102b
    ctx->pc = 0x118894u;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x118898: 0x1040000c
    ctx->pc = 0x118898u;
    {
        const bool branch_taken_0x118898 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x11889Cu;
        SET_GPR_U32(ctx, 18, ((uint32_t)38 << 16));
        if (branch_taken_0x118898) {
            ctx->pc = 0x1188CCu;
            goto label_1188cc;
        }
    }
    ctx->pc = 0x1188A0u;
    // 0x1188a0: 0x3c110026
    ctx->pc = 0x1188a0u;
    SET_GPR_U32(ctx, 17, ((uint32_t)38 << 16));
    // 0x1188a4: 0x3c100026
    ctx->pc = 0x1188a4u;
    SET_GPR_U32(ctx, 16, ((uint32_t)38 << 16));
label_1188a8:
    // 0x1188a8: 0xac600004
    ctx->pc = 0x1188a8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 0));
    // 0x1188ac: 0x24630010
    ctx->pc = 0x1188acu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 16));
    // 0x1188b0: 0x64102b
    ctx->pc = 0x1188b0u;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1188b4: 0x0
    ctx->pc = 0x1188b4u;
    // NOP
    // 0x1188b8: 0x0
    ctx->pc = 0x1188b8u;
    // NOP
    // 0x1188bc: 0x1440fffa
    ctx->pc = 0x1188BCu;
    {
        const bool branch_taken_0x1188bc = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x1188bc) {
            ctx->pc = 0x1188A8u;
            goto label_1188a8;
        }
    }
    ctx->pc = 0x1188C4u;
    // 0x1188c4: 0x10000004
    ctx->pc = 0x1188C4u;
    {
        const bool branch_taken_0x1188c4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1188C8u;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 20), 4294942184)));
        if (branch_taken_0x1188c4) {
            ctx->pc = 0x1188D8u;
            goto label_1188d8;
        }
    }
    ctx->pc = 0x1188CCu;
label_1188cc:
    // 0x1188cc: 0x3c110026
    ctx->pc = 0x1188ccu;
    SET_GPR_U32(ctx, 17, ((uint32_t)38 << 16));
    // 0x1188d0: 0x3c100026
    ctx->pc = 0x1188d0u;
    SET_GPR_U32(ctx, 16, ((uint32_t)38 << 16));
    // 0x1188d4: 0x8e849de8
    ctx->pc = 0x1188d4u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 20), 4294942184)));
label_1188d8:
    // 0x1188d8: 0xc045190
    ctx->pc = 0x1188D8u;
    SET_GPR_U32(ctx, 31, 0x1188E0u);
    ctx->pc = 0x1188DCu;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 4294956672));
    ctx->pc = 0x114640u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1188E0u; }
    }
    if (ctx->pc != 0x1188E0u) { return; }
    ctx->pc = 0x1188E0u;
    // 0x1188e0: 0x2623d6c0
    ctx->pc = 0x1188e0u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 17), 4294956736));
    // 0x1188e4: 0x2647ca00
    ctx->pc = 0x1188e4u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 18), 4294953472));
    // 0x1188e8: 0xae43ca00
    ctx->pc = 0x1188e8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4294953472), GPR_U32(ctx, 3));
    // 0x1188ec: 0x2664e140
    ctx->pc = 0x1188ecu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 19), 4294959424));
    // 0x1188f0: 0x24630440
    ctx->pc = 0x1188f0u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 1088));
    // 0x1188f4: 0x240500ff
    ctx->pc = 0x1188f4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 255));
    // 0x1188f8: 0xace30004
    ctx->pc = 0x1188f8u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 4), GPR_U32(ctx, 3));
    // 0x1188fc: 0x302d
    ctx->pc = 0x1188fcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x118900: 0xafa00000
    ctx->pc = 0x118900u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x118904: 0x24080008
    ctx->pc = 0x118904u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 0), 8));
    // 0x118908: 0x200482d
    ctx->pc = 0x118908u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11890c: 0x240a0008
    ctx->pc = 0x11890cu;
    SET_GPR_S32(ctx, 10, ADD32(GPR_U32(ctx, 0), 8));
    // 0x118910: 0xc045e7a
    ctx->pc = 0x118910u;
    SET_GPR_U32(ctx, 31, 0x118918u);
    ctx->pc = 0x118914u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1179E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118918u; }
    }
    if (ctx->pc != 0x118918u) { return; }
    ctx->pc = 0x118918u;
    // 0x118918: 0x4410004
    ctx->pc = 0x118918u;
    {
        const bool branch_taken_0x118918 = (GPR_S32(ctx, 2) >= 0);
        ctx->pc = 0x11891Cu;
        SET_GPR_U32(ctx, 4, ((uint32_t)8192 << 16));
        if (branch_taken_0x118918) {
            ctx->pc = 0x11892Cu;
            goto label_11892c;
        }
    }
    ctx->pc = 0x118920u;
    // 0x118920: 0x3c02fffe
    ctx->pc = 0x118920u;
    SET_GPR_U32(ctx, 2, ((uint32_t)65534 << 16));
    // 0x118924: 0x10000017
    ctx->pc = 0x118924u;
    {
        const bool branch_taken_0x118924 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x118928u;
        SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 65535));
        if (branch_taken_0x118924) {
            ctx->pc = 0x118984u;
            goto label_118984;
        }
    }
    ctx->pc = 0x11892Cu;
label_11892c:
    // 0x11892c: 0x26020004
    ctx->pc = 0x11892cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 16), 4));
    // 0x118930: 0x2041825
    ctx->pc = 0x118930u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 16), GPR_U32(ctx, 4)));
    // 0x118934: 0x441025
    ctx->pc = 0x118934u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x118938: 0x3c050026
    ctx->pc = 0x118938u;
    SET_GPR_U32(ctx, 5, ((uint32_t)38 << 16));
    // 0x11893c: 0x24a8e168
    ctx->pc = 0x11893cu;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 5), 4294959464));
    // 0x118940: 0x88640003
    ctx->pc = 0x118940u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 3); uint32_t shift = (3 - (addr & 3)) << 3; uint32_t mask = 0xFFFFFFFF << shift; uint32_t aligned_word = READ32(addr & ~3); SET_GPR_U32(ctx, 4, (GPR_U32(ctx, 4) & ~mask) | ((aligned_word << shift) & mask)); }
    // 0x118944: 0x98640000
    ctx->pc = 0x118944u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 0); uint32_t shift = (addr & 3) << 3; uint32_t mask = 0xFFFFFFFF >> shift; uint32_t aligned_word = READ32(addr & ~3); SET_GPR_U32(ctx, 4, (GPR_U32(ctx, 4) & ~mask) | ((aligned_word >> shift) & mask)); }
    // 0x118948: 0xa9040003
    ctx->pc = 0x118948u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 3); uint32_t shift = (3 - (addr & 3)) << 3; uint32_t mask = 0xFFFFFFFF >> shift; uint32_t aligned_addr = addr & ~3; uint32_t old_data = READ32(aligned_addr); uint32_t new_data = (old_data & ~mask) | ((GPR_U32(ctx, 4) >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x11894c: 0xb9040000
    ctx->pc = 0x11894cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 0); uint32_t shift = (addr & 3) << 3; uint32_t mask = 0xFFFFFFFF << shift; uint32_t aligned_addr = addr & ~3; uint32_t old_data = READ32(aligned_addr); uint32_t new_data = (old_data & ~mask) | ((GPR_U32(ctx, 4) << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x118950: 0x88430003
    ctx->pc = 0x118950u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 3); uint32_t shift = (3 - (addr & 3)) << 3; uint32_t mask = 0xFFFFFFFF << shift; uint32_t aligned_word = READ32(addr & ~3); SET_GPR_U32(ctx, 3, (GPR_U32(ctx, 3) & ~mask) | ((aligned_word << shift) & mask)); }
    // 0x118954: 0x98430000
    ctx->pc = 0x118954u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 0); uint32_t shift = (addr & 3) << 3; uint32_t mask = 0xFFFFFFFF >> shift; uint32_t aligned_word = READ32(addr & ~3); SET_GPR_U32(ctx, 3, (GPR_U32(ctx, 3) & ~mask) | ((aligned_word >> shift) & mask)); }
    // 0x118958: 0xaba30013
    ctx->pc = 0x118958u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 19); uint32_t shift = (3 - (addr & 3)) << 3; uint32_t mask = 0xFFFFFFFF >> shift; uint32_t aligned_addr = addr & ~3; uint32_t old_data = READ32(aligned_addr); uint32_t new_data = (old_data & ~mask) | ((GPR_U32(ctx, 3) >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x11895c: 0xbba30010
    ctx->pc = 0x11895cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 16); uint32_t shift = (addr & 3) << 3; uint32_t mask = 0xFFFFFFFF << shift; uint32_t aligned_addr = addr & ~3; uint32_t old_data = READ32(aligned_addr); uint32_t new_data = (old_data & ~mask) | ((GPR_U32(ctx, 3) << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x118960: 0x3c060021
    ctx->pc = 0x118960u;
    SET_GPR_U32(ctx, 6, ((uint32_t)33 << 16));
    // 0x118964: 0x3c050021
    ctx->pc = 0x118964u;
    SET_GPR_U32(ctx, 5, ((uint32_t)33 << 16));
    // 0x118968: 0x8fa30010
    ctx->pc = 0x118968u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11896c: 0x24040001
    ctx->pc = 0x11896cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 1));
    // 0x118970: 0xaca49ddc
    ctx->pc = 0x118970u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4294942172), GPR_U32(ctx, 4));
    // 0x118974: 0x102d
    ctx->pc = 0x118974u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x118978: 0x38630002
    ctx->pc = 0x118978u;
    SET_GPR_U32(ctx, 3, XOR32(GPR_U32(ctx, 3), 2));
    // 0x11897c: 0x2c630001
    ctx->pc = 0x11897cu;
    SET_GPR_U32(ctx, 3, SLTU32(GPR_U32(ctx, 3), 1));
    // 0x118980: 0xacc39de0
    ctx->pc = 0x118980u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4294942176), GPR_U32(ctx, 3));
label_118984:
    // 0x118984: 0xdfbf0070
    ctx->pc = 0x118984u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x118988: 0xdfb40060
    ctx->pc = 0x118988u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x11898c: 0xdfb30050
    ctx->pc = 0x11898cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x118990: 0xdfb20040
    ctx->pc = 0x118990u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x118994: 0xdfb10030
    ctx->pc = 0x118994u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x118998: 0xdfb00020
    ctx->pc = 0x118998u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11899c: 0x3e00008
    ctx->pc = 0x11899Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1189A0u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 128));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x118828u: goto label_118828;
            case 0x118830u: goto label_118830;
            case 0x11884Cu: goto label_11884c;
            case 0x118850u: goto label_118850;
            case 0x1188A8u: goto label_1188a8;
            case 0x1188CCu: goto label_1188cc;
            case 0x1188D8u: goto label_1188d8;
            case 0x11892Cu: goto label_11892c;
            case 0x118984u: goto label_118984;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1189A4u;
    // 0x1189a4: 0x0
    ctx->pc = 0x1189a4u;
    // NOP
}
