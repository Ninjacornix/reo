#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00113C20
// Address: 0x113c20 - 0x113c98
void sub_00113C20_0x113c20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x113c20u;

    // 0x113c20: 0x27bdffe0
    ctx->pc = 0x113c20u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x113c24: 0xffb00000
    ctx->pc = 0x113c24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x113c28: 0xffbf0010
    ctx->pc = 0x113c28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x113c2c: 0xc047598
    ctx->pc = 0x113C2Cu;
    SET_GPR_U32(ctx, 31, 0x113C34u);
    ctx->pc = 0x113C30u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x11D660u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113C34u; }
    }
    if (ctx->pc != 0x113C34u) { return; }
    ctx->pc = 0x113C34u;
    // 0x113c34: 0x3c061000
    ctx->pc = 0x113c34u;
    SET_GPR_U32(ctx, 6, ((uint32_t)4096 << 16));
    // 0x113c38: 0x3c071000
    ctx->pc = 0x113c38u;
    SET_GPR_U32(ctx, 7, ((uint32_t)4096 << 16));
    // 0x113c3c: 0x34c6f520
    ctx->pc = 0x113c3cu;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 6), 62752));
    // 0x113c40: 0x3c080001
    ctx->pc = 0x113c40u;
    SET_GPR_U32(ctx, 8, ((uint32_t)1 << 16));
    // 0x113c44: 0x8cc30000
    ctx->pc = 0x113c44u;
    SET_GPR_U32(ctx, 3, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 6), 0))); // MMIO: 0x10000000
    // 0x113c48: 0x34e7f590
    ctx->pc = 0x113c48u;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 7), 62864));
    // 0x113c4c: 0x3c041000
    ctx->pc = 0x113c4cu;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
    // 0x113c50: 0x3c05fffe
    ctx->pc = 0x113c50u;
    SET_GPR_U32(ctx, 5, ((uint32_t)65534 << 16));
    // 0x113c54: 0x681825
    ctx->pc = 0x113c54u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x113c58: 0x3484b400
    ctx->pc = 0x113c58u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 46080));
    // 0x113c5c: 0xace30000
    ctx->pc = 0x113c5cu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 3));
    // 0x113c60: 0x34a5ffff
    ctx->pc = 0x113c60u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 65535));
    // 0x113c64: 0xac900000
    ctx->pc = 0x113c64u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 16));
    // 0x113c68: 0x8cc30000
    ctx->pc = 0x113c68u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x113c6c: 0x651824
    ctx->pc = 0x113c6cu;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x113c70: 0xace30000
    ctx->pc = 0x113c70u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 3));
    // 0x113c74: 0x10400004
    ctx->pc = 0x113C74u;
    {
        const bool branch_taken_0x113c74 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x113C78u;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        if (branch_taken_0x113c74) {
            ctx->pc = 0x113C88u;
            goto label_113c88;
        }
    }
    ctx->pc = 0x113C7Cu;
    // 0x113c7c: 0xdfb00000
    ctx->pc = 0x113c7cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x113c80: 0x80475ae
    ctx->pc = 0x113C80u;
    ctx->pc = 0x113C84u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
    ctx->pc = 0x11D6B8u;
    sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    ctx->pc = 0x113C88u;
label_113c88:
    // 0x113c88: 0xdfb00000
    ctx->pc = 0x113c88u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x113c8c: 0x3e00008
    ctx->pc = 0x113C8Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x113C90u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x113C88u: goto label_113c88;
            default: break;
        }
        return;
    }
    ctx->pc = 0x113C94u;
    // 0x113c94: 0x0
    ctx->pc = 0x113c94u;
    // NOP
}
