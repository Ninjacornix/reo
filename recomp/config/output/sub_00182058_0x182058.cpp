#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00182058
// Address: 0x182058 - 0x182094
void sub_00182058_0x182058(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00182058_0x182058");
#endif

    switch (ctx->pc) {
        case 0x182068u: goto label_182068;
        case 0x182084u: goto label_182084;
        default: break;
    }

    ctx->pc = 0x182058u;

    // 0x182058: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x182058u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x18205c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x18205cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x182060: 0xc0605c2  jal         func_181708
    ctx->pc = 0x182060u;
    SET_GPR_U32(ctx, 31, 0x182068u);
    ctx->pc = 0x181708u;
    if (runtime->hasFunction(0x181708u)) {
        auto targetFn = runtime->lookupFunction(0x181708u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182068u; }
        if (ctx->pc != 0x182068u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181708_0x181708(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182068u; }
        if (ctx->pc != 0x182068u) { return; }
    }
    ctx->pc = 0x182068u;
label_182068:
    // 0x182068: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x182068u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18206c: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x18206cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x182070: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x182070u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182074: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x182074u;
    {
        const bool branch_taken_0x182074 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x182078u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182074u;
            // 0x182078: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182074) {
            ctx->pc = 0x182088u;
            goto label_182088;
        }
    }
    ctx->pc = 0x18207Cu;
    // 0x18207c: 0xc06074a  jal         func_181D28
    ctx->pc = 0x18207Cu;
    SET_GPR_U32(ctx, 31, 0x182084u);
    ctx->pc = 0x181D28u;
    if (runtime->hasFunction(0x181D28u)) {
        auto targetFn = runtime->lookupFunction(0x181D28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182084u; }
        if (ctx->pc != 0x182084u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181D28_0x181d28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182084u; }
        if (ctx->pc != 0x182084u) { return; }
    }
    ctx->pc = 0x182084u;
label_182084:
    // 0x182084: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x182084u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_182088:
    // 0x182088: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x182088u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18208c: 0x3e00008  jr          $ra
    ctx->pc = 0x18208Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x182090u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18208Cu;
            // 0x182090: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x182068u: goto label_182068;
            case 0x182084u: goto label_182084;
            case 0x182088u: goto label_182088;
            default: break;
        }
        return;
    }
    ctx->pc = 0x182094u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
