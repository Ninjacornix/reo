#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001264D0
// Address: 0x1264d0 - 0x1264e0
void sub_001264D0_0x1264d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001264D0_0x1264d0");
#endif

    ctx->pc = 0x1264d0u;

    // 0x1264d0: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x1264d0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x1264d4: 0x3e00008  jr          $ra
    ctx->pc = 0x1264D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1264D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1264D4u;
            // 0x1264d8: 0xac40c7a0  sw          $zero, -0x3860($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294952864), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1264DCu;
    // 0x1264dc: 0x0  nop
    ctx->pc = 0x1264dcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
