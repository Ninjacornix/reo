#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017D5F0
// Address: 0x17d5f0 - 0x17d620
void sub_0017D5F0_0x17d5f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017D5F0_0x17d5f0");
#endif

    switch (ctx->pc) {
        case 0x17d608u: goto label_17d608;
        default: break;
    }

    ctx->pc = 0x17d5f0u;

    // 0x17d5f0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17d5f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17d5f4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17d5f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17d5f8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x17d5f8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d5fc: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x17d5fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x17d600: 0xc052486  jal         func_149218
    ctx->pc = 0x17D600u;
    SET_GPR_U32(ctx, 31, 0x17D608u);
    ctx->pc = 0x17D604u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17D600u;
            // 0x17d604: 0xa0202d  daddu       $a0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x149218u;
    if (runtime->hasFunction(0x149218u)) {
        auto targetFn = runtime->lookupFunction(0x149218u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D608u; }
        if (ctx->pc != 0x17D608u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00149218_0x149218(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D608u; }
        if (ctx->pc != 0x17D608u) { return; }
    }
    ctx->pc = 0x17D608u;
label_17d608:
    // 0x17d608: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17d608u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d60c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x17d60cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17d610: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x17d610u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d614: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17d614u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17d618: 0x805f4ba  j           func_17D2E8
    ctx->pc = 0x17D618u;
    ctx->pc = 0x17D61Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17D618u;
            // 0x17d61c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D2E8u;
    if (runtime->hasFunction(0x17D2E8u)) {
        auto targetFn = runtime->lookupFunction(0x17D2E8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D2E8_0x17d2e8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17D620u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
