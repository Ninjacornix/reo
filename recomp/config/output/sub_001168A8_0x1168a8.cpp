#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001168A8
// Address: 0x1168a8 - 0x1168c4
void sub_001168A8_0x1168a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001168A8_0x1168a8");
#endif

    ctx->pc = 0x1168a8u;

    // 0x1168a8: 0x8c820010  lw          $v0, 0x10($a0)
    ctx->pc = 0x1168a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x1168ac: 0x8ca6001c  lw          $a2, 0x1C($a1)
    ctx->pc = 0x1168acu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 28)));
    // 0x1168b0: 0x8c830014  lw          $v1, 0x14($a0)
    ctx->pc = 0x1168b0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x1168b4: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1168b4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1168b8: 0x461021  addu        $v0, $v0, $a2
    ctx->pc = 0x1168b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x1168bc: 0x3e00008  jr          $ra
    ctx->pc = 0x1168BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1168C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1168BCu;
            // 0x1168c0: 0xac430000  sw          $v1, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1168C4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
