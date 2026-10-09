#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015AA70
// Address: 0x15aa70 - 0x15ac38
void sub_0015AA70_0x15aa70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015AA70_0x15aa70");
#endif

    switch (ctx->pc) {
        case 0x15aab8u: goto label_15aab8;
        case 0x15aad0u: goto label_15aad0;
        case 0x15aaf8u: goto label_15aaf8;
        case 0x15ab34u: goto label_15ab34;
        case 0x15ab44u: goto label_15ab44;
        case 0x15ab5cu: goto label_15ab5c;
        case 0x15ab8cu: goto label_15ab8c;
        case 0x15aba0u: goto label_15aba0;
        case 0x15abb8u: goto label_15abb8;
        case 0x15abd4u: goto label_15abd4;
        case 0x15ac00u: goto label_15ac00;
        default: break;
    }

    ctx->pc = 0x15aa70u;

    // 0x15aa70: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x15aa70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x15aa74: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x15aa74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x15aa78: 0x24120004  addiu       $s2, $zero, 0x4
    ctx->pc = 0x15aa78u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x15aa7c: 0xffb30038  sd          $s3, 0x38($sp)
    ctx->pc = 0x15aa7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 19));
    // 0x15aa80: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x15aa80u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15aa84: 0xffb50048  sd          $s5, 0x48($sp)
    ctx->pc = 0x15aa84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 21));
    // 0x15aa88: 0xa0a82d  daddu       $s5, $a1, $zero
    ctx->pc = 0x15aa88u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15aa8c: 0xffbe0060  sd          $fp, 0x60($sp)
    ctx->pc = 0x15aa8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 30));
    // 0x15aa90: 0xf02d  daddu       $fp, $zero, $zero
    ctx->pc = 0x15aa90u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15aa94: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x15aa94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x15aa98: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x15aa98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x15aa9c: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x15aa9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x15aaa0: 0xffb60050  sd          $s6, 0x50($sp)
    ctx->pc = 0x15aaa0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 22));
    // 0x15aaa4: 0xffb70058  sd          $s7, 0x58($sp)
    ctx->pc = 0x15aaa4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 23));
    // 0x15aaa8: 0xffbf0068  sd          $ra, 0x68($sp)
    ctx->pc = 0x15aaa8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 104), GPR_U64(ctx, 31));
    // 0x15aaac: 0x8e760384  lw          $s6, 0x384($s3)
    ctx->pc = 0x15aaacu;
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 900)));
    // 0x15aab0: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x15AAB0u;
    {
        const bool branch_taken_0x15aab0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15AAB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15AAB0u;
            // 0x15aab4: 0x24d0fffd  addiu       $s0, $a2, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967293));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15aab0) {
            ctx->pc = 0x15AABCu;
            goto label_15aabc;
        }
    }
    ctx->pc = 0x15AAB8u;
label_15aab8:
    // 0x15aab8: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x15aab8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
label_15aabc:
    // 0x15aabc: 0x250102a  slt         $v0, $s2, $s0
    ctx->pc = 0x15aabcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x15aac0: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x15AAC0u;
    {
        const bool branch_taken_0x15aac0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15AAC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15AAC0u;
            // 0x15aac4: 0x2501826  xor         $v1, $s2, $s0 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 18) ^ GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15aac0) {
            ctx->pc = 0x15AAD8u;
            goto label_15aad8;
        }
    }
    ctx->pc = 0x15AAC8u;
    // 0x15aac8: 0xc05616e  jal         func_1585B8
    ctx->pc = 0x15AAC8u;
    SET_GPR_U32(ctx, 31, 0x15AAD0u);
    ctx->pc = 0x15AACCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15AAC8u;
            // 0x15aacc: 0x2b22021  addu        $a0, $s5, $s2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 18)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1585B8u;
    if (runtime->hasFunction(0x1585B8u)) {
        auto targetFn = runtime->lookupFunction(0x1585B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15AAD0u; }
        if (ctx->pc != 0x15AAD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001585B8_0x1585b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15AAD0u; }
        if (ctx->pc != 0x15AAD0u) { return; }
    }
    ctx->pc = 0x15AAD0u;
label_15aad0:
    // 0x15aad0: 0x1040fff9  beqz        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x15AAD0u;
    {
        const bool branch_taken_0x15aad0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15AAD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15AAD0u;
            // 0x15aad4: 0x2501826  xor         $v1, $s2, $s0 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 18) ^ GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15aad0) {
            ctx->pc = 0x15AAB8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_15aab8;
        }
    }
    ctx->pc = 0x15AAD8u;
