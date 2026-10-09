#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010A710
// Address: 0x10a710 - 0x10a730
void sub_0010A710_0x10a710(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010A710_0x10a710");
#endif

    ctx->pc = 0x10a710u;

    // 0x10a710: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x10a710u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x10a714: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x10a714u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x10a718: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x10a718u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x10a71c: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x10a71cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a720: 0x8c4497f0  lw          $a0, -0x6810($v0)
    ctx->pc = 0x10a720u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294940656)));
    // 0x10a724: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x10a724u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x10a728: 0x8042984  j           func_10A610
    ctx->pc = 0x10A728u;
    ctx->pc = 0x10A72Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10A728u;
            // 0x10a72c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A610u;
    if (runtime->hasFunction(0x10A610u)) {
        auto targetFn = runtime->lookupFunction(0x10A610u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0010A610_0x10a610(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x10A730u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
