#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AFF60
// Address: 0x1aff60 - 0x1aff90
void sub_001AFF60_0x1aff60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AFF60_0x1aff60");
#endif

    switch (ctx->pc) {
        case 0x1aff70u: goto label_1aff70;
        case 0x1aff84u: goto label_1aff84;
        default: break;
    }

    ctx->pc = 0x1aff60u;

    // 0x1aff60: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1aff60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1aff64: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1aff64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1aff68: 0xc06c0c0  jal         func_1B0300
    ctx->pc = 0x1AFF68u;
    SET_GPR_U32(ctx, 31, 0x1AFF70u);
    ctx->pc = 0x1B0300u;
    if (runtime->hasFunction(0x1B0300u)) {
        auto targetFn = runtime->lookupFunction(0x1B0300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFF70u; }
        if (ctx->pc != 0x1AFF70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0300_0x1b0300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFF70u; }
        if (ctx->pc != 0x1AFF70u) { return; }
    }
    ctx->pc = 0x1AFF70u;
label_1aff70:
    // 0x1aff70: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1aff70u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1aff74: 0x14430003  bne         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AFF74u;
    {
        const bool branch_taken_0x1aff74 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1aff74) {
            ctx->pc = 0x1AFF84u;
            goto label_1aff84;
        }
    }
    ctx->pc = 0x1AFF7Cu;
    // 0x1aff7c: 0xc2043d0  jal         func_810F40
    ctx->pc = 0x1AFF7Cu;
    SET_GPR_U32(ctx, 31, 0x1AFF84u);
    ctx->pc = 0x810F40u;
    {
        auto targetFn = runtime->lookupFunction(0x810F40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFF84u; }
        if (ctx->pc != 0x1AFF84u) { return; }
    }
    ctx->pc = 0x1AFF84u;
label_1aff84:
    // 0x1aff84: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1aff84u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1aff88: 0x3e00008  jr          $ra
    ctx->pc = 0x1AFF88u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AFF8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFF88u;
            // 0x1aff8c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AFF70u: goto label_1aff70;
            case 0x1AFF84u: goto label_1aff84;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AFF90u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
