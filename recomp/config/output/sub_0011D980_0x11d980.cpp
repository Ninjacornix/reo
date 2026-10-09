#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011D980
// Address: 0x11d980 - 0x11d9b8
void sub_0011D980_0x11d980(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011D980_0x11d980");
#endif

    switch (ctx->pc) {
        case 0x11d990u: goto label_11d990;
        default: break;
    }

    ctx->pc = 0x11d980u;

    // 0x11d980: 0x63082  srl         $a2, $a2, 2
    ctx->pc = 0x11d980u;
    SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 6), 2));
    // 0x11d984: 0x10c0000a  beqz        $a2, . + 4 + (0xA << 2)
    ctx->pc = 0x11D984u;
    {
        const bool branch_taken_0x11d984 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x11D988u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11D984u;
            // 0x11d988: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11d984) {
            ctx->pc = 0x11D9B0u;
            goto label_11d9b0;
        }
    }
    ctx->pc = 0x11D98Cu;
    // 0x11d98c: 0x0  nop
    ctx->pc = 0x11d98cu;
    // NOP
label_11d990:
    // 0x11d990: 0x8ca30000  lw          $v1, 0x0($a1)
    ctx->pc = 0x11d990u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x11d994: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x11d994u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x11d998: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x11d998u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x11d99c: 0xe6102b  sltu        $v0, $a3, $a2
    ctx->pc = 0x11d99cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 7) < (uint64_t)GPR_U64(ctx, 6)) ? 1 : 0);
    // 0x11d9a0: 0xac830000  sw          $v1, 0x0($a0)
    ctx->pc = 0x11d9a0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3));
    // 0x11d9a4: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x11d9a4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x11d9a8: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x11D9A8u;
    {
        const bool branch_taken_0x11d9a8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x11d9a8) {
            ctx->pc = 0x11D990u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11d990;
        }
    }
    ctx->pc = 0x11D9B0u;
label_11d9b0:
    // 0x11d9b0: 0x3e00008  jr          $ra
    ctx->pc = 0x11D9B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11D9B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11D9B0u;
            // 0x11d9b4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11D990u: goto label_11d990;
            case 0x11D9B0u: goto label_11d9b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11D9B8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
