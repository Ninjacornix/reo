#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001416E8
// Address: 0x1416e8 - 0x141700
void sub_001416E8_0x1416e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001416E8_0x1416e8");
#endif

    ctx->pc = 0x1416e8u;

    // 0x1416e8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1416e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1416ec: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1416ecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1416f0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1416f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1416f4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1416f4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1416f8: 0x8050590  j           func_141640
    ctx->pc = 0x1416F8u;
    ctx->pc = 0x1416FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1416F8u;
            // 0x1416fc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141640u;
    if (runtime->hasFunction(0x141640u)) {
        auto targetFn = runtime->lookupFunction(0x141640u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00141640_0x141640(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x141700u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
