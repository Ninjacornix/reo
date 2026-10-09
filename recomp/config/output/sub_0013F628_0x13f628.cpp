#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013F628
// Address: 0x13f628 - 0x13f720
void sub_0013F628_0x13f628(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013F628_0x13f628");
#endif

    switch (ctx->pc) {
        case 0x13f664u: goto label_13f664;
        case 0x13f6d0u: goto label_13f6d0;
        case 0x13f6f0u: goto label_13f6f0;
        default: break;
    }

    ctx->pc = 0x13f628u;

    // 0x13f628: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x13f628u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13f62c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13f62cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13f630: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x13f630u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f634: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13f634u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13f638: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x13f638u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f63c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13f63cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13f640: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x13f640u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x13f644: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x13f644u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13f648: 0x1840002f  blez        $v0, . + 4 + (0x2F << 2)
    ctx->pc = 0x13F648u;
    {
        const bool branch_taken_0x13f648 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x13F64Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F648u;
            // 0x13f64c: 0xa0902d  daddu       $s2, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f648) {
            ctx->pc = 0x13F708u;
            goto label_13f708;
        }
    }
    ctx->pc = 0x13F650u;
    // 0x13f650: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x13f650u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x13f654: 0x5040002d  beql        $v0, $zero, . + 4 + (0x2D << 2)
    ctx->pc = 0x13F654u;
    {
        const bool branch_taken_0x13f654 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x13f654) {
            ctx->pc = 0x13F658u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13F654u;
            // 0x13f658: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13F70Cu;
            goto label_13f70c;
        }
    }
    ctx->pc = 0x13F65Cu;
    // 0x13f65c: 0xc04fc96  jal         func_13F258
    ctx->pc = 0x13F65Cu;
    SET_GPR_U32(ctx, 31, 0x13F664u);
    ctx->pc = 0x13F258u;
    if (runtime->hasFunction(0x13F258u)) {
        auto targetFn = runtime->lookupFunction(0x13F258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F664u; }
        if (ctx->pc != 0x13F664u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F258_0x13f258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F664u; }
        if (ctx->pc != 0x13F664u) { return; }
    }
    ctx->pc = 0x13F664u;
label_13f664:
    // 0x13f664: 0x12400014  beqz        $s2, . + 4 + (0x14 << 2)
    ctx->pc = 0x13F664u;
    {
        const bool branch_taken_0x13f664 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        ctx->pc = 0x13F668u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F664u;
            // 0x13f668: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f664) {
            ctx->pc = 0x13F6B8u;
            goto label_13f6b8;
        }
    }
    ctx->pc = 0x13F66Cu;
    // 0x13f66c: 0x5642001a  bnel        $s2, $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x13F66Cu;
    {
        const bool branch_taken_0x13f66c = (GPR_U64(ctx, 18) != GPR_U64(ctx, 2));
        if (branch_taken_0x13f66c) {
            ctx->pc = 0x13F670u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13F66Cu;
            // 0x13f670: 0x8e02001c  lw          $v0, 0x1C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13F6D8u;
            goto label_13f6d8;
        }
    }
    ctx->pc = 0x13F674u;
    // 0x13f674: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x13f674u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13f678: 0x8e040010  lw          $a0, 0x10($s0)
    ctx->pc = 0x13f678u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x13f67c: 0x8e05000c  lw          $a1, 0xC($s0)
    ctx->pc = 0x13f67cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x13f680: 0x822023  subu        $a0, $a0, $v0
    ctx->pc = 0x13f680u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x13f684: 0x8e070018  lw          $a3, 0x18($s0)
    ctx->pc = 0x13f684u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x13f688: 0x28820000  slti        $v0, $a0, 0x0
    ctx->pc = 0x13f688u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x13f68c: 0x8e030014  lw          $v1, 0x14($s0)
    ctx->pc = 0x13f68cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x13f690: 0x2200b  movn        $a0, $zero, $v0
    ctx->pc = 0x13f690u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 0));
    // 0x13f694: 0x8e260000  lw          $a2, 0x0($s1)
    ctx->pc = 0x13f694u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x13f698: 0xae040010  sw          $a0, 0x10($s0)
    ctx->pc = 0x13f698u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 4));
    // 0x13f69c: 0xc33023  subu        $a2, $a2, $v1
    ctx->pc = 0x13f69cu;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x13f6a0: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x13f6a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13f6a4: 0xa22821  addu        $a1, $a1, $v0
    ctx->pc = 0x13f6a4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x13f6a8: 0xe5182a  slt         $v1, $a3, $a1
    ctx->pc = 0x13f6a8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 7) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x13f6ac: 0xe3280b  movn        $a1, $a3, $v1
    ctx->pc = 0x13f6acu;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 7));
    // 0x13f6b0: 0x1086000f  beq         $a0, $a2, . + 4 + (0xF << 2)
    ctx->pc = 0x13F6B0u;
    {
        const bool branch_taken_0x13f6b0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 6));
        ctx->pc = 0x13F6B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F6B0u;
            // 0x13f6b4: 0xae05000c  sw          $a1, 0xC($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f6b0) {
            ctx->pc = 0x13F6F0u;
            goto label_13f6f0;
        }
    }
    ctx->pc = 0x13F6B8u;