label_15aad8:
    // 0x15aad8: 0x2417ffff  addiu       $s7, $zero, -0x1
    ctx->pc = 0x15aad8u;
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x15aadc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x15aadcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15aae0: 0x16c20006  bne         $s6, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x15AAE0u;
    {
        const bool branch_taken_0x15aae0 = (GPR_U64(ctx, 22) != GPR_U64(ctx, 2));
        ctx->pc = 0x15AAE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15AAE0u;
            // 0x15aae4: 0x3b80b  movn        $s7, $zero, $v1 (Delay Slot)
        if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 23, GPR_VEC(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15aae0) {
            ctx->pc = 0x15AAFCu;
            goto label_15aafc;
        }
    }
    ctx->pc = 0x15AAE8u;
    // 0x15aae8: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x15aae8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15aaec: 0x2a0282d  daddu       $a1, $s5, $zero
    ctx->pc = 0x15aaecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15aaf0: 0xc056b0e  jal         func_15AC38
    ctx->pc = 0x15AAF0u;
    SET_GPR_U32(ctx, 31, 0x15AAF8u);
    ctx->pc = 0x15AAF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15AAF0u;
            // 0x15aaf4: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15AC38u;
    if (runtime->hasFunction(0x15AC38u)) {
        auto targetFn = runtime->lookupFunction(0x15AC38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15AAF8u; }
        if (ctx->pc != 0x15AAF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015AC38_0x15ac38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15AAF8u; }
        if (ctx->pc != 0x15AAF8u) { return; }
    }
    ctx->pc = 0x15AAF8u;
label_15aaf8:
    // 0x15aaf8: 0x40f02d  daddu       $fp, $v0, $zero
    ctx->pc = 0x15aaf8u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_15aafc:
    // 0x15aafc: 0x161040  sll         $v0, $s6, 1
    ctx->pc = 0x15aafcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 22), 1));
    // 0x15ab00: 0x561021  addu        $v0, $v0, $s6
    ctx->pc = 0x15ab00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 22)));
    // 0x15ab04: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x15ab04u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x15ab08: 0x24540380  addiu       $s4, $v0, 0x380
    ctx->pc = 0x15ab08u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 2), 896));
    // 0x15ab0c: 0x2741821  addu        $v1, $s3, $s4
    ctx->pc = 0x15ab0cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 20)));
    // 0x15ab10: 0x8c710008  lw          $s1, 0x8($v1)
    ctx->pc = 0x15ab10u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x15ab14: 0x1220002f  beqz        $s1, . + 4 + (0x2F << 2)
    ctx->pc = 0x15AB14u;
    {
        const bool branch_taken_0x15ab14 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x15AB18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15AB14u;
            // 0x15ab18: 0x3a0382d  daddu       $a3, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15ab14) {
            ctx->pc = 0x15ABD4u;
            goto label_15abd4;
        }
    }
    ctx->pc = 0x15AB1Cu;
    // 0x15ab1c: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x15ab1cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x15ab20: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x15ab20u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ab24: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x15ab24u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ab28: 0x8c620018  lw          $v0, 0x18($v1)
    ctx->pc = 0x15ab28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x15ab2c: 0x40f809  jalr        $v0
    ctx->pc = 0x15AB2Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x15AB34u);
        ctx->pc = 0x15AB30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15AB2Cu;
            // 0x15ab30: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x15AB34u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15AAB8u: goto label_15aab8;
            case 0x15AABCu: goto label_15aabc;
            case 0x15AAD0u: goto label_15aad0;
            case 0x15AAD8u: goto label_15aad8;
            case 0x15AAF8u: goto label_15aaf8;
            case 0x15AAFCu: goto label_15aafc;
            case 0x15AB34u: goto label_15ab34;
            case 0x15AB44u: goto label_15ab44;
            case 0x15AB5Cu: goto label_15ab5c;
            case 0x15AB8Cu: goto label_15ab8c;
            case 0x15ABA0u: goto label_15aba0;
            case 0x15ABB8u: goto label_15abb8;
            case 0x15ABBCu: goto label_15abbc;
            case 0x15ABD4u: goto label_15abd4;
            case 0x15ABD8u: goto label_15abd8;
            case 0x15AC00u: goto label_15ac00;
            case 0x15AC04u: goto label_15ac04;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x15AB34u; }
            if (ctx->pc != 0x15AB34u) { return; }
        }
        }
    }
    ctx->pc = 0x15AB34u;
