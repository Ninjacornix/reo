#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001457B8
// Address: 0x1457b8 - 0x1458d8
void sub_001457B8_0x1457b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1457b8u;

    // 0x1457b8: 0x27bdffc0
    ctx->pc = 0x1457b8u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1457bc: 0xffb10010
    ctx->pc = 0x1457bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x1457c0: 0xffb00000
    ctx->pc = 0x1457c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1457c4: 0xffbf0030
    ctx->pc = 0x1457c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1457c8: 0x80802d
    ctx->pc = 0x1457c8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1457cc: 0xffb20020
    ctx->pc = 0x1457ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x1457d0: 0x8e020830
    ctx->pc = 0x1457d0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 2096)));
    // 0x1457d4: 0x14400005
    ctx->pc = 0x1457D4u;
    {
        const bool branch_taken_0x1457d4 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1457D8u;
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1457d4) {
            ctx->pc = 0x1457ECu;
            goto label_1457ec;
        }
    }
    ctx->pc = 0x1457DCu;
    // 0x1457dc: 0x8e020854
    ctx->pc = 0x1457dcu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 2132)));
    // 0x1457e0: 0x51102a
    ctx->pc = 0x1457e0u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 2), GPR_S32(ctx, 17)));
    // 0x1457e4: 0x50400033
    ctx->pc = 0x1457E4u;
    {
        const bool branch_taken_0x1457e4 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x1457e4) {
            ctx->pc = 0x1457E8u;
            SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 2128)));
            ctx->pc = 0x1458B4u;
            goto label_1458b4;
        }
    }
    ctx->pc = 0x1457ECu;
label_1457ec:
    // 0x1457ec: 0x3c021000
    ctx->pc = 0x1457ecu;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x1457f0: 0x3c048000
    ctx->pc = 0x1457f0u;
    SET_GPR_U32(ctx, 4, ((uint32_t)32768 << 16));
    // 0x1457f4: 0x34422010
    ctx->pc = 0x1457f4u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 8208));
    // 0x1457f8: 0x34844000
    ctx->pc = 0x1457f8u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 16384));
    // 0x1457fc: 0x8c430000
    ctx->pc = 0x1457fcu;
    SET_GPR_U32(ctx, 3, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x145800: 0x3c028000
    ctx->pc = 0x145800u;
    SET_GPR_U32(ctx, 2, ((uint32_t)32768 << 16));
    // 0x145804: 0x641824
    ctx->pc = 0x145804u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x145808: 0x1462001a
    ctx->pc = 0x145808u;
    {
        const bool branch_taken_0x145808 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 2));
        ctx->pc = 0x14580Cu;
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x145808) {
            ctx->pc = 0x145874u;
            goto label_145874;
        }
    }
    ctx->pc = 0x145810u;
    // 0x145810: 0x8e0210a0
    ctx->pc = 0x145810u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 4256)));
    // 0x145814: 0x14400018
    ctx->pc = 0x145814u;
    {
        const bool branch_taken_0x145814 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x145818u;
        SET_GPR_U32(ctx, 18, ((uint32_t)35 << 16));
        if (branch_taken_0x145814) {
            ctx->pc = 0x145878u;
            goto label_145878;
        }
    }
    ctx->pc = 0x14581Cu;
    // 0x14581c: 0x0
    ctx->pc = 0x14581cu;
    // NOP
