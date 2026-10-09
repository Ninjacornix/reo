#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00114AA0
// Address: 0x114aa0 - 0x114ab0
void sub_00114AA0_0x114aa0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00114AA0_0x114aa0");
#endif

    ctx->pc = 0x114aa0u;

    // 0x114aa0: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x114aa0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x114aa4: 0x3e00008  jr          $ra
    ctx->pc = 0x114AA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x114AA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x114AA4u;
            // 0x114aa8: 0xac409d30  sw          $zero, -0x62D0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294942000), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114AACu;
    // 0x114aac: 0x0  nop
    ctx->pc = 0x114aacu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
