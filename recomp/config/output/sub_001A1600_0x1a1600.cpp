#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A1600
// Address: 0x1a1600 - 0x1a1670
void sub_001A1600_0x1a1600(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A1600_0x1a1600");
#endif

    switch (ctx->pc) {
        case 0x1a1618u: goto label_1a1618;
        case 0x1a1640u: goto label_1a1640;
        default: break;
    }

    ctx->pc = 0x1a1600u;

    // 0x1a1600: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1a1600u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1a1604: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1a1604u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1a1608: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1a1608u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1a160c: 0x8c850000  lw          $a1, 0x0($a0)
    ctx->pc = 0x1a160cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1a1610: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1A1610u;
    {
        const bool branch_taken_0x1a1610 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A1614u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1610u;
            // 0x1a1614: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a1610) {
            ctx->pc = 0x1A164Cu;
            goto label_1a164c;
        }
    }
    ctx->pc = 0x1A1618u;
label_1a1618:
    // 0x1a1618: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x1a1618u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1a161c: 0x101900  sll         $v1, $s0, 4
    ctx->pc = 0x1a161cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 4));
    // 0x1a1620: 0x431821  addu        $v1, $v0, $v1
    ctx->pc = 0x1a1620u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a1624: 0x8c620004  lw          $v0, 0x4($v1)
    ctx->pc = 0x1a1624u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x1a1628: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1A1628u;
    {
        const bool branch_taken_0x1a1628 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a1628) {
            ctx->pc = 0x1A1648u;
            goto label_1a1648;
        }
    }
    ctx->pc = 0x1A1630u;
    // 0x1a1630: 0x60202d  daddu       $a0, $v1, $zero
    ctx->pc = 0x1a1630u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a1634: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1a1634u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a1638: 0xc0696c4  jal         func_1A5B10
    ctx->pc = 0x1A1638u;
    SET_GPR_U32(ctx, 31, 0x1A1640u);
    ctx->pc = 0x1A163Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1638u;
            // 0x1a163c: 0x24060010  addiu       $a2, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A5B10u;
    if (runtime->hasFunction(0x1A5B10u)) {
        auto targetFn = runtime->lookupFunction(0x1A5B10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A1640u; }
        if (ctx->pc != 0x1A1640u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A5B10_0x1a5b10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A1640u; }
        if (ctx->pc != 0x1A1640u) { return; }
    }
    ctx->pc = 0x1A1640u;
label_1a1640:
    // 0x1a1640: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1A1640u;
    {
        const bool branch_taken_0x1a1640 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A1644u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1640u;
            // 0x1a1644: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a1640) {
            ctx->pc = 0x1A1658u;
            goto label_1a1658;
        }
    }
    ctx->pc = 0x1A1648u;
label_1a1648:
    // 0x1a1648: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1a1648u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
label_1a164c:
    // 0x1a164c: 0x205102a  slt         $v0, $s0, $a1
    ctx->pc = 0x1a164cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x1a1650: 0x1440fff1  bnez        $v0, . + 4 + (-0xF << 2)
    ctx->pc = 0x1A1650u;
    {
        const bool branch_taken_0x1a1650 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A1654u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1650u;
            // 0x1a1654: 0x3402ffff  ori         $v0, $zero, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a1650) {
            ctx->pc = 0x1A1618u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a1618;
        }
    }
    ctx->pc = 0x1A1658u;
label_1a1658:
    // 0x1a1658: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1a1658u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a165c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1a165cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a1660: 0x3e00008  jr          $ra
    ctx->pc = 0x1A1660u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A1664u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1660u;
            // 0x1a1664: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A1618u: goto label_1a1618;
            case 0x1A1640u: goto label_1a1640;
            case 0x1A1648u: goto label_1a1648;
            case 0x1A164Cu: goto label_1a164c;
            case 0x1A1658u: goto label_1a1658;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A1668u;
    // 0x1a1668: 0x0  nop
    ctx->pc = 0x1a1668u;
    // NOP
    // 0x1a166c: 0x0  nop
    ctx->pc = 0x1a166cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
