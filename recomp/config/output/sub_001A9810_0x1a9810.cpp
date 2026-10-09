#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A9810
// Address: 0x1a9810 - 0x1a9838
void sub_001A9810_0x1a9810(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A9810_0x1a9810");
#endif

    switch (ctx->pc) {
        case 0x1a9820u: goto label_1a9820;
        default: break;
    }

    ctx->pc = 0x1a9810u;

    // 0x1a9810: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a9810u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a9814: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a9814u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a9818: 0xc06a568  jal         func_1A95A0
    ctx->pc = 0x1A9818u;
    SET_GPR_U32(ctx, 31, 0x1A9820u);
    ctx->pc = 0x1A981Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9818u;
            // 0x1a981c: 0x24040006  addiu       $a0, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A95A0u;
    if (runtime->hasFunction(0x1A95A0u)) {
        auto targetFn = runtime->lookupFunction(0x1A95A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9820u; }
        if (ctx->pc != 0x1A9820u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A95A0_0x1a95a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9820u; }
        if (ctx->pc != 0x1A9820u) { return; }
    }
    ctx->pc = 0x1A9820u;
label_1a9820:
    // 0x1a9820: 0x24030006  addiu       $v1, $zero, 0x6
    ctx->pc = 0x1a9820u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1a9824: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1a9824u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1a9828: 0xa023448a  sb          $v1, 0x448A($at)
    ctx->pc = 0x1a9828u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17546), (uint8_t)GPR_U32(ctx, 3));
    // 0x1a982c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a982cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a9830: 0x3e00008  jr          $ra
    ctx->pc = 0x1A9830u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A9834u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9830u;
            // 0x1a9834: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A9820u: goto label_1a9820;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A9838u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
