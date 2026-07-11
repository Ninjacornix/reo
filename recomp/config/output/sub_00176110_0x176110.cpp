#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00176110
// Address: 0x176110 - 0x176188
void sub_00176110_0x176110(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x176110u;

    // 0x176110: 0x27bdfff0
    ctx->pc = 0x176110u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x176114: 0x248300e4
    ctx->pc = 0x176114u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 4), 228));
    // 0x176118: 0xffb00000
    ctx->pc = 0x176118u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17611c: 0x248400bc
    ctx->pc = 0x17611cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 188));
    // 0x176120: 0xffbf0008
    ctx->pc = 0x176120u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x176124: 0x8c620000
    ctx->pc = 0x176124u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x176128: 0x10400005
    ctx->pc = 0x176128u;
    {
        const bool branch_taken_0x176128 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x17612Cu;
        WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
        if (branch_taken_0x176128) {
            ctx->pc = 0x176140u;
            goto label_176140;
        }
    }
    ctx->pc = 0x176130u;
    // 0x176130: 0x8c660024
    ctx->pc = 0x176130u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x176134: 0x1000000a
    ctx->pc = 0x176134u;
    {
        const bool branch_taken_0x176134 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x176138u;
        SET_GPR_U32(ctx, 16, READ32(ADD32(GPR_U32(ctx, 3), 32)));
        if (branch_taken_0x176134) {
            ctx->pc = 0x176160u;
            goto label_176160;
        }
    }
    ctx->pc = 0x17613Cu;
    // 0x17613c: 0x0
    ctx->pc = 0x17613cu;
    // NOP
label_176140:
    // 0x176140: 0x8c820020
    ctx->pc = 0x176140u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 4), 32)));
    // 0x176144: 0x4400004
    ctx->pc = 0x176144u;
    {
        const bool branch_taken_0x176144 = (GPR_S32(ctx, 2) < 0);
        ctx->pc = 0x176148u;
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x176144) {
            ctx->pc = 0x176158u;
            goto label_176158;
        }
    }
    ctx->pc = 0x17614Cu;
    // 0x17614c: 0x10000004
    ctx->pc = 0x17614Cu;
    {
        const bool branch_taken_0x17614c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x176150u;
        SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 4), 36)));
        if (branch_taken_0x17614c) {
            ctx->pc = 0x176160u;
            goto label_176160;
        }
    }
    ctx->pc = 0x176154u;
    // 0x176154: 0x0
    ctx->pc = 0x176154u;
    // NOP
label_176158:
    // 0x176158: 0x10000007
    ctx->pc = 0x176158u;
    {
        const bool branch_taken_0x176158 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x17615Cu;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x176158) {
            ctx->pc = 0x176178u;
            goto label_176178;
        }
    }
    ctx->pc = 0x176160u;
label_176160:
    // 0x176160: 0xc056ea0
    ctx->pc = 0x176160u;
    SET_GPR_U32(ctx, 31, 0x176168u);
    ctx->pc = 0x176164u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x15BA80u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0015BA80_0x15ba80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176168u; }
    }
    if (ctx->pc != 0x176168u) { return; }
    ctx->pc = 0x176168u;
    // 0x176168: 0x3c030023
    ctx->pc = 0x176168u;
    SET_GPR_U32(ctx, 3, ((uint32_t)35 << 16));
    // 0x17616c: 0x3c040023
    ctx->pc = 0x17616cu;
    SET_GPR_U32(ctx, 4, ((uint32_t)35 << 16));
    // 0x176170: 0xac70f1d0
    ctx->pc = 0x176170u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294963664), GPR_U32(ctx, 16));
    // 0x176174: 0xac82f1d4
    ctx->pc = 0x176174u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4294963668), GPR_U32(ctx, 2));
label_176178:
    // 0x176178: 0xdfb00000
    ctx->pc = 0x176178u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17617c: 0xdfbf0008
    ctx->pc = 0x17617cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x176180: 0x3e00008
    ctx->pc = 0x176180u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x176184u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x176140u: goto label_176140;
            case 0x176158u: goto label_176158;
            case 0x176160u: goto label_176160;
            case 0x176178u: goto label_176178;
            default: break;
        }
        return;
    }
    ctx->pc = 0x176188u;
}
