#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011DDA0
// Address: 0x11dda0 - 0x11ddd8
void sub_0011DDA0_0x11dda0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011DDA0_0x11dda0");
#endif

    switch (ctx->pc) {
        case 0x11ddb0u: goto label_11ddb0;
        default: break;
    }

    ctx->pc = 0x11dda0u;

    // 0x11dda0: 0x63082  srl         $a2, $a2, 2
    ctx->pc = 0x11dda0u;
    SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 6), 2));
    // 0x11dda4: 0x10c0000a  beqz        $a2, . + 4 + (0xA << 2)
    ctx->pc = 0x11DDA4u;
    {
        const bool branch_taken_0x11dda4 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x11DDA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11DDA4u;
            // 0x11dda8: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11dda4) {
            ctx->pc = 0x11DDD0u;
            goto label_11ddd0;
        }
    }
    ctx->pc = 0x11DDACu;
    // 0x11ddac: 0x0  nop
    ctx->pc = 0x11ddacu;
    // NOP
label_11ddb0:
    // 0x11ddb0: 0x8ca30000  lw          $v1, 0x0($a1)
    ctx->pc = 0x11ddb0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x11ddb4: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x11ddb4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x11ddb8: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x11ddb8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x11ddbc: 0xe6102b  sltu        $v0, $a3, $a2
    ctx->pc = 0x11ddbcu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 7) < (uint64_t)GPR_U64(ctx, 6)) ? 1 : 0);
    // 0x11ddc0: 0xac830000  sw          $v1, 0x0($a0)
    ctx->pc = 0x11ddc0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3));
    // 0x11ddc4: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x11ddc4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x11ddc8: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x11DDC8u;
    {
        const bool branch_taken_0x11ddc8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x11ddc8) {
            ctx->pc = 0x11DDB0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11ddb0;
        }
    }
    ctx->pc = 0x11DDD0u;
label_11ddd0:
    // 0x11ddd0: 0x3e00008  jr          $ra
    ctx->pc = 0x11DDD0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11DDD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11DDD0u;
            // 0x11ddd4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11DDB0u: goto label_11ddb0;
            case 0x11DDD0u: goto label_11ddd0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11DDD8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
