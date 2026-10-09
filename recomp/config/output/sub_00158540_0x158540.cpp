#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00158540
// Address: 0x158540 - 0x158568
void sub_00158540_0x158540(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00158540_0x158540");
#endif

    ctx->pc = 0x158540u;

    // 0x158540: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x158540u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x158544: 0xac82001c  sw          $v0, 0x1C($a0)
    ctx->pc = 0x158544u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 2));
    // 0x158548: 0xac820000  sw          $v0, 0x0($a0)
    ctx->pc = 0x158548u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x15854c: 0xac820004  sw          $v0, 0x4($a0)
    ctx->pc = 0x15854cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 2));
    // 0x158550: 0xac820008  sw          $v0, 0x8($a0)
    ctx->pc = 0x158550u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 2));
    // 0x158554: 0xac82000c  sw          $v0, 0xC($a0)
    ctx->pc = 0x158554u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 2));
    // 0x158558: 0xac820010  sw          $v0, 0x10($a0)
    ctx->pc = 0x158558u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 2));
    // 0x15855c: 0xac820014  sw          $v0, 0x14($a0)
    ctx->pc = 0x15855cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 2));
    // 0x158560: 0x3e00008  jr          $ra
    ctx->pc = 0x158560u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x158564u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158560u;
            // 0x158564: 0xac820018  sw          $v0, 0x18($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x158568u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
