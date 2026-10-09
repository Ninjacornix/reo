#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B8FC0
// Address: 0x1b8fc0 - 0x1b9084
void sub_001B8FC0_0x1b8fc0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B8FC0_0x1b8fc0");
#endif

    switch (ctx->pc) {
        case 0x1b8fdcu: goto label_1b8fdc;
        case 0x1b9070u: goto label_1b9070;
        default: break;
    }

    ctx->pc = 0x1b8fc0u;

    // 0x1b8fc0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1b8fc0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1b8fc4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1b8fc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1b8fc8: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b8fc8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b8fcc: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1b8fccu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8fd0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b8fd0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b8fd4: 0xc06bb20  jal         func_1AEC80
    ctx->pc = 0x1B8FD4u;
    SET_GPR_U32(ctx, 31, 0x1B8FDCu);
    ctx->pc = 0x1B8FD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8FD4u;
            // 0x1b8fd8: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AEC80u;
    if (runtime->hasFunction(0x1AEC80u)) {
        auto targetFn = runtime->lookupFunction(0x1AEC80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8FDCu; }
        if (ctx->pc != 0x1B8FDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AEC80_0x1aec80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8FDCu; }
        if (ctx->pc != 0x1B8FDCu) { return; }
    }
    ctx->pc = 0x1B8FDCu;
label_1b8fdc:
    // 0x1b8fdc: 0x3043ffff  andi        $v1, $v0, 0xFFFF
    ctx->pc = 0x1b8fdcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1b8fe0: 0x92220b98  lbu         $v0, 0xB98($s1)
    ctx->pc = 0x1b8fe0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 2968)));
    // 0x1b8fe4: 0x2c410008  sltiu       $at, $v0, 0x8
    ctx->pc = 0x1b8fe4u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)8) ? 1 : 0);
    // 0x1b8fe8: 0x10200013  beqz        $at, . + 4 + (0x13 << 2)
    ctx->pc = 0x1B8FE8u;
    {
        const bool branch_taken_0x1b8fe8 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B8FECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8FE8u;
            // 0x1b8fec: 0x30640001  andi        $a0, $v1, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b8fe8) {
            ctx->pc = 0x1B9038u;
            goto label_1b9038;
        }
    }
    ctx->pc = 0x1B8FF0u;
    // 0x1b8ff0: 0x3c030025  lui         $v1, 0x25
    ctx->pc = 0x1b8ff0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)37 << 16));
    // 0x1b8ff4: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1b8ff4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1b8ff8: 0x24630190  addiu       $v1, $v1, 0x190
    ctx->pc = 0x1b8ff8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 400));
    // 0x1b8ffc: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1b8ffcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b9000: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1b9000u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1b9004: 0x400008  jr          $v0
    ctx->pc = 0x1B9004u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B900Cu: goto label_1b900c;
            case 0x1B901Cu: goto label_1b901c;
            case 0x1B902Cu: goto label_1b902c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B900Cu;
label_1b900c:
    // 0x1b900c: 0x3082ffff  andi        $v0, $a0, 0xFFFF
    ctx->pc = 0x1b900cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
    // 0x1b9010: 0x2442000a  addiu       $v0, $v0, 0xA
    ctx->pc = 0x1b9010u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 10));
    // 0x1b9014: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1B9014u;
    {
        const bool branch_taken_0x1b9014 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B9018u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9014u;
            // 0x1b9018: 0x3050ffff  andi        $s0, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9014) {
            ctx->pc = 0x1B9038u;
            goto label_1b9038;
        }
    }
    ctx->pc = 0x1B901Cu;
label_1b901c:
    // 0x1b901c: 0x3082ffff  andi        $v0, $a0, 0xFFFF
    ctx->pc = 0x1b901cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
    // 0x1b9020: 0x2442000c  addiu       $v0, $v0, 0xC
    ctx->pc = 0x1b9020u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
    // 0x1b9024: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1B9024u;
    {
        const bool branch_taken_0x1b9024 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B9028u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9024u;
            // 0x1b9028: 0x3050ffff  andi        $s0, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9024) {
            ctx->pc = 0x1B9038u;
            goto label_1b9038;
        }
    }
    ctx->pc = 0x1B902Cu;
label_1b902c:
    // 0x1b902c: 0x3082ffff  andi        $v0, $a0, 0xFFFF
    ctx->pc = 0x1b902cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
    // 0x1b9030: 0x2442000e  addiu       $v0, $v0, 0xE
    ctx->pc = 0x1b9030u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 14));
    // 0x1b9034: 0x3050ffff  andi        $s0, $v0, 0xFFFF
    ctx->pc = 0x1b9034u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
label_1b9038:
    // 0x1b9038: 0xc6220038  lwc1        $f2, 0x38($s1)
    ctx->pc = 0x1b9038u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 56)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1b903c: 0x27a70030  addiu       $a3, $sp, 0x30
    ctx->pc = 0x1b903cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1b9040: 0xc621003c  lwc1        $f1, 0x3C($s1)
    ctx->pc = 0x1b9040u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 60)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1b9044: 0x3205ffff  andi        $a1, $s0, 0xFFFF
    ctx->pc = 0x1b9044u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)65535);
    // 0x1b9048: 0xc6200040  lwc1        $f0, 0x40($s1)
    ctx->pc = 0x1b9048u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 64)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1b904c: 0x2404000c  addiu       $a0, $zero, 0xC
    ctx->pc = 0x1b904cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x1b9050: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x1b9050u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b9054: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1b9054u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9058: 0xe4e20000  swc1        $f2, 0x0($a3)
    ctx->pc = 0x1b9058u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 7), 0), bits); }
    // 0x1b905c: 0xe4e10004  swc1        $f1, 0x4($a3)
    ctx->pc = 0x1b905cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 7), 4), bits); }
    // 0x1b9060: 0xe4e00008  swc1        $f0, 0x8($a3)
    ctx->pc = 0x1b9060u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 7), 8), bits); }
    // 0x1b9064: 0x92260003  lbu         $a2, 0x3($s1)
    ctx->pc = 0x1b9064u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 3)));
    // 0x1b9068: 0xc06e4f4  jal         func_1B93D0
    ctx->pc = 0x1B9068u;
    SET_GPR_U32(ctx, 31, 0x1B9070u);
    ctx->pc = 0x1B906Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9068u;
            // 0x1b906c: 0x502d  daddu       $t2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93D0u;
    if (runtime->hasFunction(0x1B93D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9070u; }
        if (ctx->pc != 0x1B9070u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B93D0_0x1b93d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9070u; }
        if (ctx->pc != 0x1B9070u) { return; }
    }
    ctx->pc = 0x1B9070u;
label_1b9070:
    // 0x1b9070: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1b9070u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b9074: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b9074u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b9078: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b9078u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b907c: 0x3e00008  jr          $ra
    ctx->pc = 0x1B907Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B9080u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B907Cu;
            // 0x1b9080: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B8FDCu: goto label_1b8fdc;
            case 0x1B900Cu: goto label_1b900c;
            case 0x1B901Cu: goto label_1b901c;
            case 0x1B902Cu: goto label_1b902c;
            case 0x1B9038u: goto label_1b9038;
            case 0x1B9070u: goto label_1b9070;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B9084u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
