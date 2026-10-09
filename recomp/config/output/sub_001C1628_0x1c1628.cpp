#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C1628
// Address: 0x1c1628 - 0x1c1688
void sub_001C1628_0x1c1628(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C1628_0x1c1628");
#endif

    switch (ctx->pc) {
        case 0x1c1638u: goto label_1c1638;
        case 0x1c1640u: goto label_1c1640;
        case 0x1c1658u: goto label_1c1658;
        default: break;
    }

    ctx->pc = 0x1c1628u;

    // 0x1c1628: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c1628u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c162c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c162cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c1630: 0xc0451b4  jal         func_1146D0
    ctx->pc = 0x1C1630u;
    SET_GPR_U32(ctx, 31, 0x1C1638u);
    ctx->pc = 0x1C1634u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1630u;
            // 0x1c1634: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1146D0u;
    if (runtime->hasFunction(0x1146D0u)) {
        auto targetFn = runtime->lookupFunction(0x1146D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1638u; }
        if (ctx->pc != 0x1C1638u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001146D0_0x1146d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1638u; }
        if (ctx->pc != 0x1C1638u) { return; }
    }
    ctx->pc = 0x1C1638u;
label_1c1638:
    // 0x1c1638: 0xc07057a  jal         func_1C15E8
    ctx->pc = 0x1C1638u;
    SET_GPR_U32(ctx, 31, 0x1C1640u);
    ctx->pc = 0x1C15E8u;
    if (runtime->hasFunction(0x1C15E8u)) {
        auto targetFn = runtime->lookupFunction(0x1C15E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1640u; }
        if (ctx->pc != 0x1C1640u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C15E8_0x1c15e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1640u; }
        if (ctx->pc != 0x1C1640u) { return; }
    }
    ctx->pc = 0x1C1640u;
label_1c1640:
    // 0x1c1640: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C1640u;
    {
        const bool branch_taken_0x1c1640 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C1644u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1640u;
            // 0x1c1644: 0x3c020023  lui         $v0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1640) {
            ctx->pc = 0x1C1650u;
            goto label_1c1650;
        }
    }
    ctx->pc = 0x1C1648u;
    // 0x1c1648: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1C1648u;
    {
        const bool branch_taken_0x1c1648 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C164Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1648u;
            // 0x1c164c: 0x904252d4  lbu         $v0, 0x52D4($v0) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 21204)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1648) {
            ctx->pc = 0x1C167Cu;
            goto label_1c167c;
        }
    }
    ctx->pc = 0x1C1650u;
label_1c1650:
    // 0x1c1650: 0xc0451b4  jal         func_1146D0
    ctx->pc = 0x1C1650u;
    SET_GPR_U32(ctx, 31, 0x1C1658u);
    ctx->pc = 0x1C1654u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1650u;
            // 0x1c1654: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1146D0u;
    if (runtime->hasFunction(0x1146D0u)) {
        auto targetFn = runtime->lookupFunction(0x1146D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1658u; }
        if (ctx->pc != 0x1C1658u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001146D0_0x1146d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1658u; }
        if (ctx->pc != 0x1C1658u) { return; }
    }
    ctx->pc = 0x1C1658u;
label_1c1658:
    // 0x1c1658: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x1c1658u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c165c: 0x31342  srl         $v0, $v1, 13
    ctx->pc = 0x1c165cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 3), 13));
    // 0x1c1660: 0x30420007  andi        $v0, $v0, 0x7
    ctx->pc = 0x1c1660u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)7);
    // 0x1c1664: 0x54400004  bnel        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x1C1664u;
    {
        const bool branch_taken_0x1c1664 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c1664) {
            ctx->pc = 0x1C1668u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1664u;
            // 0x1c1668: 0x31402  srl         $v0, $v1, 16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 3), 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1C1678u;
            goto label_1c1678;
        }
    }
    ctx->pc = 0x1C166Cu;
    // 0x1c166c: 0x31102  srl         $v0, $v1, 4
    ctx->pc = 0x1c166cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 3), 4));
    // 0x1c1670: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1C1670u;
    {
        const bool branch_taken_0x1c1670 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C1674u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1670u;
            // 0x1c1674: 0x30420001  andi        $v0, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1670) {
            ctx->pc = 0x1C167Cu;
            goto label_1c167c;
        }
    }
    ctx->pc = 0x1C1678u;
label_1c1678:
    // 0x1c1678: 0x3042001f  andi        $v0, $v0, 0x1F
    ctx->pc = 0x1c1678u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)31);
label_1c167c:
    // 0x1c167c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c167cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c1680: 0x3e00008  jr          $ra
    ctx->pc = 0x1C1680u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C1684u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1680u;
            // 0x1c1684: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C1638u: goto label_1c1638;
            case 0x1C1640u: goto label_1c1640;
            case 0x1C1650u: goto label_1c1650;
            case 0x1C1658u: goto label_1c1658;
            case 0x1C1678u: goto label_1c1678;
            case 0x1C167Cu: goto label_1c167c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C1688u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
