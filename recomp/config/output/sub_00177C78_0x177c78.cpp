#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00177C78
// Address: 0x177c78 - 0x177c90
void sub_00177C78_0x177c78(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00177C78_0x177c78");
#endif

    ctx->pc = 0x177c78u;

    // 0x177c78: 0x51100  sll         $v0, $a1, 4
    ctx->pc = 0x177c78u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 4));
    // 0x177c7c: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x177c7cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x177c80: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x177c80u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x177c84: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x177c84u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x177c88: 0x3e00008  jr          $ra
    ctx->pc = 0x177C88u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x177C8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177C88u;
            // 0x177c8c: 0x8c821aa4  lw          $v0, 0x1AA4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 6820)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x177C90u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
