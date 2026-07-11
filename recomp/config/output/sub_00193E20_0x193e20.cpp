#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00193E20
// Address: 0x193e20 - 0x193ed0
void sub_00193E20_0x193e20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x193e20u;

    // 0x193e20: 0x27bdffc0
    ctx->pc = 0x193e20u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x193e24: 0x24050010
    ctx->pc = 0x193e24u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
    // 0x193e28: 0xffbf0030
    ctx->pc = 0x193e28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x193e2c: 0x7fb20020
    ctx->pc = 0x193e2cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x193e30: 0x7fb10010
    ctx->pc = 0x193e30u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x193e34: 0x7fb00000
    ctx->pc = 0x193e34u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x193e38: 0x80882d
    ctx->pc = 0x193e38u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x193e3c: 0x8c820000
    ctx->pc = 0x193e3cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x193e40: 0x30427fff
    ctx->pc = 0x193e40u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 32767));
    // 0x193e44: 0x24520001
    ctx->pc = 0x193e44u;
    SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 2), 1));
    // 0x193e48: 0xc063774
    ctx->pc = 0x193E48u;
    SET_GPR_U32(ctx, 31, 0x193E50u);
    ctx->pc = 0x193E4Cu;
    SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 18), 4));
    ctx->pc = 0x18DDD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193E50u; }
    }
    if (ctx->pc != 0x193E50u) { return; }
    ctx->pc = 0x193E50u;
    // 0x193e50: 0x8e290000
    ctx->pc = 0x193e50u;
    SET_GPR_U32(ctx, 9, READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x193e54: 0x40802d
    ctx->pc = 0x193e54u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x193e58: 0x2643ffff
    ctx->pc = 0x193e58u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 18), 4294967295));
    // 0x193e5c: 0x3c025100
    ctx->pc = 0x193e5cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)20736 << 16));
    // 0x193e60: 0x3c088000
    ctx->pc = 0x193e60u;
    SET_GPR_U32(ctx, 8, ((uint32_t)32768 << 16));
    // 0x193e64: 0x621025
    ctx->pc = 0x193e64u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x193e68: 0x3c071300
    ctx->pc = 0x193e68u;
    SET_GPR_U32(ctx, 7, ((uint32_t)4864 << 16));
    // 0x193e6c: 0x240302d
    ctx->pc = 0x193e6cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x193e70: 0x220202d
    ctx->pc = 0x193e70u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x193e74: 0x200282d
    ctx->pc = 0x193e74u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x193e78: 0x1281825
    ctx->pc = 0x193e78u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 9), GPR_U32(ctx, 8)));
    // 0x193e7c: 0xae230000
    ctx->pc = 0x193e7cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x193e80: 0xae270008
    ctx->pc = 0x193e80u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 7));
    // 0x193e84: 0xc0626c2
    ctx->pc = 0x193E84u;
    SET_GPR_U32(ctx, 31, 0x193E8Cu);
    ctx->pc = 0x193E88u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 2));
    ctx->pc = 0x189B08u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00189B08_0x189b08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193E8Cu; }
    }
    if (ctx->pc != 0x193E8Cu) { return; }
    ctx->pc = 0x193E8Cu;
    // 0x193e8c: 0x10193c
    ctx->pc = 0x193e8cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) << (32 + 4));
    // 0x193e90: 0x3c07002a
    ctx->pc = 0x193e90u;
    SET_GPR_U32(ctx, 7, ((uint32_t)42 << 16));
    // 0x193e94: 0x3193e
    ctx->pc = 0x193e94u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 4));
    // 0x193e98: 0x3c024000
    ctx->pc = 0x193e98u;
    SET_GPR_U32(ctx, 2, ((uint32_t)16384 << 16));
    // 0x193e9c: 0x200302d
    ctx->pc = 0x193e9cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x193ea0: 0x202d
    ctx->pc = 0x193ea0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x193ea4: 0x622825
    ctx->pc = 0x193ea4u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x193ea8: 0xc0633ec
    ctx->pc = 0x193EA8u;
    SET_GPR_U32(ctx, 31, 0x193EB0u);
    ctx->pc = 0x193EACu;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 4294964976));
    ctx->pc = 0x18CFB0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018CFB0_0x18cfb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193EB0u; }
    }
    if (ctx->pc != 0x193EB0u) { return; }
    ctx->pc = 0x193EB0u;
    // 0x193eb0: 0xdfbf0030
    ctx->pc = 0x193eb0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x193eb4: 0x24020001
    ctx->pc = 0x193eb4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x193eb8: 0x7bb20020
    ctx->pc = 0x193eb8u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x193ebc: 0x7bb10010
    ctx->pc = 0x193ebcu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x193ec0: 0x7bb00000
    ctx->pc = 0x193ec0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x193ec4: 0x3e00008
    ctx->pc = 0x193EC4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x193EC8u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x193ECCu;
    // 0x193ecc: 0x0
    ctx->pc = 0x193eccu;
    // NOP
}
