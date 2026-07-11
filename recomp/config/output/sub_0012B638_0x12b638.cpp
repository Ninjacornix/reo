#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0012B638
// Address: 0x12b638 - 0x12b7b0
void sub_0012B638_0x12b638(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x12b638u;

    // 0x12b638: 0x27bdffb0
    ctx->pc = 0x12b638u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x12b63c: 0x3c020021
    ctx->pc = 0x12b63cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x12b640: 0xffb20040
    ctx->pc = 0x12b640u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x12b644: 0x3c120021
    ctx->pc = 0x12b644u;
    SET_GPR_U32(ctx, 18, ((uint32_t)33 << 16));
    // 0x12b648: 0xffb00030
    ctx->pc = 0x12b648u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x12b64c: 0x80802d
    ctx->pc = 0x12b64cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12b650: 0xffb10038
    ctx->pc = 0x12b650u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 17));
    // 0x12b654: 0x3c030021
    ctx->pc = 0x12b654u;
    SET_GPR_U32(ctx, 3, ((uint32_t)33 << 16));
    // 0x12b658: 0xffbf0048
    ctx->pc = 0x12b658u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x12b65c: 0x24420450
    ctx->pc = 0x12b65cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1104));
    // 0x12b660: 0x8e450454
    ctx->pc = 0x12b660u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 18), 1108)));
    // 0x12b664: 0x2463049c
    ctx->pc = 0x12b664u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 1180));
    // 0x12b668: 0x8c460000
    ctx->pc = 0x12b668u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x12b66c: 0xac600000
    ctx->pc = 0x12b66cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0));
    // 0x12b670: 0x54a00045
    ctx->pc = 0x12B670u;
    {
        const bool branch_taken_0x12b670 = (GPR_U32(ctx, 5) != GPR_U32(ctx, 0));
        if (branch_taken_0x12b670) {
            ctx->pc = 0x12B674u;
            SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 18), 1108));
            ctx->pc = 0x12B788u;
            goto label_12b788;
        }
    }
    ctx->pc = 0x12B678u;
    // 0x12b678: 0xc05083e
    ctx->pc = 0x12B678u;
    SET_GPR_U32(ctx, 31, 0x12B680u);
    ctx->pc = 0x1420F8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001420F8_0x1420f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B680u; }
    }
    if (ctx->pc != 0x12B680u) { return; }
    ctx->pc = 0x12B680u;
    // 0x12b680: 0x3c040013
    ctx->pc = 0x12b680u;
    SET_GPR_U32(ctx, 4, ((uint32_t)19 << 16));
    // 0x12b684: 0x282d
    ctx->pc = 0x12b684u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12b688: 0xc05077c
    ctx->pc = 0x12B688u;
    SET_GPR_U32(ctx, 31, 0x12B690u);
    ctx->pc = 0x12B68Cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294945128));
    ctx->pc = 0x141DF0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00141DF0_0x141df0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B690u; }
    }
    if (ctx->pc != 0x12B690u) { return; }
    ctx->pc = 0x12B690u;
    // 0x12b690: 0x3c040013
    ctx->pc = 0x12b690u;
    SET_GPR_U32(ctx, 4, ((uint32_t)19 << 16));
    // 0x12b694: 0x2484a9f0
    ctx->pc = 0x12b694u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294945264));
    // 0x12b698: 0xc050782
    ctx->pc = 0x12B698u;
    SET_GPR_U32(ctx, 31, 0x12B6A0u);
    ctx->pc = 0x12B69Cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x141E08u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00141E08_0x141e08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B6A0u; }
    }
    if (ctx->pc != 0x12B6A0u) { return; }
    ctx->pc = 0x12B6A0u;
    // 0x12b6a0: 0x56000011
    ctx->pc = 0x12B6A0u;
    {
        const bool branch_taken_0x12b6a0 = (GPR_U32(ctx, 16) != GPR_U32(ctx, 0));
        if (branch_taken_0x12b6a0) {
            ctx->pc = 0x12B6A4u;
            SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 16)));
            ctx->pc = 0x12B6E8u;
            goto label_12b6e8;
        }
    }
    ctx->pc = 0x12B6A8u;
    // 0x12b6a8: 0x3c110021
    ctx->pc = 0x12b6a8u;
    SET_GPR_U32(ctx, 17, ((uint32_t)33 << 16));
    // 0x12b6ac: 0x24020018
    ctx->pc = 0x12b6acu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 24));
    // 0x12b6b0: 0x26240460
    ctx->pc = 0x12b6b0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 17), 1120));
    // 0x12b6b4: 0x24030019
    ctx->pc = 0x12b6b4u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 25));
    // 0x12b6b8: 0xac820014
    ctx->pc = 0x12b6b8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 2));
    // 0x12b6bc: 0x24020001
    ctx->pc = 0x12b6bcu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x12b6c0: 0xac830018
    ctx->pc = 0x12b6c0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 3));
    // 0x12b6c4: 0x24030008
    ctx->pc = 0x12b6c4u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 8));
    // 0x12b6c8: 0xac820000
    ctx->pc = 0x12b6c8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x12b6cc: 0x24020010
    ctx->pc = 0x12b6ccu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 16));
    // 0x12b6d0: 0xac830004
    ctx->pc = 0x12b6d0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 3));
    // 0x12b6d4: 0x24030012
    ctx->pc = 0x12b6d4u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 18));
    // 0x12b6d8: 0xac82000c
    ctx->pc = 0x12b6d8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 2));
    // 0x12b6dc: 0x1000000f
    ctx->pc = 0x12B6DCu;
    {
        const bool branch_taken_0x12b6dc = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x12B6E0u;
        WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 3));
        if (branch_taken_0x12b6dc) {
            ctx->pc = 0x12B71Cu;
            goto label_12b71c;
        }
    }
    ctx->pc = 0x12B6E4u;
    // 0x12b6e4: 0x0
    ctx->pc = 0x12b6e4u;
    // NOP
