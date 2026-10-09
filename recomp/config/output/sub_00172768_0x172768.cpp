#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00172768
// Address: 0x172768 - 0x172828
void sub_00172768_0x172768(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00172768_0x172768");
#endif

    switch (ctx->pc) {
        case 0x17278cu: goto label_17278c;
        case 0x17279cu: goto label_17279c;
        case 0x1727f0u: goto label_1727f0;
        case 0x172800u: goto label_172800;
        default: break;
    }

    ctx->pc = 0x172768u;

    // 0x172768: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x172768u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17276c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17276cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x172770: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x172770u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172774: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x172774u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x172778: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x172778u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17277c: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x17277cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x172780: 0x8e320048  lw          $s2, 0x48($s1)
    ctx->pc = 0x172780u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 72)));
    // 0x172784: 0xc05ca0a  jal         func_172828
    ctx->pc = 0x172784u;
    SET_GPR_U32(ctx, 31, 0x17278Cu);
    ctx->pc = 0x172788u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172784u;
            // 0x172788: 0x8e30004c  lw          $s0, 0x4C($s1) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 76)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x172828u;
    if (runtime->hasFunction(0x172828u)) {
        auto targetFn = runtime->lookupFunction(0x172828u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17278Cu; }
        if (ctx->pc != 0x17278Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00172828_0x172828(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17278Cu; }
        if (ctx->pc != 0x17278Cu) { return; }
    }
    ctx->pc = 0x17278Cu;
label_17278c:
    // 0x17278c: 0x50400020  beql        $v0, $zero, . + 4 + (0x20 << 2)
    ctx->pc = 0x17278Cu;
    {
        const bool branch_taken_0x17278c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x17278c) {
            ctx->pc = 0x172790u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17278Cu;
            // 0x172790: 0x240102d  daddu       $v0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x172810u;
            goto label_172810;
        }
    }
    ctx->pc = 0x172794u;
    // 0x172794: 0xc05ca36  jal         func_1728D8
    ctx->pc = 0x172794u;
    SET_GPR_U32(ctx, 31, 0x17279Cu);
    ctx->pc = 0x172798u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172794u;
            // 0x172798: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1728D8u;
    if (runtime->hasFunction(0x1728D8u)) {
        auto targetFn = runtime->lookupFunction(0x1728D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17279Cu; }
        if (ctx->pc != 0x17279Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001728D8_0x1728d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17279Cu; }
        if (ctx->pc != 0x17279Cu) { return; }
    }
    ctx->pc = 0x17279Cu;
label_17279c:
    // 0x17279c: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x17279cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1727a0: 0x12020019  beq         $s0, $v0, . + 4 + (0x19 << 2)
    ctx->pc = 0x1727A0u;
    {
        const bool branch_taken_0x1727a0 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x1727A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1727A0u;
            // 0x1727a4: 0x2a020004  slti        $v0, $s0, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)4) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1727a0) {
            ctx->pc = 0x172808u;
            goto label_172808;
        }
    }
    ctx->pc = 0x1727A8u;
    // 0x1727a8: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1727A8u;
    {
        const bool branch_taken_0x1727a8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1727ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1727A8u;
            // 0x1727ac: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1727a8) {
            ctx->pc = 0x1727C8u;
            goto label_1727c8;
        }
    }
    ctx->pc = 0x1727B0u;
    // 0x1727b0: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1727b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1727b4: 0x1202000a  beq         $s0, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1727B4u;
    {
        const bool branch_taken_0x1727b4 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x1727B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1727B4u;
            // 0x1727b8: 0x240102d  daddu       $v0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1727b4) {
            ctx->pc = 0x1727E0u;
            goto label_1727e0;
        }
    }
    ctx->pc = 0x1727BCu;
    // 0x1727bc: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x1727BCu;
    {
        const bool branch_taken_0x1727bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1727C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1727BCu;
            // 0x1727c0: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1727bc) {
            ctx->pc = 0x172814u;
            goto label_172814;
        }
    }
    ctx->pc = 0x1727C4u;
    // 0x1727c4: 0x0  nop
    ctx->pc = 0x1727c4u;
    // NOP
