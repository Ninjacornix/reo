#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00128038
// Address: 0x128038 - 0x128070
void sub_00128038_0x128038(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x128038u;

    // 0x128038: 0x3c040021
    ctx->pc = 0x128038u;
    SET_GPR_U32(ctx, 4, ((uint32_t)33 << 16));
    // 0x12803c: 0x27bdfff0
    ctx->pc = 0x12803cu;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x128040: 0x282d
    ctx->pc = 0x128040u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128044: 0x2484c7b8
    ctx->pc = 0x128044u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294952888));
    // 0x128048: 0xffbf0000
    ctx->pc = 0x128048u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12804c: 0xc041f1a
    ctx->pc = 0x12804Cu;
    SET_GPR_U32(ctx, 31, 0x128054u);
    ctx->pc = 0x128050u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 256));
    ctx->pc = 0x107C68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128054u; }
    }
    if (ctx->pc != 0x128054u) { return; }
    ctx->pc = 0x128054u;
    // 0x128054: 0x3c030021
    ctx->pc = 0x128054u;
    SET_GPR_U32(ctx, 3, ((uint32_t)33 << 16));
    // 0x128058: 0xdfbf0000
    ctx->pc = 0x128058u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12805c: 0x3c020021
    ctx->pc = 0x12805cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x128060: 0xac60c7b0
    ctx->pc = 0x128060u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294952880), GPR_U32(ctx, 0));
    // 0x128064: 0xac40c7b4
    ctx->pc = 0x128064u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294952884), GPR_U32(ctx, 0));
    // 0x128068: 0x3e00008
    ctx->pc = 0x128068u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12806Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x128070u;
}
