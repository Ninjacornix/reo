#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00115748
// Address: 0x115748 - 0x115770
void sub_00115748_0x115748(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00115748_0x115748");
#endif

    switch (ctx->pc) {
        case 0x115758u: goto label_115758;
        default: break;
    }

    ctx->pc = 0x115748u;

    // 0x115748: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x115748u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x11574c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x11574cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x115750: 0xc045194  jal         func_114650
    ctx->pc = 0x115750u;
    SET_GPR_U32(ctx, 31, 0x115758u);
    ctx->pc = 0x115754u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x115750u;
            // 0x115754: 0xe0202d  daddu       $a0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114650u;
    if (runtime->hasFunction(0x114650u)) {
        auto targetFn = runtime->lookupFunction(0x114650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115758u; }
        if (ctx->pc != 0x115758u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114650_0x114650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115758u; }
        if (ctx->pc != 0x115758u) { return; }
    }
    ctx->pc = 0x115758u;
label_115758:
    // 0x115758: 0xf  sync
    ctx->pc = 0x115758u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x11575c: 0x42000038  ei
    ctx->pc = 0x11575cu;
    ctx->cop0_status |= 0x10000; // Enable interrupts
    // 0x115760: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x115760u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x115764: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x115764u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x115768: 0x3e00008  jr          $ra
    ctx->pc = 0x115768u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11576Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115768u;
            // 0x11576c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x115758u: goto label_115758;
            default: break;
        }
        return;
    }
    ctx->pc = 0x115770u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
