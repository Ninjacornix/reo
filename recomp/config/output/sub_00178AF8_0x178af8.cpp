#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00178AF8
// Address: 0x178af8 - 0x178b00
void sub_00178AF8_0x178af8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00178AF8_0x178af8");
#endif

    ctx->pc = 0x178af8u;

    // 0x178af8: 0x3e00008  jr          $ra
    ctx->pc = 0x178AF8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x178AFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178AF8u;
            // 0x178afc: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x178B00u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
