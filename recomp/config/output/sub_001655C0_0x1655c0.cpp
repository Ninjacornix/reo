#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001655C0
// Address: 0x1655c0 - 0x1655e0
void sub_001655C0_0x1655c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001655C0_0x1655c0");
#endif

    switch (ctx->pc) {
        case 0x1655d4u: goto label_1655d4;
        default: break;
    }

    ctx->pc = 0x1655c0u;

    // 0x1655c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1655c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1655c4: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x1655c4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1655c8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1655c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1655cc: 0xc059c38  jal         func_1670E0
    ctx->pc = 0x1655CCu;
    SET_GPR_U32(ctx, 31, 0x1655D4u);
    ctx->pc = 0x1655D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1655CCu;
            // 0x1655d0: 0x8c851b7c  lw          $a1, 0x1B7C($a0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 7036)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1670E0u;
    if (runtime->hasFunction(0x1670E0u)) {
        auto targetFn = runtime->lookupFunction(0x1670E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1655D4u; }
        if (ctx->pc != 0x1655D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001670E0_0x1670e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1655D4u; }
        if (ctx->pc != 0x1655D4u) { return; }
    }
    ctx->pc = 0x1655D4u;
label_1655d4:
    // 0x1655d4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1655d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1655d8: 0x3e00008  jr          $ra
    ctx->pc = 0x1655D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1655DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1655D8u;
            // 0x1655dc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1655D4u: goto label_1655d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1655E0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