label_15ab34:
    // 0x15ab34: 0x2a0282d  daddu       $a1, $s5, $zero
    ctx->pc = 0x15ab34u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ab38: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x15ab38u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15ab3c: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x15AB3Cu;
    SET_GPR_U32(ctx, 31, 0x15AB44u);
    ctx->pc = 0x15AB40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15AB3Cu;
            // 0x15ab40: 0x8fa60004  lw          $a2, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15AB44u; }
        if (ctx->pc != 0x15AB44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15AB44u; }
        if (ctx->pc != 0x15AB44u) { return; }
    }
    ctx->pc = 0x15AB44u;
label_15ab44:
    // 0x15ab44: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x15ab44u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x15ab48: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x15ab48u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ab4c: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x15ab4cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15ab50: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x15ab50u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x15ab54: 0x40f809  jalr        $v0
    ctx->pc = 0x15AB54u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x15AB5Cu);
        ctx->pc = 0x15AB58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15AB54u;
            // 0x15ab58: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x15AB5Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15AAB8u: goto label_15aab8;
            case 0x15AABCu: goto label_15aabc;
            case 0x15AAD0u: goto label_15aad0;
            case 0x15AAD8u: goto label_15aad8;
            case 0x15AAF8u: goto label_15aaf8;
            case 0x15AAFCu: goto label_15aafc;
            case 0x15AB34u: goto label_15ab34;
            case 0x15AB44u: goto label_15ab44;
            case 0x15AB5Cu: goto label_15ab5c;
            case 0x15AB8Cu: goto label_15ab8c;
            case 0x15ABA0u: goto label_15aba0;
            case 0x15ABB8u: goto label_15abb8;
            case 0x15ABBCu: goto label_15abbc;
            case 0x15ABD4u: goto label_15abd4;
            case 0x15ABD8u: goto label_15abd8;
            case 0x15AC00u: goto label_15ac00;
            case 0x15AC04u: goto label_15ac04;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x15AB5Cu; }
            if (ctx->pc != 0x15AB5Cu) { return; }
        }
        }
    }
    ctx->pc = 0x15AB5Cu;
label_15ab5c:
    // 0x15ab5c: 0x8fa40004  lw          $a0, 0x4($sp)
    ctx->pc = 0x15ab5cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x15ab60: 0x92102a  slt         $v0, $a0, $s2
    ctx->pc = 0x15ab60u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x15ab64: 0x10400015  beqz        $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x15AB64u;
    {
        const bool branch_taken_0x15ab64 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15AB68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15AB64u;
            // 0x15ab68: 0x2741021  addu        $v0, $s3, $s4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 20)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15ab64) {
            ctx->pc = 0x15ABBCu;
            goto label_15abbc;
        }
    }
    ctx->pc = 0x15AB6Cu;
    // 0x15ab6c: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x15ab6cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x15ab70: 0x27b00010  addiu       $s0, $sp, 0x10
    ctx->pc = 0x15ab70u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x15ab74: 0x2443023  subu        $a2, $s2, $a0
    ctx->pc = 0x15ab74u;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 18), GPR_U32(ctx, 4)));
    // 0x15ab78: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x15ab78u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ab7c: 0x8c620018  lw          $v0, 0x18($v1)
    ctx->pc = 0x15ab7cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x15ab80: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x15ab80u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ab84: 0x40f809  jalr        $v0
    ctx->pc = 0x15AB84u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x15AB8Cu);
        ctx->pc = 0x15AB88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15AB84u;
            // 0x15ab88: 0x200382d  daddu       $a3, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x15AB8Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15AAB8u: goto label_15aab8;
            case 0x15AABCu: goto label_15aabc;
            case 0x15AAD0u: goto label_15aad0;
            case 0x15AAD8u: goto label_15aad8;
            case 0x15AAF8u: goto label_15aaf8;
            case 0x15AAFCu: goto label_15aafc;
            case 0x15AB34u: goto label_15ab34;
            case 0x15AB44u: goto label_15ab44;
            case 0x15AB5Cu: goto label_15ab5c;
            case 0x15AB8Cu: goto label_15ab8c;
            case 0x15ABA0u: goto label_15aba0;
            case 0x15ABB8u: goto label_15abb8;
            case 0x15ABBCu: goto label_15abbc;
            case 0x15ABD4u: goto label_15abd4;
            case 0x15ABD8u: goto label_15abd8;
            case 0x15AC00u: goto label_15ac00;
            case 0x15AC04u: goto label_15ac04;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x15AB8Cu; }
            if (ctx->pc != 0x15AB8Cu) { return; }
        }
        }
    }
    ctx->pc = 0x15AB8Cu;
