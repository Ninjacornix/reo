#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00160A08
// Address: 0x160a08 - 0x160ad4
void sub_00160A08_0x160a08(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00160A08_0x160a08");
#endif

    switch (ctx->pc) {
        case 0x160a2cu: goto label_160a2c;
        case 0x160a60u: goto label_160a60;
        case 0x160a74u: goto label_160a74;
        case 0x160a84u: goto label_160a84;
        case 0x160a90u: goto label_160a90;
        case 0x160a9cu: goto label_160a9c;
        case 0x160aa8u: goto label_160aa8;
        default: break;
    }

    ctx->pc = 0x160a08u;

    // 0x160a08: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x160a08u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x160a0c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x160a0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x160a10: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x160a10u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160a14: 0xe7b40020  swc1        $f20, 0x20($sp)
    ctx->pc = 0x160a14u;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 32), bits); }
    // 0x160a18: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x160a18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x160a1c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x160a1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x160a20: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x160a20u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x160a24: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x160A24u;
    SET_GPR_U32(ctx, 31, 0x160A2Cu);
    ctx->pc = 0x160A28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160A24u;
            // 0x160a28: 0x46006506  mov.s       $f20, $f12 (Delay Slot)
        ctx->f[20] = FPU_MOV_S(ctx->f[12]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160A2Cu; }
        if (ctx->pc != 0x160A2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160A2Cu; }
        if (ctx->pc != 0x160A2Cu) { return; }
    }
    ctx->pc = 0x160A2Cu;
label_160a2c:
    // 0x160a2c: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x160A2Cu;
    {
        const bool branch_taken_0x160a2c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x160A30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160A2Cu;
            // 0x160a30: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160a2c) {
            ctx->pc = 0x160A58u;
            goto label_160a58;
        }
    }
    ctx->pc = 0x160A34u;
    // 0x160a34: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x160a34u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x160a38: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x160a38u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x160a3c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x160a3cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x160a40: 0x2484f878  addiu       $a0, $a0, -0x788
    ctx->pc = 0x160a40u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294965368));
    // 0x160a44: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x160a44u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x160a48: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x160a48u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x160a4c: 0xc7b40020  lwc1        $f20, 0x20($sp)
    ctx->pc = 0x160a4cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 32)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x160a50: 0x8058dd4  j           func_163750
    ctx->pc = 0x160A50u;
    ctx->pc = 0x160A54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160A50u;
            // 0x160a54: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x160A58u;
label_160a58:
    // 0x160a58: 0xc057ec8  jal         func_15FB20
    ctx->pc = 0x160A58u;
    SET_GPR_U32(ctx, 31, 0x160A60u);
    ctx->pc = 0x15FB20u;
    if (runtime->hasFunction(0x15FB20u)) {
        auto targetFn = runtime->lookupFunction(0x15FB20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160A60u; }
        if (ctx->pc != 0x160A60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FB20_0x15fb20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160A60u; }
        if (ctx->pc != 0x160A60u) { return; }
    }
    ctx->pc = 0x160A60u;
label_160a60:
    // 0x160a60: 0x3c01447a  lui         $at, 0x447A
    ctx->pc = 0x160a60u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)17530 << 16));
    // 0x160a64: 0x44816000  mtc1        $at, $f12
    ctx->pc = 0x160a64u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[12], &bits, sizeof(bits)); }
    // 0x160a68: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x160a68u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160a6c: 0xc04462e  jal         func_1118B8
    ctx->pc = 0x160A6Cu;
    SET_GPR_U32(ctx, 31, 0x160A74u);
    ctx->pc = 0x160A70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160A6Cu;
            // 0x160a70: 0x460ca302  mul.s       $f12, $f20, $f12 (Delay Slot)
        ctx->f[12] = FPU_MUL_S(ctx->f[20], ctx->f[12]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1118B8u;
    if (runtime->hasFunction(0x1118B8u)) {
        auto targetFn = runtime->lookupFunction(0x1118B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160A74u; }
        if (ctx->pc != 0x160A74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001118B8_0x1118b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160A74u; }
        if (ctx->pc != 0x160A74u) { return; }
    }
    ctx->pc = 0x160A74u;
label_160a74:
    // 0x160a74: 0x3405ff80  ori         $a1, $zero, 0xFF80
    ctx->pc = 0x160a74u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65408);
    // 0x160a78: 0x52bbc  dsll32      $a1, $a1, 14
    ctx->pc = 0x160a78u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 14));
    // 0x160a7c: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x160A7Cu;
    SET_GPR_U32(ctx, 31, 0x160A84u);
    ctx->pc = 0x160A80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160A7Cu;
            // 0x160a80: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160A84u; }
        if (ctx->pc != 0x160A84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160A84u; }
        if (ctx->pc != 0x160A84u) { return; }
    }
    ctx->pc = 0x160A84u;
label_160a84:
    // 0x160a84: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x160a84u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160a88: 0xc0448e8  jal         func_1123A0
    ctx->pc = 0x160A88u;
    SET_GPR_U32(ctx, 31, 0x160A90u);
    ctx->pc = 0x160A8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160A88u;
            // 0x160a8c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1123A0u;
    if (runtime->hasFunction(0x1123A0u)) {
        auto targetFn = runtime->lookupFunction(0x1123A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160A90u; }
        if (ctx->pc != 0x160A90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001123A0_0x1123a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160A90u; }
        if (ctx->pc != 0x160A90u) { return; }
    }
    ctx->pc = 0x160A90u;
label_160a90:
    // 0x160a90: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x160a90u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160a94: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x160A94u;
    SET_GPR_U32(ctx, 31, 0x160A9Cu);
    ctx->pc = 0x160A98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160A94u;
            // 0x160a98: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160A9Cu; }
        if (ctx->pc != 0x160A9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160A9Cu; }
        if (ctx->pc != 0x160A9Cu) { return; }
    }
    ctx->pc = 0x160A9Cu;
label_160a9c:
    // 0x160a9c: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x160a9cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160aa0: 0xc0448a6  jal         func_112298
    ctx->pc = 0x160AA0u;
    SET_GPR_U32(ctx, 31, 0x160AA8u);
    ctx->pc = 0x160AA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160AA0u;
            // 0x160aa4: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160AA8u; }
        if (ctx->pc != 0x160AA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160AA8u; }
        if (ctx->pc != 0x160AA8u) { return; }
    }
    ctx->pc = 0x160AA8u;
label_160aa8:
    // 0x160aa8: 0x2605ffff  addiu       $a1, $s0, -0x1
    ctx->pc = 0x160aa8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
    // 0x160aac: 0x2102a  slt         $v0, $zero, $v0
    ctx->pc = 0x160aacu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x160ab0: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x160ab0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160ab4: 0x202280a  movz        $a1, $s0, $v0
    ctx->pc = 0x160ab4u;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 16));
    // 0x160ab8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x160ab8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x160abc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x160abcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x160ac0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x160ac0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x160ac4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x160ac4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x160ac8: 0xc7b40020  lwc1        $f20, 0x20($sp)
    ctx->pc = 0x160ac8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 32)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x160acc: 0x805c8b4  j           func_1722D0
    ctx->pc = 0x160ACCu;
    ctx->pc = 0x160AD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160ACCu;
            // 0x160ad0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1722D0u;
    if (runtime->hasFunction(0x1722D0u)) {
        auto targetFn = runtime->lookupFunction(0x1722D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001722D0_0x1722d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x160AD4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
