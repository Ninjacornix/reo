#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00116BA0
// Address: 0x116ba0 - 0x116c08
void sub_00116BA0_0x116ba0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x116ba0u;

    // 0x116ba0: 0x27bdfff0
    ctx->pc = 0x116ba0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x116ba4: 0xffbf0000
    ctx->pc = 0x116ba4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x116ba8: 0xc045474
    ctx->pc = 0x116BA8u;
    SET_GPR_U32(ctx, 31, 0x116BB0u);
    ctx->pc = 0x116BACu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 5));
    ctx->pc = 0x1151D0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001151D0_0x1151d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116BB0u; }
    }
    if (ctx->pc != 0x116BB0u) { return; }
    ctx->pc = 0x116BB0u;
    // 0x116bb0: 0x3c030026
    ctx->pc = 0x116bb0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)38 << 16));
    // 0x116bb4: 0x24040005
    ctx->pc = 0x116bb4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 5));
    // 0x116bb8: 0xc0450d4
    ctx->pc = 0x116BB8u;
    SET_GPR_U32(ctx, 31, 0x116BC0u);
    ctx->pc = 0x116BBCu;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 3), 4294946708)));
    ctx->pc = 0x114350u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114350_0x114350(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116BC0u; }
    }
    if (ctx->pc != 0x116BC0u) { return; }
    ctx->pc = 0x116BC0u;
    // 0x116bc0: 0x3c030021
    ctx->pc = 0x116bc0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)33 << 16));
    // 0x116bc4: 0xdfbf0000
    ctx->pc = 0x116bc4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x116bc8: 0xac609d48
    ctx->pc = 0x116bc8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294942024), GPR_U32(ctx, 0));
    // 0x116bcc: 0x3e00008
    ctx->pc = 0x116BCCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x116BD0u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x116BD4u;
    // 0x116bd4: 0x0
    ctx->pc = 0x116bd4u;
    // NOP
    // 0x116bd8: 0x3c030026
    ctx->pc = 0x116bd8u;
    SET_GPR_U32(ctx, 3, ((uint32_t)38 << 16));
    // 0x116bdc: 0x2463af98
    ctx->pc = 0x116bdcu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294946712));
    // 0x116be0: 0x8c620014
    ctx->pc = 0x116be0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 20)));
    // 0x116be4: 0xac650018
    ctx->pc = 0x116be4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 24), GPR_U32(ctx, 5));
    // 0x116be8: 0x3e00008
    ctx->pc = 0x116BE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x116BECu;
        WRITE32(ADD32(GPR_U32(ctx, 3), 20), GPR_U32(ctx, 4));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x116BF0u;
    // 0x116bf0: 0x3c030026
    ctx->pc = 0x116bf0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)38 << 16));
    // 0x116bf4: 0x2463af98
    ctx->pc = 0x116bf4u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294946712));
    // 0x116bf8: 0x8c62000c
    ctx->pc = 0x116bf8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 12)));
    // 0x116bfc: 0xac650010
    ctx->pc = 0x116bfcu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 16), GPR_U32(ctx, 5));
    // 0x116c00: 0x3e00008
    ctx->pc = 0x116C00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x116C04u;
        WRITE32(ADD32(GPR_U32(ctx, 3), 12), GPR_U32(ctx, 4));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x116C08u;
}
