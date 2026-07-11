#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00114B40
// Address: 0x114b40 - 0x114be8
void sub_00114B40_0x114b40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x114b40u;

    // 0x114b40: 0x27bdffe0
    ctx->pc = 0x114b40u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x114b44: 0xffbf0010
    ctx->pc = 0x114b44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x114b48: 0x3a0202d
    ctx->pc = 0x114b48u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x114b4c: 0xafa00000
    ctx->pc = 0x114b4cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x114b50: 0xc045264
    ctx->pc = 0x114B50u;
    SET_GPR_U32(ctx, 31, 0x114B58u);
    ctx->pc = 0x114B54u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 29), 8));
    ctx->pc = 0x114990u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114990_0x114990(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x114B58u; }
    }
    if (ctx->pc != 0x114B58u) { return; }
    ctx->pc = 0x114B58u;
    // 0x114b58: 0xc047598
    ctx->pc = 0x114B58u;
    SET_GPR_U32(ctx, 31, 0x114B60u);
    ctx->pc = 0x11D660u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x114B60u; }
    }
    if (ctx->pc != 0x114B60u) { return; }
    ctx->pc = 0x114B60u;
    // 0x114b60: 0x3c031000
    ctx->pc = 0x114b60u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x114b64: 0x24040004
    ctx->pc = 0x114b64u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 4));
    // 0x114b68: 0x3463f000
    ctx->pc = 0x114b68u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 61440));
    // 0x114b6c: 0xac640000
    ctx->pc = 0x114b6cu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4)); // MMIO: 0x10000000
    // 0x114b70: 0xf
    ctx->pc = 0x114b70u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x114b74: 0x10400004
    ctx->pc = 0x114B74u;
    {
        const bool branch_taken_0x114b74 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x114B78u;
        SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
        if (branch_taken_0x114b74) {
            ctx->pc = 0x114B88u;
            goto label_114b88;
        }
    }
    ctx->pc = 0x114B7Cu;
    // 0x114b7c: 0xc0475ae
    ctx->pc = 0x114B7Cu;
    SET_GPR_U32(ctx, 31, 0x114B84u);
    ctx->pc = 0x11D6B8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x114B84u; }
    }
    if (ctx->pc != 0x114B84u) { return; }
    ctx->pc = 0x114B84u;
    // 0x114b84: 0x3c031000
    ctx->pc = 0x114b84u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
label_114b88:
    // 0x114b88: 0x3463f000
    ctx->pc = 0x114b88u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 61440));
    // 0x114b8c: 0x0
    ctx->pc = 0x114b8cu;
    // NOP
label_114b90:
    // 0x114b90: 0x8c620000
    ctx->pc = 0x114b90u;
    SET_GPR_U32(ctx, 2, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x114b94: 0x30420004
    ctx->pc = 0x114b94u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 4));
    // 0x114b98: 0x14400004
    ctx->pc = 0x114B98u;
    {
        const bool branch_taken_0x114b98 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x114b98) {
            ctx->pc = 0x114BACu;
            goto label_114bac;
        }
    }
    ctx->pc = 0x114BA0u;
    // 0x114ba0: 0x8fa20000
    ctx->pc = 0x114ba0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x114ba4: 0x1040fffa
    ctx->pc = 0x114BA4u;
    {
        const bool branch_taken_0x114ba4 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x114ba4) {
            ctx->pc = 0x114B90u;
            goto label_114b90;
        }
    }
    ctx->pc = 0x114BACu;
label_114bac:
    // 0x114bac: 0xc047598
    ctx->pc = 0x114BACu;
    SET_GPR_U32(ctx, 31, 0x114BB4u);
    ctx->pc = 0x11D660u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x114BB4u; }
    }
    if (ctx->pc != 0x114BB4u) { return; }
    ctx->pc = 0x114BB4u;
    // 0x114bb4: 0x24030004
    ctx->pc = 0x114bb4u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 4));
    // 0x114bb8: 0x3c011001
    ctx->pc = 0x114bb8u;
    SET_GPR_U32(ctx, 1, ((uint32_t)4097 << 16));
    // 0x114bbc: 0xac23f000
    ctx->pc = 0x114bbcu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 4294963200), GPR_U32(ctx, 3)); // MMIO: 0x1000f000
    // 0x114bc0: 0xf
    ctx->pc = 0x114bc0u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x114bc4: 0x10400003
    ctx->pc = 0x114BC4u;
    {
        const bool branch_taken_0x114bc4 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x114bc4) {
            ctx->pc = 0x114BD4u;
            goto label_114bd4;
        }
    }
    ctx->pc = 0x114BCCu;
    // 0x114bcc: 0xc0475ae
    ctx->pc = 0x114BCCu;
    SET_GPR_U32(ctx, 31, 0x114BD4u);
    ctx->pc = 0x11D6B8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x114BD4u; }
    }
    if (ctx->pc != 0x114BD4u) { return; }
    ctx->pc = 0x114BD4u;
label_114bd4:
    // 0x114bd4: 0xdfa20008
    ctx->pc = 0x114bd4u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x114bd8: 0xdfbf0010
    ctx->pc = 0x114bd8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x114bdc: 0x3e00008
    ctx->pc = 0x114BDCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x114BE0u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x114B88u: goto label_114b88;
            case 0x114B90u: goto label_114b90;
            case 0x114BACu: goto label_114bac;
            case 0x114BD4u: goto label_114bd4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x114BE4u;
    // 0x114be4: 0x0
    ctx->pc = 0x114be4u;
    // NOP
}
