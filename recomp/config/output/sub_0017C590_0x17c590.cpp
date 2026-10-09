#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017C590
// Address: 0x17c590 - 0x17c708
void sub_0017C590_0x17c590(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017C590_0x17c590");
#endif

    switch (ctx->pc) {
        case 0x17c5b8u: goto label_17c5b8;
        default: break;
    }

    ctx->pc = 0x17c590u;

    // 0x17c590: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x17c590u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17c594: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x17c594u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17c598: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x17c598u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c59c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17c59cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17c5a0: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x17c5a0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c5a4: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x17c5a4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c5a8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17c5a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17c5ac: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x17c5acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x17c5b0: 0xc05f1c2  jal         func_17C708
    ctx->pc = 0x17C5B0u;
    SET_GPR_U32(ctx, 31, 0x17C5B8u);
    ctx->pc = 0x17C5B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C5B0u;
            // 0x17c5b4: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C708u;
    if (runtime->hasFunction(0x17C708u)) {
        auto targetFn = runtime->lookupFunction(0x17C708u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17C5B8u; }
        if (ctx->pc != 0x17C5B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017C708_0x17c708(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17C5B8u; }
        if (ctx->pc != 0x17C5B8u) { return; }
    }
    ctx->pc = 0x17C5B8u;
label_17c5b8:
    // 0x17c5b8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x17c5b8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17c5bc: 0x5443004c  bnel        $v0, $v1, . + 4 + (0x4C << 2)
    ctx->pc = 0x17C5BCu;
    {
        const bool branch_taken_0x17c5bc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x17c5bc) {
            ctx->pc = 0x17C5C0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17C5BCu;
            // 0x17c5c0: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17C6F0u;
            goto label_17c6f0;
        }
    }
    ctx->pc = 0x17C5C4u;
    // 0x17c5c4: 0x2e420065  sltiu       $v0, $s2, 0x65
    ctx->pc = 0x17c5c4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 18) < (uint64_t)(int64_t)(int32_t)101) ? 1 : 0);
    // 0x17c5c8: 0x1040003f  beqz        $v0, . + 4 + (0x3F << 2)
    ctx->pc = 0x17C5C8u;
    {
        const bool branch_taken_0x17c5c8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17C5CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C5C8u;
            // 0x17c5cc: 0xae120038  sw          $s2, 0x38($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17c5c8) {
            ctx->pc = 0x17C6C8u;
            goto label_17c6c8;
        }
    }
    ctx->pc = 0x17C5D0u;
    // 0x17c5d0: 0x121080  sll         $v0, $s2, 2
    ctx->pc = 0x17c5d0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
    // 0x17c5d4: 0x3c030024  lui         $v1, 0x24
    ctx->pc = 0x17c5d4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)36 << 16));
    // 0x17c5d8: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x17c5d8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x17c5dc: 0x8c631130  lw          $v1, 0x1130($v1)
    ctx->pc = 0x17c5dcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4400)));
    // 0x17c5e0: 0x600008  jr          $v1
    ctx->pc = 0x17C5E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17C5E8u: goto label_17c5e8;
            case 0x17C608u: goto label_17c608;
            case 0x17C628u: goto label_17c628;
            case 0x17C648u: goto label_17c648;
            case 0x17C668u: goto label_17c668;
            case 0x17C688u: goto label_17c688;
            case 0x17C6A8u: goto label_17c6a8;
            case 0x17C6C8u: goto label_17c6c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17C5E8u;
