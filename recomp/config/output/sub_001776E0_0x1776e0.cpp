#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001776E0
// Address: 0x1776e0 - 0x177800
void sub_001776E0_0x1776e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001776E0_0x1776e0");
#endif

    switch (ctx->pc) {
        case 0x17770cu: goto label_17770c;
        case 0x177718u: goto label_177718;
        case 0x177734u: goto label_177734;
        case 0x177740u: goto label_177740;
        case 0x177750u: goto label_177750;
        case 0x17776cu: goto label_17776c;
        case 0x177778u: goto label_177778;
        case 0x177788u: goto label_177788;
        case 0x1777a4u: goto label_1777a4;
        case 0x1777b0u: goto label_1777b0;
        case 0x1777c0u: goto label_1777c0;
        case 0x1777d0u: goto label_1777d0;
        default: break;
    }

    ctx->pc = 0x1776e0u;

    // 0x1776e0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1776e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1776e4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1776e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1776e8: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1776e8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1776ec: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1776ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1776f0: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1776f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1776f4: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x1776f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1776f8: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1776F8u;
    {
        const bool branch_taken_0x1776f8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1776FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1776F8u;
            // 0x1776fc: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1776f8) {
            ctx->pc = 0x177720u;
            goto label_177720;
        }
    }
    ctx->pc = 0x177700u;
    // 0x177700: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x177700u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177704: 0xc05de94  jal         func_177A50
    ctx->pc = 0x177704u;
    SET_GPR_U32(ctx, 31, 0x17770Cu);
    ctx->pc = 0x177708u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x177704u;
            // 0x177708: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177A50u;
    if (runtime->hasFunction(0x177A50u)) {
        auto targetFn = runtime->lookupFunction(0x177A50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17770Cu; }
        if (ctx->pc != 0x17770Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177A50_0x177a50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17770Cu; }
        if (ctx->pc != 0x17770Cu) { return; }
    }
    ctx->pc = 0x17770Cu;
label_17770c:
    // 0x17770c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x17770cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177710: 0xc05de00  jal         func_177800
    ctx->pc = 0x177710u;
    SET_GPR_U32(ctx, 31, 0x177718u);
    ctx->pc = 0x177714u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x177710u;
            // 0x177714: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177800u;
    if (runtime->hasFunction(0x177800u)) {
        auto targetFn = runtime->lookupFunction(0x177800u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177718u; }
        if (ctx->pc != 0x177718u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177800_0x177800(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177718u; }
        if (ctx->pc != 0x177718u) { return; }
    }
    ctx->pc = 0x177718u;
label_177718:
    // 0x177718: 0x10000034  b           . + 4 + (0x34 << 2)
    ctx->pc = 0x177718u;
    {
        const bool branch_taken_0x177718 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17771Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177718u;
            // 0x17771c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x177718) {
            ctx->pc = 0x1777ECu;
            goto label_1777ec;
        }
    }
    ctx->pc = 0x177720u;
label_177720:
    // 0x177720: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x177720u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x177724: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x177724u;
    {
        const bool branch_taken_0x177724 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x177728u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177724u;
            // 0x177728: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x177724) {
            ctx->pc = 0x177758u;
            goto label_177758;
        }
    }
    ctx->pc = 0x17772Cu;
    // 0x17772c: 0xc05de94  jal         func_177A50
    ctx->pc = 0x17772Cu;
    SET_GPR_U32(ctx, 31, 0x177734u);
    ctx->pc = 0x177730u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17772Cu;
            // 0x177730: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177A50u;
    if (runtime->hasFunction(0x177A50u)) {
        auto targetFn = runtime->lookupFunction(0x177A50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177734u; }
        if (ctx->pc != 0x177734u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177A50_0x177a50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177734u; }
        if (ctx->pc != 0x177734u) { return; }
    }
    ctx->pc = 0x177734u;
label_177734:
    // 0x177734: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x177734u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177738: 0xc05de3c  jal         func_1778F0
    ctx->pc = 0x177738u;
    SET_GPR_U32(ctx, 31, 0x177740u);
    ctx->pc = 0x17773Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x177738u;
            // 0x17773c: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1778F0u;
    if (runtime->hasFunction(0x1778F0u)) {
        auto targetFn = runtime->lookupFunction(0x1778F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177740u; }
        if (ctx->pc != 0x177740u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001778F0_0x1778f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177740u; }
        if (ctx->pc != 0x177740u) { return; }
    }
    ctx->pc = 0x177740u;
