#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00102E48
// Address: 0x102e48 - 0x102ea4
void sub_00102E48_0x102e48(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00102E48_0x102e48");
#endif

    switch (ctx->pc) {
        case 0x102e70u: goto label_102e70;
        default: break;
    }

    ctx->pc = 0x102e48u;

    // 0x102e48: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x102e48u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x102e4c: 0x10a00013  beqz        $a1, . + 4 + (0x13 << 2)
    ctx->pc = 0x102E4Cu;
    {
        const bool branch_taken_0x102e4c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x102E50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102E4Cu;
            // 0x102e50: 0x24a3ffff  addiu       $v1, $a1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x102e4c) {
            ctx->pc = 0x102E9Cu;
            goto label_102e9c;
        }
    }
    ctx->pc = 0x102E54u;
    // 0x102e54: 0x3c061000  lui         $a2, 0x1000
    ctx->pc = 0x102e54u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)4096 << 16));
    // 0x102e58: 0x3c051000  lui         $a1, 0x1000
    ctx->pc = 0x102e58u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)4096 << 16));
    // 0x102e5c: 0x34c63c00  ori         $a2, $a2, 0x3C00
    ctx->pc = 0x102e5cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)15360);
    // 0x102e60: 0x3c091000  lui         $t1, 0x1000
    ctx->pc = 0x102e60u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)4096 << 16));
    // 0x102e64: 0x34a55000  ori         $a1, $a1, 0x5000
    ctx->pc = 0x102e64u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)20480);
    // 0x102e68: 0x2408ffff  addiu       $t0, $zero, -0x1
    ctx->pc = 0x102e68u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x102e6c: 0x0  nop
    ctx->pc = 0x102e6cu;
    // NOP
label_102e70:
    // 0x102e70: 0x8cc20000  lw          $v0, 0x0($a2)
    ctx->pc = 0x102e70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x102e74: 0x491024  and         $v0, $v0, $t1
    ctx->pc = 0x102e74u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 9));
    // 0x102e78: 0x50400003  beql        $v0, $zero, . + 4 + (0x3 << 2)
    ctx->pc = 0x102E78u;
    {
        const bool branch_taken_0x102e78 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x102e78) {
            ctx->pc = 0x102E7Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x102E78u;
            // 0x102e7c: 0x78820000  lq          $v0, 0x0($a0) (Delay Slot)
        SET_GPR_VEC(ctx, 2, READ128(ADD32(GPR_U32(ctx, 4), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x102E88u;
            goto label_102e88;
        }
    }
    ctx->pc = 0x102E80u;
    // 0x102e80: 0x3e00008  jr          $ra
    ctx->pc = 0x102E80u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x102E84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102E80u;
            // 0x102e84: 0xe0102d  daddu       $v0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x102E70u: goto label_102e70;
            case 0x102E88u: goto label_102e88;
            case 0x102E9Cu: goto label_102e9c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102E88u;
label_102e88:
    // 0x102e88: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x102e88u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x102e8c: 0x24840010  addiu       $a0, $a0, 0x10
    ctx->pc = 0x102e8cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 16));
    // 0x102e90: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x102e90u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x102e94: 0x1468fff6  bne         $v1, $t0, . + 4 + (-0xA << 2)
    ctx->pc = 0x102E94u;
    {
        const bool branch_taken_0x102e94 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 8));
        ctx->pc = 0x102E98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102E94u;
            // 0x102e98: 0x7ca20000  sq          $v0, 0x0($a1) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 5), 0), GPR_VEC(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x102e94) {
            ctx->pc = 0x102E70u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_102e70;
        }
    }
    ctx->pc = 0x102E9Cu;
label_102e9c:
    // 0x102e9c: 0x3e00008  jr          $ra
    ctx->pc = 0x102E9Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x102EA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102E9Cu;
            // 0x102ea0: 0xe0102d  daddu       $v0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x102E70u: goto label_102e70;
            case 0x102E88u: goto label_102e88;
            case 0x102E9Cu: goto label_102e9c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102EA4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
