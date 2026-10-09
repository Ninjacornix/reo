#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00164728
// Address: 0x164728 - 0x164740
void sub_00164728_0x164728(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00164728_0x164728");
#endif

    ctx->pc = 0x164728u;

    // 0x164728: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x164728u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16472c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x16472cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x164730: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x164730u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x164734: 0x804c16e  j           func_1305B8
    ctx->pc = 0x164734u;
    ctx->pc = 0x164738u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164734u;
            // 0x164738: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1305B8u;
    if (runtime->hasFunction(0x1305B8u)) {
        auto targetFn = runtime->lookupFunction(0x1305B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001305B8_0x1305b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16473Cu;
    // 0x16473c: 0x0  nop
    ctx->pc = 0x16473cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
