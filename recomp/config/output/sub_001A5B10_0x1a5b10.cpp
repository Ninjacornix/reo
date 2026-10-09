#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A5B10
// Address: 0x1a5b10 - 0x1a5b40
void sub_001A5B10_0x1a5b10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A5B10_0x1a5b10");
#endif

    switch (ctx->pc) {
        case 0x1a5b18u: goto label_1a5b18;
        default: break;
    }

    ctx->pc = 0x1a5b10u;

    // 0x1a5b10: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1A5B10u;
    {
        const bool branch_taken_0x1a5b10 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A5B14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5B10u;
            // 0x1a5b14: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a5b10) {
            ctx->pc = 0x1A5B24u;
            goto label_1a5b24;
        }
    }
    ctx->pc = 0x1A5B18u;
label_1a5b18:
    // 0x1a5b18: 0xa0850000  sb          $a1, 0x0($a0)
    ctx->pc = 0x1a5b18u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x1a5b1c: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x1a5b1cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x1a5b20: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1a5b20u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
label_1a5b24:
    // 0x1a5b24: 0xe6182a  slt         $v1, $a3, $a2
    ctx->pc = 0x1a5b24u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 7) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x1a5b28: 0x0  nop
    ctx->pc = 0x1a5b28u;
    // NOP
    // 0x1a5b2c: 0x1460fffa  bnez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1A5B2Cu;
    {
        const bool branch_taken_0x1a5b2c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a5b2c) {
            ctx->pc = 0x1A5B18u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a5b18;
        }
    }
    ctx->pc = 0x1A5B34u;
    // 0x1a5b34: 0x3e00008  jr          $ra
    ctx->pc = 0x1A5B34u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A5B18u: goto label_1a5b18;
            case 0x1A5B24u: goto label_1a5b24;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A5B3Cu;
    // 0x1a5b3c: 0x0  nop
    ctx->pc = 0x1a5b3cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
