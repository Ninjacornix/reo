#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AE740
// Address: 0x1ae740 - 0x1aebe0
void sub_001AE740_0x1ae740(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AE740_0x1ae740");
#endif

    switch (ctx->pc) {
        case 0x1ae78cu: goto label_1ae78c;
        case 0x1ae7a4u: goto label_1ae7a4;
        case 0x1ae810u: goto label_1ae810;
        case 0x1ae840u: goto label_1ae840;
        case 0x1ae868u: goto label_1ae868;
        case 0x1ae870u: goto label_1ae870;
        case 0x1ae894u: goto label_1ae894;
        case 0x1ae8acu: goto label_1ae8ac;
        case 0x1ae8c4u: goto label_1ae8c4;
        case 0x1ae8e4u: goto label_1ae8e4;
        case 0x1ae928u: goto label_1ae928;
        case 0x1ae98cu: goto label_1ae98c;
        case 0x1ae9b8u: goto label_1ae9b8;
        case 0x1ae9e0u: goto label_1ae9e0;
        case 0x1aea10u: goto label_1aea10;
        case 0x1aea38u: goto label_1aea38;
        case 0x1aea50u: goto label_1aea50;
        case 0x1aea8cu: goto label_1aea8c;
        case 0x1aeab4u: goto label_1aeab4;
        case 0x1aeac0u: goto label_1aeac0;
        case 0x1aeac8u: goto label_1aeac8;
        case 0x1aeaecu: goto label_1aeaec;
        case 0x1aeb18u: goto label_1aeb18;
        case 0x1aeb40u: goto label_1aeb40;
        case 0x1aeb48u: goto label_1aeb48;
        case 0x1aeb84u: goto label_1aeb84;
        case 0x1aeb8cu: goto label_1aeb8c;
        case 0x1aeba8u: goto label_1aeba8;
        case 0x1aebb4u: goto label_1aebb4;
        case 0x1aebd0u: goto label_1aebd0;
        default: break;
    }

    ctx->pc = 0x1ae740u;

label_1ae740:
    // 0x1ae740: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1ae740u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1ae744: 0x41040  sll         $v0, $a0, 1
    ctx->pc = 0x1ae744u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1ae748: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1ae748u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1ae74c: 0x3c05002c  lui         $a1, 0x2C
    ctx->pc = 0x1ae74cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)44 << 16));
    // 0x1ae750: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1ae750u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1ae754: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x1ae754u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1ae758: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1ae758u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1ae75c: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x1ae75cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1ae760: 0x280c0  sll         $s0, $v0, 3
    ctx->pc = 0x1ae760u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1ae764: 0x24a58d72  addiu       $a1, $a1, -0x728E
    ctx->pc = 0x1ae764u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294937970));
    // 0x1ae768: 0x3c02002c  lui         $v0, 0x2C
    ctx->pc = 0x1ae768u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)44 << 16));
    // 0x1ae76c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1ae76cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ae770: 0x24428dc8  addiu       $v0, $v0, -0x7238
    ctx->pc = 0x1ae770u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294938056));
    // 0x1ae774: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1ae774u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1ae778: 0xb01821  addu        $v1, $a1, $s0
    ctx->pc = 0x1ae778u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 16)));
    // 0x1ae77c: 0xa0600000  sb          $zero, 0x0($v1)
    ctx->pc = 0x1ae77cu;
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ae780: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1ae780u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ae784: 0xc04cb7c  jal         func_132DF0
    ctx->pc = 0x1AE784u;
    SET_GPR_U32(ctx, 31, 0x1AE78Cu);
    ctx->pc = 0x1AE788u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE784u;
            // 0x1ae788: 0x80650000  lb          $a1, 0x0($v1) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x132DF0u;
    if (runtime->hasFunction(0x132DF0u)) {
        auto targetFn = runtime->lookupFunction(0x132DF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE78Cu; }
        if (ctx->pc != 0x1AE78Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00132DF0_0x132df0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE78Cu; }
        if (ctx->pc != 0x1AE78Cu) { return; }
    }
    ctx->pc = 0x1AE78Cu;
label_1ae78c:
    // 0x1ae78c: 0x3c02002c  lui         $v0, 0x2C
    ctx->pc = 0x1ae78cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)44 << 16));
    // 0x1ae790: 0x24428d78  addiu       $v0, $v0, -0x7288
    ctx->pc = 0x1ae790u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937976));
    // 0x1ae794: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1ae794u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1ae798: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x1ae798u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ae79c: 0xc06b7f4  jal         func_1ADFD0
    ctx->pc = 0x1AE79Cu;
    SET_GPR_U32(ctx, 31, 0x1AE7A4u);
    ctx->pc = 0x1AE7A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE79Cu;
            // 0x1ae7a0: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ADFD0u;
    if (runtime->hasFunction(0x1ADFD0u)) {
        auto targetFn = runtime->lookupFunction(0x1ADFD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE7A4u; }
        if (ctx->pc != 0x1AE7A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ADFD0_0x1adfd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE7A4u; }
        if (ctx->pc != 0x1AE7A4u) { return; }
    }
    ctx->pc = 0x1AE7A4u;
label_1ae7a4:
    // 0x1ae7a4: 0x3c03002c  lui         $v1, 0x2C
    ctx->pc = 0x1ae7a4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)44 << 16));
    // 0x1ae7a8: 0x24638d73  addiu       $v1, $v1, -0x728D
    ctx->pc = 0x1ae7a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294937971));
    // 0x1ae7ac: 0x701821  addu        $v1, $v1, $s0
    ctx->pc = 0x1ae7acu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1ae7b0: 0xa0600000  sb          $zero, 0x0($v1)
    ctx->pc = 0x1ae7b0u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ae7b4: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1ae7b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1ae7b8: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1ae7b8u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ae7bc: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ae7bcu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ae7c0: 0x3e00008  jr          $ra
    ctx->pc = 0x1AE7C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AE7C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE7C0u;
            // 0x1ae7c4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AE740u: goto label_1ae740;
            case 0x1AE78Cu: goto label_1ae78c;
            case 0x1AE7A4u: goto label_1ae7a4;
            case 0x1AE810u: goto label_1ae810;
            case 0x1AE81Cu: goto label_1ae81c;
            case 0x1AE840u: goto label_1ae840;
            case 0x1AE868u: goto label_1ae868;
            case 0x1AE870u: goto label_1ae870;
            case 0x1AE894u: goto label_1ae894;
            case 0x1AE89Cu: goto label_1ae89c;
            case 0x1AE8ACu: goto label_1ae8ac;
            case 0x1AE8B4u: goto label_1ae8b4;
            case 0x1AE8C4u: goto label_1ae8c4;
            case 0x1AE8E4u: goto label_1ae8e4;
            case 0x1AE928u: goto label_1ae928;
            case 0x1AE938u: goto label_1ae938;
            case 0x1AE95Cu: goto label_1ae95c;
            case 0x1AE984u: goto label_1ae984;
            case 0x1AE98Cu: goto label_1ae98c;
            case 0x1AE9B8u: goto label_1ae9b8;
            case 0x1AE9E0u: goto label_1ae9e0;
            case 0x1AEA10u: goto label_1aea10;
            case 0x1AEA38u: goto label_1aea38;
            case 0x1AEA50u: goto label_1aea50;
            case 0x1AEA8Cu: goto label_1aea8c;
            case 0x1AEAB4u: goto label_1aeab4;
            case 0x1AEAC0u: goto label_1aeac0;
            case 0x1AEAC8u: goto label_1aeac8;
            case 0x1AEAECu: goto label_1aeaec;
            case 0x1AEB18u: goto label_1aeb18;
            case 0x1AEB40u: goto label_1aeb40;
            case 0x1AEB48u: goto label_1aeb48;
            case 0x1AEB84u: goto label_1aeb84;
            case 0x1AEB8Cu: goto label_1aeb8c;
            case 0x1AEBA8u: goto label_1aeba8;
            case 0x1AEBB4u: goto label_1aebb4;
            case 0x1AEBD0u: goto label_1aebd0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AE7C8u;
    // 0x1ae7c8: 0x0  nop
    ctx->pc = 0x1ae7c8u;
    // NOP
    // 0x1ae7cc: 0x0  nop
    ctx->pc = 0x1ae7ccu;
    // NOP
    // 0x1ae7d0: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x1ae7d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x1ae7d4: 0xffbf0070  sd          $ra, 0x70($sp)
    ctx->pc = 0x1ae7d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
    // 0x1ae7d8: 0x7fb60060  sq          $s6, 0x60($sp)
    ctx->pc = 0x1ae7d8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x1ae7dc: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1ae7dcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1ae7e0: 0x80b02d  daddu       $s6, $a0, $zero
    ctx->pc = 0x1ae7e0u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ae7e4: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1ae7e4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1ae7e8: 0xa0a82d  daddu       $s5, $a1, $zero
    ctx->pc = 0x1ae7e8u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ae7ec: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1ae7ecu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1ae7f0: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x1ae7f0u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ae7f4: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1ae7f4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1ae7f8: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x1ae7f8u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ae7fc: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1ae7fcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1ae800: 0x16a00006  bnez        $s5, . + 4 + (0x6 << 2)
    ctx->pc = 0x1AE800u;
    {
        const bool branch_taken_0x1ae800 = (GPR_U64(ctx, 21) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AE804u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE800u;
            // 0x1ae804: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ae800) {
            ctx->pc = 0x1AE81Cu;
            goto label_1ae81c;
        }
    }
    ctx->pc = 0x1AE808u;
    // 0x1ae808: 0xc06acbc  jal         func_1AB2F0
    ctx->pc = 0x1AE808u;
    SET_GPR_U32(ctx, 31, 0x1AE810u);
    ctx->pc = 0x1AE80Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE808u;
            // 0x1ae80c: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AB2F0u;
    if (runtime->hasFunction(0x1AB2F0u)) {
        auto targetFn = runtime->lookupFunction(0x1AB2F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE810u; }
        if (ctx->pc != 0x1AE810u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AB2F0_0x1ab2f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE810u; }
        if (ctx->pc != 0x1AE810u) { return; }
    }
    ctx->pc = 0x1AE810u;
