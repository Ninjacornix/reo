#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00135068
// Address: 0x135068 - 0x135078
void sub_00135068_0x135068(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00135068_0x135068");
#endif

    ctx->pc = 0x135068u;

    // 0x135068: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x135068u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x13506c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x13506cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x135070: 0x3e00008  jr          $ra
    ctx->pc = 0x135070u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x135074u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135070u;
            // 0x135074: 0xac62b7b0  sw          $v0, -0x4850($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 4294948784), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x135078u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
