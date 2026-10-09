#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016B5E8
// Address: 0x16b5e8 - 0x16b680
void sub_0016B5E8_0x16b5e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016B5E8_0x16b5e8");
#endif

    switch (ctx->pc) {
        case 0x16b614u: goto label_16b614;
        case 0x16b634u: goto label_16b634;
        default: break;
    }

    ctx->pc = 0x16b5e8u;

    // 0x16b5e8: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x16b5e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x16b5ec: 0xffb10038  sd          $s1, 0x38($sp)
    ctx->pc = 0x16b5ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 17));
    // 0x16b5f0: 0x2491090c  addiu       $s1, $a0, 0x90C
    ctx->pc = 0x16b5f0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), 2316));
    // 0x16b5f4: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x16b5f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x16b5f8: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x16b5f8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b5fc: 0xffb20040  sd          $s2, 0x40($sp)
    ctx->pc = 0x16b5fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x16b600: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x16b600u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x16b604: 0x8c921aec  lw          $s2, 0x1AEC($a0)
    ctx->pc = 0x16b604u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 6892)));
    // 0x16b608: 0x8e500000  lw          $s0, 0x0($s2)
    ctx->pc = 0x16b608u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x16b60c: 0xc055f74  jal         func_157DD0
    ctx->pc = 0x16B60Cu;
    SET_GPR_U32(ctx, 31, 0x16B614u);
    ctx->pc = 0x16B610u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16B60Cu;
            // 0x16b610: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x157DD0u;
    if (runtime->hasFunction(0x157DD0u)) {
        auto targetFn = runtime->lookupFunction(0x157DD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B614u; }
        if (ctx->pc != 0x16B614u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00157DD0_0x157dd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B614u; }
        if (ctx->pc != 0x16B614u) { return; }
    }
    ctx->pc = 0x16B614u;
label_16b614:
    // 0x16b614: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16b614u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b618: 0x8fa20008  lw          $v0, 0x8($sp)
    ctx->pc = 0x16b618u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16b61c: 0x27a50010  addiu       $a1, $sp, 0x10
    ctx->pc = 0x16b61cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x16b620: 0x18400002  blez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x16B620u;
    {
        const bool branch_taken_0x16b620 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x16B624u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16B620u;
            // 0x16b624: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16b620) {
            ctx->pc = 0x16B62Cu;
            goto label_16b62c;
        }
    }
    ctx->pc = 0x16B628u;
    // 0x16b628: 0xae220018  sw          $v0, 0x18($s1)
    ctx->pc = 0x16b628u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 24), GPR_U32(ctx, 2));
label_16b62c:
    // 0x16b62c: 0xc055f90  jal         func_157E40
    ctx->pc = 0x16B62Cu;
    SET_GPR_U32(ctx, 31, 0x16B634u);
    ctx->pc = 0x157E40u;
    if (runtime->hasFunction(0x157E40u)) {
        auto targetFn = runtime->lookupFunction(0x157E40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B634u; }
        if (ctx->pc != 0x16B634u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00157E40_0x157e40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B634u; }
        if (ctx->pc != 0x16B634u) { return; }
    }
    ctx->pc = 0x16B634u;
label_16b634:
    // 0x16b634: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x16b634u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x16b638: 0x8fa20020  lw          $v0, 0x20($sp)
    ctx->pc = 0x16b638u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16b63c: 0x54430001  bnel        $v0, $v1, . + 4 + (0x1 << 2)
    ctx->pc = 0x16B63Cu;
    {
        const bool branch_taken_0x16b63c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x16b63c) {
            ctx->pc = 0x16B640u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16B63Cu;
            // 0x16b640: 0xae22001c  sw          $v0, 0x1C($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 28), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16B644u;
            goto label_16b644;
        }
    }
    ctx->pc = 0x16B644u;
label_16b644:
    // 0x16b644: 0x8e220024  lw          $v0, 0x24($s1)
    ctx->pc = 0x16b644u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x16b648: 0x54430004  bnel        $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x16B648u;
    {
        const bool branch_taken_0x16b648 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x16b648) {
            ctx->pc = 0x16B64Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16B648u;
            // 0x16b64c: 0x8e220028  lw          $v0, 0x28($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 40)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16B65Cu;
            goto label_16b65c;
        }
    }
    ctx->pc = 0x16B650u;
    // 0x16b650: 0x8e420008  lw          $v0, 0x8($s2)
    ctx->pc = 0x16b650u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x16b654: 0xae220024  sw          $v0, 0x24($s1)
    ctx->pc = 0x16b654u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 36), GPR_U32(ctx, 2));
    // 0x16b658: 0x8e220028  lw          $v0, 0x28($s1)
    ctx->pc = 0x16b658u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 40)));
label_16b65c:
    // 0x16b65c: 0x14430003  bne         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x16B65Cu;
    {
        const bool branch_taken_0x16b65c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x16B660u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16B65Cu;
            // 0x16b660: 0xdfb00030  ld          $s0, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16b65c) {
            ctx->pc = 0x16B66Cu;
            goto label_16b66c;
        }
    }
    ctx->pc = 0x16B664u;
    // 0x16b664: 0x8e420004  lw          $v0, 0x4($s2)
    ctx->pc = 0x16b664u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x16b668: 0xae220028  sw          $v0, 0x28($s1)
    ctx->pc = 0x16b668u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 40), GPR_U32(ctx, 2));
label_16b66c:
    // 0x16b66c: 0xdfb10038  ld          $s1, 0x38($sp)
    ctx->pc = 0x16b66cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x16b670: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x16b670u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x16b674: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x16b674u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x16b678: 0x3e00008  jr          $ra
    ctx->pc = 0x16B678u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16B67Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16B678u;
            // 0x16b67c: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16B614u: goto label_16b614;
            case 0x16B62Cu: goto label_16b62c;
            case 0x16B634u: goto label_16b634;
            case 0x16B644u: goto label_16b644;
            case 0x16B65Cu: goto label_16b65c;
            case 0x16B66Cu: goto label_16b66c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16B680u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
