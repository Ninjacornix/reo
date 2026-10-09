#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00112440
// Address: 0x112440 - 0x112470
void sub_00112440_0x112440(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00112440_0x112440");
#endif

    switch (ctx->pc) {
        case 0x112460u: goto label_112460;
        default: break;
    }

    ctx->pc = 0x112440u;

    // 0x112440: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x112440u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x112444: 0xafa40000  sw          $a0, 0x0($sp)
    ctx->pc = 0x112444u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 4));
    // 0x112448: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x112448u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11244c: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x11244cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x112450: 0xafa50004  sw          $a1, 0x4($sp)
    ctx->pc = 0x112450u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 5));
    // 0x112454: 0xafa60008  sw          $a2, 0x8($sp)
    ctx->pc = 0x112454u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 6));
    // 0x112458: 0xc04463e  jal         func_1118F8
    ctx->pc = 0x112458u;
    SET_GPR_U32(ctx, 31, 0x112460u);
    ctx->pc = 0x11245Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x112458u;
            // 0x11245c: 0xffa70010  sd          $a3, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 7));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1118F8u;
    if (runtime->hasFunction(0x1118F8u)) {
        auto targetFn = runtime->lookupFunction(0x1118F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x112460u; }
        if (ctx->pc != 0x112460u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001118F8_0x1118f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x112460u; }
        if (ctx->pc != 0x112460u) { return; }
    }
    ctx->pc = 0x112460u;
label_112460:
    // 0x112460: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x112460u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x112464: 0x3e00008  jr          $ra
    ctx->pc = 0x112464u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x112468u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112464u;
            // 0x112468: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x112460u: goto label_112460;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11246Cu;
    // 0x11246c: 0x0  nop
    ctx->pc = 0x11246cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
