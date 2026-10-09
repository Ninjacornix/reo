#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012D710
// Address: 0x12d710 - 0x12d724
void sub_0012D710_0x12d710(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012D710_0x12d710");
#endif

    ctx->pc = 0x12d710u;

    // 0x12d710: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12d710u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12d714: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12d714u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12d718: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12d718u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12d71c: 0x8049416  j           func_125058
    ctx->pc = 0x12D71Cu;
    ctx->pc = 0x12D720u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D71Cu;
            // 0x12d720: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x125058u;
    if (runtime->hasFunction(0x125058u)) {
        auto targetFn = runtime->lookupFunction(0x125058u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00125058_0x125058(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12D724u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
