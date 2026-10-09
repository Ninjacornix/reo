#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A2C80
// Address: 0x1a2c80 - 0x1a2c90
void sub_001A2C80_0x1a2c80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A2C80_0x1a2c80");
#endif

    ctx->pc = 0x1a2c80u;

    // 0x1a2c80: 0x3e00008  jr          $ra
    ctx->pc = 0x1A2C80u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A2C84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2C80u;
            // 0x1a2c84: 0x80102d  daddu       $v0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1A2C88u;
    // 0x1a2c88: 0x0  nop
    ctx->pc = 0x1a2c88u;
    // NOP
    // 0x1a2c8c: 0x0  nop
    ctx->pc = 0x1a2c8cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
