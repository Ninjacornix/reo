#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DA450
// Address: 0x1da450 - 0x1da474
void sub_001DA450_0x1da450(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DA450_0x1da450");
#endif

    switch (ctx->pc) {
        case 0x1da460u: goto label_1da460;
        default: break;
    }

    ctx->pc = 0x1da450u;

    // 0x1da450: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1da450u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1da454: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1da454u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1da458: 0xc045534  jal         func_1154D0
    ctx->pc = 0x1DA458u;
    SET_GPR_U32(ctx, 31, 0x1DA460u);
    ctx->pc = 0x1DA45Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA458u;
            // 0x1da45c: 0x8cc40000  lw          $a0, 0x0($a2) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1154D0u;
    if (runtime->hasFunction(0x1154D0u)) {
        auto targetFn = runtime->lookupFunction(0x1154D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA460u; }
        if (ctx->pc != 0x1DA460u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001154D0_0x1154d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA460u; }
        if (ctx->pc != 0x1DA460u) { return; }
    }
    ctx->pc = 0x1DA460u;
label_1da460:
    // 0x1da460: 0xf  sync
    ctx->pc = 0x1da460u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x1da464: 0x42000038  ei
    ctx->pc = 0x1da464u;
    ctx->cop0_status |= 0x10000; // Enable interrupts
    // 0x1da468: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1da468u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1da46c: 0x3e00008  jr          $ra
    ctx->pc = 0x1DA46Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1DA470u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA46Cu;
            // 0x1da470: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1DA460u: goto label_1da460;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DA474u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
