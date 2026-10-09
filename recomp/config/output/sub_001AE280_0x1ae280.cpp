#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AE280
// Address: 0x1ae280 - 0x1ae2d4
void sub_001AE280_0x1ae280(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AE280_0x1ae280");
#endif

    switch (ctx->pc) {
        case 0x1ae290u: goto label_1ae290;
        case 0x1ae2b4u: goto label_1ae2b4;
        default: break;
    }

    ctx->pc = 0x1ae280u;

    // 0x1ae280: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1ae280u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1ae284: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1ae284u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1ae288: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1ae288u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1ae28c: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1ae28cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1ae290:
    // 0x1ae290: 0x3c03002c  lui         $v1, 0x2C
    ctx->pc = 0x1ae290u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)44 << 16));
    // 0x1ae294: 0x102080  sll         $a0, $s0, 2
    ctx->pc = 0x1ae294u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1ae298: 0x24638dc8  addiu       $v1, $v1, -0x7238
    ctx->pc = 0x1ae298u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294938056));
    // 0x1ae29c: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1ae29cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1ae2a0: 0x8c640000  lw          $a0, 0x0($v1)
    ctx->pc = 0x1ae2a0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1ae2a4: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AE2A4u;
    {
        const bool branch_taken_0x1ae2a4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AE2A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE2A4u;
            // 0x1ae2a8: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ae2a4) {
            ctx->pc = 0x1AE2B4u;
            goto label_1ae2b4;
        }
    }
    ctx->pc = 0x1AE2ACu;
    // 0x1ae2ac: 0xc04cb94  jal         func_132E50
    ctx->pc = 0x1AE2ACu;
    SET_GPR_U32(ctx, 31, 0x1AE2B4u);
    ctx->pc = 0x132E50u;
    if (runtime->hasFunction(0x132E50u)) {
        auto targetFn = runtime->lookupFunction(0x132E50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE2B4u; }
        if (ctx->pc != 0x1AE2B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00132E50_0x132e50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE2B4u; }
        if (ctx->pc != 0x1AE2B4u) { return; }
    }
    ctx->pc = 0x1AE2B4u;
label_1ae2b4:
    // 0x1ae2b4: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1ae2b4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1ae2b8: 0x2a030003  slti        $v1, $s0, 0x3
    ctx->pc = 0x1ae2b8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x1ae2bc: 0x1460fff4  bnez        $v1, . + 4 + (-0xC << 2)
    ctx->pc = 0x1AE2BCu;
    {
        const bool branch_taken_0x1ae2bc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1ae2bc) {
            ctx->pc = 0x1AE290u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1ae290;
        }
    }
    ctx->pc = 0x1AE2C4u;
    // 0x1ae2c4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1ae2c4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ae2c8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ae2c8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ae2cc: 0x3e00008  jr          $ra
    ctx->pc = 0x1AE2CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AE2D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE2CCu;
            // 0x1ae2d0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AE290u: goto label_1ae290;
            case 0x1AE2B4u: goto label_1ae2b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AE2D4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
