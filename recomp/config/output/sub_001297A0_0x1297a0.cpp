#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001297A0
// Address: 0x1297a0 - 0x1297e0
void sub_001297A0_0x1297a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1297a0u;

    // 0x1297a0: 0x27bdfff0
    ctx->pc = 0x1297a0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1297a4: 0x30c2003f
    ctx->pc = 0x1297a4u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 6), 63));
    // 0x1297a8: 0x10400009
    ctx->pc = 0x1297A8u;
    {
        const bool branch_taken_0x1297a8 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1297ACu;
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        if (branch_taken_0x1297a8) {
            ctx->pc = 0x1297D0u;
            goto label_1297d0;
        }
    }
    ctx->pc = 0x1297B0u;
    // 0x1297b0: 0x3c040024
    ctx->pc = 0x1297b0u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x1297b4: 0xc04a034
    ctx->pc = 0x1297B4u;
    SET_GPR_U32(ctx, 31, 0x1297BCu);
    ctx->pc = 0x1297B8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294942752));
    ctx->pc = 0x1280D0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1297BCu; }
    }
    if (ctx->pc != 0x1297BCu) { return; }
    ctx->pc = 0x1297BCu;
    // 0x1297bc: 0x2402fffd
    ctx->pc = 0x1297bcu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967293));
    // 0x1297c0: 0xdfbf0000
    ctx->pc = 0x1297c0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1297c4: 0x3e00008
    ctx->pc = 0x1297C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1297C8u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1297D0u: goto label_1297d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1297CCu;
    // 0x1297cc: 0x0
    ctx->pc = 0x1297ccu;
    // NOP
label_1297d0:
    // 0x1297d0: 0xdfbf0000
    ctx->pc = 0x1297d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1297d4: 0x804a584
    ctx->pc = 0x1297D4u;
    ctx->pc = 0x1297D8u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x129610u;
    entry_129610_0x1297a0(rdram, ctx, runtime); return;
    ctx->pc = 0x1297DCu;
    // 0x1297dc: 0x0
    ctx->pc = 0x1297dcu;
    // NOP
}
