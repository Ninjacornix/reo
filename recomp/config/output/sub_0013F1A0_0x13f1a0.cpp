#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013F1A0
// Address: 0x13f1a0 - 0x13f1c8
void sub_0013F1A0_0x13f1a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013F1A0_0x13f1a0");
#endif

    switch (ctx->pc) {
        case 0x13f1b4u: goto label_13f1b4;
        default: break;
    }

    ctx->pc = 0x13f1a0u;

    // 0x13f1a0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13f1a0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13f1a4: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13f1a4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13f1a8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13f1a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13f1ac: 0xc045a12  jal         func_116848
    ctx->pc = 0x13F1ACu;
    SET_GPR_U32(ctx, 31, 0x13F1B4u);
    ctx->pc = 0x13F1B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F1ACu;
            // 0x13f1b0: 0x2484d9e0  addiu       $a0, $a0, -0x2620 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957536));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F1B4u; }
        if (ctx->pc != 0x13F1B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F1B4u; }
        if (ctx->pc != 0x13F1B4u) { return; }
    }
    ctx->pc = 0x13F1B4u;
label_13f1b4:
    // 0x13f1b4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x13f1b4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f1b8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13f1b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13f1bc: 0x3e00008  jr          $ra
    ctx->pc = 0x13F1BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F1C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F1BCu;
            // 0x13f1c0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13F1B4u: goto label_13f1b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13F1C4u;
    // 0x13f1c4: 0x0  nop
    ctx->pc = 0x13f1c4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
