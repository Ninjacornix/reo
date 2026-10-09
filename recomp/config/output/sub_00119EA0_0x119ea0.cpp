#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00119EA0
// Address: 0x119ea0 - 0x119ebc
void sub_00119EA0_0x119ea0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00119EA0_0x119ea0");
#endif

    switch (ctx->pc) {
        case 0x119eb0u: goto label_119eb0;
        default: break;
    }

    ctx->pc = 0x119ea0u;

    // 0x119ea0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x119ea0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x119ea4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x119ea4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x119ea8: 0xc0466ca  jal         func_119B28
    ctx->pc = 0x119EA8u;
    SET_GPR_U32(ctx, 31, 0x119EB0u);
    ctx->pc = 0x119EACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x119EA8u;
            // 0x119eac: 0x24050008  addiu       $a1, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x119B28u;
    if (runtime->hasFunction(0x119B28u)) {
        auto targetFn = runtime->lookupFunction(0x119B28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119EB0u; }
        if (ctx->pc != 0x119EB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00119B28_0x119b28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119EB0u; }
        if (ctx->pc != 0x119EB0u) { return; }
    }
    ctx->pc = 0x119EB0u;
label_119eb0:
    // 0x119eb0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x119eb0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x119eb4: 0x3e00008  jr          $ra
    ctx->pc = 0x119EB4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x119EB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119EB4u;
            // 0x119eb8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x119EB0u: goto label_119eb0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x119EBCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
