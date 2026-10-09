#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B93D0
// Address: 0x1b93d0 - 0x1b94b0
void sub_001B93D0_0x1b93d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B93D0_0x1b93d0");
#endif

    switch (ctx->pc) {
        case 0x1b9430u: goto label_1b9430;
        case 0x1b9460u: goto label_1b9460;
        case 0x1b9484u: goto label_1b9484;
        default: break;
    }

    ctx->pc = 0x1b93d0u;

    // 0x1b93d0: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x1b93d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x1b93d4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1b93d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b93d8: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x1b93d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x1b93dc: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1b93dcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1b93e0: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1b93e0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1b93e4: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x1b93e4u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b93e8: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1b93e8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1b93ec: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x1b93ecu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b93f0: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b93f0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b93f4: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x1b93f4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b93f8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b93f8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b93fc: 0x120882d  daddu       $s1, $t1, $zero
    ctx->pc = 0x1b93fcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9400: 0x15020002  bne         $t0, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1B9400u;
    {
        const bool branch_taken_0x1b9400 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 2));
        ctx->pc = 0x1B9404u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9400u;
            // 0x1b9404: 0x140802d  daddu       $s0, $t2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9400) {
            ctx->pc = 0x1B940Cu;
            goto label_1b940c;
        }
    }
    ctx->pc = 0x1B9408u;
    // 0x1b9408: 0x40402d  daddu       $t0, $v0, $zero
    ctx->pc = 0x1b9408u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_1b940c:
    // 0x1b940c: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1b940cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1b9410: 0xe0202d  daddu       $a0, $a3, $zero
    ctx->pc = 0x1b9410u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9414: 0x81880  sll         $v1, $t0, 2
    ctx->pc = 0x1b9414u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 8), 2));
    // 0x1b9418: 0x24424bf0  addiu       $v0, $v0, 0x4BF0
    ctx->pc = 0x1b9418u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 19440));
    // 0x1b941c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1b941cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b9420: 0x27a60068  addiu       $a2, $sp, 0x68
    ctx->pc = 0x1b9420u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 104));
    // 0x1b9424: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x1b9424u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1b9428: 0xc06e52c  jal         func_1B94B0
    ctx->pc = 0x1B9428u;
    SET_GPR_U32(ctx, 31, 0x1B9430u);
    ctx->pc = 0x1B942Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9428u;
            // 0x1b942c: 0x27a7006c  addiu       $a3, $sp, 0x6C (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 108));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B94B0u;
    if (runtime->hasFunction(0x1B94B0u)) {
        auto targetFn = runtime->lookupFunction(0x1B94B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9430u; }
        if (ctx->pc != 0x1B9430u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B94B0_0x1b94b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9430u; }
        if (ctx->pc != 0x1B9430u) { return; }
    }
    ctx->pc = 0x1B9430u;
label_1b9430:
    // 0x1b9430: 0x10400014  beqz        $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x1B9430u;
    {
        const bool branch_taken_0x1b9430 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b9430) {
            ctx->pc = 0x1B9484u;
            goto label_1b9484;
        }
    }
    ctx->pc = 0x1B9438u;
    // 0x1b9438: 0x1620000b  bnez        $s1, . + 4 + (0xB << 2)
    ctx->pc = 0x1B9438u;
    {
        const bool branch_taken_0x1b9438 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b9438) {
            ctx->pc = 0x1B9468u;
            goto label_1b9468;
        }
    }
    ctx->pc = 0x1B9440u;
    // 0x1b9440: 0x8fa70068  lw          $a3, 0x68($sp)
    ctx->pc = 0x1b9440u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x1b9444: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1b9444u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9448: 0x8fa8006c  lw          $t0, 0x6C($sp)
    ctx->pc = 0x1b9448u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 108)));
    // 0x1b944c: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1b944cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9450: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x1b9450u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9454: 0x200502d  daddu       $t2, $s0, $zero
    ctx->pc = 0x1b9454u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9458: 0xc06b1fc  jal         func_1AC7F0
    ctx->pc = 0x1B9458u;
    SET_GPR_U32(ctx, 31, 0x1B9460u);
    ctx->pc = 0x1B945Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9458u;
            // 0x1b945c: 0x2409ffff  addiu       $t1, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AC7F0u;
    if (runtime->hasFunction(0x1AC7F0u)) {
        auto targetFn = runtime->lookupFunction(0x1AC7F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9460u; }
        if (ctx->pc != 0x1B9460u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AC7F0_0x1ac7f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9460u; }
        if (ctx->pc != 0x1B9460u) { return; }
    }
    ctx->pc = 0x1B9460u;
label_1b9460:
    // 0x1b9460: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1B9460u;
    {
        const bool branch_taken_0x1b9460 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B9464u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9460u;
            // 0x1b9464: 0xdfbf0050  ld          $ra, 0x50($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9460) {
            ctx->pc = 0x1B9488u;
            goto label_1b9488;
        }
    }
    ctx->pc = 0x1B9468u;
label_1b9468:
    // 0x1b9468: 0x8fa70068  lw          $a3, 0x68($sp)
    ctx->pc = 0x1b9468u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x1b946c: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1b946cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9470: 0x8fa8006c  lw          $t0, 0x6C($sp)
    ctx->pc = 0x1b9470u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 108)));
    // 0x1b9474: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1b9474u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9478: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x1b9478u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b947c: 0xc06b2d8  jal         func_1ACB60
    ctx->pc = 0x1B947Cu;
    SET_GPR_U32(ctx, 31, 0x1B9484u);
    ctx->pc = 0x1B9480u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B947Cu;
            // 0x1b9480: 0x24092000  addiu       $t1, $zero, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ACB60u;
    if (runtime->hasFunction(0x1ACB60u)) {
        auto targetFn = runtime->lookupFunction(0x1ACB60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9484u; }
        if (ctx->pc != 0x1B9484u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ACB60_0x1acb60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9484u; }
        if (ctx->pc != 0x1B9484u) { return; }
    }
    ctx->pc = 0x1B9484u;
label_1b9484:
    // 0x1b9484: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x1b9484u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
label_1b9488:
    // 0x1b9488: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1b9488u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1b948c: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1b948cu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1b9490: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1b9490u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b9494: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b9494u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b9498: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b9498u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b949c: 0x3e00008  jr          $ra
    ctx->pc = 0x1B949Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B94A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B949Cu;
            // 0x1b94a0: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B940Cu: goto label_1b940c;
            case 0x1B9430u: goto label_1b9430;
            case 0x1B9460u: goto label_1b9460;
            case 0x1B9468u: goto label_1b9468;
            case 0x1B9484u: goto label_1b9484;
            case 0x1B9488u: goto label_1b9488;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B94A4u;
    // 0x1b94a4: 0x0  nop
    ctx->pc = 0x1b94a4u;
    // NOP
    // 0x1b94a8: 0x0  nop
    ctx->pc = 0x1b94a8u;
    // NOP
    // 0x1b94ac: 0x0  nop
    ctx->pc = 0x1b94acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
