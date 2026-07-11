#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001CC7E0
// Address: 0x1cc7e0 - 0x1cc800
void sub_001CC7E0_0x1cc7e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1cc7e0u;

    // 0x1cc7e0: 0x3c011001
    ctx->pc = 0x1cc7e0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)4097 << 16));
    // 0x1cc7e4: 0x24030105
    ctx->pc = 0x1cc7e4u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 261));
    // 0x1cc7e8: 0xac24b430
    ctx->pc = 0x1cc7e8u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 4294947888), GPR_U32(ctx, 4)); // MMIO: 0x1000b430
    // 0x1cc7ec: 0x3c011001
    ctx->pc = 0x1cc7ecu;
    SET_GPR_U32(ctx, 1, ((uint32_t)4097 << 16));
    // 0x1cc7f0: 0xac20b420
    ctx->pc = 0x1cc7f0u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 4294947872), GPR_U32(ctx, 0)); // MMIO: 0x1000b420
    // 0x1cc7f4: 0x3c011001
    ctx->pc = 0x1cc7f4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)4097 << 16));
    // 0x1cc7f8: 0x3e00008
    ctx->pc = 0x1CC7F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CC7FCu;
        runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 4294947840), GPR_U32(ctx, 3));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1CC800u;
}
