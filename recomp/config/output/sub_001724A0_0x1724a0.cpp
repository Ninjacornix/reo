#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001724A0
// Address: 0x1724a0 - 0x1724c8
void sub_001724A0_0x1724a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001724A0_0x1724a0");
#endif

    ctx->pc = 0x1724a0u;

    // 0x1724a0: 0x8c830048  lw          $v1, 0x48($a0)
    ctx->pc = 0x1724a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 72)));
    // 0x1724a4: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1724a4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1724a8: 0x2c630004  sltiu       $v1, $v1, 0x4
    ctx->pc = 0x1724a8u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)4) ? 1 : 0);
    // 0x1724ac: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1724ACu;
    {
        const bool branch_taken_0x1724ac = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1724B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1724ACu;
            // 0x1724b0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1724ac) {
            ctx->pc = 0x1724BCu;
            goto label_1724bc;
        }
    }
    ctx->pc = 0x1724B4u;
    // 0x1724b4: 0x8c820044  lw          $v0, 0x44($a0)
    ctx->pc = 0x1724b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 68)));
    // 0x1724b8: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x1724b8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
label_1724bc:
    // 0x1724bc: 0x3e00008  jr          $ra
    ctx->pc = 0x1724BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1724BCu: goto label_1724bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1724C4u;
    // 0x1724c4: 0x0  nop
    ctx->pc = 0x1724c4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
