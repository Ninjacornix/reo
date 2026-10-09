#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D7360
// Address: 0x1d7360 - 0x1d7390
void sub_001D7360_0x1d7360(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D7360_0x1d7360");
#endif

    switch (ctx->pc) {
        case 0x1d7370u: goto label_1d7370;
        default: break;
    }

    ctx->pc = 0x1d7360u;

    // 0x1d7360: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d7360u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d7364: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d7364u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d7368: 0xc076310  jal         func_1D8C40
    ctx->pc = 0x1D7368u;
    SET_GPR_U32(ctx, 31, 0x1D7370u);
    ctx->pc = 0x1D8C40u;
    if (runtime->hasFunction(0x1D8C40u)) {
        auto targetFn = runtime->lookupFunction(0x1D8C40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7370u; }
        if (ctx->pc != 0x1D7370u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D8C40_0x1d8c40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7370u; }
        if (ctx->pc != 0x1D7370u) { return; }
    }
    ctx->pc = 0x1D7370u;
label_1d7370:
    // 0x1d7370: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d7370u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d7374: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x1d7374u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d7378: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d7378u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1d737c: 0x3e00008  jr          $ra
    ctx->pc = 0x1D737Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D7380u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D737Cu;
            // 0x1d7380: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D7370u: goto label_1d7370;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D7384u;
    // 0x1d7384: 0x0  nop
    ctx->pc = 0x1d7384u;
    // NOP
    // 0x1d7388: 0x0  nop
    ctx->pc = 0x1d7388u;
    // NOP
    // 0x1d738c: 0x0  nop
    ctx->pc = 0x1d738cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
