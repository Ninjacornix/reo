#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013FFD0
// Address: 0x13ffd0 - 0x13ffe8
void sub_0013FFD0_0x13ffd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013FFD0_0x13ffd0");
#endif

    ctx->pc = 0x13ffd0u;

    // 0x13ffd0: 0x52840  sll         $a1, $a1, 1
    ctx->pc = 0x13ffd0u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x13ffd4: 0xa62821  addu        $a1, $a1, $a2
    ctx->pc = 0x13ffd4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
    // 0x13ffd8: 0x52880  sll         $a1, $a1, 2
    ctx->pc = 0x13ffd8u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x13ffdc: 0xa42821  addu        $a1, $a1, $a0
    ctx->pc = 0x13ffdcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x13ffe0: 0x3e00008  jr          $ra
    ctx->pc = 0x13FFE0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13FFE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FFE0u;
            // 0x13ffe4: 0xaca70028  sw          $a3, 0x28($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 40), GPR_U32(ctx, 7));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x13FFE8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
