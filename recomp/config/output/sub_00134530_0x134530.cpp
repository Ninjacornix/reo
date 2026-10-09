#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00134530
// Address: 0x134530 - 0x1345f0
void sub_00134530_0x134530(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00134530_0x134530");
#endif

    switch (ctx->pc) {
        case 0x134558u: goto label_134558;
        case 0x134578u: goto label_134578;
        case 0x134588u: goto label_134588;
        case 0x1345b0u: goto label_1345b0;
        default: break;
    }

    ctx->pc = 0x134530u;

    // 0x134530: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x134530u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x134534: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x134534u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x134538: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x134538u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13453c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13453cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x134540: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x134540u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x134544: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x134544u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x134548: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x134548u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x13454c: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x13454cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x134550: 0xc04b2ee  jal         func_12CBB8
    ctx->pc = 0x134550u;
    SET_GPR_U32(ctx, 31, 0x134558u);
    ctx->pc = 0x134554u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134550u;
            // 0x134554: 0x8e640004  lw          $a0, 0x4($s3) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12CBB8u;
    if (runtime->hasFunction(0x12CBB8u)) {
        auto targetFn = runtime->lookupFunction(0x12CBB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134558u; }
        if (ctx->pc != 0x134558u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012CBB8_0x12cbb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134558u; }
        if (ctx->pc != 0x134558u) { return; }
    }
    ctx->pc = 0x134558u;
label_134558:
    // 0x134558: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x134558u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x13455c: 0x5443001c  bnel        $v0, $v1, . + 4 + (0x1C << 2)
    ctx->pc = 0x13455Cu;
    {
        const bool branch_taken_0x13455c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x13455c) {
            ctx->pc = 0x134560u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13455Cu;
            // 0x134560: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1345D0u;
            goto label_1345d0;
        }
    }
    ctx->pc = 0x134564u;
    // 0x134564: 0x8e640004  lw          $a0, 0x4($s3)
    ctx->pc = 0x134564u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 4)));
    // 0x134568: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x134568u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13456c: 0x3c140022  lui         $s4, 0x22
    ctx->pc = 0x13456cu;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)34 << 16));
    // 0x134570: 0xc04b5ea  jal         func_12D7A8
    ctx->pc = 0x134570u;
    SET_GPR_U32(ctx, 31, 0x134578u);
    ctx->pc = 0x134574u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134570u;
            // 0x134574: 0x26700018  addiu       $s0, $s3, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 19), 24));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D7A8u;
    if (runtime->hasFunction(0x12D7A8u)) {
        auto targetFn = runtime->lookupFunction(0x12D7A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134578u; }
        if (ctx->pc != 0x134578u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D7A8_0x12d7a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134578u; }
        if (ctx->pc != 0x134578u) { return; }
    }
    ctx->pc = 0x134578u;
label_134578:
    // 0x134578: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x134578u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13457c: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13457cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x134580: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x134580u;
    {
        const bool branch_taken_0x134580 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x134584u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134580u;
            // 0x134584: 0xac51b7a0  sw          $s1, -0x4860($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294948768), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
        if (branch_taken_0x134580) {
            ctx->pc = 0x13458Cu;
            goto label_13458c;
        }
    }
    ctx->pc = 0x134588u;
label_134588:
    // 0x134588: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x134588u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
label_13458c:
    // 0x13458c: 0x251102a  slt         $v0, $s2, $s1
    ctx->pc = 0x13458cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x134590: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x134590u;
    {
        const bool branch_taken_0x134590 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x134590) {
            ctx->pc = 0x1345BCu;
            goto label_1345bc;
        }
    }
    ctx->pc = 0x134598u;
    // 0x134598: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x134598u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13459c: 0x26100004  addiu       $s0, $s0, 0x4
    ctx->pc = 0x13459cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x1345a0: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x1345a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1345a4: 0x8c620024  lw          $v0, 0x24($v1)
    ctx->pc = 0x1345a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x1345a8: 0x40f809  jalr        $v0
    ctx->pc = 0x1345A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1345B0u);
        ctx->pc = 0x1345ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1345A8u;
            // 0x1345ac: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1345B0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x134558u: goto label_134558;
            case 0x134578u: goto label_134578;
            case 0x134588u: goto label_134588;
            case 0x13458Cu: goto label_13458c;
            case 0x1345B0u: goto label_1345b0;
            case 0x1345BCu: goto label_1345bc;
            case 0x1345D0u: goto label_1345d0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1345B0u; }
            if (ctx->pc != 0x1345B0u) { return; }
        }
        }
    }
    ctx->pc = 0x1345B0u;
label_1345b0:
    // 0x1345b0: 0x28430040  slti        $v1, $v0, 0x40
    ctx->pc = 0x1345b0u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)64) ? 1 : 0);
    // 0x1345b4: 0x1460fff4  bnez        $v1, . + 4 + (-0xC << 2)
    ctx->pc = 0x1345B4u;
    {
        const bool branch_taken_0x1345b4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1345B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1345B4u;
            // 0x1345b8: 0xae82b7a4  sw          $v0, -0x485C($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 4294948772), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1345b4) {
            ctx->pc = 0x134588u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_134588;
        }
    }
    ctx->pc = 0x1345BCu;
label_1345bc:
    // 0x1345bc: 0x16510004  bne         $s2, $s1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1345BCu;
    {
        const bool branch_taken_0x1345bc = (GPR_U64(ctx, 18) != GPR_U64(ctx, 17));
        ctx->pc = 0x1345C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1345BCu;
            // 0x1345c0: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1345bc) {
            ctx->pc = 0x1345D0u;
            goto label_1345d0;
        }
    }
    ctx->pc = 0x1345C4u;
    // 0x1345c4: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1345c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1345c8: 0xae6000a8  sw          $zero, 0xA8($s3)
    ctx->pc = 0x1345c8u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 168), GPR_U32(ctx, 0));
    // 0x1345cc: 0xa2620001  sb          $v0, 0x1($s3)
    ctx->pc = 0x1345ccu;
    WRITE8(ADD32(GPR_U32(ctx, 19), 1), (uint8_t)GPR_U32(ctx, 2));
label_1345d0:
    // 0x1345d0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1345d0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1345d4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1345d4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1345d8: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1345d8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1345dc: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x1345dcu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1345e0: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1345e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1345e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1345E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1345E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1345E4u;
            // 0x1345e8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x134558u: goto label_134558;
            case 0x134578u: goto label_134578;
            case 0x134588u: goto label_134588;
            case 0x13458Cu: goto label_13458c;
            case 0x1345B0u: goto label_1345b0;
            case 0x1345BCu: goto label_1345bc;
            case 0x1345D0u: goto label_1345d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1345ECu;
    // 0x1345ec: 0x0  nop
    ctx->pc = 0x1345ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
