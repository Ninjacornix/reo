#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00132D60
// Address: 0x132d60 - 0x132d90
void sub_00132D60_0x132d60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00132D60_0x132d60");
#endif

    switch (ctx->pc) {
        case 0x132d78u: goto label_132d78;
        default: break;
    }

    ctx->pc = 0x132d60u;

    // 0x132d60: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x132d60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x132d64: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x132D64u;
    {
        const bool branch_taken_0x132d64 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x132D68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132D64u;
            // 0x132d68: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132d64) {
            ctx->pc = 0x132D80u;
            goto label_132d80;
        }
    }
    ctx->pc = 0x132D6Cu;
    // 0x132d6c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x132d6cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x132d70: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x132D70u;
    SET_GPR_U32(ctx, 31, 0x132D78u);
    ctx->pc = 0x132D74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132D70u;
            // 0x132d74: 0x2484b3c0  addiu       $a0, $a0, -0x4C40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294947776));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132D78u; }
        if (ctx->pc != 0x132D78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132D78u; }
        if (ctx->pc != 0x132D78u) { return; }
    }
    ctx->pc = 0x132D78u;
label_132d78:
    // 0x132d78: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x132D78u;
    {
        const bool branch_taken_0x132d78 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x132D7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132D78u;
            // 0x132d7c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132d78) {
            ctx->pc = 0x132D84u;
            goto label_132d84;
        }
    }
    ctx->pc = 0x132D80u;
label_132d80:
    // 0x132d80: 0x8c82004c  lw          $v0, 0x4C($a0)
    ctx->pc = 0x132d80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 76)));
label_132d84:
    // 0x132d84: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x132d84u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x132d88: 0x3e00008  jr          $ra
    ctx->pc = 0x132D88u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x132D8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132D88u;
            // 0x132d8c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x132D78u: goto label_132d78;
            case 0x132D80u: goto label_132d80;
            case 0x132D84u: goto label_132d84;
            default: break;
        }
        return;
    }
    ctx->pc = 0x132D90u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
