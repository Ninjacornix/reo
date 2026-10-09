#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013F1C8
// Address: 0x13f1c8 - 0x13f1e0
void sub_0013F1C8_0x13f1c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013F1C8_0x13f1c8");
#endif

    ctx->pc = 0x13f1c8u;

    // 0x13f1c8: 0x52880  sll         $a1, $a1, 2
    ctx->pc = 0x13f1c8u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x13f1cc: 0x852021  addu        $a0, $a0, $a1
    ctx->pc = 0x13f1ccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x13f1d0: 0x8c830008  lw          $v1, 0x8($a0)
    ctx->pc = 0x13f1d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x13f1d4: 0x3e00008  jr          $ra
    ctx->pc = 0x13F1D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F1D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F1D4u;
            // 0x13f1d8: 0x8c620008  lw          $v0, 0x8($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x13F1DCu;
    // 0x13f1dc: 0x0  nop
    ctx->pc = 0x13f1dcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
