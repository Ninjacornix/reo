#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D2560
// Address: 0x1d2560 - 0x1d2594
void sub_001D2560_0x1d2560(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D2560_0x1d2560");
#endif

    switch (ctx->pc) {
        case 0x1d2588u: goto label_1d2588;
        default: break;
    }

    ctx->pc = 0x1d2560u;

    // 0x1d2560: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d2560u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d2564: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d2564u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d2568: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d2568u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d256c: 0x802343d7  lb          $v1, 0x43D7($at)
    ctx->pc = 0x1d256cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d2570: 0x14600005  bnez        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1D2570u;
    {
        const bool branch_taken_0x1d2570 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d2570) {
            ctx->pc = 0x1D2588u;
            goto label_1d2588;
        }
    }
    ctx->pc = 0x1D2578u;
    // 0x1d2578: 0x308400ff  andi        $a0, $a0, 0xFF
    ctx->pc = 0x1d2578u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1d257c: 0x410c0  sll         $v0, $a0, 3
    ctx->pc = 0x1d257cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x1d2580: 0xc073784  jal         func_1CDE10
    ctx->pc = 0x1D2580u;
    SET_GPR_U32(ctx, 31, 0x1D2588u);
    ctx->pc = 0x1D2584u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2580u;
            // 0x1d2584: 0x24453000  addiu       $a1, $v0, 0x3000 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 12288));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CDE10u;
    if (runtime->hasFunction(0x1CDE10u)) {
        auto targetFn = runtime->lookupFunction(0x1CDE10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2588u; }
        if (ctx->pc != 0x1D2588u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CDE10_0x1cde10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2588u; }
        if (ctx->pc != 0x1D2588u) { return; }
    }
    ctx->pc = 0x1D2588u;
label_1d2588:
    // 0x1d2588: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d2588u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d258c: 0x3e00008  jr          $ra
    ctx->pc = 0x1D258Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D2590u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D258Cu;
            // 0x1d2590: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D2588u: goto label_1d2588;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D2594u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
