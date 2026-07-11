#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00114AB0
// Address: 0x114ab0 - 0x114b40
void sub_00114AB0_0x114ab0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x114ab0u;

    // 0x114ab0: 0x27bdfff0
    ctx->pc = 0x114ab0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x114ab4: 0xffbf0000
    ctx->pc = 0x114ab4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x114ab8: 0xc047598
    ctx->pc = 0x114AB8u;
    SET_GPR_U32(ctx, 31, 0x114AC0u);
    ctx->pc = 0x11D660u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x114AC0u; }
    }
    if (ctx->pc != 0x114AC0u) { return; }
    ctx->pc = 0x114AC0u;
    // 0x114ac0: 0x3c031000
    ctx->pc = 0x114ac0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x114ac4: 0x24040004
    ctx->pc = 0x114ac4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 4));
    // 0x114ac8: 0x3463f000
    ctx->pc = 0x114ac8u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 61440));
    // 0x114acc: 0xac640000
    ctx->pc = 0x114accu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4)); // MMIO: 0x10000000
    // 0x114ad0: 0xf
    ctx->pc = 0x114ad0u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x114ad4: 0x10400004
    ctx->pc = 0x114AD4u;
    {
        const bool branch_taken_0x114ad4 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x114AD8u;
        SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
        if (branch_taken_0x114ad4) {
            ctx->pc = 0x114AE8u;
            goto label_114ae8;
        }
    }
    ctx->pc = 0x114ADCu;
    // 0x114adc: 0xc0475ae
    ctx->pc = 0x114ADCu;
    SET_GPR_U32(ctx, 31, 0x114AE4u);
    ctx->pc = 0x11D6B8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x114AE4u; }
    }
    if (ctx->pc != 0x114AE4u) { return; }
    ctx->pc = 0x114AE4u;
    // 0x114ae4: 0x3c031000
    ctx->pc = 0x114ae4u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
label_114ae8:
    // 0x114ae8: 0x3463f000
    ctx->pc = 0x114ae8u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 61440));
    // 0x114aec: 0x0
    ctx->pc = 0x114aecu;
    // NOP
label_114af0:
    // 0x114af0: 0x8c620000
    ctx->pc = 0x114af0u;
    SET_GPR_U32(ctx, 2, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x114af4: 0x30420004
    ctx->pc = 0x114af4u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 4));
    // 0x114af8: 0x0
    ctx->pc = 0x114af8u;
    // NOP
    // 0x114afc: 0x0
    ctx->pc = 0x114afcu;
    // NOP
    // 0x114b00: 0x0
    ctx->pc = 0x114b00u;
    // NOP
    // 0x114b04: 0x1040fffa
    ctx->pc = 0x114B04u;
    {
        const bool branch_taken_0x114b04 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x114b04) {
            ctx->pc = 0x114AF0u;
            goto label_114af0;
        }
    }
    ctx->pc = 0x114B0Cu;
    // 0x114b0c: 0xc047598
    ctx->pc = 0x114B0Cu;
    SET_GPR_U32(ctx, 31, 0x114B14u);
    ctx->pc = 0x11D660u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x114B14u; }
    }
    if (ctx->pc != 0x114B14u) { return; }
    ctx->pc = 0x114B14u;
    // 0x114b14: 0x3c031000
    ctx->pc = 0x114b14u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x114b18: 0x24040004
    ctx->pc = 0x114b18u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 4));
    // 0x114b1c: 0x3463f000
    ctx->pc = 0x114b1cu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 61440));
    // 0x114b20: 0xac640000
    ctx->pc = 0x114b20u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4)); // MMIO: 0x10000000
    // 0x114b24: 0xf
    ctx->pc = 0x114b24u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x114b28: 0x10400003
    ctx->pc = 0x114B28u;
    {
        const bool branch_taken_0x114b28 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x114B2Cu;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        if (branch_taken_0x114b28) {
            ctx->pc = 0x114B38u;
            goto label_114b38;
        }
    }
    ctx->pc = 0x114B30u;
    // 0x114b30: 0x80475ae
    ctx->pc = 0x114B30u;
    ctx->pc = 0x114B34u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x11D6B8u;
    sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    ctx->pc = 0x114B38u;
label_114b38:
    // 0x114b38: 0x3e00008
    ctx->pc = 0x114B38u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x114B3Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x114AE8u: goto label_114ae8;
            case 0x114AF0u: goto label_114af0;
            case 0x114B38u: goto label_114b38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x114B40u;
}
