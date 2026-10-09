#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00116BD8
// Address: 0x116bd8 - 0x116bf0
void sub_00116BD8_0x116bd8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00116BD8_0x116bd8");
#endif

    ctx->pc = 0x116bd8u;

    // 0x116bd8: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x116bd8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x116bdc: 0x2463af98  addiu       $v1, $v1, -0x5068
    ctx->pc = 0x116bdcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294946712));
    // 0x116be0: 0x8c620014  lw          $v0, 0x14($v1)
    ctx->pc = 0x116be0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 20)));
    // 0x116be4: 0xac650018  sw          $a1, 0x18($v1)
    ctx->pc = 0x116be4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 24), GPR_U32(ctx, 5));
    // 0x116be8: 0x3e00008  jr          $ra
    ctx->pc = 0x116BE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x116BECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116BE8u;
            // 0x116bec: 0xac640014  sw          $a0, 0x14($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 20), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x116BF0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
