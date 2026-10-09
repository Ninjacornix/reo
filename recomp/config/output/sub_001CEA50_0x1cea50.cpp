#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CEA50
// Address: 0x1cea50 - 0x1ceab0
void sub_001CEA50_0x1cea50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CEA50_0x1cea50");
#endif

    switch (ctx->pc) {
        case 0x1cea6cu: goto label_1cea6c;
        case 0x1cea84u: goto label_1cea84;
        default: break;
    }

    ctx->pc = 0x1cea50u;

    // 0x1cea50: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1cea50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1cea54: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1cea54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1cea58: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1cea58u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1cea5c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1cea5cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1cea60: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1cea60u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cea64: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1CEA64u;
    {
        const bool branch_taken_0x1cea64 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CEA68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CEA64u;
            // 0x1cea68: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cea64) {
            ctx->pc = 0x1CEA8Cu;
            goto label_1cea8c;
        }
    }
    ctx->pc = 0x1CEA6Cu;
label_1cea6c:
    // 0x1cea6c: 0x86240000  lh          $a0, 0x0($s1)
    ctx->pc = 0x1cea6cu;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1cea70: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1cea70u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1cea74: 0x10830008  beq         $a0, $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1CEA74u;
    {
        const bool branch_taken_0x1cea74 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1CEA78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CEA74u;
            // 0x1cea78: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cea74) {
            ctx->pc = 0x1CEA98u;
            goto label_1cea98;
        }
    }
    ctx->pc = 0x1CEA7Cu;
    // 0x1cea7c: 0xc073420  jal         func_1CD080
    ctx->pc = 0x1CEA7Cu;
    SET_GPR_U32(ctx, 31, 0x1CEA84u);
    ctx->pc = 0x1CD080u;
    if (runtime->hasFunction(0x1CD080u)) {
        auto targetFn = runtime->lookupFunction(0x1CD080u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CEA84u; }
        if (ctx->pc != 0x1CEA84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD080_0x1cd080(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CEA84u; }
        if (ctx->pc != 0x1CEA84u) { return; }
    }
    ctx->pc = 0x1CEA84u;
label_1cea84:
    // 0x1cea84: 0x26310002  addiu       $s1, $s1, 0x2
    ctx->pc = 0x1cea84u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 2));
    // 0x1cea88: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1cea88u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
label_1cea8c:
    // 0x1cea8c: 0x2a030006  slti        $v1, $s0, 0x6
    ctx->pc = 0x1cea8cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)6) ? 1 : 0);
    // 0x1cea90: 0x1460fff6  bnez        $v1, . + 4 + (-0xA << 2)
    ctx->pc = 0x1CEA90u;
    {
        const bool branch_taken_0x1cea90 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1cea90) {
            ctx->pc = 0x1CEA6Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cea6c;
        }
    }
    ctx->pc = 0x1CEA98u;
label_1cea98:
    // 0x1cea98: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1cea98u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1cea9c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1cea9cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ceaa0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ceaa0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ceaa4: 0x3e00008  jr          $ra
    ctx->pc = 0x1CEAA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CEAA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CEAA4u;
            // 0x1ceaa8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CEA6Cu: goto label_1cea6c;
            case 0x1CEA84u: goto label_1cea84;
            case 0x1CEA8Cu: goto label_1cea8c;
            case 0x1CEA98u: goto label_1cea98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CEAACu;
    // 0x1ceaac: 0x0  nop
    ctx->pc = 0x1ceaacu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
