#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011A250
// Address: 0x11a250 - 0x11a26c
void sub_0011A250_0x11a250(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011A250_0x11a250");
#endif

    switch (ctx->pc) {
        case 0x11a260u: goto label_11a260;
        default: break;
    }

    ctx->pc = 0x11a250u;

    // 0x11a250: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x11a250u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x11a254: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x11a254u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x11a258: 0xc0466ca  jal         func_119B28
    ctx->pc = 0x11A258u;
    SET_GPR_U32(ctx, 31, 0x11A260u);
    ctx->pc = 0x11A25Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A258u;
            // 0x11a25c: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x119B28u;
    if (runtime->hasFunction(0x119B28u)) {
        auto targetFn = runtime->lookupFunction(0x119B28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A260u; }
        if (ctx->pc != 0x11A260u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00119B28_0x119b28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A260u; }
        if (ctx->pc != 0x11A260u) { return; }
    }
    ctx->pc = 0x11A260u;
label_11a260:
    // 0x11a260: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x11a260u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11a264: 0x3e00008  jr          $ra
    ctx->pc = 0x11A264u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11A268u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11A264u;
            // 0x11a268: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11A260u: goto label_11a260;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11A26Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
