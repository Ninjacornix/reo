#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00148020
// Address: 0x148020 - 0x148034
void sub_00148020_0x148020(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00148020_0x148020");
#endif

    ctx->pc = 0x148020u;

    // 0x148020: 0x8c830040  lw          $v1, 0x40($a0)
    ctx->pc = 0x148020u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x148024: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x148024u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x148028: 0xfc600090  sd          $zero, 0x90($v1)
    ctx->pc = 0x148028u;
    WRITE64(ADD32(GPR_U32(ctx, 3), 144), GPR_U64(ctx, 0));
    // 0x14802c: 0x3e00008  jr          $ra
    ctx->pc = 0x14802Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x148030u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14802Cu;
            // 0x148030: 0xac60008c  sw          $zero, 0x8C($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 140), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x148034u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
