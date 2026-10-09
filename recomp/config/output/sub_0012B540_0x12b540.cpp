#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012B540
// Address: 0x12b540 - 0x12b554
void sub_0012B540_0x12b540(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012B540_0x12b540");
#endif

    ctx->pc = 0x12b540u;

    // 0x12b540: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12b540u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12b544: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12b544u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12b548: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12b548u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12b54c: 0x80507ea  j           func_141FA8
    ctx->pc = 0x12B54Cu;
    ctx->pc = 0x12B550u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12B54Cu;
            // 0x12b550: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141FA8u;
    if (runtime->hasFunction(0x141FA8u)) {
        auto targetFn = runtime->lookupFunction(0x141FA8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00141FA8_0x141fa8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12B554u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
