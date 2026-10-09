#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012A1C8
// Address: 0x12a1c8 - 0x12a1e8
void sub_0012A1C8_0x12a1c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012A1C8_0x12a1c8");
#endif

    switch (ctx->pc) {
        case 0x12a1d8u: goto label_12a1d8;
        default: break;
    }

    ctx->pc = 0x12a1c8u;

    // 0x12a1c8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12a1c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12a1cc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12a1ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12a1d0: 0xc04a808  jal         func_12A020
    ctx->pc = 0x12A1D0u;
    SET_GPR_U32(ctx, 31, 0x12A1D8u);
    ctx->pc = 0x12A020u;
    if (runtime->hasFunction(0x12A020u)) {
        auto targetFn = runtime->lookupFunction(0x12A020u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A1D8u; }
        if (ctx->pc != 0x12A1D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012A020_0x12a020(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A1D8u; }
        if (ctx->pc != 0x12A1D8u) { return; }
    }
    ctx->pc = 0x12A1D8u;
label_12a1d8:
    // 0x12a1d8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12a1d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12a1dc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x12a1dcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a1e0: 0x3e00008  jr          $ra
    ctx->pc = 0x12A1E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12A1E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12A1E0u;
            // 0x12a1e4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12A1D8u: goto label_12a1d8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12A1E8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
