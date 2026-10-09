#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001775E0
// Address: 0x1775e0 - 0x177698
void sub_001775E0_0x1775e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001775E0_0x1775e0");
#endif

    switch (ctx->pc) {
        case 0x177618u: goto label_177618;
        case 0x177630u: goto label_177630;
        case 0x177644u: goto label_177644;
        default: break;
    }

    ctx->pc = 0x1775e0u;

    // 0x1775e0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1775e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1775e4: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x1775e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x1775e8: 0x8cd30000  lw          $s3, 0x0($a2)
    ctx->pc = 0x1775e8u;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1775ec: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1775ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1775f0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1775f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1775f4: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1775f4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1775f8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1775f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1775fc: 0x260882d  daddu       $s1, $s3, $zero
    ctx->pc = 0x1775fcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177600: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x177600u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x177604: 0x24120008  addiu       $s2, $zero, 0x8
    ctx->pc = 0x177604u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x177608: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x177608u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x17760c: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x17760cu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177610: 0xae000008  sw          $zero, 0x8($s0)
    ctx->pc = 0x177610u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 0));
    // 0x177614: 0x0  nop
    ctx->pc = 0x177614u;
    // NOP
label_177618:
    // 0x177618: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x177618u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17761c: 0x2652ffff  addiu       $s2, $s2, -0x1
    ctx->pc = 0x17761cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967295));
    // 0x177620: 0x26100044  addiu       $s0, $s0, 0x44
    ctx->pc = 0x177620u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 68));
    // 0x177624: 0x8e250000  lw          $a1, 0x0($s1)
    ctx->pc = 0x177624u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x177628: 0xc05dda6  jal         func_177698
    ctx->pc = 0x177628u;
    SET_GPR_U32(ctx, 31, 0x177630u);
    ctx->pc = 0x17762Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x177628u;
            // 0x17762c: 0x26310004  addiu       $s1, $s1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177698u;
    if (runtime->hasFunction(0x177698u)) {
        auto targetFn = runtime->lookupFunction(0x177698u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177630u; }
        if (ctx->pc != 0x177630u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177698_0x177698(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177630u; }
        if (ctx->pc != 0x177630u) { return; }
    }
    ctx->pc = 0x177630u;
label_177630:
    // 0x177630: 0x643fff9  bgezl       $s2, . + 4 + (-0x7 << 2)
    ctx->pc = 0x177630u;
    {
        const bool branch_taken_0x177630 = (GPR_S64(ctx, 18) >= 0);
        if (branch_taken_0x177630) {
            ctx->pc = 0x177634u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x177630u;
            // 0x177634: 0xae000008  sw          $zero, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x177618u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_177618;
        }
    }
    ctx->pc = 0x177638u;
    // 0x177638: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x177638u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17763c: 0xc05ddb8  jal         func_1776E0
    ctx->pc = 0x17763Cu;
    SET_GPR_U32(ctx, 31, 0x177644u);
    ctx->pc = 0x177640u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17763Cu;
            // 0x177640: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1776E0u;
    if (runtime->hasFunction(0x1776E0u)) {
        auto targetFn = runtime->lookupFunction(0x1776E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177644u; }
        if (ctx->pc != 0x177644u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001776E0_0x1776e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177644u; }
        if (ctx->pc != 0x177644u) { return; }
    }
    ctx->pc = 0x177644u;
label_177644:
    // 0x177644: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x177644u;
    {
        const bool branch_taken_0x177644 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x177648u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177644u;
            // 0x177648: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x177644) {
            ctx->pc = 0x177678u;
            goto label_177678;
        }
    }
    ctx->pc = 0x17764Cu;
    // 0x17764c: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x17764cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x177650: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x177650u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x177654: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x177654u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x177658: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x177658u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17765c: 0x34a50302  ori         $a1, $a1, 0x302
    ctx->pc = 0x17765cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)770);
    // 0x177660: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x177660u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x177664: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x177664u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x177668: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x177668u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x17766c: 0x805a704  j           func_169C10
    ctx->pc = 0x17766Cu;
    ctx->pc = 0x177670u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17766Cu;
            // 0x177670: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x177674u;
    // 0x177674: 0x0  nop
    ctx->pc = 0x177674u;
    // NOP
label_177678:
    // 0x177678: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x177678u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17767c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17767cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x177680: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x177680u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x177684: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x177684u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x177688: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x177688u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17768c: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x17768cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x177690: 0x3e00008  jr          $ra
    ctx->pc = 0x177690u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x177694u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177690u;
            // 0x177694: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x177618u: goto label_177618;
            case 0x177630u: goto label_177630;
            case 0x177644u: goto label_177644;
            case 0x177678u: goto label_177678;
            default: break;
        }
        return;
    }
    ctx->pc = 0x177698u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
