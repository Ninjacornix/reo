#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: entry_124fb0
// Address: 0x124fb0 - 0x124ff0
void entry_124fb0_0x124ff0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x124fb0u;

    // 0x124fb0: 0x27bdfff0
    ctx->pc = 0x124fb0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x124fb4: 0xffb00000
    ctx->pc = 0x124fb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x124fb8: 0x80802d
    ctx->pc = 0x124fb8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124fbc: 0xffbf0008
    ctx->pc = 0x124fbcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x124fc0: 0x260500a8
    ctx->pc = 0x124fc0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 16), 168));
    // 0x124fc4: 0x260600ac
    ctx->pc = 0x124fc4u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 16), 172));
    // 0x124fc8: 0xc04d3b6
    ctx->pc = 0x124FC8u;
    SET_GPR_U32(ctx, 31, 0x124FD0u);
    ctx->pc = 0x124FCCu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 8)));
    ctx->pc = 0x134ED8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00134ED8_0x134ed8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124FD0u; }
    }
    if (ctx->pc != 0x124FD0u) { return; }
    ctx->pc = 0x124FD0u;
    // 0x124fd0: 0x8e040008
    ctx->pc = 0x124fd0u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x124fd4: 0x860700a6
    ctx->pc = 0x124fd4u;
    SET_GPR_S32(ctx, 7, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 166)));
    // 0x124fd8: 0x860500a2
    ctx->pc = 0x124fd8u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 162)));
    // 0x124fdc: 0x860600a4
    ctx->pc = 0x124fdcu;
    SET_GPR_S32(ctx, 6, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 164)));
    // 0x124fe0: 0xdfbf0008
    ctx->pc = 0x124fe0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x124fe4: 0xdfb00000
    ctx->pc = 0x124fe4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x124fe8: 0x804d3ca
    ctx->pc = 0x124FE8u;
    ctx->pc = 0x124FECu;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x134F28u;
    sub_00134F28_0x134f28(rdram, ctx, runtime); return;
    ctx->pc = 0x124FF0u;
}
