#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00170980
// Address: 0x170980 - 0x1709a0
void sub_00170980_0x170980(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00170980_0x170980");
#endif

    ctx->pc = 0x170980u;

    // 0x170980: 0x10800004  beqz        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x170980u;
    {
        const bool branch_taken_0x170980 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x170984u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x170980u;
            // 0x170984: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x170980) {
            ctx->pc = 0x170994u;
            goto label_170994;
        }
    }
    ctx->pc = 0x170988u;
    // 0x170988: 0x8c83000c  lw          $v1, 0xC($a0)
    ctx->pc = 0x170988u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x17098c: 0x8ca2000c  lw          $v0, 0xC($a1)
    ctx->pc = 0x17098cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 12)));
    // 0x170990: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x170990u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
label_170994:
    // 0x170994: 0x3e00008  jr          $ra
    ctx->pc = 0x170994u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x170994u: goto label_170994;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17099Cu;
    // 0x17099c: 0x0  nop
    ctx->pc = 0x17099cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
