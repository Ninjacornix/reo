#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017E398
// Address: 0x17e398 - 0x17e3a4
void sub_0017E398_0x17e398(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017E398_0x17e398");
#endif

    ctx->pc = 0x17e398u;

    // 0x17e398: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x17e398u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x17e39c: 0x3e00008  jr          $ra
    ctx->pc = 0x17E39Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17E3A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E39Cu;
            // 0x17e3a0: 0xac44f74c  sw          $a0, -0x8B4($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294965068), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17E3A4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
