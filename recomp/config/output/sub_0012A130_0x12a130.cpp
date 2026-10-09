#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012A130
// Address: 0x12a130 - 0x12a158
void sub_0012A130_0x12a130(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012A130_0x12a130");
#endif

    ctx->pc = 0x12a130u;

    // 0x12a130: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12a130u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12a134: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12a134u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x12a138: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12a138u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12a13c: 0x2463f3c4  addiu       $v1, $v1, -0xC3C
    ctx->pc = 0x12a13cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294964164));
    // 0x12a140: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x12a140u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12a144: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12a144u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12a148: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x12a148u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x12a14c: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x12a14cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x12a150: 0x804cb02  j           func_132C08
    ctx->pc = 0x12A150u;
    ctx->pc = 0x12A154u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A150u;
            // 0x12a154: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x132C08u;
    if (runtime->hasFunction(0x132C08u)) {
        auto targetFn = runtime->lookupFunction(0x132C08u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00132C08_0x132c08(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12A158u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
