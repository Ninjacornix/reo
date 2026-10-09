#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00158518
// Address: 0x158518 - 0x158540
void sub_00158518_0x158518(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00158518_0x158518");
#endif

    ctx->pc = 0x158518u;

    // 0x158518: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x158518u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x15851c: 0xac82001c  sw          $v0, 0x1C($a0)
    ctx->pc = 0x15851cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 2));
    // 0x158520: 0xac820000  sw          $v0, 0x0($a0)
    ctx->pc = 0x158520u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x158524: 0xac820004  sw          $v0, 0x4($a0)
    ctx->pc = 0x158524u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 2));
    // 0x158528: 0xac820008  sw          $v0, 0x8($a0)
    ctx->pc = 0x158528u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 2));
    // 0x15852c: 0xac82000c  sw          $v0, 0xC($a0)
    ctx->pc = 0x15852cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 2));
    // 0x158530: 0xac820010  sw          $v0, 0x10($a0)
    ctx->pc = 0x158530u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 2));
    // 0x158534: 0xac820014  sw          $v0, 0x14($a0)
    ctx->pc = 0x158534u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 2));
    // 0x158538: 0x3e00008  jr          $ra
    ctx->pc = 0x158538u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15853Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158538u;
            // 0x15853c: 0xac820018  sw          $v0, 0x18($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x158540u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
