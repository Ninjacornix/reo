#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C3C40
// Address: 0x1c3c40 - 0x1c3c90
void sub_001C3C40_0x1c3c40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C3C40_0x1c3c40");
#endif

    ctx->pc = 0x1c3c40u;

    // 0x1c3c40: 0x8c830020  lw          $v1, 0x20($a0)
    ctx->pc = 0x1c3c40u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 32)));
    // 0x1c3c44: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1c3c44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c3c48: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C3C48u;
    {
        const bool branch_taken_0x1c3c48 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C3C4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3C48u;
            // 0x1c3c4c: 0x3c01004c  lui         $at, 0x4C (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c3c48) {
            ctx->pc = 0x1C3C58u;
            goto label_1c3c58;
        }
    }
    ctx->pc = 0x1C3C50u;
    // 0x1c3c50: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1C3C50u;
    {
        const bool branch_taken_0x1c3c50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C3C54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3C50u;
            // 0x1c3c54: 0x9482000a  lhu         $v0, 0xA($a0) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 10)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c3c50) {
            ctx->pc = 0x1C3C70u;
            goto label_1c3c70;
        }
    }
    ctx->pc = 0x1C3C58u;
label_1c3c58:
    // 0x1c3c58: 0x8c22ae90  lw          $v0, -0x5170($at)
    ctx->pc = 0x1c3c58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294946448)));
    // 0x1c3c5c: 0x30420020  andi        $v0, $v0, 0x20
    ctx->pc = 0x1c3c5cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)32);
    // 0x1c3c60: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1C3C60u;
    {
        const bool branch_taken_0x1c3c60 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C3C64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3C60u;
            // 0x1c3c64: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c3c60) {
            ctx->pc = 0x1C3C88u;
            goto label_1c3c88;
        }
    }
    ctx->pc = 0x1C3C68u;
    // 0x1c3c68: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1C3C68u;
    {
        const bool branch_taken_0x1c3c68 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C3C6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3C68u;
            // 0x1c3c6c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c3c68) {
            ctx->pc = 0x1C3C88u;
            goto label_1c3c88;
        }
    }
    ctx->pc = 0x1C3C70u;
label_1c3c70:
    // 0x1c3c70: 0x30420010  andi        $v0, $v0, 0x10
    ctx->pc = 0x1c3c70u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)16);
    // 0x1c3c74: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C3C74u;
    {
        const bool branch_taken_0x1c3c74 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c3c74) {
            ctx->pc = 0x1C3C84u;
            goto label_1c3c84;
        }
    }
    ctx->pc = 0x1C3C7Cu;
    // 0x1c3c7c: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1C3C7Cu;
    {
        const bool branch_taken_0x1c3c7c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C3C80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3C7Cu;
            // 0x1c3c80: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c3c7c) {
            ctx->pc = 0x1C3C88u;
            goto label_1c3c88;
        }
    }
    ctx->pc = 0x1C3C84u;
label_1c3c84:
    // 0x1c3c84: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1c3c84u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1c3c88:
    // 0x1c3c88: 0x3e00008  jr          $ra
    ctx->pc = 0x1C3C88u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C3C58u: goto label_1c3c58;
            case 0x1C3C70u: goto label_1c3c70;
            case 0x1C3C84u: goto label_1c3c84;
            case 0x1C3C88u: goto label_1c3c88;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C3C90u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
