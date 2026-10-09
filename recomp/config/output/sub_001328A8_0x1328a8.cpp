#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001328A8
// Address: 0x1328a8 - 0x1328b8
void sub_001328A8_0x1328a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001328A8_0x1328a8");
#endif

    ctx->pc = 0x1328a8u;

    // 0x1328a8: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x1328a8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x1328ac: 0x3e00008  jr          $ra
    ctx->pc = 0x1328ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1328B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1328ACu;
            // 0x1328b0: 0xac44b758  sw          $a0, -0x48A8($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294948696), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1328B4u;
    // 0x1328b4: 0x0  nop
    ctx->pc = 0x1328b4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
