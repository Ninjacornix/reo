#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001682E0
// Address: 0x1682e0 - 0x168378
void sub_001682E0_0x1682e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001682E0_0x1682e0");
#endif

    switch (ctx->pc) {
        case 0x168308u: goto label_168308;
        case 0x168318u: goto label_168318;
        case 0x168330u: goto label_168330;
        case 0x168348u: goto label_168348;
        case 0x168360u: goto label_168360;
        default: break;
    }

    ctx->pc = 0x1682e0u;

    // 0x1682e0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1682e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1682e4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1682e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1682e8: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x1682e8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1682ec: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1682ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1682f0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1682f0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1682f4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1682f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1682f8: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1682f8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1682fc: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1682fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x168300: 0xc05a0de  jal         func_168378
    ctx->pc = 0x168300u;
    SET_GPR_U32(ctx, 31, 0x168308u);
    ctx->pc = 0x168304u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x168300u;
            // 0x168304: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x168378u;
    if (runtime->hasFunction(0x168378u)) {
        auto targetFn = runtime->lookupFunction(0x168378u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168308u; }
        if (ctx->pc != 0x168308u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00168378_0x168378(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168308u; }
        if (ctx->pc != 0x168308u) { return; }
    }
    ctx->pc = 0x168308u;
label_168308:
    // 0x168308: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x168308u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16830c: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x16830cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168310: 0xc05a0f6  jal         func_1683D8
    ctx->pc = 0x168310u;
    SET_GPR_U32(ctx, 31, 0x168318u);
    ctx->pc = 0x168314u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x168310u;
            // 0x168314: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1683D8u;
    if (runtime->hasFunction(0x1683D8u)) {
        auto targetFn = runtime->lookupFunction(0x1683D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168318u; }
        if (ctx->pc != 0x168318u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001683D8_0x1683d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168318u; }
        if (ctx->pc != 0x168318u) { return; }
    }
    ctx->pc = 0x168318u;
label_168318:
    // 0x168318: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x168318u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16831c: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x16831cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168320: 0x1440000f  bnez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x168320u;
    {
        const bool branch_taken_0x168320 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x168324u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168320u;
            // 0x168324: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168320) {
            ctx->pc = 0x168360u;
            goto label_168360;
        }
    }
    ctx->pc = 0x168328u;
    // 0x168328: 0xc05a370  jal         func_168DC0
    ctx->pc = 0x168328u;
    SET_GPR_U32(ctx, 31, 0x168330u);
    ctx->pc = 0x168DC0u;
    if (runtime->hasFunction(0x168DC0u)) {
        auto targetFn = runtime->lookupFunction(0x168DC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168330u; }
        if (ctx->pc != 0x168330u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00168DC0_0x168dc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168330u; }
        if (ctx->pc != 0x168330u) { return; }
    }
    ctx->pc = 0x168330u;
label_168330:
    // 0x168330: 0x5440000c  bnel        $v0, $zero, . + 4 + (0xC << 2)
    ctx->pc = 0x168330u;
    {
        const bool branch_taken_0x168330 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x168330) {
            ctx->pc = 0x168334u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x168330u;
            // 0x168334: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x168364u;
            goto label_168364;
        }
    }
    ctx->pc = 0x168338u;
    // 0x168338: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x168338u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16833c: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x16833cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168340: 0xc05a242  jal         func_168908
    ctx->pc = 0x168340u;
    SET_GPR_U32(ctx, 31, 0x168348u);
    ctx->pc = 0x168344u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x168340u;
            // 0x168344: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x168908u;
    if (runtime->hasFunction(0x168908u)) {
        auto targetFn = runtime->lookupFunction(0x168908u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168348u; }
        if (ctx->pc != 0x168348u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00168908_0x168908(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168348u; }
        if (ctx->pc != 0x168348u) { return; }
    }
    ctx->pc = 0x168348u;
label_168348:
    // 0x168348: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x168348u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16834c: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x16834cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168350: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x168350u;
    {
        const bool branch_taken_0x168350 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x168354u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168350u;
            // 0x168354: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168350) {
            ctx->pc = 0x168360u;
            goto label_168360;
        }
    }
    ctx->pc = 0x168358u;
    // 0x168358: 0xc05a2ea  jal         func_168BA8
    ctx->pc = 0x168358u;
    SET_GPR_U32(ctx, 31, 0x168360u);
    ctx->pc = 0x168BA8u;
    if (runtime->hasFunction(0x168BA8u)) {
        auto targetFn = runtime->lookupFunction(0x168BA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168360u; }
        if (ctx->pc != 0x168360u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00168BA8_0x168ba8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168360u; }
        if (ctx->pc != 0x168360u) { return; }
    }
    ctx->pc = 0x168360u;
label_168360:
    // 0x168360: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x168360u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_168364:
    // 0x168364: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x168364u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x168368: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x168368u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16836c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x16836cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x168370: 0x3e00008  jr          $ra
    ctx->pc = 0x168370u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x168374u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168370u;
            // 0x168374: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x168308u: goto label_168308;
            case 0x168318u: goto label_168318;
            case 0x168330u: goto label_168330;
            case 0x168348u: goto label_168348;
            case 0x168360u: goto label_168360;
            case 0x168364u: goto label_168364;
            default: break;
        }
        return;
    }
    ctx->pc = 0x168378u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
