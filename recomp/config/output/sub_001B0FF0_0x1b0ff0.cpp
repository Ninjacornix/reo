#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B0FF0
// Address: 0x1b0ff0 - 0x1b1040
void sub_001B0FF0_0x1b0ff0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B0FF0_0x1b0ff0");
#endif

    switch (ctx->pc) {
        case 0x1b1004u: goto label_1b1004;
        default: break;
    }

    ctx->pc = 0x1b0ff0u;

    // 0x1b0ff0: 0x3c070057  lui         $a3, 0x57
    ctx->pc = 0x1b0ff0u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)87 << 16));
    // 0x1b0ff4: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1b0ff4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b0ff8: 0x24e798d0  addiu       $a3, $a3, -0x6730
    ctx->pc = 0x1b0ff8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294940880));
    // 0x1b0ffc: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1B0FFCu;
    {
        const bool branch_taken_0x1b0ffc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B1000u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0FFCu;
            // 0x1b1000: 0x2405ffff  addiu       $a1, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0ffc) {
            ctx->pc = 0x1B1020u;
            goto label_1b1020;
        }
    }
    ctx->pc = 0x1B1004u;
label_1b1004:
    // 0x1b1004: 0x8ce30000  lw          $v1, 0x0($a3)
    ctx->pc = 0x1b1004u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1b1008: 0x14650003  bne         $v1, $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B1008u;
    {
        const bool branch_taken_0x1b1008 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 5));
        if (branch_taken_0x1b1008) {
            ctx->pc = 0x1B1018u;
            goto label_1b1018;
        }
    }
    ctx->pc = 0x1B1010u;
    // 0x1b1010: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1B1010u;
    {
        const bool branch_taken_0x1b1010 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B1014u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1010u;
            // 0x1b1014: 0xace40000  sw          $a0, 0x0($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b1010) {
            ctx->pc = 0x1B102Cu;
            goto label_1b102c;
        }
    }
    ctx->pc = 0x1B1018u;
label_1b1018:
    // 0x1b1018: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1b1018u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1b101c: 0x24e70004  addiu       $a3, $a3, 0x4
    ctx->pc = 0x1b101cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4));
label_1b1020:
    // 0x1b1020: 0x28c302bc  slti        $v1, $a2, 0x2BC
    ctx->pc = 0x1b1020u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)700) ? 1 : 0);
    // 0x1b1024: 0x1460fff7  bnez        $v1, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1B1024u;
    {
        const bool branch_taken_0x1b1024 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b1024) {
            ctx->pc = 0x1B1004u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b1004;
        }
    }
    ctx->pc = 0x1B102Cu;
label_1b102c:
    // 0x1b102c: 0x3e00008  jr          $ra
    ctx->pc = 0x1B102Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B1004u: goto label_1b1004;
            case 0x1B1018u: goto label_1b1018;
            case 0x1B1020u: goto label_1b1020;
            case 0x1B102Cu: goto label_1b102c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B1034u;
    // 0x1b1034: 0x0  nop
    ctx->pc = 0x1b1034u;
    // NOP
    // 0x1b1038: 0x0  nop
    ctx->pc = 0x1b1038u;
    // NOP
    // 0x1b103c: 0x0  nop
    ctx->pc = 0x1b103cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
