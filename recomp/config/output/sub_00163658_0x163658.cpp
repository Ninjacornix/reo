#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00163658
// Address: 0x163658 - 0x163678
void sub_00163658_0x163658(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00163658_0x163658");
#endif

    switch (ctx->pc) {
        case 0x163668u: goto label_163668;
        default: break;
    }

    ctx->pc = 0x163658u;

    // 0x163658: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x163658u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16365c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x16365cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x163660: 0xc0505c0  jal         func_141700
    ctx->pc = 0x163660u;
    SET_GPR_U32(ctx, 31, 0x163668u);
    ctx->pc = 0x141700u;
    if (runtime->hasFunction(0x141700u)) {
        auto targetFn = runtime->lookupFunction(0x141700u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163668u; }
        if (ctx->pc != 0x163668u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141700_0x141700(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163668u; }
        if (ctx->pc != 0x163668u) { return; }
    }
    ctx->pc = 0x163668u;
label_163668:
    // 0x163668: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x163668u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16366c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x16366cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x163670: 0x3e00008  jr          $ra
    ctx->pc = 0x163670u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x163674u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163670u;
            // 0x163674: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x163668u: goto label_163668;
            default: break;
        }
        return;
    }
    ctx->pc = 0x163678u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
