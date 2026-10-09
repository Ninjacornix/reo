#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00167BC8
// Address: 0x167bc8 - 0x167bd8
void sub_00167BC8_0x167bc8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00167BC8_0x167bc8");
#endif

    ctx->pc = 0x167bc8u;

    // 0x167bc8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x167bc8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x167bcc: 0xac820044  sw          $v0, 0x44($a0)
    ctx->pc = 0x167bccu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 68), GPR_U32(ctx, 2));
    // 0x167bd0: 0x3e00008  jr          $ra
    ctx->pc = 0x167BD0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x167BD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167BD0u;
            // 0x167bd4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x167BD8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
