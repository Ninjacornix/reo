#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B6A00
// Address: 0x1b6a00 - 0x1b6a30
void sub_001B6A00_0x1b6a00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B6A00_0x1b6a00");
#endif

    ctx->pc = 0x1b6a00u;

    // 0x1b6a00: 0x8c830018  lw          $v1, 0x18($a0)
    ctx->pc = 0x1b6a00u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x1b6a04: 0x8c820064  lw          $v0, 0x64($a0)
    ctx->pc = 0x1b6a04u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 100)));
    // 0x1b6a08: 0x8c850048  lw          $a1, 0x48($a0)
    ctx->pc = 0x1b6a08u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 72)));
    // 0x1b6a0c: 0x621818  mult        $v1, $v1, $v0
    ctx->pc = 0x1b6a0cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1b6a10: 0x52880  sll         $a1, $a1, 2
    ctx->pc = 0x1b6a10u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x1b6a14: 0xa42021  addu        $a0, $a1, $a0
    ctx->pc = 0x1b6a14u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x1b6a18: 0x8c82002c  lw          $v0, 0x2C($a0)
    ctx->pc = 0x1b6a18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 44)));
    // 0x1b6a1c: 0x3e00008  jr          $ra
    ctx->pc = 0x1B6A1Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B6A20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6A1Cu;
            // 0x1b6a20: 0x431021  addu        $v0, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1B6A24u;
    // 0x1b6a24: 0x0  nop
    ctx->pc = 0x1b6a24u;
    // NOP
    // 0x1b6a28: 0x0  nop
    ctx->pc = 0x1b6a28u;
    // NOP
    // 0x1b6a2c: 0x0  nop
    ctx->pc = 0x1b6a2cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
