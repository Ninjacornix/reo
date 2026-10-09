#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00192450
// Address: 0x192450 - 0x192480
void sub_00192450_0x192450(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00192450_0x192450");
#endif

    switch (ctx->pc) {
        case 0x192460u: goto label_192460;
        case 0x192474u: goto label_192474;
        default: break;
    }

    ctx->pc = 0x192450u;

    // 0x192450: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x192450u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x192454: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x192454u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x192458: 0xc063728  jal         func_18DCA0
    ctx->pc = 0x192458u;
    SET_GPR_U32(ctx, 31, 0x192460u);
    ctx->pc = 0x18DCA0u;
    if (runtime->hasFunction(0x18DCA0u)) {
        auto targetFn = runtime->lookupFunction(0x18DCA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192460u; }
        if (ctx->pc != 0x192460u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCA0_0x18dca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192460u; }
        if (ctx->pc != 0x192460u) { return; }
    }
    ctx->pc = 0x192460u;
label_192460:
    // 0x192460: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x192460u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x192464: 0xac224168  sw          $v0, 0x4168($at)
    ctx->pc = 0x192464u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 16744), GPR_U32(ctx, 2));
    // 0x192468: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x192468u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19246c: 0xc0638ec  jal         func_18E3B0
    ctx->pc = 0x19246Cu;
    SET_GPR_U32(ctx, 31, 0x192474u);
    ctx->pc = 0x192470u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19246Cu;
            // 0x192470: 0x8c244168  lw          $a0, 0x4168($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16744)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18E3B0u;
    if (runtime->hasFunction(0x18E3B0u)) {
        auto targetFn = runtime->lookupFunction(0x18E3B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192474u; }
        if (ctx->pc != 0x192474u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018E3B0_0x18e3b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192474u; }
        if (ctx->pc != 0x192474u) { return; }
    }
    ctx->pc = 0x192474u;
label_192474:
    // 0x192474: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x192474u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x192478: 0x3e00008  jr          $ra
    ctx->pc = 0x192478u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19247Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192478u;
            // 0x19247c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x192460u: goto label_192460;
            case 0x192474u: goto label_192474;
            default: break;
        }
        return;
    }
    ctx->pc = 0x192480u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
