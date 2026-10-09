#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A7FB0
// Address: 0x1a7fb0 - 0x1a8060
void sub_001A7FB0_0x1a7fb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A7FB0_0x1a7fb0");
#endif

    switch (ctx->pc) {
        case 0x1a7fd4u: goto label_1a7fd4;
        case 0x1a8018u: goto label_1a8018;
        case 0x1a8028u: goto label_1a8028;
        case 0x1a8034u: goto label_1a8034;
        default: break;
    }

    ctx->pc = 0x1a7fb0u;

    // 0x1a7fb0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1a7fb0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1a7fb4: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1a7fb4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1a7fb8: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1a7fb8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1a7fbc: 0x7fb10020  sq          $s1, 0x20($sp)
    ctx->pc = 0x1a7fbcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 17));
    // 0x1a7fc0: 0x7fb00010  sq          $s0, 0x10($sp)
    ctx->pc = 0x1a7fc0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 16));
    // 0x1a7fc4: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1a7fc4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a7fc8: 0x8c241188  lw          $a0, 0x1188($at)
    ctx->pc = 0x1a7fc8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4488)));
    // 0x1a7fcc: 0xc045198  jal         func_114660
    ctx->pc = 0x1A7FCCu;
    SET_GPR_U32(ctx, 31, 0x1A7FD4u);
    ctx->pc = 0x1A7FD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7FCCu;
            // 0x1a7fd0: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7FD4u; }
        if (ctx->pc != 0x1A7FD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7FD4u; }
        if (ctx->pc != 0x1A7FD4u) { return; }
    }
    ctx->pc = 0x1A7FD4u;
label_1a7fd4:
    // 0x1a7fd4: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a7fd4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a7fd8: 0x3c07002b  lui         $a3, 0x2B
    ctx->pc = 0x1a7fd8u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)43 << 16));
    // 0x1a7fdc: 0xac300c80  sw          $s0, 0xC80($at)
    ctx->pc = 0x1a7fdcu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 3200), GPR_U32(ctx, 16));
    // 0x1a7fe0: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a7fe0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a7fe4: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1a7fe4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1a7fe8: 0x24e70c80  addiu       $a3, $a3, 0xC80
    ctx->pc = 0x1a7fe8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 3200));
    // 0x1a7fec: 0x8c221188  lw          $v0, 0x1188($at)
    ctx->pc = 0x1a7fecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4488)));
    // 0x1a7ff0: 0x24080010  addiu       $t0, $zero, 0x10
    ctx->pc = 0x1a7ff0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1a7ff4: 0x3c0b001a  lui         $t3, 0x1A
    ctx->pc = 0x1a7ff4u;
    SET_GPR_S32(ctx, 11, (int32_t)((uint32_t)26 << 16));
    // 0x1a7ff8: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1a7ff8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a7ffc: 0x24840c00  addiu       $a0, $a0, 0xC00
    ctx->pc = 0x1a7ffcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 3072));
    // 0x1a8000: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1a8000u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a8004: 0xe0482d  daddu       $t1, $a3, $zero
    ctx->pc = 0x1a8004u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a8008: 0x100502d  daddu       $t2, $t0, $zero
    ctx->pc = 0x1a8008u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a800c: 0x256b7fa0  addiu       $t3, $t3, 0x7FA0
    ctx->pc = 0x1a800cu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 32672));
    // 0x1a8010: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x1A8010u;
    SET_GPR_U32(ctx, 31, 0x1A8018u);
    ctx->pc = 0x1A8014u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8010u;
            // 0x1a8014: 0xffa20000  sd          $v0, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8018u; }
        if (ctx->pc != 0x1A8018u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8018u; }
        if (ctx->pc != 0x1A8018u) { return; }
    }
    ctx->pc = 0x1A8018u;
label_1a8018:
    // 0x1a8018: 0x4410008  bgez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1A8018u;
    {
        const bool branch_taken_0x1a8018 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1A801Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8018u;
            // 0x1a801c: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a8018) {
            ctx->pc = 0x1A803Cu;
            goto label_1a803c;
        }
    }
    ctx->pc = 0x1A8020u;
    // 0x1a8020: 0xc0423b4  jal         func_108ED0
    ctx->pc = 0x1A8020u;
    SET_GPR_U32(ctx, 31, 0x1A8028u);
    ctx->pc = 0x1A8024u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8020u;
            // 0x1a8024: 0x24842480  addiu       $a0, $a0, 0x2480 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 9344));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108ED0u;
    if (runtime->hasFunction(0x108ED0u)) {
        auto targetFn = runtime->lookupFunction(0x108ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8028u; }
        if (ctx->pc != 0x1A8028u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108ED0_0x108ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8028u; }
        if (ctx->pc != 0x1A8028u) { return; }
    }
    ctx->pc = 0x1A8028u;
label_1a8028:
    // 0x1a8028: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1a8028u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1a802c: 0xc045190  jal         func_114640
    ctx->pc = 0x1A802Cu;
    SET_GPR_U32(ctx, 31, 0x1A8034u);
    ctx->pc = 0x1A8030u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A802Cu;
            // 0x1a8030: 0x8c241188  lw          $a0, 0x1188($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4488)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8034u; }
        if (ctx->pc != 0x1A8034u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8034u; }
        if (ctx->pc != 0x1A8034u) { return; }
    }
    ctx->pc = 0x1A8034u;
label_1a8034:
    // 0x1a8034: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1A8034u;
    {
        const bool branch_taken_0x1a8034 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A8038u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8034u;
            // 0x1a8038: 0x2402fff7  addiu       $v0, $zero, -0x9 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967287));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a8034) {
            ctx->pc = 0x1A8040u;
            goto label_1a8040;
        }
    }
    ctx->pc = 0x1A803Cu;
label_1a803c:
    // 0x1a803c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1a803cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1a8040:
    // 0x1a8040: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1a8040u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1a8044: 0x7bb10020  lq          $s1, 0x20($sp)
    ctx->pc = 0x1a8044u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1a8048: 0x7bb00010  lq          $s0, 0x10($sp)
    ctx->pc = 0x1a8048u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a804c: 0x3e00008  jr          $ra
    ctx->pc = 0x1A804Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A8050u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A804Cu;
            // 0x1a8050: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A7FD4u: goto label_1a7fd4;
            case 0x1A8018u: goto label_1a8018;
            case 0x1A8028u: goto label_1a8028;
            case 0x1A8034u: goto label_1a8034;
            case 0x1A803Cu: goto label_1a803c;
            case 0x1A8040u: goto label_1a8040;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A8054u;
    // 0x1a8054: 0x0  nop
    ctx->pc = 0x1a8054u;
    // NOP
    // 0x1a8058: 0x0  nop
    ctx->pc = 0x1a8058u;
    // NOP
    // 0x1a805c: 0x0  nop
    ctx->pc = 0x1a805cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
