#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00172000
// Address: 0x172000 - 0x172018
void sub_00172000_0x172000(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00172000_0x172000");
#endif

    ctx->pc = 0x172000u;

    // 0x172000: 0x8c831b30  lw          $v1, 0x1B30($a0)
    ctx->pc = 0x172000u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 6960)));
    // 0x172004: 0x246309d8  addiu       $v1, $v1, 0x9D8
    ctx->pc = 0x172004u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2520));
    // 0x172008: 0x8c62000c  lw          $v0, 0xC($v1)
    ctx->pc = 0x172008u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 12)));
    // 0x17200c: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x17200cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x172010: 0x3e00008  jr          $ra
    ctx->pc = 0x172010u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x172014u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172010u;
            // 0x172014: 0xac62000c  sw          $v0, 0xC($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 12), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x172018u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
