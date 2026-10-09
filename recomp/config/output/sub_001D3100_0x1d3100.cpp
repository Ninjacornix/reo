#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D3100
// Address: 0x1d3100 - 0x1d3350
void sub_001D3100_0x1d3100(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D3100_0x1d3100");
#endif

    switch (ctx->pc) {
        case 0x1d312cu: goto label_1d312c;
        case 0x1d3138u: goto label_1d3138;
        case 0x1d3148u: goto label_1d3148;
        case 0x1d3150u: goto label_1d3150;
        case 0x1d31a8u: goto label_1d31a8;
        case 0x1d31b0u: goto label_1d31b0;
        case 0x1d31c0u: goto label_1d31c0;
        case 0x1d31c8u: goto label_1d31c8;
        case 0x1d31d4u: goto label_1d31d4;
        case 0x1d31e0u: goto label_1d31e0;
        case 0x1d31ecu: goto label_1d31ec;
        case 0x1d3250u: goto label_1d3250;
        case 0x1d3280u: goto label_1d3280;
        case 0x1d32b4u: goto label_1d32b4;
        case 0x1d3304u: goto label_1d3304;
        case 0x1d330cu: goto label_1d330c;
        default: break;
    }

    ctx->pc = 0x1d3100u;

    // 0x1d3100: 0x27bdfe80  addiu       $sp, $sp, -0x180
    ctx->pc = 0x1d3100u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966912));
    // 0x1d3104: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x1d3104u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x1d3108: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1d3108u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1d310c: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1d310cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d3110: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d3110u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d3114: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d3114u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d3118: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1d3118u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d311c: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1d311cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d3120: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d3120u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d3124: 0xc068abc  jal         func_1A2AF0
    ctx->pc = 0x1D3124u;
    SET_GPR_U32(ctx, 31, 0x1D312Cu);
    ctx->pc = 0x1D3128u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3124u;
            // 0x1d3128: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A2AF0u;
    if (runtime->hasFunction(0x1A2AF0u)) {
        auto targetFn = runtime->lookupFunction(0x1A2AF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D312Cu; }
        if (ctx->pc != 0x1D312Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A2AF0_0x1a2af0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D312Cu; }
        if (ctx->pc != 0x1D312Cu) { return; }
    }
    ctx->pc = 0x1D312Cu;
label_1d312c:
    // 0x1d312c: 0xa6420816  sh          $v0, 0x816($s2)
    ctx->pc = 0x1d312cu;
    WRITE16(ADD32(GPR_U32(ctx, 18), 2070), (uint16_t)GPR_U32(ctx, 2));
    // 0x1d3130: 0xc068acc  jal         func_1A2B30
    ctx->pc = 0x1D3130u;
    SET_GPR_U32(ctx, 31, 0x1D3138u);
    ctx->pc = 0x1D3134u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3130u;
            // 0x1d3134: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A2B30u;
    if (runtime->hasFunction(0x1A2B30u)) {
        auto targetFn = runtime->lookupFunction(0x1A2B30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3138u; }
        if (ctx->pc != 0x1D3138u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A2B30_0x1a2b30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3138u; }
        if (ctx->pc != 0x1D3138u) { return; }
    }
    ctx->pc = 0x1D3138u;
label_1d3138:
    // 0x1d3138: 0x3c01003e  lui         $at, 0x3E
    ctx->pc = 0x1d3138u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)62 << 16));
    // 0x1d313c: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1d313cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d3140: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1D3140u;
    {
        const bool branch_taken_0x1d3140 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D3144u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3140u;
            // 0x1d3144: 0xa422ba50  sh          $v0, -0x45B0($at) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 1), 4294949456), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d3140) {
            ctx->pc = 0x1D3168u;
            goto label_1d3168;
        }
    }
    ctx->pc = 0x1D3148u;
