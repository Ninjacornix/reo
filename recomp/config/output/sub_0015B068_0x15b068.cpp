#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015B068
// Address: 0x15b068 - 0x15b074
void sub_0015B068_0x15b068(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015B068_0x15b068");
#endif

    ctx->pc = 0x15b068u;

    // 0x15b068: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x15b068u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x15b06c: 0x3e00008  jr          $ra
    ctx->pc = 0x15B06Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15B070u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15B06Cu;
            // 0x15b070: 0x2442e5c0  addiu       $v0, $v0, -0x1A40 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294960576));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x15B074u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
