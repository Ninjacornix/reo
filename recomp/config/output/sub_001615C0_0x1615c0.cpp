#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001615C0
// Address: 0x1615c0 - 0x1615d8
void sub_001615C0_0x1615c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001615C0_0x1615c0");
#endif

    ctx->pc = 0x1615c0u;

    // 0x1615c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1615c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1615c4: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1615c4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1615c8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1615c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1615cc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1615ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1615d0: 0x80585a2  j           func_161688
    ctx->pc = 0x1615D0u;
    ctx->pc = 0x1615D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1615D0u;
            // 0x1615d4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x161688u;
    if (runtime->hasFunction(0x161688u)) {
        auto targetFn = runtime->lookupFunction(0x161688u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00161688_0x161688(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1615D8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
