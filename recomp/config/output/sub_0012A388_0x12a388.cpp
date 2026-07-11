#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0012A388
// Address: 0x12a388 - 0x12a458
void sub_0012A388_0x12a388(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x12a388u;

    // 0x12a388: 0x27bdfff0
    ctx->pc = 0x12a388u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12a38c: 0x3c030021
    ctx->pc = 0x12a38cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)33 << 16));
    // 0x12a390: 0xffb00000
    ctx->pc = 0x12a390u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12a394: 0x2463f3b0
    ctx->pc = 0x12a394u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294964144));
    // 0x12a398: 0xffbf0008
    ctx->pc = 0x12a398u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x12a39c: 0x8c620000
    ctx->pc = 0x12a39cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12a3a0: 0x2442ffff
    ctx->pc = 0x12a3a0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x12a3a4: 0x14400028
    ctx->pc = 0x12A3A4u;
    {
        const bool branch_taken_0x12a3a4 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x12A3A8u;
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        if (branch_taken_0x12a3a4) {
            ctx->pc = 0x12A448u;
            goto label_12a448;
        }
    }
    ctx->pc = 0x12A3ACu;
    // 0x12a3ac: 0x3c100022
    ctx->pc = 0x12a3acu;
    SET_GPR_U32(ctx, 16, ((uint32_t)34 << 16));
    // 0x12a3b0: 0x2610c41c
    ctx->pc = 0x12a3b0u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 4294951964));
    // 0x12a3b4: 0xc04b192
    ctx->pc = 0x12A3B4u;
    SET_GPR_U32(ctx, 31, 0x12A3BCu);
    ctx->pc = 0x12C648u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C648_0x12c648(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A3BCu; }
    }
    if (ctx->pc != 0x12A3BCu) { return; }
    ctx->pc = 0x12A3BCu;
    // 0x12a3bc: 0xc04a104
    ctx->pc = 0x12A3BCu;
    SET_GPR_U32(ctx, 31, 0x12A3C4u);
    ctx->pc = 0x128410u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00128410_0x128410(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A3C4u; }
    }
    if (ctx->pc != 0x12A3C4u) { return; }
    ctx->pc = 0x12A3C4u;
    // 0x12a3c4: 0xc04c040
    ctx->pc = 0x12A3C4u;
    SET_GPR_U32(ctx, 31, 0x12A3CCu);
    ctx->pc = 0x130100u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00130100_0x130100(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A3CCu; }
    }
    if (ctx->pc != 0x12A3CCu) { return; }
    ctx->pc = 0x12A3CCu;
    // 0x12a3cc: 0xc04f586
    ctx->pc = 0x12A3CCu;
    SET_GPR_U32(ctx, 31, 0x12A3D4u);
    ctx->pc = 0x13D618u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D618_0x13d618(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A3D4u; }
    }
    if (ctx->pc != 0x12A3D4u) { return; }
    ctx->pc = 0x12A3D4u;
    // 0x12a3d4: 0xc049938
    ctx->pc = 0x12A3D4u;
    SET_GPR_U32(ctx, 31, 0x12A3DCu);
    ctx->pc = 0x1264E0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001264E0_0x1264e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A3DCu; }
    }
    if (ctx->pc != 0x12A3DCu) { return; }
    ctx->pc = 0x12A3DCu;
    // 0x12a3dc: 0x24040002
    ctx->pc = 0x12a3dcu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 2));
    // 0x12a3e0: 0xc0506f8
    ctx->pc = 0x12A3E0u;
    SET_GPR_U32(ctx, 31, 0x12A3E8u);
    ctx->pc = 0x12A3E4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x141BE0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00141BE0_0x141be0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A3E8u; }
    }
    if (ctx->pc != 0x12A3E8u) { return; }
    ctx->pc = 0x12A3E8u;
    // 0x12a3e8: 0x3c020021
    ctx->pc = 0x12a3e8u;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x12a3ec: 0x8c45f3c0
    ctx->pc = 0x12a3ecu;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 2), 4294964160)));
    // 0x12a3f0: 0xc0506f8
    ctx->pc = 0x12A3F0u;
    SET_GPR_U32(ctx, 31, 0x12A3F8u);
    ctx->pc = 0x12A3F4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 4));
    ctx->pc = 0x141BE0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00141BE0_0x141be0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A3F8u; }
    }
    if (ctx->pc != 0x12A3F8u) { return; }
    ctx->pc = 0x12A3F8u;
    // 0x12a3f8: 0x3c020021
    ctx->pc = 0x12a3f8u;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x12a3fc: 0x8c45f3b8
    ctx->pc = 0x12a3fcu;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 2), 4294964152)));
    // 0x12a400: 0xc0506f8
    ctx->pc = 0x12A400u;
    SET_GPR_U32(ctx, 31, 0x12A408u);
    ctx->pc = 0x12A404u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 5));
    ctx->pc = 0x141BE0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00141BE0_0x141be0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A408u; }
    }
    if (ctx->pc != 0x12A408u) { return; }
    ctx->pc = 0x12A408u;
    // 0x12a408: 0xc05084e
    ctx->pc = 0x12A408u;
    SET_GPR_U32(ctx, 31, 0x12A410u);
    ctx->pc = 0x142138u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00142138_0x142138(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A410u; }
    }
    if (ctx->pc != 0x12A410u) { return; }
    ctx->pc = 0x12A410u;
    // 0x12a410: 0xc04b25e
    ctx->pc = 0x12A410u;
    SET_GPR_U32(ctx, 31, 0x12A418u);
    ctx->pc = 0x12C978u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C978_0x12c978(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A418u; }
    }
    if (ctx->pc != 0x12A418u) { return; }
    ctx->pc = 0x12A418u;
    // 0x12a418: 0xc04a01c
    ctx->pc = 0x12A418u;
    SET_GPR_U32(ctx, 31, 0x12A420u);
    ctx->pc = 0x128070u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00128070_0x128070(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A420u; }
    }
    if (ctx->pc != 0x12A420u) { return; }
    ctx->pc = 0x12A420u;
    // 0x12a420: 0xc04fcc4
    ctx->pc = 0x12A420u;
    SET_GPR_U32(ctx, 31, 0x12A428u);
    ctx->pc = 0x13F310u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F310_0x13f310(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A428u; }
    }
    if (ctx->pc != 0x12A428u) { return; }
    ctx->pc = 0x12A428u;
    // 0x12a428: 0xc04fe16
    ctx->pc = 0x12A428u;
    SET_GPR_U32(ctx, 31, 0x12A430u);
    ctx->pc = 0x13F858u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F858_0x13f858(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A430u; }
    }
    if (ctx->pc != 0x12A430u) { return; }
    ctx->pc = 0x12A430u;
    // 0x12a430: 0xc05001c
    ctx->pc = 0x12A430u;
    SET_GPR_U32(ctx, 31, 0x12A438u);
    ctx->pc = 0x140070u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00140070_0x140070(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A438u; }
    }
    if (ctx->pc != 0x12A438u) { return; }
    ctx->pc = 0x12A438u;
    // 0x12a438: 0xc04993e
    ctx->pc = 0x12A438u;
    SET_GPR_U32(ctx, 31, 0x12A440u);
    ctx->pc = 0x1264F8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001264F8_0x1264f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A440u; }
    }
    if (ctx->pc != 0x12A440u) { return; }
    ctx->pc = 0x12A440u;
    // 0x12a440: 0x24020001
    ctx->pc = 0x12a440u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x12a444: 0xae020000
    ctx->pc = 0x12a444u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
label_12a448:
    // 0x12a448: 0xdfb00000
    ctx->pc = 0x12a448u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12a44c: 0xdfbf0008
    ctx->pc = 0x12a44cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12a450: 0x3e00008
    ctx->pc = 0x12A450u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12A454u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12A448u: goto label_12a448;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12A458u;
}
