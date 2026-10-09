#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015E160
// Address: 0x15e160 - 0x15e170
void sub_0015E160_0x15e160(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015E160_0x15e160");
#endif

    ctx->pc = 0x15e160u;

    // 0x15e160: 0x8c8200e0  lw          $v0, 0xE0($a0)
    ctx->pc = 0x15e160u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 224)));
    // 0x15e164: 0x3e00008  jr          $ra
    ctx->pc = 0x15E164u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15E168u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E164u;
            // 0x15e168: 0x2102b  sltu        $v0, $zero, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x15E16Cu;
    // 0x15e16c: 0x0  nop
    ctx->pc = 0x15e16cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
