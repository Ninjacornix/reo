#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019F550
// Address: 0x19f550 - 0x19f6c0
void sub_0019F550_0x19f550(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019F550_0x19f550");
#endif

    switch (ctx->pc) {
        case 0x19f560u: goto label_19f560;
        case 0x19f568u: goto label_19f568;
        case 0x19f580u: goto label_19f580;
        case 0x19f588u: goto label_19f588;
        case 0x19f58cu: goto label_19f58c;
        case 0x19f594u: goto label_19f594;
        case 0x19f5c0u: goto label_19f5c0;
        case 0x19f5e4u: goto label_19f5e4;
        case 0x19f698u: goto label_19f698;
        case 0x19f6a0u: goto label_19f6a0;
        default: break;
    }

    ctx->pc = 0x19f550u;

    // 0x19f550: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x19f550u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x19f554: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x19f554u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x19f558: 0xc06ad58  jal         func_1AB560
    ctx->pc = 0x19F558u;
    SET_GPR_U32(ctx, 31, 0x19F560u);
    ctx->pc = 0x19F55Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19F558u;
            // 0x19f55c: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AB560u;
    if (runtime->hasFunction(0x1AB560u)) {
        auto targetFn = runtime->lookupFunction(0x1AB560u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F560u; }
        if (ctx->pc != 0x19F560u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AB560_0x1ab560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F560u; }
        if (ctx->pc != 0x19F560u) { return; }
    }
    ctx->pc = 0x19F560u;
label_19f560:
    // 0x19f560: 0xc067d0c  jal         func_19F430
    ctx->pc = 0x19F560u;
    SET_GPR_U32(ctx, 31, 0x19F568u);
    ctx->pc = 0x19F430u;
    if (runtime->hasFunction(0x19F430u)) {
        auto targetFn = runtime->lookupFunction(0x19F430u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F568u; }
        if (ctx->pc != 0x19F568u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019F430_0x19f430(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F568u; }
        if (ctx->pc != 0x19F568u) { return; }
    }
    ctx->pc = 0x19F568u;
label_19f568:
    // 0x19f568: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x19F568u;
    {
        const bool branch_taken_0x19f568 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x19f568) {
            ctx->pc = 0x19F578u;
            goto label_19f578;
        }
    }
    ctx->pc = 0x19F570u;
    // 0x19f570: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x19F570u;
    {
        const bool branch_taken_0x19f570 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19F574u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19F570u;
            // 0x19f574: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19f570) {
            ctx->pc = 0x19F5E8u;
            goto label_19f5e8;
        }
    }
    ctx->pc = 0x19F578u;
