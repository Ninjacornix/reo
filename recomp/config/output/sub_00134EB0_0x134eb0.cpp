#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00134EB0
// Address: 0x134eb0 - 0x134ed8
void sub_00134EB0_0x134eb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00134EB0_0x134eb0");
#endif

    ctx->pc = 0x134eb0u;

    // 0x134eb0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x134eb0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x134eb4: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x134eb4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x134eb8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x134eb8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x134ebc: 0x24470032  addiu       $a3, $v0, 0x32
    ctx->pc = 0x134ebcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 2), 50));
    // 0x134ec0: 0xc0202d  daddu       $a0, $a2, $zero
    ctx->pc = 0x134ec0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x134ec4: 0x24460030  addiu       $a2, $v0, 0x30
    ctx->pc = 0x134ec4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 48));
    // 0x134ec8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x134ec8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x134ecc: 0x8049944  j           func_126510
    ctx->pc = 0x134ECCu;
    ctx->pc = 0x134ED0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134ECCu;
            // 0x134ed0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x126510u;
    if (runtime->hasFunction(0x126510u)) {
        auto targetFn = runtime->lookupFunction(0x126510u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00126510_0x126510(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x134ED4u;
    // 0x134ed4: 0x0  nop
    ctx->pc = 0x134ed4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
