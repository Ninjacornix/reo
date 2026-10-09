#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012D6F8
// Address: 0x12d6f8 - 0x12d710
void sub_0012D6F8_0x12d6f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012D6F8_0x12d6f8");
#endif

    ctx->pc = 0x12d6f8u;

    // 0x12d6f8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12d6f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12d6fc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12d6fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12d700: 0x8c840004  lw          $a0, 0x4($a0)
    ctx->pc = 0x12d700u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x12d704: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12d704u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12d708: 0x80493fc  j           func_124FF0
    ctx->pc = 0x12D708u;
    ctx->pc = 0x12D70Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D708u;
            // 0x12d70c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x124FF0u;
    if (runtime->hasFunction(0x124FF0u)) {
        auto targetFn = runtime->lookupFunction(0x124FF0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00124FF0_0x124ff0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12D710u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
