#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017A7F8
// Address: 0x17a7f8 - 0x17a818
void sub_0017A7F8_0x17a7f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017A7F8_0x17a7f8");
#endif

    ctx->pc = 0x17a7f8u;

    // 0x17a7f8: 0x24840008  addiu       $a0, $a0, 0x8
    ctx->pc = 0x17a7f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8));
    // 0x17a7fc: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x17a7fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x17a800: 0xace20000  sw          $v0, 0x0($a3)
    ctx->pc = 0x17a800u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 2));
    // 0x17a804: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x17a804u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x17a808: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x17a808u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x17a80c: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x17a80cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x17a810: 0x3e00008  jr          $ra
    ctx->pc = 0x17A810u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17A814u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A810u;
            // 0x17a814: 0xacc20000  sw          $v0, 0x0($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17A818u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
