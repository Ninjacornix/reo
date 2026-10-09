#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00164298
// Address: 0x164298 - 0x1642b8
void sub_00164298_0x164298(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00164298_0x164298");
#endif

    switch (ctx->pc) {
        case 0x1642a8u: goto label_1642a8;
        default: break;
    }

    ctx->pc = 0x164298u;

    // 0x164298: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x164298u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16429c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x16429cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1642a0: 0xc05799e  jal         func_15E678
    ctx->pc = 0x1642A0u;
    SET_GPR_U32(ctx, 31, 0x1642A8u);
    ctx->pc = 0x15E678u;
    if (runtime->hasFunction(0x15E678u)) {
        auto targetFn = runtime->lookupFunction(0x15E678u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1642A8u; }
        if (ctx->pc != 0x1642A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E678_0x15e678(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1642A8u; }
        if (ctx->pc != 0x1642A8u) { return; }
    }
    ctx->pc = 0x1642A8u;
label_1642a8:
    // 0x1642a8: 0x8c420054  lw          $v0, 0x54($v0)
    ctx->pc = 0x1642a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 84)));
    // 0x1642ac: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1642acu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1642b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1642B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1642B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1642B0u;
            // 0x1642b4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1642A8u: goto label_1642a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1642B8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
