#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A1D40
// Address: 0x1a1d40 - 0x1a1d90
void sub_001A1D40_0x1a1d40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A1D40_0x1a1d40");
#endif

    ctx->pc = 0x1a1d40u;

    // 0x1a1d40: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a1d40u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a1d44: 0x41100  sll         $v0, $a0, 4
    ctx->pc = 0x1a1d44u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
    // 0x1a1d48: 0x8c23ffa8  lw          $v1, -0x58($at)
    ctx->pc = 0x1a1d48u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294967208)));
    // 0x1a1d4c: 0x441023  subu        $v0, $v0, $a0
    ctx->pc = 0x1a1d4cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1a1d50: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1a1d50u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1a1d54: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1a1d54u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1a1d58: 0x90620000  lbu         $v0, 0x0($v1)
    ctx->pc = 0x1a1d58u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1a1d5c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A1D5Cu;
    {
        const bool branch_taken_0x1a1d5c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A1D60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1D5Cu;
            // 0x1a1d60: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a1d5c) {
            ctx->pc = 0x1A1D6Cu;
            goto label_1a1d6c;
        }
    }
    ctx->pc = 0x1A1D64u;
    // 0x1a1d64: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1A1D64u;
    {
        const bool branch_taken_0x1a1d64 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a1d64) {
            ctx->pc = 0x1A1D88u;
            goto label_1a1d88;
        }
    }
    ctx->pc = 0x1A1D6Cu;
label_1a1d6c:
    // 0x1a1d6c: 0x94630002  lhu         $v1, 0x2($v1)
    ctx->pc = 0x1a1d6cu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 2)));
    // 0x1a1d70: 0x10600005  beqz        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1A1D70u;
    {
        const bool branch_taken_0x1a1d70 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A1D74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1D70u;
            // 0x1a1d74: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a1d70) {
            ctx->pc = 0x1A1D88u;
            goto label_1a1d88;
        }
    }
    ctx->pc = 0x1A1D78u;
    // 0x1a1d78: 0x34028000  ori         $v0, $zero, 0x8000
    ctx->pc = 0x1a1d78u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x1a1d7c: 0x14620002  bne         $v1, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1A1D7Cu;
    {
        const bool branch_taken_0x1a1d7c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1A1D80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1D7Cu;
            // 0x1a1d80: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a1d7c) {
            ctx->pc = 0x1A1D88u;
            goto label_1a1d88;
        }
    }
    ctx->pc = 0x1A1D84u;
    // 0x1a1d84: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1a1d84u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1a1d88:
    // 0x1a1d88: 0x3e00008  jr          $ra
    ctx->pc = 0x1A1D88u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A1D6Cu: goto label_1a1d6c;
            case 0x1A1D88u: goto label_1a1d88;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A1D90u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
