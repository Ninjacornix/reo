#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00164368
// Address: 0x164368 - 0x1643b0
void sub_00164368_0x164368(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00164368_0x164368");
#endif

    switch (ctx->pc) {
        case 0x164378u: goto label_164378;
        case 0x164398u: goto label_164398;
        default: break;
    }

    ctx->pc = 0x164368u;

    // 0x164368: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x164368u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16436c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x16436cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x164370: 0xc05799e  jal         func_15E678
    ctx->pc = 0x164370u;
    SET_GPR_U32(ctx, 31, 0x164378u);
    ctx->pc = 0x15E678u;
    if (runtime->hasFunction(0x15E678u)) {
        auto targetFn = runtime->lookupFunction(0x15E678u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164378u; }
        if (ctx->pc != 0x164378u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E678_0x15e678(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164378u; }
        if (ctx->pc != 0x164378u) { return; }
    }
    ctx->pc = 0x164378u;
label_164378:
    // 0x164378: 0x8c420024  lw          $v0, 0x24($v0)
    ctx->pc = 0x164378u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 36)));
    // 0x16437c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x16437cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x164380: 0x3e00008  jr          $ra
    ctx->pc = 0x164380u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x164384u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164380u;
            // 0x164384: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x164378u: goto label_164378;
            case 0x164398u: goto label_164398;
            default: break;
        }
        return;
    }
    ctx->pc = 0x164388u;
    // 0x164388: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x164388u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16438c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x16438cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x164390: 0xc0590a6  jal         func_164298
    ctx->pc = 0x164390u;
    SET_GPR_U32(ctx, 31, 0x164398u);
    ctx->pc = 0x164298u;
    if (runtime->hasFunction(0x164298u)) {
        auto targetFn = runtime->lookupFunction(0x164298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164398u; }
        if (ctx->pc != 0x164398u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00164298_0x164298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164398u; }
        if (ctx->pc != 0x164398u) { return; }
    }
    ctx->pc = 0x164398u;
label_164398:
    // 0x164398: 0x38420001  xori        $v0, $v0, 0x1
    ctx->pc = 0x164398u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
    // 0x16439c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x16439cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1643a0: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x1643a0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1643a4: 0x3e00008  jr          $ra
    ctx->pc = 0x1643A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1643A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1643A4u;
            // 0x1643a8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x164378u: goto label_164378;
            case 0x164398u: goto label_164398;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1643ACu;
    // 0x1643ac: 0x0  nop
    ctx->pc = 0x1643acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
