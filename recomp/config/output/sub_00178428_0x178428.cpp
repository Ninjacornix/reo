#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00178428
// Address: 0x178428 - 0x17843c
void sub_00178428_0x178428(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00178428_0x178428");
#endif

    ctx->pc = 0x178428u;

    // 0x178428: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x178428u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x17842c: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x17842cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x178430: 0xac44f1dc  sw          $a0, -0xE24($v0)
    ctx->pc = 0x178430u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294963676), GPR_U32(ctx, 4));
    // 0x178434: 0x3e00008  jr          $ra
    ctx->pc = 0x178434u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x178438u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178434u;
            // 0x178438: 0xac65f1d8  sw          $a1, -0xE28($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 4294963672), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17843Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
