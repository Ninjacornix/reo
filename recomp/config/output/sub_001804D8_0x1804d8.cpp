#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001804D8
// Address: 0x1804d8 - 0x1805b0
void sub_001804D8_0x1804d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001804D8_0x1804d8");
#endif

    switch (ctx->pc) {
        case 0x18052cu: goto label_18052c;
        case 0x18053cu: goto label_18053c;
        case 0x180560u: goto label_180560;
        case 0x180584u: goto label_180584;
        default: break;
    }

    ctx->pc = 0x1804d8u;

    // 0x1804d8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1804d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1804dc: 0x24020334  addiu       $v0, $zero, 0x334
    ctx->pc = 0x1804dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 820));
    // 0x1804e0: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x1804e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x1804e4: 0x3c030027  lui         $v1, 0x27
    ctx->pc = 0x1804e4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)39 << 16));
    // 0x1804e8: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1804e8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1804ec: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x1804ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x1804f0: 0x2222018  mult        $a0, $s1, $v0
    ctx->pc = 0x1804f0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 17) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x1804f4: 0x24666188  addiu       $a2, $v1, 0x6188
    ctx->pc = 0x1804f4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), 24968));
    // 0x1804f8: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1804f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1804fc: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1804fcu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180500: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x180500u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x180504: 0x861021  addu        $v0, $a0, $a2
    ctx->pc = 0x180504u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
    // 0x180508: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x180508u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x18050c: 0x10600021  beqz        $v1, . + 4 + (0x21 << 2)
    ctx->pc = 0x18050Cu;
    {
        const bool branch_taken_0x18050c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x180510u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18050Cu;
            // 0x180510: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18050c) {
            ctx->pc = 0x180594u;
            goto label_180594;
        }
    }
    ctx->pc = 0x180514u;
    // 0x180514: 0xc41021  addu        $v0, $a2, $a0
    ctx->pc = 0x180514u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
    // 0x180518: 0x8c430004  lw          $v1, 0x4($v0)
    ctx->pc = 0x180518u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x18051c: 0x14600005  bnez        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x18051Cu;
    {
        const bool branch_taken_0x18051c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x18051c) {
            ctx->pc = 0x180534u;
            goto label_180534;
        }
    }
    ctx->pc = 0x180524u;
    // 0x180524: 0xc060246  jal         func_180918
    ctx->pc = 0x180524u;
    SET_GPR_U32(ctx, 31, 0x18052Cu);
    ctx->pc = 0x180528u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x180524u;
            // 0x180528: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x180918u;
    if (runtime->hasFunction(0x180918u)) {
        auto targetFn = runtime->lookupFunction(0x180918u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18052Cu; }
        if (ctx->pc != 0x18052Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00180918_0x180918(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18052Cu; }
        if (ctx->pc != 0x18052Cu) { return; }
    }
    ctx->pc = 0x18052Cu;
label_18052c:
    // 0x18052c: 0x4400019  bltz        $v0, . + 4 + (0x19 << 2)
    ctx->pc = 0x18052Cu;
    {
        const bool branch_taken_0x18052c = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x180530u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18052Cu;
            // 0x180530: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18052c) {
            ctx->pc = 0x180594u;
            goto label_180594;
        }
    }
    ctx->pc = 0x180534u;
label_180534:
    // 0x180534: 0xc06025c  jal         func_180970
    ctx->pc = 0x180534u;
    SET_GPR_U32(ctx, 31, 0x18053Cu);
    ctx->pc = 0x180538u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x180534u;
            // 0x180538: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x180970u;
    if (runtime->hasFunction(0x180970u)) {
        auto targetFn = runtime->lookupFunction(0x180970u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18053Cu; }
        if (ctx->pc != 0x18053Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00180970_0x180970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18053Cu; }
        if (ctx->pc != 0x18053Cu) { return; }
    }
    ctx->pc = 0x18053Cu;
