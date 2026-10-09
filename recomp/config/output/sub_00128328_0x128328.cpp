#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00128328
// Address: 0x128328 - 0x128348
void sub_00128328_0x128328(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00128328_0x128328");
#endif

    ctx->pc = 0x128328u;

    // 0x128328: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x128328u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12832c: 0x852821  addu        $a1, $a0, $a1
    ctx->pc = 0x12832cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x128330: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x128330u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x128334: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x128334u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x128338: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x128338u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12833c: 0x8045416  j           func_115058
    ctx->pc = 0x12833Cu;
    ctx->pc = 0x128340u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12833Cu;
            // 0x128340: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x115058u;
    if (runtime->hasFunction(0x115058u)) {
        auto targetFn = runtime->lookupFunction(0x115058u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00115058_0x115058(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x128344u;
    // 0x128344: 0x0  nop
    ctx->pc = 0x128344u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
