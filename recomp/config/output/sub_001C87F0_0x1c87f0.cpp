#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C87F0
// Address: 0x1c87f0 - 0x1c8810
void sub_001C87F0_0x1c87f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C87F0_0x1c87f0");
#endif

    ctx->pc = 0x1c87f0u;

    // 0x1c87f0: 0x3e00008  jr          $ra
    ctx->pc = 0x1C87F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C87F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C87F0u;
            // 0x1c87f4: 0x8c820000  lw          $v0, 0x0($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1C87F8u;
    // 0x1c87f8: 0x0  nop
    ctx->pc = 0x1c87f8u;
    // NOP
    // 0x1c87fc: 0x0  nop
    ctx->pc = 0x1c87fcu;
    // NOP
    // 0x1c8800: 0x3e00008  jr          $ra
    ctx->pc = 0x1C8800u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C8804u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8800u;
            // 0x1c8804: 0x80820044  lb          $v0, 0x44($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 68)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1C8808u;
    // 0x1c8808: 0x0  nop
    ctx->pc = 0x1c8808u;
    // NOP
    // 0x1c880c: 0x0  nop
    ctx->pc = 0x1c880cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