label_1d3148:
    // 0x1d3148: 0xc068ad8  jal         func_1A2B60
    ctx->pc = 0x1D3148u;
    SET_GPR_U32(ctx, 31, 0x1D3150u);
    ctx->pc = 0x1D314Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3148u;
            // 0x1d314c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A2B60u;
    if (runtime->hasFunction(0x1A2B60u)) {
        auto targetFn = runtime->lookupFunction(0x1A2B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3150u; }
        if (ctx->pc != 0x1D3150u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A2B60_0x1a2b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3150u; }
        if (ctx->pc != 0x1D3150u) { return; }
    }
    ctx->pc = 0x1D3150u;
label_1d3150:
    // 0x1d3150: 0x3204ffff  andi        $a0, $s0, 0xFFFF
    ctx->pc = 0x1d3150u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)65535);
    // 0x1d3154: 0x26030001  addiu       $v1, $s0, 0x1
    ctx->pc = 0x1d3154u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1d3158: 0x42040  sll         $a0, $a0, 1
    ctx->pc = 0x1d3158u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1d315c: 0x3070ffff  andi        $s0, $v1, 0xFFFF
    ctx->pc = 0x1d315cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65535);
    // 0x1d3160: 0x9d1821  addu        $v1, $a0, $sp
    ctx->pc = 0x1d3160u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 29)));
    // 0x1d3164: 0xa46200b0  sh          $v0, 0xB0($v1)
    ctx->pc = 0x1d3164u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 176), (uint16_t)GPR_U32(ctx, 2));
label_1d3168:
    // 0x1d3168: 0x3c01003e  lui         $at, 0x3E
    ctx->pc = 0x1d3168u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)62 << 16));
    // 0x1d316c: 0x3203ffff  andi        $v1, $s0, 0xFFFF
    ctx->pc = 0x1d316cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)65535);
    // 0x1d3170: 0x8422ba50  lh          $v0, -0x45B0($at)
    ctx->pc = 0x1d3170u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294949456)));
    // 0x1d3174: 0x62102a  slt         $v0, $v1, $v0
    ctx->pc = 0x1d3174u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1d3178: 0x1440fff3  bnez        $v0, . + 4 + (-0xD << 2)
    ctx->pc = 0x1D3178u;
    {
        const bool branch_taken_0x1d3178 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D317Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3178u;
            // 0x1d317c: 0x3205ffff  andi        $a1, $s0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d3178) {
            ctx->pc = 0x1D3148u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d3148;
        }
    }
    ctx->pc = 0x1D3180u;
    // 0x1d3180: 0x96450816  lhu         $a1, 0x816($s2)
    ctx->pc = 0x1d3180u;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 2070)));
    // 0x1d3184: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1d3184u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1d3188: 0x5d1821  addu        $v1, $v0, $sp
    ctx->pc = 0x1d3188u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 29)));
    // 0x1d318c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d318cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d3190: 0x3c020020  lui         $v0, 0x20
    ctx->pc = 0x1d3190u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
    // 0x1d3194: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x1d3194u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1d3198: 0xa46500b0  sh          $a1, 0xB0($v1)
    ctx->pc = 0x1d3198u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 176), (uint16_t)GPR_U32(ctx, 5));
    // 0x1d319c: 0x8c23440c  lw          $v1, 0x440C($at)
    ctx->pc = 0x1d319cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d31a0: 0xc063f7c  jal         func_18FDF0
    ctx->pc = 0x1D31A0u;
    SET_GPR_U32(ctx, 31, 0x1D31A8u);
    ctx->pc = 0x1D31A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D31A0u;
            // 0x1d31a4: 0x628021  addu        $s0, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18FDF0u;
    if (runtime->hasFunction(0x18FDF0u)) {
        auto targetFn = runtime->lookupFunction(0x18FDF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D31A8u; }
        if (ctx->pc != 0x1D31A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018FDF0_0x18fdf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D31A8u; }
        if (ctx->pc != 0x1D31A8u) { return; }
    }
    ctx->pc = 0x1D31A8u;
