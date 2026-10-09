#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A2B30
// Address: 0x1a2b30 - 0x1a2b60
void sub_001A2B30_0x1a2b30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A2B30_0x1a2b30");
#endif

    switch (ctx->pc) {
        case 0x1a2b40u: goto label_1a2b40;
        default: break;
    }

    ctx->pc = 0x1a2b30u;

    // 0x1a2b30: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a2b30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a2b34: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a2b34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a2b38: 0xc068b24  jal         func_1A2C90
    ctx->pc = 0x1A2B38u;
    SET_GPR_U32(ctx, 31, 0x1A2B40u);
    ctx->pc = 0x1A2B3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2B38u;
            // 0x1a2b3c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A2C90u;
    if (runtime->hasFunction(0x1A2C90u)) {
        auto targetFn = runtime->lookupFunction(0x1A2C90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2B40u; }
        if (ctx->pc != 0x1A2B40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A2C90_0x1a2c90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2B40u; }
        if (ctx->pc != 0x1A2B40u) { return; }
    }
    ctx->pc = 0x1A2B40u;
label_1a2b40:
    // 0x1a2b40: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A2B40u;
    {
        const bool branch_taken_0x1a2b40 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a2b40) {
            ctx->pc = 0x1A2B50u;
            goto label_1a2b50;
        }
    }
    ctx->pc = 0x1A2B48u;
    // 0x1a2b48: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1A2B48u;
    {
        const bool branch_taken_0x1a2b48 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A2B4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2B48u;
            // 0x1a2b4c: 0x8c420004  lw          $v0, 0x4($v0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a2b48) {
            ctx->pc = 0x1A2B54u;
            goto label_1a2b54;
        }
    }
    ctx->pc = 0x1A2B50u;
label_1a2b50:
    // 0x1a2b50: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1a2b50u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1a2b54:
    // 0x1a2b54: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a2b54u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a2b58: 0x3e00008  jr          $ra
    ctx->pc = 0x1A2B58u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A2B5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2B58u;
            // 0x1a2b5c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A2B40u: goto label_1a2b40;
            case 0x1A2B50u: goto label_1a2b50;
            case 0x1A2B54u: goto label_1a2b54;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A2B60u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
