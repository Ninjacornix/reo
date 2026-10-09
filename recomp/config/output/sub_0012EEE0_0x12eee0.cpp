#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012EEE0
// Address: 0x12eee0 - 0x12ef90
void sub_0012EEE0_0x12eee0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012EEE0_0x12eee0");
#endif

    switch (ctx->pc) {
        case 0x12ef08u: goto label_12ef08;
        case 0x12ef1cu: goto label_12ef1c;
        case 0x12ef4cu: goto label_12ef4c;
        case 0x12ef5cu: goto label_12ef5c;
        default: break;
    }

    ctx->pc = 0x12eee0u;

    // 0x12eee0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x12eee0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x12eee4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12eee4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12eee8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x12eee8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12eeec: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x12eeecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x12eef0: 0x24120012  addiu       $s2, $zero, 0x12
    ctx->pc = 0x12eef0u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x12eef4: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x12eef4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x12eef8: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x12eef8u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12eefc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12eefcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12ef00: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x12ef00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x12ef04: 0x8e11000c  lw          $s1, 0xC($s0)
    ctx->pc = 0x12ef04u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
label_12ef08:
    // 0x12ef08: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x12ef08u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x12ef0c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x12ef0cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ef10: 0x8c620024  lw          $v0, 0x24($v1)
    ctx->pc = 0x12ef10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x12ef14: 0x40f809  jalr        $v0
    ctx->pc = 0x12EF14u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12EF1Cu);
        ctx->pc = 0x12EF18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12EF14u;
            // 0x12ef18: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12EF1Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12EF08u: goto label_12ef08;
            case 0x12EF1Cu: goto label_12ef1c;
            case 0x12EF2Cu: goto label_12ef2c;
            case 0x12EF4Cu: goto label_12ef4c;
            case 0x12EF5Cu: goto label_12ef5c;
            case 0x12EF74u: goto label_12ef74;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12EF1Cu; }
            if (ctx->pc != 0x12EF1Cu) { return; }
        }
        }
    }
    ctx->pc = 0x12EF1Cu;
label_12ef1c:
    // 0x12ef1c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x12ef1cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ef20: 0x52001a  div         $zero, $v0, $s2
    ctx->pc = 0x12ef20u;
    { int32_t divisor = GPR_S32(ctx, 18);    int32_t dividend = GPR_S32(ctx, 2);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x12ef24: 0x52400001  beql        $s2, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x12EF24u;
    {
        const bool branch_taken_0x12ef24 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        if (branch_taken_0x12ef24) {
            ctx->pc = 0x12EF28u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12EF24u;
            // 0x12ef28: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x12EF2Cu;
            goto label_12ef2c;
        }
    }
    ctx->pc = 0x12EF2Cu;
label_12ef2c:
    // 0x12ef2c: 0x8e030058  lw          $v1, 0x58($s0)
    ctx->pc = 0x12ef2cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 88)));
    // 0x12ef30: 0x1012  mflo        $v0
    ctx->pc = 0x12ef30u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x12ef34: 0x43001a  div         $zero, $v0, $v1
    ctx->pc = 0x12ef34u;
    { int32_t divisor = GPR_S32(ctx, 3);    int32_t dividend = GPR_S32(ctx, 2);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x12ef38: 0x1012  mflo        $v0
    ctx->pc = 0x12ef38u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x12ef3c: 0x1840000d  blez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x12EF3Cu;
    {
        const bool branch_taken_0x12ef3c = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x12EF40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12EF3Cu;
            // 0x12ef40: 0x260102d  daddu       $v0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ef3c) {
            ctx->pc = 0x12EF74u;
            goto label_12ef74;
        }
    }
    ctx->pc = 0x12EF44u;
    // 0x12ef44: 0xc04bafc  jal         func_12EBF0
    ctx->pc = 0x12EF44u;
    SET_GPR_U32(ctx, 31, 0x12EF4Cu);
    ctx->pc = 0x12EBF0u;
    if (runtime->hasFunction(0x12EBF0u)) {
        auto targetFn = runtime->lookupFunction(0x12EBF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12EF4Cu; }
        if (ctx->pc != 0x12EF4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012EBF0_0x12ebf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12EF4Cu; }
        if (ctx->pc != 0x12EF4Cu) { return; }
    }
    ctx->pc = 0x12EF4Cu;
label_12ef4c:
    // 0x12ef4c: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x12EF4Cu;
    {
        const bool branch_taken_0x12ef4c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x12EF50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12EF4Cu;
            // 0x12ef50: 0x260102d  daddu       $v0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ef4c) {
            ctx->pc = 0x12EF74u;
            goto label_12ef74;
        }
    }
    ctx->pc = 0x12EF54u;
    // 0x12ef54: 0xc04bb6c  jal         func_12EDB0
    ctx->pc = 0x12EF54u;
    SET_GPR_U32(ctx, 31, 0x12EF5Cu);
    ctx->pc = 0x12EF58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12EF54u;
            // 0x12ef58: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12EDB0u;
    if (runtime->hasFunction(0x12EDB0u)) {
        auto targetFn = runtime->lookupFunction(0x12EDB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12EF5Cu; }
        if (ctx->pc != 0x12EF5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012EDB0_0x12edb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12EF5Cu; }
        if (ctx->pc != 0x12EF5Cu) { return; }
    }
    ctx->pc = 0x12EF5Cu;
label_12ef5c:
    // 0x12ef5c: 0x8e030030  lw          $v1, 0x30($s0)
    ctx->pc = 0x12ef5cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 48)));
    // 0x12ef60: 0x8e04003c  lw          $a0, 0x3C($s0)
    ctx->pc = 0x12ef60u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 60)));
    // 0x12ef64: 0x64182a  slt         $v1, $v1, $a0
    ctx->pc = 0x12ef64u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x12ef68: 0x1460ffe7  bnez        $v1, . + 4 + (-0x19 << 2)
    ctx->pc = 0x12EF68u;
    {
        const bool branch_taken_0x12ef68 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x12EF6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12EF68u;
            // 0x12ef6c: 0x2629821  addu        $s3, $s3, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ef68) {
            ctx->pc = 0x12EF08u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12ef08;
        }
    }
    ctx->pc = 0x12EF70u;
    // 0x12ef70: 0x260102d  daddu       $v0, $s3, $zero
    ctx->pc = 0x12ef70u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
label_12ef74:
    // 0x12ef74: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12ef74u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12ef78: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12ef78u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12ef7c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x12ef7cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12ef80: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x12ef80u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12ef84: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x12ef84u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12ef88: 0x3e00008  jr          $ra
    ctx->pc = 0x12EF88u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12EF8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12EF88u;
            // 0x12ef8c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12EF08u: goto label_12ef08;
            case 0x12EF1Cu: goto label_12ef1c;
            case 0x12EF2Cu: goto label_12ef2c;
            case 0x12EF4Cu: goto label_12ef4c;
            case 0x12EF5Cu: goto label_12ef5c;
            case 0x12EF74u: goto label_12ef74;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12EF90u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
