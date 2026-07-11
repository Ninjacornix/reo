#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001A0AD0
// Address: 0x1a0ad0 - 0x1a0bc0
void sub_001A0AD0_0x1a0ad0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1a0ad0u;

    // 0x1a0ad0: 0x27bdf7a0
    ctx->pc = 0x1a0ad0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294965152));
    // 0x1a0ad4: 0x24030001
    ctx->pc = 0x1a0ad4u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a0ad8: 0xffbf0000
    ctx->pc = 0x1a0ad8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a0adc: 0x28620008
    ctx->pc = 0x1a0adcu;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 3), 8));
    // 0x1a0ae0: 0xafa40818
    ctx->pc = 0x1a0ae0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 2072), GPR_U32(ctx, 4));
    // 0x1a0ae4: 0xffa50828
    ctx->pc = 0x1a0ae4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 2088), GPR_U64(ctx, 5));
    // 0x1a0ae8: 0xffa60830
    ctx->pc = 0x1a0ae8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 2096), GPR_U64(ctx, 6));
    // 0x1a0aec: 0xffa70838
    ctx->pc = 0x1a0aecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 2104), GPR_U64(ctx, 7));
    // 0x1a0af0: 0xffa80840
    ctx->pc = 0x1a0af0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 2112), GPR_U64(ctx, 8));
    // 0x1a0af4: 0xffa90848
    ctx->pc = 0x1a0af4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 2120), GPR_U64(ctx, 9));
    // 0x1a0af8: 0xffaa0850
    ctx->pc = 0x1a0af8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 2128), GPR_U64(ctx, 10));
    // 0x1a0afc: 0x14400003
    ctx->pc = 0x1A0AFCu;
    {
        const bool branch_taken_0x1a0afc = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1A0B00u;
        WRITE64(ADD32(GPR_U32(ctx, 29), 2136), GPR_U64(ctx, 11));
        if (branch_taken_0x1a0afc) {
            ctx->pc = 0x1A0B0Cu;
            goto label_1a0b0c;
        }
    }
    ctx->pc = 0x1A0B04u;
    // 0x1a0b04: 0x10000004
    ctx->pc = 0x1A0B04u;
    {
        const bool branch_taken_0x1a0b04 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1A0B08u;
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1a0b04) {
            ctx->pc = 0x1A0B18u;
            goto label_1a0b18;
        }
    }
    ctx->pc = 0x1A0B0Cu;
label_1a0b0c:
    // 0x1a0b0c: 0x24020008
    ctx->pc = 0x1a0b0cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 8));
    // 0x1a0b10: 0x431023
    ctx->pc = 0x1a0b10u;
    SET_GPR_U32(ctx, 2, SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a0b14: 0x218c0
    ctx->pc = 0x1a0b14u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 2), 3));
