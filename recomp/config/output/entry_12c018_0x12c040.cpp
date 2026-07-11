#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: entry_12c018
// Address: 0x12c018 - 0x12c040
void entry_12c018_0x12c040(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x12c018u;

    // 0x12c018: 0x27bdfff0
    ctx->pc = 0x12c018u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c01c: 0x3c020021
    ctx->pc = 0x12c01cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x12c020: 0xffbf0000
    ctx->pc = 0x12c020u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c024: 0x24030001
    ctx->pc = 0x12c024u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
    // 0x12c028: 0x2442049c
    ctx->pc = 0x12c028u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1180));
    // 0x12c02c: 0xdfbf0000
    ctx->pc = 0x12c02cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c030: 0x0
    ctx->pc = 0x12c030u;
    // NOP
    // 0x12c034: 0x804ac36
    ctx->pc = 0x12C034u;
    ctx->pc = 0x12C038u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x12B0D8u;
    sub_0012B0D8_0x12b0d8(rdram, ctx, runtime); return;
    ctx->pc = 0x12C03Cu;
    // 0x12c03c: 0x0
    ctx->pc = 0x12c03cu;
    // NOP
}