label_1ae810:
    // 0x1ae810: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x1ae810u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ae814: 0x6400033  bltz        $s2, . + 4 + (0x33 << 2)
    ctx->pc = 0x1AE814u;
    {
        const bool branch_taken_0x1ae814 = (GPR_S64(ctx, 18) < 0);
        if (branch_taken_0x1ae814) {
            ctx->pc = 0x1AE8E4u;
            goto label_1ae8e4;
        }
    }
    ctx->pc = 0x1AE81Cu;
label_1ae81c:
    // 0x1ae81c: 0x3c03002c  lui         $v1, 0x2C
    ctx->pc = 0x1ae81cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)44 << 16));
    // 0x1ae820: 0x162080  sll         $a0, $s6, 2
    ctx->pc = 0x1ae820u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 22), 2));
    // 0x1ae824: 0x24638dc8  addiu       $v1, $v1, -0x7238
    ctx->pc = 0x1ae824u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294938056));
    // 0x1ae828: 0x648821  addu        $s1, $v1, $a0
    ctx->pc = 0x1ae828u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1ae82c: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x1ae82cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1ae830: 0x1060002c  beqz        $v1, . + 4 + (0x2C << 2)
    ctx->pc = 0x1AE830u;
    {
        const bool branch_taken_0x1ae830 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AE834u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE830u;
            // 0x1ae834: 0x2404000e  addiu       $a0, $zero, 0xE (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ae830) {
            ctx->pc = 0x1AE8E4u;
            goto label_1ae8e4;
        }
    }
    ctx->pc = 0x1AE838u;
    // 0x1ae838: 0xc06e0a8  jal         func_1B82A0
    ctx->pc = 0x1AE838u;
    SET_GPR_U32(ctx, 31, 0x1AE840u);
    ctx->pc = 0x1B82A0u;
    if (runtime->hasFunction(0x1B82A0u)) {
        auto targetFn = runtime->lookupFunction(0x1B82A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE840u; }
        if (ctx->pc != 0x1AE840u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B82A0_0x1b82a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE840u; }
        if (ctx->pc != 0x1AE840u) { return; }
    }
    ctx->pc = 0x1AE840u;
label_1ae840:
    // 0x1ae840: 0x14400028  bnez        $v0, . + 4 + (0x28 << 2)
    ctx->pc = 0x1AE840u;
    {
        const bool branch_taken_0x1ae840 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AE844u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE840u;
            // 0x1ae844: 0x161840  sll         $v1, $s6, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 22), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ae840) {
            ctx->pc = 0x1AE8E4u;
            goto label_1ae8e4;
        }
    }
    ctx->pc = 0x1AE848u;
    // 0x1ae848: 0x3c02002c  lui         $v0, 0x2C
    ctx->pc = 0x1ae848u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)44 << 16));
    // 0x1ae84c: 0x761821  addu        $v1, $v1, $s6
    ctx->pc = 0x1ae84cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 22)));
    // 0x1ae850: 0x24428d78  addiu       $v0, $v0, -0x7288
    ctx->pc = 0x1ae850u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937976));
    // 0x1ae854: 0x380c0  sll         $s0, $v1, 3
    ctx->pc = 0x1ae854u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1ae858: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1ae858u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1ae85c: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x1ae85cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ae860: 0xc06b7f4  jal         func_1ADFD0
    ctx->pc = 0x1AE860u;
    SET_GPR_U32(ctx, 31, 0x1AE868u);
    ctx->pc = 0x1AE864u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE860u;
            // 0x1ae864: 0x2c0202d  daddu       $a0, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ADFD0u;
    if (runtime->hasFunction(0x1ADFD0u)) {
        auto targetFn = runtime->lookupFunction(0x1ADFD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE868u; }
        if (ctx->pc != 0x1AE868u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ADFD0_0x1adfd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE868u; }
        if (ctx->pc != 0x1AE868u) { return; }
    }
    ctx->pc = 0x1AE868u;
label_1ae868:
    // 0x1ae868: 0xc06b9b4  jal         func_1AE6D0
    ctx->pc = 0x1AE868u;
    SET_GPR_U32(ctx, 31, 0x1AE870u);
    ctx->pc = 0x1AE86Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE868u;
            // 0x1ae86c: 0x2c0202d  daddu       $a0, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AE6D0u;
    if (runtime->hasFunction(0x1AE6D0u)) {
        auto targetFn = runtime->lookupFunction(0x1AE6D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE870u; }
        if (ctx->pc != 0x1AE870u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AE6D0_0x1ae6d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE870u; }
        if (ctx->pc != 0x1AE870u) { return; }
    }
    ctx->pc = 0x1AE870u;
