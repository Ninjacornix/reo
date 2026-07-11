#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00107D28
// Address: 0x107d28 - 0x107da8
void sub_00107D28_0x107d28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x107d28u;

    // 0x107d28: 0x27bdffe0
    ctx->pc = 0x107d28u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x107d2c: 0xffb00000
    ctx->pc = 0x107d2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x107d30: 0xffb10008
    ctx->pc = 0x107d30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x107d34: 0xffbf0010
    ctx->pc = 0x107d34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x107d38: 0xc045144
    ctx->pc = 0x107D38u;
    SET_GPR_U32(ctx, 31, 0x107D40u);
    ctx->pc = 0x114510u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114510_0x114510(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x107D40u; }
    }
    if (ctx->pc != 0x107D40u) { return; }
    ctx->pc = 0x107D40u;
    // 0x107d40: 0x3c030021
    ctx->pc = 0x107d40u;
    SET_GPR_U32(ctx, 3, ((uint32_t)33 << 16));
    // 0x107d44: 0x40802d
    ctx->pc = 0x107d44u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x107d48: 0x24719c58
    ctx->pc = 0x107d48u;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 3), 4294941784));
    // 0x107d4c: 0x3c020021
    ctx->pc = 0x107d4cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x107d50: 0x24449c5c
    ctx->pc = 0x107d50u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 4294941788));
    // 0x107d54: 0x8e220000
    ctx->pc = 0x107d54u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x107d58: 0x14500005
    ctx->pc = 0x107D58u;
    {
        const bool branch_taken_0x107d58 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 16));
        ctx->pc = 0x107D5Cu;
        SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
        if (branch_taken_0x107d58) {
            ctx->pc = 0x107D70u;
            goto label_107d70;
        }
    }
    ctx->pc = 0x107D60u;
    // 0x107d60: 0x8c820000
    ctx->pc = 0x107d60u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x107d64: 0x24420001
    ctx->pc = 0x107d64u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
    // 0x107d68: 0x10000009
    ctx->pc = 0x107D68u;
    {
        const bool branch_taken_0x107d68 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x107d68) {
            ctx->pc = 0x107D90u;
            goto label_107d90;
        }
    }
    ctx->pc = 0x107D70u;
label_107d70:
    // 0x107d70: 0xc045198
    ctx->pc = 0x107D70u;
    SET_GPR_U32(ctx, 31, 0x107D78u);
    ctx->pc = 0x107D74u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 4294943856)));
    ctx->pc = 0x114660u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x107D78u; }
    }
    if (ctx->pc != 0x107D78u) { return; }
    ctx->pc = 0x107D78u;
    // 0x107d78: 0x3c030021
    ctx->pc = 0x107d78u;
    SET_GPR_U32(ctx, 3, ((uint32_t)33 << 16));
    // 0x107d7c: 0xae300000
    ctx->pc = 0x107d7cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 16));
    // 0x107d80: 0x24639c5c
    ctx->pc = 0x107d80u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294941788));
    // 0x107d84: 0x8c620000
    ctx->pc = 0x107d84u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x107d88: 0x24420001
    ctx->pc = 0x107d88u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
    // 0x107d8c: 0xac620000
    ctx->pc = 0x107d8cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
label_107d90:
    // 0x107d90: 0xdfb00000
    ctx->pc = 0x107d90u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x107d94: 0xdfb10008
    ctx->pc = 0x107d94u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x107d98: 0xdfbf0010
    ctx->pc = 0x107d98u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x107d9c: 0x3e00008
    ctx->pc = 0x107D9Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x107DA0u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x107D70u: goto label_107d70;
            case 0x107D90u: goto label_107d90;
            default: break;
        }
        return;
    }
    ctx->pc = 0x107DA4u;
    // 0x107da4: 0x0
    ctx->pc = 0x107da4u;
    // NOP
}
