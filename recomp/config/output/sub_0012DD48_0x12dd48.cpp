#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012DD48
// Address: 0x12dd48 - 0x12dd50
void sub_0012DD48_0x12dd48(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012DD48_0x12dd48");
#endif

    ctx->pc = 0x12dd48u;

    // 0x12dd48: 0x3e00008  jr          $ra
    ctx->pc = 0x12DD48u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12DD4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12DD48u;
            // 0x12dd4c: 0x24020100  addiu       $v0, $zero, 0x100 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x12DD50u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