label_1ae870:
    // 0x1ae870: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1ae870u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ae874: 0x16a2000f  bne         $s5, $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1AE874u;
    {
        const bool branch_taken_0x1ae874 = (GPR_U64(ctx, 21) != GPR_U64(ctx, 2));
        if (branch_taken_0x1ae874) {
            ctx->pc = 0x1AE8B4u;
            goto label_1ae8b4;
        }
    }
    ctx->pc = 0x1AE87Cu;
    // 0x1ae87c: 0x6610007  bgez        $s3, . + 4 + (0x7 << 2)
    ctx->pc = 0x1AE87Cu;
    {
        const bool branch_taken_0x1ae87c = (GPR_S64(ctx, 19) >= 0);
        if (branch_taken_0x1ae87c) {
            ctx->pc = 0x1AE89Cu;
            goto label_1ae89c;
        }
    }
    ctx->pc = 0x1AE884u;
    // 0x1ae884: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x1ae884u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1ae888: 0x280302d  daddu       $a2, $s4, $zero
    ctx->pc = 0x1ae888u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ae88c: 0xc04cd24  jal         func_133490
    ctx->pc = 0x1AE88Cu;
    SET_GPR_U32(ctx, 31, 0x1AE894u);
    ctx->pc = 0x1AE890u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE88Cu;
            // 0x1ae890: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x133490u;
    if (runtime->hasFunction(0x133490u)) {
        auto targetFn = runtime->lookupFunction(0x133490u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE894u; }
        if (ctx->pc != 0x1AE894u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00133490_0x133490(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE894u; }
        if (ctx->pc != 0x1AE894u) { return; }
    }
    ctx->pc = 0x1AE894u;
label_1ae894:
    // 0x1ae894: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1AE894u;
    {
        const bool branch_taken_0x1ae894 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ae894) {
            ctx->pc = 0x1AE8C4u;
            goto label_1ae8c4;
        }
    }
    ctx->pc = 0x1AE89Cu;
label_1ae89c:
    // 0x1ae89c: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x1ae89cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1ae8a0: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1ae8a0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ae8a4: 0xc04cd24  jal         func_133490
    ctx->pc = 0x1AE8A4u;
    SET_GPR_U32(ctx, 31, 0x1AE8ACu);
    ctx->pc = 0x1AE8A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE8A4u;
            // 0x1ae8a8: 0x280302d  daddu       $a2, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x133490u;
    if (runtime->hasFunction(0x133490u)) {
        auto targetFn = runtime->lookupFunction(0x133490u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE8ACu; }
        if (ctx->pc != 0x1AE8ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00133490_0x133490(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE8ACu; }
        if (ctx->pc != 0x1AE8ACu) { return; }
    }
    ctx->pc = 0x1AE8ACu;
label_1ae8ac:
    // 0x1ae8ac: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1AE8ACu;
    {
        const bool branch_taken_0x1ae8ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ae8ac) {
            ctx->pc = 0x1AE8C4u;
            goto label_1ae8c4;
        }
    }
    ctx->pc = 0x1AE8B4u;
label_1ae8b4:
    // 0x1ae8b4: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x1ae8b4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1ae8b8: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x1ae8b8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ae8bc: 0xc04cd24  jal         func_133490
    ctx->pc = 0x1AE8BCu;
    SET_GPR_U32(ctx, 31, 0x1AE8C4u);
    ctx->pc = 0x1AE8C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE8BCu;
            // 0x1ae8c0: 0x24050003  addiu       $a1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x133490u;
    if (runtime->hasFunction(0x133490u)) {
        auto targetFn = runtime->lookupFunction(0x133490u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE8C4u; }
        if (ctx->pc != 0x1AE8C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00133490_0x133490(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE8C4u; }
        if (ctx->pc != 0x1AE8C4u) { return; }
    }
    ctx->pc = 0x1AE8C4u;
label_1ae8c4:
    // 0x1ae8c4: 0x3c02002c  lui         $v0, 0x2C
    ctx->pc = 0x1ae8c4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)44 << 16));
    // 0x1ae8c8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1ae8c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ae8cc: 0x24428d73  addiu       $v0, $v0, -0x728D
    ctx->pc = 0x1ae8ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937971));
    // 0x1ae8d0: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1ae8d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1ae8d4: 0xa0430000  sb          $v1, 0x0($v0)
    ctx->pc = 0x1ae8d4u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ae8d8: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x1ae8d8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1ae8dc: 0xc04cb94  jal         func_132E50
    ctx->pc = 0x1AE8DCu;
    SET_GPR_U32(ctx, 31, 0x1AE8E4u);
    ctx->pc = 0x1AE8E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE8DCu;
            // 0x1ae8e0: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x132E50u;
    if (runtime->hasFunction(0x132E50u)) {
        auto targetFn = runtime->lookupFunction(0x132E50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE8E4u; }
        if (ctx->pc != 0x1AE8E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00132E50_0x132e50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE8E4u; }
        if (ctx->pc != 0x1AE8E4u) { return; }
    }
    ctx->pc = 0x1AE8E4u;
label_1ae8e4:
    // 0x1ae8e4: 0xdfbf0070  ld          $ra, 0x70($sp)
    ctx->pc = 0x1ae8e4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1ae8e8: 0x7bb60060  lq          $s6, 0x60($sp)
    ctx->pc = 0x1ae8e8u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1ae8ec: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1ae8ecu;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1ae8f0: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1ae8f0u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1ae8f4: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1ae8f4u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1ae8f8: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1ae8f8u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1ae8fc: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1ae8fcu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ae900: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ae900u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ae904: 0x3e00008  jr          $ra
    ctx->pc = 0x1AE904u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AE908u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE904u;
            // 0x1ae908: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AE740u: goto label_1ae740;
            case 0x1AE78Cu: goto label_1ae78c;
            case 0x1AE7A4u: goto label_1ae7a4;
            case 0x1AE810u: goto label_1ae810;
            case 0x1AE81Cu: goto label_1ae81c;
            case 0x1AE840u: goto label_1ae840;
            case 0x1AE868u: goto label_1ae868;
            case 0x1AE870u: goto label_1ae870;
            case 0x1AE894u: goto label_1ae894;
            case 0x1AE89Cu: goto label_1ae89c;
            case 0x1AE8ACu: goto label_1ae8ac;
            case 0x1AE8B4u: goto label_1ae8b4;
            case 0x1AE8C4u: goto label_1ae8c4;
            case 0x1AE8E4u: goto label_1ae8e4;
            case 0x1AE928u: goto label_1ae928;
            case 0x1AE938u: goto label_1ae938;
            case 0x1AE95Cu: goto label_1ae95c;
            case 0x1AE984u: goto label_1ae984;
            case 0x1AE98Cu: goto label_1ae98c;
            case 0x1AE9B8u: goto label_1ae9b8;
            case 0x1AE9E0u: goto label_1ae9e0;
            case 0x1AEA10u: goto label_1aea10;
            case 0x1AEA38u: goto label_1aea38;
            case 0x1AEA50u: goto label_1aea50;
            case 0x1AEA8Cu: goto label_1aea8c;
            case 0x1AEAB4u: goto label_1aeab4;
            case 0x1AEAC0u: goto label_1aeac0;
            case 0x1AEAC8u: goto label_1aeac8;
            case 0x1AEAECu: goto label_1aeaec;
            case 0x1AEB18u: goto label_1aeb18;
            case 0x1AEB40u: goto label_1aeb40;
            case 0x1AEB48u: goto label_1aeb48;
            case 0x1AEB84u: goto label_1aeb84;
            case 0x1AEB8Cu: goto label_1aeb8c;
            case 0x1AEBA8u: goto label_1aeba8;
            case 0x1AEBB4u: goto label_1aebb4;
            case 0x1AEBD0u: goto label_1aebd0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AE90Cu;
    // 0x1ae90c: 0x0  nop
    ctx->pc = 0x1ae90cu;
    // NOP
    // 0x1ae910: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1ae910u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1ae914: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1ae914u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1ae918: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1ae918u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1ae91c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1ae91cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ae920: 0xc06e0a8  jal         func_1B82A0
    ctx->pc = 0x1AE920u;
    SET_GPR_U32(ctx, 31, 0x1AE928u);
    ctx->pc = 0x1AE924u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE920u;
            // 0x1ae924: 0x2404000e  addiu       $a0, $zero, 0xE (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B82A0u;
    if (runtime->hasFunction(0x1B82A0u)) {
        auto targetFn = runtime->lookupFunction(0x1B82A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE928u; }
        if (ctx->pc != 0x1AE928u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B82A0_0x1b82a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE928u; }
        if (ctx->pc != 0x1AE928u) { return; }
    }
    ctx->pc = 0x1AE928u;
