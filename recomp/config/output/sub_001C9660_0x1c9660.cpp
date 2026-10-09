#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C9660
// Address: 0x1c9660 - 0x1c96a4
void sub_001C9660_0x1c9660(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C9660_0x1c9660");
#endif

    ctx->pc = 0x1c9660u;

    // 0x1c9660: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1c9660u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1c9664: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1c9664u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1c9668: 0x3c060034  lui         $a2, 0x34
    ctx->pc = 0x1c9668u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)52 << 16));
    // 0x1c966c: 0x3c070034  lui         $a3, 0x34
    ctx->pc = 0x1c966cu;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)52 << 16));
    // 0x1c9670: 0x3c080034  lui         $t0, 0x34
    ctx->pc = 0x1c9670u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)52 << 16));
    // 0x1c9674: 0x3c090034  lui         $t1, 0x34
    ctx->pc = 0x1c9674u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)52 << 16));
    // 0x1c9678: 0x3c0a0034  lui         $t2, 0x34
    ctx->pc = 0x1c9678u;
    SET_GPR_S32(ctx, 10, (int32_t)((uint32_t)52 << 16));
    // 0x1c967c: 0x3c0b0034  lui         $t3, 0x34
    ctx->pc = 0x1c967cu;
    SET_GPR_S32(ctx, 11, (int32_t)((uint32_t)52 << 16));
    // 0x1c9680: 0x2484c6e1  addiu       $a0, $a0, -0x391F
    ctx->pc = 0x1c9680u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294952673));
    // 0x1c9684: 0x24a5c6e2  addiu       $a1, $a1, -0x391E
    ctx->pc = 0x1c9684u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294952674));
    // 0x1c9688: 0x24c6c6e3  addiu       $a2, $a2, -0x391D
    ctx->pc = 0x1c9688u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294952675));
    // 0x1c968c: 0x24e7c6e4  addiu       $a3, $a3, -0x391C
    ctx->pc = 0x1c968cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294952676));
    // 0x1c9690: 0x2508c6e6  addiu       $t0, $t0, -0x391A
    ctx->pc = 0x1c9690u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4294952678));
    // 0x1c9694: 0x2529c6e8  addiu       $t1, $t1, -0x3918
    ctx->pc = 0x1c9694u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 4294952680));
    // 0x1c9698: 0x254ac6ea  addiu       $t2, $t2, -0x3916
    ctx->pc = 0x1c9698u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 4294952682));
    // 0x1c969c: 0x807261c  j           func_1C9870
    ctx->pc = 0x1C969Cu;
    ctx->pc = 0x1C96A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C969Cu;
            // 0x1c96a0: 0x256bc6ef  addiu       $t3, $t3, -0x3911 (Delay Slot)
        SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 4294952687));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C9870u;
    if (runtime->hasFunction(0x1C9870u)) {
        auto targetFn = runtime->lookupFunction(0x1C9870u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001C9870_0x1c9870(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1C96A4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
