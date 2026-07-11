#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001982D0
// Address: 0x1982d0 - 0x198390
void sub_001982D0_0x1982d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1982d0u;

    // 0x1982d0: 0x27bdffe0
    ctx->pc = 0x1982d0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1982d4: 0x24050010
    ctx->pc = 0x1982d4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
    // 0x1982d8: 0xffbf0010
    ctx->pc = 0x1982d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1982dc: 0x7fb00000
    ctx->pc = 0x1982dcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1982e0: 0x80802d
    ctx->pc = 0x1982e0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1982e4: 0xc063774
    ctx->pc = 0x1982E4u;
    SET_GPR_U32(ctx, 31, 0x1982ECu);
    ctx->pc = 0x1982E8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 48));
    ctx->pc = 0x18DDD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1982ECu; }
    }
    if (ctx->pc != 0x1982ECu) { return; }
    ctx->pc = 0x1982ECu;
    // 0x1982ec: 0x3403f000
    ctx->pc = 0x1982ecu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 0), 61440));
    // 0x1982f0: 0x3c07002a
    ctx->pc = 0x1982f0u;
    SET_GPR_U32(ctx, 7, ((uint32_t)42 << 16));
    // 0x1982f4: 0x32c38
    ctx->pc = 0x1982f4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) << 16);
    // 0x1982f8: 0x3c041300
    ctx->pc = 0x1982f8u;
    SET_GPR_U32(ctx, 4, ((uint32_t)4864 << 16));
    // 0x1982fc: 0x34a60002
    ctx->pc = 0x1982fcu;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 5), 2));
    // 0x198300: 0x3c035100
    ctx->pc = 0x198300u;
    SET_GPR_U32(ctx, 3, ((uint32_t)20736 << 16));
    // 0x198304: 0x34650002
    ctx->pc = 0x198304u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 3), 2));
    // 0x198308: 0xfc460000
    ctx->pc = 0x198308u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 0), GPR_U64(ctx, 6));
    // 0x19830c: 0xac440008
    ctx->pc = 0x19830cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 4));
    // 0x198310: 0x3c031000
    ctx->pc = 0x198310u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x198314: 0x3203c
    ctx->pc = 0x198314u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << (32 + 0));
    // 0x198318: 0xac45000c
    ctx->pc = 0x198318u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 12), GPR_U32(ctx, 5));
    // 0x19831c: 0x34038001
    ctx->pc = 0x19831cu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 0), 32769));
    // 0x198320: 0x24e7f6f0
    ctx->pc = 0x198320u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 4294964976));
    // 0x198324: 0x641825
    ctx->pc = 0x198324u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x198328: 0xfc430010
    ctx->pc = 0x198328u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 16), GPR_U64(ctx, 3));
    // 0x19832c: 0x2404000e
    ctx->pc = 0x19832cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 14));
    // 0x198330: 0xfc440018
    ctx->pc = 0x198330u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 24), GPR_U64(ctx, 4));
    // 0x198334: 0x101c02
    ctx->pc = 0x198334u;
    SET_GPR_U32(ctx, 3, SRL32(GPR_U32(ctx, 16), 16));
    // 0x198338: 0x102202
    ctx->pc = 0x198338u;
    SET_GPR_U32(ctx, 4, SRL32(GPR_U32(ctx, 16), 8));
    // 0x19833c: 0x306600ff
    ctx->pc = 0x19833cu;
    SET_GPR_U32(ctx, 6, AND32(GPR_U32(ctx, 3), 255));
    // 0x198340: 0x308500ff
    ctx->pc = 0x198340u;
    SET_GPR_U32(ctx, 5, AND32(GPR_U32(ctx, 4), 255));
    // 0x198344: 0x320300ff
    ctx->pc = 0x198344u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 16), 255));
    // 0x198348: 0x52a38
    ctx->pc = 0x198348u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << 8);
    // 0x19834c: 0x32438
    ctx->pc = 0x19834cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << 16);
    // 0x198350: 0xc53025
    ctx->pc = 0x198350u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
    // 0x198354: 0x2403003d
    ctx->pc = 0x198354u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 61));
    // 0x198358: 0x863025
    ctx->pc = 0x198358u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
    // 0x19835c: 0x2293c
    ctx->pc = 0x19835cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 4));
    // 0x198360: 0xfc460020
    ctx->pc = 0x198360u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 32), GPR_U64(ctx, 6));
    // 0x198364: 0x5293e
    ctx->pc = 0x198364u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> (32 + 4));
    // 0x198368: 0x202d
    ctx->pc = 0x198368u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19836c: 0x40302d
    ctx->pc = 0x19836cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x198370: 0xc0633ec
    ctx->pc = 0x198370u;
    SET_GPR_U32(ctx, 31, 0x198378u);
    ctx->pc = 0x198374u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 40), GPR_U64(ctx, 3));
    ctx->pc = 0x18CFB0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018CFB0_0x18cfb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x198378u; }
    }
    if (ctx->pc != 0x198378u) { return; }
    ctx->pc = 0x198378u;
    // 0x198378: 0xdfbf0010
    ctx->pc = 0x198378u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19837c: 0x24020001
    ctx->pc = 0x19837cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x198380: 0x7bb00000
    ctx->pc = 0x198380u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x198384: 0x3e00008
    ctx->pc = 0x198384u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x198388u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x19838Cu;
    // 0x19838c: 0x0
    ctx->pc = 0x19838cu;
    // NOP
}
