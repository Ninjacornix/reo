#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C6740
// Address: 0x1c6740 - 0x1c6760
void sub_001C6740_0x1c6740(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C6740_0x1c6740");
#endif

    switch (ctx->pc) {
        case 0x1c6754u: goto label_1c6754;
        default: break;
    }

    ctx->pc = 0x1c6740u;

    // 0x1c6740: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1c6740u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1c6744: 0x10a00003  beqz        $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C6744u;
    {
        const bool branch_taken_0x1c6744 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C6748u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6744u;
            // 0x1c6748: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c6744) {
            ctx->pc = 0x1C6754u;
            goto label_1c6754;
        }
    }
    ctx->pc = 0x1C674Cu;
    // 0x1c674c: 0xc07220c  jal         func_1C8830
    ctx->pc = 0x1C674Cu;
    SET_GPR_U32(ctx, 31, 0x1C6754u);
    ctx->pc = 0x1C6750u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C674Cu;
            // 0x1c6750: 0x24840028  addiu       $a0, $a0, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 40));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8830u;
    if (runtime->hasFunction(0x1C8830u)) {
        auto targetFn = runtime->lookupFunction(0x1C8830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6754u; }
        if (ctx->pc != 0x1C6754u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8830_0x1c8830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6754u; }
        if (ctx->pc != 0x1C6754u) { return; }
    }
    ctx->pc = 0x1C6754u;
label_1c6754:
    // 0x1c6754: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1c6754u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c6758: 0x3e00008  jr          $ra
    ctx->pc = 0x1C6758u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C675Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6758u;
            // 0x1c675c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C6754u: goto label_1c6754;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C6760u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
