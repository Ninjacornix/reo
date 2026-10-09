#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00182520
// Address: 0x182520 - 0x182640
void sub_00182520_0x182520(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00182520_0x182520");
#endif

    switch (ctx->pc) {
        case 0x182554u: goto label_182554;
        case 0x182580u: goto label_182580;
        case 0x1825a0u: goto label_1825a0;
        case 0x1825c8u: goto label_1825c8;
        case 0x1825d8u: goto label_1825d8;
        case 0x1825e8u: goto label_1825e8;
        case 0x1825f8u: goto label_1825f8;
        default: break;
    }

    ctx->pc = 0x182520u;

    // 0x182520: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x182520u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x182524: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x182524u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x182528: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x182528u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18252c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x18252cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x182530: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x182530u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182534: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x182534u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x182538: 0x12000008  beqz        $s0, . + 4 + (0x8 << 2)
    ctx->pc = 0x182538u;
    {
        const bool branch_taken_0x182538 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x18253Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182538u;
            // 0x18253c: 0xffbf0018  sd          $ra, 0x18($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182538) {
            ctx->pc = 0x18255Cu;
            goto label_18255c;
        }
    }
    ctx->pc = 0x182540u;
    // 0x182540: 0x3c040028  lui         $a0, 0x28
    ctx->pc = 0x182540u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)40 << 16));
    // 0x182544: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x182544u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182548: 0x24845a48  addiu       $a0, $a0, 0x5A48
    ctx->pc = 0x182548u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 23112));
    // 0x18254c: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x18254Cu;
    SET_GPR_U32(ctx, 31, 0x182554u);
    ctx->pc = 0x182550u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18254Cu;
            // 0x182550: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182554u; }
        if (ctx->pc != 0x182554u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182554u; }
        if (ctx->pc != 0x182554u) { return; }
    }
    ctx->pc = 0x182554u;
label_182554:
    // 0x182554: 0x56000006  bnel        $s0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x182554u;
    {
        const bool branch_taken_0x182554 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x182554) {
            ctx->pc = 0x182558u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x182554u;
            // 0x182558: 0x82020000  lb          $v0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x182570u;
            goto label_182570;
        }
    }
    ctx->pc = 0x18255Cu;
label_18255c:
    // 0x18255c: 0x3c020028  lui         $v0, 0x28
    ctx->pc = 0x18255cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)40 << 16));
    // 0x182560: 0x8c505a40  lw          $s0, 0x5A40($v0)
    ctx->pc = 0x182560u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 23104)));
    // 0x182564: 0x1200002f  beqz        $s0, . + 4 + (0x2F << 2)
    ctx->pc = 0x182564u;
    {
        const bool branch_taken_0x182564 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x182568u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182564u;
            // 0x182568: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182564) {
            ctx->pc = 0x182624u;
            goto label_182624;
        }
    }
    ctx->pc = 0x18256Cu;
    // 0x18256c: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x18256cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
label_182570:
    // 0x182570: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x182570u;
    {
        const bool branch_taken_0x182570 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x182574u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182570u;
            // 0x182574: 0x92050000  lbu         $a1, 0x0($s0) (Delay Slot)
        SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182570) {
            ctx->pc = 0x18258Cu;
            goto label_18258c;
        }
    }
    ctx->pc = 0x182578u;
    // 0x182578: 0x1000002a  b           . + 4 + (0x2A << 2)
    ctx->pc = 0x182578u;
    {
        const bool branch_taken_0x182578 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18257Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182578u;
            // 0x18257c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182578) {
            ctx->pc = 0x182624u;
            goto label_182624;
        }
    }
    ctx->pc = 0x182580u;
label_182580:
    // 0x182580: 0x10600028  beqz        $v1, . + 4 + (0x28 << 2)
    ctx->pc = 0x182580u;
    {
        const bool branch_taken_0x182580 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x182584u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182580u;
            // 0x182584: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182580) {
            ctx->pc = 0x182624u;
            goto label_182624;
        }
    }
    ctx->pc = 0x182588u;
    // 0x182588: 0x92050000  lbu         $a1, 0x0($s0)
    ctx->pc = 0x182588u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
