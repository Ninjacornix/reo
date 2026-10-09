#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A35A0
// Address: 0x1a35a0 - 0x1a35f0
void sub_001A35A0_0x1a35a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A35A0_0x1a35a0");
#endif

    switch (ctx->pc) {
        case 0x1a35b0u: goto label_1a35b0;
        default: break;
    }

    ctx->pc = 0x1a35a0u;

    // 0x1a35a0: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x1a35a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1a35a4: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1a35a4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a35a8: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1A35A8u;
    {
        const bool branch_taken_0x1a35a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A35ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A35A8u;
            // 0x1a35ac: 0x2484000c  addiu       $a0, $a0, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a35a8) {
            ctx->pc = 0x1A35D0u;
            goto label_1a35d0;
        }
    }
    ctx->pc = 0x1A35B0u;
label_1a35b0:
    // 0x1a35b0: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1a35b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1a35b4: 0x14450003  bne         $v0, $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A35B4u;
    {
        const bool branch_taken_0x1a35b4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 5));
        ctx->pc = 0x1A35B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A35B4u;
            // 0x1a35b8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a35b4) {
            ctx->pc = 0x1A35C4u;
            goto label_1a35c4;
        }
    }
    ctx->pc = 0x1A35BCu;
    // 0x1a35bc: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1A35BCu;
    {
        const bool branch_taken_0x1a35bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a35bc) {
            ctx->pc = 0x1A35DCu;
            goto label_1a35dc;
        }
    }
    ctx->pc = 0x1A35C4u;
label_1a35c4:
    // 0x1a35c4: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x1a35c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1a35c8: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1a35c8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1a35cc: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x1a35ccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
label_1a35d0:
    // 0x1a35d0: 0xc3102b  sltu        $v0, $a2, $v1
    ctx->pc = 0x1a35d0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1a35d4: 0x1440fff6  bnez        $v0, . + 4 + (-0xA << 2)
    ctx->pc = 0x1A35D4u;
    {
        const bool branch_taken_0x1a35d4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A35D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A35D4u;
            // 0x1a35d8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a35d4) {
            ctx->pc = 0x1A35B0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a35b0;
        }
    }
    ctx->pc = 0x1A35DCu;
label_1a35dc:
    // 0x1a35dc: 0x3e00008  jr          $ra
    ctx->pc = 0x1A35DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A35B0u: goto label_1a35b0;
            case 0x1A35C4u: goto label_1a35c4;
            case 0x1A35D0u: goto label_1a35d0;
            case 0x1A35DCu: goto label_1a35dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A35E4u;
    // 0x1a35e4: 0x0  nop
    ctx->pc = 0x1a35e4u;
    // NOP
    // 0x1a35e8: 0x0  nop
    ctx->pc = 0x1a35e8u;
    // NOP
    // 0x1a35ec: 0x0  nop
    ctx->pc = 0x1a35ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
