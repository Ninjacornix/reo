#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00137FD8
// Address: 0x137fd8 - 0x137fe8
void sub_00137FD8_0x137fd8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00137FD8_0x137fd8");
#endif

    ctx->pc = 0x137fd8u;

    // 0x137fd8: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x137fd8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x137fdc: 0x24020009  addiu       $v0, $zero, 0x9
    ctx->pc = 0x137fdcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x137fe0: 0x3e00008  jr          $ra
    ctx->pc = 0x137FE0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x137FE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137FE0u;
            // 0x137fe4: 0xa062bb8a  sb          $v0, -0x4476($v1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 3), 4294949770), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x137FE8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
