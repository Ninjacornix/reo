#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CCAD0
// Address: 0x1ccad0 - 0x1ccb30
void sub_001CCAD0_0x1ccad0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CCAD0_0x1ccad0");
#endif

    switch (ctx->pc) {
        case 0x1ccb08u: goto label_1ccb08;
        case 0x1ccb18u: goto label_1ccb18;
        default: break;
    }

    ctx->pc = 0x1ccad0u;

    // 0x1ccad0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1ccad0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1ccad4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1ccad4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1ccad8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1ccad8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1ccadc: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x1ccadcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ccae0: 0x1060000d  beqz        $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x1CCAE0u;
    {
        const bool branch_taken_0x1ccae0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CCAE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CCAE0u;
            // 0x1ccae4: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ccae0) {
            ctx->pc = 0x1CCB18u;
            goto label_1ccb18;
        }
    }
    ctx->pc = 0x1CCAE8u;
    // 0x1ccae8: 0x8603000e  lh          $v1, 0xE($s0)
    ctx->pc = 0x1ccae8u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 14)));
    // 0x1ccaec: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1ccaecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1ccaf0: 0xa603000e  sh          $v1, 0xE($s0)
    ctx->pc = 0x1ccaf0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 14), (uint16_t)GPR_U32(ctx, 3));
    // 0x1ccaf4: 0x8603000e  lh          $v1, 0xE($s0)
    ctx->pc = 0x1ccaf4u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 14)));
    // 0x1ccaf8: 0x1c600007  bgtz        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1CCAF8u;
    {
        const bool branch_taken_0x1ccaf8 = (GPR_S64(ctx, 3) > 0);
        if (branch_taken_0x1ccaf8) {
            ctx->pc = 0x1CCB18u;
            goto label_1ccb18;
        }
    }
    ctx->pc = 0x1CCB00u;
    // 0x1ccb00: 0xc07328c  jal         func_1CCA30
    ctx->pc = 0x1CCB00u;
    SET_GPR_U32(ctx, 31, 0x1CCB08u);
    ctx->pc = 0x1CCB04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CCB00u;
            // 0x1ccb04: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CCA30u;
    if (runtime->hasFunction(0x1CCA30u)) {
        auto targetFn = runtime->lookupFunction(0x1CCA30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CCB08u; }
        if (ctx->pc != 0x1CCB08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CCA30_0x1cca30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CCB08u; }
        if (ctx->pc != 0x1CCB08u) { return; }
    }
    ctx->pc = 0x1CCB08u;
label_1ccb08:
    // 0x1ccb08: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1ccb08u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ccb0c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1ccb0cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ccb10: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1CCB10u;
    SET_GPR_U32(ctx, 31, 0x1CCB18u);
    ctx->pc = 0x1CCB14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CCB10u;
            // 0x1ccb14: 0x24060010  addiu       $a2, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CCB18u; }
        if (ctx->pc != 0x1CCB18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CCB18u; }
        if (ctx->pc != 0x1CCB18u) { return; }
    }
    ctx->pc = 0x1CCB18u;
label_1ccb18:
    // 0x1ccb18: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1ccb18u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ccb1c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ccb1cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ccb20: 0x3e00008  jr          $ra
    ctx->pc = 0x1CCB20u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CCB24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CCB20u;
            // 0x1ccb24: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CCB08u: goto label_1ccb08;
            case 0x1CCB18u: goto label_1ccb18;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CCB28u;
    // 0x1ccb28: 0x0  nop
    ctx->pc = 0x1ccb28u;
    // NOP
    // 0x1ccb2c: 0x0  nop
    ctx->pc = 0x1ccb2cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