label_1d31a8:
    // 0x1d31a8: 0x1000005b  b           . + 4 + (0x5B << 2)
    ctx->pc = 0x1D31A8u;
    {
        const bool branch_taken_0x1d31a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D31ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D31A8u;
            // 0x1d31ac: 0x982d  daddu       $s3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d31a8) {
            ctx->pc = 0x1D3318u;
            goto label_1d3318;
        }
    }
    ctx->pc = 0x1D31B0u;
label_1d31b0:
    // 0x1d31b0: 0x27a400a0  addiu       $a0, $sp, 0xA0
    ctx->pc = 0x1d31b0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
    // 0x1d31b4: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1d31b4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d31b8: 0xc074d50  jal         func_1D3540
    ctx->pc = 0x1D31B8u;
    SET_GPR_U32(ctx, 31, 0x1D31C0u);
    ctx->pc = 0x1D31BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D31B8u;
            // 0x1d31bc: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D3540u;
    if (runtime->hasFunction(0x1D3540u)) {
        auto targetFn = runtime->lookupFunction(0x1D3540u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D31C0u; }
        if (ctx->pc != 0x1D31C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D3540_0x1d3540(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D31C0u; }
        if (ctx->pc != 0x1D31C0u) { return; }
    }
    ctx->pc = 0x1D31C0u;
label_1d31c0:
    // 0x1d31c0: 0xc064920  jal         func_192480
    ctx->pc = 0x1D31C0u;
    SET_GPR_U32(ctx, 31, 0x1D31C8u);
    ctx->pc = 0x1D31C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D31C0u;
            // 0x1d31c4: 0x27a400a0  addiu       $a0, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
    ctx->pc = 0x192480u;
    if (runtime->hasFunction(0x192480u)) {
        auto targetFn = runtime->lookupFunction(0x192480u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D31C8u; }
        if (ctx->pc != 0x1D31C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00192480_0x192480(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D31C8u; }
        if (ctx->pc != 0x1D31C8u) { return; }
    }
    ctx->pc = 0x1D31C8u;
label_1d31c8:
    // 0x1d31c8: 0xae42080c  sw          $v0, 0x80C($s2)
    ctx->pc = 0x1d31c8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 2060), GPR_U32(ctx, 2));
    // 0x1d31cc: 0xc06c430  jal         func_1B10C0
    ctx->pc = 0x1D31CCu;
    SET_GPR_U32(ctx, 31, 0x1D31D4u);
    ctx->pc = 0x1D31D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D31CCu;
            // 0x1d31d0: 0x8e44080c  lw          $a0, 0x80C($s2) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 2060)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B10C0u;
    if (runtime->hasFunction(0x1B10C0u)) {
        auto targetFn = runtime->lookupFunction(0x1B10C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D31D4u; }
        if (ctx->pc != 0x1D31D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B10C0_0x1b10c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D31D4u; }
        if (ctx->pc != 0x1D31D4u) { return; }
    }
    ctx->pc = 0x1D31D4u;
label_1d31d4:
    // 0x1d31d4: 0x8e45080c  lw          $a1, 0x80C($s2)
    ctx->pc = 0x1d31d4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 2060)));
    // 0x1d31d8: 0xc064ce0  jal         func_193380
    ctx->pc = 0x1D31D8u;
    SET_GPR_U32(ctx, 31, 0x1D31E0u);
    ctx->pc = 0x1D31DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D31D8u;
            // 0x1d31dc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x193380u;
    if (runtime->hasFunction(0x193380u)) {
        auto targetFn = runtime->lookupFunction(0x193380u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D31E0u; }
        if (ctx->pc != 0x1D31E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193380_0x193380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D31E0u; }
        if (ctx->pc != 0x1D31E0u) { return; }
    }
    ctx->pc = 0x1D31E0u;
