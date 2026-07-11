#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00117220
// Address: 0x117220 - 0x117248
void sub_00117220_0x117220(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x117220u;

    // 0x117220: 0x27bdfff0
    ctx->pc = 0x117220u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x117224: 0xffbf0000
    ctx->pc = 0x117224u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x117228: 0xc045ae8
    ctx->pc = 0x117228u;
    SET_GPR_U32(ctx, 31, 0x117230u);
    ctx->pc = 0x116BA0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116BA0_0x116ba0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117230u; }
    }
    if (ctx->pc != 0x117230u) { return; }
    ctx->pc = 0x117230u;
    // 0x117230: 0x3c020021
    ctx->pc = 0x117230u;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x117234: 0xdfbf0000
    ctx->pc = 0x117234u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x117238: 0xac409d50
    ctx->pc = 0x117238u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294942032), GPR_U32(ctx, 0));
    // 0x11723c: 0x3e00008
    ctx->pc = 0x11723Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x117240u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x117244u;
    // 0x117244: 0x0
    ctx->pc = 0x117244u;
    // NOP
}
