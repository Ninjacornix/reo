#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016D508
// Address: 0x16d508 - 0x16d5c8
void sub_0016D508_0x16d508(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016D508_0x16d508");
#endif

    switch (ctx->pc) {
        case 0x16d538u: goto label_16d538;
        case 0x16d54cu: goto label_16d54c;
        case 0x16d558u: goto label_16d558;
        case 0x16d574u: goto label_16d574;
        case 0x16d588u: goto label_16d588;
        case 0x16d5a8u: goto label_16d5a8;
        default: break;
    }

    ctx->pc = 0x16d508u;

    // 0x16d508: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x16d508u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x16d50c: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x16d50cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x16d510: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x16d510u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d514: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x16d514u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x16d518: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x16d518u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d51c: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x16d51cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x16d520: 0x24120080  addiu       $s2, $zero, 0x80
    ctx->pc = 0x16d520u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x16d524: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x16d524u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x16d528: 0x24130004  addiu       $s3, $zero, 0x4
    ctx->pc = 0x16d528u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x16d52c: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x16D52Cu;
    {
        const bool branch_taken_0x16d52c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16D530u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D52Cu;
            // 0x16d530: 0xffbf0030  sd          $ra, 0x30($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d52c) {
            ctx->pc = 0x16D558u;
            goto label_16d558;
        }
    }
    ctx->pc = 0x16D534u;
    // 0x16d534: 0x0  nop
    ctx->pc = 0x16d534u;
    // NOP
label_16d538:
    // 0x16d538: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x16d538u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x16d53c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x16d53cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d540: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x16d540u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x16d544: 0x40f809  jalr        $v0
    ctx->pc = 0x16D544u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x16D54Cu);
        ctx->pc = 0x16D548u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D544u;
            // 0x16d548: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x16D54Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16D538u: goto label_16d538;
            case 0x16D54Cu: goto label_16d54c;
            case 0x16D558u: goto label_16d558;
            case 0x16D574u: goto label_16d574;
            case 0x16D588u: goto label_16d588;
            case 0x16D594u: goto label_16d594;
            case 0x16D5A8u: goto label_16d5a8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x16D54Cu; }
            if (ctx->pc != 0x16D54Cu) { return; }
        }
        }
    }
    ctx->pc = 0x16D54Cu;
label_16d54c:
    // 0x16d54c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x16d54cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d550: 0xc05b572  jal         func_16D5C8
    ctx->pc = 0x16D550u;
    SET_GPR_U32(ctx, 31, 0x16D558u);
    ctx->pc = 0x16D554u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D550u;
            // 0x16d554: 0x24050004  addiu       $a1, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16D5C8u;
    if (runtime->hasFunction(0x16D5C8u)) {
        auto targetFn = runtime->lookupFunction(0x16D5C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D558u; }
        if (ctx->pc != 0x16D558u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016D5C8_0x16d5c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D558u; }
        if (ctx->pc != 0x16D558u) { return; }
    }
    ctx->pc = 0x16D558u;
label_16d558:
    // 0x16d558: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x16d558u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x16d55c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16d55cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d560: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x16d560u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16d564: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x16d564u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x16d568: 0x8c430018  lw          $v1, 0x18($v0)
    ctx->pc = 0x16d568u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x16d56c: 0x60f809  jalr        $v1
    ctx->pc = 0x16D56Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x16D574u);
        ctx->pc = 0x16D570u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D56Cu;
            // 0x16d570: 0x3a0382d  daddu       $a3, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x16D574u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16D538u: goto label_16d538;
            case 0x16D54Cu: goto label_16d54c;
            case 0x16D558u: goto label_16d558;
            case 0x16D574u: goto label_16d574;
            case 0x16D588u: goto label_16d588;
            case 0x16D594u: goto label_16d594;
            case 0x16D5A8u: goto label_16d5a8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x16D574u; }
            if (ctx->pc != 0x16D574u) { return; }
        }
        }
    }
    ctx->pc = 0x16D574u;
label_16d574:
    // 0x16d574: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x16d574u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x16d578: 0x54530006  bnel        $v0, $s3, . + 4 + (0x6 << 2)
    ctx->pc = 0x16D578u;
    {
        const bool branch_taken_0x16d578 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 19));
        if (branch_taken_0x16d578) {
            ctx->pc = 0x16D57Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16D578u;
            // 0x16d57c: 0x8e030000  lw          $v1, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16D594u;
            goto label_16d594;
        }
    }
    ctx->pc = 0x16D580u;
    // 0x16d580: 0xc05616e  jal         func_1585B8
    ctx->pc = 0x16D580u;
    SET_GPR_U32(ctx, 31, 0x16D588u);
    ctx->pc = 0x16D584u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D580u;
            // 0x16d584: 0x8fa40000  lw          $a0, 0x0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1585B8u;
    if (runtime->hasFunction(0x1585B8u)) {
        auto targetFn = runtime->lookupFunction(0x1585B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D588u; }
        if (ctx->pc != 0x16D588u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001585B8_0x1585b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D588u; }
        if (ctx->pc != 0x16D588u) { return; }
    }
    ctx->pc = 0x16D588u;
label_16d588:
    // 0x16d588: 0x1052ffeb  beq         $v0, $s2, . + 4 + (-0x15 << 2)
    ctx->pc = 0x16D588u;
    {
        const bool branch_taken_0x16d588 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 18));
        ctx->pc = 0x16D58Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D588u;
            // 0x16d58c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d588) {
            ctx->pc = 0x16D538u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_16d538;
        }
    }
    ctx->pc = 0x16D590u;
    // 0x16d590: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x16d590u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_16d594:
    // 0x16d594: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16d594u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d598: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x16d598u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16d59c: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x16d59cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x16d5a0: 0x40f809  jalr        $v0
    ctx->pc = 0x16D5A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x16D5A8u);
        ctx->pc = 0x16D5A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D5A0u;
            // 0x16d5a4: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x16D5A8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16D538u: goto label_16d538;
            case 0x16D54Cu: goto label_16d54c;
            case 0x16D558u: goto label_16d558;
            case 0x16D574u: goto label_16d574;
            case 0x16D588u: goto label_16d588;
            case 0x16D594u: goto label_16d594;
            case 0x16D5A8u: goto label_16d5a8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x16D5A8u; }
            if (ctx->pc != 0x16D5A8u) { return; }
        }
        }
    }
    ctx->pc = 0x16D5A8u;
label_16d5a8:
    // 0x16d5a8: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x16d5a8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16d5ac: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x16d5acu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16d5b0: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x16d5b0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16d5b4: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x16d5b4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16d5b8: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x16d5b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x16d5bc: 0x3e00008  jr          $ra
    ctx->pc = 0x16D5BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16D5C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D5BCu;
            // 0x16d5c0: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16D538u: goto label_16d538;
            case 0x16D54Cu: goto label_16d54c;
            case 0x16D558u: goto label_16d558;
            case 0x16D574u: goto label_16d574;
            case 0x16D588u: goto label_16d588;
            case 0x16D594u: goto label_16d594;
            case 0x16D5A8u: goto label_16d5a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16D5C4u;
    // 0x16d5c4: 0x0  nop
    ctx->pc = 0x16d5c4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
