#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012E598
// Address: 0x12e598 - 0x12e708
void sub_0012E598_0x12e598(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012E598_0x12e598");
#endif

    switch (ctx->pc) {
        case 0x12e5f0u: goto label_12e5f0;
        case 0x12e604u: goto label_12e604;
        case 0x12e638u: goto label_12e638;
        case 0x12e658u: goto label_12e658;
        case 0x12e670u: goto label_12e670;
        case 0x12e688u: goto label_12e688;
        case 0x12e6b0u: goto label_12e6b0;
        default: break;
    }

    ctx->pc = 0x12e598u;

    // 0x12e598: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x12e598u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x12e59c: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x12e59cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x12e5a0: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x12e5a0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12e5a4: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x12e5a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x12e5a8: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x12e5a8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12e5ac: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x12e5acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x12e5b0: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x12e5b0u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12e5b4: 0xffb70058  sd          $s7, 0x58($sp)
    ctx->pc = 0x12e5b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 23));
    // 0x12e5b8: 0x80b82d  daddu       $s7, $a0, $zero
    ctx->pc = 0x12e5b8u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12e5bc: 0xffbe0060  sd          $fp, 0x60($sp)
    ctx->pc = 0x12e5bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 30));
    // 0x12e5c0: 0x26fe0004  addiu       $fp, $s7, 0x4
    ctx->pc = 0x12e5c0u;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 23), 4));
    // 0x12e5c4: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x12e5c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x12e5c8: 0xffb30038  sd          $s3, 0x38($sp)
    ctx->pc = 0x12e5c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 19));
    // 0x12e5cc: 0xffb50048  sd          $s5, 0x48($sp)
    ctx->pc = 0x12e5ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 21));
    // 0x12e5d0: 0xffb60050  sd          $s6, 0x50($sp)
    ctx->pc = 0x12e5d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 22));
    // 0x12e5d4: 0xffbf0068  sd          $ra, 0x68($sp)
    ctx->pc = 0x12e5d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 104), GPR_U64(ctx, 31));
    // 0x12e5d8: 0x8ee30058  lw          $v1, 0x58($s7)
    ctx->pc = 0x12e5d8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 23), 88)));
    // 0x12e5dc: 0x18600012  blez        $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x12E5DCu;
    {
        const bool branch_taken_0x12e5dc = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x12E5E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E5DCu;
            // 0x12e5e0: 0xafa70010  sw          $a3, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 7));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12e5dc) {
            ctx->pc = 0x12E628u;
            goto label_12e628;
        }
    }
    ctx->pc = 0x12E5E4u;
    // 0x12e5e4: 0x3c0802d  daddu       $s0, $fp, $zero
    ctx->pc = 0x12e5e4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12e5e8: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x12e5e8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12e5ec: 0x0  nop
    ctx->pc = 0x12e5ecu;
    // NOP
label_12e5f0:
    // 0x12e5f0: 0x26100004  addiu       $s0, $s0, 0x4
    ctx->pc = 0x12e5f0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x12e5f4: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x12e5f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x12e5f8: 0x8c620024  lw          $v0, 0x24($v1)
    ctx->pc = 0x12e5f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x12e5fc: 0x40f809  jalr        $v0
    ctx->pc = 0x12E5FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12E604u);
        ctx->pc = 0x12E600u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E5FCu;
            // 0x12e600: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12E604u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12E5F0u: goto label_12e5f0;
            case 0x12E604u: goto label_12e604;
            case 0x12E628u: goto label_12e628;
            case 0x12E638u: goto label_12e638;
            case 0x12E658u: goto label_12e658;
            case 0x12E670u: goto label_12e670;
            case 0x12E688u: goto label_12e688;
            case 0x12E6B0u: goto label_12e6b0;
            case 0x12E6C0u: goto label_12e6c0;
            case 0x12E6D0u: goto label_12e6d0;
            case 0x12E6D4u: goto label_12e6d4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12E604u; }
            if (ctx->pc != 0x12E604u) { return; }
        }
        }
    }
    ctx->pc = 0x12E604u;
