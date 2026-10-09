#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012AB38
// Address: 0x12ab38 - 0x12ab60
void sub_0012AB38_0x12ab38(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012AB38_0x12ab38");
#endif

    ctx->pc = 0x12ab38u;

    // 0x12ab38: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12ab38u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12ab3c: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12ab3cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12ab40: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12ab40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12ab44: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12ab44u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x12ab48: 0x244204ec  addiu       $v0, $v0, 0x4EC
    ctx->pc = 0x12ab48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1260));
    // 0x12ab4c: 0x8c650478  lw          $a1, 0x478($v1)
    ctx->pc = 0x12ab4cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 1144)));
    // 0x12ab50: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x12ab50u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x12ab54: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12ab54u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12ab58: 0x804aa98  j           func_12AA60
    ctx->pc = 0x12AB58u;
    ctx->pc = 0x12AB5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12AB58u;
            // 0x12ab5c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12AA60u;
    if (runtime->hasFunction(0x12AA60u)) {
        auto targetFn = runtime->lookupFunction(0x12AA60u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0012AA60_0x12aa60(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12AB60u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