label_177740:
    // 0x177740: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x177740u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177744: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x177744u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x177748: 0xc05d518  jal         func_175460
    ctx->pc = 0x177748u;
    SET_GPR_U32(ctx, 31, 0x177750u);
    ctx->pc = 0x17774Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x177748u;
            // 0x17774c: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175460u;
    if (runtime->hasFunction(0x175460u)) {
        auto targetFn = runtime->lookupFunction(0x175460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177750u; }
        if (ctx->pc != 0x177750u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175460_0x175460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177750u; }
        if (ctx->pc != 0x177750u) { return; }
    }
    ctx->pc = 0x177750u;
label_177750:
    // 0x177750: 0x10000025  b           . + 4 + (0x25 << 2)
    ctx->pc = 0x177750u;
    {
        const bool branch_taken_0x177750 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x177754u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177750u;
            // 0x177754: 0xae200b48  sw          $zero, 0xB48($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 2888), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x177750) {
            ctx->pc = 0x1777E8u;
            goto label_1777e8;
        }
    }
    ctx->pc = 0x177758u;
label_177758:
    // 0x177758: 0x8e02000c  lw          $v0, 0xC($s0)
    ctx->pc = 0x177758u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x17775c: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x17775Cu;
    {
        const bool branch_taken_0x17775c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x177760u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17775Cu;
            // 0x177760: 0x24060002  addiu       $a2, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17775c) {
            ctx->pc = 0x177790u;
            goto label_177790;
        }
    }
    ctx->pc = 0x177764u;
    // 0x177764: 0xc05de94  jal         func_177A50
    ctx->pc = 0x177764u;
    SET_GPR_U32(ctx, 31, 0x17776Cu);
    ctx->pc = 0x177768u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x177764u;
            // 0x177768: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177A50u;
    if (runtime->hasFunction(0x177A50u)) {
        auto targetFn = runtime->lookupFunction(0x177A50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17776Cu; }
        if (ctx->pc != 0x17776Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177A50_0x177a50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17776Cu; }
        if (ctx->pc != 0x17776Cu) { return; }
    }
    ctx->pc = 0x17776Cu;
label_17776c:
    // 0x17776c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x17776cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177770: 0xc05de64  jal         func_177990
    ctx->pc = 0x177770u;
    SET_GPR_U32(ctx, 31, 0x177778u);
    ctx->pc = 0x177774u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x177770u;
            // 0x177774: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177990u;
    if (runtime->hasFunction(0x177990u)) {
        auto targetFn = runtime->lookupFunction(0x177990u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177778u; }
        if (ctx->pc != 0x177778u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177990_0x177990(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177778u; }
        if (ctx->pc != 0x177778u) { return; }
    }
    ctx->pc = 0x177778u;
label_177778:
    // 0x177778: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x177778u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17777c: 0x24050005  addiu       $a1, $zero, 0x5
    ctx->pc = 0x17777cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x177780: 0xc05d518  jal         func_175460
    ctx->pc = 0x177780u;
    SET_GPR_U32(ctx, 31, 0x177788u);
    ctx->pc = 0x177784u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x177780u;
            // 0x177784: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175460u;
    if (runtime->hasFunction(0x175460u)) {
        auto targetFn = runtime->lookupFunction(0x175460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177788u; }
        if (ctx->pc != 0x177788u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175460_0x175460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177788u; }
        if (ctx->pc != 0x177788u) { return; }
    }
    ctx->pc = 0x177788u;
label_177788:
    // 0x177788: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x177788u;
    {
        const bool branch_taken_0x177788 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17778Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177788u;
            // 0x17778c: 0xae200b44  sw          $zero, 0xB44($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 2884), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x177788) {
            ctx->pc = 0x1777E8u;
            goto label_1777e8;
        }
    }
    ctx->pc = 0x177790u;
label_177790:
    // 0x177790: 0x8e020020  lw          $v0, 0x20($s0)
    ctx->pc = 0x177790u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x177794: 0x10400012  beqz        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x177794u;
    {
        const bool branch_taken_0x177794 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x177798u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177794u;
            // 0x177798: 0x24060007  addiu       $a2, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        ctx->in_delay_slot = false;
        if (branch_taken_0x177794) {
            ctx->pc = 0x1777E0u;
            goto label_1777e0;
        }
    }
    ctx->pc = 0x17779Cu;
    // 0x17779c: 0xc05de94  jal         func_177A50
    ctx->pc = 0x17779Cu;
    SET_GPR_U32(ctx, 31, 0x1777A4u);
    ctx->pc = 0x1777A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17779Cu;
            // 0x1777a0: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177A50u;
    if (runtime->hasFunction(0x177A50u)) {
        auto targetFn = runtime->lookupFunction(0x177A50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1777A4u; }
        if (ctx->pc != 0x1777A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177A50_0x177a50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1777A4u; }
        if (ctx->pc != 0x1777A4u) { return; }
    }
    ctx->pc = 0x1777A4u;
