#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00119CD0
// Address: 0x119cd0 - 0x119cf0
void sub_00119CD0_0x119cd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00119CD0_0x119cd0");
#endif

    switch (ctx->pc) {
        case 0x119ce0u: goto label_119ce0;
        default: break;
    }

    ctx->pc = 0x119cd0u;

    // 0x119cd0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x119cd0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x119cd4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x119cd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x119cd8: 0xc0466ca  jal         func_119B28
    ctx->pc = 0x119CD8u;
    SET_GPR_U32(ctx, 31, 0x119CE0u);
    ctx->pc = 0x119CDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x119CD8u;
            // 0x119cdc: 0x24050006  addiu       $a1, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x119B28u;
    if (runtime->hasFunction(0x119B28u)) {
        auto targetFn = runtime->lookupFunction(0x119B28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119CE0u; }
        if (ctx->pc != 0x119CE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00119B28_0x119b28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119CE0u; }
        if (ctx->pc != 0x119CE0u) { return; }
    }
    ctx->pc = 0x119CE0u;
label_119ce0:
    // 0x119ce0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x119ce0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x119ce4: 0x3e00008  jr          $ra
    ctx->pc = 0x119CE4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x119CE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119CE4u;
            // 0x119ce8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x119CE0u: goto label_119ce0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x119CECu;
    // 0x119cec: 0x0  nop
    ctx->pc = 0x119cecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
