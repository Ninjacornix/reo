#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00176808
// Address: 0x176808 - 0x1768c8
void sub_00176808_0x176808(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00176808_0x176808");
#endif

    switch (ctx->pc) {
        case 0x176828u: goto label_176828;
        case 0x17686cu: goto label_17686c;
        case 0x17687cu: goto label_17687c;
        case 0x176898u: goto label_176898;
        case 0x1768a8u: goto label_1768a8;
        default: break;
    }

    ctx->pc = 0x176808u;

    // 0x176808: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x176808u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17680c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17680cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x176810: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x176810u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176814: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x176814u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x176818: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x176818u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17681c: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x17681cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x176820: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x176820u;
    SET_GPR_U32(ctx, 31, 0x176828u);
    ctx->pc = 0x176824u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x176820u;
            // 0x176824: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176828u; }
        if (ctx->pc != 0x176828u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176828u; }
        if (ctx->pc != 0x176828u) { return; }
    }
    ctx->pc = 0x176828u;
label_176828:
    // 0x176828: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x176828u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x17682c: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x17682Cu;
    {
        const bool branch_taken_0x17682c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x176830u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17682Cu;
            // 0x176830: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17682c) {
            ctx->pc = 0x176850u;
            goto label_176850;
        }
    }
    ctx->pc = 0x176834u;
    // 0x176834: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x176834u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x176838: 0x34a50129  ori         $a1, $a1, 0x129
    ctx->pc = 0x176838u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)297);
    // 0x17683c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17683cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x176840: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x176840u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x176844: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x176844u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x176848: 0x805a704  j           func_169C10
    ctx->pc = 0x176848u;
    ctx->pc = 0x17684Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x176848u;
            // 0x17684c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x176850u;
label_176850:
    // 0x176850: 0x1220000d  beqz        $s1, . + 4 + (0xD << 2)
    ctx->pc = 0x176850u;
    {
        const bool branch_taken_0x176850 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x176854u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176850u;
            // 0x176854: 0x26120cc0  addiu       $s2, $s0, 0xCC0 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 16), 3264));
        ctx->in_delay_slot = false;
        if (branch_taken_0x176850) {
            ctx->pc = 0x176888u;
            goto label_176888;
        }
    }
    ctx->pc = 0x176858u;
    // 0x176858: 0xae510290  sw          $s1, 0x290($s2)
    ctx->pc = 0x176858u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 656), GPR_U32(ctx, 17));
    // 0x17685c: 0x2405000f  addiu       $a1, $zero, 0xF
    ctx->pc = 0x17685cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x176860: 0x24060005  addiu       $a2, $zero, 0x5
    ctx->pc = 0x176860u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x176864: 0xc05d518  jal         func_175460
    ctx->pc = 0x176864u;
    SET_GPR_U32(ctx, 31, 0x17686Cu);
    ctx->pc = 0x176868u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x176864u;
            // 0x176868: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175460u;
    if (runtime->hasFunction(0x175460u)) {
        auto targetFn = runtime->lookupFunction(0x175460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17686Cu; }
        if (ctx->pc != 0x17686Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175460_0x175460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17686Cu; }
        if (ctx->pc != 0x17686Cu) { return; }
    }
    ctx->pc = 0x17686Cu;
label_17686c:
    // 0x17686c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17686cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176870: 0x24050047  addiu       $a1, $zero, 0x47
    ctx->pc = 0x176870u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 71));
    // 0x176874: 0xc05d518  jal         func_175460
    ctx->pc = 0x176874u;
    SET_GPR_U32(ctx, 31, 0x17687Cu);
    ctx->pc = 0x176878u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x176874u;
            // 0x176878: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175460u;
    if (runtime->hasFunction(0x175460u)) {
        auto targetFn = runtime->lookupFunction(0x175460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17687Cu; }
        if (ctx->pc != 0x17687Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175460_0x175460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17687Cu; }
        if (ctx->pc != 0x17687Cu) { return; }
    }
    ctx->pc = 0x17687Cu;
label_17687c:
    // 0x17687c: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x17687Cu;
    {
        const bool branch_taken_0x17687c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x176880u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17687Cu;
            // 0x176880: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17687c) {
            ctx->pc = 0x1768B0u;
            goto label_1768b0;
        }
    }
    ctx->pc = 0x176884u;
    // 0x176884: 0x0  nop
    ctx->pc = 0x176884u;
    // NOP
label_176888:
    // 0x176888: 0x24050047  addiu       $a1, $zero, 0x47
    ctx->pc = 0x176888u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 71));
    // 0x17688c: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x17688cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x176890: 0xc05d518  jal         func_175460
    ctx->pc = 0x176890u;
    SET_GPR_U32(ctx, 31, 0x176898u);
    ctx->pc = 0x176894u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x176890u;
            // 0x176894: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175460u;
    if (runtime->hasFunction(0x175460u)) {
        auto targetFn = runtime->lookupFunction(0x175460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176898u; }
        if (ctx->pc != 0x176898u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175460_0x175460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176898u; }
        if (ctx->pc != 0x176898u) { return; }
    }
    ctx->pc = 0x176898u;
label_176898:
    // 0x176898: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x176898u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17689c: 0x2405000f  addiu       $a1, $zero, 0xF
    ctx->pc = 0x17689cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x1768a0: 0xc05d518  jal         func_175460
    ctx->pc = 0x1768A0u;
    SET_GPR_U32(ctx, 31, 0x1768A8u);
    ctx->pc = 0x1768A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1768A0u;
            // 0x1768a4: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175460u;
    if (runtime->hasFunction(0x175460u)) {
        auto targetFn = runtime->lookupFunction(0x175460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1768A8u; }
        if (ctx->pc != 0x1768A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175460_0x175460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1768A8u; }
        if (ctx->pc != 0x1768A8u) { return; }
    }
    ctx->pc = 0x1768A8u;
label_1768a8:
    // 0x1768a8: 0xae400290  sw          $zero, 0x290($s2)
    ctx->pc = 0x1768a8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 656), GPR_U32(ctx, 0));
    // 0x1768ac: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1768acu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1768b0:
    // 0x1768b0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1768b0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1768b4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1768b4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1768b8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1768b8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1768bc: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1768bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1768c0: 0x3e00008  jr          $ra
    ctx->pc = 0x1768C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1768C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1768C0u;
            // 0x1768c4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x176828u: goto label_176828;
            case 0x176850u: goto label_176850;
            case 0x17686Cu: goto label_17686c;
            case 0x17687Cu: goto label_17687c;
            case 0x176888u: goto label_176888;
            case 0x176898u: goto label_176898;
            case 0x1768A8u: goto label_1768a8;
            case 0x1768B0u: goto label_1768b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1768C8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
