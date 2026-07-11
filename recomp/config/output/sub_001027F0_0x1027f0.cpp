#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001027F0
// Address: 0x1027f0 - 0x1028f0
void sub_001027F0_0x1027f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1027f0u;

    // 0x1027f0: 0x3c021000
    ctx->pc = 0x1027f0u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x1027f4: 0x24040001
    ctx->pc = 0x1027f4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1027f8: 0x34423810
    ctx->pc = 0x1027f8u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 14352));
    // 0x1027fc: 0x3c031000
    ctx->pc = 0x1027fcu;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x102800: 0xac440000
    ctx->pc = 0x102800u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4)); // MMIO: 0x10000000
    // 0x102804: 0x34633820
    ctx->pc = 0x102804u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 14368));
    // 0x102808: 0x24020006
    ctx->pc = 0x102808u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 6));
    // 0x10280c: 0x3e00008
    ctx->pc = 0x10280Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x102810u;
        runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10283Cu: goto label_10283c;
            case 0x102844u: goto label_102844;
            case 0x102854u: goto label_102854;
            case 0x102864u: goto label_102864;
            case 0x102870u: goto label_102870;
            case 0x1028B0u: goto label_1028b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102814u;
    // 0x102814: 0x0
    ctx->pc = 0x102814u;
    // NOP
    // 0x102818: 0x27bdffe0
    ctx->pc = 0x102818u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x10281c: 0xffb00000
    ctx->pc = 0x10281cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x102820: 0xffbf0010
    ctx->pc = 0x102820u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x102824: 0xc040a3c
    ctx->pc = 0x102824u;
    SET_GPR_U32(ctx, 31, 0x10282Cu);
    ctx->pc = 0x102828u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1028F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001028F0_0x1028f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10282Cu; }
    }
    if (ctx->pc != 0x10282Cu) { return; }
    ctx->pc = 0x10282Cu;
    // 0x10282c: 0x10400003
    ctx->pc = 0x10282Cu;
    {
        const bool branch_taken_0x10282c = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x102830u;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x10282c) {
            ctx->pc = 0x10283Cu;
            goto label_10283c;
        }
    }
    ctx->pc = 0x102834u;
    // 0x102834: 0x14430003
    ctx->pc = 0x102834u;
    {
        const bool branch_taken_0x102834 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 3));
        if (branch_taken_0x102834) {
            ctx->pc = 0x102844u;
            goto label_102844;
        }
    }
    ctx->pc = 0x10283Cu;
label_10283c:
    // 0x10283c: 0x1000000c
    ctx->pc = 0x10283Cu;
    {
        const bool branch_taken_0x10283c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x102840u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x10283c) {
            ctx->pc = 0x102870u;
            goto label_102870;
        }
    }
    ctx->pc = 0x102844u;
label_102844:
    // 0x102844: 0x16000003
    ctx->pc = 0x102844u;
    {
        const bool branch_taken_0x102844 = (GPR_U32(ctx, 16) != GPR_U32(ctx, 0));
        ctx->pc = 0x102848u;
        SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
        if (branch_taken_0x102844) {
            ctx->pc = 0x102854u;
            goto label_102854;
        }
    }
    ctx->pc = 0x10284Cu;
    // 0x10284c: 0x10000005
    ctx->pc = 0x10284Cu;
    {
        const bool branch_taken_0x10284c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x102850u;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x10284c) {
            ctx->pc = 0x102864u;
            goto label_102864;
        }
    }
    ctx->pc = 0x102854u;
label_102854:
    // 0x102854: 0x16030006
    ctx->pc = 0x102854u;
    {
        const bool branch_taken_0x102854 = (GPR_U32(ctx, 16) != GPR_U32(ctx, 3));
        ctx->pc = 0x102858u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x102854) {
            ctx->pc = 0x102870u;
            goto label_102870;
        }
    }
    ctx->pc = 0x10285Cu;
    // 0x10285c: 0x3c021000
    ctx->pc = 0x10285cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x102860: 0x24030004
    ctx->pc = 0x102860u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 4));
label_102864:
    // 0x102864: 0x34423810
    ctx->pc = 0x102864u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 14352));
    // 0x102868: 0xac430000
    ctx->pc = 0x102868u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x10286c: 0x24020001
    ctx->pc = 0x10286cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
