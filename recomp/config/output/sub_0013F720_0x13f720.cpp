#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013F720
// Address: 0x13f720 - 0x13f7c4
void sub_0013F720_0x13f720(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013F720_0x13f720");
#endif

    switch (ctx->pc) {
        case 0x13f754u: goto label_13f754;
        case 0x13f794u: goto label_13f794;
        case 0x13f79cu: goto label_13f79c;
        default: break;
    }

    ctx->pc = 0x13f720u;

    // 0x13f720: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x13f720u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x13f724: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x13f724u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x13f728: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x13f728u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f72c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13f72cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13f730: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x13f730u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f734: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13f734u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13f738: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x13f738u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f73c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13f73cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13f740: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x13f740u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f744: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x13f744u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x13f748: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x13f748u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x13f74c: 0xc04fc96  jal         func_13F258
    ctx->pc = 0x13F74Cu;
    SET_GPR_U32(ctx, 31, 0x13F754u);
    ctx->pc = 0x13F750u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F74Cu;
            // 0x13f750: 0xe0a02d  daddu       $s4, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F258u;
    if (runtime->hasFunction(0x13F258u)) {
        auto targetFn = runtime->lookupFunction(0x13F258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F754u; }
        if (ctx->pc != 0x13F754u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F258_0x13f258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F754u; }
        if (ctx->pc != 0x13F754u) { return; }
    }
    ctx->pc = 0x13F754u;
label_13f754:
    // 0x13f754: 0x1260000f  beqz        $s3, . + 4 + (0xF << 2)
    ctx->pc = 0x13F754u;
    {
        const bool branch_taken_0x13f754 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x13F758u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F754u;
            // 0x13f758: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f754) {
            ctx->pc = 0x13F794u;
            goto label_13f794;
        }
    }
    ctx->pc = 0x13F75Cu;
    // 0x13f75c: 0x56620008  bnel        $s3, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x13F75Cu;
    {
        const bool branch_taken_0x13f75c = (GPR_U64(ctx, 19) != GPR_U64(ctx, 2));
        if (branch_taken_0x13f75c) {
            ctx->pc = 0x13F760u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13F75Cu;
            // 0x13f760: 0x8e02001c  lw          $v0, 0x1C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13F780u;
            goto label_13f780;
        }
    }
    ctx->pc = 0x13F764u;
    // 0x13f764: 0x8e04000c  lw          $a0, 0xC($s0)
    ctx->pc = 0x13f764u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x13f768: 0x92102a  slt         $v0, $a0, $s2
    ctx->pc = 0x13f768u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x13f76c: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x13F76Cu;
    {
        const bool branch_taken_0x13f76c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13F770u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F76Cu;
            // 0x13f770: 0x240882d  daddu       $s1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f76c) {
            ctx->pc = 0x13F794u;
            goto label_13f794;
        }
    }
    ctx->pc = 0x13F774u;
    // 0x13f774: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x13F774u;
    {
        const bool branch_taken_0x13f774 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13F778u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F774u;
            // 0x13f778: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f774) {
            ctx->pc = 0x13F794u;
            goto label_13f794;
        }
    }
    ctx->pc = 0x13F77Cu;
    // 0x13f77c: 0x0  nop
    ctx->pc = 0x13f77cu;
    // NOP
label_13f780:
    // 0x13f780: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x13F780u;
    {
        const bool branch_taken_0x13f780 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13F784u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F780u;
            // 0x13f784: 0x882d  daddu       $s1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f780) {
            ctx->pc = 0x13F794u;
            goto label_13f794;
        }
    }
    ctx->pc = 0x13F788u;
    // 0x13f788: 0x8e040020  lw          $a0, 0x20($s0)
    ctx->pc = 0x13f788u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x13f78c: 0x40f809  jalr        $v0
    ctx->pc = 0x13F78Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13F794u);
        ctx->pc = 0x13F790u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F78Cu;
            // 0x13f790: 0x2405fffd  addiu       $a1, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13F794u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13F754u: goto label_13f754;
            case 0x13F780u: goto label_13f780;
            case 0x13F794u: goto label_13f794;
            case 0x13F79Cu: goto label_13f79c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13F794u; }
            if (ctx->pc != 0x13F794u) { return; }
        }
        }
    }
    ctx->pc = 0x13F794u;
label_13f794:
    // 0x13f794: 0xc04fc9c  jal         func_13F270
    ctx->pc = 0x13F794u;
    SET_GPR_U32(ctx, 31, 0x13F79Cu);
    ctx->pc = 0x13F798u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F794u;
            // 0x13f798: 0xae910000  sw          $s1, 0x0($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 0), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F270u;
    if (runtime->hasFunction(0x13F270u)) {
        auto targetFn = runtime->lookupFunction(0x13F270u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F79Cu; }
        if (ctx->pc != 0x13F79Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F270_0x13f270(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F79Cu; }
        if (ctx->pc != 0x13F79Cu) { return; }
    }
    ctx->pc = 0x13F79Cu;
label_13f79c:
    // 0x13f79c: 0x2321026  xor         $v0, $s1, $s2
    ctx->pc = 0x13f79cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) ^ GPR_U64(ctx, 18));
    // 0x13f7a0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13f7a0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13f7a4: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x13f7a4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    // 0x13f7a8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13f7a8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13f7ac: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13f7acu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13f7b0: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x13f7b0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13f7b4: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x13f7b4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13f7b8: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x13f7b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x13f7bc: 0x3e00008  jr          $ra
    ctx->pc = 0x13F7BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F7C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F7BCu;
            // 0x13f7c0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13F754u: goto label_13f754;
            case 0x13F780u: goto label_13f780;
            case 0x13F794u: goto label_13f794;
            case 0x13F79Cu: goto label_13f79c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13F7C4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
