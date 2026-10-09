#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D7660
// Address: 0x1d7660 - 0x1d7690
void sub_001D7660_0x1d7660(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D7660_0x1d7660");
#endif

    switch (ctx->pc) {
        case 0x1d7670u: goto label_1d7670;
        default: break;
    }

    ctx->pc = 0x1d7660u;

    // 0x1d7660: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d7660u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d7664: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d7664u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d7668: 0xc076384  jal         func_1D8E10
    ctx->pc = 0x1D7668u;
    SET_GPR_U32(ctx, 31, 0x1D7670u);
    ctx->pc = 0x1D8E10u;
    if (runtime->hasFunction(0x1D8E10u)) {
        auto targetFn = runtime->lookupFunction(0x1D8E10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7670u; }
        if (ctx->pc != 0x1D7670u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D8E10_0x1d8e10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7670u; }
        if (ctx->pc != 0x1D7670u) { return; }
    }
    ctx->pc = 0x1D7670u;
label_1d7670:
    // 0x1d7670: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d7670u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d7674: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x1d7674u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d7678: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d7678u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1d767c: 0x3e00008  jr          $ra
    ctx->pc = 0x1D767Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D7680u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D767Cu;
            // 0x1d7680: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D7670u: goto label_1d7670;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D7684u;
    // 0x1d7684: 0x0  nop
    ctx->pc = 0x1d7684u;
    // NOP
    // 0x1d7688: 0x0  nop
    ctx->pc = 0x1d7688u;
    // NOP
    // 0x1d768c: 0x0  nop
    ctx->pc = 0x1d768cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