label_1ae928:
    // 0x1ae928: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AE928u;
    {
        const bool branch_taken_0x1ae928 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ae928) {
            ctx->pc = 0x1AE938u;
            goto label_1ae938;
        }
    }
    ctx->pc = 0x1AE930u;
    // 0x1ae930: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x1AE930u;
    {
        const bool branch_taken_0x1ae930 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AE934u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE930u;
            // 0x1ae934: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ae930) {
            ctx->pc = 0x1AE98Cu;
            goto label_1ae98c;
        }
    }
    ctx->pc = 0x1AE938u;
label_1ae938:
    // 0x1ae938: 0x3c02002c  lui         $v0, 0x2C
    ctx->pc = 0x1ae938u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)44 << 16));
    // 0x1ae93c: 0x101880  sll         $v1, $s0, 2
    ctx->pc = 0x1ae93cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1ae940: 0x24428dc8  addiu       $v0, $v0, -0x7238
    ctx->pc = 0x1ae940u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294938056));
    // 0x1ae944: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1ae944u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1ae948: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1ae948u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ae94c: 0x14800003  bnez        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AE94Cu;
    {
        const bool branch_taken_0x1ae94c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AE950u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE94Cu;
            // 0x1ae950: 0x101840  sll         $v1, $s0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ae94c) {
            ctx->pc = 0x1AE95Cu;
            goto label_1ae95c;
        }
    }
    ctx->pc = 0x1AE954u;
    // 0x1ae954: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1AE954u;
    {
        const bool branch_taken_0x1ae954 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AE958u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE954u;
            // 0x1ae958: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ae954) {
            ctx->pc = 0x1AE98Cu;
            goto label_1ae98c;
        }
    }
    ctx->pc = 0x1AE95Cu;
label_1ae95c:
    // 0x1ae95c: 0x3c02002c  lui         $v0, 0x2C
    ctx->pc = 0x1ae95cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)44 << 16));
    // 0x1ae960: 0x701821  addu        $v1, $v1, $s0
    ctx->pc = 0x1ae960u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1ae964: 0x24428d73  addiu       $v0, $v0, -0x728D
    ctx->pc = 0x1ae964u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937971));
    // 0x1ae968: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x1ae968u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1ae96c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1ae96cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1ae970: 0x80420000  lb          $v0, 0x0($v0)
    ctx->pc = 0x1ae970u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ae974: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AE974u;
    {
        const bool branch_taken_0x1ae974 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AE978u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE974u;
            // 0x1ae978: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ae974) {
            ctx->pc = 0x1AE984u;
            goto label_1ae984;
        }
    }
    ctx->pc = 0x1AE97Cu;
    // 0x1ae97c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1AE97Cu;
    {
        const bool branch_taken_0x1ae97c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ae97c) {
            ctx->pc = 0x1AE98Cu;
            goto label_1ae98c;
        }
    }
    ctx->pc = 0x1AE984u;
label_1ae984:
    // 0x1ae984: 0xc04cb88  jal         func_132E20
    ctx->pc = 0x1AE984u;
    SET_GPR_U32(ctx, 31, 0x1AE98Cu);
    ctx->pc = 0x132E20u;
    if (runtime->hasFunction(0x132E20u)) {
        auto targetFn = runtime->lookupFunction(0x132E20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE98Cu; }
        if (ctx->pc != 0x1AE98Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00132E20_0x132e20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE98Cu; }
        if (ctx->pc != 0x1AE98Cu) { return; }
    }
    ctx->pc = 0x1AE98Cu;
label_1ae98c:
    // 0x1ae98c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1ae98cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ae990: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ae990u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ae994: 0x3e00008  jr          $ra
    ctx->pc = 0x1AE994u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AE998u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE994u;
            // 0x1ae998: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AE740u: goto label_1ae740;
            case 0x1AE78Cu: goto label_1ae78c;
            case 0x1AE7A4u: goto label_1ae7a4;
            case 0x1AE810u: goto label_1ae810;
            case 0x1AE81Cu: goto label_1ae81c;
            case 0x1AE840u: goto label_1ae840;
            case 0x1AE868u: goto label_1ae868;
            case 0x1AE870u: goto label_1ae870;
            case 0x1AE894u: goto label_1ae894;
            case 0x1AE89Cu: goto label_1ae89c;
            case 0x1AE8ACu: goto label_1ae8ac;
            case 0x1AE8B4u: goto label_1ae8b4;
            case 0x1AE8C4u: goto label_1ae8c4;
            case 0x1AE8E4u: goto label_1ae8e4;
            case 0x1AE928u: goto label_1ae928;
            case 0x1AE938u: goto label_1ae938;
            case 0x1AE95Cu: goto label_1ae95c;
            case 0x1AE984u: goto label_1ae984;
            case 0x1AE98Cu: goto label_1ae98c;
            case 0x1AE9B8u: goto label_1ae9b8;
            case 0x1AE9E0u: goto label_1ae9e0;
            case 0x1AEA10u: goto label_1aea10;
            case 0x1AEA38u: goto label_1aea38;
            case 0x1AEA50u: goto label_1aea50;
            case 0x1AEA8Cu: goto label_1aea8c;
            case 0x1AEAB4u: goto label_1aeab4;
            case 0x1AEAC0u: goto label_1aeac0;
            case 0x1AEAC8u: goto label_1aeac8;
            case 0x1AEAECu: goto label_1aeaec;
            case 0x1AEB18u: goto label_1aeb18;
            case 0x1AEB40u: goto label_1aeb40;
            case 0x1AEB48u: goto label_1aeb48;
            case 0x1AEB84u: goto label_1aeb84;
            case 0x1AEB8Cu: goto label_1aeb8c;
            case 0x1AEBA8u: goto label_1aeba8;
            case 0x1AEBB4u: goto label_1aebb4;
            case 0x1AEBD0u: goto label_1aebd0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AE99Cu;
    // 0x1ae99c: 0x0  nop
    ctx->pc = 0x1ae99cu;
    // NOP
    // 0x1ae9a0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1ae9a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1ae9a4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1ae9a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1ae9a8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1ae9a8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1ae9ac: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1ae9acu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ae9b0: 0xc06e0a8  jal         func_1B82A0
    ctx->pc = 0x1AE9B0u;
    SET_GPR_U32(ctx, 31, 0x1AE9B8u);
    ctx->pc = 0x1AE9B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE9B0u;
            // 0x1ae9b4: 0x2404000e  addiu       $a0, $zero, 0xE (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B82A0u;
    if (runtime->hasFunction(0x1B82A0u)) {
        auto targetFn = runtime->lookupFunction(0x1B82A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE9B8u; }
        if (ctx->pc != 0x1AE9B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B82A0_0x1b82a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE9B8u; }
        if (ctx->pc != 0x1AE9B8u) { return; }
    }
    ctx->pc = 0x1AE9B8u;
label_1ae9b8:
    // 0x1ae9b8: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1AE9B8u;
    {
        const bool branch_taken_0x1ae9b8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AE9BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE9B8u;
            // 0x1ae9bc: 0x3c03002c  lui         $v1, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)44 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ae9b8) {
            ctx->pc = 0x1AE9E0u;
            goto label_1ae9e0;
        }
    }
    ctx->pc = 0x1AE9C0u;
    // 0x1ae9c0: 0x102080  sll         $a0, $s0, 2
    ctx->pc = 0x1ae9c0u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1ae9c4: 0x24638dc8  addiu       $v1, $v1, -0x7238
    ctx->pc = 0x1ae9c4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294938056));
    // 0x1ae9c8: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1ae9c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1ae9cc: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x1ae9ccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1ae9d0: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AE9D0u;
    {
        const bool branch_taken_0x1ae9d0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AE9D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE9D0u;
            // 0x1ae9d4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ae9d0) {
            ctx->pc = 0x1AE9E0u;
            goto label_1ae9e0;
        }
    }
    ctx->pc = 0x1AE9D8u;
    // 0x1ae9d8: 0xc06b9d0  jal         func_1AE740
    ctx->pc = 0x1AE9D8u;
    SET_GPR_U32(ctx, 31, 0x1AE9E0u);
    ctx->pc = 0x1AE740u;
    goto label_1ae740;
    ctx->pc = 0x1AE9E0u;
