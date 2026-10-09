#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013F998
// Address: 0x13f998 - 0x13f9d8
void sub_0013F998_0x13f998(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013F998_0x13f998");
#endif

    switch (ctx->pc) {
        case 0x13f9acu: goto label_13f9ac;
        case 0x13f9c4u: goto label_13f9c4;
        default: break;
    }

    ctx->pc = 0x13f998u;

    // 0x13f998: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13f998u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13f99c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13f99cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13f9a0: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x13f9a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x13f9a4: 0xc04fc96  jal         func_13F258
    ctx->pc = 0x13F9A4u;
    SET_GPR_U32(ctx, 31, 0x13F9ACu);
    ctx->pc = 0x13F9A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F9A4u;
            // 0x13f9a8: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F258u;
    if (runtime->hasFunction(0x13F258u)) {
        auto targetFn = runtime->lookupFunction(0x13F258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F9ACu; }
        if (ctx->pc != 0x13F9ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F258_0x13f258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F9ACu; }
        if (ctx->pc != 0x13F9ACu) { return; }
    }
    ctx->pc = 0x13F9ACu;
label_13f9ac:
    // 0x13f9ac: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x13f9acu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f9b0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13f9b0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f9b4: 0x12000004  beqz        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x13F9B4u;
    {
        const bool branch_taken_0x13f9b4 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x13F9B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F9B4u;
            // 0x13f9b8: 0x24060040  addiu       $a2, $zero, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f9b4) {
            ctx->pc = 0x13F9C8u;
            goto label_13f9c8;
        }
    }
    ctx->pc = 0x13F9BCu;
    // 0x13f9bc: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x13F9BCu;
    SET_GPR_U32(ctx, 31, 0x13F9C4u);
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F9C4u; }
        if (ctx->pc != 0x13F9C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F9C4u; }
        if (ctx->pc != 0x13F9C4u) { return; }
    }
    ctx->pc = 0x13F9C4u;
label_13f9c4:
    // 0x13f9c4: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x13f9c4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
label_13f9c8:
    // 0x13f9c8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13f9c8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13f9cc: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x13f9ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13f9d0: 0x804fc9c  j           func_13F270
    ctx->pc = 0x13F9D0u;
    ctx->pc = 0x13F9D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F9D0u;
            // 0x13f9d4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F270u;
    if (runtime->hasFunction(0x13F270u)) {
        auto targetFn = runtime->lookupFunction(0x13F270u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013F270_0x13f270(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13F9D8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