label_1d31e0:
    // 0x1d31e0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1d31e0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d31e4: 0xc064c90  jal         func_193240
    ctx->pc = 0x1D31E4u;
    SET_GPR_U32(ctx, 31, 0x1D31ECu);
    ctx->pc = 0x1D31E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D31E4u;
            // 0x1d31e8: 0x27a50060  addiu       $a1, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
    ctx->pc = 0x193240u;
    if (runtime->hasFunction(0x193240u)) {
        auto targetFn = runtime->lookupFunction(0x193240u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D31ECu; }
        if (ctx->pc != 0x1D31ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193240_0x193240(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D31ECu; }
        if (ctx->pc != 0x1D31ECu) { return; }
    }
    ctx->pc = 0x1D31ECu;
label_1d31ec:
    // 0x1d31ec: 0x3263ffff  andi        $v1, $s3, 0xFFFF
    ctx->pc = 0x1d31ecu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)65535);
    // 0x1d31f0: 0x3c04003d  lui         $a0, 0x3D
    ctx->pc = 0x1d31f0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)61 << 16));
    // 0x1d31f4: 0x33840  sll         $a3, $v1, 1
    ctx->pc = 0x1d31f4u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1d31f8: 0x24849230  addiu       $a0, $a0, -0x6DD0
    ctx->pc = 0x1d31f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294939184));
    // 0x1d31fc: 0xe31821  addu        $v1, $a3, $v1
    ctx->pc = 0x1d31fcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 3)));
    // 0x1d3200: 0x3c010001  lui         $at, 0x1
    ctx->pc = 0x1d3200u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)1 << 16));
    // 0x1d3204: 0x319c0  sll         $v1, $v1, 7
    ctx->pc = 0x1d3204u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 7));
    // 0x1d3208: 0x141040  sll         $v0, $s4, 1
    ctx->pc = 0x1d3208u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 20), 1));
    // 0x1d320c: 0x832821  addu        $a1, $a0, $v1
    ctx->pc = 0x1d320cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1d3210: 0x873021  addu        $a2, $a0, $a3
    ctx->pc = 0x1d3210u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x1d3214: 0x342128e4  ori         $at, $at, 0x28E4
    ctx->pc = 0x1d3214u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)10468);
    // 0x1d3218: 0xfd1821  addu        $v1, $a3, $sp
    ctx->pc = 0x1d3218u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 29)));
    // 0x1d321c: 0xc12021  addu        $a0, $a2, $at
    ctx->pc = 0x1d321cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 1)));
    // 0x1d3220: 0x5d1021  addu        $v0, $v0, $sp
    ctx->pc = 0x1d3220u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 29)));
    // 0x1d3224: 0xa4800000  sh          $zero, 0x0($a0)
    ctx->pc = 0x1d3224u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1d3228: 0x246700b0  addiu       $a3, $v1, 0xB0
    ctx->pc = 0x1d3228u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 3), 176));
    // 0x1d322c: 0x3c010001  lui         $at, 0x1
    ctx->pc = 0x1d322cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)1 << 16));
    // 0x1d3230: 0x944200b2  lhu         $v0, 0xB2($v0)
    ctx->pc = 0x1d3230u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 178)));
    // 0x1d3234: 0x34212824  ori         $at, $at, 0x2824
    ctx->pc = 0x1d3234u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)10276);
    // 0x1d3238: 0x94e90000  lhu         $t1, 0x0($a3)
    ctx->pc = 0x1d3238u;
    SET_GPR_U32(ctx, 9, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1d323c: 0xc13021  addu        $a2, $a2, $at
    ctx->pc = 0x1d323cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 1)));
    // 0x1d3240: 0x200402d  daddu       $t0, $s0, $zero
    ctx->pc = 0x1d3240u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d3244: 0x34019820  ori         $at, $zero, 0x9820
    ctx->pc = 0x1d3244u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)38944);
    // 0x1d3248: 0x10000028  b           . + 4 + (0x28 << 2)
    ctx->pc = 0x1D3248u;
    {
        const bool branch_taken_0x1d3248 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D324Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3248u;
            // 0x1d324c: 0xa11821  addu        $v1, $a1, $at (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 1)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d3248) {
            ctx->pc = 0x1D32ECu;
            goto label_1d32ec;
        }
    }
    ctx->pc = 0x1D3250u;