label_1ae9e0:
    // 0x1ae9e0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1ae9e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ae9e4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ae9e4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ae9e8: 0x3e00008  jr          $ra
    ctx->pc = 0x1AE9E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AE9ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE9E8u;
            // 0x1ae9ec: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AE740u: goto label_1ae740;
            case 0x1AE78Cu: goto label_1ae78c;
            case 0x1AE7A4u: goto label_1ae7a4;
            case 0x1AE810u: goto label_1ae810;
            case 0x1AE81Cu: goto label_1ae81c;
            case 0x1AE840u: goto label_1ae840;
            case 0x1AE868u: goto label_1ae868;
            case 0x1AE870u: goto label_1ae870;
            case 0x1AE894u: goto label_1ae894;
            case 0x1AE89Cu: goto label_1ae89c;
            case 0x1AE8ACu: goto label_1ae8ac;
            case 0x1AE8B4u: goto label_1ae8b4;
            case 0x1AE8C4u: goto label_1ae8c4;
            case 0x1AE8E4u: goto label_1ae8e4;
            case 0x1AE928u: goto label_1ae928;
            case 0x1AE938u: goto label_1ae938;
            case 0x1AE95Cu: goto label_1ae95c;
            case 0x1AE984u: goto label_1ae984;
            case 0x1AE98Cu: goto label_1ae98c;
            case 0x1AE9B8u: goto label_1ae9b8;
            case 0x1AE9E0u: goto label_1ae9e0;
            case 0x1AEA10u: goto label_1aea10;
            case 0x1AEA38u: goto label_1aea38;
            case 0x1AEA50u: goto label_1aea50;
            case 0x1AEA8Cu: goto label_1aea8c;
            case 0x1AEAB4u: goto label_1aeab4;
            case 0x1AEAC0u: goto label_1aeac0;
            case 0x1AEAC8u: goto label_1aeac8;
            case 0x1AEAECu: goto label_1aeaec;
            case 0x1AEB18u: goto label_1aeb18;
            case 0x1AEB40u: goto label_1aeb40;
            case 0x1AEB48u: goto label_1aeb48;
            case 0x1AEB84u: goto label_1aeb84;
            case 0x1AEB8Cu: goto label_1aeb8c;
            case 0x1AEBA8u: goto label_1aeba8;
            case 0x1AEBB4u: goto label_1aebb4;
            case 0x1AEBD0u: goto label_1aebd0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AE9F0u;
    // 0x1ae9f0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1ae9f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1ae9f4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1ae9f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1ae9f8: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1ae9f8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1ae9fc: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1ae9fcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1aea00: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1aea00u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aea04: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1aea04u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aea08: 0xc06e0a8  jal         func_1B82A0
    ctx->pc = 0x1AEA08u;
    SET_GPR_U32(ctx, 31, 0x1AEA10u);
    ctx->pc = 0x1AEA0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEA08u;
            // 0x1aea0c: 0x2404000e  addiu       $a0, $zero, 0xE (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B82A0u;
    if (runtime->hasFunction(0x1B82A0u)) {
        auto targetFn = runtime->lookupFunction(0x1B82A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEA10u; }
        if (ctx->pc != 0x1AEA10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B82A0_0x1b82a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEA10u; }
        if (ctx->pc != 0x1AEA10u) { return; }
    }
    ctx->pc = 0x1AEA10u;
label_1aea10:
    // 0x1aea10: 0x1440000f  bnez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1AEA10u;
    {
        const bool branch_taken_0x1aea10 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AEA14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEA10u;
            // 0x1aea14: 0x3c03002c  lui         $v1, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)44 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aea10) {
            ctx->pc = 0x1AEA50u;
            goto label_1aea50;
        }
    }
    ctx->pc = 0x1AEA18u;
    // 0x1aea18: 0x102080  sll         $a0, $s0, 2
    ctx->pc = 0x1aea18u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1aea1c: 0x24638dc8  addiu       $v1, $v1, -0x7238
    ctx->pc = 0x1aea1cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294938056));
    // 0x1aea20: 0x648021  addu        $s0, $v1, $a0
    ctx->pc = 0x1aea20u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1aea24: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x1aea24u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1aea28: 0x10600009  beqz        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1AEA28u;
    {
        const bool branch_taken_0x1aea28 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AEA2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEA28u;
            // 0x1aea2c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aea28) {
            ctx->pc = 0x1AEA50u;
            goto label_1aea50;
        }
    }
    ctx->pc = 0x1AEA30u;
    // 0x1aea30: 0xc06acbc  jal         func_1AB2F0
    ctx->pc = 0x1AEA30u;
    SET_GPR_U32(ctx, 31, 0x1AEA38u);
    ctx->pc = 0x1AB2F0u;
    if (runtime->hasFunction(0x1AB2F0u)) {
        auto targetFn = runtime->lookupFunction(0x1AB2F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEA38u; }
        if (ctx->pc != 0x1AEA38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AB2F0_0x1ab2f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEA38u; }
        if (ctx->pc != 0x1AEA38u) { return; }
    }
    ctx->pc = 0x1AEA38u;
label_1aea38:
    // 0x1aea38: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1aea38u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aea3c: 0x4c00004  bltz        $a2, . + 4 + (0x4 << 2)
    ctx->pc = 0x1AEA3Cu;
    {
        const bool branch_taken_0x1aea3c = (GPR_S64(ctx, 6) < 0);
        if (branch_taken_0x1aea3c) {
            ctx->pc = 0x1AEA50u;
            goto label_1aea50;
        }
    }
    ctx->pc = 0x1AEA44u;
    // 0x1aea44: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x1aea44u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1aea48: 0xc04a9ae  jal         func_12A6B8
    ctx->pc = 0x1AEA48u;
    SET_GPR_U32(ctx, 31, 0x1AEA50u);
    ctx->pc = 0x1AEA4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEA48u;
            // 0x1aea4c: 0x24050003  addiu       $a1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12A6B8u;
    if (runtime->hasFunction(0x12A6B8u)) {
        auto targetFn = runtime->lookupFunction(0x12A6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEA50u; }
        if (ctx->pc != 0x1AEA50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012A6B8_0x12a6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEA50u; }
        if (ctx->pc != 0x1AEA50u) { return; }
    }
    ctx->pc = 0x1AEA50u;
