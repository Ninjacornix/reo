#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018DC00
// Address: 0x18dc00 - 0x18dc20
void sub_0018DC00_0x18dc00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018DC00_0x18dc00");
#endif

    ctx->pc = 0x18dc00u;

    // 0x18dc00: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x18dc00u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18dc04: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x18dc04u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18dc08: 0x3c04002a  lui         $a0, 0x2A
    ctx->pc = 0x18dc08u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)42 << 16));
    // 0x18dc0c: 0x8062694  j           func_189A50
    ctx->pc = 0x18DC0Cu;
    ctx->pc = 0x18DC10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18DC0Cu;
            // 0x18dc10: 0x2484fe50  addiu       $a0, $a0, -0x1B0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966864));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189A50u;
    if (runtime->hasFunction(0x189A50u)) {
        auto targetFn = runtime->lookupFunction(0x189A50u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00189A50_0x189a50(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x18DC14u;
    // 0x18dc14: 0x0  nop
    ctx->pc = 0x18dc14u;
    // NOP
    // 0x18dc18: 0x0  nop
    ctx->pc = 0x18dc18u;
    // NOP
    // 0x18dc1c: 0x0  nop
    ctx->pc = 0x18dc1cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
