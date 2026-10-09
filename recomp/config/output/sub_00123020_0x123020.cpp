#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00123020
// Address: 0x123020 - 0x1230b0
void sub_00123020_0x123020(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00123020_0x123020");
#endif

    switch (ctx->pc) {
        case 0x123054u: goto label_123054;
        case 0x1230a0u: goto label_1230a0;
        default: break;
    }

    ctx->pc = 0x123020u;

    // 0x123020: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x123020u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x123024: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x123024u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x123028: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x123028u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12302c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12302cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x123030: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x123030u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123034: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x123034u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x123038: 0x8e2200b0  lw          $v0, 0xB0($s1)
    ctx->pc = 0x123038u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 176)));
    // 0x12303c: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x12303Cu;
    {
        const bool branch_taken_0x12303c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x123040u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12303Cu;
            // 0x123040: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12303c) {
            ctx->pc = 0x123054u;
            goto label_123054;
        }
    }
    ctx->pc = 0x123044u;
    // 0x123044: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x123044u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x123048: 0x8c43b72c  lw          $v1, -0x48D4($v0)
    ctx->pc = 0x123048u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294948652)));
    // 0x12304c: 0x60f809  jalr        $v1
    ctx->pc = 0x12304Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x123054u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x123054u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123054u: goto label_123054;
            case 0x123068u: goto label_123068;
            case 0x1230A0u: goto label_1230a0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x123054u; }
            if (ctx->pc != 0x123054u) { return; }
        }
        }
    }
    ctx->pc = 0x123054u;
label_123054:
    // 0x123054: 0x24020060  addiu       $v0, $zero, 0x60
    ctx->pc = 0x123054u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 96));
    // 0x123058: 0xae3000b4  sw          $s0, 0xB4($s1)
    ctx->pc = 0x123058u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 180), GPR_U32(ctx, 16));
    // 0x12305c: 0x202001a  div         $zero, $s0, $v0
    ctx->pc = 0x12305cu;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 16);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x123060: 0x50400001  beql        $v0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x123060u;
    {
        const bool branch_taken_0x123060 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x123060) {
            ctx->pc = 0x123064u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x123060u;
            // 0x123064: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x123068u;
            goto label_123068;
        }
    }
    ctx->pc = 0x123068u;
label_123068:
    // 0x123068: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x123068u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12306c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x12306cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x123070: 0x1812  mflo        $v1
    ctx->pc = 0x123070u;
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0x123074: 0xae2300b8  sw          $v1, 0xB8($s1)
    ctx->pc = 0x123074u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 184), GPR_U32(ctx, 3));
    // 0x123078: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x123078u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12307c: 0x3e00008  jr          $ra
    ctx->pc = 0x12307Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x123080u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12307Cu;
            // 0x123080: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123054u: goto label_123054;
            case 0x123068u: goto label_123068;
            case 0x1230A0u: goto label_1230a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x123084u;
    // 0x123084: 0x0  nop
    ctx->pc = 0x123084u;
    // NOP
    // 0x123088: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x123088u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12308c: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12308cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x123090: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x123090u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x123094: 0x8c43b734  lw          $v1, -0x48CC($v0)
    ctx->pc = 0x123094u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294948660)));
    // 0x123098: 0x60f809  jalr        $v1
    ctx->pc = 0x123098u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x1230A0u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x1230A0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123054u: goto label_123054;
            case 0x123068u: goto label_123068;
            case 0x1230A0u: goto label_1230a0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1230A0u; }
            if (ctx->pc != 0x1230A0u) { return; }
        }
        }
    }
    ctx->pc = 0x1230A0u;
label_1230a0:
    // 0x1230a0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1230a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1230a4: 0x3e00008  jr          $ra
    ctx->pc = 0x1230A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1230A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1230A4u;
            // 0x1230a8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123054u: goto label_123054;
            case 0x123068u: goto label_123068;
            case 0x1230A0u: goto label_1230a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1230ACu;
    // 0x1230ac: 0x0  nop
    ctx->pc = 0x1230acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
