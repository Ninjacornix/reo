#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: entry_124f70
// Address: 0x124f70 - 0x124fb0
void entry_124f70_0x124fb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x124f70u;

    // 0x124f70: 0x27bdfff0
    ctx->pc = 0x124f70u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x124f74: 0xffb00000
    ctx->pc = 0x124f74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x124f78: 0x80802d
    ctx->pc = 0x124f78u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124f7c: 0xffbf0008
    ctx->pc = 0x124f7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x124f80: 0x260500a8
    ctx->pc = 0x124f80u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 16), 168));
    // 0x124f84: 0x260600ac
    ctx->pc = 0x124f84u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 16), 172));
    // 0x124f88: 0xc04d3c0
    ctx->pc = 0x124F88u;
    SET_GPR_U32(ctx, 31, 0x124F90u);
    ctx->pc = 0x124F8Cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 8)));
    ctx->pc = 0x134F00u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00134F00_0x134f00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124F90u; }
    }
    if (ctx->pc != 0x124F90u) { return; }
    ctx->pc = 0x124F90u;
    // 0x124f90: 0x8e040008
    ctx->pc = 0x124f90u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x124f94: 0x260700a6
    ctx->pc = 0x124f94u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 16), 166));
    // 0x124f98: 0x260500a2
    ctx->pc = 0x124f98u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 16), 162));
    // 0x124f9c: 0x260600a4
    ctx->pc = 0x124f9cu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 16), 164));
    // 0x124fa0: 0xdfb00000
    ctx->pc = 0x124fa0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x124fa4: 0xdfbf0008
    ctx->pc = 0x124fa4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x124fa8: 0x804d3ce
    ctx->pc = 0x124FA8u;
    ctx->pc = 0x124FACu;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x134F38u;
    entry_134f38_0x134f58(rdram, ctx, runtime); return;
    ctx->pc = 0x124FB0u;
}
