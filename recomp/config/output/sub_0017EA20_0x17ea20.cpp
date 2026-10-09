#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017EA20
// Address: 0x17ea20 - 0x17ea44
void sub_0017EA20_0x17ea20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017EA20_0x17ea20");
#endif

    switch (ctx->pc) {
        case 0x17ea38u: goto label_17ea38;
        default: break;
    }

    ctx->pc = 0x17ea20u;

    // 0x17ea20: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x17ea20u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x17ea24: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17ea24u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17ea28: 0xdc45f980  ld          $a1, -0x680($v0)
    ctx->pc = 0x17ea28u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 2), 4294965632)));
    // 0x17ea2c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17ea2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17ea30: 0xc043ec6  jal         func_10FB18
    ctx->pc = 0x17EA30u;
    SET_GPR_U32(ctx, 31, 0x17EA38u);
    ctx->pc = 0x10FB18u;
    if (runtime->hasFunction(0x10FB18u)) {
        auto targetFn = runtime->lookupFunction(0x10FB18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17EA38u; }
        if (ctx->pc != 0x17EA38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FB18_0x10fb18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17EA38u; }
        if (ctx->pc != 0x17EA38u) { return; }
    }
    ctx->pc = 0x17EA38u;
label_17ea38:
    // 0x17ea38: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17ea38u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17ea3c: 0x3e00008  jr          $ra
    ctx->pc = 0x17EA3Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17EA40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17EA3Cu;
            // 0x17ea40: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17EA38u: goto label_17ea38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17EA44u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
