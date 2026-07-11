#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0018DD40
// Address: 0x18dd40 - 0x18ddd0
void sub_0018DD40_0x18dd40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x18dd40u;

    // 0x18dd40: 0x27bdfff0
    ctx->pc = 0x18dd40u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x18dd44: 0x3c01002a
    ctx->pc = 0x18dd44u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x18dd48: 0xffbf0000
    ctx->pc = 0x18dd48u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x18dd4c: 0x24030001
    ctx->pc = 0x18dd4cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
    // 0x18dd50: 0x8c24fdb0
    ctx->pc = 0x18dd50u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 1), 4294966704)));
    // 0x18dd54: 0x10830008
    ctx->pc = 0x18DD54u;
    {
        const bool branch_taken_0x18dd54 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        if (branch_taken_0x18dd54) {
            ctx->pc = 0x18DD78u;
            goto label_18dd78;
        }
    }
    ctx->pc = 0x18DD5Cu;
    // 0x18dd5c: 0x24030002
    ctx->pc = 0x18dd5cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 2));
    // 0x18dd60: 0x10830005
    ctx->pc = 0x18DD60u;
    {
        const bool branch_taken_0x18dd60 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        if (branch_taken_0x18dd60) {
            ctx->pc = 0x18DD78u;
            goto label_18dd78;
        }
    }
    ctx->pc = 0x18DD68u;
    // 0x18dd68: 0x10800003
    ctx->pc = 0x18DD68u;
    {
        const bool branch_taken_0x18dd68 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 0));
        if (branch_taken_0x18dd68) {
            ctx->pc = 0x18DD78u;
            goto label_18dd78;
        }
    }
    ctx->pc = 0x18DD70u;
    // 0x18dd70: 0x10000014
    ctx->pc = 0x18DD70u;
    {
        const bool branch_taken_0x18dd70 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x18DD74u;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        if (branch_taken_0x18dd70) {
            ctx->pc = 0x18DDC4u;
            goto label_18ddc4;
        }
    }
    ctx->pc = 0x18DD78u;
label_18dd78:
    // 0x18dd78: 0x3c01002a
    ctx->pc = 0x18dd78u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x18dd7c: 0x3c02002a
    ctx->pc = 0x18dd7cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)42 << 16));
    // 0x18dd80: 0x8c23fdb4
    ctx->pc = 0x18dd80u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 1), 4294966708)));
    // 0x18dd84: 0x2442fdc4
    ctx->pc = 0x18dd84u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294966724));
    // 0x18dd88: 0x31880
    ctx->pc = 0x18dd88u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 3), 2));
    // 0x18dd8c: 0x431021
    ctx->pc = 0x18dd8cu;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x18dd90: 0xc063728
    ctx->pc = 0x18DD90u;
    SET_GPR_U32(ctx, 31, 0x18DD98u);
    ctx->pc = 0x18DD94u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    ctx->pc = 0x18DCA0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCA0_0x18dca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DD98u; }
    }
    if (ctx->pc != 0x18DD98u) { return; }
    ctx->pc = 0x18DD98u;
    // 0x18dd98: 0x3c01002a
    ctx->pc = 0x18dd98u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x18dd9c: 0x3c030008
    ctx->pc = 0x18dd9cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)8 << 16));
    // 0x18dda0: 0xac22fdb8
    ctx->pc = 0x18dda0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966712), GPR_U32(ctx, 2));
    // 0x18dda4: 0x3c01002a
    ctx->pc = 0x18dda4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x18dda8: 0x8c24fdb8
    ctx->pc = 0x18dda8u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 1), 4294966712)));
    // 0x18ddac: 0x3c01002a
    ctx->pc = 0x18ddacu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x18ddb0: 0x831821
    ctx->pc = 0x18ddb0u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x18ddb4: 0xac24fdc0
    ctx->pc = 0x18ddb4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966720), GPR_U32(ctx, 4));
    // 0x18ddb8: 0x3c01002a
    ctx->pc = 0x18ddb8u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x18ddbc: 0xac23fdbc
    ctx->pc = 0x18ddbcu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966716), GPR_U32(ctx, 3));
    // 0x18ddc0: 0xdfbf0000
    ctx->pc = 0x18ddc0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_18ddc4:
    // 0x18ddc4: 0x3e00008
    ctx->pc = 0x18DDC4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18DDC8u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18DD78u: goto label_18dd78;
            case 0x18DDC4u: goto label_18ddc4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18DDCCu;
    // 0x18ddcc: 0x0
    ctx->pc = 0x18ddccu;
    // NOP
}
