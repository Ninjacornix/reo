#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017E418
// Address: 0x17e418 - 0x17e438
void sub_0017E418_0x17e418(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017E418_0x17e418");
#endif

    ctx->pc = 0x17e418u;

    // 0x17e418: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x17e418u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x17e41c: 0x2442f978  addiu       $v0, $v0, -0x688
    ctx->pc = 0x17e41cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294965624));
    // 0x17e420: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x17e420u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x17e424: 0x18600002  blez        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x17E424u;
    {
        const bool branch_taken_0x17e424 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x17E428u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E424u;
            // 0x17e428: 0x2464ffff  addiu       $a0, $v1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e424) {
            ctx->pc = 0x17E430u;
            goto label_17e430;
        }
    }
    ctx->pc = 0x17E42Cu;
    // 0x17e42c: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x17e42cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
label_17e430:
    // 0x17e430: 0x3e00008  jr          $ra
    ctx->pc = 0x17E430u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17E430u: goto label_17e430;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17E438u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
