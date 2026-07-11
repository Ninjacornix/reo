#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001B6F10
// Address: 0x1b6f10 - 0x1b6fd0
void sub_001B6F10_0x1b6f10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1b6f10u;

    // 0x1b6f10: 0x3c01002a
    ctx->pc = 0x1b6f10u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1b6f14: 0x24a2ffff
    ctx->pc = 0x1b6f14u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x1b6f18: 0x8c2bf9f0
    ctx->pc = 0x1b6f18u;
    SET_GPR_U32(ctx, 11, READ32(ADD32(GPR_U32(ctx, 1), 4294965744)));
    // 0x1b6f1c: 0x2603c
    ctx->pc = 0x1b6f1cu;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1b6f20: 0x3c021000
    ctx->pc = 0x1b6f20u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x1b6f24: 0x3c065100
    ctx->pc = 0x1b6f24u;
    SET_GPR_U32(ctx, 6, ((uint32_t)20736 << 16));
    // 0x1b6f28: 0x34c90004
    ctx->pc = 0x1b6f28u;
    SET_GPR_U32(ctx, 9, OR32(GPR_U32(ctx, 6), 4));
    // 0x1b6f2c: 0x344a0004
    ctx->pc = 0x1b6f2cu;
    SET_GPR_U32(ctx, 10, OR32(GPR_U32(ctx, 2), 4));
    // 0x1b6f30: 0x2183c
    ctx->pc = 0x1b6f30u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1b6f34: 0xc603f
    ctx->pc = 0x1b6f34u;
    SET_GPR_S64(ctx, 12, GPR_S64(ctx, 12) >> (32 + 0));
    // 0x1b6f38: 0x24020003
    ctx->pc = 0x1b6f38u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 3));
    // 0x1b6f3c: 0x2408000e
    ctx->pc = 0x1b6f3cu;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 0), 14));
    // 0x1b6f40: 0x432825
    ctx->pc = 0x1b6f40u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b6f44: 0x24070044
    ctx->pc = 0x1b6f44u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 0), 68));
    // 0x1b6f48: 0x3c01002a
    ctx->pc = 0x1b6f48u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1b6f4c: 0xb1142
    ctx->pc = 0x1b6f4cu;
    SET_GPR_U32(ctx, 2, SRL32(GPR_U32(ctx, 11), 5));
    // 0x1b6f50: 0x9c2df9e4
    ctx->pc = 0x1b6f50u;
    SET_GPR_U32(ctx, 13, READ32(ADD32(GPR_U32(ctx, 1), 4294965732)));
    // 0x1b6f54: 0x2183c
    ctx->pc = 0x1b6f54u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1b6f58: 0x3183e
    ctx->pc = 0x1b6f58u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 0));
    // 0x1b6f5c: 0x24060042
    ctx->pc = 0x1b6f5cu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 66));
    // 0x1b6f60: 0xac8a0000
    ctx->pc = 0x1b6f60u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 10));
    // 0x1b6f64: 0xd1638
    ctx->pc = 0x1b6f64u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 13) << 24);
    // 0x1b6f68: 0xac800004
    ctx->pc = 0x1b6f68u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 0));
    // 0x1b6f6c: 0x621825
    ctx->pc = 0x1b6f6cu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1b6f70: 0xac800008
    ctx->pc = 0x1b6f70u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 0));
    // 0x1b6f74: 0xc13b8
    ctx->pc = 0x1b6f74u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 12) << 14);
    // 0x1b6f78: 0xac89000c
    ctx->pc = 0x1b6f78u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 9));
    // 0x1b6f7c: 0xfc850010
    ctx->pc = 0x1b6f7cu;
    WRITE64(ADD32(GPR_U32(ctx, 4), 16), GPR_U64(ctx, 5));
    // 0x1b6f80: 0x3445000a
    ctx->pc = 0x1b6f80u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 2), 10));
    // 0x1b6f84: 0xfc880018
    ctx->pc = 0x1b6f84u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 24), GPR_U64(ctx, 8));
    // 0x1b6f88: 0xc10bc
    ctx->pc = 0x1b6f88u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 12) << (32 + 2));
    // 0x1b6f8c: 0xfc870020
    ctx->pc = 0x1b6f8cu;
    WRITE64(ADD32(GPR_U32(ctx, 4), 32), GPR_U64(ctx, 7));
    // 0x1b6f90: 0xa21025
    ctx->pc = 0x1b6f90u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1b6f94: 0xfc860028
    ctx->pc = 0x1b6f94u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 40), GPR_U64(ctx, 6));
    // 0x1b6f98: 0xfc820030
    ctx->pc = 0x1b6f98u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 48), GPR_U64(ctx, 2));
    // 0x1b6f9c: 0x24050008
    ctx->pc = 0x1b6f9cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 8));
    // 0x1b6fa0: 0x24020001
    ctx->pc = 0x1b6fa0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b6fa4: 0xfc850038
    ctx->pc = 0x1b6fa4u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 56), GPR_U64(ctx, 5));
    // 0x1b6fa8: 0x2103c
    ctx->pc = 0x1b6fa8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1b6fac: 0x621025
    ctx->pc = 0x1b6facu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1b6fb0: 0xfc820040
    ctx->pc = 0x1b6fb0u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 64), GPR_U64(ctx, 2));
    // 0x1b6fb4: 0x2403004e
    ctx->pc = 0x1b6fb4u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 78));
    // 0x1b6fb8: 0x24820050
    ctx->pc = 0x1b6fb8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 4), 80));
    // 0x1b6fbc: 0x3e00008
    ctx->pc = 0x1B6FBCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B6FC0u;
        WRITE64(ADD32(GPR_U32(ctx, 4), 72), GPR_U64(ctx, 3));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1B6FC4u;
    // 0x1b6fc4: 0x0
    ctx->pc = 0x1b6fc4u;
    // NOP
    // 0x1b6fc8: 0x0
    ctx->pc = 0x1b6fc8u;
    // NOP
    // 0x1b6fcc: 0x0
    ctx->pc = 0x1b6fccu;
    // NOP
}
