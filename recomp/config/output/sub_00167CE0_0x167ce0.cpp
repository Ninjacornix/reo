#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00167CE0
// Address: 0x167ce0 - 0x167d00
void sub_00167CE0_0x167ce0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00167CE0_0x167ce0");
#endif

    ctx->pc = 0x167ce0u;

    // 0x167ce0: 0x510c0  sll         $v0, $a1, 3
    ctx->pc = 0x167ce0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x167ce4: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x167ce4u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x167ce8: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x167ce8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x167cec: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x167cecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x167cf0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x167cf0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x167cf4: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x167cf4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x167cf8: 0x3e00008  jr          $ra
    ctx->pc = 0x167CF8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x167CFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167CF8u;
            // 0x167cfc: 0xac86114c  sw          $a2, 0x114C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 4428), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x167D00u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
