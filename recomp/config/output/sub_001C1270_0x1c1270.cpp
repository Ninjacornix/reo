#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C1270
// Address: 0x1c1270 - 0x1c1290
void sub_001C1270_0x1c1270(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C1270_0x1c1270");
#endif

    ctx->pc = 0x1c1270u;

    // 0x1c1270: 0x3c020032  lui         $v0, 0x32
    ctx->pc = 0x1c1270u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)50 << 16));
    // 0x1c1274: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x1c1274u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1c1278: 0x24426c78  addiu       $v0, $v0, 0x6C78
    ctx->pc = 0x1c1278u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 27768));
    // 0x1c127c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1c127cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1c1280: 0x3e00008  jr          $ra
    ctx->pc = 0x1C1280u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C1284u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1280u;
            // 0x1c1284: 0x8c420000  lw          $v0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1C1288u;
    // 0x1c1288: 0x0  nop
    ctx->pc = 0x1c1288u;
    // NOP
    // 0x1c128c: 0x0  nop
    ctx->pc = 0x1c128cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
