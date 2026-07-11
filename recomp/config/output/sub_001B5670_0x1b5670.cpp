#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001B5670
// Address: 0x1b5670 - 0x1b56a0
void sub_001B5670_0x1b5670(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1b5670u;

    // 0x1b5670: 0x14800006
    ctx->pc = 0x1B5670u;
    {
        const bool branch_taken_0x1b5670 = (GPR_U32(ctx, 4) != GPR_U32(ctx, 0));
        ctx->pc = 0x1B5674u;
        SET_GPR_U32(ctx, 3, ((uint32_t)44 << 16));
        if (branch_taken_0x1b5670) {
            ctx->pc = 0x1B568Cu;
            goto label_1b568c;
        }
    }
    ctx->pc = 0x1B5678u;
    // 0x1b5678: 0x3c03002c
    ctx->pc = 0x1b5678u;
    SET_GPR_U32(ctx, 3, ((uint32_t)44 << 16));
    // 0x1b567c: 0x3c010023
    ctx->pc = 0x1b567cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)35 << 16));
    // 0x1b5680: 0x2463aaf0
    ctx->pc = 0x1b5680u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294945520));
    // 0x1b5684: 0x10000004
    ctx->pc = 0x1B5684u;
    {
        const bool branch_taken_0x1b5684 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1B5688u;
        WRITE32(ADD32(GPR_U32(ctx, 1), 18280), GPR_U32(ctx, 3));
        if (branch_taken_0x1b5684) {
            ctx->pc = 0x1B5698u;
            goto label_1b5698;
        }
    }
    ctx->pc = 0x1B568Cu;
label_1b568c:
    // 0x1b568c: 0x3c010023
    ctx->pc = 0x1b568cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)35 << 16));
    // 0x1b5690: 0x2463aa40
    ctx->pc = 0x1b5690u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294945344));
    // 0x1b5694: 0xac234768
    ctx->pc = 0x1b5694u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 18280), GPR_U32(ctx, 3));
label_1b5698:
    // 0x1b5698: 0x3e00008
    ctx->pc = 0x1B5698u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B568Cu: goto label_1b568c;
            case 0x1B5698u: goto label_1b5698;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B56A0u;
}
