#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00178F38
// Address: 0x178f38 - 0x178f54
void sub_00178F38_0x178f38(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00178F38_0x178f38");
#endif

    ctx->pc = 0x178f38u;

    // 0x178f38: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x178f38u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x178f3c: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x178f3cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x178f40: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x178f40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x178f44: 0x34a50701  ori         $a1, $a1, 0x701
    ctx->pc = 0x178f44u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1793);
    // 0x178f48: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x178f48u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x178f4c: 0x805a704  j           func_169C10
    ctx->pc = 0x178F4Cu;
    ctx->pc = 0x178F50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178F4Cu;
            // 0x178f50: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x178F54u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