label_15ab8c:
    // 0x15ab8c: 0x8fa50004  lw          $a1, 0x4($sp)
    ctx->pc = 0x15ab8cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x15ab90: 0x8fa40010  lw          $a0, 0x10($sp)
    ctx->pc = 0x15ab90u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15ab94: 0x8fa60014  lw          $a2, 0x14($sp)
    ctx->pc = 0x15ab94u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x15ab98: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x15AB98u;
    SET_GPR_U32(ctx, 31, 0x15ABA0u);
    ctx->pc = 0x15AB9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15AB98u;
            // 0x15ab9c: 0x2a52821  addu        $a1, $s5, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15ABA0u; }
        if (ctx->pc != 0x15ABA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15ABA0u; }
        if (ctx->pc != 0x15ABA0u) { return; }
    }
    ctx->pc = 0x15ABA0u;
label_15aba0:
    // 0x15aba0: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x15aba0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x15aba4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x15aba4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15aba8: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x15aba8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15abac: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x15abacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x15abb0: 0x40f809  jalr        $v0
    ctx->pc = 0x15ABB0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x15ABB8u);
        ctx->pc = 0x15ABB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15ABB0u;
            // 0x15abb4: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x15ABB8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15AAB8u: goto label_15aab8;
            case 0x15AABCu: goto label_15aabc;
            case 0x15AAD0u: goto label_15aad0;
            case 0x15AAD8u: goto label_15aad8;
            case 0x15AAF8u: goto label_15aaf8;
            case 0x15AAFCu: goto label_15aafc;
            case 0x15AB34u: goto label_15ab34;
            case 0x15AB44u: goto label_15ab44;
            case 0x15AB5Cu: goto label_15ab5c;
            case 0x15AB8Cu: goto label_15ab8c;
            case 0x15ABA0u: goto label_15aba0;
            case 0x15ABB8u: goto label_15abb8;
            case 0x15ABBCu: goto label_15abbc;
            case 0x15ABD4u: goto label_15abd4;
            case 0x15ABD8u: goto label_15abd8;
            case 0x15AC00u: goto label_15ac00;
            case 0x15AC04u: goto label_15ac04;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x15ABB8u; }
            if (ctx->pc != 0x15ABB8u) { return; }
        }
        }
    }
    ctx->pc = 0x15ABB8u;
label_15abb8:
    // 0x15abb8: 0x2741021  addu        $v0, $s3, $s4
    ctx->pc = 0x15abb8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 20)));
label_15abbc:
    // 0x15abbc: 0x8c43000c  lw          $v1, 0xC($v0)
    ctx->pc = 0x15abbcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x15abc0: 0x50600005  beql        $v1, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x15ABC0u;
    {
        const bool branch_taken_0x15abc0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x15abc0) {
            ctx->pc = 0x15ABC4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15ABC0u;
            // 0x15abc4: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15ABD8u;
            goto label_15abd8;
        }
    }
    ctx->pc = 0x15ABC8u;
    // 0x15abc8: 0x8c440010  lw          $a0, 0x10($v0)
    ctx->pc = 0x15abc8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x15abcc: 0x60f809  jalr        $v1
    ctx->pc = 0x15ABCCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x15ABD4u);
        ctx->pc = 0x15ABD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15ABCCu;
            // 0x15abd0: 0x2c0282d  daddu       $a1, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x15ABD4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15AAB8u: goto label_15aab8;
            case 0x15AABCu: goto label_15aabc;
            case 0x15AAD0u: goto label_15aad0;
            case 0x15AAD8u: goto label_15aad8;
            case 0x15AAF8u: goto label_15aaf8;
            case 0x15AAFCu: goto label_15aafc;
            case 0x15AB34u: goto label_15ab34;
            case 0x15AB44u: goto label_15ab44;
            case 0x15AB5Cu: goto label_15ab5c;
            case 0x15AB8Cu: goto label_15ab8c;
            case 0x15ABA0u: goto label_15aba0;
            case 0x15ABB8u: goto label_15abb8;
            case 0x15ABBCu: goto label_15abbc;
            case 0x15ABD4u: goto label_15abd4;
            case 0x15ABD8u: goto label_15abd8;
            case 0x15AC00u: goto label_15ac00;
            case 0x15AC04u: goto label_15ac04;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x15ABD4u; }
            if (ctx->pc != 0x15ABD4u) { return; }
        }
        }
    }
    ctx->pc = 0x15ABD4u;
