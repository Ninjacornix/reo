#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00178C38
// Address: 0x178c38 - 0x178c60
void sub_00178C38_0x178c38(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00178C38_0x178c38");
#endif

    ctx->pc = 0x178c38u;

    // 0x178c38: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x178c38u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x178c3c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x178c3cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178c40: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x178c40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x178c44: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x178c44u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178c48: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x178c48u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178c4c: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x178c4cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178c50: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x178c50u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x178c54: 0x805e318  j           func_178C60
    ctx->pc = 0x178C54u;
    ctx->pc = 0x178C58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178C54u;
            // 0x178c58: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x178C60u;
    if (runtime->hasFunction(0x178C60u)) {
        auto targetFn = runtime->lookupFunction(0x178C60u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00178C60_0x178c60(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x178C5Cu;
    // 0x178c5c: 0x0  nop
    ctx->pc = 0x178c5cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
