#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016FC80
// Address: 0x16fc80 - 0x16fca0
void sub_0016FC80_0x16fc80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016FC80_0x16fc80");
#endif

    ctx->pc = 0x16fc80u;

    // 0x16fc80: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x16fc80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16fc84: 0x2405ffff  addiu       $a1, $zero, -0x1
    ctx->pc = 0x16fc84u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x16fc88: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x16fc88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x16fc8c: 0x24060015  addiu       $a2, $zero, 0x15
    ctx->pc = 0x16fc8cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
    // 0x16fc90: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x16fc90u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16fc94: 0x80558b4  j           func_1562D0
    ctx->pc = 0x16FC94u;
    ctx->pc = 0x16FC98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16FC94u;
            // 0x16fc98: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1562D0u;
    if (runtime->hasFunction(0x1562D0u)) {
        auto targetFn = runtime->lookupFunction(0x1562D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001562D0_0x1562d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16FC9Cu;
    // 0x16fc9c: 0x0  nop
    ctx->pc = 0x16fc9cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
