#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00166FA8
// Address: 0x166fa8 - 0x166fcc
void sub_00166FA8_0x166fa8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00166FA8_0x166fa8");
#endif

    ctx->pc = 0x166fa8u;

    // 0x166fa8: 0x510c0  sll         $v0, $a1, 3
    ctx->pc = 0x166fa8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x166fac: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x166facu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x166fb0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x166fb0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x166fb4: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x166fb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x166fb8: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x166fb8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x166fbc: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x166fbcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x166fc0: 0x8c831154  lw          $v1, 0x1154($a0)
    ctx->pc = 0x166fc0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4436)));
    // 0x166fc4: 0x3e00008  jr          $ra
    ctx->pc = 0x166FC4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x166FC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166FC4u;
            // 0x166fc8: 0xacc30000  sw          $v1, 0x0($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x166FCCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
