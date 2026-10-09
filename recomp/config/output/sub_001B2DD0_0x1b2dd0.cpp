#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B2DD0
// Address: 0x1b2dd0 - 0x1b2e04
void sub_001B2DD0_0x1b2dd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B2DD0_0x1b2dd0");
#endif

    ctx->pc = 0x1b2dd0u;

    // 0x1b2dd0: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b2dd0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b2dd4: 0x3c04004c  lui         $a0, 0x4C
    ctx->pc = 0x1b2dd4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)76 << 16));
    // 0x1b2dd8: 0xa420a82c  sh          $zero, -0x57D4($at)
    ctx->pc = 0x1b2dd8u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 4294944812), (uint16_t)GPR_U32(ctx, 0));
    // 0x1b2ddc: 0x24849680  addiu       $a0, $a0, -0x6980
    ctx->pc = 0x1b2ddcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294940288));
    // 0x1b2de0: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b2de0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b2de4: 0x240500ff  addiu       $a1, $zero, 0xFF
    ctx->pc = 0x1b2de4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1b2de8: 0xa420a82e  sh          $zero, -0x57D2($at)
    ctx->pc = 0x1b2de8u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 4294944814), (uint16_t)GPR_U32(ctx, 0));
    // 0x1b2dec: 0x24060400  addiu       $a2, $zero, 0x400
    ctx->pc = 0x1b2decu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
    // 0x1b2df0: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b2df0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b2df4: 0xa420a828  sh          $zero, -0x57D8($at)
    ctx->pc = 0x1b2df4u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 4294944808), (uint16_t)GPR_U32(ctx, 0));
    // 0x1b2df8: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b2df8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b2dfc: 0x8041f1a  j           func_107C68
    ctx->pc = 0x1B2DFCu;
    ctx->pc = 0x1B2E00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2DFCu;
            // 0x1b2e00: 0xa420a82a  sh          $zero, -0x57D6($at) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 1), 4294944810), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107C68_0x107c68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1B2E04u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
