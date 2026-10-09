#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001728D8
// Address: 0x1728d8 - 0x172908
void sub_001728D8_0x1728d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001728D8_0x1728d8");
#endif

    switch (ctx->pc) {
        case 0x1728ecu: goto label_1728ec;
        case 0x1728f4u: goto label_1728f4;
        default: break;
    }

    ctx->pc = 0x1728d8u;

    // 0x1728d8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1728d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1728dc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1728dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1728e0: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1728e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1728e4: 0xc05ca42  jal         func_172908
    ctx->pc = 0x1728E4u;
    SET_GPR_U32(ctx, 31, 0x1728ECu);
    ctx->pc = 0x1728E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1728E4u;
            // 0x1728e8: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x172908u;
    if (runtime->hasFunction(0x172908u)) {
        auto targetFn = runtime->lookupFunction(0x172908u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1728ECu; }
        if (ctx->pc != 0x1728ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00172908_0x172908(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1728ECu; }
        if (ctx->pc != 0x1728ECu) { return; }
    }
    ctx->pc = 0x1728ECu;
label_1728ec:
    // 0x1728ec: 0xc05ca6c  jal         func_1729B0
    ctx->pc = 0x1728ECu;
    SET_GPR_U32(ctx, 31, 0x1728F4u);
    ctx->pc = 0x1728F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1728ECu;
            // 0x1728f0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1729B0u;
    if (runtime->hasFunction(0x1729B0u)) {
        auto targetFn = runtime->lookupFunction(0x1729B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1728F4u; }
        if (ctx->pc != 0x1728F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001729B0_0x1729b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1728F4u; }
        if (ctx->pc != 0x1728F4u) { return; }
    }
    ctx->pc = 0x1728F4u;
label_1728f4:
    // 0x1728f4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1728f4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1728f8: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1728f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1728fc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1728fcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x172900: 0x805ca8e  j           func_172A38
    ctx->pc = 0x172900u;
    ctx->pc = 0x172904u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172900u;
            // 0x172904: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x172A38u;
    if (runtime->hasFunction(0x172A38u)) {
        auto targetFn = runtime->lookupFunction(0x172A38u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00172A38_0x172a38(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x172908u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
