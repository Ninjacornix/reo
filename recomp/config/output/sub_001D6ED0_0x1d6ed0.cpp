#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D6ED0
// Address: 0x1d6ed0 - 0x1d6f10
void sub_001D6ED0_0x1d6ed0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D6ED0_0x1d6ed0");
#endif

    switch (ctx->pc) {
        case 0x1d6ee0u: goto label_1d6ee0;
        default: break;
    }

    ctx->pc = 0x1d6ed0u;

    // 0x1d6ed0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1d6ed0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1d6ed4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d6ed4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d6ed8: 0xc076294  jal         func_1D8A50
    ctx->pc = 0x1D6ED8u;
    SET_GPR_U32(ctx, 31, 0x1D6EE0u);
    ctx->pc = 0x1D6EDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6ED8u;
            // 0x1d6edc: 0x27a4001c  addiu       $a0, $sp, 0x1C (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 28));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D8A50u;
    if (runtime->hasFunction(0x1D8A50u)) {
        auto targetFn = runtime->lookupFunction(0x1D8A50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6EE0u; }
        if (ctx->pc != 0x1D6EE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D8A50_0x1d8a50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6EE0u; }
        if (ctx->pc != 0x1D6EE0u) { return; }
    }
    ctx->pc = 0x1D6EE0u;
label_1d6ee0:
    // 0x1d6ee0: 0x21c3c  dsll32      $v1, $v0, 16
    ctx->pc = 0x1d6ee0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d6ee4: 0x31c3f  dsra32      $v1, $v1, 16
    ctx->pc = 0x1d6ee4u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 16));
    // 0x1d6ee8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d6ee8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d6eec: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D6EECu;
    {
        const bool branch_taken_0x1d6eec = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1d6eec) {
            ctx->pc = 0x1D6EFCu;
            goto label_1d6efc;
        }
    }
    ctx->pc = 0x1D6EF4u;
    // 0x1d6ef4: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1D6EF4u;
    {
        const bool branch_taken_0x1d6ef4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D6EF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6EF4u;
            // 0x1d6ef8: 0x8fa2001c  lw          $v0, 0x1C($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d6ef4) {
            ctx->pc = 0x1D6F00u;
            goto label_1d6f00;
        }
    }
    ctx->pc = 0x1D6EFCu;
label_1d6efc:
    // 0x1d6efc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1d6efcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1d6f00:
    // 0x1d6f00: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d6f00u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d6f04: 0x3e00008  jr          $ra
    ctx->pc = 0x1D6F04u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D6F08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6F04u;
            // 0x1d6f08: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D6EE0u: goto label_1d6ee0;
            case 0x1D6EFCu: goto label_1d6efc;
            case 0x1D6F00u: goto label_1d6f00;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D6F0Cu;
    // 0x1d6f0c: 0x0  nop
    ctx->pc = 0x1d6f0cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
