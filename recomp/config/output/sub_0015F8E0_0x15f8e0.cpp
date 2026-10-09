#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015F8E0
// Address: 0x15f8e0 - 0x15f900
void sub_0015F8E0_0x15f8e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015F8E0_0x15f8e0");
#endif

    switch (ctx->pc) {
        case 0x15f8f0u: goto label_15f8f0;
        default: break;
    }

    ctx->pc = 0x15f8e0u;

    // 0x15f8e0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15f8e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15f8e4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15f8e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15f8e8: 0xc057e74  jal         func_15F9D0
    ctx->pc = 0x15F8E8u;
    SET_GPR_U32(ctx, 31, 0x15F8F0u);
    ctx->pc = 0x15F8ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F8E8u;
            // 0x15f8ec: 0x24040008  addiu       $a0, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15F9D0u;
    if (runtime->hasFunction(0x15F9D0u)) {
        auto targetFn = runtime->lookupFunction(0x15F9D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F8F0u; }
        if (ctx->pc != 0x15F8F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015F9D0_0x15f9d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F8F0u; }
        if (ctx->pc != 0x15F8F0u) { return; }
    }
    ctx->pc = 0x15F8F0u;
label_15f8f0:
    // 0x15f8f0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15f8f0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f8f4: 0x24040009  addiu       $a0, $zero, 0x9
    ctx->pc = 0x15f8f4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x15f8f8: 0x8057e74  j           func_15F9D0
    ctx->pc = 0x15F8F8u;
    ctx->pc = 0x15F8FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F8F8u;
            // 0x15f8fc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15F9D0u;
    if (runtime->hasFunction(0x15F9D0u)) {
        auto targetFn = runtime->lookupFunction(0x15F9D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0015F9D0_0x15f9d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15F900u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