label_18258c:
    // 0x18258c: 0x52e00  sll         $a1, $a1, 24
    ctx->pc = 0x18258cu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 24));
    // 0x182590: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x182590u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182594: 0x52e03  sra         $a1, $a1, 24
    ctx->pc = 0x182594u;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 5), 24));
    // 0x182598: 0xc042b3a  jal         func_10ACE8
    ctx->pc = 0x182598u;
    SET_GPR_U32(ctx, 31, 0x1825A0u);
    ctx->pc = 0x18259Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x182598u;
            // 0x18259c: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ACE8u;
    if (runtime->hasFunction(0x10ACE8u)) {
        auto targetFn = runtime->lookupFunction(0x10ACE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1825A0u; }
        if (ctx->pc != 0x1825A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ACE8_0x10ace8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1825A0u; }
        if (ctx->pc != 0x1825A0u) { return; }
    }
    ctx->pc = 0x1825A0u;
label_1825a0:
    // 0x1825a0: 0x5440fff7  bnel        $v0, $zero, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1825A0u;
    {
        const bool branch_taken_0x1825a0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1825a0) {
            ctx->pc = 0x1825A4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1825A0u;
            // 0x1825a4: 0x8203ffff  lb          $v1, -0x1($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 4294967295)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x182580u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_182580;
        }
    }
    ctx->pc = 0x1825A8u;
    // 0x1825a8: 0x2612ffff  addiu       $s2, $s0, -0x1
    ctx->pc = 0x1825a8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
    // 0x1825ac: 0x24030022  addiu       $v1, $zero, 0x22
    ctx->pc = 0x1825acu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 34));
    // 0x1825b0: 0x82420000  lb          $v0, 0x0($s2)
    ctx->pc = 0x1825b0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1825b4: 0x5443000d  bnel        $v0, $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x1825B4u;
    {
        const bool branch_taken_0x1825b4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1825b4) {
            ctx->pc = 0x1825B8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1825B4u;
            // 0x1825b8: 0x82050000  lb          $a1, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1825ECu;
            goto label_1825ec;
        }
    }
    ctx->pc = 0x1825BCu;
    // 0x1825bc: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x1825bcu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1825c0: 0x3c110024  lui         $s1, 0x24
    ctx->pc = 0x1825c0u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)36 << 16));
    // 0x1825c4: 0x0  nop
    ctx->pc = 0x1825c4u;
    // NOP
label_1825c8:
    // 0x1825c8: 0x82050000  lb          $a1, 0x0($s0)
    ctx->pc = 0x1825c8u;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1825cc: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1825ccu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1825d0: 0xc042b3a  jal         func_10ACE8
    ctx->pc = 0x1825D0u;
    SET_GPR_U32(ctx, 31, 0x1825D8u);
    ctx->pc = 0x1825D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1825D0u;
            // 0x1825d4: 0x262417c0  addiu       $a0, $s1, 0x17C0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 6080));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ACE8u;
    if (runtime->hasFunction(0x10ACE8u)) {
        auto targetFn = runtime->lookupFunction(0x10ACE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1825D8u; }
        if (ctx->pc != 0x1825D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ACE8_0x10ace8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1825D8u; }
        if (ctx->pc != 0x1825D8u) { return; }
    }
    ctx->pc = 0x1825D8u;
label_1825d8:
    // 0x1825d8: 0x1040fffb  beqz        $v0, . + 4 + (-0x5 << 2)
    ctx->pc = 0x1825D8u;
    {
        const bool branch_taken_0x1825d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1825DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1825D8u;
            // 0x1825dc: 0x2603ffff  addiu       $v1, $s0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1825d8) {
            ctx->pc = 0x1825C8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1825c8;
        }
    }
    ctx->pc = 0x1825E0u;
    // 0x1825e0: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1825E0u;
    {
        const bool branch_taken_0x1825e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1825E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1825E0u;
            // 0x1825e4: 0x80620000  lb          $v0, 0x0($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1825e0) {
            ctx->pc = 0x182604u;
            goto label_182604;
        }
    }
    ctx->pc = 0x1825E8u;
