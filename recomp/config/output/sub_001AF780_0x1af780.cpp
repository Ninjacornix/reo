#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AF780
// Address: 0x1af780 - 0x1af790
void sub_001AF780_0x1af780(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AF780_0x1af780");
#endif

    ctx->pc = 0x1af780u;

    // 0x1af780: 0x8065804  j           func_196010
    ctx->pc = 0x1AF780u;
    ctx->pc = 0x1AF784u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF780u;
            // 0x1af784: 0x308400ff  andi        $a0, $a0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
    ctx->pc = 0x196010u;
    if (runtime->hasFunction(0x196010u)) {
        auto targetFn = runtime->lookupFunction(0x196010u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00196010_0x196010(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1AF788u;
    // 0x1af788: 0x0  nop
    ctx->pc = 0x1af788u;
    // NOP
    // 0x1af78c: 0x0  nop
    ctx->pc = 0x1af78cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
