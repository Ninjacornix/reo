#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B0110
// Address: 0x1b0110 - 0x1b0188
void sub_001B0110_0x1b0110(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B0110_0x1b0110");
#endif

    switch (ctx->pc) {
        case 0x1b0124u: goto label_1b0124;
        case 0x1b015cu: goto label_1b015c;
        case 0x1b016cu: goto label_1b016c;
        default: break;
    }

    ctx->pc = 0x1b0110u;

    // 0x1b0110: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1b0110u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1b0114: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1b0114u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1b0118: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b0118u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b011c: 0xc06c0c0  jal         func_1B0300
    ctx->pc = 0x1B011Cu;
    SET_GPR_U32(ctx, 31, 0x1B0124u);
    ctx->pc = 0x1B0120u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B011Cu;
            // 0x1b0120: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B0300u;
    if (runtime->hasFunction(0x1B0300u)) {
        auto targetFn = runtime->lookupFunction(0x1B0300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0124u; }
        if (ctx->pc != 0x1B0124u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0300_0x1b0300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0124u; }
        if (ctx->pc != 0x1B0124u) { return; }
    }
    ctx->pc = 0x1B0124u;
label_1b0124:
    // 0x1b0124: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1b0124u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1b0128: 0x10430012  beq         $v0, $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x1B0128u;
    {
        const bool branch_taken_0x1b0128 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1B012Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0128u;
            // 0x1b012c: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0128) {
            ctx->pc = 0x1B0174u;
            goto label_1b0174;
        }
    }
    ctx->pc = 0x1B0130u;
    // 0x1b0130: 0x10430010  beq         $v0, $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1B0130u;
    {
        const bool branch_taken_0x1b0130 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1b0130) {
            ctx->pc = 0x1B0174u;
            goto label_1b0174;
        }
    }
    ctx->pc = 0x1B0138u;
    // 0x1b0138: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1b0138u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b013c: 0x10430009  beq         $v0, $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1B013Cu;
    {
        const bool branch_taken_0x1b013c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1B0140u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B013Cu;
            // 0x1b0140: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b013c) {
            ctx->pc = 0x1B0164u;
            goto label_1b0164;
        }
    }
    ctx->pc = 0x1B0144u;
    // 0x1b0144: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B0144u;
    {
        const bool branch_taken_0x1b0144 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B0148u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0144u;
            // 0x1b0148: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0144) {
            ctx->pc = 0x1B0154u;
            goto label_1b0154;
        }
    }
    ctx->pc = 0x1B014Cu;
    // 0x1b014c: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1B014Cu;
    {
        const bool branch_taken_0x1b014c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B0150u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B014Cu;
            // 0x1b0150: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b014c) {
            ctx->pc = 0x1B0178u;
            goto label_1b0178;
        }
    }
    ctx->pc = 0x1B0154u;
label_1b0154:
    // 0x1b0154: 0xc204714  jal         func_811C50
    ctx->pc = 0x1B0154u;
    SET_GPR_U32(ctx, 31, 0x1B015Cu);
    ctx->pc = 0x811C50u;
    {
        auto targetFn = runtime->lookupFunction(0x811C50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B015Cu; }
        if (ctx->pc != 0x1B015Cu) { return; }
    }
    ctx->pc = 0x1B015Cu;
label_1b015c:
    // 0x1b015c: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1B015Cu;
    {
        const bool branch_taken_0x1b015c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B0160u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B015Cu;
            // 0x1b0160: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b015c) {
            ctx->pc = 0x1B017Cu;
            goto label_1b017c;
        }
    }
    ctx->pc = 0x1B0164u;
label_1b0164:
    // 0x1b0164: 0xc20452c  jal         func_8114B0
    ctx->pc = 0x1B0164u;
    SET_GPR_U32(ctx, 31, 0x1B016Cu);
    ctx->pc = 0x8114B0u;
    {
        auto targetFn = runtime->lookupFunction(0x8114B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B016Cu; }
        if (ctx->pc != 0x1B016Cu) { return; }
    }
    ctx->pc = 0x1B016Cu;
label_1b016c:
    // 0x1b016c: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1B016Cu;
    {
        const bool branch_taken_0x1b016c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b016c) {
            ctx->pc = 0x1B0178u;
            goto label_1b0178;
        }
    }
    ctx->pc = 0x1B0174u;
label_1b0174:
    // 0x1b0174: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1b0174u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1b0178:
    // 0x1b0178: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1b0178u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1b017c:
    // 0x1b017c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b017cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b0180: 0x3e00008  jr          $ra
    ctx->pc = 0x1B0180u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B0184u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0180u;
            // 0x1b0184: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B0124u: goto label_1b0124;
            case 0x1B0154u: goto label_1b0154;
            case 0x1B015Cu: goto label_1b015c;
            case 0x1B0164u: goto label_1b0164;
            case 0x1B016Cu: goto label_1b016c;
            case 0x1B0174u: goto label_1b0174;
            case 0x1B0178u: goto label_1b0178;
            case 0x1B017Cu: goto label_1b017c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B0188u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
