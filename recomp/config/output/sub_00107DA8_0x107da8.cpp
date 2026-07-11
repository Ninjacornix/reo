#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00107DA8
// Address: 0x107da8 - 0x107df8
void sub_00107DA8_0x107da8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x107da8u;

    // 0x107da8: 0x27bdfff0
    ctx->pc = 0x107da8u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x107dac: 0x3c030021
    ctx->pc = 0x107dacu;
    SET_GPR_U32(ctx, 3, ((uint32_t)33 << 16));
    // 0x107db0: 0xffbf0000
    ctx->pc = 0x107db0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x107db4: 0x24639c5c
    ctx->pc = 0x107db4u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294941788));
    // 0x107db8: 0x8c620000
    ctx->pc = 0x107db8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x107dbc: 0x2442ffff
    ctx->pc = 0x107dbcu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x107dc0: 0x14400009
    ctx->pc = 0x107DC0u;
    {
        const bool branch_taken_0x107dc0 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x107DC4u;
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        if (branch_taken_0x107dc0) {
            ctx->pc = 0x107DE8u;
            goto label_107de8;
        }
    }
    ctx->pc = 0x107DC8u;
    // 0x107dc8: 0x3c020021
    ctx->pc = 0x107dc8u;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x107dcc: 0xdfbf0000
    ctx->pc = 0x107dccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x107dd0: 0x8c44a470
    ctx->pc = 0x107dd0u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 4294943856)));
    // 0x107dd4: 0x3c050021
    ctx->pc = 0x107dd4u;
    SET_GPR_U32(ctx, 5, ((uint32_t)33 << 16));
    // 0x107dd8: 0x2403ffff
    ctx->pc = 0x107dd8u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x107ddc: 0x0
    ctx->pc = 0x107ddcu;
    // NOP
    // 0x107de0: 0x8045190
    ctx->pc = 0x107DE0u;
    ctx->pc = 0x107DE4u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x114640u;
    sub_00114640_0x114640(rdram, ctx, runtime); return;
    ctx->pc = 0x107DE8u;
label_107de8:
    // 0x107de8: 0xdfbf0000
    ctx->pc = 0x107de8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x107dec: 0x3e00008
    ctx->pc = 0x107DECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x107DF0u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x107DE8u: goto label_107de8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x107DF4u;
    // 0x107df4: 0x0
    ctx->pc = 0x107df4u;
    // NOP
}
