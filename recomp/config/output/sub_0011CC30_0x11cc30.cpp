#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011CC30
// Address: 0x11cc30 - 0x11cc58
void sub_0011CC30_0x11cc30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011CC30_0x11cc30");
#endif

    switch (ctx->pc) {
        case 0x11cc40u: goto label_11cc40;
        default: break;
    }

    ctx->pc = 0x11cc30u;

    // 0x11cc30: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x11cc30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x11cc34: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x11cc34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x11cc38: 0xc04528c  jal         func_114A30
    ctx->pc = 0x11CC38u;
    SET_GPR_U32(ctx, 31, 0x11CC40u);
    ctx->pc = 0x11CC3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11CC38u;
            // 0x11cc3c: 0x24040004  addiu       $a0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114A30u;
    if (runtime->hasFunction(0x114A30u)) {
        auto targetFn = runtime->lookupFunction(0x114A30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CC40u; }
        if (ctx->pc != 0x11CC40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114A30_0x114a30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CC40u; }
        if (ctx->pc != 0x11CC40u) { return; }
    }
    ctx->pc = 0x11CC40u;
label_11cc40:
    // 0x11cc40: 0x3c030001  lui         $v1, 0x1
    ctx->pc = 0x11cc40u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)1 << 16));
    // 0x11cc44: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x11cc44u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11cc48: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x11cc48u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x11cc4c: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x11cc4cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x11cc50: 0x3e00008  jr          $ra
    ctx->pc = 0x11CC50u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11CC54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CC50u;
            // 0x11cc54: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11CC40u: goto label_11cc40;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11CC58u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
