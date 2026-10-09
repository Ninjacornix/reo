#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013E598
// Address: 0x13e598 - 0x13e5c0
void sub_0013E598_0x13e598(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013E598_0x13e598");
#endif

    ctx->pc = 0x13e598u;

    // 0x13e598: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13e598u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13e59c: 0x2404000c  addiu       $a0, $zero, 0xC
    ctx->pc = 0x13e59cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x13e5a0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13e5a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13e5a4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13e5a4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e5a8: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x13e5a8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e5ac: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x13e5acu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e5b0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13e5b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13e5b4: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x13e5b4u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e5b8: 0x804e518  j           func_139460
    ctx->pc = 0x13E5B8u;
    ctx->pc = 0x13E5BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13E5B8u;
            // 0x13e5bc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139460u;
    if (runtime->hasFunction(0x139460u)) {
        auto targetFn = runtime->lookupFunction(0x139460u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00139460_0x139460(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13E5C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
