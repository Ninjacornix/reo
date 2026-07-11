#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0015B258
// Address: 0x15b258 - 0x15b2e0
void sub_0015B258_0x15b258(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x15b258u;

    // 0x15b258: 0x3c020023
    ctx->pc = 0x15b258u;
    SET_GPR_U32(ctx, 2, ((uint32_t)35 << 16));
    // 0x15b25c: 0x2403017f
    ctx->pc = 0x15b25cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 383));
    // 0x15b260: 0x2444d8e8
    ctx->pc = 0x15b260u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 4294957288));
    // 0x15b264: 0x0
    ctx->pc = 0x15b264u;
    // NOP
label_15b268:
    // 0x15b268: 0x2463ffff
    ctx->pc = 0x15b268u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x15b26c: 0xa0800000
    ctx->pc = 0x15b26cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x15b270: 0x0
    ctx->pc = 0x15b270u;
    // NOP
    // 0x15b274: 0x0
    ctx->pc = 0x15b274u;
    // NOP
    // 0x15b278: 0x0
    ctx->pc = 0x15b278u;
    // NOP
    // 0x15b27c: 0x461fffa
    ctx->pc = 0x15B27Cu;
    {
        const bool branch_taken_0x15b27c = (GPR_S32(ctx, 3) >= 0);
        ctx->pc = 0x15B280u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 1));
        if (branch_taken_0x15b27c) {
            ctx->pc = 0x15B268u;
            goto label_15b268;
        }
    }
    ctx->pc = 0x15B284u;
    // 0x15b284: 0x182d
    ctx->pc = 0x15b284u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_15b288:
    // 0x15b288: 0xa0830000
    ctx->pc = 0x15b288u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x15b28c: 0x24630001
    ctx->pc = 0x15b28cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 1));
    // 0x15b290: 0x28620100
    ctx->pc = 0x15b290u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 3), 256));
    // 0x15b294: 0x0
    ctx->pc = 0x15b294u;
    // NOP
    // 0x15b298: 0x0
    ctx->pc = 0x15b298u;
    // NOP
    // 0x15b29c: 0x1440fffa
    ctx->pc = 0x15B29Cu;
    {
        const bool branch_taken_0x15b29c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x15B2A0u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 1));
        if (branch_taken_0x15b29c) {
            ctx->pc = 0x15B288u;
            goto label_15b288;
        }
    }
    ctx->pc = 0x15B2A4u;
    // 0x15b2a4: 0x2402ffff
    ctx->pc = 0x15b2a4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x15b2a8: 0x2403017f
    ctx->pc = 0x15b2a8u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 383));
    // 0x15b2ac: 0x0
    ctx->pc = 0x15b2acu;
    // NOP
label_15b2b0:
    // 0x15b2b0: 0x2463ffff
    ctx->pc = 0x15b2b0u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x15b2b4: 0xa0820000
    ctx->pc = 0x15b2b4u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x15b2b8: 0x0
    ctx->pc = 0x15b2b8u;
    // NOP
    // 0x15b2bc: 0x0
    ctx->pc = 0x15b2bcu;
    // NOP
    // 0x15b2c0: 0x0
    ctx->pc = 0x15b2c0u;
    // NOP
    // 0x15b2c4: 0x461fffa
    ctx->pc = 0x15B2C4u;
    {
        const bool branch_taken_0x15b2c4 = (GPR_S32(ctx, 3) >= 0);
        ctx->pc = 0x15B2C8u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 1));
        if (branch_taken_0x15b2c4) {
            ctx->pc = 0x15B2B0u;
            goto label_15b2b0;
        }
    }
    ctx->pc = 0x15B2CCu;
    // 0x15b2cc: 0x3c020023
    ctx->pc = 0x15b2ccu;
    SET_GPR_U32(ctx, 2, ((uint32_t)35 << 16));
    // 0x15b2d0: 0x3c030023
    ctx->pc = 0x15b2d0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)35 << 16));
    // 0x15b2d4: 0x2442da68
    ctx->pc = 0x15b2d4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294957672));
    // 0x15b2d8: 0x3e00008
    ctx->pc = 0x15B2D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15B2DCu;
        WRITE32(ADD32(GPR_U32(ctx, 3), 4294957276), GPR_U32(ctx, 2));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15B268u: goto label_15b268;
            case 0x15B288u: goto label_15b288;
            case 0x15B2B0u: goto label_15b2b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15B2E0u;
}
