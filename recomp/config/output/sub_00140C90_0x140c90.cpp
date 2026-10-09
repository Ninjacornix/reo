#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00140C90
// Address: 0x140c90 - 0x140cc0
void sub_00140C90_0x140c90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00140C90_0x140c90");
#endif

    ctx->pc = 0x140c90u;

    // 0x140c90: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x140c90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x140c94: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x140c94u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
    // 0x140c98: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x140c98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x140c9c: 0x24a54600  addiu       $a1, $a1, 0x4600
    ctx->pc = 0x140c9cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 17920));
    // 0x140ca0: 0xaca40000  sw          $a0, 0x0($a1)
    ctx->pc = 0x140ca0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 4));
    // 0x140ca4: 0x24040025  addiu       $a0, $zero, 0x25
    ctx->pc = 0x140ca4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 37));
    // 0x140ca8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x140ca8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x140cac: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x140cacu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x140cb0: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x140cb0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140cb4: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x140cb4u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140cb8: 0x804e518  j           func_139460
    ctx->pc = 0x140CB8u;
    ctx->pc = 0x140CBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x140CB8u;
            // 0x140cbc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139460u;
    if (runtime->hasFunction(0x139460u)) {
        auto targetFn = runtime->lookupFunction(0x139460u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00139460_0x139460(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x140CC0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
