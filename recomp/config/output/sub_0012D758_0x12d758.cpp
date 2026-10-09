#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012D758
// Address: 0x12d758 - 0x12d768
void sub_0012D758_0x12d758(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012D758_0x12d758");
#endif

    ctx->pc = 0x12d758u;

    // 0x12d758: 0x3e00008  jr          $ra
    ctx->pc = 0x12D758u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12D75Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D758u;
            // 0x12d75c: 0xac850040  sw          $a1, 0x40($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 64), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x12D760u;
    // 0x12d760: 0x3e00008  jr          $ra
    ctx->pc = 0x12D760u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12D764u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D760u;
            // 0x12d764: 0x8c820040  lw          $v0, 0x40($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x12D768u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
