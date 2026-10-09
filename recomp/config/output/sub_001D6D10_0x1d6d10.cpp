#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D6D10
// Address: 0x1d6d10 - 0x1d6d60
void sub_001D6D10_0x1d6d10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D6D10_0x1d6d10");
#endif

    switch (ctx->pc) {
        case 0x1d6d20u: goto label_1d6d20;
        default: break;
    }

    ctx->pc = 0x1d6d10u;

    // 0x1d6d10: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d6d10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d6d14: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d6d14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d6d18: 0xc076468  jal         func_1D91A0
    ctx->pc = 0x1D6D18u;
    SET_GPR_U32(ctx, 31, 0x1D6D20u);
    ctx->pc = 0x1D91A0u;
    if (runtime->hasFunction(0x1D91A0u)) {
        auto targetFn = runtime->lookupFunction(0x1D91A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6D20u; }
        if (ctx->pc != 0x1D6D20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D91A0_0x1d91a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6D20u; }
        if (ctx->pc != 0x1D6D20u) { return; }
    }
    ctx->pc = 0x1D6D20u;
label_1d6d20:
    // 0x1d6d20: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x1d6d20u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d6d24: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1d6d24u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d6d28: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d6d28u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1d6d2c: 0x10430004  beq         $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D6D2Cu;
    {
        const bool branch_taken_0x1d6d2c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1d6d2c) {
            ctx->pc = 0x1D6D40u;
            goto label_1d6d40;
        }
    }
    ctx->pc = 0x1D6D34u;
    // 0x1d6d34: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1D6D34u;
    {
        const bool branch_taken_0x1d6d34 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d6d34) {
            ctx->pc = 0x1D6D48u;
            goto label_1d6d48;
        }
    }
    ctx->pc = 0x1D6D3Cu;
    // 0x1d6d3c: 0x0  nop
    ctx->pc = 0x1d6d3cu;
    // NOP
label_1d6d40:
    // 0x1d6d40: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1d6d40u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d6d44: 0x0  nop
    ctx->pc = 0x1d6d44u;
    // NOP
label_1d6d48:
    // 0x1d6d48: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d6d48u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d6d4c: 0x3e00008  jr          $ra
    ctx->pc = 0x1D6D4Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D6D50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6D4Cu;
            // 0x1d6d50: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D6D20u: goto label_1d6d20;
            case 0x1D6D40u: goto label_1d6d40;
            case 0x1D6D48u: goto label_1d6d48;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D6D54u;
    // 0x1d6d54: 0x0  nop
    ctx->pc = 0x1d6d54u;
    // NOP
    // 0x1d6d58: 0x0  nop
    ctx->pc = 0x1d6d58u;
    // NOP
    // 0x1d6d5c: 0x0  nop
    ctx->pc = 0x1d6d5cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
