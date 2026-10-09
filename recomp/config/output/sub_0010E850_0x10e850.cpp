#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010E850
// Address: 0x10e850 - 0x10ea10
void sub_0010E850_0x10e850(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010E850_0x10e850");
#endif

    switch (ctx->pc) {
        case 0x10e8e4u: goto label_10e8e4;
        case 0x10e910u: goto label_10e910;
        case 0x10e95cu: goto label_10e95c;
        case 0x10e984u: goto label_10e984;
        case 0x10e9a8u: goto label_10e9a8;
        default: break;
    }

    ctx->pc = 0x10e850u;

    // 0x10e850: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x10e850u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x10e854: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x10e854u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x10e858: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x10e858u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x10e85c: 0x140882d  daddu       $s1, $t2, $zero
    ctx->pc = 0x10e85cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10e860: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x10e860u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x10e864: 0x100802d  daddu       $s0, $t0, $zero
    ctx->pc = 0x10e864u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10e868: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x10e868u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x10e86c: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x10e86cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10e870: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x10e870u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x10e874: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x10e874u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10e878: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x10e878u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x10e87c: 0x24140003  addiu       $s4, $zero, 0x3
    ctx->pc = 0x10e87cu;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x10e880: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x10e880u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x10e884: 0x120a82d  daddu       $s5, $t1, $zero
    ctx->pc = 0x10e884u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10e888: 0xffb60040  sd          $s6, 0x40($sp)
    ctx->pc = 0x10e888u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 22));
    // 0x10e88c: 0x80b02d  daddu       $s6, $a0, $zero
    ctx->pc = 0x10e88cu;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10e890: 0xffb70048  sd          $s7, 0x48($sp)
    ctx->pc = 0x10e890u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 23));
    // 0x10e894: 0xe0b82d  daddu       $s7, $a3, $zero
    ctx->pc = 0x10e894u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10e898: 0xffbe0050  sd          $fp, 0x50($sp)
    ctx->pc = 0x10e898u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 30));
    // 0x10e89c: 0x160f02d  daddu       $fp, $t3, $zero
    ctx->pc = 0x10e89cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10e8a0: 0x12220008  beq         $s1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x10E8A0u;
    {
        const bool branch_taken_0x10e8a0 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 2));
        ctx->pc = 0x10E8A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E8A0u;
            // 0x10e8a4: 0xffbf0058  sd          $ra, 0x58($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e8a0) {
            ctx->pc = 0x10E8C4u;
            goto label_10e8c4;
        }
    }
    ctx->pc = 0x10E8A8u;
    // 0x10e8a8: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x10e8a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x10e8ac: 0x12220003  beq         $s1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x10E8ACu;
    {
        const bool branch_taken_0x10e8ac = (GPR_U64(ctx, 17) == GPR_U64(ctx, 2));
        ctx->pc = 0x10E8B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E8ACu;
            // 0x10e8b0: 0x24020045  addiu       $v0, $zero, 0x45 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 69));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e8ac) {
            ctx->pc = 0x10E8BCu;
            goto label_10e8bc;
        }
    }
    ctx->pc = 0x10E8B4u;
    // 0x10e8b4: 0x16220003  bne         $s1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x10E8B4u;
    {
        const bool branch_taken_0x10e8b4 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        ctx->pc = 0x10E8B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E8B4u;
            // 0x10e8b8: 0x24140002  addiu       $s4, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e8b4) {
            ctx->pc = 0x10E8C4u;
            goto label_10e8c4;
        }
    }
    ctx->pc = 0x10E8BCu;
label_10e8bc:
    // 0x10e8bc: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x10e8bcu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x10e8c0: 0x24140002  addiu       $s4, $zero, 0x2
    ctx->pc = 0x10e8c0u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
