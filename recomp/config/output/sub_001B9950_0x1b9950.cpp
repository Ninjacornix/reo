#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B9950
// Address: 0x1b9950 - 0x1b9970
void sub_001B9950_0x1b9950(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B9950_0x1b9950");
#endif

    ctx->pc = 0x1b9950u;

    // 0x1b9950: 0x3c04003c  lui         $a0, 0x3C
    ctx->pc = 0x1b9950u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)60 << 16));
    // 0x1b9954: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b9954u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9958: 0x24842750  addiu       $a0, $a0, 0x2750
    ctx->pc = 0x1b9958u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 10064));
    // 0x1b995c: 0x8041f1a  j           func_107C68
    ctx->pc = 0x1B995Cu;
    ctx->pc = 0x1B9960u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B995Cu;
            // 0x1b9960: 0x240600f0  addiu       $a2, $zero, 0xF0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 240));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107C68_0x107c68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1B9964u;
    // 0x1b9964: 0x0  nop
    ctx->pc = 0x1b9964u;
    // NOP
    // 0x1b9968: 0x0  nop
    ctx->pc = 0x1b9968u;
    // NOP
    // 0x1b996c: 0x0  nop
    ctx->pc = 0x1b996cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