label_1825e8:
    // 0x1825e8: 0x82050000  lb          $a1, 0x0($s0)
    ctx->pc = 0x1825e8u;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
label_1825ec:
    // 0x1825ec: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1825ecu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1825f0: 0xc042b3a  jal         func_10ACE8
    ctx->pc = 0x1825F0u;
    SET_GPR_U32(ctx, 31, 0x1825F8u);
    ctx->pc = 0x1825F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1825F0u;
            // 0x1825f4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ACE8u;
    if (runtime->hasFunction(0x10ACE8u)) {
        auto targetFn = runtime->lookupFunction(0x10ACE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1825F8u; }
        if (ctx->pc != 0x1825F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ACE8_0x10ace8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1825F8u; }
        if (ctx->pc != 0x1825F8u) { return; }
    }
    ctx->pc = 0x1825F8u;
label_1825f8:
    // 0x1825f8: 0x1040fffb  beqz        $v0, . + 4 + (-0x5 << 2)
    ctx->pc = 0x1825F8u;
    {
        const bool branch_taken_0x1825f8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1825FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1825F8u;
            // 0x1825fc: 0x2603ffff  addiu       $v1, $s0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1825f8) {
            ctx->pc = 0x1825E8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1825e8;
        }
    }
    ctx->pc = 0x182600u;
    // 0x182600: 0x80620000  lb          $v0, 0x0($v1)
    ctx->pc = 0x182600u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
label_182604:
    // 0x182604: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x182604u;
    {
        const bool branch_taken_0x182604 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x182608u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182604u;
            // 0x182608: 0x3c020028  lui         $v0, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)40 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182604) {
            ctx->pc = 0x182618u;
            goto label_182618;
        }
    }
    ctx->pc = 0x18260Cu;
    // 0x18260c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x18260Cu;
    {
        const bool branch_taken_0x18260c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x182610u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18260Cu;
            // 0x182610: 0xac505a40  sw          $s0, 0x5A40($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 23104), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18260c) {
            ctx->pc = 0x18261Cu;
            goto label_18261c;
        }
    }
    ctx->pc = 0x182614u;
    // 0x182614: 0x0  nop
    ctx->pc = 0x182614u;
    // NOP
label_182618:
    // 0x182618: 0xac405a40  sw          $zero, 0x5A40($v0)
    ctx->pc = 0x182618u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 23104), GPR_U32(ctx, 0));
label_18261c:
    // 0x18261c: 0xa0600000  sb          $zero, 0x0($v1)
    ctx->pc = 0x18261cu;
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x182620: 0x240102d  daddu       $v0, $s2, $zero
    ctx->pc = 0x182620u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_182624:
    // 0x182624: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x182624u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x182628: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x182628u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x18262c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x18262cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x182630: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x182630u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x182634: 0x3e00008  jr          $ra
    ctx->pc = 0x182634u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x182638u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182634u;
            // 0x182638: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x182554u: goto label_182554;
            case 0x18255Cu: goto label_18255c;
            case 0x182570u: goto label_182570;
            case 0x182580u: goto label_182580;
            case 0x18258Cu: goto label_18258c;
            case 0x1825A0u: goto label_1825a0;
            case 0x1825C8u: goto label_1825c8;
            case 0x1825D8u: goto label_1825d8;
            case 0x1825E8u: goto label_1825e8;
            case 0x1825ECu: goto label_1825ec;
            case 0x1825F8u: goto label_1825f8;
            case 0x182604u: goto label_182604;
            case 0x182618u: goto label_182618;
            case 0x18261Cu: goto label_18261c;
            case 0x182624u: goto label_182624;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18263Cu;
    // 0x18263c: 0x0  nop
    ctx->pc = 0x18263cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
