#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016B0B0
// Address: 0x16b0b0 - 0x16b0c8
void sub_0016B0B0_0x16b0b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016B0B0_0x16b0b0");
#endif

    ctx->pc = 0x16b0b0u;

    // 0x16b0b0: 0x8c831aec  lw          $v1, 0x1AEC($a0)
    ctx->pc = 0x16b0b0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 6892)));
    // 0x16b0b4: 0x8c620014  lw          $v0, 0x14($v1)
    ctx->pc = 0x16b0b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 20)));
    // 0x16b0b8: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x16b0b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x16b0bc: 0x3e00008  jr          $ra
    ctx->pc = 0x16B0BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16B0C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16B0BCu;
            // 0x16b0c0: 0xac620014  sw          $v0, 0x14($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 20), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x16B0C4u;
    // 0x16b0c4: 0x0  nop
    ctx->pc = 0x16b0c4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