label_13f6b8:
    // 0x13f6b8: 0x8e02001c  lw          $v0, 0x1C($s0)
    ctx->pc = 0x13f6b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x13f6bc: 0x5040000d  beql        $v0, $zero, . + 4 + (0xD << 2)
    ctx->pc = 0x13F6BCu;
    {
        const bool branch_taken_0x13f6bc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x13f6bc) {
            ctx->pc = 0x13F6C0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13F6BCu;
            // 0x13f6c0: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13F6F4u;
            goto label_13f6f4;
        }
    }
    ctx->pc = 0x13F6C4u;
    // 0x13f6c4: 0x8e040020  lw          $a0, 0x20($s0)
    ctx->pc = 0x13f6c4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x13f6c8: 0x40f809  jalr        $v0
    ctx->pc = 0x13F6C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13F6D0u);
        ctx->pc = 0x13F6CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F6C8u;
            // 0x13f6cc: 0x2405fffd  addiu       $a1, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13F6D0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13F664u: goto label_13f664;
            case 0x13F6B8u: goto label_13f6b8;
            case 0x13F6D0u: goto label_13f6d0;
            case 0x13F6D8u: goto label_13f6d8;
            case 0x13F6F0u: goto label_13f6f0;
            case 0x13F6F4u: goto label_13f6f4;
            case 0x13F708u: goto label_13f708;
            case 0x13F70Cu: goto label_13f70c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13F6D0u; }
            if (ctx->pc != 0x13F6D0u) { return; }
        }
        }
    }
    ctx->pc = 0x13F6D0u;
label_13f6d0:
    // 0x13f6d0: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x13F6D0u;
    {
        const bool branch_taken_0x13f6d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13F6D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F6D0u;
            // 0x13f6d4: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f6d0) {
            ctx->pc = 0x13F6F4u;
            goto label_13f6f4;
        }
    }
    ctx->pc = 0x13F6D8u;
label_13f6d8:
    // 0x13f6d8: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x13f6d8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x13f6dc: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x13F6DCu;
    {
        const bool branch_taken_0x13f6dc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13F6E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F6DCu;
            // 0x13f6e0: 0xae200004  sw          $zero, 0x4($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f6dc) {
            ctx->pc = 0x13F6F0u;
            goto label_13f6f0;
        }
    }
    ctx->pc = 0x13F6E4u;
    // 0x13f6e4: 0x8e040020  lw          $a0, 0x20($s0)
    ctx->pc = 0x13f6e4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x13f6e8: 0x40f809  jalr        $v0
    ctx->pc = 0x13F6E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13F6F0u);
        ctx->pc = 0x13F6ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F6E8u;
            // 0x13f6ec: 0x2405fffd  addiu       $a1, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13F6F0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13F664u: goto label_13f664;
            case 0x13F6B8u: goto label_13f6b8;
            case 0x13F6D0u: goto label_13f6d0;
            case 0x13F6D8u: goto label_13f6d8;
            case 0x13F6F0u: goto label_13f6f0;
            case 0x13F6F4u: goto label_13f6f4;
            case 0x13F708u: goto label_13f708;
            case 0x13F70Cu: goto label_13f70c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13F6F0u; }
            if (ctx->pc != 0x13F6F0u) { return; }
        }
        }
    }
    ctx->pc = 0x13F6F0u;
label_13f6f0:
    // 0x13f6f0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13f6f0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_13f6f4:
    // 0x13f6f4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13f6f4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13f6f8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13f6f8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13f6fc: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x13f6fcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13f700: 0x804fc9c  j           func_13F270
    ctx->pc = 0x13F700u;
    ctx->pc = 0x13F704u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F700u;
            // 0x13f704: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F270u;
    if (runtime->hasFunction(0x13F270u)) {
        auto targetFn = runtime->lookupFunction(0x13F270u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013F270_0x13f270(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13F708u;
label_13f708:
    // 0x13f708: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13f708u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_13f70c:
    // 0x13f70c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13f70cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13f710: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13f710u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13f714: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x13f714u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13f718: 0x3e00008  jr          $ra
    ctx->pc = 0x13F718u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F71Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F718u;
            // 0x13f71c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13F664u: goto label_13f664;
            case 0x13F6B8u: goto label_13f6b8;
            case 0x13F6D0u: goto label_13f6d0;
            case 0x13F6D8u: goto label_13f6d8;
            case 0x13F6F0u: goto label_13f6f0;
            case 0x13F6F4u: goto label_13f6f4;
            case 0x13F708u: goto label_13f708;
            case 0x13F70Cu: goto label_13f70c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13F720u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
