#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0015B208
// Address: 0x15b208 - 0x15b258
void sub_0015B208_0x15b208(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x15b208u;

    // 0x15b208: 0x27bdfff0
    ctx->pc = 0x15b208u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15b20c: 0xffb00000
    ctx->pc = 0x15b20cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15b210: 0xffbf0008
    ctx->pc = 0x15b210u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x15b214: 0xc056c96
    ctx->pc = 0x15B214u;
    SET_GPR_U32(ctx, 31, 0x15B21Cu);
    ctx->pc = 0x15B218u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x15B258u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B258_0x15b258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B21Cu; }
    }
    if (ctx->pc != 0x15B21Cu) { return; }
    ctx->pc = 0x15B21Cu;
    // 0x15b21c: 0x3c050023
    ctx->pc = 0x15b21cu;
    SET_GPR_U32(ctx, 5, ((uint32_t)35 << 16));
    // 0x15b220: 0x200202d
    ctx->pc = 0x15b220u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15b224: 0x24a5d8e8
    ctx->pc = 0x15b224u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294957288));
    // 0x15b228: 0x12000006
    ctx->pc = 0x15B228u;
    {
        const bool branch_taken_0x15b228 = (GPR_U32(ctx, 16) == GPR_U32(ctx, 0));
        ctx->pc = 0x15B22Cu;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 256));
        if (branch_taken_0x15b228) {
            ctx->pc = 0x15B244u;
            goto label_15b244;
        }
    }
    ctx->pc = 0x15B230u;
    // 0x15b230: 0xc05583c
    ctx->pc = 0x15B230u;
    SET_GPR_U32(ctx, 31, 0x15B238u);
    ctx->pc = 0x1560F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001560F0_0x1560f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B238u; }
    }
    if (ctx->pc != 0x15B238u) { return; }
    ctx->pc = 0x15B238u;
    // 0x15b238: 0x3c030023
    ctx->pc = 0x15b238u;
    SET_GPR_U32(ctx, 3, ((uint32_t)35 << 16));
    // 0x15b23c: 0x26020180
    ctx->pc = 0x15b23cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 16), 384));
    // 0x15b240: 0xac62d8dc
    ctx->pc = 0x15b240u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294957276), GPR_U32(ctx, 2));
label_15b244:
    // 0x15b244: 0xdfb00000
    ctx->pc = 0x15b244u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15b248: 0xdfbf0008
    ctx->pc = 0x15b248u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15b24c: 0x3e00008
    ctx->pc = 0x15B24Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15B250u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15B244u: goto label_15b244;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15B254u;
    // 0x15b254: 0x0
    ctx->pc = 0x15b254u;
    // NOP
}