label_145820:
    // 0x145820: 0xc0102d
    ctx->pc = 0x145820u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145824: 0x28421389
    ctx->pc = 0x145824u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 2), 5001));
    // 0x145828: 0x14400004
    ctx->pc = 0x145828u;
    {
        const bool branch_taken_0x145828 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x14582Cu;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 1));
        if (branch_taken_0x145828) {
            ctx->pc = 0x14583Cu;
            goto label_14583c;
        }
    }
    ctx->pc = 0x145830u;
    // 0x145830: 0xc051ff8
    ctx->pc = 0x145830u;
    SET_GPR_U32(ctx, 31, 0x145838u);
    ctx->pc = 0x145834u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 2160)));
    ctx->pc = 0x147FE0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00147FE0_0x147fe0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145838u; }
    }
    if (ctx->pc != 0x145838u) { return; }
    ctx->pc = 0x145838u;
    // 0x145838: 0x302d
    ctx->pc = 0x145838u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_14583c:
    // 0x14583c: 0x3c031000
    ctx->pc = 0x14583cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x145840: 0x3c048000
    ctx->pc = 0x145840u;
    SET_GPR_U32(ctx, 4, ((uint32_t)32768 << 16));
    // 0x145844: 0x34632010
    ctx->pc = 0x145844u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 8208));
    // 0x145848: 0x34844000
    ctx->pc = 0x145848u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 16384));
    // 0x14584c: 0x8c620000
    ctx->pc = 0x14584cu;
    SET_GPR_U32(ctx, 2, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x145850: 0x3c058000
    ctx->pc = 0x145850u;
    SET_GPR_U32(ctx, 5, ((uint32_t)32768 << 16));
    // 0x145854: 0x441024
    ctx->pc = 0x145854u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x145858: 0x14450008
    ctx->pc = 0x145858u;
    {
        const bool branch_taken_0x145858 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 5));
        ctx->pc = 0x14585Cu;
        SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
        if (branch_taken_0x145858) {
            ctx->pc = 0x14587Cu;
            goto label_14587c;
        }
    }
    ctx->pc = 0x145860u;
    // 0x145860: 0x8e0210a0
    ctx->pc = 0x145860u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 4256)));
    // 0x145864: 0x1040ffee
    ctx->pc = 0x145864u;
    {
        const bool branch_taken_0x145864 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x145868u;
        SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
        if (branch_taken_0x145864) {
            ctx->pc = 0x145820u;
            goto label_145820;
        }
    }
    ctx->pc = 0x14586Cu;
    // 0x14586c: 0x10000004
    ctx->pc = 0x14586Cu;
    {
        const bool branch_taken_0x14586c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x145870u;
        SET_GPR_U32(ctx, 3, ((uint32_t)16384 << 16));
        if (branch_taken_0x14586c) {
            ctx->pc = 0x145880u;
            goto label_145880;
        }
    }
    ctx->pc = 0x145874u;
label_145874:
    // 0x145874: 0x3c120023
    ctx->pc = 0x145874u;
    SET_GPR_U32(ctx, 18, ((uint32_t)35 << 16));
label_145878:
    // 0x145878: 0x3c021000
    ctx->pc = 0x145878u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
label_14587c:
    // 0x14587c: 0x3c034000
    ctx->pc = 0x14587cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)16384 << 16));
label_145880:
    // 0x145880: 0x34422000
    ctx->pc = 0x145880u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 8192));
    // 0x145884: 0x2645a6f8
    ctx->pc = 0x145884u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 18), 4294944504));
    // 0x145888: 0xac430000
    ctx->pc = 0x145888u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x14588c: 0x200202d
    ctx->pc = 0x14588cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145890: 0x8ca20010
    ctx->pc = 0x145890u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 5), 16)));
    // 0x145894: 0xc0514f0
    ctx->pc = 0x145894u;
    SET_GPR_U32(ctx, 31, 0x14589Cu);
    ctx->pc = 0x145898u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 2096), GPR_U32(ctx, 2));
    ctx->pc = 0x1453C0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001453C0_0x1453c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14589Cu; }
    }
    if (ctx->pc != 0x14589Cu) { return; }
    ctx->pc = 0x14589Cu;
    // 0x14589c: 0x2103c
    ctx->pc = 0x14589cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1458a0: 0x2103f
    ctx->pc = 0x1458a0u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x1458a4: 0x24030020
    ctx->pc = 0x1458a4u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 32));
    // 0x1458a8: 0xae020850
    ctx->pc = 0x1458a8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 2128), GPR_U32(ctx, 2));
    // 0x1458ac: 0xae030854
    ctx->pc = 0x1458acu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 2132), GPR_U32(ctx, 3));
    // 0x1458b0: 0x8e030850
    ctx->pc = 0x1458b0u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 2128)));
label_1458b4:
    // 0x1458b4: 0x111023
    ctx->pc = 0x1458b4u;
    SET_GPR_U32(ctx, 2, SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 17)));
    // 0x1458b8: 0xdfbf0030
    ctx->pc = 0x1458b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1458bc: 0xdfb20020
    ctx->pc = 0x1458bcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1458c0: 0x431006
    ctx->pc = 0x1458c0u;
    SET_GPR_U32(ctx, 2, SRL32(GPR_U32(ctx, 3), GPR_U32(ctx, 2) & 0x1F));
    // 0x1458c4: 0xdfb10010
    ctx->pc = 0x1458c4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1458c8: 0xdfb00000
    ctx->pc = 0x1458c8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1458cc: 0x3e00008
    ctx->pc = 0x1458CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1458D0u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1457ECu: goto label_1457ec;
            case 0x145820u: goto label_145820;
            case 0x14583Cu: goto label_14583c;
            case 0x145874u: goto label_145874;
            case 0x145878u: goto label_145878;
            case 0x14587Cu: goto label_14587c;
            case 0x145880u: goto label_145880;
            case 0x1458B4u: goto label_1458b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1458D4u;
    // 0x1458d4: 0x0
    ctx->pc = 0x1458d4u;
    // NOP
}
