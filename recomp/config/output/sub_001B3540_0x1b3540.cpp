#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B3540
// Address: 0x1b3540 - 0x1b35ac
void sub_001B3540_0x1b3540(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B3540_0x1b3540");
#endif

    switch (ctx->pc) {
        case 0x1b3568u: goto label_1b3568;
        case 0x1b3584u: goto label_1b3584;
        default: break;
    }

    ctx->pc = 0x1b3540u;

    // 0x1b3540: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1b3540u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1b3544: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1b3544u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1b3548: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1b3548u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1b354c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b354cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b3550: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b3550u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b3554: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1b3554u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b3558: 0x8c830034  lw          $v1, 0x34($a0)
    ctx->pc = 0x1b3558u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 52)));
    // 0x1b355c: 0x94720816  lhu         $s2, 0x816($v1)
    ctx->pc = 0x1b355cu;
    SET_GPR_U32(ctx, 18, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 2070)));
    // 0x1b3560: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1B3560u;
    {
        const bool branch_taken_0x1b3560 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B3564u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3560u;
            // 0x1b3564: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b3560) {
            ctx->pc = 0x1B3588u;
            goto label_1b3588;
        }
    }
    ctx->pc = 0x1B3568u;
label_1b3568:
    // 0x1b3568: 0x8e230034  lw          $v1, 0x34($s1)
    ctx->pc = 0x1b3568u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 52)));
    // 0x1b356c: 0x3c0241a0  lui         $v0, 0x41A0
    ctx->pc = 0x1b356cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16800 << 16));
    // 0x1b3570: 0x44826000  mtc1        $v0, $f12
    ctx->pc = 0x1b3570u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[12], &bits, sizeof(bits)); }
    // 0x1b3574: 0x102080  sll         $a0, $s0, 2
    ctx->pc = 0x1b3574u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1b3578: 0x641021  addu        $v0, $v1, $a0
    ctx->pc = 0x1b3578u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1b357c: 0xc06ccec  jal         func_1B33B0
    ctx->pc = 0x1B357Cu;
    SET_GPR_U32(ctx, 31, 0x1B3584u);
    ctx->pc = 0x1B3580u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B357Cu;
            // 0x1b3580: 0x8c440820  lw          $a0, 0x820($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 2080)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B33B0u;
    if (runtime->hasFunction(0x1B33B0u)) {
        auto targetFn = runtime->lookupFunction(0x1B33B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B3584u; }
        if (ctx->pc != 0x1B3584u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B33B0_0x1b33b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B3584u; }
        if (ctx->pc != 0x1B3584u) { return; }
    }
    ctx->pc = 0x1B3584u;
label_1b3584:
    // 0x1b3584: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1b3584u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
label_1b3588:
    // 0x1b3588: 0x212182b  sltu        $v1, $s0, $s2
    ctx->pc = 0x1b3588u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)GPR_U64(ctx, 18)) ? 1 : 0);
    // 0x1b358c: 0x1460fff6  bnez        $v1, . + 4 + (-0xA << 2)
    ctx->pc = 0x1B358Cu;
    {
        const bool branch_taken_0x1b358c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b358c) {
            ctx->pc = 0x1B3568u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b3568;
        }
    }
    ctx->pc = 0x1B3594u;
    // 0x1b3594: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1b3594u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1b3598: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1b3598u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b359c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b359cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b35a0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b35a0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b35a4: 0x3e00008  jr          $ra
    ctx->pc = 0x1B35A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B35A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B35A4u;
            // 0x1b35a8: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B3568u: goto label_1b3568;
            case 0x1B3584u: goto label_1b3584;
            case 0x1B3588u: goto label_1b3588;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B35ACu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
