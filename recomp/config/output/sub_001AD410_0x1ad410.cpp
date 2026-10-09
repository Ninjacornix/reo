#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AD410
// Address: 0x1ad410 - 0x1ad4b0
void sub_001AD410_0x1ad410(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AD410_0x1ad410");
#endif

    switch (ctx->pc) {
        case 0x1ad44cu: goto label_1ad44c;
        case 0x1ad468u: goto label_1ad468;
        case 0x1ad494u: goto label_1ad494;
        default: break;
    }

    ctx->pc = 0x1ad410u;

    // 0x1ad410: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1ad410u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1ad414: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1ad414u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1ad418: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1ad418u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1ad41c: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1ad41cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1ad420: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1ad420u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1ad424: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x1ad424u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ad428: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1ad428u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1ad42c: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1ad42cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ad430: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1ad430u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1ad434: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x1ad434u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ad438: 0x8c30440c  lw          $s0, 0x440C($at)
    ctx->pc = 0x1ad438u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1ad43c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1ad43cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ad440: 0x24060040  addiu       $a2, $zero, 0x40
    ctx->pc = 0x1ad440u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x1ad444: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1AD444u;
    SET_GPR_U32(ctx, 31, 0x1AD44Cu);
    ctx->pc = 0x1AD448u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD444u;
            // 0x1ad448: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD44Cu; }
        if (ctx->pc != 0x1AD44Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD44Cu; }
        if (ctx->pc != 0x1AD44Cu) { return; }
    }
    ctx->pc = 0x1AD44Cu;
label_1ad44c:
    // 0x1ad44c: 0x24020040  addiu       $v0, $zero, 0x40
    ctx->pc = 0x1ad44cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x1ad450: 0x26040040  addiu       $a0, $s0, 0x40
    ctx->pc = 0x1ad450u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 64));
    // 0x1ad454: 0xae020018  sw          $v0, 0x18($s0)
    ctx->pc = 0x1ad454u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 2));
    // 0x1ad458: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1ad458u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ad45c: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x1ad45cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ad460: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1AD460u;
    SET_GPR_U32(ctx, 31, 0x1AD468u);
    ctx->pc = 0x1AD464u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD460u;
            // 0x1ad464: 0xae12001c  sw          $s2, 0x1C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD468u; }
        if (ctx->pc != 0x1AD468u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD468u; }
        if (ctx->pc != 0x1AD468u) { return; }
    }
    ctx->pc = 0x1AD468u;
label_1ad468:
    // 0x1ad468: 0x26020040  addiu       $v0, $s0, 0x40
    ctx->pc = 0x1ad468u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 64));
    // 0x1ad46c: 0x2722821  addu        $a1, $s3, $s2
    ctx->pc = 0x1ad46cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 18)));
    // 0x1ad470: 0x521821  addu        $v1, $v0, $s2
    ctx->pc = 0x1ad470u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x1ad474: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x1ad474u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ad478: 0x2402ffc0  addiu       $v0, $zero, -0x40
    ctx->pc = 0x1ad478u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967232));
    // 0x1ad47c: 0x2463003f  addiu       $v1, $v1, 0x3F
    ctx->pc = 0x1ad47cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 63));
    // 0x1ad480: 0x622024  and         $a0, $v1, $v0
    ctx->pc = 0x1ad480u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ad484: 0x901023  subu        $v0, $a0, $s0
    ctx->pc = 0x1ad484u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 16)));
    // 0x1ad488: 0xae020020  sw          $v0, 0x20($s0)
    ctx->pc = 0x1ad488u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 2));
    // 0x1ad48c: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1AD48Cu;
    SET_GPR_U32(ctx, 31, 0x1AD494u);
    ctx->pc = 0x1AD490u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD48Cu;
            // 0x1ad490: 0xae110024  sw          $s1, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD494u; }
        if (ctx->pc != 0x1AD494u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD494u; }
        if (ctx->pc != 0x1AD494u) { return; }
    }
    ctx->pc = 0x1AD494u;
label_1ad494:
    // 0x1ad494: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1ad494u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1ad498: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1ad498u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1ad49c: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1ad49cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1ad4a0: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1ad4a0u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ad4a4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ad4a4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ad4a8: 0x3e00008  jr          $ra
    ctx->pc = 0x1AD4A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AD4ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD4A8u;
            // 0x1ad4ac: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AD44Cu: goto label_1ad44c;
            case 0x1AD468u: goto label_1ad468;
            case 0x1AD494u: goto label_1ad494;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AD4B0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