label_10e8c4:
    // 0x10e8c4: 0x240102d  daddu       $v0, $s2, $zero
    ctx->pc = 0x10e8c4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10e8c8: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x10e8c8u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x10e8cc: 0x4430008  bgezl       $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x10E8CCu;
    {
        const bool branch_taken_0x10e8cc = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x10e8cc) {
            ctx->pc = 0x10E8D0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10E8CCu;
            // 0x10e8d0: 0xa2000000  sb          $zero, 0x0($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10E8F0u;
            goto label_10e8f0;
        }
    }
    ctx->pc = 0x10E8D4u;
    // 0x10e8d4: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x10e8d4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10e8d8: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x10e8d8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10e8dc: 0xc044752  jal         func_111D48
    ctx->pc = 0x10E8DCu;
    SET_GPR_U32(ctx, 31, 0x10E8E4u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E8E4u; }
        if (ctx->pc != 0x10E8E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E8E4u; }
        if (ctx->pc != 0x10E8E4u) { return; }
    }
    ctx->pc = 0x10E8E4u;
label_10e8e4:
    // 0x10e8e4: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x10e8e4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10e8e8: 0x2402002d  addiu       $v0, $zero, 0x2D
    ctx->pc = 0x10e8e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 45));
    // 0x10e8ec: 0xa2020000  sb          $v0, 0x0($s0)
    ctx->pc = 0x10e8ecu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 2));
label_10e8f0:
    // 0x10e8f0: 0x280302d  daddu       $a2, $s4, $zero
    ctx->pc = 0x10e8f0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10e8f4: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x10e8f4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10e8f8: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x10e8f8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10e8fc: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x10e8fcu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10e900: 0x2a0402d  daddu       $t0, $s5, $zero
    ctx->pc = 0x10e900u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10e904: 0x3a0482d  daddu       $t1, $sp, $zero
    ctx->pc = 0x10e904u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10e908: 0xc040f1e  jal         func_103C78
    ctx->pc = 0x10E908u;
    SET_GPR_U32(ctx, 31, 0x10E910u);
    ctx->pc = 0x10E90Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10E908u;
            // 0x10e90c: 0x27aa0004  addiu       $t2, $sp, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x103C78u;
    if (runtime->hasFunction(0x103C78u)) {
        auto targetFn = runtime->lookupFunction(0x103C78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E910u; }
        if (ctx->pc != 0x10E910u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103C78_0x103c78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E910u; }
        if (ctx->pc != 0x10E910u) { return; }
    }
    ctx->pc = 0x10E910u;
label_10e910:
    // 0x10e910: 0x40a02d  daddu       $s4, $v0, $zero
    ctx->pc = 0x10e910u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10e914: 0x24020067  addiu       $v0, $zero, 0x67
    ctx->pc = 0x10e914u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 103));
    // 0x10e918: 0x12220003  beq         $s1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x10E918u;
    {
        const bool branch_taken_0x10e918 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 2));
        ctx->pc = 0x10E91Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E918u;
            // 0x10e91c: 0x24020047  addiu       $v0, $zero, 0x47 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 71));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e918) {
            ctx->pc = 0x10E928u;
            goto label_10e928;
        }
    }
    ctx->pc = 0x10E920u;
    // 0x10e920: 0x16220004  bne         $s1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x10E920u;
    {
        const bool branch_taken_0x10e920 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        ctx->pc = 0x10E924u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E920u;
            // 0x10e924: 0x24020066  addiu       $v0, $zero, 0x66 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e920) {
            ctx->pc = 0x10E934u;
            goto label_10e934;
        }
    }
    ctx->pc = 0x10E928u;
label_10e928:
    // 0x10e928: 0x32e20001  andi        $v0, $s7, 0x1
    ctx->pc = 0x10e928u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 23) & (uint64_t)(uint16_t)1);
    // 0x10e92c: 0x10400028  beqz        $v0, . + 4 + (0x28 << 2)
    ctx->pc = 0x10E92Cu;
    {
        const bool branch_taken_0x10e92c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10E930u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E92Cu;
            // 0x10e930: 0x24020066  addiu       $v0, $zero, 0x66 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e92c) {
            ctx->pc = 0x10E9D0u;
            goto label_10e9d0;
        }
    }
    ctx->pc = 0x10E934u;
