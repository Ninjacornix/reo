#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001395C8
// Address: 0x1395c8 - 0x1395f8
void sub_001395C8_0x1395c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001395C8_0x1395c8");
#endif

    switch (ctx->pc) {
        case 0x1395e4u: goto label_1395e4;
        default: break;
    }

    ctx->pc = 0x1395c8u;

    // 0x1395c8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1395c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1395cc: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x1395ccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x1395d0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1395d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1395d4: 0x2442cbe0  addiu       $v0, $v0, -0x3420
    ctx->pc = 0x1395d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294953952));
    // 0x1395d8: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1395d8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1395dc: 0xc04eb84  jal         func_13AE10
    ctx->pc = 0x1395DCu;
    SET_GPR_U32(ctx, 31, 0x1395E4u);
    ctx->pc = 0x1395E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1395DCu;
            // 0x1395e0: 0x8c430000  lw          $v1, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13AE10u;
    if (runtime->hasFunction(0x13AE10u)) {
        auto targetFn = runtime->lookupFunction(0x13AE10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1395E4u; }
        if (ctx->pc != 0x1395E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013AE10_0x13ae10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1395E4u; }
        if (ctx->pc != 0x1395E4u) { return; }
    }
    ctx->pc = 0x1395E4u;
label_1395e4:
    // 0x1395e4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1395e4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1395e8: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x1395e8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x1395ec: 0x2442cbf8  addiu       $v0, $v0, -0x3408
    ctx->pc = 0x1395ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294953976));
    // 0x1395f0: 0x3e00008  jr          $ra
    ctx->pc = 0x1395F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1395F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1395F0u;
            // 0x1395f4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1395E4u: goto label_1395e4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1395F8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
