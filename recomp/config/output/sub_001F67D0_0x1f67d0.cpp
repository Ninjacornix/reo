#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F67D0
// Address: 0x1f67d0 - 0x1f67f8
void sub_001F67D0_0x1f67d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F67D0_0x1f67d0");
#endif

    ctx->pc = 0x1f67d0u;

    // 0x1f67d0: 0x8c850024  lw          $a1, 0x24($a0)
    ctx->pc = 0x1f67d0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 36)));
    // 0x1f67d4: 0x24030012  addiu       $v1, $zero, 0x12
    ctx->pc = 0x1f67d4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x1f67d8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1f67d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1f67dc: 0xa0830001  sb          $v1, 0x1($a0)
    ctx->pc = 0x1f67dcu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 1), (uint8_t)GPR_U32(ctx, 3));
    // 0x1f67e0: 0x80a30006  lb          $v1, 0x6($a1)
    ctx->pc = 0x1f67e0u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 6)));
    // 0x1f67e4: 0x14620002  bne         $v1, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1F67E4u;
    {
        const bool branch_taken_0x1f67e4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1F67E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F67E4u;
            // 0x1f67e8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f67e4) {
            ctx->pc = 0x1F67F0u;
            goto label_1f67f0;
        }
    }
    ctx->pc = 0x1F67ECu;
    // 0x1f67ec: 0x2402ffc5  addiu       $v0, $zero, -0x3B
    ctx->pc = 0x1f67ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967237));
label_1f67f0:
    // 0x1f67f0: 0x3e00008  jr          $ra
    ctx->pc = 0x1F67F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F67F0u: goto label_1f67f0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F67F8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
