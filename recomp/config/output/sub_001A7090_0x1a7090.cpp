#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A7090
// Address: 0x1a7090 - 0x1a70b4
void sub_001A7090_0x1a7090(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A7090_0x1a7090");
#endif

    switch (ctx->pc) {
        case 0x1a70a0u: goto label_1a70a0;
        default: break;
    }

    ctx->pc = 0x1a7090u;

    // 0x1a7090: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a7090u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a7094: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a7094u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a7098: 0xc045534  jal         func_1154D0
    ctx->pc = 0x1A7098u;
    SET_GPR_U32(ctx, 31, 0x1A70A0u);
    ctx->pc = 0x1A709Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7098u;
            // 0x1a709c: 0xc0202d  daddu       $a0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1154D0u;
    if (runtime->hasFunction(0x1154D0u)) {
        auto targetFn = runtime->lookupFunction(0x1154D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A70A0u; }
        if (ctx->pc != 0x1A70A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001154D0_0x1154d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A70A0u; }
        if (ctx->pc != 0x1A70A0u) { return; }
    }
    ctx->pc = 0x1A70A0u;
label_1a70a0:
    // 0x1a70a0: 0xf  sync
    ctx->pc = 0x1a70a0u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x1a70a4: 0x42000038  ei
    ctx->pc = 0x1a70a4u;
    ctx->cop0_status |= 0x10000; // Enable interrupts
    // 0x1a70a8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a70a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a70ac: 0x3e00008  jr          $ra
    ctx->pc = 0x1A70ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A70B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A70ACu;
            // 0x1a70b0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A70A0u: goto label_1a70a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A70B4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
