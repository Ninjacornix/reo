#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00139810
// Address: 0x139810 - 0x139824
void sub_00139810_0x139810(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00139810_0x139810");
#endif

    ctx->pc = 0x139810u;

    // 0x139810: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x139810u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x139814: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x139814u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x139818: 0xac44cbe4  sw          $a0, -0x341C($v0)
    ctx->pc = 0x139818u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294953956), GPR_U32(ctx, 4));
    // 0x13981c: 0x3e00008  jr          $ra
    ctx->pc = 0x13981Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x139820u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13981Cu;
            // 0x139820: 0xac65cbe8  sw          $a1, -0x3418($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 4294953960), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x139824u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
