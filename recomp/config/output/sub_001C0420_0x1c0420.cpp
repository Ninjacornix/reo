#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C0420
// Address: 0x1c0420 - 0x1c0450
void sub_001C0420_0x1c0420(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C0420_0x1c0420");
#endif

    switch (ctx->pc) {
        case 0x1c0440u: goto label_1c0440;
        default: break;
    }

    ctx->pc = 0x1c0420u;

    // 0x1c0420: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1c0420u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1c0424: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1c0424u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1c0428: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1c0428u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1c042c: 0x8c840024  lw          $a0, 0x24($a0)
    ctx->pc = 0x1c042cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 36)));
    // 0x1c0430: 0x10830003  beq         $a0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C0430u;
    {
        const bool branch_taken_0x1c0430 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c0430) {
            ctx->pc = 0x1C0440u;
            goto label_1c0440;
        }
    }
    ctx->pc = 0x1C0438u;
    // 0x1c0438: 0xc0700fc  jal         func_1C03F0
    ctx->pc = 0x1C0438u;
    SET_GPR_U32(ctx, 31, 0x1C0440u);
    ctx->pc = 0x1C03F0u;
    if (runtime->hasFunction(0x1C03F0u)) {
        auto targetFn = runtime->lookupFunction(0x1C03F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0440u; }
        if (ctx->pc != 0x1C0440u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C03F0_0x1c03f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0440u; }
        if (ctx->pc != 0x1C0440u) { return; }
    }
    ctx->pc = 0x1C0440u;
label_1c0440:
    // 0x1c0440: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1c0440u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c0444: 0x3e00008  jr          $ra
    ctx->pc = 0x1C0444u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C0448u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0444u;
            // 0x1c0448: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C0440u: goto label_1c0440;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C044Cu;
    // 0x1c044c: 0x0  nop
    ctx->pc = 0x1c044cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
