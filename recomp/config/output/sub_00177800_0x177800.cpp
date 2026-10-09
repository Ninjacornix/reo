#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00177800
// Address: 0x177800 - 0x1778f0
void sub_00177800_0x177800(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00177800_0x177800");
#endif

    switch (ctx->pc) {
        case 0x177824u: goto label_177824;
        case 0x177844u: goto label_177844;
        case 0x177850u: goto label_177850;
        case 0x177860u: goto label_177860;
        case 0x17787cu: goto label_17787c;
        case 0x177888u: goto label_177888;
        case 0x17789cu: goto label_17789c;
        case 0x1778b8u: goto label_1778b8;
        default: break;
    }

    ctx->pc = 0x177800u;

    // 0x177800: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x177800u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x177804: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x177804u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x177808: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x177808u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17780c: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x17780cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177810: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x177810u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177814: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x177814u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x177818: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x177818u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x17781c: 0xc05dec4  jal         func_177B10
    ctx->pc = 0x17781Cu;
    SET_GPR_U32(ctx, 31, 0x177824u);
    ctx->pc = 0x177820u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17781Cu;
            // 0x177820: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177B10u;
    if (runtime->hasFunction(0x177B10u)) {
        auto targetFn = runtime->lookupFunction(0x177B10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177824u; }
        if (ctx->pc != 0x177824u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177B10_0x177b10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177824u; }
        if (ctx->pc != 0x177824u) { return; }
    }
    ctx->pc = 0x177824u;
label_177824:
    // 0x177824: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x177824u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177828: 0x8e220008  lw          $v0, 0x8($s1)
    ctx->pc = 0x177828u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x17782c: 0x24050005  addiu       $a1, $zero, 0x5
    ctx->pc = 0x17782cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x177830: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x177830u;
    {
        const bool branch_taken_0x177830 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x177834u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177830u;
            // 0x177834: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x177830) {
            ctx->pc = 0x177858u;
            goto label_177858;
        }
    }
    ctx->pc = 0x177838u;
    // 0x177838: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x177838u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17783c: 0xc05de9c  jal         func_177A70
    ctx->pc = 0x17783Cu;
    SET_GPR_U32(ctx, 31, 0x177844u);
    ctx->pc = 0x177840u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17783Cu;
            // 0x177840: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177A70u;
    if (runtime->hasFunction(0x177A70u)) {
        auto targetFn = runtime->lookupFunction(0x177A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177844u; }
        if (ctx->pc != 0x177844u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177A70_0x177a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177844u; }
        if (ctx->pc != 0x177844u) { return; }
    }
    ctx->pc = 0x177844u;
label_177844:
    // 0x177844: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x177844u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177848: 0xc05de3c  jal         func_1778F0
    ctx->pc = 0x177848u;
    SET_GPR_U32(ctx, 31, 0x177850u);
    ctx->pc = 0x17784Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x177848u;
            // 0x17784c: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1778F0u;
    if (runtime->hasFunction(0x1778F0u)) {
        auto targetFn = runtime->lookupFunction(0x1778F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177850u; }
        if (ctx->pc != 0x177850u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001778F0_0x1778f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177850u; }
        if (ctx->pc != 0x177850u) { return; }
    }
    ctx->pc = 0x177850u;
label_177850:
    // 0x177850: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x177850u;
    {
        const bool branch_taken_0x177850 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x177854u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177850u;
            // 0x177854: 0x8e22000c  lw          $v0, 0xC($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x177850) {
            ctx->pc = 0x177868u;
            goto label_177868;
        }
    }
    ctx->pc = 0x177858u;
label_177858:
    // 0x177858: 0xc05d518  jal         func_175460
    ctx->pc = 0x177858u;
    SET_GPR_U32(ctx, 31, 0x177860u);
    ctx->pc = 0x175460u;
    if (runtime->hasFunction(0x175460u)) {
        auto targetFn = runtime->lookupFunction(0x175460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177860u; }
        if (ctx->pc != 0x177860u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175460_0x175460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177860u; }
        if (ctx->pc != 0x177860u) { return; }
    }
    ctx->pc = 0x177860u;
label_177860:
    // 0x177860: 0xae000b44  sw          $zero, 0xB44($s0)
    ctx->pc = 0x177860u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 2884), GPR_U32(ctx, 0));
    // 0x177864: 0x8e22000c  lw          $v0, 0xC($s1)
    ctx->pc = 0x177864u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
