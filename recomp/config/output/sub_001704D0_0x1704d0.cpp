#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001704D0
// Address: 0x1704d0 - 0x170518
void sub_001704D0_0x1704d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001704D0_0x1704d0");
#endif

    switch (ctx->pc) {
        case 0x1704e8u: goto label_1704e8;
        default: break;
    }

    ctx->pc = 0x1704d0u;

    // 0x1704d0: 0x8c821b30  lw          $v0, 0x1B30($a0)
    ctx->pc = 0x1704d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 6960)));
    // 0x1704d4: 0x248414e0  addiu       $a0, $a0, 0x14E0
    ctx->pc = 0x1704d4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 5344));
    // 0x1704d8: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1704d8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1704dc: 0x2446013c  addiu       $a2, $v0, 0x13C
    ctx->pc = 0x1704dcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 316));
    // 0x1704e0: 0x24830004  addiu       $v1, $a0, 0x4
    ctx->pc = 0x1704e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1704e4: 0x0  nop
    ctx->pc = 0x1704e4u;
    // NOP
label_1704e8:
    // 0x1704e8: 0x2484005c  addiu       $a0, $a0, 0x5C
    ctx->pc = 0x1704e8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 92));
    // 0x1704ec: 0xc0102d  daddu       $v0, $a2, $zero
    ctx->pc = 0x1704ecu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1704f0: 0x10650007  beq         $v1, $a1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1704F0u;
    {
        const bool branch_taken_0x1704f0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 5));
        ctx->pc = 0x1704F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1704F0u;
            // 0x1704f4: 0x24c60080  addiu       $a2, $a2, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 128));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1704f0) {
            ctx->pc = 0x170510u;
            goto label_170510;
        }
    }
    ctx->pc = 0x1704F8u;
    // 0x1704f8: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x1704f8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x1704fc: 0x28e20010  slti        $v0, $a3, 0x10
    ctx->pc = 0x1704fcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 7) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x170500: 0x0  nop
    ctx->pc = 0x170500u;
    // NOP
    // 0x170504: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x170504u;
    {
        const bool branch_taken_0x170504 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x170508u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x170504u;
            // 0x170508: 0x24830004  addiu       $v1, $a0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x170504) {
            ctx->pc = 0x1704E8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1704e8;
        }
    }
    ctx->pc = 0x17050Cu;
    // 0x17050c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x17050cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_170510:
    // 0x170510: 0x3e00008  jr          $ra
    ctx->pc = 0x170510u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1704E8u: goto label_1704e8;
            case 0x170510u: goto label_170510;
            default: break;
        }
        return;
    }
    ctx->pc = 0x170518u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
