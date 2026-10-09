#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BE550
// Address: 0x1be550 - 0x1be57c
void sub_001BE550_0x1be550(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BE550_0x1be550");
#endif

    ctx->pc = 0x1be550u;

    // 0x1be550: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1be550u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1be554: 0xac244508  sw          $a0, 0x4508($at)
    ctx->pc = 0x1be554u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17672), GPR_U32(ctx, 4));
    // 0x1be558: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1be558u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1be55c: 0xa0204500  sb          $zero, 0x4500($at)
    ctx->pc = 0x1be55cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17664), (uint8_t)GPR_U32(ctx, 0));
    // 0x1be560: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1be560u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1be564: 0xa0204501  sb          $zero, 0x4501($at)
    ctx->pc = 0x1be564u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17665), (uint8_t)GPR_U32(ctx, 0));
    // 0x1be568: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1be568u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1be56c: 0xa0204502  sb          $zero, 0x4502($at)
    ctx->pc = 0x1be56cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17666), (uint8_t)GPR_U32(ctx, 0));
    // 0x1be570: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1be570u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1be574: 0x3e00008  jr          $ra
    ctx->pc = 0x1BE574u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BE578u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE574u;
            // 0x1be578: 0xa0204503  sb          $zero, 0x4503($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 17667), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1BE57Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
