#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00141418
// Address: 0x141418 - 0x141490
void sub_00141418_0x141418(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00141418_0x141418");
#endif

    switch (ctx->pc) {
        case 0x14144cu: goto label_14144c;
        case 0x14146cu: goto label_14146c;
        default: break;
    }

    ctx->pc = 0x141418u;

    // 0x141418: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x141418u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x14141c: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x14141cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x141420: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x141420u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x141424: 0x24639a7c  addiu       $v1, $v1, -0x6584
    ctx->pc = 0x141424u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294941308));
    // 0x141428: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x141428u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x14142c: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x14142cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x141430: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x141430u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x141434: 0x14400012  bnez        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x141434u;
    {
        const bool branch_taken_0x141434 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x141438u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x141434u;
            // 0x141438: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x141434) {
            ctx->pc = 0x141480u;
            goto label_141480;
        }
    }
    ctx->pc = 0x14143Cu;
    // 0x14143c: 0x3c100023  lui         $s0, 0x23
    ctx->pc = 0x14143cu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)35 << 16));
    // 0x141440: 0x26109d10  addiu       $s0, $s0, -0x62F0
    ctx->pc = 0x141440u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294941968));
    // 0x141444: 0xc04e444  jal         func_139110
    ctx->pc = 0x141444u;
    SET_GPR_U32(ctx, 31, 0x14144Cu);
    ctx->pc = 0x141448u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x141444u;
            // 0x141448: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139110u;
    if (runtime->hasFunction(0x139110u)) {
        auto targetFn = runtime->lookupFunction(0x139110u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14144Cu; }
        if (ctx->pc != 0x14144Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00139110_0x139110(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14144Cu; }
        if (ctx->pc != 0x14144Cu) { return; }
    }
    ctx->pc = 0x14144Cu;
label_14144c:
    // 0x14144c: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x14144cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x141450: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x141450u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x141454: 0x24509a84  addiu       $s0, $v0, -0x657C
    ctx->pc = 0x141454u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941316));
    // 0x141458: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x141458u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x14145c: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x14145Cu;
    {
        const bool branch_taken_0x14145c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x141460u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14145Cu;
            // 0x141460: 0x60202d  daddu       $a0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14145c) {
            ctx->pc = 0x141470u;
            goto label_141470;
        }
    }
    ctx->pc = 0x141464u;
    // 0x141464: 0xc046e86  jal         func_11BA18
    ctx->pc = 0x141464u;
    SET_GPR_U32(ctx, 31, 0x14146Cu);
    ctx->pc = 0x11BA18u;
    if (runtime->hasFunction(0x11BA18u)) {
        auto targetFn = runtime->lookupFunction(0x11BA18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14146Cu; }
        if (ctx->pc != 0x14146Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011BA18_0x11ba18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14146Cu; }
        if (ctx->pc != 0x14146Cu) { return; }
    }
    ctx->pc = 0x14146Cu;
label_14146c:
    // 0x14146c: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x14146cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
label_141470:
    // 0x141470: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x141470u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x141474: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x141474u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x141478: 0x804e4fa  j           func_1393E8
    ctx->pc = 0x141478u;
    ctx->pc = 0x14147Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x141478u;
            // 0x14147c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1393E8u;
    if (runtime->hasFunction(0x1393E8u)) {
        auto targetFn = runtime->lookupFunction(0x1393E8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001393E8_0x1393e8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x141480u;
label_141480:
    // 0x141480: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x141480u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x141484: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x141484u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x141488: 0x3e00008  jr          $ra
    ctx->pc = 0x141488u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x14148Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x141488u;
            // 0x14148c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x14144Cu: goto label_14144c;
            case 0x14146Cu: goto label_14146c;
            case 0x141470u: goto label_141470;
            case 0x141480u: goto label_141480;
            default: break;
        }
        return;
    }
    ctx->pc = 0x141490u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
