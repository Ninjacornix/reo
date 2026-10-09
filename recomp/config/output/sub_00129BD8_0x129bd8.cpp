#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00129BD8
// Address: 0x129bd8 - 0x129c08
void sub_00129BD8_0x129bd8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00129BD8_0x129bd8");
#endif

    switch (ctx->pc) {
        case 0x129bf0u: goto label_129bf0;
        default: break;
    }

    ctx->pc = 0x129bd8u;

    // 0x129bd8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x129bd8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x129bdc: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x129BDCu;
    {
        const bool branch_taken_0x129bdc = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x129BE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129BDCu;
            // 0x129be0: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129bdc) {
            ctx->pc = 0x129BF8u;
            goto label_129bf8;
        }
    }
    ctx->pc = 0x129BE4u;
    // 0x129be4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x129be4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x129be8: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x129BE8u;
    SET_GPR_U32(ctx, 31, 0x129BF0u);
    ctx->pc = 0x129BECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129BE8u;
            // 0x129bec: 0x2484a158  addiu       $a0, $a0, -0x5EA8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294943064));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129BF0u; }
        if (ctx->pc != 0x129BF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129BF0u; }
        if (ctx->pc != 0x129BF0u) { return; }
    }
    ctx->pc = 0x129BF0u;
label_129bf0:
    // 0x129bf0: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x129BF0u;
    {
        const bool branch_taken_0x129bf0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x129BF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129BF0u;
            // 0x129bf4: 0x2402fffd  addiu       $v0, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129bf0) {
            ctx->pc = 0x129BFCu;
            goto label_129bfc;
        }
    }
    ctx->pc = 0x129BF8u;
label_129bf8:
    // 0x129bf8: 0x8c820014  lw          $v0, 0x14($a0)
    ctx->pc = 0x129bf8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
label_129bfc:
    // 0x129bfc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x129bfcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x129c00: 0x3e00008  jr          $ra
    ctx->pc = 0x129C00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x129C04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129C00u;
            // 0x129c04: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x129BF0u: goto label_129bf0;
            case 0x129BF8u: goto label_129bf8;
            case 0x129BFCu: goto label_129bfc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x129C08u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
