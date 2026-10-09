#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AEBE0
// Address: 0x1aebe0 - 0x1aec10
void sub_001AEBE0_0x1aebe0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AEBE0_0x1aebe0");
#endif

    switch (ctx->pc) {
        case 0x1aebfcu: goto label_1aebfc;
        case 0x1aec04u: goto label_1aec04;
        default: break;
    }

    ctx->pc = 0x1aebe0u;

    // 0x1aebe0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1aebe0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1aebe4: 0x3c040032  lui         $a0, 0x32
    ctx->pc = 0x1aebe4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)50 << 16));
    // 0x1aebe8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1aebe8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1aebec: 0x248443c0  addiu       $a0, $a0, 0x43C0
    ctx->pc = 0x1aebecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17344));
    // 0x1aebf0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1aebf0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aebf4: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1AEBF4u;
    SET_GPR_U32(ctx, 31, 0x1AEBFCu);
    ctx->pc = 0x1AEBF8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEBF4u;
            // 0x1aebf8: 0x240600f0  addiu       $a2, $zero, 0xF0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 240));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEBFCu; }
        if (ctx->pc != 0x1AEBFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEBFCu; }
        if (ctx->pc != 0x1AEBFCu) { return; }
    }
    ctx->pc = 0x1AEBFCu;
label_1aebfc:
    // 0x1aebfc: 0xc06bb04  jal         func_1AEC10
    ctx->pc = 0x1AEBFCu;
    SET_GPR_U32(ctx, 31, 0x1AEC04u);
    ctx->pc = 0x1AEC10u;
    if (runtime->hasFunction(0x1AEC10u)) {
        auto targetFn = runtime->lookupFunction(0x1AEC10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEC04u; }
        if (ctx->pc != 0x1AEC04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AEC10_0x1aec10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEC04u; }
        if (ctx->pc != 0x1AEC04u) { return; }
    }
    ctx->pc = 0x1AEC04u;
label_1aec04:
    // 0x1aec04: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1aec04u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1aec08: 0x3e00008  jr          $ra
    ctx->pc = 0x1AEC08u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AEC0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEC08u;
            // 0x1aec0c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AEBFCu: goto label_1aebfc;
            case 0x1AEC04u: goto label_1aec04;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AEC10u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