label_1aea50:
    // 0x1aea50: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1aea50u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1aea54: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1aea54u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1aea58: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1aea58u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1aea5c: 0x3e00008  jr          $ra
    ctx->pc = 0x1AEA5Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AEA60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEA5Cu;
            // 0x1aea60: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AE740u: goto label_1ae740;
            case 0x1AE78Cu: goto label_1ae78c;
            case 0x1AE7A4u: goto label_1ae7a4;
            case 0x1AE810u: goto label_1ae810;
            case 0x1AE81Cu: goto label_1ae81c;
            case 0x1AE840u: goto label_1ae840;
            case 0x1AE868u: goto label_1ae868;
            case 0x1AE870u: goto label_1ae870;
            case 0x1AE894u: goto label_1ae894;
            case 0x1AE89Cu: goto label_1ae89c;
            case 0x1AE8ACu: goto label_1ae8ac;
            case 0x1AE8B4u: goto label_1ae8b4;
            case 0x1AE8C4u: goto label_1ae8c4;
            case 0x1AE8E4u: goto label_1ae8e4;
            case 0x1AE928u: goto label_1ae928;
            case 0x1AE938u: goto label_1ae938;
            case 0x1AE95Cu: goto label_1ae95c;
            case 0x1AE984u: goto label_1ae984;
            case 0x1AE98Cu: goto label_1ae98c;
            case 0x1AE9B8u: goto label_1ae9b8;
            case 0x1AE9E0u: goto label_1ae9e0;
            case 0x1AEA10u: goto label_1aea10;
            case 0x1AEA38u: goto label_1aea38;
            case 0x1AEA50u: goto label_1aea50;
            case 0x1AEA8Cu: goto label_1aea8c;
            case 0x1AEAB4u: goto label_1aeab4;
            case 0x1AEAC0u: goto label_1aeac0;
            case 0x1AEAC8u: goto label_1aeac8;
            case 0x1AEAECu: goto label_1aeaec;
            case 0x1AEB18u: goto label_1aeb18;
            case 0x1AEB40u: goto label_1aeb40;
            case 0x1AEB48u: goto label_1aeb48;
            case 0x1AEB84u: goto label_1aeb84;
            case 0x1AEB8Cu: goto label_1aeb8c;
            case 0x1AEBA8u: goto label_1aeba8;
            case 0x1AEBB4u: goto label_1aebb4;
            case 0x1AEBD0u: goto label_1aebd0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AEA64u;
    // 0x1aea64: 0x0  nop
    ctx->pc = 0x1aea64u;
    // NOP
    // 0x1aea68: 0x0  nop
    ctx->pc = 0x1aea68u;
    // NOP
    // 0x1aea6c: 0x0  nop
    ctx->pc = 0x1aea6cu;
    // NOP
    // 0x1aea70: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1aea70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1aea74: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1aea74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1aea78: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1aea78u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1aea7c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1aea7cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aea80: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1aea80u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1aea84: 0xc06e0a8  jal         func_1B82A0
    ctx->pc = 0x1AEA84u;
    SET_GPR_U32(ctx, 31, 0x1AEA8Cu);
    ctx->pc = 0x1AEA88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEA84u;
            // 0x1aea88: 0x2404000e  addiu       $a0, $zero, 0xE (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B82A0u;
    if (runtime->hasFunction(0x1B82A0u)) {
        auto targetFn = runtime->lookupFunction(0x1B82A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEA8Cu; }
        if (ctx->pc != 0x1AEA8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B82A0_0x1b82a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEA8Cu; }
        if (ctx->pc != 0x1AEA8Cu) { return; }
    }
    ctx->pc = 0x1AEA8Cu;
label_1aea8c:
    // 0x1aea8c: 0x14400017  bnez        $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x1AEA8Cu;
    {
        const bool branch_taken_0x1aea8c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AEA90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEA8Cu;
            // 0x1aea90: 0x3c03002c  lui         $v1, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)44 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aea8c) {
            ctx->pc = 0x1AEAECu;
            goto label_1aeaec;
        }
    }
    ctx->pc = 0x1AEA94u;
    // 0x1aea94: 0x112080  sll         $a0, $s1, 2
    ctx->pc = 0x1aea94u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
    // 0x1aea98: 0x24638dc8  addiu       $v1, $v1, -0x7238
    ctx->pc = 0x1aea98u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294938056));
    // 0x1aea9c: 0x648021  addu        $s0, $v1, $a0
    ctx->pc = 0x1aea9cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1aeaa0: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x1aeaa0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1aeaa4: 0x10800011  beqz        $a0, . + 4 + (0x11 << 2)
    ctx->pc = 0x1AEAA4u;
    {
        const bool branch_taken_0x1aeaa4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1aeaa4) {
            ctx->pc = 0x1AEAECu;
            goto label_1aeaec;
        }
    }
    ctx->pc = 0x1AEAACu;
    // 0x1aeaac: 0xc04aa3c  jal         func_12A8F0
    ctx->pc = 0x1AEAACu;
    SET_GPR_U32(ctx, 31, 0x1AEAB4u);
    ctx->pc = 0x12A8F0u;
    if (runtime->hasFunction(0x12A8F0u)) {
        auto targetFn = runtime->lookupFunction(0x12A8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEAB4u; }
        if (ctx->pc != 0x1AEAB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012A8F0_0x12a8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEAB4u; }
        if (ctx->pc != 0x1AEAB4u) { return; }
    }
    ctx->pc = 0x1AEAB4u;
label_1aeab4:
    // 0x1aeab4: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x1aeab4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1aeab8: 0xc04aa0c  jal         func_12A830
    ctx->pc = 0x1AEAB8u;
    SET_GPR_U32(ctx, 31, 0x1AEAC0u);
    ctx->pc = 0x1AEABCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEAB8u;
            // 0x1aeabc: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12A830u;
    if (runtime->hasFunction(0x12A830u)) {
        auto targetFn = runtime->lookupFunction(0x12A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEAC0u; }
        if (ctx->pc != 0x1AEAC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012A830_0x12a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEAC0u; }
        if (ctx->pc != 0x1AEAC0u) { return; }
    }
    ctx->pc = 0x1AEAC0u;
label_1aeac0:
    // 0x1aeac0: 0xc04a9e0  jal         func_12A780
    ctx->pc = 0x1AEAC0u;
    SET_GPR_U32(ctx, 31, 0x1AEAC8u);
    ctx->pc = 0x1AEAC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEAC0u;
            // 0x1aeac4: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12A780u;
    if (runtime->hasFunction(0x12A780u)) {
        auto targetFn = runtime->lookupFunction(0x12A780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEAC8u; }
        if (ctx->pc != 0x1AEAC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012A780_0x12a780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEAC8u; }
        if (ctx->pc != 0x1AEAC8u) { return; }
    }
    ctx->pc = 0x1AEAC8u;
label_1aeac8:
    // 0x1aeac8: 0x111840  sll         $v1, $s1, 1
    ctx->pc = 0x1aeac8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 1));
    // 0x1aeacc: 0x3c02002c  lui         $v0, 0x2C
    ctx->pc = 0x1aeaccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)44 << 16));
    // 0x1aead0: 0x711821  addu        $v1, $v1, $s1
    ctx->pc = 0x1aead0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x1aead4: 0x24428d78  addiu       $v0, $v0, -0x7288
    ctx->pc = 0x1aead4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937976));
    // 0x1aead8: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x1aead8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1aeadc: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1aeadcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1aeae0: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x1aeae0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1aeae4: 0xc06b7f4  jal         func_1ADFD0
    ctx->pc = 0x1AEAE4u;
    SET_GPR_U32(ctx, 31, 0x1AEAECu);
    ctx->pc = 0x1AEAE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEAE4u;
            // 0x1aeae8: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ADFD0u;
    if (runtime->hasFunction(0x1ADFD0u)) {
        auto targetFn = runtime->lookupFunction(0x1ADFD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEAECu; }
        if (ctx->pc != 0x1AEAECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ADFD0_0x1adfd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEAECu; }
        if (ctx->pc != 0x1AEAECu) { return; }
    }
    ctx->pc = 0x1AEAECu;
