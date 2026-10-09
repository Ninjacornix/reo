#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001636C8
// Address: 0x1636c8 - 0x1636e8
void sub_001636C8_0x1636c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001636C8_0x1636c8");
#endif

    switch (ctx->pc) {
        case 0x1636d8u: goto label_1636d8;
        default: break;
    }

    ctx->pc = 0x1636c8u;

    // 0x1636c8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1636c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1636cc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1636ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1636d0: 0xc0505cc  jal         func_141730
    ctx->pc = 0x1636D0u;
    SET_GPR_U32(ctx, 31, 0x1636D8u);
    ctx->pc = 0x141730u;
    if (runtime->hasFunction(0x141730u)) {
        auto targetFn = runtime->lookupFunction(0x141730u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1636D8u; }
        if (ctx->pc != 0x1636D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141730_0x141730(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1636D8u; }
        if (ctx->pc != 0x1636D8u) { return; }
    }
    ctx->pc = 0x1636D8u;
label_1636d8:
    // 0x1636d8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1636d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1636dc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1636dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1636e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1636E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1636E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1636E0u;
            // 0x1636e4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1636D8u: goto label_1636d8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1636E8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
