#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00129D48
// Address: 0x129d48 - 0x129d78
void sub_00129D48_0x129d48(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x129d48u;

    // 0x129d48: 0x27bdfff0
    ctx->pc = 0x129d48u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x129d4c: 0x14800006
    ctx->pc = 0x129D4Cu;
    {
        const bool branch_taken_0x129d4c = (GPR_U32(ctx, 4) != GPR_U32(ctx, 0));
        ctx->pc = 0x129D50u;
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        if (branch_taken_0x129d4c) {
            ctx->pc = 0x129D68u;
            goto label_129d68;
        }
    }
    ctx->pc = 0x129D54u;
    // 0x129d54: 0x3c040024
    ctx->pc = 0x129d54u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x129d58: 0xc04a034
    ctx->pc = 0x129D58u;
    SET_GPR_U32(ctx, 31, 0x129D60u);
    ctx->pc = 0x129D5Cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294943248));
    ctx->pc = 0x1280D0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129D60u; }
    }
    if (ctx->pc != 0x129D60u) { return; }
    ctx->pc = 0x129D60u;
    // 0x129d60: 0x10000002
    ctx->pc = 0x129D60u;
    {
        const bool branch_taken_0x129d60 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x129D64u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967293));
        if (branch_taken_0x129d60) {
            ctx->pc = 0x129D6Cu;
            goto label_129d6c;
        }
    }
    ctx->pc = 0x129D68u;
label_129d68:
    // 0x129d68: 0x80820001
    ctx->pc = 0x129d68u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
label_129d6c:
    // 0x129d6c: 0xdfbf0000
    ctx->pc = 0x129d6cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x129d70: 0x3e00008
    ctx->pc = 0x129D70u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x129D74u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x129D68u: goto label_129d68;
            case 0x129D6Cu: goto label_129d6c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x129D78u;
}