label_1aeaec:
    // 0x1aeaec: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1aeaecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1aeaf0: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1aeaf0u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1aeaf4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1aeaf4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1aeaf8: 0x3e00008  jr          $ra
    ctx->pc = 0x1AEAF8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AEAFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEAF8u;
            // 0x1aeafc: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AE740u: goto label_1ae740;
            case 0x1AE78Cu: goto label_1ae78c;
            case 0x1AE7A4u: goto label_1ae7a4;
            case 0x1AE810u: goto label_1ae810;
            case 0x1AE81Cu: goto label_1ae81c;
            case 0x1AE840u: goto label_1ae840;
            case 0x1AE868u: goto label_1ae868;
            case 0x1AE870u: goto label_1ae870;
            case 0x1AE894u: goto label_1ae894;
            case 0x1AE89Cu: goto label_1ae89c;
            case 0x1AE8ACu: goto label_1ae8ac;
            case 0x1AE8B4u: goto label_1ae8b4;
            case 0x1AE8C4u: goto label_1ae8c4;
            case 0x1AE8E4u: goto label_1ae8e4;
            case 0x1AE928u: goto label_1ae928;
            case 0x1AE938u: goto label_1ae938;
            case 0x1AE95Cu: goto label_1ae95c;
            case 0x1AE984u: goto label_1ae984;
            case 0x1AE98Cu: goto label_1ae98c;
            case 0x1AE9B8u: goto label_1ae9b8;
            case 0x1AE9E0u: goto label_1ae9e0;
            case 0x1AEA10u: goto label_1aea10;
            case 0x1AEA38u: goto label_1aea38;
            case 0x1AEA50u: goto label_1aea50;
            case 0x1AEA8Cu: goto label_1aea8c;
            case 0x1AEAB4u: goto label_1aeab4;
            case 0x1AEAC0u: goto label_1aeac0;
            case 0x1AEAC8u: goto label_1aeac8;
            case 0x1AEAECu: goto label_1aeaec;
            case 0x1AEB18u: goto label_1aeb18;
            case 0x1AEB40u: goto label_1aeb40;
            case 0x1AEB48u: goto label_1aeb48;
            case 0x1AEB84u: goto label_1aeb84;
            case 0x1AEB8Cu: goto label_1aeb8c;
            case 0x1AEBA8u: goto label_1aeba8;
            case 0x1AEBB4u: goto label_1aebb4;
            case 0x1AEBD0u: goto label_1aebd0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AEB00u;
    // 0x1aeb00: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1aeb00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1aeb04: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1aeb04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1aeb08: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1aeb08u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1aeb0c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1aeb0cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aeb10: 0xc06e0a8  jal         func_1B82A0
    ctx->pc = 0x1AEB10u;
    SET_GPR_U32(ctx, 31, 0x1AEB18u);
    ctx->pc = 0x1AEB14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEB10u;
            // 0x1aeb14: 0x2404000e  addiu       $a0, $zero, 0xE (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B82A0u;
    if (runtime->hasFunction(0x1B82A0u)) {
        auto targetFn = runtime->lookupFunction(0x1B82A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEB18u; }
        if (ctx->pc != 0x1AEB18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B82A0_0x1b82a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEB18u; }
        if (ctx->pc != 0x1AEB18u) { return; }
    }
    ctx->pc = 0x1AEB18u;
label_1aeb18:
    // 0x1aeb18: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1AEB18u;
    {
        const bool branch_taken_0x1aeb18 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AEB1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEB18u;
            // 0x1aeb1c: 0x3c03002c  lui         $v1, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)44 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aeb18) {
            ctx->pc = 0x1AEB48u;
            goto label_1aeb48;
        }
    }
    ctx->pc = 0x1AEB20u;
    // 0x1aeb20: 0x102080  sll         $a0, $s0, 2
    ctx->pc = 0x1aeb20u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1aeb24: 0x24638dc8  addiu       $v1, $v1, -0x7238
    ctx->pc = 0x1aeb24u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294938056));
    // 0x1aeb28: 0x648021  addu        $s0, $v1, $a0
    ctx->pc = 0x1aeb28u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1aeb2c: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x1aeb2cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1aeb30: 0x10800005  beqz        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1AEB30u;
    {
        const bool branch_taken_0x1aeb30 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1aeb30) {
            ctx->pc = 0x1AEB48u;
            goto label_1aeb48;
        }
    }
    ctx->pc = 0x1AEB38u;
    // 0x1aeb38: 0xc04aa3a  jal         func_12A8E8
    ctx->pc = 0x1AEB38u;
    SET_GPR_U32(ctx, 31, 0x1AEB40u);
    ctx->pc = 0x12A8E8u;
    if (runtime->hasFunction(0x12A8E8u)) {
        auto targetFn = runtime->lookupFunction(0x12A8E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEB40u; }
        if (ctx->pc != 0x1AEB40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012A8E8_0x12a8e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEB40u; }
        if (ctx->pc != 0x1AEB40u) { return; }
    }
    ctx->pc = 0x1AEB40u;
label_1aeb40:
    // 0x1aeb40: 0xc04c78e  jal         func_131E38
    ctx->pc = 0x1AEB40u;
    SET_GPR_U32(ctx, 31, 0x1AEB48u);
    ctx->pc = 0x1AEB44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEB40u;
            // 0x1aeb44: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x131E38u;
    if (runtime->hasFunction(0x131E38u)) {
        auto targetFn = runtime->lookupFunction(0x131E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEB48u; }
        if (ctx->pc != 0x1AEB48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00131E38_0x131e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEB48u; }
        if (ctx->pc != 0x1AEB48u) { return; }
    }
    ctx->pc = 0x1AEB48u;
label_1aeb48:
    // 0x1aeb48: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1aeb48u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1aeb4c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1aeb4cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1aeb50: 0x3e00008  jr          $ra
    ctx->pc = 0x1AEB50u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AEB54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEB50u;
            // 0x1aeb54: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AE740u: goto label_1ae740;
            case 0x1AE78Cu: goto label_1ae78c;
            case 0x1AE7A4u: goto label_1ae7a4;
            case 0x1AE810u: goto label_1ae810;
            case 0x1AE81Cu: goto label_1ae81c;
            case 0x1AE840u: goto label_1ae840;
            case 0x1AE868u: goto label_1ae868;
            case 0x1AE870u: goto label_1ae870;
            case 0x1AE894u: goto label_1ae894;
            case 0x1AE89Cu: goto label_1ae89c;
            case 0x1AE8ACu: goto label_1ae8ac;
            case 0x1AE8B4u: goto label_1ae8b4;
            case 0x1AE8C4u: goto label_1ae8c4;
            case 0x1AE8E4u: goto label_1ae8e4;
            case 0x1AE928u: goto label_1ae928;
            case 0x1AE938u: goto label_1ae938;
            case 0x1AE95Cu: goto label_1ae95c;
            case 0x1AE984u: goto label_1ae984;
            case 0x1AE98Cu: goto label_1ae98c;
            case 0x1AE9B8u: goto label_1ae9b8;
            case 0x1AE9E0u: goto label_1ae9e0;
            case 0x1AEA10u: goto label_1aea10;
            case 0x1AEA38u: goto label_1aea38;
            case 0x1AEA50u: goto label_1aea50;
            case 0x1AEA8Cu: goto label_1aea8c;
            case 0x1AEAB4u: goto label_1aeab4;
            case 0x1AEAC0u: goto label_1aeac0;
            case 0x1AEAC8u: goto label_1aeac8;
            case 0x1AEAECu: goto label_1aeaec;
            case 0x1AEB18u: goto label_1aeb18;
            case 0x1AEB40u: goto label_1aeb40;
            case 0x1AEB48u: goto label_1aeb48;
            case 0x1AEB84u: goto label_1aeb84;
            case 0x1AEB8Cu: goto label_1aeb8c;
            case 0x1AEBA8u: goto label_1aeba8;
            case 0x1AEBB4u: goto label_1aebb4;
            case 0x1AEBD0u: goto label_1aebd0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AEB58u;
    // 0x1aeb58: 0x0  nop
    ctx->pc = 0x1aeb58u;
    // NOP
    // 0x1aeb5c: 0x0  nop
    ctx->pc = 0x1aeb5cu;
    // NOP
    // 0x1aeb60: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1aeb60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1aeb64: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1aeb64u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1aeb68: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1aeb68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1aeb6c: 0x8c238dc8  lw          $v1, -0x7238($at)
    ctx->pc = 0x1aeb6cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294938056)));
    // 0x1aeb70: 0x10600017  beqz        $v1, . + 4 + (0x17 << 2)
    ctx->pc = 0x1AEB70u;
    {
        const bool branch_taken_0x1aeb70 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AEB74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEB70u;
            // 0x1aeb74: 0x3c01002c  lui         $at, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aeb70) {
            ctx->pc = 0x1AEBD0u;
            goto label_1aebd0;
        }
    }
    ctx->pc = 0x1AEB78u;
    // 0x1aeb78: 0x8c258d78  lw          $a1, -0x7288($at)
    ctx->pc = 0x1aeb78u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294937976)));
    // 0x1aeb7c: 0xc06b7f4  jal         func_1ADFD0
    ctx->pc = 0x1AEB7Cu;
    SET_GPR_U32(ctx, 31, 0x1AEB84u);
    ctx->pc = 0x1AEB80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEB7Cu;
            // 0x1aeb80: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ADFD0u;
    if (runtime->hasFunction(0x1ADFD0u)) {
        auto targetFn = runtime->lookupFunction(0x1ADFD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEB84u; }
        if (ctx->pc != 0x1AEB84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ADFD0_0x1adfd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEB84u; }
        if (ctx->pc != 0x1AEB84u) { return; }
    }
    ctx->pc = 0x1AEB84u;
