#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B8140
// Address: 0x1b8140 - 0x1b8170
void sub_001B8140_0x1b8140(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B8140_0x1b8140");
#endif

    switch (ctx->pc) {
        case 0x1b8158u: goto label_1b8158;
        case 0x1b8164u: goto label_1b8164;
        default: break;
    }

    ctx->pc = 0x1b8140u;

    // 0x1b8140: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b8140u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b8144: 0x3c040058  lui         $a0, 0x58
    ctx->pc = 0x1b8144u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)88 << 16));
    // 0x1b8148: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b8148u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b814c: 0x2484f1f0  addiu       $a0, $a0, -0xE10
    ctx->pc = 0x1b814cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294963696));
    // 0x1b8150: 0xc06dfd0  jal         func_1B7F40
    ctx->pc = 0x1B8150u;
    SET_GPR_U32(ctx, 31, 0x1B8158u);
    ctx->pc = 0x1B8154u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8150u;
            // 0x1b8154: 0x24050004  addiu       $a1, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B7F40u;
    if (runtime->hasFunction(0x1B7F40u)) {
        auto targetFn = runtime->lookupFunction(0x1B7F40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8158u; }
        if (ctx->pc != 0x1B8158u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B7F40_0x1b7f40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8158u; }
        if (ctx->pc != 0x1B8158u) { return; }
    }
    ctx->pc = 0x1B8158u;
label_1b8158:
    // 0x1b8158: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1b8158u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b815c: 0xc06e034  jal         func_1B80D0
    ctx->pc = 0x1B815Cu;
    SET_GPR_U32(ctx, 31, 0x1B8164u);
    ctx->pc = 0x1B8160u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B815Cu;
            // 0x1b8160: 0x2405ffff  addiu       $a1, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B80D0u;
    if (runtime->hasFunction(0x1B80D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B80D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8164u; }
        if (ctx->pc != 0x1B8164u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B80D0_0x1b80d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8164u; }
        if (ctx->pc != 0x1B8164u) { return; }
    }
    ctx->pc = 0x1B8164u;
label_1b8164:
    // 0x1b8164: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b8164u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b8168: 0x3e00008  jr          $ra
    ctx->pc = 0x1B8168u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B816Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8168u;
            // 0x1b816c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B8158u: goto label_1b8158;
            case 0x1B8164u: goto label_1b8164;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B8170u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
