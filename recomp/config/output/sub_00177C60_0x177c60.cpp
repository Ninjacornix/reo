#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00177C60
// Address: 0x177c60 - 0x177c78
void sub_00177C60_0x177c60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00177C60_0x177c60");
#endif

    ctx->pc = 0x177c60u;

    // 0x177c60: 0x51100  sll         $v0, $a1, 4
    ctx->pc = 0x177c60u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 4));
    // 0x177c64: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x177c64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x177c68: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x177c68u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x177c6c: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x177c6cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x177c70: 0x3e00008  jr          $ra
    ctx->pc = 0x177C70u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x177C74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177C70u;
            // 0x177c74: 0xac861aa4  sw          $a2, 0x1AA4($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 6820), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x177C78u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
