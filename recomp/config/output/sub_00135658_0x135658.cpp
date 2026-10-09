#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00135658
// Address: 0x135658 - 0x13572c
void sub_00135658_0x135658(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00135658_0x135658");
#endif

    switch (ctx->pc) {
        case 0x1356b0u: goto label_1356b0;
        case 0x1356c8u: goto label_1356c8;
        case 0x1356e0u: goto label_1356e0;
        case 0x1356f8u: goto label_1356f8;
        default: break;
    }

    ctx->pc = 0x135658u;

    // 0x135658: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x135658u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x13565c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13565cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x135660: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x135660u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x135664: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x135664u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x135668: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x135668u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13566c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x13566cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x135670: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x135670u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x135674: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x135674u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x135678: 0x16400011  bnez        $s2, . + 4 + (0x11 << 2)
    ctx->pc = 0x135678u;
    {
        const bool branch_taken_0x135678 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        ctx->pc = 0x13567Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135678u;
            // 0x13567c: 0xffbf0030  sd          $ra, 0x30($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135678) {
            ctx->pc = 0x1356C0u;
            goto label_1356c0;
        }
    }
    ctx->pc = 0x135680u;
    // 0x135680: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x135680u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x135684: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x135684u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x135688: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x135688u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13568c: 0x2484b828  addiu       $a0, $a0, -0x47D8
    ctx->pc = 0x13568cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948904));
    // 0x135690: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x135690u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x135694: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x135694u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x135698: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x135698u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13569c: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x13569cu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1356a0: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1356a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1356a4: 0x804d480  j           func_135200
    ctx->pc = 0x1356A4u;
    ctx->pc = 0x1356A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1356A4u;
            // 0x1356a8: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00135200_0x135200(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1356ACu;
    // 0x1356ac: 0x0  nop
    ctx->pc = 0x1356acu;
    // NOP
label_1356b0:
    // 0x1356b0: 0x26a2fffc  addiu       $v0, $s5, -0x4
    ctx->pc = 0x1356b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 21), 4294967292));
    // 0x1356b4: 0x2621021  addu        $v0, $s3, $v0
    ctx->pc = 0x1356b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
    // 0x1356b8: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x1356B8u;
    {
        const bool branch_taken_0x1356b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1356BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1356B8u;
            // 0x1356bc: 0xa0400004  sb          $zero, 0x4($v0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 2), 4), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1356b8) {
            ctx->pc = 0x135708u;
            goto label_135708;
        }
    }
    ctx->pc = 0x1356C0u;
label_1356c0:
    // 0x1356c0: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1356C0u;
    SET_GPR_U32(ctx, 31, 0x1356C8u);
    ctx->pc = 0x1356C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1356C0u;
            // 0x1356c4: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1356C8u; }
        if (ctx->pc != 0x1356C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1356C8u; }
        if (ctx->pc != 0x1356C8u) { return; }
    }
    ctx->pc = 0x1356C8u;
label_1356c8:
    // 0x1356c8: 0x40a02d  daddu       $s4, $v0, $zero
    ctx->pc = 0x1356c8u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1356cc: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1356ccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1356d0: 0x2451206c  addiu       $s1, $v0, 0x206C
    ctx->pc = 0x1356d0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 8300));
    // 0x1356d4: 0x220a82d  daddu       $s5, $s1, $zero
    ctx->pc = 0x1356d4u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1356d8: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1356d8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1356dc: 0x0  nop
    ctx->pc = 0x1356dcu;
    // NOP
label_1356e0:
    // 0x1356e0: 0x26310010  addiu       $s1, $s1, 0x10
    ctx->pc = 0x1356e0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 16));
    // 0x1356e4: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1356e4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1356e8: 0x280302d  daddu       $a2, $s4, $zero
    ctx->pc = 0x1356e8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1356ec: 0x109900  sll         $s3, $s0, 4
    ctx->pc = 0x1356ecu;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 16), 4));
    // 0x1356f0: 0xc042d10  jal         func_10B440
    ctx->pc = 0x1356F0u;
    SET_GPR_U32(ctx, 31, 0x1356F8u);
    ctx->pc = 0x1356F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1356F0u;
            // 0x1356f4: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B440u;
    if (runtime->hasFunction(0x10B440u)) {
        auto targetFn = runtime->lookupFunction(0x10B440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1356F8u; }
        if (ctx->pc != 0x1356F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B440_0x10b440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1356F8u; }
        if (ctx->pc != 0x1356F8u) { return; }
    }
    ctx->pc = 0x1356F8u;
label_1356f8:
    // 0x1356f8: 0x1040ffed  beqz        $v0, . + 4 + (-0x13 << 2)
    ctx->pc = 0x1356F8u;
    {
        const bool branch_taken_0x1356f8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1356FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1356F8u;
            // 0x1356fc: 0x2e030020  sltiu       $v1, $s0, 0x20 (Delay Slot)
        SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)32) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1356f8) {
            ctx->pc = 0x1356B0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1356b0;
        }
    }
    ctx->pc = 0x135700u;
    // 0x135700: 0x1460fff7  bnez        $v1, . + 4 + (-0x9 << 2)
    ctx->pc = 0x135700u;
    {
        const bool branch_taken_0x135700 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x135704u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135700u;
            // 0x135704: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135700) {
            ctx->pc = 0x1356E0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1356e0;
        }
    }
    ctx->pc = 0x135708u;
label_135708:
    // 0x135708: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x135708u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13570c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13570cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x135710: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x135710u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x135714: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x135714u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x135718: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x135718u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13571c: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x13571cu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x135720: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x135720u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x135724: 0x3e00008  jr          $ra
    ctx->pc = 0x135724u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x135728u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135724u;
            // 0x135728: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1356B0u: goto label_1356b0;
            case 0x1356C0u: goto label_1356c0;
            case 0x1356C8u: goto label_1356c8;
            case 0x1356E0u: goto label_1356e0;
            case 0x1356F8u: goto label_1356f8;
            case 0x135708u: goto label_135708;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13572Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
