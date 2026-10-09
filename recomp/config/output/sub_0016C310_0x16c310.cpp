#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016C310
// Address: 0x16c310 - 0x16c330
void sub_0016C310_0x16c310(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016C310_0x16c310");
#endif

    switch (ctx->pc) {
        case 0x16c320u: goto label_16c320;
        default: break;
    }

    ctx->pc = 0x16c310u;

    // 0x16c310: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x16c310u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16c314: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x16c314u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x16c318: 0xc056d1e  jal         func_15B478
    ctx->pc = 0x16C318u;
    SET_GPR_U32(ctx, 31, 0x16C320u);
    ctx->pc = 0x15B478u;
    if (runtime->hasFunction(0x15B478u)) {
        auto targetFn = runtime->lookupFunction(0x15B478u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C320u; }
        if (ctx->pc != 0x16C320u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B478_0x15b478(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C320u; }
        if (ctx->pc != 0x16C320u) { return; }
    }
    ctx->pc = 0x16C320u;
label_16c320:
    // 0x16c320: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x16c320u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16c324: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x16c324u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c328: 0x3e00008  jr          $ra
    ctx->pc = 0x16C328u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16C32Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16C328u;
            // 0x16c32c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16C320u: goto label_16c320;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16C330u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
