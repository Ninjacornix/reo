#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00187520
// Address: 0x187520 - 0x187578
void sub_00187520_0x187520(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00187520_0x187520");
#endif

    switch (ctx->pc) {
        case 0x187548u: goto label_187548;
        default: break;
    }

    ctx->pc = 0x187520u;

    // 0x187520: 0x41040  sll         $v0, $a0, 1
    ctx->pc = 0x187520u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x187524: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x187524u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187528: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x187528u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x18752c: 0x21140  sll         $v0, $v0, 5
    ctx->pc = 0x18752cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x187530: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x187530u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x187534: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x187534u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x187538: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x187538u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x18753c: 0x2484fae8  addiu       $a0, $a0, -0x518
    ctx->pc = 0x18753cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294965992));
    // 0x187540: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x187540u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x187544: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x187544u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
label_187548:
    // 0x187548: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x187548u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x18754c: 0x10650008  beq         $v1, $a1, . + 4 + (0x8 << 2)
    ctx->pc = 0x18754Cu;
    {
        const bool branch_taken_0x18754c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 5));
        ctx->pc = 0x187550u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18754Cu;
            // 0x187550: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18754c) {
            ctx->pc = 0x187570u;
            goto label_187570;
        }
    }
    ctx->pc = 0x187554u;
    // 0x187554: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x187554u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x187558: 0x28c20020  slti        $v0, $a2, 0x20
    ctx->pc = 0x187558u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x18755c: 0x0  nop
    ctx->pc = 0x18755cu;
    // NOP
    // 0x187560: 0x0  nop
    ctx->pc = 0x187560u;
    // NOP
    // 0x187564: 0x5440fff8  bnel        $v0, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x187564u;
    {
        const bool branch_taken_0x187564 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x187564) {
            ctx->pc = 0x187568u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x187564u;
            // 0x187568: 0x8c830000  lw          $v1, 0x0($a0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x187548u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_187548;
        }
    }
    ctx->pc = 0x18756Cu;
    // 0x18756c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x18756cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_187570:
    // 0x187570: 0x3e00008  jr          $ra
    ctx->pc = 0x187570u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x187548u: goto label_187548;
            case 0x187570u: goto label_187570;
            default: break;
        }
        return;
    }
    ctx->pc = 0x187578u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
