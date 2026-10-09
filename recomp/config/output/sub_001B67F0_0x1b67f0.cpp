#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B67F0
// Address: 0x1b67f0 - 0x1b6860
void sub_001B67F0_0x1b67f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B67F0_0x1b67f0");
#endif

    switch (ctx->pc) {
        case 0x1b6854u: goto label_1b6854;
        default: break;
    }

    ctx->pc = 0x1b67f0u;

label_1b67f0:
    // 0x1b67f0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b67f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b67f4: 0x51202  srl         $v0, $a1, 8
    ctx->pc = 0x1b67f4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 5), 8));
    // 0x1b67f8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b67f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b67fc: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1b67fcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1b6800: 0x8c860028  lw          $a2, 0x28($a0)
    ctx->pc = 0x1b6800u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 40)));
    // 0x1b6804: 0xc21021  addu        $v0, $a2, $v0
    ctx->pc = 0x1b6804u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x1b6808: 0x90420000  lbu         $v0, 0x0($v0)
    ctx->pc = 0x1b6808u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1b680c: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1B680Cu;
    {
        const bool branch_taken_0x1b680c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6810u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B680Cu;
            // 0x1b6810: 0x21a40  sll         $v1, $v0, 9 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 9));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b680c) {
            ctx->pc = 0x1B6838u;
            goto label_1b6838;
        }
    }
    ctx->pc = 0x1B6814u;
    // 0x1b6814: 0x30a200ff  andi        $v0, $a1, 0xFF
    ctx->pc = 0x1b6814u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x1b6818: 0x661821  addu        $v1, $v1, $a2
    ctx->pc = 0x1b6818u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x1b681c: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1b681cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1b6820: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1b6820u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b6824: 0x9442ff00  lhu         $v0, -0x100($v0)
    ctx->pc = 0x1b6824u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 4294967040)));
    // 0x1b6828: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B6828u;
    {
        const bool branch_taken_0x1b6828 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b6828) {
            ctx->pc = 0x1B6838u;
            goto label_1b6838;
        }
    }
    ctx->pc = 0x1B6830u;
    // 0x1b6830: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1B6830u;
    {
        const bool branch_taken_0x1b6830 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6834u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6830u;
            // 0x1b6834: 0x2442ffff  addiu       $v0, $v0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6830) {
            ctx->pc = 0x1B6854u;
            goto label_1b6854;
        }
    }
    ctx->pc = 0x1B6838u;
label_1b6838:
    // 0x1b6838: 0x8c820094  lw          $v0, 0x94($a0)
    ctx->pc = 0x1b6838u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 148)));
    // 0x1b683c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B683Cu;
    {
        const bool branch_taken_0x1b683c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B6840u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B683Cu;
            // 0x1b6840: 0x2405003f  addiu       $a1, $zero, 0x3F (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 63));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b683c) {
            ctx->pc = 0x1B684Cu;
            goto label_1b684c;
        }
    }
    ctx->pc = 0x1B6844u;
    // 0x1b6844: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1B6844u;
    {
        const bool branch_taken_0x1b6844 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6848u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6844u;
            // 0x1b6848: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6844) {
            ctx->pc = 0x1B6854u;
            goto label_1b6854;
        }
    }
    ctx->pc = 0x1B684Cu;
label_1b684c:
    // 0x1b684c: 0xc06d9fc  jal         func_1B67F0
    ctx->pc = 0x1B684Cu;
    SET_GPR_U32(ctx, 31, 0x1B6854u);
    ctx->pc = 0x1B67F0u;
    goto label_1b67f0;
    ctx->pc = 0x1B6854u;
label_1b6854:
    // 0x1b6854: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b6854u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b6858: 0x3e00008  jr          $ra
    ctx->pc = 0x1B6858u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B685Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6858u;
            // 0x1b685c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B67F0u: goto label_1b67f0;
            case 0x1B6838u: goto label_1b6838;
            case 0x1B684Cu: goto label_1b684c;
            case 0x1B6854u: goto label_1b6854;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B6860u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
