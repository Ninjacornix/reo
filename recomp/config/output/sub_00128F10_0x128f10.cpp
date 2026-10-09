#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00128F10
// Address: 0x128f10 - 0x128f28
void sub_00128F10_0x128f10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00128F10_0x128f10");
#endif

    ctx->pc = 0x128f10u;

    // 0x128f10: 0x42080  sll         $a0, $a0, 2
    ctx->pc = 0x128f10u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x128f14: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x128f14u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x128f18: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x128f18u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x128f1c: 0x8c63cd00  lw          $v1, -0x3300($v1)
    ctx->pc = 0x128f1cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294954240)));
    // 0x128f20: 0x3e00008  jr          $ra
    ctx->pc = 0x128F20u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x128F24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128F20u;
            // 0x128f24: 0x8c620004  lw          $v0, 0x4($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x128F28u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