label_1d3250:
    // 0x1d3250: 0x94ea0000  lhu         $t2, 0x0($a3)
    ctx->pc = 0x1d3250u;
    SET_GPR_U32(ctx, 10, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1d3254: 0x156a0004  bne         $t3, $t2, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D3254u;
    {
        const bool branch_taken_0x1d3254 = (GPR_U64(ctx, 11) != GPR_U64(ctx, 10));
        if (branch_taken_0x1d3254) {
            ctx->pc = 0x1D3268u;
            goto label_1d3268;
        }
    }
    ctx->pc = 0x1D325Cu;
    // 0x1d325c: 0x950a00c6  lhu         $t2, 0xC6($t0)
    ctx->pc = 0x1d325cu;
    SET_GPR_U32(ctx, 10, (uint16_t)READ16(ADD32(GPR_U32(ctx, 8), 198)));
    // 0x1d3260: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x1D3260u;
    {
        const bool branch_taken_0x1d3260 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D3264u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3260u;
            // 0x1d3264: 0xa4ca0000  sh          $t2, 0x0($a2) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 10));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d3260) {
            ctx->pc = 0x1D32E0u;
            goto label_1d32e0;
        }
    }
    ctx->pc = 0x1D3268u;
label_1d3268:
    // 0x1d3268: 0x848a0000  lh          $t2, 0x0($a0)
    ctx->pc = 0x1d3268u;
    SET_GPR_S32(ctx, 10, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1d326c: 0x240c0008  addiu       $t4, $zero, 0x8
    ctx->pc = 0x1d326cu;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1d3270: 0x100702d  daddu       $t6, $t0, $zero
    ctx->pc = 0x1d3270u;
    SET_GPR_U64(ctx, 14, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d3274: 0xa5180  sll         $t2, $t2, 6
    ctx->pc = 0x1d3274u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 6));
    // 0x1d3278: 0xaa5021  addu        $t2, $a1, $t2
    ctx->pc = 0x1d3278u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 10)));
    // 0x1d327c: 0x254d0820  addiu       $t5, $t2, 0x820
    ctx->pc = 0x1d327cu;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 10), 2080));
label_1d3280:
    // 0x1d3280: 0x8dcb0000  lw          $t3, 0x0($t6)
    ctx->pc = 0x1d3280u;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 14), 0)));
    // 0x1d3284: 0x258cffff  addiu       $t4, $t4, -0x1
    ctx->pc = 0x1d3284u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 12), 4294967295));
    // 0x1d3288: 0x8dca0004  lw          $t2, 0x4($t6)
    ctx->pc = 0x1d3288u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 14), 4)));
    // 0x1d328c: 0xadab0000  sw          $t3, 0x0($t5)
    ctx->pc = 0x1d328cu;
    WRITE32(ADD32(GPR_U32(ctx, 13), 0), GPR_U32(ctx, 11));
    // 0x1d3290: 0x25ce0008  addiu       $t6, $t6, 0x8
    ctx->pc = 0x1d3290u;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), 8));
    // 0x1d3294: 0xadaa0004  sw          $t2, 0x4($t5)
    ctx->pc = 0x1d3294u;
    WRITE32(ADD32(GPR_U32(ctx, 13), 4), GPR_U32(ctx, 10));
    // 0x1d3298: 0x1d80fff9  bgtz        $t4, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1D3298u;
    {
        const bool branch_taken_0x1d3298 = (GPR_S64(ctx, 12) > 0);
        ctx->pc = 0x1D329Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3298u;
            // 0x1d329c: 0x25ad0008  addiu       $t5, $t5, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 13), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d3298) {
            ctx->pc = 0x1D3280u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d3280;
        }
    }
    ctx->pc = 0x1D32A0u;
    // 0x1d32a0: 0x848a0000  lh          $t2, 0x0($a0)
    ctx->pc = 0x1d32a0u;
    SET_GPR_S32(ctx, 10, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1d32a4: 0x250d0080  addiu       $t5, $t0, 0x80
    ctx->pc = 0x1d32a4u;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 8), 128));
    // 0x1d32a8: 0x240c0008  addiu       $t4, $zero, 0x8
    ctx->pc = 0x1d32a8u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1d32ac: 0xa5180  sll         $t2, $t2, 6
    ctx->pc = 0x1d32acu;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 6));
    // 0x1d32b0: 0x6a7021  addu        $t6, $v1, $t2
    ctx->pc = 0x1d32b0u;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 10)));
