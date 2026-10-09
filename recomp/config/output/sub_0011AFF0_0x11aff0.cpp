#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011AFF0
// Address: 0x11aff0 - 0x11b00c
void sub_0011AFF0_0x11aff0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011AFF0_0x11aff0");
#endif

    switch (ctx->pc) {
        case 0x11b000u: goto label_11b000;
        default: break;
    }

    ctx->pc = 0x11aff0u;

    // 0x11aff0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x11aff0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x11aff4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x11aff4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x11aff8: 0xc0466ca  jal         func_119B28
    ctx->pc = 0x11AFF8u;
    SET_GPR_U32(ctx, 31, 0x11B000u);
    ctx->pc = 0x11AFFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11AFF8u;
            // 0x11affc: 0x24050015  addiu       $a1, $zero, 0x15 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
        ctx->in_delay_slot = false;
    ctx->pc = 0x119B28u;
    if (runtime->hasFunction(0x119B28u)) {
        auto targetFn = runtime->lookupFunction(0x119B28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B000u; }
        if (ctx->pc != 0x11B000u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00119B28_0x119b28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B000u; }
        if (ctx->pc != 0x11B000u) { return; }
    }
    ctx->pc = 0x11B000u;
label_11b000:
    // 0x11b000: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x11b000u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11b004: 0x3e00008  jr          $ra
    ctx->pc = 0x11B004u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11B008u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B004u;
            // 0x11b008: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11B000u: goto label_11b000;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11B00Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
