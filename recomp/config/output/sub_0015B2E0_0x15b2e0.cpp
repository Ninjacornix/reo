#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015B2E0
// Address: 0x15b2e0 - 0x15b328
void sub_0015B2E0_0x15b2e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015B2E0_0x15b2e0");
#endif

    switch (ctx->pc) {
        case 0x15b300u: goto label_15b300;
        default: break;
    }

    ctx->pc = 0x15b2e0u;

    // 0x15b2e0: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x15b2e0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x15b2e4: 0x24424c70  addiu       $v0, $v0, 0x4C70
    ctx->pc = 0x15b2e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 19568));
    // 0x15b2e8: 0x8c440054  lw          $a0, 0x54($v0)
    ctx->pc = 0x15b2e8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 84)));
    // 0x15b2ec: 0x1880000b  blez        $a0, . + 4 + (0xB << 2)
    ctx->pc = 0x15B2ECu;
    {
        const bool branch_taken_0x15b2ec = (GPR_S64(ctx, 4) <= 0);
        ctx->pc = 0x15B2F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15B2ECu;
            // 0x15b2f0: 0x8c430058  lw          $v1, 0x58($v0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 88)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15b2ec) {
            ctx->pc = 0x15B31Cu;
            goto label_15b31c;
        }
    }
    ctx->pc = 0x15B2F4u;
    // 0x15b2f4: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x15b2f4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15b2f8: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x15b2f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15b2fc: 0x0  nop
    ctx->pc = 0x15b2fcu;
    // NOP
label_15b300:
    // 0x15b300: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x15b300u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x15b304: 0xac640188  sw          $a0, 0x188($v1)
    ctx->pc = 0x15b304u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 392), GPR_U32(ctx, 4));
    // 0x15b308: 0x0  nop
    ctx->pc = 0x15b308u;
    // NOP
    // 0x15b30c: 0x0  nop
    ctx->pc = 0x15b30cu;
    // NOP
    // 0x15b310: 0x0  nop
    ctx->pc = 0x15b310u;
    // NOP
    // 0x15b314: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x15B314u;
    {
        const bool branch_taken_0x15b314 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15B318u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15B314u;
            // 0x15b318: 0x246303e0  addiu       $v1, $v1, 0x3E0 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 992));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15b314) {
            ctx->pc = 0x15B300u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_15b300;
        }
    }
    ctx->pc = 0x15B31Cu;
label_15b31c:
    // 0x15b31c: 0x3e00008  jr          $ra
    ctx->pc = 0x15B31Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15B300u: goto label_15b300;
            case 0x15B31Cu: goto label_15b31c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15B324u;
    // 0x15b324: 0x0  nop
    ctx->pc = 0x15b324u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
