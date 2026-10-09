#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D5A30
// Address: 0x1d5a30 - 0x1d5a88
void sub_001D5A30_0x1d5a30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D5A30_0x1d5a30");
#endif

    switch (ctx->pc) {
        case 0x1d5a60u: goto label_1d5a60;
        default: break;
    }

    ctx->pc = 0x1d5a30u;

    // 0x1d5a30: 0x3c030034  lui         $v1, 0x34
    ctx->pc = 0x1d5a30u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)52 << 16));
    // 0x1d5a34: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1d5a34u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1d5a38: 0x8c4728d8  lw          $a3, 0x28D8($v0)
    ctx->pc = 0x1d5a38u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 10456)));
    // 0x1d5a3c: 0x24682980  addiu       $t0, $v1, 0x2980
    ctx->pc = 0x1d5a3cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 3), 10624));
    // 0x1d5a40: 0x90642980  lbu         $a0, 0x2980($v1)
    ctx->pc = 0x1d5a40u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 10624)));
    // 0x1d5a44: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1d5a44u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d5a48: 0xace40000  sw          $a0, 0x0($a3)
    ctx->pc = 0x1d5a48u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 4));
    // 0x1d5a4c: 0x91020001  lbu         $v0, 0x1($t0)
    ctx->pc = 0x1d5a4cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 1)));
    // 0x1d5a50: 0x1080000b  beqz        $a0, . + 4 + (0xB << 2)
    ctx->pc = 0x1D5A50u;
    {
        const bool branch_taken_0x1d5a50 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D5A54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5A50u;
            // 0x1d5a54: 0xace20004  sw          $v0, 0x4($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5a50) {
            ctx->pc = 0x1D5A80u;
            goto label_1d5a80;
        }
    }
    ctx->pc = 0x1D5A58u;
    // 0x1d5a58: 0x24e60008  addiu       $a2, $a3, 0x8
    ctx->pc = 0x1d5a58u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 7), 8));
    // 0x1d5a5c: 0xa81021  addu        $v0, $a1, $t0
    ctx->pc = 0x1d5a5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 8)));
label_1d5a60:
    // 0x1d5a60: 0xc52021  addu        $a0, $a2, $a1
    ctx->pc = 0x1d5a60u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
    // 0x1d5a64: 0x90430002  lbu         $v1, 0x2($v0)
    ctx->pc = 0x1d5a64u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 2)));
    // 0x1d5a68: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1d5a68u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1d5a6c: 0xa0830000  sb          $v1, 0x0($a0)
    ctx->pc = 0x1d5a6cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1d5a70: 0x8ce20000  lw          $v0, 0x0($a3)
    ctx->pc = 0x1d5a70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1d5a74: 0xa2102a  slt         $v0, $a1, $v0
    ctx->pc = 0x1d5a74u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1d5a78: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1D5A78u;
    {
        const bool branch_taken_0x1d5a78 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D5A7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5A78u;
            // 0x1d5a7c: 0xa81021  addu        $v0, $a1, $t0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5a78) {
            ctx->pc = 0x1D5A60u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d5a60;
        }
    }
    ctx->pc = 0x1D5A80u;
label_1d5a80:
    // 0x1d5a80: 0x3e00008  jr          $ra
    ctx->pc = 0x1D5A80u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D5A84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5A80u;
            // 0x1d5a84: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D5A60u: goto label_1d5a60;
            case 0x1D5A80u: goto label_1d5a80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D5A88u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
