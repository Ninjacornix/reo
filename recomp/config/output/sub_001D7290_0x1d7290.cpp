#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D7290
// Address: 0x1d7290 - 0x1d72c0
void sub_001D7290_0x1d7290(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D7290_0x1d7290");
#endif

    switch (ctx->pc) {
        case 0x1d72a0u: goto label_1d72a0;
        default: break;
    }

    ctx->pc = 0x1d7290u;

    // 0x1d7290: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d7290u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d7294: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d7294u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d7298: 0xc0761f4  jal         func_1D87D0
    ctx->pc = 0x1D7298u;
    SET_GPR_U32(ctx, 31, 0x1D72A0u);
    ctx->pc = 0x1D87D0u;
    if (runtime->hasFunction(0x1D87D0u)) {
        auto targetFn = runtime->lookupFunction(0x1D87D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D72A0u; }
        if (ctx->pc != 0x1D72A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D87D0_0x1d87d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D72A0u; }
        if (ctx->pc != 0x1D72A0u) { return; }
    }
    ctx->pc = 0x1D72A0u;
label_1d72a0:
    // 0x1d72a0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d72a0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d72a4: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x1d72a4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d72a8: 0xa0204601  sb          $zero, 0x4601($at)
    ctx->pc = 0x1d72a8u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17921), (uint8_t)GPR_U32(ctx, 0));
    // 0x1d72ac: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d72acu;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1d72b0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d72b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d72b4: 0x3e00008  jr          $ra
    ctx->pc = 0x1D72B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D72B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D72B4u;
            // 0x1d72b8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D72A0u: goto label_1d72a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D72BCu;
    // 0x1d72bc: 0x0  nop
    ctx->pc = 0x1d72bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
