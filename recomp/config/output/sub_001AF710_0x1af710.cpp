#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001AF710
// Address: 0x1af710 - 0x1af770
void sub_001AF710_0x1af710(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1af710u;

    // 0x1af710: 0x3c03002c
    ctx->pc = 0x1af710u;
    SET_GPR_U32(ctx, 3, ((uint32_t)44 << 16));
    // 0x1af714: 0x24050007
    ctx->pc = 0x1af714u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 7));
    // 0x1af718: 0x10000006
    ctx->pc = 0x1AF718u;
    {
        const bool branch_taken_0x1af718 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1AF71Cu;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294938248));
        if (branch_taken_0x1af718) {
            ctx->pc = 0x1AF734u;
            goto label_1af734;
        }
    }
    ctx->pc = 0x1AF720u;
label_1af720:
    // 0x1af720: 0x8c620000
    ctx->pc = 0x1af720u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1af724: 0x14400006
    ctx->pc = 0x1AF724u;
    {
        const bool branch_taken_0x1af724 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x1af724) {
            ctx->pc = 0x1AF740u;
            goto label_1af740;
        }
    }
    ctx->pc = 0x1AF72Cu;
    // 0x1af72c: 0x24a5ffff
    ctx->pc = 0x1af72cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x1af730: 0x2463fff8
    ctx->pc = 0x1af730u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294967288));
label_1af734:
    // 0x1af734: 0x0
    ctx->pc = 0x1af734u;
    // NOP
    // 0x1af738: 0x4a1fff9
    ctx->pc = 0x1AF738u;
    {
        const bool branch_taken_0x1af738 = (GPR_S32(ctx, 5) >= 0);
        if (branch_taken_0x1af738) {
            ctx->pc = 0x1AF720u;
            goto label_1af720;
        }
    }
    ctx->pc = 0x1AF740u;
label_1af740:
    // 0x1af740: 0x8c620004
    ctx->pc = 0x1af740u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x1af744: 0x3c01002c
    ctx->pc = 0x1af744u;
    SET_GPR_U32(ctx, 1, ((uint32_t)44 << 16));
    // 0x1af748: 0x441021
    ctx->pc = 0x1af748u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1af74c: 0xac620004
    ctx->pc = 0x1af74cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 2));
    // 0x1af750: 0x8c630004
    ctx->pc = 0x1af750u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x1af754: 0x8c228de0
    ctx->pc = 0x1af754u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 1), 4294938080)));
    // 0x1af758: 0x43082a
    ctx->pc = 0x1af758u;
    SET_GPR_U32(ctx, 1, SLT32(GPR_S32(ctx, 2), GPR_S32(ctx, 3)));
    // 0x1af75c: 0x10200002
    ctx->pc = 0x1AF75Cu;
    {
        const bool branch_taken_0x1af75c = (GPR_U32(ctx, 1) == GPR_U32(ctx, 0));
        ctx->pc = 0x1AF760u;
        SET_GPR_U32(ctx, 1, ((uint32_t)44 << 16));
        if (branch_taken_0x1af75c) {
            ctx->pc = 0x1AF768u;
            goto label_1af768;
        }
    }
    ctx->pc = 0x1AF764u;
    // 0x1af764: 0xac238de0
    ctx->pc = 0x1af764u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294938080), GPR_U32(ctx, 3));
label_1af768:
    // 0x1af768: 0x80636f8
    ctx->pc = 0x1AF768u;
    ctx->pc = 0x18DBE0u;
    entry_18dbe0_0x18dc00(rdram, ctx, runtime); return;
    ctx->pc = 0x1AF770u;
}
