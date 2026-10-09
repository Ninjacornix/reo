#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A0CF0
// Address: 0x1a0cf0 - 0x1a0d00
void sub_001A0CF0_0x1a0cf0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A0CF0_0x1a0cf0");
#endif

    ctx->pc = 0x1a0cf0u;

    // 0x1a0cf0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a0cf0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a0cf4: 0x3e00008  jr          $ra
    ctx->pc = 0x1A0CF4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A0CF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0CF4u;
            // 0x1a0cf8: 0xac24fa08  sw          $a0, -0x5F8($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294965768), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1A0CFCu;
    // 0x1a0cfc: 0x0  nop
    ctx->pc = 0x1a0cfcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