label_1a0b18:
    // 0x1a0b18: 0x8fa50818
    ctx->pc = 0x1a0b18u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 29), 2072)));
    // 0x1a0b1c: 0x27a20860
    ctx->pc = 0x1a0b1cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 29), 2144));
    // 0x1a0b20: 0x27a40010
    ctx->pc = 0x1a0b20u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 16));
    // 0x1a0b24: 0xc043e20
    ctx->pc = 0x1A0B24u;
    SET_GPR_U32(ctx, 31, 0x1A0B2Cu);
    ctx->pc = 0x1A0B28u;
    SET_GPR_U32(ctx, 6, SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    ctx->pc = 0x10F880u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010F880_0x10f880(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A0B2Cu; }
    }
    if (ctx->pc != 0x1A0B2Cu) { return; }
    ctx->pc = 0x1A0B2Cu;
    // 0x1a0b2c: 0xc042c56
    ctx->pc = 0x1A0B2Cu;
    SET_GPR_U32(ctx, 31, 0x1A0B34u);
    ctx->pc = 0x1A0B30u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x10B158u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A0B34u; }
    }
    if (ctx->pc != 0x1A0B34u) { return; }
    ctx->pc = 0x1A0B34u;
    // 0x1a0b34: 0x5d1021
    ctx->pc = 0x1a0b34u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 29)));
    // 0x1a0b38: 0x2403000d
    ctx->pc = 0x1a0b38u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 13));
    // 0x1a0b3c: 0x24440010
    ctx->pc = 0x1a0b3cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 16));
    // 0x1a0b40: 0x3c010023
    ctx->pc = 0x1a0b40u;
    SET_GPR_U32(ctx, 1, ((uint32_t)35 << 16));
    // 0x1a0b44: 0x2402000a
    ctx->pc = 0x1a0b44u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 10));
    // 0x1a0b48: 0xa0830000
    ctx->pc = 0x1a0b48u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1a0b4c: 0xa0820001
    ctx->pc = 0x1a0b4cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0x1a0b50: 0xa0800002
    ctx->pc = 0x1a0b50u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1a0b54: 0x8c220fb0
    ctx->pc = 0x1a0b54u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 1), 4016)));
    // 0x1a0b58: 0x1040000d
    ctx->pc = 0x1A0B58u;
    {
        const bool branch_taken_0x1a0b58 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1A0B5Cu;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 16));
        if (branch_taken_0x1a0b58) {
            ctx->pc = 0x1A0B90u;
            goto label_1a0b90;
        }
    }
    ctx->pc = 0x1A0B60u;
    // 0x1a0b60: 0x3c040024
    ctx->pc = 0x1a0b60u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x1a0b64: 0xc042c56
    ctx->pc = 0x1A0B64u;
    SET_GPR_U32(ctx, 31, 0x1A0B6Cu);
    ctx->pc = 0x1A0B68u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 7792));
    ctx->pc = 0x10B158u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A0B6Cu; }
    }
    if (ctx->pc != 0x1A0B6Cu) { return; }
    ctx->pc = 0x1A0B6Cu;
    // 0x1a0b6c: 0x3c040024
    ctx->pc = 0x1a0b6cu;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x1a0b70: 0x3c050024
    ctx->pc = 0x1a0b70u;
    SET_GPR_U32(ctx, 5, ((uint32_t)36 << 16));
    // 0x1a0b74: 0x40302d
    ctx->pc = 0x1a0b74u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a0b78: 0x24841e60
    ctx->pc = 0x1a0b78u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 7776));
    // 0x1a0b7c: 0xc063640
    ctx->pc = 0x1A0B7Cu;
    SET_GPR_U32(ctx, 31, 0x1A0B84u);
    ctx->pc = 0x1A0B80u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 7792));
    ctx->pc = 0x18D900u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018D900_0x18d900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A0B84u; }
    }
    if (ctx->pc != 0x1A0B84u) { return; }
    ctx->pc = 0x1A0B84u;
    // 0x1a0b84: 0x3c010023
    ctx->pc = 0x1a0b84u;
    SET_GPR_U32(ctx, 1, ((uint32_t)35 << 16));
    // 0x1a0b88: 0xac200fb0
    ctx->pc = 0x1a0b88u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4016), GPR_U32(ctx, 0));
    // 0x1a0b8c: 0x27a40010
    ctx->pc = 0x1a0b8cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 16));
label_1a0b90:
    // 0x1a0b90: 0xc042c56
    ctx->pc = 0x1A0B90u;
    SET_GPR_U32(ctx, 31, 0x1A0B98u);
    ctx->pc = 0x10B158u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A0B98u; }
    }
    if (ctx->pc != 0x1A0B98u) { return; }
    ctx->pc = 0x1A0B98u;
    // 0x1a0b98: 0x3c040024
    ctx->pc = 0x1a0b98u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x1a0b9c: 0x40302d
    ctx->pc = 0x1a0b9cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a0ba0: 0x24841e60
    ctx->pc = 0x1a0ba0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 7776));
    // 0x1a0ba4: 0xc063674
    ctx->pc = 0x1A0BA4u;
    SET_GPR_U32(ctx, 31, 0x1A0BACu);
    ctx->pc = 0x1A0BA8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x18D9D0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018D9D0_0x18d9d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A0BACu; }
    }
    if (ctx->pc != 0x1A0BACu) { return; }
    ctx->pc = 0x1A0BACu;
    // 0x1a0bac: 0xdfbf0000
    ctx->pc = 0x1a0bacu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a0bb0: 0x24020001
    ctx->pc = 0x1a0bb0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a0bb4: 0x3e00008
    ctx->pc = 0x1A0BB4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A0BB8u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 2144));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A0B0Cu: goto label_1a0b0c;
            case 0x1A0B18u: goto label_1a0b18;
            case 0x1A0B90u: goto label_1a0b90;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A0BBCu;
    // 0x1a0bbc: 0x0
    ctx->pc = 0x1a0bbcu;
    // NOP
}
