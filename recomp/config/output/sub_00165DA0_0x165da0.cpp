#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00165DA0
// Address: 0x165da0 - 0x165dd8
void sub_00165DA0_0x165da0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00165DA0_0x165da0");
#endif

    switch (ctx->pc) {
        case 0x165dc8u: goto label_165dc8;
        default: break;
    }

    ctx->pc = 0x165da0u;

    // 0x165da0: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x165da0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x165da4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x165da4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165da8: 0x3e00008  jr          $ra
    ctx->pc = 0x165DA8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x165DACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165DA8u;
            // 0x165dac: 0xac64f188  sw          $a0, -0xE78($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 4294963592), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x165DC8u: goto label_165dc8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x165DB0u;
    // 0x165db0: 0x3e00008  jr          $ra
    ctx->pc = 0x165DB0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x165DB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165DB0u;
            // 0x165db4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x165DC8u: goto label_165dc8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x165DB8u;
    // 0x165db8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x165db8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x165dbc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x165dbcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x165dc0: 0xc0597bc  jal         func_165EF0
    ctx->pc = 0x165DC0u;
    SET_GPR_U32(ctx, 31, 0x165DC8u);
    ctx->pc = 0x165DC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165DC0u;
            // 0x165dc4: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x165EF0u;
    if (runtime->hasFunction(0x165EF0u)) {
        auto targetFn = runtime->lookupFunction(0x165EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165DC8u; }
        if (ctx->pc != 0x165DC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00165EF0_0x165ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165DC8u; }
        if (ctx->pc != 0x165DC8u) { return; }
    }
    ctx->pc = 0x165DC8u;
label_165dc8:
    // 0x165dc8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x165dc8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x165dcc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x165dccu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165dd0: 0x3e00008  jr          $ra
    ctx->pc = 0x165DD0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x165DD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165DD0u;
            // 0x165dd4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x165DC8u: goto label_165dc8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x165DD8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
