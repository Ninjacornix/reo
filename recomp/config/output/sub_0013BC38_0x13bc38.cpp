#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013BC38
// Address: 0x13bc38 - 0x13bc50
void sub_0013BC38_0x13bc38(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013BC38_0x13bc38");
#endif

    ctx->pc = 0x13bc38u;

    // 0x13bc38: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13bc38u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13bc3c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13bc3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13bc40: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13bc40u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13bc44: 0x804eccc  j           func_13B330
    ctx->pc = 0x13BC44u;
    ctx->pc = 0x13BC48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13BC44u;
            // 0x13bc48: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13B330u;
    if (runtime->hasFunction(0x13B330u)) {
        auto targetFn = runtime->lookupFunction(0x13B330u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013B330_0x13b330(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13BC4Cu;
    // 0x13bc4c: 0x0  nop
    ctx->pc = 0x13bc4cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
