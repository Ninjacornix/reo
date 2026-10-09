#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D6CC0
// Address: 0x1d6cc0 - 0x1d6d10
void sub_001D6CC0_0x1d6cc0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D6CC0_0x1d6cc0");
#endif

    switch (ctx->pc) {
        case 0x1d6cd0u: goto label_1d6cd0;
        default: break;
    }

    ctx->pc = 0x1d6cc0u;

    // 0x1d6cc0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d6cc0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d6cc4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d6cc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d6cc8: 0xc07644c  jal         func_1D9130
    ctx->pc = 0x1D6CC8u;
    SET_GPR_U32(ctx, 31, 0x1D6CD0u);
    ctx->pc = 0x1D9130u;
    if (runtime->hasFunction(0x1D9130u)) {
        auto targetFn = runtime->lookupFunction(0x1D9130u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6CD0u; }
        if (ctx->pc != 0x1D6CD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9130_0x1d9130(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6CD0u; }
        if (ctx->pc != 0x1D6CD0u) { return; }
    }
    ctx->pc = 0x1D6CD0u;
label_1d6cd0:
    // 0x1d6cd0: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x1d6cd0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d6cd4: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1d6cd4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d6cd8: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d6cd8u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1d6cdc: 0x10430004  beq         $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D6CDCu;
    {
        const bool branch_taken_0x1d6cdc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1d6cdc) {
            ctx->pc = 0x1D6CF0u;
            goto label_1d6cf0;
        }
    }
    ctx->pc = 0x1D6CE4u;
    // 0x1d6ce4: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1D6CE4u;
    {
        const bool branch_taken_0x1d6ce4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d6ce4) {
            ctx->pc = 0x1D6CF8u;
            goto label_1d6cf8;
        }
    }
    ctx->pc = 0x1D6CECu;
    // 0x1d6cec: 0x0  nop
    ctx->pc = 0x1d6cecu;
    // NOP
label_1d6cf0:
    // 0x1d6cf0: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1d6cf0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d6cf4: 0x0  nop
    ctx->pc = 0x1d6cf4u;
    // NOP
label_1d6cf8:
    // 0x1d6cf8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d6cf8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d6cfc: 0x3e00008  jr          $ra
    ctx->pc = 0x1D6CFCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D6D00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6CFCu;
            // 0x1d6d00: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D6CD0u: goto label_1d6cd0;
            case 0x1D6CF0u: goto label_1d6cf0;
            case 0x1D6CF8u: goto label_1d6cf8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D6D04u;
    // 0x1d6d04: 0x0  nop
    ctx->pc = 0x1d6d04u;
    // NOP
    // 0x1d6d08: 0x0  nop
    ctx->pc = 0x1d6d08u;
    // NOP
    // 0x1d6d0c: 0x0  nop
    ctx->pc = 0x1d6d0cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