label_1777a4:
    // 0x1777a4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1777a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1777a8: 0xc05de8c  jal         func_177A30
    ctx->pc = 0x1777A8u;
    SET_GPR_U32(ctx, 31, 0x1777B0u);
    ctx->pc = 0x1777ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1777A8u;
            // 0x1777ac: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177A30u;
    if (runtime->hasFunction(0x177A30u)) {
        auto targetFn = runtime->lookupFunction(0x177A30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1777B0u; }
        if (ctx->pc != 0x1777B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177A30_0x177a30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1777B0u; }
        if (ctx->pc != 0x1777B0u) { return; }
    }
    ctx->pc = 0x1777B0u;
label_1777b0:
    // 0x1777b0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1777b0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1777b4: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x1777b4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1777b8: 0xc05d518  jal         func_175460
    ctx->pc = 0x1777B8u;
    SET_GPR_U32(ctx, 31, 0x1777C0u);
    ctx->pc = 0x1777BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1777B8u;
            // 0x1777bc: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175460u;
    if (runtime->hasFunction(0x175460u)) {
        auto targetFn = runtime->lookupFunction(0x175460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1777C0u; }
        if (ctx->pc != 0x1777C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175460_0x175460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1777C0u; }
        if (ctx->pc != 0x1777C0u) { return; }
    }
    ctx->pc = 0x1777C0u;
label_1777c0:
    // 0x1777c0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1777c0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1777c4: 0x24050005  addiu       $a1, $zero, 0x5
    ctx->pc = 0x1777c4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1777c8: 0xc05d518  jal         func_175460
    ctx->pc = 0x1777C8u;
    SET_GPR_U32(ctx, 31, 0x1777D0u);
    ctx->pc = 0x1777CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1777C8u;
            // 0x1777cc: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175460u;
    if (runtime->hasFunction(0x175460u)) {
        auto targetFn = runtime->lookupFunction(0x175460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1777D0u; }
        if (ctx->pc != 0x1777D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175460_0x175460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1777D0u; }
        if (ctx->pc != 0x1777D0u) { return; }
    }
    ctx->pc = 0x1777D0u;
label_1777d0:
    // 0x1777d0: 0xae200b48  sw          $zero, 0xB48($s1)
    ctx->pc = 0x1777d0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 2888), GPR_U32(ctx, 0));
    // 0x1777d4: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1777D4u;
    {
        const bool branch_taken_0x1777d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1777D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1777D4u;
            // 0x1777d8: 0xae200b44  sw          $zero, 0xB44($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 2884), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1777d4) {
            ctx->pc = 0x1777E8u;
            goto label_1777e8;
        }
    }
    ctx->pc = 0x1777DCu;
    // 0x1777dc: 0x0  nop
    ctx->pc = 0x1777dcu;
    // NOP
label_1777e0:
    // 0x1777e0: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1777E0u;
    {
        const bool branch_taken_0x1777e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1777E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1777E0u;
            // 0x1777e4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1777e0) {
            ctx->pc = 0x1777ECu;
            goto label_1777ec;
        }
    }
    ctx->pc = 0x1777E8u;
label_1777e8:
    // 0x1777e8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1777e8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1777ec:
    // 0x1777ec: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1777ecu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1777f0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1777f0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1777f4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1777f4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1777f8: 0x3e00008  jr          $ra
    ctx->pc = 0x1777F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1777FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1777F8u;
            // 0x1777fc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17770Cu: goto label_17770c;
            case 0x177718u: goto label_177718;
            case 0x177720u: goto label_177720;
            case 0x177734u: goto label_177734;
            case 0x177740u: goto label_177740;
            case 0x177750u: goto label_177750;
            case 0x177758u: goto label_177758;
            case 0x17776Cu: goto label_17776c;
            case 0x177778u: goto label_177778;
            case 0x177788u: goto label_177788;
            case 0x177790u: goto label_177790;
            case 0x1777A4u: goto label_1777a4;
            case 0x1777B0u: goto label_1777b0;
            case 0x1777C0u: goto label_1777c0;
            case 0x1777D0u: goto label_1777d0;
            case 0x1777E0u: goto label_1777e0;
            case 0x1777E8u: goto label_1777e8;
            case 0x1777ECu: goto label_1777ec;
            default: break;
        }
        return;
    }
    ctx->pc = 0x177800u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
