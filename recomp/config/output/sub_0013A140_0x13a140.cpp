#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013A140
// Address: 0x13a140 - 0x13a160
void sub_0013A140_0x13a140(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013A140_0x13a140");
#endif

    ctx->pc = 0x13a140u;

    // 0x13a140: 0x8c820014  lw          $v0, 0x14($a0)
    ctx->pc = 0x13a140u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x13a144: 0x3c03ffff  lui         $v1, 0xFFFF
    ctx->pc = 0x13a144u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)65535 << 16));
    // 0x13a148: 0x3183e  dsrl32      $v1, $v1, 0
    ctx->pc = 0x13a148u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 0));
    // 0x13a14c: 0x212f8  dsll        $v0, $v0, 11
    ctx->pc = 0x13a14cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 11);
    // 0x13a150: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x13a150u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x13a154: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x13a154u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x13a158: 0x3e00008  jr          $ra
    ctx->pc = 0x13A158u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13A15Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A158u;
            // 0x13a15c: 0x2103f  dsra32      $v0, $v0, 0 (Delay Slot)
        SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x13A160u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