label_1d32b4:
    // 0x1d32b4: 0x8dab0000  lw          $t3, 0x0($t5)
    ctx->pc = 0x1d32b4u;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 13), 0)));
    // 0x1d32b8: 0x258cffff  addiu       $t4, $t4, -0x1
    ctx->pc = 0x1d32b8u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 12), 4294967295));
    // 0x1d32bc: 0x8daa0004  lw          $t2, 0x4($t5)
    ctx->pc = 0x1d32bcu;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 13), 4)));
    // 0x1d32c0: 0xadcb0000  sw          $t3, 0x0($t6)
    ctx->pc = 0x1d32c0u;
    WRITE32(ADD32(GPR_U32(ctx, 14), 0), GPR_U32(ctx, 11));
    // 0x1d32c4: 0x25ad0008  addiu       $t5, $t5, 0x8
    ctx->pc = 0x1d32c4u;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 13), 8));
    // 0x1d32c8: 0xadca0004  sw          $t2, 0x4($t6)
    ctx->pc = 0x1d32c8u;
    WRITE32(ADD32(GPR_U32(ctx, 14), 4), GPR_U32(ctx, 10));
    // 0x1d32cc: 0x1d80fff9  bgtz        $t4, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1D32CCu;
    {
        const bool branch_taken_0x1d32cc = (GPR_S64(ctx, 12) > 0);
        ctx->pc = 0x1D32D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D32CCu;
            // 0x1d32d0: 0x25ce0008  addiu       $t6, $t6, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d32cc) {
            ctx->pc = 0x1D32B4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d32b4;
        }
    }
    ctx->pc = 0x1D32D4u;
    // 0x1d32d4: 0x848a0000  lh          $t2, 0x0($a0)
    ctx->pc = 0x1d32d4u;
    SET_GPR_S32(ctx, 10, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1d32d8: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x1d32d8u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x1d32dc: 0xa48a0000  sh          $t2, 0x0($a0)
    ctx->pc = 0x1d32dcu;
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 10));
label_1d32e0:
    // 0x1d32e0: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x1d32e0u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1d32e4: 0x25080190  addiu       $t0, $t0, 0x190
    ctx->pc = 0x1d32e4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 400));
    // 0x1d32e8: 0x3129ffff  andi        $t1, $t1, 0xFFFF
    ctx->pc = 0x1d32e8u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) & (uint64_t)(uint16_t)65535);
