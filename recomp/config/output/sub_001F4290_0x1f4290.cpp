#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F4290
// Address: 0x1f4290 - 0x1f42bc
void sub_001F4290_0x1f4290(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F4290_0x1f4290");
#endif

    switch (ctx->pc) {
        case 0x1f42acu: goto label_1f42ac;
        default: break;
    }

    ctx->pc = 0x1f4290u;

    // 0x1f4290: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1f4290u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1f4294: 0x3c040036  lui         $a0, 0x36
    ctx->pc = 0x1f4294u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)54 << 16));
    // 0x1f4298: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1f4298u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1f429c: 0x2484eb00  addiu       $a0, $a0, -0x1500
    ctx->pc = 0x1f429cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294961920));
    // 0x1f42a0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1f42a0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f42a4: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1F42A4u;
    SET_GPR_U32(ctx, 31, 0x1F42ACu);
    ctx->pc = 0x1F42A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F42A4u;
            // 0x1f42a8: 0x24060094  addiu       $a2, $zero, 0x94 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 148));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F42ACu; }
        if (ctx->pc != 0x1F42ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F42ACu; }
        if (ctx->pc != 0x1F42ACu) { return; }
    }
    ctx->pc = 0x1F42ACu;
label_1f42ac:
    // 0x1f42ac: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1f42acu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f42b0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f42b0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f42b4: 0x3e00008  jr          $ra
    ctx->pc = 0x1F42B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F42B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F42B4u;
            // 0x1f42b8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F42ACu: goto label_1f42ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F42BCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