label_177868:
    // 0x177868: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x177868u;
    {
        const bool branch_taken_0x177868 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17786Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177868u;
            // 0x17786c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x177868) {
            ctx->pc = 0x177890u;
            goto label_177890;
        }
    }
    ctx->pc = 0x177870u;
    // 0x177870: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x177870u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x177874: 0xc05dea4  jal         func_177A90
    ctx->pc = 0x177874u;
    SET_GPR_U32(ctx, 31, 0x17787Cu);
    ctx->pc = 0x177878u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x177874u;
            // 0x177878: 0x24060002  addiu       $a2, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177A90u;
    if (runtime->hasFunction(0x177A90u)) {
        auto targetFn = runtime->lookupFunction(0x177A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17787Cu; }
        if (ctx->pc != 0x17787Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177A90_0x177a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17787Cu; }
        if (ctx->pc != 0x17787Cu) { return; }
    }
    ctx->pc = 0x17787Cu;
label_17787c:
    // 0x17787c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17787cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177880: 0xc05de64  jal         func_177990
    ctx->pc = 0x177880u;
    SET_GPR_U32(ctx, 31, 0x177888u);
    ctx->pc = 0x177884u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x177880u;
            // 0x177884: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177990u;
    if (runtime->hasFunction(0x177990u)) {
        auto targetFn = runtime->lookupFunction(0x177990u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177888u; }
        if (ctx->pc != 0x177888u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177990_0x177990(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177888u; }
        if (ctx->pc != 0x177888u) { return; }
    }
    ctx->pc = 0x177888u;
label_177888:
    // 0x177888: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x177888u;
    {
        const bool branch_taken_0x177888 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17788Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177888u;
            // 0x17788c: 0x8e220020  lw          $v0, 0x20($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x177888) {
            ctx->pc = 0x1778A4u;
            goto label_1778a4;
        }
    }
    ctx->pc = 0x177890u;
label_177890:
    // 0x177890: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x177890u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x177894: 0xc05d518  jal         func_175460
    ctx->pc = 0x177894u;
    SET_GPR_U32(ctx, 31, 0x17789Cu);
    ctx->pc = 0x177898u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x177894u;
            // 0x177898: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175460u;
    if (runtime->hasFunction(0x175460u)) {
        auto targetFn = runtime->lookupFunction(0x175460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17789Cu; }
        if (ctx->pc != 0x17789Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175460_0x175460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17789Cu; }
        if (ctx->pc != 0x17789Cu) { return; }
    }
    ctx->pc = 0x17789Cu;
label_17789c:
    // 0x17789c: 0xae000b48  sw          $zero, 0xB48($s0)
    ctx->pc = 0x17789cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 2888), GPR_U32(ctx, 0));
    // 0x1778a0: 0x8e220020  lw          $v0, 0x20($s1)
    ctx->pc = 0x1778a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 32)));
label_1778a4:
    // 0x1778a4: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1778A4u;
    {
        const bool branch_taken_0x1778a4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1778A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1778A4u;
            // 0x1778a8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1778a4) {
            ctx->pc = 0x1778D8u;
            goto label_1778d8;
        }
    }
    ctx->pc = 0x1778ACu;
    // 0x1778ac: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1778acu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1778b0: 0xc05deac  jal         func_177AB0
    ctx->pc = 0x1778B0u;
    SET_GPR_U32(ctx, 31, 0x1778B8u);
    ctx->pc = 0x1778B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1778B0u;
            // 0x1778b4: 0x24060007  addiu       $a2, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177AB0u;
    if (runtime->hasFunction(0x177AB0u)) {
        auto targetFn = runtime->lookupFunction(0x177AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1778B8u; }
        if (ctx->pc != 0x1778B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177AB0_0x177ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1778B8u; }
        if (ctx->pc != 0x1778B8u) { return; }
    }
    ctx->pc = 0x1778B8u;
label_1778b8:
    // 0x1778b8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1778b8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1778bc: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1778bcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1778c0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1778c0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1778c4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1778c4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1778c8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1778c8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1778cc: 0x805de8c  j           func_177A30
    ctx->pc = 0x1778CCu;
    ctx->pc = 0x1778D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1778CCu;
            // 0x1778d0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177A30u;
    if (runtime->hasFunction(0x177A30u)) {
        auto targetFn = runtime->lookupFunction(0x177A30u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00177A30_0x177a30(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1778D4u;
    // 0x1778d4: 0x0  nop
    ctx->pc = 0x1778d4u;
    // NOP
label_1778d8:
    // 0x1778d8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1778d8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1778dc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1778dcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1778e0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1778e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1778e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1778E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1778E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1778E4u;
            // 0x1778e8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x177824u: goto label_177824;
            case 0x177844u: goto label_177844;
            case 0x177850u: goto label_177850;
            case 0x177858u: goto label_177858;
            case 0x177860u: goto label_177860;
            case 0x177868u: goto label_177868;
            case 0x17787Cu: goto label_17787c;
            case 0x177888u: goto label_177888;
            case 0x177890u: goto label_177890;
            case 0x17789Cu: goto label_17789c;
            case 0x1778A4u: goto label_1778a4;
            case 0x1778B8u: goto label_1778b8;
            case 0x1778D8u: goto label_1778d8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1778ECu;
    // 0x1778ec: 0x0  nop
    ctx->pc = 0x1778ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
