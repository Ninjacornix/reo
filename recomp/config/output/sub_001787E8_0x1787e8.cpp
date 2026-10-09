#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001787E8
// Address: 0x1787e8 - 0x17890c
void sub_001787E8_0x1787e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001787E8_0x1787e8");
#endif

    switch (ctx->pc) {
        case 0x178828u: goto label_178828;
        case 0x1788ccu: goto label_1788cc;
        case 0x1788e0u: goto label_1788e0;
        default: break;
    }

    ctx->pc = 0x1787e8u;

    // 0x1787e8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1787e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1787ec: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1787ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1787f0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1787f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1787f4: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1787f4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1787f8: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x1787f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x1787fc: 0x100982d  daddu       $s3, $t0, $zero
    ctx->pc = 0x1787fcu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178800: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x178800u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x178804: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x178804u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178808: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x178808u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x17880c: 0xe0a82d  daddu       $s5, $a3, $zero
    ctx->pc = 0x17880cu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178810: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x178810u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x178814: 0xa0b02d  daddu       $s6, $a1, $zero
    ctx->pc = 0x178814u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178818: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x178818u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17881c: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x17881cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x178820: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x178820u;
    SET_GPR_U32(ctx, 31, 0x178828u);
    ctx->pc = 0x178824u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178820u;
            // 0x178824: 0x26301cc0  addiu       $s0, $s1, 0x1CC0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 7360));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178828u; }
        if (ctx->pc != 0x178828u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178828u; }
        if (ctx->pc != 0x178828u) { return; }
    }
    ctx->pc = 0x178828u;
label_178828:
    // 0x178828: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x178828u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x17882c: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x17882cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178830: 0x34a50192  ori         $a1, $a1, 0x192
    ctx->pc = 0x178830u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)402);
    // 0x178834: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x178834u;
    {
        const bool branch_taken_0x178834 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x178838u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178834u;
            // 0x178838: 0x24030008  addiu       $v1, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x178834) {
            ctx->pc = 0x178868u;
            goto label_178868;
        }
    }
    ctx->pc = 0x17883Cu;
    // 0x17883c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17883cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x178840: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x178840u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x178844: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x178844u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x178848: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x178848u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17884c: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x17884cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x178850: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x178850u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x178854: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x178854u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x178858: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x178858u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x17885c: 0x805a704  j           func_169C10
    ctx->pc = 0x17885Cu;
    ctx->pc = 0x178860u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17885Cu;
            // 0x178860: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x178864u;
    // 0x178864: 0x0  nop
    ctx->pc = 0x178864u;
    // NOP
label_178868:
    // 0x178868: 0x8e120010  lw          $s2, 0x10($s0)
    ctx->pc = 0x178868u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x17886c: 0x1643000e  bne         $s2, $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x17886Cu;
    {
        const bool branch_taken_0x17886c = (GPR_U64(ctx, 18) != GPR_U64(ctx, 3));
        ctx->pc = 0x178870u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17886Cu;
            // 0x178870: 0x8e020008  lw          $v0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17886c) {
            ctx->pc = 0x1788A8u;
            goto label_1788a8;
        }
    }
    ctx->pc = 0x178874u;
    // 0x178874: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x178874u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178878: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x178878u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17887c: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x17887cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x178880: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x178880u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x178884: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x178884u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x178888: 0x34a50602  ori         $a1, $a1, 0x602
    ctx->pc = 0x178888u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1538);
    // 0x17888c: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x17888cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x178890: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x178890u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x178894: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x178894u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x178898: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x178898u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x17889c: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x17889cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1788a0: 0x805a704  j           func_169C10
    ctx->pc = 0x1788A0u;
    ctx->pc = 0x1788A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1788A0u;
            // 0x1788a4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1788A8u;
label_1788a8:
    // 0x1788a8: 0x168100  sll         $s0, $s6, 4
    ctx->pc = 0x1788a8u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 22), 4));
    // 0x1788ac: 0x260402d  daddu       $t0, $s3, $zero
    ctx->pc = 0x1788acu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1788b0: 0x508021  addu        $s0, $v0, $s0
    ctx->pc = 0x1788b0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1788b4: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x1788b4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1788b8: 0x26100004  addiu       $s0, $s0, 0x4
    ctx->pc = 0x1788b8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x1788bc: 0x2a0382d  daddu       $a3, $s5, $zero
    ctx->pc = 0x1788bcu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1788c0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1788c0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1788c4: 0xc05e318  jal         func_178C60
    ctx->pc = 0x1788C4u;
    SET_GPR_U32(ctx, 31, 0x1788CCu);
    ctx->pc = 0x1788C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1788C4u;
            // 0x1788c8: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x178C60u;
    if (runtime->hasFunction(0x178C60u)) {
        auto targetFn = runtime->lookupFunction(0x178C60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1788CCu; }
        if (ctx->pc != 0x1788CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00178C60_0x178c60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1788CCu; }
        if (ctx->pc != 0x1788CCu) { return; }
    }
    ctx->pc = 0x1788CCu;
label_1788cc:
    // 0x1788cc: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1788ccu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1788d0: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1788d0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1788d4: 0x2c0302d  daddu       $a2, $s6, $zero
    ctx->pc = 0x1788d4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1788d8: 0xc059bc6  jal         func_166F18
    ctx->pc = 0x1788D8u;
    SET_GPR_U32(ctx, 31, 0x1788E0u);
    ctx->pc = 0x1788DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1788D8u;
            // 0x1788dc: 0x200382d  daddu       $a3, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166F18u;
    if (runtime->hasFunction(0x166F18u)) {
        auto targetFn = runtime->lookupFunction(0x166F18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1788E0u; }
        if (ctx->pc != 0x1788E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00166F18_0x166f18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1788E0u; }
        if (ctx->pc != 0x1788E0u) { return; }
    }
    ctx->pc = 0x1788E0u;
label_1788e0:
    // 0x1788e0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1788e0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1788e4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1788e4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1788e8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1788e8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1788ec: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1788ecu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1788f0: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1788f0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1788f4: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x1788f4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1788f8: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x1788f8u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1788fc: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x1788fcu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x178900: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x178900u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x178904: 0x3e00008  jr          $ra
    ctx->pc = 0x178904u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x178908u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178904u;
            // 0x178908: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x178828u: goto label_178828;
            case 0x178868u: goto label_178868;
            case 0x1788A8u: goto label_1788a8;
            case 0x1788CCu: goto label_1788cc;
            case 0x1788E0u: goto label_1788e0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17890Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
