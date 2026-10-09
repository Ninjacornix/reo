#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001300C8
// Address: 0x1300c8 - 0x130100
void sub_001300C8_0x1300c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001300C8_0x1300c8");
#endif

    switch (ctx->pc) {
        case 0x1300e4u: goto label_1300e4;
        default: break;
    }

    ctx->pc = 0x1300c8u;

    // 0x1300c8: 0x3c040022  lui         $a0, 0x22
    ctx->pc = 0x1300c8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)34 << 16));
    // 0x1300cc: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1300ccu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1300d0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1300d0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1300d4: 0x2484a8c0  addiu       $a0, $a0, -0x5740
    ctx->pc = 0x1300d4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294944960));
    // 0x1300d8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1300d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1300dc: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1300DCu;
    SET_GPR_U32(ctx, 31, 0x1300E4u);
    ctx->pc = 0x1300E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1300DCu;
            // 0x1300e0: 0x24060e60  addiu       $a2, $zero, 0xE60 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3680));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1300E4u; }
        if (ctx->pc != 0x1300E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1300E4u; }
        if (ctx->pc != 0x1300E4u) { return; }
    }
    ctx->pc = 0x1300E4u;
label_1300e4:
    // 0x1300e4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1300e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1300e8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1300e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1300ec: 0x3e00008  jr          $ra
    ctx->pc = 0x1300ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1300F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1300ECu;
            // 0x1300f0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1300E4u: goto label_1300e4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1300F4u;
    // 0x1300f4: 0x0  nop
    ctx->pc = 0x1300f4u;
    // NOP
    // 0x1300f8: 0x3e00008  jr          $ra
    ctx->pc = 0x1300F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1300E4u: goto label_1300e4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x130100u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
