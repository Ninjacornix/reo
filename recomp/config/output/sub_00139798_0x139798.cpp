#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00139798
// Address: 0x139798 - 0x139828
void sub_00139798_0x139798(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x139798u;

    // 0x139798: 0x27bdffd0
    ctx->pc = 0x139798u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x13979c: 0xffb30018
    ctx->pc = 0x13979cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x1397a0: 0x3c130022
    ctx->pc = 0x1397a0u;
    SET_GPR_U32(ctx, 19, ((uint32_t)34 << 16));
    // 0x1397a4: 0xffb00000
    ctx->pc = 0x1397a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1397a8: 0xffb10008
    ctx->pc = 0x1397a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1397ac: 0xffb20010
    ctx->pc = 0x1397acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1397b0: 0xffbf0020
    ctx->pc = 0x1397b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1397b4: 0xc050864
    ctx->pc = 0x1397B4u;
    SET_GPR_U32(ctx, 31, 0x1397BCu);
    ctx->pc = 0x1397B8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 19), 4294953968));
    ctx->pc = 0x142190u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00142190_0x142190(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1397BCu; }
    }
    if (ctx->pc != 0x1397BCu) { return; }
    ctx->pc = 0x1397BCu;
    // 0x1397bc: 0x1040000d
    ctx->pc = 0x1397BCu;
    {
        const bool branch_taken_0x1397bc = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1397C0u;
        SET_GPR_U32(ctx, 2, ((uint32_t)34 << 16));
        if (branch_taken_0x1397bc) {
            ctx->pc = 0x1397F4u;
            goto label_1397f4;
        }
    }
    ctx->pc = 0x1397C4u;
    // 0x1397c4: 0x24120001
    ctx->pc = 0x1397c4u;
    SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1397c8: 0x2450cc60
    ctx->pc = 0x1397c8u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 2), 4294954080));
    // 0x1397cc: 0x24110027
    ctx->pc = 0x1397ccu;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 0), 39));
label_1397d0:
    // 0x1397d0: 0x82020000
    ctx->pc = 0x1397d0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1397d4: 0x54520004
    ctx->pc = 0x1397D4u;
    {
        const bool branch_taken_0x1397d4 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 18));
        if (branch_taken_0x1397d4) {
            ctx->pc = 0x1397D8u;
            SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 17), 4294967295));
            ctx->pc = 0x1397E8u;
            goto label_1397e8;
        }
    }
    ctx->pc = 0x1397DCu;
    // 0x1397dc: 0xc04e5b4
    ctx->pc = 0x1397DCu;
    SET_GPR_U32(ctx, 31, 0x1397E4u);
    ctx->pc = 0x1397E0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1396D0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001396D0_0x1396d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1397E4u; }
    }
    if (ctx->pc != 0x1397E4u) { return; }
    ctx->pc = 0x1397E4u;
    // 0x1397e4: 0x2631ffff
    ctx->pc = 0x1397e4u;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 17), 4294967295));
label_1397e8:
    // 0x1397e8: 0x621fff9
    ctx->pc = 0x1397E8u;
    {
        const bool branch_taken_0x1397e8 = (GPR_S32(ctx, 17) >= 0);
        ctx->pc = 0x1397ECu;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 72));
        if (branch_taken_0x1397e8) {
            ctx->pc = 0x1397D0u;
            goto label_1397d0;
        }
    }
    ctx->pc = 0x1397F0u;
    // 0x1397f0: 0xae60cbf0
    ctx->pc = 0x1397f0u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4294953968), GPR_U32(ctx, 0));
label_1397f4:
    // 0x1397f4: 0xdfb00000
    ctx->pc = 0x1397f4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1397f8: 0xdfb10008
    ctx->pc = 0x1397f8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1397fc: 0xdfb20010
    ctx->pc = 0x1397fcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x139800: 0xdfb30018
    ctx->pc = 0x139800u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x139804: 0xdfbf0020
    ctx->pc = 0x139804u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x139808: 0x3e00008
    ctx->pc = 0x139808u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13980Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1397D0u: goto label_1397d0;
            case 0x1397E8u: goto label_1397e8;
            case 0x1397F4u: goto label_1397f4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x139810u;
    // 0x139810: 0x3c020022
    ctx->pc = 0x139810u;
    SET_GPR_U32(ctx, 2, ((uint32_t)34 << 16));
    // 0x139814: 0x3c030022
    ctx->pc = 0x139814u;
    SET_GPR_U32(ctx, 3, ((uint32_t)34 << 16));
    // 0x139818: 0xac44cbe4
    ctx->pc = 0x139818u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294953956), GPR_U32(ctx, 4));
    // 0x13981c: 0x3e00008
    ctx->pc = 0x13981Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x139820u;
        WRITE32(ADD32(GPR_U32(ctx, 3), 4294953960), GPR_U32(ctx, 5));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1397D0u: goto label_1397d0;
            case 0x1397E8u: goto label_1397e8;
            case 0x1397F4u: goto label_1397f4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x139824u;
    // 0x139824: 0x0
    ctx->pc = 0x139824u;
    // NOP
}
