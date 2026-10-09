#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016F6A0
// Address: 0x16f6a0 - 0x16f778
void sub_0016F6A0_0x16f6a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016F6A0_0x16f6a0");
#endif

    switch (ctx->pc) {
        case 0x16f6c4u: goto label_16f6c4;
        case 0x16f6e4u: goto label_16f6e4;
        case 0x16f764u: goto label_16f764;
        default: break;
    }

    ctx->pc = 0x16f6a0u;

    // 0x16f6a0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x16f6a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x16f6a4: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x16f6a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x16f6a8: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x16f6a8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16f6ac: 0xffb10038  sd          $s1, 0x38($sp)
    ctx->pc = 0x16f6acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 17));
    // 0x16f6b0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x16f6b0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16f6b4: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x16f6b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x16f6b8: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x16f6b8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16f6bc: 0xc059bfa  jal         func_166FE8
    ctx->pc = 0x16F6BCu;
    SET_GPR_U32(ctx, 31, 0x16F6C4u);
    ctx->pc = 0x16F6C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16F6BCu;
            // 0x16f6c0: 0x8e251b38  lw          $a1, 0x1B38($s1) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 6968)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166FE8u;
    if (runtime->hasFunction(0x166FE8u)) {
        auto targetFn = runtime->lookupFunction(0x166FE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F6C4u; }
        if (ctx->pc != 0x16F6C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00166FE8_0x166fe8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F6C4u; }
        if (ctx->pc != 0x16F6C4u) { return; }
    }
    ctx->pc = 0x16F6C4u;
label_16f6c4:
    // 0x16f6c4: 0x54400028  bnel        $v0, $zero, . + 4 + (0x28 << 2)
    ctx->pc = 0x16F6C4u;
    {
        const bool branch_taken_0x16f6c4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x16f6c4) {
            ctx->pc = 0x16F6C8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16F6C4u;
            // 0x16f6c8: 0xdfb00030  ld          $s0, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16F768u;
            goto label_16f768;
        }
    }
    ctx->pc = 0x16F6CCu;
    // 0x16f6cc: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x16f6ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x16f6d0: 0x10400024  beqz        $v0, . + 4 + (0x24 << 2)
    ctx->pc = 0x16F6D0u;
    {
        const bool branch_taken_0x16f6d0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16F6D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16F6D0u;
            // 0x16f6d4: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16f6d0) {
            ctx->pc = 0x16F764u;
            goto label_16f764;
        }
    }
    ctx->pc = 0x16F6D8u;
    // 0x16f6d8: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x16f6d8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16f6dc: 0xc05b326  jal         func_16CC98
    ctx->pc = 0x16F6DCu;
    SET_GPR_U32(ctx, 31, 0x16F6E4u);
    ctx->pc = 0x16F6E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16F6DCu;
            // 0x16f6e0: 0x27a60020  addiu       $a2, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16CC98u;
    if (runtime->hasFunction(0x16CC98u)) {
        auto targetFn = runtime->lookupFunction(0x16CC98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F6E4u; }
        if (ctx->pc != 0x16F6E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016CC98_0x16cc98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F6E4u; }
        if (ctx->pc != 0x16F6E4u) { return; }
    }
    ctx->pc = 0x16F6E4u;
label_16f6e4:
    // 0x16f6e4: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x16f6e4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16f6e8: 0x14800009  bnez        $a0, . + 4 + (0x9 << 2)
    ctx->pc = 0x16F6E8u;
    {
        const bool branch_taken_0x16f6e8 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x16F6ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16F6E8u;
            // 0x16f6ec: 0x8fa30000  lw          $v1, 0x0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16f6e8) {
            ctx->pc = 0x16F710u;
            goto label_16f710;
        }
    }
    ctx->pc = 0x16F6F0u;
    // 0x16f6f0: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x16f6f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x16f6f4: 0x8fa3000c  lw          $v1, 0xC($sp)
    ctx->pc = 0x16f6f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x16f6f8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x16f6f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x16f6fc: 0x2445fffd  addiu       $a1, $v0, -0x3
    ctx->pc = 0x16f6fcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967293));
    // 0x16f700: 0x4a10016  bgez        $a1, . + 4 + (0x16 << 2)
    ctx->pc = 0x16F700u;
    {
        const bool branch_taken_0x16f700 = (GPR_S64(ctx, 5) >= 0);
        if (branch_taken_0x16f700) {
            ctx->pc = 0x16F75Cu;
            goto label_16f75c;
        }
    }
    ctx->pc = 0x16F708u;
    // 0x16f708: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x16F708u;
    {
        const bool branch_taken_0x16f708 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16F70Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16F708u;
            // 0x16f70c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16f708) {
            ctx->pc = 0x16F75Cu;
            goto label_16f75c;
        }
    }
    ctx->pc = 0x16F710u;