label_1727c8:
    // 0x1727c8: 0x12020007  beq         $s0, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1727C8u;
    {
        const bool branch_taken_0x1727c8 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x1727CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1727C8u;
            // 0x1727cc: 0x24020006  addiu       $v0, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1727c8) {
            ctx->pc = 0x1727E8u;
            goto label_1727e8;
        }
    }
    ctx->pc = 0x1727D0u;
    // 0x1727d0: 0x12020005  beq         $s0, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1727D0u;
    {
        const bool branch_taken_0x1727d0 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x1727D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1727D0u;
            // 0x1727d4: 0x240102d  daddu       $v0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1727d0) {
            ctx->pc = 0x1727E8u;
            goto label_1727e8;
        }
    }
    ctx->pc = 0x1727D8u;
    // 0x1727d8: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1727D8u;
    {
        const bool branch_taken_0x1727d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1727DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1727D8u;
            // 0x1727dc: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1727d8) {
            ctx->pc = 0x172814u;
            goto label_172814;
        }
    }
    ctx->pc = 0x1727E0u;
label_1727e0:
    // 0x1727e0: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1727E0u;
    {
        const bool branch_taken_0x1727e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1727E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1727E0u;
            // 0x1727e4: 0x24120002  addiu       $s2, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1727e0) {
            ctx->pc = 0x17280Cu;
            goto label_17280c;
        }
    }
    ctx->pc = 0x1727E8u;
label_1727e8:
    // 0x1727e8: 0xc05caf8  jal         func_172BE0
    ctx->pc = 0x1727E8u;
    SET_GPR_U32(ctx, 31, 0x1727F0u);
    ctx->pc = 0x1727ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1727E8u;
            // 0x1727ec: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x172BE0u;
    if (runtime->hasFunction(0x172BE0u)) {
        auto targetFn = runtime->lookupFunction(0x172BE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1727F0u; }
        if (ctx->pc != 0x1727F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00172BE0_0x172be0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1727F0u; }
        if (ctx->pc != 0x1727F0u) { return; }
    }
    ctx->pc = 0x1727F0u;
label_1727f0:
    // 0x1727f0: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1727F0u;
    {
        const bool branch_taken_0x1727f0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1727F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1727F0u;
            // 0x1727f4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1727f0) {
            ctx->pc = 0x172808u;
            goto label_172808;
        }
    }
    ctx->pc = 0x1727F8u;
    // 0x1727f8: 0xc05cec0  jal         func_173B00
    ctx->pc = 0x1727F8u;
    SET_GPR_U32(ctx, 31, 0x172800u);
    ctx->pc = 0x1727FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1727F8u;
            // 0x1727fc: 0x24120004  addiu       $s2, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x173B00u;
    if (runtime->hasFunction(0x173B00u)) {
        auto targetFn = runtime->lookupFunction(0x173B00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172800u; }
        if (ctx->pc != 0x172800u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00173B00_0x173b00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172800u; }
        if (ctx->pc != 0x172800u) { return; }
    }
    ctx->pc = 0x172800u;
label_172800:
    // 0x172800: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x172800u;
    {
        const bool branch_taken_0x172800 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x172804u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172800u;
            // 0x172804: 0x240102d  daddu       $v0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172800) {
            ctx->pc = 0x172810u;
            goto label_172810;
        }
    }
    ctx->pc = 0x172808u;
label_172808:
    // 0x172808: 0x24120003  addiu       $s2, $zero, 0x3
    ctx->pc = 0x172808u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
label_17280c:
    // 0x17280c: 0x240102d  daddu       $v0, $s2, $zero
    ctx->pc = 0x17280cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_172810:
    // 0x172810: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x172810u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_172814:
    // 0x172814: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x172814u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x172818: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x172818u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17281c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17281cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x172820: 0x3e00008  jr          $ra
    ctx->pc = 0x172820u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x172824u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172820u;
            // 0x172824: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17278Cu: goto label_17278c;
            case 0x17279Cu: goto label_17279c;
            case 0x1727C8u: goto label_1727c8;
            case 0x1727E0u: goto label_1727e0;
            case 0x1727E8u: goto label_1727e8;
            case 0x1727F0u: goto label_1727f0;
            case 0x172800u: goto label_172800;
            case 0x172808u: goto label_172808;
            case 0x17280Cu: goto label_17280c;
            case 0x172810u: goto label_172810;
            case 0x172814u: goto label_172814;
            default: break;
        }
        return;
    }
    ctx->pc = 0x172828u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
