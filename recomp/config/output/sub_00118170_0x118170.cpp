#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00118170
// Address: 0x118170 - 0x1181f8
void sub_00118170_0x118170(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x118170u;

    // 0x118170: 0x27bdffd0
    ctx->pc = 0x118170u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x118174: 0xffb10010
    ctx->pc = 0x118174u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x118178: 0xffb00000
    ctx->pc = 0x118178u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11817c: 0xffbf0020
    ctx->pc = 0x11817cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x118180: 0xc046044
    ctx->pc = 0x118180u;
    SET_GPR_U32(ctx, 31, 0x118188u);
    ctx->pc = 0x118184u;
    SET_GPR_U32(ctx, 17, ((uint32_t)33 << 16));
    ctx->pc = 0x118110u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00118110_0x118110(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118188u; }
    }
    if (ctx->pc != 0x118188u) { return; }
    ctx->pc = 0x118188u;
    // 0x118188: 0xc045198
    ctx->pc = 0x118188u;
    SET_GPR_U32(ctx, 31, 0x118190u);
    ctx->pc = 0x11818Cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 4294942184)));
    ctx->pc = 0x114660u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118190u; }
    }
    if (ctx->pc != 0x118190u) { return; }
    ctx->pc = 0x118190u;
    // 0x118190: 0x3c030026
    ctx->pc = 0x118190u;
    SET_GPR_U32(ctx, 3, ((uint32_t)38 << 16));
    // 0x118194: 0x2470df40
    ctx->pc = 0x118194u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 3), 4294958912));
    // 0x118198: 0x26030200
    ctx->pc = 0x118198u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 16), 512));
    // 0x11819c: 0x203102b
    ctx->pc = 0x11819cu;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
    // 0x1181a0: 0x1040000d
    ctx->pc = 0x1181A0u;
    {
        const bool branch_taken_0x1181a0 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1181A4u;
        SET_GPR_U32(ctx, 5, ((uint32_t)4096 << 16));
        if (branch_taken_0x1181a0) {
            ctx->pc = 0x1181D8u;
            goto label_1181d8;
        }
    }
    ctx->pc = 0x1181A8u;
    // 0x1181a8: 0x8e020004
    ctx->pc = 0x1181a8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1181ac: 0x0
    ctx->pc = 0x1181acu;
    // NOP
label_1181b0:
    // 0x1181b0: 0x54400006
    ctx->pc = 0x1181B0u;
    {
        const bool branch_taken_0x1181b0 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x1181b0) {
            ctx->pc = 0x1181B4u;
            SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 16));
            ctx->pc = 0x1181CCu;
            goto label_1181cc;
        }
    }
    ctx->pc = 0x1181B8u;
    // 0x1181b8: 0x8e249de8
    ctx->pc = 0x1181b8u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 4294942184)));
    // 0x1181bc: 0xc045190
    ctx->pc = 0x1181BCu;
    SET_GPR_U32(ctx, 31, 0x1181C4u);
    ctx->pc = 0x1181C0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 5));
    ctx->pc = 0x114640u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1181C4u; }
    }
    if (ctx->pc != 0x1181C4u) { return; }
    ctx->pc = 0x1181C4u;
    // 0x1181c4: 0x10000007
    ctx->pc = 0x1181C4u;
    {
        const bool branch_taken_0x1181c4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1181C8u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1181c4) {
            ctx->pc = 0x1181E4u;
            goto label_1181e4;
        }
    }
    ctx->pc = 0x1181CCu;
label_1181cc:
    // 0x1181cc: 0x203102b
    ctx->pc = 0x1181ccu;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
    // 0x1181d0: 0x5440fff7
    ctx->pc = 0x1181D0u;
    {
        const bool branch_taken_0x1181d0 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x1181d0) {
            ctx->pc = 0x1181D4u;
            SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 4)));
            ctx->pc = 0x1181B0u;
            goto label_1181b0;
        }
    }
    ctx->pc = 0x1181D8u;
label_1181d8:
    // 0x1181d8: 0xc045190
    ctx->pc = 0x1181D8u;
    SET_GPR_U32(ctx, 31, 0x1181E0u);
    ctx->pc = 0x1181DCu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 4294942184)));
    ctx->pc = 0x114640u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1181E0u; }
    }
    if (ctx->pc != 0x1181E0u) { return; }
    ctx->pc = 0x1181E0u;
    // 0x1181e0: 0x102d
    ctx->pc = 0x1181e0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1181e4:
    // 0x1181e4: 0xdfbf0020
    ctx->pc = 0x1181e4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1181e8: 0xdfb10010
    ctx->pc = 0x1181e8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1181ec: 0xdfb00000
    ctx->pc = 0x1181ecu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1181f0: 0x3e00008
    ctx->pc = 0x1181F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1181F4u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1181B0u: goto label_1181b0;
            case 0x1181CCu: goto label_1181cc;
            case 0x1181D8u: goto label_1181d8;
            case 0x1181E4u: goto label_1181e4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1181F8u;
}
