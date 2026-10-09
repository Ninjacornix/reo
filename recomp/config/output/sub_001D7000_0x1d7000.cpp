#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D7000
// Address: 0x1d7000 - 0x1d7030
void sub_001D7000_0x1d7000(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D7000_0x1d7000");
#endif

    ctx->pc = 0x1d7000u;

    // 0x1d7000: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d7000u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d7004: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1d7004u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1d7008: 0xac2045f8  sw          $zero, 0x45F8($at)
    ctx->pc = 0x1d7008u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17912), GPR_U32(ctx, 0));
    // 0x1d700c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1d700cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d7010: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d7010u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d7014: 0xac2245e8  sw          $v0, 0x45E8($at)
    ctx->pc = 0x1d7014u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17896), GPR_U32(ctx, 2));
    // 0x1d7018: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d7018u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d701c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1d701cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d7020: 0x3e00008  jr          $ra
    ctx->pc = 0x1D7020u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D7024u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7020u;
            // 0x1d7024: 0xa0234603  sb          $v1, 0x4603($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 17923), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1D7028u;
    // 0x1d7028: 0x0  nop
    ctx->pc = 0x1d7028u;
    // NOP
    // 0x1d702c: 0x0  nop
    ctx->pc = 0x1d702cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
