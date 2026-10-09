#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011C510
// Address: 0x11c510 - 0x11c52c
void sub_0011C510_0x11c510(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011C510_0x11c510");
#endif

    switch (ctx->pc) {
        case 0x11c520u: goto label_11c520;
        default: break;
    }

    ctx->pc = 0x11c510u;

    // 0x11c510: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x11c510u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x11c514: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x11c514u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x11c518: 0xc046fd0  jal         func_11BF40
    ctx->pc = 0x11C518u;
    SET_GPR_U32(ctx, 31, 0x11C520u);
    ctx->pc = 0x11C51Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11C518u;
            // 0x11c51c: 0x3a0382d  daddu       $a3, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11BF40u;
    if (runtime->hasFunction(0x11BF40u)) {
        auto targetFn = runtime->lookupFunction(0x11BF40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C520u; }
        if (ctx->pc != 0x11C520u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011BF40_0x11bf40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C520u; }
        if (ctx->pc != 0x11C520u) { return; }
    }
    ctx->pc = 0x11C520u;
label_11c520:
    // 0x11c520: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x11c520u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11c524: 0x3e00008  jr          $ra
    ctx->pc = 0x11C524u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11C528u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C524u;
            // 0x11c528: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11C520u: goto label_11c520;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11C52Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
