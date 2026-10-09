#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001594F8
// Address: 0x1594f8 - 0x159520
void sub_001594F8_0x1594f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001594F8_0x1594f8");
#endif

    ctx->pc = 0x1594f8u;

    // 0x1594f8: 0x10a00003  beqz        $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1594F8u;
    {
        const bool branch_taken_0x1594f8 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x1594FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1594F8u;
            // 0x1594fc: 0x248403b8  addiu       $a0, $a0, 0x3B8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 952));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1594f8) {
            ctx->pc = 0x159508u;
            goto label_159508;
        }
    }
    ctx->pc = 0x159500u;
    // 0x159500: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x159500u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x159504: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x159504u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
label_159508:
    // 0x159508: 0x10c00003  beqz        $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x159508u;
    {
        const bool branch_taken_0x159508 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x159508) {
            ctx->pc = 0x159518u;
            goto label_159518;
        }
    }
    ctx->pc = 0x159510u;
    // 0x159510: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x159510u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x159514: 0xacc20000  sw          $v0, 0x0($a2)
    ctx->pc = 0x159514u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
label_159518:
    // 0x159518: 0x3e00008  jr          $ra
    ctx->pc = 0x159518u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x159508u: goto label_159508;
            case 0x159518u: goto label_159518;
            default: break;
        }
        return;
    }
    ctx->pc = 0x159520u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