label_12b6e8:
    // 0x12b6e8: 0x3c110021
    ctx->pc = 0x12b6e8u;
    SET_GPR_U32(ctx, 17, ((uint32_t)33 << 16));
    // 0x12b6ec: 0x26240460
    ctx->pc = 0x12b6ecu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 17), 1120));
    // 0x12b6f0: 0xac830014
    ctx->pc = 0x12b6f0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 3));
    // 0x12b6f4: 0x8e020000
    ctx->pc = 0x12b6f4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12b6f8: 0xac820000
    ctx->pc = 0x12b6f8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x12b6fc: 0x8e030004
    ctx->pc = 0x12b6fcu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x12b700: 0xac830004
    ctx->pc = 0x12b700u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 3));
    // 0x12b704: 0x8e020008
    ctx->pc = 0x12b704u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x12b708: 0xac82000c
    ctx->pc = 0x12b708u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 2));
    // 0x12b70c: 0x8e03000c
    ctx->pc = 0x12b70cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x12b710: 0xac830010
    ctx->pc = 0x12b710u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 3));
    // 0x12b714: 0x8e020014
    ctx->pc = 0x12b714u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x12b718: 0xac820018
    ctx->pc = 0x12b718u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 2));
label_12b71c:
    // 0x12b71c: 0xc045144
    ctx->pc = 0x12B71Cu;
    SET_GPR_U32(ctx, 31, 0x12B724u);
    ctx->pc = 0x12B720u;
    SET_GPR_U32(ctx, 16, ((uint32_t)33 << 16));
    ctx->pc = 0x114510u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114510_0x114510(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B724u; }
    }
    if (ctx->pc != 0x12B724u) { return; }
    ctx->pc = 0x12B724u;
    // 0x12b724: 0x261004e8
    ctx->pc = 0x12b724u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 1256));
    // 0x12b728: 0x3a0282d
    ctx->pc = 0x12b728u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12b72c: 0x0
    ctx->pc = 0x12b72cu;
    // NOP
    // 0x12b730: 0xc045148
    ctx->pc = 0x12B730u;
    SET_GPR_U32(ctx, 31, 0x12B738u);
    ctx->pc = 0x12B734u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 0)));
    ctx->pc = 0x114520u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114520_0x114520(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B738u; }
    }
    if (ctx->pc != 0x12B738u) { return; }
    ctx->pc = 0x12B738u;
    // 0x12b738: 0x3c030021
    ctx->pc = 0x12b738u;
    SET_GPR_U32(ctx, 3, ((uint32_t)33 << 16));
    // 0x12b73c: 0x8fa20018
    ctx->pc = 0x12b73cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12b740: 0xc04ac6e
    ctx->pc = 0x12B740u;
    SET_GPR_U32(ctx, 31, 0x12B748u);
    ctx->pc = 0x12B1B8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B1B8_0x12b1b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B748u; }
    }
    if (ctx->pc != 0x12B748u) { return; }
    ctx->pc = 0x12B748u;
    // 0x12b748: 0xc04acba
    ctx->pc = 0x12B748u;
    SET_GPR_U32(ctx, 31, 0x12B750u);
    ctx->pc = 0x12B2E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B2E8_0x12b2e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B750u; }
    }
    if (ctx->pc != 0x12B750u) { return; }
    ctx->pc = 0x12B750u;
    // 0x12b750: 0xc04acdc
    ctx->pc = 0x12B750u;
    SET_GPR_U32(ctx, 31, 0x12B758u);
    ctx->pc = 0x12B370u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B370_0x12b370(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B758u; }
    }
    if (ctx->pc != 0x12B758u) { return; }
    ctx->pc = 0x12B758u;
    // 0x12b758: 0xc04acfe
    ctx->pc = 0x12B758u;
    SET_GPR_U32(ctx, 31, 0x12B760u);
    ctx->pc = 0x12B3F8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B3F8_0x12b3f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B760u; }
    }
    if (ctx->pc != 0x12B760u) { return; }
    ctx->pc = 0x12B760u;
    // 0x12b760: 0x8e040000
    ctx->pc = 0x12b760u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12b764: 0x26220460
    ctx->pc = 0x12b764u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 17), 1120));
    // 0x12b768: 0xc04512c
    ctx->pc = 0x12B768u;
    SET_GPR_U32(ctx, 31, 0x12B770u);
    ctx->pc = 0x12B76Cu;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 2), 20)));
    ctx->pc = 0x1144B0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001144B0_0x1144b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B770u; }
    }
    if (ctx->pc != 0x12B770u) { return; }
    ctx->pc = 0x12B770u;
    // 0x12b770: 0x3c050013
    ctx->pc = 0x12b770u;
    SET_GPR_U32(ctx, 5, ((uint32_t)19 << 16));
    // 0x12b774: 0x24a5ab38
    ctx->pc = 0x12b774u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294945592));
    // 0x12b778: 0x24040006
    ctx->pc = 0x12b778u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 6));
    // 0x12b77c: 0xc050746
    ctx->pc = 0x12B77Cu;
    SET_GPR_U32(ctx, 31, 0x12B784u);
    ctx->pc = 0x12B780u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x141D18u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00141D18_0x141d18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B784u; }
    }
    if (ctx->pc != 0x12B784u) { return; }
    ctx->pc = 0x12B784u;
    // 0x12b784: 0x26430454
    ctx->pc = 0x12b784u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 18), 1108));
label_12b788:
    // 0x12b788: 0xdfb20040
    ctx->pc = 0x12b788u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x12b78c: 0x8c620000
    ctx->pc = 0x12b78cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12b790: 0xdfb00030
    ctx->pc = 0x12b790u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x12b794: 0xdfb10038
    ctx->pc = 0x12b794u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x12b798: 0x24420001
    ctx->pc = 0x12b798u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
    // 0x12b79c: 0xdfbf0048
    ctx->pc = 0x12b79cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x12b7a0: 0xac620000
    ctx->pc = 0x12b7a0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x12b7a4: 0x3e00008
    ctx->pc = 0x12B7A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12B7A8u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 80));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12B6E8u: goto label_12b6e8;
            case 0x12B71Cu: goto label_12b71c;
            case 0x12B788u: goto label_12b788;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12B7ACu;
    // 0x12b7ac: 0x0
    ctx->pc = 0x12b7acu;
    // NOP
}
