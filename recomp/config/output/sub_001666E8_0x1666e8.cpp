#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001666E8
// Address: 0x1666e8 - 0x166704
void sub_001666E8_0x1666e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001666E8_0x1666e8");
#endif

    ctx->pc = 0x1666e8u;

    // 0x1666e8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1666e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1666ec: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x1666ecu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x1666f0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1666f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1666f4: 0x34a50a01  ori         $a1, $a1, 0xA01
    ctx->pc = 0x1666f4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)2561);
    // 0x1666f8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1666f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1666fc: 0x805a704  j           func_169C10
    ctx->pc = 0x1666FCu;
    ctx->pc = 0x166700u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1666FCu;
            // 0x166700: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x166704u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
