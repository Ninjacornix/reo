#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00116E08
// Address: 0x116e08 - 0x116e48
void sub_00116E08_0x116e08(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00116E08_0x116e08");
#endif

    switch (ctx->pc) {
        case 0x116e38u: goto label_116e38;
        default: break;
    }

    ctx->pc = 0x116e08u;

    // 0x116e08: 0xc0102d  daddu       $v0, $a2, $zero
    ctx->pc = 0x116e08u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116e0c: 0xe0182d  daddu       $v1, $a3, $zero
    ctx->pc = 0x116e0cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116e10: 0x100582d  daddu       $t3, $t0, $zero
    ctx->pc = 0x116e10u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116e14: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x116e14u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x116e18: 0x120502d  daddu       $t2, $t1, $zero
    ctx->pc = 0x116e18u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116e1c: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x116e1cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116e20: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x116e20u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x116e24: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x116e24u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116e28: 0x60402d  daddu       $t0, $v1, $zero
    ctx->pc = 0x116e28u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116e2c: 0x160482d  daddu       $t1, $t3, $zero
    ctx->pc = 0x116e2cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116e30: 0xc045b34  jal         func_116CD0
    ctx->pc = 0x116E30u;
    SET_GPR_U32(ctx, 31, 0x116E38u);
    ctx->pc = 0x116E34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x116E30u;
            // 0x116e34: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116CD0u;
    if (runtime->hasFunction(0x116CD0u)) {
        auto targetFn = runtime->lookupFunction(0x116CD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116E38u; }
        if (ctx->pc != 0x116E38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116CD0_0x116cd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116E38u; }
        if (ctx->pc != 0x116E38u) { return; }
    }
    ctx->pc = 0x116E38u;
label_116e38:
    // 0x116e38: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x116e38u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x116e3c: 0x3e00008  jr          $ra
    ctx->pc = 0x116E3Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x116E40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116E3Cu;
            // 0x116e40: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x116E38u: goto label_116e38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x116E44u;
    // 0x116e44: 0x0  nop
    ctx->pc = 0x116e44u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
