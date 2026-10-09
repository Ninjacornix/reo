#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00155EF0
// Address: 0x155ef0 - 0x155f04
void sub_00155EF0_0x155ef0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00155EF0_0x155ef0");
#endif

    ctx->pc = 0x155ef0u;

    // 0x155ef0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x155ef0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x155ef4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x155ef4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x155ef8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x155ef8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x155efc: 0x80557a4  j           func_155E90
    ctx->pc = 0x155EFCu;
    ctx->pc = 0x155F00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x155EFCu;
            // 0x155f00: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155E90u;
    if (runtime->hasFunction(0x155E90u)) {
        auto targetFn = runtime->lookupFunction(0x155E90u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00155E90_0x155e90(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x155F04u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
