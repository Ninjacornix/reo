#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001920D0
// Address: 0x1920d0 - 0x1920f4
void sub_001920D0_0x1920d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001920D0_0x1920d0");
#endif

    switch (ctx->pc) {
        case 0x1920e0u: goto label_1920e0;
        case 0x1920e8u: goto label_1920e8;
        default: break;
    }

    ctx->pc = 0x1920d0u;

    // 0x1920d0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1920d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1920d4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1920d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1920d8: 0xc064828  jal         func_1920A0
    ctx->pc = 0x1920D8u;
    SET_GPR_U32(ctx, 31, 0x1920E0u);
    ctx->pc = 0x1920A0u;
    if (runtime->hasFunction(0x1920A0u)) {
        auto targetFn = runtime->lookupFunction(0x1920A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1920E0u; }
        if (ctx->pc != 0x1920E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001920A0_0x1920a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1920E0u; }
        if (ctx->pc != 0x1920E0u) { return; }
    }
    ctx->pc = 0x1920E0u;
label_1920e0:
    // 0x1920e0: 0xc064888  jal         func_192220
    ctx->pc = 0x1920E0u;
    SET_GPR_U32(ctx, 31, 0x1920E8u);
    ctx->pc = 0x1920E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1920E0u;
            // 0x1920e4: 0x46000306  mov.s       $f12, $f0 (Delay Slot)
        ctx->f[12] = FPU_MOV_S(ctx->f[0]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x192220u;
    if (runtime->hasFunction(0x192220u)) {
        auto targetFn = runtime->lookupFunction(0x192220u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1920E8u; }
        if (ctx->pc != 0x1920E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00192220_0x192220(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1920E8u; }
        if (ctx->pc != 0x1920E8u) { return; }
    }
    ctx->pc = 0x1920E8u;
label_1920e8:
    // 0x1920e8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1920e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1920ec: 0x3e00008  jr          $ra
    ctx->pc = 0x1920ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1920F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1920ECu;
            // 0x1920f0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1920E0u: goto label_1920e0;
            case 0x1920E8u: goto label_1920e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1920F4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
