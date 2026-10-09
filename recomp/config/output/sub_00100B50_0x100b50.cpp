#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00100B50
// Address: 0x100b50 - 0x100b6c
void sub_00100B50_0x100b50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00100B50_0x100b50");
#endif

    switch (ctx->pc) {
        case 0x100b60u: goto label_100b60;
        default: break;
    }

    ctx->pc = 0x100b50u;

    // 0x100b50: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x100b50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x100b54: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x100b54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x100b58: 0xc04020e  jal         func_100838
    ctx->pc = 0x100B58u;
    SET_GPR_U32(ctx, 31, 0x100B60u);
    ctx->pc = 0x100B5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100B58u;
            // 0x100b5c: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x100838u;
    if (runtime->hasFunction(0x100838u)) {
        auto targetFn = runtime->lookupFunction(0x100838u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100B60u; }
        if (ctx->pc != 0x100B60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00100838_0x100838(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100B60u; }
        if (ctx->pc != 0x100B60u) { return; }
    }
    ctx->pc = 0x100B60u;
label_100b60:
    // 0x100b60: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x100b60u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x100b64: 0x3e00008  jr          $ra
    ctx->pc = 0x100B64u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x100B68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100B64u;
            // 0x100b68: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x100B60u: goto label_100b60;
            default: break;
        }
        return;
    }
    ctx->pc = 0x100B6Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
