#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013F858
// Address: 0x13f858 - 0x13f8a8
void sub_0013F858_0x13f858(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013F858_0x13f858");
#endif

    switch (ctx->pc) {
        case 0x13f868u: goto label_13f868;
        case 0x13f898u: goto label_13f898;
        default: break;
    }

    ctx->pc = 0x13f858u;

    // 0x13f858: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13f858u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13f85c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13f85cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13f860: 0xc04fc96  jal         func_13F258
    ctx->pc = 0x13F860u;
    SET_GPR_U32(ctx, 31, 0x13F868u);
    ctx->pc = 0x13F258u;
    if (runtime->hasFunction(0x13F258u)) {
        auto targetFn = runtime->lookupFunction(0x13F258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F868u; }
        if (ctx->pc != 0x13F868u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F258_0x13f258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F868u; }
        if (ctx->pc != 0x13F868u) { return; }
    }
    ctx->pc = 0x13F868u;
label_13f868:
    // 0x13f868: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x13f868u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x13f86c: 0x3c040022  lui         $a0, 0x22
    ctx->pc = 0x13f86cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)34 << 16));
    // 0x13f870: 0x24634c58  addiu       $v1, $v1, 0x4C58
    ctx->pc = 0x13f870u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 19544));
    // 0x13f874: 0x24844c60  addiu       $a0, $a0, 0x4C60
    ctx->pc = 0x13f874u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19552));
    // 0x13f878: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x13f878u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x13f87c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13f87cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f880: 0x24064000  addiu       $a2, $zero, 0x4000
    ctx->pc = 0x13f880u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16384));
    // 0x13f884: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x13f884u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x13f888: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x13F888u;
    {
        const bool branch_taken_0x13f888 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x13f888) {
            ctx->pc = 0x13F898u;
            goto label_13f898;
        }
    }
    ctx->pc = 0x13F890u;
    // 0x13f890: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x13F890u;
    SET_GPR_U32(ctx, 31, 0x13F898u);
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F898u; }
        if (ctx->pc != 0x13F898u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F898u; }
        if (ctx->pc != 0x13F898u) { return; }
    }
    ctx->pc = 0x13F898u;
label_13f898:
    // 0x13f898: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13f898u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13f89c: 0x804fc9c  j           func_13F270
    ctx->pc = 0x13F89Cu;
    ctx->pc = 0x13F8A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F89Cu;
            // 0x13f8a0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F270u;
    if (runtime->hasFunction(0x13F270u)) {
        auto targetFn = runtime->lookupFunction(0x13F270u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013F270_0x13f270(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13F8A4u;
    // 0x13f8a4: 0x0  nop
    ctx->pc = 0x13f8a4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
