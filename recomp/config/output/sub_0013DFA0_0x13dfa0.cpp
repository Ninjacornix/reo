#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013DFA0
// Address: 0x13dfa0 - 0x13dffc
void sub_0013DFA0_0x13dfa0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013DFA0_0x13dfa0");
#endif

    switch (ctx->pc) {
        case 0x13dfa8u: goto label_13dfa8;
        case 0x13dfd8u: goto label_13dfd8;
        default: break;
    }

    ctx->pc = 0x13dfa0u;

    // 0x13dfa0: 0x54a00009  bnel        $a1, $zero, . + 4 + (0x9 << 2)
    ctx->pc = 0x13DFA0u;
    {
        const bool branch_taken_0x13dfa0 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        if (branch_taken_0x13dfa0) {
            ctx->pc = 0x13DFA4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13DFA0u;
            // 0x13dfa4: 0x8ca50000  lw          $a1, 0x0($a1) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13DFC8u;
            goto label_13dfc8;
        }
    }
    ctx->pc = 0x13DFA8u;
label_13dfa8:
    // 0x13dfa8: 0x0  nop
    ctx->pc = 0x13dfa8u;
    // NOP
    // 0x13dfac: 0x0  nop
    ctx->pc = 0x13dfacu;
    // NOP
    // 0x13dfb0: 0x0  nop
    ctx->pc = 0x13dfb0u;
    // NOP
    // 0x13dfb4: 0x0  nop
    ctx->pc = 0x13dfb4u;
    // NOP
    // 0x13dfb8: 0x0  nop
    ctx->pc = 0x13dfb8u;
    // NOP
    // 0x13dfbc: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x13DFBCu;
    {
        const bool branch_taken_0x13dfbc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x13dfbc) {
            ctx->pc = 0x13DFA8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13dfa8;
        }
    }
    ctx->pc = 0x13DFC4u;
    // 0x13dfc4: 0x0  nop
    ctx->pc = 0x13dfc4u;
    // NOP
label_13dfc8:
    // 0x13dfc8: 0x18a0000a  blez        $a1, . + 4 + (0xA << 2)
    ctx->pc = 0x13DFC8u;
    {
        const bool branch_taken_0x13dfc8 = (GPR_S64(ctx, 5) <= 0);
        if (branch_taken_0x13dfc8) {
            ctx->pc = 0x13DFF4u;
            goto label_13dff4;
        }
    }
    ctx->pc = 0x13DFD0u;
    // 0x13dfd0: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x13dfd0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x13dfd4: 0x0  nop
    ctx->pc = 0x13dfd4u;
    // NOP
label_13dfd8:
    // 0x13dfd8: 0x0  nop
    ctx->pc = 0x13dfd8u;
    // NOP
    // 0x13dfdc: 0x0  nop
    ctx->pc = 0x13dfdcu;
    // NOP
    // 0x13dfe0: 0x0  nop
    ctx->pc = 0x13dfe0u;
    // NOP
    // 0x13dfe4: 0x0  nop
    ctx->pc = 0x13dfe4u;
    // NOP
    // 0x13dfe8: 0x0  nop
    ctx->pc = 0x13dfe8u;
    // NOP
    // 0x13dfec: 0x54a0fffa  bnel        $a1, $zero, . + 4 + (-0x6 << 2)
    ctx->pc = 0x13DFECu;
    {
        const bool branch_taken_0x13dfec = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        if (branch_taken_0x13dfec) {
            ctx->pc = 0x13DFF0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13DFECu;
            // 0x13dff0: 0x24a5ffff  addiu       $a1, $a1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13DFD8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13dfd8;
        }
    }
    ctx->pc = 0x13DFF4u;
label_13dff4:
    // 0x13dff4: 0x3e00008  jr          $ra
    ctx->pc = 0x13DFF4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13DFA8u: goto label_13dfa8;
            case 0x13DFC8u: goto label_13dfc8;
            case 0x13DFD8u: goto label_13dfd8;
            case 0x13DFF4u: goto label_13dff4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13DFFCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
