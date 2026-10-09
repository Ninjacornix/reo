#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016E1F0
// Address: 0x16e1f0 - 0x16e230
void sub_0016E1F0_0x16e1f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016E1F0_0x16e1f0");
#endif

    ctx->pc = 0x16e1f0u;

    // 0x16e1f0: 0x8c820010  lw          $v0, 0x10($a0)
    ctx->pc = 0x16e1f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x16e1f4: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x16e1f4u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x16e1f8: 0x8c83001c  lw          $v1, 0x1C($a0)
    ctx->pc = 0x16e1f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 28)));
    // 0x16e1fc: 0xaca30004  sw          $v1, 0x4($a1)
    ctx->pc = 0x16e1fcu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 3));
    // 0x16e200: 0x8c820020  lw          $v0, 0x20($a0)
    ctx->pc = 0x16e200u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 32)));
    // 0x16e204: 0xaca20008  sw          $v0, 0x8($a1)
    ctx->pc = 0x16e204u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 8), GPR_U32(ctx, 2));
    // 0x16e208: 0x8c830024  lw          $v1, 0x24($a0)
    ctx->pc = 0x16e208u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 36)));
    // 0x16e20c: 0xaca3000c  sw          $v1, 0xC($a1)
    ctx->pc = 0x16e20cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 12), GPR_U32(ctx, 3));
    // 0x16e210: 0x8c820028  lw          $v0, 0x28($a0)
    ctx->pc = 0x16e210u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 40)));
    // 0x16e214: 0xaca20010  sw          $v0, 0x10($a1)
    ctx->pc = 0x16e214u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 16), GPR_U32(ctx, 2));
    // 0x16e218: 0x8c83002c  lw          $v1, 0x2C($a0)
    ctx->pc = 0x16e218u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 44)));
    // 0x16e21c: 0xaca30014  sw          $v1, 0x14($a1)
    ctx->pc = 0x16e21cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 20), GPR_U32(ctx, 3));
    // 0x16e220: 0x8c820014  lw          $v0, 0x14($a0)
    ctx->pc = 0x16e220u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x16e224: 0x3e00008  jr          $ra
    ctx->pc = 0x16E224u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16E228u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E224u;
            // 0x16e228: 0xaca20018  sw          $v0, 0x18($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 24), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x16E22Cu;
    // 0x16e22c: 0x0  nop
    ctx->pc = 0x16e22cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
