#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D7630
// Address: 0x1d7630 - 0x1d7660
void sub_001D7630_0x1d7630(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D7630_0x1d7630");
#endif

    switch (ctx->pc) {
        case 0x1d7640u: goto label_1d7640;
        default: break;
    }

    ctx->pc = 0x1d7630u;

    // 0x1d7630: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d7630u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d7634: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d7634u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d7638: 0xc076360  jal         func_1D8D80
    ctx->pc = 0x1D7638u;
    SET_GPR_U32(ctx, 31, 0x1D7640u);
    ctx->pc = 0x1D763Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7638u;
            // 0x1d763c: 0x24a60004  addiu       $a2, $a1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D8D80u;
    if (runtime->hasFunction(0x1D8D80u)) {
        auto targetFn = runtime->lookupFunction(0x1D8D80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7640u; }
        if (ctx->pc != 0x1D7640u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D8D80_0x1d8d80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7640u; }
        if (ctx->pc != 0x1D7640u) { return; }
    }
    ctx->pc = 0x1D7640u;
label_1d7640:
    // 0x1d7640: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d7640u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d7644: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x1d7644u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d7648: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d7648u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1d764c: 0x3e00008  jr          $ra
    ctx->pc = 0x1D764Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D7650u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D764Cu;
            // 0x1d7650: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D7640u: goto label_1d7640;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D7654u;
    // 0x1d7654: 0x0  nop
    ctx->pc = 0x1d7654u;
    // NOP
    // 0x1d7658: 0x0  nop
    ctx->pc = 0x1d7658u;
    // NOP
    // 0x1d765c: 0x0  nop
    ctx->pc = 0x1d765cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
