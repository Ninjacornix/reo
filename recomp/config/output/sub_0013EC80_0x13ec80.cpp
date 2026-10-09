#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013EC80
// Address: 0x13ec80 - 0x13ec9c
void sub_0013EC80_0x13ec80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013EC80_0x13ec80");
#endif

    ctx->pc = 0x13ec80u;

    // 0x13ec80: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13ec80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13ec84: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13ec84u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13ec88: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13ec88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13ec8c: 0x2484d870  addiu       $a0, $a0, -0x2790
    ctx->pc = 0x13ec8cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957168));
    // 0x13ec90: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13ec90u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13ec94: 0x8045a12  j           func_116848
    ctx->pc = 0x13EC94u;
    ctx->pc = 0x13EC98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13EC94u;
            // 0x13ec98: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00116848_0x116848(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13EC9Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
