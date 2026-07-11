#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0013CA18
// Address: 0x13ca18 - 0x13caa8
void sub_0013CA18_0x13ca18(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x13ca18u;

    // 0x13ca18: 0x27bdfff0
    ctx->pc = 0x13ca18u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13ca1c: 0x80282d
    ctx->pc = 0x13ca1cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ca20: 0x14800007
    ctx->pc = 0x13CA20u;
    {
        const bool branch_taken_0x13ca20 = (GPR_U32(ctx, 4) != GPR_U32(ctx, 0));
        ctx->pc = 0x13CA24u;
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        if (branch_taken_0x13ca20) {
            ctx->pc = 0x13CA40u;
            goto label_13ca40;
        }
    }
    ctx->pc = 0x13CA28u;
    // 0x13ca28: 0xdfbf0000
    ctx->pc = 0x13ca28u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13ca2c: 0x3c020022
    ctx->pc = 0x13ca2cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)34 << 16));
    // 0x13ca30: 0xa040dea8
    ctx->pc = 0x13ca30u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 4294958760), (uint8_t)GPR_U32(ctx, 0));
    // 0x13ca34: 0x3e00008
    ctx->pc = 0x13CA34u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13CA38u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13CA40u: goto label_13ca40;
            case 0x13CA80u: goto label_13ca80;
            case 0x13CA8Cu: goto label_13ca8c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13CA3Cu;
    // 0x13ca3c: 0x0
    ctx->pc = 0x13ca3cu;
    // NOP
label_13ca40:
    // 0x13ca40: 0x80840000
    ctx->pc = 0x13ca40u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x13ca44: 0x2402002f
    ctx->pc = 0x13ca44u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 47));
    // 0x13ca48: 0x1082000d
    ctx->pc = 0x13CA48u;
    {
        const bool branch_taken_0x13ca48 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 2));
        ctx->pc = 0x13CA4Cu;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 92));
        if (branch_taken_0x13ca48) {
            ctx->pc = 0x13CA80u;
            goto label_13ca80;
        }
    }
    ctx->pc = 0x13CA50u;
    // 0x13ca50: 0x1082000b
    ctx->pc = 0x13CA50u;
    {
        const bool branch_taken_0x13ca50 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 2));
        ctx->pc = 0x13CA54u;
        SET_GPR_U32(ctx, 4, ((uint32_t)34 << 16));
        if (branch_taken_0x13ca50) {
            ctx->pc = 0x13CA80u;
            goto label_13ca80;
        }
    }
    ctx->pc = 0x13CA58u;
    // 0x13ca58: 0x3c020024
    ctx->pc = 0x13ca58u;
    SET_GPR_U32(ctx, 2, ((uint32_t)36 << 16));
    // 0x13ca5c: 0x2448d150
    ctx->pc = 0x13ca5cu;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 2), 4294955344));
    // 0x13ca60: 0x2487dea8
    ctx->pc = 0x13ca60u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 4), 4294958760));
    // 0x13ca64: 0x81030000
    ctx->pc = 0x13ca64u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x13ca68: 0x81060001
    ctx->pc = 0x13ca68u;
    SET_GPR_S32(ctx, 6, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 1)));
    // 0x13ca6c: 0xa0e30000
    ctx->pc = 0x13ca6cu;
    WRITE8(ADD32(GPR_U32(ctx, 7), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x13ca70: 0xa0e60001
    ctx->pc = 0x13ca70u;
    WRITE8(ADD32(GPR_U32(ctx, 7), 1), (uint8_t)GPR_U32(ctx, 6));
    // 0x13ca74: 0x10000005
    ctx->pc = 0x13CA74u;
    {
        const bool branch_taken_0x13ca74 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x13CA78u;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        if (branch_taken_0x13ca74) {
            ctx->pc = 0x13CA8Cu;
            goto label_13ca8c;
        }
    }
    ctx->pc = 0x13CA7Cu;
    // 0x13ca7c: 0x0
    ctx->pc = 0x13ca7cu;
    // NOP
label_13ca80:
    // 0x13ca80: 0x3c040022
    ctx->pc = 0x13ca80u;
    SET_GPR_U32(ctx, 4, ((uint32_t)34 << 16));
    // 0x13ca84: 0xa080dea8
    ctx->pc = 0x13ca84u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 4294958760), (uint8_t)GPR_U32(ctx, 0));
    // 0x13ca88: 0xdfbf0000
    ctx->pc = 0x13ca88u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_13ca8c:
    // 0x13ca8c: 0x2484dea8
    ctx->pc = 0x13ca8cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294958760));
    // 0x13ca90: 0x8042bf0
    ctx->pc = 0x13CA90u;
    ctx->pc = 0x13CA94u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x10AFC0u;
    sub_0010AFC0_0x10afc0(rdram, ctx, runtime); return;
    ctx->pc = 0x13CA98u;
    // 0x13ca98: 0x3c020022
    ctx->pc = 0x13ca98u;
    SET_GPR_U32(ctx, 2, ((uint32_t)34 << 16));
    // 0x13ca9c: 0x3e00008
    ctx->pc = 0x13CA9Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13CAA0u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294958760));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13CA40u: goto label_13ca40;
            case 0x13CA80u: goto label_13ca80;
            case 0x13CA8Cu: goto label_13ca8c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13CAA4u;
    // 0x13caa4: 0x0
    ctx->pc = 0x13caa4u;
    // NOP
}