label_18053c:
    // 0x18053c: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x18053cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180540: 0x92020002  lbu         $v0, 0x2($s0)
    ctx->pc = 0x180540u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x180544: 0x50400010  beql        $v0, $zero, . + 4 + (0x10 << 2)
    ctx->pc = 0x180544u;
    {
        const bool branch_taken_0x180544 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x180544) {
            ctx->pc = 0x180548u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x180544u;
            // 0x180548: 0x8e020004  lw          $v0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x180588u;
            goto label_180588;
        }
    }
    ctx->pc = 0x18054Cu;
    // 0x18054c: 0x2605001c  addiu       $a1, $s0, 0x1C
    ctx->pc = 0x18054cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 28));
    // 0x180550: 0x10a0000c  beqz        $a1, . + 4 + (0xC << 2)
    ctx->pc = 0x180550u;
    {
        const bool branch_taken_0x180550 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x180554u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180550u;
            // 0x180554: 0x40302d  daddu       $a2, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x180550) {
            ctx->pc = 0x180584u;
            goto label_180584;
        }
    }
    ctx->pc = 0x180558u;
    // 0x180558: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x180558u;
    SET_GPR_U32(ctx, 31, 0x180560u);
    ctx->pc = 0x18055Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x180558u;
            // 0x18055c: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180560u; }
        if (ctx->pc != 0x180560u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180560u; }
        if (ctx->pc != 0x180560u) { return; }
    }
    ctx->pc = 0x180560u;
label_180560:
    // 0x180560: 0x24030334  addiu       $v1, $zero, 0x334
    ctx->pc = 0x180560u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 820));
    // 0x180564: 0x92040002  lbu         $a0, 0x2($s0)
    ctx->pc = 0x180564u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x180568: 0x2231818  mult        $v1, $s1, $v1
    ctx->pc = 0x180568u;
    { int64_t result = (int64_t)GPR_S32(ctx, 17) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x18056c: 0x3c050027  lui         $a1, 0x27
    ctx->pc = 0x18056cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)39 << 16));
    // 0x180570: 0x2484001c  addiu       $a0, $a0, 0x1C
    ctx->pc = 0x180570u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 28));
    // 0x180574: 0x24a5619c  addiu       $a1, $a1, 0x619C
    ctx->pc = 0x180574u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 24988));
    // 0x180578: 0x2042021  addu        $a0, $s0, $a0
    ctx->pc = 0x180578u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 4)));
    // 0x18057c: 0xc0602a8  jal         func_180AA0
    ctx->pc = 0x18057Cu;
    SET_GPR_U32(ctx, 31, 0x180584u);
    ctx->pc = 0x180580u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18057Cu;
            // 0x180580: 0x652821  addu        $a1, $v1, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x180AA0u;
    if (runtime->hasFunction(0x180AA0u)) {
        auto targetFn = runtime->lookupFunction(0x180AA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180584u; }
        if (ctx->pc != 0x180584u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00180AA0_0x180aa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180584u; }
        if (ctx->pc != 0x180584u) { return; }
    }
    ctx->pc = 0x180584u;
label_180584:
    // 0x180584: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x180584u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
label_180588:
    // 0x180588: 0x54400002  bnel        $v0, $zero, . + 4 + (0x2 << 2)
    ctx->pc = 0x180588u;
    {
        const bool branch_taken_0x180588 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x180588) {
            ctx->pc = 0x18058Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x180588u;
            // 0x18058c: 0x92020002  lbu         $v0, 0x2($s0) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x180594u;
            goto label_180594;
        }
    }
    ctx->pc = 0x180590u;
    // 0x180590: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x180590u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_180594:
    // 0x180594: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x180594u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x180598: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x180598u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x18059c: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x18059cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1805a0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1805a0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1805a4: 0x3e00008  jr          $ra
    ctx->pc = 0x1805A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1805A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1805A4u;
            // 0x1805a8: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18052Cu: goto label_18052c;
            case 0x180534u: goto label_180534;
            case 0x18053Cu: goto label_18053c;
            case 0x180560u: goto label_180560;
            case 0x180584u: goto label_180584;
            case 0x180588u: goto label_180588;
            case 0x180594u: goto label_180594;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1805ACu;
    // 0x1805ac: 0x0  nop
    ctx->pc = 0x1805acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
