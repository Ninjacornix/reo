#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00112708
// Address: 0x112708 - 0x112770
void sub_00112708_0x112708(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x112708u;

    // 0x112708: 0x3c021000
    ctx->pc = 0x112708u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x11270c: 0x24070001
    ctx->pc = 0x11270cu;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 0), 1));
    // 0x112710: 0x34423c10
    ctx->pc = 0x112710u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 15376));
    // 0x112714: 0x3c031000
    ctx->pc = 0x112714u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x112718: 0xac470000
    ctx->pc = 0x112718u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 7)); // MMIO: 0x10000000
    // 0x11271c: 0x34633c20
    ctx->pc = 0x11271cu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 15392));
    // 0x112720: 0x24020002
    ctx->pc = 0x112720u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 2));
    // 0x112724: 0x202d
    ctx->pc = 0x112724u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x112728: 0xac620000
    ctx->pc = 0x112728u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2)); // MMIO: 0x10000000
    // 0x11272c: 0xf
    ctx->pc = 0x11272cu;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x112730: 0x4844e000
    ctx->pc = 0x112730u;
    SET_GPR_U32(ctx, 4, ctx->vu0_itop);
    // 0x112734: 0x34840200
    ctx->pc = 0x112734u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 512));
    // 0x112738: 0x48c4e000
    ctx->pc = 0x112738u;
    ctx->vu0_itop = GPR_U32(ctx, 4) & 0x3FF;
    // 0x11273c: 0x40f
    ctx->pc = 0x11273cu;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x112740: 0x3c050021
    ctx->pc = 0x112740u;
    SET_GPR_U32(ctx, 5, ((uint32_t)33 << 16));
    // 0x112744: 0x3c061000
    ctx->pc = 0x112744u;
    SET_GPR_U32(ctx, 6, ((uint32_t)4096 << 16));
    // 0x112748: 0x24a59c80
    ctx->pc = 0x112748u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294941824));
    // 0x11274c: 0x34c65000
    ctx->pc = 0x11274cu;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 6), 20480));
    // 0x112750: 0x78a40000
    ctx->pc = 0x112750u;
    SET_GPR_VEC(ctx, 4, READ128(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x112754: 0x3c031000
    ctx->pc = 0x112754u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x112758: 0x34633000
    ctx->pc = 0x112758u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 12288));
    // 0x11275c: 0x7cc40000
    ctx->pc = 0x11275cu;
    WRITE128(ADD32(GPR_U32(ctx, 6), 0), GPR_VEC(ctx, 4));
    // 0x112760: 0x78a20010
    ctx->pc = 0x112760u;
    SET_GPR_VEC(ctx, 2, READ128(ADD32(GPR_U32(ctx, 5), 16)));
    // 0x112764: 0x7cc20000
    ctx->pc = 0x112764u;
    WRITE128(ADD32(GPR_U32(ctx, 6), 0), GPR_VEC(ctx, 2));
    // 0x112768: 0x3e00008
    ctx->pc = 0x112768u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11276Cu;
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 7));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x112770u;
}
