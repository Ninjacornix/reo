#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001769B0
// Address: 0x1769b0 - 0x1769c0
void sub_001769B0_0x1769b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001769B0_0x1769b0");
#endif

    ctx->pc = 0x1769b0u;

    // 0x1769b0: 0x63080  sll         $a2, $a2, 2
    ctx->pc = 0x1769b0u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x1769b4: 0x862021  addu        $a0, $a0, $a2
    ctx->pc = 0x1769b4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
    // 0x1769b8: 0x3e00008  jr          $ra
    ctx->pc = 0x1769B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1769BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1769B8u;
            // 0x1769bc: 0xac850cc0  sw          $a1, 0xCC0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 3264), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1769C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
