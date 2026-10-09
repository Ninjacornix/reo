#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B02D0
// Address: 0x1b02d0 - 0x1b0300
void sub_001B02D0_0x1b02d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B02D0_0x1b02d0");
#endif

    switch (ctx->pc) {
        case 0x1b02e0u: goto label_1b02e0;
        default: break;
    }

    ctx->pc = 0x1b02d0u;

    // 0x1b02d0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b02d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b02d4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b02d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b02d8: 0xc06c0c0  jal         func_1B0300
    ctx->pc = 0x1B02D8u;
    SET_GPR_U32(ctx, 31, 0x1B02E0u);
    ctx->pc = 0x1B0300u;
    if (runtime->hasFunction(0x1B0300u)) {
        auto targetFn = runtime->lookupFunction(0x1B0300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B02E0u; }
        if (ctx->pc != 0x1B02E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0300_0x1b0300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B02E0u; }
        if (ctx->pc != 0x1B02E0u) { return; }
    }
    ctx->pc = 0x1B02E0u;
label_1b02e0:
    // 0x1b02e0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b02e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b02e4: 0x401026  xor         $v0, $v0, $zero
    ctx->pc = 0x1b02e4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ GPR_U64(ctx, 0));
    // 0x1b02e8: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x1b02e8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    // 0x1b02ec: 0x3e00008  jr          $ra
    ctx->pc = 0x1B02ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B02F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B02ECu;
            // 0x1b02f0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B02E0u: goto label_1b02e0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B02F4u;
    // 0x1b02f4: 0x0  nop
    ctx->pc = 0x1b02f4u;
    // NOP
    // 0x1b02f8: 0x0  nop
    ctx->pc = 0x1b02f8u;
    // NOP
    // 0x1b02fc: 0x0  nop
    ctx->pc = 0x1b02fcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
