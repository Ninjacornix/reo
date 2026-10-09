#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BA330
// Address: 0x1ba330 - 0x1ba35c
void sub_001BA330_0x1ba330(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BA330_0x1ba330");
#endif

    ctx->pc = 0x1ba330u;

    // 0x1ba330: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1ba330u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1ba334: 0xa020ae71  sb          $zero, -0x518F($at)
    ctx->pc = 0x1ba334u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294946417), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ba338: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1ba338u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1ba33c: 0xa020ae72  sb          $zero, -0x518E($at)
    ctx->pc = 0x1ba33cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294946418), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ba340: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1ba340u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1ba344: 0xa020ae73  sb          $zero, -0x518D($at)
    ctx->pc = 0x1ba344u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294946419), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ba348: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1ba348u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1ba34c: 0xa020ae74  sb          $zero, -0x518C($at)
    ctx->pc = 0x1ba34cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294946420), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ba350: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1ba350u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1ba354: 0x3e00008  jr          $ra
    ctx->pc = 0x1BA354u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BA358u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA354u;
            // 0x1ba358: 0xa020ae75  sb          $zero, -0x518B($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 4294946421), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1BA35Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
