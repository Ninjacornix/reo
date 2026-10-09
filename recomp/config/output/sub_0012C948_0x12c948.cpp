#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012C948
// Address: 0x12c948 - 0x12c978
void sub_0012C948_0x12c948(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012C948_0x12c948");
#endif

    switch (ctx->pc) {
        case 0x12c958u: goto label_12c958;
        default: break;
    }

    ctx->pc = 0x12c948u;

    // 0x12c948: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c948u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c94c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12c94cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c950: 0xc0491e8  jal         func_1247A0
    ctx->pc = 0x12C950u;
    SET_GPR_U32(ctx, 31, 0x12C958u);
    ctx->pc = 0x1247A0u;
    if (runtime->hasFunction(0x1247A0u)) {
        auto targetFn = runtime->lookupFunction(0x1247A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C958u; }
        if (ctx->pc != 0x12C958u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001247A0_0x1247a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C958u; }
        if (ctx->pc != 0x12C958u) { return; }
    }
    ctx->pc = 0x12C958u;
label_12c958:
    // 0x12c958: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12c958u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c95c: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x12c95cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x12c960: 0x24847d88  addiu       $a0, $a0, 0x7D88
    ctx->pc = 0x12c960u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 32136));
    // 0x12c964: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12c964u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12c968: 0x240609c0  addiu       $a2, $zero, 0x9C0
    ctx->pc = 0x12c968u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2496));
    // 0x12c96c: 0x8041f1a  j           func_107C68
    ctx->pc = 0x12C96Cu;
    ctx->pc = 0x12C970u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C96Cu;
            // 0x12c970: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107C68_0x107c68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12C974u;
    // 0x12c974: 0x0  nop
    ctx->pc = 0x12c974u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
