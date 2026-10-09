#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00177A30
// Address: 0x177a30 - 0x177a50
void sub_00177A30_0x177a30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00177A30_0x177a30");
#endif

    ctx->pc = 0x177a30u;

    // 0x177a30: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x177a30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x177a34: 0x24050007  addiu       $a1, $zero, 0x7
    ctx->pc = 0x177a34u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x177a38: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x177a38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x177a3c: 0x24060008  addiu       $a2, $zero, 0x8
    ctx->pc = 0x177a3cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x177a40: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x177a40u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x177a44: 0x805dec4  j           func_177B10
    ctx->pc = 0x177A44u;
    ctx->pc = 0x177A48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x177A44u;
            // 0x177a48: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177B10u;
    if (runtime->hasFunction(0x177B10u)) {
        auto targetFn = runtime->lookupFunction(0x177B10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00177B10_0x177b10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x177A4Cu;
    // 0x177a4c: 0x0  nop
    ctx->pc = 0x177a4cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
