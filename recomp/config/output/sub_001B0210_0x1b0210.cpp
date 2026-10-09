#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B0210
// Address: 0x1b0210 - 0x1b0240
void sub_001B0210_0x1b0210(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B0210_0x1b0210");
#endif

    switch (ctx->pc) {
        case 0x1b0220u: goto label_1b0220;
        case 0x1b0234u: goto label_1b0234;
        default: break;
    }

    ctx->pc = 0x1b0210u;

    // 0x1b0210: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b0210u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b0214: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b0214u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b0218: 0xc06c0c0  jal         func_1B0300
    ctx->pc = 0x1B0218u;
    SET_GPR_U32(ctx, 31, 0x1B0220u);
    ctx->pc = 0x1B0300u;
    if (runtime->hasFunction(0x1B0300u)) {
        auto targetFn = runtime->lookupFunction(0x1B0300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0220u; }
        if (ctx->pc != 0x1B0220u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0300_0x1b0300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0220u; }
        if (ctx->pc != 0x1B0220u) { return; }
    }
    ctx->pc = 0x1B0220u;
label_1b0220:
    // 0x1b0220: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1b0220u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b0224: 0x14430003  bne         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B0224u;
    {
        const bool branch_taken_0x1b0224 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1b0224) {
            ctx->pc = 0x1B0234u;
            goto label_1b0234;
        }
    }
    ctx->pc = 0x1B022Cu;
    // 0x1b022c: 0xc204afc  jal         func_812BF0
    ctx->pc = 0x1B022Cu;
    SET_GPR_U32(ctx, 31, 0x1B0234u);
    ctx->pc = 0x812BF0u;
    {
        auto targetFn = runtime->lookupFunction(0x812BF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0234u; }
        if (ctx->pc != 0x1B0234u) { return; }
    }
    ctx->pc = 0x1B0234u;
label_1b0234:
    // 0x1b0234: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b0234u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b0238: 0x3e00008  jr          $ra
    ctx->pc = 0x1B0238u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B023Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0238u;
            // 0x1b023c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B0220u: goto label_1b0220;
            case 0x1B0234u: goto label_1b0234;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B0240u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
