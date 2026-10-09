#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019EED0
// Address: 0x19eed0 - 0x19ef00
void sub_0019EED0_0x19eed0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019EED0_0x19eed0");
#endif

    switch (ctx->pc) {
        case 0x19eee0u: goto label_19eee0;
        case 0x19eef0u: goto label_19eef0;
        default: break;
    }

    ctx->pc = 0x19eed0u;

    // 0x19eed0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x19eed0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x19eed4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x19eed4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x19eed8: 0xc067b14  jal         func_19EC50
    ctx->pc = 0x19EED8u;
    SET_GPR_U32(ctx, 31, 0x19EEE0u);
    ctx->pc = 0x19EC50u;
    if (runtime->hasFunction(0x19EC50u)) {
        auto targetFn = runtime->lookupFunction(0x19EC50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19EEE0u; }
        if (ctx->pc != 0x19EEE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019EC50_0x19ec50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19EEE0u; }
        if (ctx->pc != 0x19EEE0u) { return; }
    }
    ctx->pc = 0x19EEE0u;
label_19eee0:
    // 0x19eee0: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x19EEE0u;
    {
        const bool branch_taken_0x19eee0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x19EEE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19EEE0u;
            // 0x19eee4: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19eee0) {
            ctx->pc = 0x19EEF0u;
            goto label_19eef0;
        }
    }
    ctx->pc = 0x19EEE8u;
    // 0x19eee8: 0xc067adc  jal         func_19EB70
    ctx->pc = 0x19EEE8u;
    SET_GPR_U32(ctx, 31, 0x19EEF0u);
    ctx->pc = 0x19EB70u;
    if (runtime->hasFunction(0x19EB70u)) {
        auto targetFn = runtime->lookupFunction(0x19EB70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19EEF0u; }
        if (ctx->pc != 0x19EEF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019EB70_0x19eb70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19EEF0u; }
        if (ctx->pc != 0x19EEF0u) { return; }
    }
    ctx->pc = 0x19EEF0u;
label_19eef0:
    // 0x19eef0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x19eef0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19eef4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x19eef4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19eef8: 0x3e00008  jr          $ra
    ctx->pc = 0x19EEF8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19EEFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19EEF8u;
            // 0x19eefc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19EEE0u: goto label_19eee0;
            case 0x19EEF0u: goto label_19eef0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19EF00u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
