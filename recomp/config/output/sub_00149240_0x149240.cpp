#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00149240
// Address: 0x149240 - 0x149288
void sub_00149240_0x149240(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00149240_0x149240");
#endif

    switch (ctx->pc) {
        case 0x149250u: goto label_149250;
        default: break;
    }

    ctx->pc = 0x149240u;

    // 0x149240: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x149240u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x149244: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x149244u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x149248: 0xc052482  jal         func_149208
    ctx->pc = 0x149248u;
    SET_GPR_U32(ctx, 31, 0x149250u);
    ctx->pc = 0x149208u;
    if (runtime->hasFunction(0x149208u)) {
        auto targetFn = runtime->lookupFunction(0x149208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x149250u; }
        if (ctx->pc != 0x149250u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00149208_0x149208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x149250u; }
        if (ctx->pc != 0x149250u) { return; }
    }
    ctx->pc = 0x149250u;
label_149250:
    // 0x149250: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x149250u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149254: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x149254u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x149258: 0x3e00008  jr          $ra
    ctx->pc = 0x149258u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x14925Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x149258u;
            // 0x14925c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x149250u: goto label_149250;
            default: break;
        }
        return;
    }
    ctx->pc = 0x149260u;
    // 0x149260: 0x3e00008  jr          $ra
    ctx->pc = 0x149260u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x149250u: goto label_149250;
            default: break;
        }
        return;
    }
    ctx->pc = 0x149268u;
    // 0x149268: 0x3e00008  jr          $ra
    ctx->pc = 0x149268u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x149250u: goto label_149250;
            default: break;
        }
        return;
    }
    ctx->pc = 0x149270u;
    // 0x149270: 0x3e00008  jr          $ra
    ctx->pc = 0x149270u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x149250u: goto label_149250;
            default: break;
        }
        return;
    }
    ctx->pc = 0x149278u;
    // 0x149278: 0x3e00008  jr          $ra
    ctx->pc = 0x149278u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x149250u: goto label_149250;
            default: break;
        }
        return;
    }
    ctx->pc = 0x149280u;
    // 0x149280: 0x3e00008  jr          $ra
    ctx->pc = 0x149280u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x149250u: goto label_149250;
            default: break;
        }
        return;
    }
    ctx->pc = 0x149288u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
