#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00165D80
// Address: 0x165d80 - 0x165da0
void sub_00165D80_0x165d80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00165D80_0x165d80");
#endif

    switch (ctx->pc) {
        case 0x165d90u: goto label_165d90;
        default: break;
    }

    ctx->pc = 0x165d80u;

    // 0x165d80: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x165d80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x165d84: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x165d84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x165d88: 0xc04c646  jal         func_131918
    ctx->pc = 0x165D88u;
    SET_GPR_U32(ctx, 31, 0x165D90u);
    ctx->pc = 0x131918u;
    if (runtime->hasFunction(0x131918u)) {
        auto targetFn = runtime->lookupFunction(0x131918u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165D90u; }
        if (ctx->pc != 0x165D90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00131918_0x131918(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165D90u; }
        if (ctx->pc != 0x165D90u) { return; }
    }
    ctx->pc = 0x165D90u;
label_165d90:
    // 0x165d90: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x165d90u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x165d94: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x165d94u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165d98: 0x3e00008  jr          $ra
    ctx->pc = 0x165D98u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x165D9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165D98u;
            // 0x165d9c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x165D90u: goto label_165d90;
            default: break;
        }
        return;
    }
    ctx->pc = 0x165DA0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
