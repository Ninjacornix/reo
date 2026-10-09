#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012A0F0
// Address: 0x12a0f0 - 0x12a0fc
void sub_0012A0F0_0x12a0f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012A0F0_0x12a0f0");
#endif

    ctx->pc = 0x12a0f0u;

    // 0x12a0f0: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12a0f0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12a0f4: 0x3e00008  jr          $ra
    ctx->pc = 0x12A0F4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12A0F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12A0F4u;
            // 0x12a0f8: 0xac44f3bc  sw          $a0, -0xC44($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294964156), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x12A0FCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
