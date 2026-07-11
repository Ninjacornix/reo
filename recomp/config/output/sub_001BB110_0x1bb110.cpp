#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001BB110
// Address: 0x1bb110 - 0x1bb160
void sub_001BB110_0x1bb110(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1bb110u;

    // 0x1bb110: 0x27bdfff0
    ctx->pc = 0x1bb110u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1bb114: 0x3c010023
    ctx->pc = 0x1bb114u;
    SET_GPR_U32(ctx, 1, ((uint32_t)35 << 16));
    // 0x1bb118: 0xffbf0000
    ctx->pc = 0x1bb118u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1bb11c: 0x8c234e20
    ctx->pc = 0x1bb11cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 1), 20000)));
    // 0x1bb120: 0x2463ffff
    ctx->pc = 0x1bb120u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1bb124: 0x3c010023
    ctx->pc = 0x1bb124u;
    SET_GPR_U32(ctx, 1, ((uint32_t)35 << 16));
    // 0x1bb128: 0x14600007
    ctx->pc = 0x1BB128u;
    {
        const bool branch_taken_0x1bb128 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x1BB12Cu;
        WRITE32(ADD32(GPR_U32(ctx, 1), 20000), GPR_U32(ctx, 3));
        if (branch_taken_0x1bb128) {
            ctx->pc = 0x1BB148u;
            goto label_1bb148;
        }
    }
    ctx->pc = 0x1BB130u;
    // 0x1bb130: 0x3c040032
    ctx->pc = 0x1bb130u;
    SET_GPR_U32(ctx, 4, ((uint32_t)50 << 16));
    // 0x1bb134: 0x24020014
    ctx->pc = 0x1bb134u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 20));
    // 0x1bb138: 0x3c010023
    ctx->pc = 0x1bb138u;
    SET_GPR_U32(ctx, 1, ((uint32_t)35 << 16));
    // 0x1bb13c: 0x24844198
    ctx->pc = 0x1bb13cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 16792));
    // 0x1bb140: 0xc040742
    ctx->pc = 0x1BB140u;
    SET_GPR_U32(ctx, 31, 0x1BB148u);
    ctx->pc = 0x1BB144u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 20000), GPR_U32(ctx, 2));
    ctx->pc = 0x101D08u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00101D08_0x101d08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB148u; }
    }
    if (ctx->pc != 0x1BB148u) { return; }
    ctx->pc = 0x1BB148u;
label_1bb148:
    // 0x1bb148: 0xdfbf0000
    ctx->pc = 0x1bb148u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bb14c: 0x3e00008
    ctx->pc = 0x1BB14Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BB150u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BB148u: goto label_1bb148;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BB154u;
    // 0x1bb154: 0x0
    ctx->pc = 0x1bb154u;
    // NOP
    // 0x1bb158: 0x0
    ctx->pc = 0x1bb158u;
    // NOP
    // 0x1bb15c: 0x0
    ctx->pc = 0x1bb15cu;
    // NOP
}