label_15abd4:
    // 0x15abd4: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x15abd4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
label_15abd8:
    // 0x15abd8: 0x16c2000a  bne         $s6, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x15ABD8u;
    {
        const bool branch_taken_0x15abd8 = (GPR_U64(ctx, 22) != GPR_U64(ctx, 2));
        ctx->pc = 0x15ABDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15ABD8u;
            // 0x15abdc: 0x3c0102d  daddu       $v0, $fp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15abd8) {
            ctx->pc = 0x15AC04u;
            goto label_15ac04;
        }
    }
    ctx->pc = 0x15ABE0u;
    // 0x15abe0: 0x8e6403b8  lw          $a0, 0x3B8($s3)
    ctx->pc = 0x15abe0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 952)));
    // 0x15abe4: 0x10800007  beqz        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x15ABE4u;
    {
        const bool branch_taken_0x15abe4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x15ABE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15ABE4u;
            // 0x15abe8: 0x2a0282d  daddu       $a1, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15abe4) {
            ctx->pc = 0x15AC04u;
            goto label_15ac04;
        }
    }
    ctx->pc = 0x15ABECu;
    // 0x15abec: 0x8e6603bc  lw          $a2, 0x3BC($s3)
    ctx->pc = 0x15abecu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 956)));
    // 0x15abf0: 0x246102a  slt         $v0, $s2, $a2
    ctx->pc = 0x15abf0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x15abf4: 0x242300b  movn        $a2, $s2, $v0
    ctx->pc = 0x15abf4u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 18));
    // 0x15abf8: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x15ABF8u;
    SET_GPR_U32(ctx, 31, 0x15AC00u);
    ctx->pc = 0x15ABFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15ABF8u;
            // 0x15abfc: 0xae6603c0  sw          $a2, 0x3C0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 960), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15AC00u; }
        if (ctx->pc != 0x15AC00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15AC00u; }
        if (ctx->pc != 0x15AC00u) { return; }
    }
    ctx->pc = 0x15AC00u;
label_15ac00:
    // 0x15ac00: 0x3c0102d  daddu       $v0, $fp, $zero
    ctx->pc = 0x15ac00u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
label_15ac04:
    // 0x15ac04: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x15ac04u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x15ac08: 0x2fe100a  movz        $v0, $s7, $fp
    ctx->pc = 0x15ac08u;
    if (GPR_U64(ctx, 30) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 23));
    // 0x15ac0c: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x15ac0cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x15ac10: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x15ac10u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x15ac14: 0xdfb30038  ld          $s3, 0x38($sp)
    ctx->pc = 0x15ac14u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x15ac18: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x15ac18u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x15ac1c: 0xdfb50048  ld          $s5, 0x48($sp)
    ctx->pc = 0x15ac1cu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x15ac20: 0xdfb60050  ld          $s6, 0x50($sp)
    ctx->pc = 0x15ac20u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x15ac24: 0xdfb70058  ld          $s7, 0x58($sp)
    ctx->pc = 0x15ac24u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x15ac28: 0xdfbe0060  ld          $fp, 0x60($sp)
    ctx->pc = 0x15ac28u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x15ac2c: 0xdfbf0068  ld          $ra, 0x68($sp)
    ctx->pc = 0x15ac2cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x15ac30: 0x3e00008  jr          $ra
    ctx->pc = 0x15AC30u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15AC34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15AC30u;
            // 0x15ac34: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15AAB8u: goto label_15aab8;
            case 0x15AABCu: goto label_15aabc;
            case 0x15AAD0u: goto label_15aad0;
            case 0x15AAD8u: goto label_15aad8;
            case 0x15AAF8u: goto label_15aaf8;
            case 0x15AAFCu: goto label_15aafc;
            case 0x15AB34u: goto label_15ab34;
            case 0x15AB44u: goto label_15ab44;
            case 0x15AB5Cu: goto label_15ab5c;
            case 0x15AB8Cu: goto label_15ab8c;
            case 0x15ABA0u: goto label_15aba0;
            case 0x15ABB8u: goto label_15abb8;
            case 0x15ABBCu: goto label_15abbc;
            case 0x15ABD4u: goto label_15abd4;
            case 0x15ABD8u: goto label_15abd8;
            case 0x15AC00u: goto label_15ac00;
            case 0x15AC04u: goto label_15ac04;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15AC38u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
