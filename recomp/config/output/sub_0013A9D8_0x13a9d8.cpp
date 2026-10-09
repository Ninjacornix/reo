#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013A9D8
// Address: 0x13a9d8 - 0x13aa00
void sub_0013A9D8_0x13a9d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013A9D8_0x13a9d8");
#endif

    ctx->pc = 0x13a9d8u;

    // 0x13a9d8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13a9d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13a9dc: 0x3c040022  lui         $a0, 0x22
    ctx->pc = 0x13a9dcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)34 << 16));
    // 0x13a9e0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13a9e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13a9e4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13a9e4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13a9e8: 0x2484d8d0  addiu       $a0, $a0, -0x2730
    ctx->pc = 0x13a9e8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957264));
    // 0x13a9ec: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x13a9ecu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x13a9f0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13a9f0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13a9f4: 0x8041f1a  j           func_107C68
    ctx->pc = 0x13A9F4u;
    ctx->pc = 0x13A9F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13A9F4u;
            // 0x13a9f8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107C68_0x107c68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13A9FCu;
    // 0x13a9fc: 0x0  nop
    ctx->pc = 0x13a9fcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
