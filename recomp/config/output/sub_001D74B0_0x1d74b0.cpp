#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D74B0
// Address: 0x1d74b0 - 0x1d7500
void sub_001D74B0_0x1d74b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D74B0_0x1d74b0");
#endif

    switch (ctx->pc) {
        case 0x1d74c0u: goto label_1d74c0;
        default: break;
    }

    ctx->pc = 0x1d74b0u;

    // 0x1d74b0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d74b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d74b4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d74b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d74b8: 0xc0760bc  jal         func_1D82F0
    ctx->pc = 0x1D74B8u;
    SET_GPR_U32(ctx, 31, 0x1D74C0u);
    ctx->pc = 0x1D82F0u;
    if (runtime->hasFunction(0x1D82F0u)) {
        auto targetFn = runtime->lookupFunction(0x1D82F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D74C0u; }
        if (ctx->pc != 0x1D74C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D82F0_0x1d82f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D74C0u; }
        if (ctx->pc != 0x1D74C0u) { return; }
    }
    ctx->pc = 0x1D74C0u;
label_1d74c0:
    // 0x1d74c0: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x1d74c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d74c4: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d74c4u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1d74c8: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D74C8u;
    {
        const bool branch_taken_0x1d74c8 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1d74c8) {
            ctx->pc = 0x1D74D8u;
            goto label_1d74d8;
        }
    }
    ctx->pc = 0x1D74D0u;
    // 0x1d74d0: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1D74D0u;
    {
        const bool branch_taken_0x1d74d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D74D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D74D0u;
            // 0x1d74d4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d74d0) {
            ctx->pc = 0x1D74E8u;
            goto label_1d74e8;
        }
    }
    ctx->pc = 0x1D74D8u;
label_1d74d8:
    // 0x1d74d8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1d74d8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d74dc: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d74dcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d74e0: 0xa0234605  sb          $v1, 0x4605($at)
    ctx->pc = 0x1d74e0u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17925), (uint8_t)GPR_U32(ctx, 3));
    // 0x1d74e4: 0x0  nop
    ctx->pc = 0x1d74e4u;
    // NOP
label_1d74e8:
    // 0x1d74e8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d74e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d74ec: 0x3e00008  jr          $ra
    ctx->pc = 0x1D74ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D74F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D74ECu;
            // 0x1d74f0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D74C0u: goto label_1d74c0;
            case 0x1D74D8u: goto label_1d74d8;
            case 0x1D74E8u: goto label_1d74e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D74F4u;
    // 0x1d74f4: 0x0  nop
    ctx->pc = 0x1d74f4u;
    // NOP
    // 0x1d74f8: 0x0  nop
    ctx->pc = 0x1d74f8u;
    // NOP
    // 0x1d74fc: 0x0  nop
    ctx->pc = 0x1d74fcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