label_19f578:
    // 0x19f578: 0xc0449c2  jal         func_112708
    ctx->pc = 0x19F578u;
    SET_GPR_U32(ctx, 31, 0x19F580u);
    ctx->pc = 0x112708u;
    if (runtime->hasFunction(0x112708u)) {
        auto targetFn = runtime->lookupFunction(0x112708u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F580u; }
        if (ctx->pc != 0x19F580u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112708_0x112708(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F580u; }
        if (ctx->pc != 0x19F580u) { return; }
    }
    ctx->pc = 0x19F580u;
label_19f580:
    // 0x19f580: 0xc040c22  jal         func_103088
    ctx->pc = 0x19F580u;
    SET_GPR_U32(ctx, 31, 0x19F588u);
    ctx->pc = 0x19F584u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19F580u;
            // 0x19f584: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x103088u;
    if (runtime->hasFunction(0x103088u)) {
        auto targetFn = runtime->lookupFunction(0x103088u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F588u; }
        if (ctx->pc != 0x19F588u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103088_0x103088(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F588u; }
        if (ctx->pc != 0x19F588u) { return; }
    }
    ctx->pc = 0x19F588u;
label_19f588:
    // 0x19f588: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x19f588u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_19f58c:
    // 0x19f58c: 0xc040c18  jal         func_103060
    ctx->pc = 0x19F58Cu;
    SET_GPR_U32(ctx, 31, 0x19F594u);
    ctx->pc = 0x19F590u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19F58Cu;
            // 0x19f590: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x103060u;
    if (runtime->hasFunction(0x103060u)) {
        auto targetFn = runtime->lookupFunction(0x103060u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F594u; }
        if (ctx->pc != 0x19F594u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103060_0x103060(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F594u; }
        if (ctx->pc != 0x19F594u) { return; }
    }
    ctx->pc = 0x19F594u;
label_19f594:
    // 0x19f594: 0x3c03002a  lui         $v1, 0x2A
    ctx->pc = 0x19f594u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)42 << 16));
    // 0x19f598: 0x102080  sll         $a0, $s0, 2
    ctx->pc = 0x19f598u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x19f59c: 0x2463f9b0  addiu       $v1, $v1, -0x650
    ctx->pc = 0x19f59cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294965680));
    // 0x19f5a0: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x19f5a0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x19f5a4: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x19f5a4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x19f5a8: 0xac6203c4  sw          $v0, 0x3C4($v1)
    ctx->pc = 0x19f5a8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 964), GPR_U32(ctx, 2));
    // 0x19f5ac: 0x2a02000a  slti        $v0, $s0, 0xA
    ctx->pc = 0x19f5acu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)10) ? 1 : 0);
    // 0x19f5b0: 0x1440fff6  bnez        $v0, . + 4 + (-0xA << 2)
    ctx->pc = 0x19F5B0u;
    {
        const bool branch_taken_0x19f5b0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x19f5b0) {
            ctx->pc = 0x19F58Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19f58c;
        }
    }
    ctx->pc = 0x19F5B8u;
    // 0x19f5b8: 0xc06005c  jal         func_180170
    ctx->pc = 0x19F5B8u;
    SET_GPR_U32(ctx, 31, 0x19F5C0u);
    ctx->pc = 0x180170u;
    if (runtime->hasFunction(0x180170u)) {
        auto targetFn = runtime->lookupFunction(0x180170u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F5C0u; }
        if (ctx->pc != 0x19F5C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00180170_0x180170(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F5C0u; }
        if (ctx->pc != 0x19F5C0u) { return; }
    }
    ctx->pc = 0x19F5C0u;
label_19f5c0:
    // 0x19f5c0: 0x3c04002a  lui         $a0, 0x2A
    ctx->pc = 0x19f5c0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)42 << 16));
    // 0x19f5c4: 0x3c060019  lui         $a2, 0x19
    ctx->pc = 0x19f5c4u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)25 << 16));
    // 0x19f5c8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x19f5c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19f5cc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19f5ccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19f5d0: 0x2484f6f0  addiu       $a0, $a0, -0x910
    ctx->pc = 0x19f5d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294964976));
    // 0x19f5d4: 0xac22f6f0  sw          $v0, -0x910($at)
    ctx->pc = 0x19f5d4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294964976), GPR_U32(ctx, 2));
    // 0x19f5d8: 0x24051000  addiu       $a1, $zero, 0x1000
    ctx->pc = 0x19f5d8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
    // 0x19f5dc: 0xc06338c  jal         func_18CE30
    ctx->pc = 0x19F5DCu;
    SET_GPR_U32(ctx, 31, 0x19F5E4u);
    ctx->pc = 0x19F5E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19F5DCu;
            // 0x19f5e0: 0x24c6d160  addiu       $a2, $a2, -0x2EA0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294955360));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18CE30u;
    if (runtime->hasFunction(0x18CE30u)) {
        auto targetFn = runtime->lookupFunction(0x18CE30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F5E4u; }
        if (ctx->pc != 0x19F5E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018CE30_0x18ce30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F5E4u; }
        if (ctx->pc != 0x19F5E4u) { return; }
    }
    ctx->pc = 0x19F5E4u;
