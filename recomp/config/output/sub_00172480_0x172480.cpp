#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00172480
// Address: 0x172480 - 0x1724a0
void sub_00172480_0x172480(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00172480_0x172480");
#endif

    ctx->pc = 0x172480u;

    // 0x172480: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x172480u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x172484: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x172484u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x172488: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x172488u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17248c: 0x805d766  j           func_175D98
    ctx->pc = 0x17248Cu;
    ctx->pc = 0x172490u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17248Cu;
            // 0x172490: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175D98u;
    if (runtime->hasFunction(0x175D98u)) {
        auto targetFn = runtime->lookupFunction(0x175D98u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00175D98_0x175d98(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x172494u;
    // 0x172494: 0x0  nop
    ctx->pc = 0x172494u;
    // NOP
    // 0x172498: 0x3e00008  jr          $ra
    ctx->pc = 0x172498u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1724A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
