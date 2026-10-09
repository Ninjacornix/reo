#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00167CA0
// Address: 0x167ca0 - 0x167cc0
void sub_00167CA0_0x167ca0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00167CA0_0x167ca0");
#endif

    ctx->pc = 0x167ca0u;

    // 0x167ca0: 0x510c0  sll         $v0, $a1, 3
    ctx->pc = 0x167ca0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x167ca4: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x167ca4u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x167ca8: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x167ca8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x167cac: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x167cacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x167cb0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x167cb0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x167cb4: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x167cb4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x167cb8: 0x3e00008  jr          $ra
    ctx->pc = 0x167CB8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x167CBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167CB8u;
            // 0x167cbc: 0xac861148  sw          $a2, 0x1148($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 4424), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x167CC0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
