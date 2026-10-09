#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013BBE0
// Address: 0x13bbe0 - 0x13bbe8
void sub_0013BBE0_0x13bbe0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013BBE0_0x13bbe0");
#endif

    ctx->pc = 0x13bbe0u;

    // 0x13bbe0: 0x3e00008  jr          $ra
    ctx->pc = 0x13BBE0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13BBE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13BBE0u;
            // 0x13bbe4: 0x24020800  addiu       $v0, $zero, 0x800 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x13BBE8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
