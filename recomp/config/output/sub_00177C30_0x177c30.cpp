#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00177C30
// Address: 0x177c30 - 0x177c48
void sub_00177C30_0x177c30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00177C30_0x177c30");
#endif

    ctx->pc = 0x177c30u;

    // 0x177c30: 0x51100  sll         $v0, $a1, 4
    ctx->pc = 0x177c30u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 4));
    // 0x177c34: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x177c34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x177c38: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x177c38u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x177c3c: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x177c3cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x177c40: 0x3e00008  jr          $ra
    ctx->pc = 0x177C40u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x177C44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177C40u;
            // 0x177c44: 0xac861aa0  sw          $a2, 0x1AA0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 6816), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x177C48u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
