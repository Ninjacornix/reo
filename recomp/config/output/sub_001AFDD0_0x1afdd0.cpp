#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AFDD0
// Address: 0x1afdd0 - 0x1afe70
void sub_001AFDD0_0x1afdd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AFDD0_0x1afdd0");
#endif

    switch (ctx->pc) {
        case 0x1afdfcu: goto label_1afdfc;
        case 0x1afe3cu: goto label_1afe3c;
        case 0x1afe54u: goto label_1afe54;
        default: break;
    }

    ctx->pc = 0x1afdd0u;

    // 0x1afdd0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1afdd0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1afdd4: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1afdd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1afdd8: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1afdd8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1afddc: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1afddcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1afde0: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x1afde0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1afde4: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1afde4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1afde8: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1afde8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1afdec: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1afdecu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1afdf0: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x1afdf0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1afdf4: 0xc06c0c0  jal         func_1B0300
    ctx->pc = 0x1AFDF4u;
    SET_GPR_U32(ctx, 31, 0x1AFDFCu);
    ctx->pc = 0x1AFDF8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFDF4u;
            // 0x1afdf8: 0xe0802d  daddu       $s0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B0300u;
    if (runtime->hasFunction(0x1B0300u)) {
        auto targetFn = runtime->lookupFunction(0x1B0300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFDFCu; }
        if (ctx->pc != 0x1AFDFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0300_0x1b0300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFDFCu; }
        if (ctx->pc != 0x1AFDFCu) { return; }
    }
    ctx->pc = 0x1AFDFCu;
label_1afdfc:
    // 0x1afdfc: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1afdfcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1afe00: 0x10430014  beq         $v0, $v1, . + 4 + (0x14 << 2)
    ctx->pc = 0x1AFE00u;
    {
        const bool branch_taken_0x1afe00 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1AFE04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFE00u;
            // 0x1afe04: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afe00) {
            ctx->pc = 0x1AFE54u;
            goto label_1afe54;
        }
    }
    ctx->pc = 0x1AFE08u;
    // 0x1afe08: 0x10430012  beq         $v0, $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x1AFE08u;
    {
        const bool branch_taken_0x1afe08 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1afe08) {
            ctx->pc = 0x1AFE54u;
            goto label_1afe54;
        }
    }
    ctx->pc = 0x1AFE10u;
    // 0x1afe10: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1afe10u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1afe14: 0x1043000b  beq         $v0, $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x1AFE14u;
    {
        const bool branch_taken_0x1afe14 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1AFE18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFE14u;
            // 0x1afe18: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afe14) {
            ctx->pc = 0x1AFE44u;
            goto label_1afe44;
        }
    }
    ctx->pc = 0x1AFE1Cu;
    // 0x1afe1c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AFE1Cu;
    {
        const bool branch_taken_0x1afe1c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AFE20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFE1Cu;
            // 0x1afe20: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afe1c) {
            ctx->pc = 0x1AFE2Cu;
            goto label_1afe2c;
        }
    }
    ctx->pc = 0x1AFE24u;
    // 0x1afe24: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1AFE24u;
    {
        const bool branch_taken_0x1afe24 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AFE28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFE24u;
            // 0x1afe28: 0xdfbf0040  ld          $ra, 0x40($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afe24) {
            ctx->pc = 0x1AFE58u;
            goto label_1afe58;
        }
    }
    ctx->pc = 0x1AFE2Cu;
label_1afe2c:
    // 0x1afe2c: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1afe2cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1afe30: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x1afe30u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1afe34: 0xc204464  jal         func_811190
    ctx->pc = 0x1AFE34u;
    SET_GPR_U32(ctx, 31, 0x1AFE3Cu);
    ctx->pc = 0x1AFE38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFE34u;
            // 0x1afe38: 0x200382d  daddu       $a3, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x811190u;
    {
        auto targetFn = runtime->lookupFunction(0x811190u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFE3Cu; }
        if (ctx->pc != 0x1AFE3Cu) { return; }
    }
    ctx->pc = 0x1AFE3Cu;
label_1afe3c:
    // 0x1afe3c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1AFE3Cu;
    {
        const bool branch_taken_0x1afe3c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1afe3c) {
            ctx->pc = 0x1AFE54u;
            goto label_1afe54;
        }
    }
    ctx->pc = 0x1AFE44u;
label_1afe44:
    // 0x1afe44: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1afe44u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1afe48: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x1afe48u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1afe4c: 0xc20421c  jal         func_810870
    ctx->pc = 0x1AFE4Cu;
    SET_GPR_U32(ctx, 31, 0x1AFE54u);
    ctx->pc = 0x1AFE50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFE4Cu;
            // 0x1afe50: 0x200382d  daddu       $a3, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x810870u;
    {
        auto targetFn = runtime->lookupFunction(0x810870u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFE54u; }
        if (ctx->pc != 0x1AFE54u) { return; }
    }
    ctx->pc = 0x1AFE54u;
label_1afe54:
    // 0x1afe54: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1afe54u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
label_1afe58:
    // 0x1afe58: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1afe58u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1afe5c: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1afe5cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1afe60: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1afe60u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1afe64: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1afe64u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1afe68: 0x3e00008  jr          $ra
    ctx->pc = 0x1AFE68u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AFE6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFE68u;
            // 0x1afe6c: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AFDFCu: goto label_1afdfc;
            case 0x1AFE2Cu: goto label_1afe2c;
            case 0x1AFE3Cu: goto label_1afe3c;
            case 0x1AFE44u: goto label_1afe44;
            case 0x1AFE54u: goto label_1afe54;
            case 0x1AFE58u: goto label_1afe58;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AFE70u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
