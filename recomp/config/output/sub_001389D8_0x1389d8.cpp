#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001389D8
// Address: 0x1389d8 - 0x138ab8
void sub_001389D8_0x1389d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1389d8u;

    // 0x1389d8: 0x27bdffe0
    ctx->pc = 0x1389d8u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1389dc: 0x3c020022
    ctx->pc = 0x1389dcu;
    SET_GPR_U32(ctx, 2, ((uint32_t)34 << 16));
    // 0x1389e0: 0xffbf0018
    ctx->pc = 0x1389e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1389e4: 0xffb00000
    ctx->pc = 0x1389e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1389e8: 0x2450bc08
    ctx->pc = 0x1389e8u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 2), 4294949896));
    // 0x1389ec: 0xffb10008
    ctx->pc = 0x1389ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1389f0: 0x2411001f
    ctx->pc = 0x1389f0u;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 0), 31));
    // 0x1389f4: 0xffb20010
    ctx->pc = 0x1389f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1389f8: 0x24120001
    ctx->pc = 0x1389f8u;
    SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1389fc: 0x0
    ctx->pc = 0x1389fcu;
    // NOP
label_138a00:
    // 0x138a00: 0x82020000
    ctx->pc = 0x138a00u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x138a04: 0x54520004
    ctx->pc = 0x138A04u;
    {
        const bool branch_taken_0x138a04 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 18));
        if (branch_taken_0x138a04) {
            ctx->pc = 0x138A08u;
            SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 17), 4294967295));
            ctx->pc = 0x138A18u;
            goto label_138a18;
        }
    }
    ctx->pc = 0x138A0Cu;
    // 0x138a0c: 0xc04e194
    ctx->pc = 0x138A0Cu;
    SET_GPR_U32(ctx, 31, 0x138A14u);
    ctx->pc = 0x138A10u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x138650u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00138650_0x138650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138A14u; }
    }
    if (ctx->pc != 0x138A14u) { return; }
    ctx->pc = 0x138A14u;
    // 0x138a14: 0x2631ffff
    ctx->pc = 0x138a14u;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 17), 4294967295));
label_138a18:
    // 0x138a18: 0x621fff9
    ctx->pc = 0x138A18u;
    {
        const bool branch_taken_0x138a18 = (GPR_S32(ctx, 17) >= 0);
        ctx->pc = 0x138A1Cu;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 64));
        if (branch_taken_0x138a18) {
            ctx->pc = 0x138A00u;
            goto label_138a00;
        }
    }
    ctx->pc = 0x138A20u;
    // 0x138a20: 0xdfb00000
    ctx->pc = 0x138a20u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x138a24: 0xdfb10008
    ctx->pc = 0x138a24u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x138a28: 0xdfb20010
    ctx->pc = 0x138a28u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x138a2c: 0xdfbf0018
    ctx->pc = 0x138a2cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x138a30: 0x804e55a
    ctx->pc = 0x138A30u;
    ctx->pc = 0x138A34u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
    ctx->pc = 0x139568u;
    sub_00139568_0x139568(rdram, ctx, runtime); return;
    ctx->pc = 0x138A38u;
    // 0x138a38: 0x27bdfff0
    ctx->pc = 0x138a38u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x138a3c: 0x3c020022
    ctx->pc = 0x138a3cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)34 << 16));
    // 0x138a40: 0xffb00000
    ctx->pc = 0x138a40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x138a44: 0x2450bc04
    ctx->pc = 0x138a44u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 2), 4294949892));
    // 0x138a48: 0xffbf0008
    ctx->pc = 0x138a48u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x138a4c: 0x3c040024
    ctx->pc = 0x138a4cu;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x138a50: 0x2484c8e0
    ctx->pc = 0x138a50u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294953184));
    // 0x138a54: 0xc045a12
    ctx->pc = 0x138A54u;
    SET_GPR_U32(ctx, 31, 0x138A5Cu);
    ctx->pc = 0x138A58u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 16), 0)));
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138A5Cu; }
    }
    if (ctx->pc != 0x138A5Cu) { return; }
    ctx->pc = 0x138A5Cu;
    // 0x138a5c: 0x3c040022
    ctx->pc = 0x138a5cu;
    SET_GPR_U32(ctx, 4, ((uint32_t)34 << 16));
    // 0x138a60: 0x8e020000
    ctx->pc = 0x138a60u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x138a64: 0x2484bc08
    ctx->pc = 0x138a64u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294949896));
    // 0x138a68: 0x282d
    ctx->pc = 0x138a68u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138a6c: 0x14400004
    ctx->pc = 0x138A6Cu;
    {
        const bool branch_taken_0x138a6c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x138A70u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 2048));
        if (branch_taken_0x138a6c) {
            ctx->pc = 0x138A80u;
            goto label_138a80;
        }
    }
    ctx->pc = 0x138A74u;
    // 0x138a74: 0xc041f1a
    ctx->pc = 0x138A74u;
    SET_GPR_U32(ctx, 31, 0x138A7Cu);
    ctx->pc = 0x107C68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138A7Cu; }
    }
    if (ctx->pc != 0x138A7Cu) { return; }
    ctx->pc = 0x138A7Cu;
    // 0x138a7c: 0x8e020000
    ctx->pc = 0x138a7cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_138a80:
    // 0x138a80: 0x24420001
    ctx->pc = 0x138a80u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
    // 0x138a84: 0x3c040024
    ctx->pc = 0x138a84u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x138a88: 0xae020000
    ctx->pc = 0x138a88u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x138a8c: 0x2484c8f8
    ctx->pc = 0x138a8cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294953208));
    // 0x138a90: 0xdfb00000
    ctx->pc = 0x138a90u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x138a94: 0xdfbf0008
    ctx->pc = 0x138a94u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x138a98: 0x8045a12
    ctx->pc = 0x138A98u;
    ctx->pc = 0x138A9Cu;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x116848u;
    sub_00116848_0x116848(rdram, ctx, runtime); return;
    ctx->pc = 0x138AA0u;
    // 0x138aa0: 0x3c030022
    ctx->pc = 0x138aa0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)34 << 16));
    // 0x138aa4: 0x2463bc04
    ctx->pc = 0x138aa4u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294949892));
    // 0x138aa8: 0x8c620000
    ctx->pc = 0x138aa8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x138aac: 0x2442ffff
    ctx->pc = 0x138aacu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x138ab0: 0x3e00008
    ctx->pc = 0x138AB0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x138AB4u;
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138A00u: goto label_138a00;
            case 0x138A18u: goto label_138a18;
            case 0x138A80u: goto label_138a80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x138AB8u;
}
