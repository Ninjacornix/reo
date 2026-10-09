#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012C4A0
// Address: 0x12c4a0 - 0x12c4c8
void sub_0012C4A0_0x12c4a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012C4A0_0x12c4a0");
#endif

    switch (ctx->pc) {
        case 0x12c4b4u: goto label_12c4b4;
        default: break;
    }

    ctx->pc = 0x12c4a0u;

    // 0x12c4a0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c4a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c4a4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12c4a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12c4a8: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x12c4a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x12c4ac: 0xc04f2cc  jal         func_13CB30
    ctx->pc = 0x12C4ACu;
    SET_GPR_U32(ctx, 31, 0x12C4B4u);
    ctx->pc = 0x12C4B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C4ACu;
            // 0x12c4b0: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13CB30u;
    if (runtime->hasFunction(0x13CB30u)) {
        auto targetFn = runtime->lookupFunction(0x13CB30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C4B4u; }
        if (ctx->pc != 0x12C4B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013CB30_0x13cb30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C4B4u; }
        if (ctx->pc != 0x12C4B4u) { return; }
    }
    ctx->pc = 0x12C4B4u;
label_12c4b4:
    // 0x12c4b4: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x12c4b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12c4b8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x12c4b8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12c4bc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12c4bcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c4c0: 0x804e80e  j           func_13A038
    ctx->pc = 0x12C4C0u;
    ctx->pc = 0x12C4C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C4C0u;
            // 0x12c4c4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13A038u;
    if (runtime->hasFunction(0x13A038u)) {
        auto targetFn = runtime->lookupFunction(0x13A038u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013A038_0x13a038(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12C4C8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
