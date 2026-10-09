#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00167CC0
// Address: 0x167cc0 - 0x167ce0
void sub_00167CC0_0x167cc0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00167CC0_0x167cc0");
#endif

    ctx->pc = 0x167cc0u;

    // 0x167cc0: 0x510c0  sll         $v0, $a1, 3
    ctx->pc = 0x167cc0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x167cc4: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x167cc4u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x167cc8: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x167cc8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x167ccc: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x167cccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x167cd0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x167cd0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x167cd4: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x167cd4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x167cd8: 0x3e00008  jr          $ra
    ctx->pc = 0x167CD8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x167CDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167CD8u;
            // 0x167cdc: 0x8c821148  lw          $v0, 0x1148($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4424)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x167CE0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
