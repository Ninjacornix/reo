#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011C8E0
// Address: 0x11c8e0 - 0x11c908
void sub_0011C8E0_0x11c8e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011C8E0_0x11c8e0");
#endif

    switch (ctx->pc) {
        case 0x11c8fcu: goto label_11c8fc;
        default: break;
    }

    ctx->pc = 0x11c8e0u;

    // 0x11c8e0: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x11c8e0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c8e4: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x11c8e4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x11c8e8: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x11c8e8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x11c8ec: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x11c8ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x11c8f0: 0x24a58b98  addiu       $a1, $a1, -0x7468
    ctx->pc = 0x11c8f0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294937496));
    // 0x11c8f4: 0xc0471ee  jal         func_11C7B8
    ctx->pc = 0x11C8F4u;
    SET_GPR_U32(ctx, 31, 0x11C8FCu);
    ctx->pc = 0x11C8F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11C8F4u;
            // 0x11c8f8: 0x24070001  addiu       $a3, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11C7B8u;
    if (runtime->hasFunction(0x11C7B8u)) {
        auto targetFn = runtime->lookupFunction(0x11C7B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C8FCu; }
        if (ctx->pc != 0x11C8FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011C7B8_0x11c7b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C8FCu; }
        if (ctx->pc != 0x11C8FCu) { return; }
    }
    ctx->pc = 0x11C8FCu;
label_11c8fc:
    // 0x11c8fc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x11c8fcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11c900: 0x3e00008  jr          $ra
    ctx->pc = 0x11C900u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11C904u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C900u;
            // 0x11c904: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11C8FCu: goto label_11c8fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11C908u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
