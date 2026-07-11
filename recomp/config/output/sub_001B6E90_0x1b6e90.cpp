#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001B6E90
// Address: 0x1b6e90 - 0x1b6f10
void sub_001B6E90_0x1b6e90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1b6e90u;

    // 0x1b6e90: 0x24a2ffff
    ctx->pc = 0x1b6e90u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x1b6e94: 0x2303c
    ctx->pc = 0x1b6e94u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1b6e98: 0x3c021000
    ctx->pc = 0x1b6e98u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x1b6e9c: 0x6303f
    ctx->pc = 0x1b6e9cu;
    SET_GPR_S64(ctx, 6, GPR_S64(ctx, 6) >> (32 + 0));
    // 0x1b6ea0: 0x34450003
    ctx->pc = 0x1b6ea0u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 2), 3));
    // 0x1b6ea4: 0x2183c
    ctx->pc = 0x1b6ea4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1b6ea8: 0xac850000
    ctx->pc = 0x1b6ea8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
    // 0x1b6eac: 0x3c025100
    ctx->pc = 0x1b6eacu;
    SET_GPR_U32(ctx, 2, ((uint32_t)20736 << 16));
    // 0x1b6eb0: 0x34450003
    ctx->pc = 0x1b6eb0u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 2), 3));
    // 0x1b6eb4: 0xac800004
    ctx->pc = 0x1b6eb4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 0));
    // 0x1b6eb8: 0xac800008
    ctx->pc = 0x1b6eb8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 0));
    // 0x1b6ebc: 0x24020002
    ctx->pc = 0x1b6ebcu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b6ec0: 0x431025
    ctx->pc = 0x1b6ec0u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b6ec4: 0xac85000c
    ctx->pc = 0x1b6ec4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 5));
    // 0x1b6ec8: 0xfc820010
    ctx->pc = 0x1b6ec8u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 16), GPR_U64(ctx, 2));
    // 0x1b6ecc: 0x2402000e
    ctx->pc = 0x1b6eccu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 14));
    // 0x1b6ed0: 0xfc820018
    ctx->pc = 0x1b6ed0u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 24), GPR_U64(ctx, 2));
    // 0x1b6ed4: 0x24020044
    ctx->pc = 0x1b6ed4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 68));
    // 0x1b6ed8: 0xfc820020
    ctx->pc = 0x1b6ed8u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 32), GPR_U64(ctx, 2));
    // 0x1b6edc: 0x24020042
    ctx->pc = 0x1b6edcu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 66));
    // 0x1b6ee0: 0xfc820028
    ctx->pc = 0x1b6ee0u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 40), GPR_U64(ctx, 2));
    // 0x1b6ee4: 0x613b8
    ctx->pc = 0x1b6ee4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) << 14);
    // 0x1b6ee8: 0x3443000a
    ctx->pc = 0x1b6ee8u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 2), 10));
    // 0x1b6eec: 0x610bc
    ctx->pc = 0x1b6eecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) << (32 + 2));
    // 0x1b6ef0: 0x621025
    ctx->pc = 0x1b6ef0u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1b6ef4: 0xfc820030
    ctx->pc = 0x1b6ef4u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 48), GPR_U64(ctx, 2));
    // 0x1b6ef8: 0x24030008
    ctx->pc = 0x1b6ef8u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 8));
    // 0x1b6efc: 0x24820040
    ctx->pc = 0x1b6efcu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 4), 64));
    // 0x1b6f00: 0x3e00008
    ctx->pc = 0x1B6F00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B6F04u;
        WRITE64(ADD32(GPR_U32(ctx, 4), 56), GPR_U64(ctx, 3));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1B6F08u;
    // 0x1b6f08: 0x0
    ctx->pc = 0x1b6f08u;
    // NOP
    // 0x1b6f0c: 0x0
    ctx->pc = 0x1b6f0cu;
    // NOP
}