label_17c5e8:
    // 0x17c5e8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17c5e8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c5ec: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17c5ecu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17c5f0: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17c5f0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c5f4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17c5f4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17c5f8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17c5f8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17c5fc: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17c5fcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17c600: 0x805f1f0  j           func_17C7C0
    ctx->pc = 0x17C600u;
    ctx->pc = 0x17C604u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C600u;
            // 0x17c604: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C7C0u;
    if (runtime->hasFunction(0x17C7C0u)) {
        auto targetFn = runtime->lookupFunction(0x17C7C0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017C7C0_0x17c7c0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17C608u;
label_17c608:
    // 0x17c608: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17c608u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c60c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17c60cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17c610: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17c610u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c614: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17c614u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17c618: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17c618u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17c61c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17c61cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17c620: 0x805f1f8  j           func_17C7E0
    ctx->pc = 0x17C620u;
    ctx->pc = 0x17C624u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C620u;
            // 0x17c624: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C7E0u;
    if (runtime->hasFunction(0x17C7E0u)) {
        auto targetFn = runtime->lookupFunction(0x17C7E0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017C7E0_0x17c7e0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17C628u;
label_17c628:
    // 0x17c628: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17c628u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c62c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17c62cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17c630: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17c630u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c634: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17c634u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17c638: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17c638u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17c63c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17c63cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17c640: 0x805f234  j           func_17C8D0
    ctx->pc = 0x17C640u;
    ctx->pc = 0x17C644u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C640u;
            // 0x17c644: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C8D0u;
    if (runtime->hasFunction(0x17C8D0u)) {
        auto targetFn = runtime->lookupFunction(0x17C8D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017C8D0_0x17c8d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17C648u;
label_17c648:
    // 0x17c648: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17c648u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c64c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17c64cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17c650: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17c650u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c654: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17c654u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17c658: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17c658u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17c65c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17c65cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17c660: 0x805f23c  j           func_17C8F0
    ctx->pc = 0x17C660u;
    ctx->pc = 0x17C664u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C660u;
            // 0x17c664: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C8F0u;
    if (runtime->hasFunction(0x17C8F0u)) {
        auto targetFn = runtime->lookupFunction(0x17C8F0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017C8F0_0x17c8f0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17C668u;
label_17c668:
    // 0x17c668: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17c668u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c66c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17c66cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17c670: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17c670u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c674: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17c674u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17c678: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17c678u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17c67c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17c67cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17c680: 0x805f244  j           func_17C910
    ctx->pc = 0x17C680u;
    ctx->pc = 0x17C684u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C680u;
            // 0x17c684: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C910u;
    if (runtime->hasFunction(0x17C910u)) {
        auto targetFn = runtime->lookupFunction(0x17C910u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017C910_0x17c910(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17C688u;
label_17c688:
    // 0x17c688: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17c688u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c68c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17c68cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17c690: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17c690u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c694: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17c694u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17c698: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17c698u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17c69c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17c69cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17c6a0: 0x805f24a  j           func_17C928
    ctx->pc = 0x17C6A0u;
    ctx->pc = 0x17C6A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C6A0u;
            // 0x17c6a4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C928u;
    if (runtime->hasFunction(0x17C928u)) {
        auto targetFn = runtime->lookupFunction(0x17C928u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017C928_0x17c928(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17C6A8u;
label_17c6a8:
    // 0x17c6a8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17c6a8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c6ac: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17c6acu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17c6b0: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17c6b0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c6b4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17c6b4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17c6b8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17c6b8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17c6bc: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17c6bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17c6c0: 0x805f200  j           func_17C800
    ctx->pc = 0x17C6C0u;
    ctx->pc = 0x17C6C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C6C0u;
            // 0x17c6c4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C800u;
    if (runtime->hasFunction(0x17C800u)) {
        auto targetFn = runtime->lookupFunction(0x17C800u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017C800_0x17c800(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17C6C8u;
label_17c6c8:
    // 0x17c6c8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17c6c8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c6cc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17c6ccu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17c6d0: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17c6d0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c6d4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17c6d4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17c6d8: 0x3c060024  lui         $a2, 0x24
    ctx->pc = 0x17c6d8u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)36 << 16));
    // 0x17c6dc: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17c6dcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17c6e0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17c6e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17c6e4: 0x24c610f0  addiu       $a2, $a2, 0x10F0
    ctx->pc = 0x17c6e4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4336));
    // 0x17c6e8: 0x805f472  j           func_17D1C8
    ctx->pc = 0x17C6E8u;
    ctx->pc = 0x17C6ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C6E8u;
            // 0x17c6ec: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D1C8u;
    if (runtime->hasFunction(0x17D1C8u)) {
        auto targetFn = runtime->lookupFunction(0x17D1C8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D1C8_0x17d1c8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17C6F0u;
label_17c6f0:
    // 0x17c6f0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17c6f0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17c6f4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17c6f4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17c6f8: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17c6f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17c6fc: 0x3e00008  jr          $ra
    ctx->pc = 0x17C6FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17C700u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C6FCu;
            // 0x17c700: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17C5B8u: goto label_17c5b8;
            case 0x17C5E8u: goto label_17c5e8;
            case 0x17C608u: goto label_17c608;
            case 0x17C628u: goto label_17c628;
            case 0x17C648u: goto label_17c648;
            case 0x17C668u: goto label_17c668;
            case 0x17C688u: goto label_17c688;
            case 0x17C6A8u: goto label_17c6a8;
            case 0x17C6C8u: goto label_17c6c8;
            case 0x17C6F0u: goto label_17c6f0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17C704u;
    // 0x17c704: 0x0  nop
    ctx->pc = 0x17c704u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