label_1d32ec:
    // 0x1d32ec: 0x312bffff  andi        $t3, $t1, 0xFFFF
    ctx->pc = 0x1d32ecu;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 9) & (uint64_t)(uint16_t)65535);
    // 0x1d32f0: 0x162502a  slt         $t2, $t3, $v0
    ctx->pc = 0x1d32f0u;
    SET_GPR_U64(ctx, 10, ((int64_t)GPR_S64(ctx, 11) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1d32f4: 0x1540ffd6  bnez        $t2, . + 4 + (-0x2A << 2)
    ctx->pc = 0x1D32F4u;
    {
        const bool branch_taken_0x1d32f4 = (GPR_U64(ctx, 10) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d32f4) {
            ctx->pc = 0x1D3250u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d3250;
        }
    }
    ctx->pc = 0x1D32FCu;
    // 0x1d32fc: 0xc064960  jal         func_192580
    ctx->pc = 0x1D32FCu;
    SET_GPR_U32(ctx, 31, 0x1D3304u);
    ctx->pc = 0x1D3300u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D32FCu;
            // 0x1d3300: 0x8e44080c  lw          $a0, 0x80C($s2) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 2060)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x192580u;
    if (runtime->hasFunction(0x192580u)) {
        auto targetFn = runtime->lookupFunction(0x192580u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3304u; }
        if (ctx->pc != 0x1D3304u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00192580_0x192580(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3304u; }
        if (ctx->pc != 0x1D3304u) { return; }
    }
    ctx->pc = 0x1D3304u;
label_1d3304:
    // 0x1d3304: 0xc06c444  jal         func_1B1110
    ctx->pc = 0x1D3304u;
    SET_GPR_U32(ctx, 31, 0x1D330Cu);
    ctx->pc = 0x1D3308u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3304u;
            // 0x1d3308: 0x8e44080c  lw          $a0, 0x80C($s2) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 2060)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B1110u;
    if (runtime->hasFunction(0x1B1110u)) {
        auto targetFn = runtime->lookupFunction(0x1B1110u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D330Cu; }
        if (ctx->pc != 0x1D330Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1110_0x1b1110(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D330Cu; }
        if (ctx->pc != 0x1D330Cu) { return; }
    }
    ctx->pc = 0x1D330Cu;
label_1d330c:
    // 0x1d330c: 0x26630001  addiu       $v1, $s3, 0x1
    ctx->pc = 0x1d330cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x1d3310: 0xae40080c  sw          $zero, 0x80C($s2)
    ctx->pc = 0x1d3310u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 2060), GPR_U32(ctx, 0));
    // 0x1d3314: 0x3073ffff  andi        $s3, $v1, 0xFFFF
    ctx->pc = 0x1d3314u;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65535);
label_1d3318:
    // 0x1d3318: 0x3c01003e  lui         $at, 0x3E
    ctx->pc = 0x1d3318u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)62 << 16));
    // 0x1d331c: 0x3274ffff  andi        $s4, $s3, 0xFFFF
    ctx->pc = 0x1d331cu;
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)65535);
    // 0x1d3320: 0x8423ba50  lh          $v1, -0x45B0($at)
    ctx->pc = 0x1d3320u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294949456)));
    // 0x1d3324: 0x283182a  slt         $v1, $s4, $v1
    ctx->pc = 0x1d3324u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 20) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1d3328: 0x1460ffa1  bnez        $v1, . + 4 + (-0x5F << 2)
    ctx->pc = 0x1D3328u;
    {
        const bool branch_taken_0x1d3328 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D332Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3328u;
            // 0x1d332c: 0x3267ffff  andi        $a3, $s3, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d3328) {
            ctx->pc = 0x1D31B0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d31b0;
        }
    }
    ctx->pc = 0x1D3330u;
    // 0x1d3330: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x1d3330u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1d3334: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1d3334u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d3338: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1d3338u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d333c: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d333cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d3340: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d3340u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d3344: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d3344u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d3348: 0x3e00008  jr          $ra
    ctx->pc = 0x1D3348u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D334Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3348u;
            // 0x1d334c: 0x27bd0180  addiu       $sp, $sp, 0x180 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 384));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D312Cu: goto label_1d312c;
            case 0x1D3138u: goto label_1d3138;
            case 0x1D3148u: goto label_1d3148;
            case 0x1D3150u: goto label_1d3150;
            case 0x1D3168u: goto label_1d3168;
            case 0x1D31A8u: goto label_1d31a8;
            case 0x1D31B0u: goto label_1d31b0;
            case 0x1D31C0u: goto label_1d31c0;
            case 0x1D31C8u: goto label_1d31c8;
            case 0x1D31D4u: goto label_1d31d4;
            case 0x1D31E0u: goto label_1d31e0;
            case 0x1D31ECu: goto label_1d31ec;
            case 0x1D3250u: goto label_1d3250;
            case 0x1D3268u: goto label_1d3268;
            case 0x1D3280u: goto label_1d3280;
            case 0x1D32B4u: goto label_1d32b4;
            case 0x1D32E0u: goto label_1d32e0;
            case 0x1D32ECu: goto label_1d32ec;
            case 0x1D3304u: goto label_1d3304;
            case 0x1D330Cu: goto label_1d330c;
            case 0x1D3318u: goto label_1d3318;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D3350u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
