#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00106AB0
// Address: 0x106ab0 - 0x106ad4
void sub_00106AB0_0x106ab0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00106AB0_0x106ab0");
#endif

    ctx->pc = 0x106ab0u;

    // 0x106ab0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x106ab0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x106ab4: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x106ab4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x106ab8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x106ab8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x106abc: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x106abcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106ac0: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x106ac0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106ac4: 0x8c4497f0  lw          $a0, -0x6810($v0)
    ctx->pc = 0x106ac4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294940656)));
    // 0x106ac8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x106ac8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x106acc: 0x8041a84  j           func_106A10
    ctx->pc = 0x106ACCu;
    ctx->pc = 0x106AD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106ACCu;
            // 0x106ad0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x106A10u;
    if (runtime->hasFunction(0x106A10u)) {
        auto targetFn = runtime->lookupFunction(0x106A10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00106A10_0x106a10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x106AD4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