label_10e934:
    // 0x10e934: 0x1622000f  bne         $s1, $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x10E934u;
    {
        const bool branch_taken_0x10e934 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        ctx->pc = 0x10E938u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E934u;
            // 0x10e938: 0x2938021  addu        $s0, $s4, $s3 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 19)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e934) {
            ctx->pc = 0x10E974u;
            goto label_10e974;
        }
    }
    ctx->pc = 0x10E93Cu;
    // 0x10e93c: 0x82830000  lb          $v1, 0x0($s4)
    ctx->pc = 0x10e93cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x10e940: 0x24020030  addiu       $v0, $zero, 0x30
    ctx->pc = 0x10e940u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
    // 0x10e944: 0x5462000a  bnel        $v1, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x10E944u;
    {
        const bool branch_taken_0x10e944 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x10e944) {
            ctx->pc = 0x10E948u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10E944u;
            // 0x10e948: 0x8ea20000  lw          $v0, 0x0($s5) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10E970u;
            goto label_10e970;
        }
    }
    ctx->pc = 0x10E94Cu;
    // 0x10e94c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x10e94cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10e950: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x10e950u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10e954: 0xc0448a6  jal         func_112298
    ctx->pc = 0x10E954u;
    SET_GPR_U32(ctx, 31, 0x10E95Cu);
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E95Cu; }
        if (ctx->pc != 0x10E95Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E95Cu; }
        if (ctx->pc != 0x10E95Cu) { return; }
    }
    ctx->pc = 0x10E95Cu;
label_10e95c:
    // 0x10e95c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x10E95Cu;
    {
        const bool branch_taken_0x10e95c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10E960u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E95Cu;
            // 0x10e960: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e95c) {
            ctx->pc = 0x10E96Cu;
            goto label_10e96c;
        }
    }
    ctx->pc = 0x10E964u;
    // 0x10e964: 0x531023  subu        $v0, $v0, $s3
    ctx->pc = 0x10e964u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x10e968: 0xaea20000  sw          $v0, 0x0($s5)
    ctx->pc = 0x10e968u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 2));
label_10e96c:
    // 0x10e96c: 0x8ea20000  lw          $v0, 0x0($s5)
    ctx->pc = 0x10e96cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 0)));
label_10e970:
    // 0x10e970: 0x2028021  addu        $s0, $s0, $v0
    ctx->pc = 0x10e970u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
label_10e974:
    // 0x10e974: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x10e974u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10e978: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x10e978u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10e97c: 0xc0448a6  jal         func_112298
    ctx->pc = 0x10E97Cu;
    SET_GPR_U32(ctx, 31, 0x10E984u);
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E984u; }
        if (ctx->pc != 0x10E984u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E984u; }
        if (ctx->pc != 0x10E984u) { return; }
    }
    ctx->pc = 0x10E984u;
label_10e984:
    // 0x10e984: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x10e984u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x10e988: 0x38420000  xori        $v0, $v0, 0x0
    ctx->pc = 0x10e988u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)0);
    // 0x10e98c: 0x202180a  movz        $v1, $s0, $v0
    ctx->pc = 0x10e98cu;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 16));
    // 0x10e990: 0x70102b  sltu        $v0, $v1, $s0
    ctx->pc = 0x10e990u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
    // 0x10e994: 0xafa30004  sw          $v1, 0x4($sp)
    ctx->pc = 0x10e994u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 3));
    // 0x10e998: 0x1040000e  beqz        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x10E998u;
    {
        const bool branch_taken_0x10e998 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10E99Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E998u;
            // 0x10e99c: 0x60202d  daddu       $a0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e998) {
            ctx->pc = 0x10E9D4u;
            goto label_10e9d4;
        }
    }
    ctx->pc = 0x10E9A0u;
    // 0x10e9a0: 0x24050030  addiu       $a1, $zero, 0x30
    ctx->pc = 0x10e9a0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
    // 0x10e9a4: 0x0  nop
    ctx->pc = 0x10e9a4u;
    // NOP