label_12e604:
    // 0x12e604: 0x28842  srl         $s1, $v0, 1
    ctx->pc = 0x12e604u;
    SET_GPR_S32(ctx, 17, (int32_t)SRL32(GPR_U32(ctx, 2), 1));
    // 0x12e608: 0x232182a  slt         $v1, $s1, $s2
    ctx->pc = 0x12e608u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x12e60c: 0x14600031  bnez        $v1, . + 4 + (0x31 << 2)
    ctx->pc = 0x12E60Cu;
    {
        const bool branch_taken_0x12e60c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x12E610u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E60Cu;
            // 0x12e610: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12e60c) {
            ctx->pc = 0x12E6D4u;
            goto label_12e6d4;
        }
    }
    ctx->pc = 0x12E614u;
    // 0x12e614: 0x8ee30058  lw          $v1, 0x58($s7)
    ctx->pc = 0x12e614u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 23), 88)));
    // 0x12e618: 0x26940001  addiu       $s4, $s4, 0x1
    ctx->pc = 0x12e618u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
    // 0x12e61c: 0x283102a  slt         $v0, $s4, $v1
    ctx->pc = 0x12e61cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 20) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x12e620: 0x5440fff3  bnel        $v0, $zero, . + 4 + (-0xD << 2)
    ctx->pc = 0x12E620u;
    {
        const bool branch_taken_0x12e620 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x12e620) {
            ctx->pc = 0x12E624u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12E620u;
            // 0x12e624: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12E5F0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12e5f0;
        }
    }
    ctx->pc = 0x12E628u;
label_12e628:
    // 0x12e628: 0x18600029  blez        $v1, . + 4 + (0x29 << 2)
    ctx->pc = 0x12E628u;
    {
        const bool branch_taken_0x12e628 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x12E62Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E628u;
            // 0x12e62c: 0xa02d  daddu       $s4, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12e628) {
            ctx->pc = 0x12E6D0u;
            goto label_12e6d0;
        }
    }
    ctx->pc = 0x12E630u;
    // 0x12e630: 0xa82d  daddu       $s5, $zero, $zero
    ctx->pc = 0x12e630u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12e634: 0x0  nop
    ctx->pc = 0x12e634u;
    // NOP
label_12e638:
    // 0x12e638: 0x1a400021  blez        $s2, . + 4 + (0x21 << 2)
    ctx->pc = 0x12E638u;
    {
        const bool branch_taken_0x12e638 = (GPR_S64(ctx, 18) <= 0);
        ctx->pc = 0x12E63Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E638u;
            // 0x12e63c: 0x882d  daddu       $s1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12e638) {
            ctx->pc = 0x12E6C0u;
            goto label_12e6c0;
        }
    }
    ctx->pc = 0x12E640u;
    // 0x12e640: 0x8fa20010  lw          $v0, 0x10($sp)
    ctx->pc = 0x12e640u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12e644: 0x12b040  sll         $s6, $s2, 1
    ctx->pc = 0x12e644u;
    SET_GPR_S32(ctx, 22, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x12e648: 0x2be8021  addu        $s0, $s5, $fp
    ctx->pc = 0x12e648u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 30)));
    // 0x12e64c: 0x2a29821  addu        $s3, $s5, $v0
    ctx->pc = 0x12e64cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 2)));
    // 0x12e650: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x12e650u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12e654: 0x0  nop
    ctx->pc = 0x12e654u;
    // NOP
label_12e658:
    // 0x12e658: 0x3a0382d  daddu       $a3, $sp, $zero
    ctx->pc = 0x12e658u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12e65c: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x12e65cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12e660: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x12e660u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x12e664: 0x8c620018  lw          $v0, 0x18($v1)
    ctx->pc = 0x12e664u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x12e668: 0x40f809  jalr        $v0
    ctx->pc = 0x12E668u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12E670u);
        ctx->pc = 0x12E66Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E668u;
            // 0x12e66c: 0x2c0302d  daddu       $a2, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12E670u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12E5F0u: goto label_12e5f0;
            case 0x12E604u: goto label_12e604;
            case 0x12E628u: goto label_12e628;
            case 0x12E638u: goto label_12e638;
            case 0x12E658u: goto label_12e658;
            case 0x12E670u: goto label_12e670;
            case 0x12E688u: goto label_12e688;
            case 0x12E6B0u: goto label_12e6b0;
            case 0x12E6C0u: goto label_12e6c0;
            case 0x12E6D0u: goto label_12e6d0;
            case 0x12E6D4u: goto label_12e6d4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12E670u; }
            if (ctx->pc != 0x12E670u) { return; }
        }
        }
    }
    ctx->pc = 0x12E670u;
label_12e670:
    // 0x12e670: 0x8e630000  lw          $v1, 0x0($s3)
    ctx->pc = 0x12e670u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x12e674: 0x8fa50000  lw          $a1, 0x0($sp)
    ctx->pc = 0x12e674u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12e678: 0x112040  sll         $a0, $s1, 1
    ctx->pc = 0x12e678u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 17), 1));
    // 0x12e67c: 0x8fa60004  lw          $a2, 0x4($sp)
    ctx->pc = 0x12e67cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x12e680: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x12E680u;
    SET_GPR_U32(ctx, 31, 0x12E688u);
    ctx->pc = 0x12E684u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12E680u;
            // 0x12e684: 0x832021  addu        $a0, $a0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12E688u; }
        if (ctx->pc != 0x12E688u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12E688u; }
        if (ctx->pc != 0x12E688u) { return; }
    }
    ctx->pc = 0x12E688u;
