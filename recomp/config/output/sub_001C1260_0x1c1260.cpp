#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C1260
// Address: 0x1c1260 - 0x1c1270
void sub_001C1260_0x1c1260(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C1260_0x1c1260");
#endif

    ctx->pc = 0x1c1260u;

    // 0x1c1260: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c1260u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c1264: 0x3e00008  jr          $ra
    ctx->pc = 0x1C1264u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C1268u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1264u;
            // 0x1c1268: 0x8c226c74  lw          $v0, 0x6C74($at) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 27764)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1C126Cu;
    // 0x1c126c: 0x0  nop
    ctx->pc = 0x1c126cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