label_19f5e4:
    // 0x19f5e4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x19f5e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_19f5e8:
    // 0x19f5e8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x19f5e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19f5ec: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19f5ecu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19f5f0: 0x3e00008  jr          $ra
    ctx->pc = 0x19F5F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19F5F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19F5F0u;
            // 0x19f5f4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19F560u: goto label_19f560;
            case 0x19F568u: goto label_19f568;
            case 0x19F578u: goto label_19f578;
            case 0x19F580u: goto label_19f580;
            case 0x19F588u: goto label_19f588;
            case 0x19F58Cu: goto label_19f58c;
            case 0x19F594u: goto label_19f594;
            case 0x19F5C0u: goto label_19f5c0;
            case 0x19F5E4u: goto label_19f5e4;
            case 0x19F5E8u: goto label_19f5e8;
            case 0x19F698u: goto label_19f698;
            case 0x19F6A0u: goto label_19f6a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19F5F8u;
    // 0x19f5f8: 0x0  nop
    ctx->pc = 0x19f5f8u;
    // NOP
    // 0x19f5fc: 0x0  nop
    ctx->pc = 0x19f5fcu;
    // NOP
    // 0x19f600: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x19f600u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x19f604: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19f604u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19f608: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x19f608u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x19f60c: 0x8c24fa0c  lw          $a0, -0x5F4($at)
    ctx->pc = 0x19f60cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965772)));
    // 0x19f610: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19f610u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19f614: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x19f614u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x19f618: 0x8c234170  lw          $v1, 0x4170($at)
    ctx->pc = 0x19f618u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16752)));
    // 0x19f61c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19f61cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19f620: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x19f620u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x19f624: 0x8c22fa04  lw          $v0, -0x5FC($at)
    ctx->pc = 0x19f624u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965764)));
    // 0x19f628: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19f628u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19f62c: 0xac24fa0c  sw          $a0, -0x5F4($at)
    ctx->pc = 0x19f62cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965772), GPR_U32(ctx, 4));
    // 0x19f630: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19f630u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19f634: 0xac234170  sw          $v1, 0x4170($at)
    ctx->pc = 0x19f634u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 16752), GPR_U32(ctx, 3));
    // 0x19f638: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19f638u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19f63c: 0x8c23fa0c  lw          $v1, -0x5F4($at)
    ctx->pc = 0x19f63cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965772)));
    // 0x19f640: 0x43082a  slt         $at, $v0, $v1
    ctx->pc = 0x19f640u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x19f644: 0x10200014  beqz        $at, . + 4 + (0x14 << 2)
    ctx->pc = 0x19F644u;
    {
        const bool branch_taken_0x19f644 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x19F648u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19F644u;
            // 0x19f648: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19f644) {
            ctx->pc = 0x19F698u;
            goto label_19f698;
        }
    }
    ctx->pc = 0x19F64Cu;
    // 0x19f64c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x19f64cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19f650: 0x8c23fa10  lw          $v1, -0x5F0($at)
    ctx->pc = 0x19f650u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965776)));
    // 0x19f654: 0x14620010  bne         $v1, $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x19F654u;
    {
        const bool branch_taken_0x19f654 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x19f654) {
            ctx->pc = 0x19F698u;
            goto label_19f698;
        }
    }
    ctx->pc = 0x19F65Cu;
    // 0x19f65c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19f65cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19f660: 0xac20fa10  sw          $zero, -0x5F0($at)
    ctx->pc = 0x19f660u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965776), GPR_U32(ctx, 0));
    // 0x19f664: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19f664u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19f668: 0x8c23fa08  lw          $v1, -0x5F8($at)
    ctx->pc = 0x19f668u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965768)));
    // 0x19f66c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19f66cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19f670: 0x8c22fa00  lw          $v0, -0x600($at)
    ctx->pc = 0x19f670u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965760)));
    // 0x19f674: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19f674u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19f678: 0x38420001  xori        $v0, $v0, 0x1
    ctx->pc = 0x19f678u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
    // 0x19f67c: 0xac23fa04  sw          $v1, -0x5FC($at)
    ctx->pc = 0x19f67cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965764), GPR_U32(ctx, 3));
    // 0x19f680: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19f680u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19f684: 0xac22fa00  sw          $v0, -0x600($at)
    ctx->pc = 0x19f684u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965760), GPR_U32(ctx, 2));
    // 0x19f688: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19f688u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19f68c: 0x8c24fa00  lw          $a0, -0x600($at)
    ctx->pc = 0x19f68cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965760)));
    // 0x19f690: 0xc0680d4  jal         func_1A0350
    ctx->pc = 0x19F690u;
    SET_GPR_U32(ctx, 31, 0x19F698u);
    ctx->pc = 0x19F694u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19F690u;
            // 0x19f694: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A0350u;
    if (runtime->hasFunction(0x1A0350u)) {
        auto targetFn = runtime->lookupFunction(0x1A0350u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F698u; }
        if (ctx->pc != 0x19F698u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A0350_0x1a0350(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F698u; }
        if (ctx->pc != 0x19F698u) { return; }
    }
    ctx->pc = 0x19F698u;
label_19f698:
    // 0x19f698: 0xc06a410  jal         func_1A9040
    ctx->pc = 0x19F698u;
    SET_GPR_U32(ctx, 31, 0x19F6A0u);
    ctx->pc = 0x1A9040u;
    if (runtime->hasFunction(0x1A9040u)) {
        auto targetFn = runtime->lookupFunction(0x1A9040u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F6A0u; }
        if (ctx->pc != 0x19F6A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A9040_0x1a9040(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F6A0u; }
        if (ctx->pc != 0x19F6A0u) { return; }
    }
    ctx->pc = 0x19F6A0u;
label_19f6a0:
    // 0x19f6a0: 0xf  sync
    ctx->pc = 0x19f6a0u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x19f6a4: 0x42000038  ei
    ctx->pc = 0x19f6a4u;
    ctx->cop0_status |= 0x10000; // Enable interrupts
    // 0x19f6a8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x19f6a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19f6ac: 0x3e00008  jr          $ra
    ctx->pc = 0x19F6ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19F6B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19F6ACu;
            // 0x19f6b0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19F560u: goto label_19f560;
            case 0x19F568u: goto label_19f568;
            case 0x19F578u: goto label_19f578;
            case 0x19F580u: goto label_19f580;
            case 0x19F588u: goto label_19f588;
            case 0x19F58Cu: goto label_19f58c;
            case 0x19F594u: goto label_19f594;
            case 0x19F5C0u: goto label_19f5c0;
            case 0x19F5E4u: goto label_19f5e4;
            case 0x19F5E8u: goto label_19f5e8;
            case 0x19F698u: goto label_19f698;
            case 0x19F6A0u: goto label_19f6a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19F6B4u;
    // 0x19f6b4: 0x0  nop
    ctx->pc = 0x19f6b4u;
    // NOP
    // 0x19f6b8: 0x0  nop
    ctx->pc = 0x19f6b8u;
    // NOP
    // 0x19f6bc: 0x0  nop
    ctx->pc = 0x19f6bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
