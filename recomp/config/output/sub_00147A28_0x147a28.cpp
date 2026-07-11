#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00147A28
// Address: 0x147a28 - 0x147ad8
void sub_00147A28_0x147a28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x147a28u;

    // 0x147a28: 0x27bdfff0
    ctx->pc = 0x147a28u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x147a2c: 0xffbf0000
    ctx->pc = 0x147a2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x147a30: 0xc047598
    ctx->pc = 0x147A30u;
    SET_GPR_U32(ctx, 31, 0x147A38u);
    ctx->pc = 0x11D660u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147A38u; }
    }
    if (ctx->pc != 0x147A38u) { return; }
    ctx->pc = 0x147A38u;
    // 0x147a38: 0x3c091000
    ctx->pc = 0x147a38u;
    SET_GPR_U32(ctx, 9, ((uint32_t)4096 << 16));
    // 0x147a3c: 0x3c040001
    ctx->pc = 0x147a3cu;
    SET_GPR_U32(ctx, 4, ((uint32_t)1 << 16));
    // 0x147a40: 0x3529f520
    ctx->pc = 0x147a40u;
    SET_GPR_U32(ctx, 9, OR32(GPR_U32(ctx, 9), 62752));
    // 0x147a44: 0x3c0a1000
    ctx->pc = 0x147a44u;
    SET_GPR_U32(ctx, 10, ((uint32_t)4096 << 16));
    // 0x147a48: 0x8d230000
    ctx->pc = 0x147a48u;
    SET_GPR_U32(ctx, 3, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 9), 0))); // MMIO: 0x10000000
    // 0x147a4c: 0x354af590
    ctx->pc = 0x147a4cu;
    SET_GPR_U32(ctx, 10, OR32(GPR_U32(ctx, 10), 62864));
    // 0x147a50: 0x3c061000
    ctx->pc = 0x147a50u;
    SET_GPR_U32(ctx, 6, ((uint32_t)4096 << 16));
    // 0x147a54: 0x3c08ffff
    ctx->pc = 0x147a54u;
    SET_GPR_U32(ctx, 8, ((uint32_t)65535 << 16));
    // 0x147a58: 0x641825
    ctx->pc = 0x147a58u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x147a5c: 0x34c6b000
    ctx->pc = 0x147a5cu;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 6), 45056));
    // 0x147a60: 0xad430000
    ctx->pc = 0x147a60u;
    WRITE32(ADD32(GPR_U32(ctx, 10), 0), GPR_U32(ctx, 3));
    // 0x147a64: 0x3508feff
    ctx->pc = 0x147a64u;
    SET_GPR_U32(ctx, 8, OR32(GPR_U32(ctx, 8), 65279));
    // 0x147a68: 0x3c051000
    ctx->pc = 0x147a68u;
    SET_GPR_U32(ctx, 5, ((uint32_t)4096 << 16));
    // 0x147a6c: 0x3c07fffe
    ctx->pc = 0x147a6cu;
    SET_GPR_U32(ctx, 7, ((uint32_t)65534 << 16));
    // 0x147a70: 0x8cc40000
    ctx->pc = 0x147a70u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x147a74: 0x34a5b400
    ctx->pc = 0x147a74u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 46080));
    // 0x147a78: 0x34e7ffff
    ctx->pc = 0x147a78u;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 7), 65535));
    // 0x147a7c: 0x882024
    ctx->pc = 0x147a7cu;
    SET_GPR_U32(ctx, 4, AND32(GPR_U32(ctx, 4), GPR_U32(ctx, 8)));
    // 0x147a80: 0xacc40000
    ctx->pc = 0x147a80u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x147a84: 0x8ca30000
    ctx->pc = 0x147a84u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x147a88: 0x681824
    ctx->pc = 0x147a88u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x147a8c: 0xaca30000
    ctx->pc = 0x147a8cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x147a90: 0x8d240000
    ctx->pc = 0x147a90u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x147a94: 0x872024
    ctx->pc = 0x147a94u;
    SET_GPR_U32(ctx, 4, AND32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x147a98: 0xad440000
    ctx->pc = 0x147a98u;
    WRITE32(ADD32(GPR_U32(ctx, 10), 0), GPR_U32(ctx, 4));
    // 0x147a9c: 0x10400004
    ctx->pc = 0x147A9Cu;
    {
        const bool branch_taken_0x147a9c = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x147AA0u;
        SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
        if (branch_taken_0x147a9c) {
            ctx->pc = 0x147AB0u;
            goto label_147ab0;
        }
    }
    ctx->pc = 0x147AA4u;
    // 0x147aa4: 0xc0475ae
    ctx->pc = 0x147AA4u;
    SET_GPR_U32(ctx, 31, 0x147AACu);
    ctx->pc = 0x11D6B8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147AACu; }
    }
    if (ctx->pc != 0x147AACu) { return; }
    ctx->pc = 0x147AACu;
    // 0x147aac: 0x3c021000
    ctx->pc = 0x147aacu;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
label_147ab0:
    // 0x147ab0: 0x3c031000
    ctx->pc = 0x147ab0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x147ab4: 0x3442b020
    ctx->pc = 0x147ab4u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 45088));
    // 0x147ab8: 0x3463b420
    ctx->pc = 0x147ab8u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 46112));
    // 0x147abc: 0xac400000
    ctx->pc = 0x147abcu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0)); // MMIO: 0x10000000
    // 0x147ac0: 0xc044fec
    ctx->pc = 0x147AC0u;
    SET_GPR_U32(ctx, 31, 0x147AC8u);
    ctx->pc = 0x147AC4u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0));
    ctx->pc = 0x113FB0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00113FB0_0x113fb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147AC8u; }
    }
    if (ctx->pc != 0x147AC8u) { return; }
    ctx->pc = 0x147AC8u;
    // 0x147ac8: 0xdfbf0000
    ctx->pc = 0x147ac8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x147acc: 0x24020001
    ctx->pc = 0x147accu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x147ad0: 0x3e00008
    ctx->pc = 0x147AD0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x147AD4u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x147AB0u: goto label_147ab0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x147AD8u;
}