label_16f710:
    // 0x16f710: 0x83102b  sltu        $v0, $a0, $v1
    ctx->pc = 0x16f710u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x16f714: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x16F714u;
    {
        const bool branch_taken_0x16f714 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16F718u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16F714u;
            // 0x16f718: 0x8fa60008  lw          $a2, 0x8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16f714) {
            ctx->pc = 0x16F734u;
            goto label_16f734;
        }
    }
    ctx->pc = 0x16F71Cu;
    // 0x16f71c: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x16f71cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x16f720: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x16f720u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x16f724: 0x82102b  sltu        $v0, $a0, $v0
    ctx->pc = 0x16f724u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x16f728: 0x1440000c  bnez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x16F728u;
    {
        const bool branch_taken_0x16f728 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16F72Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16F728u;
            // 0x16f72c: 0x832823  subu        $a1, $a0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16f728) {
            ctx->pc = 0x16F75Cu;
            goto label_16f75c;
        }
    }
    ctx->pc = 0x16F730u;
    // 0x16f730: 0x8fa60008  lw          $a2, 0x8($sp)
    ctx->pc = 0x16f730u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
label_16f734:
    // 0x16f734: 0x86102b  sltu        $v0, $a0, $a2
    ctx->pc = 0x16f734u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 6)) ? 1 : 0);
    // 0x16f738: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x16F738u;
    {
        const bool branch_taken_0x16f738 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16F73Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16F738u;
            // 0x16f73c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16f738) {
            ctx->pc = 0x16F75Cu;
            goto label_16f75c;
        }
    }
    ctx->pc = 0x16F740u;
    // 0x16f740: 0x8fa2000c  lw          $v0, 0xC($sp)
    ctx->pc = 0x16f740u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x16f744: 0xc21021  addu        $v0, $a2, $v0
    ctx->pc = 0x16f744u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x16f748: 0x82102b  sltu        $v0, $a0, $v0
    ctx->pc = 0x16f748u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x16f74c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x16F74Cu;
    {
        const bool branch_taken_0x16f74c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16F750u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16F74Cu;
            // 0x16f750: 0x8fa30004  lw          $v1, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16f74c) {
            ctx->pc = 0x16F75Cu;
            goto label_16f75c;
        }
    }
    ctx->pc = 0x16F754u;
    // 0x16f754: 0x861023  subu        $v0, $a0, $a2
    ctx->pc = 0x16f754u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
    // 0x16f758: 0x432821  addu        $a1, $v0, $v1
    ctx->pc = 0x16f758u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_16f75c:
    // 0x16f75c: 0xc05bdde  jal         func_16F778
    ctx->pc = 0x16F75Cu;
    SET_GPR_U32(ctx, 31, 0x16F764u);
    ctx->pc = 0x16F760u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16F75Cu;
            // 0x16f760: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16F778u;
    if (runtime->hasFunction(0x16F778u)) {
        auto targetFn = runtime->lookupFunction(0x16F778u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F764u; }
        if (ctx->pc != 0x16F764u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016F778_0x16f778(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F764u; }
        if (ctx->pc != 0x16F764u) { return; }
    }
    ctx->pc = 0x16F764u;
label_16f764:
    // 0x16f764: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x16f764u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_16f768:
    // 0x16f768: 0xdfb10038  ld          $s1, 0x38($sp)
    ctx->pc = 0x16f768u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x16f76c: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x16f76cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x16f770: 0x3e00008  jr          $ra
    ctx->pc = 0x16F770u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16F774u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16F770u;
            // 0x16f774: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16F6C4u: goto label_16f6c4;
            case 0x16F6E4u: goto label_16f6e4;
            case 0x16F710u: goto label_16f710;
            case 0x16F734u: goto label_16f734;
            case 0x16F75Cu: goto label_16f75c;
            case 0x16F764u: goto label_16f764;
            case 0x16F768u: goto label_16f768;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16F778u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
