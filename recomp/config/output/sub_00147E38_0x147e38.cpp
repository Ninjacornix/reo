#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00147E38
// Address: 0x147e38 - 0x147e58
void sub_00147E38_0x147e38(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00147E38_0x147e38");
#endif

    ctx->pc = 0x147e38u;

    // 0x147e38: 0x8c880040  lw          $t0, 0x40($a0)
    ctx->pc = 0x147e38u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x147e3c: 0x8d0200ac  lw          $v0, 0xAC($t0)
    ctx->pc = 0x147e3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 172)));
    // 0x147e40: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x147e40u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x147e44: 0x8d0300b0  lw          $v1, 0xB0($t0)
    ctx->pc = 0x147e44u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 176)));
    // 0x147e48: 0xacc30000  sw          $v1, 0x0($a2)
    ctx->pc = 0x147e48u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 3));
    // 0x147e4c: 0x8d0200b4  lw          $v0, 0xB4($t0)
    ctx->pc = 0x147e4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 180)));
    // 0x147e50: 0x3e00008  jr          $ra
    ctx->pc = 0x147E50u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x147E54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x147E50u;
            // 0x147e54: 0xace20000  sw          $v0, 0x0($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x147E58u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
