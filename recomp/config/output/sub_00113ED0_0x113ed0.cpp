#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00113ED0
// Address: 0x113ed0 - 0x113f38
void sub_00113ED0_0x113ed0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00113ED0_0x113ed0");
#endif

    switch (ctx->pc) {
        case 0x113ef8u: goto label_113ef8;
        default: break;
    }

    ctx->pc = 0x113ed0u;

    // 0x113ed0: 0x10800006  beqz        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x113ED0u;
    {
        const bool branch_taken_0x113ed0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x113ED4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113ED0u;
            // 0x113ed4: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x113ed0) {
            ctx->pc = 0x113EECu;
            goto label_113eec;
        }
    }
    ctx->pc = 0x113ED8u;
    // 0x113ed8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x113ed8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x113edc: 0x1082000f  beq         $a0, $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x113EDCu;
    {
        const bool branch_taken_0x113edc = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x113EE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113EDCu;
            // 0x113ee0: 0x60102d  daddu       $v0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x113edc) {
            ctx->pc = 0x113F1Cu;
            goto label_113f1c;
        }
    }
    ctx->pc = 0x113EE4u;
    // 0x113ee4: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x113EE4u;
    {
        const bool branch_taken_0x113ee4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x113ee4) {
            ctx->pc = 0x113F30u;
            goto label_113f30;
        }
    }
    ctx->pc = 0x113EECu;
label_113eec:
    // 0x113eec: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x113eecu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x113ef0: 0x34632010  ori         $v1, $v1, 0x2010
    ctx->pc = 0x113ef0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)8208);
    // 0x113ef4: 0x0  nop
    ctx->pc = 0x113ef4u;
    // NOP
label_113ef8:
    // 0x113ef8: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x113ef8u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x113efc: 0x0  nop
    ctx->pc = 0x113efcu;
    // NOP
    // 0x113f00: 0x0  nop
    ctx->pc = 0x113f00u;
    // NOP
    // 0x113f04: 0x0  nop
    ctx->pc = 0x113f04u;
    // NOP
    // 0x113f08: 0x0  nop
    ctx->pc = 0x113f08u;
    // NOP
    // 0x113f0c: 0x440fffa  bltz        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x113F0Cu;
    {
        const bool branch_taken_0x113f0c = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x113f0c) {
            ctx->pc = 0x113EF8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_113ef8;
        }
    }
    ctx->pc = 0x113F14u;
    // 0x113f14: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x113F14u;
    {
        const bool branch_taken_0x113f14 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x113F18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113F14u;
            // 0x113f18: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x113f14) {
            ctx->pc = 0x113F2Cu;
            goto label_113f2c;
        }
    }
    ctx->pc = 0x113F1Cu;
label_113f1c:
    // 0x113f1c: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x113f1cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x113f20: 0x34422010  ori         $v0, $v0, 0x2010
    ctx->pc = 0x113f20u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)8208);
    // 0x113f24: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x113f24u;
    SET_GPR_S32(ctx, 3, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x113f28: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x113f28u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
label_113f2c:
    // 0x113f2c: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x113f2cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
label_113f30:
    // 0x113f30: 0x3e00008  jr          $ra
    ctx->pc = 0x113F30u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x113EECu: goto label_113eec;
            case 0x113EF8u: goto label_113ef8;
            case 0x113F1Cu: goto label_113f1c;
            case 0x113F2Cu: goto label_113f2c;
            case 0x113F30u: goto label_113f30;
            default: break;
        }
        return;
    }
    ctx->pc = 0x113F38u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
