#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018DB80
// Address: 0x18db80 - 0x18dbb0
void sub_0018DB80_0x18db80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018DB80_0x18db80");
#endif

    switch (ctx->pc) {
        case 0x18db88u: goto label_18db88;
        default: break;
    }

    ctx->pc = 0x18db80u;

    // 0x18db80: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x18DB80u;
    {
        const bool branch_taken_0x18db80 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18DB84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18DB80u;
            // 0x18db84: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18db80) {
            ctx->pc = 0x18DB94u;
            goto label_18db94;
        }
    }
    ctx->pc = 0x18DB88u;
label_18db88:
    // 0x18db88: 0xa0850000  sb          $a1, 0x0($a0)
    ctx->pc = 0x18db88u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x18db8c: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x18db8cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x18db90: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x18db90u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
label_18db94:
    // 0x18db94: 0xe6182a  slt         $v1, $a3, $a2
    ctx->pc = 0x18db94u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 7) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x18db98: 0x0  nop
    ctx->pc = 0x18db98u;
    // NOP
    // 0x18db9c: 0x1460fffa  bnez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x18DB9Cu;
    {
        const bool branch_taken_0x18db9c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x18db9c) {
            ctx->pc = 0x18DB88u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_18db88;
        }
    }
    ctx->pc = 0x18DBA4u;
    // 0x18dba4: 0x3e00008  jr          $ra
    ctx->pc = 0x18DBA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18DB88u: goto label_18db88;
            case 0x18DB94u: goto label_18db94;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18DBACu;
    // 0x18dbac: 0x0  nop
    ctx->pc = 0x18dbacu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
