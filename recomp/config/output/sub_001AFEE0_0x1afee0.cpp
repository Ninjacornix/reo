#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AFEE0
// Address: 0x1afee0 - 0x1aff5c
void sub_001AFEE0_0x1afee0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AFEE0_0x1afee0");
#endif

    switch (ctx->pc) {
        case 0x1afef4u: goto label_1afef4;
        case 0x1aff2cu: goto label_1aff2c;
        case 0x1aff3cu: goto label_1aff3c;
        default: break;
    }

    ctx->pc = 0x1afee0u;

    // 0x1afee0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1afee0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1afee4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1afee4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1afee8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1afee8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1afeec: 0xc06c0c0  jal         func_1B0300
    ctx->pc = 0x1AFEECu;
    SET_GPR_U32(ctx, 31, 0x1AFEF4u);
    ctx->pc = 0x1AFEF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFEECu;
            // 0x1afef0: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B0300u;
    if (runtime->hasFunction(0x1B0300u)) {
        auto targetFn = runtime->lookupFunction(0x1B0300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFEF4u; }
        if (ctx->pc != 0x1AFEF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0300_0x1b0300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFEF4u; }
        if (ctx->pc != 0x1AFEF4u) { return; }
    }
    ctx->pc = 0x1AFEF4u;
label_1afef4:
    // 0x1afef4: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1afef4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1afef8: 0x10430012  beq         $v0, $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x1AFEF8u;
    {
        const bool branch_taken_0x1afef8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1AFEFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFEF8u;
            // 0x1afefc: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afef8) {
            ctx->pc = 0x1AFF44u;
            goto label_1aff44;
        }
    }
    ctx->pc = 0x1AFF00u;
    // 0x1aff00: 0x10430010  beq         $v0, $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1AFF00u;
    {
        const bool branch_taken_0x1aff00 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1aff00) {
            ctx->pc = 0x1AFF44u;
            goto label_1aff44;
        }
    }
    ctx->pc = 0x1AFF08u;
    // 0x1aff08: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1aff08u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1aff0c: 0x10430009  beq         $v0, $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1AFF0Cu;
    {
        const bool branch_taken_0x1aff0c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1AFF10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFF0Cu;
            // 0x1aff10: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aff0c) {
            ctx->pc = 0x1AFF34u;
            goto label_1aff34;
        }
    }
    ctx->pc = 0x1AFF14u;
    // 0x1aff14: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AFF14u;
    {
        const bool branch_taken_0x1aff14 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AFF18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFF14u;
            // 0x1aff18: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aff14) {
            ctx->pc = 0x1AFF24u;
            goto label_1aff24;
        }
    }
    ctx->pc = 0x1AFF1Cu;
    // 0x1aff1c: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1AFF1Cu;
    {
        const bool branch_taken_0x1aff1c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AFF20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFF1Cu;
            // 0x1aff20: 0x2001026  xor         $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) ^ GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aff1c) {
            ctx->pc = 0x1AFF48u;
            goto label_1aff48;
        }
    }
    ctx->pc = 0x1AFF24u;
label_1aff24:
    // 0x1aff24: 0xc204748  jal         func_811D20
    ctx->pc = 0x1AFF24u;
    SET_GPR_U32(ctx, 31, 0x1AFF2Cu);
    ctx->pc = 0x811D20u;
    {
        auto targetFn = runtime->lookupFunction(0x811D20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFF2Cu; }
        if (ctx->pc != 0x1AFF2Cu) { return; }
    }
    ctx->pc = 0x1AFF2Cu;
label_1aff2c:
    // 0x1aff2c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1AFF2Cu;
    {
        const bool branch_taken_0x1aff2c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AFF30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFF2Cu;
            // 0x1aff30: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aff2c) {
            ctx->pc = 0x1AFF50u;
            goto label_1aff50;
        }
    }
    ctx->pc = 0x1AFF34u;
label_1aff34:
    // 0x1aff34: 0xc204574  jal         func_8115D0
    ctx->pc = 0x1AFF34u;
    SET_GPR_U32(ctx, 31, 0x1AFF3Cu);
    ctx->pc = 0x8115D0u;
    {
        auto targetFn = runtime->lookupFunction(0x8115D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFF3Cu; }
        if (ctx->pc != 0x1AFF3Cu) { return; }
    }
    ctx->pc = 0x1AFF3Cu;
label_1aff3c:
    // 0x1aff3c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1AFF3Cu;
    {
        const bool branch_taken_0x1aff3c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1aff3c) {
            ctx->pc = 0x1AFF4Cu;
            goto label_1aff4c;
        }
    }
    ctx->pc = 0x1AFF44u;
label_1aff44:
    // 0x1aff44: 0x2001026  xor         $v0, $s0, $zero
    ctx->pc = 0x1aff44u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) ^ GPR_U64(ctx, 0));
label_1aff48:
    // 0x1aff48: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x1aff48u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
label_1aff4c:
    // 0x1aff4c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1aff4cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1aff50:
    // 0x1aff50: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1aff50u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1aff54: 0x3e00008  jr          $ra
    ctx->pc = 0x1AFF54u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AFF58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFF54u;
            // 0x1aff58: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AFEF4u: goto label_1afef4;
            case 0x1AFF24u: goto label_1aff24;
            case 0x1AFF2Cu: goto label_1aff2c;
            case 0x1AFF34u: goto label_1aff34;
            case 0x1AFF3Cu: goto label_1aff3c;
            case 0x1AFF44u: goto label_1aff44;
            case 0x1AFF48u: goto label_1aff48;
            case 0x1AFF4Cu: goto label_1aff4c;
            case 0x1AFF50u: goto label_1aff50;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AFF5Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
