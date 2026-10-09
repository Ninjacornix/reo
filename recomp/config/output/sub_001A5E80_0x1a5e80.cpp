#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A5E80
// Address: 0x1a5e80 - 0x1a5ea4
void sub_001A5E80_0x1a5e80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A5E80_0x1a5e80");
#endif

    switch (ctx->pc) {
        case 0x1a5e90u: goto label_1a5e90;
        case 0x1a5e98u: goto label_1a5e98;
        default: break;
    }

    ctx->pc = 0x1a5e80u;

    // 0x1a5e80: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a5e80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a5e84: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a5e84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a5e88: 0xc06980c  jal         func_1A6030
    ctx->pc = 0x1A5E88u;
    SET_GPR_U32(ctx, 31, 0x1A5E90u);
    ctx->pc = 0x1A6030u;
    if (runtime->hasFunction(0x1A6030u)) {
        auto targetFn = runtime->lookupFunction(0x1A6030u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5E90u; }
        if (ctx->pc != 0x1A5E90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A6030_0x1a6030(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5E90u; }
        if (ctx->pc != 0x1A5E90u) { return; }
    }
    ctx->pc = 0x1A5E90u;
label_1a5e90:
    // 0x1a5e90: 0xc0699c8  jal         func_1A6720
    ctx->pc = 0x1A5E90u;
    SET_GPR_U32(ctx, 31, 0x1A5E98u);
    ctx->pc = 0x1A6720u;
    if (runtime->hasFunction(0x1A6720u)) {
        auto targetFn = runtime->lookupFunction(0x1A6720u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5E98u; }
        if (ctx->pc != 0x1A5E98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A6720_0x1a6720(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5E98u; }
        if (ctx->pc != 0x1A5E98u) { return; }
    }
    ctx->pc = 0x1A5E98u;
label_1a5e98:
    // 0x1a5e98: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a5e98u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a5e9c: 0x3e00008  jr          $ra
    ctx->pc = 0x1A5E9Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A5EA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5E9Cu;
            // 0x1a5ea0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A5E90u: goto label_1a5e90;
            case 0x1A5E98u: goto label_1a5e98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A5EA4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
