#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00170518
// Address: 0x170518 - 0x170560
void sub_00170518_0x170518(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00170518_0x170518");
#endif

    switch (ctx->pc) {
        case 0x170530u: goto label_170530;
        default: break;
    }

    ctx->pc = 0x170518u;

    // 0x170518: 0x8c821b30  lw          $v0, 0x1B30($a0)
    ctx->pc = 0x170518u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 6960)));
    // 0x17051c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x17051cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170520: 0x8c460138  lw          $a2, 0x138($v0)
    ctx->pc = 0x170520u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 312)));
    // 0x170524: 0x18c0000b  blez        $a2, . + 4 + (0xB << 2)
    ctx->pc = 0x170524u;
    {
        const bool branch_taken_0x170524 = (GPR_S64(ctx, 6) <= 0);
        ctx->pc = 0x170528u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x170524u;
            // 0x170528: 0x2443013c  addiu       $v1, $v0, 0x13C (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 316));
        ctx->in_delay_slot = false;
        if (branch_taken_0x170524) {
            ctx->pc = 0x170554u;
            goto label_170554;
        }
    }
    ctx->pc = 0x17052Cu;
    // 0x17052c: 0x248414e0  addiu       $a0, $a0, 0x14E0
    ctx->pc = 0x17052cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 5344));
label_170530:
    // 0x170530: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x170530u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170534: 0x10650008  beq         $v1, $a1, . + 4 + (0x8 << 2)
    ctx->pc = 0x170534u;
    {
        const bool branch_taken_0x170534 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 5));
        ctx->pc = 0x170538u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x170534u;
            // 0x170538: 0x2484005c  addiu       $a0, $a0, 0x5C (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 92));
        ctx->in_delay_slot = false;
        if (branch_taken_0x170534) {
            ctx->pc = 0x170558u;
            goto label_170558;
        }
    }
    ctx->pc = 0x17053Cu;
    // 0x17053c: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x17053cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x170540: 0xe6102a  slt         $v0, $a3, $a2
    ctx->pc = 0x170540u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 7) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x170544: 0x0  nop
    ctx->pc = 0x170544u;
    // NOP
    // 0x170548: 0x0  nop
    ctx->pc = 0x170548u;
    // NOP
    // 0x17054c: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x17054Cu;
    {
        const bool branch_taken_0x17054c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x170550u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17054Cu;
            // 0x170550: 0x24630080  addiu       $v1, $v1, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 128));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17054c) {
            ctx->pc = 0x170530u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_170530;
        }
    }
    ctx->pc = 0x170554u;
label_170554:
    // 0x170554: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x170554u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_170558:
    // 0x170558: 0x3e00008  jr          $ra
    ctx->pc = 0x170558u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x170530u: goto label_170530;
            case 0x170554u: goto label_170554;
            case 0x170558u: goto label_170558;
            default: break;
        }
        return;
    }
    ctx->pc = 0x170560u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
