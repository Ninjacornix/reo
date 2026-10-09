#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001594B8
// Address: 0x1594b8 - 0x1594e0
void sub_001594B8_0x1594b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001594B8_0x1594b8");
#endif

    ctx->pc = 0x1594b8u;

    // 0x1594b8: 0x51040  sll         $v0, $a1, 1
    ctx->pc = 0x1594b8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x1594bc: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x1594bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1594c0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1594c0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1594c4: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x1594c4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1594c8: 0x24840388  addiu       $a0, $a0, 0x388
    ctx->pc = 0x1594c8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 904));
    // 0x1594cc: 0xac880008  sw          $t0, 0x8($a0)
    ctx->pc = 0x1594ccu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 8));
    // 0x1594d0: 0xac860000  sw          $a2, 0x0($a0)
    ctx->pc = 0x1594d0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 6));
    // 0x1594d4: 0x3e00008  jr          $ra
    ctx->pc = 0x1594D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1594D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1594D4u;
            // 0x1594d8: 0xac870004  sw          $a3, 0x4($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 7));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1594DCu;
    // 0x1594dc: 0x0  nop
    ctx->pc = 0x1594dcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
