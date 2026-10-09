#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00124F68
// Address: 0x124f68 - 0x124f70
void sub_00124F68_0x124f68(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00124F68_0x124f68");
#endif

    ctx->pc = 0x124f68u;

    // 0x124f68: 0x3e00008  jr          $ra
    ctx->pc = 0x124F68u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x124F6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124F68u;
            // 0x124f6c: 0x248200cc  addiu       $v0, $a0, 0xCC (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 204));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x124F70u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
