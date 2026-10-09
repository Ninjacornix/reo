#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016A2F8
// Address: 0x16a2f8 - 0x16a318
void sub_0016A2F8_0x16a2f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016A2F8_0x16a2f8");
#endif

    switch (ctx->pc) {
        case 0x16a30cu: goto label_16a30c;
        default: break;
    }

    ctx->pc = 0x16a2f8u;

    // 0x16a2f8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x16a2f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16a2fc: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x16a2fcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a300: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x16a300u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x16a304: 0xc059c38  jal         func_1670E0
    ctx->pc = 0x16A304u;
    SET_GPR_U32(ctx, 31, 0x16A30Cu);
    ctx->pc = 0x16A308u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16A304u;
            // 0x16a308: 0x8c851af4  lw          $a1, 0x1AF4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 6900)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1670E0u;
    if (runtime->hasFunction(0x1670E0u)) {
        auto targetFn = runtime->lookupFunction(0x1670E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A30Cu; }
        if (ctx->pc != 0x16A30Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001670E0_0x1670e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A30Cu; }
        if (ctx->pc != 0x16A30Cu) { return; }
    }
    ctx->pc = 0x16A30Cu;
label_16a30c:
    // 0x16a30c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x16a30cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16a310: 0x3e00008  jr          $ra
    ctx->pc = 0x16A310u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16A314u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A310u;
            // 0x16a314: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16A30Cu: goto label_16a30c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16A318u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
