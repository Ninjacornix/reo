#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00134D90
// Address: 0x134d90 - 0x134db8
void sub_00134D90_0x134d90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00134D90_0x134d90");
#endif

    ctx->pc = 0x134d90u;

    // 0x134d90: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x134d90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x134d94: 0x3c040022  lui         $a0, 0x22
    ctx->pc = 0x134d94u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)34 << 16));
    // 0x134d98: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x134d98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x134d9c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x134d9cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x134da0: 0x2484b7b8  addiu       $a0, $a0, -0x4848
    ctx->pc = 0x134da0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948792));
    // 0x134da4: 0x240603c0  addiu       $a2, $zero, 0x3C0
    ctx->pc = 0x134da4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 960));
    // 0x134da8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x134da8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x134dac: 0x8041f1a  j           func_107C68
    ctx->pc = 0x134DACu;
    ctx->pc = 0x134DB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134DACu;
            // 0x134db0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107C68_0x107c68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x134DB4u;
    // 0x134db4: 0x0  nop
    ctx->pc = 0x134db4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
