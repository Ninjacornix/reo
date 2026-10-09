#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017A7B8
// Address: 0x17a7b8 - 0x17a7d0
void sub_0017A7B8_0x17a7b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017A7B8_0x17a7b8");
#endif

    ctx->pc = 0x17a7b8u;

    // 0x17a7b8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17a7b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17a7bc: 0xc0202d  daddu       $a0, $a2, $zero
    ctx->pc = 0x17a7bcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a7c0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17a7c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17a7c4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17a7c4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17a7c8: 0x8053ef6  j           func_14FBD8
    ctx->pc = 0x17A7C8u;
    ctx->pc = 0x17A7CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17A7C8u;
            // 0x17a7cc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x14FBD8u;
    if (runtime->hasFunction(0x14FBD8u)) {
        auto targetFn = runtime->lookupFunction(0x14FBD8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0014FBD8_0x14fbd8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17A7D0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
