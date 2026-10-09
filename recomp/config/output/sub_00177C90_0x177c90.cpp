#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00177C90
// Address: 0x177c90 - 0x177cb0
void sub_00177C90_0x177c90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00177C90_0x177c90");
#endif

    ctx->pc = 0x177c90u;

    // 0x177c90: 0x51100  sll         $v0, $a1, 4
    ctx->pc = 0x177c90u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 4));
    // 0x177c94: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x177c94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x177c98: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x177c98u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x177c9c: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x177c9cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x177ca0: 0x8c821aac  lw          $v0, 0x1AAC($a0)
    ctx->pc = 0x177ca0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 6828)));
    // 0x177ca4: 0x3e00008  jr          $ra
    ctx->pc = 0x177CA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x177CA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177CA4u;
            // 0x177ca8: 0x2102b  sltu        $v0, $zero, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x177CACu;
    // 0x177cac: 0x0  nop
    ctx->pc = 0x177cacu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
