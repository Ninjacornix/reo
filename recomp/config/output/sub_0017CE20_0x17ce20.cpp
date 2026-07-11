#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0017CE20
// Address: 0x17ce20 - 0x17ce90
void sub_0017CE20_0x17ce20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x17ce20u;

    // 0x17ce20: 0x27bdfff0
    ctx->pc = 0x17ce20u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17ce24: 0x3c020023
    ctx->pc = 0x17ce24u;
    SET_GPR_U32(ctx, 2, ((uint32_t)35 << 16));
    // 0x17ce28: 0xffb00000
    ctx->pc = 0x17ce28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17ce2c: 0x2450f298
    ctx->pc = 0x17ce2cu;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 2), 4294963864));
    // 0x17ce30: 0x8e030000
    ctx->pc = 0x17ce30u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17ce34: 0x1c600012
    ctx->pc = 0x17CE34u;
    {
        const bool branch_taken_0x17ce34 = (GPR_S32(ctx, 3) > 0);
        ctx->pc = 0x17CE38u;
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        if (branch_taken_0x17ce34) {
            ctx->pc = 0x17CE80u;
            goto label_17ce80;
        }
    }
    ctx->pc = 0x17CE3Cu;
    // 0x17ce3c: 0xc05f3a4
    ctx->pc = 0x17CE3Cu;
    SET_GPR_U32(ctx, 31, 0x17CE44u);
    ctx->pc = 0x17CE90u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0017CE90_0x17ce90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CE44u; }
    }
    if (ctx->pc != 0x17CE44u) { return; }
    ctx->pc = 0x17CE44u;
    // 0x17ce44: 0x3c030027
    ctx->pc = 0x17ce44u;
    SET_GPR_U32(ctx, 3, ((uint32_t)39 << 16));
    // 0x17ce48: 0x24636148
    ctx->pc = 0x17ce48u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 24904));
    // 0x17ce4c: 0xc05f3a8
    ctx->pc = 0x17CE4Cu;
    SET_GPR_U32(ctx, 31, 0x17CE54u);
    ctx->pc = 0x17CE50u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    ctx->pc = 0x17CEA0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0017CEA0_0x17cea0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CE54u; }
    }
    if (ctx->pc != 0x17CE54u) { return; }
    ctx->pc = 0x17CE54u;
    // 0x17ce54: 0xc05f58e
    ctx->pc = 0x17CE54u;
    SET_GPR_U32(ctx, 31, 0x17CE5Cu);
    ctx->pc = 0x17D638u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D638_0x17d638(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CE5Cu; }
    }
    if (ctx->pc != 0x17CE5Cu) { return; }
    ctx->pc = 0x17CE5Cu;
    // 0x17ce5c: 0xc05f5ba
    ctx->pc = 0x17CE5Cu;
    SET_GPR_U32(ctx, 31, 0x17CE64u);
    ctx->pc = 0x17D6E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D6E8_0x17d6e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CE64u; }
    }
    if (ctx->pc != 0x17CE64u) { return; }
    ctx->pc = 0x17CE64u;
    // 0x17ce64: 0xc05e988
    ctx->pc = 0x17CE64u;
    SET_GPR_U32(ctx, 31, 0x17CE6Cu);
    ctx->pc = 0x17A620u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A620_0x17a620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CE6Cu; }
    }
    if (ctx->pc != 0x17CE6Cu) { return; }
    ctx->pc = 0x17CE6Cu;
    // 0x17ce6c: 0x8e020000
    ctx->pc = 0x17ce6cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17ce70: 0x3c030023
    ctx->pc = 0x17ce70u;
    SET_GPR_U32(ctx, 3, ((uint32_t)35 << 16));
    // 0x17ce74: 0xac60f29c
    ctx->pc = 0x17ce74u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294963868), GPR_U32(ctx, 0));
    // 0x17ce78: 0x24420001
    ctx->pc = 0x17ce78u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
    // 0x17ce7c: 0xae020000
    ctx->pc = 0x17ce7cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
label_17ce80:
    // 0x17ce80: 0xdfb00000
    ctx->pc = 0x17ce80u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17ce84: 0xdfbf0008
    ctx->pc = 0x17ce84u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17ce88: 0x3e00008
    ctx->pc = 0x17CE88u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17CE8Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17CE80u: goto label_17ce80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17CE90u;
}
