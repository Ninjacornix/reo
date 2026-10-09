#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010A538
// Address: 0x10a538 - 0x10a610
void sub_0010A538_0x10a538(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010A538_0x10a538");
#endif

    switch (ctx->pc) {
        case 0x10a57cu: goto label_10a57c;
        case 0x10a5a4u: goto label_10a5a4;
        case 0x10a5f8u: goto label_10a5f8;
        default: break;
    }

    ctx->pc = 0x10a538u;

    // 0x10a538: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x10a538u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x10a53c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x10a53cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x10a540: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x10a540u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a544: 0x2e220020  sltiu       $v0, $s1, 0x20
    ctx->pc = 0x10a544u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)(int64_t)(int32_t)32) ? 1 : 0);
    // 0x10a548: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x10a548u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x10a54c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x10a54cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x10a550: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x10A550u;
    {
        const bool branch_taken_0x10a550 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10A554u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A550u;
            // 0x10a554: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a550) {
            ctx->pc = 0x10A568u;
            goto label_10a568;
        }
    }
    ctx->pc = 0x10A558u;
    // 0x10a558: 0x24030016  addiu       $v1, $zero, 0x16
    ctx->pc = 0x10a558u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 22));
    // 0x10a55c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x10a55cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10a560: 0x10000026  b           . + 4 + (0x26 << 2)
    ctx->pc = 0x10A560u;
    {
        const bool branch_taken_0x10a560 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10A564u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A560u;
            // 0x10a564: 0xae030000  sw          $v1, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a560) {
            ctx->pc = 0x10A5FCu;
            goto label_10a5fc;
        }
    }
    ctx->pc = 0x10A568u;
label_10a568:
    // 0x10a568: 0x8e0301d4  lw          $v1, 0x1D4($s0)
    ctx->pc = 0x10a568u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 468)));
    // 0x10a56c: 0x14600007  bnez        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x10A56Cu;
    {
        const bool branch_taken_0x10a56c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x10A570u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A56Cu;
            // 0x10a570: 0x111080  sll         $v0, $s1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a56c) {
            ctx->pc = 0x10A58Cu;
            goto label_10a58c;
        }
    }
    ctx->pc = 0x10A574u;
    // 0x10a574: 0xc042912  jal         func_10A448
    ctx->pc = 0x10A574u;
    SET_GPR_U32(ctx, 31, 0x10A57Cu);
    ctx->pc = 0x10A448u;
    if (runtime->hasFunction(0x10A448u)) {
        auto targetFn = runtime->lookupFunction(0x10A448u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10A57Cu; }
        if (ctx->pc != 0x10A57Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A448_0x10a448(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10A57Cu; }
        if (ctx->pc != 0x10A57Cu) { return; }
    }
    ctx->pc = 0x10A57Cu;
label_10a57c:
    // 0x10a57c: 0x1440001f  bnez        $v0, . + 4 + (0x1F << 2)
    ctx->pc = 0x10A57Cu;
    {
        const bool branch_taken_0x10a57c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10A580u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A57Cu;
            // 0x10a580: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a57c) {
            ctx->pc = 0x10A5FCu;
            goto label_10a5fc;
        }
    }
    ctx->pc = 0x10A584u;
    // 0x10a584: 0x8e0301d4  lw          $v1, 0x1D4($s0)
    ctx->pc = 0x10a584u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 468)));
    // 0x10a588: 0x111080  sll         $v0, $s1, 2
    ctx->pc = 0x10a588u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
