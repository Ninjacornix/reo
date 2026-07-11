#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0012DA38
// Address: 0x12da38 - 0x12da50
void sub_0012DA38_0x12da38(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x12da38u;

    // 0x12da38: 0x27bdfff0
    ctx->pc = 0x12da38u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12da3c: 0xffbf0000
    ctx->pc = 0x12da3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12da40: 0x8c840004
    ctx->pc = 0x12da40u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x12da44: 0xdfbf0000
    ctx->pc = 0x12da44u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12da48: 0x80493dc
    ctx->pc = 0x12DA48u;
    ctx->pc = 0x12DA4Cu;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x124F70u;
    entry_124f70_0x124fb0(rdram, ctx, runtime); return;
    ctx->pc = 0x12DA50u;
}
