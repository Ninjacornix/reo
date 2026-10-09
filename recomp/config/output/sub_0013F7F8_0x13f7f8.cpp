#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013F7F8
// Address: 0x13f7f8 - 0x13f858
void sub_0013F7F8_0x13f7f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013F7F8_0x13f7f8");
#endif

    switch (ctx->pc) {
        case 0x13f814u: goto label_13f814;
        case 0x13f83cu: goto label_13f83c;
        default: break;
    }

    ctx->pc = 0x13f7f8u;

    // 0x13f7f8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13f7f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13f7fc: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13f7fcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13f800: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13f800u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13f804: 0x24424c20  addiu       $v0, $v0, 0x4C20
    ctx->pc = 0x13f804u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 19488));
    // 0x13f808: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x13f808u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x13f80c: 0xc04fc96  jal         func_13F258
    ctx->pc = 0x13F80Cu;
    SET_GPR_U32(ctx, 31, 0x13F814u);
    ctx->pc = 0x13F810u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F80Cu;
            // 0x13f810: 0x8c430000  lw          $v1, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F258u;
    if (runtime->hasFunction(0x13F258u)) {
        auto targetFn = runtime->lookupFunction(0x13F258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F814u; }
        if (ctx->pc != 0x13F814u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F258_0x13f258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F814u; }
        if (ctx->pc != 0x13F814u) { return; }
    }
    ctx->pc = 0x13F814u;
label_13f814:
    // 0x13f814: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13f814u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13f818: 0x3c040022  lui         $a0, 0x22
    ctx->pc = 0x13f818u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)34 << 16));
    // 0x13f81c: 0x24504c58  addiu       $s0, $v0, 0x4C58
    ctx->pc = 0x13f81cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 19544));
    // 0x13f820: 0x24844c60  addiu       $a0, $a0, 0x4C60
    ctx->pc = 0x13f820u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19552));
    // 0x13f824: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x13f824u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13f828: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13f828u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f82c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x13F82Cu;
    {
        const bool branch_taken_0x13f82c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13F830u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F82Cu;
            // 0x13f830: 0x24064000  addiu       $a2, $zero, 0x4000 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16384));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f82c) {
            ctx->pc = 0x13F840u;
            goto label_13f840;
        }
    }
    ctx->pc = 0x13F834u;
    // 0x13f834: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x13F834u;
    SET_GPR_U32(ctx, 31, 0x13F83Cu);
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F83Cu; }
        if (ctx->pc != 0x13F83Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F83Cu; }
        if (ctx->pc != 0x13F83Cu) { return; }
    }
    ctx->pc = 0x13F83Cu;
label_13f83c:
    // 0x13f83c: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x13f83cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_13f840:
    // 0x13f840: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x13f840u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x13f844: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x13f844u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13f848: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x13f848u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x13f84c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13f84cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13f850: 0x804fc9c  j           func_13F270
    ctx->pc = 0x13F850u;
    ctx->pc = 0x13F854u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F850u;
            // 0x13f854: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F270u;
    if (runtime->hasFunction(0x13F270u)) {
        auto targetFn = runtime->lookupFunction(0x13F270u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013F270_0x13f270(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13F858u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
