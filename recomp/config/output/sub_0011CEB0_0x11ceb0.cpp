#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011CEB0
// Address: 0x11ceb0 - 0x11cee8
void sub_0011CEB0_0x11ceb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011CEB0_0x11ceb0");
#endif

    switch (ctx->pc) {
        case 0x11cec0u: goto label_11cec0;
        default: break;
    }

    ctx->pc = 0x11ceb0u;

    // 0x11ceb0: 0x63082  srl         $a2, $a2, 2
    ctx->pc = 0x11ceb0u;
    SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 6), 2));
    // 0x11ceb4: 0x10c0000a  beqz        $a2, . + 4 + (0xA << 2)
    ctx->pc = 0x11CEB4u;
    {
        const bool branch_taken_0x11ceb4 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x11CEB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CEB4u;
            // 0x11ceb8: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ceb4) {
            ctx->pc = 0x11CEE0u;
            goto label_11cee0;
        }
    }
    ctx->pc = 0x11CEBCu;
    // 0x11cebc: 0x0  nop
    ctx->pc = 0x11cebcu;
    // NOP
label_11cec0:
    // 0x11cec0: 0x8ca30000  lw          $v1, 0x0($a1)
    ctx->pc = 0x11cec0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x11cec4: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x11cec4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x11cec8: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x11cec8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x11cecc: 0xe6102b  sltu        $v0, $a3, $a2
    ctx->pc = 0x11ceccu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 7) < (uint64_t)GPR_U64(ctx, 6)) ? 1 : 0);
    // 0x11ced0: 0xac830000  sw          $v1, 0x0($a0)
    ctx->pc = 0x11ced0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3));
    // 0x11ced4: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x11ced4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x11ced8: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x11CED8u;
    {
        const bool branch_taken_0x11ced8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x11ced8) {
            ctx->pc = 0x11CEC0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11cec0;
        }
    }
    ctx->pc = 0x11CEE0u;
label_11cee0:
    // 0x11cee0: 0x3e00008  jr          $ra
    ctx->pc = 0x11CEE0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11CEE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CEE0u;
            // 0x11cee4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11CEC0u: goto label_11cec0;
            case 0x11CEE0u: goto label_11cee0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11CEE8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
