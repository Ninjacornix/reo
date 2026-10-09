#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BC880
// Address: 0x1bc880 - 0x1bc8b0
void sub_001BC880_0x1bc880(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BC880_0x1bc880");
#endif

    switch (ctx->pc) {
        case 0x1bc890u: goto label_1bc890;
        case 0x1bc898u: goto label_1bc898;
        default: break;
    }

    ctx->pc = 0x1bc880u;

    // 0x1bc880: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1bc880u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1bc884: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1bc884u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1bc888: 0xc06a5f0  jal         func_1A97C0
    ctx->pc = 0x1BC888u;
    SET_GPR_U32(ctx, 31, 0x1BC890u);
    ctx->pc = 0x1BC88Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC888u;
            // 0x1bc88c: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A97C0u;
    if (runtime->hasFunction(0x1A97C0u)) {
        auto targetFn = runtime->lookupFunction(0x1A97C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC890u; }
        if (ctx->pc != 0x1BC890u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A97C0_0x1a97c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC890u; }
        if (ctx->pc != 0x1BC890u) { return; }
    }
    ctx->pc = 0x1BC890u;
label_1bc890:
    // 0x1bc890: 0xc07dce0  jal         func_1F7380
    ctx->pc = 0x1BC890u;
    SET_GPR_U32(ctx, 31, 0x1BC898u);
    ctx->pc = 0x1F7380u;
    if (runtime->hasFunction(0x1F7380u)) {
        auto targetFn = runtime->lookupFunction(0x1F7380u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC898u; }
        if (ctx->pc != 0x1BC898u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F7380_0x1f7380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC898u; }
        if (ctx->pc != 0x1BC898u) { return; }
    }
    ctx->pc = 0x1BC898u;
label_1bc898:
    // 0x1bc898: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1bc898u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bc89c: 0x3e00008  jr          $ra
    ctx->pc = 0x1BC89Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BC8A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC89Cu;
            // 0x1bc8a0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BC890u: goto label_1bc890;
            case 0x1BC898u: goto label_1bc898;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BC8A4u;
    // 0x1bc8a4: 0x0  nop
    ctx->pc = 0x1bc8a4u;
    // NOP
    // 0x1bc8a8: 0x0  nop
    ctx->pc = 0x1bc8a8u;
    // NOP
    // 0x1bc8ac: 0x0  nop
    ctx->pc = 0x1bc8acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