label_10a58c:
    // 0x10a58c: 0x432021  addu        $a0, $v0, $v1
    ctx->pc = 0x10a58cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x10a590: 0x8c850000  lw          $a1, 0x0($a0)
    ctx->pc = 0x10a590u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x10a594: 0x54a0000c  bnel        $a1, $zero, . + 4 + (0xC << 2)
    ctx->pc = 0x10A594u;
    {
        const bool branch_taken_0x10a594 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        if (branch_taken_0x10a594) {
            ctx->pc = 0x10A598u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10A594u;
            // 0x10a598: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10A5C8u;
            goto label_10a5c8;
        }
    }
    ctx->pc = 0x10A59Cu;
    // 0x10a59c: 0xc0429e4  jal         func_10A790
    ctx->pc = 0x10A59Cu;
    SET_GPR_U32(ctx, 31, 0x10A5A4u);
    ctx->pc = 0x10A5A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10A59Cu;
            // 0x10a5a0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A790u;
    if (runtime->hasFunction(0x10A790u)) {
        auto targetFn = runtime->lookupFunction(0x10A790u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10A5A4u; }
        if (ctx->pc != 0x10A5A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A790_0x10a790(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10A5A4u; }
        if (ctx->pc != 0x10A5A4u) { return; }
    }
    ctx->pc = 0x10A5A4u;
label_10a5a4:
    // 0x10a5a4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x10a5a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a5a8: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x10a5a8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a5ac: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x10a5acu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x10a5b0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x10a5b0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x10a5b4: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x10a5b4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a5b8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x10a5b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x10a5bc: 0x80429cc  j           func_10A730
    ctx->pc = 0x10A5BCu;
    ctx->pc = 0x10A5C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10A5BCu;
            // 0x10a5c0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A730u;
    if (runtime->hasFunction(0x10A730u)) {
        auto targetFn = runtime->lookupFunction(0x10A730u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0010A730_0x10a730(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x10A5C4u;
    // 0x10a5c4: 0x0  nop
    ctx->pc = 0x10a5c4u;
    // NOP
label_10a5c8:
    // 0x10a5c8: 0x10a3000c  beq         $a1, $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x10A5C8u;
    {
        const bool branch_taken_0x10a5c8 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        ctx->pc = 0x10A5CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A5C8u;
            // 0x10a5cc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a5c8) {
            ctx->pc = 0x10A5FCu;
            goto label_10a5fc;
        }
    }
    ctx->pc = 0x10A5D0u;
    // 0x10a5d0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x10a5d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10a5d4: 0x54a20006  bnel        $a1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x10A5D4u;
    {
        const bool branch_taken_0x10a5d4 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 2));
        if (branch_taken_0x10a5d4) {
            ctx->pc = 0x10A5D8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10A5D4u;
            // 0x10a5d8: 0xac800000  sw          $zero, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10A5F0u;
            goto label_10a5f0;
        }
    }
    ctx->pc = 0x10A5DCu;
    // 0x10a5dc: 0x24030016  addiu       $v1, $zero, 0x16
    ctx->pc = 0x10a5dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 22));
    // 0x10a5e0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x10a5e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x10a5e4: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x10A5E4u;
    {
        const bool branch_taken_0x10a5e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10A5E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A5E4u;
            // 0x10a5e8: 0xae030000  sw          $v1, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a5e4) {
            ctx->pc = 0x10A5FCu;
            goto label_10a5fc;
        }
    }
    ctx->pc = 0x10A5ECu;
    // 0x10a5ec: 0x0  nop
    ctx->pc = 0x10a5ecu;
    // NOP
label_10a5f0:
    // 0x10a5f0: 0xa0f809  jalr        $a1
    ctx->pc = 0x10A5F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 5);
        SET_GPR_U32(ctx, 31, 0x10A5F8u);
        ctx->pc = 0x10A5F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A5F0u;
            // 0x10a5f4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x10A5F8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10A568u: goto label_10a568;
            case 0x10A57Cu: goto label_10a57c;
            case 0x10A58Cu: goto label_10a58c;
            case 0x10A5A4u: goto label_10a5a4;
            case 0x10A5C8u: goto label_10a5c8;
            case 0x10A5F0u: goto label_10a5f0;
            case 0x10A5F8u: goto label_10a5f8;
            case 0x10A5FCu: goto label_10a5fc;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x10A5F8u; }
            if (ctx->pc != 0x10A5F8u) { return; }
        }
        }
    }
    ctx->pc = 0x10A5F8u;
label_10a5f8:
    // 0x10a5f8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x10a5f8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_10a5fc:
    // 0x10a5fc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x10a5fcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x10a600: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x10a600u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x10a604: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x10a604u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x10a608: 0x3e00008  jr          $ra
    ctx->pc = 0x10A608u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10A60Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A608u;
            // 0x10a60c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10A568u: goto label_10a568;
            case 0x10A57Cu: goto label_10a57c;
            case 0x10A58Cu: goto label_10a58c;
            case 0x10A5A4u: goto label_10a5a4;
            case 0x10A5C8u: goto label_10a5c8;
            case 0x10A5F0u: goto label_10a5f0;
            case 0x10A5F8u: goto label_10a5f8;
            case 0x10A5FCu: goto label_10a5fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10A610u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
