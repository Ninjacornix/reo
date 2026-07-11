#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0013C9E8
// Address: 0x13c9e8 - 0x13ca18
void sub_0013C9E8_0x13c9e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x13c9e8u;

    // 0x13c9e8: 0x10800007
    ctx->pc = 0x13C9E8u;
    {
        const bool branch_taken_0x13c9e8 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 0));
        ctx->pc = 0x13C9ECu;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x13c9e8) {
            ctx->pc = 0x13CA08u;
            goto label_13ca08;
        }
    }
    ctx->pc = 0x13C9F0u;
    // 0x13c9f0: 0x14820006
    ctx->pc = 0x13C9F0u;
    {
        const bool branch_taken_0x13c9f0 = (GPR_U32(ctx, 4) != GPR_U32(ctx, 2));
        ctx->pc = 0x13C9F4u;
        SET_GPR_U32(ctx, 3, ((uint32_t)34 << 16));
        if (branch_taken_0x13c9f0) {
            ctx->pc = 0x13CA0Cu;
            goto label_13ca0c;
        }
    }
    ctx->pc = 0x13C9F8u;
    // 0x13c9f8: 0x3c020022
    ctx->pc = 0x13c9f8u;
    SET_GPR_U32(ctx, 2, ((uint32_t)34 << 16));
    // 0x13c9fc: 0x3e00008
    ctx->pc = 0x13C9FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13CA00u;
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294958752), GPR_U32(ctx, 4));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13CA08u: goto label_13ca08;
            case 0x13CA0Cu: goto label_13ca0c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13CA04u;
    // 0x13ca04: 0x0
    ctx->pc = 0x13ca04u;
    // NOP
label_13ca08:
    // 0x13ca08: 0x3c030022
    ctx->pc = 0x13ca08u;
    SET_GPR_U32(ctx, 3, ((uint32_t)34 << 16));
label_13ca0c:
    // 0x13ca0c: 0x34028001
    ctx->pc = 0x13ca0cu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 0), 32769));
    // 0x13ca10: 0x3e00008
    ctx->pc = 0x13CA10u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13CA14u;
        WRITE32(ADD32(GPR_U32(ctx, 3), 4294958752), GPR_U32(ctx, 2));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13CA08u: goto label_13ca08;
            case 0x13CA0Cu: goto label_13ca0c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13CA18u;
}
