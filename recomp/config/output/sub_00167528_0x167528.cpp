#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00167528
// Address: 0x167528 - 0x167548
void sub_00167528_0x167528(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00167528_0x167528");
#endif

    ctx->pc = 0x167528u;

    // 0x167528: 0x510c0  sll         $v0, $a1, 3
    ctx->pc = 0x167528u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x16752c: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x16752cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x167530: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x167530u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x167534: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x167534u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x167538: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x167538u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x16753c: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x16753cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x167540: 0x3e00008  jr          $ra
    ctx->pc = 0x167540u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x167544u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167540u;
            // 0x167544: 0x8c821174  lw          $v0, 0x1174($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4468)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x167548u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
