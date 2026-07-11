#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0011D970
// Address: 0x11d970 - 0x11d9b8
void sub_0011D970_0x11d970(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x11d970u;

    // 0x11d970: 0x2403005a
    ctx->pc = 0x11d970u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 90));
    // 0x11d974: 0xc
    ctx->pc = 0x11d974u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x11d978: 0x3e00008
    ctx->pc = 0x11D978u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11D990u: goto label_11d990;
            case 0x11D9B0u: goto label_11d9b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11D980u;
    // 0x11d980: 0x63082
    ctx->pc = 0x11d980u;
    SET_GPR_U32(ctx, 6, SRL32(GPR_U32(ctx, 6), 2));
    // 0x11d984: 0x10c0000a
    ctx->pc = 0x11D984u;
    {
        const bool branch_taken_0x11d984 = (GPR_U32(ctx, 6) == GPR_U32(ctx, 0));
        ctx->pc = 0x11D988u;
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x11d984) {
            ctx->pc = 0x11D9B0u;
            goto label_11d9b0;
        }
    }
    ctx->pc = 0x11D98Cu;
    // 0x11d98c: 0x0
    ctx->pc = 0x11d98cu;
    // NOP
label_11d990:
    // 0x11d990: 0x8ca30000
    ctx->pc = 0x11d990u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x11d994: 0x24e70001
    ctx->pc = 0x11d994u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 1));
    // 0x11d998: 0x24a50004
    ctx->pc = 0x11d998u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4));
    // 0x11d99c: 0xe6102b
    ctx->pc = 0x11d99cu;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 7), GPR_U32(ctx, 6)));
    // 0x11d9a0: 0xac830000
    ctx->pc = 0x11d9a0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3));
    // 0x11d9a4: 0x24840004
    ctx->pc = 0x11d9a4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4));
    // 0x11d9a8: 0x1440fff9
    ctx->pc = 0x11D9A8u;
    {
        const bool branch_taken_0x11d9a8 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x11d9a8) {
            ctx->pc = 0x11D990u;
            goto label_11d990;
        }
    }
    ctx->pc = 0x11D9B0u;
label_11d9b0:
    // 0x11d9b0: 0x3e00008
    ctx->pc = 0x11D9B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11D9B4u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11D990u: goto label_11d990;
            case 0x11D9B0u: goto label_11d9b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11D9B8u;
}
