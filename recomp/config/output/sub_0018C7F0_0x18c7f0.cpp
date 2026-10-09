#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018C7F0
// Address: 0x18c7f0 - 0x18c810
void sub_0018C7F0_0x18c7f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018C7F0_0x18c7f0");
#endif

    ctx->pc = 0x18c7f0u;

    // 0x18c7f0: 0x3c021700  lui         $v0, 0x1700
    ctx->pc = 0x18c7f0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)5888 << 16));
    // 0x18c7f4: 0xac820000  sw          $v0, 0x0($a0)
    ctx->pc = 0x18c7f4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x18c7f8: 0xac800004  sw          $zero, 0x4($a0)
    ctx->pc = 0x18c7f8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 0));
    // 0x18c7fc: 0x24820010  addiu       $v0, $a0, 0x10
    ctx->pc = 0x18c7fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 16));
    // 0x18c800: 0xac800008  sw          $zero, 0x8($a0)
    ctx->pc = 0x18c800u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 0));
    // 0x18c804: 0x3e00008  jr          $ra
    ctx->pc = 0x18C804u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18C808u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18C804u;
            // 0x18c808: 0xac80000c  sw          $zero, 0xC($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x18C80Cu;
    // 0x18c80c: 0x0  nop
    ctx->pc = 0x18c80cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