label_102870:
    // 0x102870: 0xdfbf0010
    ctx->pc = 0x102870u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x102874: 0xdfb00000
    ctx->pc = 0x102874u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x102878: 0x3e00008
    ctx->pc = 0x102878u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10287Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10283Cu: goto label_10283c;
            case 0x102844u: goto label_102844;
            case 0x102854u: goto label_102854;
            case 0x102864u: goto label_102864;
            case 0x102870u: goto label_102870;
            case 0x1028B0u: goto label_1028b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102880u;
    // 0x102880: 0x27bdfff0
    ctx->pc = 0x102880u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x102884: 0xffbf0000
    ctx->pc = 0x102884u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x102888: 0xc040a3c
    ctx->pc = 0x102888u;
    SET_GPR_U32(ctx, 31, 0x102890u);
    ctx->pc = 0x1028F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001028F0_0x1028f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102890u; }
    }
    if (ctx->pc != 0x102890u) { return; }
    ctx->pc = 0x102890u;
    // 0x102890: 0x24030001
    ctx->pc = 0x102890u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
    // 0x102894: 0x14430006
    ctx->pc = 0x102894u;
    {
        const bool branch_taken_0x102894 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 3));
        ctx->pc = 0x102898u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x102894) {
            ctx->pc = 0x1028B0u;
            goto label_1028b0;
        }
    }
    ctx->pc = 0x10289Cu;
    // 0x10289c: 0x3c031000
    ctx->pc = 0x10289cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x1028a0: 0x24040008
    ctx->pc = 0x1028a0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 8));
    // 0x1028a4: 0x34633810
    ctx->pc = 0x1028a4u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 14352));
    // 0x1028a8: 0x24020001
    ctx->pc = 0x1028a8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1028ac: 0xac640000
    ctx->pc = 0x1028acu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4)); // MMIO: 0x10000000
label_1028b0:
    // 0x1028b0: 0xdfbf0000
    ctx->pc = 0x1028b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1028b4: 0x3e00008
    ctx->pc = 0x1028B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1028B8u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10283Cu: goto label_10283c;
            case 0x102844u: goto label_102844;
            case 0x102854u: goto label_102854;
            case 0x102864u: goto label_102864;
            case 0x102870u: goto label_102870;
            case 0x1028B0u: goto label_1028b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1028BCu;
    // 0x1028bc: 0x0
    ctx->pc = 0x1028bcu;
    // NOP
    // 0x1028c0: 0x52840
    ctx->pc = 0x1028c0u;
    SET_GPR_U32(ctx, 5, SLL32(GPR_U32(ctx, 5), 1));
    // 0x1028c4: 0x63080
    ctx->pc = 0x1028c4u;
    SET_GPR_U32(ctx, 6, SLL32(GPR_U32(ctx, 6), 2));
    // 0x1028c8: 0x851025
    ctx->pc = 0x1028c8u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x1028cc: 0x3c031000
    ctx->pc = 0x1028ccu;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x1028d0: 0x461025
    ctx->pc = 0x1028d0u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x1028d4: 0x34633820
    ctx->pc = 0x1028d4u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 14368));
    // 0x1028d8: 0x3e00008
    ctx->pc = 0x1028D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1028DCu;
        runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10283Cu: goto label_10283c;
            case 0x102844u: goto label_102844;
            case 0x102854u: goto label_102854;
            case 0x102864u: goto label_102864;
            case 0x102870u: goto label_102870;
            case 0x1028B0u: goto label_1028b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1028E0u;
    // 0x1028e0: 0x3c031000
    ctx->pc = 0x1028e0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x1028e4: 0x34633820
    ctx->pc = 0x1028e4u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 14368));
    // 0x1028e8: 0x3e00008
    ctx->pc = 0x1028E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1028ECu;
        SET_GPR_U32(ctx, 2, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0)));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10283Cu: goto label_10283c;
            case 0x102844u: goto label_102844;
            case 0x102854u: goto label_102854;
            case 0x102864u: goto label_102864;
            case 0x102870u: goto label_102870;
            case 0x1028B0u: goto label_1028b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1028F0u;
}
