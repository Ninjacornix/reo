#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00164998
// Address: 0x164998 - 0x1649c0
void sub_00164998_0x164998(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00164998_0x164998");
#endif

    switch (ctx->pc) {
        case 0x1649a8u: goto label_1649a8;
        case 0x1649b0u: goto label_1649b0;
        default: break;
    }

    ctx->pc = 0x164998u;

    // 0x164998: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x164998u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16499c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x16499cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1649a0: 0xc04b24c  jal         func_12C930
    ctx->pc = 0x1649A0u;
    SET_GPR_U32(ctx, 31, 0x1649A8u);
    ctx->pc = 0x12C930u;
    if (runtime->hasFunction(0x12C930u)) {
        auto targetFn = runtime->lookupFunction(0x12C930u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1649A8u; }
        if (ctx->pc != 0x1649A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C930_0x12c930(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1649A8u; }
        if (ctx->pc != 0x1649A8u) { return; }
    }
    ctx->pc = 0x1649A8u;
label_1649a8:
    // 0x1649a8: 0xc04a8e2  jal         func_12A388
    ctx->pc = 0x1649A8u;
    SET_GPR_U32(ctx, 31, 0x1649B0u);
    ctx->pc = 0x12A388u;
    if (runtime->hasFunction(0x12A388u)) {
        auto targetFn = runtime->lookupFunction(0x12A388u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1649B0u; }
        if (ctx->pc != 0x1649B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012A388_0x12a388(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1649B0u; }
        if (ctx->pc != 0x1649B0u) { return; }
    }
    ctx->pc = 0x1649B0u;
label_1649b0:
    // 0x1649b0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1649b0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1649b4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1649b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1649b8: 0x3e00008  jr          $ra
    ctx->pc = 0x1649B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1649BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1649B8u;
            // 0x1649bc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1649A8u: goto label_1649a8;
            case 0x1649B0u: goto label_1649b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1649C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
