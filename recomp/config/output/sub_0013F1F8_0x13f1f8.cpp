#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013F1F8
// Address: 0x13f1f8 - 0x13f204
void sub_0013F1F8_0x13f1f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013F1F8_0x13f1f8");
#endif

    ctx->pc = 0x13f1f8u;

    // 0x13f1f8: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13f1f8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13f1fc: 0x3e00008  jr          $ra
    ctx->pc = 0x13F1FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F200u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F1FCu;
            // 0x13f200: 0xac404758  sw          $zero, 0x4758($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 18264), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x13F204u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
