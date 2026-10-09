#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00133470
// Address: 0x133470 - 0x133484
void sub_00133470_0x133470(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00133470_0x133470");
#endif

    ctx->pc = 0x133470u;

    // 0x133470: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x133470u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x133474: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x133474u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x133478: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x133478u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13347c: 0x804b5c4  j           func_12D710
    ctx->pc = 0x13347Cu;
    ctx->pc = 0x133480u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13347Cu;
            // 0x133480: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D710u;
    if (runtime->hasFunction(0x12D710u)) {
        auto targetFn = runtime->lookupFunction(0x12D710u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0012D710_0x12d710(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x133484u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