label_10e9a8:
    // 0x10e9a8: 0x24830001  addiu       $v1, $a0, 0x1
    ctx->pc = 0x10e9a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x10e9ac: 0xa0850000  sb          $a1, 0x0($a0)
    ctx->pc = 0x10e9acu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x10e9b0: 0x70102b  sltu        $v0, $v1, $s0
    ctx->pc = 0x10e9b0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
    // 0x10e9b4: 0xafa30004  sw          $v1, 0x4($sp)
    ctx->pc = 0x10e9b4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 3));
    // 0x10e9b8: 0x0  nop
    ctx->pc = 0x10e9b8u;
    // NOP
    // 0x10e9bc: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x10E9BCu;
    {
        const bool branch_taken_0x10e9bc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E9C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E9BCu;
            // 0x10e9c0: 0x60202d  daddu       $a0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e9bc) {
            ctx->pc = 0x10E9A8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10e9a8;
        }
    }
    ctx->pc = 0x10E9C4u;
    // 0x10e9c4: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x10E9C4u;
    {
        const bool branch_taken_0x10e9c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10E9C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E9C4u;
            // 0x10e9c8: 0x741823  subu        $v1, $v1, $s4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 20)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e9c4) {
            ctx->pc = 0x10E9D8u;
            goto label_10e9d8;
        }
    }
    ctx->pc = 0x10E9CCu;
    // 0x10e9cc: 0x0  nop
    ctx->pc = 0x10e9ccu;
    // NOP
label_10e9d0:
    // 0x10e9d0: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x10e9d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
label_10e9d4:
    // 0x10e9d4: 0x741823  subu        $v1, $v1, $s4
    ctx->pc = 0x10e9d4u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 20)));
label_10e9d8:
    // 0x10e9d8: 0x280102d  daddu       $v0, $s4, $zero
    ctx->pc = 0x10e9d8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10e9dc: 0xafc30000  sw          $v1, 0x0($fp)
    ctx->pc = 0x10e9dcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 3));
    // 0x10e9e0: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x10e9e0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x10e9e4: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x10e9e4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10e9e8: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x10e9e8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x10e9ec: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x10e9ecu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x10e9f0: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x10e9f0u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x10e9f4: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x10e9f4u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x10e9f8: 0xdfb60040  ld          $s6, 0x40($sp)
    ctx->pc = 0x10e9f8u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x10e9fc: 0xdfb70048  ld          $s7, 0x48($sp)
    ctx->pc = 0x10e9fcu;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x10ea00: 0xdfbe0050  ld          $fp, 0x50($sp)
    ctx->pc = 0x10ea00u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x10ea04: 0xdfbf0058  ld          $ra, 0x58($sp)
    ctx->pc = 0x10ea04u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x10ea08: 0x3e00008  jr          $ra
    ctx->pc = 0x10EA08u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10EA0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EA08u;
            // 0x10ea0c: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10E8BCu: goto label_10e8bc;
            case 0x10E8C4u: goto label_10e8c4;
            case 0x10E8E4u: goto label_10e8e4;
            case 0x10E8F0u: goto label_10e8f0;
            case 0x10E910u: goto label_10e910;
            case 0x10E928u: goto label_10e928;
            case 0x10E934u: goto label_10e934;
            case 0x10E95Cu: goto label_10e95c;
            case 0x10E96Cu: goto label_10e96c;
            case 0x10E970u: goto label_10e970;
            case 0x10E974u: goto label_10e974;
            case 0x10E984u: goto label_10e984;
            case 0x10E9A8u: goto label_10e9a8;
            case 0x10E9D0u: goto label_10e9d0;
            case 0x10E9D4u: goto label_10e9d4;
            case 0x10E9D8u: goto label_10e9d8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10EA10u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
