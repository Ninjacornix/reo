#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D7390
// Address: 0x1d7390 - 0x1d73c0
void sub_001D7390_0x1d7390(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D7390_0x1d7390");
#endif

    ctx->pc = 0x1d7390u;

    // 0x1d7390: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d7390u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d7394: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1d7394u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1d7398: 0xac2045f8  sw          $zero, 0x45F8($at)
    ctx->pc = 0x1d7398u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17912), GPR_U32(ctx, 0));
    // 0x1d739c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1d739cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d73a0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d73a0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d73a4: 0xac2245e8  sw          $v0, 0x45E8($at)
    ctx->pc = 0x1d73a4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17896), GPR_U32(ctx, 2));
    // 0x1d73a8: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d73a8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d73ac: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1d73acu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d73b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1D73B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D73B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D73B0u;
            // 0x1d73b4: 0xa0234603  sb          $v1, 0x4603($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 17923), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1D73B8u;
    // 0x1d73b8: 0x0  nop
    ctx->pc = 0x1d73b8u;
    // NOP
    // 0x1d73bc: 0x0  nop
    ctx->pc = 0x1d73bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
