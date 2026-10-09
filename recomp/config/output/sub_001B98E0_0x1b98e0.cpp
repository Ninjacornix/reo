#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B98E0
// Address: 0x1b98e0 - 0x1b9938
void sub_001B98E0_0x1b98e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B98E0_0x1b98e0");
#endif

    switch (ctx->pc) {
        case 0x1b98fcu: goto label_1b98fc;
        case 0x1b9914u: goto label_1b9914;
        default: break;
    }

    ctx->pc = 0x1b98e0u;

    // 0x1b98e0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1b98e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1b98e4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1b98e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1b98e8: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b98e8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b98ec: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b98ecu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b98f0: 0x3c11003c  lui         $s1, 0x3C
    ctx->pc = 0x1b98f0u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)60 << 16));
    // 0x1b98f4: 0x26312750  addiu       $s1, $s1, 0x2750
    ctx->pc = 0x1b98f4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 10064));
    // 0x1b98f8: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1b98f8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1b98fc:
    // 0x1b98fc: 0x82230000  lb          $v1, 0x0($s1)
    ctx->pc = 0x1b98fcu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1b9900: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B9900u;
    {
        const bool branch_taken_0x1b9900 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b9900) {
            ctx->pc = 0x1B9914u;
            goto label_1b9914;
        }
    }
    ctx->pc = 0x1B9908u;
    // 0x1b9908: 0x8e220028  lw          $v0, 0x28($s1)
    ctx->pc = 0x1b9908u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 40)));
    // 0x1b990c: 0x40f809  jalr        $v0
    ctx->pc = 0x1B990Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1B9914u);
        ctx->pc = 0x1B9910u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B990Cu;
            // 0x1b9910: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1B9914u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B98FCu: goto label_1b98fc;
            case 0x1B9914u: goto label_1b9914;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1B9914u; }
            if (ctx->pc != 0x1B9914u) { return; }
        }
        }
    }
    ctx->pc = 0x1B9914u;
label_1b9914:
    // 0x1b9914: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1b9914u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1b9918: 0x2a030004  slti        $v1, $s0, 0x4
    ctx->pc = 0x1b9918u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x1b991c: 0x1460fff7  bnez        $v1, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1B991Cu;
    {
        const bool branch_taken_0x1b991c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B9920u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B991Cu;
            // 0x1b9920: 0x2631003c  addiu       $s1, $s1, 0x3C (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 60));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b991c) {
            ctx->pc = 0x1B98FCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b98fc;
        }
    }
    ctx->pc = 0x1B9924u;
    // 0x1b9924: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1b9924u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b9928: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b9928u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b992c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b992cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b9930: 0x3e00008  jr          $ra
    ctx->pc = 0x1B9930u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B9934u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9930u;
            // 0x1b9934: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B98FCu: goto label_1b98fc;
            case 0x1B9914u: goto label_1b9914;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B9938u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