label_1aeb84:
    // 0x1aeb84: 0xc06b9b4  jal         func_1AE6D0
    ctx->pc = 0x1AEB84u;
    SET_GPR_U32(ctx, 31, 0x1AEB8Cu);
    ctx->pc = 0x1AEB88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEB84u;
            // 0x1aeb88: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AE6D0u;
    if (runtime->hasFunction(0x1AE6D0u)) {
        auto targetFn = runtime->lookupFunction(0x1AE6D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEB8Cu; }
        if (ctx->pc != 0x1AEB8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AE6D0_0x1ae6d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEB8Cu; }
        if (ctx->pc != 0x1AEB8Cu) { return; }
    }
    ctx->pc = 0x1AEB8Cu;
label_1aeb8c:
    // 0x1aeb8c: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1aeb8cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1aeb90: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1aeb90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1aeb94: 0x8c248dc8  lw          $a0, -0x7238($at)
    ctx->pc = 0x1aeb94u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294938056)));
    // 0x1aeb98: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1aeb98u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aeb9c: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1aeb9cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1aeba0: 0xc04cb94  jal         func_132E50
    ctx->pc = 0x1AEBA0u;
    SET_GPR_U32(ctx, 31, 0x1AEBA8u);
    ctx->pc = 0x1AEBA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEBA0u;
            // 0x1aeba4: 0xa0228d73  sb          $v0, -0x728D($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 4294937971), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x132E50u;
    if (runtime->hasFunction(0x132E50u)) {
        auto targetFn = runtime->lookupFunction(0x132E50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEBA8u; }
        if (ctx->pc != 0x1AEBA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00132E50_0x132e50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEBA8u; }
        if (ctx->pc != 0x1AEBA8u) { return; }
    }
    ctx->pc = 0x1AEBA8u;
label_1aeba8:
    // 0x1aeba8: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1aeba8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1aebac: 0xc06acbc  jal         func_1AB2F0
    ctx->pc = 0x1AEBACu;
    SET_GPR_U32(ctx, 31, 0x1AEBB4u);
    ctx->pc = 0x1AEBB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEBACu;
            // 0x1aebb0: 0x2484fe18  addiu       $a0, $a0, -0x1E8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966808));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AB2F0u;
    if (runtime->hasFunction(0x1AB2F0u)) {
        auto targetFn = runtime->lookupFunction(0x1AB2F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEBB4u; }
        if (ctx->pc != 0x1AEBB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AB2F0_0x1ab2f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEBB4u; }
        if (ctx->pc != 0x1AEBB4u) { return; }
    }
    ctx->pc = 0x1AEBB4u;
label_1aebb4:
    // 0x1aebb4: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1aebb4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aebb8: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1aebb8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1aebbc: 0x10c30004  beq         $a2, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1AEBBCu;
    {
        const bool branch_taken_0x1aebbc = (GPR_U64(ctx, 6) == GPR_U64(ctx, 3));
        ctx->pc = 0x1AEBC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEBBCu;
            // 0x1aebc0: 0x3c01002c  lui         $at, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aebbc) {
            ctx->pc = 0x1AEBD0u;
            goto label_1aebd0;
        }
    }
    ctx->pc = 0x1AEBC4u;
    // 0x1aebc4: 0x8c248dc8  lw          $a0, -0x7238($at)
    ctx->pc = 0x1aebc4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294938056)));
    // 0x1aebc8: 0xc04cd24  jal         func_133490
    ctx->pc = 0x1AEBC8u;
    SET_GPR_U32(ctx, 31, 0x1AEBD0u);
    ctx->pc = 0x1AEBCCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEBC8u;
            // 0x1aebcc: 0x24050003  addiu       $a1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x133490u;
    if (runtime->hasFunction(0x133490u)) {
        auto targetFn = runtime->lookupFunction(0x133490u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEBD0u; }
        if (ctx->pc != 0x1AEBD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00133490_0x133490(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEBD0u; }
        if (ctx->pc != 0x1AEBD0u) { return; }
    }
    ctx->pc = 0x1AEBD0u;
label_1aebd0:
    // 0x1aebd0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1aebd0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1aebd4: 0x3e00008  jr          $ra
    ctx->pc = 0x1AEBD4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AEBD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEBD4u;
            // 0x1aebd8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AE740u: goto label_1ae740;
            case 0x1AE78Cu: goto label_1ae78c;
            case 0x1AE7A4u: goto label_1ae7a4;
            case 0x1AE810u: goto label_1ae810;
            case 0x1AE81Cu: goto label_1ae81c;
            case 0x1AE840u: goto label_1ae840;
            case 0x1AE868u: goto label_1ae868;
            case 0x1AE870u: goto label_1ae870;
            case 0x1AE894u: goto label_1ae894;
            case 0x1AE89Cu: goto label_1ae89c;
            case 0x1AE8ACu: goto label_1ae8ac;
            case 0x1AE8B4u: goto label_1ae8b4;
            case 0x1AE8C4u: goto label_1ae8c4;
            case 0x1AE8E4u: goto label_1ae8e4;
            case 0x1AE928u: goto label_1ae928;
            case 0x1AE938u: goto label_1ae938;
            case 0x1AE95Cu: goto label_1ae95c;
            case 0x1AE984u: goto label_1ae984;
            case 0x1AE98Cu: goto label_1ae98c;
            case 0x1AE9B8u: goto label_1ae9b8;
            case 0x1AE9E0u: goto label_1ae9e0;
            case 0x1AEA10u: goto label_1aea10;
            case 0x1AEA38u: goto label_1aea38;
            case 0x1AEA50u: goto label_1aea50;
            case 0x1AEA8Cu: goto label_1aea8c;
            case 0x1AEAB4u: goto label_1aeab4;
            case 0x1AEAC0u: goto label_1aeac0;
            case 0x1AEAC8u: goto label_1aeac8;
            case 0x1AEAECu: goto label_1aeaec;
            case 0x1AEB18u: goto label_1aeb18;
            case 0x1AEB40u: goto label_1aeb40;
            case 0x1AEB48u: goto label_1aeb48;
            case 0x1AEB84u: goto label_1aeb84;
            case 0x1AEB8Cu: goto label_1aeb8c;
            case 0x1AEBA8u: goto label_1aeba8;
            case 0x1AEBB4u: goto label_1aebb4;
            case 0x1AEBD0u: goto label_1aebd0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AEBDCu;
    // 0x1aebdc: 0x0  nop
    ctx->pc = 0x1aebdcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