label_12e688:
    // 0x12e688: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x12e688u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12e68c: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x12e68cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x12e690: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12e690u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12e694: 0x8c870000  lw          $a3, 0x0($a0)
    ctx->pc = 0x12e694u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x12e698: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x12e698u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12e69c: 0x213c0  sll         $v0, $v0, 15
    ctx->pc = 0x12e69cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 15));
    // 0x12e6a0: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x12e6a0u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x12e6a4: 0x8ce30020  lw          $v1, 0x20($a3)
    ctx->pc = 0x12e6a4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 32)));
    // 0x12e6a8: 0x60f809  jalr        $v1
    ctx->pc = 0x12E6A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x12E6B0u);
        ctx->pc = 0x12E6ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E6A8u;
            // 0x12e6ac: 0x2228821  addu        $s1, $s1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12E6B0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12E5F0u: goto label_12e5f0;
            case 0x12E604u: goto label_12e604;
            case 0x12E628u: goto label_12e628;
            case 0x12E638u: goto label_12e638;
            case 0x12E658u: goto label_12e658;
            case 0x12E670u: goto label_12e670;
            case 0x12E688u: goto label_12e688;
            case 0x12E6B0u: goto label_12e6b0;
            case 0x12E6C0u: goto label_12e6c0;
            case 0x12E6D0u: goto label_12e6d0;
            case 0x12E6D4u: goto label_12e6d4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12E6B0u; }
            if (ctx->pc != 0x12E6B0u) { return; }
        }
        }
    }
    ctx->pc = 0x12E6B0u;
label_12e6b0:
    // 0x12e6b0: 0x232102a  slt         $v0, $s1, $s2
    ctx->pc = 0x12e6b0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x12e6b4: 0x5440ffe8  bnel        $v0, $zero, . + 4 + (-0x18 << 2)
    ctx->pc = 0x12E6B4u;
    {
        const bool branch_taken_0x12e6b4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x12e6b4) {
            ctx->pc = 0x12E6B8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12E6B4u;
            // 0x12e6b8: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12E658u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12e658;
        }
    }
    ctx->pc = 0x12E6BCu;
    // 0x12e6bc: 0x8ee30058  lw          $v1, 0x58($s7)
    ctx->pc = 0x12e6bcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 23), 88)));
label_12e6c0:
    // 0x12e6c0: 0x26940001  addiu       $s4, $s4, 0x1
    ctx->pc = 0x12e6c0u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
    // 0x12e6c4: 0x283102a  slt         $v0, $s4, $v1
    ctx->pc = 0x12e6c4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 20) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x12e6c8: 0x1440ffdb  bnez        $v0, . + 4 + (-0x25 << 2)
    ctx->pc = 0x12E6C8u;
    {
        const bool branch_taken_0x12e6c8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x12E6CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E6C8u;
            // 0x12e6cc: 0x26b50004  addiu       $s5, $s5, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12e6c8) {
            ctx->pc = 0x12E638u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12e638;
        }
    }
    ctx->pc = 0x12E6D0u;
label_12e6d0:
    // 0x12e6d0: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x12e6d0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_12e6d4:
    // 0x12e6d4: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x12e6d4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12e6d8: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x12e6d8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x12e6dc: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x12e6dcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x12e6e0: 0xdfb30038  ld          $s3, 0x38($sp)
    ctx->pc = 0x12e6e0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x12e6e4: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x12e6e4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x12e6e8: 0xdfb50048  ld          $s5, 0x48($sp)
    ctx->pc = 0x12e6e8u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x12e6ec: 0xdfb60050  ld          $s6, 0x50($sp)
    ctx->pc = 0x12e6ecu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x12e6f0: 0xdfb70058  ld          $s7, 0x58($sp)
    ctx->pc = 0x12e6f0u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x12e6f4: 0xdfbe0060  ld          $fp, 0x60($sp)
    ctx->pc = 0x12e6f4u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x12e6f8: 0xdfbf0068  ld          $ra, 0x68($sp)
    ctx->pc = 0x12e6f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x12e6fc: 0x3e00008  jr          $ra
    ctx->pc = 0x12E6FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12E700u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E6FCu;
            // 0x12e700: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12E5F0u: goto label_12e5f0;
            case 0x12E604u: goto label_12e604;
            case 0x12E628u: goto label_12e628;
            case 0x12E638u: goto label_12e638;
            case 0x12E658u: goto label_12e658;
            case 0x12E670u: goto label_12e670;
            case 0x12E688u: goto label_12e688;
            case 0x12E6B0u: goto label_12e6b0;
            case 0x12E6C0u: goto label_12e6c0;
            case 0x12E6D0u: goto label_12e6d0;
            case 0x12E6D4u: goto label_12e6d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12E704u;
    // 0x12e704: 0x0  nop
    ctx->pc = 0x12e704u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
