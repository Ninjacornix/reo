#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D7030
// Address: 0x1d7030 - 0x1d7050
void sub_001D7030_0x1d7030(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D7030_0x1d7030");
#endif

    ctx->pc = 0x1d7030u;

    // 0x1d7030: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d7030u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d7034: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1d7034u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1d7038: 0xa0204603  sb          $zero, 0x4603($at)
    ctx->pc = 0x1d7038u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17923), (uint8_t)GPR_U32(ctx, 0));
    // 0x1d703c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1d703cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d7040: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d7040u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d7044: 0x3e00008  jr          $ra
    ctx->pc = 0x1D7044u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D7048u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7044u;
            // 0x1d7048: 0xac2345e8  sw          $v1, 0x45E8($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 17896), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1D704Cu;
    // 0x1d704c: 0x0  nop
    ctx->pc = 0x1d704cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
