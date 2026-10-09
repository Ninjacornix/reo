#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013CD10
// Address: 0x13cd10 - 0x13cd38
void sub_0013CD10_0x13cd10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013CD10_0x13cd10");
#endif

    ctx->pc = 0x13cd10u;

    // 0x13cd10: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13cd10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13cd14: 0x3c08000f  lui         $t0, 0xF
    ctx->pc = 0x13cd14u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)15 << 16));
    // 0x13cd18: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13cd18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13cd1c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x13cd1cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13cd20: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x13cd20u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13cd24: 0x3508ffff  ori         $t0, $t0, 0xFFFF
    ctx->pc = 0x13cd24u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | (uint64_t)(uint16_t)65535);
    // 0x13cd28: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13cd28u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13cd2c: 0x804f34e  j           func_13CD38
    ctx->pc = 0x13CD2Cu;
    ctx->pc = 0x13CD30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13CD2Cu;
            // 0x13cd30: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13CD38u;
    if (runtime->hasFunction(0x13CD38u)) {
        auto targetFn = runtime->lookupFunction(0x13CD38u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013CD38_0x13cd38(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13CD34u;
    // 0x13cd34: 0x0  nop
    ctx->pc = 0x13cd34u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
