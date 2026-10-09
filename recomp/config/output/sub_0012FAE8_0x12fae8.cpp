#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012FAE8
// Address: 0x12fae8 - 0x12faf8
void sub_0012FAE8_0x12fae8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012FAE8_0x12fae8");
#endif

    ctx->pc = 0x12fae8u;

    // 0x12fae8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x12fae8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12faec: 0x3e00008  jr          $ra
    ctx->pc = 0x12FAECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12FAF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FAECu;
            // 0x12faf0: 0xa0820003  sb          $v0, 0x3($a0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 4), 3), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x12FAF4u;
    // 0x12faf4: 0x0  nop
    ctx->pc = 0x12faf4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
