#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017CE90
// Address: 0x17ce90 - 0x17cea0
void sub_0017CE90_0x17ce90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017CE90_0x17ce90");
#endif

    ctx->pc = 0x17ce90u;

    // 0x17ce90: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x17ce90u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x17ce94: 0x3e00008  jr          $ra
    ctx->pc = 0x17CE94u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17CE98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17CE94u;
            // 0x17ce98: 0x24421390  addiu       $v0, $v0, 0x1390 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 5008));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17CE9Cu;
    // 0x17ce9c: 0x0  nop
    ctx->pc = 0x17ce9cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
