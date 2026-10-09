#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013C7C0
// Address: 0x13c7c0 - 0x13c7e8
void sub_0013C7C0_0x13c7c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013C7C0_0x13c7c0");
#endif

    ctx->pc = 0x13c7c0u;

    // 0x13c7c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13c7c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13c7c4: 0x3c040022  lui         $a0, 0x22
    ctx->pc = 0x13c7c4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)34 << 16));
    // 0x13c7c8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13c7c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13c7cc: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13c7ccu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c7d0: 0x2484de90  addiu       $a0, $a0, -0x2170
    ctx->pc = 0x13c7d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294958736));
    // 0x13c7d4: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x13c7d4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x13c7d8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13c7d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13c7dc: 0x8041f1a  j           func_107C68
    ctx->pc = 0x13C7DCu;
    ctx->pc = 0x13C7E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C7DCu;
            // 0x13c7e0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107C68_0x107c68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13C7E4u;
    // 0x13c7e4: 0x0  nop
    ctx->pc = 0x13c7e4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
