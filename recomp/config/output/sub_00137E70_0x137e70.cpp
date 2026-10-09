#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00137E70
// Address: 0x137e70 - 0x137e7c
void sub_00137E70_0x137e70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00137E70_0x137e70");
#endif

    ctx->pc = 0x137e70u;

    // 0x137e70: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x137e70u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x137e74: 0x3e00008  jr          $ra
    ctx->pc = 0x137E74u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x137E78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137E74u;
            // 0x137e78: 0x8062bb89  lb          $v0, -0x4477($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 4294949769)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x137E7Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
