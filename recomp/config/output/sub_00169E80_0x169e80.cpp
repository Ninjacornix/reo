#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00169E80
// Address: 0x169e80 - 0x169ea0
void sub_00169E80_0x169e80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00169E80_0x169e80");
#endif

    switch (ctx->pc) {
        case 0x169e90u: goto label_169e90;
        default: break;
    }

    ctx->pc = 0x169e80u;

    // 0x169e80: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x169e80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x169e84: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x169e84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x169e88: 0xc05c908  jal         func_172420
    ctx->pc = 0x169E88u;
    SET_GPR_U32(ctx, 31, 0x169E90u);
    ctx->pc = 0x172420u;
    if (runtime->hasFunction(0x172420u)) {
        auto targetFn = runtime->lookupFunction(0x172420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169E90u; }
        if (ctx->pc != 0x169E90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00172420_0x172420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169E90u; }
        if (ctx->pc != 0x169E90u) { return; }
    }
    ctx->pc = 0x169E90u;
label_169e90:
    // 0x169e90: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x169e90u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x169e94: 0x805a3ca  j           func_168F28
    ctx->pc = 0x169E94u;
    ctx->pc = 0x169E98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x169E94u;
            // 0x169e98: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x168F28u;
    if (runtime->hasFunction(0x168F28u)) {
        auto targetFn = runtime->lookupFunction(0x168F28u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00168F28_0x168f28(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x169E9Cu;
    // 0x169e9c: 0x0  nop
    ctx->pc = 0x169e9cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
